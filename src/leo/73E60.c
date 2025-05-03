#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern OSMesg D_80794CD4;
extern u16 D_80794CE0;
extern u16 D_807C6E60;
extern u16 D_807C6E62;
extern s32 D_80794CD0;
extern unk_leo_80419EA0 D_80784EF0;

s32 func_80766660(u16 arg0) {
    UNUSED s32 pad;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
        if ((arg0 == 0xFFFE) || (arg0 == 0xFFFF)) {
            D_80794CD4 = 0x104;
            return -1;
        }
    }
    if ((arg0 == 0xFFFF) || (func_8075F9E0(arg0) == 0xFFFF)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766CC0(0x48, 0, 0, arg0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    D_807C6E62 = 0;
    D_807C6E60 = arg0;
    return 0;
}

u16 func_80766788(void) {
    while (D_807C6E62 < D_80794CD0) {
        if ((D_80784EF0.unk_16B0[D_807C6E62].unk_02 == D_807C6E60) && (D_80784EF0.unk_16B0[D_807C6E62].unk_00 & 0x4000)) {
            return D_807C6E62++;
        }
        D_807C6E62++;
    }

    return -1;
}
