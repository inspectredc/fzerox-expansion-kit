#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern unk_leo_804285D0 D_80793620;
extern OSMesg D_80794CD4;

s32 func_80766370(u16 arg0, u8* arg1, u8* arg2) {
    s32 sp1C;

    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = func_8075F600(arg0);
    func_8075F3A0(arg1);
    func_8075F454(arg2);
    if (func_8075F7C0(D_80793620.unk_02, D_80793620.unk_10, D_80793620.unk_24) != 0xFFFF) {
        D_80794CD4 = 0x105;
        return -1;
    }
    func_8075F584(arg0);
    return 0;
}

extern s32 D_80794CDC;

s32 func_80766434(u16 arg0, u8* arg1, u8* arg2, u8* arg3, u8* arg4, s32 arg5) {
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
    if (func_80766370(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 D_80794CD0;
extern unk_leo_80419EA0 D_80784EF0;

s32 func_8076650C(u16 arg0, u8* arg1, s32 arg2, s32 arg3) {
    D_80794CDC = 4;
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
    if (func_80766370(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (func_807608A4() < 0)) {
        return -1;
    }
    return 0;
}
