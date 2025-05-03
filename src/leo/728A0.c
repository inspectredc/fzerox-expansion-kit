#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern u8 D_8077B4D0[];
extern s32 D_80794CDC;
extern LEOCapacity D_80794D24;
extern unk_leo_80419EA0 D_80784EF0;

s32 func_807650A0(s32 arg0, u8* arg1, u32 arg2, s32* arg3, OSMesg* arg4, s32* arg5, s32 arg6) {
    s32 sp24;
    s32 sp20;
    u32 sp1C;

    D_80794CDC = 1;
    sp24 = func_80764D4C(arg0);

    for (sp20 = 1; sp20 <= sp24; sp20++) {
        LeoLBAToByte(arg0 + D_80794D24.startLBA, sp20, &sp1C);
        if (sp1C > arg2) {
            break;
        }
    }

    sp20--;
    if (sp20 > 0) {
        if (func_80766248(arg0 + D_80794D24.startLBA, arg1, sp20, arg6) < 0) {
            return -1;
        }
        LeoLBAToByte(arg0 + D_80794D24.startLBA, sp20, &sp1C);
    } else {
        if (func_80766248(arg0 + D_80794D24.startLBA, D_8077B4D0, 1, arg6) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, arg1, arg2);
        sp1C = arg2;
    }

    *arg3 = D_80784EF0.unk_3C[arg0 + sp20 - 1];
    *arg4 = arg1 + sp1C;

    if (arg2 <= sp1C) {
        *arg5 = 0;
    } else {
        *arg5 = arg2 - sp1C;
    }
    return 0;
}

s32 func_8076527C(u16 arg0, u8* arg1, s32 arg2) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;

    sp38 = 0;
    sp4C = D_80784EF0.unk_16B0[arg0].unk_0A;
    while (arg2 != 0) {
        sp44 = D_80784EF0.unk_16B0[arg0].unk_00;

        if (func_807650A0(sp4C, arg1, arg2, &sp48, &sp40, &sp3C, (sp44 & 0x400) ? 1 : 0) < 0) {
            return -1;
        }
        sp4C = sp48;
        arg1 = sp40;
        arg2 = sp3C;
    }

    return 0;
}

extern OSMesg D_80794CD4;

s32 func_80765380(u16 arg0, u8* arg1, u32 arg2) {
    u32 sp1C;
    s32 sp18;

    if (func_80766CC0(0x70, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = D_80784EF0.unk_16B0[arg0].unk_0C;
    if ((arg2 == 0) || (sp1C < arg2)) {
        arg2 = sp1C;
    }
    return sp18 = func_8076527C(arg0, arg1, arg2);
}

extern u16 D_80794CE0;

s32 func_8076543C(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4) {
    u16 sp1E;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (func_80762D80(arg1) < 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }
    sp1E = func_8075F7C0(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    return func_80765380(sp1E, arg3, arg4);
}

extern s32 D_80794CD0;

s32 func_8076553C(u16 arg0, u8* arg1, s32 arg2) {
    s32 sp1C;

    sp1C = func_80760C6C();
    if (sp1C < 0) {
        return -1;
    }
    if ((arg0 < 0) || (arg0 > D_80794CD0)) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (!(D_80784EF0.unk_16B0[arg0].unk_00 & 0x4000)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (D_80784EF0.unk_16B0[arg0].unk_00 & 0x8000) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    return func_80765380(arg0, arg1, arg2);
}

extern u16 D_80793650[];

s32 func_8076564C(u16 arg0, u8* arg1, s32 arg2, u32 arg3) {
    s32 sp4C;
    u32 sp48;
    u32 sp44;
    s32 sp40;
    u32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u8* sp28;

    sp48 = arg3;
    sp28 = arg1;
    sp4C = D_80784EF0.unk_16B0[arg0].unk_0C;
    sp34 = D_80784EF0.unk_16B0[arg0].unk_0A;
    if (D_80784EF0.unk_16B0[arg0].unk_00 & 0x400) {
        sp40 = 1;
    } else {
        sp40 = 0;
    }
    D_80794CDC = 1;
    func_807648D0();
    func_80764C54(&sp34, arg2, &sp44);
    if (sp44 != 0) {
        LeoLBAToByte(sp34 + D_80794D24.startLBA, 1, &sp3C);
        if (func_80766248(sp34 + D_80794D24.startLBA, D_8077B4D0, 1, sp40) < 0) {
            return -1;
        }

        bcopy((sp3C - sp44) + D_8077B4D0, arg1, (sp44 > sp48) ? sp48 : sp44);
        sp38 = (sp44 > sp48) ? sp48 : sp44;
        sp28 += sp38;
        sp48 -= sp38;
        if (sp48 != 0) {
            sp34 = D_80793650[sp34];
            if (sp34 == 0xFFFF) {
                D_80794CD4 = 0xF3;
                return -1;
            }
        }
    }

    while (sp48 != 0) {
        sp30 = func_80764D4C(sp34);

        for (sp2C = 1; sp2C <= sp30; sp2C++) {
            LeoLBAToByte(sp34 + D_80794D24.startLBA, sp2C, &sp3C);
            if (sp3C < sp48) {
                continue;
            }

            if (sp3C == sp48) {
                if (func_80766248(sp34 + D_80794D24.startLBA, sp28, sp2C, sp40) < 0) {
                    return -1;
                }
                sp48 = 0;
                break;
            }
            if (--sp2C == 0) {
                break;
            }

            LeoLBAToByte(sp34 + D_80794D24.startLBA, sp2C, &sp3C);
            if (func_80766248(sp34 + D_80794D24.startLBA, sp28, sp2C, sp40) < 0) {
                return -1;
            }
            sp34 += sp2C;
            sp48 -= sp3C;
            sp28 += sp3C;
            break;
        }

        if (sp2C <= sp30) {
            break;
        }
        if (func_80766248(sp34 + D_80794D24.startLBA, sp28, sp30, sp40) < 0) {
            return -1;
        }
        LeoLBAToByte(sp34 + D_80794D24.startLBA, sp30, &sp3C);
        sp48 -= sp3C;
        sp28 += sp3C;
        sp34 = (sp34 + sp30) - 1;

        if ((sp34 = D_80793650[sp34]) == 0xFFFF) {
            D_80794CD4 = 0xF3;
            return -1;
        }
    }

    if (sp48 != 0) {
        if (func_80766248(sp34 + D_80794D24.startLBA, D_8077B4D0, 1, sp40) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, sp28, sp48);
    }

    return 0;
}

s32 func_80765AF8(u16 arg0, u8* arg1, s32 arg2, u32 arg3) {
    s32 sp1C;

    if (func_80766CC0(0x70, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = D_80784EF0.unk_16B0[arg0].unk_0C;
    if ((arg3 == 0) || (sp1C - arg2) < arg3) {
        arg3 = sp1C - arg2;
    }
    return func_8076564C(arg0, arg1, arg2, arg3);
}

s32 func_80765BC8(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4, s32 arg5) {
    u16 sp1E;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (func_80762D80(arg1) < 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }
    sp1E = func_8075F7C0(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    return func_80765AF8(sp1E, arg3, arg4, arg5);
}

void func_80765CC0(LEODiskID* arg0, u8* arg1, s32 arg2) {
    s32 j;
    s32 i;
    u8 diskIdBuf[0x20];
    u8* sp1C;

    sp1C = arg1;
    bcopy(arg0, diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }
    *sp1C ^= 0x59;

    *sp1C = (((*sp1C & 0x1F) << 3) | (*sp1C & 0xE0) >> 5) & 0xFF;

    for (j = 1; j < arg2; j++) {
        sp1C[j] =
            ((sp1C[j] + (((((sp1C[j - 1] ^ 0xBF) & 0xF) << 4) | (((sp1C[j - 1] ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF) ^
            diskIdBuf[j & 0x1F];
    }

    *sp1C = *sp1C ^ diskIdBuf[0x17];

    i = 0;
    while (i < arg2) {
        sp1C[i] = (sp1C[i] ^ 0xFE) + 0x6F;
        i = ((sp1C[i] & 0xF) >> 1) + i + 4;
    }
}

void func_80765E70(LEODiskID* arg0, u8* arg1, s32 arg2) {
    s32 j;
    s32 i;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u8 diskIdBuf[0x20];
    u8* sp18;

    sp18 = arg1;
    bcopy(arg0, &diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }

    i = 0;
    while (i < arg2) {
        sp44 = ((sp18[i] & 0xF) >> 1) + i + 4;
        sp18[i] = ((sp18[i] - 0x6F) & 0xFF) ^ 0xFE;
        i = sp44;
    }
    *sp18 = *sp18 ^ diskIdBuf[0x17];
    sp40 = *sp18;

    for (j = 1; j < arg2; j++) {
        sp3C = sp18[j];
        sp3C ^= diskIdBuf[j & 0x1F];
        sp3C = (sp3C - (((((sp40 ^ 0xBF) & 0xF) << 4) | (((sp40 ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF;
        sp40 = sp18[j];
        sp18[j] = sp3C;
    }

    *sp18 = (((*sp18 & 7) << 5) | ((*sp18 & 0xF8) >> 3)) & 0xFF;
    *sp18 ^= 0x59;
}

s32 func_80766074(u8* arg0, s32 arg1) {
    LEODiskID diskId;

    if (func_80760260(&diskId) < 0) {
        return -1;
    }
    func_80765CC0(&diskId, arg0, arg1);
    return 0;
}

s32 func_807660CC(u8* arg0, s32 arg1) {
    LEODiskID diskId;

    if (func_80760260(&diskId) < 0) {
        return -1;
    }
    func_80765CC0(&diskId, arg0, arg1);
    return 0;
}

s32 func_80766124(s32 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 i;
    s32 sp20;
    s32 sp1C;
    u8* sp18;

    if (arg3 != 0) {
        sp20 = arg0;
        sp18 = arg1;
        for (i = 0; i < arg2; i++, sp20++) {

            LeoLBAToByte(sp20, 1, &sp1C);
            if (D_8077B4D0 != arg1) {
                bcopy(sp18, D_8077B4D0, sp1C);
            }
            func_80766074(D_8077B4D0, sp1C);
            if (func_80762768(sp20, D_8077B4D0, 1) < 0) {
                return -1;
            }
            sp18 += sp1C;
        }
    } else {
        return func_80762768(arg0, arg1, arg2);
    }

    return 0;
}

s32 func_80766248(s32 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 i;
    s32 sp20;
    s32 sp1C;
    u8* sp18;

    if (arg3 != 0) {
        sp20 = arg0;
        sp18 = arg1;
        for (i = 0; i < arg2; i++, sp20++) {
            LeoLBAToByte(sp20, 1, &sp1C);
            if (func_80762570(sp20, D_8077B4D0, 1) < 0) {
                return -1;
            }
            func_807660CC(D_8077B4D0, sp1C);
            if (D_8077B4D0 != arg1) {
                bcopy(D_8077B4D0, sp18, sp1C);
            }
            sp18 += sp1C;
        }
    } else {
        return func_80762570(arg0, arg1, arg2);
    }
    return 0;
}
