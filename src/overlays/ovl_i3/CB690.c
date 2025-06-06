#include "global.h"
#include "ovl_i3.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_hud.h"
#include "fzx_assets.h"

extern s32 D_i3_8006B708[];
extern u32 gGameFrameCount;

Gfx* func_i3_80059EC0(Gfx* gfx, s32 arg1) {
    s32 temp_a3;
    s32 temp_a2;
    s32 red;
    s32 green;
    s32 blue;
    s32 temp_hi;
    s32* temp_a0;
    s32 pad;

    temp_hi = (((gGameFrameCount * arg1) % 300) * 8) % 300;
    temp_a2 = temp_hi % 100;
    temp_a3 = 100 - temp_a2;
    temp_a0 = &D_i3_8006B708[((temp_hi / 100) % 3) * 3];

    red = ((temp_a0[0] * temp_a3) + (temp_a0[3] * temp_a2)) / 100;
    green = ((temp_a0[1] * temp_a3) + (temp_a0[4] * temp_a2)) / 100;
    blue = ((temp_a0[2] * temp_a3) + (temp_a0[5] * temp_a2)) / 100;
            
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);

    return gfx;
}

Gfx* func_i3_DrawTimerDigitRectangle(Gfx* gfx, s32 left, s32 top, s32 number, f32 scale) {

    if (number >= 15) {
        return gfx;
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 8.0f) << 2, (s32) (top + 16.0f * scale) << 2, 0, 0,
                        (number * 16) << 5, 1 << 10, (s32) (1024.0f / scale));
    return gfx;
}

Gfx* func_i3_DrawTimerDigitScisRectangle(Gfx* gfx, s32 left, s32 top, s32 number, f32 scale) {

    if (number >= 15) {
        return gfx;
    }

    gSPScisTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 8.0f * scale) << 2,
                            (s32) (top + 16.0f * scale) << 2, 0, 0, (number * 16) << 5, (s32) (1024.0f / scale),
                            (s32) (1024.0f / scale));
    return gfx;
}

extern s32 sPracticeBestLapCounter;
extern bool sSecondLapStarted;
extern bool sFinalLapStarted;
extern s32 D_i3_8006B5EC;
extern f32 sPositionScales[];
extern unk_80141EA8 D_i3_8006D678[4];
extern s32 gPlayerLapNumbers[];

#ifdef IMPORT_BSS
void func_i3_8005A464(void) {
    s32 i;

    sPracticeBestLapCounter = 0;
    sSecondLapStarted = false;
    sFinalLapStarted = false;

    func_i2_800AE7C4(aBestTex, TEX_SIZE(aBestTex, sizeof(u16)), 0, 0, 0);

    if (gGameMode == GAMEMODE_PRACTICE) {
        D_i3_8006B5EC = 360;
    } else {
        D_i3_8006B5EC = 180;
    }

    for (i = 0; i < 4; i++) {
        D_i3_8006D678[i].unk_00 = 0;
        D_i3_8006D678[i].unk_04 = 0;
        D_i3_8006D678[i].lapIntervalCounter = 0;
        D_i3_8006D678[i].unk_0C.time = 0;

        sPositionScales[i] = 1.0f;
        gPlayerLapNumbers[i] = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_8005A464.s")
#endif

void func_i3_8005A590(unk_8012F450* arg0) {

    if (arg0->time < 360000) {
        arg0->time++;
    }

    arg0->hours = arg0->time / 3600;
    arg0->minutes = (arg0->time / 60) % 60;
    arg0->minuteFraction = (arg0->time % 60) / 60.0f;

    if (arg0->hours >= 100) {
        arg0->minuteFraction = 0.99f;
        arg0->minutes = 60 - 1;
        arg0->hours = 100 - 1;
    }
}

Gfx* func_i3_DrawTimerScisThousandths(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    s32 timeField;

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, 0, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8.0f * scale;
    } else {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8.0f * scale;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);
    offset += 8.0f * scale;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, 0, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8.0f * scale;
    } else {
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8.0f * scale;
        gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8.0f * scale;
    }

    time -= timeField * 1000;
    timeField = time / 100;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8.0f * scale;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
    offset += 8.0f * scale;

    time -= timeField * 100;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, timeField, scale);
    offset += 8.0f * scale;

    time -= timeField * 10;

    return func_i3_DrawTimerDigitScisRectangle(gfx, left + offset, top, time, scale);
}

Gfx* func_i3_DrawBlankTimeHundredths(Gfx* gfx, s32 left, s32 top) {
    s32 offset = 0;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    return func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
}

Gfx* func_i3_DrawBlankTimeThousandths(Gfx* gfx, s32 left, s32 top) {
    s32 offset = 0;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
    offset += 8;
    return func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, 1.0f);
}

extern s32 sPlayerTimerPositions[][4][2];

Gfx* func_i3_DrawPlayerTimer(Gfx* gfx, s32 time, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad;
    s32 top;
    s32 left;
    s32 offset = 0;
    s32 timeField;
    f32 scale;

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    left = sPlayerTimerPositions[numPlayersIndex][playerIndex][0];
    top = sPlayerTimerPositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            scale = 1.0f;
            break;
        case 2:
        case 3:
            scale = 0.75f;
            break;
    }

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

extern s32 gGameMode;
extern s32 sPlayerTimePositions[][4][2];

Gfx* func_i3_DrawTimeRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 right;
    s32 left;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }

    left = sPlayerTimePositions[numPlayersIndex][playerIndex][0];
    right = sPlayerTimePositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149D0);
    gSPTextureRectangle(gfx++, left << 2, right << 2, (left + 23) << 2, (right + 15) << 2, 0, 0, 0, 1 << 12, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

extern s32 gTotalLapCount;
extern s16 D_807A16CC;
extern s16 D_807A16E0;
extern s8 gGamePaused;
extern s32 sPreviousLapTimes[];

Gfx* func_i3_UpdatePlayerHudInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad[2];
    s32 lap;
    bool newLap;

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    lap = gRacers[playerIndex].lap;
    newLap = false;

    if (gGameMode == GAMEMODE_PRACTICE) {
        if (gRacers[playerIndex].startNewPracticeLap) {
            newLap = true;
        }
    } else if (gPlayerLapNumbers[playerIndex] < lap) {
        newLap = true;
    }

    if (newLap) {
        gRacers[playerIndex].startNewPracticeLap = false;
        gPlayerLapNumbers[playerIndex] = lap;

        D_i3_8006D678[playerIndex].unk_04 = D_i3_8006B5EC;
        if ((gRacers[playerIndex].position != 1) || (gGameMode == GAMEMODE_TIME_ATTACK)) {
            D_i3_8006D678[playerIndex].lapIntervalCounter = 90;
        }
        if ((lap == 2) && !sSecondLapStarted && (D_807A16E0 != 0) && (gGameMode != GAMEMODE_PRACTICE)) {
            func_8074122C(0x11);
            sSecondLapStarted = true;
        }
        if ((lap == gTotalLapCount) && !sFinalLapStarted && (D_807A16E0 != 0) && (gGameMode != GAMEMODE_PRACTICE)) {
            func_8074122C(0x12);
            sFinalLapStarted = true;
        }
    }

    if (D_i3_8006B5EC == D_i3_8006D678[playerIndex].unk_04) {
        sPreviousLapTimes[playerIndex] = gRacers[playerIndex].lapTimes[(lap + 1) % 3];
    }

    func_i3_8005A590(&D_i3_8006D678[playerIndex].unk_0C);

    if (D_i3_8006D678[playerIndex].unk_04 > 0) {
        if (!gGamePaused) {
            D_i3_8006D678[playerIndex].unk_04--;
        }
        if ((D_i3_8006D678[playerIndex].unk_04 % 20) >= 5) {
            if ((numPlayersIndex != 0) && (D_807A16CC != 0) && (gRacers[playerIndex].position != 1)) {
                return gfx;
            }

            gfx = func_i3_DrawPlayerTimer(gfx, sPreviousLapTimes[playerIndex] + 5, numPlayersIndex, playerIndex);
        }
    } else if (numPlayersIndex < 2) {
        if (gGameMode == GAMEMODE_PRACTICE) {
            return gfx;
        }
        if ((numPlayersIndex == 1) && (D_807A16CC != 0)) {
            return gfx;
        }

        gfx = func_i3_DrawPlayerTimer(gfx, gRacers[playerIndex].raceTime + 5, numPlayersIndex, playerIndex);
    }
    return gfx;
}

extern s32 sEnergyBarPositions[][4][2];
extern s32 sEnergyBarFillColors[];

Gfx* func_i3_DrawEnergyBar(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 energyWidth;
    s32 left;
    s32 top;
    s32 height;
    f32 scale;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }

    left = sEnergyBarPositions[numPlayersIndex][playerIndex][0];
    top = sEnergyBarPositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            height = 5;
            scale = 1.0f;
            break;
        case 2:
        case 3:
            height = 3;
            top++;
            scale = 0.75f;
            break;
    }

    energyWidth = Math_Round((gRacers[playerIndex].energy / gRacers[playerIndex].maxEnergy) * 68.0f * scale);

    gSPDisplayList(gfx++, D_80149A0);

    for (i = 0; i < height; i++) {
        gDPPipeSync(gfx++);
        if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_100000) {
            gDPSetFillColor(gfx++, sEnergyBarFillColors[i + 5]);
        } else {
            gDPSetFillColor(gfx++, sEnergyBarFillColors[i]);
        }

        gDPFillRectangle(gfx++, left, top + i, left + energyWidth - 1, top + i);
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

extern s32 sEnergyOutlinePositions[][4][2];

Gfx* func_i3_DrawEnergyOutlineRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    UNUSED s32 pad;
    s32 top;
    s32 left;
    s32 width;
    s32 height;
    f32 scale;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_80149D0);

    left = sEnergyOutlinePositions[numPlayersIndex][playerIndex][0];
    top = sEnergyOutlinePositions[numPlayersIndex][playerIndex][1];

    switch (numPlayersIndex) {
        case 0:
        case 1:
            scale = 1.0f;
            width = 71.0f * scale;
            height = 15.0f * scale;
            break;
        case 2:
        case 3:
            scale = 0.75f;
            width = 72.0f * scale;
            height = 16.0f * scale;
            break;
    }

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0,
                        (s32) ((1 << 12) / scale), (s32) ((1 << 10) / scale));

    return gfx;
}

extern s32 sSpeedPositions[][4][2];

Gfx* func_i3_DrawPlayerSpeed(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    s32 left;
    s32 top;
    s32 height;
    s32 digit;
    s32 speedRemainder;
    s32 speed;
    s32 digitMask;
    f32 heightScale;

    if ((numPlayersIndex >= 2) && (D_i3_8006D678[playerIndex].unk_04 != 0)) {
        return gfx;
    }

    switch (numPlayersIndex) {
        case 0:
        case 1:
            heightScale = 1.0f;
            height = 15;
            break;
        case 2:
        case 3:
            heightScale = 0.75f;
            height = 16.0f * heightScale;
            break;
    }

    digitMask = 1000;
    speedRemainder = speed = Math_Round(gRacers[playerIndex].speed * 21.6f);
    left = sSpeedPositions[numPlayersIndex][playerIndex][0];
    top = sSpeedPositions[numPlayersIndex][playerIndex][1];

    gSPDisplayList(gfx++, D_80149A0);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));

    gDPFillRectangle(gfx++, left + 12, top, left + 35, top + height);

    gSPDisplayList(gfx++, D_80149D0);

    gDPLoadTextureBlock(gfx++, D_303B270, G_IM_FMT_RGBA, G_IM_SIZ_16b, 12, 160, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (i = 0; i < 4; i++) {
        digit = speedRemainder / digitMask;
        if ((i != 3) && (digit == 0) && (speed == speedRemainder)) {
            speedRemainder %= digitMask;
            digitMask /= 10;
        } else {
            gSPTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 11) << 2,
                                (top + height) << 2, 0, 0, (digit * 16) << 5, 1 << 12, (s32) ((1 << 10) / heightScale));
            speedRemainder %= digitMask;
            digitMask /= 10;
        }
    }

    gDPLoadTextureBlock(gfx++, D_303C170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + (i * 12)) << 2, top << 2, (left + (i * 12) + 19) << 2, (top + height) << 2, 0, 0,
                        0, 1 << 12, (s32) ((1 << 10) / heightScale));

    return gfx;
}

extern s16 gCpuRacersRetired;
extern s32 gTotalRacers;

Gfx* func_i3_DrawRacePositionExtras(Gfx* gfx, s32 left, s32 top) {
    s32 i;
    s32 xOffset;
    s32 digit;
    s32 racersRemaining;
    s32 digitMask;
    f32 scale = 0.25f;

    digitMask = 10;
    racersRemaining = gTotalRacers - gCpuRacersRetired;

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        gDPPipeSync(gfx++);

        left -= 88;
        top += 16;

        gDPLoadTextureBlock(gfx++, aRacersLeftTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 32) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        return gfx;
    }

    gDPPipeSync(gfx++);

    top += 20;

    gDPLoadTextureBlock(gfx++, aTotalRacerDigitsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 132, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    // Draw /
    gSPTextureRectangle(gfx++, (left - 2) << 2, top << 2, ((left - 2) + 8) << 2, (top + 12) << 2, 0, 0, (10 * 12) << 5,
                        1 << 10, 1 << 10);

    xOffset = 28.0f * scale;

    left += 6;

    // Draw Remaining Racer Digits
    for (i = 0; i < 2; i++) {
        digit = racersRemaining / digitMask;
        if ((i == 0) && (digit == 0)) {
            left += xOffset;
            digitMask /= 10;
        } else {
            gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 8) << 2, (top + 12) << 2, 0, 0, (digit * 12) << 5,
                                1 << 10, 1 << 10);

            left += xOffset;
            racersRemaining %= digitMask;
            digitMask /= 10;
        }
    }

    return gfx;
}

Gfx* func_i3_DrawPositionSuffixRectangle(Gfx* gfx, s32 left, s32 top, f32 scale) {

    gSPTextureRectangle(gfx++, left << 2, (s32) (top + (12.0f * scale)) << 2, (s32) (left + (20.0f * scale)) << 2,
                        (s32) (top + (12.0f * scale) + (20.0f * scale)) << 2, 0, 0, 0, (s32) ((1 << 10) / scale),
                        (s32) ((1 << 10) / scale));

    return gfx;
}

extern s32 sPositionPositions[][4][2];

Gfx* func_i3_DrawPosition(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 i;
    u8* positionTexturePtr;
    s32 positionDigit;
    f32 leftAdjustment;
    f32 scaleDiff;
    s32 positionSuffix;
    s32 top;
    s32 left;
    f32 scale;
    f32 baseScale;
    s32 digitMask;
    s32 position;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        return gfx;
    }

    if (gRacers[playerIndex].stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_RETIRED)) {
        sPositionScales[playerIndex] += 0.04f;
    }

    if (sPositionScales[playerIndex] > 1.5f) {
        sPositionScales[playerIndex] = 1.5f;
    }

    left = sPositionPositions[numPlayersIndex][playerIndex][0];
    top = sPositionPositions[numPlayersIndex][playerIndex][1];

    digitMask = 10;

    switch (numPlayersIndex) {
        case 0:
            sPositionScales[playerIndex] = 1.0f;
        /* fallthrough */
        case 1:
            baseScale = scale = 1.0f;
            break;
        case 2:
        case 3:
            baseScale = scale = 0.75f;
            break;
    }
    scale *= sPositionScales[playerIndex];

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        position = (gTotalRacers - gCpuRacersRetired) - 1;
    } else {
        position = gRacers[playerIndex].position;
    }

    if (numPlayersIndex != 0) {
        scaleDiff = scale - baseScale;
        leftAdjustment = (scaleDiff * 28.0f) / 2;
    } else {
        scaleDiff = scale - baseScale;
        leftAdjustment = scaleDiff * 28.0f;
    }

    switch (position) {
        case 1:
            positionSuffix = POSITION_SUFFIX_ST;
            break;
        case 2:
            positionSuffix = POSITION_SUFFIX_ND;
            break;
        case 3:
            positionSuffix = POSITION_SUFFIX_RD;
            break;
        default:
            positionSuffix = POSITION_SUFFIX_TH;
            break;
    }

    gSPDisplayList(gfx++, D_8014940);

    left -= leftAdjustment;
    top -= ((scaleDiff * 32.0f) / 2);

    positionTexturePtr = (u8*) aPositionDigitTexs;

    for (i = 0; i < 2; i++) {
        //! @bug the numPlayersIndex condition should be conditionally &&ed here
        if ((i == 0) & numPlayersIndex) {
            left += (s32) (28.0f * baseScale);
            position %= digitMask;
            digitMask /= 10;
        } else {
            positionDigit = position / digitMask;

            left += (i == 0 && positionDigit == 1) * 5;

            if ((i == 0) && (positionDigit == 0)) {
                left += (s32) (28.0f * scale);
                position %= digitMask;
                digitMask /= 10;
            } else {
                gDPPipeSync(gfx++);

                gDPLoadTextureBlock(gfx++, positionTexturePtr + ((positionDigit * 0x380) << 1), G_IM_FMT_RGBA,
                                    G_IM_SIZ_16b, 28, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, left << 2, top << 2, (s32) (left + 28.0f * scale) << 2,
                                    (s32) (top + (32.0f * scale)) << 2, 0, 0, 0, (s32) (1024.0f / scale),
                                    (s32) (1024.0f / scale));

                left += (s32) (28.0f * scale) - (i == 0 && positionDigit == 1) * 5;
                position %= digitMask;
                digitMask /= 10;
            }
        }
    }

    gDPPipeSync(gfx++);

    gDPLoadTextureBlock(gfx++, aPositionOrdinalSuffixTexs[positionSuffix], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    if (numPlayersIndex == 0) {
        gfx = func_i3_DrawRacePositionExtras(gfx, left, top);
    }

    if (numPlayersIndex == 1) {
        gfx = func_i3_DrawPositionSuffixRectangle(gfx, left, top, scale);
    }

    return gfx;
}

extern s32 sLapPositions[][4][2];
extern s32 gPlayerMinimapLapCounterToggle[];

Gfx* func_i3_DrawLapRectangle(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 top;
    s32 left;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }
    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }
    if ((gPlayerMinimapLapCounterToggle[playerIndex] != 0) && (numPlayersIndex >= 2)) {
        return gfx;
    }

    left = sLapPositions[numPlayersIndex][playerIndex][0];
    top = sLapPositions[numPlayersIndex][playerIndex][1];

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 15) << 2, (top + 11) << 2, 0, 0, 0, 1 << 12, 1 << 10);

    return gfx;
}

Gfx* func_i3_DrawLapCounter(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex) {
    s32 top;
    s32 left;
    s32 lap;

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if (gGameMode == GAMEMODE_DEATH_RACE) {
        return gfx;
    }
    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_2000000) {
        return gfx;
    }
    if ((gPlayerMinimapLapCounterToggle[playerIndex] != 0) && (numPlayersIndex >= 2)) {
        return gfx;
    }

    lap = gPlayerLapNumbers[playerIndex];
    if (gTotalLapCount < lap) {
        lap = gTotalLapCount;
    }

    left = sLapPositions[numPlayersIndex][playerIndex][0];
    top = sLapPositions[numPlayersIndex][playerIndex][1];

    top += 14;

    // Lap Number

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, (lap * 12) << 5, 1 << 12,
                        1 << 10);
    left += 8;

    // Lap /

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, 0, 1 << 12, 1 << 10);
    left += 8;

    // Lap Count

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + 7) << 2, (top + 11) << 2, 0, 0, (gTotalLapCount * 12) << 5,
                        1 << 12, 1 << 10);

    return gfx;
}

extern s32 gNumPlayers;

Gfx* func_i3_DrawHUD(Gfx* gfx) {

    gSPDisplayList(gfx++, D_8014940);

    switch (gNumPlayers) {
        case 1:
            // Time
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudTimeTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawTimeRectangle(gfx, 0, 0);

            gfx = func_i3_DrawDeathRaceBest(gfx, 0, 0);

            // Timer
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 0, 0);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 0, 0, 1.0f);

            // Best Lap Time
            gfx = func_i3_DrawPracticeBestLap(gfx);
            gfx = func_i3_DrawDeathRaceTimer(gfx, 0, 0);

            gfx = func_i3_DrawDeathRaceBestTime(gfx, 0, 0);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 0, 0);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 0, 0);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 0, 0);

            gfx = func_i3_DrawEnergyBar(gfx, 0, 0);

            gfx = func_i3_DrawReverse(gfx, 0, 0);

            gfx = func_i3_DrawPlayerLives(gfx, 0, 0);

            gfx = func_i3_DrawKOStars(gfx, 0, 0);
            break;
        case 2:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 1, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 1, 1);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 1, 0, 1.0f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 1, 1, 1.0f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 1, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 1, 1);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 1, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 1, 1);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 1, 0);
            gfx = func_i3_DrawLapCounter(gfx, 1, 1);

            gfx = func_i3_DrawEnergyBar(gfx, 1, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 1, 1);

            gfx = func_i3_DrawReverse(gfx, 1, 0);
            gfx = func_i3_DrawReverse(gfx, 1, 1);
            break;
        case 3:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 1);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 2, 2);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 0, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 1, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 2, 2, 0.75f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 1);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 2, 2);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 2, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 2, 1);
            gfx = func_i3_DrawLapRectangle(gfx, 2, 2);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 2, 0);
            gfx = func_i3_DrawLapCounter(gfx, 2, 1);
            gfx = func_i3_DrawLapCounter(gfx, 2, 2);

            gfx = func_i3_DrawEnergyBar(gfx, 2, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 2, 1);
            gfx = func_i3_DrawEnergyBar(gfx, 2, 2);

            gfx = func_i3_DrawReverse(gfx, 2, 0);
            gfx = func_i3_DrawReverse(gfx, 2, 1);
            gfx = func_i3_DrawReverse(gfx, 2, 2);
            break;
        case 4:
            // Timer
            gDPPipeSync(gfx++);
            gDPSetTextureFilter(gfx++, G_TF_POINT);

            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 0);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 1);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 2);
            gfx = func_i3_UpdatePlayerHudInfo(gfx, 3, 3);

            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 0, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 1, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 2, 0.75f);
            gfx = func_i3_UpdateRaceIntervalInfo(gfx, 3, 3, 0.75f);

            // Energy Bar
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aHudEnergyTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 72, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 0);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 1);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 2);
            gfx = func_i3_DrawEnergyOutlineRectangle(gfx, 3, 3);

            // Lap
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, D_303D1F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 12, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapRectangle(gfx, 3, 0);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 1);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 2);
            gfx = func_i3_DrawLapRectangle(gfx, 3, 3);

            // Lap Counter
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aLapCounterSymbolsTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 72, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gfx = func_i3_DrawLapCounter(gfx, 3, 0);
            gfx = func_i3_DrawLapCounter(gfx, 3, 1);
            gfx = func_i3_DrawLapCounter(gfx, 3, 2);
            gfx = func_i3_DrawLapCounter(gfx, 3, 3);

            gfx = func_i3_DrawEnergyBar(gfx, 3, 0);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 1);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 2);
            gfx = func_i3_DrawEnergyBar(gfx, 3, 3);

            gfx = func_i3_DrawReverse(gfx, 3, 0);
            gfx = func_i3_DrawReverse(gfx, 3, 1);
            gfx = func_i3_DrawReverse(gfx, 3, 2);
            gfx = func_i3_DrawReverse(gfx, 3, 3);
            break;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    return gfx;
}

extern f32 sPortraitTextureScale[];

void func_i3_UpdatePortraitScales(void) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (gRacers[i].stateFlags & RACER_STATE_FLAGS_2000000) {
            sPortraitTextureScale[i] = 1.0f;
        } else if (gRacers[i].stateFlags & RACER_STATE_FLAGS_80000) {
            sPortraitTextureScale[i] -= 0.01f;
            if (sPortraitTextureScale[i] < 0.01f) {
                sPortraitTextureScale[i] = 0.01f;
            }
        }
    }
}

extern Racer* gRacersByPosition[];
extern s32 D_i3_8006B60C[][3];

void func_i3_8005DEB8(void) {
    s32 i;
    s32 var_v1;
    Racer* racer;

    for (i = 0; i < 6; i++) {
        racer = gRacersByPosition[i];
        if (racer->stateFlags & RACER_STATE_FLAGS_80000 && racer->position < 6) {
            D_i3_8006B60C[i][1] = 90;
            D_i3_8006B60C[i][2] = racer->character;
        }
    }

    for (i = 0, var_v1 = 0; i < 6; i++) {
        if (D_i3_8006B60C[i][1] != 0) {
            if (D_i3_8006B60C[i][1] != 0) {
                D_i3_8006B60C[i][1]--;
            }
        } else {
            D_i3_8006B60C[i][2] = var_v1;
            var_v1++;
        }
    }
}

extern TexturePtr sPositionTextures[];
extern s32 sPortraitPositionYPos[];
extern s32 sPortraitYPosOffsets[];

Gfx* func_i3_DrawRacePortraits(Gfx* gfx) {
    s32 i;
    s32 position;
    s32 portraitWidth;
    s32 portraitHeight;
    s32 portraitBaseXPos;
    s32 portraitBaseYPos;
    f32 scale;
    Racer* racer;
    s32 character;

    gSPDisplayList(gfx++, D_8014940);

    func_i3_UpdatePortraitScales();

    // Draw Top 6 Positions for GAMEMODE_GP_RACE, otherwise draw just the player
    for (position = 0, i = 0; i < 6; i++, position++) {
        if (gTotalRacers == i) {
            break;
        }

        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            racer = gRacers;
        } else {
            racer = gRacersByPosition[position];
        }
        if (i < 3) {
            scale = 1.0f;
            scale *= sPortraitTextureScale[racer->id];

            portraitWidth = Math_Round(32.0f * scale);
            portraitHeight = Math_Round(32.0f * scale);
            portraitBaseXPos = (32 - portraitWidth) / 2;
            portraitBaseYPos = (32 - portraitHeight) / 2;
        } else {
            scale = 0.75f;
            scale *= sPortraitTextureScale[racer->id];

            portraitWidth = Math_Round(32.0f * scale);
            portraitHeight = Math_Round(32.0f * scale);
            portraitBaseXPos = (24.0f - portraitWidth) / 2;
            portraitBaseYPos = (24.0f - portraitHeight) / 2;
        }
        character = racer->character;
        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, gCharacterPortraitTextures[character], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, (portraitBaseXPos + 24) << 2, (portraitBaseYPos + sPortraitYPosOffsets[i]) << 2,
                            Math_Round(portraitBaseXPos + 24 + portraitWidth) << 2,
                            Math_Round(portraitBaseYPos + sPortraitYPosOffsets[i] + portraitHeight) << 2, 0, 0, 0,
                            Math_Round(1024.0f / scale), Math_Round(1024.0f / scale));

        if (gGameMode != GAMEMODE_GP_RACE) {
            break;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, sPositionTextures[position], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 6, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);
        gSPTextureRectangle(gfx++, 24 << 2, sPortraitPositionYPos[i] << 2, (24 + 16) << 2,
                            (sPortraitPositionYPos[i] + 6) << 2, 0, 0, 0, Math_Round(1024.0f), Math_Round(1024.0f));

        // Flash effect around border of players character portrait
        if ((gRacers[0].position - 1 == i) && ((gGameFrameCount % 20U) >= 5)) {
            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, aCharacterPortraitHighlightBorderTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (portraitBaseXPos + 24) << 2, (portraitBaseYPos + sPortraitYPosOffsets[i]) << 2,
                                Math_Round(portraitBaseXPos + 24 + portraitWidth) << 2,
                                Math_Round(portraitBaseYPos + sPortraitYPosOffsets[i] + portraitHeight) << 2, 0, 0, 0,
                                (s32) (1024.0f / scale), (s32) (1024.0f / scale));
        }
    }
    return gfx;
}

Gfx* func_i3_DrawTimerWithPosition(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    UNUSED s32 pad;
    s32 timeField;

    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }
    time -= (timeField * 60000);
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);
    offset += 8;
    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

Gfx* func_i3_DrawRaceTimeInterval(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale) {
    s32 offset = 0;
    UNUSED s32 pad;
    s32 timeField;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0,
                      TEXEL0, 0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    if (time >= MAX_TIMER) {
        time = MAX_TIMER;
    }
    if (time <= -MAX_TIMER) {
        time = -MAX_TIMER;
    }
    if (time < -4) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_MINUS, scale);
        time = -time;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PLUS, scale);
    }
    if (time < 0) {
        time = -time;
    }

    offset += 8;

    timeField = time / 60000;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 60000;
    timeField = time / 1000;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
        offset += 8;
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
        offset += 8;
    }

    time -= timeField * 1000;
    timeField = time / 10;

    gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, TIMER_DIGIT_DOUBLE_PRIME, scale);

    offset += 8;

    if (timeField < 10) {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, 0, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField, scale);
    } else {
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField / 10, scale);
        offset += 8;
        gfx = func_i3_DrawTimerDigitRectangle(gfx, left + offset, top, timeField % 10, scale);
    }
    return gfx;
}

extern s32 sLeadRivalRaceTime[];
extern s32 sPlayerLeadInterval[];
extern s32 sIntervalPositions[][4][2];

extern GhostRacer* gFastestGhostRacer;

Gfx* func_i3_UpdateRaceIntervalInfo(Gfx* gfx, s32 numPlayersIndex, s32 playerIndex, f32 scale) {
    Racer* leadRivalRacer;
    s32 i;
    s32 raceTime;
    s32 completedLaps;

    if (D_i3_8006D678[playerIndex].lapIntervalCounter != 0) {
        D_i3_8006D678[playerIndex].lapIntervalCounter--;
    } else {
        return gfx;
    }

    if (gGameMode == GAMEMODE_PRACTICE) {
        return gfx;
    }
    if ((gGameMode == GAMEMODE_TIME_ATTACK) && (gFastestGhostRacer == NULL)) {
        return gfx;
    }

    // Update lap interval on first frame of new lap update
    if (D_i3_8006D678[playerIndex].lapIntervalCounter == 89) {

        completedLaps = gPlayerLapNumbers[playerIndex] - 1;

        // Select leading racer that isn't this player
        if (gRacers[playerIndex].position == 1) {
            leadRivalRacer = gRacersByPosition[1];
        } else {
            leadRivalRacer = gRacersByPosition[0];
        }

        sLeadRivalRaceTime[playerIndex] = 0;

        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            for (i = 0; i < completedLaps; i++) {
                sLeadRivalRaceTime[playerIndex] += gFastestGhostRacer->ghost->lapTimes[i];
            }
        } else {
            for (i = 0; i < completedLaps; i++) {
                sLeadRivalRaceTime[playerIndex] += leadRivalRacer->lapTimes[i];
            }
        }

        raceTime = 0;
        for (i = 0; i < completedLaps; i++) {
            raceTime += gRacers[playerIndex].lapTimes[i];
        }

        sPlayerLeadInterval[playerIndex] = raceTime - sLeadRivalRaceTime[playerIndex];

        if (sPlayerLeadInterval[playerIndex] >= 0) {
            sPlayerLeadInterval[playerIndex] += 5;
        } else {
            sPlayerLeadInterval[playerIndex] -= 5;
        }
    }
    if ((D_i3_8006D678[playerIndex].lapIntervalCounter % 20) >= 5) {
        gfx = func_i3_DrawRaceTimeInterval(gfx, sPlayerLeadInterval[playerIndex],
                                           sIntervalPositions[numPlayersIndex][playerIndex][0],
                                           sIntervalPositions[numPlayersIndex][playerIndex][1], scale);
    }

    return gfx;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawReverse.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_InitRacePortraits.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_ResetLivesChangeCounter.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_TriggerLivesIncrease.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_TriggerLivesDecrease.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawKOStars.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawPlayerLives.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_8005FD34.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_8005FDB0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawPracticeBestLap.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawDeathRaceTimer.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawDeathRaceBest.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i3/CB690/func_i3_DrawDeathRaceBestTime.s")
