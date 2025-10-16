#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_bordered_box.h"
#include "fzx_assets.h"
#include "records.h"
#include "src/overlays/ovl_i2/transition.h"
#include "assets/overlays/records/records_assets.h"

s32 sRecordsState;
s32 sUnlockedCourseCount;
s16 sRecordsMenuIndexValid[5];
BorderedBoxWidget* sRecordsMenuBox;
BorderedBoxWidget* sRecordsClearConfirmBox;
BorderedBoxWidget* sRecordsState3Box;
BorderedBoxWidget* sRecordsGhostCopyBox;
BorderedBoxWidget* sRecordsCopyWhereBox;
BorderedBoxWidget* sRecordsCopyToDiskBox;
BorderedBoxWidget* sRecordsCopyingInfoBox;
s16 sRecordsHighlightedMenuIndex;
s16 sRecordsToCourseSelectMenuIndex;
s16 sRecordsCopyGhostMenuIndex;
s16 sRecordsYesNoIndex;
s16 sRecordsClearType;
s16 sGhostMarkerState;
s16 sGhostMarkerTopAlpha;
s16 sGhostMarkerBottomAlpha;
s16 sRecordsStopStateUpdate;
s16 sRecordsRetireCleanupTimer;
GhostMarkerRenderInfo* sGhostMarkerRenderInfo;
GhostMarkerRenderInfo sGhostMarkerRenderInfos[2];
UNUSED s32 D_i8_800A2038[6];
s16 sRecordsCopyFromGhostTypeIndex;
s16 sRecordsCopyWhereMenuIndex;
s16 sRecordsCopyToGhostTypeIndex;
s16 sGhostCopiedTimer;
s16 sGhostCopyingState;
s32 sGhostCourseRecordTimes[4];
s32 sSortedDiskGhostRecordTimeIndices[4];
s32 sSortedDiskGhostRecordTimeIndices2[4];
s32 sDiskGhostCourseRecordTimes[4];

s32 sRecordsCourseIndex = 0;

RecordsMenuInfo sRecordsMenuInfo[] = {
    { RECORDS_MENU_CHANGE_COURSE,
      { aMenuChangeCourseTex, TEX_WIDTH(aMenuChangeCourseTex), TEX_HEIGHT(aMenuChangeCourseTex) },
      NULL },
    { RECORDS_MENU_QUIT, { aMenuQuitTex, TEX_WIDTH(aMenuQuitTex), TEX_HEIGHT(aMenuQuitTex) }, NULL },
    { RECORDS_MENU_CLEAR_RECORD,
      { aMenuClearRecordTex, TEX_WIDTH(aMenuClearRecordTex), TEX_HEIGHT(aMenuClearRecordTex) },
      NULL },
    { RECORDS_MENU_CLEAR_GHOST,
      { aMenuClearGhostTex, TEX_WIDTH(aMenuClearGhostTex), TEX_HEIGHT(aMenuClearGhostTex) },
      NULL },
    { RECORDS_MENU_COPY_GHOST,
      { aMenuCopyGhostTex, TEX_WIDTH(aMenuCopyGhostTex), TEX_HEIGHT(aMenuCopyGhostTex) },
      aMenuCopyGhostPalette },
};

TextureInfo sRecordsClearTextureInfos[] = {
    { aMenuEraseCourseSavedData1Tex, TEX_WIDTH(aMenuEraseCourseSavedData1Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData1Tex) },
    { aMenuEraseCourseSavedData2Tex, TEX_WIDTH(aMenuEraseCourseSavedData2Tex),
      TEX_HEIGHT(aMenuEraseCourseSavedData2Tex) },
};

TextureInfo sRecordsYesNoTextureInfos[] = {
    { aMenuNoTex, TEX_WIDTH(aMenuNoTex), TEX_HEIGHT(aMenuNoTex) },
    { aMenuYesTex, TEX_WIDTH(aMenuYesTex), TEX_HEIGHT(aMenuYesTex) },
};

TexturePaletteInfo sRecordsGhostTypeTextureInfos[] = {
    { aRecordsCassetteGhostTex, aRecordsCassetteGhostPalette, TEX_WIDTH(aRecordsCassetteGhostTex),
      TEX_HEIGHT(aRecordsCassetteGhostTex) },
    { aRecordsDiskGhost1Tex, aRecordsDiskGhost1Palette, TEX_WIDTH(aRecordsDiskGhost1Tex),
      TEX_HEIGHT(aRecordsDiskGhost1Tex) },
    { aRecordsDiskGhost2Tex, aRecordsDiskGhost2Palette, TEX_WIDTH(aRecordsDiskGhost2Tex),
      TEX_HEIGHT(aRecordsDiskGhost2Tex) },
    { aRecordsDiskGhost3Tex, aRecordsDiskGhost3Palette, TEX_WIDTH(aRecordsDiskGhost3Tex),
      TEX_HEIGHT(aRecordsDiskGhost3Tex) },
};

TextureInfo sRecordsCopyLocationTextureInfos[] = {
    { aMenuToGamePakTex, TEX_WIDTH(aMenuToGamePakTex), TEX_HEIGHT(aMenuToGamePakTex) },
    { aMenuToDiskTex, TEX_WIDTH(aMenuToDiskTex), TEX_HEIGHT(aMenuToDiskTex) },
};

TexturePaletteInfo sRecordsGhostCopyingInfoTextureInfos[] = {
    { aRecordsGhostCopiedTex, aRecordsGhostCopiedPalette, TEX_WIDTH(aRecordsGhostCopiedTex),
      TEX_HEIGHT(aRecordsGhostCopiedTex) },
    { aRecordsInsertDiskToCopyToTex, aRecordsInsertDiskToCopyToPalette, TEX_WIDTH(aRecordsInsertDiskToCopyToTex),
      TEX_HEIGHT(aRecordsInsertDiskToCopyToTex) },
};

UNUSED s32 D_i8_8009E27C = 0;

UNUSED const char* sStaffGhostNames[] = {
    "tadashi sugiyama", "takaya imamura", "yasuyuki oyagi",    "hideki konno",      "masanao arimoto",
    "taro bando",       "keizo ohta",     "masahiro kawano",   "daisuke tsujimura", "shiro mouri",
    "hiroki sotoike",   "hajime wakai",   "tsutomu kaneshige",
};

#include "src/assets/overlays/records/records_assets/records_assets.c"

s32 sRecordsMoveDirection = 0;

s32 sExpansionKitCourses[] = {
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
    bool changingCourseIndex;

    D_8076C7A8 = D_i2_800BF040 = 3;
    gGamePaused = false;
    gDifficulty = MASTER;
    gRacers[0].character = CAPTAIN_FALCON;
    changingCourseIndex = true;

    while (changingCourseIndex) {
        Course_Init();
        if (sRecordsMoveDirection != RECORDS_FROM_MENU) {
            if ((gCourseIndex >= COURSE_EDIT_1) && (gCourseIndex <= COURSE_EDIT_6)) {
                if (gEditCupTrackNames[gCourseIndex - COURSE_EDIT_1][0] == '\0') {
                    if (sRecordsMoveDirection == RECORDS_MOVE_RIGHT) {
                        if (gCourseIndex == COURSE_EDIT_6) {
                            gCourseIndex = COURSE_MUTE_CITY_4;
                            changingCourseIndex = false;
                            Course_Init();
                        } else {
                            gCourseIndex++;
                        }
                    } else { // RECORDS_MOVE_LEFT
                        if (gCourseIndex == COURSE_EDIT_1) {
                            gCourseIndex = COURSE_BIG_BLUE_3;
                            changingCourseIndex = false;
                            Course_Init();
                        } else {
                            gCourseIndex--;
                        }
                    }
                } else {
                    changingCourseIndex = false;
                }
            } else {
                changingCourseIndex = false;
            }
            if (!changingCourseIndex) {
                sRecordsMoveDirection = RECORDS_FROM_MENU;
            }
        } else {
            changingCourseIndex = false;
        }
    }

    func_i3_80040158();
    func_8071D48C();
    func_807160A0();
    func_8070F0B0(COURSE_CONTEXT()->courseData.venue, COURSE_CONTEXT()->courseData.skybox);
    func_i3_800617A0();
    Course_LandminesViewInteractDataInit();
    Course_JumpsViewInteractDataInit();
    Course_DecorationsViewInteractDataInit();
    Course_EffectsViewInteractDataInit(false);
    Records_InitData();
}

extern s8 gUnlockableLevel;
extern s8 gSettingEverythingUnlocked;

void Records_InitData(void) {
    s32 i;
    RecordsMenuInfo* recordsOption;

    sRecordsCourseIndex = gCourseIndex;
    if ((gUnlockableLevel == 0) && !gSettingEverythingUnlocked) {
        sUnlockedCourseCount = 18;
    } else {
        sUnlockedCourseCount = 24;
    }
    sRecordsRetireCleanupTimer = -1;
    for (i = 0; i < 4; i++) {
        sGhostCourseRecordTimes[i] = sDiskGhostCourseRecordTimes[i] = -1;
    }

    for (i = 0; i < 5; i++) {
        switch (sRecordsMenuInfo[i].menuOption) {
            case RECORDS_MENU_CLEAR_RECORD:
                if (Records_CourseHasNoRecords(sRecordsCourseIndex)) {
                    sRecordsMenuIndexValid[i] = false;
                } else {
                    sRecordsMenuIndexValid[i] = true;
                }
                break;
            case RECORDS_MENU_CLEAR_GHOST:
                if (Records_CourseHasGhost(sRecordsCourseIndex)) {
                    sRecordsMenuIndexValid[i] = true;
                    sGhostMarkerState = GHOST_MARKER_SHOWN;
                    sGhostMarkerTopAlpha = sGhostMarkerBottomAlpha = 255;
                } else {
                    sRecordsMenuIndexValid[i] = false;
                    sGhostMarkerState = GHOST_MARKER_NONE;
                }
                break;
            case RECORDS_MENU_CHANGE_COURSE:
                sRecordsToCourseSelectMenuIndex = i;
                sRecordsMenuIndexValid[i] = true;
                break;
            case RECORDS_MENU_COPY_GHOST:
                sRecordsCopyGhostMenuIndex = i;
                if ((sGhostMarkerState != GHOST_MARKER_NONE) &&
                    !((gCourseIndex >= COURSE_EDIT_1) && (gCourseIndex <= COURSE_EDIT_6))) {
                    sRecordsMenuIndexValid[i] = true;
                } else {
                    sRecordsMenuIndexValid[i] = false;
                }
                break;
            default:
                sRecordsMenuIndexValid[i] = true;
                break;
        }
    }
    sRecordsState = RECORDS_STATE_VIEW_RECORDS;
    sRecordsStopStateUpdate = false;
    func_i2_800AE7C4(aMenuTextTLUT, TEX_SIZE(aMenuTextTLUT, sizeof(u16)), 0, 0, false);

    recordsOption = sRecordsMenuInfo;
    for (i = 0; i < 5; i++, recordsOption++) {
        if (recordsOption->tlut == NULL) {
            func_i2_800AE7C4(recordsOption->textureInfo.texture,
                             recordsOption->textureInfo.width * recordsOption->textureInfo.height * sizeof(u8), 0, 1,
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
    func_i2_800AE7C4(aMenuToGamePakTex, TEX_SIZE(aMenuToGamePakTex, sizeof(u8)), 0, 1, false);
    func_i2_800AE7C4(aMenuToDiskTex, TEX_SIZE(aMenuToDiskTex, sizeof(u8)), 0, 1, false);
    func_i3_80064F20();
    BorderedBox_CleanWidget(&sRecordsMenuBox);
    BorderedBox_CleanWidget(&sRecordsClearConfirmBox);
    BorderedBox_CleanWidget(&sRecordsGhostCopyBox);
    BorderedBox_CleanWidget(&sRecordsCopyWhereBox);
    BorderedBox_CleanWidget(&sRecordsCopyToDiskBox);
    BorderedBox_CleanWidget(&sRecordsCopyingInfoBox);
    BorderedBox_CleanWidget(&sRecordsState3Box);
    BorderedBox_ClearAll();
}

bool Records_CourseHasNoRecords(s32 courseIndex) {
    s32 i;
    bool hasNoRecords = true;

    for (i = 0; i < 5; i++) {
        if (gCourseInfos[courseIndex].timeRecord[i] != MAX_TIMER) {
            hasNoRecords = false;
            break;
        }
    }

    return hasNoRecords;
}

bool Records_CourseHasGhost(s32 courseIndex) {
    CourseInfo* courseInfo = &gCourseInfos[courseIndex];
    s32 i;
    bool hasGhost = false;
    s32 pad[4];
    GhostInfo ghostInfo;
    GhostRecord ghostRecords[3];

    Save_LoadGhostInfo(&ghostInfo);

    if (ghostInfo.encodedCourseIndex == courseInfo->encodedCourseIndex) {
        hasGhost = true;
    }

    if (!hasGhost) {
        DDSave_LoadCourseGhostRecords(courseIndex, ghostRecords);
        for (i = 0; i < 3; i++) {
            if (ghostRecords[i].encodedCourseIndex == courseInfo->encodedCourseIndex) {
                sGhostCourseRecordTimes[i + 1] = ghostRecords[i].raceTime;
                hasGhost = true;
            }
        }
    }

    return hasGhost;
}

void Records_LoadGhostRaceTimes(s32* raceTimes, bool loadCassetteGhost) {
    s32 i;
    CourseInfo* courseInfo = &gCourseInfos[gCourseIndex];
    GhostInfo ghostInfo;
    GhostRecord ghostRecords[3];
    s32 courseIndex;

    if (loadCassetteGhost) {
        Save_LoadGhostInfo(&ghostInfo);
        if (ghostInfo.encodedCourseIndex == courseInfo->encodedCourseIndex) {
            *raceTimes = ghostInfo.raceTime;
        } else {
            *raceTimes = -1;
        }
    }
    raceTimes++;

    DDSave_LoadCourseGhostRecords(gCourseIndex, ghostRecords);

    for (i = 0; i < 3; i++, raceTimes++) {
        if (courseInfo->encodedCourseIndex == ghostRecords[i].encodedCourseIndex) {
            *raceTimes = ghostRecords[i].raceTime;
        } else {
            *raceTimes = -1;
        }
    }
}

extern s16 gMenuChangeMode;
extern s32 gLastRecordsCourseIndex;
extern s32 D_8079A35C;

s32 Records_Update(void) {
    s32 updateState;
    s32 gameMode;
    bool reloadRecords;
    bool stopStateUpdate;

    Controller_SetGlobalInputs(&gSharedController);
    sGhostMarkerRenderInfo = &sGhostMarkerRenderInfos[D_8079A35C];
    func_8070D220();
    func_80726554();
    func_80717294();
    func_i3_80061C2C();
    func_800B94D8();
    func_8070304C();
    if (sGhostMarkerState != GHOST_MARKER_NONE) {
        Records_UpdateGhostMarker();
    }
    func_i3_80065204();
    BorderedBox_Update();
    gameMode = GAMEMODE_RECORDS;
    reloadRecords = false;
    if (!sRecordsStopStateUpdate) {
        switch (sRecordsState) {
            case RECORDS_STATE_VIEW_RECORDS:
                updateState = Records_ViewRecordsUpdate();
                if (updateState == 1) {
                    reloadRecords = true;
                } else if (updateState == 2) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                }
                if (updateState != 0) {
                    sRecordsStopStateUpdate = true;
                }
                break;
            case RECORDS_STATE_RECORDS_MENU:
                updateState = Records_MenuUpdate();
                if (updateState == 1) {
                    gameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
                } else if (updateState == 2) {
                    gameMode = GAMEMODE_FLX_MAIN_MENU;
                }
                if (updateState != 0) {
                    sRecordsStopStateUpdate = true;
                }
                break;
            case RECORDS_STATE_CONFIRM_CLEAR:
                Records_ClearConfirmUpdate();
                break;
            case RECORDS_STATE_COPY_GHOST_MENU:
                Records_CopyGhostMenuUpdate();
                break;
            case RECORDS_STATE_COPY_WHERE_MENU:
                Records_CopyWhereMenuUpdate();
                break;
            case RECORDS_STATE_COPY_TO_DISK_MENU:
                Records_CopyToDiskMenuUpdate();
                break;
            case RECORDS_STATE_SHOW_COPYING_INFO:
                Records_CopyingStateUpdate();
                break;
            case RECORDS_STATE_3:
                Records_State3Update();
                break;
        }
    }

    switch (sRecordsRetireCleanupTimer) {
        case -1:
            if (gRacers[0].stateFlags & RACER_STATE_RETIRED) {
                sRecordsRetireCleanupTimer = 60;
            }
            break;
        case 0:
            sRecordsRetireCleanupTimer = -1;
            func_8071D48C();
            func_807160A0();
            break;
        default:
            sRecordsRetireCleanupTimer--;
            break;
    }

    if (reloadRecords) {
        gLastRecordsCourseIndex = gCourseIndex;
        gMenuChangeMode = MENU_CHANGE_CHANGE_RECORD_COURSE;
    }
    stopStateUpdate = sRecordsStopStateUpdate;
    if ((gameMode == GAMEMODE_FLX_MAIN_MENU) && stopStateUpdate) {
        Audio_RomBgmReady(BGM_SELECT);
    }
    return gameMode;
}

extern s32 gTransitionState;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

s32 Records_ViewRecordsUpdate(void) {
    s32 i;
    s32 sp30;
    s32 lastCourseIndex;

    if (gTransitionState != TRANSITION_INACTIVE) {
        return 0;
    }
    if (BorderedBox_GetInfo(sRecordsMenuBox, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }
    if (BorderedBox_GetInfo(sRecordsGhostCopyBox, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }
    if (BorderedBox_GetInfo(sRecordsState3Box, IS_BORDERED_BOX_ACTIVE)) {
        return 0;
    }

    lastCourseIndex = gCourseIndex;
    if (gInputPressed & BTN_RIGHT) {
        sRecordsMoveDirection = RECORDS_MOVE_RIGHT;
        if (gCourseIndex == COURSE_BIG_FOOT) {
            gCourseIndex = COURSE_MUTE_CITY;
        } else {
            if (gCourseIndex >= sUnlockedCourseCount - 1) {
                for (i = 0; i < 18; i++) {
                    if (gCourseIndex == sExpansionKitCourses[i]) {
                        break;
                    }
                }
                if (i != 18) {
                    gCourseIndex = sExpansionKitCourses[i + 1];
                } else {
                    gCourseIndex = COURSE_SILENCE_3;
                }
            } else {
                gCourseIndex++;
            }
        }
        Transition_SetArgument(TRANSITION_TYPE_WIPE, WIPE_DIRECTION_LEFT);
    } else if (gInputPressed & BTN_LEFT) {
        sRecordsMoveDirection = RECORDS_MOVE_LEFT;
        if (gCourseIndex == COURSE_MUTE_CITY) {
            gCourseIndex = COURSE_BIG_FOOT;
        } else {
            if (gCourseIndex >= sUnlockedCourseCount) {
                for (i = 0; i < 18; i++) {
                    if (gCourseIndex == sExpansionKitCourses[i]) {
                        break;
                    }
                }
                if (i != 0) {
                    gCourseIndex = sExpansionKitCourses[i - 1];
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
            sRecordsMenuBox =
                BorderedBox_Init(0, 108, 50, 104, 120, 10, GPACK_RGBA5551(0, 255, 0, 1), Records_MenuDraw);
            if (sRecordsMenuBox != NULL) {
                sRecordsState = RECORDS_STATE_RECORDS_MENU;
                sRecordsHighlightedMenuIndex = 0;
                Audio_TriggerSystemSE(NA_SE_33);
                func_i3_80067118(false);
            }
        } else if (gInputButtonPressed & BTN_B) {
            sp30 = 2;
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
    return sp30;
}

s32 Records_MenuUpdate(void) {
    s32 i;
    bool successfulSelection;
    s32 sp2C;
    s32 lastMenuIndex;
    s32 j;
    s32 clearBoxTop;
    s32 ghostIndex;
    s32 ghostIndexTemp;
    bool swapIndices;

    if (!BorderedBox_GetInfo(sRecordsMenuBox, IS_BORDERED_BOX_OPENED)) {
        return 0;
    }
    sp2C = 0;
    lastMenuIndex = sRecordsHighlightedMenuIndex;
    // clang-format off
    if (gInputPressed & BTN_UP) {
        if (--sRecordsHighlightedMenuIndex < 0) { sRecordsHighlightedMenuIndex = 4; }

        while (!sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex]) {
            if (--sRecordsHighlightedMenuIndex < 0) { sRecordsHighlightedMenuIndex = 4; }
        }
    } else if (gInputPressed & BTN_DOWN) {
        if (++sRecordsHighlightedMenuIndex > 4) { sRecordsHighlightedMenuIndex = 0; }

        while (!sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex]) {
            if (++sRecordsHighlightedMenuIndex > 4) { sRecordsHighlightedMenuIndex = 0; }
        }
    }
    // clang-format on
    if (lastMenuIndex != sRecordsHighlightedMenuIndex) {
        Audio_TriggerSystemSE(NA_SE_30);
    }
    if (gInputButtonPressed & (BTN_A | BTN_START)) {
        successfulSelection = false;

        switch (sRecordsMenuInfo[sRecordsHighlightedMenuIndex].menuOption) {
            case RECORDS_MENU_CHANGE_COURSE:
                successfulSelection = true;
                sp2C = 1;
                break;
            case RECORDS_MENU_QUIT:
                successfulSelection = true;
                sp2C = 2;
                break;
            case RECORDS_MENU_CLEAR_RECORD:
            case RECORDS_MENU_CLEAR_GHOST:
                if (sRecordsMenuInfo[sRecordsHighlightedMenuIndex].menuOption == RECORDS_MENU_CLEAR_RECORD) {
                    sRecordsClearType = RECORDS_CLEAR_RECORDS;
                    clearBoxTop = 120;
                } else { // RECORDS_MENU_CLEAR_GHOST
                    sRecordsClearType = RECORDS_CLEAR_GHOST;
                    clearBoxTop = 142;
                }

                sRecordsClearConfirmBox = BorderedBox_Init(1, 120, clearBoxTop, 148, 80, 20,
                                                           GPACK_RGBA5551(255, 0, 0, 1), Records_DrawClearConfirm);

                successfulSelection = false;
                if (sRecordsClearConfirmBox != NULL) {
                    successfulSelection = true;
                    sRecordsYesNoIndex = 0;
                    sRecordsState = RECORDS_STATE_CONFIRM_CLEAR;
                }
                break;
            case RECORDS_MENU_COPY_GHOST:
                sRecordsGhostCopyBox =
                    BorderedBox_Init(3, 40, 46, 168, 122, 30, GPACK_RGBA5551(0, 0, 255, 1), Records_DrawGhostCopyMenu);

                successfulSelection = false;
                if (sRecordsGhostCopyBox != NULL) {
                    successfulSelection = true;
                    sRecordsState = RECORDS_STATE_COPY_GHOST_MENU;
                    Records_LoadGhostRaceTimes(sGhostCourseRecordTimes, true);
                    for (i = 0; i < 3; i++) {
                        sSortedDiskGhostRecordTimeIndices[i] = i;
                    }

                    for (i = 0; i < 2; i++) {
                        for (j = i + 1; j < 3; j++) {
                            swapIndices = false;

                            if (sGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices[i] + 1] == -1) {
                                if (sGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices[j] + 1] != -1) {
                                    swapIndices = true;
                                }
                            } else if (sGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices[j] + 1] != -1) {
                                if (sGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices[j] + 1] <
                                    sGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices[i] + 1]) {
                                    swapIndices = true;
                                }
                            }
                            if (swapIndices) {
                                ghostIndexTemp = sSortedDiskGhostRecordTimeIndices[i];
                                sSortedDiskGhostRecordTimeIndices[i] = sSortedDiskGhostRecordTimeIndices[j];
                                sSortedDiskGhostRecordTimeIndices[j] = ghostIndexTemp;
                            }
                        }
                    }

                    for (i = 0; i < 4; i++) {

                        if (i == RECORDS_GHOST_CASSETTE) {
                            ghostIndex = i;
                        } else {
                            ghostIndex = sSortedDiskGhostRecordTimeIndices[i - 1] + 1;
                        }
                        if (sGhostCourseRecordTimes[ghostIndex] != -1) {
                            break;
                        }
                    }
                    if (i != 4) {
                        sRecordsCopyFromGhostTypeIndex = i;
                    } else {
                        sRecordsCopyFromGhostTypeIndex = -1;
                    }
                }
                break;
        }

        if (successfulSelection) {
            Audio_TriggerSystemSE(NA_SE_33);
        }
    } else if (gInputButtonPressed & BTN_B) {
        sRecordsState = RECORDS_STATE_VIEW_RECORDS;
        func_i3_80067118(true);
        BorderedBox_StartClose(sRecordsMenuBox);
        Audio_TriggerSystemSE(NA_SE_16);
    }
    return sp2C;
}

void Records_ClearConfirmUpdate(void) {
    s32 lastYesNoIndex;
    bool selectionMade;

    if (BorderedBox_GetInfo(sRecordsClearConfirmBox, IS_BORDERED_BOX_OPENED)) {
        lastYesNoIndex = sRecordsYesNoIndex;
        if (gInputPressed & BTN_LEFT) {
            sRecordsYesNoIndex--;
            if (sRecordsYesNoIndex < RECORDS_CLEAR_NO) {
                sRecordsYesNoIndex = RECORDS_CLEAR_YES;
            }
        } else if (gInputPressed & BTN_RIGHT) {
            sRecordsYesNoIndex++;
            if (sRecordsYesNoIndex > RECORDS_CLEAR_YES) {
                sRecordsYesNoIndex = RECORDS_CLEAR_NO;
            }
        }
        if (lastYesNoIndex != sRecordsYesNoIndex) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        selectionMade = false;
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            selectionMade = true;
            if (sRecordsYesNoIndex == RECORDS_CLEAR_NO) {
                Audio_TriggerSystemSE(NA_SE_16);
            } else {
                if (sRecordsClearType == RECORDS_CLEAR_RECORDS) {
                    if ((gCourseIndex >= COURSE_MUTE_CITY) && (gCourseIndex <= COURSE_BIG_HAND)) {
                        func_i2_800A7660(gCourseIndex);
                    } else {
                        DDSave_EraseDiskCourseRecord(gCourseIndex);
                    }
                } else if (sRecordsClearType == RECORDS_CLEAR_GHOST) {
                    Save_InitGhost(gCourseIndex);
                    DDSave_EraseDiskGhostSave(gCourseIndex);
                    sRecordsMenuIndexValid[sRecordsCopyGhostMenuIndex] = false;
                    sGhostMarkerState = GHOST_MARKER_FADE_OUT;
                }
                sRecordsMenuIndexValid[sRecordsHighlightedMenuIndex] = false;
                sRecordsHighlightedMenuIndex = sRecordsToCourseSelectMenuIndex;
                Audio_TriggerSystemSE(NA_SE_5);
            }
        } else if (gInputButtonPressed & BTN_B) {
            selectionMade = true;
            Audio_TriggerSystemSE(NA_SE_16);
        }
        if (selectionMade) {
            sRecordsState = RECORDS_STATE_RECORDS_MENU;
            BorderedBox_StartClose(sRecordsClearConfirmBox);
        }
    }
}

void Records_State3Update(void) {
    if (BorderedBox_GetInfo(sRecordsState3Box, IS_BORDERED_BOX_OPENED) && (gInputButtonPressed & BTN_B)) {
        sRecordsState = RECORDS_STATE_VIEW_RECORDS;
        func_i3_80067118(true);
        BorderedBox_StartClose(sRecordsState3Box);
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
    gfx = Course_FeaturesDraw(gfx, 0);
    gfx = func_i3_80065560(gfx, sRecordsCourseIndex);
    if (sGhostMarkerState != GHOST_MARKER_NONE) {
        gfx = Records_DrawGhostMarker(gfx);
    }
    return BorderedBox_Draw(gfx);
}

void Records_UpdateGhostMarker(void) {
    Vtx* vtx;

    switch (sGhostMarkerState) {
        case GHOST_MARKER_SHOWN:
            break;
        case GHOST_MARKER_FADE_OUT:
            if (sGhostMarkerBottomAlpha > 0) {
                sGhostMarkerBottomAlpha -= 10;
                if (sGhostMarkerBottomAlpha < 0) {
                    sGhostMarkerBottomAlpha = 0;
                }
            }
            if (sGhostMarkerBottomAlpha == 0) {
                sGhostMarkerTopAlpha -= 10;
                if (sGhostMarkerTopAlpha < 0) {
                    sGhostMarkerTopAlpha = 0;
                }
            }
            if ((sGhostMarkerBottomAlpha == 0) && (sGhostMarkerTopAlpha == 0)) {
                sGhostMarkerState = GHOST_MARKER_NONE;
                return;
            }
            break;
    }

    Matrix_SetOrtho(&sGhostMarkerRenderInfo->mtx, NULL, 1.0f, 0.0f, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, 0.0f, -100.0f,
                    100.0f);

    vtx = sGhostMarkerRenderInfo->vtx;

    SET_VTX(vtx, 236, 60, 0, -16, -16, 255, 255, 255, sGhostMarkerTopAlpha);
    vtx++;
    SET_VTX(vtx, 236 + TEX_WIDTH(aHasGhostMarkerTex) - 1, 60, 0, 0x400, 0, 255, 255, 255, sGhostMarkerTopAlpha);
    vtx++;
    SET_VTX(vtx, 236, 60 + TEX_HEIGHT(aHasGhostMarkerTex) - 1, 0, 0, 0x200, 255, 255, 255, sGhostMarkerBottomAlpha);
    vtx++;
    SET_VTX(vtx, 236 + TEX_WIDTH(aHasGhostMarkerTex) - 1, 60 + TEX_HEIGHT(aHasGhostMarkerTex) - 1, 0, 0x400, 0x200, 255,
            255, 255, sGhostMarkerBottomAlpha);
    vtx++;
}

extern Mtx D_2000000[];

Gfx* Records_DrawGhostMarker(Gfx* gfx) {

    gfx = func_806F6360(gfx, 0);
    gSPDisplayList(gfx++, D_8014810);
    gDPSetCombineLERP(gfx++, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, SHADE, 0);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    gSPMatrix(gfx++, &sGhostMarkerRenderInfo->mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPVertex(gfx++, sGhostMarkerRenderInfo->vtx, 4, 0);

    gDPLoadTextureBlock_4b(gfx++, func_i2_800AEA90(aHasGhostMarkerTex), G_IM_FMT_I, TEX_WIDTH(aHasGhostMarkerTex),
                           TEX_HEIGHT(aHasGhostMarkerTex), 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSP2Triangles(gfx++, 0, 3, 1, 0, 0, 2, 3, 0);

    return gfx;
}

Gfx* Records_MenuDraw(Gfx* gfx, s32 left, s32 top) {
    s32 boxCenteringOffset;
    s32 i;
    TextureInfo* textureInfo;
    TexturePtr tlut;
    TexturePtr texture;
    RecordsMenuInfo* recordsOption;

    gSPDisplayList(gfx++, D_8014940);

    recordsOption = sRecordsMenuInfo;
    for (i = 0; i < 5; i++, recordsOption++) {

        gDPPipeSync(gfx++);

        if (i != sRecordsHighlightedMenuIndex) {
            if (sRecordsMenuIndexValid[i]) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }

        textureInfo = &recordsOption->textureInfo;
        boxCenteringOffset = ((104 - textureInfo->width) / 2) - 20;
        if (recordsOption->tlut == NULL) {
            texture = func_i2_800AEA90(textureInfo->texture);
            tlut = func_i2_800AEA90(aMenuTextTLUT);
        } else {
            texture = textureInfo->texture;
            tlut = recordsOption->tlut;
        }

        gfx = func_8070DEE0(gfx, texture, tlut, G_IM_FMT_CI, 1, left + boxCenteringOffset + 20, top + 10 + i * 20,
                            textureInfo->width, textureInfo->height, 3);
    }

    return gfx;
}

Gfx* Records_DrawClearConfirm(Gfx* gfx, s32 left, s32 top) {
    TextureInfo* textureInfo;
    s32 boxCenteringOffset;
    s32 pad;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 0, 255);

    textureInfo = &sRecordsClearTextureInfos[sRecordsClearType];

    gfx = func_8070DEE0(gfx, func_i2_800AEA90(textureInfo->texture), func_i2_800AEA90(aMenuTextTLUT), G_IM_FMT_CI, 1,
                        left + 12, top + 10, textureInfo->width, textureInfo->height, 3);

    gDPPipeSync(gfx++);
    gfx = func_8070D4A8(gfx, 0);
    gfx = func_8070DEE0(gfx, func_i2_800AEA90(aMenuLeftArrowTex), NULL, G_IM_FMT_CI, 1, left + 24, top + 50, 16, 16, 0);
    gfx =
        func_8070DEE0(gfx, func_i2_800AEA90(aMenuRightArrowTex), NULL, G_IM_FMT_CI, 1, left + 99, top + 50, 16, 16, 0);

    textureInfo = &sRecordsYesNoTextureInfos[sRecordsYesNoIndex];
    boxCenteringOffset = (59 - textureInfo->width) / 2;
    return func_8070DEE0(gfx, func_i2_800AEA90(textureInfo->texture), NULL, G_IM_FMT_CI, 1,
                         left + boxCenteringOffset + 42, top + 50, textureInfo->width, textureInfo->height, 0);
}

void func_i8_8009CE5C(void) {
}

void Records_CopyGhostMenuUpdate(void) {
    s32 lastGhostTypeIndex;
    s32 ghostIndex;

    if ((BorderedBox_GetInfo(sRecordsGhostCopyBox, IS_BORDERED_BOX_OPENED)) &&
        (!BorderedBox_GetInfo(sRecordsCopyWhereBox, IS_BORDERED_BOX_ACTIVE))) {
        lastGhostTypeIndex = sRecordsCopyFromGhostTypeIndex;
        if (sRecordsCopyFromGhostTypeIndex == -1) {
            if (gInputButtonPressed & BTN_B) {
                sRecordsState = RECORDS_STATE_RECORDS_MENU;
                BorderedBox_StartClose(sRecordsGhostCopyBox);
                Audio_TriggerSystemSE(NA_SE_16);
            }
        } else {
            if (gInputPressed & BTN_UP) {
                do {
                    sRecordsCopyFromGhostTypeIndex--;
                    if (sRecordsCopyFromGhostTypeIndex < RECORDS_GHOST_CASSETTE) {
                        sRecordsCopyFromGhostTypeIndex = RECORDS_GHOST_DISK_3;
                    }
                    if (sRecordsCopyFromGhostTypeIndex == RECORDS_GHOST_CASSETTE) {
                        ghostIndex = sRecordsCopyFromGhostTypeIndex;
                    } else {
                        ghostIndex = sSortedDiskGhostRecordTimeIndices[sRecordsCopyFromGhostTypeIndex - 1] + 1;
                    }
                } while (sGhostCourseRecordTimes[ghostIndex] == -1);
            } else if (gInputPressed & BTN_DOWN) {
                do {
                    sRecordsCopyFromGhostTypeIndex++;
                    if (sRecordsCopyFromGhostTypeIndex > RECORDS_GHOST_DISK_3) {
                        sRecordsCopyFromGhostTypeIndex = RECORDS_GHOST_CASSETTE;
                    }
                    if (sRecordsCopyFromGhostTypeIndex == RECORDS_GHOST_CASSETTE) {
                        ghostIndex = sRecordsCopyFromGhostTypeIndex;
                    } else {
                        ghostIndex = sSortedDiskGhostRecordTimeIndices[sRecordsCopyFromGhostTypeIndex - 1] + 1;
                    }
                } while (sGhostCourseRecordTimes[ghostIndex] == -1);
            }
            if (lastGhostTypeIndex != sRecordsCopyFromGhostTypeIndex) {
                Audio_TriggerSystemSE(NA_SE_30);
            }
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                sRecordsCopyWhereBox =
                    BorderedBox_Init(4, 120, 60, 148, 72, 40, GPACK_RGBA5551(0, 0, 255, 1), Records_DrawCopyWhereMenu);

                if (sRecordsCopyWhereBox != NULL) {
                    sRecordsState = RECORDS_STATE_COPY_WHERE_MENU;
                    if ((sRecordsCopyFromGhostTypeIndex != RECORDS_GHOST_CASSETTE) &&
                        (gCourseIndex <= COURSE_BIG_HAND)) {
                        sDiskGhostCourseRecordTimes[0] = MAX_TIMER;
                        sRecordsCopyWhereMenuIndex = 0;
                    } else {
                        sDiskGhostCourseRecordTimes[0] = -1;
                        sRecordsCopyWhereMenuIndex = 1;
                    }
                    Records_ReadWriteGhost(OS_READ);
                }
                Audio_TriggerSystemSE(NA_SE_33);
                return;
            }
            if (gInputButtonPressed & BTN_B) {
                sRecordsState = RECORDS_STATE_RECORDS_MENU;
                func_80704810(1);
                BorderedBox_StartClose(sRecordsGhostCopyBox);
                Audio_TriggerSystemSE(NA_SE_16);
            }
        }
    }
}

Gfx* Records_DrawGhostCopyMenu(Gfx* gfx, s32 left, s32 top) {
    TexturePaletteInfo* textureInfo;
    s32 i;
    s32 timeTexturesLoaded;
    s32 ghostTypeLeft;
    s32 ghostTypeTop;
    s32 ghostIndex;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_8070DEE0(gfx, aRecordsWhichGhostToCopyTex, aRecordsWhichGhostToCopyPalette, G_IM_FMT_CI, 1, left + 20,
                        top + 10, 128, 16, 3);

    for (i = 0; i < 4; i++) {
        ghostTypeLeft = left + 10;
        ghostTypeTop = top + 30 + i * 20;
        textureInfo = &sRecordsGhostTypeTextureInfos[i];
        gDPPipeSync(gfx++);

        if (i != sRecordsCopyFromGhostTypeIndex) {
            if (i == RECORDS_GHOST_CASSETTE) {
                ghostIndex = i;
            } else {
                ghostIndex = sSortedDiskGhostRecordTimeIndices[i - 1] + 1;
            }
            if (sGhostCourseRecordTimes[ghostIndex] != -1) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, textureInfo->texture, textureInfo->tlut, G_IM_FMT_CI, 1, ghostTypeLeft, ghostTypeTop,
                            textureInfo->width, textureInfo->height, 2);
    }

    gSPDisplayList(gfx++, D_8014940);

    timeTexturesLoaded = false;
    for (i = 0; i < 4; i++) {
        if (i == 0) {
            ghostIndex = i;
        } else {
            ghostIndex = sSortedDiskGhostRecordTimeIndices[i - 1] + 1;
        }

        if (sGhostCourseRecordTimes[ghostIndex] == -1) {
            continue;
        }
        if (!timeTexturesLoaded) {
            timeTexturesLoaded = true;
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gfx = func_i3_DrawTimerScisThousandths(gfx, sGhostCourseRecordTimes[ghostIndex], left + 84, top + 30 + (i * 20),
                                               1.0f);
    }
    return gfx;
}

void Records_CopyWhereMenuUpdate(void) {
    s32 lastCopyWhereIndex;
    s16 sp20[2];

    if (BorderedBox_GetInfo(sRecordsCopyWhereBox, IS_BORDERED_BOX_OPENED) &&
        !BorderedBox_GetInfo(sRecordsCopyToDiskBox, IS_BORDERED_BOX_ACTIVE)) {
        sp20[0] = sDiskGhostCourseRecordTimes[0];
        sp20[1] = 0xEE7F;
        lastCopyWhereIndex = sRecordsCopyWhereMenuIndex;
        if (gInputPressed & BTN_UP) {
            do {
                sRecordsCopyWhereMenuIndex--;
                if (sRecordsCopyWhereMenuIndex < RECORDS_COPY_TO_GAME_PAK) {
                    sRecordsCopyWhereMenuIndex = RECORDS_COPY_TO_DISK;
                }
            } while (sp20[sRecordsCopyWhereMenuIndex] == -1);
        } else if (gInputPressed & BTN_DOWN) {
            do {
                sRecordsCopyWhereMenuIndex++;
                if (sRecordsCopyWhereMenuIndex > RECORDS_COPY_TO_DISK) {
                    sRecordsCopyWhereMenuIndex = RECORDS_COPY_TO_GAME_PAK;
                }
            } while (sp20[sRecordsCopyWhereMenuIndex] == -1);
        }
        if (lastCopyWhereIndex != sRecordsCopyWhereMenuIndex) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            if (sRecordsCopyWhereMenuIndex == RECORDS_COPY_TO_GAME_PAK) {
                sRecordsCopyToGhostTypeIndex = RECORDS_COPY_TO_GAME_PAK;
                Records_SetCopyingState(RECORDS_GHOST_COPIED);
            } else {
                Records_SetCopyingState(RECORDS_INSERT_DISK);
            }
            Audio_TriggerSystemSE(NA_SE_33);
            return;
        }
        if (gInputButtonPressed & BTN_B) {
            sRecordsState = RECORDS_STATE_COPY_GHOST_MENU;
            BorderedBox_StartClose(sRecordsCopyWhereBox);
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
}

void Records_SetCopyingState(s32 copyingState) {
    s32 boxWidth;
    s32 boxHeight;
    TexturePaletteInfo* textureInfo;

    sGhostCopyingState = copyingState;
    textureInfo = &sRecordsGhostCopyingInfoTextureInfos[sGhostCopyingState];
    boxWidth = textureInfo->width + 20;
    boxHeight = textureInfo->height + 20;
    sRecordsCopyingInfoBox =
        BorderedBox_Init(6, (SCREEN_WIDTH - boxWidth) / 2, (SCREEN_HEIGHT - boxHeight) / 2, boxWidth, boxHeight, 60,
                         GPACK_RGBA5551(255, 255, 0, 1), Records_DrawCopyingInfo);

    if (sRecordsCopyingInfoBox != NULL) {
        sRecordsState = RECORDS_STATE_SHOW_COPYING_INFO;
        sGhostCopiedTimer = 0;
    }
}

Gfx* Records_DrawCopyWhereMenu(Gfx* gfx, s32 left, s32 top) {
    TextureInfo* textureInfo;
    TexturePtr tlut;
    s32 i;
    s32 copyLocationLeft;
    s32 copyLocationTop;
    s32 ghostIndex;

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_8070DEE0(gfx, aRecordsWhereToCopyTex, aRecordsWhereToCopyPalette, G_IM_FMT_CI, 1, left + 10, top + 10,
                        128, 16, 3);

    for (i = 0; i < 2; i++) {
        copyLocationLeft = left + 20;
        copyLocationTop = top + 30 + i * 20;
        textureInfo = &sRecordsCopyLocationTextureInfos[i];

        gDPPipeSync(gfx++);
        if (i != RECORDS_COPY_TO_GAME_PAK) {
            tlut = NULL;
        } else {
            tlut = func_i2_800AEA90(aMenuTextTLUT);
        }
        if (i != sRecordsCopyWhereMenuIndex) {
            if (i == RECORDS_COPY_TO_GAME_PAK) {
                ghostIndex = i;
            } else {
                ghostIndex = sSortedDiskGhostRecordTimeIndices2[i - 1] + 1;
            }
            if ((i == RECORDS_COPY_TO_GAME_PAK) && (sDiskGhostCourseRecordTimes[ghostIndex] == -1)) {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, func_i2_800AEA90(textureInfo->texture), tlut, G_IM_FMT_CI, 1, copyLocationLeft,
                            copyLocationTop, textureInfo->width, textureInfo->height, 2);
    }
    return gfx;
}

void Records_CopyToDiskMenuUpdate(void) {
    s32 lastGhostTypeIndex;

    if (BorderedBox_GetInfo(sRecordsCopyToDiskBox, IS_BORDERED_BOX_OPENED) &&
        !BorderedBox_GetInfo(sRecordsCopyingInfoBox, IS_BORDERED_BOX_ACTIVE)) {
        lastGhostTypeIndex = sRecordsCopyToGhostTypeIndex;
        if (gInputPressed & BTN_UP) {
            sRecordsCopyToGhostTypeIndex--;
            if (sRecordsCopyToGhostTypeIndex < RECORDS_GHOST_DISK_1) {
                sRecordsCopyToGhostTypeIndex = RECORDS_GHOST_DISK_3;
            }
        } else if (gInputPressed & BTN_DOWN) {
            sRecordsCopyToGhostTypeIndex++;
            if (sRecordsCopyToGhostTypeIndex > RECORDS_GHOST_DISK_3) {
                sRecordsCopyToGhostTypeIndex = RECORDS_GHOST_DISK_1;
            }
        }
        if (lastGhostTypeIndex != sRecordsCopyToGhostTypeIndex) {
            Audio_TriggerSystemSE(NA_SE_30);
        }
        if (gInputButtonPressed & (BTN_A | BTN_START)) {
            Records_SetCopyingState(RECORDS_GHOST_COPIED);
            Audio_TriggerSystemSE(NA_SE_33);
            return;
        }
        if (gInputButtonPressed & BTN_B) {
            func_80704810(1);
            sRecordsState = RECORDS_STATE_RECORDS_MENU;
            BorderedBox_StartClose(sRecordsCopyToDiskBox);
            BorderedBox_StartClose(sRecordsCopyWhereBox);
            BorderedBox_StartClose(sRecordsGhostCopyBox);
            Audio_TriggerSystemSE(NA_SE_16);
        }
    }
}

Gfx* Records_DrawCopyToDiskMenu(Gfx* gfx, s32 left, s32 top) {
    s32 i;
    TexturePaletteInfo* textureInfo;
    s32 ghostIndex;
    s32 var_s4;
    bool timeTexturesLoaded;

    for (i = 1, textureInfo = &sRecordsGhostTypeTextureInfos[i]; i < 4; i++, textureInfo++) {

        gDPPipeSync(gfx++);

        if (i != RECORDS_GHOST_DISK_1) {
            var_s4 = 2;
        } else {
            var_s4 = 3;
        }
        if (i != sRecordsCopyToGhostTypeIndex) {
            if (i == RECORDS_GHOST_CASSETTE) {
                ghostIndex = i;
            } else {
                ghostIndex = sSortedDiskGhostRecordTimeIndices2[i - 1] + 1;
            }
            if (sDiskGhostCourseRecordTimes[ghostIndex] != -1) {
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
        } else {
            gfx = func_8070D4A8(gfx, 0);
        }
        gfx = func_8070DEE0(gfx, textureInfo->texture, textureInfo->tlut, 2, 1, left + 10, top - 10 + i * 20,
                            textureInfo->width, textureInfo->height, var_s4);
    }

    gSPDisplayList(gfx++, D_8014940);

    timeTexturesLoaded = false;
    for (i = 1; i < 4; i++) {

        if (i == RECORDS_GHOST_CASSETTE) {
            ghostIndex = i;
        } else {
            ghostIndex = sSortedDiskGhostRecordTimeIndices2[i - 1] + 1;
        }

        if (sDiskGhostCourseRecordTimes[ghostIndex] == -1) {
            continue;
        }
        if (!timeTexturesLoaded) {
            timeTexturesLoaded = true;
            gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gfx = func_i3_DrawTimerScisThousandths(gfx, sDiskGhostCourseRecordTimes[ghostIndex], left + 84,
                                               top - 10 + i * 20, 1.0f);
    }
    return gfx;
}

extern volatile u8 D_80794E14;

void Records_CopyingStateUpdate(void) {
    s32 i;
    s32 j;
    bool swapIndices;
    s32 ghostIndexTemp;

    if (BorderedBox_GetInfo(sRecordsCopyingInfoBox, IS_BORDERED_BOX_OPENED)) {
        switch (sGhostCopyingState) {
            case RECORDS_GHOST_COPIED:
                if (sGhostCopiedTimer < 1000) {
                    sGhostCopiedTimer++;
                }

                if (D_80794E14) {
                    break;
                }

                if (sGhostCopiedTimer == 5) {
                    sGhostCopiedTimer++;
                    Records_ReadWriteGhost(OS_WRITE);
                }
                if (sGhostCopiedTimer >= 60) {
                    func_80704810(1);
                    sRecordsState = RECORDS_STATE_RECORDS_MENU;
                    BorderedBox_StartClose(sRecordsCopyingInfoBox);
                    if (sRecordsCopyToGhostTypeIndex != RECORDS_GHOST_CASSETTE) {
                        BorderedBox_StartClose(sRecordsCopyToDiskBox);
                    }
                    BorderedBox_StartClose(sRecordsCopyWhereBox);
                    BorderedBox_StartClose(sRecordsGhostCopyBox);
                }
                break;
            case RECORDS_INSERT_DISK:
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_80704810(0);
                    func_80704AA8();
                    Records_LoadGhostRaceTimes(sDiskGhostCourseRecordTimes, false);

                    for (i = 0; i < 3; i++) {
                        sSortedDiskGhostRecordTimeIndices2[i] = i;
                    }

                    for (i = 0; i < 2; i++) {
                        for (j = i + 1; j < 3; j++) {
                            swapIndices = false;

                            if (sDiskGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices2[i] + 1] == -1) {
                                if (sDiskGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices2[j] + 1] != -1) {
                                    swapIndices = true;
                                }
                            } else if (sDiskGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices2[j] + 1] != -1) {
                                if ((sDiskGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices2[j] + 1] <
                                     sDiskGhostCourseRecordTimes[sSortedDiskGhostRecordTimeIndices2[i] + 1])) {
                                    swapIndices = true;
                                }
                            }
                            if (swapIndices) {
                                ghostIndexTemp = sSortedDiskGhostRecordTimeIndices2[i];
                                sSortedDiskGhostRecordTimeIndices2[i] = sSortedDiskGhostRecordTimeIndices2[j];
                                sSortedDiskGhostRecordTimeIndices2[j] = ghostIndexTemp;
                            }
                        }
                    }
                    sRecordsCopyToDiskBox = BorderedBox_Init(5, 130, 126, 168, 72, 50, GPACK_RGBA5551(0, 0, 255, 1),
                                                             Records_DrawCopyToDiskMenu);

                    if (sRecordsCopyToDiskBox != NULL) {
                        sRecordsState = RECORDS_STATE_COPY_TO_DISK_MENU;
                        sRecordsCopyToGhostTypeIndex = RECORDS_GHOST_DISK_1;
                        BorderedBox_StartClose(sRecordsCopyingInfoBox);
                    }
                    Audio_TriggerSystemSE(NA_SE_33);
                }
                break;
        }
    }
}

void Records_ReadWriteGhost(s32 direction) {
    s32 pad[3];
    s32 ghostIndex;
    GhostRecord ghostRecords[3];

    PRINTF("STAFF GHOST");
    PRINTF("STAFF GHOST");
    PRINTF("TIME");
    PRINTF("LAP%1d");

    if (direction == OS_READ) {
        switch (sRecordsCopyFromGhostTypeIndex) {
            case RECORDS_GHOST_CASSETTE:
                Save_LoadGhostInfo(NULL);
                Save_ReadGhostData(&gSaveContext.ghostSave.data);
                Save_LoadGhostData(&gSaveContext.ghostSave.record, &gSaveContext.ghostSave.data, NULL, true);
                break;
            case RECORDS_GHOST_DISK_1:
            case RECORDS_GHOST_DISK_2:
            case RECORDS_GHOST_DISK_3:
                DDSave_LoadCachedCourseGhostRecords(gCourseIndex, ghostRecords);
                ghostIndex = sSortedDiskGhostRecordTimeIndices[sRecordsCopyFromGhostTypeIndex - RECORDS_GHOST_DISK_1];
                gSaveContext.ghostSave.record = ghostRecords[ghostIndex];
                DDSave_LoadCachedCourseGhostData(gCourseIndex, ghostIndex, &gSaveContext.ghostSave.data);
                break;
        }
    } else {
        switch (sRecordsCopyToGhostTypeIndex) {
            case RECORDS_GHOST_CASSETTE:
                Save_WriteGhostRecord(&gSaveContext.ghostSave.record);
                Save_WriteGhostData(&gSaveContext.ghostSave.data);
                break;
            case RECORDS_GHOST_DISK_1:
            case RECORDS_GHOST_DISK_2:
            case RECORDS_GHOST_DISK_3:
                ghostIndex = sSortedDiskGhostRecordTimeIndices2[sRecordsCopyToGhostTypeIndex - 1];
                DDSave_SaveGhost(gCourseIndex, ghostIndex, NULL);
                break;
        }
    }
}

Gfx* Records_DrawCopyingInfo(Gfx* gfx, s32 left, s32 top) {
    TexturePaletteInfo* textureInfo = &sRecordsGhostCopyingInfoTextureInfos[sGhostCopyingState];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return func_8070DEE0(gfx, textureInfo->texture, textureInfo->tlut, G_IM_FMT_CI, 1, left + 10, top + 10,
                         textureInfo->width, textureInfo->height, 3);
}
