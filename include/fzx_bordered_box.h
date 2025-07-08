#ifndef FZX_BORDERED_BOX_H
#define FZX_BORDERED_BOX_H

#include "libultra/ultra64.h"

typedef Gfx* (*BorderedBoxContentsDrawFunc)(Gfx*, s32, s32);

typedef struct BorderedBoxWidget {
    s32 state;
    s16 id;
    s16 timer;
    s16 left;
    s16 top;
    s16 maxLeft;
    s16 maxTop;
    s16 width;
    s16 height;
    s16 maxWidth;
    s16 maxHeight;
    u16 boxColor;
    u16 borderColor;
    u16 depth;
    BorderedBoxContentsDrawFunc contentsDrawFunc;
} BorderedBoxWidget; // size = 0x20

typedef enum BorderedBoxState {
    /* 0 */ BORDERED_BOX_CLOSED,
    /* 1 */ BORDERED_BOX_OPEN_WIDTH,
    /* 2 */ BORDERED_BOX_OPEN_HEIGHT,
    /* 3 */ BORDERED_BOX_OPENED,
    /* 4 */ BORDERED_BOX_CLOSE_HEIGHT,
    /* 5 */ BORDERED_BOX_CLOSE_WIDTH,
} BorderedBoxState;

typedef enum BorderedBoxInfoRequest {
    /* 0 */ IS_BORDERED_BOX_ACTIVE,
    /* 1 */ IS_BORDERED_BOX_OPENED,
} BorderedBoxInfoRequest;

void BorderedBox_CleanWidget(BorderedBoxWidget** boxPtr);
void BorderedBox_ClearAll(void);
BorderedBoxWidget* BorderedBox_Init(s16 id, s16 left, s16 top, s16 width, s16 height, u16 depth, u16 borderColor, BorderedBoxContentsDrawFunc contentsDrawFunc);
void BorderedBox_StartClose(BorderedBoxWidget* box);
void BorderedBox_Update(void);
Gfx* BorderedBox_Draw(Gfx* gfx);
bool BorderedBox_GetInfo(BorderedBoxWidget* box, s32 infoCondition);

#endif // FZX_BORDERED_BOX_H
