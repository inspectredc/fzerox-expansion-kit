#include "global.h"
#include "leo/leo_functions.h"
#include "fzx_game.h"
#include "fzx_font.h"
#include "fzx_machine.h"
#include "fzx_assets.h"

extern u8 D_xk3_80139870[];
extern u8 D_xk3_801398F0[];
extern u8 D_xk3_80139970[];
extern u8 D_xk3_801399F0[];
extern u8 D_xk3_80139A70[];
extern u8 D_xk3_80139AF0[];
extern u8 D_xk3_80139B70[];
extern u8 D_xk3_80139BF0[];
extern u8 D_xk3_80139C70[];
extern u8 D_xk3_80139CF0[];

Vp D_xk3_801412A0[3][7];
unk_801413F0 D_xk3_801413F0[2];
unk_801413F0* D_xk3_801414B0;

Gfx* D_xk3_80136600[][7] = {
    { D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088, D_90148F8 },
    { D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948 },
    { D_90186C0, D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8 },
};

const char* D_xk3_80136654[] = {
    "MM ガゼル",
    "ジョディ サマー",
    "ドクター スチュワート",
    "ババ",
    "サムライ ゴロー",
    "ピコ",
    "キャプテン ファルコン",
    "オクトマン",
    "ミスター EAD",
    "ジェームズ マクラウド",
    "ビリー",
    "ケイト アレン",
    "ゾーダ",
    "ジャック レビン",
    "バイオレックス",
    "アービン ゴードン",
    "アントニオ ガスター",
    "ビーストマン",
    "レオン",
    "スーパー アロー",
    "ミセス アロー",
    "ゴマー&シオー",
    "シルバー ニールセン",
    "マイケル チェーン",
    "ブラッド ファルコン",
    "ジョン タナカ",
    "ドラク",
    "ロジャー バスター",
    "ドクター クラッシュ",
    "ブラック シャドー",
};

Gfx* (*D_xk3_801366CC[])(Gfx*) = {
    Machine_DrawSuperFalconLod1,   Machine_DrawSuperFalconLod1, Machine_DrawSuperFalconLod1,
    Machine_DrawSuperStingrayLod1, Machine_DrawSuperCatLod1,
};

Gfx* (*D_xk3_801366E0[])(Gfx*) = {
    Machine_DrawLoadBlueFalconTextures,   Machine_DrawLoadBlueFalconTextures, Machine_DrawLoadBlueFalconTextures,
    Machine_DrawLoadFireStingrayTextures, Machine_DrawLoadWhiteCatTextures,
};

const u8 D_xk3_80140750[] = {
    7, 3, 6, 5, 2, 1, 4, 8, 29, 9, 15, 11, 23, 22, 26, 21, 25, 14, 10, 13, 24, 20, 12, 28, 19, 27, 18, 17, 30, 16,
};

const char* D_xk3_801366F4[] = {
    "SUPER FALCON", "X", "X", "SUPER STINGRAY", "SUPER CAT",
};

u8* D_xk3_80136708[] = {
    D_xk3_80139870, D_xk3_801398F0, D_xk3_80139970, D_xk3_801399F0, D_xk3_80139A70,
    D_xk3_80139AF0, D_xk3_80139B70, D_xk3_80139BF0, D_xk3_80139C70, D_xk3_80139CF0,
};

u16 D_xk3_80136730[][7][2] = {
    { { 23, 70 }, { 62, 70 }, { 101, 70 }, { 140, 70 }, { 179, 70 }, { 218, 70 }, { 257, 70 } },
    { { 23, 107 }, { 62, 107 }, { 101, 107 }, { 140, 107 }, { 179, 107 }, { 218, 107 }, { 257, 107 } },
    { { 23, 144 }, { 62, 144 }, { 101, 144 }, { 140, 144 }, { 179, 144 }, { 218, 144 }, { 257, 144 } },
};

u16 D_xk3_80136784[][7] = {
    { 23, 62, 101, 140, 179, 218, 257 },
    { 23, 62, 101, 140, 179, 218, 257 },
    { 23, 62, 101, 140, 179, 218, 257 },
};

u8 D_xk3_801367B0[][7] = {
    { 40, 40, 40, 40, 40, 40, 40 },
    { 77, 77, 77, 77, 77, 77, 77 },
    { 114, 114, 114, 114, 114, 114, 114 },
};

u16 D_xk3_801367C8[][7] = {
    { 62, 101, 140, 179, 218, 257, 296 },
    { 62, 101, 140, 179, 218, 257, 296 },
    { 62, 101, 140, 179, 218, 257, 296 },
};

u8 D_xk3_801367F4[][7] = {
    { 77, 77, 77, 77, 77, 77, 77 },
    { 114, 114, 114, 114, 114, 114, 114 },
    { 151, 151, 151, 151, 151, 151, 151 },
};

const u16 D_xk3_801407A4[] = {
    790, 0, 0, 2210, 1840,
};

const u8 D_xk3_801407B0[][3] = {
    { 4, 3, 4 }, { 0, 0, 0 }, { 0, 0, 0 }, { 3, 4, 4 }, { 4, 4, 3 },
};

const u8 D_xk3_801407C0[][3] = {
    { 223, 199, 33 }, { 0, 0, 0 }, { 0, 0, 0 }, { 55, 55, 55 }, { 33, 55, 137 },
};

Gfx* func_xk3_8012E120(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width - 1) << 2, (top + height - 1) << 2, 0, 0, 0,
                        4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E358(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height, u8 uls, u8 ult, u8 lrs,
                       u8 lrt) {

    gDPLoadTextureTile(gfx++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, uls, ult, lrs, lrt, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (left + uls) << 2, (top + ult) << 2, (left + lrs) << 2, (top + lrt) << 2, 0, uls << 5,
                        ult << 5, 4 * (1 << 10), 1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E518(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock_4b(gfx++, texture, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E740(Gfx* gfx, TexturePtr texture, u16 left, u16 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, left << 2, top << 2, (left + width) << 2, (top + height) << 2, 0, 0, 0, 1 << 10,
                        1 << 10);

    return gfx;
}

Gfx* func_xk3_8012E970(Gfx* gfx, TexturePtr texture, f32 left, f32 top, u8 width, u8 height) {

    gDPLoadTextureBlock(gfx++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, (u16) (left * 4.0f), (u16) (top * 4.0f), (u16) ((left + width) * 4.0f),
                        (u16) ((top + height) * 4.0f), 0, 0, 0, 1 << 10, 1 << 10);

    return gfx;
}

extern Gfx D_xk3_80137378[];

Gfx* func_xk3_8012EDDC(Gfx* gfx, TexturePtr arg1, TexturePtr arg2, u16 left, u16 top, u8 width, u8 height, u8 red,
                       u8 green, u8 blue) {

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

Gfx* func_xk3_8012EEF0(Gfx* gfx, u8* texture, u16 left, u16 top, u8 width, u8 height, u8 arg6, u8 arg7, u8 arg8,
                       u8 arg9, u8 argA, u8 argB) {
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

        gSPTextureRectangle(gfx++, left << 2, (top + i) << 2, (left + width) << 2, (top + i + 1) << 2, 0, 0, 0, 1 << 10,
                            1 << 10);
    }
    return gfx;
}

Gfx* func_xk3_8012F2F4(Gfx* gfx, u16 left, u16 top, u16 right, u16 bottom, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                       f32 arg9, f32 argA) {
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
        gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(arg1)], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0, 0,
                               1.0f, 1.0f, 0);
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
        if (OBJECT_STATE(arg0) != (D_800333F4 + 30)) {
            var_a3 = func_8070DBE0(D_800333F4) + 30;
            if (var_a3 >= 36) {
                var_a3 %= 30;
            }
            func_i2_800AFB1C(OBJECT_CACHE_INDEX(arg0), 0, D_xk3_80136E60[var_a3]);
        }
        OBJECT_STATE(arg0) = D_800333F4 + 30;
    } else {
        if (OBJECT_STATE(arg0) != (D_xk1_800333D0.number - 1)) {
            func_i2_800AFB1C(OBJECT_CACHE_INDEX(arg0), 0, D_xk3_80136E60[func_xk3_8012F59C(D_xk1_800333D0.number)]);
        }
        OBJECT_STATE(arg0) = D_xk1_800333D0.number - 1;
    }
}

extern u8* D_xk3_801372B8[];

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
        sp67 = Leo_strlen(&sp44) + Leo_strlen(D_xk3_801372B8[10]);
        sp6A = ((((34 - sp67) / 2) + 3) * 8);
        sp68 = 46;

        gfx = func_xk1_8002EA10(gfx, sp6A, sp68, sp6A + (sp67 * 8), 124 - sp68, GPACK_RGBA5551(130, 130, 255, 1));
    } else {
        sp67 = Leo_strlen(&sp44) + Leo_strlen(D_xk3_801372B8[10]) + Leo_strlen(D_xk3_801372B8[11]);
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
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[10]);
        sp68 += 16;
        sp6A = (((((34 - sp67) / 2) + 3) * 8));
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[11]);
    } else {
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[10]);
        sp6A += 16;
        gfx = func_xk1_800262F4(gfx, sp6A, sp68, D_xk3_801372B8[11]);
    }

    func_xk1_8002D340(&gfx);
    *gfxP = gfx;
}

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
    gfx = func_xk3_8012FCD8(gfx, D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue, D_xk1_800333D0.decalR,
                            D_xk1_800333D0.decalG, D_xk1_800333D0.decalB);
    gfx = func_xk3_8012E970(gfx, D_xk3_8013A130, 117.5f, 125.0f, 8, 5);
    gfx = func_xk3_8012E970(gfx, D_xk3_8013A158, 78.5f, 125.0f, 8, 5);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139D70, D_xk3_80136730[0][D_xk1_800333D0.frontType][0],
                            D_xk3_80136730[0][D_xk1_800333D0.frontType][1], 40, 8);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139EB0, D_xk3_80136730[1][D_xk1_800333D0.rearType][0],
                            D_xk3_80136730[1][D_xk1_800333D0.rearType][1], 40, 8);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139FF0, D_xk3_80136730[2][D_xk1_800333D0.wingType][0],
                            D_xk3_80136730[2][D_xk1_800333D0.wingType][1], 40, 8);
    gfx = func_xk3_8012FA94(gfx, 150, 155, D_xk3_80141294);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[i][j], D_xk3_801367B0[i][j], D_xk3_801367C8[i][j],
                                    D_xk3_801367F4[i][j], GPACK_RGBA5551(100, 100, 100, 1), 1, 1);
        }
    }
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[0][D_xk1_800333D0.frontType],
                            D_xk3_801367B0[0][D_xk1_800333D0.frontType], D_xk3_801367C8[0][D_xk1_800333D0.frontType],
                            D_xk3_801367F4[0][D_xk1_800333D0.frontType], GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[1][D_xk1_800333D0.rearType], D_xk3_801367B0[1][D_xk1_800333D0.rearType],
                            D_xk3_801367C8[1][D_xk1_800333D0.rearType], D_xk3_801367F4[1][D_xk1_800333D0.rearType],
                            GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    gfx = func_xk1_8002FCA0(gfx, D_xk3_80136784[2][D_xk1_800333D0.wingType], D_xk3_801367B0[2][D_xk1_800333D0.wingType],
                            D_xk3_801367C8[2][D_xk1_800333D0.wingType], D_xk3_801367F4[2][D_xk1_800333D0.wingType],
                            GPACK_RGBA5551(255, 255, 255, 1), 1, 1);
    if (D_xk3_80140E60.unk_04 == 3) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A580, 264, 155, 32, 16);
    } else {
        gfx = func_xk1_8002FDF8(gfx, D_xk3_80136784[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
                                D_xk3_801367B0[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
                                D_xk3_801367C8[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00],
                                D_xk3_801367F4[D_xk3_80140E60.unk_04][D_xk3_80140E60.unk_00], 255, 64, 64,
                                func_xk1_800290C0(), 2, 2);
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
            Light_SetLookAtSource(&D_xk3_801414B0->unk_40, &spC0);
            gSPLookAt(gfx++, &D_xk3_801414B0->unk_40);
            break;
    }

    gSPTexture(gfx++, 1250, 1250, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 80);
    return gfx;
}

extern Vp D_xk3_801372F0;
extern Gfx D_xk3_801374A8[];
extern Gfx D_xk3_80137538[];
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
    func_806F86C0(&gGfxPool->unk_32308[1], NULL, 1.0f, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E78)), 0, 0, 0.0f, 0.0f,
                  0.0f);
    func_806F86C0(&gGfxPool->unk_32308[2], NULL, 1.0f, 0, Math_Round(DEG_TO_FZXANG2(D_xk3_80140E7C)), 0, 0.0f, 0.0f,
                  0.0f);

    gSPMatrix(gfx++, &D_1000000.unk_1A008, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_1A108, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPPerspNormalize(gfx++, spBE);
    gSPMatrix(gfx++, &D_1000000.unk_32308[2], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPMatrix(gfx++, &D_1000000.unk_32308[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    if (D_xk1_800333F0 != 0) {
        gfx = D_xk3_801366E0[D_800333F4](gfx);
        gDPSetEnvColor(gfx++, D_xk3_801407C0[D_800333F4][0], D_xk3_801407C0[D_800333F4][1],
                       D_xk3_801407C0[D_800333F4][2], 255);
        gfx = D_xk3_801366CC[D_800333F4](gfx);
    } else {
        gfx = Machine_DrawLoadCustomTextures(gfx, D_xk1_800333D0.logo - 1, D_xk1_800333D0.number - 1,
                                             D_xk1_800333D0.decal - 1);
        gDPSetEnvColor(gfx++, D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue, 255);
        gfx = Machine_DrawCustom(gfx, 0, D_xk1_800333D0.frontType, D_xk1_800333D0.rearType, D_xk1_800333D0.wingType,
                                 D_xk1_800333D0.decalR, D_xk1_800333D0.decalG, D_xk1_800333D0.decalB,
                                 D_xk1_800333D0.numberR, D_xk1_800333D0.numberG, D_xk1_800333D0.numberB, 255, 255, 255,
                                 D_xk1_800333D0.cockpitR, D_xk1_800333D0.cockpitG, D_xk1_800333D0.cockpitB);
    }
    gfx = func_xk3_80130698(gfx, 0);
    gDPSetRenderMode(gfx++, G_RM_ZB_OVL_SURF, G_RM_ZB_OVL_SURF2);

    if (D_xk1_800333F0 != 0) {
        switch (D_800333F4) {
            case CAPTAIN_FALCON:
                gSPDisplayList(gfx++, D_9012718);
                break;
            case SAMURAI_GOROH:
                gSPDisplayList(gfx++, D_9013460);
                break;
            case JODY_SUMMER:
                gSPDisplayList(gfx++, D_9013D58);
                break;
        }
    } else {
        gSPDisplayList(gfx++, D_xk3_80136600[MACHINE_PART_FRONT][D_xk1_800333D0.frontType]);
        gSPDisplayList(gfx++, D_xk3_80136600[MACHINE_PART_REAR][D_xk1_800333D0.rearType]);
        gSPDisplayList(gfx++, D_xk3_80136600[MACHINE_PART_WING][D_xk1_800333D0.wingType]);
    }
    if (D_xk3_80136820 != 0x11) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
    }
    return gfx;
}

extern FrontMachineDraw sFrontMachineDrawFuncs[][5];
extern RearMachineDraw sRearMachineDrawFuncs[][5];
extern WingMachineDraw sWingMachineDrawFuncs[][5];
extern Gfx D_xk3_80137570[];

Gfx* func_xk3_80130EE0(Gfx* gfx) {
    u8 j;
    u8 i;

    gSPDisplayList(gfx++, D_xk3_801374A8);
    gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPDisplayList(gfx++, D_xk3_80137570);
    gfx = Machine_DrawLoadCustomTextures(gfx, D_xk1_800333D0.logo - 1, D_xk1_800333D0.number - 1,
                                         D_xk1_800333D0.decal - 1);
    func_806F8FE0(&gGfxPool->unk_1A108[1], NULL, 0.0f, 0.0f, 2000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    func_806F86C0(&gGfxPool->unk_32308[3], NULL, 1.0f, 0x400, 0, 0, 0.0f, 0.0f, 0.0f);
    func_806F9628(&D_xk3_801414B0->unk_00, NULL, 1.0f, -1550.0f, 1550.0f, -1550.0f, 1550.0f, 10.0f, 12800.0f);

    gSPMatrix(gfx++, &D_xk3_801414B0->unk_00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_1A108[1], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(gfx++, &D_1000000.unk_32308[3], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            if ((i == MACHINE_PART_WING) && (j < 3)) {
                continue;
            }
            gSPViewport(gfx++, &D_xk3_801412A0[i][j]);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue, 255);
            switch (i) {
                case MACHINE_PART_FRONT:
                    if (j == FRONT_3) {
                        gDPPipeSync(gfx++);
                        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
                    }
                    gfx = sFrontMachineDrawFuncs[j][0](
                        gfx, D_xk1_800333D0.decalR, D_xk1_800333D0.decalG, D_xk1_800333D0.decalB,
                        D_xk1_800333D0.numberR, D_xk1_800333D0.numberG, D_xk1_800333D0.numberB, 255, 255, 255,
                        D_xk1_800333D0.cockpitR, D_xk1_800333D0.cockpitG, D_xk1_800333D0.cockpitB);

                    if (j == FRONT_3) {
                        gDPPipeSync(gfx++);
                        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
                    }
                    break;
                case MACHINE_PART_REAR:
                    switch (j) {
                        case REAR_2:
                        case REAR_3:
                        case REAR_6:
                            gDPPipeSync(gfx++);
                            gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
                            break;
                    }
                    gfx = sRearMachineDrawFuncs[j][0](gfx, D_xk1_800333D0.decalR, D_xk1_800333D0.decalG,
                                                      D_xk1_800333D0.decalB, D_xk1_800333D0.numberR,
                                                      D_xk1_800333D0.numberG, D_xk1_800333D0.numberB);

                    switch (j) {
                        case REAR_2:
                        case REAR_3:
                        case REAR_6:
                            gDPPipeSync(gfx++);
                            gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_OPA_SURF2);
                            break;
                    }
                    break;
                case MACHINE_PART_WING:
                    gfx = sWingMachineDrawFuncs[j][0](gfx, D_xk1_800333D0.decalR, D_xk1_800333D0.decalG,
                                                      D_xk1_800333D0.decalB, D_xk1_800333D0.numberR,
                                                      D_xk1_800333D0.numberG, D_xk1_800333D0.numberB);
                    break;
            }
        }
    }
    gfx = func_xk3_80130698(gfx, 1);
    gDPSetRenderMode(gfx++, G_RM_CLD_SURF, G_RM_CLD_SURF2);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 7; j++) {
            if ((i == MACHINE_PART_WING) && (j < 3)) {
                continue;
            }
            gSPViewport(gfx++, &D_xk3_801412A0[i][j]);
            gSPDisplayList(gfx++, D_xk3_80136600[i][j]);
        }
    }
    return gfx;
}

extern u8 D_4000A80[];
extern u8 D_4000C00[];
extern u8 D_4000D80[];
extern u8 D_4000F00[];
extern u8 D_4001080[];
extern u8 D_4001200[];
extern u8 D_4001500[];
extern u8 D_4001800[];
extern u8 D_4001980[];
extern u8 D_7005180[];
extern u8 D_7005D80[];
extern u8 D_7007580[];
extern u8 D_7010180[];
extern u8 D_701F9A0[];

extern u8 D_xk3_80136548;
extern u8 D_xk3_8013654C;
extern s32 D_xk3_80136658;
extern s32 D_xk3_80136664;
extern s32 D_xk3_8013666C;
extern Gfx D_xk3_80137378[];
extern Gfx D_xk3_801373F0[];
extern u16 D_xk3_80137590[];
extern u8 D_xk3_80138390[];
extern u8 D_xk3_801385D0[];
extern u8 D_xk3_80138B30[];
extern u8 D_xk3_80138CB0[];
extern u8 D_xk3_8013A980[];
extern Gfx D_xk3_8013B280[];
extern s32 D_xk3_80141294;
extern unk_80026914 D_xk1_80031E50;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;

extern unk_806F2400 D_806F2400;
extern unk_800E51B8* D_xk3_80140E44;
extern u8* D_xk3_80141298;

Gfx* func_xk3_80131494(Gfx* gfx) {
    static f32 D_xk3_8013680C = 0.0f;
    static s8 D_xk3_80136810 = 1;
    f32 spD0[6];
    f32 var_fv0;
    u16 color;
    u8 i;
    s32 pad;

    if (D_xk3_80136820 == 0x11) {
        var_fv0 = 0.001f;
    } else {
        var_fv0 = 0.0025f;
    }

    if (D_xk3_80136810 == 1) {
        D_xk3_8013680C += var_fv0;
        if (D_xk3_8013680C >= 1.0f) {
            D_xk3_8013680C = 1.0f;
            D_xk3_80136810 = -1;
        }
    } else {
        D_xk3_8013680C -= var_fv0;
        if (D_xk3_8013680C <= 0.0f) {
            D_xk3_8013680C = 0.0f;
            D_xk3_80136810 = 1;
        }
    }

    spD0[0] = ((1.0f - D_xk3_8013680C) * (50.0f - 50.0f)) + (D_xk3_8013680C * 50.0f);
    spD0[1] = ((1.0f - D_xk3_8013680C) * (75.0f - 75.0f)) + (D_xk3_8013680C * 75.0f);
    spD0[2] = ((1.0f - D_xk3_8013680C) * (165.0f - 165.0f)) + (D_xk3_8013680C * 165.0f);
    spD0[3] = ((1.0f - D_xk3_8013680C) * (150.0f - 150.0f)) + (D_xk3_8013680C * 150.0f);
    spD0[4] = ((1.0f - D_xk3_8013680C) * (180.0f - 180.0f)) + (D_xk3_8013680C * 180.0f);
    spD0[5] = ((1.0f - D_xk3_8013680C) * (200.0f - 100.0f)) + (D_xk3_8013680C * 200.0f);

    gSPLoadUcodeL(gfx++, gspF3DEX2_Rej_fifo);
    gSPClipRatio(gfx++, FRUSTRATIO_5);
    gSPDisplayList(gfx++, D_xk3_80137378);
    gDPLoadTextureBlock(gfx++, D_xk3_80137590, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 28, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 12 << 2, 8 << 2, 307 << 2, 27 << 2, 0, 12 << 5, 8 << 5, 4 * (1 << 10), 1 << 10);

    for (i = 1; i < 8; i++) {
        gSPTextureRectangle(gfx++, 12 << 2, (i * 28) << 2, 307 << 2, (i * 28 + 27) << 2, 0, 12 << 5, 0, 4 * (1 << 10),
                            1 << 10);
    }

    gSPTextureRectangle(gfx++, 12 << 2, 224 << 2, 307 << 2, 231 << 2, 0, 12 << 5, 0, 4 * (1 << 10), 1 << 10);

    if (D_xk3_80136820 == 0x11) {
        gfx = func_xk3_80130920(gfx);
        gfx = func_xk3_8012F2F4(gfx, 24, 41, 295, 76, spD0[0], spD0[1], spD0[2], spD0[3], spD0[4], spD0[5]);
        gfx = func_xk3_8012F2F4(gfx, 24, 78, 295, 113, spD0[0], spD0[1], spD0[2], spD0[3], spD0[4], spD0[5]);
        gfx = func_xk3_8012F2F4(gfx, 24, 115, 295, 150, spD0[0], spD0[1], spD0[2], spD0[3], spD0[4], spD0[5]);
        gfx = func_xk3_80130EE0(gfx);
        gfx = func_xk3_801301B4(gfx);
    } else {
        gfx = func_xk3_8012F2F4(gfx, 25, 90, 152, 217, spD0[0], spD0[1], spD0[2], spD0[3], spD0[4], spD0[5]);
        if (D_xk3_80136548 != 0) {
            color = GPACK_RGBA5551(255, 70, 70, 1);
        } else {
            color = GPACK_RGBA5551(255, 255, 255, 1);
        }
        gfx = func_xk1_8002FCA0(gfx, 24, 89, 153, 218, color, 1, 1);

        switch (D_xk3_80136820) {
            case 0x14:
            case 0x15:
            case 0x16:
            case 0x17:
                if (func_80711AC0(D_xk3_80140E44, 1) == 0) {
                    gfx = func_xk3_80135474(gfx);
                }
                break;
            default:
                gfx = func_xk3_80135474(gfx);
                break;
        }

        gSPDisplayList(gfx++, D_xk3_801373F0);

        gfx = func_xk3_8012EEF0(gfx, D_xk3_80138390, 170, 82, 48, 12, 255, 255, 0, 255, 120, 0);
        gfx = func_xk3_8012EEF0(gfx, D_xk3_801385D0, 170, 118, 72, 12, 255, 255, 0, 255, 120, 0);
        gSPDisplayList(gfx++, D_xk3_80137378);
        if (D_xk1_800333F0 != 0) {
            gfx = func_xk3_8012E358(gfx, D_xk3_8013B280, 178, 97, 120, 16, 0, 0, 59, 15);
            gfx = func_xk3_8012E358(gfx, D_xk3_8013B280, 178, 97, 120, 16, 60, 0, 119, 15);
            gSPDisplayList(gfx++, D_xk3_801373F0);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            gfx = func_xk1_8002924C(gfx, 182, 101, "%s", D_xk3_801366F4[D_800333F4]);
            if ((D_800333F4 == CAPTAIN_FALCON) && (D_806F2400.unk_3C0[CAPTAIN_FALCON] == -1)) {
                gfx = func_xk3_8012FC58(gfx, D_xk3_801407A4[D_800333F4], D_xk3_80136654[6]);
            } else if ((D_800333F4 == SAMURAI_GOROH) && (D_806F2400.unk_3C0[SAMURAI_GOROH] == -1)) {
                gfx = func_xk3_8012FC58(gfx, D_xk3_801407A4[D_800333F4], D_xk3_80136654[4]);
            } else if ((D_800333F4 == JODY_SUMMER) && (D_806F2400.unk_3C0[JODY_SUMMER] == -1)) {
                gfx = func_xk3_8012FC58(gfx, D_xk3_801407A4[D_800333F4], D_xk3_80136654[1]);
            } else {
                gfx = func_xk3_8012FA94(gfx, 200, 195, D_xk3_801407A4[D_800333F4]);
            }
        } else {
            gfx = func_xk3_8012E120(gfx, D_xk3_8013A980, 190, 97, 72, 16);
            if ((D_xk3_80136820 != 0x22) && (D_xk1_800333D0.machineName[0] != 0)) {
                gSPDisplayList(gfx++, D_xk3_801373F0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = func_xk1_8002924C(gfx, 194, 101, "%s", D_xk1_800333D0.machineName);
            }

            if (D_xk1_800333D0.number != 31) {
                gfx = func_xk3_8012FC58(gfx, D_xk3_80141294, D_xk3_80136654[D_xk1_800333D0.number - 1]);
            } else {
                gfx = func_xk3_8012FA94(gfx, 200, 195, D_xk3_80141294);
            }
        }
        gfx = func_xk3_80130920(gfx);
        switch (D_xk3_80136820) {
            case 34:
                gfx = func_xk1_80029B48(gfx, 0, 0);
                break;
            case 4:
            case 15:
            case 25:
            case 30:
                gfx = func_xk1_8002C420(gfx, 88, 54);
                gfx = func_xk1_8002B17C(gfx, 8);
                break;
            case 5:
            case 26:
            case 31:
                gfx = func_xk1_8002C420(gfx, 88, 54);
                gfx = func_xk1_8002B17C(gfx, 14);
                break;
            case 6:
                func_xk1_8002C720(&gfx, 88, 54, D_xk3_80141298, 0);
                func_xk1_8002D340(&gfx);
                break;
            case 16:
                func_xk1_8002C720(&gfx, 88, 54, D_xk3_80141298, 2);
                func_xk1_8002D340(&gfx);
                break;
            case 37:
                func_xk1_8002C720(&gfx, 88, 90, D_xk3_80141298, 2);
                func_xk1_8002D340(&gfx);
                break;
            case 32:
            case 33:
                func_xk3_8012F7AC(&gfx, D_xk3_80141298);
                break;
        }
        gfx = func_80711698(gfx);
    }

    if (D_xk3_80136548 != 0) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E358(gfx, D_7000000, 48, 20, 224, 32, 0, 0, 63, 31);
        gfx = func_xk3_8012E358(gfx, D_7000000, 48, 20, 224, 32, 64, 0, 127, 31);
        gfx = func_xk3_8012E358(gfx, D_7000000, 48, 20, 224, 32, 128, 0, 191, 31);
        gfx = func_xk3_8012E358(gfx, D_7000000, 48, 20, 224, 32, 192, 0, 223, 31);
    } else {
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        func_xk1_800276B0(&gfx, &D_xk1_80031E50, D_xk3_80140E50, D_xk3_80140E54);
        switch (D_xk3_80136820) {
            case 3:
            case 4:
            case 5:
                gfx = func_xk3_8012EDDC(gfx, D_7007580, D_4001500, 168, 36, 48, 16, 0, 0, 0);
                break;
            case 14:
            case 15:
                gfx = func_xk3_8012EDDC(gfx, D_7007580, D_xk3_80138CB0, 168, 36, 48, 16, 0, 0, 0);
                break;
            case 24:
            case 25:
            case 26:
                gfx = func_xk3_8012EDDC(gfx, D_7007580, D_4001800, 216, 36, 48, 16, 0, 0, 0);
                break;
            case 30:
            case 31:
                gfx = func_xk3_8012EDDC(gfx, D_7007580, D_4001980, 216, 36, 48, 16, 0, 0, 0);
                break;
            case 34:
                gfx = func_xk3_8012EDDC(gfx, D_7007580, D_xk3_80138B30, 168, 36, 48, 16, 0, 0, 0);
                break;
            case 18:
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4000F00, 72, 36, 48, 16, 0, 0, 0);
                break;
            case 19:
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4000A80, 72, 36, 48, 16, 0, 0, 0);
                break;
            case 2:
                gfx = func_xk3_8012EDDC(gfx, D_7005180, D_4000C00, 72, 36, 48, 16, 0, 0, 0);
                break;
            case 20:
                gfx = func_xk3_8012EDDC(gfx, D_7005180, D_4000C00, 72, 36, 48, 16, 0, 0, 0);
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4000D80, 72, 52, 48, 16, 0, 0, 0);
                break;
            case 21:
                gfx = func_xk3_8012EDDC(gfx, D_7005180, D_4000C00, 72, 36, 48, 16, 0, 0, 0);
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4000F00, 72, 52, 48, 16, 0, 0, 0);
                break;
            case 22:
                gfx = func_xk3_8012EDDC(gfx, D_7005180, D_4000C00, 72, 36, 48, 16, 0, 0, 0);
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4001080, 72, 52, 48, 16, 0, 0, 0);
                break;
            case 23:
                gfx = func_xk3_8012EDDC(gfx, D_7005180, D_4000C00, 72, 36, 48, 16, 0, 0, 0);
                gfx = func_xk3_8012EDDC(gfx, D_7005D80, D_4001200, 72, 52, 48, 16, 0, 0, 0);
                break;
        }
        gSPDisplayList(gfx++, D_xk3_80137378);
        if (D_xk3_8013654C != 0) {
            gfx = func_xk3_8012E120(gfx, D_7010180, 265, 20, 32, 16);
        } else {
            gfx = func_xk3_8012E120(gfx, D_701F9A0, 265, 20, 32, 16);
        }
    }

    return gfx;
}
