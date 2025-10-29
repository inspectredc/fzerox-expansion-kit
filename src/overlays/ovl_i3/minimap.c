#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_assets.h"

u8* sCourseMinimapTex;

u16 sCourseMinimapPalette[] = { GPACK_RGBA5551(0, 0, 0, 0), GPACK_RGBA5551(0, 0, 0, 1),
                                GPACK_RGBA5551(255, 255, 255, 1), GPACK_RGBA5551(100, 100, 100, 1) };

s32 sPlayerMinimapPositions[][4][2] = {
    { { 232, 132 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 246, 40 }, { 246, 152 }, { 0, 0 }, { 0, 0 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 210, 152 } },
    { { 106, 58 }, { 106, 170 }, { 248, 58 }, { 248, 170 } },
};

s32 gPlayerMinimapLapCounterToggle[] = { 0, 0, 0, 0 };

extern bool gInCourseEditor;
extern s32 gNumPlayers;

void func_i3_InitCourseMinimap(void) {
    s32 pad[23];
    s32 i;
    f32 temp_fs1;
    f32 temp_fs3;
    f32 var_fs0;
    s32 temp_s0;
    s32 temp_v0;
    CourseSegment* temp_s5;
    CourseSegment* var_s1;
    f32 sp90;
    Vec3f sp84;
    Vec3f sp78;
    CourseInfo* sp74;

    if (!gInCourseEditor) {
        sCourseMinimapTex = Arena_Allocate(ALLOC_FRONT, 0x1000);
    }

    sp74 = gCurrentCourseInfo;

    if (gNumPlayers == 1) {
        sp90 = 1;
    } else {
        sp90 = 0.75f;
    }

    for (i = 0; i < 0x1000; i++) {
        sCourseMinimapTex[i] = 0;
    }
    var_s1 = sp74->courseSegments;
    var_fs0 = 0.0f;
    temp_fs3 = 64.0f * sp90;

    temp_s5 = var_s1;

    while (true) {
        temp_fs1 = Course_SplineGetTangent(var_s1, var_fs0, &sp84);
        Course_SplineGetPosition(var_s1, var_fs0, &sp78);
        temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
        temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
        if ((temp_s0 >= 0) && (temp_s0 < 64)) {
            temp_v0 /= 2;
            if ((temp_v0 >= 0) && (temp_v0 < 64)) {
                if (temp_s0 > 0) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 1] = 1;
                }
                if (temp_s0 < 63) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 1] = 1;
                }
                if (temp_v0 > 0) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 64] = 1;
                }
                if (temp_v0 < 63) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 64] = 1;
                }
            }
        }
        var_fs0 += 200.0f / temp_fs1;
        if (var_fs0 >= 1.0f) {
            var_s1 = var_s1->next;
            if (temp_s5 == var_s1) {
                break;
            }
            var_fs0 -= 1.0f;
            var_fs0 *= (temp_fs1 / Course_SplineGetTangent(var_s1, 0.0f, &sp84));
        }
    }

    var_s1 = sp74->courseSegments;
    var_fs0 = 0.0f;
    temp_s5 = var_s1;

    while (true) {
        temp_fs1 = Course_SplineGetTangent(var_s1, var_fs0, &sp84);
        Course_SplineGetPosition(var_s1, var_fs0, &sp78);
        temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
        temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
        if ((temp_s0 > 0) && (temp_s0 < 64)) {
            temp_v0 /= 2;
            if ((temp_v0 > 0) && (temp_v0 < 64)) {
                if (temp_s5 == var_s1->next) {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 3;
                } else {
                    sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 2;
                }
            }
        }
        var_fs0 += 200.0f / temp_fs1;
        if (var_fs0 >= 1.0f) {
            var_s1 = var_s1->next;
            if (temp_s5 == var_s1) {
                break;
            }
            var_fs0 -= 1.0f;
            var_fs0 *= (temp_fs1 / Course_SplineGetTangent(var_s1, 0.0f, &sp84));
        }
    }

    var_s1 = sp74->courseSegments;
    Course_SplineGetTangent(var_s1, 0.0f, &sp84);
    Course_SplineGetPosition(var_s1, 0.0f, &sp78);
    temp_s0 = Math_Round(((sp78.x * 64.0f * sp90) / 16000.0f) + temp_fs3) / 2;
    temp_v0 = Math_Round(((sp78.z * 64.0f * sp90) / 16000.0f) + temp_fs3);
    if ((temp_s0 > 0) && (temp_s0 < 63)) {
        temp_v0 /= 2;
        if ((temp_v0 > 0) && (temp_v0 < 63)) {
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 0] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 1] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 1] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 64] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 64] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 65] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 63] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 - 63] = 1;
            sCourseMinimapTex[temp_v0 * 64 + temp_s0 + 65] = 1;
        }
    }
}

extern s16 gSettingVsCom;
extern s8 D_8076C7D8;
extern s32 gGameMode;
extern s32 gTotalRacers;
extern Racer* gRacersByPosition[];
extern GhostRacer* gFastestGhostRacer;
extern u32 gGameFrameCount;

Gfx* func_i3_DrawCourseMinimap(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    Controller* controller = &gControllers[gPlayerControlPorts[playerIndex]];
    Racer* racer;
    s32 i;
    s32 numPlayers;
    s32 left;
    s32 top;
    f32 minimapScale;
    s32 playerMarkerLeftPos;
    s32 playerMarkerRightPos;

    if ((controller->buttonPressed & BTN_CLEFT) && (numPlayersIndex >= 2)) {
        if (D_8076C7D8 == 0) {
            gPlayerMinimapLapCounterToggle[playerIndex] = (gPlayerMinimapLapCounterToggle[playerIndex] + 1) % 2;
        }
    }
    if (((numPlayersIndex != 2) || (playerIndex != 3)) && (gPlayerMinimapLapCounterToggle[playerIndex] == 0) &&
        (numPlayersIndex >= 2)) {
        return gfx;
    }

    switch (numPlayersIndex) {
        case 0:
            minimapScale = 1.0f;
            break;
        case 1:
            minimapScale = 0.75f;
            break;
        case 2:
        case 3:
            minimapScale = 0.75f;
            break;
    }

    left = sPlayerMinimapPositions[numPlayersIndex][playerIndex][0];
    top = sPlayerMinimapPositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_8014940);
    gDPLoadTLUT_pal256(gfx++, sCourseMinimapPalette);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, (sCourseMinimapTex + (i * 64 * (s32) (64 * minimapScale)) / 2), G_IM_FMT_CI,
                            G_IM_SIZ_8b, 64, (s32) (64 * minimapScale) / 2, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, left << 2, (s32) (top + (((i * 64) / 2) * minimapScale)) << 2,
                            (s32) (left + 64 * minimapScale) << 2,
                            (s32) (top + ((i * 64) / 2 + 32) * minimapScale) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P)) {
        numPlayers = gTotalRacers;
    } else {
        numPlayers = numPlayersIndex + 1;
    }

    for (i = 0; i < numPlayers; i++) {
        if (i == playerIndex) {
            continue;
        }
        playerMarkerLeftPos =
            Math_Round(((gRacers[i].segmentPositionInfo.segmentPos.x * 64.0f * minimapScale) / 16000.0f) +
                       (64 * minimapScale)) /
            2;
        playerMarkerRightPos =
            Math_Round(((gRacers[i].segmentPositionInfo.segmentPos.z * 64.0f * minimapScale) / 16000.0f) +
                       (64 * minimapScale)) /
            2;
        playerMarkerLeftPos += left;
        playerMarkerRightPos += top;
        gDPPipeSync(gfx++);

        // Player Markers
        switch (i) {
            case 0:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 255, 1) << 16 | GPACK_RGBA5551(0, 255, 255, 1));
                break;
            case 1:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 255, 0, 1) << 16 | GPACK_RGBA5551(255, 255, 0, 1));
                break;
            case 2:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1));
                break;
            case 3:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 127, 255, 1) << 16 | GPACK_RGBA5551(255, 127, 255, 1));
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                         playerMarkerRightPos + 1);
    }
    if (numPlayersIndex == 0) {
        if (gGameMode == GAMEMODE_GP_RACE) {
            // Lead Non-Player Racer Marker
            if (gRacers[0].position == 1) {
                racer = gRacersByPosition[1];
            } else {
                racer = gRacersByPosition[0];
            }
            playerMarkerLeftPos =
                Math_Round(((racer->segmentPositionInfo.segmentPos.x * 64.0f * minimapScale) / 16000.0f) +
                           (64 * minimapScale)) /
                2;
            playerMarkerRightPos =
                Math_Round(((racer->segmentPositionInfo.segmentPos.z * 64.0f * minimapScale) / 16000.0f) +
                           (64 * minimapScale)) /
                2;
            playerMarkerLeftPos += left;
            playerMarkerRightPos += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 255, 1) << 16 | GPACK_RGBA5551(0, 0, 255, 1));
            gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                             playerMarkerRightPos + 1);

        } else if (gFastestGhostRacer != NULL) {
            // Ghost Racer Marker
            playerMarkerLeftPos =
                Math_Round(
                    ((gFastestGhostRacer->racer->segmentPositionInfo.segmentPos.x * 64.0f * minimapScale) / 16000.0f) +
                    (64 * minimapScale)) /
                2;
            playerMarkerRightPos =
                Math_Round(
                    ((gFastestGhostRacer->racer->segmentPositionInfo.segmentPos.z * 64.0f * minimapScale) / 16000.0f) +
                    (64 * minimapScale)) /
                2;
            playerMarkerLeftPos += left;
            playerMarkerRightPos += top;

            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
            gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                             playerMarkerRightPos + 1);
        }
    }
    if ((gGameFrameCount % 16) < 8) {
        if ((numPlayersIndex < playerIndex) && (gSettingVsCom == 0)) {
            return gfx;
        }

        playerMarkerLeftPos =
            Math_Round(((gRacers[playerIndex].segmentPositionInfo.segmentPos.x * 64.0f * minimapScale) / 16000.0f) +
                       (64 * minimapScale)) /
            2;
        playerMarkerRightPos =
            Math_Round(((gRacers[playerIndex].segmentPositionInfo.segmentPos.z * 64.0f * minimapScale) / 16000.0f) +
                       (64 * minimapScale)) /
            2;
        playerMarkerLeftPos += left;
        playerMarkerRightPos += top;

        gDPPipeSync(gfx++);

        switch (playerIndex) {
            case 0:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 255, 1) << 16 | GPACK_RGBA5551(0, 255, 255, 1));
                break;
            case 1:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 255, 0, 1) << 16 | GPACK_RGBA5551(255, 255, 0, 1));
                break;
            case 2:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 255, 0, 1) << 16 | GPACK_RGBA5551(0, 255, 0, 1));
                break;
            case 3:
                gDPSetFillColor(gfx++, GPACK_RGBA5551(255, 127, 255, 1) << 16 | GPACK_RGBA5551(255, 127, 255, 1));
                break;
        }

        gDPFillRectangle(gfx++, playerMarkerLeftPos - 1, playerMarkerRightPos - 1, playerMarkerLeftPos + 1,
                         playerMarkerRightPos + 1);
    }

    return gfx;
}
