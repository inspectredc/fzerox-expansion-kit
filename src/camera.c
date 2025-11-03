#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_assets.h"
#include "fzx_camera.h"

Camera gCameras[4];
CameraSettings gCameraSettings[4];
unk_800E5D70 D_807A1480[4];
unk_struct_20_2 D_807A1510[4];
s32 sNumCameras;
s32 D_807A1594;
s16 sCameraEndingFocusRacer;
s16 D_807A159A;
UNUSED s16 D_807A159C;
Vec3f D_807A15A0[4];

const CameraAtEyeData D_807763D0 = {
    { { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      { 0.0f, 1.0f, 0.0f },
      1.0f,
      60.0f,
      60.0f,
      1.0f,
      0.0f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      1.0f },
    { { 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f, 1.0f }, 1.0f, 1.0f },
};

const CameraOrbitData D_80776448 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

UNUSED const CameraFollowSmoothData D_807764F4 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 120.0f, 120.0f, 1.0f, 35.0f, 35.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0 },
};

const CameraLocalAnchorData D_807765E8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
};

const CameraOrbitData D_807766A8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 400.0f, 400.0f, 1.0f, 40.0f, 40.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const CameraOrbitData D_80776754 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 1500.0f, 1500.0f, 1.0f, 35.0f, 35.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const CameraOrbitData D_80776800 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,     0.0f,     0.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 10500.0f, 10500.0f, 1.0f, 20.0f, 20.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

const CameraAtEyeData D_807768AC = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 4000.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 30.0f, 30.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

UNUSED const CameraAtEyeData D_80776924 = {
    { 0.0f, 50.0f, 0.0f,  0.0f,  150.0f, 500.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f,  75.0f, 75.0f, 0.0f,   0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

const CameraOrbitData D_8077699C = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 75.0f, 75.0f, 1.0f, 0.0f, 77.0f, 0.0f, 77.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,   0.0f,   1.0f, 0.0f,
      0.0f, 1000.0f, 1000.0f, 1.0f, 35.0f, 35.0f, 1.0f, 180.0f, 180.0f, 1.0f },
};

const unk_80776A48 D_80776A48[] = {
    { 80.0f, 400.0f, 50.0f },
    { 75.0f, 90.0f, 25.0f },
    { 75.0f, 120.0f, 35.0f },
    { 100.0f, 120.0f, 50.0f },
};

const unk_80776A48 D_80776A78[] = {
    { 100.0f, 400.0f, 50.0f },
    { 90.0f, 100.0f, 25.0f },
    { 100.0f, 120.0f, 35.0f },
    { 110.0f, 125.0f, 40.0f },
};

const CameraFollowSmoothData D_80776AA8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 400.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 80.0f, 80.0f, 0.2f, 0.0f,   77.0f, 0.0f, 77.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0 },
};

const CameraFollowSmoothData D_80776B9C = {
    { 0.0f, 0.0f, 0.0f,   0.0f,   0.0f, 400.0f, 0.0f,   1.0f, 0.0f,   0.0f, 1.0f,
      0.0f, 1.0f, 100.0f, 100.0f, 0.2f, 0.0f,   -15.0f, 0.0f, -15.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0 },
};

s32 D_8076D6C0 = -1;
s32 D_8076D6C4 = 1;

unk_8076D6C8 D_8076D6C8 = {
    2000.0f,
    0.0f,
    25.0f,
};

unk_8076D6C8 D_8076D6D4 = {
    4000.0f,
    -0.9f,
    50.0f,
};

unk_800CD8B0 D_8076D6E0 = {
    { -7.0f, 0.0f, 63.0f }, { -7.0f, 0.0f, 63.0f }, { 26.0f, 20.0f, -65.0f }, { 26.0f, 20.0f, -65.0f }, 0.0f, 0.0f
};

unk_800CD8B0 D_8076D718 = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -50.0f, 40.0f, 40.0f }, { -50.0f, 40.0f, -40.0f }, 0.0f, 1.0f
};

unk_800CD8B0 D_8076D750 = {
    { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { -40.0f, 30.0f, 104.0f }, { 40.0f, 30.0f, 104.0f }, 0.0f, 1.0f
};

unk_800CD970 D_8076D788[] = {
    { 0, 88, 60.0f, &D_8076D6C8 }, { 1, 23, 60.0f, &D_8076D6E0 },  { 1, 23, 60.0f, &D_8076D718 },
    { 1, 23, 80.0f, &D_8076D750 }, { 0, 284, 60.0f, &D_8076D6D4 },
};

const s32 kSingleCameraScissorBoxTypes[] = { SCISSOR_BOX_FULL_SCREEN };

const s32 kTwoCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_HALF, SCISSOR_BOX_BOTTOM_HALF };

const s32 kThreeCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_LEFT_QUARTER, SCISSOR_BOX_BOTTOM_LEFT_QUARTER,
                                            SCISSOR_BOX_TOP_RIGHT_QUARTER };

const s32 kFourCameraScissorBoxTypes[] = { SCISSOR_BOX_TOP_LEFT_QUARTER, SCISSOR_BOX_BOTTOM_LEFT_QUARTER,
                                           SCISSOR_BOX_TOP_RIGHT_QUARTER, SCISSOR_BOX_BOTTOM_RIGHT_QUARTER };

const s32* sCameraScissorBoxTypes[] = {
    NULL,
    kSingleCameraScissorBoxTypes,
    kTwoCameraScissorBoxTypes,
    kThreeCameraScissorBoxTypes,
    kFourCameraScissorBoxTypes,
};

ScissorBox gScissorBoxFullScreen = { 12, 8, 308, 232 };
ScissorBox gScissorBoxTopHalf = { 12, 8, 307, 119 };
ScissorBox gScissorBoxBottomHalf = { 12, 120, 307, 231 };
ScissorBox gScissorBoxLeftHalf = { 12, 8, 159, 231 };
ScissorBox gScissorBoxRightHalf = { 160, 8, 307, 231 };
ScissorBox gScissorBoxTopLeftQuarter = { 12, 8, 159, 119 };
ScissorBox gScissorBoxTopRightQuarter = { 160, 8, 307, 119 };
ScissorBox gScissorBoxBottomLeftQuarter = { 12, 120, 159, 231 };
ScissorBox gScissorBoxBottomRightQuarter = { 160, 120, 307, 231 };
ScissorBox gScissorBoxTopCenterQuarter = { 86, 8, 233, 119 };
ScissorBox gScissorBoxBottomCenterQuarter = { 86, 120, 233, 231 };
ScissorBox gScissorBoxLeftCenterQuarter = { 12, 64, 159, 175 };
ScissorBox gScissorBoxRightCenterQuarter = { 160, 64, 307, 175 };

f32 D_8076D8A8 = 1375.0f / 54.0f;
f32 D_8076D8AC = 2500.0f / 54.0f;
f32 D_8076D8B0 = 120.0f;
s32 sMaxCameraLookBackRotate = 8;

void Camera_SettingsSetAtEye(CameraSettings* cameraSettings, CameraTypeAtEye* atEye) {
    cameraSettings->type = CAMERA_TYPE_AT_EYE;
    cameraSettings->atEye = *atEye;
}

void Camera_SettingsSetAtEyeWithParameters(CameraSettings* cameraSettings, CameraAtEyeData* atEyeData) {
    cameraSettings->type = CAMERA_TYPE_AT_EYE;
    cameraSettings->parameters = atEyeData->parameters;
    cameraSettings->atEye = atEyeData->data;
}

void Camera_SettingsSetFollowSmooth(CameraSettings* cameraSettings, CameraTypeFollowSmooth* followSmooth) {
    cameraSettings->type = CAMERA_TYPE_FOLLOW_SMOOTH;
    cameraSettings->followSmooth = *followSmooth;
}

void Camera_SettingsSetFollowSmoothWithParameters(CameraSettings* cameraSettings,
                                                  CameraFollowSmoothData* followSmoothData) {
    cameraSettings->type = CAMERA_TYPE_FOLLOW_SMOOTH;
    cameraSettings->parameters = followSmoothData->parameters;
    cameraSettings->followSmooth = followSmoothData->data;
}

void Camera_SettingsSetOrbit(CameraSettings* cameraSettings, s32 type, CameraTypeOrbit* orbit) {
    cameraSettings->type = type;
    cameraSettings->orbit = *orbit;
}

void Camera_SettingsSetOrbitWithParameters(CameraSettings* cameraSettings, s32 type, CameraOrbitData* orbitData) {
    cameraSettings->type = type;
    cameraSettings->parameters = orbitData->parameters;
    cameraSettings->orbit = orbitData->data;
}

void Camera_SettingsSetLocalAnchor(CameraSettings* cameraSettings, CameraTypeLocalAnchor* localAnchor) {
    cameraSettings->type = CAMERA_TYPE_LOCAL_ANCHOR;
    cameraSettings->localAnchor = *localAnchor;
}

void Camera_SettingsSetLocalAnchorWithParameters(CameraSettings* cameraSettings,
                                                 CameraLocalAnchorData* localAnchorData) {
    cameraSettings->type = CAMERA_TYPE_LOCAL_ANCHOR;
    cameraSettings->parameters = localAnchorData->parameters;
    cameraSettings->localAnchor = localAnchorData->data;
}

void Camera_SettingsUpdateCommon(CameraSettings* cameraSettings) {
    CameraParameters* params = &cameraSettings->parameters;

    params->up.x += (params->targetUp.x - params->up.x) * params->upLerpFactor;
    params->up.y += (params->targetUp.y - params->up.y) * params->upLerpFactor;
    params->up.z += (params->targetUp.z - params->up.z) * params->upLerpFactor;
    params->fov += (params->targetFov - params->fov) * params->fovLerpFactor;
    params->frustrumCenterX +=
        (params->targetFrustrumCenterX - params->frustrumCenterX) * params->frustrumCenterXLerpFactor;
    params->frustrumCenterY +=
        (params->targetFrustrumCenterY - params->frustrumCenterY) * params->frustrumCenterYLerpFactor;
}

void Camera_SettingsUpdateAtEye(CameraSettings* cameraSettings) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;
    CameraParameters* params = &cameraSettings->parameters;

    params->at.x += (atEye->targetAt.x - params->at.x) * atEye->atLerpFactor;
    params->at.y += (atEye->targetAt.y - params->at.y) * atEye->atLerpFactor;
    params->at.z += (atEye->targetAt.z - params->at.z) * atEye->atLerpFactor;
    params->eye.x += (atEye->targetEye.x - params->eye.x) * atEye->eyeLerpFactor;
    params->eye.y += (atEye->targetEye.y - params->eye.y) * atEye->eyeLerpFactor;
    params->eye.z += (atEye->targetEye.z - params->eye.z) * atEye->eyeLerpFactor;
}

void Camera_SettingsUpdateOrbit(CameraSettings* cameraSettings) {
    s32 angle;
    f32 sp40;
    f32 sp3C;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 xOffset;
    f32 yOffset;
    f32 zOffset;
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    orbit->distance += (orbit->targetDistance - orbit->distance) * orbit->distanceLerpFactor;
    orbit->pitch += (orbit->targetPitch - orbit->pitch) * orbit->pitchLerpFactor;
    orbit->yaw += (orbit->targetYaw - orbit->yaw) * orbit->yawLerpFactor;

    angle = Math_Round(DEG_TO_FZXANG2(orbit->pitch));

    sp3C = orbit->distance * SIN(angle);
    sp40 = orbit->distance * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(orbit->yaw));
    temp_fv0 = SIN(angle) * sp40;
    temp_fv1 = COS(angle) * sp40;

    xOffset = (orbit->basis.x.x * temp_fv1) + (orbit->basis.z.x * temp_fv0) + (orbit->basis.y.x * sp3C);
    yOffset = (orbit->basis.x.y * temp_fv1) + (orbit->basis.z.y * temp_fv0) + (orbit->basis.y.y * sp3C);
    zOffset = (orbit->basis.x.z * temp_fv1) + (orbit->basis.z.z * temp_fv0) + (orbit->basis.y.z * sp3C);

    switch (cameraSettings->type) {
        case CAMERA_TYPE_ORBIT_AT:
            params->at = orbit->anchorPos;
            params->eye.x = orbit->anchorPos.x + xOffset;
            params->eye.y = orbit->anchorPos.y + yOffset;
            params->eye.z = orbit->anchorPos.z + zOffset;
            break;
        case CAMERA_TYPE_ORBIT_EYE:
            params->eye = orbit->anchorPos;
            params->at.x = orbit->anchorPos.x + xOffset;
            params->at.y = orbit->anchorPos.y + yOffset;
            params->at.z = orbit->anchorPos.z + zOffset;
            break;
    }
}

extern s32 gNumPlayers;
extern s8 gGamePaused;

void Camera_SettingsUpdateFollowSmooth(CameraSettings* cameraSettings, Camera* camera) {
    s32 angle;
    f32 var_fv1;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    Racer* racer = &gRacers[camera->id];
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0;
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;

    followSmooth->distance +=
        (followSmooth->targetDistance - followSmooth->distance) * followSmooth->distanceLerpFactor;
    followSmooth->pitch += (followSmooth->targetPitch - followSmooth->pitch) * followSmooth->pitchLerpFactor;
    followSmooth->yaw += (followSmooth->targetYaw - followSmooth->yaw) * followSmooth->yawLerpFactor;

    camera->focusPos.x = racer->focusPos.x;
    camera->focusPos.y = racer->focusPos.y;
    camera->focusPos.z = racer->focusPos.z;

    var_fv1 = (racer->focusVelocity.x * racer->gravityUp.x) + (racer->focusVelocity.y * racer->gravityUp.y) +
              (racer->focusVelocity.z * racer->gravityUp.z);
    sp98.x = (followSmooth->anchorPoint.x - camera->focusPos.x) + (var_fv1 * racer->gravityUp.x);
    sp98.y = (followSmooth->anchorPoint.y - camera->focusPos.y) + (var_fv1 * racer->gravityUp.y);
    sp98.z = (followSmooth->anchorPoint.z - camera->focusPos.z) + (var_fv1 * racer->gravityUp.z);
    var_fv1 = sqrtf(SQ(sp98.x) + SQ(sp98.y) + SQ(sp98.z));

    if (var_fv1 < 0.01f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp98.x *= var_fv1;
    sp98.y *= var_fv1;
    sp98.z *= var_fv1;
    if (!gGamePaused) {
        temp_fv0 = followSmooth->distance;
        followSmooth->anchorPoint.x = camera->focusPos.x + (temp_fv0 * sp98.x);
        followSmooth->anchorPoint.y = camera->focusPos.y + (temp_fv0 * sp98.y);
        followSmooth->anchorPoint.z = camera->focusPos.z + (temp_fv0 * sp98.z);
    }

    temp_fv0 = (racer->focusVelocity.x * camera->basis.y.x) + (racer->focusVelocity.y * camera->basis.y.y) +
               (racer->focusVelocity.z * camera->basis.y.z);
    if (followSmooth->targetYaw >= 50.0f) {
        var_fv1 = 0.0f;
    } else {
        var_fv1 = (50.0f - followSmooth->targetYaw) * 0.02f;
    }

    params->at.x = camera->focusPos.x + (var_fv1 * (racer->focusVelocity.x - (temp_fv0 * camera->basis.y.x)));
    params->at.y = camera->focusPos.y + (var_fv1 * (racer->focusVelocity.y - (temp_fv0 * camera->basis.y.y)));
    params->at.z = camera->focusPos.z + (var_fv1 * (racer->focusVelocity.z - (temp_fv0 * camera->basis.y.z)));
    sp8C.x = racer->gravityUp.x - camera->racerBasis.y.x;
    sp8C.y = racer->gravityUp.y - camera->racerBasis.y.y;
    sp8C.z = racer->gravityUp.z - camera->racerBasis.y.z;

    var_fv1 = sqrtf(SQ(sp8C.x) + SQ(sp8C.y) + SQ(sp8C.z)) * 0.2f;

    followSmooth->basis.y.x = camera->racerBasis.y.x += var_fv1 * sp8C.x;
    followSmooth->basis.y.y = camera->racerBasis.y.y += var_fv1 * sp8C.y;
    followSmooth->basis.y.z = camera->racerBasis.y.z += var_fv1 * sp8C.z;

    sp7C.x = (followSmooth->basis.y.y * sp98.z) - (followSmooth->basis.y.z * sp98.y);
    sp7C.y = (followSmooth->basis.y.z * sp98.x) - (followSmooth->basis.y.x * sp98.z);
    sp7C.z = (followSmooth->basis.y.x * sp98.y) - (followSmooth->basis.y.y * sp98.x);
    var_fv1 = sqrtf(SQ(sp7C.x) + SQ(sp7C.y) + SQ(sp7C.z));
    if (var_fv1 < 0.1f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp7C.x *= var_fv1;
    sp7C.y *= var_fv1;
    sp7C.z *= var_fv1;

    sp70.x = (sp98.y * sp7C.z) - (sp98.z * sp7C.y);
    sp70.y = (sp98.z * sp7C.x) - (sp98.x * sp7C.z);
    sp70.z = (sp98.x * sp7C.y) - (sp98.y * sp7C.x);

    var_fv1 = 1.0f / sqrtf(SQ(sp70.x) + SQ(sp70.y) + SQ(sp70.z));

    sp70.x *= var_fv1;
    sp70.y *= var_fv1;
    sp70.z *= var_fv1;
    angle = Math_Round(DEG_TO_FZXANG2(followSmooth->pitch));

    var_fv1 = followSmooth->distance * SIN(angle) *
              ((sp70.x * racer->trueBasis.y.x) + (sp70.y * racer->trueBasis.y.y) + (sp70.z * racer->trueBasis.y.z));
    spA4 = followSmooth->distance * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(followSmooth->targetYaw));
    temp_fv0 = COS(angle) * spA4;
    spA4 = SIN(angle) * spA4;
    params->eye.x = camera->focusPos.x + (spA4 * sp7C.x) + (temp_fv0 * sp98.x) + (var_fv1 * sp70.x);
    params->eye.y = camera->focusPos.y + (spA4 * sp7C.y) + (temp_fv0 * sp98.y) + (var_fv1 * sp70.y);
    params->eye.z = camera->focusPos.z + (spA4 * sp7C.z) + (temp_fv0 * sp98.z) + (var_fv1 * sp70.z);
    followSmooth->basis.x.x = params->at.x - params->eye.x;
    followSmooth->basis.x.y = params->at.y - params->eye.y;
    followSmooth->basis.x.z = params->at.z - params->eye.z;
    Math_OrthonormalizeAroundForward(&followSmooth->basis);
    if (!gGamePaused) {
        params->targetUp.x = params->up.x = followSmooth->basis.y.x;
        params->targetUp.y = params->up.y = followSmooth->basis.y.y;
        params->targetUp.z = params->up.z = followSmooth->basis.y.z;
    }
    params->frustrumCenterX = 0.0f;
    params->targetFrustrumCenterX = 0.0f;
    if (gNumPlayers == 2) {
        params->frustrumCenterY = -15.0f;
        params->targetFrustrumCenterY = -15.0f;
    } else {
        params->frustrumCenterY = 77.0f;
        params->targetFrustrumCenterY = 77.0f;
    }
}

void Camera_SettingsUpdateLocalAnchor(CameraSettings* cameraSettings) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;

    localAnchor->localAtCoordinates.x +=
        (localAnchor->targetLocalAt.x - localAnchor->localAtCoordinates.x) * localAnchor->localAtLerpFactor;
    localAnchor->localAtCoordinates.y +=
        (localAnchor->targetLocalAt.y - localAnchor->localAtCoordinates.y) * localAnchor->localAtLerpFactor;
    localAnchor->localAtCoordinates.z +=
        (localAnchor->targetLocalAt.z - localAnchor->localAtCoordinates.z) * localAnchor->localAtLerpFactor;

    localAnchor->localEyeCoordinates.x +=
        (localAnchor->targetLocalEye.x - localAnchor->localEyeCoordinates.x) * localAnchor->localEyeLerpFactor;
    localAnchor->localEyeCoordinates.y +=
        (localAnchor->targetLocalEye.y - localAnchor->localEyeCoordinates.y) * localAnchor->localEyeLerpFactor;
    localAnchor->localEyeCoordinates.z +=
        (localAnchor->targetLocalEye.z - localAnchor->localEyeCoordinates.z) * localAnchor->localEyeLerpFactor;

    params->at.x = localAnchor->anchorPoint.x + (localAnchor->basis.z.x * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.x * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.x * localAnchor->localAtCoordinates.z);
    params->at.y = localAnchor->anchorPoint.y + (localAnchor->basis.z.y * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.y * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.y * localAnchor->localAtCoordinates.z);
    params->at.z = localAnchor->anchorPoint.z + (localAnchor->basis.z.z * localAnchor->localAtCoordinates.x) +
                   (localAnchor->basis.y.z * localAnchor->localAtCoordinates.y) +
                   (localAnchor->basis.x.z * localAnchor->localAtCoordinates.z);

    params->eye.x = localAnchor->anchorPoint.x + (localAnchor->basis.z.x * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.x * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.x * localAnchor->localEyeCoordinates.z);
    params->eye.y = localAnchor->anchorPoint.y + (localAnchor->basis.z.y * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.y * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.y * localAnchor->localEyeCoordinates.z);
    params->eye.z = localAnchor->anchorPoint.z + (localAnchor->basis.z.z * localAnchor->localEyeCoordinates.x) +
                    (localAnchor->basis.y.z * localAnchor->localEyeCoordinates.y) +
                    (localAnchor->basis.x.z * localAnchor->localEyeCoordinates.z);
}

void Camera_SettingsUpdate(CameraSettings* cameraSettings, Camera* camera) {

    switch (cameraSettings->type) {
        case CAMERA_TYPE_AT_EYE:
            Camera_SettingsUpdateAtEye(cameraSettings);
            break;
        case CAMERA_TYPE_FOLLOW_SMOOTH:
            Camera_SettingsUpdateFollowSmooth(cameraSettings, camera);
            break;
        case CAMERA_TYPE_ORBIT_AT:
        case CAMERA_TYPE_ORBIT_EYE:
            Camera_SettingsUpdateOrbit(cameraSettings);
            break;
        case CAMERA_TYPE_LOCAL_ANCHOR:
            Camera_SettingsUpdateLocalAnchor(cameraSettings);
            break;
    }
    Camera_SettingsUpdateCommon(cameraSettings);
}

void func_80712B34(CameraSettings* cameraSettings, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

    if (arg1 != NULL) {
        atEye->targetAt.x = arg1->x;
        atEye->targetAt.y = arg1->y;
        atEye->targetAt.z = arg1->z;
    }
    if (arg2 != NULL) {
        atEye->targetEye.x = arg2->x;
        atEye->targetEye.y = arg2->y;
        atEye->targetEye.z = arg2->z;
    }
    if (arg3 != NULL) {
        params->targetUp.x = arg3->x;
        params->targetUp.y = arg3->y;
        params->targetUp.z = arg3->z;
    }
    if (arg4 != NULL) {
        params->targetFov = *arg4;
    }
}

void func_80712BBC(CameraSettings* cameraSettings, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    if (arg1 != NULL) {
        orbit->anchorPos.x = arg1->x;
        orbit->anchorPos.y = arg1->y;
        orbit->anchorPos.z = arg1->z;
    }
    if (arg2 != NULL) {
        orbit->targetDistance = arg2->v[0];
        orbit->targetYaw = arg2->v[1];
        orbit->targetPitch = arg2->v[2];
    }
    if (arg3 != NULL) {
        params->targetUp.x = arg3->x;
        params->targetUp.y = arg3->y;
        params->targetUp.z = arg3->z;
    }
    if (arg4 != NULL) {
        params->targetFov = *arg4;
    }
}

void func_80712C44(CameraSettings* cameraSettings, Vec3f* arg1, Mtx3F* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5,
                   f32* arg6) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;

    if (arg1 != NULL) {
        localAnchor->anchorPoint.x = arg1->x;
        localAnchor->anchorPoint.y = arg1->y;
        localAnchor->anchorPoint.z = arg1->z;
    }
    if (arg2 != NULL) {
        localAnchor->basis.x.x += arg2->x.x * 0.2f;
        localAnchor->basis.x.y += arg2->x.y * 0.2f;
        localAnchor->basis.x.z += arg2->x.z * 0.2f;
        localAnchor->basis.y.x += arg2->y.x * 0.2f;
        localAnchor->basis.y.y += arg2->y.y * 0.2f;
        localAnchor->basis.y.z += arg2->y.z * 0.2f;
        localAnchor->basis.z.x += arg2->z.x * 0.2f;
        localAnchor->basis.z.y += arg2->z.y * 0.2f;
        localAnchor->basis.z.z += arg2->z.z * 0.2f;
        Math_OrthonormalizeAroundForward(&localAnchor->basis);
    }
    if (arg3 != NULL) {
        localAnchor->targetLocalAt.x = arg3->x;
        localAnchor->targetLocalAt.y = arg3->y;
        localAnchor->targetLocalAt.z = arg3->z;
    }
    if (arg4 != NULL) {
        localAnchor->targetLocalEye.x = arg4->x;
        localAnchor->targetLocalEye.y = arg4->y;
        localAnchor->targetLocalEye.z = arg4->z;
    }
    if (arg5 != NULL) {
        params->targetUp.x = arg5->x;
        params->targetUp.y = arg5->y;
        params->targetUp.z = arg5->z;
    }
    if (arg6 != NULL) {
        params->targetFov = *arg6;
    }
}

void func_80712DE0(CameraSettings* cameraSettings, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    CameraParameters* params = &cameraSettings->parameters;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;

    if (arg1 != NULL) {
        followSmooth->centerPos.x = arg1->x;
        followSmooth->centerPos.y = arg1->y;
        followSmooth->centerPos.z = arg1->z;
    }
    if (arg2 != NULL) {
        followSmooth->targetDistance = arg2->v[0];
        followSmooth->targetYaw = arg2->v[1];
        followSmooth->targetPitch = arg2->v[2];
    }
    if (arg3 != NULL) {
        params->targetUp.x = arg3->x;
        params->targetUp.y = arg3->y;
        params->targetUp.z = arg3->z;
    }
    if (arg4 != NULL) {
        params->targetFov = *arg4;
    }
}

f32 func_80712E68(CourseSegment** segment, f32 t, f32 arg2) {
    f32 temp_fs3;
    s32 i;
    s32 sp54;
    s32 pad[4];
    Vec3f tangent;
    Mtx3F basis;

    sp54 = (s32) arg2 / 20;
    temp_fs3 = Course_SplineGetBasis(*segment, t, &basis, 0.0f);

    for (i = 0; i < sp54; i++) {
        t += 20.0f / temp_fs3;
        if (t >= 1.0f) {
            *segment = (*segment)->next;
            t -= 1.0f;
            t *= (temp_fs3 / Course_SplineGetTangent(*segment, 0.0f, &tangent));
        }
    }

    t += ((arg2 - ((f32) sp54 * 20.0f)) / temp_fs3);
    if (t >= 1.0f) {
        *segment = (*segment)->next;
        t -= 1.0f;
        t *= (temp_fs3 / Course_SplineGetTangent(*segment, 0.0f, &tangent));
    }
    return t;
}

Mtx3F* func_80712FE4(Mtx3F* basis, CourseSegment* segment, f32 t) {
    s32 pad;
    f32 lengthFromStart;
    Mtx3F segmentBasis;

    Course_SplineGetBasis(segment, t, &segmentBasis, Course_SplineGetLengthInfo(segment, t, &lengthFromStart));
    *basis = segmentBasis;

    return basis;
}

void Camera_RaceSettingChanged(Camera* camera, CameraParameters* arg1, CameraTypeFollowSmooth* arg2, s32 numPlayers) {
    unk_80776A48* var_v0;

    if (numPlayers == 2) {
        var_v0 = &D_80776A78[camera->raceSetting];
    } else {
        var_v0 = &D_80776A48[camera->raceSetting];
    }
    arg2->targetDistance = var_v0->distance;
    arg2->targetPitch = var_v0->pitch;
    arg1->targetFov = camera->targetFov = var_v0->fov;

    camera->fovFlags = CAMERA_FOV_FLAG_2;

    switch (camera->raceSetting) {
        case CAMERA_RACE_SETTING_CLOSE_BEHIND:
        case CAMERA_RACE_SETTING_REGULAR:
            camera->fovFlags |= CAMERA_FOV_FLAG_1;
            break;
        default:
            break;
    }
}

void func_807130F8(Camera* camera, CameraSettings* arg1) {

    camera->eye = arg1->parameters.eye;
    camera->at = arg1->parameters.at;

    camera->basis.y.x = arg1->parameters.up.x;
    camera->basis.y.y = arg1->parameters.up.y;
    camera->basis.y.z = arg1->parameters.up.z;
    camera->fov = arg1->parameters.fov;
    camera->frustrumCenterX = arg1->parameters.frustrumCenterX;
    camera->frustrumCenterY = arg1->parameters.frustrumCenterY;
}

void func_8071315C(Camera* camera) {
    f32 x;
    f32 z;
    f32 normalizingFactor;

    camera->basis.x.x = camera->at.x - camera->eye.x;
    camera->basis.x.y = camera->at.y - camera->eye.y;
    camera->basis.x.z = camera->at.z - camera->eye.z;

    Math_OrthonormalizeAroundForward(&camera->basis);
    x = camera->basis.x.x;
    z = camera->basis.x.z;
    normalizingFactor = sqrtf(SQ(x) + SQ(z));
    if (normalizingFactor != 0.0f) {
        camera->unk_80 = camera->basis.x.x / normalizingFactor;
        camera->unk_84 = camera->basis.x.z / normalizingFactor;
    }
}

void Camera_CalculateProjectionViewMtx(MtxF* projectionViewMtx, MtxF* projectionMtx, MtxF* viewMtx) {
    projectionViewMtx->m[0][0] =
        (projectionMtx->m[0][0] * viewMtx->m[0][0]) + (projectionMtx->m[2][0] * viewMtx->m[0][2]);
    projectionViewMtx->m[0][1] =
        (projectionMtx->m[1][1] * viewMtx->m[0][1]) + (projectionMtx->m[2][1] * viewMtx->m[0][2]);
    projectionViewMtx->m[0][2] = projectionMtx->m[2][2] * viewMtx->m[0][2];
    projectionViewMtx->m[0][3] = -viewMtx->m[0][2];
    projectionViewMtx->m[1][0] =
        (projectionMtx->m[0][0] * viewMtx->m[1][0]) + (projectionMtx->m[2][0] * viewMtx->m[1][2]);
    projectionViewMtx->m[1][1] =
        (projectionMtx->m[1][1] * viewMtx->m[1][1]) + (projectionMtx->m[2][1] * viewMtx->m[1][2]);
    projectionViewMtx->m[1][2] = projectionMtx->m[2][2] * viewMtx->m[1][2];
    projectionViewMtx->m[1][3] = -viewMtx->m[1][2];
    projectionViewMtx->m[2][0] =
        (projectionMtx->m[0][0] * viewMtx->m[2][0]) + (projectionMtx->m[2][0] * viewMtx->m[2][2]);
    projectionViewMtx->m[2][1] =
        (projectionMtx->m[1][1] * viewMtx->m[2][1]) + (projectionMtx->m[2][1] * viewMtx->m[2][2]);
    projectionViewMtx->m[2][2] = projectionMtx->m[2][2] * viewMtx->m[2][2];
    projectionViewMtx->m[2][3] = -viewMtx->m[2][2];
    projectionViewMtx->m[3][0] =
        (projectionMtx->m[0][0] * viewMtx->m[3][0]) + (projectionMtx->m[2][0] * viewMtx->m[3][2]);
    projectionViewMtx->m[3][1] =
        (projectionMtx->m[1][1] * viewMtx->m[3][1]) + (projectionMtx->m[2][1] * viewMtx->m[3][2]);
    projectionViewMtx->m[3][2] = (projectionMtx->m[2][2] * viewMtx->m[3][2]) + projectionMtx->m[3][2];
    projectionViewMtx->m[3][3] = -viewMtx->m[3][2];
}

void Camera_MatrixToMtx(MtxF* mtxF, Mtx* mtx2) {
    s32 pad[3];
    s64 longValue;
    f32 temp_fv0;
    s32 i;
    s32 j;
    Mtx* mtx = mtx2;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = mtxF->m[i][j] * 65536.0f;
            if (temp_fv0 < 0.0f) {
                longValue = temp_fv0 - 0.5f;
            } else {
                longValue = temp_fv0 + 0.5f;
            }

            mtx->u.i[i][j] = longValue >> 0x10;
            mtx->u.f[i][j] = longValue & 0xFFFF;
        }
    }
}

void Camera_UpdateProjectionViewMtx(GfxPool* gfxPool, Camera* camera) {
    Vec3f at;
    Vec3f eye;
    f32 var_fv0;
    f32 fov;
    s32 pad[2];

    Matrix_SetFrustrum(&gfxPool->unk_1A008[camera->id], &camera->projectionMtx, camera->fov, camera->near, camera->far,
                       camera->fovScaleX, camera->frustrumCenterX, camera->fovScaleY, camera->frustrumCenterY,
                       &camera->perspectiveScale);
    eye = camera->eye;
    at = camera->at;

    Matrix_SetLookAt(&gfxPool->unk_1A108[camera->id], &camera->viewMtx, eye.x, eye.y, eye.z, at.x, at.y, at.z,
                     camera->basis.y.x, camera->basis.y.y, camera->basis.y.z);
    Camera_CalculateProjectionViewMtx(&camera->projectionViewMtx, &camera->projectionMtx, &camera->viewMtx);
    if (gNumPlayers != 2) {
        var_fv0 = ABS(camera->projectionViewMtx.m[3][1]);

        if (var_fv0 > 30000.0f) {
            var_fv0 -= 30000.0f;
            var_fv0 /= SHT_MAX - 30000.0f;
            if (var_fv0 >= 1.0f) {
                var_fv0 = 1.0f;
            }
            fov = camera->fov + ((85.0f - camera->fov) * var_fv0);

            Matrix_SetFrustrum(&gfxPool->unk_1A008[camera->id], &camera->projectionMtx, fov, camera->near, camera->far,
                               camera->fovScaleX, camera->frustrumCenterX, camera->fovScaleY, camera->frustrumCenterY,
                               &camera->perspectiveScale);
            Camera_CalculateProjectionViewMtx(&camera->projectionViewMtx, &camera->projectionMtx, &camera->viewMtx);
        }
    }
    Camera_MatrixToMtx(&camera->projectionViewMtx, &gfxPool->unk_1A208[camera->id]);
}

extern s32 gNearestRacer;

void func_8071370C(Camera* camera) {
    Racer* racer;
    f32 var_fv1;
    f32 var_fa0;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    racer = &gRacers[gNearestRacer];
    sp20 = racer->segmentPositionInfo.pos.x - camera->eye.x;
    sp1C = racer->segmentPositionInfo.pos.y - camera->eye.y;
    sp18 = racer->segmentPositionInfo.pos.z - camera->eye.z;

    var_fv1 = sqrtf(SQ(sp20) + SQ(sp1C) + SQ(sp18));

    if (var_fv1 != 0.0f) {
        var_fa0 = -((camera->basis.z.x * sp20) + (sp1C * camera->basis.z.y) + (sp18 * camera->basis.z.z)) / var_fv1;
        var_fv1 *= var_fa0;
    }
    if ((var_fv1 >= -1000.0f) && (var_fv1 <= 1000.0f)) {
        Audio_SetEnemyEnginePan(((var_fv1 + 1000.0f) / 2000.0f) * 127.0f);
    }
}

void Camera_NormalizeXYZ(f32* x, f32* y, f32* z) {
    f32 normalizeScale;

    normalizeScale = 1.0f / (SQ(*x) + SQ(*y) + SQ(*z));
    *x *= normalizeScale;
    *y *= normalizeScale;
    *z *= normalizeScale;
}

void Camera_SetAxisRotation(MtxF* mtxF, f32 angle, f32 x, f32 y, f32 z) {
    s32 pad[2];
    f32 temp_fa0;
    f32 temp_ft1;
    f32 cos;
    f32 sp18;
    f32 temp_fv0;
    f32 sin;
    s32 binAngle;

    Camera_NormalizeXYZ(&x, &y, &z);
    binAngle = Math_Round(DEG_TO_FZXANG2(angle));
    sin = SIN(binAngle);
    cos = COS(binAngle);
    temp_fv0 = 1.0f - cos;
    temp_ft1 = x * y * temp_fv0;
    temp_fa0 = y * z * temp_fv0;
    sp18 = z * x * temp_fv0;
    mtxF->m[0][0] = ((1.0f - SQ(x)) * cos) + SQ(x);
    mtxF->m[2][1] = temp_fa0 - (x * sin);
    mtxF->m[1][2] = (x * sin) + temp_fa0;
    mtxF->m[1][1] = ((1.0f - SQ(y)) * cos) + SQ(y);
    mtxF->m[2][0] = (y * sin) + sp18;
    mtxF->m[0][2] = sp18 - (y * sin);
    mtxF->m[2][2] = ((1.0f - SQ(z)) * cos) + SQ(z);
    mtxF->m[1][0] = temp_ft1 - (z * sin);
    mtxF->m[0][1] = (z * sin) + temp_ft1;
    mtxF->m[3][3] = 1.0f;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = mtxF->m[3][0] = mtxF->m[3][1] = mtxF->m[3][2] = 0.0f;
}

void func_80713AC0(unk_800832EC_arg_2* arg0) {
    u32 i;

    for (i = 0; i < arg0->unk_04; i++) {
        arg0->unk_08[i] = 0;
    }
}

u8* func_80713B00(u32 arg0, unk_800832EC_arg_2* arg1) {
    s32 var_v0;
    u32 temp_a2;
    u32 temp_v0;
    s32 var_a0;
    u32 var_a3;

    if ((arg0 % arg1->unk_00) != 0) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    temp_a2 = var_v0 + (arg0 / arg1->unk_00);
    if (arg1->unk_04 < temp_a2) {
        return NULL;
    }

    temp_v0 = (arg1->unk_04 - temp_a2) + 1;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
        for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
            if (arg1->unk_08[var_a0 + var_a3] != 0) {
                break;
            }
        }
        if (var_a3 >= temp_a2) {
            for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
                arg1->unk_08[var_a0 + var_a3] = temp_a2 - var_a3;
            }
            return &arg1->unk_0C[arg1->unk_00 * var_a0];
        }
    }
    return NULL;
}

void func_80713C9C(u8* arg0, unk_800832EC_arg_2* arg1) {
    s32 temp_v1;
    u32 i;
    u32 temp_lo;

    if (arg0 != NULL) {
        temp_lo = (size_t) (arg0 - arg1->unk_0C) / arg1->unk_00;
        temp_v1 = arg1->unk_08[temp_lo];

        for (i = 0; i < temp_v1; i++) {
            arg1->unk_08[temp_lo + i] = 0;
        }
    }
}

u8* func_80713D78(u8* arg0, u32 arg1, unk_800832EC_arg_2* arg2) {
    u8* temp_v0;
    u32 var_a2;
    s32 var_v1;

    temp_v0 = func_80713B00(arg1, arg2);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        return temp_v0;
    }
    var_v1 = arg2->unk_08[(size_t) (arg0 - arg2->unk_0C) / arg2->unk_00];
    var_a2 = arg2->unk_00 * var_v1;
    if (arg1 < var_a2) {
        var_a2 = arg1;
    }

    bcopy(arg0, temp_v0, var_a2);
    func_80713C9C(arg0, arg2);
    return temp_v0;
}

extern s32 gGameMode;
extern GfxPool D_1000000;
extern Camera gCameras[];

Gfx* func_80713E38(Gfx* gfx, s32 scissorBoxType, s32 playerIndex) {
    Camera* camera = &gCameras[playerIndex];

    switch (camera->vpTransitionState) {
        case 1:
            gSPViewport(gfx++, &D_1000000.unk_362C8[playerIndex]);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, camera->currentScissorLeft, camera->currentScissorTop,
                          camera->currentScissorRight, camera->currentScissorBottom);
            break;
        default:
            gfx = func_806F6360(gfx, scissorBoxType);
            if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS)) {
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            }
            break;
    }

    return gfx;
}

void func_80713F8C(s32 cameraId, f32 distance, f32 pitch, f32 yaw) {

    gCameraSettings[cameraId].followSmooth.distance = gCameraSettings[cameraId].followSmooth.targetDistance = distance;
    gCameraSettings[cameraId].followSmooth.pitch = gCameraSettings[cameraId].followSmooth.targetPitch = pitch;
    gCameraSettings[cameraId].followSmooth.yaw = gCameraSettings[cameraId].followSmooth.targetYaw = yaw;
}

void func_80713FD4(unk_800E5D70* arg0, CameraSettings* cameraSettings) {
    arg0->unk_00 = cameraSettings;
}

void func_80713FDC(unk_800E5D70* arg0, unk_struct_20_2* arg1) {
    arg0->unk_0C = arg1;
}

void func_80713FE4(unk_800E5D70* arg0, Vec3f* focusPos, Mtx3F* basis, Racer* racer) {
    arg0->focusPos = focusPos;
    arg0->basis = basis;
    arg0->racer = racer;
}

void func_80713FF4(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

void func_80714000(unk_800E5D70* arg0, unk_struct_C* arg1) {
    arg0->unk_04 = arg1;
    arg0->unk_08 = 0;
}

void func_8071400C(unk_800E5D70* arg0, s32 arg1) {
    func_80715768(arg0->unk_0C, arg1);
}

void func_8071402C(unk_800E5D70* arg0, f32* arg1) {
    arg0->unk_00->parameters.targetFrustrumCenterY = *arg1;
}

bool func_8071403C(unk_800E5D70* arg0) {
    bool ret;
    unk_struct_C* var_s0;

    while (true) {
        ret = false;
        var_s0 = arg0->unk_04;
        if (var_s0 == NULL) {
            return true;
        }

        if (var_s0->unk_04 != NULL) {
            ((void (*)(unk_800E5D70*, void*)) var_s0->unk_04)(arg0, var_s0->unk_08);
        }
        switch (var_s0->unk_00) {
            case 0:
                arg0->unk_04++;
                continue;
            case -1:
                arg0->unk_08 = 0;
                var_s0 = NULL;
                ret = true;
                break;
            case -2:
                arg0->unk_08++;
                ret = true;
                break;
            default:
                if (++arg0->unk_08 >= var_s0->unk_00) {
                    var_s0++;
                    arg0->unk_08 = 0;
                }
                break;
        }
        break;
    }

    arg0->unk_04 = var_s0;
    return ret;
}

void func_80714130(unk_800E5D70* arg0, CameraAtEyeData* arg1) {
    Camera_SettingsSetAtEyeWithParameters(arg0->unk_00, arg1);
}

void func_80714150(unk_800E5D70* arg0, CameraOrbitData* arg1) {
    Camera_SettingsSetOrbitWithParameters(arg0->unk_00, CAMERA_TYPE_ORBIT_AT, arg1);
}

void func_80714178(unk_800E5D70* arg0, CameraOrbitData* arg1) {
    Camera_SettingsSetOrbitWithParameters(arg0->unk_00, CAMERA_TYPE_ORBIT_EYE, arg1);
}

void func_807141A0(unk_800E5D70* arg0, CameraFollowSmoothData* arg1) {
    Camera_SettingsSetFollowSmoothWithParameters(arg0->unk_00, arg1);
}

void func_807141C0(unk_800E5D70* arg0, CameraLocalAnchorData* arg1) {
    Camera_SettingsSetLocalAnchorWithParameters(arg0->unk_00, arg1);
}

void func_80083754(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80715E1C(sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38[0].x + arg0->focusPos->x;
    sp2C.y = sp38[0].y + arg0->focusPos->y;
    sp2C.z = sp38[0].z + arg0->focusPos->z;
    func_80712B34(arg0->unk_00, &sp2C, &sp38[1], NULL, NULL);
}

void func_80714268(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp34[3];
    Vec3f sp28;

    func_80715E60(sp34, arg0->unk_0C, arg1);
    sp28.x = sp34[0].x + arg0->focusPos->x;
    sp28.y = sp34[0].y + arg0->focusPos->y;
    sp28.z = sp34[0].z + arg0->focusPos->z;
    func_80712B34(arg0->unk_00, &sp28, &sp34[1], &sp34[2], NULL);
}

void func_807142F0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80715EC0(&sp34, arg0->unk_0C, arg1);
    sp28.x = sp34.unk_00[0].x + arg0->focusPos->x;
    sp28.y = sp34.unk_00[0].y + arg0->focusPos->y;
    sp28.z = sp34.unk_00[0].z + arg0->focusPos->z;
    func_80712B34(arg0->unk_00, &sp28, &sp34.unk_00[1], NULL, &sp34.unk_18);
}

void func_8071437C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80715F20(&sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38.unk_00[0].x + arg0->focusPos->x;
    sp2C.y = sp38.unk_00[0].y + arg0->focusPos->y;
    sp2C.z = sp38.unk_00[0].z + arg0->focusPos->z;
    func_80712B34(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80714408(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp48[2];
    Vec3f sp3C;
    Vec3f sp30;

    func_80715E1C(sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48[0].x + arg0->focusPos->x;
    sp3C.y = sp48[0].y + arg0->focusPos->y;
    sp3C.z = sp48[0].z + arg0->focusPos->z;

    sp30.x =
        arg0->unk_1C->x + arg0->unk_20->x.x * sp48[1].z + arg0->unk_20->y.x * sp48[1].y + arg0->unk_20->z.x * sp48[1].x;
    sp30.y =
        arg0->unk_1C->y + arg0->unk_20->x.y * sp48[1].z + arg0->unk_20->y.y * sp48[1].y + arg0->unk_20->z.y * sp48[1].x;
    sp30.z =
        arg0->unk_1C->z + arg0->unk_20->x.z * sp48[1].z + arg0->unk_20->y.z * sp48[1].y + arg0->unk_20->z.z * sp48[1].x;
    func_80712B34(arg0->unk_00, &sp3C, &sp30, NULL, NULL);
}

void func_80714538(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp44[3];
    Vec3f sp38;
    Vec3f sp2C;

    func_80715E60(sp44, arg0->unk_0C, arg1);
    sp38.x = sp44[0].x + arg0->focusPos->x;
    sp38.y = sp44[0].y + arg0->focusPos->y;
    sp38.z = sp44[0].z + arg0->focusPos->z;

    sp2C.x =
        arg0->unk_1C->x + arg0->unk_20->x.x * sp44[1].z + arg0->unk_20->y.x * sp44[1].y + arg0->unk_20->z.x * sp44[1].x;
    sp2C.y =
        arg0->unk_1C->y + arg0->unk_20->x.y * sp44[1].z + arg0->unk_20->y.y * sp44[1].y + arg0->unk_20->z.y * sp44[1].x;
    sp2C.z =
        arg0->unk_1C->z + arg0->unk_20->x.z * sp44[1].z + arg0->unk_20->y.z * sp44[1].y + arg0->unk_20->z.z * sp44[1].x;
    func_80712B34(arg0->unk_00, &sp38, &sp2C, &sp44[2], NULL);
}

void func_80714668(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp44;
    Vec3f sp38;
    Vec3f sp2C;

    func_80715EC0(&sp44, arg0->unk_0C, arg1);
    sp38.x = sp44.unk_00[0].x + arg0->focusPos->x;
    sp38.y = sp44.unk_00[0].y + arg0->focusPos->y;
    sp38.z = sp44.unk_00[0].z + arg0->focusPos->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->x.x * sp44.unk_00[1].z + arg0->unk_20->y.x * sp44.unk_00[1].y +
             arg0->unk_20->z.x * sp44.unk_00[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->x.y * sp44.unk_00[1].z + arg0->unk_20->y.y * sp44.unk_00[1].y +
             arg0->unk_20->z.y * sp44.unk_00[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->x.z * sp44.unk_00[1].z + arg0->unk_20->y.z * sp44.unk_00[1].y +
             arg0->unk_20->z.z * sp44.unk_00[1].x;
    func_80712B34(arg0->unk_00, &sp38, &sp2C, NULL, &sp44.unk_18);
}

void func_8071479C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp48;
    Vec3f sp3C;
    Vec3f sp30;

    func_80715F20(&sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48.unk_00[0].x + arg0->focusPos->x;
    sp3C.y = sp48.unk_00[0].y + arg0->focusPos->y;
    sp3C.z = sp48.unk_00[0].z + arg0->focusPos->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->x.x * sp48.unk_00[1].z + arg0->unk_20->y.x * sp48.unk_00[1].y +
             arg0->unk_20->z.x * sp48.unk_00[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->x.y * sp48.unk_00[1].z + arg0->unk_20->y.y * sp48.unk_00[1].y +
             arg0->unk_20->z.y * sp48.unk_00[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->x.z * sp48.unk_00[1].z + arg0->unk_20->y.z * sp48.unk_00[1].y +
             arg0->unk_20->z.z * sp48.unk_00[1].x;
    func_80712B34(arg0->unk_00, &sp3C, &sp30, &sp48.unk_00[2], &sp48.unk_24);
}

void func_807148D0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_8071491C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80714968(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_807149B8(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714A08(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80714A54(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80714AA0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80714AF0(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714B40(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20[1], &sp20[0], NULL, NULL);
}

void func_80714B8C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24[1], &sp24[0], &sp24[2], NULL);
}

void func_80714BD8(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24.unk_00[1], &sp24.unk_00[0], NULL, &sp24.unk_18);
}

void func_80714C28(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20.unk_00[1], &sp20.unk_00[0], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714C78(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    Vec3f sp3C[2];
    Vec3f sp30;
    s32 pad;

    func_80715E1C(sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp3C[0].x;
    sp30.x = COS(sp64) * temp_fv0 + arg0->focusPos->x;
    sp30.y = sp3C[0].x * SIN(temp_v0) + arg0->focusPos->y;
    sp30.z = arg0->focusPos->z - SIN(sp64) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp30, &sp3C[1], NULL, NULL);
}

void func_80714D90(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp6C;
    s32 temp_v0;
    f32 sp64;
    f32 sp60;
    f32 temp_fv0;
    Vec3f sp38[3];
    Vec3f sp2C;
    s32 pad;

    func_80715E60(sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp6C = Math_Round(DEG_TO_FZXANG2(sp64));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp60));
    temp_fv0 = COS(temp_v0) * sp38[0].x;
    sp2C.x = COS(sp6C) * temp_fv0 + arg0->focusPos->x;
    sp2C.y = sp38[0].x * SIN(temp_v0) + arg0->focusPos->y;
    sp2C.z = arg0->focusPos->z - SIN(sp6C) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp2C, &sp38[1], &sp38[2], NULL);
}

void func_80714EA8(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    unk_80085434_arg_0 sp38;
    Vec3f sp2C;
    s32 pad;

    func_80715EC0(&sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp38.unk_00[0].x;
    sp2C.x = COS(sp64) * temp_fv0 + arg0->focusPos->x;
    sp2C.y = sp38.unk_00[0].x * SIN(temp_v0) + arg0->focusPos->y;
    sp2C.z = arg0->focusPos->z - SIN(sp64) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp2C, &sp38.unk_00[1], NULL, &sp38.unk_18);
}

void func_80714FC4(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 sp74;
    s32 temp_v0;
    f32 sp6C;
    f32 sp68;
    f32 temp_fv0;
    unk_80085494_arg_0 sp3C;
    Vec3f sp30;
    s32 pad;

    func_80715F20(&sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp74 = Math_Round(DEG_TO_FZXANG2(sp6C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp68));
    temp_fv0 = COS(temp_v0) * sp3C.unk_00[0].x;
    sp30.x = COS(sp74) * temp_fv0 + arg0->focusPos->x;
    sp30.y = sp3C.unk_00[0].x * SIN(temp_v0) + arg0->focusPos->y;
    sp30.z = arg0->focusPos->z - SIN(sp74) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp30, &sp3C.unk_00[1], &sp3C.unk_00[2], &sp3C.unk_24);
}

void func_807150E0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    Vec3f sp64[2];
    Vec3f sp58;
    Mtx3F sp34;

    func_80715E1C(sp64, arg0->unk_0C, arg1->unk_00);
    sp58.x = arg0->focusPos->x;
    sp58.y = arg0->focusPos->y;
    sp58.z = arg0->focusPos->z;
    sp34 = *arg0->basis;
    func_80712C44(arg0->unk_00, &sp58, &sp34, &sp64[0], &sp64[1], NULL, NULL);
}

void func_8071518C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    Vec3f sp60[3];
    Vec3f sp54;
    Mtx3F sp30;

    func_80715E60(sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->focusPos->x;
    sp54.y = arg0->focusPos->y;
    sp54.z = arg0->focusPos->z;
    sp30 = *arg0->basis;
    func_80712C44(arg0->unk_00, &sp54, &sp30, &sp60[0], &sp60[1], &sp60[2], NULL);
}

void func_8071523C(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    unk_80085434_arg_0 sp60;
    Vec3f sp54;
    Mtx3F sp30;

    func_80715EC0(&sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->focusPos->x;
    sp54.y = arg0->focusPos->y;
    sp54.z = arg0->focusPos->z;
    sp30 = *arg0->basis;
    func_80712C44(arg0->unk_00, &sp54, &sp30, &sp60.unk_00[0], &sp60.unk_00[1], NULL, &sp60.unk_18);
}

void func_807152EC(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad;
    unk_80085494_arg_0 sp64;
    Vec3f sp58;
    Mtx3F sp34;

    func_80715F20(&sp64, arg0->unk_0C, arg1);
    sp58.x = arg0->focusPos->x;
    sp58.y = arg0->focusPos->y;
    sp58.z = arg0->focusPos->z;
    sp34 = *arg0->basis;
    func_80712C44(arg0->unk_00, &sp58, &sp34, &sp64.unk_00[0], &sp64.unk_00[1], &sp64.unk_00[2], &sp64.unk_24);
}

void func_807153A0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80715E1C(sp38, arg0->unk_0C, arg1);
    racer = arg0->racer;
    followSmooth = &arg0->unk_00->followSmooth;
    followSmooth->racerBasis = *arg0->basis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    sp2C.x = sp38[0].x + arg0->focusPos->x;
    sp2C.y = sp38[0].y + arg0->focusPos->y;
    sp2C.z = sp38[0].z + arg0->focusPos->z;

    func_80712DE0(arg0->unk_00, &sp2C, &sp38[1], NULL, NULL);
}

void func_80715490(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    Vec3f sp34[3];
    Vec3f sp28;

    func_80715E60(sp34, arg0->unk_0C, arg1);
    racer = arg0->racer;
    followSmooth = &arg0->unk_00->followSmooth;
    followSmooth->racerBasis = *arg0->basis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    sp28.x = sp34[0].x + arg0->focusPos->x;
    sp28.y = sp34[0].y + arg0->focusPos->y;
    sp28.z = sp34[0].z + arg0->focusPos->z;

    func_80712DE0(arg0->unk_00, &sp28, &sp34[1], &sp34[2], NULL);
}

void func_80715580(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad[6];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80715EC0(&sp34, arg0->unk_0C, arg1);
    racer = arg0->racer;
    followSmooth = &arg0->unk_00->followSmooth;
    followSmooth->racerBasis = *arg0->basis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    sp28.x = sp34.unk_00[0].x + arg0->focusPos->x;
    sp28.y = sp34.unk_00[0].y + arg0->focusPos->y;
    sp28.z = sp34.unk_00[0].z + arg0->focusPos->z;

    func_80712DE0(arg0->unk_00, &sp28, &sp34.unk_00[1], NULL, &sp34.unk_18);
}

void func_80715674(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad[4];
    CameraTypeFollowSmooth* followSmooth;
    Racer* racer;
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80715F20(&sp38, arg0->unk_0C, arg1);
    racer = arg0->racer;
    followSmooth = &arg0->unk_00->followSmooth;
    followSmooth->racerBasis = *arg0->basis;
    followSmooth->tiltUp = racer->tiltUp;
    followSmooth->speed = racer->speed;
    followSmooth->trackSegmentInfo = racer->segmentPositionInfo.courseSegment->trackSegmentInfo;
    sp2C.x = sp38.unk_00[0].x + arg0->focusPos->x;
    sp2C.y = sp38.unk_00[0].y + arg0->focusPos->y;
    sp2C.z = sp38.unk_00[0].z + arg0->focusPos->z;

    func_80712DE0(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80715768(unk_struct_20_2* arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0->unk_00[i].unk_04 = 0;
        arg0->unk_00[i].unk_00 = 0;
    }
}

f32 func_807157DC(f32 arg0, s32 arg1, f32* arg2, s32 arg3) {
    s32 pad[2];
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    if (arg1 == 0) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0);
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (arg0 * 3.0f);
        spC = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == 1) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0) / 4.0f;
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (arg0 / 4.0f) + 7.0f / 12.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if ((arg3 < 7) || (arg1 < (arg3 - 5))) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = temp_fv1 * arg0;
        sp4 = CB(temp_fv0) / 6.0f;
        sp8 = ((temp_fa1 / 2.0f) - temp_fv1) + 2.0f / 3.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == arg3 - 5) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (temp_fv0 / 2.0f) + 1.0f / 6.0f;
        spC = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (temp_fv0 / 4.0f) + 7.0f / 12.0f;
        sp10 = CB(arg0) / 4.0f;
    } else if (arg1 == arg3 - 4) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        spC = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (temp_fv0 * 3.0f);
        sp10 = CB(arg0);
    }

    return sp4 * arg2[arg1] + sp8 * arg2[arg1 + 1] + spC * arg2[arg1 + 2] + sp10 * arg2[arg1 + 3];
}

void func_80715BE0(f32* arg0, unk_struct_8* arg1, unk_80085154_arg_2* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;

    while (arg2->unk_08[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    *arg0 =
        func_807157DC((f32) arg1->unk_00 / (f32) arg2->unk_08[arg1->unk_04], arg1->unk_04, arg2->unk_04, arg2->unk_00);

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_08[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80715CD8(Vec3f* arg0, unk_struct_8* arg1, unk_struct_14* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;
    s32 i;

    while (arg2->unk_10[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    for (i = 0; i < 3; i++) {
        arg0->v[i] = func_807157DC((f32) arg1->unk_00 / (f32) arg2->unk_10[arg1->unk_04], arg1->unk_04, arg2->unk_04[i],
                                   arg2->unk_00);
    }

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_10[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80715E1C(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_80715CD8(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_80715CD8(&arg0[1], &arg1->unk_00[1], &arg2[1]);
}

void func_80715E60(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_80715CD8(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_80715CD8(&arg0[1], &arg1->unk_00[1], &arg2[1]);
    func_80715CD8(&arg0[2], &arg1->unk_00[2], &arg2[2]);
}

void func_80715EC0(unk_80085434_arg_0* arg0, unk_struct_20_2* arg1, unk_80085434_arg_2* arg2) {
    func_80715CD8(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_80715CD8(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_80715BE0(&arg0->unk_18, &arg1->unk_00[2], &arg2->unk_28);
}

void func_80715F20(unk_80085494_arg_0* arg0, unk_struct_20_2* arg1, unk_80085494_arg_2* arg2) {
    func_80715CD8(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_80715CD8(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_80715CD8(&arg0->unk_00[2], &arg1->unk_00[2], &arg2->unk_00[2]);
    func_80715BE0(&arg0->unk_24, &arg1->unk_00[3], &arg2->unk_3C);
}

void func_80715F9C(void) {
    unk_800E5D70* var_s1;
    s32 i;
    Racer* racer;
    Camera* camera;
    unk_struct_20_2* var_s4;
    CameraSettings* cameraSettings;

    for (i = 0, camera = gCameras, var_s1 = D_807A1480, cameraSettings = gCameraSettings, var_s4 = D_807A1510; i < 4;
         i++) {
        camera->id = (s16) i;
        camera->raceSetting = CAMERA_RACE_SETTING_REGULAR;
        camera->vpTransitionState = 0;
        func_80713FD4(var_s1, cameraSettings);
        func_80713FDC(var_s1, var_s4);
        racer = &gRacers[camera->id];
        func_80713FE4(var_s1, &racer->focusPos, &racer->trueBasis, racer);

        var_s1++;
        cameraSettings++;
        var_s4++;
        camera++;
    }
    D_807A159A = 1;
}

extern s8 gTitleDemoState;

void Camera_Init(void) {
    s32 i;
    Camera* camera;
    Racer* racer;

    D_807A1594 = 0;

    for (i = 0, camera = gCameras; i < 4; i++, camera++) {
        racer = &gRacers[camera->id];
        func_80713FE4(&D_807A1480[i], &racer->focusPos, &racer->trueBasis, racer);
    }
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_TITLE;
            Camera_InitMode(gCameras, gCameraSettings, D_807A1480);
            break;
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_MACHINE_SELECT_CREATE;
            Camera_InitMode(gCameras, gCameraSettings, D_807A1480);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_MACHINE_SETTINGS;
            Camera_InitMode(gCameras, gCameraSettings, D_807A1480);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_COURSE_SELECT;
            Camera_InitMode(gCameras, gCameraSettings, D_807A1480);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
            D_8076D6C0 = -1;
            sNumCameras = gNumPlayers;
            for (i = 0; i < sNumCameras; i++) {
                if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                    gCameras[i].mode = CAMERA_MODE_TITLE_DEMO;
                } else {
                    gCameras[i].mode = CAMERA_MODE_RACE_INTRO;
                }

                gCameras[i].focusPos = gRacers[i].segmentPositionInfo.pos;

                gCameras[i].racerBasis = gRacers[i].trueBasis;

                Camera_InitMode(&gCameras[i], &gCameraSettings[i], &D_807A1480[i]);
            }

            break;
        case GAMEMODE_TIME_ATTACK:
            D_8076D6C0 = -1;
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                sNumCameras = 1;
                gCameras[0].mode = CAMERA_MODE_TITLE_DEMO;
            } else {
                sNumCameras = 2;
                gCameras[0].mode = CAMERA_MODE_RACE_INTRO;
            }
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;
            gCameras[1].mode = CAMERA_MODE_RECORDS_ENTRY;
            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &gCameraSettings[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_COURSE_EDIT:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_RACE;
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;

            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &gCameraSettings[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_RECORDS:
            sNumCameras = 2;
            gCameras[0].mode = CAMERA_MODE_RECORDS_RACE;
            gCameras[0].focusPos = gRacers[0].segmentPositionInfo.pos;
            gCameras[0].racerBasis = gRacers[0].trueBasis;
            gCameras[1].mode = CAMERA_MODE_RECORDS_ENTRY;
            for (i = 0; i < sNumCameras; i++) {
                Camera_InitMode(&gCameras[i], &gCameraSettings[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_GP_END_CS:
            sNumCameras = 1;
            gCameras[0].mode = CAMERA_MODE_ENDING;
            Camera_InitMode(gCameras, gCameraSettings, D_807A1480);
            break;
    }
}

extern s16 gPlayer1OverallPosition;

void Camera_InitMode(Camera* camera, CameraSettings* arg1, unk_800E5D70* arg2) {
    s32 pad;
    s32 sp48;
    bool sp44;
    f32 angle;
    s32 pad2;
    unk_80776A48* sp38;
    Vec3f sp2C;
    Racer* racer;

    camera->lookBackRotate = 0;
    camera->state = 0;
    camera->timer = 0;
    sp44 = false;

    switch (camera->mode) {
        case CAMERA_MODE_MACHINE_SELECT_CREATE:
        case CAMERA_MODE_RECORDS_ENTRY:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(arg1, CAMERA_TYPE_ORBIT_AT, &D_807766A8);
            break;
        case CAMERA_MODE_MACHINE_SETTINGS:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(arg1, CAMERA_TYPE_ORBIT_AT, &D_80776754);
            if (gNumPlayers >= 2) {
                arg1->orbit.yaw = arg1->orbit.targetYaw = 30.0f;
            }
            break;
        case CAMERA_MODE_COURSE_SELECT:
            camera->near = 16.0f;
            camera->far = 16384.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(arg1, CAMERA_TYPE_ORBIT_AT, &D_80776800);
            break;
        case CAMERA_MODE_RACE_INTRO:
            Camera_SettingsSetOrbitWithParameters(arg1, CAMERA_TYPE_ORBIT_AT, &D_8077699C);
            if (gNumPlayers == 2) {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                arg1->parameters.frustrumCenterY = arg1->parameters.targetFrustrumCenterY = -15.0f;
                arg1->parameters.fov = arg1->parameters.targetFov = 100.0f;
            } else {
                camera->near = 16.0f;
                camera->far = 8192.0f;
            }
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            sp44 = true;
            break;
        case CAMERA_MODE_RACE:
        case CAMERA_MODE_TITLE_DEMO:
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                sp48 = CAMERA_RACE_SETTING_REGULAR;
            } else {
                sp48 = camera->raceSetting;
            }
            if (gNumPlayers == 2) {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                camera->fovScaleX = SCREEN_WIDTH;
                camera->fovScaleY = SCREEN_HEIGHT;

                Camera_SettingsSetFollowSmoothWithParameters(arg1, &D_80776B9C);

                sp38 = &D_80776A78[sp48];
            } else {
                camera->near = 16.0f;
                camera->far = 8192.0f;
                camera->fovScaleX = SCREEN_WIDTH;
                camera->fovScaleY = SCREEN_HEIGHT;

                Camera_SettingsSetFollowSmoothWithParameters(arg1, &D_80776AA8);

                sp38 = &D_80776A48[sp48];
            }
            arg1->followSmooth.targetDistance = arg1->followSmooth.distance = sp38->distance;
            arg1->followSmooth.targetPitch = arg1->followSmooth.pitch = sp38->pitch;
            arg1->parameters.targetFov = arg1->parameters.fov = sp38->fov;

            Math_Round(DEG_TO_FZXANG2(arg1->followSmooth.pitch));
            racer = &gRacers[camera->id];
            arg1->followSmooth.anchorPoint.x = racer->focusPos.x - (sp38->distance * racer->trueBasis.x.x);
            arg1->followSmooth.anchorPoint.y = racer->focusPos.y - (sp38->distance * racer->trueBasis.x.y);
            arg1->followSmooth.anchorPoint.z = racer->focusPos.z - (sp38->distance * racer->trueBasis.x.z);
            camera->targetFov = arg1->parameters.targetFov;
            camera->fovFlags = 0;
            if ((sp48 == CAMERA_RACE_SETTING_CLOSE_BEHIND) || (sp48 == CAMERA_RACE_SETTING_REGULAR)) {
                camera->fovFlags |= CAMERA_FOV_FLAG_1;
            }
            sp44 = true;
            break;
        case CAMERA_MODE_FALLING_OFF_TRACK:
            sp2C = arg1->parameters.eye;
            Camera_SettingsSetAtEyeWithParameters(arg1, &D_807763D0);
            arg1->parameters.fov = arg1->parameters.targetFov = 80.0f;
            arg1->atEye.targetEye = sp2C;
            if (gNumPlayers == 2) {
                arg1->parameters.frustrumCenterY = arg1->parameters.targetFrustrumCenterY = -50.0f;
            }
            break;
        case CAMERA_MODE_FINISHED_SUCCESS:
            Camera_SettingsSetAtEyeWithParameters(arg1, &D_807763D0);
            arg1->parameters.targetFov = D_8076D788[0].fov;
            if (gNumPlayers == 2) {
                arg1->parameters.frustrumCenterY = arg1->parameters.targetFrustrumCenterY = -30.0f;
            }

            racer = &gRacers[camera->id];
            func_80718F58(&D_807A15A0[camera->id], racer->segmentPositionInfo.courseSegment,
                          racer->segmentPositionInfo.segmentTValue, &D_8076D788[0]);
            break;
        case CAMERA_MODE_FINISHED_SPECTATE:
            racer = &gRacers[camera->id];

            Camera_SettingsSetOrbitWithParameters(arg1, 2, &D_80776448);
            if (gNumPlayers == 2) {
                arg1->parameters.frustrumCenterY = arg1->parameters.targetFrustrumCenterY = -30.0f;
            }
            arg1->parameters.fov = arg1->parameters.targetFov = 80.0f;
            arg1->orbit.distance = arg1->orbit.targetDistance = 125.0f;
            arg1->orbit.pitch = arg1->orbit.targetPitch = 35.0f;
            arg1->orbit.yaw = arg1->orbit.targetYaw = -50.0f;

            arg1->orbit.basis = racer->trueBasis;

            arg1->orbit.basis.y.x = racer->tiltUp.x;
            arg1->orbit.basis.y.y = racer->tiltUp.y;
            arg1->orbit.basis.y.z = racer->tiltUp.z;
            break;
        case CAMERA_MODE_FINISHED_LOSER:
            sp2C = arg1->parameters.eye;
            Camera_SettingsSetAtEyeWithParameters(arg1, &D_807763D0);
            arg1->parameters.fov = arg1->parameters.targetFov = 80.0f;
            arg1->atEye.targetEye = sp2C;
            break;
        case CAMERA_MODE_RECORDS_RACE:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetFollowSmoothWithParameters(arg1, &D_80776AA8);
            sp38 = &D_80776A48[1];
            arg1->followSmooth.targetDistance = arg1->followSmooth.distance = sp38->distance;
            arg1->followSmooth.targetPitch = arg1->followSmooth.pitch = 15.0f;
            arg1->parameters.targetFov = arg1->parameters.fov = sp38->fov;
            angle = 15.0f;
            Math_Round(DEG_TO_FZXANG2(angle));
            racer = &gRacers[0];
            arg1->followSmooth.anchorPoint.x = racer->focusPos.x - (sp38->distance * racer->trueBasis.x.x);
            arg1->followSmooth.anchorPoint.y = racer->focusPos.y - (sp38->distance * racer->trueBasis.x.y);
            arg1->followSmooth.anchorPoint.z = racer->focusPos.z - (sp38->distance * racer->trueBasis.x.z);
            camera->targetFov = arg1->parameters.targetFov;
            camera->fovFlags = 0;
            sp44 = true;
            break;
        case CAMERA_MODE_13:
            camera->near = 512.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetAtEyeWithParameters(arg1, &D_807768AC);
            break;
        case CAMERA_MODE_ENDING:
            camera->near = 16.0f;
            camera->far = 8192.0f;
            camera->fovScaleX = SCREEN_WIDTH;
            camera->fovScaleY = SCREEN_HEIGHT;
            Camera_SettingsSetOrbitWithParameters(arg1, CAMERA_TYPE_ORBIT_EYE, &D_80776448);
            arg1->orbit.anchorPos.x = 196.0f;
            arg1->orbit.anchorPos.y = 25.0f;
            arg1->orbit.anchorPos.z = -3000.0f;
            arg1->orbit.distance = arg1->orbit.targetDistance = 258.0f;
            arg1->orbit.pitch = arg1->orbit.targetPitch = -7.0f;
            arg1->orbit.yaw = arg1->orbit.targetYaw = 269.0f;
            sp44 = true;
            if (gPlayer1OverallPosition < 4) {
                sCameraEndingFocusRacer = gPlayer1OverallPosition - 1;
            } else {
                sCameraEndingFocusRacer = 0;
            }
            break;
    }
    if (sp44) {
        camera->vpTransitionState = 0;
        camera->transitionTimer = camera->transitionTime = 0;
        func_80716F38(camera);
    }
}

extern s32 sNumCameras;

void func_80716F38(Camera* camera) {
    s32* scissorBoxTypes = sCameraScissorBoxTypes[sNumCameras];
    s32 scissorBoxType = scissorBoxTypes[camera->id];
    Vp* vp;
    ScissorBox* scissorBox;

    switch (scissorBoxType) {
        case SCISSOR_BOX_FULL_SCREEN:
            vp = Segment_SegmentedToVirtual(&aVpFullScreen);
            scissorBox = &gScissorBoxFullScreen;
            break;
        case SCISSOR_BOX_TOP_HALF:
            vp = Segment_SegmentedToVirtual(&aVpTopHalf);
            scissorBox = &gScissorBoxTopHalf;
            break;
        case SCISSOR_BOX_BOTTOM_HALF:
            vp = Segment_SegmentedToVirtual(&aVpBottomHalf);
            scissorBox = &gScissorBoxBottomHalf;
            break;
        case SCISSOR_BOX_LEFT_HALF:
            vp = Segment_SegmentedToVirtual(&aVpLeftHalf);
            scissorBox = &gScissorBoxLeftHalf;
            break;
        case SCISSOR_BOX_RIGHT_HALF:
            vp = Segment_SegmentedToVirtual(&aVpRightHalf);
            scissorBox = &gScissorBoxRightHalf;
            break;
        case SCISSOR_BOX_TOP_LEFT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopLeftQuarter);
            scissorBox = &gScissorBoxTopLeftQuarter;
            break;
        case SCISSOR_BOX_TOP_RIGHT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopRightQuarter);
            scissorBox = &gScissorBoxTopRightQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_LEFT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomLeftQuarter);
            scissorBox = &gScissorBoxBottomLeftQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_RIGHT_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomRightQuarter);
            scissorBox = &gScissorBoxBottomRightQuarter;
            break;
        case SCISSOR_BOX_TOP_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpTopCenterQuarter);
            scissorBox = &gScissorBoxTopCenterQuarter;
            break;
        case SCISSOR_BOX_BOTTOM_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpBottomCenterQuarter);
            scissorBox = &gScissorBoxBottomCenterQuarter;
            break;
        case SCISSOR_BOX_LEFT_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpLeftCenterQuarter);
            scissorBox = &gScissorBoxLeftCenterQuarter;
            break;
        case SCISSOR_BOX_RIGHT_CENTER_QUARTER:
            vp = Segment_SegmentedToVirtual(&aVpRightCenterQuarter);
            scissorBox = &gScissorBoxRightCenterQuarter;
            break;
    }

    camera->currentVpScaleX = camera->startVpScaleX = camera->endVpScaleX = vp->vp.vscale[0] * 0.25f;
    camera->currentVpScaleY = camera->startVpScaleY = camera->endVpScaleY = vp->vp.vscale[1] * 0.25f;

    camera->currentVpTransX = vp->vp.vtrans[0] * 0.25f;
    camera->currentVpTransY = vp->vp.vtrans[1] * 0.25f;

    camera->startVpTransX = camera->endVpTransX = camera->currentVpTransX - camera->currentVpScaleX;
    camera->startVpTransY = camera->endVpTransY = camera->currentVpTransY - camera->currentVpScaleY;

    camera->currentScissorLeft = camera->startScissorLeft = camera->endScissorLeft = scissorBox->left;
    camera->currentScissorTop = camera->startScissorTop = camera->endScissorTop = scissorBox->top;
    camera->currentScissorRight = camera->startScissorRight = camera->endScissorRight = scissorBox->right;
    camera->currentScissorBottom = camera->startScissorBottom = camera->endScissorBottom = scissorBox->bottom;
}

void Camera_Update(void) {
    s32 i;

    for (i = 0; i < sNumCameras; i++) {
        Camera_UpdateMode(&gCameras[i], &gCameraSettings[i], &D_807A1480[i]);
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P)) {
        func_80717B20();
    }
}

extern GfxPool* gGfxPool;

void Camera_UpdateMode(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 diff;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    bool cameraReadyForRace;
    u32 startMode;
    u32 mode;

    do {
        startMode = mode = camera->mode;
        switch (mode) {
            case CAMERA_MODE_TITLE:
            case CAMERA_MODE_MACHINE_SELECT_CREATE:
            case CAMERA_MODE_MACHINE_SETTINGS:
            case CAMERA_MODE_16:
                break;
            case CAMERA_MODE_COURSE_SELECT:
                Camera_UpdateCourseSelect(camera, cameraSettings);
                break;
            case CAMERA_MODE_RACE_INTRO:
                if (!gGamePaused) {
                    Camera_UpdateRaceIntro(camera, cameraSettings);
                }
                break;
            case CAMERA_MODE_SETUP_RACE:

                cameraReadyForRace = true;

                diff = cameraSettings->parameters.targetFov - cameraSettings->parameters.fov;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->parameters.targetFrustrumCenterY - cameraSettings->parameters.frustrumCenterY;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->followSmooth.targetDistance - cameraSettings->followSmooth.distance;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                diff = cameraSettings->followSmooth.targetPitch - cameraSettings->followSmooth.pitch;
                if (ABS(diff) > 0.5f) {
                    cameraReadyForRace = false;
                }

                if (cameraReadyForRace) {
                    camera->mode = CAMERA_MODE_RACE;
                    cameraSettings->parameters.fovLerpFactor = 0.2f;
                    cameraSettings->parameters.upLerpFactor = 1.0f;
                    cameraSettings->parameters.frustrumCenterXLerpFactor = 0.1f;
                    cameraSettings->parameters.frustrumCenterYLerpFactor = 0.2f;
                    cameraSettings->followSmooth.distanceLerpFactor = 0.2f;
                    cameraSettings->followSmooth.pitchLerpFactor = 0.2f;
                }
                break;
            case CAMERA_MODE_RACE:
                Camera_UpdateRace(camera, cameraSettings, arg2);
                break;
            case CAMERA_MODE_TITLE_DEMO:
                Camera_UpdateTitleDemo(camera, cameraSettings, arg2);
                break;
            case CAMERA_MODE_FALLING_OFF_TRACK:
                if (!gGamePaused) {
                    Camera_UpdateFallingOffTrack(camera, cameraSettings);
                }
                break;
            case CAMERA_MODE_FINISHED_SUCCESS:
                if (!gGamePaused) {
                    Camera_UpdateFinishedSuccess(camera, cameraSettings, arg2);
                }
                break;
            case CAMERA_MODE_FINISHED_SPECTATE:
                if (!gGamePaused) {
                    Camera_UpdateFinishedSpectate(camera, cameraSettings, arg2);
                }
                break;
            case CAMERA_MODE_FINISHED_LOSER:
                if (!gGamePaused) {
                    Camera_UpdateFinishedLoser(camera, cameraSettings, arg2);
                }
                break;
            case CAMERA_MODE_RECORDS_RACE:
                Camera_UpdateRecordsRace(camera, cameraSettings, arg2);
                break;
            case CAMERA_MODE_ENDING:
                Camera_UpdateEnding(camera, cameraSettings, arg2);
                break;
        }
        mode = camera->mode;
    } while (startMode != mode);

    Camera_SettingsUpdate(cameraSettings, camera);
    func_807176B4(camera, cameraSettings);
    func_807130F8(camera, cameraSettings);
    func_8071315C(camera);
    Camera_UpdateProjectionViewMtx(gGfxPool, camera);
    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_TIME_ATTACK) ||
        (gGameMode == GAMEMODE_DEATH_RACE)) {
        func_8071370C(camera);
    }
}

void func_807176B4(Camera* camera, CameraSettings* cameraSettings) {
    unk_80776A48* var_s1;
    s32 angle;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    Mtx3F sp48;
    f32 temp_fv0;
    f32 temp_fv1;
    CameraParameters* temp_v1 = &cameraSettings->parameters;
    Racer* racer;

    if (camera->mode == CAMERA_MODE_RACE_INTRO) {
        if (gNumPlayers == 2) {
            var_s1 = &D_80776A78[2];
        } else {
            var_s1 = &D_80776A48[2];
        }

        racer = &gRacers[camera->id];

        sp48.x.x = 0.0f - (var_s1->distance * racer->trueBasis.x.x);
        sp48.x.y = 0.0f - (var_s1->distance * racer->trueBasis.x.y);
        sp48.x.z = 0.0f - (var_s1->distance * racer->trueBasis.x.z);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.x.x) + SQ(sp48.x.y) + SQ(sp48.x.z));
        sp48.x.x *= temp_fv1;
        sp48.x.y *= temp_fv1;
        sp48.x.z *= temp_fv1;

        sp48.z.x = (racer->trueBasis.y.y * sp48.x.z) - (racer->trueBasis.y.z * sp48.x.y);
        sp48.z.y = (racer->trueBasis.y.z * sp48.x.x) - (racer->trueBasis.y.x * sp48.x.z);
        sp48.z.z = (racer->trueBasis.y.x * sp48.x.y) - (racer->trueBasis.y.y * sp48.x.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.z.x) + SQ(sp48.z.y) + SQ(sp48.z.z));
        sp48.z.x *= temp_fv1;
        sp48.z.y *= temp_fv1;
        sp48.z.z *= temp_fv1;

        sp48.y.x = (sp48.x.y * sp48.z.z) - (sp48.x.z * sp48.z.y);
        sp48.y.y = (sp48.x.z * sp48.z.x) - (sp48.x.x * sp48.z.z);
        sp48.y.z = (sp48.x.x * sp48.z.y) - (sp48.x.y * sp48.z.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.y.x) + SQ(sp48.y.y) + SQ(sp48.y.z));
        sp48.y.x *= temp_fv1;
        sp48.y.y *= temp_fv1;
        sp48.y.z *= temp_fv1;

        angle = Math_Round(DEG_TO_FZXANG2(var_s1->pitch));

        temp_fv0 =
            (SIN(angle) * var_s1->distance) *
            ((sp48.y.x * racer->trueBasis.y.x) + (sp48.y.y * racer->trueBasis.y.y) + (sp48.y.z * racer->trueBasis.y.z));
        temp_fv1 = COS(angle) * var_s1->distance;

        temp1 = (racer->focusPos.x + (temp_fv1 * sp48.x.x) + (temp_fv0 * sp48.y.x));
        temp2 = (racer->focusPos.y + (temp_fv1 * sp48.x.y) + (temp_fv0 * sp48.y.y));
        temp3 = (racer->focusPos.z + (temp_fv1 * sp48.x.z) + (temp_fv0 * sp48.y.z));

        temp_fv0 = (f32) (camera->timer - 1) / 300.0f;

        temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);

        temp_v1->eye.x = ((1.0f - temp_fv0) * temp_v1->eye.x) + (temp_fv0 * temp1);
        temp_v1->eye.y = ((1.0f - temp_fv0) * temp_v1->eye.y) + (temp_fv0 * temp2);
        temp_v1->eye.z = ((1.0f - temp_fv0) * temp_v1->eye.z) + (temp_fv0 * temp3);

        sp48.x.x = temp_v1->at.x - temp_v1->eye.x;
        sp48.x.y = temp_v1->at.y - temp_v1->eye.y;
        sp48.x.z = temp_v1->at.z - temp_v1->eye.z;
        sp48.y.x = racer->trueBasis.y.x;
        sp48.y.y = racer->trueBasis.y.y;
        sp48.y.z = racer->trueBasis.y.z;
        Math_OrthonormalizeAroundForward(&sp48);
        temp_v1->up.x = temp_v1->targetUp.x = sp48.y.x;
        temp_v1->up.y = temp_v1->targetUp.y = sp48.y.y;
        temp_v1->up.z = temp_v1->targetUp.z = sp48.y.z;
    }
}

extern s32 D_8006D544;
extern s32 D_8006D548;
extern s32 D_800BF040;
extern s32 sNumCameras;
extern s16 D_807A16CC;

void func_80717B20(void) {
    Racer* racer;
    f32 temp_fv0;
    s32 i;
    Camera* camera;
    Vp* vp;

    if (D_8076D6C0 == -1) {
        if ((D_807A16CC != 0) && (D_8006D544 != 0)) {
            D_800BF040 = 30;

            for (i = 0, camera = gCameras; i < sNumCameras; i++, camera++) {
                racer = &gRacers[i];
                if (racer->position == 1) {
                    D_8076D6C0 = i;
                }
                camera->vpTransitionState = 1;
                camera->transitionTimer = 0;
                camera->transitionTime = 30;
            }

            switch (gGameMode) {
                case GAMEMODE_VS_2P:
                    if (D_8076D6C0 == 0) {
                        gCameras[0].endScissorTop = 8.0f;
                        gCameras[0].endScissorBottom = 231.0f;
                        gCameras[0].endVpScaleY = 120.0f;
                        gCameras[0].endVpTransY = 0.0f;
                        gCameras[1].endScissorTop = 231.0f;
                        gCameras[1].endScissorBottom = 231.0f;
                        gCameras[1].endVpScaleY = 0.0f;
                        gCameras[1].endVpTransY = 240.0f;
                    } else {
                        gCameras[0].endScissorTop = 8.0f;
                        gCameras[0].endScissorBottom = 8.0f;
                        gCameras[0].endVpScaleY = 0.0f;
                        gCameras[0].endVpTransY = 0.0f;
                        gCameras[1].endScissorTop = 8.0f;
                        gCameras[1].endScissorBottom = 231.0f;
                        gCameras[1].endVpScaleY = 120.0f;
                        gCameras[1].endVpTransY = 0.0f;
                    }
                    break;
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                    switch (D_8076D6C0) {
                        case 0:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 307.0f;
                            gCameras[0].endScissorBottom = 231.0f;
                            gCameras[0].endVpScaleX = 160.0f;
                            gCameras[0].endVpScaleY = 120.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 231.0f;
                            gCameras[1].endScissorRight = 307.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 160.0f;
                            gCameras[1].endVpScaleY = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 240.0f;
                            gCameras[2].endScissorLeft = 307.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorBottom = 231.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endVpScaleX = 0.0f;
                            gCameras[2].endVpScaleY = 120.0f;
                            gCameras[2].endVpTransX = 320.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 307.0f;
                            gCameras[3].endScissorTop = 231.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 0.0f;
                            gCameras[3].endVpScaleY = 0.0f;
                            gCameras[3].endVpTransX = 320.0f;
                            gCameras[3].endVpTransY = 240.0f;
                            break;
                        case 1:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 307.0f;
                            gCameras[0].endScissorBottom = 8.0f;
                            gCameras[0].endVpScaleX = 160.0f;
                            gCameras[0].endVpScaleY = 0.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 8.0f;
                            gCameras[1].endScissorRight = 307.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 160.0f;
                            gCameras[1].endVpScaleY = 120.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 0.0f;
                            gCameras[2].endScissorLeft = 307.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endScissorBottom = 8.0f;
                            gCameras[2].endVpScaleX = 0.0f;
                            gCameras[2].endVpScaleY = 0.0f;
                            gCameras[2].endVpTransX = 320.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 307.0f;
                            gCameras[3].endScissorTop = 8.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 0.0f;
                            gCameras[3].endVpScaleY = 120.0f;
                            gCameras[3].endVpTransX = 320.0f;
                            gCameras[3].endVpTransY = 0.0f;
                            break;
                        case 2:
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorRight = 12.0f;
                            gCameras[0].endScissorBottom = 231.0f;
                            gCameras[0].endVpScaleX = 0.0f;
                            gCameras[0].endVpScaleY = 120.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 231.0f;
                            gCameras[1].endScissorRight = 12.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[1].endVpScaleX = 0.0f;
                            gCameras[1].endVpScaleY = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 240.0f;
                            gCameras[2].endScissorLeft = 12.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[2].endScissorBottom = 231.0f;
                            gCameras[2].endVpScaleX = 160.0f;
                            gCameras[2].endVpScaleY = 120.0f;
                            gCameras[2].endVpTransX = 0.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endScissorLeft = 12.0f;
                            gCameras[3].endScissorTop = 231.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[3].endVpScaleX = 160.0f;
                            gCameras[3].endVpScaleY = 0.0f;
                            gCameras[3].endVpTransX = 0.0f;
                            gCameras[3].endVpTransY = 240.0f;
                            break;
                        case 3:
                            gCameras[0].endVpScaleX = 0.0f;
                            gCameras[0].endVpScaleY = 0.0f;
                            gCameras[0].endScissorLeft = 12.0f;
                            gCameras[0].endScissorRight = 12.0f;
                            gCameras[0].endVpTransX = 0.0f;
                            gCameras[0].endVpTransY = 0.0f;
                            gCameras[0].endScissorTop = 8.0f;
                            gCameras[0].endScissorBottom = 8.0f;
                            gCameras[1].endScissorLeft = 12.0f;
                            gCameras[1].endScissorRight = 12.0f;
                            gCameras[2].endScissorLeft = 12.0f;
                            gCameras[3].endScissorLeft = 12.0f;
                            gCameras[1].endScissorTop = 8.0f;
                            gCameras[2].endScissorTop = 8.0f;
                            gCameras[2].endScissorBottom = 8.0f;
                            gCameras[3].endScissorTop = 8.0f;
                            gCameras[1].endVpScaleY = 120.0f;
                            gCameras[3].endVpScaleY = 120.0f;
                            gCameras[1].endScissorBottom = 231.0f;
                            gCameras[3].endScissorBottom = 231.0f;
                            gCameras[2].endVpScaleX = 160.0f;
                            gCameras[3].endVpScaleX = 160.0f;
                            gCameras[2].endScissorRight = 307.0f;
                            gCameras[3].endScissorRight = 307.0f;
                            gCameras[1].endVpScaleX = 0.0f;
                            gCameras[1].endVpTransX = 0.0f;
                            gCameras[1].endVpTransY = 0.0f;
                            gCameras[2].endVpScaleY = 0.0f;
                            gCameras[2].endVpTransX = 0.0f;
                            gCameras[2].endVpTransY = 0.0f;
                            gCameras[3].endVpTransX = 0.0f;
                            gCameras[3].endVpTransY = 0.0f;
                            break;
                    }
                    break;
            }
        }
    } else if ((gCameras[D_8076D6C0].transitionTimer == 30) && (D_8006D548 == 0)) {
        D_8006D548 = 1;
    }

    for (i = 0, camera = gCameras; i < sNumCameras; i++, camera++) {
        if (camera->vpTransitionState == 1) {
            if (camera->transitionTimer < camera->transitionTime) {
                camera->transitionTimer++;
            }

            temp_fv0 = (f32) camera->transitionTimer / camera->transitionTime;

            camera->currentScissorLeft =
                camera->startScissorLeft + ((camera->endScissorLeft - camera->startScissorLeft) * temp_fv0);
            camera->currentScissorTop =
                camera->startScissorTop + ((camera->endScissorTop - camera->startScissorTop) * temp_fv0);
            camera->currentScissorRight =
                camera->startScissorRight + ((camera->endScissorRight - camera->startScissorRight) * temp_fv0);
            camera->currentScissorBottom =
                camera->startScissorBottom + ((camera->endScissorBottom - camera->startScissorBottom) * temp_fv0);
            camera->currentVpScaleX =
                camera->startVpScaleX + ((camera->endVpScaleX - camera->startVpScaleX) * temp_fv0);
            camera->currentVpScaleY =
                camera->startVpScaleY + ((camera->endVpScaleY - camera->startVpScaleY) * temp_fv0);
            camera->currentVpTransX = camera->startVpTransX +
                                      ((camera->endVpTransX - camera->startVpTransX) * temp_fv0) +
                                      camera->currentVpScaleX;
            camera->currentVpTransY = camera->startVpTransY +
                                      ((camera->endVpTransY - camera->startVpTransY) * temp_fv0) +
                                      camera->currentVpScaleY;

            vp = &gGfxPool->unk_362C8[i];
            vp->vp.vscale[0] = camera->currentVpScaleX * 4.0f;
            vp->vp.vscale[1] = camera->currentVpScaleY * 4.0f;
            vp->vp.vscale[2] = 0x1FF;
            vp->vp.vscale[3] = 0;
            vp->vp.vtrans[0] = camera->currentVpTransX * 4.0f;
            vp->vp.vtrans[1] = camera->currentVpTransY * 4.0f;
            vp->vp.vtrans[2] = 0x1FF;
            vp->vp.vtrans[3] = 0;
        }
    }
}

void Camera_UpdateRaceIntro(Camera* camera, CameraSettings* cameraSettings) {
    unk_80776A48* var_v1;
    f32 temp_fv0;
    s32 index;
    CameraParameters* params = &cameraSettings->parameters;
    Racer* racer = &gRacers[camera->id];
    CameraTypeOrbit* orbit = &cameraSettings->orbit;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;
    s32 pad[5];

    orbit->anchorPos = racer->focusPos;
    orbit->basis = racer->trueBasis;

    temp_fv0 = (f32) camera->timer / 300.0f;
    temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);
    orbit->targetDistance = (-880.0f * temp_fv0) + 1000.0f;
    orbit->targetYaw = (-360.0f * temp_fv0) + 180.0f;

    if (camera->timer >= 300) {
        if (gNumPlayers == 2) {
            Camera_SettingsSetFollowSmooth(cameraSettings, &D_80776B9C.data);
            var_v1 = &D_80776A78[2];
        } else {
            Camera_SettingsSetFollowSmooth(cameraSettings, &D_80776AA8.data);
            var_v1 = &D_80776A48[2];
        }
        camera->mode = CAMERA_MODE_SETUP_RACE;

        followSmooth->centerPos.x = 0.0f;
        followSmooth->centerPos.y = 0.0f;
        followSmooth->centerPos.z = 0.0f;

        followSmooth->distance = var_v1->distance;
        followSmooth->pitch = var_v1->pitch;
        params->fov = var_v1->fov;

        if (gNumPlayers == 2) {
            var_v1 = &D_80776A78[camera->raceSetting];
        } else {
            var_v1 = &D_80776A48[camera->raceSetting];
        }
        followSmooth->targetDistance = var_v1->distance;
        followSmooth->targetPitch = var_v1->pitch;
        params->targetFov = var_v1->fov;

        racer = &gRacers[camera->id];
        followSmooth->anchorPoint.x = racer->focusPos.x - (var_v1->distance * racer->trueBasis.x.x);
        followSmooth->anchorPoint.y = racer->focusPos.y - (var_v1->distance * racer->trueBasis.x.y);
        followSmooth->anchorPoint.z = racer->focusPos.z - (var_v1->distance * racer->trueBasis.x.z);

        camera->focusPos = racer->focusPos;
        camera->racerBasis = racer->trueBasis;

        camera->targetFov = cameraSettings->parameters.targetFov;
        camera->fovFlags = 0;
        if ((camera->raceSetting == CAMERA_RACE_SETTING_CLOSE_BEHIND) ||
            (camera->raceSetting == CAMERA_RACE_SETTING_REGULAR)) {
            camera->fovFlags |= CAMERA_FOV_FLAG_1;
        }
        followSmooth->distanceLerpFactor = followSmooth->pitchLerpFactor = 0.1f;
        params->upLerpFactor = 0.1f;
        params->fovLerpFactor = 0.1f;
        params->frustrumCenterYLerpFactor = 0.1f;
    } else {
        camera->timer++;
    }
}

extern s16 D_807A16CC;
extern s32 gCurrentGhostType;
extern s32 gFastestGhostTime;

void Camera_UpdateRace(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    f32 var_fa0;
    f32 var_fv1;
    s32 playerIndex;
    bool settingChanged;
    CameraParameters* params;
    s32 pad[4];
    Racer* racer;
    CameraTypeFollowSmooth* followSmooth = &cameraSettings->followSmooth;
    Controller* controller;

    playerIndex = camera->id;
    racer = &gRacers[playerIndex];
    if (!gGamePaused) {
        if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
            camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
            Camera_InitMode(camera, cameraSettings, arg2);
            return;
        }
        if (racer->stateFlags & RACER_STATE_FINISHED) {
            if ((gNumPlayers >= 2) && (D_807A16CC != 0)) {
                camera->mode = CAMERA_MODE_FINISHED_SPECTATE;
                Camera_InitMode(camera, cameraSettings, arg2);
                return;
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if ((gCurrentGhostType != GHOST_STAFF) && (gCurrentGhostType != GHOST_CELEBRITY) &&
                    (gCurrentGhostType != GHOST_CHAMP)) {
                    camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
                } else if (racer->raceTime < gFastestGhostTime) {
                    camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
                } else {
                    camera->mode = CAMERA_MODE_FINISHED_LOSER;
                }
            } else {
                camera->mode = CAMERA_MODE_FINISHED_SUCCESS;
            }
            Camera_InitMode(camera, cameraSettings, arg2);
            return;
        }
    }

    controller = &gControllers[gPlayerControlPorts[playerIndex]];
    settingChanged = false;

    if (!(racer->stateFlags & RACER_STATE_RETIRED) && (controller->buttonPressed & BTN_CRIGHT)) {
        settingChanged = true;
        if (++camera->raceSetting == CAMERA_RACE_SETTING_MAX) {
            camera->raceSetting = CAMERA_RACE_SETTING_OVERHEAD;
        }
    }
    if (settingChanged) {
        Camera_RaceSettingChanged(camera, &cameraSettings->parameters, followSmooth, gNumPlayers);
    }
    params = &cameraSettings->parameters;
    if ((D_8076D6C4 != 0) && (!gGamePaused)) {
        if ((controller->buttonCurrent & BTN_CUP) && !(racer->stateFlags & RACER_STATE_RETIRED)) {
            if (++camera->lookBackRotate > sMaxCameraLookBackRotate) {
                camera->lookBackRotate = sMaxCameraLookBackRotate;
            }
        } else {
            if (--camera->lookBackRotate < 0) {
                camera->lookBackRotate = 0;
            }
        }
        followSmooth->targetYaw = (camera->lookBackRotate * 180.0f) / sMaxCameraLookBackRotate;
    }
    if (camera->fovFlags & CAMERA_FOV_FLAG_1) {

        var_fv1 = sqrtf(SQ(racer->unk_5C.x) + SQ(racer->unk_5C.z)) - D_8076D8A8;
        if (var_fv1 < 0.0f) {
            var_fa0 = camera->targetFov;
        } else {
            var_fv1 /= (D_8076D8AC - D_8076D8A8);
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            var_fa0 = camera->targetFov + ((120.0f - camera->targetFov) * var_fv1);
        }
        if (camera->fovFlags & CAMERA_FOV_FLAG_2) {
            params->targetFov = var_fa0;
        } else {
            params->targetFov = var_fa0;
            params->fov = var_fa0;
        }
    }
    var_fv1 = params->targetFov - params->fov;

    if (ABS(var_fv1) < 0.1f) {
        camera->fovFlags &= ~CAMERA_FOV_FLAG_2;
    }
}

void Camera_UpdateTitleDemo(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    s32 playerIndex = camera->id;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, arg2);
    }
}

extern s8 D_i5_8007B9DC;

void Camera_UpdateCourseSelect(Camera* camera, CameraSettings* cameraSettings) {
    s32 i;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;

    if (D_i5_8007B9DC) {
        orbit->targetYaw += 1.0f;
        if (orbit->targetYaw >= 360.0f) {
            orbit->targetYaw -= 360.0f;
        }
        if (camera->state == CAMERA_COURSE_SELECT_ACCEPT_INPUTS) {
            for (i = 0; i < gNumPlayers; i++) {
                Controller* controller = &gControllers[gPlayerControlPorts[i]];

                if (controller->buttonCurrent & BTN_CUP) {
                    orbit->targetPitch += 0.1f;
                }
                if (controller->buttonCurrent & BTN_CDOWN) {
                    orbit->targetPitch -= 0.1f;
                }
            }
        } else {
            camera->state = CAMERA_COURSE_SELECT_ACCEPT_INPUTS;
            orbit->targetPitch = 20.0f;
        }

        if (orbit->targetPitch < -50.0f) {
            orbit->targetPitch = -50.0f;
        } else if (orbit->targetPitch > 90.0f) {
            orbit->targetPitch = 90.0f;
        }
    }
}

void Camera_UpdateFallingOffTrack(Camera* camera, CameraSettings* cameraSettings) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

    atEye->targetAt = gRacers[camera->id].focusPos;
}

void Camera_UpdateFinishedSuccess(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    s32 pad;
    Vec3f* temp_s1 = &D_807A15A0[camera->id];
    unk_800CD970* temp_a3 = &D_8076D788[camera->state];
    CameraParameters* params = &cameraSettings->parameters;
    s16 lastType = temp_a3->type;
    Racer* racer = &gRacers[camera->id];
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;
    CameraTypeAtEye* atEye = &cameraSettings->atEye;
    unk_800CD8B0* temp_v0_2;

    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, arg2);
        return;
    }
    switch (temp_a3->type) {
        case 0:
            atEye->targetAt = racer->focusPos;
            atEye->targetEye.x = temp_s1->x;
            atEye->targetEye.y = temp_s1->y;
            atEye->targetEye.z = temp_s1->z;
            break;
        case 1:
            temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;

            localAnchor->basis = racer->trueBasis;

            params->targetUp.x = localAnchor->basis.y.x;
            params->targetUp.y = localAnchor->basis.y.y;
            params->targetUp.z = localAnchor->basis.y.z;
            localAnchor->anchorPoint = racer->focusPos;

            localAnchor->targetLocalAt.x =
                temp_v0_2->startAt.x +
                ((((temp_v0_2->endAt.x - temp_v0_2->startAt.x) * camera->timer) / temp_a3->time) *
                 temp_v0_2->atTranslationScale);
            localAnchor->targetLocalAt.y =
                temp_v0_2->startAt.y +
                ((((temp_v0_2->endAt.y - temp_v0_2->startAt.y) * camera->timer) / temp_a3->time) *
                 temp_v0_2->atTranslationScale);
            localAnchor->targetLocalAt.z =
                temp_v0_2->startAt.z +
                ((((temp_v0_2->endAt.z - temp_v0_2->startAt.z) * camera->timer) / temp_a3->time) *
                 temp_v0_2->atTranslationScale);

            localAnchor->targetLocalEye.x =
                temp_v0_2->startEye.x +
                ((((temp_v0_2->endEye.x - temp_v0_2->startEye.x) * camera->timer) / temp_a3->time) *
                 temp_v0_2->eyeTranslationScale);
            localAnchor->targetLocalEye.y =
                temp_v0_2->startEye.y +
                ((((temp_v0_2->endEye.y - temp_v0_2->startEye.y) * camera->timer) / temp_a3->time) *
                 temp_v0_2->eyeTranslationScale);
            localAnchor->targetLocalEye.z =
                temp_v0_2->startEye.z +
                ((((temp_v0_2->endEye.z - temp_v0_2->startEye.z) * camera->timer) / temp_a3->time) *
                 temp_v0_2->eyeTranslationScale);
        default:
            break;
    }

    if (camera->timer >= temp_a3->time) {
        camera->timer = 0;
        if (++camera->state >= 5) {
            camera->mode = CAMERA_MODE_FINISHED_SPECTATE;
            Camera_InitMode(camera, cameraSettings, arg2);
            return;
        }
        temp_a3 = &D_8076D788[camera->state];
        params->targetFov = temp_a3->fov;

        switch (temp_a3->type) {
            case 0:
                if (lastType != temp_a3->type) {
                    Camera_SettingsSetAtEye(cameraSettings, &D_807763D0.data);
                }
                params->targetUp.x = 0.0f;
                params->targetUp.y = 1.0f;
                params->targetUp.z = 0.0f;
                func_80718F58(temp_s1, racer->segmentPositionInfo.courseSegment,
                              racer->segmentPositionInfo.segmentTValue, temp_a3);
                atEye->targetAt = racer->focusPos;
                atEye->targetEye.x = temp_s1->x;
                atEye->targetEye.y = temp_s1->y;
                atEye->targetEye.z = temp_s1->z;
                break;
            case 1:
                if (lastType != temp_a3->type) {
                    Camera_SettingsSetLocalAnchor(cameraSettings, &D_807765E8.data);
                }
                temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;
                localAnchor->targetLocalAt = temp_v0_2->startAt;
                localAnchor->targetLocalEye = temp_v0_2->startEye;
                break;
            default:
                break;
        }
    } else {
        camera->timer++;
    }
}

void func_80718F58(Vec3f* eyePos, CourseSegment* segment, f32 arg2, unk_800CD970* arg3) {
    f32 abs;
    f32 t;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 var_fa0;
    f32 var_fv0;
    Mtx3F segmentBasis;
    unk_8076D6C8* sp28 = (unk_8076D6C8*) arg3->unk_08;

    t = func_80712E68(&segment, arg2, sp28->unk_00);

    Course_SplineGetPosition(segment, t, eyePos);
    func_80712FE4(&segmentBasis, segment, t);

    temp_ft4 = segment->radiusLeft * (1.0f - t) + segment->next->radiusLeft * t;
    temp_fa1 = segment->radiusRight * (1.0f - t) + segment->next->radiusRight * t;

    switch (segment->trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_CYLINDER:
            var_fv0 = sp28->unk_04 * temp_fa1;
            var_fa0 = sp28->unk_08 + temp_fa1;
            break;
        case TRACK_SHAPE_HALF_PIPE:
            var_fv0 = sp28->unk_04 * temp_ft4;
            var_fa0 = sp28->unk_08;
            break;
        default:
            if (sp28->unk_04 >= 0.0f) {
                var_fv0 = sp28->unk_04 * temp_ft4;
            } else {
                var_fv0 = sp28->unk_04 * temp_fa1;
            }
            var_fa0 = sp28->unk_08;
            break;
    }

    abs = ABS(var_fv0);
    if (D_8076D8B0 < abs) {
        abs = D_8076D8B0;
        if (var_fv0 < 0) {
            var_fv0 = 0.0f - abs;
        } else {
            var_fv0 = abs;
        }
    }

    eyePos->x += (segmentBasis.y.x * var_fa0) + (segmentBasis.z.x * var_fv0);
    eyePos->y += (segmentBasis.y.y * var_fa0) + (segmentBasis.z.y * var_fv0);
    eyePos->z += (segmentBasis.y.z * var_fa0) + (segmentBasis.z.z * var_fv0);
}

void Camera_UpdateFinishedLoser(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    CameraTypeAtEye* atEye = &cameraSettings->atEye;

    if (camera->timer <= 60) {
        atEye->targetAt = gRacers[camera->id].segmentPositionInfo.pos;
        camera->timer++;
    }
}

void Camera_UpdateFinishedSpectate(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    s32 pad;
    f32 temp;
    CameraTypeOrbit* orbit = &cameraSettings->orbit;
    Racer* temp_a3 = &gRacers[camera->id];
    CameraParameters* params = &cameraSettings->parameters;

    if (temp_a3->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, arg2);
        return;
    }
    orbit->basis.y.x += temp_a3->tiltUp.x * 0.3f;
    orbit->basis.y.y += temp_a3->tiltUp.y * 0.3f;
    orbit->basis.y.z += temp_a3->tiltUp.z * 0.3f;

    Math_OrthonormalizeAroundUp(&orbit->basis);

    params->targetUp.x = orbit->basis.y.x;
    params->targetUp.y = orbit->basis.y.y;
    params->targetUp.z = orbit->basis.y.z;

    orbit->anchorPos = temp_a3->focusPos;

    switch (camera->state) {
        case 0:
            if (++camera->timer >= 180) {
                camera->state = 1;
                camera->timer = 0;
                orbit->distanceLerpFactor = 0.005f;
            }
            break;
        case 1:
            if (++camera->timer >= 300) {
                camera->timer = 0;
                orbit->targetDistance = (Math_Rand1() % 451) + 50.0f;
            }
            orbit->targetYaw += 0.4f;

            if (orbit->targetYaw >= 360.0f) {
                orbit->targetYaw -= 360.0f;
            }
            break;
        default:
            break;
    }

    if ((D_8076D6C0 == camera->id) && (gNumPlayers == 2)) {

        if (camera->transitionTimer < camera->transitionTime) {
            temp = (f32) (camera->transitionTimer + 1) / camera->transitionTime;
            cameraSettings->parameters.targetFrustrumCenterY = -30.0f - (-30.0f * temp);
        } else {
            cameraSettings->parameters.targetFrustrumCenterY = 0.0f;
        }
    }
}

void Camera_UpdateRecordsRace(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    Racer* racer = &gRacers[camera->id];

    if (racer->stateFlags & RACER_STATE_FALLING_OFF_TRACK) {
        camera->mode = CAMERA_MODE_FALLING_OFF_TRACK;
        Camera_InitMode(camera, cameraSettings, arg2);
    }
}

extern unk_struct_C D_i7_800993D0[];
extern unk_struct_C D_i7_800996E0[];
extern unk_struct_C D_i7_80099A60[];
extern unk_struct_C D_i7_80099F70[];
extern unk_struct_C D_i7_8009A090[];
extern unk_struct_C D_i7_8009A210[];
extern u16 D_8009AD16;

void Camera_UpdateEnding(Camera* camera, CameraSettings* cameraSettings, unk_800E5D70* arg2) {
    s32 var_s3 = true;
    Racer* racer;
    CameraTypeLocalAnchor* localAnchor = &cameraSettings->localAnchor;
    unk_struct_C* var_a1;

    while (var_s3) {

        var_s3 = false;
        switch (camera->state) {
            case 0:
                if (func_80719868(1)) {
                    if (D_8009AD16 & 0x40) {
                        var_s3 = true;
                        camera->state = 2;
                        Camera_SettingsSetLocalAnchor(cameraSettings, &D_807765E8.data);
                        localAnchor = &cameraSettings->localAnchor;
                        localAnchor->targetLocalAt.x = localAnchor->targetLocalAt.y = localAnchor->targetLocalAt.z =
                            0.0f;
                        localAnchor->targetLocalEye.x = 0.0f;
                        localAnchor->targetLocalEye.y = 37.0f;
                        localAnchor->targetLocalEye.z = -132.0f;
                    } else {
                        camera->state = 1;
                        camera->timer = 0;
                        if (sCameraEndingFocusRacer == 0) {
                            var_a1 = D_i7_800993D0;
                        } else if (sCameraEndingFocusRacer == 1) {
                            var_a1 = D_i7_80099A60;
                        } else {
                            var_a1 = D_i7_800996E0;
                        }
                        func_80714000(arg2, var_a1);
                        racer = &gRacers[sCameraEndingFocusRacer];
                        func_80713FE4(&D_807A1480[camera->id], &racer->focusPos, &racer->trueBasis, racer);
                    }
                }
                break;
            case 1:
                if (func_8071403C(arg2)) {
                    camera->state = 2;
                    localAnchor = &cameraSettings->localAnchor;
                    localAnchor->targetLocalAt.x = 0.0f;
                    localAnchor->targetLocalAt.y = 0.0f;
                    localAnchor->targetLocalAt.z = 0.0f;
                    localAnchor->targetLocalEye.x = 0.0f;
                    localAnchor->targetLocalEye.y = 37.0f;
                    var_s3 = true;
                    if (D_8009AD16 & 2) {
                        localAnchor->targetLocalEye.z = 132.0f;
                    } else {
                        localAnchor->targetLocalEye.z = -132.0f;
                    }
                }
                break;
            case 2:
                racer = &gRacers[sCameraEndingFocusRacer];
                localAnchor = &cameraSettings->localAnchor;
                localAnchor->basis = racer->trueBasis;
                localAnchor->anchorPoint = racer->focusPos;
                if (func_80719868(4)) {
                    camera->state = 3;
                    camera->timer = 0;
                    racer = &gRacers[2];
                    func_80713FE4(&D_807A1480[camera->id], &racer->focusPos, &racer->trueBasis, racer);
                    func_80714000(arg2, D_i7_8009A210);
                }
                break;
            case 3:
                if (func_8071403C(arg2) && func_80719868(3)) {
                    camera->state = 4;
                    camera->timer = 0;
                    racer = &gRacers[1];
                    func_80713FE4(&D_807A1480[camera->id], &racer->focusPos, &racer->trueBasis, racer);
                    func_80714000(arg2, D_i7_8009A090);
                }
                break;
            case 4:
                if (func_8071403C(arg2) && func_80719868(2)) {
                    camera->state = 5;
                    camera->timer = 0;
                    racer = &gRacers[0];
                    func_80713FE4(&D_807A1480[camera->id], &racer->focusPos, &racer->trueBasis, racer);
                    func_80714000(arg2, D_i7_80099F70);
                }
                break;
            case 5:
                func_8071403C(arg2);
                break;
        }
    }
}

void func_8071985C(s32 arg0) {
    D_807A1594 = arg0;
}

bool func_80719868(s32 arg0) {
    bool var_v1 = false;

    if (arg0 == D_807A1594) {
        var_v1 = true;
        D_807A1594 = 0;
    }
    return var_v1;
}

Gfx* func_80719890(Gfx* gfx) {

    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);
    gSPMatrix(gfx++, &D_1000000.unk_1A208[gCameras[0].id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    return func_80713E38(gfx, SCISSOR_BOX_FULL_SCREEN, gCameras[0].id);
}
