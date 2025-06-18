#include "global.h"

extern volatile unk_807C6EA8 D_807C6EA8;

void func_xk1_8002FB80(void) {
    func_xk1_8002FA50();
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

void func_xk1_8002FBB0(void) {
    D_807C6EA8.unk_04 = 0;
    D_807C6EA8.unk_08 = 0;
    D_807C6EA8.unk_0C = 0;
}

extern unk_806F2400 D_806F2400;
extern u8 D_800D1308[];

void func_xk1_8002FBC8(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((D_806F2400.unk_3C0[i] < 0) && (D_800D1308[func_8070DBE0(i)] == 0)) {
            D_806F2400.unk_00[i].unk_07 = 0x1F;
            D_806F2400.unk_3C0[i] = 0;
        }
    }
    func_8071E0C0();
}

extern unk_806F2400_unk_00 D_xk1_800333D0;

void func_xk1_8002FC70(void) {
    func_xk1_8002FFA0();
    D_xk1_800333D0.unk_07 = 0x1F;
    func_8071E0C0();
}

Gfx* func_xk1_8002FCA0(Gfx* gfx, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u8 arg6, u8 arg7) {

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetFillColor(gfx++, (arg5 << 16) | arg5);
    gDPFillRectangle(gfx++, arg1, arg2, arg1 + arg6 - 1, arg4);
    gDPFillRectangle(gfx++, arg1, arg2, arg3, arg2 + arg7 - 1);
    gDPFillRectangle(gfx++, arg1, arg4 - arg7 + 1, arg3, arg4);
    gDPFillRectangle(gfx++, arg3 - arg6 + 1, arg2, arg3, arg4);

    return gfx;
}

Gfx* func_xk1_8002FDF8(Gfx* gfx, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u8 red, u8 green, u8 blue, u8 alpha, u8 arg9,
                       u8 argA) {

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPFillRectangle(gfx++, arg1, arg2, arg1 + arg9, arg4 + 1);
    gDPFillRectangle(gfx++, arg1, arg2, arg3 + 1, arg2 + argA);
    gDPFillRectangle(gfx++, arg1, arg4 - argA + 1, arg3 + 1, arg4 + 1);
    gDPFillRectangle(gfx++, arg3 - arg9 + 1, arg2, arg3 + 1, arg4 + 1);

    return gfx;
}
