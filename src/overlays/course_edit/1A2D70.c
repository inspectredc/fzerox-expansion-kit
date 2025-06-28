#include "global.h"

u8 D_xk2_80128D00[64];
f32 D_xk2_80128D40;
f32 D_xk2_80128D44;
s32 D_xk2_80128D48;
s32 D_xk2_80128D4C;
s32 D_xk2_80128D50;
s32 D_xk2_80128D54;
s32 D_xk2_80128D58;
s32 D_xk2_80128D5C;
f32 D_xk2_80128D60;
f32 D_xk2_80128D64;
f32 D_xk2_80128D68;
s32 D_xk2_80128D6C;

u8 D_xk2_80104CA0[12] = { 0 };

extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F12B0(void) {
    s32 i;

    D_800D6CA0.unk_1C = -1;

    for (i = 0; i < 12; i++) {
        if ((i != 0xA) && (i != 1) && (i != 3)) {
            D_xk2_80104CA0[i] = 0;
        }
    }

    for (i = 0; i < 64; i++) {
        D_xk2_80128D00[i] = 0;
    }
}

void func_xk2_800F1330(s32 arg0, s32 arg1) {
    if (&arg1) {}
    D_xk2_80128D00[arg0] |= arg1;
}

u8 func_xk2_800F1350(s32 arg0) {
    return D_xk2_80128D00[arg0];
}

UNUSED s32 D_xk2_80104CAC = 0;
s32 D_xk2_80104CB0 = 90;
s32 D_xk2_80104CB4 = 15000;
s32 D_xk2_80104CB8 = 0;
s32 D_xk2_80104CBC = 0;
s32 D_xk2_80104CC0 = 0;

void func_xk2_800F1360(void) {
    D_xk2_80128D48 = D_xk2_80104CB0;
    D_xk2_80128D4C = D_800D6CA0.unk_14;
    D_xk2_80128D50 = D_xk2_80104CB4;
    D_xk2_80128D54 = D_xk2_80104CB8;
    D_xk2_80128D58 = D_xk2_80104CBC;
    D_xk2_80128D5C = D_xk2_80104CC0;
}

void func_xk2_800F13C4(void) {
    D_xk2_80104CB0 = D_xk2_80128D48;
    D_800D6CA0.unk_14 = D_xk2_80128D4C;
    D_xk2_80104CB4 = D_xk2_80128D50;
    D_xk2_80104CB8 = D_xk2_80128D54;
    D_xk2_80104CBC = D_xk2_80128D58;
    D_xk2_80104CC0 = D_xk2_80128D5C;
}

extern Mtx D_2000000[];
extern Player gPlayers[];
extern s32 D_8076C950;
extern unk_80128C94 D_6000000;
extern unk_80128C94* D_80128C94;

#ifdef NON_MATCHING
// stack
Gfx* func_xk2_800F1428(Gfx* gfx) {
    u16 sp13E;
    s32 pad[9];
    s32 temp_v0;
    s32 temp_v1;
    Player* player = gPlayers;
    Mtx spC8;
    MtxF sp88;

    if (D_8076C950 != 0) {
        return func_80719890();
    }
    if (D_8076C950 != 0) {
        func_806F9384(&D_80128C94->unk_0000, NULL, (gPlayers[0].unk_94.x * 320.0f) / 240.0f, 32.0f, 4096.0f, 320.0f,
                      0.0f, 240.0f, 0.0f, &sp13E);
    } else {
        func_806F9384(&D_80128C94->unk_0000, NULL, (gPlayers[0].unk_94.x * 320.0f) / 240.0f, 128.0f, 32768.0f, 320.0f,
                      0.0f, 240.0f, 0.0f, &sp13E);
        sp13E = 0x10;
    }
    gSPPerspNormalize(gfx++, sp13E);
    gSPMatrix(gfx++, &D_6000000.unk_0000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    Matrix_FromMtx(&D_80128C94->unk_0000, &gPlayers[0].unk_11C);
    temp_v0 = (D_xk2_80104CB0 * 0x1000) / 360;
    D_xk2_80128D64 = SIN(temp_v0);
    D_xk2_80128D68 = COS(temp_v0);
    temp_v1 = (D_800D6CA0.unk_14 * 0x1000) / 360;
    D_xk2_80128D60 = SIN(temp_v1) * D_xk2_80128D68;
    D_xk2_80128D64 = (-1.0f * D_xk2_80128D64);
    D_xk2_80128D68 = COS(temp_v1) * (-1.0f * D_xk2_80128D68);
    gPlayers[0].unk_5C.x.x = D_xk2_80128D60;
    gPlayers[0].unk_5C.x.y = D_xk2_80128D64;
    gPlayers[0].unk_5C.x.z = D_xk2_80128D68;

    gPlayers[0].unk_50.x = D_xk2_80104CB8 - (D_xk2_80104CB4 * D_xk2_80128D60);
    gPlayers[0].unk_50.y = D_xk2_80104CBC - (D_xk2_80104CB4 * D_xk2_80128D64);
    gPlayers[0].unk_50.z = D_xk2_80104CC0 - (D_xk2_80104CB4 * D_xk2_80128D68);

    D_xk2_80128D40 = SIN(temp_v1);
    D_xk2_80128D44 = COS(temp_v1);

    gPlayers[0].unk_5C.y.x = 0 - (D_xk2_80128D64 * D_xk2_80128D40);
    gPlayers[0].unk_5C.y.y = (D_xk2_80128D60 * D_xk2_80128D40) - (D_xk2_80128D68 * D_xk2_80128D44);
    gPlayers[0].unk_5C.y.z = D_xk2_80128D64 * D_xk2_80128D44;

    gPlayers[0].unk_5C.z.x = (D_xk2_80128D68 * gPlayers[0].unk_5C.y.y) - (D_xk2_80128D64 * gPlayers[0].unk_5C.y.z);
    gPlayers[0].unk_5C.z.y = (D_xk2_80128D60 * gPlayers[0].unk_5C.y.z) - (D_xk2_80128D68 * gPlayers[0].unk_5C.y.x);
    gPlayers[0].unk_5C.z.z = (D_xk2_80128D64 * gPlayers[0].unk_5C.y.x) - (D_xk2_80128D60 * gPlayers[0].unk_5C.y.y);
    func_806F8FE0(&D_80128C94->unk_0040, NULL, gPlayers[0].unk_50.x, gPlayers[0].unk_50.y, gPlayers[0].unk_50.z,
                  D_xk2_80104CB8, D_xk2_80104CBC, D_xk2_80104CC0, gPlayers[0].unk_5C.y.x, gPlayers[0].unk_5C.y.y,
                  gPlayers[0].unk_5C.y.z);

    gSPMatrix(gfx++, &D_6000000.unk_0040, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    Matrix_FromMtx(&D_80128C94->unk_0040, &gPlayers[0].unk_15C);
    func_80713204(&gPlayers[0].unk_19C, &gPlayers[0].unk_11C, &gPlayers[0].unk_15C);
    func_806F7FCC(&spC8, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Matrix_FromMtx(&spC8, &sp88);
    func_xk2_800F1FF0(&sp88, &gPlayers[0].unk_19C, &gPlayers[0].unk_19C);
    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/1A2D70/func_xk2_800F1428.s")
#endif

extern s32 D_xk2_800F6824;
extern s32 D_xk2_800F6828;
extern unk_807B3C20 D_807B3C20;

void func_xk2_800F1938(void) {
    CourseSegment* temp_v1;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f64 temp_fa0;
    f64 temp_fa1;
    f32 var_fa1;
    f32 radiusLeft;
    f32 radiusRight;
    f32 var_fv0;
    f64 var_fv1;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    f64 var_fv0_2;
    f64 temp_dfv0;
    f64 temp_dfv1;
    f32 pad;

    if (D_xk2_800F6828 < 0x38) {
        return;
    }
    temp_dfv0 = gPlayers[0].unk_94.x;
    temp_dfv1 = ((gPlayers[0].unk_94.x * 320.0f) / 240.0f);
    temp_dfv1 = ((D_xk2_800F6824 - 0xA0) / 320.0) * temp_dfv1;
    temp_dfv0 = ((D_xk2_800F6828 - 0x78) / 240.0) * temp_dfv0;

    temp_dfv1 = (4096.0 * temp_dfv1) / 360.0;
    temp_dfv0 = (4096.0 * temp_dfv0) / 360.0;

    temp_fa0 = ((10000.0f * SIN((s32) temp_dfv1)) / COS((s32) temp_dfv1));
    temp_fa1 = ((10000.0f * SIN((s32) temp_dfv0)) / COS((s32) temp_dfv0));

    sp88 = gPlayers[0].unk_50.x + (gPlayers[0].unk_5C.x.x * 10000.0f);
    sp8C = gPlayers[0].unk_50.y + (gPlayers[0].unk_5C.x.y * 10000.0f);
    sp90 = gPlayers[0].unk_50.z + (gPlayers[0].unk_5C.x.z * 10000.0f);

    sp88 = ((sp88 - (temp_fa1 * gPlayers[0].unk_5C.y.x)) - (temp_fa0 * gPlayers[0].unk_5C.z.x));
    sp8C = ((sp8C - (temp_fa1 * gPlayers[0].unk_5C.y.y)) - (temp_fa0 * gPlayers[0].unk_5C.z.y));
    sp90 = ((sp90 - (temp_fa1 * gPlayers[0].unk_5C.y.z)) - (temp_fa0 * gPlayers[0].unk_5C.z.z));

    if (gPlayers[0].unk_50.y <= sp8C) {
        var_fa1 = sp8C - gPlayers[0].unk_50.y;
        var_fv0 = var_fa1;
    } else {
        var_fa1 = sp8C - gPlayers[0].unk_50.y;
        var_fv0 = -var_fa1;
    }
    if (var_fv0 < 10.0f) {
        return;
    }
    if (D_807B3C20.unk_2900 != 0) {
        temp_v1 = &D_807B3C20.unk_0000[D_800D6CA0.unk_0C];
        if (D_xk2_80104CB0 < 0) {
            var_fv1 = (((temp_v1->pos.y + temp_v1->next->pos.y) * 0.3f) / 2);
        } else {
            var_fv1 = (((temp_v1->pos.y + temp_v1->next->pos.y) * 0.3f) / 2);
            if (gPlayers[0].unk_50.y < var_fv1) {
                var_fv1 = (gPlayers[0].unk_50.y - 256.0f);
                if (var_fv1 < 0.0) {
                    var_fv1 = 0.0;
                }
            }
        }
        radiusLeft = (temp_v1->radiusLeft + temp_v1->next->radiusLeft) / 2;
        radiusRight = (temp_v1->radiusRight + temp_v1->next->radiusRight) / 2;
        temp_a2 = gCourseCtx.courseData.bankAngle[temp_v1->segmentIndex];
        temp_a3 = gCourseCtx.courseData.bankAngle[temp_v1->next->segmentIndex];
        temp_a1 = temp_a3 - temp_a2;

        if (ABS(temp_a1) < 180) {
            D_xk2_80128D6C = (s32) (temp_a2 + temp_a3) / 2;
        } else {
            D_xk2_80128D6C = (s32) (temp_a3 + temp_a2 + 360) / 2;
            D_xk2_80128D6C %= 360;
        }
    } else {
        D_xk2_80128D6C = 0;
        var_fv1 = 0.0;
        radiusLeft = 260.0f;
        radiusRight = 260.0f;
    }
    if (gPlayers[0].unk_50.y != 0.0f) {
        // FAKE
        var_fv0_2 = (var_fv1 - (1 * gPlayers[0].unk_50.y)) / (pad = var_fa1);
    } else {
        var_fv0_2 = (var_fv1 - (1 * sp8C)) / (gPlayers[0].unk_50.y - sp8C);
    }
    if ((var_fv0_2 > 100000.0) || (var_fv0_2 < -10000.0)) {
        return;
    }

    D_800D6CA0.unk_28.pos.x = ((sp88 - gPlayers[0].unk_50.x) * var_fv0_2) + gPlayers[0].unk_50.x;
    D_800D6CA0.unk_28.pos.y = var_fv1;
    D_800D6CA0.unk_28.pos.z = ((sp90 - gPlayers[0].unk_50.z) * var_fv0_2) + gPlayers[0].unk_50.z;
    D_800D6CA0.unk_28.pos.x /= 0.3f;
    D_800D6CA0.unk_28.pos.y /= 0.3f;
    D_800D6CA0.unk_28.pos.z /= 0.3f;
    D_800D6CA0.unk_28.pos.x = (Math_Round(D_800D6CA0.unk_28.pos.x) / 10) * 10;
    D_800D6CA0.unk_28.pos.y = (Math_Round(D_800D6CA0.unk_28.pos.y) / 10) * 10;
    D_800D6CA0.unk_28.pos.z = (Math_Round(D_800D6CA0.unk_28.pos.z) / 10) * 10;
    D_800D6CA0.unk_28.radiusLeft = radiusLeft;
    D_800D6CA0.unk_28.radiusRight = radiusRight;

    if ((D_807B3C20.unk_2900 == 1) && (D_807B3C20.unk_0000[0].trackSegmentInfo == 0x18000000) &&
        (D_800D6CA0.unk_28.trackSegmentInfo == 0x18000000)) {
        D_800D6CA0.unk_28.trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2);
    } else if (D_807B3C20.unk_2900 == 0) {
        D_800D6CA0.unk_28.trackSegmentInfo =
            (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE);
    }
}
