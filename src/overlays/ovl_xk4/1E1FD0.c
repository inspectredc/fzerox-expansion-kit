#include "global.h"
#include "fzx_assets.h"

Lights1 D_xk4_800F1A90 = gdSPDefLights1(50, 50, 30, 255, 200, 160, 0, 84, 84);

Vp D_xk4_800F1AA8 = {
    640, 480, 511, 0, 640, 480, 511, 0,
};

extern s32 D_8076C77C;
extern s16 D_8076C7A8;

void func_xk4_800D8260(void) {
    Audio_DDBgmReady(BGM_EAD_DEMO);
    Audio_DDBgmStart(BGM_EAD_DEMO);
    func_xk4_800D6F38();
    D_8076C77C = 2;
    D_8076C7A8 = 3;
}

extern s32 D_800BEE14;
extern s32 D_8076C77C;

extern GfxPool D_8024E260[];
extern s32 D_8079A35C;
extern s32 gGameMode;
extern s32 D_8076C7C0;
extern u16 gInputButtonPressed;
extern GfxPool* gGfxPool;

s32 func_xk4_800D82A4(void) {
    gGfxPool = &D_8024E260[D_8079A35C];
    if (D_800BEE14 != 0) {
        return gGameMode;
    }
    Controller_SetGlobalInputs(&gSharedController);
    if (gInputButtonPressed & BTN_START) {
        Audio_DDBgmStop();
        D_8076C77C = 1;
        return D_8076C7C0;
    }

    return gGameMode;
}

extern Gfx D_8076CAF8[];
extern u8 D_xk4_800ECA78[];
extern GfxPool D_1000000;
extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A364;

Gfx* func_xk4_800D8348(Gfx* gfx) {
    static s32 D_xk4_800F1AB8 = 4800;
    static s32 D_xk4_800F1ABC = -550;
    static s32 D_xk4_800F1AC0 = 0;
    s32 temp_lo;
    s32 i;
    u16 spFE;
    s32 pad[2];

    gSPDisplayList(gfx++, D_3000338);
    gSPDisplayList(gfx++, D_8076CAF8);

    gfx = func_xk4_800D7530(gfx, gFrameBuffers[D_8079A364], 0, 0, 0x60, 0, 0, 0);
    gSPDisplayList(gfx++, D_8014940);

    for (i = 0; i < 64; i++) {
        gDPLoadTextureBlock(gfx++, D_xk4_800ECA78 + i * SCREEN_WIDTH, G_IM_FMT_RGBA, G_IM_SIZ_16b, 160, 1, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, 24 << 2, (i + 32) << 2, 184 << 2, ((i + 1) + 32) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    if (SQ(gControllers[gPlayerControlPorts[0]].stickX) > 100) {
        D_xk4_800F1AC0 += gControllers[gPlayerControlPorts[0]].stickX / 10;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_Z) {
        D_xk4_800F1AC0 = 0;
    }
    temp_lo = (s32) (D_xk4_800F1AC0 * 0x1000) / 360;
    func_806F7FCC(gGfxPool->unk_36628, NULL, 1.0f, 1.0f, 1.0f, SIN(temp_lo), 0.0f, COS(temp_lo), 0.0f, 1.0f, 0.0f, 0.0f,
                  0.0f, 0.0f);

    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) {
        D_xk4_800F1AB8 += 50;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) {
        D_xk4_800F1AB8 -= 50;
    }
    if (D_xk4_800F1AB8 < 1600) {
        D_xk4_800F1AB8 = 1600;
    }
    if (D_xk4_800F1AB8 > 4800) {
        D_xk4_800F1AB8 = 4800;
    }

    D_xk4_800F1ABC = ((4800 - D_xk4_800F1AB8) / 3) - 550;

    gSPViewport(gfx++, &D_xk4_800F1AA8);

    func_806F9384(gGfxPool->unk_1A008, NULL, 60.0f, 64.0f, 8192.0f, 320.0f, -80.0f, 240.0f, 0.0f, &spFE);

    gSPPerspNormalize(gfx++, spFE);

    gSPMatrix(gfx++, D_1000000.unk_1A008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    func_806F8FE0(gGfxPool->unk_1A108, NULL, 500.0f, D_xk4_800F1ABC, D_xk4_800F1AB8, 500.0f, D_xk4_800F1ABC, 0, 0, 1,
                  0);

    gSPMatrix(gfx++, D_1000000.unk_1A108, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    gSPMatrix(gfx++, gGfxPool->unk_36628, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_3000400);

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

    gSPNumLights(gfx++, NUMLIGHTS_1);
    gSPSetLights1(gfx++, D_xk4_800F1A90);

    gSPClipRatio(gfx++, FRUSTRATIO_4);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);

    func_xk4_800D81F4(&gfx);
    return gfx;
}
