#include "global.h"
#include "ovl_i3.h"

extern GfxPool* gGfxPool;
extern s32 gNumPlayers;

Gfx* func_i3_80059D90(Gfx* gfx, s32 playerIndex) {
    u16 perspectiveScale;
    f32 frustrumCenterY;

    frustrumCenterY = 0;
    if (gNumPlayers == 2) {
        frustrumCenterY = -60.0f;
    }

    Matrix_SetFrustrum(&gGfxPool->unk_1A008[playerIndex], NULL, 45.0f, 16.0f, 4096.0f, SCREEN_WIDTH, 0, SCREEN_HEIGHT,
                       frustrumCenterY, &perspectiveScale);
    gSPPerspNormalize(gfx++, perspectiveScale);
    Matrix_SetLookAt(&gGfxPool->unk_1A108[playerIndex], NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f);
    return gfx;
}
