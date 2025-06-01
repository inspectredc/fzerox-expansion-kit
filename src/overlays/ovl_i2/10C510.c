#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"

extern s8 gGamePaused;

s32 D_i2_800BF040 = 0;
UNUSED s8 D_i2_800BF044[] = { 0, 1, 2, 5, 4, 3, 7, 6, 5, 0, 4, 8, 2, 1, 7, 6, 8, 0, 9, 5, 6, 2, 3, 8, 0 };

void func_i2_800AABD0(void) {
    func_i3_8005A464();
    func_806F5A50();
    func_8071D48C();
    func_807160A0();
    func_i2_800AB6B0();
    gGamePaused = false;
    func_i3_80044DD0();
    func_i3_ResetLivesChangeCounter();
    func_i3_InitRacePortraits();
}

extern s16 D_8076C7A8;
extern s32 gGameMode;
extern s32 gCurrentGhostType;
extern s32 gCourseIndex;

void Race_Init(void) {
    D_8076C7A8 = D_i2_800BF040 = 3;
    gGamePaused = false;
    if ((gGameMode == GAMEMODE_TIME_ATTACK) && (gCurrentGhostType == GHOST_STAFF)) {
        Save_LoadGhost(gCourseIndex);
    }
    func_i2_800B934C();
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((gCurrentGhostType == GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE))) {
        Save_LoadGhost(gCourseIndex);
    }
    func_i3_80040158();
    func_8071D48C();
    func_807160A0();
    func_8070F0B0(gCourseCtx.courseData.venue, gCourseCtx.courseData.skybox);
    func_i3_800617A0();
    func_i2_800AB6B0();
    func_806F9774();
    func_806FB3AC();
    func_806FBBC8();
    func_806FE8F8(0);
    func_i3_8005A464();
    func_i3_InitCourseMinimap();
    func_i3_80044DD0();
    func_i3_InitRacePortraits();
}

s32 Race_Update(void) {
    func_i3_80044750();
    func_i2_800AB82C();
    func_80726554();
    func_80717294();
    func_i3_80061C2C();
    func_800B94D8();
    func_8070304C();
    return gGameMode;
}

extern s32 D_8079A35C;
extern s32 D_8079A364;
extern Vtx* D_807A15DC;
extern Vtx* D_807A15E0;
extern Vtx* D_800D65D0;
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;
extern Player gPlayers[];
extern FrameBuffer* gFrameBuffers[];
extern s16 D_8076C7A4;
extern s32 gNumPlayers;
extern Gfx D_8076CF10[];
extern Gfx D_8076CE28[];

Gfx* Race_Draw(Gfx* gfx) {

    if (D_i2_800BF040 != 0) {
        D_i2_800BF040--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

        if (D_8076C7A4 == 2) {
            gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A35C]));
        } else {
            gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                             OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
        }

        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }
    if (gNumPlayers == 1) {
        gSPDisplayList(gfx++, D_8076CF10);
    } else {
        gSPDisplayList(gfx++, D_8076CE28);
    }

    gDPPipeSync(gfx++);

    if (D_8076C7A4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A35C]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
    }
    D_800D65D0 = gGfxPool->unk_1A308;
    D_807A15DC = gGfxPool->unk_2A308;
    D_807A15E0 = &gGfxPool->unk_2A308[0x7FF];
    switch (gNumPlayers) {
        case 1:
            gfx = func_i3_8006339C(gfx, 0, 0);
            gfx = func_i2_800BDE60(gfx, 0);
            gfx = func_806F9DB4(gfx, 0);
            break;
        case 2:
            gfx = func_i3_8006339C(gfx, 0, 1);
            gfx = func_i2_800BDE60(gfx, 0);
            gfx = func_806F9DB4(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, 2);
            gfx = func_i2_800BDE60(gfx, 1);
            gfx = func_806F9DB4(gfx, 1);
            break;
        case 3:
            gfx = func_i3_8006339C(gfx, 0, 5);
            gfx = func_i2_800BDE60(gfx, 0);
            gfx = func_806F9DB4(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, 7);
            gfx = func_i2_800BDE60(gfx, 1);
            gfx = func_806F9DB4(gfx, 1);
            gfx = func_i3_8006339C(gfx, 2, 6);
            gfx = func_i2_800BDE60(gfx, 2);
            gfx = func_806F9DB4(gfx, 2);
            break;
        case 4:
            gfx = func_i3_8006339C(gfx, 0, 5);
            gfx = func_i2_800BDE60(gfx, 0);
            gfx = func_806F9DB4(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, 7);
            gfx = func_i2_800BDE60(gfx, 1);
            gfx = func_806F9DB4(gfx, 1);
            gfx = func_i3_8006339C(gfx, 2, 6);
            gfx = func_i2_800BDE60(gfx, 2);
            gfx = func_806F9DB4(gfx, 2);
            gfx = func_i3_8006339C(gfx, 3, 8);
            gfx = func_i2_800BDE60(gfx, 3);
            gfx = func_806F9DB4(gfx, 3);
            break;
    }

    gSPLoadUcodeL(gfx++, gspF3DFLX_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);

    if (D_8076C7A4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A35C]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
    }

    switch (gNumPlayers) {
        case 1:
            gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 0, 0);
            gfx = func_80727F54(gfx, 0);
            gfx = func_i3_80057D90(gfx, 0);
            break;
        case 2:
            gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 1, 0);
            gfx = func_80727F54(gfx, 0);
            gSPPerspNormalize(gfx++, gPlayers[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 2, 1);
            gfx = func_80727F54(gfx, 1);
            break;
        case 3:
            gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 5, 0);
            gfx = func_80727F54(gfx, 0);
            gSPPerspNormalize(gfx++, gPlayers[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 7, 1);
            gfx = func_80727F54(gfx, 1);
            gSPPerspNormalize(gfx++, gPlayers[2].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 6, 2);
            gfx = func_80727F54(gfx, 2);
            break;
        case 4:
            gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 5, 0);
            gfx = func_80727F54(gfx, 0);
            gSPPerspNormalize(gfx++, gPlayers[1].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 7, 1);
            gfx = func_80727F54(gfx, 1);
            gSPPerspNormalize(gfx++, gPlayers[2].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 6, 2);
            gfx = func_80727F54(gfx, 2);
            gSPPerspNormalize(gfx++, gPlayers[3].unk_118);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = func_80713E38(gfx, 8, 3);
            gfx = func_80727F54(gfx, 3);
            break;
    }

    return func_i3_8005823C(gfx);
}
