#ifndef FZX_CAMERA_H
#define FZX_CAMERA_H

#include "fzx_math.h"
#include "unk_structs.h"

typedef struct ScissorBox {
    /* 0x0 */ u32 left;
    /* 0x4 */ u32 top;
    /* 0x8 */ u32 right;
    /* 0xC */ u32 bottom;
} ScissorBox; // size = 0x10

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
    /*  4 */ CAMERA_MODE_RACE_INTRO,
    /*  5 */ CAMERA_MODE_5,
    /*  6 */ CAMERA_MODE_6,
    /*  7 */ CAMERA_MODE_FALLING_OFF_TRACK,
    /*  8 */ CAMERA_MODE_FINISHED_SUCCESS,
    /*  9 */ CAMERA_MODE_FINISHED_SPECTATE,
    /* 10 */ CAMERA_MODE_FINISHED_LOSER,
    /* 11 */ CAMERA_MODE_11,
    /* 12 */ CAMERA_MODE_12,
    /* 13 */ CAMERA_MODE_13,
    /* 14 */ CAMERA_MODE_ENDING,
    /* 15 */ CAMERA_MODE_TITLE_DEMO,
    /* 16 */ CAMERA_MODE_16,
} CameraMode;

typedef struct unk_80776A48 {
    /* 0x0 */ f32 fov;
    /* 0x4 */ f32 distance;
    /* 0x8 */ f32 pitch;
} unk_80776A48; // size = 0xC

typedef struct unk_struct_20 {
    /* 0x00 */ Vec3f targetAt;
    /* 0x0C */ Vec3f targetEye;
    /* 0x18 */ f32 atLerpFactor;
    /* 0x1C */ f32 eyeLerpFactor;
} unk_struct_20; // size = 0x20

typedef struct unk_struct_54 {
    /* 0x00 */ Vec3f anchorPos; // type 2 anchor around at, type 3 anchor around eye
    /* 0x0C */ Mtx3F basis;
    /* 0x30 */ f32 distance;
    /* 0x34 */ f32 targetDistance;
    /* 0x38 */ f32 distanceLerpFactor;
    /* 0x3C */ f32 pitch;
    /* 0x40 */ f32 targetPitch;
    /* 0x44 */ f32 pitchLerpFactor;
    /* 0x48 */ f32 yaw;
    /* 0x4C */ f32 targetYaw;
    /* 0x50 */ f32 yawLerpFactor;
} unk_struct_54; // size = 0x54

typedef struct unk_struct_68 {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ Mtx3F unk_0C;
    /* 0x30 */ Vec3f unk_30;
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f unk_54;
    /* 0x60 */ f32 unk_60;
    /* 0x64 */ f32 unk_64;
} unk_struct_68; // size = 0x68

typedef struct unk_struct_9C {
    /* 0x00 */ Mtx3F racerBasis;
    /* 0x24 */ Mtx3F basis;
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f anchorPoint;
    /* 0x60 */ Vec3f tiltUp;
    /* 0x6C */ f32 distance;
    /* 0x70 */ f32 targetDistance;
    /* 0x74 */ f32 distanceLerpFactor;
    /* 0x78 */ f32 pitch;
    /* 0x7C */ f32 targetPitch;
    /* 0x80 */ f32 pitchLerpFactor;
    /* 0x84 */ f32 yaw;
    /* 0x88 */ f32 targetYaw;
    /* 0x8C */ f32 yawLerpFactor;
    /* 0x90 */ f32 speed;
    /* 0x94 */ f32 unk_94;
    /* 0x98 */ s32 trackSegmentInfo;
} unk_struct_9C; // size = 0x9C

typedef struct unk_struct_58 {
    /* 0x00 */ Vec3f at;
    /* 0x0C */ Vec3f eye;
    /* 0x18 */ Vec3f up;
    /* 0x24 */ Vec3f targetUp;
    /* 0x30 */ f32 upLerpFactor;
    /* 0x34 */ f32 fov;
    /* 0x38 */ f32 targetFov;
    /* 0x3C */ f32 fovLerpFactor;
    /* 0x40 */ f32 frustrumCenterX;
    /* 0x44 */ f32 frustrumCenterY;
    /* 0x48 */ f32 targetFrustrumCenterX;
    /* 0x4C */ f32 targetFrustrumCenterY;
    /* 0x50 */ f32 frustrumCenterXLerpFactor;
    /* 0x54 */ f32 frustrumCenterYLerpFactor;
} unk_struct_58; // size = 0x58

typedef struct unk_redo_1 {
    /* 0x00 */ unk_struct_58 unk_00;
    /* 0x58 */ unk_struct_20 unk_58;
} unk_redo_1; // size = 0x78

typedef struct unk_redo_2 {
    /* 0x00 */ unk_struct_58 unk_00;
    /* 0x58 */ unk_struct_54 unk_58;
} unk_redo_2; // size = 0xAC

typedef struct unk_redo_3 {
    /* 0x00 */ unk_struct_58 unk_00;
    /* 0x58 */ unk_struct_68 unk_58;
} unk_redo_3; // size = 0xC0

typedef struct unk_8008112C_arg_1 {
    /* 0x00 */ unk_struct_58 unk_00;
    /* 0x58 */ unk_struct_9C unk_58;
} unk_8008112C_arg_1; // size = 0xF4

typedef struct CameraSettings {
    s32 type;
    unk_struct_58 unk_04;
    union {
        unk_struct_20 sub_1_unk_5C;
        unk_struct_54 sub_2_3_unk_5C;
        unk_struct_9C sub_4_unk_5C;
        unk_struct_68 sub_5_unk_5C;
    };
} CameraSettings; // size = 0xF8

typedef struct unk_struct_14 {
    s32 unk_00;
    f32* unk_04[3];
    s32* unk_10;
} unk_struct_14; // size = 0x14

typedef struct unk_80085154_arg_2 {
    s32 unk_00;
    f32* unk_04;
    s32* unk_08;
} unk_80085154_arg_2; // size = 0xC

typedef struct unk_80085434_arg_2 {
    unk_struct_14 unk_00[2];
    unk_80085154_arg_2 unk_28;
} unk_80085434_arg_2; // size = 0x34

typedef struct unk_80085494_arg_2 {
    unk_struct_14 unk_00[3];
    unk_80085154_arg_2 unk_3C;
} unk_80085494_arg_2; // size = 0x48

typedef struct unk_80085434_arg_0 {
    Vec3f unk_00[2];
    f32 unk_18;
} unk_80085434_arg_0; // size = 0x1C

typedef struct unk_80085494_arg_0 {
    Vec3f unk_00[3];
    f32 unk_24;
} unk_80085494_arg_0; // size = 0x28

typedef struct unk_struct_8 {
    s32 unk_00;
    s32 unk_04;
} unk_struct_8; // size = 0x8

typedef struct unk_struct_20_2 {
    unk_struct_8 unk_00[4];
} unk_struct_20_2; // size = 0x20

typedef struct unk_struct_C {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
} unk_struct_C; // size = 0xC

typedef struct unk_800E5D70 {
    CameraSettings* unk_00;
    unk_struct_C* unk_04;
    s32 unk_08;
    unk_struct_20_2* unk_0C;
    Vec3f* focusPos;
    Mtx3F* basis;
    Racer* racer;
    Vec3f* unk_1C;
    Mtx3F* unk_20;
} unk_800E5D70; // size = 0x24

typedef struct unk_8076D6C8 {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} unk_8076D6C8; // size 0x4

typedef struct unk_800CD8B0 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3f unk_24;
    f32 unk_30;
    f32 unk_34;
} unk_800CD8B0; // size 0x38

typedef struct unk_800CD970 {
    s16 type;
    s16 unk_02;
    f32 fov;
    void* unk_08;
} unk_800CD970; // size 0xC

#define CAMERA_FOV_FLAG_1 1
#define CAMERA_FOV_FLAG_2 2

#endif // FZX_CAMERA_H
