#include "global.h"
#include "ovl_i3.h"

extern GfxPool* gGfxPool;
extern s32 gNumPlayers;

Gfx* func_i3_80059D90(Gfx* gfx, s32 playerIndex) {
    u16 sp46;
    f32 var_fv0;

    var_fv0 = 0;
    if (gNumPlayers == 2) {
        var_fv0 = -60.0f;
    }

    Matrix_SetFrustrum(&gGfxPool->unk_1A008[playerIndex], NULL, 45.0f, 16.0f, 4096.0f, 320.0f, 0, 240.0f, var_fv0,
                       &sp46);
    gSPPerspNormalize(gfx++, sp46);
    Matrix_SetLookAt(&gGfxPool->unk_1A108[playerIndex], NULL, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f);
    return gfx;
}
