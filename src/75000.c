#include "global.h"
#include "leo/leo_functions.h"

extern unk_807C6F10 D_807C6F10[];
extern vs32 D_80794E28;
extern vs32 D_80794E2C;
extern OSMesgQueue D_807C6E90;

void func_80767800(unk_807C6F10 arg0) {
    OSIntMask prevMask;
    s32 temp_lo;

    do {
    } while (D_80794E28 == ((D_80794E2C + 1) & 7));
    prevMask = osGetIntMask();
    osSetIntMask(OS_IM_NONE);
    D_80794E2C &= 7;
    D_807C6F10[D_80794E2C] = arg0;
    temp_lo = D_80794E2C;
    D_80794E2C = (D_80794E2C + 1) & 7;
    osSendMesg(&D_807C6E90, &D_807C6F10[temp_lo], 1);
    osSetIntMask(prevMask);
}

void func_80767900(void) {
    if (D_80794E2C != D_80794E28) {
        D_80794E28++;
        D_80794E28 &= 7;
    }
}

extern volatile unk_807C6EA8 D_807C6EA8;

void func_80767940(void) {
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

extern u8 D_80794E14;
extern u8 D_80794E18;
extern OSMesgQueue D_807C6E90;
extern void* D_807C7030;
extern OSMesgQueue D_807C7058;
extern unk_807C6F10* D_807C7050;

// void SLLeoReadWrite(LEOCmd*, s32, s32, s32, s32, OSMesgQueue*);
// void SLLeoReadWrite_DATA(LEOCmd*, s32, s32, s32, s32, OSMesgQueue*);
// void SLMFSSave(s32, s32, s32, s32, s32, s32, s32, s32);
// void func_800EB938(s32, s32, s32, s32, s32, s32, s32, s32);
// void SLMFSLoad(s32, s32, s32, s32, s32);
// void SLMFSLoadHalfway(s32, s32, s32, s32, s32, s32);
// void func_807039D4(s32, s32, s32, s32);
// void func_80706518(s32, s32, s32);
// void SLMFSFlushManageArea(void);
// void SLMFSNewDisk(void);
// s32 func_8002E368(void);
// void func_8070F8A4(s32, s32);

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767958.s")

s32 func_80767E30(void) {
    if (D_80794E18 == 0) {
        return 0;
    }
    switch (D_807C6EA8.unk_08) {
        case 0:
            return 0;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 14:
        case 15:
            D_807C6EA8.unk_08 = 9;
            return 1;
        default:
            return 1;
    }
}

void func_80767E98(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {

    D_807C6EA8.unk_16 = arg0;
    D_807C6EA8.unk_18 = arg1;
    D_807C6EA8.unk_1C = arg2;
    D_807C6EA8.unk_20 = arg3;
    D_807C6EA8.unk_28 = arg4;
    D_807C6EA8.unk_2C = arg5;
    D_807C6EA8.unk_30 = arg6;
    D_807C6EA8.unk_34 = arg7;
    osSendMesg(&D_807C6E90, NULL, 1);
}

void func_80767F14(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4) {
    D_807C6EA8.unk_16 = arg0;
    D_807C6EA8.unk_18 = arg1;
    D_807C6EA8.unk_1C = arg2;
    D_807C6EA8.unk_38 = arg3;
    D_807C6EA8.unk_28 = arg4;
    osSendMesg(&D_807C6E90, NULL, 1);
}

void func_80767F78(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 0;
        D_807C6EA8.unk_58 = arg0;
        D_807C6EA8.unk_5C = arg1;
        D_807C6EA8.unk_28 = arg2;
        D_807C6EA8.unk_60 = arg3;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_80767FE4(s32 arg0, u8 arg1, u8* arg2) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 1;
        D_807C6EA8.unk_04 = 0;
        D_807C6EA8.unk_08 = 0;
        D_807C6EA8.unk_0C = 4;
        D_807C6EA8.unk_30 = arg0;
        D_807C6EA8.unk_54 = arg1;
        D_807C6EA8.unk_1C = arg2;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_8076805C(void) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 2;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_807680A4(void) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 3;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_807680EC(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 4;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_8076814C(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 5;
        D_807C6EA8.unk_08 = 6;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_807681C8(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 5;
        D_807C6EA8.unk_08 = 7;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_80768244(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 6;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_807682C0(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 10;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_8076833C(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 25;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_807683B8(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 26;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_80768434(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 8;
        D_807C6EA8.unk_08 = 8;
        func_80767E98(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

void func_807684AC(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4, s32 arg5) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 7;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        D_807C6EA8.unk_38 = arg3;
        D_807C6EA8.unk_24 = arg4;
        D_807C6EA8.unk_28 = arg5;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_8076852C(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4) {
    if (D_80794E18 == 0) {
        D_807C6EA8.unk_00 = 6;
        func_80767F14(arg0, arg1, arg2, arg3, arg4);
    }
}

void func_80768574(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 9;
        D_807C6EA8.unk_08 = 5;
        func_80767F14(arg0, arg1, arg2, arg3, arg4);
    }
}

void func_807685D8(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 10;
        D_807C6EA8.unk_08 = 10;
        func_80767F14(arg0, arg1, arg2, arg3, arg4);
    }
}

void func_80768638(u16 arg0, u8* arg1, u8* arg2, void* arg3, s32 arg4) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 9;
        D_807C6EA8.unk_08 = 10;
        func_80767F14(arg0, arg1, arg2, arg3, arg4);
    }
}

void func_8076869C(u16 arg0, u8* arg1, u8* arg2) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 13;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_8076870C(u16 arg0, u8* arg1, u8* arg2) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 14;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_8076877C(u8 arg0, u8* arg1) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 11;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_54 = arg0;
        D_807C6EA8.unk_1C = arg1;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_807687E0(u8 arg0, u8* arg1) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 12;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_54 = arg0;
        D_807C6EA8.unk_1C = arg1;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_80768844(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 15;
        D_807C6EA8.unk_08 = 11;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_3C = arg1;
        D_807C6EA8.unk_40 = arg2;
        D_807C6EA8.unk_44 = arg3;
        D_807C6EA8.unk_48 = arg4;
        D_807C6EA8.unk_34 = arg5;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_807688D0(u16 arg0, u8* arg1, u8* arg2, s32 arg3) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 16;
        D_807C6EA8.unk_08 = 12;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        D_807C6EA8.unk_34 = arg3;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_8076894C(u16 arg0, u8* arg1, u8* arg2) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 17;
        D_807C6EA8.unk_08 = 10;
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

void func_807689BC(u16 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (func_80767E30() == 0) {
        D_807C6EA8.unk_00 = 18;
        if (arg3 == 0x2000) {
            D_807C6EA8.unk_08 = 14;
        } else {
            D_807C6EA8.unk_08 = 15;
        }
        D_807C6EA8.unk_16 = arg0;
        D_807C6EA8.unk_18 = arg1;
        D_807C6EA8.unk_1C = arg2;
        D_807C6EA8.unk_4C = arg3;
        D_807C6EA8.unk_50 = arg4;
        D_807C6EA8.unk_34 = arg5;
        osSendMesg(&D_807C6E90, NULL, 1);
    }
}

s32 func_80768A5C(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 0;
    sp34.cmdBlock = cmdBlock;
    sp34.direction = direction;
    sp34.lba = lba;
    sp34.unk_08 = vAddr;
    sp34.unk_0C = nLbas;
    sp34.mq = mq;

    func_80767800(sp34);
    return 0;
}

s32 func_80768AF0(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 1;
    sp34.cmdBlock = cmdBlock;
    sp34.direction = direction;
    sp34.lba = lba;
    sp34.unk_08 = vAddr;
    sp34.unk_0C = nLbas;
    sp34.mq = mq;

    func_80767800(sp34);
    return 0;
}

s32 func_80768B88(OSPiHandle* arg0, OSIoMesg* arg1, s32 direction) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 2;
    sp34.unk_10 = arg0;
    sp34.unk_14 = arg1;
    sp34.direction = direction;

    func_80767800(sp34);
    return 0;
}

s32 func_80768C08(OSPiHandle* arg0, OSIoMesg* arg1, s32 direction) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 3;
    sp34.unk_10 = arg0;
    sp34.unk_14 = arg1;
    sp34.direction = direction;

    func_80767800(sp34);
    return 0;
}

extern OSMesg D_80794CD4;

s32 func_80768C88(u16 arg0, u8* arg1, u8* arg2) {
    if (func_80766660(arg0) == -1) {
        return 0;
    }
    while (func_80766788() != 0xFFFF) {}

    if (func_8075F7C0(arg0, arg1, arg2) == 0xFFFF) {
        if ((s32) D_80794CD4 == 0xF2) {
            D_80794CD4 = 0;
        }
        return 0;
    }
    return 1;
}

extern LEODiskID D_8076CB50;
extern LEODiskID D_807C7080;

void func_80768D30(void) {
    SLLeoReadDiskID(&D_8076CB50);
    if (func_80704F44(D_807C7080, D_8076CB50)) {
        SLLeo_mfs_newdisk();
        D_807C7080 = D_8076CB50;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/D_80794E30.s")
