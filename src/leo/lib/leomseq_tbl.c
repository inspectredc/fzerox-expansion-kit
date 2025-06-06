#include "libultra/ultra64.h"
#include "leo/leo_internal.h"

u32 mseq_tbl[0x10];

const u32 rd_mseq_code[0x10] = {
    0x00010000, 0x00020200, 0x80030100, 0x82040000, 0xA8050000, 0xA0060600, 0x31760000, 0x00020300,
    0,          0,          0,          0,          0,          0,          0,          0x4060000,
};
const u32 wt_mseq_code[0x10] = {
    0x40020000, 0x00020000, 0x40130B00, 0x42140100, 0x68050000, 0x50060600, 0x401702FF, 0x01870000,
    0x40020000, 0,          0,          0,          0,          0,          0,          0x40F0000,
};

extern vu16 LEOrw_flags;

void leoSet_mseq(u16 rwmode) {
    const u32* tbl;
    u32 sct_byte_x;
    u32 sct_byte_u;
    u8 i;

    LEOasic_seq_ctl_shadow &= 0xBFFFFFFF;
    osEPiWriteIo(LEOPiInfo, LEO_SEQ_STATUS, LEOasic_seq_ctl_shadow);
    if (rwmode == 1) {
        tbl = wt_mseq_code;
    } else {
        tbl = rd_mseq_code;
    }
    for (i = 0; i < 0x10; i++) {
        mseq_tbl[i] = *tbl;
        tbl++;
    }

    sct_byte_x = sct_byte_u = LEOtgt_param.sec_bytes - 1;
    sct_byte_u += 7;
    sct_byte_x <<= 8;
    mseq_tbl[4] |= sct_byte_x;

    osWritebackDCache(mseq_tbl, 0x40);
    LEOPiDmaParam.dramAddr = mseq_tbl;
    LEOPiDmaParam.devAddr = LEO_RAM_ADDR;
    LEOPiDmaParam.size = 0x40;
    LEOPiInfo->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(LEOPiInfo, &LEOPiDmaParam, OS_WRITE);
    osRecvMesg(&LEOdma_que, NULL, OS_MESG_BLOCK);
    osEPiWriteIo(LEOPiInfo, LEO_SEC_BYTE, (sct_byte_u | 0x5900) << 0x10);

    if (LEOrw_flags & 0x800) {
        sct_byte_x += 0x100;
    }
    osEPiWriteIo(LEOPiInfo, LEO_HOST_SECBYTE, sct_byte_x << 8);
    osEPiWriteIo(LEOPiInfo, LEO_SEQ_CTL, (LEOasic_seq_ctl_shadow |= LEO_STATUS_DATA_REQUEST));
}
