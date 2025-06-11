#include "global.h"
#include "course_select.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_assets.h"

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

extern s8 sUnlockedGhosts;
extern s8 sStaffGhostTimeBeaten;
extern s32 sLastCourseIndex;
extern s32 gCourseIndex;

void CourseSelect_UpdateUnlockedGhosts(void) {
    s32 staffTime;
    s32 timeRecord;

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
extern s8 D_i5_8007B9EC[];
extern s8 D_i5_8007C2AF;

extern s8 sGhostOptionTypeMap[];
extern s8 sSelectedGhostOption;
extern s8 sCourseSelectTrackNo;
extern s32 sCourseSelectCup;

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

    sp20 = func_807084E4(0, 4 * 30 * 7);
    Save_UpdateCupSave(sp20);

    for (i = 0; i < 2; i++) {
        var_a1 = false;
        for (j = 3; j >= 0; j--) {
            for (k = 0; k < 30; k++) {
                if (((s8*)sp20)[(j * 30 * 7) + (k * 7) + i + 5] != 0) {
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

extern s32 sCourseSelectState;

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_Update.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/NextCourseSelect_Update.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_Draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_BackgroundInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ModelInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_CupInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_HeaderInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_OkInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ArrowsInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostMarkerInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostOptionInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_BackgroundDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ModelDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_CupDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_HeaderDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_OkDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ArrowsDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEA0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEB0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BED4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BEF0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF00.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF24.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF30.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF7C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF8C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BF9C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BFAC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BFC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BFD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BFE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007BFFC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C010.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C020.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C030.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C034.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C038.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C03C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C040.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C044.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C048.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C05C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C070.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C07C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C090.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C09C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C0F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C108.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C10C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C110.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C114.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C118.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C11C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/D_i5_8007C120.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_NameDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostMarkerDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostOptionDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ModelUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_CupUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_ArrowsUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostMarkerUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_select/course_select/CourseSelect_GhostOptionUpdate.s")
