#include "global.h"
#include "ovl_i6.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"

extern s16 D_8076C7A8;
extern s32 D_8076CC54;
extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;
extern s32 gNumPlayers;
extern u32 gGameFrameCount;

void MainMenu_Init(void) {
    D_8076C7A8 = 3;
    D_8076E568 = D_8076E56C = D_8076E570 = 0.1f;
    D_8076CC54 = 0;
    gNumPlayers = 1;
    if ((gGameFrameCount % 4) == 0) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    if ((gGameFrameCount % 4) == 1) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_BACKGROUND, 0, 0, 4);
    if ((gGameFrameCount % 4) == 2) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_0, 0, 0, 10);
    if ((gGameFrameCount % 4) == 3) {
        Object_Init(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING, 0, 0, 0);
    }
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_1, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_2, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_3, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_4, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_5, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_6, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_MODE_SIGN_7, 0, 0, 10);
    Object_Init(OBJECT_MAIN_MENU_HEADER, 100, 13, 10);
    Object_Init(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS, 96, 80, 14);
    Object_Init(OBJECT_MAIN_MENU_OK, 0, 0, 14);
    Object_Init(OBJECT_MAIN_MENU_SELECT_DIFFICULTY, 96, 80, 14);
    Object_Init(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE, 96, 80, 14);
}

extern s32 gGameMode;
extern s32 gSelectedMode;
extern s32 gAntiPiracyAddedDifficulty;
extern s32 D_800BEE14;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;
extern char* gCurrentTrackName;
extern char* gTrackNames[];
extern s32 gDifficulty;
extern s32 gCourseIndex;
extern s8 gUnlockableLevel;
extern s32 gModeSubOption[];
extern s16 D_8076C810;
extern s16 D_8076C814;
extern s8 gSettingEverythingUnlocked;

const s32 gDefaultSubOptionLimits[] = { 2, 1, 0, 2, 0, 2, 0, 0 };
const s32 gMaxSubOptionLimits[] = { 3, 1, 0, 2, 0, 3, 0, 0 };

s32 MainMenu_Update(void) {
    s32 previous;
    bool var_v1_2;

    if (D_800BEE14 != 0) {
        return gGameMode;
    }

    Controller_SetGlobalInputs(&gSharedController);
    if (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_BACKGROUND)) >= 3) {
        return gGameMode;
    }
    switch (D_8076CC54) {
        case 0:
            previous = gSelectedMode;
            if (gInputPressed & BTN_RIGHT) {
                if ((gSelectedMode % 4) != 3) {
                    gSelectedMode++;
                }
            }
            if (gInputPressed & BTN_LEFT) {
                if (gSelectedMode % 4) {
                    gSelectedMode--;
                }
            }
            if (gInputPressed & BTN_DOWN) {
                if ((gSelectedMode / 4) == 0) {
                    gSelectedMode += 4;
                }
            }
            if (gInputPressed & BTN_UP) {
                if ((gSelectedMode / 4) != 0) {
                    gSelectedMode -= 4;
                }
            }

            if (previous != gSelectedMode) {
                func_8074122C(0x1E);
            }
            if (gInputButtonPressed & BTN_B) {
                func_8074122C(0x10);
                func_8070DB48();
                func_80741BD4(0xE);
                D_8076CC54 = 5;
                return GAMEMODE_FLX_TITLE;
            }

            if ((gInputButtonPressed & BTN_START) &&
                (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            }

            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_8074122C(0x3E);
                gAntiPiracyAddedDifficulty =
                    (UNLOCK_EVERYTHING_ROMDATA(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) & 0xFFFF) - 0x997A;
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        func_8074122C(0x21);
                        D_8076CC54 = 1;
                        break;
                    case MODE_DEATH_RACE:
                        D_8076CC54 = 5;
                        gCourseIndex = COURSE_DEATH_RACE;
                        gCurrentTrackName = gTrackNames[gCourseIndex];
                        gNumPlayers = 1;
                        func_80742360(gNumPlayers - 1);
                        gDifficulty = gAntiPiracyAddedDifficulty + MASTER;
                        return GAMEMODE_FLX_MACHINE_SELECT;
                    case MODE_OPTIONS:
                        func_80741BD4(0x10);
                        D_8076CC54 = 5;
                        D_8076C814 = 13;
                        break;
                    case MODE_COURSE_EDIT:
                        D_8076CC54 = 5;
                        func_80742D50();
                        func_80704810(0);
                        func_8070481C();
                        return GAMEMODE_COURSE_EDIT;
                    case MODE_CREATE_MACHINE:
                        D_8076CC54 = 5;
                        func_80742E2C();
                        func_80704810(0);
                        func_8070481C();
                        return GAMEMODE_CREATE_MACHINE;
                    default:
                        D_8076CC54 = 2;
                        break;
                }
            }
            break;
        case 1:
            previous = gModeSubOption[gSelectedMode];
            if (gInputPressed & BTN_DOWN) {
                gModeSubOption[gSelectedMode]++;
            }
            if ((gUnlockableLevel < 2) && !gSettingEverythingUnlocked) {
                if (gDefaultSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gDefaultSubOptionLimits[gSelectedMode];
                }
            } else {
                if (gMaxSubOptionLimits[gSelectedMode] < gModeSubOption[gSelectedMode]) {
                    gModeSubOption[gSelectedMode] = gMaxSubOptionLimits[gSelectedMode];
                }
            }

            if (gInputPressed & BTN_UP) {
                if (gModeSubOption[gSelectedMode] > 0) {
                    gModeSubOption[gSelectedMode]--;
                }
            }
            if (previous != gModeSubOption[gSelectedMode]) {
                func_8074122C(0x1E);
            }
            if (gInputButtonPressed & BTN_B) {
                D_8076CC54 = 0;
                func_8074122C(0x10);
            } else if ((gInputButtonPressed & BTN_START) &&
                       (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_8074122C(0x21);
                D_8076CC54 = 2;
                switch (gSelectedMode) {
                    case MODE_VS_BATTLE:
                        gNumPlayers = gModeSubOption[MODE_VS_BATTLE] + 2;
                        break;
                    case MODE_TIME_ATTACK:
                        if (gModeSubOption[MODE_TIME_ATTACK] != 0) {
                            D_8076CC54 = 6;
                            D_8076C814 = 9;
                            func_8074122C(0x3E);
                            func_80741BD4(0x10);
                        } else {
                            gNumPlayers = 1;
                        }
                        break;
                    case MODE_GP_RACE:
                    case MODE_PRACTICE:
                        gNumPlayers = 1;
                        gDifficulty = gAntiPiracyAddedDifficulty + gModeSubOption[gSelectedMode];
                        break;
                }
            }
            break;
        case 2:
            Math_Rand1();
            if (gInputButtonPressed & BTN_B) {
                func_8074122C(0x10);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        D_8076CC54 = 1;
                        break;
                    default:
                        D_8076CC54 = 0;
                        break;
                }
                break;
            }
            if ((gInputButtonPressed & BTN_START) &&
                (OBJECT_STATE(Object_Get(OBJECT_MAIN_MENU_UNLOCK_EVERYTHING)) == 7)) {
                break;
            }
            if (gInputButtonPressed & (BTN_A | BTN_START)) {
                func_8074122C(0x3E);
                func_80742360(gNumPlayers - 1);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        func_8071BE88();
                        D_8076CC54 = 3;
                        break;
                    default:
                        return GAMEMODE_FLX_TITLE;
                }
            }
            break;
        case 3:
            if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_MODE_SIGN_3)) == 12) {
                var_v1_2 = false;
                switch (gSelectedMode) {
                    case MODE_TIME_ATTACK:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_GP_RACE:
                    case MODE_PRACTICE:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_DIFFICULTY)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                    case MODE_VS_BATTLE:
                        if (OBJECT_COUNTER(Object_Get(OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS)) == 12) {
                            var_v1_2 = true;
                        }
                        break;
                }
                if (var_v1_2) {
                    D_8076CC54 = 4;
                }
            }
            if (gInputButtonPressed & BTN_B) {
                func_8074122C(0x10);
                switch (gSelectedMode) {
                    case MODE_GP_RACE:
                    case MODE_TIME_ATTACK:
                    case MODE_VS_BATTLE:
                    case MODE_PRACTICE:
                        D_8076CC54 = 1;
                        break;
                }
            }
            break;
        case 4:
            if (D_8076C810 == 0) {
                D_8076C814 = 11;
            }
            break;
        default:
            break;
    }
    return GAMEMODE_FLX_MAIN_MENU;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_Draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_BackgroundInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_SignInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_HeaderInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_NumPlayersInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_DifficultyInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_TimeAttackModeInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_OkInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_UnlockEverythingInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_SignDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_BackgroundDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_HeaderDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_NumPlayersDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_DifficultyDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_TimeAttackModeDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_OkDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/MainMenu_UnlockEverythingUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_80085040.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_8008504C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_8008505C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_80085068.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_80085074.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_80085088.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_80085098.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_800850A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i6/EB850/D_i6_800850B8.s")
