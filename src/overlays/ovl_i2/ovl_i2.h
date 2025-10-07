#ifndef OVL_I2_H
#define OVL_I2_H

#include "libultra/ultra64.h"
#include "other_types.h"

typedef struct unk_8010D778_unk_18 {
    s8 unk_00;
    u8 unk_01;
} unk_8010D778_unk_18; // size = 0x2

typedef struct unk_8010D778_unk_18_2 {
    s8 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} unk_8010D778_unk_18_2; // size = 0x1C

typedef struct unk_8010D778_unk_18_3 {
    s8 unk_00;
    s8 unk_01;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_8010D778_unk_18_3; // size = 0x14

typedef struct unk_8010D778_unk_1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} unk_8010D778_unk_1C; // size = 0x14

typedef struct Transition {
    s32 activeTransitionType;
    s32 queuedTransitionType;
    s32 state;
    s16 timer;
    s16 unk_0E;
    u16 appearType;
    u16 flags;
    TexturePtr backgroundBuffer;
    void* workBuffer;
    unk_8010D778_unk_1C unk_1C;
} Transition; // size = 0x30

typedef enum TransitionAppearType {
    /* 0 */ TRANSITION_APPEAR,
    /* 1 */ TRANSITION_HIDE,
} TransitionAppearType;

#define TRANSITION_BORDER_WIDTH 12
#define TRANSITION_BORDER_HEIGHT 8
#define TRANSITION_BACKGROUND_WIDTH (SCREEN_WIDTH - TRANSITION_BORDER_WIDTH * 2)
#define TRANSITION_BACKGROUND_HEIGHT (SCREEN_HEIGHT - TRANSITION_BORDER_HEIGHT * 2)

typedef enum TransitionType {
    /*  0 */ TRANSITION_TYPE_NONE,
    /*  1 */ TRANSITION_TYPE_SMALL_TILES,
    /*  2 */ TRANSITION_TYPE_LARGE_TILES,
    /*  3 */ TRANSITION_TYPE_TILED_WHIRL,
    /*  4 */ TRANSITION_TYPE_TILED_SPIRAL,
    /*  5 */ TRANSITION_TYPE_FADE,
    /*  6 */ TRANSITION_TYPE_STATIC_FADE,
    /*  7 */ TRANSITION_TYPE_PHASED_STRIPS,
    /*  8 */ TRANSITION_TYPE_GREYSCALE_PALETTE,
    /*  9 */ TRANSITION_TYPE_WIPE_LEFT,
    /* 10 */ TRANSITION_TYPE_INSTANT,
} TransitionType;

#define TRANSITION_STATE_INACTIVE 0

typedef enum TransitionSmallTilesState {
    /* 1 */ SMALL_TILES_START_APPEAR = 1,
    /* 2 */ SMALL_TILES_WAIT,
    /* 3 */ SMALL_TILES_START_HIDE,
    /* 4 */ SMALL_TILES_FINISHED,
} TransitionSmallTilesState;

#define SMALL_TILES_WIDTH 4
#define SMALL_TILES_HEIGHT 4
#define SMALL_TILES_COLUMNS (TRANSITION_BACKGROUND_WIDTH / SMALL_TILES_WIDTH)
#define SMALL_TILES_ROWS (TRANSITION_BACKGROUND_HEIGHT / SMALL_TILES_HEIGHT)
#define SMALL_TILES_WORK_SIZE (SMALL_TILES_COLUMNS * SMALL_TILES_ROWS / 2)

#define SMALL_TILES_TILE_UNSET 0
#define SMALL_TILES_TILE_SET 1
#define SMALL_TILES_TILE_FINISHED 2

#define TRANSITION_FLAG_SET_BACKGROUND_BUFFER (1 << 0)
#define TRANSITION_FLAG_DRAW (1 << 1)
#define TRANSITION_FLAG_FILL_BLACK (1 << 2)
#define TRANSITION_FLAG_FINISHED (1 << 3)
#define TRANSITION_FLAG_GREYSCALE (1 << 4)
#define TRANSITION_FLAG_INVERSE_GREYSCALE (1 << 5)
#define TRANSITION_FLAG_CONVERT_TO_PALETTE (1 << 6)

s32 Transition_Queue(s32 appearType, s32 transitionType);
s32 Transition_QueueRandom(s32, bool);
s32 Transition_Update(void);
void Transition_PopQueue(Transition*);
void Transition_SmallTilesInit(Transition*);
void Transition_SmallTilesUpdate(Transition*);
bool Transition_SmallTilesUpdateState(Transition*);
s32 Transition_SmallTilesFindUnsetSurroundingTiles(Transition*, s32, bool*);
s32 Transition_SmallTilesGetTileState(Transition*, s32);
void Transition_SmallTilesSetTileState(Transition*, s32, s8);
Gfx* Transition_SmallTilesDraw(Gfx*, Transition*);
void Transition_LargeTilesInit(Transition*);
void Transition_LargeTilesUpdate(Transition*);
bool func_i2_800A3620(Transition*);
Gfx* Transition_LargeTilesDraw(Gfx*, Transition*);
void Transition_TiledWhirlInit(Transition*);
void Transition_TiledWhirlUpdate(Transition*);
bool func_i2_800A4078(Transition*);
Gfx* Transition_TiledDraw(Gfx*, Transition*);
void Transition_TiledSpiralInit(Transition*);
void Transition_TiledSpiralUpdate(Transition*);
bool func_i2_800A4E1C(Transition*);
void Transition_FadeInit(Transition*, s32, s32);
void Transition_FadeUpdate(Transition*);
Gfx* Transition_FadeDraw(Gfx*, Transition*);
void Transition_WipeLeftInit(Transition*);
void Transition_WipeLeftUpdate(Transition*);
Gfx* Transition_WipeLeftDraw(Gfx*, Transition*);
void Transition_PhasedStripsInit(Transition*);
void Transition_PhasedStripsUpdate(Transition*);
bool func_i2_800A56D4(Transition*);
Gfx* Transition_PhasedStripsDraw(Gfx*, Transition*);
void Transition_GreyscalePaletteInit(Transition*);
void Transition_GreyscalePaletteUpdate(Transition*);
bool func_i2_800A5C70(Transition*);
Gfx* Transition_GreyscalePaletteDraw(Gfx*, Transition*);

#endif // OVL_I2_H
