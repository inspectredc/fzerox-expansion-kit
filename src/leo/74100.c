#include "leo/unk_leo.h"
#include "leo/leo_functions.h"

extern OSMesg D_80794CD4;
extern unk_leo_80419EA0 D_80784EF0;
extern u16 D_80794CE0;

s32 func_80766900(u16 arg0, u16 arg1, u16 arg2) {
    u16 sp6;

    if (!(D_80784EF0.unk_16B0[arg0].unk_00 & 0x4000) || (D_80784EF0.unk_16B0[arg0].unk_00 & 0x8000)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if ((arg1 & 0x8000) || (arg2 & 0x4000)) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    sp6 = D_80784EF0.unk_16B0[arg0].unk_00;
    sp6 |= arg1;
    sp6 &= arg2 ^ 0xFFFF;
    D_80784EF0.unk_16B0[arg0].unk_00 = sp6;
    return 0;
}

s32 func_80766A04(u16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (func_80766900(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80766A98(u16 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
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
    if (func_80766900(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80766BC0(u16 arg0, u8* arg1, u8* arg2) {
    u16 sp1E;

    D_80794CD4 = 0;
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
    return D_80784EF0.unk_16B0[sp1E].unk_00;
}

extern u8 D_80794D40[2];
extern u8 D_80794D44[4];
extern LEODiskID D_80794CE8;

s32 func_80766CC0(s32 arg0, u16 arg1, u16 arg2, u16 arg3) {
    u16 sp1E;
    s32 sp18;

    sp1E = 0xFFFF;
    if (arg0 & 0x80) {
        if (D_80784EF0.unk_0E & 0x80) {
            return -1;
        }
        if ((D_80784EF0.unk_0E & 0x20) &&
            ((Leo_bcmp(D_80794CE8.company, D_80794D40, 2) != 0) || (Leo_bcmp(&D_80794CE8, D_80794D44, 4) != 0))) {
            return -1;
        }
        if ((arg0 & 0x20) && (D_80784EF0.unk_16B0[arg1].unk_00 & 0x2000)) {
            return -1;
        }
        if ((arg0 & 2) && (D_80784EF0.unk_16B0[arg2].unk_00 & 0x2000)) {
            return -1;
        }
        if ((arg0 & 0x10) && (D_80784EF0.unk_16B0[D_80784EF0.unk_16B0[arg1].unk_02].unk_00 & 0x2000)) {
            return -1;
        }
        if (arg0 & 8) {
            sp1E = func_8075F9E0(arg3);
            if (D_80784EF0.unk_16B0[sp1E].unk_00 & 0x2000) {
                return -1;
            }
        }
        if (arg0 & 4) {
            if ((sp1E = arg1) == 0xFFFF) {
                sp1E = func_8075F9E0(arg3);
            }
            if (D_80784EF0.unk_16B0[sp1E].unk_00 & 0x2000) {
                return -1;
            }
        }
    }

    sp1E = 0xFFFF;
    if (arg0 & 0x40) {
        sp18 = func_8075F714(arg1);
        if ((D_80784EF0.unk_0E & 0x40) &&
            ((Leo_bcmp(D_80794CE8.company, D_80794D40, 2) != 0) || (Leo_bcmp(&D_80794CE8, D_80794D44, 4) != 0))) {
            return -1;
        }
        if ((arg0 & 0x20) && (D_80784EF0.unk_16B0[arg1].unk_00 & 0x1000) && (sp18 < 0)) {
            return -1;
        }
        if ((arg0 & 2) && (D_80784EF0.unk_16B0[arg2].unk_00 & 0x1000) && (sp18 < 0)) {
            return -1;
        }
        if ((arg0 & 0x10) && (D_80784EF0.unk_16B0[D_80784EF0.unk_16B0[arg1].unk_02].unk_00 & 0x1000)) {
            if (func_8075F714(D_80784EF0.unk_16B0[arg1].unk_02) < 0) {
                return -1;
            }
        }
        if (arg0 & 8) {
            sp1E = func_8075F9E0(arg3);
            if ((D_80784EF0.unk_16B0[sp1E].unk_00 & 0x1000)) {
                if (func_8075F714(sp1E) < 0) {
                    return -1;
                }
            }
        }
        if (arg0 & 4) {
            if (sp1E == 0xFFFF) {
                arg1 = func_8075F9E0(arg3);
            }
            if ((D_80784EF0.unk_16B0[sp1E].unk_00 & 0x2000)) {
                if (func_8075F714(sp1E) < 0) {
                    return -1;
                }
            }
        }
    }
    return 0;
}

extern LEOCapacity D_80794D24;
extern u16 D_80784F2C[];

void func_80767170(s32* arg0, s32* arg1) {
    s32 i;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = 0;
    sp20 = 0;

    for (i = 6; i < D_80794D24.endLBA - D_80794D24.startLBA; i++) {
        LeoLBAToByte(i + D_80794D24.startLBA, 1, &sp1C);
        sp28 = D_80784F2C[i];
        if (sp28 == 0) {
            sp20 += sp1C;
        }
        if ((sp28 == 0xFFFF) || (sp28 < 0x7FFF)) {
            sp24 += sp1C;
        }
    }
    if (arg1 != NULL) {
        *arg1 = sp20;
    }
    if (arg0 != NULL) {
        *arg0 = sp24;
    }
}

extern u16 D_80793650[];
extern u8 D_8077B4D0[];
extern u8 D_807801E0[];

s32 func_8076729C(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp2C = *arg0;
    sp28 = *arg1;
    sp24 = *arg2;
    sp20 = 0;
    sp18 = arg3;
    while (sp18 > 0) {
        if (sp28 == sp2C) {
            func_80762570(sp24 + D_80794D24.startLBA, D_8077B4D0, 1);
            sp2C = 0;
            LeoLBAToByte(sp24 + D_80794D24.startLBA, 1, &sp28);
            sp24 = D_80793650[sp24];
        }
        sp1C = sp28 - sp2C;
        if (sp1C < sp18) {
            bcopy(&D_8077B4D0[sp2C], &D_807801E0[sp20], sp1C);
            sp2C += sp1C;
            sp20 += sp1C;
        } else {
            bcopy(&D_8077B4D0[sp2C], &D_807801E0[sp20], sp18);
            sp2C += sp18;
            sp20 += sp18;
        }
        sp18 = arg3 - sp20;
    }
    *arg0 = sp2C;
    *arg1 = sp28;
    *arg2 = sp24;
    return 0;
}

extern unk_leo_804285D0 D_80793620;

s32 func_80767470(s32 arg0, s32 arg1, u16 arg2) {
    u16 sp4E;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp3C = -1;
    sp34 = 0;
    sp30 = 0;
    bcopy(&D_80784EF0.unk_16B0[arg0], &D_80793620, sizeof(unk_leo_804285D0));
    if (D_80784EF0.unk_16B0[arg0].unk_00 & 0x200) {
        if (D_80784EF0.unk_16B0[arg0].unk_29 == 0) {
            D_80794CD4 = 0x110;
            return -1;
        }
    }
    sp48 = D_80784EF0.unk_16B0[arg0].unk_0C;
    sp4E = func_8075FABC();
    if (sp4E == 0xFFFF) {
        D_80794CD4 = 0xF1;
        return -1;
    }
    func_80767170(0, &sp44);
    if (sp44 < sp48) {
        D_80794CD4 = 0xF1;
        return -1;
    }
    sp40 = D_80784EF0.unk_16B0[arg0].unk_0A;
    func_807648D0();
    while (sp48 > 0) {
        func_8075FB38(sp48, &sp2C, &sp28, &sp24);
        if (sp2C == -1) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        sp20 = 0;
        while ((sp20 < sp28) && (sp48 > 0)) {
            LeoLBAToByte(sp2C + D_80794D24.startLBA + sp20, 1U, &sp38);
            if (sp48 < sp38) {
                sp38 = sp48;
            }
            func_8076729C(&sp34, &sp30, &sp40, sp38);
            func_80762768(sp2C + D_80794D24.startLBA + sp20, D_807801E0, 1);
            sp1C = sp2C + sp20;
            if (sp3C < 0) {
                D_80793620.unk_0A = sp1C;
            } else {
                D_80793650[sp3C] = sp1C;
            }
            sp3C = sp1C;
            sp20 += 1;
            sp48 -= sp38;
        }
        D_80793650[sp3C] = -1;
    }

    if (sp3C < 0) {
        D_80793620.unk_0A = -1;
    } else {
        D_80793650[sp3C] = -1;
    }
    func_80764914();
    func_8075F4C8(arg2, arg1);
    func_8075F538(0);
    func_8075F454(D_80784EF0.unk_16B0[arg0].unk_24);
    func_8075F584(sp4E);
}
