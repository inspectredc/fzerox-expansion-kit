#include "global.h"
#include "leo/leo_functions.h"

extern GfxPool* gGfxPool;
extern unk_807B3C20 D_807B3C20;
extern unk_800D6CA0 D_800D6CA0;
extern Vtx* D_800D65D0;

s32 func_xk2_800F2750(void) {
    D_800D65D0 = gGfxPool->unk_1A308;
    gCourseInfos->courseSegments = D_807B3C20.unk_0000;
    gCourseInfos->segmentCount = D_807B3C20.unk_2900;
    if (D_800D6CA0.unk_20 == -1) {
        func_i2_800B42E0(gCourseInfos);
        func_i2_800B3F54(gCourseInfos);
        return func_i2_800B5CD8(gCourseInfos);
    }
    return 0;
}

extern s32 D_xk2_80104364;
extern s32 D_xk2_80104368;
extern s32 D_xk2_80104378;
extern s32 D_xk1_80032C20;
extern s32 D_800D65C8;
extern u8 D_xk2_80104CA0[];

void func_xk2_800F27DC(CourseInfo* courseInfo) {
    s32 i;
    s32 temp_v0;
    s32 pad;
    s32 sp18;

    D_xk2_80104364 = 0;
    D_xk2_80104368 = 0;
    gCourseCtx.courseData.flag = 0;
    sp18 = 0;
    if (D_807B3C20.unk_2900 < 4) {
        D_xk1_80032C20 = 0;
        D_800D6CA0.unk_08 = 0x10;
        D_xk2_80104378 = 9;
        return;
    }

    i = 0;

    while (true) {
        if (D_xk2_80104CA0[i] != 0) {
            D_xk1_80032C20 = 0;
            D_800D6CA0.unk_08 = 0x10;
            D_xk2_80104378 = 7;
            break;
        }
        i++;
        if (i == 12) {
            D_xk2_80104CA0[7] = 0;
            if ((func_i2_800B39B4(courseInfo) != -1) || (func_i2_800BE8BC(courseInfo) != -1)) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                break;
            }
            func_i2_800B91AC(2);
            temp_v0 = func_i2_800B5CD8(courseInfo);
            if (temp_v0 != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                if (temp_v0 & 0x10000) {
                    D_xk2_80104CA0[3] = 1;
                    D_xk2_80104364 = 1;
                    D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
                }
                if (D_800D65C8 >= 0x2FF) {
                    D_xk2_80104CA0[0xA] = 1;
                    D_xk2_80104368 = 1;
                }
                func_i2_800B91AC(0);
                sp18 = 1;
            }
            func_806FE8F8(0);
            if (D_xk2_80104CA0[7] != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                func_i2_800B91AC(0);
            }
            func_i2_800B91AC(1);
            temp_v0 = func_i2_800B5CD8(courseInfo);
            if (temp_v0 != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                if (temp_v0 & 0x10000) {
                    D_xk2_80104CA0[3] = 1;
                    D_xk2_80104364 = 1;
                    D_800D6CA0.unk_1C = func_xk2_800E9134(temp_v0 & 0xFFFF);
                }
                if (D_800D65C8 >= 0x2FF) {
                    D_xk2_80104CA0[0xA] = 1;
                    D_xk2_80104368 = 1;
                }
                func_i2_800B91AC(0);
            }
            func_806FE8F8(0);
            if (D_xk2_80104CA0[7] != 0) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
                D_xk2_80104378 = 7;
                sp18 = 1;
                func_i2_800B91AC(0);
            }
            func_i2_800B91AC(0);
            if (sp18 == 0) {
                gCourseCtx.courseData.flag = 1;
            }
            break;
        }
    }
}

s32 func_xk2_800F2AC0(s8* arg0) {
    s32 var_v1;

    var_v1 = 0;
    do {
        if ((*arg0 == 0xA) || (*arg0 == 0)) {
            var_v1++;
        }
    } while (!*arg0++ == 0);
    return var_v1;
}

s32 func_xk2_800F2AF4(s8* arg0) {
    s32 var_v0;
    s32 var_v1;

    var_v1 = 0;
    var_v0 = 0;

    while (true) {
        if ((*arg0 != 0xA) && (*arg0 != 0)) {
            arg0++;
            var_v0++;
            continue;
        }

        if (var_v1 < var_v0) {
            var_v1 = var_v0;
        }
        if (*arg0 == 0) {
            break;
        }
        arg0++;
        var_v0 = 0;
    }
    return var_v1;
}

extern u16 D_7004B00[];
extern Gfx D_3000510[];
extern Gfx D_3000540[];
extern Gfx D_8014940[];
extern u8* D_xk1_800331F0[];
extern s32 D_xk2_80104F04;
extern s32 D_xk2_800F6828;

void func_xk2_800F2B48(Gfx** gfxP) {
    Gfx* gfx;
    s32 width;
    s32 i;
    s32 temp_v1;
    s32 top = 200;
    s32 pad;

    gfx = *gfxP;
    D_xk2_80104F04 = 0;
    for (i = 0; i < 12; i++) {
        if (D_xk2_80104CA0[i] != 0) {
            D_xk2_80104F04 = 1;
        }
    }

    if ((D_xk2_80104F04 != 0) && (func_xk2_800EF780() != 0) && (D_xk2_800F6828 < 200)) {
        width = Leo_strlen(D_xk1_800331F0[21]) * 8;
        width += 16;
        temp_v1 = (s32) (SCREEN_WIDTH - width) / 2;

        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        // FAKE
        gSPTextureRectangle(pad = gfx++, (temp_v1 - 2) << 2, (top - 2) << 2, (temp_v1 + width + 2) << 2,
                            (top + 16 + 2) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gSPTextureRectangle(gfx++, (temp_v1 - 1) << 2, (top - 1) << 2, (temp_v1 + width + 1) << 2, (top + 16 + 1) << 2,
                            0, 0, 0, 1 << 10, 1 << 10);
        gSPDisplayList(gfx++, D_3000540);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        gfx = func_xk1_800264C0(gfx, temp_v1 + 16, top, 0x15);

        gSPDisplayList(gfx++, D_8014940);

        gDPLoadTextureBlock(gfx++, D_7004B00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, temp_v1 << 2, top << 2, (temp_v1 + 16) << 2, (top + 16) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);

        *gfxP = gfx;
    }
}

extern s32 D_xk1_80032AD0;
extern s32 D_80119880;
extern u8 D_xk2_80104F28[];
extern u8 D_xk2_80104F30[];
extern u8 D_xk2_80104F38[];
extern u8 D_xk2_80104F40[];
extern u8 D_xk2_80104F44[];
extern u8 D_xk2_80104F50[];
extern u8 D_xk2_80104F5C[];
extern u8 D_xk2_80104F68[];

void func_xk2_800F2E4C(Gfx** gfxP) {
    Gfx* gfx;
    s32 left;
    s32 temp;
    s32 top;
    s32 width;
    s32 height;

    if ((D_800D6CA0.unk_08 != 3) || (D_80119880 != 4)) {
        return;
    }

    gfx = *gfxP;
    left = 24;
    top = 96;
    width = 128;
    height = 40;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, (top + height + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (top - 1) << 2, (left + width + 1) << 2, (top + height + 1) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gDPSetTextureFilter(gfx++, G_TF_POINT);

    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F30);
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left + 80, top, D_xk2_80104F38);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 112, top, D_xk2_80104F40);
    top += 8;
    D_xk1_80032AD0 = 1;

    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F44);
    top += 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F50);
    top += 8;
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F38);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 32, top, D_xk2_80104F5C);
    top += 8;
    D_xk1_80032AD0 = 0;
    gfx = func_xk1_8002924C(gfx, left, top, D_xk2_80104F28);
    D_xk1_80032AD0 = 1;
    gfx = func_xk1_8002924C(gfx, left + 40, top, D_xk2_80104F68);
    *gfxP = gfx;
}

extern s32 D_xk2_80119918;
extern u16 D_7000000[];

void func_xk2_800F3164(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;
    s32 left;
    s32 top;
    s32 width;

    if (D_xk2_80119918 == 0) {
        return;
    }
    gfx = *gfxP;
    left = 48;
    top = 20;
    width = 224;

    gSPDisplayList(gfx++, D_8014940);

    for (i = 0; i < 32; i++) {
        gDPLoadTextureBlock(gfx++, D_7000000 + i * width, G_IM_FMT_RGBA, G_IM_SIZ_16b, 224, 1, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + 1) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        top++;
    }

    *gfxP = gfx;
}

s32 func_xk2_800F3320(s8* arg0) {
    s32 var_v1;
    s32 temp;

    var_v1 = 0;

    while (true) {
        // FAKE
        temp = *arg0;
        switch (*arg0) {
            case 0:
                goto exit;
            case 1:
            case 2:
                break;
            default:
                var_v1++;
                break;
        }
        arg0++;
    }

exit:
    return var_v1;
}

void func_xk2_800F335C(Gfx** gfxP, s32 top, s8* arg2) {
    s32 left;
    s32 width;
    s32 height;
    s32 temp_v0;
    Gfx* gfx;

    gfx = *gfxP;
    temp_v0 = func_xk2_800F3320(arg2);
    width = temp_v0 * 8;
    left = (((0x22 - temp_v0) / 2) * 8) + 0x18;
    height = 8;

    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gSPTextureRectangle(gfx++, (left - 2) << 2, (top - 2) << 2, (left + width + 2) << 2, (top + height + 2) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    gSPTextureRectangle(gfx++, (left - 1) << 2, (top - 1) << 2, (left + width + 1) << 2, (top + height + 1) << 2, 0, 0,
                        0, 1 << 10, 1 << 10);
    gSPDisplayList(gfx++, D_3000540);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_xk1_8002924C(gfx, left, top, arg2);
    *gfxP = gfx;
}

extern s32 D_8076C96C;
extern s32 D_xk2_800F705C;
extern u8 D_xk2_80104F74[];
extern u8 D_xk2_80104F94[];
extern u8 D_xk2_80104FAC[];

void func_xk2_800F3548(Gfx** gfxP) {
    s32 top = 194;
    Gfx* gfx;

    if (D_8076C96C == 0) {
        return;
    }
    gfx = *gfxP;
    switch (D_xk2_800F705C) {
        case 0:
            func_xk2_800F335C(&gfx, top, D_xk2_80104F74);
            break;
        case 1:
            func_xk2_800F335C(&gfx, top, D_xk2_80104F94);
            break;
        case 2:
            func_xk2_800F335C(&gfx, top, D_xk2_80104FAC);
            break;
        case 3:
            break;
    }
    *gfxP = gfx;
}

extern unk_80026914 D_xk1_80032880;
extern unk_80026914 D_xk1_80031870;
extern unk_80026914 D_xk1_80032160;
extern unk_80026914 D_xk1_8003226C;
extern unk_80026914 D_xk1_80032354;
extern unk_80026914 D_xk1_80032484;
extern unk_80026914 D_xk1_800325FC;
extern unk_80026914 D_xk1_80032774;
extern u8 D_xk2_80104FD4[];
extern u8 D_xk2_80104FEC[];
extern u8 D_xk2_80105008[];
extern u8 D_xk2_80105024[];
extern u8 D_xk2_80105048[];
extern u8 D_xk2_80105064[];
extern u8 D_xk2_80105078[];
extern u8 D_xk2_80105090[];
extern u8 D_xk2_801050AC[];
extern u8 D_xk2_801050CC[];
extern u8 D_xk2_801050E8[];
extern u8 D_xk2_801050FC[];
extern u8 D_xk2_80105114[];
extern u8 D_xk2_8010512C[];
extern u8 D_xk2_8010514C[];
extern u8 D_xk2_80105174[];
extern u8 D_xk2_80105190[];
extern u8 D_xk2_801051A8[];
extern u8 D_xk2_801051D0[];
extern u8 D_xk2_801051F0[];
extern u8 D_xk2_80105210[];
extern u8 D_xk2_80105230[];
extern u8 D_xk2_80105244[];
extern u8 D_xk2_80105260[];
extern u8 D_xk2_80105280[];
extern u8 D_xk2_8010529C[];
extern u8 D_xk2_801052C0[];
extern u8 D_xk2_801052E0[];
extern u8 D_xk2_801052FC[];
extern u8 D_xk2_80105318[];
extern u8 D_xk2_80105328[];
extern u8 D_xk2_8010533C[];
extern u8 D_xk2_80105354[];
extern u8 D_xk2_80105374[];
extern u8 D_xk2_80105388[];
extern u8 D_xk2_801053A0[];
extern u8 D_xk2_801053B4[];
extern u8 D_xk2_801053C8[];
extern u8 D_xk2_801053DC[];
extern u8 D_xk2_801053F8[];
extern u8 D_xk2_8010540C[];
extern u8 D_xk2_80105428[];
extern u8 D_xk2_8010544C[];
extern u8 D_xk2_8010546C[];

void func_xk2_800F3600(Gfx** gfxP) {
    s32 pad;
    Gfx* gfx;
    unk_80026914* sp2C;

    if ((D_8076C96C == 0) || (D_800D6CA0.unk_08 != 1)) {
        return;
    }
    sp2C = func_xk1_80026914(&D_xk1_80032880);

    gfx = *gfxP;
    if (sp2C == &D_xk1_8003226C) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80104FD4);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[25], 25);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80104FEC);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[26], 26);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105008);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[27], 27);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105024);
                func_xk2_800EECD4(&gfx, 0, 156, D_xk1_800331F0[28], 28);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105048);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105064);
                break;
        }
    }
    if (sp2C == &D_xk1_80032354) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105078);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105090);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050AC);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050CC);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050E8);
                break;
        }
    }
    if (sp2C == &D_xk1_80032484) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801050FC);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105114);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010512C);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010514C);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105174);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105190);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051A8);
                break;
        }
    }
    if (sp2C == &D_xk1_80032160) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053B4);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053C8);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053DC);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053F8);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010540C);
                break;
        }
    }
    if (sp2C == &D_xk1_80031870) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105428);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010544C);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010546C);
                break;
        }
    }
    if (sp2C == &D_xk1_800325FC) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051D0);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801051F0);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105210);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105230);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105244);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105260);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105280);
                break;
            case 7:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010529C);
                break;
            case 8:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052C0);
                break;
        }
    }
    if (sp2C == &D_xk1_80032774) {
        switch (sp2C->unk_08) {
            case 0:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052E0);
                break;
            case 1:
                func_xk2_800F335C(&gfx, 24, D_xk2_801052FC);
                break;
            case 2:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105318);
                break;
            case 3:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105328);
                break;
            case 4:
                func_xk2_800F335C(&gfx, 24, D_xk2_8010533C);
                break;
            case 5:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105354);
                break;
            case 6:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105374);
                break;
            case 7:
                func_xk2_800F335C(&gfx, 24, D_xk2_80105388);
                break;
            case 8:
                func_xk2_800F335C(&gfx, 24, D_xk2_801053A0);
                break;
        }
    }
    *gfxP = gfx;
}

extern u16* D_8076C970[];
extern u16 D_9002988[];
extern s32 D_8076C95C;
extern s32 D_8076C960;

void func_xk2_800F3D10(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        D_8076C96C = 1;
        D_8076C970[3] = D_9002988;
        D_8076C95C = 0;
        D_8076C960 = 0;
        D_800D6CA0.unk_08 = 0;
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        D_8076C95C = 0;
        D_800D6CA0.unk_08 = 0;
        func_xk2_800EE664(0x16);
    }
}

extern s32 D_8076C958;
extern u8 D_9001C88[];
extern u16 D_9002788[];

void func_xk2_800F3DAC(Gfx** gfxP) {
    s32 left;
    s32 top;
    s32 width;
    s32 height;
    s32 temp_v1;
    Gfx* gfx;

    gfx = *gfxP;
    if (D_8076C958 == 0) {
        return;
    }
    D_8076C958--;
    if (D_8076C958 == 0) {
        return;
    }

    left = 128;
    top = 88;
    width = 16;
    height = 16;

    func_xk2_800F2AC0(D_xk1_800331F0[22]);
    temp_v1 = (((0x22 - func_xk2_800F2AF4(D_xk1_800331F0[22])) / 2) * 8) + 0x18;
    func_xk2_800EECD4(&gfx, temp_v1, 0x58, D_xk1_800331F0[22], 22);

    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, D_9002788, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    gDPPipeSync(gfx++);

    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);

    gDPLoadTextureBlock(gfx++, D_9001C88, G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    func_xk2_800E92E4(&gfx, 0x120, 0xCC);
    *gfxP = gfx;
}
