#include "global.h"
#include "fzx_course.h"

void func_xk2_800D6D90(s32 arg0, s32 arg1, f32* arg2, f32* arg3) {
    s32 var_v0;
    s32 var_v1;
    f32 temp_fv1;
    s32 temp_ft3;

    temp_fv1 = sqrtf(SQ((f32)arg0) + SQ((f32)arg1));
    if (temp_fv1 <= 16.970562f) {
        var_v0 = 0;
        var_v1 = 0;
    } else {
        temp_fv1 -= 16.970562f;
        temp_ft3 = (func_xk2_800EF5E8((f32)arg1, (f32)arg0) * 4096.0f) / 360.0f;
        if (arg0) {}
        if (arg1) {}
        var_v0 = COS(temp_ft3) * temp_fv1;
        var_v1 = SIN(temp_ft3) * temp_fv1;
        if (var_v0 > 49) {
            var_v1 = (var_v1 * 49) / var_v0;
            var_v0 = 49;
        }
        if (var_v0 < -49) {
            var_v1 = (var_v1 * 49) / (-var_v0);
            var_v0 = -49;
        }
        if (var_v1 > 49) {
            var_v0 = (var_v0 * 49) / var_v1;
            var_v1 = 49;
        }
        if (var_v1 < -49) {
            var_v0 = (var_v0 * 49) / (-var_v1);
            var_v1 = -49;
        }
    }
    *arg2 = var_v0 / 49.0f;
    *arg3 = var_v1 / 49.0f;
}

extern s32 D_xk2_80119918;

void func_xk2_800D6FF0(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        func_8074122C(0x44);
        D_xk2_80119918 ^= 1;
    }
}

extern s32 D_xk2_80104CB4;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CBC;
extern s32 D_xk2_80104CC0;
extern Player gPlayers[];

void func_xk2_800D7058(void) {

    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) || ((D_xk2_80119918 != 0) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_B))) {
        D_xk2_80104CB4 += 300;
    }
    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) || ((D_xk2_80119918 != 0) && (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_A))) {
        if (D_xk2_80104CB4 > 300) {
            D_xk2_80104CB4 -= 300;
        } else if (D_xk2_80104CBC > 300) {
            D_xk2_80104CB8 = D_xk2_80104CB8 + (gPlayers->unk_5C.x.x * 300.0f);
            D_xk2_80104CBC = D_xk2_80104CBC + (gPlayers->unk_5C.x.y * 300.0f);
            D_xk2_80104CC0 = D_xk2_80104CC0 + (gPlayers->unk_5C.x.z * 300.0f);
        }
    }

    if (D_xk2_80104CBC < 0) {
        D_xk2_80104CBC = 0;
    }
    if (D_xk2_80104CB4 < 300) {
        D_xk2_80104CB4 = 300;
    }
    if (D_xk2_80104CB4 > 16000) {
        D_xk2_80104CB4 = 16000;
    }
}

extern u16 D_xk2_8011972C;
extern f32 D_xk2_80128D40;
extern f32 D_xk2_80128D44;

void func_xk2_800D71E8(void) {
    f32 temp_fv0;
    f32 temp_fv1;

    D_xk2_8011972C = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);

    temp_fv0 = (D_xk2_80104CB4 * 0.04) + 15.0;
    switch (D_xk2_8011972C) {
        case BTN_CLEFT:
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            break;
        case BTN_CRIGHT:
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            break;
        case BTN_CUP:
            D_xk2_80104CB8 += temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC += temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 += temp_fv0 * gPlayers->unk_5C.y.z;
            break;
        case BTN_CDOWN:
            D_xk2_80104CB8 -= temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC -= temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gPlayers->unk_5C.y.z;
            break;
        case (BTN_CUP | BTN_CLEFT):
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            D_xk2_80104CB8 += temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC += temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 += temp_fv0 * gPlayers->unk_5C.y.z;
            break;
        case (BTN_CDOWN | BTN_CLEFT):
            temp_fv1 = -1.0f * temp_fv0;
            D_xk2_80104CB8 += temp_fv1 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv1 * D_xk2_80128D40;
            D_xk2_80104CB8 -= temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC -= temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gPlayers->unk_5C.y.z;
            break;
            case (BTN_CUP | BTN_CRIGHT):
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            D_xk2_80104CB8 += temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC += temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 += temp_fv0 * gPlayers->unk_5C.y.z;
            break;
        case (BTN_CDOWN | BTN_CRIGHT):
            D_xk2_80104CB8 += temp_fv0 * D_xk2_80128D44;
            D_xk2_80104CC0 += temp_fv0 * D_xk2_80128D40;
            D_xk2_80104CB8 -= temp_fv0 * gPlayers->unk_5C.y.x;
            D_xk2_80104CBC -= temp_fv0 * gPlayers->unk_5C.y.y;
            D_xk2_80104CC0 -= temp_fv0 * gPlayers->unk_5C.y.z;
            break;
    }

    if (D_xk2_80104CB8 < -8000) {
        D_xk2_80104CB8 = -8000;
    }
    if (D_xk2_80104CB8 > 8000) {
        D_xk2_80104CB8 = 8000;
    }

    if (D_xk2_80104CBC < 0) {
        D_xk2_80104CBC = 0;
    }
    if (D_xk2_80104CBC > 8000) {
        D_xk2_80104CBC = 8000;
    }

    if (D_xk2_80104CC0 < -8000) {
        D_xk2_80104CC0 = -8000;
    }
    if (D_xk2_80104CC0 > 8000) {
        D_xk2_80104CC0 = 8000;
    }
}

extern Controller* D_80119720;
extern s32 D_xk2_80104CB0;
extern s32 D_800D6CA0[];

void func_xk2_800D78A0(void) {
    u16 var_v0;

    var_v0 = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_UP | BTN_DOWN | BTN_LEFT| BTN_RIGHT);
    if (D_xk2_80119918 != 0) {
        if (ABS(D_80119720->stickX) > ABS(D_80119720->stickY)) {
            if (D_80119720->stickX < -60) {
                var_v0 |= BTN_LEFT;
            }
            if (D_80119720->stickX > 60) {
                var_v0 |= BTN_RIGHT;
            }
        } else {
            if (D_80119720->stickY < -60) {
                var_v0 |= BTN_DOWN;
            }
            if (D_80119720->stickY > 60) {
                var_v0 |= BTN_UP;
            }
        }
    }
    
    switch (var_v0) {
        case BTN_UP:
            D_xk2_80104CB0 += 6;
            break;
        case BTN_DOWN:
            D_xk2_80104CB0 -= 6;
            break;
        case BTN_LEFT:
            D_800D6CA0[5] = (D_800D6CA0[5] + 6) % 360;
            break;
        case BTN_RIGHT:
            D_800D6CA0[5] = (D_800D6CA0[5] + 0x162) % 360;
            break;
        default:
            break;
    }

    if (D_xk2_80104CB0 < -90) {
        D_xk2_80104CB0 = -90;
        D_xk2_80104CB0 = -90;
    }
    if (D_xk2_80104CB0 > 90) {
        D_xk2_80104CB0 = 90;
    }
}

extern s32 D_xk2_800F6850[];
extern s32 D_xk2_800F6860[];
extern s32 D_xk2_800F6874[];
extern s32 D_xk2_800F6888[];
extern s32 D_xk2_800F689C[];
extern s32 D_xk2_800F68B8[];
extern s32 D_xk2_800F68D4[];
extern s32 D_xk2_800F68F0[];
extern s32 D_xk2_800F7040;

extern s32 D_xk1_80030628;
extern s32 D_xk1_80030648;
extern s32 D_xk1_8003064C;
extern s32 D_xk1_80030650;
extern s32 D_xk1_80030654;

void func_xk2_800D7A4C(s32 arg0) {
    s32 var_v0;
    s32 var_v1;
    s32 var_a2;
    s32 var_a3;

    var_v0 = gCourseCtx.courseData.pit[D_800D6CA0[3]] + 1;
    var_v1 = gCourseCtx.courseData.dash[D_800D6CA0[3]] + 1;
    var_a2 = gCourseCtx.courseData.dirt[D_800D6CA0[3]] + 1;
    var_a3 = gCourseCtx.courseData.ice[D_800D6CA0[3]] + 1;

    var_v0 = D_xk2_800F6860[var_v0];
    var_v1 = D_xk2_800F6850[var_v1];
    var_a2 = D_xk2_800F6874[var_a2];
    var_a3 = D_xk2_800F6888[var_a3];
    switch (arg0) {
        case 0:
            var_v0 = ~D_xk2_800F6860[D_xk1_80030648 + 1];
            var_v1 &= var_v0;
            var_a2 &= var_v0;
            var_a3 &= var_v0;
            var_v0 = D_xk2_800F6860[D_xk1_80030648 + 1];
            break;
        case 1:
            var_v1 = ~D_xk2_800F6850[D_xk1_8003064C + 1];
            var_v0 &= var_v1;
            var_a2 &= var_v1;
            var_a3 &= var_v1;
            var_v1 = D_xk2_800F6850[D_xk1_8003064C + 1];
            break;
        case 2:
            var_a2 = ~D_xk2_800F6874[D_xk1_80030650 + 1];
            var_v0 &= var_a2;
            var_v1 &= var_a2;
            var_a3 &= var_a2;
            var_a2 = D_xk2_800F6874[D_xk1_80030650 + 1];
            break;
        case 3:
            var_a3 = ~D_xk2_800F6888[D_xk1_80030654 + 1];
            var_v0 &= var_a3;
            var_v1 &= var_a3;
            var_a2 &= var_a3;
            var_a3 = D_xk2_800F6888[D_xk1_80030654 + 1];
            break;
    }

    if (gCourseCtx.courseData.pit[D_800D6CA0[3]] != D_xk2_800F689C[var_v0]) {
        func_8074122C(0x27);
        gCourseCtx.courseData.pit[D_800D6CA0[3]] = D_xk2_800F689C[var_v0];
        D_xk2_800F7040 = 3;
    }

    if (gCourseCtx.courseData.dash[D_800D6CA0[3]] != D_xk2_800F68B8[var_v1]) {
        func_8074122C(0x27);
        gCourseCtx.courseData.dash[D_800D6CA0[3]] = D_xk2_800F68B8[var_v1];
        D_xk2_800F7040 = 3;
        if (D_xk1_80030628 != 1) {
            func_xk2_800EE664(0x14);
        }
    }

    if (gCourseCtx.courseData.dirt[D_800D6CA0[3]] != D_xk2_800F68D4[var_a2]) {
        func_8074122C(0x27);
        gCourseCtx.courseData.dirt[D_800D6CA0[3]] = D_xk2_800F68D4[var_a2];
        D_xk2_800F7040 = 3;
    }

    if (gCourseCtx.courseData.ice[D_800D6CA0[3]] != D_xk2_800F68F0[var_a3]) {
        func_8074122C(0x27);
        gCourseCtx.courseData.ice[D_800D6CA0[3]] = D_xk2_800F68F0[var_a3];
        D_xk2_800F7040 = 3;
    }
}

extern s32 D_xk2_800F7040;
extern unk_807B3C20 D_807B3C20;
extern u8 D_xk2_80104CA7;

void func_xk2_800D7D80(void) {

    if (D_xk1_80030628 != 0) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    if ((D_xk2_80104CA7 != 0) && (D_xk1_80030648 != 4)) {
        func_8074122C(0x20);
        return;
    }
    if (D_xk1_80030648 == 4) {
        if (gCourseCtx.courseData.pit[D_800D6CA0[3]] != -1) {
            func_8074122C(0x27);
            func_xk2_800EF78C();
            gCourseCtx.courseData.pit[D_800D6CA0[3]] = -1;
            D_xk2_800F7040 = 3;
        }
    } else if (D_xk1_80030648 != gCourseCtx.courseData.pit[D_800D6CA0[3]]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(0);
    }
}

extern unk_807B3C20 D_807B3C20;

void func_xk2_800D7EB8(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 1) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.dash[i] != -1) {
            var_v1++;
        }
    }
    if (D_xk1_8003064C == 3) {
        if (gCourseCtx.courseData.dash[D_800D6CA0[3]] != -1) {
            func_8074122C(0x27);
            func_xk2_800EF78C();
            gCourseCtx.courseData.dash[D_800D6CA0[3]] = -1;
            D_xk2_800F7040 = 3;
        }
    } else {
        if ((var_v1 >= 32) && (gCourseCtx.courseData.dash[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
        } else if (D_xk1_8003064C != gCourseCtx.courseData.dash[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_xk2_800D7A4C(1);
        }
    }
}

void func_xk2_800D8018(void) {

    if (D_xk1_80030628 != 2) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    if ((D_xk2_80104CA7 != 0) && (D_xk1_80030650 != 4)) {
        func_8074122C(0x20);
        return;
    }
    if (D_xk1_80030650 == 4) {
        if (gCourseCtx.courseData.dirt[D_800D6CA0[3]] != -1) {
            func_8074122C(0x27);
            func_xk2_800EF78C();
            gCourseCtx.courseData.dirt[D_800D6CA0[3]] = -1;
            D_xk2_800F7040 = 3;
        }
    } else if (D_xk1_80030650 != gCourseCtx.courseData.dirt[D_800D6CA0[3]]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(2);
    }
}

void func_xk2_800D8154(void) {

    if (D_xk1_80030628 != 3) {
        return;
    }
    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    if ((D_xk2_80104CA7 != 0) && (D_xk1_80030654 != 4)) {
        func_8074122C(0x20);
        return;
    }
    if (D_xk1_80030654 == 4) {
        if (gCourseCtx.courseData.ice[D_800D6CA0[3]] != -1) {
            func_8074122C(0x27);
            func_xk2_800EF78C();
            gCourseCtx.courseData.ice[D_800D6CA0[3]] = -1;
            D_xk2_800F7040 = 3;
        }
    } else if (D_xk1_80030654 != gCourseCtx.courseData.ice[D_800D6CA0[3]]) {
        func_xk2_800EF78C();
        func_xk2_800D7A4C(3);
    }
}

extern s32 D_xk1_80030658;
extern s32 D_xk1_8003065C;
extern s32 D_xk1_80030660;
extern s32 D_xk1_80030664;
extern s32 D_xk1_80030668;

void func_xk2_800D8290(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 4) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.jump[i] != -1) {
            var_v1++;
        }
    }
    if (D_xk1_80030658 == 3) {
        if (gCourseCtx.courseData.jump[D_800D6CA0[3]] != -1) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.jump[D_800D6CA0[3]] = -1;
        }
    } else {
        if ((var_v1 >= 8) && (gCourseCtx.courseData.jump[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
        } else if (D_xk1_80030658 != gCourseCtx.courseData.jump[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.jump[D_800D6CA0[3]] = D_xk1_80030658;
        }
    }
}

void func_xk2_800D8418(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 5) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_PIPE:
        case TRACK_SHAPE_CYLINDER:
        case TRACK_SHAPE_HALF_PIPE:
        case TRACK_SHAPE_AIR:
            func_8074122C(0x20);
            return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.landmine[i] != -1) {
            var_v1++;
        }
    }
    if (D_xk1_8003065C == 3) {
        if (gCourseCtx.courseData.landmine[D_800D6CA0[3]] != -1) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.landmine[D_800D6CA0[3]] = -1;
        }
    } else {
        if ((var_v1 >= 8) && (gCourseCtx.courseData.landmine[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
        } else if (D_xk1_8003065C != gCourseCtx.courseData.landmine[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.landmine[D_800D6CA0[3]] = D_xk1_8003065C;
        }
    }
}

void func_xk2_800D85A0(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 6) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            switch (D_807B3C20.unk_0000[D_800D6CA0[3]].prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    break;
                default:
                    func_8074122C(0x20);
                    return;
            }
            break;
        case TRACK_SHAPE_ROAD:
        case TRACK_SHAPE_BORDERLESS_ROAD:
            break;
        default:
            func_8074122C(0x20);
            return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.gate[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.building[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.sign[i] != -1) {
            var_v1++;
        }
    }

    if (D_xk1_80030660 == 3) {
        if (gCourseCtx.courseData.gate[D_800D6CA0[3]] != -1) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.gate[D_800D6CA0[3]] = -1;
        }
    } else {
        if ((var_v1 >= 16) && (gCourseCtx.courseData.gate[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
            return;
        }
        if (D_xk1_80030660 != gCourseCtx.courseData.gate[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.gate[D_800D6CA0[3]] = D_xk1_80030660;
        }
    }
}

void func_xk2_800D8778(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 7) {
        return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.gate[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.building[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.sign[i] != -1) {
            var_v1++;
        }
    }
    if (D_xk1_80030664 == 15) {
        if (gCourseCtx.courseData.building[D_800D6CA0[3]] != -1) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.building[D_800D6CA0[3]] = -1;
        }
    } else {
        if ((var_v1 >= 0x10) && (gCourseCtx.courseData.building[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
            return;
        }
        if (D_xk1_80030664 != gCourseCtx.courseData.building[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.building[D_800D6CA0[3]] = D_xk1_80030664;
        }
    }
}

void func_xk2_800D88D8(void) {
    s32 var_v1;
    s32 i;

    var_v1 = 0;
    if (D_xk1_80030628 != 8) {
        return;
    }

    switch (D_807B3C20.unk_0000[D_800D6CA0[3]].trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_AIR:
            switch (D_807B3C20.unk_0000[D_800D6CA0[3]].prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    break;
                default:
                    func_8074122C(0x20);
                    return;
            }
            break;
        case TRACK_SHAPE_ROAD:
        case TRACK_SHAPE_BORDERLESS_ROAD:
            break;
        default:
            func_8074122C(0x20);
            return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.gate[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.building[i] != -1) {
            var_v1++;
        }
        if (gCourseCtx.courseData.sign[i] != -1) {
            var_v1++;
        }
    }

    if (D_xk1_80030668 == 5) {
        if (gCourseCtx.courseData.sign[D_800D6CA0[3]] != -1) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.sign[D_800D6CA0[3]] = -1;
        }
    } else {
        if ((var_v1 >= 16) && (gCourseCtx.courseData.sign[D_800D6CA0[3]] == -1)) {
            func_8074122C(0x20);
            return;
        }
        if (D_xk1_80030668 != gCourseCtx.courseData.sign[D_800D6CA0[3]]) {
            func_xk2_800EF78C();
            func_8074122C(0x27);
            gCourseCtx.courseData.sign[D_800D6CA0[3]] = D_xk1_80030668;
        }
    }
}

void func_xk2_800D8AB0(void) {

}

extern s32 D_xk1_80030614;
extern s32 D_xk1_80030624;
extern s32 D_xk2_800F6828;

#ifdef IMPORT_DATA
void func_xk2_800D8AB8(void) {
    s32 temp_a1;
    s32 temp_v1;
    CourseSegment* temp_v0;
    s32 sp2C[] = { TRACK_SHAPE_ROAD, TRACK_SHAPE_WALLED_ROAD, TRACK_SHAPE_BORDERLESS_ROAD, TRACK_SHAPE_TUNNEL, TRACK_SHAPE_PIPE, TRACK_SHAPE_HALF_PIPE, TRACK_SHAPE_CYLINDER, TRACK_SHAPE_AIR };

    if ((D_80119720->buttonPressed & BTN_A) && (D_xk2_800F6828 >= 0x38) && (D_800D6CA0[2] != 3) && (D_xk1_80030614 == 2)) {
        if (D_807B3C20.unk_2900 < 4) {
            func_8074122C(0x20);
            return;
        }
        if (D_800D6CA0[3] == 0) {
            func_8074122C(0x20);
            return;
        }
        if (D_800D6CA0[3] != -1) {
            temp_v0 = &D_807B3C20.unk_0000[D_800D6CA0[3]];
            func_807032B0(temp_v0->pos, temp_v0->next->pos);

            temp_a1 = D_xk1_80030624;
            temp_v1 = sp2C[temp_a1];
            if (((temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK) != sp2C[temp_a1]) && ((temp_v0->next->trackSegmentInfo & TRACK_SHAPE_MASK) == sp2C[temp_a1])) {
                switch (temp_v0->prev->trackSegmentInfo & TRACK_SHAPE_MASK) {
                    case TRACK_SHAPE_ROAD:
                    case TRACK_SHAPE_BORDERLESS_ROAD:
                        break;
                }
            }
            switch (temp_a1) {
                case 0:
                case 1:
                case 2:
                case 7:
                    func_xk2_800DCF2C();
                    func_xk2_800DCFE0();
                    func_xk2_800DD0AC();
                    func_xk2_800DD568();
                    break;
                case 3:
                    func_xk2_800DD178();
                    break;
                case 4:
                case 5:
                case 6:
                    func_xk2_800DD244();
                    func_xk2_800DD350();
                    func_xk2_800DD45C();
                    break;
                default:
                    break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800D8AB8.s")
#endif

void func_xk2_800D8CC4(void) {

    if (!(D_80119720->buttonPressed & BTN_A)) {
        return;
    } 
    if (D_xk2_800F6828 < 0x38) {
        return;
    } 
    if (D_800D6CA0[2] == 2 || D_800D6CA0[2] == 1 || D_800D6CA0[2] == 3 || D_800D6CA0[2] == 16) {
        return;
    }

    if (D_xk1_80030614 != 3) {
        return;
    }

    if (D_807B3C20.unk_2900 < 4) {
        func_8074122C(0x20);
        return;
    }
    func_xk2_800D7EB8();
    func_xk2_800D7D80();
    func_xk2_800D8018();
    func_xk2_800D8154();
    func_xk2_800D8290();
    func_xk2_800D8418();
    func_xk2_800D85A0();
    func_xk2_800D8778();
    func_xk2_800D88D8();
}

extern s32 D_8076C958;
extern f32 D_xk2_800F6834;

void func_xk2_800D8DAC(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    f32 sp28;
    f32 sp24;

    D_80119720 = &gControllers[gPlayerControlPorts[0]];

    temp_a0 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;
    func_xk2_800D6D90(temp_a0, temp_a1, &sp28, &sp24);
    D_80119720->stickX = sp28 * 64.0f;
    D_80119720->stickY = sp24 * 64.0f;
    temp_a0 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;
    temp_a2 = SQ(temp_a0) + SQ(temp_a1);
    if (temp_a2 > 100) {
        if (D_8076C958 > 4) {
            D_8076C958 -= 4;
        }
        func_xk2_800EE640(temp_a0, temp_a1, temp_a2);
    }
    if (temp_a2 > 1600) {
        if (D_xk2_800F6834 < 0.5f) {
            D_xk2_800F6834 += 0.05f;
        }
    } else {
        D_xk2_800F6834 = 0.15f;
    }
}

extern s32 D_8076C950;
extern s32 D_8076C964;
extern volatile u8 D_80794E14;
extern s32 D_xk1_800305F8;
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;
extern s32 D_xk2_800F6824;
extern s32 D_xk2_800F703C;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F704C;
extern s32 D_xk2_800F705C;
extern s16 D_xk2_80119728;
extern s16 D_xk2_8011972A;
extern s16 D_xk2_8011972E;
extern CourseSegment D_xk2_80119748;
extern CourseSegment* D_xk2_801197EC;
extern unk_80026914 D_xk1_80032880;

void func_xk2_800D8F04(void) {
    s32 pad[37];
    s32 temp_v1;
    s32 sp1C;

    D_80119720 = &gControllers[gPlayerControlPorts[0]];

    temp_v1 = D_xk2_800F704C;
    if (temp_v1 != -1) {
        D_xk2_801197EC = &D_807B3C20.unk_0000[D_xk2_800F704C];
    } else {
        D_xk2_801197EC = D_807B3C20.unk_0000;
    }
    D_xk2_80119748 = *D_xk2_801197EC;

    if (D_80119720) {}
    func_xk2_800DBEE4();
    if (D_800D6CA0[2] == 0) {
        D_xk1_8003A550 = D_xk2_800F6824;
        D_xk1_8003A554 = D_xk2_800F6828;
    }
    if (D_80794E14 == 1) {
        func_xk1_80027CFC(&D_xk1_80032880, &D_xk1_8003A550, &D_xk1_8003A554);
        return;
    }
    func_xk2_800D8AB0();
    D_xk2_80119728 = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_UP | BTN_DOWN | BTN_LEFT | BTN_RIGHT);
    D_xk2_8011972A = gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_UP | BTN_DOWN | BTN_LEFT | BTN_RIGHT);
    D_xk2_8011972C = gControllers[gPlayerControlPorts[0]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
    D_xk2_8011972E = gControllers[gPlayerControlPorts[0]].buttonPressed & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
    D_xk2_801197EC = &D_807B3C20.unk_0000[D_xk2_800F704C];
    D_xk2_80128D40 = SIN((D_800D6CA0[5] << 12) / 360);
    D_xk2_80128D44 = COS((D_800D6CA0[5] << 12) / 360);
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) {
        D_xk2_800F703C = -1;
    }
    func_xk2_800DF54C();
    func_xk2_800F5F2C();
    if (D_8076C950 == 0) {
        func_xk2_800D7058();
        func_xk2_800D71E8();
        func_xk2_800D78A0();
    }
    func_xk2_800DF2EC();
    sp1C = D_xk2_800F705C;
    func_xk2_800E9A58();
    if ((sp1C != -1) && (D_xk2_800F705C == -1)) {
        func_8074122C(0x23);
    }
    func_xk2_800DEC1C();
    func_xk2_800DE8D0();
    func_xk2_800DECF0();
    if (func_xk2_800E6B3C() == 0) {
        if (D_8076C964 == 1) {
            D_xk2_800F7044 = 1;
        } else {
            D_xk2_800F7044 = 0;
        }
    }
    if ((D_xk2_800F6824 < 230) || (D_xk2_800F6824 >= 298) || (D_xk2_800F6828 < 202) || (D_xk2_800F6828 >= 222)) {
        func_xk2_800D8AB8();
        func_xk2_800D8CC4();
        func_xk2_800DC67C();
        func_xk2_800DC58C();
        func_xk2_800DC4E4();
        func_xk2_800F07A4();
    }
    func_xk2_800DD8C8();
    func_xk2_800DCCD8();
    func_xk2_800DB924();
    func_xk2_800EFF40();
    func_xk2_800DC018();
    func_xk2_800DC428();
    func_xk2_800DCDD0();
    func_xk1_80027CFC(&D_xk1_80032880, &D_xk1_8003A550, &D_xk1_8003A554);
    if ((D_80119720->buttonPressed & BTN_A) && (D_800D6CA0[2] == 0)) {
        D_xk1_8003A550 = D_xk2_800F6824;
        D_xk1_8003A554 = D_xk2_800F6828;
        func_xk1_80027DC8(&D_xk1_80032880, &D_xk1_8003A550, &D_xk1_8003A554);
        if (D_xk1_800305F8 != 0) {
            D_800D6CA0[2] = 1;
        }
    }
    func_xk2_800D6FF0();
}

extern s32 D_800D11C8[];
extern f32 D_xk2_800F6834;
extern f32 D_xk2_800F692C[];

void func_xk2_800D934C(void) {
    f32 temp_fv0;
    s32 var_v0;
    s32 temp;
    s32 temp_a1;
    s32 temp_a2;

    D_80119720 = &gControllers[*gPlayerControlPorts];

    temp_a1 = D_80119720->stickX;
    temp_a2 = D_80119720->stickY;
    if ((SQ(temp_a1) + SQ(temp_a2)) != 0) {
        D_xk2_800F703C = -1;
    }

    var_v0 = D_800D11C8[4];
    if ((var_v0 < 0) || (var_v0 >= 9)) {
        D_800D11C8[4] = var_v0 = 4;
    }
    temp_fv0 = D_xk2_800F692C[var_v0] * D_xk2_800F6834;
    temp = D_xk2_800F6828;
    D_xk2_800F6824 += (temp_fv0 * temp_a1) / 2;
    D_xk2_800F6828 -= (temp_fv0 * temp_a2) / 2;
    if ((temp >= 36) && (D_xk2_800F6828 < 36)) {
        func_8074122C(0x23);
    }

    if (D_xk2_800F6824 < 24) {
        D_xk2_800F6824 = 24;
    }
    if (D_xk2_800F6824 > 295) {
        D_xk2_800F6824 = 295;
    }
    if (D_xk2_800F6828 < 20) {
        D_xk2_800F6828 = 21;
    }
    if (D_xk2_800F6828 > 212) {
        D_xk2_800F6828 = 212;
    }
}

void func_xk2_800D950C(void) {
    f32 temp_fv0;
    s32 var_a0;
    s32 var_v0;

    var_v0 = D_80119720->stickX;
    var_a0 = D_80119720->stickY;

    if ((SQ(var_v0) + SQ(var_a0)) < 100) {
        return;
    }
    if (var_v0 < 0) {
        var_v0 = -var_v0 * var_v0;
    } else {
        var_v0 = var_v0 * var_v0;
    }
    if (var_a0 < 0) {
        var_a0 = -var_a0 * var_a0;
    } else {
        var_a0 = var_a0 * var_a0;
    }
    temp_fv0 = D_xk2_800F692C[D_800D11C8[4]] * D_xk2_800F6834;
    D_xk2_800F6824 += (temp_fv0 * var_v0) / 128;
    D_xk2_800F6828 -= (temp_fv0 * var_a0) / 128;
    if (D_xk2_800F6824 < 24) {
        D_xk2_800F6824 = 24;
    }
    if (D_xk2_800F6824 > 295) {
        D_xk2_800F6824 = 295;
    }
    
    if (D_xk2_800F6828 < 56) {
        D_xk2_800F6828 = 57;
    }
    if (D_xk2_800F6828 > 212) {
        D_xk2_800F6828 = 212;
    }
}

extern unk_80128690 D_80128690[];
extern f32 D_xk2_80119730;
extern f32 D_xk2_80119738;
extern unk_807B3C20 D_807B6528;

void func_xk2_800D9670(void) {
    CourseSegment* temp_s0_2;
    CourseSegment* temp_s1_2;
    bool var_s1;
    s8 temp_s0;
    s8 temp_s1;
    s32 var_s2;
    s32 var_s3;
    bool sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    f32 var_fa0;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 i;

    temp_s0 = D_80119720->stickX;
    temp_s1 = D_80119720->stickY;
    var_s2 = 0;
    var_s3 = 0;
    if ((SQ(temp_s0) + SQ(temp_s1)) < 100) {
        return;
    }

    if (gCurrentCourseInfo->length > 300000.0f) {
        func_xk2_800EE664(0x1D);
        func_8074122C(0x20);
        return;
    }
    if (D_80119720->buttonCurrent & BTN_Z) {
        sp5C = D_xk2_800F6834 * 9.0f;
    } else {
        sp5C = D_xk2_800F6834;
    }

    sp64 = D_xk2_80119730;
    sp60 = D_xk2_80119738;
    if (func_xk1_8002DAD4() == 1) {

        if (ABS(temp_s0) > 10) {
            if (temp_s0 < 0) {
                var_s2 = -1;
            } else {
                var_s2 = 1;
            }
        }

        if (ABS(temp_s1) > 10) {
            if (temp_s1 < 0) {
                var_s3 = -1;
            } else {
                var_s3 = 1;
            }
        }

        if (((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3)) >= 0.0f) {
            var_fa0 = ((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3));
        } else {
            var_fa0 = -((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3));
        }
        if (var_fa0 > 0.6) {
            if (((D_xk2_80128D44 * var_s2) + (D_xk2_80128D40 * var_s3)) > 0.0f) {
                D_xk2_80119730 += 10.0f;
            } else {
                D_xk2_80119730 -= 10.0f;
            }
        }

        if ( (D_xk2_80128D40 * var_s2) >= (D_xk2_80128D44 * var_s3)) {
            var_fa0 = (D_xk2_80128D40 * var_s2) - (D_xk2_80128D44 * var_s3);
        } else {
            var_fa0 = -((D_xk2_80128D40 * var_s2) - (D_xk2_80128D44 * var_s3));
        }
        if (var_fa0 > 0.6) {
            if ((D_xk2_80128D44 * var_s3) < (D_xk2_80128D40 * var_s2)) {
                D_xk2_80119738 += 10.0f;
            } else {
                D_xk2_80119738 -= 10.0f;
            }
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_80119730 += ((D_xk2_80128D44 * sp5C) * temp_s0) + ((D_xk2_80128D40 * sp5C) * temp_s1);
            D_xk2_80119738 += ((D_xk2_80128D40 * sp5C) * temp_s0) - ((D_xk2_80128D44 * sp5C) * temp_s1);
        }
    }
    D_xk2_80119730 = (Math_Round(D_xk2_80119730) / 10) * 10;
    D_xk2_80119738 = (Math_Round(D_xk2_80119738) / 10) * 10;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_807B3C20.unk_0000[i];
        temp_s1_2 = &D_807B6528.unk_0000[i];
        temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
        temp_s0_2->pos.x = (((s32) temp_s0_2->pos.x / 10) * 10);
        temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
        temp_s0_2->pos.z = (((s32) temp_s0_2->pos.z / 10) * 10);
    }
    var_s1 = false;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_807B3C20.unk_0000[i];
        if (func_807032B0(temp_s0_2->pos, temp_s0_2->prev->pos) < 498.0f) {
            var_s1 = true;
        }
        if (func_807032B0(temp_s0_2->pos, temp_s0_2->next->pos) < 498.0f) {
            var_s1 = true;
        }
    }
    if (var_s1) {
        func_8074122C(0x20);
        D_xk2_80119730 = sp64;
        D_xk2_80119738 = sp60;

        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }
            temp_s0_2 = &D_807B3C20.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
            temp_s0_2->pos.x = (((s32) temp_s0_2->pos.x / 10) * 10);
            temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
            temp_s0_2->pos.z = (((s32) temp_s0_2->pos.z / 10) * 10);
        }
    }
    sp80 = 15000;
    sp7C = -15000;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_s0_2 = &D_807B3C20.unk_0000[i];
        if (temp_s0_2->pos.x < sp80) {
            sp70 = i;
            sp80 = Math_Round(temp_s0_2->pos.x);
        }
        if (sp7C < temp_s0_2->pos.x) {
            sp6C = i;
            sp7C = Math_Round(temp_s0_2->pos.x);
        }
    }
    sp84 = false;
    if (sp80 < -15000) {
        sp84 = true;
        D_xk2_80119730 = -15000 - Math_Round(D_807B6528.unk_0000[sp70].pos.x);
    }
    if (sp7C > 15000) {
        sp84 = true;
        D_xk2_80119730 = 15000 - Math_Round(D_807B6528.unk_0000[sp6C].pos.x);
    }

    if (sp84) {
        func_8074122C(0x20);

        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_807B3C20.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.x = Math_Round(D_xk2_80119730) + temp_s1_2->pos.x;
            temp_s0_2->pos.x = (Math_Round(temp_s0_2->pos.x) / 10) * 10;
        }
    }
    sp84 = false;

    sp78 = 15000;
    sp74 = -15000;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_807B3C20.unk_0000[i];
        if (temp_s0_2->pos.z < sp78) {
            sp70 = i;
            sp78 = Math_Round(temp_s0_2->pos.z);
        }
        if (sp74 < temp_s0_2->pos.z) {
            sp6C = i;
            sp74 = Math_Round(temp_s0_2->pos.z);
        }
    }
    if (sp78 < -15000) {
        sp84 = true;
        D_xk2_80119738 = -15000 - Math_Round(D_807B6528.unk_0000[sp70].pos.z);
    }
    if (sp74 > 15000) {
        sp84 = true;
        D_xk2_80119738 = 15000 - Math_Round(D_807B6528.unk_0000[sp6C].pos.z);
    }
    if (sp84) {
        func_8074122C(0x20);

        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_807B3C20.unk_0000[i];
            temp_s1_2 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.z = Math_Round(D_xk2_80119738) + temp_s1_2->pos.z;
            temp_s0_2->pos.z = (Math_Round(temp_s0_2->pos.z) / 10) * 10;
        }
    }
    D_xk2_800F7040 = 3;
}

extern f32 D_xk2_80119734;

void func_xk2_800DA288(void) {
    CourseSegment* temp_s0_2;
    CourseSegment* temp_s1;
    s32 i;
    s8 temp_s0;
    s8 temp_v0;
    bool var_s1;
    bool var_s0;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    f32 sp54;
    f32 sp50;

    temp_v0 = D_80119720->stickX;
    temp_s0 = D_80119720->stickY;

    if (ABS(temp_v0) > ABS(temp_s0)) {
        return;
    }

    if ((SQ(temp_v0) + SQ(temp_s0)) < 100) {
        return;
    }
    if (gCurrentCourseInfo->length > 300000.0f) {
        func_xk2_800EE664(0x1D);
        func_8074122C(0x20);
        return;
    }
    if (D_80119720->buttonCurrent & BTN_Z) {
        sp50 = D_xk2_800F6834 * 6.0f;
    } else {
        sp50 = D_xk2_800F6834;
    }

    sp54 = D_xk2_80119734;
    if (func_xk1_8002DAD4(D_80119720) == 1) {
        if (temp_s0 < 0) {
            D_xk2_80119734 -= 10.0f;
        } else {
            D_xk2_80119734 += 10.0f;
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_80119734 += sp50 * temp_s0;
        }
    }

    D_xk2_80119734 = (Math_Round(D_xk2_80119734) / 10) * 10;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_807B3C20.unk_0000[i];
        temp_s1 = &D_807B6528.unk_0000[i];
        temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
        temp_s0_2->pos.y = ((s32) temp_s0_2->pos.y / 10) * 10;
    }
    var_s1 = false;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_807B3C20.unk_0000[i];
        if (func_807032B0(temp_s0_2->pos, temp_s0_2->prev->pos) < 498.0f) {
            var_s1 = true;
        }

        if (func_807032B0(temp_s0_2->pos, temp_s0_2->next->pos) < 498.0f) {
            var_s1 = true;
        }
    }
    if (var_s1) {
        func_8074122C(0x20);
        D_xk2_80119734 = sp54;
        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            temp_s0_2 = &D_807B3C20.unk_0000[i];
            temp_s1 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
            temp_s0_2->pos.y = ((s32) temp_s0_2->pos.y / 10) * 10;
        }

    }
    sp64 = 10000;
    sp60 = 0;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0_2 = &D_807B3C20.unk_0000[i];
        if (temp_s0_2->pos.y < sp64) {
            sp5C = i;
            sp64 = Math_Round(temp_s0_2->pos.y);
        }
        if (sp60 < temp_s0_2->pos.y) {
            sp58 = i;
            sp60 = Math_Round(temp_s0_2->pos.y);
        }
    }
    var_s0 = false;
    if (sp64 < 0) {
        var_s0 = true;
        D_xk2_80119734 = -Math_Round(D_807B6528.unk_0000[sp5C].pos.y);
    }
    if (sp60 > 5000) {
        var_s0 = true;
        D_xk2_80119734 = 5000 - Math_Round(D_807B6528.unk_0000[sp58].pos.y);
    }
    if (var_s0) {
        func_8074122C(0x20);
        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }
            temp_s0_2 = &D_807B3C20.unk_0000[i];
            temp_s1 = &D_807B6528.unk_0000[i];
            temp_s0_2->pos.y = Math_Round(D_xk2_80119734) + temp_s1->pos.y;
            temp_s0_2->pos.y = (Math_Round(temp_s0_2->pos.y) / 10) * 10;
        }
    }
    D_xk2_800F7040 = 3;
}

extern s32 D_xk2_8011973C;

extern s32 D_xk2_8011973C;

void func_xk2_800DA984(void) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;
    f32 temp_fa0_4;
    s32 sp5C;
    s32 var_s0;
    s8 temp_s1;
    s8 temp_v1;
    s32 i;

    temp_s1 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;
    sp5C = 0x2710;
    var_s0 = -0x2710;

    if (ABS(temp_s1) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s1) + SQ(temp_v1)) < 100) {
        return;
    }

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s1 < 0) {
            D_xk2_8011973C -= 10;
        } else {
            D_xk2_8011973C += 10;
        }
    } else {
        if (func_xk1_8002DAD4() >= 9) {
            D_xk2_8011973C += Math_Round(temp_s1 * D_xk2_800F6834);
        }
    }

    D_xk2_8011973C = (D_xk2_8011973C / 10) * 10;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_fv1 = D_807B6528.unk_0000[i].radiusRight;
        temp_fa0 = D_807B6528.unk_0000[i].radiusLeft;
        temp_fa1 = 1000.0f - ((temp_fv1 + temp_fa0) / 2);
        if (sp5C > temp_fa1) {
            sp5C = temp_fa1;
        }

        if (var_s0 < 50.0f - temp_fa0) {
            var_s0 = 50.0f - temp_fa0;
        }
        if (var_s0 < 50.0f - temp_fv1) {
            var_s0 = 50.0f - temp_fv1;
        }
    }

    if (D_xk2_8011973C > sp5C) {
        D_xk2_8011973C = sp5C;
    }
    if (D_xk2_8011973C < var_s0) {
        D_xk2_8011973C = var_s0;
    }
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        D_807B3C20.unk_0000[i].radiusLeft = D_807B6528.unk_0000[i].radiusLeft + D_xk2_8011973C;
        D_807B3C20.unk_0000[i].radiusRight = D_807B6528.unk_0000[i].radiusRight + D_xk2_8011973C;
        D_807B3C20.unk_0000[i].radiusLeft = (Math_Round(D_807B3C20.unk_0000[i].radiusLeft) / 10) * 10;
        D_807B3C20.unk_0000[i].radiusRight = (Math_Round(D_807B3C20.unk_0000[i].radiusRight) / 10) * 10;
        if (D_807B3C20.unk_0000[i].radiusLeft < 50.0f) {
            D_807B3C20.unk_0000[i].radiusLeft = 50.0f;
        }
        if (D_807B3C20.unk_0000[i].radiusRight < 50.0f) {
            D_807B3C20.unk_0000[i].radiusRight = 50.0f;
        }

        temp_fa0_4 = D_807B3C20.unk_0000[i].radiusRight + D_807B3C20.unk_0000[i].radiusLeft;
        if (temp_fa0_4 > 2000.0f) {
            D_807B3C20.unk_0000[i].radiusLeft = D_807B3C20.unk_0000[i].radiusLeft - ((temp_fa0_4 / 2) - 1000.0f);
            D_807B3C20.unk_0000[i].radiusRight = 2000.0f - D_807B3C20.unk_0000[i].radiusLeft;
        }
    }
    D_xk2_800F7040 = 3;
}

void func_xk2_800DADEC(void) {
    s32 pad[13];
    s32 i;
    s8 temp_s3;
    s8 temp_v1;

    temp_s3 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;

    if (ABS(temp_s3) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s3) + SQ(temp_v1)) < 100) {
        return;
    }

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s3 < 0) {
            for (i = 0; i < D_807B3C20.unk_2900; i++) {
                if (D_80128690[i].unk_08 == 0) {
                    continue;
                }

                gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] + 357 + 360) % 360;
                gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] / 3) * 3;
            }
        } else {
            for (i = 0; i < D_807B3C20.unk_2900; i++) {
                if (D_80128690[i].unk_08 == 0) {
                    continue;
                }

                gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] + 3 + 360) % 360;
                gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] / 3) * 3;
            }
        }
    } else if (func_xk1_8002DAD4() >= 9) {
        for (i = 0; i < D_807B3C20.unk_2900; i++) {
            if (D_80128690[i].unk_08 == 0) {
                continue;
            }

            gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] + Math_Round((temp_s3 * D_xk2_800F6834) / 6) + 360) % 360;
            gCourseCtx.courseData.bankAngle[i] = (gCourseCtx.courseData.bankAngle[i] / 3) * 3;
        }
    }
    func_807034F0(gCurrentCourseInfo);
    D_xk2_800F7040 = 3;
}

extern s32 D_xk2_80119740;

void func_xk2_800DB154(void) {
    CourseSegment* temp_s0;
    CourseSegment* temp_v1_2;
    s32 var_s0;
    s32 var_s3;
    f32 temp_fv0;
    s32 temp_ft2;
    s8 temp_s1;
    s8 temp_v1;
    s32 i;

    temp_s1 = D_80119720->stickX;
    temp_v1 = D_80119720->stickY;
    var_s0 = 0x2710;
    var_s3 = -0x2710;
    if (ABS(temp_s1) < ABS(temp_v1)) {
        return;
    }

    if ((SQ(temp_s1) + SQ(temp_v1)) < 100) {
        return;
    }
    

    if (func_xk1_8002DAD4() == 1) {
        if (temp_s1 < 0) {
            D_xk2_80119740 -= 10;
        } else {
            D_xk2_80119740 += 10;
        }
    } else if (func_xk1_8002DAD4() >= 9) {
        D_xk2_80119740 += Math_Round(temp_s1 * D_xk2_800F6834);
    }

    D_xk2_80119740 = (D_xk2_80119740 / 10) * 10;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        temp_v1_2 = &D_807B6528.unk_0000[i];
        temp_fv0 = temp_v1_2->radiusRight - 50.0f;
        if (var_s0 > temp_fv0) {
            var_s0 = temp_fv0;
        }
        temp_fv0 = (temp_v1_2->radiusLeft - 50.0f) * -1.0f;
        if (var_s3 < temp_fv0) {
            var_s3 = temp_fv0;
        }
    }
    

    if (D_xk2_80119740 > var_s0) {
        D_xk2_80119740 = var_s0;
    }
    if (D_xk2_80119740 < var_s3) {
        D_xk2_80119740 = var_s3;
    }
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }

        temp_s0 = &D_807B3C20.unk_0000[i];
        temp_v1_2 = &D_807B6528.unk_0000[i];
        temp_ft2 = temp_s0->radiusLeft + temp_s0->radiusRight;
        temp_s0->radiusLeft = temp_v1_2->radiusLeft + D_xk2_80119740;
        temp_s0->radiusRight = temp_v1_2->radiusRight - D_xk2_80119740;
        temp_s0->radiusLeft = (Math_Round(temp_s0->radiusLeft) / 10) * 10;
        temp_s0->radiusRight = (Math_Round(temp_s0->radiusRight) / 10) * 10;
        if (temp_s0->radiusLeft < 50.0f) {
            temp_s0->radiusLeft = 50.0f;
            temp_s0->radiusRight = temp_ft2 - 50;
        }
        if (temp_s0->radiusRight < 50.0f) {
            temp_s0->radiusRight = 50.0f;
            temp_s0->radiusLeft = temp_ft2 - 50;
        }
    }

    D_xk2_800F7040 = 3;
}

extern CourseData D_800CF950;
extern CourseSegment D_xk2_80119920[64];

void func_xk2_800DB550(void) {
    s32 i;
    s32 j;
    Vec3f sp74;
    CourseSegment* var_s0;

    if (D_807B3C20.unk_2900 < 2) {
        return;
    }

    j = 0;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        var_s0 = &D_807B3C20.unk_0000[i];

        if ((i != 0) && (func_807032B0(var_s0->pos, var_s0->prev->pos) < 498.0f)) {
            continue;
        }

        if ((i + 1 == D_807B3C20.unk_2900) && (func_807032B0(var_s0->pos, var_s0->next->pos) < 498.0f)) {
            continue;
        }

        D_800CF950.bankAngle[j] = gCourseCtx.courseData.bankAngle[i];
        D_800CF950.pit[j] = gCourseCtx.courseData.pit[i];
        D_800CF950.dash[j] = gCourseCtx.courseData.dash[i];
        D_800CF950.dirt[j] = gCourseCtx.courseData.dirt[i];
        D_800CF950.ice[j] = gCourseCtx.courseData.ice[i];
        D_800CF950.jump[j] = gCourseCtx.courseData.jump[i];
        D_800CF950.landmine[j] = gCourseCtx.courseData.landmine[i];
        D_800CF950.gate[j] = gCourseCtx.courseData.gate[i];
        D_800CF950.building[j] = gCourseCtx.courseData.building[i];
        D_800CF950.sign[j] = gCourseCtx.courseData.sign[i];
      
        D_xk2_80119920[j] = *var_s0;
        j++;
    }
    D_807B3C20.unk_2900 = j;
    for (i = 0; i < j; i++) {
        D_807B3C20.unk_0000[i] = D_xk2_80119920[i];
        
        gCourseCtx.courseData.bankAngle[i] = D_800CF950.bankAngle[i];
        gCourseCtx.courseData.pit[i] = D_800CF950.pit[i];
        gCourseCtx.courseData.dash[i] = D_800CF950.dash[i];
        gCourseCtx.courseData.dirt[i] = D_800CF950.dirt[i];
        gCourseCtx.courseData.ice[i] = D_800CF950.ice[i];
        gCourseCtx.courseData.jump[i] = D_800CF950.jump[i];
        gCourseCtx.courseData.landmine[i] = D_800CF950.landmine[i];
        gCourseCtx.courseData.gate[i] = D_800CF950.gate[i];
        gCourseCtx.courseData.building[i] = D_800CF950.building[i];
        gCourseCtx.courseData.sign[i] = D_800CF950.sign[i];
    }
    
    func_xk2_800E6F9C();

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        var_s0 = &D_807B3C20.unk_0000[i];
        func_xk2_800DE210(&sp74, var_s0->prev->pos, var_s0->pos, var_s0->next->pos);
        var_s0->pos = sp74;
    }
    func_807034F0(gCurrentCourseInfo);
}

extern s32 D_xk1_80030614;
extern s32 D_xk1_8003061C;
extern s32 D_xk1_80030620;
extern unk_80026914 D_xk1_80032354;
extern unk_80026914_unk_1C D_xk1_800327A8[];
extern u8 D_9004888[];
extern s32* D_xk1_8003067C[];

void func_xk2_800DB924(void) {
    s32 i;
    s32 j;

    if ((D_xk1_80030614 != 1) || (D_xk1_80030620 != 5) || !(D_80119720->buttonPressed & BTN_A)) {
        return;
    }

    j = 0;
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 != 0) {
            continue;
        }

        D_800CF950.bankAngle[j] = gCourseCtx.courseData.bankAngle[i];
        D_800CF950.pit[j] = gCourseCtx.courseData.pit[i];
        D_800CF950.dash[j] = gCourseCtx.courseData.dash[i];
        D_800CF950.dirt[j] = gCourseCtx.courseData.dirt[i];
        D_800CF950.ice[j] = gCourseCtx.courseData.ice[i];
        D_800CF950.jump[j] = gCourseCtx.courseData.jump[i];
        D_800CF950.landmine[j] = gCourseCtx.courseData.landmine[i];
        D_800CF950.gate[j] = gCourseCtx.courseData.gate[i];
        D_800CF950.building[j] = gCourseCtx.courseData.building[i];
        D_800CF950.sign[j] = gCourseCtx.courseData.sign[i];
      
        D_xk2_80119920[j] = D_807B3C20.unk_0000[i];
        j++;
    }
    
    if (D_807B3C20.unk_2900 - j != 0) {
        func_8074122C(0x27);
    }
    D_807B3C20.unk_2900 = j;
    for (i = 0; i < j; i++) {
        D_807B3C20.unk_0000[i] = D_xk2_80119920[i];
        
        gCourseCtx.courseData.bankAngle[i] = D_800CF950.bankAngle[i];
        gCourseCtx.courseData.pit[i] = D_800CF950.pit[i];
        gCourseCtx.courseData.dash[i] = D_800CF950.dash[i];
        gCourseCtx.courseData.dirt[i] = D_800CF950.dirt[i];
        gCourseCtx.courseData.ice[i] = D_800CF950.ice[i];
        gCourseCtx.courseData.jump[i] = D_800CF950.jump[i];
        gCourseCtx.courseData.landmine[i] = D_800CF950.landmine[i];
        gCourseCtx.courseData.gate[i] = D_800CF950.gate[i];
        gCourseCtx.courseData.building[i] = D_800CF950.building[i];
        gCourseCtx.courseData.sign[i] = D_800CF950.sign[i];
    }

    func_xk2_800E6F9C();
    func_xk2_800DB550();

    if (D_807B3C20.unk_2900 != 0) {
        D_800D6CA0[3] = 0;
    } else {
        D_800D6CA0[3] = -1;
    }
    if (D_807B3C20.unk_2900 < 4) {
        D_xk1_80030614 = 0;
        D_xk1_800327A8[1].unk_08 = D_9004888;
        D_xk1_800327A8[1].unk_10 = &D_xk1_80032354;
        D_xk1_8003067C[1] = &D_xk1_8003061C;
        D_xk1_800327A8[2].unk_08 = NULL;
        D_xk1_800327A8[2].unk_10 = NULL;
        D_xk1_8003061C = 0;
    }
    D_xk2_800F704C = -1;
    D_xk2_800F7040 = 3;
    D_800D6CA0[0] = 0;
    func_xk2_800E6F9C();
    func_xk2_800DC3F8();
    D_807B3C20.unk_0000[0].trackSegmentInfo = (TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000);
    if (func_xk2_800E6B3C() != 0) {
        D_xk2_800F7044 = 0;
    }
}

s32 func_xk2_800DBC68(void) {
    s32 previousSegmentIndex;
    s32 i;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (D_80128690[i].unk_08 == 0) {
            continue;
        }
        previousSegmentIndex = D_807B3C20.unk_0000[i].prev->segmentIndex;
        if ((D_807B3C20.unk_0000[i].trackSegmentInfo & TRACK_FLAG_8000000) && (D_807B3C20.unk_0000[previousSegmentIndex].trackSegmentInfo & TRACK_FLAG_8000000)) {
            return 0;
        }
    }
    return 1;
}

extern u32 gGameFrameCount;

void func_xk2_800DBCF8(void) {
    s32 temp_v1;
    s32 temp_a1;
    s32 var_a2;

    temp_v1 = D_80119720->stickX;
    temp_a1 = D_80119720->stickY;

    if (SQ(temp_v1) + SQ(temp_a1) < 100) {
        return;
    }

    var_a2 = sqrtf(SQ(temp_v1) + SQ(temp_a1));
    switch (D_xk1_80030620) {
        case 1:
            if (ABS(temp_v1) > ABS(temp_a1)) {
                return;
            }
            break;
        case 2:
        case 3:
            if (ABS(temp_v1) < ABS(temp_a1)) {
                return;
            }
            break;
        case 4:
            if (ABS(temp_v1) < ABS(temp_a1)) {
                return;
            }
            if (func_xk2_800DBC68() != 0) {
                func_8074122C(0x20);
                return;
            }
            break;
        default:
            break;
    }
    var_a2 = 120 / var_a2;
    if (var_a2 == 0) {
        var_a2 = 1;
    }
    if (((gGameFrameCount % var_a2) == 0) && ((func_xk1_8002DAD4() == 1) || (func_xk1_8002DAD4() >= 9))) {
        func_8074122C(0x26);
    }
}

void func_xk2_800DBEE4(void) {

    if ((D_8076C950 != 0) || (D_800D6CA0[2] != 0)) {
        return;
    }

    switch (D_xk1_80030614) {
        case 0:
            func_xk2_800DEB04();
            break;
        case 1:
            if (D_800D6CA0[0] != 0) {
                func_xk2_800DBCF8();
            }
            switch (D_800D6CA0[0]) {
                case 0:
                    func_xk2_800DEB04();
                    break;
                case 1:
                    switch (D_xk1_80030620) {
                        case 0:
                            func_xk2_800D9670();
                            break;
                        case 1:
                            func_xk2_800DA288();
                            break;
                        case 2:
                            func_xk2_800DA984();
                            break;
                        case 3:
                            func_xk2_800DADEC();
                            break;
                        case 4:
                            func_xk2_800DB154();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            func_xk2_800DEB04();
            break;
        default:
            break;
    }
}

extern s32 D_xk2_800F6838;
extern s32 D_xk2_800F683C;
extern s32 D_xk2_800F6840;
extern s32 D_xk2_800F6844;

void func_xk2_800DC018(void) {
    if (D_800D6CA0[0] == 1) {
        return;
    } 
    if ((D_xk2_800F6828 < 56) || ((D_xk2_800F6824 >= 232) && (D_xk2_800F6824 <= 295) && (D_xk2_800F6828 >= 204) && (D_xk2_800F6828 < 220))) {
        return;
    }

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) {
        D_xk2_800F6838 = D_xk2_800F6824;
        D_xk2_800F683C = D_xk2_800F6828;
        D_xk2_800F6840 = D_xk2_800F6824;
        D_xk2_800F6844 = D_xk2_800F6828;
        D_800D6CA0[2] = 5;
    }
}

void func_xk2_800DC0D4(void) {
    D_xk2_800F6840 = D_xk2_800F6824;
    D_xk2_800F6844 = D_xk2_800F6828;
}

#ifdef NON_MATCHING
s32 func_xk2_800DC0F8(void) {
    s32 i;
    s32 j;
    CourseSegment* var_s1;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;

    j = 0;
    if (D_xk1_80030614 != 1) {
        return 0;
    }

    if (D_xk2_800F6838 < D_xk2_800F6840) {
        sp68 = D_xk2_800F6838;
        sp60 = D_xk2_800F6840;
    } else {
        sp68 = D_xk2_800F6840;
        sp60 = D_xk2_800F6838;
    }
    if (D_xk2_800F683C < D_xk2_800F6844) {
        sp64 = D_xk2_800F683C;
        sp5C = D_xk2_800F6844;
    } else {
        sp64 = D_xk2_800F6844;
        sp5C = D_xk2_800F683C;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (func_xk2_800EF090(D_807B3C20.unk_0000[i].pos, &sp70, &sp6C) != 0) {
            continue;
        } 
        if ((sp70 >= sp68) && (sp60 >= sp70) && (sp6C >= sp64) && (sp5C >= sp6C)) {
            j++;
            D_80128690[i].unk_08 = 1;
            D_800D6CA0[0] = 1;
            func_xk2_800EF78C();
            D_xk2_80119730 = 0.0f;
            D_xk2_80119734 = 0.0f;
            D_xk2_80119738 = 0.0f;
            D_xk2_8011973C = 0;
            D_xk2_80119740 = 0;
        }
    }
    return j;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC0F8.s")
#endif

void func_xk2_800DC2D0(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if ((D_xk1_80030614 != 1) || (D_800D6CA0[0] == 1)) {
        return;
    }
    func_8074122C(0x45);
    D_xk2_800F704C = -1;
    func_xk2_800DC3F8();
    temp_v0 = func_xk2_800DC0F8();
    if (temp_v0 != 0) {
        D_xk2_800F7040 = 3;
    }
    if ((temp_v0 == 0) && (D_xk2_800F6838 == D_xk2_800F6840) && (D_xk2_800F683C == D_xk2_800F6844)) {
        func_xk2_800DC3F8();
        temp_v0_2 = func_xk2_800EFDE4(4000.0f);
        if (temp_v0_2 != -1) {
            D_800D6CA0[3] = temp_v0_2;
            D_xk2_80119730 = 0.0f;
            D_xk2_80119734 = 0.0f;
            D_xk2_80119738 = 0.0f;
            D_xk2_8011973C = 0;
            D_xk2_80119740 = 0;
            D_80128690[temp_v0_2].unk_08 = 1;
            D_800D6CA0[0] = 1;
            D_xk2_800F7040 = 3;
            func_xk2_800EF78C();
        }
    }
}

void func_xk2_800DC3F8(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_80128690[i].unk_08 = 0;
    }
}

extern s32 D_xk2_80119800;

void func_xk2_800DC428(void) {
    if ((D_xk1_80030614 != 1) || (D_800D6CA0[0] != 1)) {
        return;
    }

    if (D_80119720->buttonPressed & BTN_B) {
        D_807B3C20 = D_807B6528;
        D_xk2_801197EC = D_807B3C20.unk_0000;
        D_xk2_800F704C = -1;
        func_xk2_800DC3F8();
        D_800D6CA0[3] = D_xk2_80119800;
        D_800D6CA0[0] = 0;
    }
}

void func_xk2_800DC4E4(void) {
    if ((D_80119720->buttonPressed & BTN_A) && (D_800D6CA0[2] == 0) && (D_xk1_8003061C == 1) && (D_xk1_80030614 == 0) && (D_xk2_800F6828 >= 0x38) && (func_xk2_800DEFCC() == 0)) {
        D_xk2_800F7040 = 3;
        D_800D6CA0[3] = 1;
        func_xk2_800DEB38();
        D_800D6CA0[3] = 0;
    }
}

void func_xk2_800DC58C(void) {
    if ((D_800D6CA0[0] == 1) || (D_800D6CA0[2] != 0) || (D_xk1_80030614 != 1) || (D_xk2_800F6828 < 56)) {
        return;
    }
    if (D_800D11C8[0] == 1) {
        D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
    }
    if (D_80119720->buttonPressed & BTN_A) {
        if (D_800D11C8[0] == 0) {
            D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
        }
        if (D_xk2_800F703C != -1) {
            func_8074122C(0x1E);
        } else {
            func_8074122C(0x20);
        }
    }
}

extern CourseSegment D_i2_800D6CC8;
extern u8 D_xk2_80104CA0[];
extern s32 D_80030608;
extern s32 D_8076C968;

void func_xk2_800DC67C(void) {
    s32 sp16C;
    s32 sp168;
    s32 sp164;
    CourseSegment spC0;
    CourseSegment* spBC;
    s32 temp_a1;
    s32 var_v1;

    if ((D_800D6CA0[2] != 0) || (D_xk1_8003061C != 0) || (D_xk1_80030614 != 0) || (D_xk2_800F6828 < 0x38) || (D_800D6CA0[0] != 0)) {
        return;
    }
    if (D_800D11C8[0] == 1) {
        D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
    }
    if (D_80119720->buttonPressed & BTN_A) {
        if (D_800D11C8[0] == 0) {
            D_xk2_800F703C = func_xk2_800EFDE4(150.0f);
        }
        if (D_xk2_800F703C != -1) {
            func_8074122C(0x24);
            return;
        }
        if (D_807B3C20.unk_2900 >= 0x40) {
            func_8074122C(0x20);
            return;
        }
        func_8074122C(0x24);
        D_xk2_800F704C = D_xk2_800F703C;
        if ((D_xk1_80030614 == 0) && (D_xk2_80104CA0[1] == 0) && (D_xk2_80104CA0[10] == 0)) {
            spC0 = D_i2_800D6CC8;
            if ((spC0.pos.x < -15000.0f) || (spC0.pos.x > 15000.0f) || (spC0.pos.y < 0.0f) || (spC0.pos.y > 5000.0f) || (spC0.pos.z < -15000.0f) || (spC0.pos.z > 15000.0f)) {
                func_8074122C(0x20);
                return;
            }
            if (D_8076C968 != 0) {
                sp16C = Math_Round(spC0.pos.x);
                sp168 = Math_Round(spC0.pos.y);
                sp164 = Math_Round(spC0.pos.z);
                var_v1 = ABS(sp16C);
                temp_a1 = D_80030608 / 2;
                if (var_v1 < temp_a1) {
                    sp16C = 0;
                } else if (sp16C > 0) {
                    sp16C = ((temp_a1 + sp16C) / D_80030608) * D_80030608;
                } else {
                    sp16C = ((sp16C - temp_a1) / D_80030608) * D_80030608;
                }

                var_v1 = ABS(sp168);
                if (var_v1 < temp_a1) {
                    sp168 = 0;
                } else if (sp168 > 0) {
                    sp168 = ((temp_a1 + sp168) / D_80030608) * D_80030608;
                } else {
                    sp168 = ((sp168 - temp_a1) / D_80030608) * D_80030608;
                }

                var_v1 = ABS(sp164);
                if (var_v1 < temp_a1) {
                    sp164 = 0;
                } else if (sp164 > 0) {
                    sp164 = ((temp_a1 + sp164) / D_80030608) * D_80030608;
                } else {
                    sp164 = ((sp164 - temp_a1) / D_80030608) * D_80030608;
                }
                spC0.pos.x = sp16C;
                spC0.pos.y = sp168;
                spC0.pos.z = sp164;
            }
            if (D_807B3C20.unk_2900 != 0) {
                spBC = &D_807B3C20.unk_0000[D_800D6CA0[3]];
                if (func_807032B0(spC0.pos, spBC->pos) < 498.0f) {
                    func_8074122C(0x20);
                    return;
                }
                spBC = spBC->next;
                if (func_807032B0(spC0.pos, spBC->pos) < 498.0f) {
                    func_8074122C(0x20);
                    return;
                }
            }

            func_8074122C(0x27);
            if ((D_xk2_800F704C == -1) && (D_807B3C20.unk_2900 < 0x40)) {
                D_xk2_800F7040 = 3;
                func_xk2_800EF78C();
                D_xk2_800F704C = -1;
                func_xk2_800E6CA8(D_800D6CA0[3], spC0);
            }
        }
    }
}

void func_xk2_800DCCD8(void) {
    CourseSegment* temp_at = &D_i2_800D6CC8;
    CourseSegment* temp_v0_2;

    if ((D_xk1_80030614 != 1) || (D_800D6CA0[0] != 1)) {
        return;
    }
    if ((D_xk1_80030620 != 5) && (D_80119720->buttonPressed & BTN_A)) {
        D_xk2_800F7040 = 3;
        if (D_8076C968 != 0) {
            func_xk2_800DE4F8();
        }
        if (D_xk1_80030620 != 6) {
            func_8074122C(0x27);
        }
        func_xk2_800DC3F8();
        temp_v0_2 = &D_807B3C20.unk_0000[D_xk2_800F704C];
        temp_at->radiusLeft = temp_v0_2->radiusLeft;
        temp_at->radiusRight = temp_v0_2->radiusRight;
        D_xk2_800F704C = -1;
        D_800D6CA0[0] = 0;
    }
}

extern s32 D_xk2_800F7058;

void func_xk2_800DCDD0(void) {
    s32 var_v1;
    s32 sp18;
    s32 var_a0;
    s32 i;

    if (D_xk2_800F6828 < 56) {
        return;
    }

    // FAKE
    if (var_v1) {}

    if (((D_xk1_80030614 == 0) || (D_xk1_80030614 == 2) || (D_xk1_80030614 == 3)) && (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_Z) && (D_807B3C20.unk_2900 != 0)) {
        sp18 = func_xk2_800DD76C(400.0f);
        if (sp18 != -1) {
            func_8074122C(0x45);

            for (i = 0; i < D_807B3C20.unk_2900; i++) {
                var_a0 = D_80128690[D_807B3C20.unk_0000[i].next->segmentIndex].unk_00;
                var_v1 = D_80128690[i].unk_00;
                if (i + 1 == D_807B3C20.unk_2900) {
                    var_a0 = D_xk2_800F7058;
                }
                if ((i == 0) && (var_a0 < var_v1)) {
                    var_v1 = 0;
                }
                if ((sp18 >= var_v1) && (sp18 < var_a0)) {
                    D_800D6CA0[3] = i;
                }
            }
        }
    }
}

extern s32 D_xk2_800F6950[];
extern s32 D_xk1_8003062C;

void func_xk2_800DCF2C(void) {
    CourseSegment* sp1C;

    if (D_xk1_80030624 != 0) {
        return;
    }

    sp1C = &D_807B3C20.unk_0000[D_800D6CA0[3]];
    if ((sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) != (D_xk2_800F6950[D_xk1_8003062C] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        func_xk2_800EF78C();
        func_8074122C(0x27);
        sp1C->trackSegmentInfo = D_xk2_800F6950[D_xk1_8003062C];
        D_xk2_800F7040 = 3;
    }
}

extern s32 D_xk2_800F6964[];
extern s32 D_xk1_80030630;

void func_xk2_800DCFE0(void) {
    CourseSegment* sp1C;

    if (D_xk1_80030624 != 1) {
        return;
    }

    sp1C = &D_807B3C20.unk_0000[D_800D6CA0[3]];
    if (!func_xk2_800DD688(TRACK_SHAPE_WALLED_ROAD) && (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) != (D_xk2_800F6964[D_xk1_80030630] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        func_8074122C(0x27);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F6964[D_xk1_80030630];
        D_xk2_800F7040 = 3;
    }
}

extern s32 D_xk2_800F6970[];
extern s32 D_xk1_80030634;

void func_xk2_800DD0AC(void) {
    CourseSegment* sp1C;

    if (D_xk1_80030624 != 2) {
        return;
    }

    sp1C = &D_807B3C20.unk_0000[D_800D6CA0[3]];
    if (!func_xk2_800DD688(TRACK_SHAPE_BORDERLESS_ROAD) && (sp1C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) != (D_xk2_800F6970[D_xk1_80030634] & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        func_8074122C(0x27);
        func_xk2_800EF78C();
        sp1C->trackSegmentInfo = D_xk2_800F6970[D_xk1_80030634];
        D_xk2_800F7040 = 3;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD178.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD244.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD350.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD45C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD568.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD638.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD688.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD76C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD8C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/D_xk2_800F6A10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD938.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DDC2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DDEF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DE210.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DE4F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DE758.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DE8D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DE980.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEA14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEA20.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEB04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEB38.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEC1C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DECF0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEDA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEE20.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DEFCC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DF2EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DF370.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DF42C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DF54C.s")
