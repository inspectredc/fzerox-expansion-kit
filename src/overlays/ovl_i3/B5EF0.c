#include "global.h"
#include "ovl_i3.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_assets.h"
#include "fzx_font.h"

extern s32 sMenuStateFlags;
extern s32 D_i3_8006D0A8;
extern s32 D_i3_8006D0A0;
extern s32 D_i3_8006D098;

void func_i3_80044720(void) {
    sMenuStateFlags = D_i3_8006D0A8 = 0;
}

void func_i3_80044738(void) {
    D_i3_8006D098 = D_i3_8006D0A0 = 0;
}

extern s16 D_800D5810[];
extern s16 D_8076C814;
extern s32 D_i2_800BF040;
extern s16 sRaceFinishSaveTriggered;
extern s16 sMenuOptionTriggered;
extern s16 D_i3_8006D096;
extern s8 gGamePaused;
extern s32 gNumPlayers;
extern s32 gGameMode;
extern s32 gTotalRacers;
extern s32 gCourseIndex;
extern s32 gPlayerControlPorts[];

void func_i3_80044750(void) {
    s32 i;

    if (sMenuStateFlags != 0) {
        if (sMenuStateFlags & MENU_STATE_PAUSE_GAME) {
            gGamePaused = true;
            func_8074204C(1);
            func_8074122C(12);
            func_806F5A50();
        }
        if (sMenuStateFlags & MENU_STATE_UNPAUSE_GAME) {
            gGamePaused = false;
            D_i2_800BF040 = 4;
            for (i = 0; i < gNumPlayers; i++) {
                gControllers[gPlayerControlPorts[i]].unk_72 = 1;
            }
            func_8074204C(0);
            func_8074122C(13);
        }
        if ((sMenuStateFlags & MENU_STATE_RACE_FINISH_SAVE) && !sRaceFinishSaveTriggered) {
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if (gCourseIndex < COURSE_X_1) {
                    func_8071A88C();
                    func_i3_80067208();
                }
                if (gCourseIndex < COURSE_EDIT_1) {
                    Save_SaveCourseRecordProfiles(gCourseIndex);
                }
            } else if (gGameMode == GAMEMODE_GP_RACE) {
                func_i3_80067150(gCourseIndex);
            } else if (gGameMode == GAMEMODE_DEATH_RACE) {
                func_8071A88C();
                Save_SaveDeathRaceProfiles();
            }
            sRaceFinishSaveTriggered = true;
        }
        if (!sMenuOptionTriggered && (D_i3_8006D096 == 0)) {
            if (sMenuStateFlags & MENU_STATE_RETRY) {
                func_807263A4();
                D_8076C814 = 1;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_QUIT) {
                func_807263A4();
                D_8076C814 = 2;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_MACHINE) {
                func_807263A4();
                D_8076C814 = 7;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_CHANGE_COURSE) {
                func_807263A4();
                D_8076C814 = 3;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_SETTINGS) {
                func_807263A4();
                D_8076C814 = 15;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_100) {
                func_807263A4();
                D_8076C814 = 6;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_GP_NEXT_COURSE) {
                if ((gNumPlayers == 1) && (gGameMode == GAMEMODE_GP_RACE)) {
                    for (i = 0; i < gTotalRacers; i++) {
                        D_800D5810[i] = gRacers[i].position;
                    }
                }
                func_807263A4();
                D_8076C814 = 4;
                sMenuOptionTriggered = true;
            }
            if (sMenuStateFlags & MENU_STATE_400) {
                func_807263A4();
                D_8076C814 = 5;
                sMenuOptionTriggered = true;
            }
        }
    }
    if (D_i3_8006D096 == 0) {
        func_i3_80044720();
    } else {
        D_i3_8006D096--;
    }
}

Gfx* func_i3_DrawBeveledBox(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue,
                            s32 alpha) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);
    // Draw Border At Top and Bottom
    gSPTextureRectangle(gfx++, (left + 1) << 2, (top - 1) << 2, (right - 1) << 2, top << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, (left + 1) << 2, bottom << 2, (right - 1) << 2, (bottom + 1) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

Gfx* func_i3_80044CCC(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern Vec3f D_i3_8006D1C8;
extern unk_800CD970 D_8076D788[];
extern s16 D_i3_8006D148[4][3];
extern s16 D_i3_8006D160[4];
extern f32 D_i3_8006D168[4][3];
extern Vec3f D_i3_8006D198[];
extern s32 D_i3_8006D5D8;
extern s32 D_i3_8006D0B4;
extern s16 gRacersRemaining;
extern s32 sPlayer1Lives;
extern s16 sMenuIsBusy;
extern s16 D_i3_8006D096;
extern TexturePtr D_i3_8006D1D8[8][3];
extern u16 D_i3_8006D238[8][3];
extern s16 D_i3_8006D268[4];
extern bool D_i3_8006D330[4];
extern s32 D_i3_8006D350[4];
extern s32 D_i3_8006D364;
extern s32 D_i3_8006D374;
extern s32 D_i3_8006D398[4];
extern s32 D_i3_8006D3A8[4];
extern s32 D_i3_8006D3B8[4];
extern s32 D_i3_8006D3C8[4];
extern f32 D_i3_8006D3D8[4];
extern f32 D_i3_8006D3E8[4];
extern s32 D_i3_8006D3F8[4];
extern s32 D_i3_8006D408[4];
extern f32 D_i3_8006D418[4];
extern f32 D_i3_8006D428[4];
extern u8* sRetireTexture;
extern u8* sRetirePalette;
extern u8* sWinnerTexture;
extern u8* sWinnerPalette;
extern u8* sLoserTexture;
extern u8* sLoserPalette;
extern s32 gFastestGhostIndex;
extern f32 D_i3_8006D4A0;
extern s32 D_i3_8006D4A8[4];
extern s32 D_i3_8006D4B8[4];
extern s32 D_i3_8006D4C8[4];
extern f32 D_i3_8006D4E0;
extern s32 D_8006D544;
extern s32 D_i3_8006D550[4];
extern s32 D_i3_8006D560;
extern s32 D_i3_8006D564;
extern s32 D_i3_8006D568;
extern s32 sRaceMenuOptionIndex;
extern s32 D_i3_8006D570;
extern s32 D_i3_8006D574;
extern s32 D_i3_8006D578;
extern bool sSaveGhostMenuOpen;
extern s32 D_i3_8006D58C;
extern s32 sOverwriteGhostOption;
extern s32 D_i3_8006D590;
extern s32 D_i3_8006D594;
extern s32 D_i3_8006D598;
extern s32 D_i3_8006D59C;
extern s32 sGhostSaveTimer;
extern s16 D_i3_8006D5A4;
extern Racer* D_i3_8006D5A8;
extern f32 D_i3_8006D5B0;
extern f32 D_i3_8006D5B4;
extern s32 D_i3_8006D5B8[4];
extern s32 D_i3_8006D5C8[4];
extern s32 D_8006CFF0;
extern bool D_i3_8006D0B0;
extern s16 gPlayerLives[];
extern GhostRacer* gFastestGhostRacer;

void func_i3_80044DD0(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 index2;
    s32 temp_a1;
    s32 pad[2];

    D_i3_8006D1C8.x = Math_Rand2() % 256 / 255.0f * 0.3f + 6.04f - 0.15f;
    D_i3_8006D1C8.y = Math_Rand1() % 256 / 255.0f * 0.3f + 4.18f - 0.15f;
    D_i3_8006D1C8.z = Math_Rand2() % 256 / 255.0f * 0.3f + 5.12f - 0.15f;

    gRacersRemaining = gTotalRacers;
    D_i3_8006D5D8 = 0;

    for (i = 0; i < 5; i++) {
        D_i3_8006D5D8 += D_8076D788[i].unk_02;
    }

    for (i = 0; i < 4; i++) {
        D_i3_8006D160[i] = 0;

        for (j = 0; j < 3; j++) {
            D_i3_8006D148[i][j] = Math_Rand2() % 6;
            D_i3_8006D168[i][j] = (Math_Rand2() % 10) * -1.0f;
        }

        D_i3_8006D398[i] = D_i3_8006D5B8[i] = D_i3_8006D5C8[i] = 0;

        D_i3_8006D198[i].x = D_i3_8006D1C8.x;
        D_i3_8006D198[i].y = D_i3_8006D1C8.y;
        D_i3_8006D198[i].z = D_i3_8006D1C8.z;


        D_i3_8006D3F8[i] = D_i3_8006D4C8[i] = D_i3_8006D4A8[i] = D_i3_8006D4B8[i] = D_i3_8006D3B8[i] =
            D_i3_8006D330[i] = D_i3_8006D350[i] = D_i3_8006D550[i] = D_i3_8006D3C8[i] = D_i3_8006D3A8[i] =
                D_i3_8006D268[i] = D_i3_8006D408[i] = 0;

        D_i3_8006D0B4 = 0;

        D_i3_8006D3E8[i] = D_i3_8006D428[i] = 0.0f;
        D_i3_8006D418[i] = -20.0f;
        D_i3_8006D3D8[i] = 10.0f;
    }

    sGhostSaveTimer = D_i3_8006D590 = sSaveGhostMenuOpen = D_i3_8006D59C = D_i3_8006D594 = D_i3_8006D364 =
        D_i3_8006D374 = D_8006D544 = D_i3_8006D560 = D_i3_8006D564 = sRaceMenuOptionIndex = D_i3_8006D574 =
            sMenuIsBusy = sRaceFinishSaveTriggered = D_i3_8006D5A4 = sMenuOptionTriggered = D_i3_8006D096 =
                D_i3_8006D0B0 = D_8006CFF0 = D_i3_8006D568 = 0;

    D_i3_8006D4E0 = D_i3_8006D4A0 = 0.0f;
    D_i3_8006D598 = D_i3_8006D58C = 90;
    D_i3_8006D578 = D_i3_8006D570 = 60;
    D_i3_8006D5A4 = 0;
    sPlayer1Lives = gPlayerLives[0];
    sRetireTexture = func_i2_800AE7C4(aRetireTex, TEX_SIZE(aRetireTex, sizeof(u8)), 0, 0, 0);
    sRetirePalette = func_i2_800AE7C4(aRetireTLUT, TEX_SIZE(aRetireTLUT, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aMenuTextTLUT, 0x200, 0, 0, 0);
    func_i2_800AE7C4(aMenuRetryTex, TEX_SIZE(aMenuRetryTex, sizeof(u8)), 0, 1, 0);
    func_i2_800AE7C4(aMenuSettingsTex, TEX_SIZE(aMenuSettingsTex, sizeof(u8)), 0, 1, 0);
    func_i2_800AE7C4(aMenuQuitTex, TEX_SIZE(aMenuQuitTex, sizeof(u8)), 0, 1, 0);
    func_i2_800AE7C4(aMenuContinueTex, TEX_SIZE(aMenuContinueTex, sizeof(u8)), 0, 1, 0);

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        func_i2_800AE7C4(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), 0, 0, 0);
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        func_i2_800AE7C4(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuGhostSaveTex, TEX_SIZE(aMenuGhostSaveTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuOverwriteData1Tex, TEX_SIZE(aMenuOverwriteData1Tex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuSavedTex, TEX_SIZE(aMenuSavedTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuSavingTex, TEX_SIZE(aMenuSavingTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuNewGhostTex, TEX_SIZE(aMenuNewGhostTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuSavedGhostTex, TEX_SIZE(aMenuSavedGhostTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuCannotSaveGhostTex, TEX_SIZE(aMenuCannotSaveGhostTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuNoGamePakTex, TEX_SIZE(aMenuNoGamePakTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuNoDiskTex, TEX_SIZE(aMenuNoDiskTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuOverwriteData2Tex, TEX_SIZE(aMenuOverwriteData2Tex, sizeof(u8)), 0, 1, 0);
        sLoserTexture = func_i2_800AE7C4(aLoserTex, TEX_SIZE(aLoserTex, sizeof(u8)), 0, 0, 0);
        sLoserPalette = func_i2_800AE7C4(aLoserTLUT, TEX_SIZE(aLoserTLUT, sizeof(u16)), 0, 0, 0);
        func_i3_8004C5A4();
        if (gFastestGhostIndex >= 0) {
            D_i3_8006D5A8 = gFastestGhostRacer->racer;
            D_i3_8006D5B0 = D_i3_8006D5A8->lapDistance;
            D_i3_8006D5B4 = gCurrentCourseInfo->length * -1.0f;
        }
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P) ||
        (gGameMode == GAMEMODE_TIME_ATTACK)) {
        sWinnerTexture = func_i2_800AE7C4(aWinnerTex, TEX_SIZE(aWinnerTex, sizeof(u8)), 0, 0, 0);
        sWinnerPalette = func_i2_800AE7C4(aWinnerTLUT, TEX_SIZE(aWinnerTLUT, sizeof(u16)), 0, 0, 0);
    }
    if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) ||
        (gGameMode == GAMEMODE_VS_4P)) {
        func_i2_800AE7C4(aMenuChangeMachineTex, TEX_SIZE(aMenuChangeMachineTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(aMenuChangeCourseTex, TEX_SIZE(aMenuChangeCourseTex, sizeof(u8)), 0, 1, 0);
        func_i2_800AE7C4(D_F25D858, TEX_SIZE(D_F25D858, sizeof(u16)), 0, 0, 0);
        func_i2_800AE7C4(D_F25E060, TEX_SIZE(D_F25E060, sizeof(u16)), 0, 0, 0);
        func_i2_800AE7C4(D_F25E868, TEX_SIZE(D_F25E868, sizeof(u16)), 0, 0, 0);

        for (j = 0; j < 3; j++) {
            D_i3_8006D238[0][j] = 32;
            D_i3_8006D238[1][j] = 32;
            D_i3_8006D238[2][j] = 32;
            D_i3_8006D238[3][j] = 32;
            D_i3_8006D238[4][j] = 30;
            D_i3_8006D238[5][j] = 30;
            D_i3_8006D238[6][j] = 31;
            D_i3_8006D238[7][j] = 31;

            for (i = 0; i < gNumPlayers; i++) {
                D_i3_8006D238[i][j] = gRacers[i].character;
            }

            for (i = 0; i < 3; i++) {
                for (k = 1; k < 4; k++) {
                    if (i != k) {
                        if (D_i3_8006D238[i][j] == D_i3_8006D238[k][j]) {
                            D_i3_8006D238[k][j] = 32;
                        }
                    }
                }
            }

            for (i = 0; i < 30; i++) {
                k = Math_Rand2() % 8;
                index2 = Math_Rand1() % 8;

                temp_a1 = D_i3_8006D238[k][j];
                D_i3_8006D238[k][j] = D_i3_8006D238[index2][j];
                D_i3_8006D238[index2][j] = temp_a1;
            }

            for (i = 0; i < 8; i++) {
                if (D_i3_8006D238[i][j] < 30) {
                    D_i3_8006D1D8[i][j] = gCharacterPortraitTextures[D_i3_8006D238[i][j]];
                } else {
                    switch (D_i3_8006D238[i][j]) {
                        case 30:
                            D_i3_8006D1D8[i][j] = func_i2_800AEA90(D_F25D858);
                            break;
                        case 31:
                            D_i3_8006D1D8[i][j] = func_i2_800AEA90(D_F25E060);
                            break;
                        case 32:
                            D_i3_8006D1D8[i][j] = func_i2_800AEA90(D_F25E868);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    func_i3_80044720();
    func_i3_80064F20();
    func_i3_80067280();
    Font_LoadString("Ｍ", FONT_SET_5);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZＡＢ23", FONT_SET_6);
    Font_LoadString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", FONT_SET_3);
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        Font_LoadString(gCurrentCourseInfo->recordNames[0], FONT_SET_1);
    }
}

extern s16 D_i3_8006B328[5][4][2];
extern s8 D_8076C7D8;
extern u32 gGameFrameCount;
extern Racer* gRacersByPosition[];

Gfx* func_i3_80045BC4(Gfx* gfx, s32 playerNum) {
    s32 i;
    s32 var_v1;
    f32 var_ft5;
    s32 var_a2_2;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 temp_ft0;
    s32 pad[2];

    if (!gGamePaused && (D_8076C7D8 == 0)) {
        if (D_i3_8006D198[playerNum].x != 0.0f) {
            D_i3_8006D168[playerNum][0] += D_i3_8006D198[playerNum].x;
            if (D_i3_8006D168[playerNum][0] > 0.0f) {
                D_i3_8006D168[playerNum][0] -= 32.0f;
                D_i3_8006D148[playerNum][0]++;
                if (D_i3_8006D148[playerNum][0] >= 8) {
                    D_i3_8006D148[playerNum][0] = 0;
                }
            }
            if (D_i3_8006D198[playerNum].x < (D_i3_8006D1C8.x * 0.4f)) {
                if ((D_i3_8006D1C8.x * (-0.4f)) < D_i3_8006D168[playerNum][0]) {
                    D_i3_8006D168[playerNum][0] = 0.0f;
                    D_i3_8006D198[playerNum].x = 0.0f;
                } else {
                    D_i3_8006D198[playerNum].x = D_i3_8006D1C8.x * 0.4f;
                }
            }
        }
        if (D_i3_8006D198[playerNum].y != 0.0f) {
            D_i3_8006D168[playerNum][1] += D_i3_8006D198[playerNum].y;
            if (D_i3_8006D168[playerNum][1] > 0.0f) {
                D_i3_8006D168[playerNum][1] -= 32.0f;
                D_i3_8006D148[playerNum][1]++;
                if (D_i3_8006D148[playerNum][1] >= 8) {
                    D_i3_8006D148[playerNum][1] = 0;
                }
            }
            if (D_i3_8006D198[playerNum].y < (D_i3_8006D1C8.y * 0.4f)) {
                if ((D_i3_8006D1C8.y * (-0.4f)) < D_i3_8006D168[playerNum][1]) {
                    D_i3_8006D168[playerNum][1] = 0.0f;
                    D_i3_8006D198[playerNum].y = 0.0f;
                } else {
                    D_i3_8006D198[playerNum].y = D_i3_8006D1C8.y * 0.4f;
                }
            }
        }
        if (D_i3_8006D198[playerNum].z != 0.0f) {
            D_i3_8006D168[playerNum][2] += D_i3_8006D198[playerNum].z;
            if (D_i3_8006D168[playerNum][2] > 0.0f) {
                D_i3_8006D168[playerNum][2] -= 32.0f;
                D_i3_8006D148[playerNum][2]++;
                if (D_i3_8006D148[playerNum][2] >= 8) {
                    D_i3_8006D148[playerNum][2] = 0;
                }
            }
            if (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][1]][1]) {
                if (D_i3_8006D198[playerNum].z < (D_i3_8006D1C8.z * 0.2f)) {
                    if ((D_i3_8006D1C8.z * (-0.2f)) < D_i3_8006D168[playerNum][2]) {
                        D_i3_8006D168[playerNum][2] = 0.0f;
                        D_i3_8006D198[playerNum].z = 0.0f;
                    } else {
                        D_i3_8006D198[playerNum].z = D_i3_8006D1C8.z * 0.2f;
                    }
                }
            } else if (D_i3_8006D198[playerNum].z < (D_i3_8006D1C8.z * 0.4f)) {
                if ((D_i3_8006D1C8.z * (-0.4f)) < D_i3_8006D168[playerNum][2]) {
                    D_i3_8006D168[playerNum][2] = 0.0f;
                    D_i3_8006D198[playerNum].z = 0.0f;
                } else {
                    D_i3_8006D198[playerNum].z = D_i3_8006D1C8.z * 0.4f;
                }
            }
        }
        if (D_i3_8006D160[playerNum] > 0) {
            D_i3_8006D198[playerNum].x *= 0.8f;
        }
        if (D_i3_8006D160[playerNum] >= 2) {
            D_i3_8006D198[playerNum].y *= 0.8f;
        }
        if (D_i3_8006D160[playerNum] >= 3) {
            if (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][1]][1]) {
                D_i3_8006D198[playerNum].z *= 0.91f;
            } else {
                D_i3_8006D198[playerNum].z *= 0.8f;
            }
        }
        if (D_i3_8006D268[playerNum] != 0) {
            D_i3_8006D268[playerNum]--;
        } else if (D_i3_8006D160[playerNum] < 4) {
            if (D_i3_8006D160[playerNum] < 3) {
                if ((gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_A) &&
                    (((D_i3_8006D160[playerNum] == 0) ||
                      ((D_i3_8006D160[playerNum] == 1) && (D_i3_8006D198[playerNum].x == 0.0f))) ||
                     ((D_i3_8006D160[playerNum] == 2) && (D_i3_8006D198[playerNum].y == 0.0f)))) {
                    D_i3_8006D160[playerNum]++;
                    func_80741014(playerNum, 0x31);
                }
            }
            if ((D_i3_8006D160[playerNum] == 3) &&
                (((D_i3_8006D198[playerNum].x + D_i3_8006D198[playerNum].y) + D_i3_8006D198[playerNum].z) == 0.0f)) {
                D_i3_8006D160[playerNum]++;
                if ((D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][1]][1]) &&
                    (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][2]][2])) {
                    func_80741014(playerNum, 0x30);
                    D_i3_8006D268[playerNum] = 0x78;
                    var_v1 = 0;
                    for (i = 0; i < gTotalRacers; i++) {
                        if ((D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == gRacers[i].character) &&
                            (!(gRacers[i].stateFlags & RACER_STATE_CRASHED))) {
                            gRacers[i].energy = 0.0f;
                            var_v1++;
                        }
                    }

                    if ((var_v1 == 0) && (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] < 30)) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
                        }
                    }
                    if (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == 30) {
                        gRacersByPosition[0]->energy = 0.0f;
                    }
                    if (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == 31) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy = 0.0f;
                        }
                    }
                    if (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == 32) {
                        for (i = 0; i < gTotalRacers; i++) {
                            gRacers[i].energy /= 2.0f;
                        }
                    }
                }
            }
        } else {
            D_i3_8006D160[playerNum]++;
            if (D_i3_8006D160[playerNum] >= 5) {
                D_i3_8006D160[playerNum] = 5;
            }
            if (D_i3_8006D160[playerNum] >= 5) {
                if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_B) {
                    D_i3_8006D160[playerNum] = 0;
                    D_i3_8006D198[playerNum].x = D_i3_8006D1C8.x;
                    D_i3_8006D198[playerNum].y = D_i3_8006D1C8.y;
                    D_i3_8006D198[playerNum].z = D_i3_8006D1C8.z;
                }
            }
        }
        gSPDisplayList(gfx++, D_80149D0);
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aStartStopGuideTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 12, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gfx++, D_i3_8006B328[gNumPlayers][playerNum][0] << 2,
                            (D_i3_8006B328[gNumPlayers][playerNum][1] - 12) << 2,
                            (D_i3_8006B328[gNumPlayers][playerNum][0] + 63) << 2,
                            (D_i3_8006B328[gNumPlayers][playerNum][1] - 1) << 2, 0, 0, 0, 1 << 12, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8006B328[gNumPlayers][playerNum][0],
                      D_i3_8006B328[gNumPlayers][playerNum][1], D_i3_8006B328[gNumPlayers][playerNum][0] + 127,
                      D_i3_8006B328[gNumPlayers][playerNum][1] + 32);
        for (i = 0; i < 3; i++) {
            var_a2_2 = D_i3_8006D148[playerNum][i] - 1;
            if (var_a2_2 < 0) {
                var_a2_2 = 7;
            }
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_i3_8006D1D8[var_a2_2][i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            temp_ft0 = D_i3_8006D168[playerNum][i];
            left = D_i3_8006B328[gNumPlayers][playerNum][0] + (i * 32);
            top = D_i3_8006B328[gNumPlayers][playerNum][1] + temp_ft0 + 32;
            right = D_i3_8006B328[gNumPlayers][playerNum][0] + (i * 32) + 31;
            bottom = D_i3_8006B328[gNumPlayers][playerNum][1] + temp_ft0 + 63;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_i3_8006D1D8[D_i3_8006D148[playerNum][i]][i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32,
                                32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            top = D_i3_8006B328[gNumPlayers][playerNum][1] + temp_ft0;
            bottom = D_i3_8006B328[gNumPlayers][playerNum][1] + temp_ft0 + 31;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, right << 2, bottom << 2, 0, 0, 0, 1 << 12, 1 << 10);
        }

        left = D_i3_8006B328[gNumPlayers][playerNum][0];
        right = D_i3_8006B328[gNumPlayers][playerNum][0] + 96;
        top = bottom = D_i3_8006B328[gNumPlayers][playerNum][1];
        gfx = func_i3_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        top = bottom = D_i3_8006B328[gNumPlayers][playerNum][1] + 32;
        gfx = func_i3_DrawBeveledBox(gfx, left, top, right, bottom, 255, 255, 255, 255);
        gSPDisplayList(gfx++, D_80149D0);
        if ((D_i3_8006D198[playerNum].x + D_i3_8006D198[playerNum].y) == 0.0f) {
            if ((((D_i3_8006D238[D_i3_8006D148[playerNum][0]][0]) == D_i3_8006D238[D_i3_8006D148[playerNum][1]][1]) &&
                 ((gGameFrameCount % 20) >= 5)) &&
                ((D_i3_8006D160[playerNum] == 2) ||
                 ((D_i3_8006D160[playerNum] >= 3) && (D_i3_8006D198[playerNum].z != 0.0f)))) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (D_i3_8006B328[gNumPlayers][playerNum][0] + 64) << 2,
                                    D_i3_8006B328[gNumPlayers][playerNum][1] << 2,
                                    (D_i3_8006B328[gNumPlayers][playerNum][0] + 95) << 2,
                                    (D_i3_8006B328[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12, 1 << 10);
            }
        }
        if ((((D_i3_8006D198[playerNum].x + D_i3_8006D198[playerNum].y) + D_i3_8006D198[playerNum].z) == 0.0f) &&
            (D_i3_8006D160[playerNum] >= 3)) {
            if (((D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][1]][1]) &&
                 (D_i3_8006D238[D_i3_8006D148[playerNum][0]][0] == D_i3_8006D238[D_i3_8006D148[playerNum][2]][2])) &&
                ((gGameFrameCount % 20) >= 5)) {
                gSPDisplayList(gfx++, D_80149D0);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPTextureRectangle(gfx++, (D_i3_8006B328[gNumPlayers][playerNum][0] + 64) << 2,
                                    D_i3_8006B328[gNumPlayers][playerNum][1] << 2,
                                    (D_i3_8006B328[gNumPlayers][playerNum][0] + 95) << 2,
                                    (D_i3_8006B328[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12, 1 << 10);
                for (i = 0; i < 3; i++) {
                    gSPTextureRectangle(gfx++, (D_i3_8006B328[gNumPlayers][playerNum][0] + (i * 32)) << 2,
                                        D_i3_8006B328[gNumPlayers][playerNum][1] << 2,
                                        ((D_i3_8006B328[gNumPlayers][playerNum][0] + (i * 32)) + 31) << 2,
                                        (D_i3_8006B328[gNumPlayers][playerNum][1] + 31) << 2, 0, 0, 0, 1 << 12,
                                        1 << 10);
                }
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }
    return gfx;
}

Gfx* func_i3_80047258(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_DrawBlankTimeHundredths(gfx, left + 8, top);
}

Gfx* func_i3_800473AC(Gfx* gfx, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_DrawBlankTimeThousandths(gfx, left + 8, top);
}

Gfx* func_i3_80047500(Gfx* gfx, s32 time, s32 left, s32 top) {

    gSPDisplayList(gfx++, D_8014940);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    if (time <= -MAX_TIMER) {
        time = -MAX_TIMER;
    }

    return func_i3_DrawRaceTimeInterval(gfx, time, left, top, 1.0f);
}

extern s32 D_i3_8006D378;
extern s32 D_i3_8006D37C;
extern s32 D_i3_8006D380;
extern s32 D_i3_8006D384;
extern s32 D_i3_8006D388;
extern s32 D_i3_8006D390;
extern s32 D_i3_8006D394;
extern s32 gTotalLapCount;
extern s16 D_807A16F2;
extern s16 D_807A16F6;

Gfx* func_i3_80047698(Gfx* gfx, s32 playerNum) {
    s32 sp144;
    s32 left;
    s32 top;
    s32 i;
    f32 scale = 1.0f;

    gSPDisplayList(gfx++, D_80149D0);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = D_i3_8006D378 - D_i3_8006D374;
    if (left >= 0) {
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * D_i3_8006D380) + D_i3_8006D37C + 3;
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (15.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, 0, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left += 0x11;

    if (left >= 0) {
        for (i = 1; i <= gTotalLapCount; i++) {
            top = ((i - 1) * D_i3_8006D380) + D_i3_8006D37C + 3;

            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (7.0f * scale)) << 2,
                                    (s32) (top + (11.0f * scale)) << 2, 0, 0, (i * 12) << 5, (s32) (4096.0f / scale),
                                    (s32) (1024.0f / scale));
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    left = D_i3_8006D378 - D_i3_8006D374;
    top = (gTotalLapCount * D_i3_8006D380) + (D_i3_8006D380 / 2) + D_i3_8006D37C;
    if (left > 0) {
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + (23.0f * scale)) << 2,
                                (s32) (top + (15.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (sp144 = 0; sp144 < gTotalLapCount; sp144++) {
        top = (sp144 * D_i3_8006D380) + D_i3_8006D37C;
        if (D_i3_8006D350[playerNum] < ((D_i3_8006D390 * sp144) + D_i3_8006D388)) {
            top += (((D_i3_8006D390 * sp144) + D_i3_8006D388) - D_i3_8006D350[playerNum]) * D_i3_8006D394;
        }
        if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
            ((((D_i3_8006D390 * sp144) + D_i3_8006D388) - D_i3_8006D350[playerNum]) == 1) && (D_8076C7D8 == 0)) {
            func_8074122C(0x22);
        }
        if (top < 240) {
            gDPPipeSync(gfx++);
            if ((sp144 + 1) == D_807A16F6) {
                gfx = func_8070EC64(gfx, 255, 0, 0);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
            gfx = func_i3_DrawTimerScisThousandths(gfx, gRacers[playerNum].lapTimes[sp144],
                                                   D_i3_8006D378 + D_i3_8006D384 + D_i3_8006D374, top, 1.0f);
        }
    }

    top = (gTotalLapCount * D_i3_8006D380) + (D_i3_8006D380 / 2) + D_i3_8006D37C;
    if (D_i3_8006D350[playerNum] < ((D_i3_8006D390 * sp144) + D_i3_8006D388)) {
        top += (((D_i3_8006D390 * gTotalLapCount) + D_i3_8006D388) - D_i3_8006D350[playerNum]) * D_i3_8006D394;
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((D_i3_8006D390 * gTotalLapCount) + D_i3_8006D388) - D_i3_8006D350[playerNum]) == 1) && (D_8076C7D8 == 0)) {
        func_8074122C(0x22);
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) &&
        ((((D_i3_8006D390 * (gTotalLapCount + 1)) + D_i3_8006D388) - D_i3_8006D350[playerNum]) == 1) && (D_807A16F2 == 1) &&
        (D_8076C7D8 == 0)) {
        func_8074122C(0x2A);
    }
    if (top < 240) {
        gDPPipeSync(gfx++);
        if (D_807A16F2 != 0) {
            gfx = func_8070EC64(gfx, 255, 0, 0);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        gfx = func_i3_DrawTimerScisThousandths(gfx, gRacers[playerNum].raceTime,
                                               D_i3_8006D378 + D_i3_8006D384 + D_i3_8006D374, top, 1.0f);
    }

    D_i3_8006D350[playerNum]++;
    if (D_i3_8006D350[playerNum] >= 3000) {
        D_i3_8006D350[playerNum] = 3000;
    }
    return gfx;
}

extern TexturePtr D_i3_8006B310[];

Gfx* func_i3_80048658(Gfx* gfx) {
    f32 scale;
    s32 temp_v0;
    s32 left;
    s32 i;
    s32 top;
    s32 character;
    s32 var_s6;
    s32 index;
    s32* new_var;

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gSPDisplayList(gfx++, D_80149D0);

    for (i = 0; i < 6; i++) {
        if (i == gTotalRacers) {
            break;
        }
        top = 130;
        left = (i * 40 + 45);

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, D_i3_8006B310[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 6, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + 15) << 2, (top + 5) << 2, 0, 0, 0, 1 << 12,
                                1 << 10);
    }
    gSPDisplayList(gfx++, D_8014940);

    index = 0;
    for (i = 0; i < 6; i++) {
        scale = 1.0f;
        top = 136;
        left = (i * 40 + 45);
        var_s6 = (i * 10 + 60);

        if (D_i3_8006D350[index] < var_s6) {
            temp_v0 = (((i * 10) - D_i3_8006D350[index]) * 10) + 600;
            left += temp_v0;
            scale += (temp_v0 * 0.03f);
        }

        if (D_i3_8006D350[index] == var_s6) {
            switch (i) {
                case 0:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x18);
                    }
                    break;
                case 1:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x19);
                    }
                    break;
                case 2:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x1A);
                    }
                    break;
                case 3:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x1B);
                    }
                    break;
                case 4:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x1C);
                    }
                    break;
                case 5:
                    if (D_8076C7D8 == 0) {
                        func_8074122C(0x1D);
                    }
                    break;
            }
        }

        if (left < SCREEN_WIDTH) {
            gDPPipeSync(gfx++);
            character = gRacersByPosition[i]->character;
            gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                    (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                    (s32) (1024.0f / scale));

            if ((gRacersByPosition[i]->id == 0) && ((gGameFrameCount % 20) >= 5)) {
                gDPPipeSync(gfx++);
                gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);
                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * scale) << 2,
                                        (s32) (top + 32.0f * scale) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                        (s32) (1024.0f / scale));
            }
        }
    }
    return gfx;
}

Gfx* func_i3_80048EC8(Gfx* gfx, s32 arg1, s32 character, s32 left, s32 top, f32 arg5) {
    s32 pad;

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);
    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * arg5) << 2,
                            (s32) (top + 32.0f * arg5) << 2, 0, 0, 0, (s32) (1024.0f / arg5), (s32) (1024.0f / arg5));

    if ((arg1 == 0) && ((gGameFrameCount % 20) >= 5)) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 32.0f * arg5) << 2,
                                (s32) (top + 32.0f * arg5) << 2, 0, 0, 0, (s32) (1024.0f / arg5),
                                (s32) (1024.0f / arg5));
    }
    return gfx;
}

void func_i3_8004944C(Gfx* gfx) {

    gfx = func_i3_80048658(gfx);
    D_i3_8006D378 = 196;
    D_i3_8006D37C = 16;
    D_i3_8006D380 = 24;
    D_i3_8006D384 = 30;
    D_i3_8006D388 = 30;
    D_i3_8006D390 = 10;
    D_i3_8006D394 = 10;
    func_i3_80047698(gfx, 0);
}

Gfx* func_i3_DrawLoser(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTLUT_pal256(gfx++, sLoserPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 3; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, sLoserTexture + ALIGN_2(i * 0x320), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 10, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 10) * scale) << 2,
                                (s32) (left + 80.0f * scale) << 2, (s32) (top + ((i + 1) * 10) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

Gfx* func_i3_DrawWinner(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
    gDPLoadTLUT_pal256(gfx++, sWinnerPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 4; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, sWinnerTexture + ALIGN_2(i * 0x400), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 8) * scale) << 2,
                                (s32) (left + 128.0f * scale) << 2, (s32) (top + ((i + 1) * 8) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return gfx;
}

extern s32 D_8006D548;

Gfx* func_i3_80049D74(Gfx* gfx, s32 playerNum) {
    s32 i;
    s32 j;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 var_a1;
    s32 winnerLeft;
    s32 winnerTop;
    f32 scale;
    f32 temp_fv0;
    s32 temp;
    s32 pad[2];
    f32 sp84;
    f32 sp80;
    s32 sp60[8];

    if (gRacers[playerNum].position == 1) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    switch (gNumPlayers) {
        case 1:
            spAC = 100;
            spB4 = 100;
            spB0 = 100;
            spA8 = 170;
            sp84 = 1.0f;
            sp80 = 1.0f;
            break;
        case 2:
            sp84 = 1.0f;
            sp80 = 0.6f;
            spB4 = 100;
            spAC = 210;
            switch (playerNum) {
                case 0:
                    spB0 = 43;
                    spA8 = 21;
                    break;
                case 1:
                    spA8 = 133;
                    spB0 = 0x9B;
                    break;
                case 2:
                case 3:
                    var_a1 = 0;
                    D_8006D548 = 1;
                    break;
            }
            break;
        case 3:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (playerNum) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB0 = 0x9B;
                    spB4 = 43;
                    break;
                case 2:
                    spB0 = 43;
                    spB4 = 0xB7;
                    break;
                case 3:
                    var_a1 = 0;
                    D_8006D548 = 1;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
        case 4:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (playerNum) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB4 = 43;
                    spB0 = 0x9B;
                    break;
                case 2:
                    spB4 = 0xB7;
                    spB0 = 43;
                    break;
                case 3:
                    spB4 = 0xB7;
                    spB0 = 0x9B;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
    }
    if (var_a1 == 1) {
        if (D_i3_8006D3B8[playerNum] <= 60) {
            winnerLeft = spB4;
            winnerTop = spB0;
            scale = sp84;
        } else if (D_i3_8006D3B8[playerNum] >= 70) {
            winnerLeft = spAC;
            winnerTop = spA8;
            scale = sp80;
        } else {
            temp_fv0 = D_i3_8006D3B8[playerNum] - 60;
            winnerLeft = (spB4 + (((spAC - spB4) / 10.0f) * temp_fv0));
            winnerTop = (spB0 + (((spA8 - spB0) / 10.0f) * temp_fv0));
            scale = (((sp80 - sp84) / 10.0f) * temp_fv0) + sp84;
        }
        if ((D_i3_8006D3B8[playerNum] > 60) || (gGameFrameCount & 4)) {
            gfx = func_i3_DrawWinner(gfx, winnerLeft, winnerTop, scale);
        }
    }

    D_i3_8006D3B8[playerNum]++;
    if ((gNumPlayers >= 2) && (((D_i3_8006D3B8[playerNum] == 1)) || (D_i3_8006D3B8[playerNum] == 0x3C)) && (playerNum < gNumPlayers)) {

        for (i = 0; i < gTotalRacers; i++) {
            sp60[i] = i;
        }

        for (i = 0; i < gTotalRacers - 1; i++) {
            for (j = i + 1; j < gTotalRacers; j++) {
                if (sp60[i] >= gNumPlayers) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                } else if ((sp60[j] < gNumPlayers) && (gRacers[sp60[j]].position < gRacers[sp60[i]].position)) {
                    temp = sp60[i];
                    sp60[i] = sp60[j];
                    sp60[j] = temp;
                }
            }
        }

        if (playerNum == sp60[0]) {
            if (D_i3_8006D3B8[playerNum] == 60) {

                if (gRacers[playerNum].stateFlags & RACER_STATE_CRASHED) {
                    if (D_8076C7D8 == 0) {
                        func_8070DAD4(0x18);
                    }
                } else if (D_8076C7D8 == 0) {
                    func_8070DAD4(0x16);
                }
                for (i = 0; i < gNumPlayers; i++) {
                    if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                        (gRacers[playerNum].stateFlags & RACER_STATE_FLAGS_2000000)) {
                        func_80740CE8(i, 3);
                        func_80740CE8(i, 4);
                        func_80740CE8(i, 5);
                        func_80740CE8(i, 8);
                        func_80740CE8(i, 9);
                        func_80740CE8(i, 10);
                        func_80740CE8(i, 11);
                    }
                }

            } else if (D_8076C7D8 == 0) {
                func_8070DAFC();
            }
        }
    }
    if (D_i3_8006D3B8[playerNum] >= 600) {
        D_i3_8006D3B8[playerNum] = 600;
    }
    return gfx;
}

Gfx* func_i3_8004A330(Gfx* gfx, s32 playerNum) {
    s32 i;
    s32 j;
    s32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 var_a1;
    s32 loserLeft;
    s32 loserTop;
    f32 scale;
    f32 temp_fv0;
    s32 temp;
    s32 pad[2];
    f32 sp84;
    f32 sp80;

    if (gRacers[playerNum].position == 1) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }

    switch (gNumPlayers) {
        case 1:
            spB4 = 130;
            spAC = 130;
            spB0 = 100;
            spA8 = 170;
            sp84 = 1.0f;
            sp80 = 1.0f;
            break;
        case 2:
            sp84 = 1.0f;
            sp80 = 0.6f;
            spB4 = 100;
            spAC = 210;
            switch (playerNum) {
                case 0:
                    spB0 = 43;
                    spA8 = 21;
                    break;
                case 1:
                    spA8 = 133;
                    spB0 = 155;
                    break;
                case 2:
                case 3:
                    var_a1 = 0;
                    D_8006D548 = 1;
                    break;
            }
            break;
        case 3:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (playerNum) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB0 = 155;
                    spB4 = 43;
                    break;
                case 2:
                    spB0 = 43;
                    spB4 = 183;
                    break;
                case 3:
                    var_a1 = 0;
                    D_8006D548 = 1;
                    break;
            }
            spA8 = spB0 - 0x14;
            spAC = spB4 + 0x36;
            break;
        case 4:
            sp84 = 0.75f;
            sp80 = 0.4f;
            switch (playerNum) {
                case 0:
                    spB4 = 43;
                    spB0 = 43;
                    break;
                case 1:
                    spB4 = 43;
                    spB0 = 155;
                    break;
                case 2:
                    spB4 = 183;
                    spB0 = 43;
                    break;
                case 3:
                    spB4 = 183;
                    spB0 = 155;
                    break;
            }
            spA8 = spB0 - 20;
            spAC = spB4 + 54;
            break;
    }
    if (var_a1 == 1) {
        if (D_i3_8006D3B8[playerNum] <= 60) {
            loserLeft = spB4;
            loserTop = spB0;
            scale = sp84;
        } else if (D_i3_8006D3B8[playerNum] >= 70) {
            loserLeft = spAC;
            loserTop = spA8;
            scale = sp80;
        } else {
            temp_fv0 = D_i3_8006D3B8[playerNum] - 60;
            loserLeft = (spB4 + (((spAC - spB4) / 10.0f) * temp_fv0));
            loserTop = (spB0 + (((spA8 - spB0) / 10.0f) * temp_fv0));
            scale = (((sp80 - sp84) / 10.0f) * temp_fv0) + sp84;
        }
        if ((D_i3_8006D3B8[playerNum] > 60) || (gGameFrameCount & 4)) {
            gfx = func_i3_DrawLoser(gfx, loserLeft, loserTop, scale);
        }
    }

    D_i3_8006D3B8[playerNum]++;

    if (D_i3_8006D3B8[playerNum] >= 600) {
        D_i3_8006D3B8[playerNum] = 600;
    }
    return gfx;
}

Gfx* func_i3_DrawFinalLap(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, aFinalLapPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 1; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (aFinalLapTex + (i * 0x800)), G_IM_FMT_CI, G_IM_SIZ_8b, 128, 16, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (i * 16) * scale) << 2,
                                (s32) (left + 128.0f * scale) << 2, (s32) (top + ((i + 1) * 16) * scale) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_8004AAE0(Gfx* gfx, s32 playerNum) {
    s32 left;
    s32 top;
    s32 pad;
    f32 scale;

    switch (gNumPlayers) {
        case 1:
            left = 100;
            top = 88;
            scale = 1.0f;
            break;
        case 2:
            scale = 1.0f;
            left = 100;
            switch (playerNum) {
                case 0:
                    top = 35;
                    break;
                case 1:
                    top = 147;
                    break;
            }
            break;
        case 3:
        case 4:
            scale = 0.75f;
            switch (playerNum) {
                case 0:
                    left = 43;
                    top = 56;
                    break;
                case 1:
                    left = 43;
                    top = 168;
                    break;
                case 2:
                    left = 183;
                    top = 56;
                    break;
                case 3:
                    left = 183;
                    top = 168;
                    break;
            }
            break;
    }
    return func_i3_DrawFinalLap(gfx, left, top, scale);
}

Gfx* func_i3_DrawBoosterOk(Gfx* gfx, s32 left, s32 top, f32 scale) {
    s32 i;
    f32 blockTop;
    f32 temp;
    s32 pad[2];

    gSPDisplayList(gfx++, D_8014940);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gDPLoadTLUT_pal256(gfx++, aBoosterOkPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    blockTop = top;

    for (i = 0; i < 2; i++) {

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (aBoosterOkTex + (i * 0x280)), G_IM_FMT_CI, G_IM_SIZ_8b, 80, 8, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        temp = (8.0f * scale);
        gSPScisTextureRectangle(gfx++, left << 2, (s32) (blockTop) << 2, (s32) (left + 80.0f * scale) << 2,
                                (s32) (blockTop + temp) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                (s32) (1024.0f / scale));
        blockTop += temp;
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

Gfx* func_i3_8004B028(Gfx* gfx, s32 playerNum) {
    s32 left;
    s32 top;
    s32 pad;
    f32 scale;

    switch (gNumPlayers) {
        case 1:
            left = 120;
            top = 90;
            scale = 1.0f;
            break;
        case 2:
            scale = 1.0f;
            left = 120;
            switch (playerNum) {
                case 0:
                    top = 37;
                    break;
                case 1:
                    top = 149;
                    break;
            }
            break;
        case 3:
        case 4:
            scale = 1.0f;
            switch (playerNum) {
                case 0:
                    left = 43;
                    top = 56;
                    break;
                case 1:
                    left = 43;
                    top = 168;
                    break;
                case 2:
                    left = 193;
                    top = 56;
                    break;
                case 3:
                    left = 193;
                    top = 168;
                    break;
            }
            break;
    }
    return func_i3_DrawBoosterOk(gfx, left, top, scale);
}

void func_i3_8004B158(s32 playerNum) {
    D_i3_8006D3D8[playerNum] = gRacers[playerNum].speed * 0.05f;
    D_i3_8006D3E8[playerNum] = 0.0f;
    D_i3_8006D550[playerNum] = 0;
    D_i3_8006D3C8[playerNum] = 0;
}

extern GfxPool D_1000000;
extern Player gPlayers[];
extern GfxPool* gGfxPool;

Gfx* func_i3_8004B1C8(Gfx* gfx, s32 playerNum) {
    s32 pad[6];
    s32 i;
    f32 spC8;
    f32 spC4;
    f32 spC0;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 spB0;
    f32 spAC;
    f32 temp;
    f32 spA4;
    f32 spA0;
    f32 temp_fv0_2;
    s32 angle;

    temp_fv0 = gPlayers[playerNum].unk_5C.x.x;
    temp_fv1 = gPlayers[playerNum].unk_5C.x.y;
    temp_fa1 = gPlayers[playerNum].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));

    if (D_i3_8006D3C8[playerNum] <= 10) {
        spC0 = 0 * 0;
        spC4 = 0 * -2;
        spC8 = 0 * 2 + 180.0f;
    } else if (D_i3_8006D3C8[playerNum] >= 30) {
        spC0 = 20.0f * 0;
        spC4 = 20.0f * -2;
        spC8 = 20.0f * 2 + 180.0f;
    } else {
        temp_fv0_2 = D_i3_8006D3C8[playerNum] - 10;
        spC0 = temp_fv0_2 * 0;
        spC4 = temp_fv0_2 * -2;
        spC8 = (temp_fv0_2 * 2) + 180.0f;
    }

    D_i3_8006D3E8[playerNum] += D_i3_8006D3D8[playerNum];
    D_i3_8006D3D8[playerNum] *= 0.92f;
    if (D_i3_8006D3D8[playerNum] < 0.08f) {
        D_i3_8006D3D8[playerNum] = 0.08f;
    }
    while (D_i3_8006D3E8[playerNum] < 0.0f) {
        D_i3_8006D3E8[playerNum] += M_TWO_PI;
    }
    while (D_i3_8006D3E8[playerNum] > M_TWO_PI) {
        D_i3_8006D3E8[playerNum] -= M_TWO_PI;
    }
    if ((D_i3_8006D3D8[playerNum] <= 0.08f) && (D_i3_8006D3E8[playerNum] >= (0.92f * M_TWO_PI))) {
        D_i3_8006D3E8[playerNum] = (0.92f * M_TWO_PI);
        D_i3_8006D3D8[playerNum] = 0.0f;
    }
    temp = D_i3_8006D3E8[playerNum];
    angle = RAD_TO_FZXANG(temp);
    spA0 = SIN(angle);
    spA4 = -COS(angle);
    spAC = COS(angle);
    spB0 = SIN(angle);

    gfx = func_i3_80059D90(gfx, playerNum);

    gSPMatrix(gfx++, &D_1000000.unk_1A008[playerNum], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_1A108[playerNum], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BACK);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    func_806F7FCC(gGfxPool->unk_33988, NULL, 0.07f, 0.07f, 0.07f, 0, spA0, spA4, 0, spAC, spB0, spC0, spC4, spC8);
    gSPMatrix(gfx++, gGfxPool->unk_33988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aFinishDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_8006D3B8[playerNum]++;
    if (D_i3_8006D3B8[playerNum] == 2) {
        if ((gGameMode == GAMEMODE_TIME_ATTACK) || (gGameMode == GAMEMODE_GP_RACE)) {
            if (gTotalLapCount == 3) {
                sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
            }
        } else if (gGameMode == GAMEMODE_DEATH_RACE) {
            sMenuStateFlags |= MENU_STATE_RACE_FINISH_SAVE;
        }
    }

    if (D_i3_8006D3B8[playerNum] == 60) {
        if (D_8076C7D8 == 0) {
            func_8070DAD4(0x16);
        }
        for (i = 0; i < gNumPlayers; i++) {
            if ((gRacers[i].stateFlags & RACER_STATE_CRASHED) ||
                (gRacers[playerNum].stateFlags & RACER_STATE_FLAGS_2000000)) {
                func_80740CE8(i, 3);
                func_80740CE8(i, 4);
                func_80740CE8(i, 5);
                func_80740CE8(i, 8);
                func_80740CE8(i, 9);
                func_80740CE8(i, 10);
                func_80740CE8(i, 11);
            }
        }
    }

    if (D_i3_8006D3D8[playerNum] == 0.0f) {
        D_i3_8006D3C8[playerNum]++;
        if (D_i3_8006D3C8[playerNum] >= 600) {
            D_i3_8006D3C8[playerNum] = 600;
        }
    }
    return gfx;
}

extern f32 D_i3_8006D4E4;

void func_i3_8004B790(s32 arg0) {
    D_i3_8006D3D8[arg0] = 0.25f;
    D_i3_8006D3C8[arg0] = 0;
    D_i3_8006D3E8[arg0] = 0.0f;
    D_i3_8006D4E4 = 0.001f;
}

Gfx* func_i3_8004B7D8(Gfx* gfx, s32 playerNum) {
    s32 pad[7];
    f32 sp88;
    f32 sp84;
    f32 sp80;
    s32 row;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 angle;
    s32 alpha;
    f32 sp64;
    f32 temp_fv0_2;
    f32 sp5C;

    temp_fv0 = gPlayers[playerNum].unk_5C.x.x;
    temp_fv1 = gPlayers[playerNum].unk_5C.x.y;
    temp_fa1 = gPlayers[playerNum].unk_5C.x.z;
    sqrtf(SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa1));
    if ((gNumPlayers == 1) && (D_i3_8006D3D8[playerNum] <= 0.02f)) {
        gControllers[gGameFrameCount % 4].unk_78 = 1;
        D_i3_8006D398[0] += 2;
        if (D_i3_8006D398[0] == 250) {
            func_80741EB4();
            func_80741EC4();
        }
        if (D_i3_8006D398[0] > 1000) {
            D_i3_8006D398[0] = 1000;
        }
        gSPDisplayList(gfx++, D_8014940);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);

        for (row = 16; row < 224; row++) {
            alpha = (row - 124);
            if (row < 124) {
                alpha = -alpha;
            }
            alpha = (D_i3_8006D398[0] + alpha) - 150;
            if (alpha < 0) {
                alpha = 0;
            }
            if (alpha > 255) {
                alpha = 255;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, alpha);
            gSPTextureRectangle(gfx++, 12 << 2, row << 2, 308 << 2, (row + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    if (gRacers[playerNum].stateFlags & RACER_STATE_FLAGS_2000000) {
        if (D_i3_8006D3C8[playerNum] <= 10) {
            sp80 = 0;
            sp84 = 0.f;
            sp88 = 20.0f;
        } else if (D_i3_8006D3C8[playerNum] >= 30) {
            sp80 = 0;
            sp84 = 20.0f * -0.15f;
            sp88 = 20.0f;
        } else {
            temp_fv0_2 = D_i3_8006D3C8[playerNum] - 10;
            sp80 = temp_fv0_2 * 0;
            sp84 = temp_fv0_2 * -0.15f;
            sp88 = sp80 + 20.0f;
        }
    } else {
        sp80 = 0;
        sp84 = 0;
        sp88 = 20.0f;
    }

    D_i3_8006D3E8[playerNum] += D_i3_8006D3D8[playerNum];
    D_i3_8006D3D8[playerNum] *= 0.99f;
    if (D_i3_8006D3D8[playerNum] < 0.02f) {
        D_i3_8006D3D8[playerNum] = 0.02f;
    }
    if ((D_i3_8006D3D8[playerNum] <= 0.02f) && (D_i3_8006D3E8[playerNum] >= M_TWO_PI)) {
        D_i3_8006D3E8[playerNum] = M_TWO_PI;
        D_i3_8006D3D8[playerNum] = 0.0f;
    }

    if (D_i3_8006D3D8[playerNum] == 0.0f) {
        D_i3_8006D3C8[playerNum]++;
        if (D_i3_8006D3C8[playerNum] >= 600) {
            D_i3_8006D3C8[playerNum] = 600;
        }
    }
    while (D_i3_8006D3E8[playerNum] < 0.0f) {
        D_i3_8006D3E8[playerNum] += M_TWO_PI;
    }
    while (D_i3_8006D3E8[playerNum] > M_TWO_PI) {
        D_i3_8006D3E8[playerNum] -= M_TWO_PI;
    }

    angle = RAD_TO_FZXANG(D_i3_8006D3E8[playerNum]);

    sp5C = SIN(angle);
    sp64 = -COS(angle);
    gfx = func_i3_80059D90(gfx, playerNum);
    gSPMatrix(gfx++, &D_1000000.unk_1A008[playerNum], G_MTX_PUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_1A108[playerNum], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, D_400A258);

    D_i3_8006D4E4 += 0.00005f;
    if (D_i3_8006D4E4 >= 0.009f) {
        D_i3_8006D4E4 = 0.009f;
        if ((gControllers[gPlayerControlPorts[playerNum]].buttonPressed & (BTN_A | BTN_START)) &&
            (D_i3_8006D3C8[playerNum] >= 60) && !sMenuIsBusy) {
            if (D_8076C7D8 == 0) {
                func_80741EC4();
            }
            if (D_8076C7D8 == 0) {
                func_8070DAFC();
            }
            sMenuIsBusy = true;
            sMenuStateFlags |= MENU_STATE_QUIT;
        }
    }

    func_806F7FCC(gGfxPool->unk_33988, NULL, D_i3_8006D4E4, D_i3_8006D4E4, D_i3_8006D4E4, sp5C, 0.0f, sp64, 0.0f, 1.0f,
                  0.0f, sp80, sp84, sp88);
    gSPMatrix(gfx++, gGfxPool->unk_33988, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, aExecuteGameoverDL);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    D_i3_8006D3B8[playerNum]++;
    return gfx;
}

Gfx* func_i3_8004BFD4(Gfx* gfx, s32 playerNum) {
    s32 pad;
    s32 left;
    s32 top;

    if (gNumPlayers < 3) {
        switch (playerNum) {
            case 0:
                left = 24;
                top = 20;
                break;
            case 1:
                left = 24;
                top = 132;
                break;
        }
    } else {
        switch (playerNum) {
            case 0:
                left = 21;
                top = 20;
                break;
            case 1:
                left = 21;
                top = 132;
                break;
            case 2:
                left = 165;
                top = 20;
                break;
            case 3:
                left = 165;
                top = 132;
                break;
        }
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    return func_i3_DrawTimerScisThousandths(gfx, gRacers[playerNum].raceTime, left, top, 1.0f);
}

extern TexturePtr sRaceMenuTextures[];
extern s32 sRaceMenuDimensions[];

Gfx* func_i3_DrawRaceMenuTexture(Gfx* gfx, s32 textureIndex, s32 left, s32 top) {

    if (textureIndex >= 24) {
        return gfx;
    }

    return func_8070DEE0(gfx, func_i2_800AEA90(sRaceMenuTextures[textureIndex]), NULL, G_IM_FMT_CI, 1, left, top,
                         sRaceMenuDimensions[textureIndex * 2 + 0], sRaceMenuDimensions[textureIndex * 2 + 1], 2);
}

s32 func_i3_8004C260(s32 playerNum, s32 highlightedOption, s32 maxOptionValue) {
    s32 var_v0 = 0;
    s32 stickY = gControllers[gPlayerControlPorts[playerNum]].stickY;

    if (stickY > 50) {
        var_v0 = -1;
        D_i3_8006D568++;
    } else if (stickY < -50) {
        var_v0 = 1;
        D_i3_8006D568++;
    } else {
        if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_UP) {
            var_v0 = -1;
            D_i3_8006D568 = 1;
        } else if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_DOWN) {
            var_v0 = 1;
            D_i3_8006D568 = 1;
        } else {
            D_i3_8006D568 = 0;
        }
    }

    if ((D_i3_8006D568 == 1) || (D_i3_8006D568 == 60)) {
        highlightedOption += var_v0;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (D_8076C7D8 == 0) {
            func_8074122C(0x1E);
        }
    }
    if (D_i3_8006D568 >= 75) {
        D_i3_8006D568 = 59;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

s32 func_i3_8004C3D4(s32 playerNum, s32 highlightedOption, s32 maxOptionValue) {
    s32 var_v0 = 0;
    s32 stickX = gControllers[gPlayerControlPorts[playerNum]].stickX;

    if (stickX > 50) {
        var_v0 = -1;
        D_i3_8006D568++;
    } else if (stickX < -50) {
        var_v0 = 1;
        D_i3_8006D568++;
    } else {
        if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_LEFT) {
            var_v0 = -1;
            D_i3_8006D568 = 1;
        } else if (gControllers[gPlayerControlPorts[playerNum]].buttonPressed & BTN_RIGHT) {
            var_v0 = 1;
            D_i3_8006D568 = 1;
        } else {
            D_i3_8006D568 = 0;
        }
    }

    if ((D_i3_8006D568 == 1) || (D_i3_8006D568 == 60)) {
        highlightedOption += var_v0;
        if (highlightedOption == -1) {
            highlightedOption = maxOptionValue;
        }
        if (highlightedOption == (maxOptionValue + 1)) {
            highlightedOption = 0;
        }
        if (D_8076C7D8 == 0) {
            func_8074122C(0x1E);
        }
    }
    if (D_i3_8006D568 >= 75) {
        D_i3_8006D568 = 59;
    }

    Math_Rand1();
    Math_Rand2();
    return highlightedOption;
}

Gfx* func_i3_SetOptionColor(Gfx* gfx, s32 arg1) {

    gDPPipeSync(gfx++);

    if (arg1 == 0) {
        gfx = func_8070D4A8(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    }
    return gfx;
}

extern s32 sFastestGhostTime;
extern s32 sFastestGhostIndex;
extern s32 gFastestGhostTime;
extern Ghost* gFastestGhost;
extern Ghost gGhosts[];

void func_i3_8004C5A4(void) {

    if (gFastestGhostRacer == NULL) {
        gFastestGhostIndex = -1;
        gFastestGhostTime = MAX_TIMER;
    } else {
        gFastestGhostIndex = gFastestGhostRacer->ghost - gGhosts;
        gFastestGhostTime = gFastestGhostRacer->ghost->raceTime;
    }
    if (gFastestGhost == NULL) {
        sFastestGhostIndex = -1;
        return;
    }
    sFastestGhostIndex = gFastestGhost - gGhosts;
    sFastestGhostTime = gFastestGhost->raceTime;
}

extern s32 sCannotSaveGhost;
extern GhostInfo gSavedGhostInfo;

s32 func_i3_8004C654(void) {
    func_i3_8004C5A4();
    if (sFastestGhostIndex == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }
    if (Save_LoadGhostInfo(&gSavedGhostInfo) != 0) {
        if (gCourseIndex < COURSE_EDIT_1) {
            Save_SaveGhost(gCourseIndex, gFastestGhost);
        }
        sSaveGhostMenuOpen = false;
        sGhostSaveTimer = 60;
        return 0;
    }
    return 0;
}

extern GhostRecord D_i3_8006D270[];
extern GhostRecord* D_i3_8006D340[];
extern GhostRecord* D_i3_8006D360;
extern s32 D_i3_8006D368[];

void func_i3_8004C6F0(void) {
    s32 temp_a0;
    GhostRecord* temp_v1;
    s32 i;
    s32 j;

    D_i3_8006D270[0].raceTime = D_i3_8006D270[1].raceTime = D_i3_8006D270[2].raceTime = MAX_TIMER;

    func_i2_800A9ED0(gCourseIndex, D_i3_8006D270);

    for (i = 0; i < 3; i++) {
        D_i3_8006D340[i] = &D_i3_8006D270[i];
        D_i3_8006D368[i] = i;
    }

    for (i = 0; i < 2; i++) {
        for (j = i + 1; j < 3; j++) {
            if (D_i3_8006D340[i]->raceTime > D_i3_8006D340[j]->raceTime) {
                D_i3_8006D360 = D_i3_8006D340[i];
                D_i3_8006D340[i] = D_i3_8006D340[j];
                D_i3_8006D340[j] = D_i3_8006D360;
                temp_a0 = D_i3_8006D368[i];
                D_i3_8006D368[i] = D_i3_8006D368[j];
                D_i3_8006D368[j] = temp_a0;
            }
        }
    }
}

extern s32 gCupType;

s32 func_i3_8004C8D4(void) {
    s32 sp1C;
    s32 i;

    sCannotSaveGhost = false;
    if (gCourseIndex >= COURSE_X_1) {
        sCannotSaveGhost = true;
        return 0;
    }
    func_i3_8004C5A4();
    if (sFastestGhostIndex == -1) {
        sCannotSaveGhost = true;
        sSaveGhostMenuOpen = false;
        return -1;
    }

    sp1C = Save_LoadGhostInfo(&gSavedGhostInfo);
    func_i3_8004C6F0();
    if ((sp1C == 0) && (gSavedGhostInfo.courseIndex == gCourseIndex) && (sFastestGhostTime >= gSavedGhostInfo.raceTime)) {
        sCannotSaveGhost = true;
    }

    for (i = 0; i < 3; i++) {
        if ((sFastestGhostTime >= D_i3_8006D270[i].raceTime) && (D_i3_8006D270[i].encodedCourseIndex == gCourseInfos[gCourseIndex].encodedCourseIndex)) {
            sCannotSaveGhost = true;
        }
    }
    
    if (gCupType == X_CUP) {
        sCannotSaveGhost = true;
    } else if ((gSavedGhostInfo.courseIndex == gCourseIndex) && (sFastestGhostTime == gSavedGhostInfo.raceTime) && (gSavedGhostInfo.replayChecksum == gFastestGhost->replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == D_i3_8006D270[0].raceTime) && (gFastestGhost->replayChecksum == D_i3_8006D270[0].replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == D_i3_8006D270[1].raceTime) && (gFastestGhost->replayChecksum == D_i3_8006D270[1].replayChecksum)) {
        sCannotSaveGhost = true;
    } else if ((sFastestGhostTime == D_i3_8006D270[2].raceTime) && (gFastestGhost->replayChecksum == D_i3_8006D270[2].replayChecksum)) {
        sCannotSaveGhost = true;
    }
    return 0;
}

Gfx* func_i3_DrawSaved(Gfx* gfx) {

    if (sGhostSaveTimer > 0) {
        sGhostSaveTimer--;
    } else {
        sGhostSaveTimer = 0;
    }

    if (sGhostSaveTimer == 1) {
        sCannotSaveGhost = true;
        sRaceMenuOptionIndex = 0;
        D_i3_8006D5A4 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 85, 105, 165, 135);

    gfx = func_i3_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_i2_800AEA90(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVED, 93, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    D_i3_8006D5A4 = 0;
    return gfx;
}

Gfx* func_i3_DrawSaving(Gfx* gfx) {

    if (sGhostSaveTimer == 1) {
        sRaceMenuOptionIndex = 0;
        D_i3_8006D5A4 = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 80, 105, 170, 135);

    gfx = func_i3_DrawBeveledBox(gfx, 90, 110, 160, 130, 0, 0, 0, 255);
    gSPDisplayList(gfx++, aMenuTextTlutSetupDL);
    gDPLoadTLUT_pal256(gfx++, func_i2_800AEA90(aMenuTextTLUT));
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_SAVING, 95, 112);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);

    D_i3_8006D5A4 = 0;
    return gfx;
}

extern char* gCurrentTrackName;
extern s32 D_i3_8006B49C;
extern s32 D_i3_8006D370;
extern char* D_i3_8006B4A0[];

Gfx* func_i3_DrawGhostSave(Gfx* gfx) {
    s32 i;

    if (D_i3_8006B49C > 0) {
        D_i3_8006B49C -= 8;
    } else {
        D_i3_8006B49C = 0;
    }

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8006B49C + 20, D_i3_8006B49C + 40, 210 - D_i3_8006B49C,
                  226 - D_i3_8006B49C);

    gfx = func_i3_DrawBeveledBox(gfx, 25, 45, 205, 221, 0, 0, 0, 255);
    
    gSPDisplayList(gfx++, D_8014940);
    
    sOverwriteGhostOption = func_i3_8004C3D4(0, sOverwriteGhostOption, 1);

    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8006B49C + 20, D_i3_8006B49C + 40, 210 - D_i3_8006B49C,
                  226 - D_i3_8006B49C);

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_A | BTN_START)) {
        if (sOverwriteGhostOption == 1) {
            sGhostSaveTimer = 60;
            func_i2_800AA368(gCourseIndex, D_i3_8006D370, gFastestGhost);
            sSaveGhostMenuOpen = false;
            if (D_8076C7D8 == 0) {
                func_8074122C(0x21);
            }
        } else {
            sGhostSaveTimer = 0;
            sSaveGhostMenuOpen = false;
            sRaceMenuOptionIndex = 0;
            D_i3_8006D5A4 = 0;
            if (D_8076C7D8 == 0) {
                func_8074122C(0x10);
            }
        }
    } else if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        sGhostSaveTimer = 0;
        sSaveGhostMenuOpen = false;
        sRaceMenuOptionIndex = 0;
        D_i3_8006D5A4 = 0;
        if (D_8076C7D8 == 0) {
            func_8074122C(0x10);
        }
    }
    
    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8006B49C + 20, D_i3_8006B49C + 40, 210 - D_i3_8006B49C,
                  226 - D_i3_8006B49C);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gfx++, G_TF_POINT);

    gDPLoadTLUT_pal256(gfx++, func_i2_800AEA90(aMenuTextTLUT));
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);


    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NEW_GHOST, 83, 45);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_OVERWRITE_DATA2, 51, 114);

    gfx = func_8070D4A8(gfx, 0);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_LEFT_ARROW, 70, 197);
    gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_RIGHT_ARROW, 144, 197);
    if (sOverwriteGhostOption == 0) {
        gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_NO, 99, 197);
    } else {
        gfx = func_i3_DrawRaceMenuTexture(gfx, RACE_MENU_YES, 99, 197);
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, D_i3_8006B49C + 20, D_i3_8006B49C + 40, 210 - D_i3_8006B49C,
                  226 - D_i3_8006B49C);
    
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_DrawTimerScisThousandths(gfx, gFastestGhost->raceTime, 115, 77, 1.0f);

    for (i = 0; i < 3; i++) {
        if (D_i3_8006D340[i]->raceTime != MAX_TIMER) {
            gfx = func_i3_DrawTimerScisThousandths(gfx, D_i3_8006D340[i]->raceTime, 95, 139 + i * 16, 1.0f);
        } else {
            gfx = func_i3_800473AC(gfx, 0x57, 0x8b + i * 16);
        }
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
    gfx = Font_DrawString(gfx, 116 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 78, gCurrentTrackName,
                          1, FONT_SET_6, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = Font_DrawString(gfx, 115 - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_6, 1) / 2), 77, gCurrentTrackName,
                          1, FONT_SET_6, 0);

    for (i = 0; i < 3; i++) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
        gfx = Font_DrawString(gfx, 0x2E, 0x9C + i * 16, D_i3_8006B4A0[i], 1, FONT_SET_6, 0);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
        gfx = Font_DrawString(gfx, 0x2D, 0x9B + i * 16, D_i3_8006B4A0[i], 1, FONT_SET_6, 0);
    }
    
    return gfx;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C7A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C7A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C7AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004D758.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004DD68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004E5A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004E6FC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004F004.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004F61C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8004FC2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80050208.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80050A10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80051154.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80051994.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80052340.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_800523D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_800526A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80052980.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80052CDC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C89C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C8A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C8B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C8B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80053008.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8005379C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80053BE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80053BF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80054380.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80054490.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C960.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C978.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C990.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C998.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9C4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006C9F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA1C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA34.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA3C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA78.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA88.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CA98.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAB8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAD0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CAF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CB08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CB10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CB18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/D_i3_8006CB2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_800544EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8005453C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80054654.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_800546C4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80054730.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8005479C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80054D94.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80056A10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8005733C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_80057D90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/B5EF0/func_i3_8005823C.s")
