#include "global.h"
#include "ovl_i6.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_assets.h"

SaveContext* sSaveContextPtr;
Vtx D_i6_80085B18[2][0x258]; // Some kind of vtx buffer space?
Vtx* D_i6_8008A618;
s16 D_i6_8008A620[176];
s32 sOptionsDataClearMenu;
s16 sOptionsDataAlreadyCleared;
s32 sOptionsSelectionState[7];
unk_800E51B8* D_i6_8008A7A4;
s16 D_i6_8008A7A8;
s16 D_i6_8008A7AA;
TexturePtr D_i6_8008A7AC;
s16 D_i6_8008A7B0;

/*
    OPTIONS MENU
 */

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsComSelection[] = {
    { aMenuWithTex, 32, 16 },
    { aMenuWithoutTex, 32, 16 },
};

// 'WITH', 'W/O'
OptionsTextureInfo gOptionsVsSlotSelection[] = {
    { aMenuWithTex, 32, 16 },
    { aMenuWithoutTex, 32, 16 },
};

// 'W/O', '+1', '+2'
OptionsTextureInfo gOptionsVsHandicapSelection[] = {
    { aMenuWithoutTex, 32, 16 },
    { aMenuPlusOneTex, 32, 16 },
    { aMenuPlusTwoTex, 32, 16 },
};

// 'Stereo', 'Mono'
OptionsTextureInfo gOptionsSoundModeSelection[] = {
    { aMenuStereoTex, 64, 16 },
    { aMenuMonoTex, 64, 16 },
};

// 'No', 'Yes'
OptionsTextureInfo gOptionsAllDataClearSelection[] = {
    { aMenuNoTex, 32, 16 },
    { aMenuYesTex, 32, 16 },
};

s32 gOptionsCurrentRow = 0;

OptionsInfo gOptionsInfo[] = {
    // 'VS COM (2P,3P)'
    { OPTIONS_VS_COM,
      OPTIONS_SHOWN,
      2,
      0,
      0,
      gOptionsVsComSelection,
      { aOptionsVsCom2P3PTex, TEX_WIDTH(aOptionsVsCom2P3PTex), TEX_HEIGHT(aOptionsVsCom2P3PTex) } },
    // 'VS Slot'
    { OPTIONS_VS_SLOT,
      OPTIONS_SHOWN,
      2,
      0,
      0,
      gOptionsVsSlotSelection,
      { aOptionsVsSlotTex, TEX_WIDTH(aOptionsVsSlotTex), TEX_HEIGHT(aOptionsVsSlotTex) } },
    // 'VS Handicap'
    { OPTIONS_VS_HANDICAP,
      OPTIONS_SHOWN,
      3,
      0,
      0,
      gOptionsVsHandicapSelection,
      { aOptionsVsHandicapTex, TEX_WIDTH(aOptionsVsHandicapTex), TEX_HEIGHT(aOptionsVsHandicapTex) } },
    // 'Sound Mode'
    { OPTIONS_SOUND_MODE,
      OPTIONS_SHOWN,
      2,
      0,
      4,
      gOptionsSoundModeSelection,
      { aOptionsSoundModeTex, TEX_WIDTH(aOptionsSoundModeTex), TEX_HEIGHT(aOptionsSoundModeTex) } },
    // 'All data clear'
    { OPTIONS_DATA_CLEAR,
      OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN,
      0,
      0,
      0,
      NULL,
      { aOptionsAllDataClearTex, TEX_WIDTH(aOptionsAllDataClearTex), TEX_HEIGHT(aOptionsAllDataClearTex) } },
    // 'Copying ghost'
    { OPTIONS_GHOST_COPY,
      OPTIONS_REQUIRE_SELECTING,
      0,
      0,
      0,
      NULL,
      { aOptionsCopyingGhostTex, TEX_WIDTH(aOptionsCopyingGhostTex), TEX_HEIGHT(aOptionsCopyingGhostTex) } },
    // 'EXIT'
    { OPTIONS_EXIT,
      OPTIONS_REQUIRE_SELECTING | OPTIONS_SHOWN,
      0,
      0,
      0,
      NULL,
      { aOptionsExitTex, TEX_WIDTH(aOptionsExitTex), TEX_HEIGHT(aOptionsExitTex) } },
};

UNUSED char D_i6_80084FEC[] = "Feel Mie";

extern s16 D_8076C7A8;
extern s8 D_8076CC94;

void OptionsMenu_Init(void) {
    s32 i;
    OptionsInfo* option;

    D_8076C7A8 = 3;
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    func_i2_800AE7C4(aMenuTextTLUT, TEX_SIZE(aMenuTextTLUT, sizeof(u16)), 0, 0, false);
    func_i2_800AE7C4(aOptionsFalconHelmetTex, TEX_SIZE(aOptionsFalconHelmetTex, sizeof(u16)), 0, 1, false);
    func_i2_800AE7C4(aOptionsTex, TEX_SIZE(aOptionsTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aOptionsEraseAllSavedDataTex, TEX_SIZE(aOptionsEraseAllSavedDataTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuWithoutTex, TEX_SIZE(aMenuWithoutTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuWithTex, TEX_SIZE(aMenuWithTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuPlusOneTex, TEX_SIZE(aMenuPlusOneTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuPlusTwoTex, TEX_SIZE(aMenuPlusTwoTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuStereoTex, TEX_SIZE(aMenuStereoTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuMonoTex, TEX_SIZE(aMenuMonoTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, false);

    for (i = 0, option = gOptionsInfo; i < OPTIONS_MAX; i++, option++) {
        func_i2_800AE7C4(option->optionTextureInfo.textureOffset,
                         option->optionTextureInfo.width * option->optionTextureInfo.height * sizeof(u8), 0, 1, 0);
    }

    func_i2_800AE7C4(aTitleBackgroundMainTex, TEX_SIZE(aTitleBackgroundMainTex, sizeof(u16)), 0, 1, false);
    func_8070A078(func_i2_800AEA90(aTitleBackgroundMainTex), TEX_SIZE(aTitleBackgroundMainTex, sizeof(u16)), 0xC3, 0x5F,
                  0x5F);

    if (D_8076CC94 == 1) {
        D_i6_8008A7AC =
            func_i2_800AE7C4(aTitleBackgroundComicTex, TEX_SIZE(aTitleBackgroundComicTex, sizeof(u16)), 0, 1, false);
        func_8070A078(D_i6_8008A7AC, TEX_SIZE(aTitleBackgroundComicTex, sizeof(u16)), 0xC3, 0x5F, 0x5F);
    } else if (D_8076CC94 == 2) {
        D_i6_8008A7AC =
            func_i2_800AE7C4(aTitleBackgroundFalconTex, TEX_SIZE(aTitleBackgroundFalconTex, sizeof(u16)), 0, 1, false);
        func_8070A078(D_i6_8008A7AC, TEX_SIZE(aTitleBackgroundFalconTex, sizeof(u16)), 0xC3, 0x5F, 0x5F);
    }
    if (D_8076CC94 != 0) {
        D_i6_8008A7A8 = 1;
        // clang-format off
        for (i = 0; i < ARRAY_COUNT(D_i6_8008A620); i++) { \
            D_i6_8008A620[i] = 255;
        }
        // clang-format on
    } else {
        D_i6_8008A7A8 = 0;
    }
    sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
    sOptionsDataAlreadyCleared = false;
    D_i6_8008A7B0 = 0;
    gOptionsCurrentRow = 0;
    func_i6_80082A24();
    func_80711170(&D_i6_8008A7A4);
    func_80711178();
    sSaveContextPtr = &gSaveContext;
}

extern s16 gSettingVsHandicap;
extern s16 gSettingVsCom;
extern s32 gSettingVsSlot;
extern s16 gSettingSoundMode;

void func_i6_80082A24(void) {
    s32 state;
    s32 i;
    OptionsInfo* option;

    for (i = 0, option = gOptionsInfo; i < 7; i++, option++) {
        switch (option->row) {
            case OPTIONS_VS_COM:
                if (gSettingVsCom == 0) {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
            case OPTIONS_VS_SLOT:
                if (gSettingVsSlot == 0) {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
            case OPTIONS_VS_HANDICAP:
                if (gSettingVsHandicap == 0) {
                    state = 0;
                } else if (gSettingVsHandicap == 1) {
                    state = 1;
                } else {
                    state = 2;
                }
                break;
            case OPTIONS_SOUND_MODE:
                if (gSettingSoundMode == 0) {
                    state = 0;
                } else {
                    state = 1;
                }
                break;
            default:
                state = 0;
                break;
        }

        sOptionsSelectionState[i] = state;
    }
}

extern s32 D_800BEE14;
extern s16 D_8076C814;

s32 OptionsMenu_Update(void) {
    Controller_SetGlobalInputs(&gSharedController);
    func_80711414();
    func_i6_80083A20();
    if (!sOptionsDataAlreadyCleared) {
        switch (sOptionsDataClearMenu) {
            case OPTIONS_DATA_CLEAR_MENU_CLOSED:
                if (D_800BEE14 == 0 && func_i6_80082DB4()) {
                    sOptionsDataAlreadyCleared = true;
                    D_8076C814 = 14;
                    func_80741BD4(0xF);
                }
                break;
            case OPTIONS_DATA_CLEAR_MENU_OPEN:
                func_i6_800831E8();
                break;
        }
    }
    return GAMEMODE_FLX_OPTIONS_MENU;
}

extern s32 gSettingVsSlot;
extern s16 gSettingSoundMode;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

bool func_i6_80082DB4(void) {
    s32 lastRow;
    s32 lastSelectionState;
    bool updateSettings;
    OptionsInfo* option;

    if (func_80711AC0(D_i6_8008A7A4, 0)) {
        return false;
    }
    lastRow = gOptionsCurrentRow;
    if (gInputPressed & BTN_UP) {
        if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
            gOptionsCurrentRow = OPTIONS_EXIT;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (--gOptionsCurrentRow < OPTIONS_VS_COM) {
                gOptionsCurrentRow = OPTIONS_EXIT;
            }
        }
    }
    if (gInputPressed & BTN_DOWN) {
        if (++gOptionsCurrentRow > OPTIONS_EXIT) {
            gOptionsCurrentRow = OPTIONS_VS_COM;
        }
        while (!(gOptionsInfo[gOptionsCurrentRow].flags & OPTIONS_SHOWN)) {
            if (++gOptionsCurrentRow > OPTIONS_EXIT) {
                gOptionsCurrentRow = OPTIONS_VS_COM;
            }
        }
    }
    if (lastRow != gOptionsCurrentRow) {
        func_8074122C(0x1E);
        return false;
    }
    option = &gOptionsInfo[gOptionsCurrentRow];
    updateSettings = false;
    if (!(option->flags & OPTIONS_REQUIRE_SELECTING)) {
        lastSelectionState = sOptionsSelectionState[gOptionsCurrentRow];
        if (gInputButtonPressed & BTN_LEFT) {
            sOptionsSelectionState[gOptionsCurrentRow]--;
            if (sOptionsSelectionState[gOptionsCurrentRow] < 0) {
                sOptionsSelectionState[gOptionsCurrentRow] = option->totalSelectionStates - 1;
            }
        }
        if (gInputButtonPressed & BTN_RIGHT) {
            sOptionsSelectionState[gOptionsCurrentRow]++;
            if (sOptionsSelectionState[gOptionsCurrentRow] > option->totalSelectionStates - 1) {
                sOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (lastSelectionState != sOptionsSelectionState[gOptionsCurrentRow]) {
            updateSettings = true;
            func_8074122C(0x21);
        }
    }
    if (gInputButtonPressed & BTN_B) {
        func_8074122C(0x10);
        return true;
    }

    switch (option->row) {
        case OPTIONS_VS_COM:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsCom = 0;
                } else {
                    gSettingVsCom = 1;
                }
            }
            break;
        case OPTIONS_VS_SLOT:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsSlot = 0;
                } else {
                    gSettingVsSlot = 1;
                }
            }
            break;
        case OPTIONS_VS_HANDICAP:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    gSettingVsHandicap = 0;
                } else if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                    gSettingVsHandicap = 1;
                } else {
                    gSettingVsHandicap = 2;
                }
            }
            break;
        case OPTIONS_SOUND_MODE:
            if (updateSettings) {
                if (sOptionsSelectionState[gOptionsCurrentRow] == 0) {
                    gSettingSoundMode = 0;
                    Audio_SetSoundMode(SOUNDMODE_SURROUND); // Option says stereo, but sets surround anyway?
                } else {
                    gSettingSoundMode = 1;
                    Audio_SetSoundMode(SOUNDMODE_MONO);
                }
            }
            break;
        case OPTIONS_DATA_CLEAR:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                D_i6_8008A7A4 =
                    func_807112A0(0, 0x5A, 0x8C, 0x94, 0x50, 10, GPACK_RGBA5551(255, 0, 0, 1), func_i6_800837F4);
                if (D_i6_8008A7A4 != NULL) {
                    sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_OPEN;
                    sOptionsSelectionState[gOptionsCurrentRow] = 0;
                    func_8074122C(0x21);
                }
            }
            break;
        case OPTIONS_EXIT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_8074122C(0x10);
                return true;
            }
            break;
        default:
            break;
    }

    if (updateSettings) {
        Save_SaveSettingsProfiles();
    }
    return false;
}

extern s32 D_807A1610[];
extern s32 D_807A1620[];

void func_i6_800831E8(void) {
    s32 lastSelectionState;
    s32 pad;
    s32 i;
    bool updateSettings;

    if (func_80711AC0(D_i6_8008A7A4, 1) != 0) {
        lastSelectionState = sOptionsSelectionState[gOptionsCurrentRow];
        if (gInputButtonPressed & BTN_LEFT) {
            if (--sOptionsSelectionState[gOptionsCurrentRow] < 0) {
                sOptionsSelectionState[gOptionsCurrentRow] = 1;
            }
        }
        if (gInputButtonPressed & BTN_RIGHT) {
            if (++sOptionsSelectionState[gOptionsCurrentRow] > 1) {
                sOptionsSelectionState[gOptionsCurrentRow] = 0;
            }
        }
        if (lastSelectionState != sOptionsSelectionState[gOptionsCurrentRow]) {
            func_8074122C(0x1E);
        }
        updateSettings = false;
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            updateSettings = true;
            if (sOptionsSelectionState[gOptionsCurrentRow] == 1) {
                Save_Init(sSaveContextPtr, 1);
                func_i6_80083390();
                func_i6_80082A24();
                for (i = 0; i < 4; i++) {
                    D_807A1610[i] = D_807A1620[i] = 0;
                }
                func_8070DE6C();
                func_8074122C(5);
                func_xk1_8002FC70();
            } else {
                func_8074122C(0x10);
            }
        } else if (gInputButtonPressed & BTN_B) {
            updateSettings = true;
            func_8074122C(0x10);
        }
        if (updateSettings) {
            sOptionsDataClearMenu = OPTIONS_DATA_CLEAR_MENU_CLOSED;
            func_807113DC(D_i6_8008A7A4);
        }
    }
}

void func_i6_80083390(void) {
    s32 i;

    for (i = 0; i < 42; i++) {
        func_i2_800AAB0C(i);
    };
    func_8076805C();
}

Gfx* OptionsMenu_Draw(Gfx* gfx) {
    s32 temp_s4;
    s32 var_s5;
    s32 i;
    s32 var_s7;
    OptionsInfo* option;
    OptionsTextureInfo* selectionStateTextureInfo;
    OptionsTextureInfo* optionTextureInfo;

    gfx = Object_UpdateAndDrawAll(gfx);
    if (D_i6_8008A7A8 != 1) {
        gfx = func_8070A99C(gfx, func_i2_800AEA90(aTitleBackgroundMainTex), 8, 0, 304, 240, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                            0, 0, 0, 0);
    }
    if (D_i6_8008A7A8 != 0) {
        gfx = func_i6_80083F54(gfx);
    }
    gfx = func_8070A99C(gfx, func_i2_800AEA90(aOptionsFalconHelmetTex), 50, 4, 64, 64, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0,
                        0, 1, 0);
    gfx = func_8070A99C(gfx, func_i2_800AEA90(aOptionsFalconHelmetTex), 206, 4, 64, 64, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0,
                        0, 0, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);
    gfx = func_8070DEE0(gfx, func_i2_800AEA90(aOptionsTex), func_i2_800AEA90(aMenuTextTLUT), G_IM_FMT_CI, 1, 112, 22,
                        96, 24, 3);

    var_s5 = 60;

    if (D_i6_8008A7B0 != 0) {
        var_s7 = 0x17;
    } else {
        var_s7 = 0x1B;
    }

    for (i = 0, option = gOptionsInfo; i < 7; i++, option++) {
        if (!(option->flags & OPTIONS_SHOWN)) {
            continue;
        }

        gDPPipeSync(gfx++);
        if (gOptionsCurrentRow != i) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        optionTextureInfo = &option->optionTextureInfo;
        gfx = func_8070DEE0(gfx, func_i2_800AEA90(optionTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                            option->unk_0C + 0x1E, var_s5, optionTextureInfo->width, optionTextureInfo->height, 0);

        if (!(option->flags & OPTIONS_REQUIRE_SELECTING)) {
            gfx = func_8070DEE0(gfx, func_i2_800AEA90(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, 0xBE, var_s5, 0x10,
                                0x10, 0);
            gfx = func_8070DEE0(gfx, func_i2_800AEA90(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, 0x109, var_s5, 0x10,
                                0x10, 0);
            selectionStateTextureInfo = &option->selectionStateTextureInfo[sOptionsSelectionState[i]];
            temp_s4 = ((60 - selectionStateTextureInfo->width) / 2) + option->unk_10;
            gfx = func_8070DEE0(gfx, func_i2_800AEA90(selectionStateTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                                temp_s4 + 0xD0, var_s5, selectionStateTextureInfo->width,
                                selectionStateTextureInfo->height, 0);
        }
        var_s5 += var_s7;
    }

    return func_80711698(gfx);
}

Gfx* func_i6_800837F4(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 sp54;
    OptionsTextureInfo* dataClearTextureInfo;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    gfx = func_8070DEE0(gfx, func_i2_800AEA90(aOptionsEraseAllSavedDataTex), func_i2_800AEA90(aMenuTextTLUT),
                        G_IM_FMT_CI, 1, arg1 + 0xC, arg2 + 0xA, 128, 32, 3);

    gDPPipeSync(gfx++);
    gfx = func_8070D4A8(gfx, 0);
    gfx = func_8070DEE0(gfx, func_i2_800AEA90(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 0x18, arg2 + 0x32, 16,
                        16, 0);
    gfx = func_8070DEE0(gfx, func_i2_800AEA90(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 0x63, arg2 + 0x32, 16,
                        16, 0);
    dataClearTextureInfo = &gOptionsAllDataClearSelection[sOptionsSelectionState[gOptionsCurrentRow]];
    sp54 = (60 - dataClearTextureInfo->width) / 2;
    return func_8070DEE0(gfx, func_i2_800AEA90(dataClearTextureInfo->textureOffset), NULL, G_IM_FMT_CI, 1,
                         arg1 + sp54 + 0x2A, arg2 + 0x32, dataClearTextureInfo->width, dataClearTextureInfo->height, 0);
}

extern s32 D_8079A35C;
extern GfxPool* gGfxPool;

#ifdef NON_EQUIVALENT
void func_i6_80083A20(void) {
    s32 i;
    s32 j;
    MtxF mtxF;
    f32 sp80;
    Vtx* vtx;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs2_2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_ft0;
    f32 temp_ft5;
    f32 temp_ft5_2;
    f32* var_t1;
    f32* var_t2;
    f32* var_t3;
    f32* var_t4;
    s16* temp_t8;
    s16* temp_v0;
    s16* temp_v0_2;
    s16* var_ra;
    s16* var_s5;
    s32 temp_a3;
    s32 temp_ft2;
    s32 temp_lo;
    s32 temp_t0;
    s32 var_a0;
    s32 var_a3;
    s32 var_s2;
    s32 var_s4;
    s32 var_v1;
    void* temp_v0_3;
    s32 temp;

    switch (D_i6_8008A7A8) {
        case 0:
            break;
        case 1:
            if (D_8076CC94 == 0) {
                D_i6_8008A7A8 = 2;
                D_i6_8008A7AA = 0;
            }
            break;
        case 2:
            temp_a3 = (11 - ((D_i6_8008A7AA * 11) / 120));
            temp = (16 - ((D_i6_8008A7AA * 16) / 120));
            for (i = 0; i < 16; i++) {

                if (i < temp) {
                    continue;
                }
                // unrolls
                for (j = 0; j < 11; j++) {
                    if (j < temp_a3) {
                        continue;
                    }
                    D_i6_8008A620[i * 11 + j] -= 5;
                    if (D_i6_8008A620[i * 11 + j] < 0) {
                        D_i6_8008A620[i * 11 + j] = 0;
                    }
                }
            }
            D_i6_8008A7AA++;
            break;
    }
    if (D_i6_8008A7A8 == 0) {
        return;
    }

    D_i6_8008A618 = D_i6_80085B18[D_8079A35C];
    func_806F9628(gGfxPool->unk_35248, NULL, 1.0f, 0.0f, 319.0f, 239.0f, 0.0f, -100.0f, 100.0f);
    vtx = D_i6_8008A618;
    var_s5 = D_i6_8008A620;

    for (var_s4 = 0; var_s4 < 240; var_s4 += 16) {

        var_ra = var_s5;

        for (var_s2 = 0; var_s2 < 320; var_s2 += 32) {
            // temp_fs2 = var_s4 - 0.5f;
            // temp_fs1 = var_s4 - 2.0f;
            // temp_fs0 = var_s2 - 0.5f;
            // temp_ft5 = var_s2 - 2.0f;
            mtxF.m[0][1] = var_s4 - 0.5f;
            mtxF.m[2][1] = var_s4 - 2.0f;
            mtxF.m[0][0] = var_s4 - 0.5f;
            mtxF.m[2][0] = var_s4 - 2.0f;
            mtxF.m[1][2] = var_s2 - 0.5f;
            mtxF.m[1][0] = var_s2 - 0.5f;
            mtxF.m[3][2] = var_s2 - 2.0f;
            mtxF.m[3][0] = var_s2 - 2.0f;
            // temp_fs0 += 0x20;
            // temp_fs2 += 0x10;
            // temp_ft5 += 0x20;
            // temp_fs1 += 0x10;
            mtxF.m[1][3] = var_s2 - 0.5f + 0x20;
            mtxF.m[1][1] = var_s2 - 0.5f + 0x20;
            mtxF.m[0][3] = var_s4 - 0.5f + 0x10;
            mtxF.m[0][2] = var_s4 - 0.5f + 0x10;
            mtxF.m[3][3] = var_s2 - 2.0f + 0x20;
            mtxF.m[3][1] = var_s2 - 2.0f + 0x20;
            mtxF.m[2][3] = var_s4 - 2.0f + 0x10;
            mtxF.m[2][2] = var_s4 - 2.0f + 0x10;

            var_t1 = &mtxF.m[3][0];
            var_t2 = &mtxF.m[2][0];
            var_t3 = &mtxF.m[1][0];
            var_t4 = &mtxF.m[0][0];

            for (var_a3 = 0; var_a3 < 4; var_a3++) {
                s32 x, y, s, t;
                x = (s32) *var_t1;
                y = (s32) *var_t2;
                s = (s32) (*var_t3 * 32.0f);
                t = (s32) (*var_t4 * 32.0f);
                temp_lo = (var_a3 >> 1) * 11 * ((var_a3 % 2U) + 1);
                temp_t8 = &var_ra[var_a3 % 2U];
                SET_VTX(vtx, x, y, 0, s, t, 255, 255, 255, temp_t8[temp_lo])
                vtx++;
                var_t1++;
                var_t2++;
                var_t3++;
                var_t4++;
            }
            var_ra++;
        }
        var_s5 += 0x16;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/options_menu/func_i6_80083A20.s")
#endif

extern GfxPool D_1000000;
extern Mtx D_2000000[];

Gfx* func_i6_80083F54(Gfx* gfx) {
    s32 pad[27];
    s32 sp40;
    s32 lrt;
    s32 uls;
    s32 lrs;
    s32 ult;
    s32 var_s3;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t5;

    if ((D_i6_8008A7A8 == 1) || (D_i6_8008A7A8 == 2)) {
        gfx = func_806F6360(gfx, 0);
        gSPDisplayList(gfx++, D_8014810);
        gDPSetTextureFilter(gfx++, G_TF_POINT);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_DECALRGB, G_CC_DECALRGB);
        gSPMatrix(gfx++, D_1000000.unk_35248, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        for (sp40 = 0, var_s5 = 0x10, var_s4 = -1; var_s4 < SCREEN_HEIGHT - 1; var_s4 += 16, sp40 += 10, var_s5 += 16) {

            var_s3 = sp40 << 2;

            for (var_s2 = 32, var_t5 = -1; var_t5 < SCREEN_WIDTH - 1; var_t5 += 32, var_s3 += 4, var_s2 += 32) {
                uls = MAX(var_t5, 0);
                lrs = MIN(var_s2, SCREEN_WIDTH - 1);
                ult = MAX(var_s4, 0);
                lrt = MIN(var_s5, SCREEN_HEIGHT - 1);

                gSPVertex(gfx++, (u8*) D_i6_8008A618 + (var_s3 << 4), 4, 0);
                gDPPipeSync(gfx++);
                gDPLoadTextureTile(gfx++, D_i6_8008A7AC, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                   SCREEN_HEIGHT /* unused by macro */, uls, ult, lrs, lrt, 0,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                                   G_TX_NOLOD, G_TX_NOLOD);
                gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);
            }
        }
    }
    return gfx;
}
