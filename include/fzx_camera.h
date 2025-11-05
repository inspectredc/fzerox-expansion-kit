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
    /*  5 */ CAMERA_MODE_SETUP_RACE,
    /*  6 */ CAMERA_MODE_RACE,
    /*  7 */ CAMERA_MODE_FALLING_OFF_TRACK,
    /*  8 */ CAMERA_MODE_FINISHED_SUCCESS,
    /*  9 */ CAMERA_MODE_FINISHED_SPECTATE,
    /* 10 */ CAMERA_MODE_FINISHED_LOSER,
    /* 11 */ CAMERA_MODE_RECORDS_RACE,
    /* 12 */ CAMERA_MODE_RECORDS_ENTRY,
    /* 13 */ CAMERA_MODE_13,
    /* 14 */ CAMERA_MODE_ENDING,
    /* 15 */ CAMERA_MODE_TITLE_DEMO,
    /* 16 */ CAMERA_MODE_16,
} CameraMode;

typedef enum CameraViewportTransitionState {
    /* 0 */ CAMERA_VP_TRANSITION_INACTIVE,
    /* 1 */ CAMERA_VP_TRANSITION_ACTIVE,
} CameraViewportTransitionState;

typedef enum CameraCourseSelectState {
    /* 0 */ CAMERA_COURSE_SELECT_ACCEPT_INPUTS,
    /* 1 */ CAMERA_COURSE_SELECT_DISABLED,
} CameraCourseSelectState;

#define CAMERA_FINISHED_SUCCESS_STATE_COUNT 5

typedef enum CameraFinishedSpectateState {
    /* 0 */ CAMERA_FINISHED_SPECTATE_STILL_ON_RACER,
    /* 1 */ CAMERA_FINISHED_SPECTATE_ROTATE_AROUND_RACER,
} CameraFinishedSpectateState;

typedef enum CameraEndingState {
    /* 0 */ CAMERA_ENDING_DRIVE_INTO_CAMERA,
    /* 1 */ CAMERA_ENDING_FOLLOW_RACER,
    /* 2 */ CAMERA_ENDING_FIXED_FOCUS_RACER,
    /* 3 */ CAMERA_ENDING_PODIUM_P3,
    /* 4 */ CAMERA_ENDING_PODIUM_P2,
    /* 5 */ CAMERA_ENDING_PODIUM_P1,
} CameraEndingState;

typedef enum EndingCameraMessage {
    /* 1 */ ENDING_CAMERA_1 = 1,
    /* 2 */ ENDING_CAMERA_PODIUM_P1,
    /* 3 */ ENDING_CAMERA_PODIUM_P2,
    /* 3 */ ENDING_CAMERA_PODIUM_P3,
} EndingCameraMessage;

typedef struct Camera {
    s32 id;
    s32 mode;
    s32 raceSetting;
    s32 lookBackRotate;
    s32 fovFlags;
    f32 targetFov;
    s32 state;
    s32 timer;
    Vec3f focusPos;
    Mtx3F racerBasis;
    Vec3f eye;
    Mtx3F basis;
    f32 unk_80;
    f32 unk_84;
    Vec3f at;
    f32 fov;
    f32 frustrumCenterX;
    f32 frustrumCenterY;
    f32 near;
    f32 far;
    f32 fovScaleX;
    f32 fovScaleY;
    f32 currentScissorLeft;
    f32 currentScissorTop;
    f32 currentScissorRight;
    f32 currentScissorBottom;
    f32 startScissorLeft;
    f32 startScissorTop;
    f32 startScissorRight;
    f32 startScissorBottom;
    f32 endScissorLeft;
    f32 endScissorTop;
    f32 endScissorRight;
    f32 endScissorBottom;
    s32 vpTransitionState;
    s16 transitionTimer;
    s16 transitionTime;
    f32 currentVpScaleX;
    f32 currentVpScaleY;
    f32 currentVpTransX;
    f32 currentVpTransY;
    f32 startVpScaleX;
    f32 startVpScaleY;
    f32 startVpTransX;
    f32 startVpTransY;
    f32 endVpScaleX;
    f32 endVpScaleY;
    f32 endVpTransX;
    f32 endVpTransY;
    u16 perspectiveScale;
    MtxF projectionMtx;
    MtxF viewMtx;
    MtxF projectionViewMtx;
} Camera; // size = 0x1DC

typedef enum CameraRaceSetting {
    /* 0 */ CAMERA_RACE_SETTING_OVERHEAD,
    /* 1 */ CAMERA_RACE_SETTING_CLOSE_BEHIND,
    /* 2 */ CAMERA_RACE_SETTING_REGULAR,
    /* 3 */ CAMERA_RACE_SETTING_WIDE,
    /* 4 */ CAMERA_RACE_SETTING_MAX,
} CameraRaceSetting;

#define CAMERA_FOV_FLAG_1 1
#define CAMERA_FOV_FLAG_2 2

typedef struct CameraRaceSettingInfo {
    /* 0x0 */ f32 fov;
    /* 0x4 */ f32 distance;
    /* 0x8 */ f32 pitch;
} CameraRaceSettingInfo; // size = 0xC

typedef enum CameraType {
    /* 1 */ CAMERA_TYPE_AT_EYE = 1,
    /* 2 */ CAMERA_TYPE_ORBIT_AT,
    /* 3 */ CAMERA_TYPE_ORBIT_EYE,
    /* 4 */ CAMERA_TYPE_FOLLOW_SMOOTH,
    /* 5 */ CAMERA_TYPE_LOCAL_ANCHOR,
} CameraType;

typedef struct CameraParameters {
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
} CameraParameters; // size = 0x58

typedef struct CameraTypeAtEye {
    /* 0x00 */ Vec3f targetAt;
    /* 0x0C */ Vec3f targetEye;
    /* 0x18 */ f32 atLerpFactor;
    /* 0x1C */ f32 eyeLerpFactor;
} CameraTypeAtEye; // size = 0x20

typedef struct CameraTypeOrbit {
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
} CameraTypeOrbit; // size = 0x54

typedef struct CameraTypeFollowSmooth {
    /* 0x00 */ Mtx3F racerBasis;
    /* 0x24 */ Mtx3F basis;
    /* 0x48 */ Vec3f centerPos;
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
} CameraTypeFollowSmooth; // size = 0x9C

typedef struct CameraTypeLocalAnchor {
    /* 0x00 */ Vec3f anchorPoint;
    /* 0x0C */ Mtx3F basis;
    /* 0x30 */ Vec3f localAtCoordinates; // x-side z-depth
    /* 0x3C */ Vec3f targetLocalAt;
    /* 0x48 */ Vec3f localEyeCoordinates; // x-side z-depth
    /* 0x54 */ Vec3f targetLocalEye;
    /* 0x60 */ f32 localAtLerpFactor;
    /* 0x64 */ f32 localEyeLerpFactor;
} CameraTypeLocalAnchor; // size = 0x68

typedef struct CameraSettings {
    s32 type;
    CameraParameters parameters;
    union {
        CameraTypeAtEye atEye;
        CameraTypeOrbit orbit;
        CameraTypeFollowSmooth followSmooth;
        CameraTypeLocalAnchor localAnchor;
    };
} CameraSettings; // size = 0xF8

typedef struct CameraAtEyeData {
    /* 0x00 */ CameraParameters parameters;
    /* 0x58 */ CameraTypeAtEye data;
} CameraAtEyeData; // size = 0x78

typedef struct CameraOrbitData {
    /* 0x00 */ CameraParameters parameters;
    /* 0x58 */ CameraTypeOrbit data;
} CameraOrbitData; // size = 0xAC

typedef struct CameraFollowSmoothData {
    /* 0x00 */ CameraParameters parameters;
    /* 0x58 */ CameraTypeFollowSmooth data;
} CameraFollowSmoothData; // size = 0xF4

typedef struct CameraLocalAnchorData {
    /* 0x00 */ CameraParameters parameters;
    /* 0x58 */ CameraTypeLocalAnchor data;
} CameraLocalAnchorData; // size = 0xC0

typedef struct CubicBSpline3fData {
    s32 controlPointCount;
    f32* controlPoints[3];
    s32* times;
} CubicBSpline3fData; // size = 0x14

typedef struct CubicBSpline1fData {
    s32 controlPointCount;
    f32* controlPoints;
    s32* times;
} CubicBSpline1fData; // size = 0xC

typedef struct CubicBSpline331Data {
    CubicBSpline3fData vecData[2];
    CubicBSpline1fData floatData;
} CubicBSpline331Data; // size = 0x34

typedef struct CubicBSpline3331Data {
    CubicBSpline3fData vecData[3];
    CubicBSpline1fData floatData;
} CubicBSpline3331Data; // size = 0x48

typedef struct InterpolateOut331Data {
    Vec3f vecData[2];
    f32 floatData;
} InterpolateOut331Data; // size = 0x1C

typedef struct InterpolateOut3331Data {
    Vec3f vecData[3];
    f32 floatData;
} InterpolateOut3331Data; // size = 0x28

typedef struct SplineControlPointTimer {
    s32 timer;
    s32 controlPoint;
} SplineControlPointTimer; // size = 0x8

typedef struct SplineControlPointTimers {
    SplineControlPointTimer controlPointTimer[4];
} SplineControlPointTimers; // size = 0x20

#define CAMERA_SCRIPT_NEXT 0
#define CAMERA_SCRIPT_CLEAR -1
#define CAMERA_SCRIPT_BREAK -2

typedef struct CameraScript {
    s32 time;
    void* updateFunc;
    void* updateData; // can be a pointer or int
} CameraScript; // size = 0xC

typedef struct CameraScriptManager {
    CameraSettings* settings;
    CameraScript* script;
    s32 timer;
    SplineControlPointTimers* controlPointTimers;
    Vec3f* focusPos;
    Mtx3F* racerBasis;
    Racer* racer;
    Vec3f* eyeAnchorPoint;
    Mtx3F* eyeBasis;
} CameraScriptManager; // size = 0x24

typedef enum FinishedSuccessScriptType {
    /* 0 */ FINISHED_SUCCESS_FIXED_FOLLOW_RACER,
    /* 1 */ FINISHED_SUCCESS_LERP_LOCAL_AT_EYE,
} FinishedSuccessScriptType;

typedef struct EyeFromRacerInfo {
    f32 distanceAhead;
    f32 lateralOffset;
    f32 verticalOffset;
} EyeFromRacerInfo; // size 0x4

typedef struct LerpLocalAtEyeInfo {
    Vec3f startAt;
    Vec3f endAt;
    Vec3f startEye;
    Vec3f endEye;
    f32 atTranslationScale;
    f32 eyeTranslationScale;
} LerpLocalAtEyeInfo; // size 0x38

typedef struct FinishedSuccessScript {
    s16 type;
    s16 time;
    f32 fov;
    void* data;
} FinishedSuccessScript; // size 0xC

typedef struct unk_800832EC_arg_2 {
    u32 unk_00;
    u32 unk_04;
    s32* unk_08;
    u8* unk_0C;
} unk_800832EC_arg_2;

void Camera_ScriptSetLocalAnchorData(CameraScriptManager* scriptMgr, CameraLocalAnchorData* localAnchorData);
void Camera_ScriptSetControlPointTimerCount(CameraScriptManager* scriptMgr, s32 timersCount);
void Camera_ScriptUpdateLocalAnchorBasisAtEye(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData);
void Camera_ScriptUpdateLocalAnchorBasisAtEyeFov(CameraScriptManager* scriptMgr, CubicBSpline331Data* splineData);
void Camera_ScriptUpdateLocalAnchorBasisAtEyeUpFov(CameraScriptManager* scriptMgr, CubicBSpline3331Data* splineData);

#endif // FZX_CAMERA_H
