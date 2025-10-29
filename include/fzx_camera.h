#ifndef FZX_CAMERA_H
#define FZX_CAMERA_H

#include "fzx_math.h"
#include "unk_structs.h"

typedef struct ScissorBox {
    u32 left;
    u32 top;
    u32 right;
    u32 bottom;
} ScissorBox;

extern ScissorBox gScissorBoxFullScreen;
extern ScissorBox gScissorBoxTopHalf;
extern ScissorBox gScissorBoxBottomHalf;
extern ScissorBox gScissorBoxLeftHalf;
extern ScissorBox gScissorBoxRightHalf;
extern ScissorBox gScissorBoxTopLeftQuarter;
extern ScissorBox gScissorBoxTopRightQuarter;
extern ScissorBox gScissorBoxBottomLeftQuarter;
extern ScissorBox gScissorBoxBottomRightQuarter;
extern ScissorBox gScissorBoxTopCenterQuarter;
extern ScissorBox gScissorBoxBottomCenterQuarter;
extern ScissorBox gScissorBoxLeftCenterQuarter;
extern ScissorBox gScissorBoxRightCenterQuarter;

typedef enum ScissorBoxType {
    /*  0 */ SCISSOR_BOX_FULL_SCREEN,
    /*  1 */ SCISSOR_BOX_TOP_HALF,
    /*  2 */ SCISSOR_BOX_BOTTOM_HALF,
    /*  3 */ SCISSOR_BOX_LEFT_HALF,
    /*  4 */ SCISSOR_BOX_RIGHT_HALF,
    /*  5 */ SCISSOR_BOX_TOP_LEFT_QUARTER,
    /*  6 */ SCISSOR_BOX_TOP_RIGHT_QUARTER,
    /*  7 */ SCISSOR_BOX_BOTTOM_LEFT_QUARTER,
    /*  8 */ SCISSOR_BOX_BOTTOM_RIGHT_QUARTER,
    /*  9 */ SCISSOR_BOX_TOP_CENTER_QUARTER,
    /* 10 */ SCISSOR_BOX_BOTTOM_CENTER_QUARTER,
    /* 11 */ SCISSOR_BOX_LEFT_CENTER_QUARTER,
    /* 12 */ SCISSOR_BOX_RIGHT_CENTER_QUARTER,
} ScissorBoxType;

typedef enum CameraMode {
    /*  0 */ CAMERA_MODE_TITLE,
    /*  1 */ CAMERA_MODE_MACHINE_SELECT_CREATE,
    /*  2 */ CAMERA_MODE_MACHINE_SETTINGS,
    /*  3 */ CAMERA_MODE_COURSE_SELECT,
    /*  4 */ CAMERA_MODE_4,
    /*  5 */ CAMERA_MODE_5,
    /*  6 */ CAMERA_MODE_6,
    /*  7 */ CAMERA_MODE_FALLING_OFF_TRACK,
    /*  8 */ CAMERA_MODE_8,
    /*  9 */ CAMERA_MODE_9,
    /* 10 */ CAMERA_MODE_10,
    /* 11 */ CAMERA_MODE_11,
    /* 12 */ CAMERA_MODE_12,
    /* 13 */ CAMERA_MODE_13,
    /* 14 */ CAMERA_MODE_14,
    /* 15 */ CAMERA_MODE_15,
    /* 16 */ CAMERA_MODE_16,
} CameraMode;

#endif // FZX_CAMERA_H
