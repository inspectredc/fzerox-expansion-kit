#ifndef OVL_I7_H
#define OVL_I7_H

#include "unk_structs.h"

typedef struct unk_8014B480 {
    Mtx unk_00[3];
    Mtx unk_C0[3];
    Vtx unk_180[3][13];
    Mtx unk_3F0[3];
} unk_8014B480; // size = 0x4B0

typedef struct unk_8014BE28 {
    s16 unk_00;
    s16 track;
    s16 unk_04;
    s16 unk_06;
    f32 unk_08;
    f32 unk_0C;
} unk_8014BE28; // size = 0x10

typedef struct unk_8014BEC8 {
    s16 unk_00;
    u16 unk_02;
    s16 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
} unk_8014BEC8; // size = 0x20

typedef struct unk_8014BF98 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14[0x4];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    s8 unk_24;
    s8 unk_25;
    f32 unk_28;
    s8 unk_2C;
    s16 unk_2E;
    s16 unk_30;
    s32 unk_34;
    s8 unk_38[0x4];
    s32 unk_3C;
} unk_8014BF98; // size = 0x40

typedef struct unk_8014BF94 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14[0x4];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    s8 unk_24[0x4];
    s32 unk_28;
    s32 unk_2C;
    s8 unk_30[0x4];
} unk_8014BF94; // size = 0x34

typedef enum EndScreenState {
    /* 0 */ END_SCREEN_INACTIVE,
    /* 1 */ END_SCREEN_FADE_IN,
    /* 2 */ END_SCREEN_WAIT,
    /* 3 */ END_SCREEN_FADE_OUT,
} EndScreenState;

s32 func_i7_8009318C(void);
Gfx* func_i7_80093A18(Gfx* gfx);
Gfx* func_i7_DrawFinalResultsRaceResult(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_DrawFinalResultsPosition(Gfx* gfx, s32 xPos, s32 yPos, s32 position, bool shouldHighlight);
Gfx* func_i7_DrawFinalResultsCupInfo(Gfx*, unk_8014BE28*, f32);
void func_i7_FadeInThanksForPlaying(void);
Gfx* func_i7_DrawThanksForPlayingWindow(Gfx* gfx);
Gfx* func_i7_800943A0(Gfx*, unk_8014BE28*, f32);
Gfx* func_i7_DrawResultsRacersKOd(Gfx* gfx, s32 left, s32 top, s32 racersKOd);
void func_i7_FadeEndScreen(void);
Gfx* func_i7_DrawEndScreen(Gfx* gfx);
void func_i7_800956E8(void);
void func_i7_8009580C(void);
Gfx* func_i7_80095D14(Gfx* gfx);

Gfx* func_i7_800969B8(Gfx* gfx);
void func_i7_80096BB0(void);
void func_i7_80096DAC(void);

extern unk_8014B480 D_8009A3A0[2];

extern unk_8014B480* D_i7_8009AD10;
extern s16 sCupDifficulty;
extern unk_8014BEC8 D_i7_8009ADE8[3];
extern u16 D_i7_8009AE48;

extern u16 D_i7_80099CA8[];
extern u16 D_i7_80099D30[];
extern u16 D_i7_80099DB8[];

extern s16 D_i7_8009AEB2;
extern s32 D_i7_8009B168;

#endif // OVL_I7_H
