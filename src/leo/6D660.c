#include "leo/unk_leo.h"
#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "libc/stdbool.h"

extern OSMesg D_80794D08[1];
extern OSMesgQueue D_80794D0C;

void func_8075FE60(void) {
    osCreateMesgQueue(&D_80794D0C, D_80794D08, ARRAY_COUNT(D_80794D08));
}

extern OSMesg D_80794CD4;
extern LEODiskID D_80794CE8;

s32 func_8075FE98(void) {
    s32 i = 0;

    LeoResetClear();

    while (true) {
        if (func_80760260(&D_80794CE8) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch ((s32) D_80794CD4) {
            case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
                D_80794CD4 = 0xF9;
                return -1;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                break;
            default:
                return -1;
        }
    }

    return 0;
}

s32 func_8075FF6C(void) {
    return func_8075FE98();
}

s32 func_8075FF9C(void) {
    s32 i = 0;

    while (true) {
        if (func_80760260(&D_80794CE8) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch ((s32) D_80794CD4) {
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return -1;
        }

        return -1;
    }

    if (bcmp(&leoBootID, &D_80794CE8, sizeof(LEODiskID)) == 0) {
        return 0;
    }

    D_80794CD4 = 0xF5;
    return -1;
}

extern s32 D_80794CC4;
extern s32 D_80794D30;
extern s32 D_80794CD8;
extern char D_80794D40[2];
extern char D_80794D44[4];

s32 func_8076007C(s32 region, OSMesg* cmdBuf, s32 cmdMsgCount) {
    s32 i = 0;

    D_80794CC4 = 0;
    func_80766860();

    if ((D_80794D40[0] == 0) || (D_80794D44[0] == 0)) {
        D_80794D30 = 0x107;
        D_80794CD4 = 0x107;
        return -1;
    }

    func_8075FE60();
    func_80760244();
    switch (region) {
        case LEO_MANAGER_REGION_NONE:
            D_80794CD8 = 0xD;
            D_80794CD4 = LeoCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_JP:
            D_80794CD8 = 0xE;
            D_80794CD4 = LeoCJCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_US:
            D_80794CD8 = 0xE;
            D_80794CD4 = LeoCACreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        default:
            D_80794CD4 = 0xF4;
            return -1;
            break;
    }

    if ((s32) D_80794CD4 != LEO_ERROR_GOOD) {
        return -1;
    }

    if (region == LEO_MANAGER_REGION_NONE) {

    } else {
        return func_8075FF6C();
    }

    D_80794D30 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
    return 0;
}

extern unk_leo_80419EA0 D_80784EF0;

void func_80760244(void) {
    D_80784EF0.unk_00[0] = 0;
}

extern OSMesgQueue D_80794D0C;

s32 func_80760260(LEODiskID* arg0) {
    LEOCmd sp1C;

    D_80794CD8 = 8;
    osInvalDCache(arg0, 4);
    if (gLeoReadDiskIDFunc(&sp1C, arg0, &D_80794D0C) < 0) {
        D_80794CD4 = 0xF7;
        return -1;
    }
    return func_80762390();
}

void func_807602E4(void) {
    LeoGetKAdr(0);
    LeoGetAAdr(0, NULL, NULL, NULL);
}

extern s32 D_80794CD0;
extern LEOCapacity D_80794D24;

s32 func_80760320(void) {
    s32 sp1C;

    D_80794CD4 = LeoReadCapacity(&D_80794D24, OS_WRITE);
    if ((s32) D_80794CD4 != LEO_ERROR_GOOD) {
        return -1;
    }
    LeoLBAToByte(D_80794D24.startLBA, 3, &sp1C);
    D_80794CD0 = (sp1C - 0x16B0) / 48;
    return 0;
}

extern u16 D_80794CE0;

s32 func_807603A8(void) {
    if (func_80760260(&D_80794CE8) != 0) {
        return -1;
    }
    if (D_80794D30 == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (func_80760A84() < 0) {
        return -1;
    }
    if (func_80760320() < 0) {
        return -1;
    }
    if (D_80794D24.nbytes == 0) {
        D_80794D30 = 0xF6;
        D_80794CD4 = 0xF6;
        return -1;
    }
    D_80794CE0 = 0;
    func_80760244();
    D_80794D30 = LEO_ERROR_GOOD;
    return 0;
}

s32 func_8076049C(void) {
    if (D_80794D24.startLBA == 0x58A) {
        return 0;
    }
    if (D_80794D24.startLBA == 0x7AE) {
        return 1;
    }
    if (D_80794D24.startLBA == 0x9D2) {
        return 2;
    }
    if (D_80794D24.startLBA == 0xBF6) {
        return 3;
    }
    if (D_80794D24.startLBA == 0xE1A) {
        return 4;
    }
    if (D_80794D24.startLBA == 0xFF8) {
        return 5;
    }
    return 6;
}

s32 func_8076055C(void) {
    LEOStatus sp1F;

    D_80794CD4 = LEO_ERROR_GOOD;
    D_80794CD8 = 15;
    D_80794CD4 = LeoTestUnitReady(&sp1F);
    if (!(sp1F & 1)) {
        if ((s32) D_80794CD4 == LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED) {}
        return 1;
    }
    if ((s32) D_80794CD4 == LEO_SENSE_MEDIUM_NOT_PRESENT) {
        return 0;
    }
    return -1;
}

extern char D_80794D34[]; // "64dd-Multi"

s32 func_807605F0(s32 arg0, u8 arg1, u8* arg2) {
    LEODiskTime sp28;
    s32 i;
    s32 sp20;
    s32 sp1C;

    sp20 = 0;
    if (arg0 == 1) {
        sp20 = 1;
    } else if (arg0 == 2) {
        sp20 = 0;
    } else {
        D_80794CD4 = 0xF4;
        return -1;
    }

    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (func_80760C2C() < 0) {
        return -1;
    }
    if (func_8076055C() <= 0) {
        return -1;
    }
    if ((sp20 == 0) && (func_80760C6C() < 0)) {
        sp20 = 1;
    }
    for (i = 0; i < 60; i++) {
        ((u8*) &D_80784EF0)[i] = 0;
    }
    Leo_bcopy(D_80784EF0.unk_00, D_80794D34, 10);
    D_80784EF0.unk_0A[0] = '0';
    D_80784EF0.unk_0A[1] = '1';
    D_80784EF0.unk_0A[2] = '0';
    D_80784EF0.unk_0A[3] = '1';
    D_80784EF0.unk_0E = arg1;
    D_80784EF0.unk_0F = func_8076049C();
    if (arg2 != NULL) {
        Leo_bcopy(&D_80784EF0.unk_10, arg2, 20);
    }
    D_80784EF0.unk_28 = 0;
    func_807620C0(&sp28);
    func_80762184(&sp28, &D_80784EF0.unk_24);
    if (sp20 != 0) {
        bzero(D_80784EF0.unk_3C, sizeof(D_80784EF0.unk_3C));
    } else {
        for (i = 0; i < ARRAY_COUNT(D_80784EF0.unk_3C); i++) {
            if (D_80784EF0.unk_3C[i] != 0xFFFD) {
                D_80784EF0.unk_3C[i] = 0;
            }
        }
    }
    LeoLBAToByte(D_80794D24.startLBA, 3, &sp1C);
    bzero(D_80784EF0.unk_16B0, sp1C - 0x16B0);
    func_80761390(0);
    D_80794CE0 = 0;
    D_80794D30 = LEO_ERROR_GOOD;
    if (func_807608A4() < 0) {
        func_80760244();
        return -1;
    } else {
        return 0;
    }
}

extern s32 D_80794CDC;
extern u16 D_80784F18;

s32 func_807608A4(void) {
    D_80794CDC = 0;
    if (func_807609F4() < 0) {
        return -1;
    }
    D_80784F18++;
    func_80760FE4();
    D_80794CDC = 2;
    if (func_80762768(D_80794D24.startLBA, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    D_80794CDC = 3;
    if (func_80762768(D_80794D24.startLBA + 3, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 func_80760974(void) {
    if (func_80762570(D_80794D24.startLBA, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    if (func_807610AC() < 0) {
        D_80794D30 = 0x10A;
        D_80794CD4 = 0x10A;
        return -1;
    }
    return 0;
}

extern char D_80794D34[];

s32 func_807609F4(void) {
    s32 i;
    s32 j = 0;

    D_80794CD4 = 0;

    for (i = 0; i < 10; i++) {
        if (D_80784EF0.unk_00[i] != D_80794D34[i]) {
            j++;
        }
    }

    if (j != 0) {
        D_80794CD4 = 0xF0;
        return -1;
    }
    return 0;
}

s32 func_80760A84(void) {
    if (D_80794CE8.ramUsage != 1) {
        D_80794CD4 = 0x111;
        return -1;
    }
}

s32 func_80760ABC(void) {
    s32 i = 0;

    D_80794CD4 = 0;
    if (func_80760C2C() < 0) {
        return -1;
    }

    while (true) {
        if (((i++ < 5) ^ 1)) {
            return -1;
        }

        if (func_80760974() == 0) {
            break;
        }

        if ((s32) D_80794CD4 == LEO_ERROR_GOOD) {
            break;
        }

        if ((s32) D_80794CD4 == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
            if (func_80760260(&D_80794CE8) < 0) {
                return -1;
            }
        } else {
            if ((s32) D_80794CD4 == LEO_ERROR_UNRECOVERED_READ_ERROR) {
                D_80794CD4 = 0xF0;
                return 0;
            }
            if ((s32) D_80794CD4 == 0x10A) {
                D_80794CD4 = 0xF0;
                return 0;
            }
            return -1;
        }
    }

    osWritebackDCache(D_80784EF0.unk_00, 10);

    if (func_807609F4() == 0) {
        return 1;
    }

    D_80794CD4 = 0xF0;

    return 0;
}

s32 func_80760C2C(void) {
    if (D_80794D30 != LEO_ERROR_GOOD) {
        D_80794CD4 = D_80794D30;
        return -1;
    }
    return 0;
}

s32 func_80760C6C(void) {
    s32 err;

    D_80794CD4 = 0;
    if (func_80760C2C() < 0) {
        return -1;
    }
    err = func_8076055C();
    if (err <= 0) {
        return -1;
    }

    if ((s32) D_80794CD4 == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        func_80760244();
        D_80794D30 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
        return -1;
    } else {
        osWritebackDCache(&D_80784EF0, sizeof(unk_leo_80419EA0));
        if (func_807609F4() == 0) {
            return 0;
        }
        if ((s32) D_80794CD4 == 0xF0) {
            if (func_80760974() < 0) {
                return -1;
            }
            if (func_807609F4() == 0) {
                return 0;
            }
        }
    }

    return -1;
}

s32 func_80760D78(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_80760C6C() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 6; i <= (D_80794D24.endLBA - D_80794D24.startLBA); i++) {
        if (D_80784EF0.unk_3C[i] != 0) {
            continue;
        }
        LeoLBAToByte(i + D_80794D24.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

extern u16 D_80793650[];

s32 func_80760E5C(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_80760C6C() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 6; i <= (D_80794D24.endLBA - D_80794D24.startLBA); i++) {
        if (D_80793650[i] != 0) {
            continue;
        }
        LeoLBAToByte(i + D_80794D24.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

void func_80760F40(u8* arg0, u8* arg1) {
    if (arg0 != 0) {
        Leo_bcopy(D_80794D40, arg0, 2);
    }
    if (arg1 != 0) {
        Leo_bcopy(D_80794D44, arg1, 4);
    }
}

void func_i1_80404B54(void) {
    D_80784EF0.unk_28++;
}

void func_i1_80404B78(void) {
    D_80784EF0.unk_28 = 0;
}

extern s32 D_80784F1C;

s32 func_80760FE4(void) {
    s32 sp24;
    s32* sp20;
    u32 i;
    s32 sp18;

    sp20 = (s32*) &D_80784EF0;
    sp18 = 0;
    D_80784F1C = 0;
    LeoLBAToByte(D_80794D24.startLBA, 3, &sp24);

    for (i = 0; i < (sp24 / 4); i++) {
        sp18 ^= *sp20++;
    }
    D_80784F1C = sp18;
    return 0;
}

s32 func_807610AC(void) {
    s32 sp34;
    s32* sp30;
    u32 i;
    s32 sp28;

    sp30 = (s32*) &D_80784EF0;
    sp28 = 0;

    LeoLBAToByte(D_80794D24.startLBA, 3, &sp34);

    for (i = 0; i < (sp34 / 4); i++) {
        if (*sp30 != 0) {}
        sp28 ^= *sp30++;
    }
    sp28 ^= D_80784F1C;
    sp28 ^= D_80784F1C;

    return (sp28 != 0) ? -1 : 0;
}

s32 func_807611B8(void) {
    UNUSED s32 pad;
    if (func_80762570(D_80794D24.startLBA, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    func_80760FE4();
    if (func_80762768(D_80794D24.startLBA, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 func_80761238(void) {
    UNUSED s32 pad;

    D_80794CDC = 1;
    if (func_80762570(D_80794D24.startLBA + 3, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    if (func_807609F4() < 0) {
        return -1;
    }
    D_80784F18++;
    func_80760FE4();
    D_80794CDC = 2;
    if (func_80762768(D_80794D24.startLBA, (u8*) &D_80784EF0, 3) < 0) {
        return -1;
    }
    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    return 0;
}

s32 func_8076131C(void) {
    LEOCmd sp1C;

    if (gLeoSpdlMotorFunc(&sp1C, 4, &D_80794D0C) < 0) {
        D_80794CD4 = 0xF7;
        return -1;
    }
    return func_80762390();
}
