#include "global.h"
#include "fzx_font.h"
#include "fzx_machine.h"
#include "fzx_assets.h"

Gfx* func_xk3_8012E120(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width - 1) << 2, (top + height - 1) << 2, 0, 0, 0,
                        4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E358(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height, u8 uls, u8 ult, u8 lrs, u8 lrt) {

    gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, uls, ult, lrs, lrt, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + uls) << 2, (top + ult) << 2, (left + lrs) << 2, (top + lrt) << 2, 0, uls << 5, ult << 5,
                        4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E518(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E740(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0,
                        1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E970(Gfx* gfx, TexturePtr texture, f32 left, f32 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (u16)(left * 4.0f), (u16)(top * 4.0f), (u16)((left + width) * 4.0f), (u16)((top + height) * 4.0f), 0, 0, 0,
                        1 << 10, 1 << 10);

    return gfx;
}

extern Gfx D_xk3_80137378[];

Gfx* func_xk3_8012EDDC(Gfx* gfx, TexturePtr arg1, TexturePtr arg2, u16 left, u16 top, u8 width, u8 height, u8 red, u8 green, u8 blue) {

    gSPDisplayList(gfx++, D_xk3_80137378);
    gfx = func_xk3_8012E120(gfx, arg1, left, top, width, height);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetTextureFilter(gfx++, G_TF_POINT);
    gfx = func_xk3_8012E518(gfx, arg2, left, top, width, height);

    return gfx;
}

Gfx* func_xk3_8012EEF0(Gfx* gfx, u8* texture, u16 left, u16 top, u8 width, u8 height, u8 arg6, u8 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    u8 temp_s1;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;

    for (i = 0; i < height; i++) {
        temp_s1 = (height - i) - 1;
        red = Math_Round((f32) ((arg6 * temp_s1) + (arg9 * i)) / (height - 1));
        green = Math_Round((f32) ((arg7 * temp_s1) + (argA * i)) / (height - 1));
        blue = Math_Round((f32) ((arg8 * temp_s1) + (argB * i)) / (height - 1));
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);

        gDPLoadTextureBlock(gfx++, texture + width * i, G_IM_FMT_I, G_IM_SIZ_8b, width, 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, left << 2, (top + i) << 2, (left + width) << 2, (top + i + 1) << 2, 0, 0, 0,
                            1 << 10, 1 << 10);

    }
    return gfx;
}

Gfx* func_xk3_8012F2F4(Gfx* gfx, u16 left, u16 top, u16 right, u16 bottom, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 argA) {
    u16 temp_s1;
    u16 height;
    u16 i;
    u8 red;
    u8 green;
    u8 blue;

    height = (bottom - top) + 1;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (i = 0; i < height; i++) {
        temp_s1 = (height - i) - 1;
        red = Math_Round(((temp_s1 * arg5) + (arg8 * i)) / (height - 1));
        green = Math_Round(((temp_s1 * arg6) + (arg9 * i)) / (height - 1));
        blue = Math_Round(((temp_s1 * arg7) + (argA * i)) / (height - 1));
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
        gDPFillRectangle(gfx++, left, top + i, right + 1, top + i + 1);
    }
    return gfx;
}

void func_xk3_8012F594(void) {
}

extern u8 D_xk3_80140750[];

s32 func_xk3_8012F59C(s32 arg0) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (arg0 == D_xk3_80140750[i]) {
            return func_8070DBE0(i);
        }
    }

    return 0;
}

extern unk_800792D8* D_xk3_80136E60[];

void func_xk3_8012F5F0(Object* arg0) {
    OBJECT_CACHE_INDEX(arg0) = func_i2_800AF9F8(D_xk3_80136E60[0]);
    OBJECT_STATE(arg0) = -1;
}

extern s32 D_xk3_80136820;
extern unk_800E3F28 D_800D63F8[];

Gfx* func_xk3_8012F628(Gfx* gfx, Object* arg1) {

    if (D_xk3_80136820 != 0x1C) {
        gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(arg1)], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0, 0, 1.0f, 1.0f, 0);
    }
    return gfx;
}

extern u8 D_xk1_800333F0;
extern u8 D_800333F4;
extern unk_806F2400_unk_00 D_xk1_800333D0;

void func_xk3_8012F6A8(Object* arg0) {
    s32 temp_v1;
    s32 var_a3;
    s32 var_v0;
    u8 temp_a0;

    if (D_xk3_80136820 == 0x1C) {
        return;
    }

    if (D_xk1_800333F0 != 0) {
        if (arg0->state != (D_800333F4 + 30)) {
            var_a3 = func_8070DBE0(D_800333F4) + 30;
            if (var_a3 >= 36) {
                var_a3 %= 30;
            }
            func_i2_800AFB1C(arg0->cacheIndex, 0, D_xk3_80136E60[var_a3]);
        }
        arg0->state = D_800333F4 + 30;
    } else {
        if (arg0->state != (D_xk1_800333D0.unk_07 - 1)) {
            func_i2_800AFB1C(arg0->cacheIndex, 0, D_xk3_80136E60[func_xk3_8012F59C(D_xk1_800333D0.unk_07)]);
        }
        arg0->state = D_xk1_800333D0.unk_07 - 1;
    }
}

extern const char* D_xk3_801372E0;
extern const char* D_xk3_801372E4;

void func_xk3_8012F7AC(Gfx** gfxP, char* arg1) {
    Gfx* gfx;
    u16 sp6A;
    u16 sp68;
    u8 sp67;
    char sp44[35];
    u8 sp43 = 0;

    gfx = *gfxP;
    if (Leo_strlen(arg1) >= 9) {
        sp43 = 1;
    }
    func_xk1_80026830(arg1, &sp44);
    if (sp43) {
        sp67 = Leo_strlen(&sp44) + Leo_strlen(D_xk3_801372E0);
        sp6A = ((((34 - sp67) / 2) + 3) * 8);
        sp68 = 46;

        gfx = func_xk1_8002EA10(gfx, sp6A, sp68, sp6A + (sp67 * 8), 124 - sp68, GPACK_RGBA5551(130, 130, 255, 1));
    } else {
        sp67 = Leo_strlen(&sp44) + Leo_strlen(D_xk3_801372E0) + Leo_strlen(D_xk3_801372E4);
        sp6A = ((((34 - sp67) / 2) + 3) * 8);
        sp68 = 54;
        gfx = func_xk1_8002EA10(gfx, sp6A, sp68, sp6A + (sp67 * 8), 124 - sp68, GPACK_RGBA5551(130, 130, 255, 1));
    }

    gDPSetPrimColor(gfx++, 0, 0, 255, 64, 64, 255);
    gfx = func_xk1_800262F4(gfx, sp6A, sp68, &sp44);
    sp6A += Leo_strlen(&sp44) * 8;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    if (sp43) {
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372E0);
        sp68 += 16;
        sp6A = (((((34 - sp67) / 2) + 3) * 8));
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372E4);
    } else {
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372E0);
        sp6A += 16;
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372E4);
    }

    func_xk1_8002D340(&gfx);
    *gfxP = gfx;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140570.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_8014057C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_8014058C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405C4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801405F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140610.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140618.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140628.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140630.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140640.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140650.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140664.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140678.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140688.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140690.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801406FC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_8014070C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140714.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140728.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_8014073C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140750.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140770.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140780.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140784.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140788.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_80140798.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801407A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801407B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/D_xk3_801407C0.s")

extern u8* D_xk3_80136708[];
extern Gfx D_xk3_801373F0[];
extern u8 D_xk3_80138930[];
extern u8 D_xk3_80139770[];

Gfx* func_xk3_8012FA94(Gfx* gfx, s32 arg1, s32 arg2, s32 arg3) {
    u8 i;
    signed char sp60[4];

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_xk3_8012E740(gfx, D_xk3_80138930, arg1, arg2, 32, 16);
    if (arg3 < 1000) {
        arg1 += 0x29;
    } else {
        arg1 += 0x21;
    }
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    sprintf(sp60, "%d", arg3);
    i = 0;
    while (sp60[i] != 0) {
        gfx = func_xk3_8012E740(gfx, D_xk3_80136708[sp60[i] - '0'], arg1, arg2, 8, 16);
        i++;
        arg1 += 8;
    }

    arg1++;
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139770, arg1, arg2, 16, 16);

    return gfx;
}

Gfx* func_xk3_8012FC58(Gfx* gfx, s32 arg1, s8* arg2) {

    gfx = func_xk3_8012FA94(gfx, 170, 190, arg1);
    gfx = Font_DrawString(gfx, 252 - Font_GetStringWidth(arg2, 4, 0), 219, arg2, 0, 4, 0);
    gfx = Object_UpdateAndDrawAll(gfx);
    func_i2_800AF7E0();
    return gfx;
}

extern f32 D_xk3_80136540;

Gfx* func_xk3_8012FCD8(Gfx* gfx, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6) {

    if (!((D_xk3_80136540 >= -100.0f) && (D_xk3_80136540 <= 100.0f))) {
        arg1 *= 0.8f;
        arg2 *= 0.8f;
        arg3 *= 0.8f;
        arg4 *= 0.8f;
        arg5 *= 0.8f;
        arg6 *= 0.8f;
    }

    if (D_xk1_800333D0.decal == MACHINE_DECAL(DECAL_BLOCK)) {
        gDPSetPrimColor(gfx++, 0, 0, arg4, arg5, arg6, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, arg1, arg2, arg3, 255);
    }
    return gfx;
}

extern u16 D_xk3_80136730[][2];
extern u16 D_xk3_80136784[][7];
extern u8 D_xk3_801367B0[][7];
extern u16 D_xk3_801367C8[][7];
extern u8 D_xk3_801367F4[][7];
extern u8 D_xk3_80139D70[];
extern u8 D_xk3_80139EB0[];
extern u8 D_xk3_80139FF0[];
extern u8 D_xk3_8013A130[];
extern u8 D_xk3_8013A158[];
extern u16 D_xk3_8013A180[];
extern u16 D_xk3_8013A580[];
extern s32 D_xk3_80141294;

extern unk_80140E60 D_xk3_80140E60;

Gfx* func_xk3_801301B4(Gfx* gfx) {
    u8 i;
    u8 j;

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gfx = func_xk3_8012FCD8(gfx, D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue, D_xk1_800333D0.decalR, D_xk1_800333D0.decalG, D_xk1_800333D0.decalB);
    gfx = func_xk3_8012E970(gfx, D_xk3_8013A130, 117.5f, 125.0f, 8, 5);
    gfx = func_xk3_8012E970(gfx, D_xk3_8013A158, 78.5f, 125.0f, 8, 5);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139D70, D_xk3_80136730[D_xk1_800333D0.frontType][0], D_xk3_80136730[D_xk1_800333D0.frontType][1], 40, 8);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139EB0, D_xk3_80136730[D_xk1_800333D0.rearType + 7][0], D_xk3_80136730[D_xk1_800333D0.rearType + 7][1], 40, 8);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139FF0, D_xk3_80136730[D_xk1_800333D0.wingType + 14][0], D_xk3_80136730[D_xk1_800333D0.wingType + 14][1], 40, 8);
    gfx = func_xk3_8012FA94(gfx, 150, 155, D_xk3_80141294);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[i][j], D_xk3_801367B0[i][j], D_xk3_801367C8[i][j], D_xk3_801367F4[i][j], GPACK_RGBA5551(100, 100, 100, 1), 1, 1);
        }
    }
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[0][D_xk1_800333D0.frontType], D_xk3_801367B0[0][D_xk1_800333D0.frontType], D_xk3_801367C8[0][D_xk1_800333D0.frontType], D_xk3_801367F4[0][D_xk1_800333D0.frontType], GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[1][D_xk1_800333D0.rearType], D_xk3_801367B0[1][D_xk1_800333D0.rearType], D_xk3_801367C8[1][D_xk1_800333D0.rearType], D_xk3_801367F4[1][D_xk1_800333D0.rearType], GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[2][D_xk1_800333D0.wingType], D_xk3_801367B0[2][D_xk1_800333D0.wingType], D_xk3_801367C8[2][D_xk1_800333D0.wingType], D_xk3_801367F4[2][D_xk1_800333D0.wingType], GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    if (D_xk3_80140E60.unk_04 == 3) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A580, 264, 155, 32, 16);
    } else {
        gfx = func_xk1_8002FDF8(gfx, D_xk3_80136784[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], D_xk3_801367B0[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], D_xk3_801367C8[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], D_xk3_801367F4[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], 255, 64, 64, func_xk1_800290C0(), 2, 2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A180, 264, 155, 32, 16);
    }
    return gfx;
}

extern unk_801413F0* D_xk3_801414B0;
extern GfxPool* gGfxPool;

Gfx* func_xk3_80130698(Gfx* gfx, s32 arg1) {
    MtxF spC0;
    MtxF sp80;

    gDPPipeSync(gfx++);
    gSPDisplayList(gfx++, D_90186C8);

    switch (arg1) {
        case 0:
            Matrix_FromMtx(gGfxPool->unk_1A108, &sp80);
            Light_SetLookAtSource(&gGfxPool->unk_33B28, &sp80);
            gSPLookAt(gfx++, &gGfxPool->unk_33B28);
            break;
        case 1:
            func_806F8FE0(NULL, &spC0, D_xk3_80136540, 0.0f, 1320.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            Light_SetLookAtSource(&D_xk3_801414B0->unk_00[2], &spC0);
            gSPLookAt(gfx++, &D_xk3_801414B0->unk_00[2]);
            break;
    }

    gSPTexture(gfx++, 1250, 1250, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 80);
    return gfx;
}

extern Gfx* (*D_xk3_801366CC[])(Gfx*);
extern Gfx* (*D_xk3_801366E0[])(Gfx*);
extern Gfx* D_xk3_80136600[][7];
extern Vp D_xk3_801372F0;
extern Gfx D_xk3_801374A8[];
extern Gfx D_xk3_80137538[];
extern u8 D_xk3_801407C0[];
extern f32 D_xk3_80140E78;
extern f32 D_xk3_80140E7C;
extern GfxPool D_1000000;

Gfx* func_xk3_80130920(Gfx* gfx) {
    u16 spBE;

    if (D_xk3_80136820 == 0x11) {
        gSPViewport(gfx++, &D_xk3_801372F0);
    } else {
        gSPViewport(gfx++, &gGfxPool->unk_362C8[1]);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 25, 90, 153, 218);

    }
    
    gSPDisplayList(gfx++, D_xk3_801374A8);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gSPDisplayList(gfx++, D_xk3_80137538);

    func_806F9384(gGfxPool->unk_1A008, NULL, 44.0f, 10.0f, 12800.0f, 320.0f, 0.0f, 240.0f, 0.0f, &spBE);
    func_806F8FE0(gGfxPool->unk_1A108, NULL, 0.0f, 880.0f, 1320.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    func_806F86C0(&gGfxPool->unk_32308[1], NULL, 1.0f, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E78)), 0, 0, 0.0f, 0.0f, 0.0f);
    func_806F86C0(&gGfxPool->unk_32308[2], NULL, 1.0f, 0, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E7C)), 0, 0.0f, 0.0f, 0.0f);

    gSPMatrix(gfx++, &D_1000000.unk_1A008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_1A108, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gfx++, spBE);
    gSPMatrix(gfx++, &D_1000000.unk_32308[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gfx++, &D_1000000.unk_32308[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (D_xk1_800333F0 != 0) {
        gfx = D_xk3_801366E0[D_800333F4](gfx);
        gDPSetEnvColor(gfx++, D_xk3_801407C0[D_800333F4 * 3 + 0], D_xk3_801407C0[D_800333F4 * 3 + 1], D_xk3_801407C0[D_800333F4 * 3 + 2], 255); 
        gfx = D_xk3_801366CC[D_800333F4](gfx);
    } else {
        gfx = Machine_DrawLoadCustomTextures(gfx, D_xk1_800333D0.logo - 1, D_xk1_800333D0.unk_07 - 1, D_xk1_800333D0.decal - 1);
        gDPSetEnvColor(gfx++, D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue, 255);
        gfx = Machine_DrawCustom(gfx, 0, D_xk1_800333D0.frontType, D_xk1_800333D0.rearType, D_xk1_800333D0.wingType, D_xk1_800333D0.decalR, D_xk1_800333D0.decalG, D_xk1_800333D0.decalB, D_xk1_800333D0.numberR, D_xk1_800333D0.numberG, D_xk1_800333D0.numberB, 255, 255, 255, D_xk1_800333D0.cockpitR, D_xk1_800333D0.cockpitG, D_xk1_800333D0.cockpitB);
    }
    gfx = func_xk3_80130698(gfx, 0);
    gDPSetRenderMode(gfx++, G_RM_ZB_OVL_SURF, G_RM_ZB_OVL_SURF2);

    if (D_xk1_800333F0 != 0) {
        switch (D_800333F4) {
            case 0:
                gSPDisplayList(gfx++, D_9012718);
                break;
            case 3:
                gSPDisplayList(gfx++, D_9013460);
                break;
            case 4:
                gSPDisplayList(gfx++, D_9013D58);
                break;
        }
    } else {
        gSPDisplayList(gfx++, D_xk3_80136600[0][D_xk1_800333D0.frontType]);
        gSPDisplayList(gfx++, D_xk3_80136600[1][D_xk1_800333D0.rearType]);
        gSPDisplayList(gfx++, D_xk3_80136600[2][D_xk1_800333D0.wingType]);
    }
    if (D_xk3_80136820 != 0x11) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);

    }
    return gfx;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/func_xk3_80130EE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CDDE0/func_xk3_80131494.s")
