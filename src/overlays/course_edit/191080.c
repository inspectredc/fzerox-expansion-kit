#include "global.h"
#include "fzx_assets.h"

extern unk_807B3C20 D_807B3C20;

void func_xk2_800DF5C0(void) {
    s32 i;

    if (gControllers[1].buttonPressed & BTN_START) {
        for (i = 0; i < D_807B3C20.unk_2900; i++) {}
    }
}

extern s32 D_8076C950;
extern s32 D_xk2_800F7030;
extern Mtx D_xk2_80119838;

Gfx* func_xk2_800DF5FC(Gfx* gfx) {

    switch (D_xk2_800F7030) {
        case 0:
            D_xk2_800F7030 = 1;
            func_806F7FCC(&D_xk2_80119838, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
            break;
        case 1:
            func_xk2_800DF5C0();
            func_xk1_800260E4();
            if (D_8076C950 == 0) {
                gSPMatrix(gfx++, K0_TO_PHYS(&D_xk2_80119838), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            }
            gfx = func_xk2_800DF6FC(gfx);
            break;
    }
    return gfx;
}

void func_xk2_800F3DAC(Gfx** gfxP);
void func_xk1_8002D340(Gfx** gfxP);
void func_xk2_800F5250(Gfx** gfxP);

extern Mtx D_2000000[];
extern Gfx D_30004A8[];
extern Gfx D_3000540[];
extern s32 D_80033268;
extern s32 D_80119880;
extern Gfx* D_8076C974;
extern Gfx D_9000858[];
extern Gfx D_9002588[];
extern Gfx D_9014AA0[];
extern Gfx D_9014B68[];
extern Gfx D_9014BA0[];
extern Gfx D_9014BC0[];
extern Gfx D_3000510[];
extern u8 D_80794E14;
extern s32 D_8076C964;
extern unk_800D6CA0 D_800D6CA0;

extern s32 D_xk2_800F6824;
extern s32 D_xk2_800F6828;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F7404;
extern s8 D_xk2_80104CA2;
extern u8 D_xk2_80104CAA;
extern s32 D_xk2_80119918;

Gfx* func_xk2_800DF6FC(Gfx* gfx) {

    gSPDisplayList(gfx++, D_30004A8);
    gSPDisplayList(gfx++, D_9014AA0);

    if (D_8076C950 != 0) {
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gfx++);
        gDPPipelineMode(gfx++, G_PM_1PRIMITIVE);
        gDPSetTextureFilter(gfx++, G_TF_BILERP);
        gfx = func_i3_8006339C(gfx, 0, 0);
        gfx = func_i2_800BDE60(gfx, 0);
        gfx = func_806F9DB4(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DFLX2_Rej_fifo);
        func_xk2_800E1FC0(&gfx);
        gfx = func_80727F54(gfx, 0);
        gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_xk2_800E1FC0(&gfx);
        gfx = func_i3_DrawCourseMinimap(gfx, 0, 0);
        gfx = func_i3_DrawPlayerSpeed(gfx, 0, 0);
        return func_i3_DrawReverse(gfx, 0, 0);
    }
    if (func_xk2_800E6B3C() != 0) {
        D_xk2_80104CA2 = 1;
        D_8076C964 = 0;
        D_8076C974 = D_9002588;
        D_xk2_800F7044 = 0;
    }
    gfx = func_xk2_800E5870(gfx);
    gSPDisplayList(gfx++, D_9014B68);
    gSPDisplayList(gfx++, D_9000858);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_807B3C20.unk_2900 >= 4) && (D_xk2_800F7044 == 1) && (D_800D6CA0.unk_20 == -1)) {
        gSPDisplayList(gfx++, D_9014BA0);
        if (D_xk2_800F7404 == 0) {
            gfx = func_i2_800BDAA4(gfx);
        }
    }
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if ((D_807B3C20.unk_2900 >= 4) && (D_800D6CA0.unk_20 == -1) && (D_xk2_800F7404 == 0) && (D_xk2_80104CAA == 0)) {
        gfx = func_806F9DB4(gfx, 0);
    }
    if (D_xk2_800F7404 != 0) {
        D_xk2_800F7404 = 0;
    } else {
        gfx = func_xk2_800E2104(gfx);
        gfx = func_xk2_800E04E0(gfx);
        gfx = func_xk2_800EA248(gfx);
        gfx = func_xk2_800EA4E4(gfx);
    }
    gfx = func_xk2_800E7518(gfx);
    func_xk2_800F61DC(&gfx);
    func_xk2_800E9234();
    gSPDisplayList(gfx++, D_9014BC0);
    func_xk2_800E93B0(&gfx);
    func_xk2_800E9504(&gfx);
    func_xk2_800E95E0(&gfx);
    func_xk2_800E96F4(&gfx);
    func_xk2_800E9808(&gfx);
    func_xk2_800E98D8(&gfx);
    func_xk2_800E9C4C(&gfx);
    gfx = func_xk2_800E8F7C(gfx);
    gfx = func_xk2_800E54A4(gfx);
    gfx = func_xk2_800E5058(gfx);
    gfx = func_xk2_800E4984(gfx);
    gfx = func_xk2_800EDF90(gfx);
    func_xk2_800F2B48(&gfx);
    if (D_xk2_80119918 != 0) {
        gSPDisplayList(gfx++, D_3000510);
        gDPSetPrimColor(gfx++, 0, 0, 0, 30, 70, 255);
        gSPTextureRectangle(gfx++, 0 << 2, 0 << 2, SCREEN_WIDTH << 2, 56 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    } else {
        gfx = func_xk2_800E8080(gfx);
    }
    gfx = func_xk2_800E5214(gfx);
    func_xk2_800F3164(&gfx);
    if (D_80794E14 == 0) {
        gfx = func_xk2_800EA3B0(gfx);
    }

    if ((D_800D6CA0.unk_08 == 0x11) || (D_800D6CA0.unk_08 == 0x23) || (D_800D6CA0.unk_08 == 0xFF)) {
        func_xk1_8002D340(&gfx);
    }
    if (D_800D6CA0.unk_08 == 0xFF) {
        func_xk2_800EECD4(&gfx, 0, 0x48, D_80033268, 0x1E);
    }
    if (D_xk2_80119918 == 0) {
        gfx = func_xk2_800E0320(gfx);
    }
    func_xk2_800EE8A0(&gfx);
    func_xk2_800EE67C(&gfx);
    if (D_xk2_80119918 == 0) {
        func_xk2_800F3548(&gfx);
        func_xk2_800F3600(&gfx);
    }
    func_xk2_800F3DAC(&gfx);
    if (D_800D6CA0.unk_08 == 4) {
        func_xk2_800F5250(&gfx);
    }
    if (D_800D6CA0.unk_08 == 2) {
        gfx = func_xk1_80029B48(gfx, &D_xk2_800F6824, &D_xk2_800F6828);
        if (D_80119880 == 9) {
            s32 x = 24;
            s32 y = 56;
            s32 width = 256;
            gSPDisplayList(gfx++, D_3000510);
            gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y - 2) << 2, (x + width + 2) << 2, y << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, (y + 16) << 2, (x + width + 2) << 2, (y + 16 + 2) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x - 2) << 2, y << 2, x << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPTextureRectangle(gfx++, (x + width) << 2, y << 2, (x + width + 2) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 160);
            gSPTextureRectangle(gfx++, x << 2, y << 2, (x + width) << 2, (y + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            gSPDisplayList(gfx++, D_3000540);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_800264C0(gfx, 0x18, 0x38, 0x10);
        }
    }
    func_xk2_800EA8E8(&gfx);
    func_xk2_800EA948(&gfx);
    return gfx;
}

extern unk_80128C94* D_80128C94;

void func_xk2_800DFFF8(void) {
    CourseSegment* var_s0;
    Vtx* vtx;
    s32 i;
    Vec3f sp68;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;

    if (D_807B3C20.unk_2900 < 2) {
        return;
    }
    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        var_s0 = &D_807B3C20.unk_0000[i];
        func_i2_800B2500(var_s0, 0.0f, &sp68);
        func_807033A0(&sp68.x, &sp68.y, &sp68.z);

        temp_fa1 = (var_s0->unk_0C.y * sp68.z) - (sp68.y * var_s0->unk_0C.z);
        temp_ft4 = (var_s0->unk_0C.z * sp68.x) - (sp68.z * var_s0->unk_0C.x);
        temp_ft5 = (var_s0->unk_0C.x * sp68.y) - (sp68.x * var_s0->unk_0C.y);
        vtx = &D_80128C94->unk_0180[i * 6];
        vtx->v.ob[0] = var_s0->pos.x;
        vtx->v.ob[1] = var_s0->pos.y;
        vtx->v.ob[2] = var_s0->pos.z;
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x;
        vtx->v.ob[1] = 0;
        vtx->v.ob[2] = var_s0->pos.z;
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (300.0f * sp68.x);
        vtx->v.ob[1] = var_s0->pos.y + (300.0f * sp68.y);
        vtx->v.ob[2] = var_s0->pos.z + (300.0f * sp68.z);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (300.0f * var_s0->unk_0C.x);
        vtx->v.ob[1] = var_s0->pos.y + (300.0f * var_s0->unk_0C.y);
        vtx->v.ob[2] = var_s0->pos.z + (300.0f * var_s0->unk_0C.z);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x + (var_s0->radiusLeft * temp_fa1);
        vtx->v.ob[1] = var_s0->pos.y + (var_s0->radiusLeft * temp_ft4);
        vtx->v.ob[2] = var_s0->pos.z + (var_s0->radiusLeft * temp_ft5);
        vtx++;
        vtx->v.ob[0] = var_s0->pos.x - (var_s0->radiusRight * temp_fa1);
        vtx->v.ob[1] = var_s0->pos.y - (var_s0->radiusRight * temp_ft4);
        vtx->v.ob[2] = var_s0->pos.z - (var_s0->radiusRight * temp_ft5);
    }
}

extern u16 D_90005A0[];
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;

Gfx* func_xk2_800E0320(Gfx* gfx) {
    s32 var_v0;
    s32 var_v1;

    if (D_800D6CA0.unk_00 == 1) {
        return gfx;
    }
    // clang-format off
    if (D_800D6CA0.unk_08 == 1) {
        var_v0 = D_xk1_8003A550; \
        var_v1 = D_xk1_8003A554;
    } else {
        var_v0 = D_xk2_800F6824; \
        var_v1 = D_xk2_800F6828;
    }
    // clang-format on
    if (D_800D6CA0.unk_08 == 0x20) {
        return gfx;
    }
    if (D_800D6CA0.unk_08 == 4) {
        return gfx;
    }
    if (D_800D6CA0.unk_08 == 3) {
        return gfx;
    }

    if (D_800D6CA0.unk_08 == 0x10) {
        return gfx;
    }
    gSPDisplayList(gfx++, D_8014940);

    gDPLoadTextureBlock(gfx++, D_90005A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, var_v0 << 2, var_v1 << 2, (var_v0 + 16) << 2, (var_v1 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    
    return gfx;
}

extern Gfx D_9014C60[];
extern u32 gGameFrameCount;
extern s32 D_8079A35C;
extern unk_80128690 D_80128690[];

Gfx* func_xk2_800E04E0(Gfx* gfx) {
    s32 i;
    s32 spC0;
    s32 spBC;
    s32 spB8;
    f32 var_fs1;
    Vec3f spA8;
    s32 var_a0;

    if (D_8076C950 != 0) {
        return gfx;
    }
    spC0 = func_xk2_800EFDE4(150.0f);
    gSPDisplayList(gfx++, D_9014C60);

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        gDPPipeSync(gfx++);
        if (D_80128690[i].unk_08 != 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.unk_1C) && (D_8079A35C != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == D_800D6CA0.unk_20) && (D_8079A35C != 0)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else if ((i == spC0) && (D_800D6CA0.unk_00 != 1)) {
            if (D_8079A35C != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else if (i == 0) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 255, 128);
        } else {
            var_a0 = Math_Round(D_807B3C20.unk_0000[i].pos.y);
            if (var_a0 < 0) {
                var_a0 = 0;
            }
            var_a0 = (var_a0 * 255) / 5000;
            gDPSetPrimColor(gfx++, 0, 0, var_a0, var_a0, 255, 255);
        }
        spA8 = D_807B3C20.unk_0000[i].pos;

        if (func_xk2_800EF090(spA8, &spBC, &spB8) != 0) {
            continue;
        }

        if (D_80128690[i].unk_08 != 0) {
            var_fs1 = ((gGameFrameCount % 10) * 0.2f) + 1.0f;
        } else {
            var_fs1 = 1.0f;
        }

        gSPTextureRectangle(gfx++, Math_Round(spBC - (4.0f * var_fs1)) << 2, Math_Round(spB8 - (4.0f * var_fs1)) << 2, Math_Round(spBC + (4.0f * var_fs1)) << 2, Math_Round(spB8 + (4.0f * var_fs1)) << 2, 0, 0, 0, Math_Round((1 << 10) / var_fs1), Math_Round((1 << 10) / var_fs1));
    }
    return gfx;
}

s32 func_xk2_800E08FC(s32 arg0) {
    CourseSegment* var_a0;
    s32 i;
    s32 var_a1;
    s32 var_a3;


    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        var_a0 = &D_807B3C20.unk_0000[i];
        var_a1 = D_80128690[var_a0->segmentIndex].unk_00;
        var_a3 = D_80128690[var_a0->segmentIndex].unk_04;
        if (var_a1 > var_a3) {
            var_a1 = 0;
        }
        if ((arg0 >= var_a1) && (arg0 < var_a3)) {
            break;
        }
    }
    return i;
}

extern unk_80128C94 D_6000000;

extern s32 D_8079A364;
extern s32 D_xk1_80030614;
extern s32 D_xk2_800F7058;
extern s8 D_xk2_800F7070[][4];

extern unk_8011C220 D_8011C220[];

Gfx* func_xk2_800E0988(Gfx* gfx) {
    s32 i;
    s32 var_a2;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 64, 64, 64, 255);
    gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);

    if ((D_800D6CA0.unk_20 != -1) || (D_807B3C20.unk_2900 < 4)) {
        return func_xk2_800E73DC(gfx);
    }
    if (D_xk2_800F7044 != 0) {
        return gfx;
    } else if (D_807B3C20.unk_2900 < 4) {
        return gfx;
    } 

    for (i = 0; i < D_xk2_800F7058; i++) {
        if ((func_xk2_800E08FC(i) == D_800D6CA0.unk_0C) && (D_8079A364 == 0) && (D_xk1_80030614 != 1)) {
            continue;
        }
        gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
        gDPPipeSync(gfx++);
        var_a2 = TRACK_SHAPE_INDEX(D_8011C220[i].unk_00 & TRACK_SHAPE_MASK);

        gDPSetPrimColor(gfx++, 0, 0, D_xk2_800F7070[var_a2][0], D_xk2_800F7070[var_a2][1], D_xk2_800F7070[var_a2][2], 255);
        gSPLineW3D(gfx++, 0, 1, D_xk2_800F7070[var_a2][3], 0);
    }
    return gfx;
}

extern s32 D_xk2_800F7034;

Gfx* func_xk2_800E0BD0(Gfx* gfx) {
    CourseSegment* var_v1_6;
    s32 var_t4;
    s32 var_t5;
    s32 i;

    if (D_807B3C20.unk_2900 < 4) {
        return gfx;
    } 
    
    if (D_xk1_80030614 == 1) {
        return gfx;
    }
    
    if (D_800D6CA0.unk_20 != -1) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_NOOP2);
        if (D_800D6CA0.unk_0C != -1) {
            var_t5 = D_800D6CA0.unk_0C;
        } else {
            var_t5 = 0;
        }
        var_t4 = D_807B3C20.unk_0000[var_t5].next->segmentIndex;
        if (var_t4 < var_t5) {
            for (i = 0; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_807B3C20.unk_2900) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }

            for (i = var_t5; i < D_807B3C20.unk_2900; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_807B3C20.unk_2900) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        } else {
            for (i = var_t5; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 1, 0);
                gSPVertex(gfx++, &D_6000000.unk_0180[((i + 1) % D_807B3C20.unk_2900) * 6], 1, 1);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
        return gfx;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255 - D_xk2_800F7034);
    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    if (D_800D6CA0.unk_0C != -1) {
        var_v1_6 = &D_807B3C20.unk_0000[D_800D6CA0.unk_0C];
    } else {
        var_v1_6 = &D_807B3C20.unk_0000[0];
    }

    var_t5 = D_80128690[var_v1_6->segmentIndex].unk_00;
    var_t4 = D_80128690[var_v1_6->segmentIndex].unk_04;

    if (var_t4 < var_t5) {
        for (i = 0; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }

        for (i = var_t5; i < D_xk2_800F7058; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    } else {
        for (i = var_t5; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }
    
    return gfx;
}

Gfx* func_xk2_800E17E0(Gfx* gfx, s32 arg1) {
    s32 var_t5;
    s32 var_t4;
    s32 i;

    var_t5 = D_80128690[arg1].unk_00;
    var_t4 = D_80128690[arg1].unk_04;

    if (var_t4 < var_t5) {
        if (var_t5 < 0x10000) {
            for (i = 0; i < var_t4; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
    
            for (i = var_t5; i < D_xk2_800F7058; i++) {
                gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
                gSPLineW3D(gfx++, 0, 1, 10, 0);
            }
        }
    } else {
        for (i = var_t5; i < var_t4; i++) {
            gSPVertex(gfx++, &D_6000000.unk_1980[i], 2, 0);
            gSPLineW3D(gfx++, 0, 1, 10, 0);
        }
    }
    return gfx;
}

extern s32 D_xk1_80030628;

Gfx* func_xk2_800E1B28(Gfx* gfx) {
    s32 i;

    if (D_xk1_80030628 != 5) {
        return gfx;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.landmine[i] == LANDMINE_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1BCC(Gfx* gfx) {
    s32 i;

    if (D_xk1_80030628 != 1) {
        return gfx;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.dash[i] == DASH_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1C70(Gfx* gfx) {
    s32 i;

    if (D_xk1_80030628 != 4) {
        return gfx;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.jump[i] == JUMP_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1D14(Gfx* gfx) {
    s32 i;

    if (D_xk1_80030628 != 6) {
        return gfx;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.gate[i] == GATE_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1DB8(Gfx* gfx) {
    s32 i;

    if (D_xk1_80030628 != 8) {
        return gfx;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        if (gCourseCtx.courseData.sign[i] == SIGN_NONE) {
            continue;
        }
        gfx = func_xk2_800E17E0(gfx, i);
    }
    return gfx;
}

Gfx* func_xk2_800E1E5C(Gfx* gfx) {

    if (D_807B3C20.unk_2900 < 4) {
        return gfx;
    }
    if (D_xk1_80030614 != 3) {
        return gfx;
    }
    if (D_800D6CA0.unk_20 != -1) {
        return gfx;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, D_xk2_800F7034);

    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_NOOP2);

    gfx = func_xk2_800E1B28(gfx);
    gfx = func_xk2_800E1BCC(gfx);
    gfx = func_xk2_800E1C70(gfx);
    gfx = func_xk2_800E1D14(gfx);
    gfx = func_xk2_800E1DB8(gfx);
    return gfx;
}

extern Gfx D_70207A0[];

void func_xk2_800E1F40(Gfx** gfxP) {
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    if (D_807B3C20.unk_2900 < 4) {
        return;
    }

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        gSPVertex(gfx++, &D_6000000.unk_0180[i * 6], 6, 0);
        gSPDisplayList(gfx++, D_70207A0);
    }

    *gfxP = gfx;
}

extern Gfx D_3000338[];
extern FrameBuffer* gFrameBuffers[];

void func_xk2_800E1FC0(Gfx** gfxP) {
    Gfx* gfx;

    gfx = Segment_SetTableAddresses(*gfxP);
    gSPDisplayList(gfx++, D_3000338);
    gSPSetGeometryMode(gfx++, G_CLIPPING);
    gSPClipRatio(gfx++, FRUSTRATIO_2);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, PHYSICAL_TO_VIRTUAL(gFrameBuffers[D_8079A364]));
    gDPSetDepthImage(gfx++, K0_TO_PHYS(0x803DBC00));
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    gfx = func_xk2_800F1428(gfx);
    if (D_8076C950 == 0) {
        gSPMatrix(gfx++, K0_TO_PHYS(&D_xk2_80119838), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    }
    *gfxP = gfx;
}

Gfx* func_xk2_800E2104(Gfx* gfx) {

    if (D_8076C950 != 0) {
        return gfx;
    }

    gSPLoadUcodeL(gfx++, gspL3DEX2_fifo);
    func_xk2_800E1FC0(&gfx);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gfx = func_xk2_800E0988(gfx);
    gfx = func_xk2_800E1E5C(gfx);
    gfx = func_xk2_800E0BD0(gfx);
    func_xk2_800E1F40(&gfx);
    gSPLoadUcodeL(gfx++, gspF3DEX2_fifo);
    func_xk2_800E1FC0(&gfx);
    return gfx;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/D_xk2_800F7240.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E2238.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E38A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E396C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E3E90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E4364.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E47B4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E4984.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E49FC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E4BA0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E4D04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E4E80.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5058.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5214.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E54A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5570.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5870.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5920.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5A38.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5B6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E5D90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E6270.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E6B3C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E6CA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E6F9C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7028.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E72BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E73DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7518.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E77F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7854.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7990.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7A78.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E7BA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E8080.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E8F7C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9134.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9234.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E92E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E93B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9504.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E95E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E96F4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9808.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E98D8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9A58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800E9C4C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA028.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA248.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA3B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA4E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA8E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/191080/func_xk2_800EA948.s")
