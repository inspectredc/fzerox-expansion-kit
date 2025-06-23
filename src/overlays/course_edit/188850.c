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

    D_80119720 = &gControllers[*gPlayerControlPorts];

    temp_v1 = D_xk2_800F704C;
    if (temp_v1 != -1) {
        D_xk2_801197EC = &D_807B3C20.unk_0000[D_xk2_800F704C];
    } else {
        D_xk2_801197EC = D_807B3C20.unk_0000;
    }
    D_xk2_80119748 = *D_xk2_801197EC;

    func_xk2_800DBEE4(&D_80119720);
    if (D_800D6CA0[2] == 0) {
        D_xk1_8003A550 = D_xk2_800F6824;
        D_xk1_8003A554 = D_xk2_800F6828;
    }
    if (D_80794E14 == 1) {
        func_xk1_80027CFC(&D_xk1_80032880, &D_xk1_8003A550, &D_xk1_8003A554);
        return;
    }
    func_xk2_800D8AB0();
    D_xk2_80119728 = gControllers[gPlayerControlPorts[0]].buttonCurrent & 0xF00;
    D_xk2_8011972A = gControllers[gPlayerControlPorts[0]].buttonPressed & 0xF00;
    D_xk2_8011972C = gControllers[gPlayerControlPorts[0]].buttonCurrent & 0xF;
    D_xk2_8011972E = gControllers[gPlayerControlPorts[0]].buttonPressed & 0xF;
    D_xk2_801197EC = &D_807B3C20.unk_0000[D_xk2_800F704C];
    D_xk2_80128D40 = SIN((D_800D6CA0[5] << 12) / 360);
    D_xk2_80128D44 = COS((D_800D6CA0[5] << 12) / 360);
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & 0x2000) {
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
    if ((D_80119720->buttonPressed & 0x8000) && (D_800D6CA0[2] == 0)) {
        D_xk1_8003A550 = D_xk2_800F6824;
        D_xk1_8003A554 = D_xk2_800F6828;
        func_xk1_80027DC8(&D_xk1_80032880, &D_xk1_8003A550, &D_xk1_8003A554);
        if (D_xk1_800305F8 != 0) {
            D_800D6CA0[2] = 1;
        }
    }
    func_xk2_800D6FF0();
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800D934C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800D950C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800D9670.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DA288.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DA984.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DADEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DB154.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DB550.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DB924.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DBC68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DBCF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DBEE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC018.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC0D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC0F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC2D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC3F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC428.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC4E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC58C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DC67C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DCCD8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DCDD0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DCF2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DCFE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/188850/func_xk2_800DD0AC.s")

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
