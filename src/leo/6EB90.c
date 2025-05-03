#include "leo/unk_leo.h"
#include "leo/leo_functions.h"

extern OSMesg D_80794CD4;
extern u16 D_80794CE0;

s32 func_80761390(s32 arg0) {
    u16 sp1E;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (func_8075F904(0xFFFE, "/") != 0xFFFF) {
        D_80794CD4 = 0x100;
        return -1;
    }
    sp1E = func_8075FABC();
    if (sp1E != 0) {
        D_80794CD4 = 0x103;
        return -1;
    }
    func_8075F554();
    func_8075F4C8(0xFFFE, "/");
    func_8075F2B0(0x8000);
    func_8075F438(0);
    func_8075F538(0);
    func_8075F584(sp1E);
    if ((arg0 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_8076148C(u16 arg0) {
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        return 0;
    }
    if ((arg0 == 0xFFFC) && ((arg0 = func_80761590(0xFFFB), (arg0 == 0xFFFE)) || (arg0 == 0xFFFF))) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (func_8075F9E0(arg0) == 0xFFFF) {
        return 0xF2;
    }
    D_80794CE0 = arg0;
    return 0;
}

void func_8076155C(u16 arg0) {
    func_8076148C(arg0);
    return;
}

extern unk_leo_80419EA0 D_80784EF0;

s32 func_80761590(u16 arg0) {
    u16 sp1E;

    if (func_80760C6C() < 0) {
        return 0xFFF0;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0) {
        return 0xFFFE;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }
    sp1E = func_8075F9E0(arg0);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return 0xFFFF;
    }
    return D_80784EF0.unk_16B0[arg0].unk_02;
}

s32 func_80761668(u16 arg0, u16 arg1) {
    u16 sp1E;
    u16 sp1C;
    u16 sp1A;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg1 == 0xFFFB) {
        arg1 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }
    if (arg1 == 0xFFFC) {
        arg1 = func_80761590(0xFFFB);
    }
    if (arg0 == 0) {
        D_80794CD4 = 0x104;
        return -1;
    }
    if (arg0 == 0xFFFE) {
        D_80794CD4 = 0x104;
        return -1;
    }
    if (arg0 == arg1) {
        D_80794CD4 = 0x104;
        return -1;
    }
    sp1C = func_8075F9E0(arg0);
    if (sp1C == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    sp1A = func_8075F9E0(arg1);
    if (sp1A == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766CC0(0xB2, sp1C, sp1A, arg0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1E = D_80784EF0.unk_16B0[sp1C].unk_02;
    if (sp1E == arg1) {
        return 0;
    }
    if (func_8075F904(arg1, D_80784EF0.unk_16B0[sp1C].unk_10) != 0xFFFF) {
        D_80794CD4 = 0x100;
        return -1;
    }
    D_80784EF0.unk_16B0[sp1C].unk_02 = arg1;

    return 0;
}

extern s32 D_80794CD0;

s32 func_807618B8(u16 arg0, s32 arg1) {
    u16 i;
    u16 sp1C;
    s32 sp18;

    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = D_80784EF0.unk_16B0[arg0].unk_0A;

    
    for (i = 0, sp18 = 0; i < D_80794CD0; i++) {
        if (D_80784EF0.unk_16B0[i].unk_00 == 0) {
            continue;
        }
        if (D_80784EF0.unk_16B0[i].unk_02 == sp1C) {
            sp18++;
        }
    }
    if (sp18 != 0) {
        D_80794CD4 = 0x103;
        return -1;
    }
    bzero(&D_80784EF0.unk_16B0[arg0], 0x30);
    if ((arg1 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 D_80794CDC;

s32 func_80761A3C(u16 arg0, s32 arg1, s32 arg2) {
    u16 sp26;
    UNUSED s32 pad[2];
    s32 sp18;

    sp18 = 0;
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
    if (arg0 == 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (arg0 == 0xFFFE) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    sp26 = func_8075F9E0(arg0);
    if (sp26 == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_807618B8(sp26, arg2) < 0) {
        return -1;
    }
    return 0;
}
