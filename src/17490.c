#include "global.h"
#include "fzx_game.h"
#include "fzx_ghost.h"
#include "fzx_assets.h"
#include "src/overlays/ovl_i4/ovl_i4.h"

f32 gCharacterLastEngine[30];
UNUSED s32 D_8079FB18;
u16 gInputPressed;
u16 gInputButtonPressed;
u16 gStickPressed;
s8 gCupNumDifficultiesCleared[4];
s8 D_8079FB28[2];
char* gCurrentTrackName;
char* gTrackNames[55];

s32 gSelectedMode = MODE_GP_RACE;
UNUSED s32 D_8076CC54 = 0;
s32 gModeSubOption[8] = { 0 };
s8 gPlayerSelectionLock[] = { SELECTION_FREE, SELECTION_FREE, SELECTION_FREE, SELECTION_FREE };
s8 D_8076CC7C[] = { 1, 1, 1, 1 };
s32 gMachineSelectState = MACHINE_SELECT_ACTIVE;
s32 gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;
s32 gLastCourseSelectCourseIndex = 0;
s32 gLastRecordsCourseIndex = 0;
s8 gUnlockableLevel = 0;
s8 D_8076CC94 = 0;
s8 gSettingEverythingUnlocked = false;
s32 gCurrentGhostType = GHOST_PLAYER;
bool D_8076CCA0 = false;

const char* sTrackNames[] = {
    "mute city",
    "silence",
    "sand ocean",
    "devil's forest",
    "big blue",
    "port town",
    "sector Ａ",
    "red canyon",
    "devil's forest 2",
    "mute city 2",
    "big blue 2",
    "white land",
    "fire field",
    "silence 2",
    "sector Ｂ",
    "red canyon 2",
    "white land 2",
    "mute city 3",
    "rainbow road",
    "devil's forest 3",
    "space plant",
    "sand ocean 2",
    "port town 2",
    "big hand",
    "default",
    "default",
    "default",
    "default",
    "default",
    "default",
    "x",
    "",
    "silence 3",
    "sand ocean 3",
    "devil's forest 4",
    "port town 3",
    "devil's forest 5",
    "big blue 3",
    "mute city 4",
    "space plant 2",
    "port town 4",
    "fire field 2",
    "white land 3",
    "big foot",
};

const char* gMachineNames[] = { "blue falcon",   "golden fox",       "wild goose",    "fire stingray",  "white cat",
                                "red gazelle",   "great star",       "iron tiger",    "deep claw",      "twin noritta",
                                "super piranha", "mighty hurricane", "little wyvern", "space angler",   "green panther",
                                "black bull",    "wild boar",        "astro robin",   "king meteor",    "queen meteor",
                                "wonder wasp",   "hyper speeder",    "death anchor",  "crazy bear",     "night thunder",
                                "big fang",      "mighty typhoon",   "mad wolf",      "sonic phantom",  "hell hawk",
                                "super falcon",  "golden fox",       "wild goose",    "super stingray", "super cat",
                                "red gazelle" };

// clang-format off
s32 D_8076CDE4[] = {
    255, 0, 0,
    0, 255, 0,
    255, 255, 100,
    255, 0, 0,
};
// clang-format on

Gfx* func_80709C90(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {

    red &= 0xFF;
    green &= 0xFF;
    blue &= 0xFF;
    alpha &= 0xFF;
    if ((left >= SCREEN_WIDTH) || (top >= SCREEN_HEIGHT)) {
        return gfx;
    }

    if (left < 0) {
        left = 0;
    }
    if (top < 0) {
        top = 0;
    }
    if ((right < 0) || (bottom < 0)) {
        return gfx;
    }

    if (right > SCREEN_WIDTH) {
        right = SCREEN_WIDTH;
    }
    if (bottom > SCREEN_HEIGHT) {
        bottom = SCREEN_HEIGHT;
    }

    gSPDisplayList(gfx++, D_3000088);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gDPFillRectangle(gfx++, left, top, right, bottom);
    gDPPipeSync(gfx++);
    return gfx;
}

void func_80709DEC(u16* arg0, s32 size) {
    u32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (size / (s32) sizeof(u16)); i++, arg0++) {
        red = ((*arg0 & 0xF800) >> 11) * 77;
        green = ((*arg0 & 0x7C0) >> 6) * 150;
        blue = ((*arg0 & 0x3E) >> 1) * 29;
        alpha = *arg0 & 0x1;

        colorBlend = (red + green + blue) >> 8;

        *arg0 = (colorBlend << 1) + (colorBlend << 6) + (colorBlend << 11) + alpha;
    }
}

void func_8070A078(u16* arg0, size_t size, s32 arg2, s32 arg3, s32 arg4) {
    u32 i;
    u32 colorBlend;
    u32 red, green, blue, alpha;

    for (i = 0; i < (size / sizeof(u16)); i++, arg0++) {
        red = ((*arg0 & 0xF800) >> 11) * 77;
        green = ((*arg0 & 0x7C0) >> 6) * 150;
        blue = ((*arg0 & 0x3E) >> 1) * 29;
        alpha = *arg0 & 0x1;

        colorBlend = (red + green + blue) >> 8;

        *arg0 = (((arg2 * colorBlend) >> 8) << 11) + (((arg3 * colorBlend) >> 8) << 6) +
                (((arg4 * colorBlend) >> 8) << 1) + alpha;
    }
}

Gfx* func_8070A3D8(Gfx* gfx) {
    gSPDisplayList(gfx++, D_30001A8);
    return gfx;
}

extern s16 D_8076C7A4;
extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A35C;
extern s32 D_8079A364;

Gfx* func_8070A3F4(Gfx* gfx) {

    gDPPipeSync(gfx++);

    if (D_8076C7A4 == 2) {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A35C]));
    } else {
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
    }
    return gfx;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

Gfx* func_8070A498(Gfx* gfx, u16 red, u16 green, u16 blue) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, 12, 8, 307, 231);
    return gfx;
}

Gfx* func_8070A594(Gfx* gfx, u16 red, u16 green, u16 blue, s32 left, s32 top, s32 right, s32 bottom) {

    if ((red < 0) || (red > 255) || (green < 0) || (green > 255) || (blue < 0) || (blue > 255)) {
        return gfx;
    }

    red >>= 3;
    green >>= 3;
    blue >>= 3;
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetFillColor(gfx++, PACK_5551(red, green, blue, 1) << 16 | PACK_5551(red, green, blue, 1));
    gDPFillRectangle(gfx++, left, top, right, bottom);
    return gfx;
}

extern Gfx D_8076CAF8[];

// New Gfx in N64DD
Gfx* func_8070A6C0(Gfx* gfx) {
    gSPDisplayList(gfx++, D_8076CAF8);
    return gfx;
}

Gfx* func_8070A6DC(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000000);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

Gfx* func_8070A790(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom, s32 red, s32 green, s32 blue, s32 alpha) {
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, alpha);
    gSPDisplayList(gfx++, D_3000028);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* func_8070A844(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gSPDisplayList(gfx++, D_3000270);
    gSPTextureRectangle(gfx++, (left + 1) << 2, (top + 1) << 2, (right - 1) << 2, (bottom - 1) << 2, G_TX_RENDERTILE, 0,
                        (gGameFrameCount % 32) << 5, 1 << 10, 1 << 10);

    return gfx;
}

Gfx* func_8070A8F8(Gfx* gfx, s32 left, s32 top, s32 right, s32 bottom) {
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++,
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                     IM_RD | CVG_DST_FULL | ZMODE_OPA | CVG_X_ALPHA | FORCE_BL |
                         GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPFillRectangle(gfx++, left, top, right, bottom);

    return gfx;
}

Gfx* func_8070A99C(Gfx* gfx, TexturePtr texture, s32 left, s32 top, s32 width, u32 height, s32 format, s32 size,
                   s32 arg8, s32 arg9, s32 argA, s32 argB) {
    s32 i;
    s32 numBlocks;
    s32 blockHeight;
    s32 blockWidth = width;
    s32 pad[1];
    s32 sp48;
    s32 var;
    s32 var_t0;
    s32 spE4;
    s32 spE0;
    s32 var_a0;
    s32 dsdx;
    s32 dtdy;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    s32 sTemp = 1;

    if (blockWidth & 3) {
        return gfx;
    }

    switch (size) {
        case G_IM_SIZ_4b:
            var_t0 = G_IM_SIZ_4b_LOAD_BLOCK;
            spC8 = G_IM_SIZ_4b_INCR;
            spC4 = G_IM_SIZ_4b_SHIFT;
            spC0 = G_IM_SIZ_4b_BYTES;
            var_a0 = 0x1000;
            break;
        case G_IM_SIZ_8b:
            var_t0 = G_IM_SIZ_8b_LOAD_BLOCK;
            spCC = G_IM_SIZ_8b_LINE_BYTES;
            spC8 = G_IM_SIZ_8b_INCR;
            spC4 = G_IM_SIZ_8b_SHIFT;
            spC0 = G_IM_SIZ_8b_BYTES;
            var_a0 = 0x800;
            break;
        case G_IM_SIZ_16b:
            var_t0 = G_IM_SIZ_16b_LOAD_BLOCK;
            spCC = G_IM_SIZ_16b_LINE_BYTES;
            spC8 = G_IM_SIZ_16b_INCR;
            spC4 = G_IM_SIZ_16b_SHIFT;
            spC0 = G_IM_SIZ_16b_BYTES;
            var_a0 = 0x400;
            break;
        case G_IM_SIZ_32b:
            var_t0 = G_IM_SIZ_32b_LOAD_BLOCK;
            spCC = G_IM_SIZ_32b_LINE_BYTES;
            spC8 = G_IM_SIZ_32b_INCR;
            spC4 = G_IM_SIZ_32b_SHIFT;
            spC0 = G_IM_SIZ_32b_BYTES;
            var_a0 = 0x200;
            break;
        default:
            return gfx;
    }

    blockHeight = var_a0 / blockWidth;
    while (height < blockHeight / 2) {
        blockHeight /= 2;
    }

    if ((blockHeight % 4) && (size == G_IM_SIZ_4b)) {
        blockHeight /= 4;
        blockHeight *= 4;
    }
    numBlocks = height / blockHeight;

    if (argA != 0) {
        dsdx = -0x400;
        spE0 = (blockWidth - sTemp) << 5;
    } else {
        dsdx = 0x400;
        spE0 = 0;
    }

    switch (arg8) {
        case 1:
            gSPDisplayList(gfx++, D_3000088);
            break;
        case 2:
            gSPDisplayList(gfx++, D_3000100);
            break;
        case 3:
            gSPDisplayList(gfx++, D_3000138);
            break;
        case 0:
        default:
            gSPDisplayList(gfx++, D_3000050);
            break;
    }

    if (arg9 == 0) {
        gDPSetTextureImage(gfx++, format, var_t0, blockWidth, texture);

        gDPSetTile(gfx++, format, var_t0, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        if (size == G_IM_SIZ_4b) {
            gDPSetTile(gfx++, format, size, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                       G_TX_NOLOD);
        } else {
            gDPSetTile(gfx++, format, size, ((blockWidth * spCC) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                       G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                       G_TX_NOLOD);
        }
    } else if (size == G_IM_SIZ_4b) {
        gDPSetTextureImage(gfx++, format, 1, blockWidth >> 1, texture);

        gDPSetTile(gfx++, format, 1, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        gDPSetTile(gfx++, format, 0, ((blockWidth * size) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTextureImage(gfx++, format, size, blockWidth, texture);

        gDPSetTile(gfx++, format, size, ((blockWidth * size) + 7) >> 3, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

        gDPSetTile(gfx++, format, size, ((blockWidth * size) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
    }

    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                   (blockHeight - 1) << G_TEXTURE_IMAGE_FRAC);

    if (argB != 0) {
        sp48 = height % blockHeight;
        for (i = 0; i < numBlocks; i++) {
            gDPLoadSync(gfx++);
            if (arg9 == 0) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT(blockWidth, spC0));
                }

                gSPScisTextureRectangle(gfx++, left << 2,
                                        (s32) (top + ((numBlocks - i - 1) * blockHeight) + (height % blockHeight)) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + ((numBlocks - i) * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, spE0, (blockHeight - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            } else {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);

                //! @bug s and t are swapped around from expected
                gSPScisTextureRectangle(
                    gfx++, left << 2, (s32) (top + ((numBlocks - i - 1) * blockHeight) + (height % blockHeight)) << 2,
                    (left + blockWidth) << 2,
                    (s32) (top + ((numBlocks - i) * blockHeight) + (height % blockHeight)) << 2, G_TX_RENDERTILE, spE0,
                    (((i + 1) * blockHeight) - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            }
        }

        if (height % blockHeight) {
            gDPLoadSync(gfx++);
            if (arg9 == 0) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT(blockWidth, spC0));
                }

                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + blockWidth) << 2,
                                        (top + (height % blockHeight)) << 2, G_TX_RENDERTILE, spE0,
                                        ((height % blockHeight) - 1) << 5, dsdx, (64 - 1) * (1 << 10));
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, top << 2, (left + blockWidth) << 2,
                                        (top + (height % blockHeight)) << 2, G_TX_RENDERTILE, spE0, (height - 1) << 5,
                                        dsdx, (64 - 1) * (1 << 10));
            }
        }
    } else {
        for (i = 0; i < numBlocks; i++) {
            // FAKE?
            var = i + 1;
            gDPLoadSync(gfx++);
            if (arg9 == 0) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight / 4,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT(blockWidth, spC0));
                }

                gSPScisTextureRectangle(gfx++, left << 2, (top + (i * blockHeight)) << 2, (left + blockWidth) << 2,
                                        (top + (var * blockHeight)) << 2, G_TX_RENDERTILE, spE0, 0, dsdx, 1 << 10);
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (i * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((i + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, (top + (i * blockHeight)) << 2, (left + blockWidth) << 2,
                                        (top + (var * blockHeight)) << 2, G_TX_RENDERTILE, spE0, (i * blockHeight) << 5,
                                        dsdx, 1 << 10);
            }
        }

        if (height % blockHeight) {
            gDPLoadSync(gfx++);
            if (arg9 == 0) {
                if (size == G_IM_SIZ_4b) {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight / 4,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT_4b(blockWidth));
                } else {
                    gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                                 ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT(blockWidth, spC0));
                }

                gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + ((numBlocks * blockHeight))) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + (numBlocks * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, spE0, 0, dsdx, 1 << 10);
            } else {
                //! @bug, condition blocks switched around from what size would expect
                if (size == G_IM_SIZ_4b) {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << (G_TEXTURE_IMAGE_FRAC - 1),
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << (G_TEXTURE_IMAGE_FRAC - 1));
                } else {
                    gDPLoadTile(gfx++, G_TX_LOADTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                                (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                                (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                }

                gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, (numBlocks * blockHeight) << G_TEXTURE_IMAGE_FRAC,
                               (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                               (((numBlocks + 1) * blockHeight) - 1) << G_TEXTURE_IMAGE_FRAC);
                gSPScisTextureRectangle(gfx++, left << 2, (s32) (top + (numBlocks * blockHeight)) << 2,
                                        (left + blockWidth) << 2,
                                        (s32) (top + (numBlocks * blockHeight) + (height % blockHeight)) << 2,
                                        G_TX_RENDERTILE, spE0, (numBlocks * blockHeight) << 5, dsdx, 1 << 10);
            }
        }
    }

    return gfx;
}

Gfx* func_8070C600(Gfx* gfx, TexturePtr texture, s32 left, s32 top, s32 width, u32 height, f32 arg6, f32 arg7,
                   s32 format, s32 size, s32 argA, s32 argB, s32 argC) {
    s32 i;
    s32 numBlocks;
    s32 blockHeight;
    s32 blockWidth = width;
    s32 pad[5];
    s32 spE0;
    s32 var_a0;
    s32 dsdx;
    s32 dtdy;
    s32 var_t0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    f32 temp;
    s32 sTemp = 1;

    if (blockWidth & 3) {
        return gfx;
    }
    if ((arg6 == 0.0) || (arg7 == 0.0)) {
        return gfx;
    }

    switch (size) {
        case G_IM_SIZ_4b:
            var_t0 = G_IM_SIZ_4b_LOAD_BLOCK;
            spC8 = G_IM_SIZ_4b_INCR;
            spC4 = G_IM_SIZ_4b_SHIFT;
            spC0 = G_IM_SIZ_4b_BYTES;
            var_a0 = 0x1000;
            break;
        case G_IM_SIZ_8b:
            var_t0 = G_IM_SIZ_8b_LOAD_BLOCK;
            spCC = G_IM_SIZ_8b_LINE_BYTES;
            spC8 = G_IM_SIZ_8b_INCR;
            spC4 = G_IM_SIZ_8b_SHIFT;
            spC0 = G_IM_SIZ_8b_BYTES;
            var_a0 = 0x800;
            break;
        case G_IM_SIZ_16b:
            var_t0 = G_IM_SIZ_16b_LOAD_BLOCK;
            spCC = G_IM_SIZ_16b_LINE_BYTES;
            spC8 = G_IM_SIZ_16b_INCR;
            spC4 = G_IM_SIZ_16b_SHIFT;
            spC0 = G_IM_SIZ_16b_BYTES;
            var_a0 = 0x400;
            break;
        case G_IM_SIZ_32b:
            var_t0 = G_IM_SIZ_32b_LOAD_BLOCK;
            spCC = G_IM_SIZ_32b_LINE_BYTES;
            spC8 = G_IM_SIZ_32b_INCR;
            spC4 = G_IM_SIZ_32b_SHIFT;
            spC0 = G_IM_SIZ_32b_BYTES;
            var_a0 = 0x200;
            break;
        default:
            return gfx;
    }

    if (argB == 0) {
        blockHeight = var_a0 / blockWidth;
        while (height < blockHeight / 2) {
            blockHeight /= 2;
        }
    } else {
        blockHeight = 1;
    }

    numBlocks = height / blockHeight;

    if (argC != 0) {
        dsdx = -0x400;
        dtdy = 0x400;
        spE0 = (blockWidth - sTemp) << 5;
    } else {
        dsdx = 0x400;
        dtdy = 0x400;
        spE0 = 0;
    }

    switch (argA) {
        case 1:
            gSPDisplayList(gfx++, D_3000088);
            break;
        case 2:
            gSPDisplayList(gfx++, D_3000100);
            break;
        case 3:
            gSPDisplayList(gfx++, D_3000138);
            break;
        case 0:
        default:
            gSPDisplayList(gfx++, D_3000050);
            break;
    }

    dsdx /= arg6;
    dtdy /= arg7;

    gDPSetTextureImage(gfx++, format, var_t0, blockWidth, texture);

    gDPSetTile(gfx++, format, var_t0, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

    if (size == G_IM_SIZ_4b) {
        gDPSetTile(gfx++, format, size, ((blockWidth >> 1) + 7) >> 3, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                   G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTile(gfx++, format, size, ((blockWidth * spCC) + 7) >> 3, 0, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
    }

    gDPSetTileSize(gfx++, G_TX_RENDERTILE, 0, 0, (blockWidth - 1) << G_TEXTURE_IMAGE_FRAC,
                   (blockHeight - 1) << G_TEXTURE_IMAGE_FRAC);

    temp = blockHeight * arg7;

    for (i = 0; i < numBlocks; i++) {
        gDPLoadSync(gfx++);
        if (size == G_IM_SIZ_4b) {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight, ((blockWidth * blockHeight + spC8) >> spC4) - 1,
                         CALC_DXT_4b(blockWidth));
        } else {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, i * blockHeight, ((blockWidth * blockHeight + spC8) >> spC4) - 1,
                         CALC_DXT(blockWidth, spC0));
        }

        gSPScisTextureRectangle(
            gfx++, left << 2, (top + (s32) (i * temp)) << 2, (left + (s32) (blockWidth * arg6)) << 2,
            (top + (s32) ((i + 1) * (blockHeight * arg7))) << 2, G_TX_RENDERTILE, spE0, 0, dsdx, dtdy);
    }

    if (height % blockHeight) {
        gDPLoadSync(gfx++);
        if (size == G_IM_SIZ_4b) {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                         ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT_4b(blockWidth));
        } else {
            gDPLoadBlock(gfx++, G_TX_LOADTILE, 0, numBlocks * blockHeight,
                         ((blockWidth * blockHeight + spC8) >> spC4) - 1, CALC_DXT(blockWidth, spC0));
        }

        gSPScisTextureRectangle(gfx++, left << 2, (top + (s32) (numBlocks * temp)) << 2,
                                (left + (s32) (blockWidth * arg6)) << 2, (top + (s32) (height * arg7)) << 2,
                                G_TX_RENDERTILE, spE0, 0, dsdx, dtdy);
    }

    return gfx;
}

extern u8 gEditCupTrackNames[][9];

void func_8070D220(void) {
    s32 i;

    for (i = 24; i < 30; i++) {
        if (gEditCupTrackNames[i - 24][0] == '\0') {
            gTrackNames[i] = sTrackNames[i];
        } else {
            gTrackNames[i] = gEditCupTrackNames[i - 24];
        }
    }
}

void func_8070D358(void) {
    s32 i;

    for (i = 0; i < 24; i++) {
        gTrackNames[i] = sTrackNames[i];
    }

    func_8070D220();

    for (i = 30; i < 42; i++) {
        gTrackNames[i] = sTrackNames[i + 2];
    }

    for (i = 42; i < 48; i++) {
        gTrackNames[i] = sTrackNames[31];
    }

    for (i = 48; i < 54; i++) {
        gTrackNames[i] = sTrackNames[30];
    }

    gTrackNames[54] = sTrackNames[31];
}

void Controller_SetGlobalInputs(Controller* controller) {
    gInputButtonPressed = controller->buttonPressed | STICK_TO_BUTTON(controller->stickPressed);
    if (controller->unk_82 != 0) {
        gStickPressed = controller->buttonCurrent | STICK_TO_BUTTON(controller->stickCurrent);
    } else {
        gStickPressed = 0;
    }
    gInputPressed = gInputButtonPressed | gStickPressed;
}

extern u32 gGameFrameCount;

Gfx* func_8070D4A8(Gfx* gfx, s32 arg1) {
    s32 temp_a3;
    s32 temp_a2;
    s32 red;
    s32 green;
    s32 blue;
    s32 temp_hi;
    s32* temp_a0;

    temp_hi = ((gGameFrameCount % 300) * 8) % 300;
    temp_a2 = temp_hi % 100;
    temp_a3 = 100 - temp_a2;
    temp_a0 = &D_8076CDE4[((temp_hi / 100) % 3) * 3];

    switch (arg1) {
        case 0:
            red = ((temp_a0[0] * temp_a3) + (temp_a0[3] * temp_a2)) / 100;
            green = ((temp_a0[1] * temp_a3) + (temp_a0[4] * temp_a2)) / 100;
            blue = ((temp_a0[2] * temp_a3) + (temp_a0[5] * temp_a2)) / 100;
            break;
        case 1:
        default:
            red = ((temp_a0[0] * temp_a2) + (temp_a0[3] * temp_a3)) / 100;
            green = ((temp_a0[1] * temp_a2) + (temp_a0[4] * temp_a3)) / 100;
            blue = ((temp_a0[2] * temp_a2) + (temp_a0[5] * temp_a3)) / 100;
            break;
    }

    gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
    return gfx;
}

void func_8070D858(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gCupNumDifficultiesCleared[i] = 0;
    }
}

extern s32 gCupType;
extern s32 gDifficulty;
extern s16 D_8079FC7C;

void func_8070D870(void) {
    s32 i;
    bool var_v1;
    bool var_a1;
    s32 var_a0;
    s32 cupType;

    switch (gCupType) {
        case EDIT_CUP:
            return;
        case DD_1_CUP:
        case DD_2_CUP:
            var_a1 = true;
            break;
        default:
            var_a1 = false;
            break;
    }

    var_v1 = false;
    if (var_a1) {
        for (i = 0; i < 2; i++) {
            if (D_8079FB28[i] < 3) {
                var_v1 = true;
                break;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (gCupNumDifficultiesCleared[i] < 3) {
                var_v1 = true;
                break;
            }
        }
    }
    cupType = gCupType;
    var_a0 = gDifficulty + 1;
    if (var_a0 > MASTER + 1) {
        var_a0 = MASTER + 1;
    }
    if (var_a1) {
        if (D_8079FB28[cupType - DD_1_CUP] < var_a0) {
            D_8079FB28[cupType - DD_1_CUP] = var_a0;
        }
        if (var_v1) {
            for (i = 0; i < 2; i++) {
                if (D_8079FB28[i] < 3) {
                    var_v1 = false;
                }
            }

            if (var_v1) {
                D_8079FC7C = 1;
            }
        }
    } else {
        if (gCupNumDifficultiesCleared[cupType] < var_a0) {
            gCupNumDifficultiesCleared[cupType] = var_a0;
        }
        if (var_v1) {
            for (i = 0; i < 4; i++) {
                if (gCupNumDifficultiesCleared[i] < 3) {
                    var_v1 = false;
                }
            }

            if (var_v1) {
                D_8079FC7C = 1;
            }
        }
        Save_SaveSettingsProfiles();
    }
}

s32 func_8070DA54(void) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        sum += gCupNumDifficultiesCleared[i];
    }
    return sum;
}

void func_8070DA84(void) {
    Audio_ChangeSoundMode(0);
}

void func_8070DAA4(s32 bgm) {

    if (bgm == BGM_DEATHRACE2) {
        bgm = BGM_DEATHRACE;
    }
    Audio_DDBgmStart(bgm);
}

void func_8070DAD4(s32 bgm) {
    Audio_RomBgmStart(bgm);
    D_8076CCA0 = true;
}

void func_8070DAFC(void) {
    Audio_BetaBgmStop();
    if (D_8076CCA0) {
        Audio_RomBgmStop();
    } else {
        Audio_DDBgmStop();
    }
    D_8076CCA0 = false;
}

void func_8070DB48(void) {
    Audio_BetaBgmStop();
    if (D_8076CCA0) {
        Audio_RomBgmStop2();
    } else {
        Audio_DDBgmStop();
    }
    D_8076CCA0 = false;
}

void func_8070DB94(void) {
    Audio_BetaBgmStop2();
    if (D_8076CCA0) {
        Audio_RomBgmStop();
    } else {
        Audio_DDBgmStop();
    }
    D_8076CCA0 = false;
}

const s8 kMachineSelectCharacterList[] = { CAPTAIN_FALCON,
                                           DR_STEWART,
                                           PICO,
                                           SAMURAI_GOROH,
                                           JODY_SUMMER,
                                           MIGHTY_GAZELLE,
                                           BABA,
                                           OCTOMAN,
                                           DR_CLASH,
                                           MR_EAD,
                                           BIO_REX,
                                           BILLY,
                                           SILVER_NEELSEN,
                                           GOMAR_AND_SHIOH,
                                           JOHN_TANAKA,
                                           MRS_ARROW,
                                           BLOOD_FALCON,
                                           JACK_LEVIN,
                                           JAMES_MCCLOUD,
                                           ZODA,
                                           MICHAEL_CHAIN,
                                           SUPER_ARROW,
                                           KATE_ALEN,
                                           ROGER_BUSTER,
                                           LEON,
                                           DRAQ,
                                           BEASTMAN,
                                           ANTONIO_GUSTER,
                                           BLACK_SHADOW,
                                           THE_SKULL,
                                           30 };

s32 Character_GetCharacterFromSlot(s32 characterSlot) {
    return kMachineSelectCharacterList[characterSlot];
}

s32 Character_GetSlotFromCharacter(s32 character) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if (character == kMachineSelectCharacterList[i]) {
            return i;
        }
    }

    return 0;
}

void func_8070DC94(void) {
    GhostInfo sp40;
    s32 pad;
    bool sp38;
    s32 i;

    sp38 = false;

    for (i = 0; i < 24; i++) {
        if (Save_LoadStaffGhostRecord(&sp40, i) != 0) {
            sp38 = true;
            break;
        } else {
            if (gCourseInfos[i].timeRecord[0] >= sp40.raceTime) {
                sp38 = true;
                break;
            }
        }
    }
    if (!sp38 || (gUnlockableLevel >= 3)) {
        D_8076CC94 = 2;
    } else if (gUnlockableLevel >= 2) {
        D_8076CC94 = 1;
    } else {
        D_8076CC94 = 0;
    }
}

void func_8070DD88(void) {
    bool var_a0;
    s32 i;

    if (func_8070DA54() >= 16) {
        gUnlockableLevel = 3;
    } else {
        var_a0 = false;
        for (i = JACK_CUP; i <= JOKER_CUP; i++) {
            if (gCupNumDifficultiesCleared[i] < 3) {
                var_a0 = true;
                break;
            }
        }

        if (!var_a0) {
            gUnlockableLevel = 2;
        } else {
            var_a0 = false;
            for (i = JACK_CUP; i <= KING_CUP; i++) {
                if (gCupNumDifficultiesCleared[i] < 2) {
                    var_a0 = true;
                    break;
                }
            }

            if (!var_a0) {
                gUnlockableLevel = 1;
            } else {
                gUnlockableLevel = 0;
            }
        }
    }
    func_8070DC94();
}

extern s16 D_807A15F0[];
extern s16 D_807A15F8[];

void func_8070DE6C(void) {
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        D_807A15F0[i] = i;
        D_807A15F8[i] = 0;
    }

    for (i = 0; i < 8; i++) {
        gModeSubOption[i] = 0;
    }

    gLastCourseSelectCourseIndex = 0;
    gLastRecordsCourseIndex = 0;
    gCurrentGhostType = GHOST_PLAYER;
}
