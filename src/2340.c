#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"

s32 gPostEadDemoGameMode = GAMEMODE_FLX_TITLE;
s32 sEADDemoQueueState = 0;
s32 gNumPlayers = 1;
s32 gCupType = JACK_CUP;
s32 gDifficulty = NOVICE;
s32 gTotalLapCount = 3;
s8 gTitleDemoState = TITLE_DEMO_INACTIVE;
s8 sTitleDemoNumPlayerState = 0;
s8 sTitleDemoCoursesState = 0;
UNUSED s32 D_8076C7E4 = 0;
u16 sTitleDemoCounter = 0;
s8 D_8076C7EC = false;
s32 sTitleDemoGameModes[] = { GAMEMODE_GP_RACE, GAMEMODE_VS_2P, GAMEMODE_VS_4P };
s32 sTitleDemoNumPlayers[] = { 1, 2, 4 };
s8 sTitleDemoCourses[] = { COURSE_DEVILS_FOREST, COURSE_SILENCE, COURSE_SAND_OCEAN, COURSE_BIG_BLUE,
                           COURSE_WHITE_LAND_2 };
s16 gGameModeChangeState = GAMEMODE_UPDATE;
s16 gMenuChangeMode = MENU_CHANGE_INACTIVE;

s32 D_8079A4B0;
s32 gGameMode;
s32 gQueuedGameMode;
UNUSED s32 D_8079A4BC;
UNUSED s32 D_8079A4C0;
UNUSED s32 D_8079A4C4;
s32 gAntiPiracyAddedDifficulty;
s8 gGamePaused;
UNUSED s32 D_8079A4D0;

void (*sGamemodeInitFuncs[])(void) = {
    Title_Init,            // GAMEMODE_TITLE
    Race_Init,             // GAMEMODE_GP_RACE
    Race_Init,             // GAMEMODE_PRACTICE
    Race_Init,             // GAMEMODE_VS_2P
    Race_Init,             // GAMEMODE_VS_3P
    Race_Init,             // GAMEMODE_VS_4P
    Records_Init,          // GAMEMODE_RECORDS
    MainMenu_Init,         // GAMEMODE_MAIN_MENU
    MachineSelect_Init,    // GAMEMODE_MACHINE_SELECT
    MachineSettings_Init,  // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Init,     // GAMEMODE_COURSE_SELECT
    Credits_Init,          // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Init,          // GAMEMODE_UNSKIPPABLE_CREDITS
    CourseEdit_Init,       // GAMEMODE_COURSE_EDIT
    Race_Init,             // GAMEMODE_TIME_ATTACK
    NextCourseSelect_Init, // GAMEMODE_GP_RACE_NEXT_COURSE
    MachineCreate_Init,    // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Init,   // GAMEMODE_GP_END_CS
    MachineSettings_Init,  // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Init,     // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Init,      // GAMEMODE_OPTIONS_MENU
    Race_Init,             // GAMEMODE_DEATH_RACE
    EADDemo_Init,          // GAMEMODE_EAD_DEMO
};

s32 (*sGamemodeUpdateFuncs[])(void) = {
    Title_Update,            // GAMEMODE_TITLE
    Race_Update,             // GAMEMODE_GP_RACE
    Race_Update,             // GAMEMODE_PRACTICE
    Race_Update,             // GAMEMODE_VS_2P
    Race_Update,             // GAMEMODE_VS_3P
    Race_Update,             // GAMEMODE_VS_4P
    Records_Update,          // GAMEMODE_RECORDS
    MainMenu_Update,         // GAMEMODE_MAIN_MENU
    MachineSelect_Update,    // GAMEMODE_MACHINE_SELECT
    MachineSettings_Update,  // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Update,     // GAMEMODE_COURSE_SELECT
    Credits_Update,          // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Update,          // GAMEMODE_UNSKIPPABLE_CREDITS
    CourseEdit_Update,       // GAMEMODE_COURSE_EDIT
    Race_Update,             // GAMEMODE_TIME_ATTACK
    NextCourseSelect_Update, // GAMEMODE_GP_RACE_NEXT_COURSE
    MachineCreate_Update,    // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Update,   // GAMEMODE_GP_END_CS
    MachineSettings_Update,  // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Update,     // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Update,      // GAMEMODE_OPTIONS_MENU
    Race_Update,             // GAMEMODE_DEATH_RACE
    EADDemo_Update,          // GAMEMODE_EAD_DEMO
};

Gfx* (*sGamemodeDrawFuncs[])(Gfx*) = {
    Title_Draw,           // GAMEMODE_TITLE
    Race_Draw,            // GAMEMODE_GP_RACE
    Race_Draw,            // GAMEMODE_PRACTICE
    Race_Draw,            // GAMEMODE_VS_2P
    Race_Draw,            // GAMEMODE_VS_3P
    Race_Draw,            // GAMEMODE_VS_4P
    Records_Draw,         // GAMEMODE_RECORDS
    MainMenu_Draw,        // GAMEMODE_MAIN_MENU
    MachineSelect_Draw,   // GAMEMODE_MACHINE_SELECT
    MachineSettings_Draw, // GAMEMODE_MACHINE_SETTINGS
    CourseSelect_Draw,    // GAMEMODE_COURSE_SELECT
    Credits_Draw,         // GAMEMODE_SKIPPABLE_CREDITS
    Credits_Draw,         // GAMEMODE_UNSKIPPABLE_CREDITS
    CourseEdit_Draw,      // GAMEMODE_COURSE_EDIT
    Race_Draw,            // GAMEMODE_TIME_ATTACK
    CourseSelect_Draw,    // GAMEMODE_GP_RACE_NEXT_COURSE
    MachineCreate_Draw,   // GAMEMODE_CREATE_MACHINE
    EndingCutscene_Draw,  // GAMEMODE_GP_END_CS
    MachineSettings_Draw, // GAMEMODE_GP_RACE_NEXT_MACHINE_SETTINGS
    CourseSelect_Draw,    // GAMEMODE_RECORDS_COURSE_SELECT
    OptionsMenu_Draw,     // GAMEMODE_OPTIONS_MENU
    Race_Draw,            // GAMEMODE_DEATH_RACE
    EADDemo_Draw,         // GAMEMODE_EAD_DEMO
};

extern s32 gGameMode;
extern s32 gQueuedGameMode;
extern s16 D_8076C93C;

void Game_Init(void) {
    gGameMode = -1;
    gQueuedGameMode = GAMEMODE_FLX_TITLE;
    func_8071ED34();
    func_i2_800B904C();
    Camera_StartInit();
    Transition_Init();
    func_8070F0D0();
    Arena_EndInit();
    func_8070D358();
    DDSave_LoadBaseCourses();
    D_8076C93C = true;
}

extern s32 gCourseIndex;
extern f32 gPlayerEngine[];

void func_806F4BB4(void) {
    if (gGameModeChangeState != GAMEMODE_UPDATE) {
        return;
    }
    switch (gMenuChangeMode) {
        case MENU_CHANGE_RETRY:
            if (sEADDemoQueueState != 0) {
                gPostEadDemoGameMode = GAMEMODE_TIME_ATTACK;
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_EAD_DEMO;
                sEADDemoQueueState = 2;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START_RELOAD;
            }
            break;
        case MENU_CHANGE_QUIT:
            if (sEADDemoQueueState != 0) {
                gPostEadDemoGameMode = GAMEMODE_FLX_TITLE;
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_EAD_DEMO;
                sEADDemoQueueState = 2;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            }
            break;
        case MENU_CHANGE_CHANGE_COURSE:
            if (sEADDemoQueueState != 0) {
                gPostEadDemoGameMode = GAMEMODE_FLX_COURSE_SELECT;
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_EAD_DEMO;
                sEADDemoQueueState = 2;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
            }
            break;
        case MENU_CHANGE_CHANGE_MACHINE:
            if (sEADDemoQueueState != 0) {
                gPostEadDemoGameMode = GAMEMODE_FLX_MACHINE_SELECT;
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_EAD_DEMO;
                sEADDemoQueueState = 2;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_FLX_MACHINE_SELECT;
            }
            break;
        case MENU_CHANGE_NEXT_COURSE:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            if (gCourseIndex % 6 == 5) {
                gQueuedGameMode = GAMEMODE_GP_END_CS;
            } else {
                gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                gCourseIndex++;
            }
            gPlayerEngine[0] = 0.5f;
            break;
        case MENU_CHANGE_CRASH_RESTART:
            gGameModeChangeState = GAMEMODE_CHANGE_START;
            gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
            break;
        case MENU_CHANGE_6:
            gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
            break;
        case MENU_CHANGE_CHANGE_RECORD_COURSE:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_RECORDS;
            break;
        case MENU_CHANGE_TO_RECORDS:
            D_8076C7EC = true;
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_RECORDS_COURSE_SELECT;
            break;
        case MENU_CHANGE_EXIT_RECORDS:
        case MENU_CHANGE_EXIT_OPTIONS:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            break;
        case MENU_CHANGE_TO_COURSE_SELECT:
            D_8076C7EC = true;
            gGameModeChangeState = GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_COURSE_SELECT;
            break;
        case MENU_CHANGE_EXIT_COURSE_SELECT:
            gGameModeChangeState = GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_MAIN_MENU;
            break;
        case MENU_CHANGE_TO_OPTIONS:
            gGameModeChangeState = GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START);
            gQueuedGameMode = GAMEMODE_FLX_OPTIONS_MENU;
            break;
        case MENU_CHANGE_SETTINGS:
            if (sEADDemoQueueState != 0) {
                gPostEadDemoGameMode = GAMEMODE_LX_MACHINE_SETTINGS;
                gGameModeChangeState = GAMEMODE_CHANGE_START;
                gQueuedGameMode = GAMEMODE_EAD_DEMO;
                sEADDemoQueueState = 2;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
                if (gGameMode == GAMEMODE_GP_RACE) {
                    gQueuedGameMode = GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS;
                } else {
                    gQueuedGameMode = GAMEMODE_LX_MACHINE_SETTINGS;
                }
            }
            break;
        case MENU_CHANGE_16:
            gGameModeChangeState = GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START);
            gQueuedGameMode = gGameMode;
            break;
        default:
            break;
    }
    if (sEADDemoQueueState == 2) {
        sEADDemoQueueState = 0;
    }
}

void func_806F4FC8(void) {
    static u16 D_8076C92C = BGM_MUTE_CITY;
    s32 bgm = D_8076C92C;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                D_8076C92C = BGM_MUTE_CITY;
            }
            return;
        case GAMEMODE_FLX_TITLE:
            bgm = BGM_TITLE;
            break;
        case GAMEMODE_GP_END_CS:
            bgm = BGM_END_CS;
            break;
        case GAMEMODE_FLX_SKIPPABLE_CREDITS:
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
            bgm = BGM_CREDITS;
            break;
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
        case GAMEMODE_FLX_OPTIONS_MENU:
            bgm = BGM_OPTION;
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_FLX_MACHINE_SELECT:
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
            bgm = BGM_SELECT;
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_EAD_DEMO:
            D_8076C92C = BGM_MUTE_CITY;
            return;
        default:
            break;
    }
    if (D_8076C92C != bgm) {
        func_8070DAFC();
        if (gGameMode != GAMEMODE_FLX_TITLE) {
            func_8070DA84();
        }
        func_8070DAD4(bgm);
    }
    D_8076C92C = bgm;
}

s32 D_8076C930 = 15;
s32 D_8076C934 = 5;
s16 gControllerReadDataStarted = false;
s16 D_8076C93C = false;

extern Controller gSharedController;
extern s32 gControllersConnected;
extern u16 gInputButtonPressed;

void func_806F5118(void) {

    if (gGameMode != gQueuedGameMode) {
        gTitleDemoState = TITLE_DEMO_INACTIVE;
        sTitleDemoCounter = 0;
        return;
    }
    Controller_SetGlobalInputs(&gSharedController);
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            if (gControllersConnected != 0) {
                sTitleDemoCounter++;
            }
            if ((gTitleDemoState != TITLE_DEMO_INACTIVE) && (gControllersConnected != 0)) {

                gQueuedGameMode = sTitleDemoGameModes[sTitleDemoNumPlayerState];
                gNumPlayers = sTitleDemoNumPlayers[sTitleDemoNumPlayerState];
                gCourseIndex = sTitleDemoCourses[sTitleDemoCoursesState];
                sTitleDemoNumPlayerState++;
                sTitleDemoCoursesState++;
                if (sTitleDemoNumPlayerState >= ARRAY_COUNT(sTitleDemoNumPlayers)) {
                    sTitleDemoNumPlayerState = 0;
                }
                if (sTitleDemoCoursesState >= ARRAY_COUNT(sTitleDemoCourses)) {
                    sTitleDemoCoursesState = 0;
                }
                sTitleDemoCounter = 0;
                gTitleDemoState = TITLE_DEMO_ACTIVE;
                gDifficulty = MASTER;
            }
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            if (gTitleDemoState != TITLE_DEMO_INACTIVE) {
                sTitleDemoCounter++;
                switch (gTitleDemoState) {
                    case TITLE_DEMO_ACTIVE:
                        if (!(gInputButtonPressed & (BTN_A | BTN_START))) {
                            break;
                        }
                        /* fallthrough */
                    case TITLE_DEMO_START_EXIT:
                        gQueuedGameMode = GAMEMODE_FLX_TITLE;
                        sTitleDemoCounter = 0;
                        gTitleDemoState = TITLE_DEMO_EXIT;
                        break;
                    case TITLE_DEMO_EXIT:
                        break;
                }
            }
            break;
    }
}

extern OSMesgQueue gSerialEventQueue;
extern s8 gGamePaused;
extern CourseInfo* gCurrentCourseInfo;
extern u8 D_i2_800BF044[];

void func_806F5310(void) {
    s32 sp24;
    s32 sp20;

    if (gGameMode != gQueuedGameMode) {
        if (gGameModeChangeState == GAMEMODE_UPDATE) {
            if (gGameMode == -1) {
                gGameModeChangeState = GAMEMODE_CHANGE_INIT;
            } else {
                gGameModeChangeState = GAMEMODE_CHANGE_START;
            }
        }
    } else {
        func_806F4BB4();
    }

    gMenuChangeMode = MENU_CHANGE_INACTIVE;
    switch (gGameModeChangeState) {
        case GAMEMODE_CHANGE_START:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_START):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_START):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_START):
            Transition_HideSet();
            if (gControllerReadDataStarted) {
                Controller_UpdateInputs();
                gControllerReadDataStarted = false;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            Transition_Update();
            if (D_8076C93C) {
                osContStartReadData(&gSerialEventQueue);
                gControllerReadDataStarted = true;
            }
            gGameModeChangeState++;
            return;
        case GAMEMODE_CHANGE_WAIT_TRANSITION:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_WAIT_TRANSITION):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_WAIT_TRANSITION):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_WAIT_TRANSITION):
            if (gControllerReadDataStarted) {
                Controller_UpdateInputs();
                gControllerReadDataStarted = false;
            }
            sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
            if (Transition_Update()) {
                if (gGameMode == GAMEMODE_GP_RACE) {
                    Hud_ResetLivesChangeCounter();
                }
                gGameModeChangeState++;
            }
            if (D_8076C93C) {
                osContStartReadData(&gSerialEventQueue);
                gControllerReadDataStarted = true;
                return;
            }
            return;
        case GAMEMODE_CHANGE_INIT:
        case GAMEMODE_CHANGE_UNK10(GAMEMODE_CHANGE_INIT):
        case GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT):
        case GAMEMODE_CHANGE_INSTANT(GAMEMODE_CHANGE_INIT):
            Controller_Reset();
            if (D_8076C7EC) {
                func_80704870();
                D_8076C7EC = false;
            }
            switch (gGameMode) {
                case GAMEMODE_LX_MACHINE_SETTINGS:
                case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
                    if ((gNumPlayers == 1) && (gCourseIndex < COURSE_EDIT_1)) {
                        Save_UpdateCourseCharacterSave(gCourseIndex);
                    }
                    break;
                case GAMEMODE_FLX_MACHINE_SELECT:
                    func_i4_80073EA0();
                    break;
                case GAMEMODE_COURSE_EDIT:
                    func_8070D220();
                    break;
            }
            gGameMode = gQueuedGameMode;
            if (gTitleDemoState == TITLE_DEMO_EXIT) {
                gTitleDemoState = TITLE_DEMO_INACTIVE;
            }
            gGamePaused = false;
            Arena_StartInit();

            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_COURSE_EDIT:
                case GAMEMODE_TIME_ATTACK:
                case GAMEMODE_CREATE_MACHINE:
                case GAMEMODE_DEATH_RACE:
                case GAMEMODE_EAD_DEMO:
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        func_8070DA84();
                    }
                    break;
            }
            sp24 = 0;
            sp20 = 0;
            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_COURSE_EDIT:
                case GAMEMODE_DEATH_RACE:
                case GAMEMODE_LX_MACHINE_SETTINGS:
                case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
                case GAMEMODE_FLX_MACHINE_SELECT:
                    sp20 = 1;
                    break;
                case GAMEMODE_TIME_ATTACK:
                    sp20 = 2;
                    break;
                case GAMEMODE_RECORDS:
                    sp20 = 3;
                    break;
            }
            if (func_80708D88()) {
                // effectively go to the next switch
                sp20 += 4;
            }

            if (sp20 != 0) {
                if (sp20 < 4) {
                    if ((gGameModeChangeState == GAMEMODE_CHANGE_FAST(GAMEMODE_CHANGE_INIT)) && (sp20 == 3)) {
                        OSTime time = osGetTime();

                        while (osGetTime() - time < 6100000) {}
                    }
                } else {
                    sp20 -= 4;
                }

                switch (sp20) {
                    case 1:
                        func_8071E988();
                        break;
                    case 2:
                        sp24 = 1;
                        break;
                    case 3:
                        func_8071E9C4();
                        break;
                }
            }

            func_80708F4C();
            func_i2_800B079C();
            sp20 = GAMEMODE_UPDATE;
            sGamemodeInitFuncs[GET_MODE(gGameMode)]();
            if (sp24 == 1) {
                func_8071EA88();
            }
            func_80709C3C();
            switch (gGameMode) {
                case GAMEMODE_GP_RACE:
                case GAMEMODE_PRACTICE:
                case GAMEMODE_VS_2P:
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                case GAMEMODE_TIME_ATTACK:
                case GAMEMODE_DEATH_RACE:
                    Hud_UpdateCharacterPortraits();
                    if (gTitleDemoState == TITLE_DEMO_INACTIVE) {
                        if (gCurrentCourseInfo->courseIndex < COURSE_EDIT_1) {
                            Audio_DDBgmReady(D_i2_800BF044[gCurrentCourseInfo->courseIndex]);
                        } else if (gCurrentCourseInfo->courseIndex == COURSE_DEATH_RACE) {
                            Audio_DDBgmReady(BGM_DEATHRACE);
                        } else {
                            Audio_DDBgmReady(Course_GetBgm());
                        }
                    }
                    break;
            }
            func_806F4FC8();
            Transition_AppearSet();
            gGameModeChangeState = sp20;
            break;
        case GAMEMODE_CHANGE_START_RELOAD:
            Transition_HideSet();
            Transition_Update();
            gGameModeChangeState = GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD;
            break;
        case GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD:
            if (Transition_Update()) {
                Transition_AppearSet();
                if (gGameMode != GAMEMODE_RECORDS) {
                    func_8070DA84();
                }
                func_806F4FC8();
                func_i2_800B07F0();
                func_i2_800AABD0();
                gGameModeChangeState = GAMEMODE_UPDATE;
            }
            break;
        case GAMEMODE_UPDATE:
        default:
            break;
    }

    if (gControllerReadDataStarted) {
        Controller_UpdateInputs();
        gControllerReadDataStarted = false;
    }
    gQueuedGameMode = sGamemodeUpdateFuncs[GET_MODE(gGameMode)]();
    func_806F5118();
    switch (gGameModeChangeState) {
        case GAMEMODE_CHANGE_WAIT_TRANSITION_RELOAD:
            break;
        case GAMEMODE_UPDATE:
            Transition_Update();
            break;
    }
    if (D_8076C93C) {
        osContStartReadData(&gSerialEventQueue);
        gControllerReadDataStarted = true;
    }
}

extern s16 D_i2_800BEE10;

Gfx* func_806F59E0(Gfx* gfx) {

    if ((gGameModeChangeState != GAMEMODE_CHANGE_INIT) && D_i2_800BEE10) {
        gfx = sGamemodeDrawFuncs[GET_MODE(gGameMode)](gfx);
    }
    return Transition_Draw(gfx);
}
