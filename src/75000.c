#include "global.h"

extern unk_807C6F10 D_807C6F10[];
extern vs32 D_80794E28;
extern vs32 D_80794E2C;
extern OSMesgQueue D_807C6E90;

void func_80767800(unk_807C6F10 arg0) {
    OSIntMask prevMask;
    s32 temp_lo;

    do {} while (D_80794E28 == ((D_80794E2C + 1) & 7));
    prevMask = osGetIntMask();
    osSetIntMask(1);
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

typedef struct unk_807C6EA8 {
    s8 unk_00[0x4];
    s8 unk_04;
    s32 unk_08;
    s32 unk_0C;
} unk_807C6EA8;

extern unk_807C6EA8 D_807C6EA8;

void func_80767940(void) {
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767958.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767E30.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767E98.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767F14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767F78.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80767FE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076805C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807680A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807680EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076814C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807681C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768244.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807682C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076833C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807683B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768434.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807684AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076852C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768574.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807685D8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768638.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076869C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076870C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076877C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807687E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768844.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807688D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_8076894C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_807689BC.s")

s32 func_80768A5C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 0;
    sp34.unk_1C = arg0;
    sp34.unk_18 = arg1;
    sp34.unk_04 = arg2;
    sp34.unk_08 = arg3;
    sp34.unk_0C = arg4;
    sp34.unk_20 = arg5;

    func_80767800(sp34);
    return 0;
}

s32 func_80768AF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 1;
    sp34.unk_1C = arg0;
    sp34.unk_18 = arg1;
    sp34.unk_04 = arg2;
    sp34.unk_08 = arg3;
    sp34.unk_0C = arg4;
    sp34.unk_20 = arg5;

    func_80767800(sp34);
    return 0;
}

s32 func_80768B88(s32 arg0, s32 arg1, s32 arg2) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 2;
    sp34.unk_10 = arg0;
    sp34.unk_14 = arg1;
    sp34.unk_18 = arg2;

    func_80767800(sp34);
    return 0;
}

s32 func_80768C08(s32 arg0, s32 arg1, s32 arg2) {
    unk_807C6F10 sp34;

    sp34.unk_00 = 3;
    sp34.unk_10 = arg0;
    sp34.unk_14 = arg1;
    sp34.unk_18 = arg2;

    func_80767800(sp34);
    return 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768C88.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/func_80768D30.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/75000/D_80794E30.s")
