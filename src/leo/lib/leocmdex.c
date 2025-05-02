#include "sys.h"
#include "leo/leo_internal.h"

OSPiHandle* LEOPiInfo;
OSIoMesg LEOPiDmaParam;
s32 LEO_currentCommand;

void (*LEO_cmd_tbl[])(void) = {
    NULL,          leoClr_queue, leoInquiry,    leoTest_unit_rdy, leoRezero,    leoRead,
    leoWrite,      leoSeek,      leoStart_stop, leoRd_capacity,   leoTranslate, leoMode_sel,
    leoReadDiskId, leoReadTimer, leoSetTimer,   leoClr_reset,
};

LEOCmdRead leo_sys_read_cmd = {
    { LEO_COMMAND_READ, 0, 0, 0, 0, 0, 0, 0, 0 }, 12, 1, 0, 0,
};

extern vu16 LEOrw_flags;

void leomain(void* arg0) {
    u32 cur_status;
    u32 sense_code;
    u8 disktype_bak;

    ((u8*) &LEO_country_code)[0] = *(vu8*) OS_PHYSICAL_TO_K1(0x10);
    ((u8*) &LEO_country_code)[1] = *(vu8*) OS_PHYSICAL_TO_K1(0x90);
    ((u8*) &LEO_country_code)[2] = *(vu8*) OS_PHYSICAL_TO_K1(0x110);
    ((u8*) &LEO_country_code)[3] = *(vu8*) OS_PHYSICAL_TO_K1(0x190);

    LEOasic_seq_ctl_shadow = 0;
    LEOasic_bm_ctl_shadow = 0;
    LEOdrive_flag = 0;
    LEOclr_que_flag = 0;
    leoInitUnit_atten();
    LEOPiInfo = osLeoDiskInit();
    LEOPiDmaParam.hdr.pri = 1;
    LEOPiDmaParam.hdr.retQueue = &LEOdma_que;
    osEPiReadIo(LEOPiInfo, LEO_STATUS, &cur_status);
    if (!(cur_status & 0x400000)) {
        if ((cur_status & 0x06800000)) {
            leoDrive_reset();
        }
    }

    while (true) {
        osRecvMesg(&LEOcommand_que, (OSMesg*) &LEOcur_command, OS_MESG_BLOCK);
        LEO_currentCommand = LEOcur_command->header.command;
        if (LEOcur_command->header.command == 0) {
            leoDrive_reset();
            osRecvMesg(&LEOevent_que, NULL, OS_MESG_NOBLOCK);
            continue;
        }

        sense_code = leoChk_asic_ready(0x10001);
        cur_status = leoChkUnit_atten();

        do {
            if (cur_status == 0) {
                if (sense_code == 0) {
                    continue;
                }
            } else {
                switch (sense_code) {
                    case 3:
                    case 37:
                    case 41:
                    case 43:
                        break;
                    case 49:
                        if (leoRetUnit_atten() == 43) {
                            sense_code = 43;
                        }
                        break;
                    default:
                        sense_code = leoRetUnit_atten();
                }
            }

            switch (sense_code) {
                case 47:
                    switch (LEOcur_command->header.command) {
                        case 2:
                        case 8:
                        case 11:
                        case 12:
                        case 13:
                        case 14:
                        case 15:
                            continue;
                    }
                    break;
                case 49:
                    switch (LEOcur_command->header.command) {
                        case 2:
                        case 11:
                        case 13:
                        case 14:
                        case 15:
                            continue;
                        default:
                            sense_code = 42;
                    }
                    break;
                case 43:
                    switch (LEOcur_command->header.command) {
                        case 15:
                            leoClrUA_RESET();
                            /* FALLTHROUGH; */
                        case 2:
                        case 13:
                        case 14:
                            continue;
                    }
                    break;
                default:
                    /* empty */;
            }

            if (LEOcur_command->header.command == 3) {
                LEOcur_command->data.modeselect.reserve1 = leoChk_cur_drvmode();
            }
            LEOcur_command->header.sense = sense_code;
            LEOcur_command->header.status = 2;
            goto post_exe;
        } while (0);

        if (LEOdrive_flag == 0) {
            switch (LEOcur_command->header.command) {
                case 2:
                case 3:
                case 8:
                case 11:
                case 13:
                case 14:
                case 15:
                    break;
                default:
                    if (LEO_country_code == 0) {
                        osEPiReadIo(LEOPiInfo, LEO_ID_REG, &cur_status);
                        if ((cur_status & 0x70000) != 0x40000) {
                            while (true) {}
                        }
                    }

                    if (leoRead_system_area() != 0) {
                        LEOcur_command->header.status = 2;
                        goto post_exe;
                    }

                    if ((LEOcur_command->header.sense =
                             leoSend_asic_cmd_w(0xB0001, LEO_sys_data.param.disk_type << 16)) != 0) {
                        LEOcur_command->header.status = 2;
                        goto post_exe;
                    }

                    if ((LEO_sys_data.param.disk_type & 0xF0) != 0x10) {
                        goto invalid_disktype;
                    }

                    LEOdisk_type = (LEO_sys_data.param.disk_type & 0xF);
                    if (LEOdisk_type >= 7) {
                    invalid_disktype:
                        LEOcur_command->header.sense = 0xBU;
                        LEOcur_command->header.status = 2;
                        goto post_exe;
                    }

                    LEOdrive_flag = -1;
            }
        }

        LEO_cmd_tbl[LEOcur_command->header.command]();

    post_exe:
        if (LEOcur_command->header.control & 0x80) {
            osSendMesg(LEOcur_command->header.post, (void*) (s32) LEOcur_command->header.sense, OS_MESG_BLOCK);
        }
        if (LEOclr_que_flag != 0) {
            leoClr_queue();
        }
    }
}

const u8 leo_sys_form_lbas[] = { 0, 1, 8, 9, 0, 0, 0, 0 };

u8 leoRead_system_area(void) {
    LEOCmdRead temp_cmd;
    LEOCmd* prev_cmd;
    u32 retry_cntr;
    s32 read_mode;

    prev_cmd = LEOcur_command;
    LEOcur_command = (LEOCmd*) &temp_cmd;
    read_mode = 0;
    retry_cntr = 0;

    while (true) {
        LEOdisk_type = 0;
        // For lba_to_phys to avoid dealing with alternative tracks on the disk
        LEO_sys_data.param.defect_num[0] = 0;
        LEOrw_flags = 0x3000;
        temp_cmd = leo_sys_read_cmd;
        temp_cmd.buff_ptr = &LEO_sys_data;

        if (read_mode == 0) {
            // read System LBA 12 (+0, this is an offset value for leoRead_common)
            // see leo_sys_read_cmd premade struct
            leoRead_common(0);
            switch (GET_ERROR(temp_cmd)) {
                case LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION:
                    do {
                        // if expecting a retail disk, LBA 12 is expected to do a read error, if not then freeze
                    } while (LEO_country_code != LEO_COUNTRY_NONE);
                    break;
                case LEO_SENSE_UNRECOVERED_READ_ERROR:
                    do {
                        // if expecting a development disk, LBA 12 is expected to read correctly, if not then freeze
                    } while (LEO_country_code == LEO_COUNTRY_NONE);
                    break;
                default:
                    goto system_retry;
            }
            read_mode--;
            retry_cntr = 0;
            continue;
        } else {
            // read System LBA 0,1,8,9 (or 2,3,10,11 for dev)
            temp_cmd.lba = leo_sys_form_lbas[retry_cntr % 4];
            if (LEO_country_code == LEO_COUNTRY_NONE) {
                temp_cmd.lba += 2;
            }
            leoRead_common(0);
            if (temp_cmd.header.status == LEO_STATUS_GOOD) {
                do {
                    // if disk country and set country code in libleo mismatch, then freeze
                } while ((0, LEO_sys_data.param.country) != LEO_country_code);
                // todo: use likely macro for above
                break;
            }
        }
    system_retry:
        if (leoChk_err_retry(GET_ERROR(temp_cmd)) != LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
            break;
        }
        if (retry_cntr++ >= 64) {
            break;
        }
        if ((retry_cntr % 8) == 0) {
            // Recalibrate drive every 8 tries
            if ((temp_cmd.header.sense = leoSend_asic_cmd_w(ASIC_RECAL, 0)) !=
                LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION) {
                goto system_retry;
            }
        }
    }
    LEOcur_command = prev_cmd;
    return LEOcur_command->header.sense = GET_ERROR(temp_cmd);
}
