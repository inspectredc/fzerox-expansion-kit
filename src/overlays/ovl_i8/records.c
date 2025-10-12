#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_bordered_box.h"
#include "fzx_assets.h"
#include "src/overlays/ovl_i2/transition.h"
#include "assets/overlays/ovl_i8/records.h"

s32 D_800A1EF0;
s32 sUnlockedCourseCount;
s16 D_i8_800A1EF8[5];
BorderedBoxWidget* D_i8_800A1F04;
BorderedBoxWidget* D_i8_800A1F08;
BorderedBoxWidget* D_i8_800A1F0C;
BorderedBoxWidget* D_i8_800A1F10;
BorderedBoxWidget* D_i8_800A1F14;
BorderedBoxWidget* D_i8_800A1F18;
BorderedBoxWidget* D_i8_800A1F1C;
s16 D_i8_800A1F20;
s16 D_i8_800A1F22;
s16 D_i8_800A1F24;
s16 D_i8_800A1F26;
s16 D_i8_800A1F28;
s16 D_i8_800A1F2A;
s16 D_i8_800A1F2C;
s16 D_i8_800A1F2E;
s16 D_i8_800A1F30;
s16 D_i8_800A1F32;
unk_80144FE0* D_i8_800A1F34;
unk_80144FE0 D_i8_800A1F38[2];
UNUSED s32 D_i8_800A2038[6];
s16 D_i8_800A2050;
s16 D_i8_800A2052;
s16 D_i8_800A2054;
s16 D_i8_800A2056;
s16 D_i8_800A2058;
s32 D_i8_800A2060[4];
s32 D_i8_800A2070[4];
s32 D_i8_800A2080[4];
s32 D_i8_800A2090[4];

s32 D_i8_8009E1B0 = 0;

unk_80144F44 D_i8_8009E1B4[] = {
    { 3, { aMenuChangeCourseTex, TEX_WIDTH(aMenuChangeCourseTex), TEX_HEIGHT(aMenuChangeCourseTex) }, NULL },
    { 2, { aMenuQuitTex, TEX_WIDTH(aMenuQuitTex), TEX_HEIGHT(aMenuQuitTex) }, NULL },
    { 0, { aMenuClearRecordTex, TEX_WIDTH(aMenuClearRecordTex), TEX_HEIGHT(aMenuClearRecordTex) }, NULL },
    { 1, { aMenuClearGhostTex, TEX_WIDTH(aMenuClearGhostTex), TEX_HEIGHT(aMenuClearGhostTex) }, NULL },
    { 4, { D_i8_8009F360, TEX_WIDTH(D_i8_8009F360), TEX_HEIGHT(D_i8_8009F360) }, D_i8_8009F768 },
};

unk_80144F74 D_i8_8009E204[] = {
    { aMenuEraseCourseSavedData1Tex, TEX_WIDTH(aMenuEraseCourseSavedData1Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData1Tex) }, // ERASE COURSE DATA? (1)
    { aMenuEraseCourseSavedData2Tex, TEX_WIDTH(aMenuEraseCourseSavedData2Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData2Tex) }, // ERASE COURSE DATA? (2)
};

unk_80144F74 D_i8_8009E214[] = {
    { aMenuNoTex, TEX_WIDTH(aMenuNoTex), TEX_HEIGHT(aMenuNoTex) },    // NO
    { aMenuYesTex, TEX_WIDTH(aMenuYesTex), TEX_HEIGHT(aMenuYesTex) }, // YES
};

unk_8009E224 D_i8_8009E224[] = {
    { D_i8_8009FC00, D_i8_800A0008, TEX_WIDTH(D_i8_8009FC00), TEX_HEIGHT(D_i8_8009FC00) },
    { D_i8_800A0050, D_i8_800A0458, TEX_WIDTH(D_i8_800A0050), TEX_HEIGHT(D_i8_800A0050) },
    { D_i8_800A04A0, D_i8_800A08A8, TEX_WIDTH(D_i8_800A04A0), TEX_HEIGHT(D_i8_800A04A0) },
    { D_i8_800A08F0, D_i8_800A0CF8, TEX_WIDTH(D_i8_800A08F0), TEX_HEIGHT(D_i8_800A08F0) },
};

unk_80144F74 D_i8_8009E254[] = {
    { aMenuNoGamePakTex, TEX_WIDTH(aMenuNoGamePakTex), TEX_HEIGHT(aMenuNoGamePakTex) },
    { aMenuNoDiskTex, TEX_WIDTH(aMenuNoDiskTex), TEX_HEIGHT(aMenuNoDiskTex) },
};

unk_8009E224 D_i8_8009E264[] = {
    { D_i8_8009F7B0, D_i8_8009FBB8, TEX_WIDTH(D_i8_8009F7B0), TEX_HEIGHT(D_i8_8009F7B0) },
    { D_i8_800A0D40, D_i8_800A1D48, TEX_WIDTH(D_i8_800A0D40), TEX_HEIGHT(D_i8_800A0D40) },
};

UNUSED s32 D_i8_8009E27C = 0;

UNUSED const char* D_i8_8009E280[] = {
    "tadashi sugiyama", "takaya imamura", "yasuyuki oyagi",    "hideki konno",      "masanao arimoto",
    "taro bando",       "keizo ohta",     "masahiro kawano",   "daisuke tsujimura", "shiro mouri",
    "hiroki sotoike",   "hajime wakai",   "tsutomu kaneshige",
};

#include "src/assets/overlays/ovl_i8/records/records.c"

s32 D_i8_800A1D6C = 0;

s32 D_i8_800A1D70[] = {
    COURSE_SILENCE_3,    COURSE_SAND_OCEAN_3, COURSE_DEVILS_FOREST_4, COURSE_PORT_TOWN_3,   COURSE_DEVILS_FOREST_5,
    COURSE_BIG_BLUE_3,   COURSE_EDIT_1,       COURSE_EDIT_2,          COURSE_EDIT_3,        COURSE_EDIT_4,
    COURSE_EDIT_5,       COURSE_EDIT_6,       COURSE_MUTE_CITY_4,     COURSE_SPACE_PLANT_2, COURSE_PORT_TOWN_4,
    COURSE_FIRE_FIELD_2, COURSE_WHITE_LAND_3, COURSE_BIG_FOOT,
};

extern s16 D_8076C7A8;
extern s32 D_i2_800BF040;
extern s8 gGamePaused;
extern s32 gDifficulty;
extern s32 gCourseIndex;
extern u8 gEditCupTrackNames[][9];

void Records_Init(void) {
    bool var_s0;

    D_8076C7A8 = D_i2_800BF040 = 3;
    gGamePaused = false;
    gDifficulty = MASTER;
    gRacers[0].character = CAPTAIN_FALCON;
    var_s0 = true;

    while (var_s0) {
        func_i2_800B934C();
        if (D_i8_800A1D6C != 0) {
            if ((gCourseIndex >= COURSE_EDIT_1) && (gCourseIndex <= COURSE_EDIT_6)) {
                if (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0') {
                    if (D_i8_800A1D6C == 1) {
                        if (gCourseIndex == COURSE_EDIT_6) {
                            gCourseIndex = COURSE_MUTE_CITY_4;
                            var_s0 = false;
                            func_i2_800B934C();
                        } else {
                            gCourseIndex++;
                        }
                    } else if (gCourseIndex == COURSE_EDIT_1) {
                        gCourseIndex = COURSE_BIG_BLUE_3;
                        var_s0 = false;
                        func_i2_800B934C();
                    } else {
                        gCourseIndex--;
                    }
                } else {
                    var_s0 = false;
                }
            } else {
                var_s0 = false;
            }
            if (!var_s0) {
                D_i8_800A1D6C = 0;
            }
        } else {
            var_s0 = false;
        }
    }

    func_i3_80040158();
    func_8071D48C();
    func_807160A0();
    func_8070F0B0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
    func_i3_800617A0();
    func_806F9774();
    func_806FB3AC();
    func_806FBBC8();
    func_806FE8F8(0);
    func_i8_8009B348();
}

extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;

void func_i8_8009B348(void) {
    s32 i;
    unk_80144F44* var_s0;

    D_i8_8009E1B0 = gCourseIndex;
    if ((gUnlockableLevel == 0) && !gSettingEverythingUnlocked) {
        sUnlockedCourseCount = 18;
    } else {
        sUnlockedCourseCount = 24;
    }
    D_i8_800A1F32 = -1;
    for (i = 0; i < 4; i++) {
        D_i8_800A2060[i] = D_i8_800A2090[i] = -1;
    }

    for (i = 0; i < 5; i++) {
        switch (D_i8_8009E1B4[i].unk_00) {
            case 0:
                if (func_i8_8009B704(D_i8_8009E1B0)) {
                    D_i8_800A1EF8[i] = 0;
                } else {
                    D_i8_800A1EF8[i] = 1;
                }
                break;
            case 1:
                if (func_i8_8009B758(D_i8_8009E1B0)) {
                    D_i8_800A1EF8[i] = 1;
                    D_i8_800A1F2A = 1;
                    D_i8_800A1F2C = D_i8_800A1F2E = 255;
                } else {
                    D_i8_800A1EF8[i] = 0;
                    D_i8_800A1F2A = 0;
                }
                break;
            case 3:
                D_i8_800A1F22 = i;
                D_i8_800A1EF8[i] = 1;
                break;
            case 4:
                D_i8_800A1F24 = i;
                if ((D_i8_800A1F2A != 0) && !((gCourseIndex >= COURSE_EDIT_1) && (gCourseIndex <= COURSE_EDIT_6))) {
                    D_i8_800A1EF8[i] = 1;
                } else {
                    D_i8_800A1EF8[i] = 0;
                }
                break;
            default:
                D_i8_800A1EF8[i] = 1;
                break;
        }
    }
    D_800A1EF0 = 0;
    D_i8_800A1F30 = 0;
    func_i2_800AE7C4(aMenuTextTLUT, TEX_SIZE(aMenuTextTLUT, sizeof(u16)), 0, 0, false);

    var_s0 = D_i8_8009E1B4;
    for (i = 0; i < 5; i++, var_s0++) {
        if (var_s0->tlut == NULL) {
            func_i2_800AE7C4(var_s0->unk_04.unk_00, var_s0->unk_04.width * var_s0->unk_04.height * sizeof(u8), 0, 1,
                             false);
        }
    }
    func_i2_800AE7C4(aMenuEraseCourseSavedData1Tex, TEX_SIZE(aMenuEraseCourseSavedData1Tex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuEraseCourseSavedData2Tex, TEX_SIZE(aMenuEraseCourseSavedData2Tex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuLeftArrowTex, TEX_SIZE(aMenuLeftArrowTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuRightArrowTex, TEX_SIZE(aMenuRightArrowTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuNoTex, TEX_SIZE(aMenuNoTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuYesTex, TEX_SIZE(aMenuYesTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aHasGhostMarkerTex, TEX_SIZE_4B(aHasGhostMarkerTex), 0, 0, false);
    func_i2_800AE7C4(aMenuNoGamePakTex, TEX_SIZE(aMenuNoGamePakTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuNoDiskTex, TEX_SIZE(aMenuNoDiskTex, sizeof(u8)), 0, 1, false);
    func_i3_80064F20();
    BorderedBox_CleanWidget(&D_i8_800A1F04);
    BorderedBox_CleanWidget(&D_i8_800A1F08);
    BorderedBox_CleanWidget(&D_i8_800A1F10);
    BorderedBox_CleanWidget(&D_i8_800A1F14);
    BorderedBox_CleanWidget(&D_i8_800A1F18);
    BorderedBox_CleanWidget(&D_i8_800A1F1C);
    BorderedBox_CleanWidget(&D_i8_800A1F0C);
    BorderedBox_ClearAll();
}

bool func_i8_8009B704(s32 courseIndex) {
    s32 i;
    bool ret = true;

    for (i = 0; i < 5; i++) {
        if (gCourseInfos[courseIndex].timeRecord[i] != MAX_TIMER) {
            ret = false;
            break;
        }
    }

    return ret;
}

bool func_i8_8009B758(s32 courseIndex) {
    CourseInfo* courseInfo = &gCourseInfos[courseIndex];
    s32 i;
    bool ret = false;
    s32 pad[4];
    GhostInfo spE4;
    GhostRecord sp24[3];

    Save_LoadGhostInfo(&spE4);

    if (spE4.encodedCourseIndex == courseInfo->encodedCourseIndex) {
        ret = true;
    }

    if (!ret) {
        func_i2_800A9CE0(courseIndex, sp24);
        for (i = 0; i < 3; i++) {
            if (sp24[i].encodedCourseIndex == courseInfo->encodedCourseIndex) {
                D_i8_800A2060[i + 1] = sp24[i].raceTime;
                ret = true;
            }
        }
    }

    return ret;
}

void func_i8_8009B81C(s32* raceTimes, bool arg1) {
    s32 i;
    CourseInfo* courseInfo = &gCourseInfos[gCourseIndex];
    GhostInfo spE8;
    GhostRecord sp28[3];
    s32 courseIndex;

    if (arg1) {
        Save_LoadGhostInfo(&spE8);
        if (spE8.encodedCourseIndex == courseInfo->encodedCourseIndex) {
            *raceTimes = spE8.raceTime;
        } else {
            *raceTimes = -1;
        }
    }
    raceTimes++;

    func_i2_800A9CE0(gCourseIndex, sp28);

    for (i = 0; i < 3; i++, raceTimes++) {
        if (courseInfo->encodedCourseIndex == sp28[i].encodedCourseIndex) {
            *raceTimes = sp28[i].raceTime;
        } else {
            *raceTimes = -1;
        }
    }
}

extern s16 D_8076C814;
extern s32 D_8076CC8C;
extern s32 D_8079A35C;

s32 Records_Update(void) {
    s32 temp_v0;
    s32 gameMode;
    s32 sp1C;
    s32 var_v0;

    Controller_SetGlobalInputs(&gSharedController);
    D_i8_800A1F34 = &D_i8_800A1F38[D_8079A35C];
    func_8070D220();
    func_80726554();
    func_80717294();
    func_i3_80061C2C();
    func_800B94D8();
    func_8070304C();
    if (D_i8_800A1F2A != 0) {
        func_i8_8009C708();
    }
    func_i3_80065204();
    BorderedBox_Update();
    gameMode = GAMEMODE_RECORDS;
    sp1C = 0;
    if (D_i8_800A1F30 == 0) {
        switch (D_800A1EF0) {
            case 0:
                temp_v0 = func_i8_8009BB60();
                if (temp_v0 == 1) {
                    sp1C = 1;
                } else if (temp_v0 == 2) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                }
                if (temp_v0 != 0) {
                    D_i8_800A1F30 = 1;
                }
                break;
            case 1:
                temp_v0 = func_i8_8009BE14();
                if (temp_v0 == 1) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                } else if (temp_v0 == 2) {
                    gameMode = GAMEMODE_FLX_MAIN_MENU;
                }
                if (temp_v0 != 0) {
                    D_i8_800A1F30 = 1;
                }
                break;
            case 2:
                func_i8_8009C26C();
                break;
            case 4:
                func_i8_8009CE64();
                break;
            case 5:
                func_i8_8009D430();
                break;
            case 6:
                func_i8_8009D8A4();
                break;
            case 7:
                func_i8_8009DCC8();
                break;
            case 3:
                func_i8_8009C44C();
                break;
        }
    }

    switch (D_i8_800A1F32) {
        case -1:
            if (gRacers->stateFlags & 0x40000) {
                D_i8_800A1F32 = 0x3C;
            }
            break;
        case 0:
            D_i8_800A1F32 = -1;
            func_8071D48C();
            func_807160A0();
            break;
        default:
            D_i8_800A1F32 -= 1;
            break;
    }

    if (sp1C != 0) {
        D_8076CC8C = gCourseIndex;
        D_8076C814 = 8;
    }
    var_v0 = D_i8_800A1F30;
    if ((gameMode == GAMEMODE_FLX_MAIN_MENU) && (var_v0 != 0)) {
        Audio_RomBgmReady(BGM_SELECT);
    }
    return gameMode;
}

extern s32 gTransitionState;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

s32 func_i8_8009BB60(void) {
    s32 i;
    s32 sp30;
    s32 lastCourseIndex;

    if (gTransitionState != TRANSITION_INACTIVE) {
        return 0;
    }
    if (BorderedBox_GetInfo(D_i8_800A1F04, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }
    if (BorderedBox_GetInfo(D_i8_800A1F10, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }
    if (BorderedBox_GetInfo(D_i8_800A1F0C, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }

    lastCourseIndex = gCourseIndex;
    if (gInputPressed & BTN_RIGHT) {
        D_i8_800A1D6C = 1;
        if (gCourseIndex == COURSE_BIG_FOOT) {
            gCourseIndex = 0;
        } else {
            if (gCourseIndex >= sUnlockedCourseCount - 1) {
                for (i = 0; i < 18; i++) {
                    if (gCourseIndex == D_i8_800A1D70[i]) {
                        break;
                    }
                }
                if (i != 18) {
                    gCourseIndex = D_i8_800A1D70[i + 1];
                } else {
                    gCourseIndex = COURSE_SILENCE_3;
                }
            } else {
                gCourseIndex++;
            }
        }
        Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_LEFT);
    } else if (gInputPressed & BTN_LEFT) {
        D_i8_800A1D6C = 2;
        if (gCourseIndex == 0) {
            gCourseIndex = COURSE_BIG_FOOT;
        } else {
            if (gCourseIndex >= sUnlockedCourseCount) {
                for (i = 0; i < 18; i++) {
                    if (gCourseIndex == D_i8_800A1D70[i]) {
                        break;
                    }
                }
                if (i != 0) {
                    gCourseIndex = D_i8_800A1D70[i - 1];
                } else {
                    gCourseIndex = sUnlockedCourseCount - 1;
                }
            } else {
                gCourseIndex--;
            }
        }
        Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_RIGHT);
    }

    if (lastCourseIndex != gCourseIndex) {
        sp30 = 1;
        Audio_TriggerSystemSE(NA_SE_30);
    } else {
        sp30 = 0;
    }
    if (sp30 == 0) {
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            D_i8_800A1F04 = BorderedBox_Init(0, 108, 50, 104, 120, 10, GPACK_RGBA5551(0, 255, 0, 1), func_i8_8009CA7C);
            if (D_i8_800A1F04 != NULL) {
                D_800A1EF0 = 1;
                D_i8_800A1F20 = 0;
                Audio_TriggerSystemSE(NA_SE_33);
                func_i3_80067118(0);
            }
        } else if (gInputButtonPressed & BTN_B) {
            sp30 = 2;
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
    return sp30;
}

s32 func_i8_8009BE14(void) {
    s32 i;
    bool var_t0;
    s32 sp2C;
    s32 sp28;
    s32 j;
    s32 var_v0;
    s32 var_v1;
    s32 temp_a3;
    bool var_a2;

    if (!BorderedBox_GetInfo(D_i8_800A1F04, IS_BORDERED_BOX_OPENED)) {
        return 0;
    }
    sp2C = 0;
    sp28 = D_i8_800A1F20;
    // clang-format off
    if (gInputPressed & BTN_UP) {
        if (--D_i8_800A1F20 < 0) { D_i8_800A1F20 = 4; }

        while (D_i8_800A1EF8[D_i8_800A1F20] == 0) {
            if (--D_i8_800A1F20 < 0) { D_i8_800A1F20 = 4; }
        }
    } else if (gInputPressed & BTN_DOWN) {
        if (++D_i8_800A1F20 > 4) { D_i8_800A1F20 = 0; }

        while (D_i8_800A1EF8[D_i8_800A1F20] == 0) {
            if (++D_i8_800A1F20 > 4) { D_i8_800A1F20 = 0; }
        }
    }
    // clang-format on
    if (sp28 != D_i8_800A1F20) {
        Audio_TriggerSystemSE(NA_SE_30);
    }
    if (gInputButtonPressed & (BTN_A | BTN_START)) {
        var_t0 = false;

        switch (D_i8_8009E1B4[D_i8_800A1F20].unk_00) {
            case 3:
                var_t0 = true;
                sp2C = 1;
                break;
            case 2:
                var_t0 = true;
                sp2C = 2;
                break;
            case 0:
            case 1:
                if (D_i8_8009E1B4[D_i8_800A1F20].unk_00 == 0) {
                    D_i8_800A1F28 = 0;
                    var_v0 = 120;
                } else {
                    D_i8_800A1F28 = 1;
                    var_v0 = 142;
                }

                D_i8_800A1F08 =
                    BorderedBox_Init(1, 120, var_v0, 148, 80, 20, GPACK_RGBA5551(255, 0, 0, 1), func_i8_8009CC30);

                var_t0 = false;
                if (D_i8_800A1F08 != NULL) {
                    var_t0 = true;
                    D_i8_800A1F26 = 0;
                    D_800A1EF0 = 2;
                }
                break;
            case 4:
                D_i8_800A1F10 =
                    BorderedBox_Init(3, 40, 46, 168, 122, 30, GPACK_RGBA5551(0, 0, 255, 1), func_i8_8009D0E8);

                var_t0 = false;
                if (D_i8_800A1F10 != NULL) {
                    var_t0 = true;
                    D_800A1EF0 = 4;
                    func_i8_8009B81C(D_i8_800A2060, 1);
                    for (i = 0; i < 3; i++) {
                        D_i8_800A2070[i] = i;
                    }

                    for (i = 0; i < 2; i++) {
                        for (j = i + 1; j < 3; j++) {
                            var_a2 = false;

                            if (D_i8_800A2060[D_i8_800A2070[i] + 1] == -1) {
                                if (D_i8_800A2060[D_i8_800A2070[j] + 1] != -1) {
                                    var_a2 = true;
                                }
                            } else if (D_i8_800A2060[D_i8_800A2070[j] + 1] != -1) {
                                if (D_i8_800A2060[D_i8_800A2070[j] + 1] < D_i8_800A2060[D_i8_800A2070[i] + 1]) {
                                    var_a2 = true;
                                }
                            }
                            if (var_a2) {
                                temp_a3 = D_i8_800A2070[i];
                                D_i8_800A2070[i] = D_i8_800A2070[j];
                                D_i8_800A2070[j] = temp_a3;
                            }
                        }
                    }

                    for (i = 0; i < 4; i++) {

                        if (i == 0) {
                            var_v1 = i;
                        } else {
                            var_v1 = D_i8_800A2070[i - 1] + 1;
                        }
                        if (D_i8_800A2060[var_v1] != -1) {
                            break;
                        }
                    }
                    if (i != 4) {
                        D_i8_800A2050 = i;
                    } else {
                        D_i8_800A2050 = -1;
                    }
                }
                break;
        }

        if (var_t0) {
            Audio_TriggerSystemSE(NA_SE_33);
        }
    } else if (gInputButtonPressed & BTN_B) {
        D_800A1EF0 = 0;
        func_i3_80067118(1);
        BorderedBox_StartClose(D_i8_800A1F04);
        Audio_TriggerSystemSE(NA_SE_16);
    }
    return sp2C;
}

void func_i8_8009C26C(void) {
    s32 sp1C;
    bool sp18;

    if (BorderedBox_GetInfo(D_i8_800A1F08, IS_BORDERED_BOX_OPENED)) {
        sp1C = D_i8_800A1F26;
        if (gInputPressed & BTN_LEFT) {
            D_i8_800A1F26--;
            if (D_i8_800A1F26 < 0) {
                D_i8_800A1F26 = 1;
            }
        } else if (gInputPressed & BTN_RIGHT) {
            D_i8_800A1F26++;
            if (D_i8_800A1F26 > 1) {
                D_i8_800A1F26 = 0;
            }
        }
        if (sp1C != D_i8_800A1F26) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        sp18 = false;
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            sp18 = true;
            if (D_i8_800A1F26 == 0) {
                Audio_TriggerSystemSE(NA_SE_16);
            } else {
                if (D_i8_800A1F28 == 0) {
                    if ((gCourseIndex >= COURSE_MUTE_CITY) && (gCourseIndex <= COURSE_BIG_HAND)) {
                        func_i2_800A7660(gCourseIndex);
                    } else {
                        func_i2_800AA694(gCourseIndex);
                    }
                } else if (D_i8_800A1F28 == 1) {
                    Save_InitGhost(gCourseIndex);
                    func_i2_800AA520(gCourseIndex);
                    D_i8_800A1EF8[D_i8_800A1F24] = 0;
                    D_i8_800A1F2A = 2;
                }
                D_i8_800A1EF8[D_i8_800A1F20] = 0;
                D_i8_800A1F20 = D_i8_800A1F22;
                Audio_TriggerSystemSE(NA_SE_5);
            }
        } else if (gInputButtonPressed & BTN_B) {
            sp18 = true;
            Audio_TriggerSystemSE(NA_SE_16);
        }
        if (sp18) {
            D_800A1EF0 = 1;
            BorderedBox_StartClose(D_i8_800A1F08);
        }
    }
}

void func_i8_8009C44C(void) {
    if (BorderedBox_GetInfo(D_i8_800A1F0C, IS_BORDERED_BOX_OPENED) && (gInputButtonPressed & BTN_B)) {
        D_800A1EF0 = 0;
        func_i3_80067118(1);
        BorderedBox_StartClose(D_i8_800A1F0C);
        Audio_TriggerSystemSE(NA_SE_16);
    }
}

extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A364;
extern Vtx* D_807A15DC;
extern Vtx* D_807A15E0;
extern Vtx* D_800D65D0;
extern GfxPool* gGfxPool;
extern Gfx D_8076CE28[];

Gfx* Records_Draw(Gfx* gfx) {

    if (D_i2_800BF040 != 0) {
        D_i2_800BF040--;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPPipelineMode(gfx++, G_PM_NPRIMITIVE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1));
        gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                         OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    }

    gSPDisplayList(gfx++, D_8076CE28);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));

    D_800D65D0 = gGfxPool->unk_1A308;
    D_807A15DC = gGfxPool->unk_2A308;
    D_807A15E0 = &gGfxPool->unk_2A308[0x7FF];
    gfx = func_i3_8006339C(gfx, 0, 0);
    gfx = func_i2_800BDE60(gfx, 0);
    gfx = func_806F9DB4(gfx, 0);
    gfx = func_i3_80065560(gfx, D_i8_8009E1B0);
    if (D_i8_800A1F2A != 0) {
        gfx = func_i8_8009C900(gfx);
    }
    return BorderedBox_Draw(gfx);
}

void func_i8_8009C708(void) {
    Vtx* vtx;
    u16 temp;

    switch (D_i8_800A1F2A) {
        case 1:
            break;
        case 2:
            if (D_i8_800A1F2E > 0) {
                D_i8_800A1F2E -= 10;
                if (D_i8_800A1F2E < 0) {
                    D_i8_800A1F2E = 0;
                }
            }
            if (D_i8_800A1F2E == 0) {
                D_i8_800A1F2C -= 10;
                if (D_i8_800A1F2C < 0) {
                    D_i8_800A1F2C = 0;
                }
            }
            if ((D_i8_800A1F2E == 0) && (D_i8_800A1F2C == 0)) {
                D_i8_800A1F2A = 0;
                return;
            }
            break;
    }

    Matrix_SetOrtho(&D_i8_800A1F34->unk_00, NULL, 1.0f, 0.0f, 319.0f, 239.0f, 0.0f, -100.0f, 100.0f);

    vtx = D_i8_800A1F34->unk_40;
    temp = -16;

    SET_VTX(vtx, 236, 60, 0, temp, temp, 255, 255, 255, D_i8_800A1F2C);
    vtx++;
    SET_VTX(vtx, 267, 60, 0, 0x400, 0, 255, 255, 255, D_i8_800A1F2C);
    vtx++;
    SET_VTX(vtx, 236, 75, 0, 0, 0x200, 255, 255, 255, D_i8_800A1F2E);
    vtx++;
    SET_VTX(vtx, 267, 75, 0, 0x400, 0x200, 255, 255, 255, D_i8_800A1F2E);
    vtx++;
}

extern Mtx D_2000000[];

Gfx* func_i8_8009C900(Gfx* gfx) {

    gfx = func_806F6360(gfx, 0);
    gSPDisplayList(gfx++, D_8014810);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    gSPMatrix(gfx++, &D_i8_800A1F34->unk_00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, D_i8_800A1F34->unk_40, 4, 0);

    gDPLoadTextureBlock_4b(gfx++, func_i2_800AEA90(aHasGhostMarkerTex), G_IM_FMT_I, 32, 16, 0,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);

    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);

    return gfx;
}

Gfx* func_i8_8009CA7C(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 temp_s4;
    s32 i;
    unk_80144F74* temp_s1;
    TexturePtr tlut;
    TexturePtr texture;
    unk_80144F44* var_s5;

    gSPDisplayList(gfx++, D_8014940);

    var_s5 = D_i8_8009E1B4;
    for (i = 0; i < 5; i++, var_s5++) {

        gDPPipeSync(gfx++);

        if (i != D_i8_800A1F20) {
            if (D_i8_800A1EF8[i] != 0) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }

        temp_s1 = &var_s5->unk_04;
        temp_s4 = ((104 - temp_s1->width) / 2) - 20;
        if (var_s5->tlut == NULL) {
            texture = func_i2_800AEA90(temp_s1->unk_00);
            tlut = func_i2_800AEA90(aMenuTextTLUT);
        } else {
            texture = temp_s1->unk_00;
            tlut = var_s5->tlut;
        }

        gfx = func_8070DEE0(gfx, texture, tlut, G_IM_FMT_CI, 1, arg1 + temp_s4 + 20, arg2 + 10 + i * 20, temp_s1->width,
                            temp_s1->height, 3);
    }

    return gfx;
}

Gfx* func_i8_8009CC30(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_80144F74* temp_s0;
    s32 sp58;
    s32 pad;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    temp_s0 = &D_i8_8009E204[D_i8_800A1F28];

    gfx = func_8070DEE0(gfx, func_i2_800AEA90(temp_s0->unk_00), func_i2_800AEA90(aMenuTextTLUT), G_IM_FMT_CI, 1,
                        arg1 + 12, arg2 + 10, temp_s0->width, temp_s0->height, 3);

    gDPPipeSync(gfx++);
    gfx = func_8070D4A8(gfx, 0);
    gfx =
        func_8070DEE0(gfx, func_i2_800AEA90(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 24, arg2 + 50, 16, 16, 0);
    gfx =
        func_8070DEE0(gfx, func_i2_800AEA90(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, arg1 + 99, arg2 + 50, 16, 16, 0);

    temp_s0 = &D_i8_8009E214[D_i8_800A1F26];
    sp58 = (0x3B - temp_s0->width) / 2;
    return func_8070DEE0(gfx, func_i2_800AEA90(temp_s0->unk_00), NULL, G_IM_FMT_CI, 1, arg1 + sp58 + 42, arg2 + 50,
                         temp_s0->width, temp_s0->height, 0);
}

void func_i8_8009CE5C(void) {
}

void func_i8_8009CE64(void) {
    s32 temp;
    s32 var_v1;

    if ((BorderedBox_GetInfo(D_i8_800A1F10, IS_BORDERED_BOX_OPENED)) &&
        (!BorderedBox_GetInfo(D_i8_800A1F14, IS_BORDERED_BOX_ACTIVE))) {
        temp = D_i8_800A2050;
        if (D_i8_800A2050 == -1) {
            if (gInputButtonPressed & BTN_B) {
                D_800A1EF0 = 1;
                BorderedBox_StartClose(D_i8_800A1F10);
                Audio_TriggerSystemSE(NA_SE_16);
            }
        } else {
            if (gInputPressed & BTN_UP) {
                do {
                    D_i8_800A2050--;
                    if (D_i8_800A2050 < 0) {
                        D_i8_800A2050 = 3;
                    }
                    if (D_i8_800A2050 == 0) {
                        var_v1 = D_i8_800A2050;
                    } else {
                        var_v1 = D_i8_800A2070[D_i8_800A2050 - 1] + 1;
                    }
                } while (D_i8_800A2060[var_v1] == -1);
            } else if (gInputPressed & BTN_DOWN) {
                do {
                    D_i8_800A2050++;
                    if (D_i8_800A2050 > 3) {
                        D_i8_800A2050 = 0;
                    }
                    if (D_i8_800A2050 == 0) {
                        var_v1 = D_i8_800A2050;
                    } else {
                        var_v1 = D_i8_800A2070[D_i8_800A2050 - 1] + 1;
                    }
                } while (D_i8_800A2060[var_v1] == -1);
            }
            if (temp != D_i8_800A2050) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                D_i8_800A1F14 =
                    BorderedBox_Init(4, 120, 60, 148, 72, 40, GPACK_RGBA5551(0, 0, 255, 1), func_i8_8009D6A4);

                if (D_i8_800A1F14 != NULL) {
                    D_800A1EF0 = 5;
                    if ((D_i8_800A2050 != 0) && (gCourseIndex <= COURSE_BIG_HAND)) {
                        D_i8_800A2090[0] = MAX_TIMER;
                        D_i8_800A2052 = 0;
                    } else {
                        D_i8_800A2090[0] = -1;
                        D_i8_800A2052 = 1;
                    }
                    func_i8_8009DF6C(0);
                }
                Audio_TriggerSystemSE(NA_SE_33);
                return;
            }
            if (gInputButtonPressed & BTN_B) {
                D_800A1EF0 = 1;
                func_80704810(1);
                BorderedBox_StartClose(D_i8_800A1F10);
                Audio_TriggerSystemSE(NA_SE_16);
            }
        }
    }
}

Gfx* func_i8_8009D0E8(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_8009E224* var_s2;
    s32 i;
    s32 var_s4;
    s32 var_s8;
    s32 var_s3;
    s32 var_v0;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_8070DEE0(gfx, D_i8_8009E2C0, D_i8_8009EAC8, G_IM_FMT_CI, 1, arg1 + 20, arg2 + 10, 128, 16, 3);

    for (i = 0; i < 4; i++) {
        var_s8 = arg1 + 10;
        var_s3 = arg2 + 30 + i * 20;
        var_s2 = &D_i8_8009E224[i];
        gDPPipeSync(gfx++);

        if (i != D_i8_800A2050) {
            if (i == 0) {
                var_v0 = i;
            } else {
                var_v0 = D_i8_800A2070[i - 1] + 1;
            }
            if (D_i8_800A2060[var_v0] != -1) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, var_s2->texture, var_s2->tlut, G_IM_FMT_CI, 1, var_s8, var_s3, var_s2->width,
                            var_s2->height, 2);
    }

    gSPDisplayList(gfx++, D_8014940);

    var_s4 = false;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            var_v0 = i;
        } else {
            var_v0 = D_i8_800A2070[i - 1] + 1;
        }

        if (D_i8_800A2060[var_v0] == -1) {
            continue;
        }
        if (!var_s4) {
            var_s4 = true;
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gfx = func_i3_DrawTimerScisThousandths(gfx, D_i8_800A2060[var_v0], arg1 + 84, arg2 + 30 + (i * 20), 1.0f);
    }
    return gfx;
}

void func_i8_8009D430(void) {
    s32 temp;
    s16 sp20[2];

    if (BorderedBox_GetInfo(D_i8_800A1F14, IS_BORDERED_BOX_OPENED) &&
        !BorderedBox_GetInfo(D_i8_800A1F18, IS_BORDERED_BOX_ACTIVE)) {
        sp20[0] = D_i8_800A2090[0];
        sp20[1] = -0x1181;
        temp = D_i8_800A2052;
        if (gInputPressed & BTN_UP) {
            do {
                D_i8_800A2052--;
                if (D_i8_800A2052 < 0) {
                    D_i8_800A2052 = 1;
                }
            } while (sp20[D_i8_800A2052] == -1);
        } else if (gInputPressed & BTN_DOWN) {
            do {
                D_i8_800A2052++;
                if (D_i8_800A2052 > 1) {
                    D_i8_800A2052 = 0;
                }
            } while (sp20[D_i8_800A2052] == -1);
        }
        if (temp != D_i8_800A2052) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            if (D_i8_800A2052 == 0) {
                D_i8_800A2054 = 0;
                func_i8_8009D5B8(0);
            } else {
                func_i8_8009D5B8(1);
            }
            Audio_TriggerSystemSE(NA_SE_33);
            return;
        }
        if (gInputButtonPressed & BTN_B) {
            D_800A1EF0 = 4;
            BorderedBox_StartClose(D_i8_800A1F14);
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
}

void func_i8_8009D5B8(s32 arg0) {
    s32 temp_v1;
    s32 temp_t0;
    unk_8009E224* temp_v0;
    BorderedBoxWidget* temp_v0_2;

    D_i8_800A2058 = arg0;
    temp_v0 = &D_i8_8009E264[D_i8_800A2058];
    temp_v1 = temp_v0->width + 20;
    temp_t0 = temp_v0->height + 20;
    D_i8_800A1F1C = BorderedBox_Init(6, (SCREEN_WIDTH - temp_v1) / 2, (SCREEN_HEIGHT - temp_t0) / 2, temp_v1, temp_t0,
                                     60, GPACK_RGBA5551(255, 255, 0, 1), func_i8_8009E0F0);

    if (D_i8_800A1F1C != NULL) {
        D_800A1EF0 = 7;
        D_i8_800A2056 = 0;
    }
}

Gfx* func_i8_8009D6A4(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_80144F74* var_s2;
    TexturePtr tlut;
    s32 i;
    s32 var_s6;
    s32 var_s4;
    s32 var_v0;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_8070DEE0(gfx, D_i8_8009EB10, D_i8_8009F318, G_IM_FMT_CI, 1, arg1 + 10, arg2 + 10, 128, 16, 3);

    for (i = 0; i < 2; i++) {
        var_s6 = arg1 + 20;
        var_s4 = arg2 + 30 + i * 20;
        var_s2 = &D_i8_8009E254[i];

        gDPPipeSync(gfx++);
        if (i != 0) {
            tlut = NULL;
        } else {
            tlut = func_i2_800AEA90(aMenuTextTLUT);
        }
        if (i != D_i8_800A2052) {
            if (i == 0) {
                var_v0 = i;
            } else {
                var_v0 = D_i8_800A2070[i + 3] + 1;
            }
            if ((i == 0) && (D_i8_800A2090[var_v0] == -1)) {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, func_i2_800AEA90(var_s2->unk_00), tlut, G_IM_FMT_CI, 1, var_s6, var_s4, var_s2->width,
                            var_s2->height, 2);
    }
    return gfx;
}

void func_i8_8009D8A4(void) {
    s32 temp;

    if (BorderedBox_GetInfo(D_i8_800A1F18, IS_BORDERED_BOX_OPENED) &&
        !BorderedBox_GetInfo(D_i8_800A1F1C, IS_BORDERED_BOX_ACTIVE)) {
        temp = D_i8_800A2054;
        if (gInputPressed & BTN_UP) {
            D_i8_800A2054--;
            if (D_i8_800A2054 < 1) {
                D_i8_800A2054 = 3;
            }
        } else if (gInputPressed & BTN_DOWN) {
            D_i8_800A2054++;
            if (D_i8_800A2054 > 3) {
                D_i8_800A2054 = 1;
            }
        }
        if (temp != D_i8_800A2054) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            func_i8_8009D5B8(0);
            Audio_TriggerSystemSE(NA_SE_33);
            return;
        }
        if (gInputButtonPressed & BTN_B) {
            func_80704810(1);
            D_800A1EF0 = 1;
            BorderedBox_StartClose(D_i8_800A1F18);
            BorderedBox_StartClose(D_i8_800A1F14);
            BorderedBox_StartClose(D_i8_800A1F10);
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
}

Gfx* func_i8_8009D9D8(Gfx* gfx, s32 arg1, s32 arg2) {
    s32 i;
    unk_8009E224* var_s2;
    s32 var_v0;
    s32 var_s4;
    s32 pad;

    for (i = 1, var_s2 = &D_i8_8009E224[i]; i < 4; i++, var_s2++) {

        gDPPipeSync(gfx++);

        if (i != 1) {
            var_s4 = 2;
        } else {
            var_s4 = 3;
        }
        if (i != D_i8_800A2054) {
            if (i == 0) {
                var_v0 = i;
            } else {
                var_v0 = D_i8_800A2070[i + 3] + 1;
            }
            if (D_i8_800A2090[var_v0] != -1) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, var_s2->texture, var_s2->tlut, 2, 1, arg1 + 10, arg2 - 10 + i * 20, var_s2->width,
                            var_s2->height, var_s4);
    }

    gSPDisplayList(gfx++, D_8014940);

    var_s4 = false;
    for (i = 1; i < 4; i++) {

        if (i == 0) {
            var_v0 = i;
        } else {
            var_v0 = D_i8_800A2070[i + 3] + 1;
        }

        if (D_i8_800A2090[var_v0] == -1) {
            continue;
        }
        if (!var_s4) {
            var_s4 = true;
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gfx = func_i3_DrawTimerScisThousandths(gfx, D_i8_800A2090[var_v0], arg1 + 84, arg2 - 10 + i * 20, 1.0f);
    }
    return gfx;
}

extern volatile u8 D_80794E14;

void func_i8_8009DCC8(void) {
    s32 i;
    s32 j;
    bool var_a2;
    s32 temp_a3;

    if (BorderedBox_GetInfo(D_i8_800A1F1C, IS_BORDERED_BOX_OPENED)) {
        switch (D_i8_800A2058) {
            case 0:
                if (D_i8_800A2056 < 1000) {
                    D_i8_800A2056++;
                }

                if (D_80794E14) {
                    break;
                }

                if (D_i8_800A2056 == 5) {
                    D_i8_800A2056++;
                    func_i8_8009DF6C(1);
                }
                if (D_i8_800A2056 >= 60) {
                    func_80704810(1);
                    D_800A1EF0 = 1;
                    BorderedBox_StartClose(D_i8_800A1F1C);
                    if (D_i8_800A2054 != 0) {
                        BorderedBox_StartClose(D_i8_800A1F18);
                    }
                    BorderedBox_StartClose(D_i8_800A1F14);
                    BorderedBox_StartClose(D_i8_800A1F10);
                }
                break;
            case 1:
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_80704810(0);
                    func_80704AA8();
                    func_i8_8009B81C(D_i8_800A2090, 0);

                    for (i = 0; i < 3; i++) {
                        D_i8_800A2080[i] = i;
                    }

                    for (i = 0; i < 2; i++) {
                        for (j = i + 1; j < 3; j++) {
                            var_a2 = false;

                            if (D_i8_800A2090[D_i8_800A2080[i] + 1] == -1) {
                                if (D_i8_800A2090[D_i8_800A2080[j] + 1] != -1) {
                                    var_a2 = true;
                                }
                            } else if (D_i8_800A2090[D_i8_800A2080[j] + 1] != -1) {
                                if ((D_i8_800A2090[D_i8_800A2080[j] + 1] < D_i8_800A2090[D_i8_800A2080[i] + 1])) {
                                    var_a2 = true;
                                }
                            }
                            if (var_a2 != 0) {
                                temp_a3 = D_i8_800A2080[i];
                                D_i8_800A2080[i] = D_i8_800A2080[j];
                                D_i8_800A2080[j] = temp_a3;
                            }
                        }
                    }
                    D_i8_800A1F18 =
                        BorderedBox_Init(5, 130, 126, 168, 72, 50, GPACK_RGBA5551(0, 0, 255, 1), func_i8_8009D9D8);

                    if (D_i8_800A1F18 != NULL) {
                        D_800A1EF0 = 6;
                        D_i8_800A2054 = 1;
                        BorderedBox_StartClose(D_i8_800A1F1C);
                    }
                    Audio_TriggerSystemSE(NA_SE_33);
                }
                break;
        }
    }
}

void func_i8_8009DF6C(s32 arg0) {
    s32 pad[3];
    s32 temp;
    GhostRecord sp20[3];

    PRINTF("STAFF GHOST");
    PRINTF("STAFF GHOST");
    PRINTF("TIME");
    PRINTF("LAP%1d");

    if (arg0 == 0) {
        switch (D_i8_800A2050) {
            case 0:
                Save_LoadGhostInfo(NULL);
                Save_ReadGhostData(&gSaveContext.ghostSave.data);
                Save_LoadGhostData(&gSaveContext.ghostSave, &gSaveContext.ghostSave.data, 0, 1);
                break;
            case 1:
            case 2:
            case 3:
                func_i2_800A9ED0(gCourseIndex, sp20);
                temp = D_i8_800A2060[D_i8_800A2050 + 3];
                gSaveContext.ghostSave.record = sp20[temp];
                func_i2_800AA1C0(gCourseIndex, temp, &gSaveContext.ghostSave.data);
                break;
        }
    } else {
        switch (D_i8_800A2054) {
            case 0:
                Save_WriteGhostRecord(&gSaveContext.ghostSave);
                Save_WriteGhostData(&gSaveContext.ghostSave.data);
                break;
            case 1:
            case 2:
            case 3:
                temp = D_i8_800A2070[D_i8_800A2054 + 3];
                func_i2_800AA220(gCourseIndex, temp, 0);
                break;
        }
    }
}

Gfx* func_i8_8009E0F0(Gfx* gfx, s32 arg1, s32 arg2) {
    unk_8009E224* temp_v0 = &D_i8_8009E264[D_i8_800A2058];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return func_8070DEE0(gfx, temp_v0->texture, temp_v0->tlut, G_IM_FMT_CI, 1, arg1 + 10, arg2 + 10, temp_v0->width,
                         temp_v0->height, 3);
}
