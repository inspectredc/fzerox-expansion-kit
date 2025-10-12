#include "global.h"
#include "course_select.h"
#include "fzx_game.h"
#include "fzx_font.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_assets.h"
#include "src/overlays/ovl_i2/transition.h"
#include "assets/overlays/course_select/course_select.h"

s32 sCourseSelectCup;
s32 sLastCourseIndex;
s8 D_i5_8007C2A8[7];
s8 D_i5_8007C2AF;

UNUSED s32 D_i5_8007B080 = 0;
#include "src/assets/overlays/course_select/course_select/course_select.c"

s32 sCourseSelectState = COURSE_SELECT_CUP_SELECT;
UNUSED s32 D_i5_8007B9D0 = 0;
s8 gCupSelectOption = 0;
s8 sCourseSelectTrackNo = 0;
s8 D_i5_8007B9DC = 0;
s8 sSelectedGhostOption = 0;
s8 sUnlockedGhosts = 1;
s8 sStaffGhostTimeBeaten = 0;

s8 D_i5_8007B9EC[42] = { 0 };

UNUSED s32 D_i5_8007BA18 = 64;
UNUSED s32 D_i5_8007BA1C = 0;
UNUSED s32 D_i5_8007BA20 = 60;
UNUSED s32 D_i5_8007BA24 = 40;
UNUSED s32 D_i5_8007BA28 = 70;

unk_80077D50 sCupSelectJackCompTexInfo[] = { { 17, aCupSelectJackTex, TEX_WIDTH(aCupSelectJackTex),
                                               TEX_HEIGHT(aCupSelectJackTex), TEX_COMPRESSED_SIZE(aCupSelectJackTex) },
                                             { 0 } };
unk_80077D50 sCupSelectQueenCompTexInfo[] = { { 17, aCupSelectQueenTex, TEX_WIDTH(aCupSelectQueenTex),
                                                TEX_HEIGHT(aCupSelectQueenTex),
                                                TEX_COMPRESSED_SIZE(aCupSelectQueenTex) },
                                              { 0 } };
unk_80077D50 sCupSelectKingCompTexInfo[] = { { 17, aCupSelectKingTex, TEX_WIDTH(aCupSelectKingTex),
                                               TEX_HEIGHT(aCupSelectKingTex), TEX_COMPRESSED_SIZE(aCupSelectKingTex) },
                                             { 0 } };
unk_80077D50 sCupSelectJokerCompTexInfo[] = { { 17, aCupSelectJokerTex, TEX_WIDTH(aCupSelectJokerTex),
                                                TEX_HEIGHT(aCupSelectJokerTex),
                                                TEX_COMPRESSED_SIZE(aCupSelectJokerTex) },
                                              { 0 } };
unk_80077D50 sCupSelectXCompTexInfo[] = { { 17, aCupSelectXTex, TEX_WIDTH(aCupSelectXTex), TEX_HEIGHT(aCupSelectXTex),
                                            TEX_COMPRESSED_SIZE(aCupSelectXTex) },
                                          { 0 } };

unk_80077D50 sCupSelectEditCompTexInfo[] = { { 17, aCupSelectEditTex, TEX_WIDTH(aCupSelectEditTex),
                                               TEX_HEIGHT(aCupSelectEditTex), TEX_COMPRESSED_SIZE(aCupSelectEditTex) },
                                             { 0 } };

unk_80077D50 sCupSelectDD1CompTexInfo[] = { { 17, aCupSelectDD1Tex, TEX_WIDTH(aCupSelectDD1Tex),
                                              TEX_HEIGHT(aCupSelectDD1Tex), TEX_COMPRESSED_SIZE(aCupSelectDD1Tex) },
                                            { 0 } };

unk_80077D50 sCupSelectDD2CompTexInfo[] = { { 17, aCupSelectDD2Tex, TEX_WIDTH(aCupSelectDD2Tex),
                                              TEX_HEIGHT(aCupSelectDD2Tex), TEX_COMPRESSED_SIZE(aCupSelectDD2Tex) },
                                            { 0 } };

unk_80077D50 sCupSelectQuestionMarkCompTexInfo[] = {
    { 17, aCupSelectQuestionMarkTex, TEX_WIDTH(aCupSelectQuestionMarkTex), TEX_HEIGHT(aCupSelectQuestionMarkTex),
      TEX_COMPRESSED_SIZE(aCupSelectQuestionMarkTex) },
    { 0 }
};

unk_80077D50* sCupSelectCompTexInfos[] = {
    sCupSelectJackCompTexInfo,  sCupSelectQueenCompTexInfo, sCupSelectKingCompTexInfo,
    sCupSelectJokerCompTexInfo, sCupSelectXCompTexInfo,     sCupSelectEditCompTexInfo,
    sCupSelectDD1CompTexInfo,   sCupSelectDD2CompTexInfo,   sCupSelectQuestionMarkCompTexInfo,
};

unk_80077D50 sSelectCourseCompTexInfo[] = { { 4, aSelectCourseTex, TEX_WIDTH(aSelectCourseTex),
                                              TEX_HEIGHT(aSelectCourseTex), 0 } };
unk_80077D50 sRecordsCompTexInfo[] = { { 4, aRecordsTex, TEX_WIDTH(aRecordsTex), TEX_HEIGHT(aRecordsTex), 0 } };
static unk_80077D50 sOKCompTexInfo[] = { { 17, aOKTex, TEX_WIDTH(aOKTex), TEX_HEIGHT(aOKTex),
                                           TEX_COMPRESSED_SIZE(aOKTex) } };
unk_80077D50 sYellowArrowCompTexInfo[] = { { 17, aYellowArrowTex, TEX_WIDTH(aYellowArrowTex),
                                             TEX_HEIGHT(aYellowArrowTex), TEX_COMPRESSED_SIZE(aYellowArrowTex) } };
unk_80077D50 sOptionsFalconHelmetCompTexInfo[] = { { 17, aOptionsFalconHelmetTex, TEX_WIDTH(aOptionsFalconHelmetTex),
                                                     TEX_HEIGHT(aOptionsFalconHelmetTex),
                                                     TEX_COMPRESSED_SIZE(aOptionsFalconHelmetTex) } };

static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = {
    { 17, aTitleBackgroundMainTex, TEX_WIDTH(aTitleBackgroundMainTex), TEX_HEIGHT(aTitleBackgroundMainTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundMainTex) }
};
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = {
    { 17, aTitleBackgroundComicTex, TEX_WIDTH(aTitleBackgroundComicTex), TEX_HEIGHT(aTitleBackgroundComicTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundComicTex) }
};
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = {
    { 17, aTitleBackgroundFalconTex, TEX_WIDTH(aTitleBackgroundFalconTex), TEX_HEIGHT(aTitleBackgroundFalconTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundFalconTex) }
};

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

unk_80077D50 sCupCleared1CompTexInfo[] = { { 17, aCupCleared1Tex, TEX_WIDTH(aCupCleared1Tex),
                                             TEX_HEIGHT(aCupCleared1Tex), TEX_COMPRESSED_SIZE(aCupCleared1Tex) } };
unk_80077D50 sCupCleared2CompTexInfo[] = { { 17, aCupCleared2Tex, TEX_WIDTH(aCupCleared2Tex),
                                             TEX_HEIGHT(aCupCleared2Tex), TEX_COMPRESSED_SIZE(aCupCleared2Tex) } };
unk_80077D50 sCupCleared3CompTexInfo[] = { { 17, aCupCleared3Tex, TEX_WIDTH(aCupCleared3Tex),
                                             TEX_HEIGHT(aCupCleared3Tex), TEX_COMPRESSED_SIZE(aCupCleared3Tex) } };
unk_80077D50 sCupCleared4CompTexInfo[] = { { 17, aCupCleared4Tex, TEX_WIDTH(aCupCleared4Tex),
                                             TEX_HEIGHT(aCupCleared4Tex), TEX_COMPRESSED_SIZE(aCupCleared4Tex) } };

unk_80077D50* sCupClearedDifficultyCompTexInfos[] = {
    sCupCleared1CompTexInfo,
    sCupCleared2CompTexInfo,
    sCupCleared3CompTexInfo,
    sCupCleared4CompTexInfo,
};

unk_80077D50 sHasGhostMarkerCompTexInfo[] = { { 4, aHasGhostMarkerTex, TEX_WIDTH(aHasGhostMarkerTex),
                                                TEX_HEIGHT(aHasGhostMarkerTex), 0 } };
unk_80077D50 sStaffGhostBeatenCompTexInfo[] = { { 17, aStaffGhostBeatenTex, TEX_WIDTH(aStaffGhostBeatenTex),
                                                  TEX_HEIGHT(aStaffGhostBeatenTex),
                                                  TEX_COMPRESSED_SIZE(aStaffGhostBeatenTex) } };

unk_80077D50 sMenuWithGhostCompTexInfo[] = { { 4, aMenuWithGhostTex, TEX_WIDTH(aMenuWithGhostTex),
                                               TEX_HEIGHT(aMenuWithGhostTex), 0 } };
unk_80077D50 sMenuWithoutGhostCompTexInfo[] = { { 4, aMenuWithoutGhostTex, TEX_WIDTH(aMenuWithoutGhostTex),
                                                  TEX_HEIGHT(aMenuWithoutGhostTex), 0 } };
unk_80077D50 sMenuStaffGhostCompTexInfo[] = { { 4, aMenuStaffGhostTex, TEX_WIDTH(aMenuStaffGhostTex),
                                                TEX_HEIGHT(aMenuStaffGhostTex), 0 } };
unk_80077D50 sMenuCelebrityGhostCompTexInfo[] = { { 4, aMenuCelebrityGhostTex, TEX_WIDTH(aMenuCelebrityGhostTex),
                                                    TEX_HEIGHT(aMenuCelebrityGhostTex), 0 } };
unk_80077D50 sMenuChampGhostCompTexInfo[] = { { 4, aMenuChampGhostTex, TEX_WIDTH(aMenuChampGhostTex),
                                                TEX_HEIGHT(aMenuChampGhostTex), 0 } };

unk_80077D50* sTimeAttackGhostOptionCompTexInfos[] = {
    sMenuWithGhostCompTexInfo,      sMenuWithoutGhostCompTexInfo, sMenuStaffGhostCompTexInfo,
    sMenuCelebrityGhostCompTexInfo, sMenuChampGhostCompTexInfo,
};

// clang-format off
s32 sCourseSelectCupColors[] = {
    192, 64,  64,
    100, 150, 255,
    255, 255, 100,
    0,   255, 0,
    200, 90,  255,
    200, 90,  255,
    200, 90,  255
};
// clang-format on

extern s8 gSettingEverythingUnlocked;
extern s8 gUnlockableLevel;

void func_i5_80077D60(void) {
    s32 var_v0;

    var_v0 = gUnlockableLevel;
    if ((var_v0 >= 3) || (gSettingEverythingUnlocked != 0)) {
        var_v0 = 2;
    }

    if (var_v0 + 2 < gCupSelectOption) {
        gCupSelectOption = var_v0 + 2;
    }
}

s32 func_i5_80077DAC(s32 cupType) {
    s32 var_v0;

    var_v0 = gUnlockableLevel;

    if ((var_v0 >= 3) || (gSettingEverythingUnlocked != 0)) {
        var_v0 = 2;
    }
    if (var_v0 < cupType - 2) {
        cupType = 6;
    }
    return cupType;
}

extern s32 gCourseIndex;

void CourseSelect_UpdateUnlockedGhosts(void) {
    s32 staffTime;
    s32 timeRecord;

    // TODO: move to appropriate functions
    PRINTF("setup start %d\n");
    PRINTF("setup end cup:%d, crs:%d\n");
    PRINTF("ghost time %d:%d:%d\n");
    PRINTF("GHOET IRU\n");
    PRINTF("GHOET INAI\n");
    PRINTF("GHOET INAI2\n");
    PRINTF("setup end %d\n");
    PRINTF("");

    if (sLastCourseIndex < -1) {
        sLastCourseIndex++;
    } else if (sLastCourseIndex != gCourseIndex) {
        sStaffGhostTimeBeaten = false;
        staffTime = func_i2_800A9788(gCourseIndex);
        if (staffTime == -1) {
            sUnlockedGhosts = 1;
        } else {
            timeRecord = gCourseInfos[gCourseIndex].timeRecord[0];
            if (timeRecord < (staffTime * 115) / 100) {
                sUnlockedGhosts = 2;
            } else {
                sUnlockedGhosts = 1;
            }
            if (timeRecord < staffTime) {
                sStaffGhostTimeBeaten = true;
            }
        }
        sLastCourseIndex = gCourseIndex;
    }
}

const char* sTrackSubtitles[] = {
    "エイトロード",
    "ハイスピード",
    "パイプ",
    "スクリュー",
    "シリンダー",
    "ハイジャンプ",
    "ロールオーバー",
    "ジャンプジャンプ",
    "アップダウン",
    "テクニカル",
    "クイックターン",
    "ステップアップロード",
    "ジグザグジャンプ",
    "ウェーブロード",
    "ムーンサルト",
    "スリムライン",
    "ハーフパイプ",
    "クランククランク",
    "レインボーロード",
    "ミラーロード",
    "シリンダー&ハイジャンプ",
    "ウェーブパニック",
    "スネークロード",
    "ビッグハンド",
    "",
    "",
    "",
    "",
    "",
    "",
    "アウトサイドループ",
    "シリンダーループ",
    "ダイビング",
    "ジグザグクランク",
    "エックス",
    "ジャポン",
    "スリムハーフパイプ",
    "ストレートジャンプ",
    "トラップロード",
    "180ローリング",
    "スター",
    "ビッグフット",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
};

s8 sGhostOptionTypeMap[] = { 1, 0, 2, 3, 4 };

s8 D_i5_8007BDF0[] = {
    11, 10, 12, 0, 0, 11, 10, 10, 12, 0, 11, 11, 10, 12, 12, 0,  1,  0,
    2,  1,  0,  3, 2, 1,  3,  0,  0,  0, 11, 11, 10, 0,  12, 10, 12,
};

extern char* gCurrentTrackName;
extern char* gTrackNames[];

void func_i5_80077EEC(void) {
    gCurrentTrackName = gTrackNames[gCourseIndex];
}

extern s16 D_8076C7A8;
extern s32 D_8076CC88;
extern s32 D_8076CC8C;
extern s8 D_8079FB28[];
extern s32 gCurrentGhostType;
extern s32 gGameMode;
extern s32 gSelectedMode;
extern s32 sCourseSelectState;

void CourseSelect_Init(void) {
    s32 i;
    s32 j;
    s32 k;
    s8* sp20;
    bool var_a1;

    D_8076C7A8 = 3;
    sCourseSelectState = COURSE_SELECT_CUP_SELECT;
    sSelectedGhostOption = sGhostOptionTypeMap[gCurrentGhostType];
    sLastCourseIndex = -1;

    for (i = 0; i < 42; i++) {
        D_i5_8007B9EC[i] = 0;
    }

    sp20 = Arena_Allocate(ALLOC_FRONT, 4 * 30 * 7);
    Save_UpdateCupSave(sp20);

    for (i = 0; i < 2; i++) {
        var_a1 = false;
        for (j = 3; j >= 0; j--) {
            for (k = 0; k < 30; k++) {
                if (((s8*) sp20)[(j * 30 * 7) + (k * 7) + i + 5] != 0) {
                    var_a1 = true;
                    break;
                }
            }

            if (var_a1) {
                break;
            }
        }

        if (var_a1) {
            D_8079FB28[i] = j + 1;
        } else {
            D_8079FB28[i] = 0;
        }
    }
    D_i5_8007C2AF = -1;

    if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
        k = D_8076CC88;
    } else {
        k = D_8076CC8C;
    }
    if (k >= COURSE_X_1) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = 0;
        gCourseIndex = COURSE_X_1;
    } else {
        sCourseSelectTrackNo = k % 6;
        if (k >= COURSE_EDIT_1) {
            gCupSelectOption = (k / 6) + 6;
            if (gCupSelectOption >= 13) {
                gCupSelectOption = 10;
            }
        } else {
            gCupSelectOption = k / 6;
        }
        gCourseIndex = k;
    }
    CourseSelect_UpdateUnlockedGhosts();
    if (gCupSelectOption < 10) {
        func_i5_80077D60();
    }
    if ((gCupSelectOption == 4) &&
        ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
        gCupSelectOption = 3;
    }
    if (gCupSelectOption >= 10) {
        if (gCupSelectOption == 10) {
            sCourseSelectCup = 4;
        } else {
            sCourseSelectCup = gCupSelectOption - 6;
        }
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = 7;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }

    func_807160A0();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        i = 80;
        j = 17;
    } else {
        i = 112;
        j = 21;
    }
    Object_Init(OBJECT_COURSE_SELECT_HEADER, i, j, 4);
    Object_Init(OBJECT_COURSE_SELECT_OK, 0, 0, 10);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
    Object_Init(OBJECT_COURSE_SELECT_CUP_7, 128, 0, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_5, 128, 0, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_6, 128, 0, 6);
    if (((gSettingEverythingUnlocked != 0) || (gUnlockableLevel >= 2)) &&
        (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) && (gSelectedMode != MODE_TIME_ATTACK)) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_4, 0, -100, 6);
    }
    if ((gUnlockableLevel >= 1) || (gSettingEverythingUnlocked != 0)) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_3, 0, -100, 6);
    }
    Object_Init(OBJECT_COURSE_SELECT_CUP_2, 0, -100, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_1, 0, -100, 6);
    Object_Init(OBJECT_COURSE_SELECT_CUP_0, 0, -100, 6);
    if (gSelectedMode != MODE_GP_RACE) {
        Object_Init(OBJECT_COURSE_SELECT_ARROWS, 0, 0, 8);
    }
    Object_Init(OBJECT_COURSE_SELECT_NAME, 0, 0, 8);
    switch (gSelectedMode) {
        case MODE_TIME_ATTACK:
            if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
                Object_Init(OBJECT_COURSE_SELECT_GHOST_OPTION, 0, 0, 10);
            }
            /* fallthrough */
        case MODE_DEATH_RACE:
            Object_Init(OBJECT_COURSE_SELECT_GHOST_MARKER, 190, 160, 10);
            break;
    }
}

void NextCourseSelect_Init(void) {
    D_8076C7A8 = 3;
    sCourseSelectState = COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT;
    if (gCourseIndex >= COURSE_X_1) {
        gCupSelectOption = 4;
        sCourseSelectTrackNo = gCourseIndex % 6;
    } else {
        sCourseSelectTrackNo = gCourseIndex % 6;
        if (gCourseIndex >= COURSE_EDIT_1) {
            gCupSelectOption = (gCourseIndex / 6) + 6;
        } else {
            gCupSelectOption = gCourseIndex / 6;
        }
    }
    func_i5_80077EEC();
    if (gCupSelectOption >= 10) {
        if (gCupSelectOption == 10) {
            sCourseSelectCup = 4;
        } else {
            sCourseSelectCup = gCupSelectOption - 6;
        }
    } else if (gCupSelectOption == 4) {
        sCourseSelectCup = 7;
    } else {
        sCourseSelectCup = gCupSelectOption;
    }
    func_807160A0();
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_COURSE_SELECT_BACKGROUND, 0, 0, 2);
    Object_Init(OBJECT_COURSE_SELECT_MODEL, 0, 0, 8);
    if (gCupSelectOption >= 10) {
        Object_Init(OBJECT_COURSE_SELECT_CUP_5 + gCupSelectOption - 10, 0, -100, 6);
    } else {
        Object_Init(OBJECT_COURSE_SELECT_CUP_0 + gCupSelectOption, 0, -100, 6);
    }
    Object_Init(OBJECT_COURSE_SELECT_NAME, 0, 0, 8);
}

extern s16 D_8076C810;
extern s16 D_8076C814;
extern s32 D_8076CC88;
extern s32 D_8076CC8C;
extern s32 gTransitionState;
extern u16 gInputPressed;
extern s32 gCupType;
extern u16 gInputButtonPressed;
extern Player gPlayers[];
extern u8 gEditCupTrackNames[][9];

s32 CourseSelect_Update(void) {
    s32 originalCupSelectOption;
    bool sp110;
    s32 var_v1;
    s8 originalSelectedGhostOption;
    s32 i;
    s32 temp_lo;
    s32 j;
    CourseInfo* courseInfo;
    GhostRecord ghostRecords[3];
    bool var_v1_2;
    s32 unlockedGhost;

    if (Object_Get(OBJECT_COURSE_SELECT_CUP_5) != NULL) {
        sp110 = true;
    } else {
        sp110 = false;
    }

    func_80717294();
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT)) {
        CourseSelect_UpdateUnlockedGhosts();
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
            D_i5_8007B9DC = 1;
            originalCupSelectOption = gCupSelectOption;
            if (sp110) {
                var_v1 = gUnlockableLevel;
                if ((var_v1 >= 3) || (gSettingEverythingUnlocked != 0)) {
                    var_v1 = 2;
                }

                if ((var_v1 == 2) &&
                    ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
                    var_v1 = 1;
                }

                if (gInputPressed & BTN_DOWN) {
                    if (gCupSelectOption < 10) {
                        if (D_i5_8007C2AF >= 10) {
                            gCupSelectOption = D_i5_8007C2AF;
                        } else {
                            gCupSelectOption = D_i5_8007BDF0[var_v1 * 5 + gCupSelectOption];
                        }
                        D_i5_8007C2AF = originalCupSelectOption;
                    }
                } else if (gInputPressed & BTN_UP) {
                    if (gCupSelectOption >= 10) {
                        if ((D_i5_8007C2AF < 10) && (D_i5_8007C2AF >= 0)) {
                            gCupSelectOption = D_i5_8007C2AF;
                        } else {
                            // FAKE!
                            gCupSelectOption = D_i5_8007BDF0[(var_v1 & 0xFFFFFFFF) * 3 + gCupSelectOption + 6];
                        }
                        D_i5_8007C2AF = originalCupSelectOption;
                    }
                }
            }

            if (gCupSelectOption < 10) {
                if ((gInputPressed & BTN_LEFT) && (gCupSelectOption > 0)) {
                    gCupSelectOption--;
                }
                if ((gInputPressed & BTN_RIGHT) && (gCupSelectOption < 4)) {
                    gCupSelectOption++;
                }
                func_i5_80077D60();
                if ((gCupSelectOption == 4) &&
                    ((gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) || (gSelectedMode == MODE_TIME_ATTACK))) {
                    gCupSelectOption = 3;
                }
            } else {
                if (gInputPressed & BTN_LEFT) {
                    gCupSelectOption = D_i5_8007BDF0[gCupSelectOption + 18];
                }
                if (gInputPressed & BTN_RIGHT) {
                    gCupSelectOption = D_i5_8007BDF0[gCupSelectOption + 22];
                }
            }
            if (gCupSelectOption >= 10) {
                if (gCupSelectOption == 10) {
                    sCourseSelectCup = 4;
                } else {
                    sCourseSelectCup = gCupSelectOption - 6;
                }
            } else if (gCupSelectOption == 4) {
                sCourseSelectCup = 7;
            } else {
                sCourseSelectCup = gCupSelectOption;
            }
            if (originalCupSelectOption != gCupSelectOption) {
                if (gInputPressed & (BTN_LEFT | BTN_RIGHT)) {
                    D_i5_8007C2AF = -1;
                }
                sCourseSelectTrackNo = 0;
                if (sCourseSelectCup < 7) {
                    CourseModel_Init(sCourseSelectCup);
                }
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gCupSelectOption < 10) {
                gCupType = gCupSelectOption;
            } else {
                gCupType = gCupSelectOption - 5;
            }
            if (gCupSelectOption >= 10) {
                gCourseIndex = (sCourseSelectCup * 6) + sCourseSelectTrackNo;
            } else if (gCupSelectOption == 4) {
                gCourseIndex = COURSE_X_1;
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                Audio_TriggerSystemSE(NA_SE_16);
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    D_8076CC88 = gCourseIndex;
                    sCourseSelectState = COURSE_SELECT_START_EXIT;
                } else {
                    D_8076CC8C = gCourseIndex;
                    sCourseSelectState = COURSE_SELECT_EXIT_RECORDS;
                    Audio_RomBgmReady(BGM_SELECT);
                    D_8076C814 = 10;
                }
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_33);
                if (gCupSelectOption == 4) {
                    sCourseSelectTrackNo = 0;
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                } else if (gSelectedMode == MODE_GP_RACE) {
                    if (gCupSelectOption >= 10) {
                        gCourseIndex = sCourseSelectCup * 6;
                    } else {
                        gCourseIndex = gCupSelectOption * 6;
                    }
                    sCourseSelectTrackNo = 0;
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                } else {
                    sCourseSelectState = COURSE_SELECT_CHOOSE_COURSE;
                    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupSelectOption < 10)) {
                        temp_lo = gCupSelectOption * 6;

                        if (D_i5_8007C2A8[temp_lo / 6] == 0) {
                            for (i = temp_lo; i < temp_lo + 6; i++) {
                                courseInfo = &gCourseInfos[i];
                                func_i2_800A9CE0(i, ghostRecords);
                                D_i5_8007B9EC[i] = 0;
                                for (j = 0; j < 3; j++) {
                                    if (courseInfo->encodedCourseIndex == 0) {
                                        break;
                                    }
                                    if (courseInfo->encodedCourseIndex == ghostRecords[j].encodedCourseIndex) {
                                        D_i5_8007B9EC[i] |= 1;
                                        break;
                                    }
                                }
                            }
                        }
                        D_i5_8007C2A8[temp_lo / 6] = 1;
                    } else {
                        sLastCourseIndex = -3;
                    }
                }
                OBJECT_LEFT(Object_Get(OBJECT_COURSE_SELECT_MODEL)) = 400 - (sCourseSelectTrackNo * 0x500);
            }
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
            D_i5_8007B9DC = 1;
            var_v1_2 = false;
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
                (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
                var_v1_2 = true;
            }
            if ((gSelectedMode == MODE_TIME_ATTACK) && (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) && !var_v1_2) {
                unlockedGhost = sUnlockedGhosts;
                originalSelectedGhostOption = sSelectedGhostOption;
                if ((gInputPressed & BTN_UP) && (sSelectedGhostOption > 0)) {
                    sSelectedGhostOption--;
                }
                if ((gInputPressed & BTN_DOWN) && (sSelectedGhostOption < unlockedGhost)) {
                    sSelectedGhostOption++;
                }
                if (originalSelectedGhostOption != sSelectedGhostOption) {
                    Audio_TriggerSystemSE(NA_SE_30);
                }
                if (unlockedGhost < sSelectedGhostOption) {
                    sSelectedGhostOption = 0;
                }
                gCurrentGhostType = sGhostOptionTypeMap[sSelectedGhostOption];
            }

            if ((gInputPressed & BTN_LEFT) && (sCourseSelectTrackNo > 0)) {
                sCourseSelectTrackNo--;
                gPlayers[0].unk_18 = 1;
                LEFT_ARROW_ROTATION_CHANGE(Object_Get(OBJECT_COURSE_SELECT_ARROWS)) += 0x200;
                Audio_TriggerSystemSE(NA_SE_30);
            }

            if ((gInputPressed & BTN_RIGHT) && (sCourseSelectTrackNo < 5)) {
                sCourseSelectTrackNo++;
                gPlayers[0].unk_18 = 1;
                RIGHT_ARROW_ROTATION_CHANGE(Object_Get(OBJECT_COURSE_SELECT_ARROWS)) += 0x200;
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gCupSelectOption >= 10) {
                gCourseIndex = (sCourseSelectCup * 6) + sCourseSelectTrackNo;
            } else {
                gCourseIndex = (gCupSelectOption * 6) + sCourseSelectTrackNo;
            }
            if (gInputButtonPressed & BTN_B) {
                sCourseSelectState = COURSE_SELECT_CUP_SELECT;
                Audio_TriggerSystemSE(NA_SE_16);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
                    (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
                    Audio_TriggerSystemSE(NA_SE_32);
                } else {
                    Audio_TriggerSystemSE(NA_SE_33);
                    sCourseSelectState = COURSE_SELECT_AWAIT_OK;
                    D_i5_8007B9DC = 0;
                }
            }
            break;
        case COURSE_SELECT_AWAIT_OK:
            if (gInputButtonPressed & BTN_B) {
                if ((gSelectedMode == MODE_GP_RACE) || (gCupSelectOption == 4)) {
                    sCourseSelectState = COURSE_SELECT_CUP_SELECT;
                } else {
                    sCourseSelectState = COURSE_SELECT_CHOOSE_COURSE;
                }
                Audio_TriggerSystemSE(NA_SE_16);
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_62);
                sCourseSelectState = COURSE_SELECT_CONTINUE;
                if (gGameMode == GAMEMODE_FLX_COURSE_SELECT) {
                    D_8076CC88 = gCourseIndex;
                    return GAMEMODE_FLX_MACHINE_SELECT;
                }
                D_8076CC8C = gCourseIndex;
                return GAMEMODE_RECORDS;
            }
            break;
        case COURSE_SELECT_START_EXIT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                Audio_TriggerSystemSE(NA_SE_33);
                sCourseSelectState = COURSE_SELECT_CUP_SELECT;
            }
            break;
        case COURSE_SELECT_EXIT:
            if (D_8076C810 == 0) {
                D_8076C814 = 12;
            }
            break;
        default:
            break;
    }

    func_i5_80077EEC();
    func_8070D220();
    return gGameMode;
}

s32 NextCourseSelect_Update(void) {
    func_80717294();
    if (gTransitionState != TRANSITION_INACTIVE) {
        return gGameMode;
    }
    Controller_SetGlobalInputs(&gSharedController);
    D_i5_8007B9DC = 1;
    switch (sCourseSelectState) {
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                sCourseSelectState = COURSE_SELECT_NEXT_COURSE_CONTINUE;
                Audio_TriggerSystemSE(NA_SE_62);
                return GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS;
            }
            break;
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
        default:
            break;
    }

    func_8070D220();
    return gGameMode;
}

Gfx* CourseSelect_Draw(Gfx* gfx) {
    return Object_UpdateAndDrawAll(gfx);
}

extern s8 D_8076CC94;

void CourseSelect_BackgroundInit(Object* backgroundObj) {
    size_t size;
    unk_80077D50* sp20;

    OBJECT_STATE(backgroundObj) = D_8076CC94;
    sp20 = sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)];
    func_i2_800AE17C(sp20, 0, true);

    if (OBJECT_STATE(backgroundObj) == 0) {
        OBJECT_LEFT(backgroundObj) = 8;
    }
    if (gGameMode == GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        func_i2_800AE17C(sOptionsFalconHelmetCompTexInfo, 0, true);
        if (OBJECT_STATE(backgroundObj) == 0) {
            size = 0x23A00;
        } else {
            size = 0x25800;
        }

        func_8070A078(func_i2_800AEA90(sp20->unk_04), size, 135, 135, 255);
    }
}

void CourseSelect_ModelInit(void) {
    func_i5_80077080();
    if (sCourseSelectCup < 7) {
        CourseModel_Init(sCourseSelectCup);
    }
}

void CourseSelect_CupInit(Object* cupObj) {
    s32 cupType;
    s32 i;

    cupType = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (cupType == JOKER_CUP || cupType == X_CUP) {
        cupType = func_i5_80077DAC(cupType);
    }

    if (cupType >= DD_1_CUP) {
        func_i2_800AE578(sCupSelectCompTexInfos[cupType], false);
    } else {
        func_i2_800AE17C(sCupSelectCompTexInfos[cupType], 0, false);
    }

    for (i = 0; i < 4; i++) {
        func_i2_800AE17C(sCupClearedDifficultyCompTexInfos[i], 0, true);
    }

    if (D_8076C810 == 33) {
        OBJECT_COUNTER(cupObj) = 12;
    }
    OBJECT_LEFT(cupObj) = 0x80;
    OBJECT_TOP(cupObj) = 0x55;
}

void CourseSelect_HeaderInit(Object* headerObj) {
    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        func_i2_800AE17C(sSelectCourseCompTexInfo, 0, true);
        OBJECT_COUNTER(headerObj) = 12;
    } else {
        func_i2_800AE17C(sRecordsCompTexInfo, 0, true);
    }
}

void CourseSelect_OkInit(Object* okObj) {
    func_i2_800AE17C(sOKCompTexInfo, 0, true);
    OBJECT_LEFT(okObj) = 50;
}

void CourseSelect_ArrowsInit(Object* arrowsObj) {
    func_i2_800AE17C(sYellowArrowCompTexInfo, 0, true);
    LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
    RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
}

void CourseSelect_GhostMarkerInit(Object* ghostMarkerObj) {
    GhostInfo ghostInfo;
    s32 pad[50];
    s32 i;

    for (i = 0; i < 7; i++) {
        D_i5_8007C2A8[i] = 0;
    }

    GHOST_MARKER_COURSE(ghostMarkerObj) = -1;
    if ((Save_LoadGhostInfo(&ghostInfo) == 0) && (ghostInfo.encodedCourseIndex != 0)) {
        GHOST_MARKER_COURSE(ghostMarkerObj) = ghostInfo.courseIndex;
    }
    func_i2_800AE17C(sHasGhostMarkerCompTexInfo, 0, true);
}

void CourseSelect_GhostOptionInit(Object* ghostOptionObj) {
    s32 i;

    func_i2_800AE17C(sStaffGhostBeatenCompTexInfo, 0, true);

    for (i = 0; i < 5; i++) {
        func_i2_800AE17C(sTimeAttackGhostOptionCompTexInfos[i], 0, true);
    }

    OBJECT_LEFT(ghostOptionObj) = 150;
}

Gfx* CourseSelect_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        gDPSetPrimColor(gfx++, 0, 0, 75, 75, 75, 180);
        gfx = func_i2_800AF584(gfx, sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)],
                               OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), 1, 0, 0, 1.0f, 1.0f, true);
    } else {
        gfx = func_i2_800AF584(gfx, sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)],
                               OBJECT_LEFT(backgroundObj), OBJECT_TOP(backgroundObj), 0, 0, 0, 1.0f, 1.0f, true);
        gfx = func_i2_800AF584(gfx, sOptionsFalconHelmetCompTexInfo, 53, 4, 2, 1, 0, 1.0f, 1.0f, true);
        gfx = func_i2_800AF584(gfx, sOptionsFalconHelmetCompTexInfo, 203, 4, 0, 0, 0, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* CourseSelect_ModelDraw(Gfx* gfx, Object* modelObj) {

    switch (sCourseSelectState) {
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
            if (sCourseSelectCup < 7) {
                gfx = func_i5_800774F0(gfx);
            }
            break;
        case COURSE_SELECT_CUP_SELECT:
        default:
            break;
    }
    return gfx;
}

extern u32 gGameFrameCount;
extern s8 gCupNumDifficultiesCleared[];

Gfx* CourseSelect_CupDraw(Gfx* gfx, Object* cupObj) {
    s32 spA4;
    s32 i;
    s32 alpha;
    s32 cupOption;
    s32 cupDifficultiesCleared;
    s32 var_v0;
    s32 yOffset;
    s32 greyness;

    spA4 = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    if (gCupSelectOption >= 10) {
        cupOption = gCupSelectOption - 5;
    } else {
        cupOption = gCupSelectOption;
    }
    if (cupOption == spA4) {
        if ((sCourseSelectState == COURSE_SELECT_CUP_SELECT) || (sCourseSelectState == COURSE_SELECT_EXIT_RECORDS)) {
            greyness = gGameFrameCount;
            greyness %= 30U;
            if (greyness >= 15) {
                greyness = 30 - greyness;
            }
            gDPSetPrimColor(gfx++, 0, 0, 255 - (greyness * 5), 255 - (greyness * 5), 255 - (greyness * 5), 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
    } else {
        if (cupOption >= 5) {
            if (gSelectedMode == 0) {
                var_v0 = 0x31;
            } else {
                var_v0 = 0x2D;
            }

            alpha = ((OBJECT_TOP(cupObj) - var_v0) * 300) / (85 - var_v0);
            if (alpha > 255) {
                alpha = 255;
                if (1) {}
            }
        } else {
            alpha = 255;
        }
        gDPSetPrimColor(gfx++, 0, 0, 100, 100, 100, alpha);
    }

    switch (sCourseSelectState) {
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            OBJECT_COUNTER(cupObj)++;
            if (OBJECT_COUNTER(cupObj) > 12) {
                sCourseSelectState = COURSE_SELECT_EXIT;
                OBJECT_COUNTER(cupObj) = 12;
            }
            break;
        default:
            if (OBJECT_COUNTER(cupObj) > 0) {
                OBJECT_COUNTER(cupObj)--;
            }
            break;
    }

    if (OBJECT_COUNTER(cupObj) < 0) {
        OBJECT_COUNTER(cupObj) = 0;
    }

    cupDifficultiesCleared = gCupNumDifficultiesCleared[spA4];
    yOffset = (SQ(OBJECT_COUNTER(cupObj)) * 3) / 2;

    switch (spA4) {
        case JOKER_CUP:
        case X_CUP:
            spA4 = func_i5_80077DAC(spA4);
            break;
    }

    gfx = func_i2_800AF584(gfx, sCupSelectCompTexInfos[spA4], OBJECT_LEFT(cupObj), OBJECT_TOP(cupObj) + yOffset, 1, 0,
                           0, 1.0f, 1.0f, false);

    if ((gSelectedMode == MODE_GP_RACE) && (spA4 <= JOKER_CUP)) {
        alpha = ((OBJECT_TOP(cupObj) - 49) * 255) / 36;
        if (cupOption == spA4) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = func_i2_800AF584(gfx, sCupClearedDifficultyCompTexInfos[i],
                                   OBJECT_LEFT(cupObj) + (i * 16) + ((12 - i * 8) / 2),
                                   (OBJECT_TOP(cupObj) + yOffset) - 12, 1, 0, 0, 1.0f, 1.0f, true);
        }
    }

    cupDifficultiesCleared = D_8079FB28[spA4 - DD_1_CUP];
    if ((gSelectedMode == MODE_GP_RACE) && (spA4 >= DD_1_CUP)) {
        alpha = ((OBJECT_TOP(cupObj) - 49) * 255) / 121;
        if (cupOption == spA4) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, alpha);
        }

        for (i = 0; i < cupDifficultiesCleared; i++) {
            gfx = func_i2_800AF584(gfx, sCupClearedDifficultyCompTexInfos[i],
                                   OBJECT_LEFT(cupObj) + (i * 16) + ((12 - i * 8) / 2),
                                   (OBJECT_TOP(cupObj) + yOffset) - 9, 1, 0, 0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

Gfx* CourseSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    s32 yOffset;

    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    if (gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) {
        switch (sCourseSelectState) {
            case COURSE_SELECT_START_EXIT:
            case COURSE_SELECT_EXIT:
                OBJECT_COUNTER(headerObj)++;
                if (OBJECT_COUNTER(headerObj) > 12) {
                    sCourseSelectState = COURSE_SELECT_EXIT;
                    OBJECT_COUNTER(headerObj) = 12;
                }
                break;
            default:
                if (OBJECT_COUNTER(headerObj) > 0) {
                    OBJECT_COUNTER(headerObj)--;
                }
                break;
        }
        if (OBJECT_COUNTER(headerObj) < 0) {
            OBJECT_COUNTER(headerObj) = 0;
        }
        yOffset = (SQ(OBJECT_COUNTER(headerObj)) * 3) / 2;

        gfx = func_i2_800AF584(gfx, sSelectCourseCompTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj) + yOffset,
                               0, 0, 0, 1.0f, 1.0f, true);
    } else {
        gfx = func_i2_800AF584(gfx, sRecordsCompTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj), 0, 0, 0, 1.0f,
                               1.0f, true);
    }
    return gfx;
}

Gfx* CourseSelect_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8070D4A8(gfx, 0);
    return func_i2_800AF584(gfx, sOKCompTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0, 1, 0, 0, 1.0f,
                            1.0f, true);
}

Gfx* CourseSelect_ArrowsDraw(Gfx* gfx, Object* arrowsObj) {
    f32 temp_fv0 = (SIN(LEFT_ARROW_ROTATION(arrowsObj)) + 1.0) / 2;
    f32 temp_fa1 = (SIN(RIGHT_ARROW_ROTATION(arrowsObj)) + 1.0) / 2;

    gfx = func_i2_800AF584(gfx, sYellowArrowCompTexInfo, LEFT_ARROW_LEFT(arrowsObj) + 0x2B,
                           (((1.0 - temp_fv0) * 16.0) + 112.0), 3, 0, 0, 1.0f, temp_fv0, true);
    return func_i2_800AF584(gfx, sYellowArrowCompTexInfo, RIGHT_ARROW_LEFT(arrowsObj) + 0xF5,
                            (((1.0 - temp_fa1) * 16.0) + 112.0), 5, 0, 0, 1.0f, temp_fa1, true);
}

Gfx* CourseSelect_NameDraw(Gfx* gfx) {
    char cupTrackNoStr[4];
    s32 cupTrackNoWidth;
    s32 trackNameWidth;
    s32* cupColors;
    s32 greyFactor;

    greyFactor = 1;
    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
        (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
        greyFactor = 2;
        switch (sCourseSelectState) {
            case COURSE_SELECT_CUP_SELECT:
            case COURSE_SELECT_EXIT_RECORDS:
            case COURSE_SELECT_START_EXIT:
            case COURSE_SELECT_EXIT:
            case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
            case COURSE_SELECT_NEXT_COURSE_CONTINUE:
                break;
            default:
                if ((gGameFrameCount / 15) % 4) {
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth("センタク デキマセン", 4, 0) / 2), 0x84,
                                          "センタク デキマセン", 0, 4, 0);
                }
                break;
        }
    }

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        default:
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        case COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT:
        case COURSE_SELECT_NEXT_COURSE_CONTINUE:
            Font_IntToString(sCourseSelectTrackNo + 1, cupTrackNoStr);
            cupTrackNoStr[1] = ':';
            cupTrackNoStr[2] = ' ';
            cupTrackNoStr[3] = '\0';
            cupTrackNoWidth = Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0);
            if (sCourseSelectCup == 7) {
                trackNameWidth = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
                gfx = Font_DrawString(
                    gfx, (-(trackNameWidth / 2) - (Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0) / 2)) + 160, 200,
                    cupTrackNoStr, 0, FONT_SET_3, 0);
                gfx = Font_DrawString(
                    gfx, ((cupTrackNoWidth / 2) - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0) / 2)) + 160,
                    200, gCurrentTrackName, 0, FONT_SET_3, 0);
            } else {
                trackNameWidth = Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0);
                cupColors = &sCourseSelectCupColors[sCourseSelectCup * 3];
                gDPSetPrimColor(gfx++, 0, 0, cupColors[0], cupColors[1], cupColors[2], 255);
                gfx = Font_DrawString(
                    gfx, (-(trackNameWidth / 2) - (Font_GetStringWidth(cupTrackNoStr, FONT_SET_3, 0) / 2)) + 160, 200,
                    cupTrackNoStr, 0, FONT_SET_3, 0);
                gDPSetPrimColor(gfx++, 0, 0, 255 / greyFactor, 255 / greyFactor, 255 / greyFactor, 255);
                gfx = Font_DrawString(
                    gfx, ((cupTrackNoWidth / 2) - (Font_GetStringWidth(gCurrentTrackName, FONT_SET_3, 0) / 2)) + 160,
                    200, gCurrentTrackName, 0, FONT_SET_3, 0);
                gfx = Font_DrawString(
                    gfx,
                    160 - (Font_GetStringWidth(sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], FONT_SET_4,
                                               0) /
                           2),
                    210, sTrackSubtitles[sCourseSelectCup * 6 + sCourseSelectTrackNo], 0, FONT_SET_4, 0);
            }
            break;
    }
    return gfx;
}

Gfx* CourseSelect_GhostMarkerDraw(Gfx* gfx, Object* ghostMarkerObj) {
    s32 i;
    s32 cupCourseIndex;
    s32 left;

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            if (gCupSelectOption >= 10) {
                cupCourseIndex = sCourseSelectCup * 6;
            } else {
                cupCourseIndex = gCupSelectOption * 6;
            }

            for (i = 0; i < 6; i++) {
                left = OBJECT_LEFT(ghostMarkerObj) + i * SCREEN_WIDTH + GHOST_MARKER_OFFSET(ghostMarkerObj);
                if (left >= -30 && left <= SCREEN_WIDTH &&
                    ((D_i5_8007B9EC[cupCourseIndex + i] & 1) ||
                     (GHOST_MARKER_COURSE(ghostMarkerObj) == cupCourseIndex + i))) {
                    gfx = func_i2_800AF584(gfx, sHasGhostMarkerCompTexInfo, left, OBJECT_TOP(ghostMarkerObj), 0, 0, 0,
                                           1.0f, 1.0f, true);
                }
            }
            break;
    }

    return gfx;
}

Gfx* CourseSelect_GhostOptionDraw(Gfx* gfx, Object* ghostOptionObj) {
    s32 i;
    s32 numUnlockedGhosts;

    if ((gSelectedMode == MODE_TIME_ATTACK) && (gCupType == EDIT_CUP) &&
        (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0')) {
        return gfx;
    }

    numUnlockedGhosts = sUnlockedGhosts + 1;
    for (i = 0; i < numUnlockedGhosts; i++) {
        if (i == sSelectedGhostOption) {
            switch (sCourseSelectState) {
                case COURSE_SELECT_AWAIT_OK:
                case COURSE_SELECT_CONTINUE:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
                default:
                    gfx = func_8070D4A8(gfx, 0);
                    break;
            }
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        }
        gfx = func_i2_800AF584(gfx, sTimeAttackGhostOptionCompTexInfos[i], OBJECT_LEFT(ghostOptionObj) + 195,
                               i * 20 + 0x2D, 0, 0, 0, 1.0f, 1.0f, true);

        if ((i == 2) && sStaffGhostTimeBeaten) {
            gfx = func_i2_800AF584(gfx, sStaffGhostBeatenCompTexInfo, OBJECT_LEFT(ghostOptionObj) + 265, i * 20 + 0x2D,
                                   0, 0, 0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

void CourseSelect_ModelUpdate(Object* modelObj) {
    s32 temp_a1;
    bool var_v1;

    if (D_i5_8007B074 == 0) {
        OBJECT_COUNTER(modelObj) = 1;
    }
    var_v1 = false;
    switch (sCourseSelectState) {
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            var_v1 = true;
            break;
        case COURSE_SELECT_CUP_SELECT:
            if (gCupSelectOption < 10) {
                break;
            }
            /* fallthrough */
        default:
            if (OBJECT_COUNTER(modelObj) == 0) {
                if ((func_80742510() == 0) || (gCupSelectOption < 10)) {
                    func_i5_800770B4();
                }
                var_v1 = true;
            }
            break;
    }

    if (!var_v1 &&
        (((sCourseSelectState != COURSE_SELECT_CUP_SELECT) && (sCourseSelectState != COURSE_SELECT_EXIT_RECORDS)) ||
         (gCupSelectOption < 4))) {
        func_i5_800770B4();
    }
    temp_a1 = -(sCourseSelectTrackNo * 0x500);
    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        OBJECT_LEFT(modelObj) = temp_a1;
    } else {
        Object_LerpPosXToClampedTargetMaxStep(modelObj, temp_a1, 192);
    }
    func_i5_80077B8C(OBJECT_LEFT(modelObj));
}

void CourseSelect_CupUpdate(Object* cupObj) {
    s32 var_v1;
    s32 var_a1;
    s32 var_v0;
    s32 state;

    if (gGameMode == GAMEMODE_FLX_GP_RACE_NEXT_COURSE) {
        OBJECT_LEFT(cupObj) = 0x80;
        OBJECT_TOP(cupObj) = 0x31;
        return;
    }

    var_v1 = cupObj->cmdId - OBJECT_COURSE_SELECT_CUP_0;
    state = OBJECT_STATE(cupObj);
    switch (state) {
        case 0:
            if (var_v1 >= 5) {
                if (OBJECT_TOP(cupObj) < 85) {
                    Object_LerpPosYToTarget(cupObj, 85);
                } else {
                    OBJECT_STATE(cupObj) = 1;
                }
            } else if (OBJECT_TOP(cupObj) > 170) {
                Object_LerpPosYToTarget(cupObj, 170);
            } else {
                OBJECT_STATE(cupObj) = 1;
            }
            if ((sCourseSelectState != COURSE_SELECT_CUP_SELECT) &&
                (sCourseSelectState != COURSE_SELECT_EXIT_RECORDS)) {
                OBJECT_STATE(cupObj) = 1;
            }
            break;
        case 1:
        case 2:
        case 3:
            if ((var_v1 == gCupSelectOption) || ((gCupSelectOption >= 10) && (var_v1 == gCupSelectOption - 5))) {
                cupObj->priority = 7;
            } else {
                cupObj->priority = 6;
            }

            switch (sCourseSelectState) {
                case COURSE_SELECT_CUP_SELECT:
                case COURSE_SELECT_EXIT_RECORDS:
                case COURSE_SELECT_START_EXIT:
                case COURSE_SELECT_EXIT:
                    Object_LerpPosYToTarget(cupObj, (var_v1 < 5) ? 85 : 170);

                    if (OBJECT_STATE(cupObj) == 2) {
                        OBJECT_STATE(cupObj) = 3;
                    }
                    break;
                case COURSE_SELECT_CHOOSE_COURSE:
                case COURSE_SELECT_AWAIT_OK:
                case COURSE_SELECT_CONTINUE:
                default:
                    if (gSelectedMode == MODE_GP_RACE) {
                        Object_LerpPosYToTarget(cupObj, 0x31);
                    } else {
                        Object_LerpPosYToTarget(cupObj, 0x2D);
                    }
                    OBJECT_STATE(cupObj) = 2;
                    break;
            }
            if (OBJECT_STATE(cupObj) == 2) {
                var_a1 = 0x80;
            } else if (var_v1 >= 5) {
                switch (var_v1) {
                    case 5:
                        var_a1 = 0x80;
                        break;
                    case 6:
                        var_a1 = 0x36;
                        break;
                    case 7:
                        var_a1 = 0xCA;
                        break;
                }
            } else {
                var_v0 = gUnlockableLevel;
                if (gSettingEverythingUnlocked != 0) {
                    var_v0 = 2;
                }
                switch (var_v0) {
                    case 0:
                        if (var_v1 >= 3) {
                            var_v1 = 2;
                        }
                        var_a1 = (((s32) ((var_v1 << 7) + 0x80) / 2) + (var_v1 * 0xA)) - 0xA;
                        break;
                    default:
                    case 2:
                    case 3:
                        if ((gGameMode != GAMEMODE_FLX_RECORDS_COURSE_SELECT) && (gSelectedMode != MODE_TIME_ATTACK)) {
                            var_a1 = ((s32) (var_v1 << 7) / 2) + (var_v1 * -8) + 0x10;
                            break;
                        }
                    /* fallthrough */
                    case 1:
                        if (var_v1 >= 4) {
                            var_v1 = 3;
                        }
                        var_a1 = (((s32) ((var_v1 * 0xC) + 0x12E) / 2) + (var_v1 << 6)) - 0x80;
                        break;
                }
            }

            if (OBJECT_COUNTER(cupObj) == 0xB) {
                OBJECT_LEFT(cupObj) = var_a1;
            } else if (OBJECT_STATE(cupObj) >= 2) {
                Object_LerpPosXToClampedTargetMaxStep(cupObj, var_a1, 0x80);
            } else {
                Object_LerpPosXToTarget(cupObj, var_a1, 0x10 / OBJECT_STATE(cupObj));
            }
            break;
    }
}

void CourseSelect_OkUpdate(Object* okObj) {
    switch (sCourseSelectState) {
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 50, 192);
            break;
    }
}

void CourseSelect_ArrowsUpdate(Object* arrowsObj) {

    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            arrowsObj->shouldDraw = false;
            LEFT_ARROW_LEFT(arrowsObj) = -100;
            RIGHT_ARROW_LEFT(arrowsObj) = 100;
            LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
            RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 0x80;
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        default:
            if (LEFT_ARROW_ROTATION_CHANGE(arrowsObj) > 640) {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 640;
            }
            if (LEFT_ARROW_ROTATION_CHANGE(arrowsObj) > 128) {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) -= 16;
            } else {
                LEFT_ARROW_ROTATION_CHANGE(arrowsObj) = 128;
            }
            LEFT_ARROW_ROTATION(arrowsObj) += LEFT_ARROW_ROTATION_CHANGE(arrowsObj);

            if (RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) > 640) {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 640;
            }
            if (RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) > 128) {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) -= 16;
            } else {
                RIGHT_ARROW_ROTATION_CHANGE(arrowsObj) = 128;
            }
            RIGHT_ARROW_ROTATION(arrowsObj) += RIGHT_ARROW_ROTATION_CHANGE(arrowsObj);

            arrowsObj->shouldDraw = true;
            if ((sCourseSelectTrackNo == 0) || (sCourseSelectState == COURSE_SELECT_AWAIT_OK) ||
                (sCourseSelectState == COURSE_SELECT_CONTINUE)) {
                Object_LerpPosXToClampedTargetMaxStep(arrowsObj, -100, 192);
            } else {
                Object_LerpPosXToClampedTargetMaxStep(arrowsObj, 0, 192);
            }
            if ((sCourseSelectTrackNo == 5) || (sCourseSelectState == COURSE_SELECT_AWAIT_OK) ||
                (sCourseSelectState == COURSE_SELECT_CONTINUE)) {
                Object_LerpPosYToClampedTarget(arrowsObj, 100);
            } else {
                Object_LerpPosYToClampedTarget(arrowsObj, 0);
            }
            break;
    }
}

void CourseSelect_GhostMarkerUpdate(Object* ghostMarkerObj) {
    GHOST_MARKER_OFFSET(ghostMarkerObj) = OBJECT_LEFT(Object_Get(OBJECT_COURSE_SELECT_MODEL)) >> 2;
}

void CourseSelect_GhostOptionUpdate(Object* ghostOptionObj) {
    switch (sCourseSelectState) {
        case COURSE_SELECT_CUP_SELECT:
        case COURSE_SELECT_EXIT_RECORDS:
        case COURSE_SELECT_START_EXIT:
        case COURSE_SELECT_EXIT:
            Object_LerpPosXToClampedTargetMaxStep(ghostOptionObj, 150, 192);
            break;
        case COURSE_SELECT_CHOOSE_COURSE:
        case COURSE_SELECT_AWAIT_OK:
        case COURSE_SELECT_CONTINUE:
        default:
            Object_LerpPosXToClampedTargetMaxStep(ghostOptionObj, 0, 192);
            break;
    }
}
