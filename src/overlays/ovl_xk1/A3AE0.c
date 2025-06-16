#include "global.h"

extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;
extern s32 D_80119890;

void func_xk1_80026870(void) {
    D_80119890 = 0;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

void func_xk1_800268A8(void) {
    D_80119890 = 1;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

extern s32 D_800D6CA0[];
extern s32 D_xk1_80032C20;

void func_xk1_800268E4(void) {
    D_80119890 = 2;
    D_xk1_80032C20 = 0;
    D_800D6CA0[2] = 0x23;
}

extern s32 D_xk1_800305F0;

void func_xk1_80026908(s32 arg0) {
    D_xk1_800305F0 = arg0;
}

typedef struct unk_80026914_unk_1C {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    struct unk_80026914* unk_10;
    void (*unk_14)(void);
    u16 unk_18;
    u16 unk_1A;
    s8 unk_1C[0x4];
    void* unk_20;
} unk_80026914_unk_1C; // size = 0x24

typedef struct unk_80026914 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    unk_80026914_unk_1C* unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32* unk_30;
} unk_80026914;

unk_80026914* func_xk1_80026914(unk_80026914* arg0) {
    unk_80026914* temp_a0;
    unk_80026914* var_v1 = arg0;

    while (true) {
        if (var_v1->unk_04 == -1) {
            break;
        }
        temp_a0 = var_v1->unk_1C[var_v1->unk_04].unk_10;
        if (temp_a0 == NULL) {
            break;
        }
        var_v1 = temp_a0;
    }
    
    return var_v1;
}

extern s32 D_xk1_8003060C;

s32 func_xk1_80026958(unk_80026914* arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 var_v1;

    var_v1 = -1;
    for (i = 0; i < arg0->unk_00; i++) {
        if ((arg1 >= (arg0->unk_0C + arg0->unk_14 * i)) && (arg1 < ((arg0->unk_0C + arg0->unk_14 * i) + 0x30))) {
            if (((arg2 + D_xk1_8003060C) >= (arg0->unk_10 + (arg0->unk_18 * i))) && ((arg2 + D_xk1_8003060C) < ((arg0->unk_10 + (arg0->unk_18 * i)) + 0x10))) {
                var_v1 = i;
            }
        }
    }
    return var_v1;
}

void func_xk1_800269F4(unk_80026914* arg0, s32* arg1, s32* arg2) {
    s32 var_v0;
    s32 var_v1;
    unk_80026914* temp_v1;

    while (true) {
        if (arg0->unk_04 == -1) {
            break;
        }
        temp_v1 = arg0->unk_1C[arg0->unk_04].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    var_v0 = *arg1;
    var_v1 = *arg2;
    if (var_v0 < arg0->unk_20) {
        var_v0 = arg0->unk_20;
    }

    if (arg0->unk_28 < var_v0) {
        var_v0 = arg0->unk_28;
    }

    if (arg0->unk_2C < var_v1) {
        var_v1 = arg0->unk_2C;
    }

    if (arg0->unk_00 < 10) {
        if (var_v1 < arg0->unk_24) {
            var_v1 = arg0->unk_24;
        }
        *arg1 = var_v0;
        *arg2 = var_v1;
    } else {
        if ((arg0->unk_10 + 160) < var_v1) {
            D_xk1_8003060C = ((D_xk1_8003060C + 16) / 16) * 16;
            var_v1 = arg0->unk_10 + 156;
        }
    
        if (arg0->unk_2C < (var_v1 + D_xk1_8003060C)) {
            D_xk1_8003060C = arg0->unk_2C - var_v1;
        }
    
        if (var_v1 < arg0->unk_10) {
            D_xk1_8003060C -= 16;
            var_v1 = arg0->unk_24;
        }
        if (D_xk1_8003060C < 0) {
            D_xk1_8003060C = 0;
        }
        *arg1 = var_v0;
        *arg2 = var_v1;
    }
}

extern s32 D_xk1_80030600;
extern unk_80026914 D_xk1_80031C28;
extern unk_80026914 D_xk1_80031E50;
extern unk_80026914 D_xk1_80032880;
extern u8 D_70201A0[];

void func_xk1_80026B44(Gfx** gfxP, unk_80026914* arg1, s32 arg2, s32 arg3) {
    s32 temp_ra;
    s32 temp_s0;
    s32 temp_v0;
    unk_80026914_unk_1C* var_t5;
    s32 width;
    s32 height;
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    temp_v0 = func_xk1_80026958(arg1, arg2, arg3);

    for (i = 0; i < arg1->unk_00; i++) {
        var_t5 = &arg1->unk_1C[i];

        temp_ra = arg1->unk_0C + (i * arg1->unk_14);
        temp_s0 = (arg1->unk_10 + (i * arg1->unk_18)) - (D_xk1_8003060C * (arg1->unk_14 == 0));
        
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (i == temp_v0) {
            if (var_t5->unk_04 != NULL) {
                gDPLoadTextureBlock(gfx++, var_t5->unk_04, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            }
        } else {
            if (((arg1 == &D_xk1_80032880) || (arg1 == &D_xk1_80031E50)) && (i != temp_v0)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if ((arg1 == &D_xk1_80031C28) && (temp_v0 != 2) && (i == 2)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if (var_t5->unk_00 != 0) {
                gDPLoadTextureBlock(gfx++, var_t5->unk_00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (arg1->unk_1C[i].unk_0C != NULL) {
            gDPLoadTextureBlock(gfx++, var_t5->unk_0C, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 19) << 2, (temp_s0 + 2) << 2, (temp_ra + 45) << 2, (temp_s0 + 14) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
        if (arg1->unk_1C[i].unk_08 != 0) {
            width = var_t5->unk_18;
            height = var_t5->unk_1A;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, var_t5->unk_08, G_IM_FMT_I, width, height, 0,
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + width) << 2, (temp_s0 + height) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
        if (arg1->unk_1C[i].unk_20 != 0) {
            width = 16;
            height = 16;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, var_t5->unk_20, G_IM_FMT_I, width, height, 0,
                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 28) << 2, temp_s0 << 2, (temp_ra + 44) << 2, (temp_s0 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
        if ((i == temp_v0) && (D_800D6CA0[2] != 3) && ((arg1 != &D_xk1_80032880) || (temp_v0 != 5))) {
            gDPPipeSync(gfx++);
            gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0);

            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_xk1_80030600);

            gDPLoadTextureBlock(gfx++, D_70201A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);

            if (D_xk1_800305F0 != 0) {
                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
            }
        }
    }
    *gfxP = gfx;
}

extern u8 D_701F5A0[];
extern u32 gGameFrameCount;

extern s32 D_xk1_80030604;

void func_xk1_800276B0(Gfx** gfxP, unk_80026914* arg1, s32 arg2, s32 arg3) {
    Gfx* gfx;
    unk_80026914* temp_v1;

    gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    D_xk1_80030600 += D_xk1_80030604 * func_xk1_80025C0C();

    if (D_xk1_80030600 > 255) { \
        D_xk1_80030600 = 255;   \
        D_xk1_80030604 = -4;
    }
    if (D_xk1_80030600 < 100) { \
        D_xk1_80030600 = 100;   \
        D_xk1_80030604 = 4;
    }
    func_xk1_80026B44(&gfx, arg1, arg2, arg3);

    while (true) {
        if (arg1->unk_14 != 0) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + 48, arg1->unk_10 + (arg1->unk_18 * 9) + 0x10);
        }

        if (arg1->unk_04 == -1) {
            break;
        }
        temp_v1 = arg1->unk_1C[arg1->unk_04].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        arg1 = temp_v1;
    }

    func_xk1_80026B44(&gfx, arg1, arg2, arg3);
    
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    
    if ((arg1->unk_00 > 10) && (D_xk1_8003060C < ((arg1->unk_00 - 10) * arg1->unk_18))) {
        if ((gGameFrameCount % 4) >= 2) {
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPLoadTextureBlock(gfx++, D_701F5A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                    G_TX_NOLOD, G_TX_NOLOD);
            
            gSPTextureRectangle(gfx++, (arg1->unk_0C + 8) << 2, (arg1->unk_10 + (arg1->unk_18 * 0xA)) << 2, (arg1->unk_0C + 40) << 2, ((arg1->unk_10 + (arg1->unk_18 * 0xA)) + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    *gfxP = gfx;
}

extern s32 D_xk1_800305F8;
extern s32 D_xk1_80030610;
extern s32 D_xk1_80030678;
extern unk_80026914 D_xk1_800314C0;

void func_xk1_80027B74(unk_80026914* arg0) {
    unk_80026914* temp_v1;
    s32 temp_v0;

    if (D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->unk_1C[temp_v0].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }
    if (arg0 != &D_xk1_800314C0) {
        func_8074122C(0x25);
    }
    D_xk1_80030610 = -1;
    D_xk1_80030678 = -1;
    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
}

void func_xk1_80027C1C(unk_80026914* arg0) {
    unk_80026914* temp_v1;
    s32 temp_v0;

    if (D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->unk_1C[temp_v0].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
}

void func_xk1_80027C80(unk_80026914* arg0) {
    unk_80026914* temp_v1;
    s32 temp_v0;

    if (D_800D6CA0[2] != 1 || D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->unk_1C[temp_v0].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
    D_800D6CA0[2] = 0;
}

extern s32 D_xk2_800F7048;

void func_xk1_80027CFC(unk_80026914* arg0, s32* arg1, s32* arg2) {
    s32 pad;
    unk_80026914* var_a3 = arg0;
    unk_80026914* temp_v1;
    s32 var_a1;

    if (D_xk2_800F7048 == 1) {
        return;
    }

    while (true) {
        if (var_a3->unk_04 == -1) {
            break;
        }
        temp_v1 = var_a3->unk_1C[var_a3->unk_04].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        var_a3 = temp_v1;
    }

    var_a1 = func_xk1_80026958(var_a3, *arg1, *arg2);

    if ((var_a1 != var_a3->unk_08) && (var_a3->unk_08 != -1) && (var_a3 != &D_xk1_800314C0)) {
        func_8074122C(0x23U);
    }
    var_a3->unk_08 = var_a1;
}

extern s32 D_xk1_800305FC;

void func_xk1_80027DC8(unk_80026914* arg0, s32* arg1, s32* arg2) {
    unk_80026914* temp_v1;
    unk_80026914* var_a3;
    unk_80026914* sp24;
    s32 sp20;

    var_a3 = arg0;
    while (true) {
        if (var_a3->unk_04 == -1) {
            break;
        }
        temp_v1 = var_a3->unk_1C[var_a3->unk_04].unk_10;
        if (temp_v1 == NULL) {
            break;
        }
        var_a3 = temp_v1;
    }

    sp20 = func_xk1_80026958(var_a3, *arg1, *arg2);
    if (sp20 != -1) {
        if (((var_a3 != &D_xk1_80032880) || (sp20 != 2) || (D_xk1_80032880.unk_1C[2].unk_10 != NULL)) && ((var_a3 != &D_xk1_80032880) || (sp20 != 5)) && ((var_a3 != &D_xk1_80032880) || (sp20 != 5)) && (var_a3 != &D_xk1_800314C0)) {
            func_8074122C(0x24);
        }
        if (var_a3 != &D_xk1_800314C0) {
            D_xk1_8003060C = 0;
        }

        var_a3->unk_04 = sp20;
        var_a3->unk_08 = -1;
        if (var_a3->unk_30 != NULL) {
            *var_a3->unk_30 = sp20;
        }

        sp24 = var_a3->unk_1C[sp20].unk_10;
        if (sp24 != NULL) {
            D_xk1_800305F8 = 1;
        }
        if (sp24 != NULL) {
            if (var_a3->unk_1C[sp20].unk_14 != NULL) {
                var_a3->unk_1C[sp20].unk_14();
            }

            if (sp24->unk_30 != NULL) {
                if (*sp24->unk_30 == -1) {
                    D_xk1_800305FC = 0;
                    *arg1 = sp24->unk_20;
                    *arg2 = sp24->unk_24;
                } else {
                    D_xk1_800305FC = *sp24->unk_30;
                    if ((*sp24->unk_30 + 1) > 10) {
                        D_xk1_8003060C = (*sp24->unk_30 - 9) * sp24->unk_18;
                    }
                    *arg1 = (*sp24->unk_30 * sp24->unk_14) + sp24->unk_20;
                    *arg2 = ((*sp24->unk_30 * sp24->unk_18) + sp24->unk_24) - D_xk1_8003060C;
                    
                }
            } else {
                *arg1 = sp24->unk_20;
                *arg2 = sp24->unk_24;
            }
        } else {
            if (var_a3->unk_1C[sp20].unk_14 != NULL) {
                func_xk1_80027C1C(arg0);
                var_a3->unk_1C[sp20].unk_14();
            }
        }
    }
}

extern s32 D_80119880;
extern u8 D_xk2_800F7400;
extern s32 D_xk2_80104378;
extern s32 D_807B6520;
extern s32 D_xk1_80032BF8;
extern unk_80026914 D_xk1_80032160;

void func_xk1_80028064(void) {
    if (D_xk1_80032160.unk_04 == -1) {
        return;
    }
    
    func_xk1_80027C80(&D_xk1_80032880);
    D_xk2_800F7400 = 1;
    switch (D_xk1_80030610) {
        case 0:
            func_8076877C(1, "CRSD");
            PRINTF("LESS POINT\n");
            D_80119880 = 0;
            D_800D6CA0[2] = 50;
            break;
        case 1:
            D_80119880 = 1;
            func_xk2_800F27DC(gCurrentCourseInfo);
            if (D_807B6520 < 4) {
                D_xk1_80032C20 = 0;
                D_800D6CA0[2] = 16;
                D_xk2_80104378 = 9;
                D_80119880 = -2;
            } else {
                D_xk1_80032BF8 = 0;
                func_8076877C(1, "CRSD");
                PRINTF("NAME\n");
                D_800D6CA0[2] = 50;
            }
            break;
        case 2:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("DELETE\n");
            D_80119880 = 3;
            D_800D6CA0[2] = 50;
            break;
        case 3:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            D_80119880 = 2;
            D_800D6CA0[2] = 50;
            break;
        case 4:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("BGM NO. SET %d\n");
            D_80119880 = 7;
            D_800D6CA0[2] = 50;
            break;
    }
}

extern s32 D_80030614;
extern u8 D_9004888[];
extern s32 D_xk1_8003061C;
extern s32* D_xk1_80030680;
extern unk_80026914 D_xk1_80032354;
extern unk_80026914_unk_1C D_xk1_800327A8[];

void func_xk1_8002820C(void) {
    D_80030614 = 0;
    D_xk1_800327A8[1].unk_08 = &D_9004888;
    D_xk1_800327A8[1].unk_10 = &D_xk1_80032354;
    D_xk1_80030680 = &D_xk1_8003061C;
    D_xk1_800327A8[2].unk_08 = NULL;
    D_xk1_800327A8[2].unk_10 = NULL;
}

extern u8 D_9004A08[];
extern u8 D_9004B88[];
extern u8 D_9004D08[];
extern u8 D_9004E88[];
extern u8 D_9005008[];
extern s32 D_xk1_80030620;
extern s32 D_xk1_80030624;
extern s32 D_xk1_80030628;
extern s32 D_xk1_8003062C;
extern s32 D_xk1_80030630;
extern s32 D_xk1_80030634;
extern s32 D_xk1_80030638;
extern s32 D_xk1_8003063C;
extern s32 D_xk1_80030640;
extern s32 D_xk1_80030644;
extern s32 D_xk1_80030648;
extern s32 D_xk1_8003064C;
extern s32 D_xk1_80030650;
extern s32 D_xk1_80030654;
extern s32 D_xk1_80030658;
extern s32 D_xk1_8003065C;
extern s32 D_xk1_80030660;
extern s32 D_xk1_80030664;
extern s32 D_xk1_80030668;
extern s32 D_xk1_8003066C;
extern s32 D_xk1_80030670;
extern s32 D_xk1_80030674;
extern s32* D_xk1_8003067C[];
extern unk_80026914 D_xk1_80031140;
extern unk_80026914 D_xk1_80031294;
extern unk_80026914 D_xk1_8003226C;
extern unk_80026914 D_xk1_80032484;
extern unk_80026914 D_xk1_800325FC;
extern unk_80026914 D_xk1_80032774;

extern unk_80026914* D_xk1_800328EC[9];
extern s32* D_xk1_80032910[9];
extern unk_80026914* D_xk1_80032934[9];
extern s32* D_xk1_80032958[9];

#ifdef IMPORT_DATA
void func_xk1_80028250(void) {
    unk_80026914* sp94[9] = D_xk1_800328EC;
    s32* sp70[9] = D_xk1_80032910;
    unk_80026914* sp4C[9] = D_xk1_80032934;
    s32* sp28[9] = D_xk1_80032958;

    if (D_xk1_8003226C.unk_04 == -1) {
        return;
    }

    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_80030614) {
        case 0:
            D_xk1_800327A8[1].unk_08 = D_9004888;
            D_xk1_800327A8[1].unk_10 = &D_xk1_80032354;
            D_xk1_8003067C[1] = &D_xk1_8003061C;
            D_xk1_800327A8[2].unk_08 = NULL;
            D_xk1_800327A8[2].unk_10 = NULL;
            D_xk1_8003061C = 0;
            break;
        case 1:
            D_xk1_800327A8[1].unk_08 = D_9004A08;
            D_xk1_800327A8[1].unk_10 = &D_xk1_80032484;
            D_xk1_8003067C[1] = &D_xk1_80030620;
            D_xk1_800327A8[2].unk_08 = NULL;
            D_xk1_800327A8[2].unk_10 = NULL;
            D_xk1_80030620 = 0;
            break;
        case 2:
            D_xk1_80030624 = 0;
            D_xk1_8003062C = 0;
            D_xk1_80030630 = 0;
            D_xk1_80030634 = 0;
            D_xk1_80030638 = 0;
            D_xk1_8003063C = 0;
            D_xk1_80030640 = 0;
            D_xk1_80030644 = 0;
            D_xk1_800327A8[1].unk_08 = D_9004B88;
            D_xk1_800327A8[1].unk_10 = &D_xk1_800325FC;
            D_xk1_8003067C[1] = &D_xk1_80030624;

            switch (D_xk1_80030624) {
                case 7:
                case 8:
                    D_xk1_800327A8[2].unk_08 = NULL;
                    break;
                default:
                    D_xk1_800327A8[2].unk_08 = D_9004E88;
                    break;
            }

            D_xk1_800327A8[2].unk_10 = sp94[D_xk1_80030624];
            D_xk1_8003067C[2] = sp70[D_xk1_80030624];
            break;
        case 3:
            D_xk1_80030628 = 0;
            D_xk1_80030648 = 0;
            D_xk1_8003064C = 0;
            D_xk1_80030650 = 0;
            D_xk1_80030654 = 0;
            D_xk1_80030658 = 0;
            D_xk1_8003065C = 0;
            D_xk1_80030660 = 0;
            D_xk1_80030664 = 0;
            D_xk1_80030668 = 0;

            D_xk1_800327A8[1].unk_08 = D_9004B88;
            D_xk1_800327A8[1].unk_10 = &D_xk1_80032774;
            D_xk1_8003067C[1] = &D_xk1_80030628;
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = sp4C[D_xk1_80030628];
            D_xk1_8003067C[2] = sp28[D_xk1_80030628];
            break;
        case 4:
            D_xk1_800327A8[1].unk_08 = D_9004D08;
            D_xk1_800327A8[1].unk_10 = &D_xk1_80031140;
            D_xk1_8003067C[1] = &D_xk1_8003066C;
            D_xk1_800327A8[2].unk_08 = D_9005008;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80031294;
            D_xk1_8003067C[2] = &D_xk1_80030670;
            break;
        case 5:
            D_xk1_800327A8[1].unk_08 = D_9004E88;
            D_xk1_800327A8[1].unk_10 = &D_xk1_800314C0;
            D_xk1_8003067C[1] = &D_xk1_80030674;
            D_xk1_800327A8[2].unk_08 = NULL;
            D_xk1_800327A8[2].unk_10 = NULL;
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A3AE0/func_xk1_80028250.s")
#endif

extern s8 D_80030060;
extern u8 D_xk2_80104CA0[];
extern s32 D_xk2_80104CB0;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CC0;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F7058;
extern f32 D_xk2_80119744;

extern unk_802D1B60 D_807BCB58;
extern s32 D_800D65C8;

void func_xk1_8002860C(void) {
    func_xk2_800EF78C();
    func_xk2_800F5C50();
    D_80030060 = 0;
    D_xk2_80104CB8 = 0;
    D_xk2_80104CC0 = 0;
    D_xk2_80104CB0 = 90;
    D_800D6CA0[5] = 0;
    D_xk2_800F7044 = 0;
    D_807B6520 = 0;
    gCurrentCourseInfo->segmentCount = 0;
    gCourseCtx.courseData.controlPointCount = 0;
    D_800D6CA0[3] = -1;
    D_800D6CA0[1] = 0;
    D_800D6CA0[7] = -1;
    if (D_800D6CA0[2] != 0x10) {
        func_xk2_800F12B0();
    }
    D_xk2_80104CA0[3] = 0;
    D_xk2_80104CA0[7] = 0;
    D_800D65C8 = 0;
    D_xk2_800F7058 = 0;
    D_xk2_80119744 = 0.0f;
    D_xk1_8003061C = 0;
    func_xk2_800DC3F8();
    func_8070299C();
    gCurrentCourseInfo->length = 0.0f;
    D_807BCB58.unk_0C = 0;
    D_807BCB58.unk_08 = 0;
}

extern s32 D_xk1_80032358;
extern s32 D_xk2_800F7040;

void func_xk1_80028708(void) {
    if (D_xk1_80032354.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_8003061C) {
        case 2:
            func_xk2_800EF78C();
            func_xk2_800E72BC();
            D_xk1_8003061C = 0;
            return;
        case 3:
            func_xk2_800EF78C();
            func_xk2_800F0FF4();
            D_xk2_800F7040 = 3;
            D_xk1_8003061C = 0;
            return;
        case 4:
            D_xk1_80032C20 = 0;
            D_800D6CA0[2] = 0x11;
            break;
        case 0:
        case 1:
            break;
    }
}

extern s32 D_xk1_80032488;

void func_xk1_800287BC(void) {
    if (D_xk1_80032484.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030620) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            break;
    }
}

extern s32* D_xk1_80030684;
extern unk_80026914 D_xk1_80031584;
extern unk_80026914 D_xk1_80031648;
extern unk_80026914 D_xk1_8003170C;
extern unk_80026914 D_xk1_800317D0;
extern unk_80026914 D_xk1_80031F38;
extern unk_80026914 D_xk1_80031FD8;
extern unk_80026914 D_xk1_80032078;

void func_xk1_80028818(void) {
    if (D_xk1_800325FC.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030624) {
        case 0:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80031F38;
            D_xk1_80030684 = &D_xk1_8003062C;
            break;
        case 1:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80031FD8;
            D_xk1_80030684 = &D_xk1_80030630;
            break;
        case 2:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80032078;
            D_xk1_80030684 = &D_xk1_80030634;
            break;
        case 4:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80031648;
            D_xk1_80030684 = &D_xk1_8003063C;
            break;
        case 3:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_80031584;
            D_xk1_80030684 = &D_xk1_80030638;
            break;
        case 5:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_8003170C;
            D_xk1_80030684 = &D_xk1_80030640;
            break;
        case 6:
            D_xk1_800327A8[2].unk_08 = D_9004E88;
            D_xk1_800327A8[2].unk_10 = &D_xk1_800317D0;
            D_xk1_80030684 = &D_xk1_80030644;
            break;
        case 7:
            D_xk1_800327A8[2].unk_08 = NULL;
            D_xk1_800327A8[2].unk_10 = NULL;
            break;
        case 8:
            D_xk1_800327A8[2].unk_08 = NULL;
            D_xk1_800327A8[2].unk_10 = NULL;
            break;
    }
}

extern s32 D_xk1_80032778;
extern unk_80026914 D_xk1_80030744;
extern unk_80026914 D_xk1_80030808;
extern unk_80026914 D_xk1_800308F0;
extern unk_80026914 D_xk1_800309D8;
extern unk_80026914 D_xk1_80030A9C;
extern unk_80026914 D_xk1_80030B60;
extern unk_80026914 D_xk1_80030C24;
extern unk_80026914 D_xk1_80030E98;
extern unk_80026914 D_xk1_80030FA4;

void func_xk1_80028A04(void) {

    if (D_xk1_80032774.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030628) {
        case 0:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030744;
            D_xk1_80030684 = &D_xk1_80030648;
            break;
        case 1:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030808;
            D_xk1_80030684 = &D_xk1_8003064C;
            break;
        case 2:
            D_xk1_800327A8[2].unk_10 = &D_xk1_800308F0;
            D_xk1_80030684 = &D_xk1_80030650;
            break;
        case 3:
            D_xk1_800327A8[2].unk_10 = &D_xk1_800309D8;
            D_xk1_80030684 = &D_xk1_80030654;
            break;
        case 4:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030A9C;
            D_xk1_80030684 = &D_xk1_80030658;
            break;
        case 5:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030B60;
            D_xk1_80030684 = &D_xk1_8003065C;
            break;
        case 6:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030C24;
            D_xk1_80030684 = &D_xk1_80030660;
            break;
        case 7:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030E98;
            D_xk1_80030684 = &D_xk1_80030664;
            break;
        case 8:
            D_xk1_800327A8[2].unk_10 = &D_xk1_80030FA4;
            D_xk1_80030684 = &D_xk1_80030668;
            break;
    }
}

void func_xk1_80028BA0(void) {
    if (D_xk1_80031F38.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028BD4(void) {
    if (D_xk1_80031FD8.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C08(void) {
    if (D_xk1_80032078.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C3C(void) {
    if (D_xk1_80031584.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C70(void) {
    if (D_xk1_80031648.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028CA4(void) {
    if (D_xk1_8003170C.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028CD8(void) {
    if (D_xk1_800317D0.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D0C(void) {
    if (D_xk1_80030744.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D40(void) {
    if (D_xk1_80030808.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D74(void) {
    if (D_xk1_800308F0.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028DA8(void) {
    if (D_xk1_800309D8.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028DDC(void) {
    if (D_xk1_80030A9C.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028E10(void) {
    if (D_xk1_80030B60.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        switch (D_xk1_8003065C) {
            case 0:
            case 1:
            case 2:
                break;
        }
    }
}

void func_xk1_80028E54(void) {
    if (D_xk1_80030C24.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028E88(void) {
    if (D_xk1_80030E98.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028EBC(void) {
    if (D_xk1_80030FA4.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028EF0(void) {
    if (D_xk1_80031140.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        gCourseCtx.courseData.venue = D_xk1_8003066C;
        func_80702FF4(D_xk1_8003066C);
        func_80709A38(D_xk1_8003066C);
        D_xk2_800F7040 = 3;
    }
}

void func_xk1_80028F50(void) {
    if (D_xk1_80031294.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        gCourseCtx.courseData.skybox = D_xk1_80030670;
    }
}

extern s32 D_800D11D4;
extern s32 D_xk1_800305F4;
extern s32 D_xk1_800328B4[];

void func_xk1_80028F94(void) {

    if ((D_xk1_800314C0.unk_04 != -1) && (func_807424CC() == 0)) {
        if (D_xk1_800305F4 != D_xk1_800328B4[D_xk1_80030674]) {
            if (D_800D11D4 != 0) {
                func_8074122C(0x24);
            }
            D_xk1_800305F4 = D_xk1_800328B4[D_xk1_80030674];
            func_80741AF4(D_xk1_800328B4[D_xk1_800314C0.unk_04]);
            D_xk1_800314C0.unk_04 = -1;
            gCourseCtx.courseData.fileName[0x16] = D_xk1_800328B4[D_xk1_80030674];
        }
    }
}

void func_xk1_80029070(void) {
    D_80030614 = 0;
    D_xk1_800327A8[1].unk_08 = D_9004888;
    D_xk1_800327A8[1].unk_10 = &D_xk1_80032354;
    D_xk1_80030680 = &D_xk1_8003061C;
    D_xk1_800327A8[2].unk_08 = NULL;
    D_xk1_800327A8[2].unk_10 = NULL;
}

s32 func_xk1_800290B4(void) {
    return D_xk1_8003060C;
}

s32 func_xk1_800290C0(void) {
    return D_xk1_80030600;
}
