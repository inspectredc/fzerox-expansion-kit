#include "global.h"
#include "ovl_i2.h"
#include "fzx_game.h"
#include "fzx_assets.h"

s16 D_800D11F0;
u16 D_i2_800D11F2;
s16 D_i2_800D11F4;
Transition sTransition;
s16 D_i2_800D1228;
s16 D_i2_800D122A;
u16* sTransitionPalettePtr;
u16 sTransitionPalette[32];

s16 D_i2_800BEE10 = 1;
s32 D_800BEE14 = 0;
s16 sSurroundingTilesRelativeIndex[] = {
    -SMALL_TILES_COLUMNS - 1, -SMALL_TILES_COLUMNS, -SMALL_TILES_COLUMNS + 1, -1, 1,
    SMALL_TILES_COLUMNS - 1,  SMALL_TILES_COLUMNS,  SMALL_TILES_COLUMNS + 1
};

UNUSED Gfx D_i2_800BEE28[] = {
    gsSPEndDisplayList(),
};

f32 D_i2_800BEE30 = 3.25f;

s32 sSurroundingTileSkipChanceMask[] = { 7, 3, 3, 1, 1, 0, 0, 0 };

void Transition_Init(void) {
    Transition* transition = &sTransition;

    transition->activeTransitionType = transition->queuedTransitionType = 0;
    transition->state = 0;
    transition->timer = 0;
    transition->unk_0E = 0;
    transition->flags = 0;
    transition->backgroundBuffer = NULL;
    transition->workBuffer = NULL;
    D_i2_800D1228 = 0;
    D_i2_800D122A = 0;
    D_800D11F0 = 0;
    D_i2_800D11F4 = 0;
}

extern s32 gNumPlayers;
extern s16 D_8076C810;
extern s32 gGameMode;

void Transition_AppearSet(void) {
    D_800BEE14 = 2;

    if (D_8076C810 == 31) {
        Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_PHASED_STRIPS);
            break;
        case GAMEMODE_GP_END_CS:
            func_i2_800A26C0(TRANSITION_TYPE_FADE, 120);
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_COURSE_EDIT:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
            break;
        case GAMEMODE_CREATE_MACHINE:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
            func_i2_800A26C0(TRANSITION_TYPE_FADE, 40);
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_FLX_MACHINE_SELECT:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (D_8076C810 == 21) {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
            } else {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_SMALL_TILES);
            }
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (D_8076C810 == 21) {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
            } else {
                Transition_QueueRandom(TRANSITION_APPEAR, true);
            }
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_RECORDS:
            if (D_8076C810 != 21) {
                Transition_QueueRandom(TRANSITION_APPEAR, true);
            } else {
                Transition_Queue(TRANSITION_APPEAR, TRANSITION_TYPE_INSTANT);
            }
            break;
        default:
            Transition_QueueRandom(TRANSITION_APPEAR, true);
            break;
    }
}

extern s32 gQueuedGameMode;

void Transition_HideSet(void) {
    D_800BEE14 = 1;

    if (D_8076C810 == 33) {
        Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
        return;
    }

    switch (gQueuedGameMode) {
        case GAMEMODE_FLX_TITLE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_SMALL_TILES);
            break;
        case GAMEMODE_GP_END_CS:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        case GAMEMODE_FLX_MACHINE_SELECT:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_COURSE_EDIT:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_INSTANT);
            break;
        case GAMEMODE_CREATE_MACHINE:
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_STATIC_FADE);
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            if (D_8076C810 == 23) {
                func_i2_800A26C0(TRANSITION_TYPE_WIPE_LEFT, 2);
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_WIPE_LEFT);
            } else {
                Transition_QueueRandom(TRANSITION_HIDE, true);
            }
            break;
        case GAMEMODE_FLX_MAIN_MENU:
            if (D_8076C810 == 23) {
                func_i2_800A26C0(TRANSITION_TYPE_WIPE_LEFT, 3);
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_WIPE_LEFT);
            } else {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_PHASED_STRIPS);
            }
            break;
        case GAMEMODE_RECORDS:
            if (D_8076C810 != 23) {
                Transition_QueueRandom(TRANSITION_HIDE, true);
            } else {
                Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_WIPE_LEFT);
            }
            break;
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            func_i2_800A26C0(TRANSITION_TYPE_FADE, 60);
            Transition_Queue(TRANSITION_HIDE, TRANSITION_TYPE_FADE);
            break;
        default:
            Transition_QueueRandom(TRANSITION_HIDE, true);
            break;
    }
}

extern u32 gGameFrameCount;

s32 Transition_Queue(s32 appearType, s32 transitionType) {
    size_t backgroundBufferSize;
    size_t workBufferSize;
    Transition* transition = &sTransition;

    transition->queuedTransitionType = transitionType;
    transition->appearType = appearType;
    if (transition->queuedTransitionType != D_i2_800D122A) {
        transition->unk_0E = 0;
    } else {
        transition->unk_0E = D_i2_800D1228;
        D_i2_800D122A = TRANSITION_TYPE_NONE;
        D_i2_800D1228 = 0;
    }
    sTransitionPalettePtr = NULL;

    switch (transitionType) {
        case TRANSITION_TYPE_SMALL_TILES:
            backgroundBufferSize = 0;
            workBufferSize = SMALL_TILES_WORK_SIZE;
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0x80;
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0x700;
            transition->unk_0E = gGameFrameCount % 2;
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0x500;
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            backgroundBufferSize = 0;
            workBufferSize = 0;
            break;
        case TRANSITION_TYPE_WIPE_LEFT:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0;
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0x380;
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            if (appearType != TRANSITION_APPEAR) {
                if (D_i2_800D11F4 != 0) {
                    transition->queuedTransitionType = TRANSITION_TYPE_STATIC_FADE;
                    backgroundBufferSize = 0;
                    workBufferSize = 0;
                    break;
                }
            }
            backgroundBufferSize = TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16);
            workBufferSize = 0xC0;
            break;
        default:
            backgroundBufferSize = 0;
            workBufferSize = 0;
            break;
    }

    if (((transition->backgroundBuffer = Arena_Allocate(ALLOC_BACK, backgroundBufferSize)) == NULL) ||
        ((transition->workBuffer = Arena_Allocate(ALLOC_BACK, workBufferSize)) == NULL)) {
        transition->queuedTransitionType = TRANSITION_TYPE_FADE;
        return 1;
    }
    if (transition->queuedTransitionType == TRANSITION_TYPE_GREYSCALE_PALETTE) {
        sTransitionPalettePtr = sTransitionPalette;
    }
    return 0;
}

void func_i2_800A26C0(s32 transitionType, s32 arg1) {
    D_i2_800D122A = transitionType;
    D_i2_800D1228 = arg1;
}

const s32 kTransitionRandomSelection[] = { TRANSITION_TYPE_SMALL_TILES,  TRANSITION_TYPE_LARGE_TILES,
                                           TRANSITION_TYPE_TILED_WHIRL,  TRANSITION_TYPE_TILED_SPIRAL,
                                           TRANSITION_TYPE_FADE,         TRANSITION_TYPE_STATIC_FADE,
                                           TRANSITION_TYPE_PHASED_STRIPS };

s32 Transition_QueueRandom(s32 appearType, bool instantTransitionAllowed) {
    s32 temp;
    u32 temp2;
    s32 var_v0;

    if (appearType == TRANSITION_APPEAR) {
        temp = (Math_Rand1() % 8);
        if (instantTransitionAllowed) {
            if (temp < 2) {
                temp2 = Math_Rand1();
                var_v0 = Transition_Queue(appearType, kTransitionRandomSelection[temp2 % 7]);
            } else {
                var_v0 = Transition_Queue(appearType, TRANSITION_TYPE_INSTANT);
            }
        } else {
            temp2 = Math_Rand1();
            var_v0 = Transition_Queue(appearType, kTransitionRandomSelection[temp2 % 7]);
        }
    } else {
        temp2 = Math_Rand1();
        var_v0 = Transition_Queue(appearType, kTransitionRandomSelection[temp2 % 7]);
    }
    return var_v0;
}

s32 Transition_Update(void) {
    Transition* transition = &sTransition;

    if (transition->queuedTransitionType != TRANSITION_TYPE_NONE) {
        Transition_PopQueue(transition);
    }

    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_NONE:
            break;
        case TRANSITION_TYPE_SMALL_TILES:
            Transition_SmallTilesUpdate(transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            Transition_LargeTilesUpdate(transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            Transition_TiledWhirlUpdate(transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            Transition_TiledSpiralUpdate(transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            Transition_FadeUpdate(transition);
            break;
        case TRANSITION_TYPE_WIPE_LEFT:
            Transition_WipeLeftUpdate(transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            Transition_PhasedStripsUpdate(transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            Transition_GreyscalePaletteUpdate(transition);
            break;
        case TRANSITION_TYPE_INSTANT:
        default:
            break;
    }

    if (D_800BEE14 != 0 && transition->flags & TRANSITION_FLAG_FINISHED) {
        D_800BEE14 = 0;
    }

    return transition->flags & TRANSITION_FLAG_FINISHED;
}

void Transition_PopQueue(Transition* transition) {

    transition->activeTransitionType = transition->queuedTransitionType;
    transition->queuedTransitionType = TRANSITION_TYPE_NONE;
    transition->timer = 0;
    transition->flags = TRANSITION_FLAG_DRAW;

    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_INSTANT:
            transition->flags &= ~TRANSITION_FLAG_DRAW;
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_TYPE_SMALL_TILES:
            if (transition->appearType != TRANSITION_APPEAR) {
                transition->state = SMALL_TILES_START_HIDE;
            } else {
                transition->state = SMALL_TILES_START_APPEAR;
            }
            Transition_SmallTilesInit(transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_LargeTilesInit(transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_TiledWhirlInit(transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_TiledSpiralInit(transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            if (transition->appearType != TRANSITION_APPEAR) {
                transition->state = 3;
                Transition_FadeInit(transition, 255, 20);
            } else {
                transition->state = 1;
                Transition_FadeInit(transition, 0, 20);
            }
            break;
        case TRANSITION_TYPE_WIPE_LEFT:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_WipeLeftInit(transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_PhasedStripsInit(transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            if (transition->appearType == TRANSITION_APPEAR) {
                transition->flags |= TRANSITION_FLAG_FILL_BLACK;
            }
            transition->state = 1;
            Transition_GreyscalePaletteInit(transition);
            break;
    }

    if (transition->appearType == TRANSITION_APPEAR) {
        if (transition->flags & TRANSITION_FLAG_FILL_BLACK) {
            D_i2_800D11F4 = 1;
        } else {
            D_i2_800D11F4 = 0;
        }
    }
}

Gfx* Transition_Draw(Gfx* gfx) {
    Transition* transition = &sTransition;

    if (!(transition->flags & TRANSITION_FLAG_DRAW)) {
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);

    gfx = func_806F6360(gfx, 0);

    if (transition->flags & TRANSITION_FLAG_FILL_BLACK) {
        gSPDisplayList(gfx++, aSetupFillBlackDL);
        gDPFillRectangle(gfx++, TRANSITION_BORDER_WIDTH, TRANSITION_BORDER_HEIGHT,
                         SCREEN_WIDTH - TRANSITION_BORDER_WIDTH - 1, SCREEN_HEIGHT - TRANSITION_BORDER_HEIGHT - 1);
    }
    switch (transition->activeTransitionType) {
        case TRANSITION_TYPE_SMALL_TILES:
            gfx = Transition_SmallTilesDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_LARGE_TILES:
            gfx = Transition_LargeTilesDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_TILED_WHIRL:
            gfx = Transition_TiledDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_TILED_SPIRAL:
            gfx = Transition_TiledDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_FADE:
        case TRANSITION_TYPE_STATIC_FADE:
            gfx = Transition_FadeDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_WIPE_LEFT:
            gfx = Transition_WipeLeftDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_PHASED_STRIPS:
            gfx = Transition_PhasedStripsDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_GREYSCALE_PALETTE:
            gfx = Transition_GreyscalePaletteDraw(gfx, transition);
            break;
        case TRANSITION_TYPE_INSTANT:
            break;
    }
    if (transition->flags & TRANSITION_FLAG_FINISHED) {
        transition->activeTransitionType = TRANSITION_TYPE_NONE;
        transition->state = TRANSITION_STATE_INACTIVE;
        transition->flags &= ~TRANSITION_FLAG_DRAW;
        // Clear background arena
        Arena_EndInit();
    }
    return gfx;
}

extern FrameBuffer* gFrameBuffers[];
extern s16 D_8076C7A4;
extern s32 D_8079A360;
extern s32 D_8079A368;

void Transition_SetBackgroundBuffer(void) {
    s32 pad;
    s32 column;
    s32 row;
    s32 var_v0;
    u16* frameBufferPtr;
    u16* backgroundBufferPtr;
    Transition* transition = &sTransition;

    if (!(transition->flags & TRANSITION_FLAG_SET_BACKGROUND_BUFFER)) {
        return;
    }

    transition->flags &= ~TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    backgroundBufferPtr = transition->backgroundBuffer;
    if (D_8076C7A4 == 3) {
        var_v0 = D_8079A368;
    } else {
        var_v0 = D_8079A360;
    }

    osInvalDCache(gFrameBuffers[var_v0], SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16));

    for (row = 0; row < TRANSITION_BACKGROUND_HEIGHT; row++) {
        frameBufferPtr = &gFrameBuffers[var_v0]->array[row + TRANSITION_BORDER_HEIGHT][TRANSITION_BORDER_WIDTH];

        for (column = 0; column < TRANSITION_BACKGROUND_WIDTH; column++, backgroundBufferPtr++, frameBufferPtr++) {
            *backgroundBufferPtr = *frameBufferPtr;
        }
    }

    if (transition->flags & TRANSITION_FLAG_GREYSCALE) {
        func_80709DEC(transition->backgroundBuffer,
                      TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
    if (transition->flags & TRANSITION_FLAG_INVERSE_GREYSCALE) {
        func_8070E79C(transition->backgroundBuffer,
                      TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
    if (transition->flags & TRANSITION_FLAG_CONVERT_TO_PALETTE) {
        func_8070EB90(transition->backgroundBuffer, sTransitionPalettePtr,
                      TRANSITION_BACKGROUND_WIDTH * TRANSITION_BACKGROUND_HEIGHT * sizeof(u16));
    }
}

void Transition_SmallTilesInit(Transition* transition) {
    s32 i;
    u8* ptr = transition->workBuffer;
    s32 tileColumn;
    s32 tileRow;

    for (i = 0; i < SMALL_TILES_WORK_SIZE; i++) {
        *ptr++ = SMALL_TILES_TILE_UNSET;
    }

    for (i = 0; i < 5; i++) {
        tileColumn = Math_Rand1() % SMALL_TILES_COLUMNS;
        tileRow = Math_Rand1() % SMALL_TILES_ROWS;
        Transition_SmallTilesSetTileState(transition, (tileRow * SMALL_TILES_COLUMNS) + tileColumn,
                                          SMALL_TILES_TILE_SET);
    }
}

void Transition_SmallTilesUpdate(Transition* transition) {

    switch (transition->state) {
        case SMALL_TILES_START_APPEAR:
            if (Transition_SmallTilesUpdateState(transition)) {
                transition->state = SMALL_TILES_WAIT;
                transition->timer = 0;
            }
            break;
        case SMALL_TILES_WAIT:
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = SMALL_TILES_FINISHED;
            }
            break;
        case SMALL_TILES_START_HIDE:
            if (Transition_SmallTilesUpdateState(transition)) {
                transition->state = SMALL_TILES_FINISHED;
            }
            break;
        case SMALL_TILES_FINISHED:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_STATE_INACTIVE:
        default:
            break;
    }
}

bool Transition_SmallTilesUpdateState(Transition* transition) {
    s32 surroundingTilesUnset;
    bool transitionComplete;
    s32 tileIndexToSet;
    s8* tileStateBufferPtr;
    u32 surroundingTilesIndex;
    s32 i;
    s32 pad[6];
    bool surroundingTileUnset[8];

    for (i = 0; i < SMALL_TILES_COLUMNS * SMALL_TILES_ROWS; i++) {
        if (Transition_SmallTilesGetTileState(transition, i) == SMALL_TILES_TILE_SET) {
            surroundingTilesUnset = Transition_SmallTilesFindUnsetSurroundingTiles(transition, i, surroundingTileUnset);
            if (surroundingTilesUnset == 0) {
                Transition_SmallTilesSetTileState(transition, i, SMALL_TILES_TILE_FINISHED);
                continue;
            }

            if ((Math_Rand1() & sSurroundingTileSkipChanceMask[surroundingTilesUnset - 1])) {
                continue;
            }

            surroundingTilesIndex = Math_Rand1() % 8;

            while (!surroundingTileUnset[surroundingTilesIndex]) {
                surroundingTilesIndex++;
                surroundingTilesIndex %= 8;
            }

            tileIndexToSet = (sSurroundingTilesRelativeIndex[surroundingTilesIndex] % SMALL_TILES_WORK_SIZE) + i;
            if (tileIndexToSet < 0) {
                tileIndexToSet += SMALL_TILES_WORK_SIZE;
            }
            Transition_SmallTilesSetTileState(transition, tileIndexToSet, SMALL_TILES_TILE_SET);
        }
    }

    if (++transition->timer <= 60) {
        transitionComplete = true;

        for (i = 0, tileStateBufferPtr = transition->workBuffer; i < SMALL_TILES_WORK_SIZE; i++, tileStateBufferPtr++) {
            if (!(*tileStateBufferPtr & 0xF0) || !(*tileStateBufferPtr & 0xF)) {
                transitionComplete = false;
                break;
            }
        }

    } else {
        transitionComplete = true;
        // clang-format off
        for (i = 0, tileStateBufferPtr = transition->workBuffer; i < SMALL_TILES_WORK_SIZE; i++) { \
            *tileStateBufferPtr++ = (SMALL_TILES_TILE_FINISHED << 4) | SMALL_TILES_TILE_FINISHED;
        }
        // clang-format on
    }
    return transitionComplete;
}

s32 Transition_SmallTilesFindUnsetSurroundingTiles(Transition* transition, s32 tileIndex, bool* surroundingTileUnset) {
    s32 tileToCheck;
    s32 i;
    s32 unsetTilesFound = 0;

    for (i = 0; i < ARRAY_COUNT(sSurroundingTilesRelativeIndex); i++) {
        tileToCheck = (sSurroundingTilesRelativeIndex[i] % SMALL_TILES_WORK_SIZE) + tileIndex;
        if (tileToCheck < 0) {
            tileToCheck += SMALL_TILES_WORK_SIZE;
        }
        if (Transition_SmallTilesGetTileState(transition, tileToCheck) == 0) {
            unsetTilesFound++;
            surroundingTileUnset[i] = true;
        } else {
            surroundingTileUnset[i] = false;
        }
    }
    return unsetTilesFound;
}

s32 Transition_SmallTilesGetTileState(Transition* transition, s32 tileIndex) {
    s8* workByte = (s8*) transition->workBuffer + (tileIndex >> 1);
    s8 tileState;

    if (tileIndex & 1) {
        tileState = (*workByte & 0xF);
    } else {
        tileState = (*workByte >> 4);
    }
    return tileState;
}

void Transition_SmallTilesSetTileState(Transition* transition, s32 tileIndex, s8 tileState) {
    s8* workByte = (s8*) transition->workBuffer + (tileIndex >> 1);

    if (tileIndex & 1) {
        *workByte = (*workByte & 0xF0) | tileState;
    } else {
        *workByte = (*workByte & 0xF) | (tileState << 4);
    }
}

Gfx* Transition_SmallTilesDraw(Gfx* gfx, Transition* transition) {
    s32 tileTop;
    s32 groupedHiddenTileCount;
    s32 column;
    s32 tileIndex;
    s32 hiddenTileColumnStart;
    s32 row;
    s32 tileLeft;

    gSPDisplayList(gfx++, aSetupFillBlackDL);
    tileIndex = 0;

    for (row = 0; row < SMALL_TILES_ROWS; row++) {
        groupedHiddenTileCount = 0;
        for (column = 0; column < SMALL_TILES_COLUMNS; column++, tileIndex++) {
            if (transition->appearType != TRANSITION_APPEAR) {
                if (Transition_SmallTilesGetTileState(transition, tileIndex) != SMALL_TILES_TILE_UNSET) {
                    tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
                    tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
                    if (groupedHiddenTileCount == 0) {
                        continue;
                    }
                } else {
                    if (groupedHiddenTileCount == 0) {
                        hiddenTileColumnStart = column;
                    }
                    groupedHiddenTileCount++;
                    continue;
                }
            } else {
                if (Transition_SmallTilesGetTileState(transition, tileIndex) == SMALL_TILES_TILE_UNSET) {
                    tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
                    tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
                    if (groupedHiddenTileCount == 0) {
                        continue;
                    }
                } else {
                    if (groupedHiddenTileCount == 0) {
                        hiddenTileColumnStart = column;
                    }
                    groupedHiddenTileCount++;
                    continue;
                }
            }

            gDPFillRectangle(gfx++, tileLeft + TRANSITION_BORDER_WIDTH, tileTop,
                             ((groupedHiddenTileCount * SMALL_TILES_WIDTH) + tileLeft + TRANSITION_BORDER_WIDTH - 1),
                             (tileTop + SMALL_TILES_HEIGHT - 1));
            groupedHiddenTileCount = 0;
        }

        tileLeft = hiddenTileColumnStart * SMALL_TILES_WIDTH;
        tileTop = (row * SMALL_TILES_HEIGHT) + TRANSITION_BORDER_HEIGHT;
        if (groupedHiddenTileCount != 0) {
            gDPFillRectangle(gfx++, tileLeft + TRANSITION_BORDER_WIDTH, tileTop,
                             ((groupedHiddenTileCount * SMALL_TILES_WIDTH) + tileLeft + TRANSITION_BORDER_WIDTH - 1),
                             (tileTop + SMALL_TILES_HEIGHT - 1));
            groupedHiddenTileCount = 0;
        }
    }
    return gfx;
}

void Transition_LargeTilesInit(Transition* transition) {
    s32 i;
    u8* var_v1;

    transition->unk_1C.unk_00 = 0x40;
    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    for (i = 0, var_v1 = transition->workBuffer; i < 0x40; i++) {
        *var_v1++ = 0;
        *var_v1++ = -1;
    }
}

void Transition_LargeTilesUpdate(Transition* transition) {
    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            if (func_i2_800A3620(transition)) {
                transition->state = 2;
            }
            break;
        case 2:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool func_i2_800A3620(Transition* transition) {
    bool ret;
    s32 i;
    s32 var_v0;
    s32 var_v1;
    unk_8010D778_unk_1C* var_a2;
    unk_8010D778_unk_18* var_a1;

    var_a1 = transition->workBuffer;
    var_a2 = &transition->unk_1C;
    transition->timer++;
    if (transition->timer > 0) {
        transition->timer = 0;
        for (i = 0; i < 2; i++) {
            if (var_a2->unk_00 > 0) {
                var_v1 = Math_Rand1() % 64;
                while ((var_a1 + var_v1)->unk_00) {
                    var_v1++;
                    var_v1 %= 64;
                }

                (var_a1 + var_v1)->unk_00 = 1;
                var_a2->unk_00--;
            }
        }
    }

    var_a1 = transition->workBuffer;
    ret = true;

    for (i = 0; i < 64; i++, var_a1++) {
        if (var_a1->unk_00 != 2) {
            ret = false;
        }
        if (var_a1->unk_00 == 1) {
            var_v0 = var_a1->unk_01 - 8;
            if (var_v0 < 0) {
                var_a1->unk_00 = 2;
                var_v0 = 0;
            }
            var_a1->unk_01 = var_v0;
        }
    }

    return ret;
}

Gfx* Transition_LargeTilesDraw(Gfx* gfx, Transition* transition) {
    s32 i;
    s32 j;
    unk_8010D778_unk_18* temp_t1;

    gSPDisplayList(gfx++, D_80147B0);

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            temp_t1 = (unk_8010D778_unk_18*) transition->workBuffer + (i * 8 + j);
            if (temp_t1->unk_00 == 2) {
                continue;
            }
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, temp_t1->unk_01);

            gDPLoadTextureTile(gfx++, transition->backgroundBuffer, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                               TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, (j * 37), (i * 28),
                               (j * 37) + 36, (i * 28) + 27, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPTextureRectangle(gfx++, ((j * 37) + 12) << 2, ((i * 28) + 8) << 2, ((j * 37) + 49) << 2,
                                ((i * 28) + 36) << 2, 0, (j * 37) << 5, (i * 28) << 5, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

extern GfxPool D_8024E260[2];

void Transition_TiledWhirlInit(Transition* transition) {
    s32 pad[11];
    f32 sp104[4];
    f32 spF4[4];
    f32 spE4[4];
    f32 spD4[4];
    s32 pad2[5];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    Vtx* vtx;
    s32 temp_ft0;
    s32 temp_ft3;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a1;
    unk_8010D778_unk_18_2* temp_v0_2;

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    transition->unk_1C.unk_00 = -1;

    for (i = 0; i < 2; i++) {
        vtx = D_8024E260[i].unk_34248;
        sp104[0] = sp104[2] = -33.3f;
        sp104[1] = sp104[3] = sp104[0] + 66.6f + 1.0f;
        spF4[0] = spF4[1] = 25.199999f;
        spF4[2] = spF4[3] = spF4[0] - 50.399998f;

        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                for (m = 0; m < 4; m++) {
                    if (m & 1) {
                        spE4[m] = (k + 1) * 37;
                    } else {
                        spE4[m] = k * 37;
                    }
                    if (m >= 2) {
                        spD4[m] = (j + 1) * 28;
                    } else {
                        spD4[m] = j * 28;
                    }
                    temp_s4 = Math_Round(sp104[m]);
                    temp_v0 = Math_Round(spF4[m]);
                    temp_ft0 = spE4[m] * 32.0f;
                    temp_ft3 = spD4[m] * 32.0f;
                    SET_VTX(vtx, temp_s4, temp_v0, 0, temp_ft0, temp_ft3, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            temp_v0_2 = (unk_8010D778_unk_18_2*) transition->workBuffer + (j + i * 8);
            temp_v0_2->unk_00 = 0;
            temp_v0_2->unk_04 = (j * 66.6f) + -233.09999f;
            temp_v0_2->unk_08 = 176.4f - (i * 50.399998f);
            temp_v0_2->unk_0C = 0.0f;
            temp_v0_2->unk_10 = 0.0f;
            temp_v0_2->unk_14 = 0.0f;
            temp_v0_2->unk_18 = 0.0f;
        }
    }
}

extern GfxPool* gGfxPool;

void Transition_TiledWhirlUpdate(Transition* transition) {
    s32 i;
    s32 temp_v0;
    s32 var_s0;
    unk_8010D778_unk_18_2* var_s0_2;
    MtxF sp70;

    var_s0 = 0;

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            var_s0 = 1;
            if (func_i2_800A4078(transition) != 0) {
                transition->state = 2;
                transition->timer = 0;
            }
            break;
        case 2:
            var_s0 = 1;
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = 3;
                transition->timer = 0;
            }
            break;
        case 3:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
    if (var_s0 != 0) {
        func_806F9384(gGfxPool->unk_35248, &sp70, 60.0f, 16.0f, 8129.0f, 320.0f, 0.0f, 240.0f, 0.0f, &D_i2_800D11F2);
        func_806F8FE0(gGfxPool->unk_35288, &sp70, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        var_s0_2 = transition->workBuffer;
        for (i = 0; i < 64; i++) {
            func_806F7FCC(&gGfxPool->unk_352C8[i], &sp70, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
                          var_s0_2->unk_04, var_s0_2->unk_08, var_s0_2->unk_0C);
            var_s0_2++;
        }
    }
}

bool func_i2_800A4078(Transition* transition) {
    bool var_a0;
    s32 j;
    s32 i;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_4;
    unk_8010D778_unk_1C* temp_v0;
    unk_8010D778_unk_18_2* var_a3;

    temp_v0 = &transition->unk_1C;
    transition->timer++;
    if (transition->timer >= 2) {
        transition->timer = 0;
        var_v1 = 0;

        if (temp_v0->unk_00 < 0xF) {
            temp_v0->unk_00++;
        }

        if (transition->unk_0E != 0) {
            for (i = temp_v0->unk_00; i >= 0; i--, var_v1++) {
                if (i >= 8) {
                    continue;
                }

                for (j = 0; j < var_v1 + 1; j++) {
                    var_v1_2 = 7 - j;
                    if (var_v1_2 >= 0) {
                        var_a3 = (unk_8010D778_unk_18_2*) transition->workBuffer + ((var_v1_2 * 8) + i);
                        if (var_a3->unk_00 == 0) {
                            var_a3->unk_00 = 1;
                        }
                    }
                }
            }
        } else {
            var_v1_4 = 0;
            for (i = 7 - temp_v0->unk_00; i < 8; i++, var_v1_4++) {
                if (i < 0) {
                    continue;
                }

                for (j = 0; j < var_v1_4 + 1; j++) {
                    if (j < 8) {
                        var_a3 = (unk_8010D778_unk_18_2*) transition->workBuffer + ((j * 8) + i);
                        if (var_a3->unk_00 == 0) {
                            var_a3->unk_00 = 1;
                        }
                    }
                }
            }
        }
    }

    for (i = 0, var_a3 = transition->workBuffer; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 == 1) {
            var_a3->unk_10 += 0.0f;
            var_a3->unk_14 += 0.0f;
            var_a3->unk_18 += -60.0f;
            var_a3->unk_04 += var_a3->unk_10;
            var_a3->unk_08 += var_a3->unk_14;
            var_a3->unk_0C += var_a3->unk_18;
            if (var_a3->unk_0C < -10000.0f) {
                var_a3->unk_00 = 2;
                var_a3->unk_0C = -10000.0f;
            }
        }
    }

    var_a0 = true;
    for (i = 0, var_a3 = transition->workBuffer; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 != 2) {
            var_a0 = false;
        }
    }
    return var_a0;
}

extern GfxPool D_1000000;

Gfx* Transition_TiledDraw(Gfx* gfx, Transition* transition) {
    s32 pad[2];
    s32 i;
    s32 j;
    f32 var_fv0;
    unk_8010D778_unk_18_2* spA8;
    s32 var_t3;

    gSPDisplayList(gfx++, D_8014810);

    if (transition->activeTransitionType == TRANSITION_TYPE_TILED_WHIRL) {
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE);
        spA8 = transition->workBuffer;
    }
    gSPPerspNormalize(gfx++, D_i2_800D11F2);
    gSPMatrix(gfx++, D_1000000.unk_35248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_1000000.unk_35288, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            var_t3 = (i * 8) + j;
            if (transition->activeTransitionType == TRANSITION_TYPE_TILED_WHIRL) {
                var_fv0 = 1.0f - (spA8 + var_t3)->unk_0C / -10000.0f;
                if (var_fv0 < 0.0f) {
                    var_fv0 = 0.0f;
                }
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, (s32) (255.0f * var_fv0));
            }

            gSPMatrix(gfx++, &D_1000000.unk_352C8[var_t3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(gfx++, &D_1000000.unk_34248[var_t3 * 4], 4, 0);

            gDPLoadTextureTile(gfx++, transition->backgroundBuffer, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                               TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, (j * 37), (i * 28),
                               (j * 37) + 36, (i * 28) + 27, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
        }
    }
    return gfx;
}

void Transition_TiledSpiralInit(Transition* transition) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    Vtx* vtx;
    s32 temp_ft0;
    s32 temp_ft3;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_a1;
    unk_8010D778_unk_18_3* temp_v0_2;
    f32 spC4[4];
    f32 spB4[4];
    f32 spA4[4];
    f32 sp94[4];

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    transition->unk_1C.unk_00 = 0x40;
    transition->unk_1C.unk_04 = -1;
    transition->unk_1C.unk_08 = 0;
    transition->unk_1C.unk_0C = 0;

    for (i = 0; i < 2; i++) {
        vtx = D_8024E260[i].unk_34248;
        spC4[0] = spC4[2] = -33.3f;
        spC4[1] = spC4[3] = spC4[0] + 66.6f + 1;
        spB4[0] = spB4[1] = 25.199999f;
        spB4[2] = spB4[3] = spB4[0] - 50.399998f;

        for (j = 0; j < 8; j++) {
            for (k = 0; k < 8; k++) {
                for (m = 0; m < 4; m++) {
                    temp_s4 = Math_Round(spC4[m]);
                    temp_v0 = Math_Round(spB4[m]);
                    if (m & 1) {
                        spA4[m] = (k + 1) * 37;
                    } else {
                        spA4[m] = k * 37;
                    }
                    if (m >= 2) {
                        sp94[m] = (j + 1) * 28;
                    } else {
                        sp94[m] = j * 28;
                    }
                    temp_ft0 = spA4[m] * 32.0f;
                    temp_ft3 = sp94[m] * 32.0f;
                    SET_VTX(vtx, temp_s4, temp_v0, 0, temp_ft0, temp_ft3, 0, 0, 0, 0);
                    vtx++;
                }
            }
        }
    }

    for (j = 0; j < 8; j++) {
        for (k = 0; k < 8; k++) {
            temp_v0_2 = (unk_8010D778_unk_18_3*) transition->workBuffer + (k + j * 8);
            temp_v0_2->unk_00 = 0;
            temp_v0_2->unk_04 = (k * 66.6f) + -233.09999f;
            temp_v0_2->unk_08 = 176.4f - (j * 50.399998f);
            temp_v0_2->unk_0C = 0.0f;
            temp_v0_2->unk_10 = 1.0f;
            temp_v0_2->unk_01 = 0;
        }
    }
}

void Transition_TiledSpiralUpdate(Transition* transition) {
    s32 i;
    bool var_s0;
    unk_8010D778_unk_18_3* var_s0_2;
    MtxF sp74;

    var_s0 = false;
    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            var_s0 = true;
            if (func_i2_800A4E1C(transition)) {
                transition->state = 2;
                transition->timer = 0;
            }
            break;
        case 2:
            var_s0 = true;
            transition->timer++;
            if (transition->timer >= 3) {
                transition->state = 3;
                transition->timer = 0;
            }
            break;
        case 3:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }

    if (var_s0) {
        func_806F9384(gGfxPool->unk_35248, &sp74, 60.0f, 16.0f, 8129.0f, 320.0f, 0.0f, 240.0f, 0.0f, &D_i2_800D11F2);
        func_806F8FE0(gGfxPool->unk_35288, &sp74, 0.0f, 0.0f, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        var_s0_2 = transition->workBuffer;
        for (i = 0; i < 64; i++) {
            func_806F7FCC(&gGfxPool->unk_352C8[i], &sp74, var_s0_2->unk_10, var_s0_2->unk_10, var_s0_2->unk_10, 0.0f,
                          0.0f, 1.0f, 0.0f, 1.0f, 0.0f, var_s0_2->unk_04, var_s0_2->unk_08, var_s0_2->unk_0C);
            var_s0_2++;
        }
    }
}

bool func_i2_800A4E1C(Transition* transition) {
    bool var_a0;
    s32 i;
    s32 j;
    unk_8010D778_unk_1C* temp_v0;
    unk_8010D778_unk_18_3* var_a3;

    temp_v0 = &transition->unk_1C;

    for (i = 0; i < 2; i++) {
        if (temp_v0->unk_00 <= 0) {
            continue;
        }

        temp_v0->unk_00--;

        switch (temp_v0->unk_0C) {
            case 0:
                temp_v0->unk_04++;
                var_a3 = (unk_8010D778_unk_18_3*) transition->workBuffer + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_04 >= 8 || var_a3->unk_00 != 0) {
                    temp_v0->unk_04--;
                    temp_v0->unk_08++;
                    temp_v0->unk_0C = 1;
                }
                break;
            case 1:
                temp_v0->unk_08++;
                var_a3 = (unk_8010D778_unk_18_3*) transition->workBuffer + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_08 >= 8 || var_a3->unk_00 != 0) {
                    temp_v0->unk_08--;
                    temp_v0->unk_04--;
                    temp_v0->unk_0C = 2;
                }
                break;
            case 2:
                temp_v0->unk_04--;
                var_a3 = (unk_8010D778_unk_18_3*) transition->workBuffer + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_04 < 0 || var_a3->unk_00 != 0) {
                    temp_v0->unk_04++;
                    temp_v0->unk_08--;
                    temp_v0->unk_0C = 3;
                }
                break;
            case 3:
                temp_v0->unk_08--;
                var_a3 = (unk_8010D778_unk_18_3*) transition->workBuffer + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
                if (temp_v0->unk_08 < 0 || var_a3->unk_00 != 0) {
                    temp_v0->unk_08++;
                    temp_v0->unk_04++;
                    temp_v0->unk_0C = 0;
                }
                break;
            default:
                break;
        }
        var_a3 = (unk_8010D778_unk_18_3*) transition->workBuffer + (temp_v0->unk_08 * 8 + temp_v0->unk_04);
        var_a3->unk_00 = 1;
    }

    for (i = 0, var_a3 = transition->workBuffer; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 == 1) {
            if (var_a3->unk_01 < 11) {
                var_a3->unk_10 = (10 - var_a3->unk_01) / 10.0f;
                var_a3->unk_01++;

            } else {
                var_a3->unk_00 = 2;
                var_a3->unk_10 = 0.0f;
            }
        }
    }

    var_a0 = true;
    for (i = 0, var_a3 = transition->workBuffer; i < 64; i++, var_a3++) {
        if (var_a3->unk_00 != 2) {
            var_a0 = false;
        }
    }
    return var_a0;
}

void Transition_FadeInit(Transition* transition, s32 arg1, s32 arg2) {

    transition->unk_1C.unk_00 = transition->unk_1C.unk_04 = transition->unk_1C.unk_08 = 0;
    transition->unk_1C.unk_0C = arg1;

    if (transition->unk_0E != 0) {
        transition->unk_1C.unk_10 = transition->unk_0E;
    } else {
        transition->unk_1C.unk_10 = arg2;
    }
}

void Transition_FadeUpdate(Transition* transition) {
    unk_8010D778_unk_1C* temp_v0;

    temp_v0 = &transition->unk_1C;

    switch (transition->state) {
        case 1:
            temp_v0->unk_0C = (transition->timer * 255.0f) / temp_v0->unk_10;
            transition->timer++;
            if (temp_v0->unk_10 < transition->timer) {
                transition->state = 2;
                transition->timer = 0;
                temp_v0->unk_0C = 255;
            }
            break;
        case 2:
            transition->timer++;
            if (transition->timer >= 2) {
                transition->state = 4;
            }
            break;
        case 3:
            temp_v0->unk_0C = ((temp_v0->unk_10 - transition->timer) * 255.0f) / temp_v0->unk_10;
            transition->timer++;

            if (temp_v0->unk_10 < transition->timer) {
                transition->state = 4;
                transition->timer = 0;
                temp_v0->unk_0C = 0;
            }
            break;
        case 4:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
        case TRANSITION_STATE_INACTIVE:
        default:
            break;
    }
}

Gfx* Transition_FadeDraw(Gfx* gfx, Transition* transition) {
    unk_8010D778_unk_1C* temp_v1 = &transition->unk_1C;

    gSPDisplayList(gfx++, D_8014888);

    if (transition->activeTransitionType == TRANSITION_TYPE_STATIC_FADE) {
        gDPSetAlphaCompare(gfx++, G_AC_DITHER);
    }

    gDPSetPrimColor(gfx++, 0, 0, temp_v1->unk_00, temp_v1->unk_04, temp_v1->unk_08, temp_v1->unk_0C);

    gDPFillRectangle(gfx++, 12, 8, 308, 232);

    return gfx;
}

void Transition_WipeLeftInit(Transition* transition) {

    transition->unk_1C.unk_00 = 0xC;
    transition->unk_1C.unk_04 = 8;
    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    switch (transition->unk_0E) {
        case 0:
        case 1:
            D_800D11F0 = transition->unk_1C.unk_00;
            break;
        case 2:
        case 3:
            D_800D11F0 = transition->unk_1C.unk_04;
            break;
    }
}

void Transition_WipeLeftUpdate(Transition* transition) {
    unk_8010D778_unk_1C* temp_v0 = &transition->unk_1C;

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            switch (transition->unk_0E) {
                case 0:
                    temp_v0->unk_00 = 12 - (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_WIDTH) / 20.0f);
                    D_800D11F0 = temp_v0->unk_00;
                    break;
                case 1:
                    temp_v0->unk_00 = (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_WIDTH) / 20.0f) + 12;
                    D_800D11F0 = temp_v0->unk_00;
                    break;
                case 2:
                    temp_v0->unk_04 = 8 - (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_HEIGHT) / 20.0f);
                    D_800D11F0 = temp_v0->unk_04;
                    break;
                case 3:
                    temp_v0->unk_04 = (s32) ((transition->timer * (f32) TRANSITION_BACKGROUND_HEIGHT) / 20.0f) + 8;
                    D_800D11F0 = temp_v0->unk_04;
                    break;
            }

            transition->timer++;
            if (transition->timer >= 0x15) {
                transition->state = 2;
                transition->timer = 0;
                transition->unk_1C.unk_00 = 0x134;
            }
            break;
        case 2:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

Gfx* Transition_WipeLeftDraw(Gfx* gfx, Transition* transition) {

    gDPSetTextureLUT(gfx++, G_TT_NONE);

    return func_8070A99C(gfx, transition->backgroundBuffer, transition->unk_1C.unk_00, transition->unk_1C.unk_04,
                         TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                         0, 0);
}

void Transition_PhasedStripsInit(Transition* transition) {
    s32 i;
    f32* var_v1;

    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;

    for (i = 0, var_v1 = transition->workBuffer; i < TRANSITION_BACKGROUND_HEIGHT; i++, var_v1++) {
        *var_v1 = 12.0f;
    }
}

void Transition_PhasedStripsUpdate(Transition* transition) {

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            if (func_i2_800A56D4(transition)) {
                transition->state = 2;
                transition->timer = 0;
            }
            break;
        case 2:
            transition->timer++;
            if (transition->timer >= 2) {
                transition->state = 3;
                transition->timer = 0;
            }
            break;
        case 3:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool func_i2_800A56D4(Transition* transition) {
    f32 var_fv0;
    s32 var_a2;
    s32 var_a3;
    s32 i;
    bool var_v1;
    f32* var_a1;
    s32 var = TRANSITION_BACKGROUND_HEIGHT / 2;

    var_v1 = true;

    for (i = 0, var_a1 = transition->workBuffer; i < TRANSITION_BACKGROUND_HEIGHT; i++, var_a1++) {
        var_a2 = var - i;

        if (var_a2 < 0) {
            var_a2 = -var_a2;
        }

        var_a2 = var - var_a2;
        var_a3 = (transition->timer * D_i2_800BEE30) - var_a2;

        if (var_a3 < 0) {
            var_a3 = 0;
        }
        var_fv0 = var_a3 * 0.5f;

        if (i & 1) {
            var_fv0 = 0.0f - var_fv0;
        }
        *var_a1 += var_fv0;
        if ((*var_a1 >= 12.0f) && (*var_a1 < 308.0f)) {
            var_v1 = false;
        }
    }
    transition->timer++;

    return var_v1;
}

#ifdef NON_EQUIVALENT
Gfx* Transition_PhasedStripsDraw(Gfx* gfx, Transition* transition) {
    f32* var_t3;
    u16* var_s5;
    s32 i;
    s32 j;
    s32 sp30[2];
    s32 width = TRANSITION_BACKGROUND_WIDTH;
    s32 tileHeight = 4;
    s32 var;
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;
    s32 var_t5;

    gSPDisplayList(gfx++, D_8014940);

    sp30[1] = 0x38;
    sp30[0] = 0;

    var_t5 = 4;
    var_s5 = transition->backgroundBuffer;
    var_t3 = transition->workBuffer;

    for (i = 0; i < sp30[1]; i++) {
        gDPPipeSync(gfx++);
        gDPLoadTextureTile(gfx++, var_s5 + i * 0x4A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, TRANSITION_BACKGROUND_WIDTH, 4, 0, 0,
                           TRANSITION_BACKGROUND_WIDTH - 1, 4 - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (j = 0; j < var_t5; j++) {
            if ((*var_t3 < -284.0f) || (*var_t3 > 308.0f)) {
                var_t3++;
                continue;
            }

            var = (i * 4) + j;
            xl = *var_t3 * 4.0f;
            xh = (*var_t3 + width) * 4.0f;

            var_t3++;

            gSPScisTextureRectangle(gfx++, xl, (var + 8) << 2, xh, (var + 9) << 2, 0, 0, j << 5, 1 << 10, 1 << 10);
        }
    }

    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/transition/Transition_PhasedStripsDraw.s")
#endif

void Transition_GreyscalePaletteInit(Transition* transition) {
    transition->flags |= TRANSITION_FLAG_SET_BACKGROUND_BUFFER;
    transition->flags |= TRANSITION_FLAG_GREYSCALE;
    transition->flags |= TRANSITION_FLAG_CONVERT_TO_PALETTE;
    transition->unk_1C.unk_00 = -8;
}

void Transition_GreyscalePaletteUpdate(Transition* transition) {

    switch (transition->state) {
        case TRANSITION_STATE_INACTIVE:
            break;
        case 1:
            if (func_i2_800A5C70(transition)) {
                transition->state = 2;
                transition->timer = 0;
            }
            break;
        case 2:
            transition->timer++;
            if (transition->timer >= 4) {
                transition->state = 3;
                transition->timer = 0;
            }
            break;
        case 3:
            transition->flags |= TRANSITION_FLAG_FINISHED;
            break;
    }
}

bool func_i2_800A5C70(Transition* transition) {
    bool var_v1 = false;

    if (transition->unk_1C.unk_00 >= 0) {
        sTransitionPalette[transition->unk_1C.unk_00] = 0;
    }
    transition->timer++;
    if (transition->timer >= 2) {
        transition->timer = 0;
        transition->unk_1C.unk_00++;
        if (transition->unk_1C.unk_00 > 31) {
            transition->unk_1C.unk_00 = 31;
            var_v1 = true;
        }
    }
    return var_v1;
}

Gfx* Transition_GreyscalePaletteDraw(Gfx* gfx, Transition* transition) {
    return func_8070DEE0(gfx, transition->backgroundBuffer, sTransitionPalettePtr, G_IM_FMT_CI, 1, 12, 8,
                         TRANSITION_BACKGROUND_WIDTH, TRANSITION_BACKGROUND_HEIGHT, 5);
}
