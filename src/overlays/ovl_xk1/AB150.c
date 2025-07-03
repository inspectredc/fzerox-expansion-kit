#include "global.h"
#include "fzx_game.h"
#include "leo/leo_functions.h"

LEODiskID D_xk1_8003BB60;
LEODiskID D_xk1_8003BB80;

void func_xk1_8002DEE0(s32 arg0) {
    func_8070F8A4(arg0, 0);
    while (true) {}
}

extern s16 gWorkingDirectory;
extern s32 D_80794D30;
extern LEODiskID D_8076CB50;
extern LEODiskID D_80794CE8;
extern MfsRamArea gMfsRamArea;
extern s32 D_80794CD4;

void func_xk1_8002DF10(void) {
    D_80794CE8 = D_8076CB50;

    func_80760320();
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_80794D30 = 0;
    gMfsRamArea.id.diskId[0] = '\0';
    func_807047AC();
    if (D_80794CD4 == 0xF2) {
        D_80794CD4 = 0;
    }
}

extern volatile unk_807C6EA8 D_807C6EA8;

void func_xk1_8002DFB4(s32* arg0, s32* arg1) {

    switch (*arg0) {
        case LEO_ERROR_GOOD:
            func_80767940();
            *arg1 = LEO_ERROR_GOOD;
            break;
        case LEO_ERROR_QUEUE_FULL:
            *arg1 = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            D_807C6EA8.unk_14 = *arg0;
            D_807C6EA8.unk_04 = 1;
            D_807C6EA8.unk_08 = 2;
            D_807C6EA8.unk_0C = 1;
            *arg1 = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            D_807C6EA8.unk_0C = 1;
            *arg1 = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
            func_80767940();
            *arg1 = LEO_ERROR_COMMAND_TERMINATED;
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            D_807C6EA8.unk_14 = *arg0;
            D_807C6EA8.unk_04 = 1;
            D_807C6EA8.unk_0C = 3;
            *arg1 = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        default:
            func_xk1_8002DEE0(*arg0);
            break;
    }
}

extern s32 gGameMode;

s32 func_xk1_8002E0A8(void) {
    s32 sp2C;

    if (Mfs_ReadDiskId(&D_8076CB50) == 0) {
        if (func_80704120(D_8076CB50) != 2) {
            func_80767940();
            return 4;
        }
        if (((bcmp(&D_xk1_8003BB60, &D_8076CB50, sizeof(LEODiskID)) != 0) &&
             ((D_807C6EA8.unk_00 == 9) || (D_807C6EA8.unk_00 == 0xF) || (D_807C6EA8.unk_00 == 0x10) ||
              (D_807C6EA8.unk_00 == 0x11) || (D_807C6EA8.unk_00 == 0x12))) ||
            ((bcmp(&D_xk1_8003BB80, &D_8076CB50, sizeof(LEODiskID)) != 0) && (gGameMode == GAMEMODE_CREATE_MACHINE) &&
             ((D_807C6EA8.unk_00 == 8) || (D_807C6EA8.unk_00 == GAMEMODE_TIME_ATTACK)))) {
            func_80767940();
            return 4;
        }
        func_xk1_8002DF10();
    }

    func_xk1_8002DFB4(&D_80794CD4, &sp2C);
    return sp2C;
}

s32 func_xk1_8002E238(void) {
    s32 sp1C;

    Mfs_SpdlMotor(LEO_MOTOR_BRAKE);
    switch (D_80794CD4) {
        case LEO_ERROR_GOOD:
            D_807C6EA8.unk_0C = 2;
            sp1C = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        case LEO_ERROR_QUEUE_FULL:
            sp1C = LEO_ERROR_DIAGNOSTIC_FAILURE;
            break;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            D_807C6EA8.unk_0C = 0;
            sp1C = LEO_ERROR_MEDIUM_NOT_PRESENT;
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
            D_807C6EA8.unk_0C = 0;
            sp1C = LEO_ERROR_COMMAND_TERMINATED;
            break;
        default:
            func_xk1_8002DEE0(D_80794CD4);
            break;
    }
    return sp1C;
}

s32 func_xk1_8002E2E8(s32 arg0) {
    s32 var_v1;

    switch (arg0) {
        case 0:
            var_v1 = func_xk1_8002E0A8();
            if (var_v1 == LEO_ERROR_GOOD) {
                D_807C6EA8.unk_04 = 0;
                D_807C6EA8.unk_08 = 0;
                var_v1 = LEO_ERROR_GOOD;
            }
            break;
        case 1:
            var_v1 = func_xk1_8002E238();
            if (var_v1 == LEO_ERROR_MEDIUM_NOT_PRESENT) {
                D_807C6EA8.unk_08 = 0;
                var_v1 = LEO_ERROR_GOOD;
            }
            break;
    }
    return var_v1;
}

extern volatile u8 D_80794E10;
extern volatile u8 D_80794E1C;
extern volatile u8 D_80794E20;
extern volatile u8 D_80794E24;
extern volatile s32 D_807C6F0C;
extern s32 D_8076CBB0;
extern s32 D_80794CD8;

s32 func_xk1_8002E368(void) {
    static u8 D_xk1_80033400 = 0;
    static s32 D_xk1_80033404 = 0;
    static s16 D_xk1_80033408 = 0;
    static u8 D_xk1_8003340C = 0;
    s32 sp3C;
    u8 sp3B;
    s32 pad;

    sp3B = D_xk1_8003340C;
    D_xk1_8003340C = 0;

    if (D_807C6EA8.unk_10 == 4) {
        D_807C6EA8.unk_10 = 1;
        D_xk1_80033400 = 1;
        D_xk1_80033404 = 0xF6;
    }
    switch (D_xk1_80033400) {
        case 0:
            if (D_8076CBB0 != 0) {
                func_xk1_8002DF10();
                D_8076CBB0 = 0;
            }
            switch (D_807C6EA8.unk_00) {
                case 11:
                case 12:
                    D_807C6F0C = func_xk1_8002BD64(D_807C6EA8.unk_54, D_807C6EA8.unk_1C);
                    break;
                case 13:
                case 14:
                    if (func_80768C88(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C) != 0) {
                        D_80794E20 = 1;
                    } else {
                        D_80794E20 = 0;
                    }
                    break;
                case 8:
                    func_8076321C(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C, D_807C6EA8.unk_20,
                                  D_807C6EA8.unk_28, D_807C6EA8.unk_2C, D_807C6EA8.unk_30, D_807C6EA8.unk_34);
                    break;
                case 9:
                case 10:
                    func_8076543C(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C, D_807C6EA8.unk_38,
                                  D_807C6EA8.unk_28);
                    break;
                case 15:
                    func_80766434(D_807C6EA8.unk_16, D_807C6EA8.unk_3C, D_807C6EA8.unk_40, D_807C6EA8.unk_44,
                                  D_807C6EA8.unk_48, D_807C6EA8.unk_34);
                    break;
                case 16:
                    func_80764E90(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C, D_807C6EA8.unk_34);
                    break;
                case 17:
                    func_80766BC0(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C);
                    break;
                case 18:
                    func_80766A98(D_807C6EA8.unk_16, D_807C6EA8.unk_18, D_807C6EA8.unk_1C, D_807C6EA8.unk_4C,
                                  D_807C6EA8.unk_50, D_807C6EA8.unk_34);
                    break;
            }
            D_807C6EA8.unk_14 = D_xk1_80033404 = D_80794CD4;
            D_xk1_80033408 = D_80794CD8;
            /* fallthrough */
        case 1:
            D_xk1_80033400 = 0;
            sp3C = D_xk1_80033404;

            if ((D_xk1_80033404 == LEO_ERROR_GOOD) || (D_xk1_80033404 == 0xF2)) {
                D_807C6EA8.unk_08 = 0;
                switch (D_807C6EA8.unk_00) {
                    case 9:
                    case 10:
                        D_80794E10 = 1;
                        break;
                    case 11:
                        D_xk1_8003BB60 = D_8076CB50;
                        if (D_807C6F0C == 0) {
                            D_80794E24 = 1;
                            D_807C6EA8.unk_08 = 0xD;
                        }
                        break;
                    case 12:
                        D_xk1_8003BB80 = D_8076CB50;
                        break;
                }
                sp3C = D_807C6EA8.unk_14 = D_80794CD4 = 0;
                break;
            }
            if (D_xk1_80033404 == 0x106) {
                D_80794E1C = 1;
                D_807C6EA8.unk_08 = 0x10;
                sp3C = LEO_ERROR_GOOD;
                break;
            }
            if (D_xk1_80033404 == LEO_ERROR_COMMAND_TERMINATED) {
                sp3C = LEO_ERROR_COMMAND_TERMINATED;
                break;
            }
            if ((D_xk1_80033404 == LEO_ERROR_QUEUE_FULL) || (D_xk1_80033404 == LEO_ERROR_BUSY)) {
                sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                break;
            }
            if ((D_xk1_80033404 == 0x10A) || (D_xk1_80033404 == 0xF3)) {
                func_80704068();
                if (sp3B == 0) {
                    func_80703948();
                    func_807040C8();
                    SLMFSRecoverManageArea();
                    D_xk1_8003340C = 1;
                    sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                } else {
                    if (sp3B == 1) {
                        func_807038B0();
                        func_80706518(1, 0x20, 0);
                        func_807040C8();
                    }
                    sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                }
                break;
            }
            if (D_xk1_80033404 == 0xF0) {
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                break;
            }
            if (D_xk1_80033404 == 0xF6) {
                sp3C = func_xk1_8002E2E8(1);
                if (sp3C == LEO_ERROR_GOOD) {
                    sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                } else if (sp3C == LEO_ERROR_DIAGNOSTIC_FAILURE) {
                    sp3C = LEO_ERROR_DATA_PHASE_ERROR;
                }
                break;
            }
            if (D_xk1_80033408 == 8) {
                func_xk1_8002DFB4(&D_xk1_80033404, &sp3C);
                break;
            }

            switch (D_xk1_80033404) {
                case LEO_ERROR_DIAGNOSTIC_FAILURE:
                case LEO_ERROR_MEDIUM_NOT_PRESENT:
                case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                    if (D_xk1_80033404 == LEO_ERROR_EJECTED_ILLEGALLY_RESUME) {
                        D_807C6EA8.unk_04 = 1;
                        D_807C6EA8.unk_08 = 2;
                    }
                    sp3C = func_xk1_8002E2E8(0);
                    if (sp3C == LEO_ERROR_GOOD) {
                        sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                    } else if (sp3C == LEO_ERROR_DIAGNOSTIC_FAILURE) {
                        D_xk1_80033400 = 1;
                    }
                    break;
                case LEO_ERROR_UNRECOVERED_READ_ERROR:
                    func_80704068();
                    if (sp3B == 0) {
                        func_80703948();
                        func_807040C8();
                        SLMFSRecoverManageArea();
                        D_xk1_8003340C = 1;
                    } else if (sp3B == 1) {
                        func_807038B0();
                        func_80706518(1, 0x20, 0);
                        func_807040C8();
                    }
                    sp3C = LEO_ERROR_DIAGNOSTIC_FAILURE;
                    break;
                default:
                    func_xk1_8002DEE0(D_xk1_80033404);
                    break;
            }
            break;
        default:
            break;
    }
    return sp3C;
}
