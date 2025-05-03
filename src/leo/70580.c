#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

s32 func_80762D80(u8* arg0) {
    u8* sp1C;

    if ((arg0 == NULL) || (*arg0 == 0)) {
        return -1;
    }
    if (Leo_strlen(arg0) > 20) {
        return -1;
    }

    for (sp1C = arg0; *sp1C != 0; sp1C++) {
        if (*sp1C == 0x2F || *sp1C == 0x2E || *sp1C == 0x3A) {
            return -1;
        }
        if ((((*sp1C >= 0x20 && *sp1C < 0x7F) || (*sp1C > 0xA0 && *sp1C < 0xE0)) && (*sp1C != 0x2F))) {
            continue;
        }
        if (*sp1C >= 0x81 && *sp1C < 0x99) {
            sp1C++;
            if (*sp1C >= 0x40 && *sp1C < 0xFD && *sp1C != 0x7F) {
                continue;
            }
            return -1;
        }
        return -1;
    }

    return 0;
}

u16 D_80794D50[] = {
    0x0000, 0x8142, 0x8175, 0x8176, 0x8141, 0x8145, 0x8392, 0x8340, 0x8342, 0x8344, 0x8346, 0x8348, 0x8383,
    0x8385, 0x8387, 0x8362, 0x815B, 0x8341, 0x8343, 0x8345, 0x8347, 0x8349, 0x834A, 0x834C, 0x834E, 0x8350,
    0x8352, 0x8354, 0x8356, 0x8358, 0x835A, 0x835C, 0x835E, 0x8360, 0x8363, 0x8365, 0x8367, 0x8369, 0x836A,
    0x836B, 0x836C, 0x836D, 0x836E, 0x8371, 0x8374, 0x8377, 0x837A, 0x837D, 0x837E, 0x8380, 0x8381, 0x8382,
    0x8384, 0x8386, 0x8388, 0x8389, 0x838A, 0x838B, 0x838C, 0x838D, 0x838F, 0x8393, 0x814F, 0x814B,
};

s16 func_80762F14(s32 arg0) {
    if ((arg0 > 0x20) && (arg0 < 0x7F)) {
        return (s16) (arg0 - 0x20);
    }
    if ((arg0 > 0xA0) && (arg0 < 0xE0)) {
        return D_80794D50[arg0 - 0xA0];
    }
    return 0;
}

extern OSMesg D_80794CD4;
extern LEOCapacity D_80794D24;

s32 func_80762F80(u8* arg0, u32 arg1, s32 arg2) {
    u32 sp2C = arg1;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C = -1;
    u8* sp18 = arg0;

    func_807648D0();

    while (sp2C != 0) {
        if (func_8075FB38(sp2C, &sp24, &sp20, &sp28) < 0) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        if (func_80766124(sp24 + D_80794D24.startLBA, sp18, sp20, arg2) < 0) {
            return -1;
        }
        func_80764958(&sp1C, sp24, sp20);
        if (sp28 >= sp2C) {
            sp2C = 0;
        } else {
            sp2C -= sp28;
        }
        sp18 += sp28;
    }
    return 0;
}

extern u8 D_80794DD0;

s32 func_80763098(u16 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u16 sp26;

    func_8075F554();
    if ((arg6 < 0) || (arg6 >= 0x100)) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (arg5 & 0x8000) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    arg5 |= 0x4000;
    if ((arg6 > 0) && (arg6 < 0xFE)) {
        arg5 |= 0x200;
    }
    sp26 = func_8075FABC();
    if (sp26 == 0xFFFF) {
        D_80794CD4 = 0xF1;
        return -1;
    }

    if (func_80762F80(arg3, arg4, (arg5 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    func_8075F4C8(arg0, arg1);
    func_8075F2B0(arg5);
    func_8075F4B0(arg4);
    func_8075F454(arg2);
    func_8075F520(arg6);
    func_8075F538(D_80794DD0);
    func_8075F584(sp26);
    func_8075F67C(sp26);
    func_80764914();
    return 0;
}

extern unk_leo_80419EA0 D_80784EF0;
extern u16 D_80794CE0;

s32 func_8076321C(u16 arg0, u8* arg1, u8* arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u16 sp2E;
    u16 sp2C;

    D_80794CD4 = 0;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg4 == 0) {
        D_80794CD4 = 0xF4;
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
    sp2C = func_8075F9E0(arg0);
    if (sp2C == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    D_80794DD0 = 0;
    sp2E = func_8075F7C0(arg0, arg1, arg2);
    if (sp2E != 0xFFFF) {
        D_80794DD0 = D_80784EF0.unk_16B0[sp2E].unk_2A;
        if (func_80766CC0(0xB0, sp2E, 0, 0) < 0) {
            D_80794CD4 = 0x106;
            return -1;
        }
        if (func_80760D78() < arg4) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        if (func_80763098(arg0, "__TMP__", "_!TMP", arg3, arg4, arg5, arg6) < 0) {
            return -1;
        }
        func_80764E90(arg0, arg1, arg2, 0);
        func_80766434(arg0, "__TMP__", "_!TMP", arg1, arg2, 0);
    } else {
        if (func_80766CC0(0xA0, sp2C, 0, 0) < 0) {
            D_80794CD4 = 0x106;
            return -1;
        }
        if (func_80760D78() < arg4) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        if (func_80763098(arg0, arg1, arg2, arg3, arg4, arg5, arg6) < 0) {
            return -1;
        }
    }

    if ((arg7 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern u8 D_8077B4D0[];

s32 func_80763510(u16 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 sp44;
    u32 sp40;
    u32 sp3C;
    u32 sp38;
    u32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    u8* sp24;

    sp40 = arg2;
    sp24 = arg1;
    sp44 = D_80784EF0.unk_16B0[arg0].unk_0C;
    sp30 = D_80784EF0.unk_16B0[arg0].unk_0A;
    func_807648D0();
    func_80764B04(&sp30, sp44, &sp3C);
    if (sp3C != 0) {
        LeoLBAToByte(sp30 + D_80794D24.startLBA, 1, &sp38);
        if (func_80766248(sp30 + D_80794D24.startLBA, D_8077B4D0, 1, arg3) < 0) {
            return -1;
        }

        bcopy(sp24, (sp38 - sp3C) + D_8077B4D0, (sp3C > sp40) ? sp40 : sp3C);
        if (func_80766124(sp30 + D_80794D24.startLBA, D_8077B4D0, 1, arg3) < 0) {
            return -1;
        }
    }

    sp34 = (sp3C > sp40) ? sp40 : sp3C;

    sp40 -= sp34;
    sp24 += sp34;
    while (sp40 != 0) {
        if (func_8075FB38(sp40, &sp2C, &sp28, &sp38) < 0) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        if (func_80766124(sp2C + D_80794D24.startLBA, sp24, sp28, arg3) < 0) {
            return -1;
        }
        func_80764958(&sp30, sp2C, sp28);
        if (sp38 >= sp40) {
            sp40 = 0;
        } else {
            sp40 -= sp38;
        }
        sp24 += sp38;
    }

    func_8075F4B0(sp44 + arg2);
    func_8075F3FC();
    func_8075F584(arg0);
    func_8075F67C(arg0);
    func_80764914();
    return 0;
}

s32 func_807637C4(u16 arg0, u8* arg1, s32 arg2) {
    u32 sp2C;
    s32 sp28;

    if (arg2 == 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    sp2C = D_80784EF0.unk_16B0[arg0].unk_0C + arg2;

    func_807648D0();
    func_80764A4C(D_80784EF0.unk_16B0[arg0].unk_0A);
    if (func_80760E5C() < sp2C) {
        func_80760244();
        D_80794CD4 = 0xF1;
        return -1;
    }
    sp28 = D_80784EF0.unk_16B0[arg0].unk_00;

    if (func_80763510(arg0, arg1, arg2, (sp28 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    return 0;
}

s32 func_80763904(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4, s32 arg5) {
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
    if (func_80766CC0(0xB0, sp1E, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_807637C4(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 D_80794CD0;

s32 func_80763A64(u16 arg0, u8* arg1, s32 arg2, s32 arg3) {
    D_80794CD4 = 0;
    if (func_80760C6C() < 0) {
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
    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_807637C4(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern u16 D_80793650[];

s32 func_80763BDC(u16 arg0, u8* arg1, s32 arg2, u32 arg3, s32 arg4) {
    s32 sp4C;
    u32 sp48;
    u32 sp44;
    s32 sp40;
    u32 sp3C;
    s32 sp38;
    s32 pad[2];
    s32 sp2C;
    s32 i;
    u8* sp24;

    sp48 = arg3;
    sp24 = arg1;
    sp4C = D_80784EF0.unk_16B0[arg0].unk_0C;
    sp38 = D_80784EF0.unk_16B0[arg0].unk_0A;
    func_807648D0();
    func_80764C54(&sp38, arg2, &sp44);
    if (sp44 != 0) {
        LeoLBAToByte(sp38 + D_80794D24.startLBA, 1, &sp40);
        if (func_80766248(sp38 + D_80794D24.startLBA, D_8077B4D0, 1, arg4) < 0) {
            return -1;
        }

        bcopy(sp24, (sp40 - sp44) + D_8077B4D0, (sp44 > sp48) ? sp48 : sp44);
        if (func_80766124(sp38 + D_80794D24.startLBA, D_8077B4D0, 1, arg4) < 0) {
            return -1;
        }
        sp3C = (sp44 > sp48) ? sp48 : sp44;

        sp48 -= sp3C;
        sp24 += sp3C;
        if (sp48 != 0) {
            sp38 = D_80793650[sp38];
            if (sp38 == 0xFFFF) {
                D_80794CD4 = 0xF3;
                return -1;
            }
        }
    }

    while (sp48 != 0) {
        sp2C = func_80764D4C(sp38);

        for (i = 1; i <= sp2C; i++) {
            LeoLBAToByte(sp38 + D_80794D24.startLBA, i, &sp40);
            if (sp40 >= sp48) {
                break;
            }
        }
        if (sp40 == sp48) {
            if (func_80766124(sp38 + D_80794D24.startLBA, sp24, i, arg4) < 0) {
                return -1;
            }
            sp48 = 0;
        } else {
            if (--i > 0) {
                LeoLBAToByte(sp38 + D_80794D24.startLBA, i, &sp40);
                if (func_80766124(sp38 + D_80794D24.startLBA, sp24, i, arg4) < 0) {
                    return -1;
                }
                sp38 += i;
                sp48 -= sp40;
                sp24 += sp40;
            } else {
                break;
            }
        }

        if (i < sp2C) {
            break;
        }
        sp38 = (sp38 + sp2C) - 1;
        if ((sp38 = D_80793650[sp38]) == 0xFFFF) {
            D_80794CD4 = 0xF3;
            return -1;
        }
    }

    if (sp48 != 0) {
        if (func_80766248(sp38 + D_80794D24.startLBA, D_8077B4D0, 1, arg4) < 0) {
            return -1;
        }
        bcopy(sp24, D_8077B4D0, sp48);
        if (func_80766124(sp38 + D_80794D24.startLBA, D_8077B4D0, 1, arg4) < 0) {
            return -1;
        }
    }

    func_8075F3FC();
    func_8075F584(arg0);
    return 0;
}

s32 func_80764048(u16 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 sp2C;

    if (arg3 == 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (D_80784EF0.unk_16B0[arg0].unk_0C < arg2 + arg3) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    sp2C = D_80784EF0.unk_16B0[arg0].unk_00;

    if (func_80763BDC(arg0, arg1, arg2, arg3, (sp2C & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    return 0;
}

s32 func_80764154(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4, s32 arg5, s32 arg6) {
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
    if (func_80766CC0(0xB0, sp1E, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_80764048(sp1E, arg3, arg4, arg5) < 0) {
        return -1;
    }
    if ((arg6 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_807642B8(u16 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_80794CD4 = 0;
    if (func_80760C6C() < 0) {
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
    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_80764048(arg0, arg1, arg2, arg3) < 0) {
        return -1;
    }
    if ((arg4 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80764434(u16 arg0, u8* arg1, u32 arg2, s32 arg3) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;

    sp30 = 0;
    sp2C = 0;
    if (arg3 == 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (D_80784EF0.unk_16B0[arg0].unk_0C < arg2 + arg3) {
        sp30 = D_80784EF0.unk_16B0[arg0].unk_0C - arg2;
        sp2C = (arg2 + arg3) - D_80784EF0.unk_16B0[arg0].unk_0C;
    } else {
        sp30 = arg3;
    }
    sp34 = D_80784EF0.unk_16B0[arg0].unk_00;

    if (func_80763BDC(arg0, arg1, arg2, sp30, (sp34 & 0x400) ? 1 : 0) < 0) {
        return -1;
    }
    if (sp2C != 0) {
        if (func_80763510(arg0, arg1 + sp30, sp2C, (sp34 & 0x400) ? 1 : 0) < 0) {
            return -1;
        }
    }
    return 0;
}

s32 func_807645EC(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4, s32 arg5, s32 arg6) {
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
    if (func_80766CC0(0xB0, sp1E, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_80764434(sp1E, arg3, arg4, arg5) < 0) {
        return -1;
    }
    if ((arg6 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80764750(u16 arg0, u8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    D_80794CD4 = 0;
    if (func_80760C6C() < 0) {
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
    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (func_80764434(arg0, arg1, arg2, arg3) < 0) {
        return -1;
    }
    if ((arg4 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}
