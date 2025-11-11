#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"

extern s8 gGamePaused;

s32 D_i2_800BF040 = 0;

u8 D_i2_800BF044[] = {
    BGM_MUTE_CITY,    BGM_SILENCE,       BGM_SAND_OCEAN,    BGM_DEVILS_FOREST, BGM_BIG_BLUE,   BGM_PORT_TOWN,
    BGM_SECTOR,       BGM_RED_CANYON,    BGM_DEVILS_FOREST, BGM_MUTE_CITY,     BGM_BIG_BLUE,   BGM_WHITE_LAND,
    BGM_SAND_OCEAN,   BGM_SILENCE,       BGM_SECTOR,        BGM_RED_CANYON,    BGM_WHITE_LAND, BGM_MUTE_CITY,
    BGM_RAINBOW_ROAD, BGM_DEVILS_FOREST, BGM_RED_CANYON,    BGM_SAND_OCEAN,    BGM_PORT_TOWN,  BGM_WHITE_LAND,
};

void func_i2_800AABD0(void) {
    func_i3_8005A464();
    func_806F5A50();
    Racer_Init();
    Camera_Init();
    Effects_Init();
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
    Course_Init();
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((gCurrentGhostType == GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE))) {
        Save_LoadGhost(gCourseIndex);
    }
    func_i3_80040158();
    Racer_Init();
    Camera_Init();
    func_8070F0B0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
    func_i3_800617A0();
    Effects_Init();
    Course_LandminesViewInteractDataInit();
    Course_JumpsViewInteractDataInit();
    Course_DecorationsViewInteractDataInit();
    Course_EffectsViewInteractDataInit(false);
    func_i3_8005A464();
    func_i3_InitCourseMinimap();
    func_i3_80044DD0();
    func_i3_InitRacePortraits();
}

s32 Race_Update(void) {
    func_i3_80044750();
    Effects_Update();
    Racer_Update();
    Camera_Update();
    func_i3_80061C2C();
    Course_Update();
    func_8070304C();
    return gGameMode;
}

extern s32 D_8079A35C;
extern s32 D_8079A364;
extern Vtx* gEffectsVtxPtr;
extern Vtx* gEffectsVtxEndPtr;
extern Vtx* gCourseVtxPtr;
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;
extern Camera gCameras[];
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
    gCourseVtxPtr = gGfxPool->courseVtxBuffer;
    gEffectsVtxPtr = gGfxPool->effectsVtxBuffer;
    gEffectsVtxEndPtr = &gGfxPool->effectsVtxBuffer[0x7FF];
    switch (gNumPlayers) {
        case 1:
            gfx = func_i3_8006339C(gfx, 0, SCISSOR_BOX_FULL_SCREEN);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            break;
        case 2:
            gfx = func_i3_8006339C(gfx, 0, SCISSOR_BOX_TOP_HALF);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, SCISSOR_BOX_BOTTOM_HALF);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            break;
        case 3:
            gfx = func_i3_8006339C(gfx, 0, SCISSOR_BOX_TOP_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, SCISSOR_BOX_BOTTOM_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            gfx = func_i3_8006339C(gfx, 2, SCISSOR_BOX_TOP_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 2);
            gfx = Course_GadgetsDraw(gfx, 2);
            break;
        case 4:
            gfx = func_i3_8006339C(gfx, 0, SCISSOR_BOX_TOP_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 0);
            gfx = Course_GadgetsDraw(gfx, 0);
            gfx = func_i3_8006339C(gfx, 1, SCISSOR_BOX_BOTTOM_LEFT_QUARTER);
            gfx = Course_Draw(gfx, 1);
            gfx = Course_GadgetsDraw(gfx, 1);
            gfx = func_i3_8006339C(gfx, 2, SCISSOR_BOX_TOP_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 2);
            gfx = Course_GadgetsDraw(gfx, 2);
            gfx = func_i3_8006339C(gfx, 3, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER);
            gfx = Course_Draw(gfx, 3);
            gfx = Course_GadgetsDraw(gfx, 3);
            break;
    }

    gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
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
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_FULL_SCREEN, 0);
            gfx = Racer_Draw(gfx, 0);
            gfx = func_i3_80057D90(gfx, 0);
            break;
        case 2:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_HALF, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_HALF, 1);
            gfx = Racer_Draw(gfx, 1);
            break;
        case 3:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_LEFT_QUARTER, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_LEFT_QUARTER, 1);
            gfx = Racer_Draw(gfx, 1);
            gSPPerspNormalize(gfx++, gCameras[2].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_RIGHT_QUARTER, 2);
            gfx = Racer_Draw(gfx, 2);
            break;
        case 4:
            gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_LEFT_QUARTER, 0);
            gfx = Racer_Draw(gfx, 0);
            gSPPerspNormalize(gfx++, gCameras[1].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_LEFT_QUARTER, 1);
            gfx = Racer_Draw(gfx, 1);
            gSPPerspNormalize(gfx++, gCameras[2].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_TOP_RIGHT_QUARTER, 2);
            gfx = Racer_Draw(gfx, 2);
            gSPPerspNormalize(gfx++, gCameras[3].perspectiveScale);
            gSPMatrix(gfx++, &D_1000000.unk_1A208[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gfx = Camera_Draw(gfx, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER, 3);
            gfx = Racer_Draw(gfx, 3);
            break;
    }

    return func_i3_8005823C(gfx);
}
