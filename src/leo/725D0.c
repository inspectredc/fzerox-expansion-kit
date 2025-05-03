#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern unk_leo_80419EA0 D_80784EF0;
extern OSMesg D_80794CD4;

s32 func_80764DD0(u16 arg0) {
    s32 sp1C;

    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    func_807648D0();
    sp1C = D_80784EF0.unk_16B0[arg0].unk_0A;
    if (func_80764A4C(sp1C) < 0) {
        return -1;
    }
    func_80764914();
    D_80784EF0.unk_16B0[arg0].unk_00 = 0;
    return 0;
}

extern s32 D_80794CDC;

s32 func_80764E90(u16 arg0, u8* arg1, u8* arg2, s32 arg3) {
    u16 sp1E;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    sp1E = func_8075F7C0(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80764DD0(sp1E) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 D_80794CD0;

s32 func_80764F60(u16 arg0, s32 arg1) {
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 < 0 || arg0 > D_80794CD0) {
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
    if (func_80764DD0(arg0) < 0) {
        return -1;
    }
    if ((arg1 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}
