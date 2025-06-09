#include "global.h"
#include "ovl_i4.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include "fzx_font.h"
#include "fzx_assets.h"

extern s16 D_8076C7A8;
extern s32 gSelectedMode;
extern s8 gPlayerSelectionLock[];
extern s32 gMachineSelectState;
extern s8 gSettingEverythingUnlocked;
extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;
extern s32 gNumPlayers;
extern s32 sMachinesUnlocked;
extern s16 sMachineSelectIndex[8];

void MachineSelect_Init(void) {
    s32 i;

    D_8076C7A8 = 3;
    D_8076E568 = D_8076E56C = D_8076E570 = 0.1f;
    func_807160A0();
    func_8071A358();
    gMachineSelectState = MACHINE_SELECT_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        sMachineSelectIndex[i] = func_8070DBF0(gRacers[i].character);
    }
    sMachinesUnlocked = ((func_8070DA54() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        sMachinesUnlocked = 30;
    }
    if (sMachinesUnlocked > 30) {
        sMachinesUnlocked = 30;
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SELECT_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SELECT_HEADER, 80, 13, 4);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR, 60, 10, 8);
    Object_Init(OBJECT_MACHINE_SELECT_MACHINE, 0, 0, 10);

    switch (gNumPlayers) {
        case 4:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_3, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_3, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_3, 260, 190, 6);
            /* fallthrough */
        case 3:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_2, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_2, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_2, 260, 10, 6);
            /* fallthrough */
        case 2:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_1, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_1, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_1, 20, 190, 6);
            /* fallthrough */
        case 1:
            break;
    }

    if (gSelectedMode == MODE_GP_RACE) {
        Object_Init(OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS, 0, 0, 12);
    }
    Object_Init(OBJECT_MACHINE_SELECT_STATS_0, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_0, 60, 10, 12);
    Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_0, 20, 10, 6);

    if (gNumPlayers == 1) {
        Object_Init(OBJECT_MACHINE_SELECT_NAME, 0, 0, 12);
    }

    Object_Init(OBJECT_MACHINE_SELECT_OK, 0, 0, 12);
}

extern s32 gMachineSettingsState;
extern s32 gGameMode;
extern s32 gCourseIndex;
extern f32 gCharacterLastEngine[];
extern f32 gPlayerEngine[];

void MachineSettings_Init(void) {
    s32 i;

    D_8076C7A8 = 3;
    func_807160A0();
    func_8071A358();
    gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        if (gGameMode != GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS) {
            gPlayerEngine[i] = 0.5f;
        }
    }

    if ((gNumPlayers == 1) && (gCourseIndex < COURSE_EDIT_1)) {
        Save_UpdateCharacterSave(gCourseIndex);
        gPlayerEngine[0] = gCharacterLastEngine[gRacers[0].character];
    }

    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SETTINGS_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SETTINGS_NAME, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT, 160, 34, 10);
    Object_Init(OBJECT_MACHINE_SETTINGS_STATS, 160, 97, 10);
    if (gNumPlayers == 2) {
        Object_Init(OBJECT_58, 160, 97, 13);
    }
    Object_Init(OBJECT_MACHINE_SETTINGS_MACHINE, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_NAME_CARD, 20, 185, 12);
    Object_Init(OBJECT_MACHINE_SETTINGS_SLIDER, 208, 85, 11);
    Object_Init(OBJECT_MACHINE_SETTINGS_OK, 0, 0, 14);

    switch (gNumPlayers) {
        case 4:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_3, -6, -5, 8);
            /* fallthrough */
        case 3:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_2, -6, -5, 8);
            /* fallthrough */
        case 2:
            Object_Init(OBJECT_MACHINE_SETTINGS_SPLITSCREEN_BARS, 0, 0, 6);
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_1, -6, -5, 8);
            /* fallthrough */
        case 1:
            Object_Init(OBJECT_MACHINE_SETTINGS_PORTRAIT_0, -6, -5, 8);
            break;
    }
}

extern s8 D_8076CC7C[];
extern f32 D_i4_80077058;
extern f32 D_i4_8007705C;
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

s32 MachineSelect_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 lastMachineIndex;

    func_80717294();

    for (i = 3; i >= 0; i--) {

        Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[i]]);
        if (i >= gNumPlayers) {
            if ((gInputButtonPressed & BTN_B) && (gMachineSelectState == MACHINE_SELECT_ACTIVE)) {
                func_8074122C(0x10);
                gMachineSelectState = MACHINE_SELECT_EXIT;
                if (gSelectedMode == MODE_DEATH_RACE) {
                    return GAMEMODE_FLX_MAIN_MENU;
                }
                // FAKE
                if ((gRacers + i)->character) {}
                return GAMEMODE_FLX_COURSE_SELECT;
            }
            continue;
        }

        // Setup Mini Cars
        if (gInputButtonPressed & (BTN_L | BTN_R | BTN_CLEFT | BTN_CDOWN)) {
            if ((gSharedController.buttonCurrent & BTN_L) && (gSharedController.buttonCurrent & BTN_R) &&
                (gSharedController.buttonCurrent & BTN_CLEFT) && (gSharedController.buttonCurrent & BTN_CDOWN) &&
                (MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) == 0) &&
                (gMachineSelectState != MACHINE_SELECT_CONTINUE)) {
                MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) = 1;
                D_i4_80077058 = 1.0f;
                D_i4_8007705C = 0.0f;
                func_8074122C(0x17);
                return gGameMode;
            }
        }

        switch (gMachineSelectState) {
            case MACHINE_SELECT_ACTIVE:
                lastMachineIndex = sMachineSelectIndex[i];

                if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                    if (gInputPressed & BTN_LEFT) {
                        if (sMachineSelectIndex[i] % 6) {
                            sMachineSelectIndex[i]--;
                        } else {
                            sMachineSelectIndex[i] += 5;
                        }
                    } else if (gInputPressed & BTN_RIGHT) {
                        if ((sMachineSelectIndex[i] % 6) < 5) {
                            sMachineSelectIndex[i]++;
                        } else {
                            sMachineSelectIndex[i] -= 5;
                        }
                    }
                    if (gInputPressed & BTN_UP) {
                        sMachineSelectIndex[i] -= 6;
                    } else if (gInputPressed & BTN_DOWN) {
                        sMachineSelectIndex[i] += 6;
                    }
                }

                sMachineSelectIndex[i] += sMachinesUnlocked;
                sMachineSelectIndex[i] %= sMachinesUnlocked;
                gRacers[i].character = func_8070DBE0(sMachineSelectIndex[i]);

                if (lastMachineIndex != sMachineSelectIndex[i]) {
                    func_80741014(i, 0x1E);
                    D_8076CC7C[i] = 1;
                    gPlayerEngine[i] = 0.5f;
                }

                if (gInputButtonPressed & BTN_B) {
                    func_80741014(i, 0x10);

                    if (gPlayerSelectionLock[i] != SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_FREE;
                    } else {
                        gMachineSelectState = MACHINE_SELECT_EXIT;
                        if (gSelectedMode == MODE_DEATH_RACE) {
                            return GAMEMODE_FLX_MAIN_MENU;
                        }
                        return GAMEMODE_FLX_COURSE_SELECT;
                    }
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_LOCKED;
                        if (D_8076CC7C[i] != 0) {
                            D_8076CC7C[i] = 0;
                            for (j = 0; j < gNumPlayers; j++) {
                                for (k = 0; k < 4; k++) {
                                    if (i != k && gRacers[k].character == gRacers[i].character && D_8076CC7C[k] == 0 &&
                                        j == gRacers[k].machineSkinIndex) {
                                        break;
                                    }
                                }

                                if (k >= 4) {
                                    gRacers[i].machineSkinIndex = j;
                                    break;
                                }
                            }
                            if (j >= 4) {
                                gRacers[i].machineSkinIndex = 0;
                            }
                        }
                        func_80741014(i, 0x21);
                    }
                }

                for (j = 0, k = 0; j < gNumPlayers; j++) {
                    if (gPlayerSelectionLock[j] == SELECTION_FREE) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    gMachineSelectState = MACHINE_SELECT_AWAIT_OK;
                }
                break;
            case 2:
                if (gInputButtonPressed & BTN_B) {
                    gPlayerSelectionLock[i] = SELECTION_FREE;
                    gMachineSelectState = MACHINE_SELECT_ACTIVE;
                    func_80741014(i, 0x10);
                    break;
                }
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_80741014(i, 0x3E);
                    gMachineSelectState = MACHINE_SELECT_CONTINUE;
                    return GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
        }
    }
    return gGameMode;
}

extern s32 D_800BEE14;

s32 MachineSettings_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    Controller* temp_s1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fa1;
    s32 stickX;

    func_80717294();
    if (D_800BEE14 != 0) {
        return gGameMode;
    }

    for (i = gNumPlayers - 1; i >= 0; i--) {
        temp_s1 = &gControllers[gPlayerControlPorts[i]];
        Controller_SetGlobalInputs(temp_s1);

        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
                if (gPlayerSelectionLock[i] == SELECTION_FREE) {

                    k = gRacers[i].machineSkinIndex;

                    if (gInputButtonPressed & BTN_Z) {
                        gRacers[i].machineSkinIndex--;
                        gRacers[i].machineSkinIndex &= 3;
                    }
                    if (gInputButtonPressed & BTN_R) {
                        gRacers[i].machineSkinIndex++;
                        gRacers[i].machineSkinIndex &= 3;
                    }
                    if (k != gRacers[i].machineSkinIndex) {
                        func_80741014(i, 0x1E);
                    }
                    stickX = temp_s1->stickX;
                    temp_fa0 = gPlayerEngine[i];
                    temp_fv0 = (f32) stickX * 0.003;
                    var_fa1 = SQ(temp_fv0);
                    if (var_fa1 < 0.001) {
                        var_fa1 = 0.0078125f;
                        stickX = 0;
                        if (gInputPressed & BTN_LEFT) {
                            stickX = -1;
                        } else if (!(gInputPressed & BTN_RIGHT)) {
                            var_fa1 = 0.0f;
                        }
                    }
                    if (stickX < 0) {
                        gPlayerEngine[i] -= var_fa1;
                        if (gPlayerEngine[i] < 0.0) {
                            gPlayerEngine[i] = 0.0f;
                        }
                    } else {
                        gPlayerEngine[i] += var_fa1;
                        if (gPlayerEngine[i] > 1.0) {
                            gPlayerEngine[i] = 1.0f;
                        }
                    }
                    if ((s32) (temp_fa0 / 0.1f) != (s32) (gPlayerEngine[i] / 0.1f)) {
                        func_80741014(i, 0x16);
                    }
                    if (gNumPlayers == 1) {
                        gCharacterLastEngine[gRacers[0].character] = gPlayerEngine[0];
                    }
                }
                if (gInputButtonPressed & BTN_B) {
                    func_80741014(i, 0x10);

                    if (gPlayerSelectionLock[i] != SELECTION_FREE) {
                        gPlayerSelectionLock[i] = SELECTION_FREE;
                    } else {
                        gMachineSettingsState = MACHINE_SETTINGS_EXIT;
                        if (gGameMode == GAMEMODE_LX_MACHINE_SETTINGS) {
                            return GAMEMODE_FLX_MACHINE_SELECT;
                        }
                        return GAMEMODE_FLX_GP_RACE_NEXT_COURSE;
                    }
                } else if ((gInputButtonPressed & (BTN_A | BTN_START)) && (gPlayerSelectionLock[i] == SELECTION_FREE)) {
                    func_80741014(i, 0x21);
                    gPlayerSelectionLock[i] = SELECTION_LOCKED;
                }

                for (k = 0, j = 0; j < gNumPlayers; j++) {
                    if (gPlayerSelectionLock[j] == SELECTION_FREE) {
                        k++;
                        break;
                    }
                }

                if (k == 0) {
                    gMachineSettingsState = MACHINE_SETTINGS_AWAIT_OK;
                }
                break;
            case MACHINE_SETTINGS_AWAIT_OK:
                if (gInputButtonPressed & BTN_B) {
                    gPlayerSelectionLock[i] = SELECTION_FREE;
                    gMachineSettingsState = MACHINE_SETTINGS_ACTIVE;
                    func_80741014(i, 0x10);
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    func_80741014(i, 0x3E);
                    func_8070DAFC();
                    gMachineSettingsState = MACHINE_SETTINGS_CONTINUE;
                    switch (gSelectedMode) {
                        case MODE_GP_RACE:
                            return GAMEMODE_GP_RACE;
                        case MODE_TIME_ATTACK:
                            return GAMEMODE_TIME_ATTACK;
                        case MODE_PRACTICE:
                            return GAMEMODE_PRACTICE;
                        case MODE_VS_BATTLE:
                            return gNumPlayers + 1;
                        case MODE_DEATH_RACE:
                            return GAMEMODE_DEATH_RACE;
                    }
                }
            case MACHINE_SETTINGS_EXIT:
            case MACHINE_SETTINGS_CONTINUE:
            default:
                break;
        }
    }

    return gGameMode;
}

extern s32 gQueuedGameMode;

Gfx* MachineSelect_Draw(Gfx* gfx) {
    gfx = Object_UpdateAndDrawAll(gfx);
    func_i2_800AF7E0();
    if (gGameMode != gQueuedGameMode) {
        func_8071A3E0();
    }
    return gfx;
}

Gfx* MachineSettings_Draw(Gfx* gfx) {
    gfx = Object_UpdateAndDrawAll(gfx);
    func_i2_800AF7E0();
    if (gGameMode != gQueuedGameMode) {
        func_8071A3E0();
    }
    return gfx;
}

extern unk_806F2400 D_806F2400;

s32 MachineSettings_GetCharacter(s32 character) {

    if (D_806F2400.unk_3C0[character] == -1) {
        character += 30;
        if (character >= 36) {
            character %= 30;
        }
    }
    return character;
}

extern unk_80077D50 sSelectMachineCompTexInfo[];

void MachineSelect_HeaderInit(void) {
    func_i2_800AE17C(sSelectMachineCompTexInfo, 0, true);
}

extern unk_80077D50* sPortraitCompTexInfos[];
extern unk_80077D50* sSmallPortraitCompTexInfos[];

void func_i4_80070288(Object* arg0) {
    s32 i;

    if (gNumPlayers == 1) {
        func_i2_800AE17C(sPortraitCompTexInfos[gRacers[0].character], 0, true);
        return;
    }

    for (i = 0; i < gNumPlayers; i++) {
        func_i2_800AE17C(sSmallPortraitCompTexInfos[gRacers[i].character], 0, true);
    }
}

extern unk_80077D50 sPortraitBackgroundCompTexInfo[];
extern unk_800792D8* D_i4_800756A8[];
extern unk_800792D8* D_i4_80075BE0[];

void MachineSettings_PortraitInit(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;

    OBJECT_STATE(portraitObj) = gRacers[playerIndex].character;
    OBJECT_STATE(portraitObj) = MachineSettings_GetCharacter(OBJECT_STATE(portraitObj));

    if (gNumPlayers == 1) {
        func_i2_800AE17C(sPortraitBackgroundCompTexInfo, 0, true);
        OBJECT_CACHE_INDEX(portraitObj) = func_i2_800AF9F8(D_i4_800756A8[OBJECT_STATE(portraitObj)]);
    } else {
        OBJECT_CACHE_INDEX(portraitObj) = func_i2_800AF9F8(D_i4_80075BE0[OBJECT_STATE(portraitObj)]);
    }
}

void MachineSelect_PortraitInit(Object* portraitObj) {
    OBJECT_CACHE_INDEX(portraitObj) = func_i2_800AF9F8(D_i4_80075BE0[0]);
}

extern unk_80077D50* sPlayerNumIconCompTexInfos[];

void MachineSelect_CursorNumInit(Object* cursorNumObj) {
    func_i2_800AE17C(sPlayerNumIconCompTexInfos[cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0], 0, true);
}

extern unk_80077D50 sMachineSelectCursorCompTexInfo[];

void MachineSelect_CursorInit(void) {
    func_i2_800AE17C(sMachineSelectCursorCompTexInfo, 0, true);
}

void MachineSelect_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = (Vp*) func_807084E4(0, 30 * sizeof(Vp));
    MACHINE_VIEWPORT(machineObj) = vp;

    for (i = 0; i < 30; i++) {
        vp[i].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
        vp[i].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
        vp[i].vp.vscale[2] = 0x1FF;
        vp[i].vp.vscale[3] = 0;
        vp[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x39) << 2;
        vp[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x39) << 2;
        vp[i].vp.vtrans[2] = 0x1FF;
        vp[i].vp.vtrans[3] = 0;
    }

    for (j = 3; j >= 0; j--) {
        gRacers[j].unk_0C.unk_34.x = gRacers[j].unk_0C.unk_34.y = gRacers[j].unk_0C.unk_34.z = 0.0f;
        gRacers[j].unk_C0.x.z = 1.0f;
        gRacers[j].unk_C0.y.y = 1.0f;
        gRacers[j].unk_C0.z.x = 1.0f;
        gRacers[j].unk_C0.x.x = 0.0f;
        gRacers[j].unk_C0.y.z = 0.0f;
        gRacers[j].unk_C0.z.y = 0.0f;
        gRacers[j].unk_C0.x.y = 0.0f;
        gRacers[j].unk_C0.y.x = 0.0f;
        gRacers[j].unk_C0.z.z = 0.0f;
    }
}

void MachineSettings_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;
    s32 k;

    vp = (Vp*) func_807084E4(0, 2 * 4 * sizeof(Vp));
    MACHINE_VIEWPORT(machineObj) = vp;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            vp[i * 4 + j].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
            vp[i * 4 + j].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
            vp[i * 4 + j].vp.vscale[2] = 0x1FF;
            vp[i * 4 + j].vp.vscale[3] = 0;

            switch (gNumPlayers) {
                case 1:
                    vp[i * 4 + j].vp.vtrans[0] = ((i * -4) + 0xDC) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = ((i * 0xA) + 0xC8) << 2;
                    break;
                case 2:
                    vp[i * 4 + j].vp.vtrans[0] = ((i * -6) + 0xE9) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 0xE) + 0x50) << 2;
                    break;
                default:
                    vp[i * 4 + j].vp.vtrans[0] = (((j / 2) * 0x8C) + (i * -2) + 0x2B) << 2;
                    vp[i * 4 + j].vp.vtrans[1] = (((j % 2) * 0x69) + (i * 5) + 0x35) << 2;
                    break;
            }

            vp[i * 4 + j].vp.vtrans[2] = 0x1FF;
            vp[i * 4 + j].vp.vtrans[3] = 0;
        }
    }

    for (k = 3; k >= 0; k--) {
        gRacers[k].unk_0C.unk_34.x = gRacers[k].unk_0C.unk_34.y = gRacers[k].unk_0C.unk_34.z = 0.0f;
        gRacers[k].unk_C0.x.z = 1.0f;
        gRacers[k].unk_C0.y.y = 1.0f;
        gRacers[k].unk_C0.z.x = 1.0f;
        gRacers[k].unk_C0.x.x = 0.0f;
        gRacers[k].unk_C0.y.z = 0.0f;
        gRacers[k].unk_C0.z.y = 0.0f;
        gRacers[k].unk_C0.x.y = 0.0f;
        gRacers[k].unk_C0.y.x = 0.0f;
        gRacers[k].unk_C0.z.z = 0.0f;
    }
}

extern unk_80077D50 sMachineInfoGraphCompTexInfo[];
extern unk_80077D50 sMachineAccelerationMaxSpeedCompTexInfo[];
extern unk_80077D50 sMachineInfoGraphSmallCompTexInfo[];
extern unk_80077D50 sMachineAccelerationMaxSpeedSmallCompTexInfo[];

void MachineSettings_EngineWeightInit(void) {
    if (gNumPlayers == 1) {
        func_i2_800AE17C(sMachineInfoGraphCompTexInfo, 0, true);
        func_i2_800AE17C(sMachineAccelerationMaxSpeedCompTexInfo, 0, true);
    } else {
        func_i2_800AE17C(sMachineInfoGraphSmallCompTexInfo, 0, true);
        func_i2_800AE17C(sMachineAccelerationMaxSpeedSmallCompTexInfo, 0, true);
    }
}

extern unk_80077D50 sMachineBodyBoostGripCompTexInfo[];
extern unk_80077D50 sMachineBodyBoostGripSmallCompTexInfo[];

void MachineSettings_StatsInit(void) {
    if (gNumPlayers == 1) {
        func_i2_800AE17C(sMachineBodyBoostGripCompTexInfo, 0, true);
    } else {
        func_i2_800AE17C(sMachineBodyBoostGripSmallCompTexInfo, 0, true);
    }
}

extern unk_800792D8* D_i4_800760AC[];

void MachineSettings_NameCardInit(Object* nameCardObj) {
    if (gNumPlayers == 1) {
        OBJECT_CACHE_INDEX(nameCardObj) = func_i2_800AF9F8(D_i4_800760AC[0]);
    }
}

extern unk_80077D50 sEngineSliderCompTexInfo[];

void MachineSettings_SliderInit(void) {
    func_i2_800AE17C(sEngineSliderCompTexInfo, 0, true);
}

extern unk_80077D50* sTrophyCompTexInfos[];
extern unk_80077D50* D_i4_8007657C[];
extern unk_80077D50* sDifficultyCompTexInfos[];

void MachineSelect_DifficultyCupsInit(Object* difficultyCupsObj) {
    s32 i;

    OBJECT_BUFFER(difficultyCupsObj) = func_807084E4(0, 4 * 30 * 7);

    Save_UpdateCupSave(OBJECT_BUFFER(difficultyCupsObj));

    for (i = 0; i < 21; i++) {
        func_i2_800AE17C(sTrophyCompTexInfos[i], 0, false);
    }

    for (i = 0; i < 4; i++) {
        func_i2_800AE578(D_i4_8007657C[i], 0);
    }

    for (i = 0; i < 4; i++) {
        func_i2_800AE17C(sDifficultyCompTexInfos[i], 0, true);
    }
}

extern unk_80077D50* sMachineStatCompTexInfos[];

void MachineSelect_StatsInit(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_i2_800AE17C(sMachineStatCompTexInfos[i], 0, true);
    }
}

extern unk_80077D50 sOKCompTexInfo[];

void MachineSelect_OkInit(Object* okObj) {
    func_i2_800AE17C(sOKCompTexInfo, 0, true);
    OBJECT_TOP(okObj) = 50;
}

void MachineSettings_OkInit(Object* okObj) {
    func_i2_800AE17C(sOKCompTexInfo, 0, true);
    OBJECT_LEFT(okObj) = 50;
}

#define PACK_5551(r, g, b, a) (((((r) << 11) | ((g) << 6)) | ((b) << 1)) | (a))

#ifdef NON_MATCHING
Gfx* MachineSelect_BackgroundDraw(Gfx* gfx) {
    s32 color;
    s32 i;
    s32 rmul = 10;
    s32 gmul = 0;
    s32 bmul = 60;
    s32 r, g, b;

    gDPSetCycleType(gfx++, G_CYC_FILL);

    for (i = 0; i < 224; i++) {
        r = ((i * rmul) / 224) >> 3;
        g = ((i * gmul) / 224) >> 3;
        b = ((i * bmul) / 224) >> 3;
        if (1) {
            gDPPipeSync(gfx++);
            gDPSetFillColor(gfx++, PACK_5551(r, g, b, 1) << 0x10 | PACK_5551(r, g, b, 1));
            gDPFillRectangle(gfx++, 12, i + 8, 307, i + 8);
        }
    }
    r = ((i * rmul) / 224) >> 3;
    g = ((i * gmul) / 224) >> 3;
    b = ((i * bmul) / 224) >> 3;

    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_BackgroundDraw.s")
#endif

Gfx* MachineSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_i2_800AF584(gfx, sSelectMachineCompTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj), 0, 0, 0, 1.0f,
                         1.0f, true);
}

extern const s32 D_i4_80076FA4[];

Gfx* func_i4_80071054(Gfx* gfx, Object* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = func_i2_800AF584(gfx, sPortraitCompTexInfos[gRacers[0].character], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0,
                            0, 1.0f, 1.0f, true);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_80076FA4[i * 2];
            gfx = func_i2_800AF584(gfx, sSmallPortraitCompTexInfos[gRacers[i].character], var_s0[0], var_s0[1] + 55, 0, 0,
                                0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

extern unk_800E3F28 D_800D63F8[];

Gfx* MachineSettings_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;
    const s32* positions;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    positions = &D_i4_80076FA4[playerIndex * 2];
    switch (gNumPlayers) {
        case 1:
            gfx = func_i2_800AF584(gfx, sPortraitBackgroundCompTexInfo, OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj),
                                0, 0, 0, 1.0f, 1.0f, true);
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                                OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
            break;
        case 2:
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], positions[0] - 4,
                                positions[1] + 0x1A, 0, 0, 0, 1.0f, 1.0f, true);
            break;
        default:
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], positions[0], positions[1] + 0x37, 0,
                                0, 0, 1.0f, 1.0f, true);
            break;
    }
    return gfx;
}

extern Machine gMachines[];
extern const s32 D_i4_80076F74[];
extern const char* sMachineStatValues[];

Gfx* MachineSelect_StatsDraw(Gfx* gfx, Object* statsObj) {
    s32 temp_fp;
    s32 temp_s0;
    s32 temp_t0;
    s32 playerIndex;
    s8* temp_a3;
    s32 i;

    playerIndex = statsObj->cmdId - OBJECT_MACHINE_SELECT_STATS_0;

    temp_a3 = &gMachines[gRacers[playerIndex].character].machineStats;
    temp_fp = D_i4_80076F74[playerIndex * 2 + 0];
    temp_t0 = D_i4_80076F74[playerIndex * 2 + 1];
    if (playerIndex < 2) {
        for (i = 0; i < 3; i++) {
            gfx = func_i2_800AF584(gfx, sMachineStatCompTexInfos[i], temp_fp, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f, 1.0f, true);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = Font_DrawString(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = func_i2_800AF584(gfx, sMachineStatCompTexInfos[i], temp_fp - 20, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f,
                                1.0f, true);
            temp_s0 = sMachineStatValues[temp_a3[i]];
            gfx = Font_DrawString(gfx, (temp_fp - Font_GetStringWidth(temp_s0, FONT_SET_2, 0)) - 5,
                                  (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

extern const s32 D_i4_80076F54[];

Gfx* MachineSelect_PortraitDraw(Gfx* gfx, Object* portraitObj) {
    s32 playerIndex;

    playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;

    gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                        OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
    return func_i2_800AF584(gfx, sPlayerNumIconCompTexInfos[playerIndex],
                         D_i4_80076F54[playerIndex * 2 + 0] + OBJECT_LEFT(portraitObj),
                         D_i4_80076F54[playerIndex * 2 + 1] + OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
}

Gfx* MachineSelect_CursorNumDraw(Gfx* gfx, Object* portraitObj) {
    return func_i2_800AF584(gfx, sPlayerNumIconCompTexInfos[portraitObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0],
                         OBJECT_LEFT(portraitObj), OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
}

extern u32 gGameFrameCount;

Gfx* MachineSelect_CursorDraw(Gfx* gfx, Object* cursorObj) {
    s32 temp_v0;
    s32 i;
    s32 temp_s3 = 30;
    s32 red;
    s32 green;
    s32 blue;

    for (i = 0; i < 4; i++) {
        if (Object_Get(OBJECT_MACHINE_SELECT_CURSOR_NUM_0 + i) != NULL) {
            temp_v0 = (u32) gGameFrameCount % temp_s3;
            if (D_806F2400.unk_3C0[sMachineSelectIndex[i]] != 0) {
                red = 255;
                green = 155;
                blue = 55;
            } else {
                red = 255;
                green = 255;
                blue = 255;
            }
            if ((gPlayerSelectionLock[i] != SELECTION_FREE) || (temp_v0 >= 0xF)) {
                gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, red, green, blue, 255 - ((temp_v0 * 510) / temp_s3));
            }
            temp_v0 = sMachineSelectIndex[i];
            OBJECT_LEFT(cursorObj) = ((temp_v0 % 6) * 0x28) + 0x28;
            OBJECT_TOP(cursorObj) = ((temp_v0 / 6) * 0x22) + 0x25;

            gfx = func_i2_800AF584(gfx, sMachineSelectCursorCompTexInfo, OBJECT_LEFT(cursorObj), OBJECT_TOP(cursorObj), 1,
                                0, 0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

extern Player gPlayers[];
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* MachineSelect_MachineDraw(Gfx* gfx, Object* machineObj) {
    bool var_t0;
    s32 i;
    s32 j;

    gSPLoadUcodeL(gfx++, gspF3DEX_Rej_fifo);
    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_1A208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A5F8);

    gSPLight(gfx++, &D_1000000.unk_33A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_33A88[0].a, 2);
    gSPNumLights(gfx++, NUMLIGHTS_1);

    Lights_SetSource(&gGfxPool->unk_33A88[0], 0, 0, 0, 255, 255, 255, 100, 50, 69);
    Lights_SetSource(&gGfxPool->unk_33A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

    for (i = 0; i < 30; i++) {
        gDPPipeSync(gfx++);
        var_t0 = false;
        if (i < sMachinesUnlocked) {
            j = 0;
        } else {
            j = 1;
        }

        gSPLight(gfx++, &D_1000000.unk_33A88[j].l[0], 1);
        gSPLight(gfx++, &D_1000000.unk_33A88[j].a, 2);
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);

        for (j = 0; j < gNumPlayers; j++) {
            if (i == sMachineSelectIndex[j]) {
                var_t0 = true;
                break;
            }
        }

        if (!var_t0) {
            gSPMatrix(gfx++, &D_1000000.unk_32308[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        } else {
            gSPMatrix(gfx++, &D_1000000.unk_32308[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
        gfx = func_8072DF40(gfx, func_8070DBE0(i), 0);
    }
    return gfx;
}

Gfx* MachineSelect_OkDraw(Gfx* gfx, Object* okObj) {
    s32 var_v1;

    if (gNumPlayers == 1) {
        var_v1 = 265;
    } else {
        var_v1 = 144;
    }

    gfx = func_8070D4A8(gfx, 0);
    return func_i2_800AF584(gfx, sOKCompTexInfo, OBJECT_LEFT(okObj) + var_v1, OBJECT_TOP(okObj) + 209, 1, 0, 0, 1.0f,
                         1.0f, true);
}

extern const char* gMachineNames[];
extern const s32 D_i4_80076FA4[];

Gfx* MachineSettings_NameDraw(Gfx* gfx) {
    s32 i;
    const char* machineName;
    const s32* var_s0;
    s32 characterSlot;

    if (gNumPlayers == 1) {
        characterSlot = func_8070DBF0(gRacers[0].character);
        if (D_806F2400.unk_3C0[characterSlot] > 0) {
            machineName = D_806F2400.unk_00[characterSlot].machineName;
        } else {
            machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
        }
        gfx =
            Font_DrawString(gfx, 0x122 - Font_GetStringWidth(machineName, FONT_SET_1, 0), 0x22, machineName, 0, FONT_SET_1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_80076FA4[i * 2];
            characterSlot = func_8070DBF0(gRacers[i].character);
            if (D_806F2400.unk_3C0[characterSlot] > 0) {
                machineName = D_806F2400.unk_00[characterSlot].machineName;
            } else {
                machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[i].character)];
            }
            gfx = Font_DrawString(gfx, (var_s0[0] - Font_GetStringWidth(machineName, FONT_SET_2, 0)) + 0x82,
                                  var_s0[1] + 0xA, machineName, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

extern s16 D_i4_80076678;
extern s32 D_i4_8007667C;
extern s8 D_i4_80076680[];

Gfx* MachineSettings_MachineDraw(Gfx* gfx, Object* machineObj) {
    s32 i;

    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);

    gSPMatrix(gfx++, D_1000000.unk_1A208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gSPDisplayList(gfx++, D_303A758);

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        if (D_i4_80076680[i] == 0) {
            continue;
        }

        if (gControllers[gPlayerControlPorts[i]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT)) {
            D_i4_80076680[i] = 0;
            continue;
        }

        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i + 4);
        gSPMatrix(gfx++, &D_1000000.unk_32A88[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8072E0B0(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A7D8);
    gDPSetBlendColor(gfx++, 0, 0, 0, 255);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_33208[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8072E1C0(gfx, gRacers[i].character);
    }

    gSPDisplayList(gfx++, D_303A5F8);

    Lights_SetSource(gGfxPool->unk_33A88, 0, 0, 0, 255, 255, 255, 50, 25, 34);
    gSPLight(gfx++, &D_1000000.unk_33A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_33A88[0].a, 2);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_32308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8072DF40(gfx, gRacers[i].character, gRacers[i].machineSkinIndex);
    }

    gSPDisplayList(gfx++, D_90186C8);

    Light_SetLookAtSource(&gGfxPool->unk_33B28, &gPlayers[0].unk_15C);
    gSPLookAt(gfx++, &gGfxPool->unk_33B28);

    gSPTexture(gfx++, D_i4_8007667C, D_i4_8007667C, 0, G_TX_RENDERTILE, G_ON);

    gDPLoadTextureBlock(gfx++, D_9000008, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i4_80076678);

    for (i = 0; i < gNumPlayers; i++) {
        gSPViewport(gfx++, MACHINE_VIEWPORT(machineObj) + i);
        gSPMatrix(gfx++, &D_1000000.unk_32308[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gfx = func_8072E1F0(gfx, gRacers[i].character);
    }

    return gfx;
}

Gfx* MachineSettings_EngineWeightDraw(Gfx* gfx, Object* engineWeightObj) {
    s32 i;
    s16 weight;
    s32 temp_s0;
    s32 temp_s1;

    if (gNumPlayers == 1) {
        weight = gMachines[gRacers[0].character].weight;
        gfx = func_i2_800AF584(gfx, sMachineInfoGraphCompTexInfo, OBJECT_LEFT(engineWeightObj),
                            OBJECT_TOP(engineWeightObj), 0, 0, 0, 1.0f, 1.0f, true);
        gfx = Font_DrawMachineWeight(gfx, OBJECT_LEFT(engineWeightObj) + 0x66, OBJECT_TOP(engineWeightObj) + 0x17,
                                     weight);

        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
            case MACHINE_SETTINGS_EXIT:
                gfx = func_8070D4A8(gfx, 0);
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }

        gfx = func_i2_800AF584(gfx, sMachineAccelerationMaxSpeedCompTexInfo, OBJECT_LEFT(engineWeightObj),
                            OBJECT_TOP(engineWeightObj), 1, 0, 0, 1.0f, 1.0f, true);

    } else {
        for (i = 0; i < gNumPlayers; i++) {
            weight = gMachines[gRacers[i].character].weight;
            temp_s0 = D_i4_80076FA4[i * 2 + 0];
            temp_s1 = D_i4_80076FA4[i * 2 + 1];
            gfx = func_i2_800AF584(gfx, sMachineInfoGraphSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 0, 0, 0, 1.0f,
                                1.0f, true);
            gfx = Font_DrawMachineWeight(gfx, temp_s0 + 0x6E, temp_s1 + 0x1C, weight);
            if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                gfx = func_8070D4A8(gfx, 0);
            } else {
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
            }
            gfx = func_i2_800AF584(gfx, sMachineAccelerationMaxSpeedSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 1, 0,
                                0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

Gfx* MachineSettings_StatsDraw(Gfx* gfx, Object* statsObj) {
    s32 i;
    s32 j;
    s32 leftOffset;
    s32 topOffset;
    s8* temp;
    s32 pad;

    if (gNumPlayers == 1) {
        gfx = func_i2_800AF584(gfx, sMachineBodyBoostGripCompTexInfo, OBJECT_LEFT(statsObj), OBJECT_TOP(statsObj), 0, 0, 0,
                            1.0f, 1.0f, true);

        for (i = 0; i < 3; i++) {
            temp = gMachines[gRacers[0].character].machineStats;
            gfx = Font_DrawMachineStatValue(gfx, OBJECT_LEFT(statsObj) + 0x69, OBJECT_TOP(statsObj) + i * 23 + 3,
                                            temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            leftOffset = D_i4_80076FA4[i * 2 + 0];
            topOffset = D_i4_80076FA4[i * 2 + 1];

            gfx = func_i2_800AF584(gfx, sMachineBodyBoostGripSmallCompTexInfo, leftOffset + 0x2B, topOffset + 0x39, 0, 0,
                                0, 1.0f, 1.0f, true);

            for (j = 0; j < 3; j++) {
                temp = gMachines[gRacers[i].character].machineStats;
                gfx = Font_DrawString(gfx, leftOffset + 0x6B, topOffset + 0x43 + j * 14, sMachineStatValues[temp[j]], 0,
                                      FONT_SET_2, 0);
            }
        }
    }
    return gfx;
}

Gfx* func_i4_800729D8(Gfx* gfx, Object* arg1) {
    s32 i;
    s32 j;
    s8* temp;
    s32 var_s3;
    s32 var_s1;
    const char* temp2;

    for (i = 0; i < gNumPlayers; i++) {
        var_s3 = D_i4_80076FA4[i * 2 + 0];
        var_s1 = D_i4_80076FA4[i * 2 + 1];

        for (j = 0; j < 3; j++) {
            temp = gMachines[gRacers[i].character].machineStats;
            temp2 = sMachineStatValues[temp[j]];
            gfx = Font_DrawString(gfx, var_s3 + 0x6B, var_s1 + 0x43 + j * 14, temp2, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSettings_NameCardDraw(Gfx* gfx, Object* nameCardObj) {

    if (gNumPlayers == 1) {
        gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(nameCardObj)], OBJECT_LEFT(nameCardObj),
                            OBJECT_TOP(nameCardObj), 0, 0, 0, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* MachineSettings_SliderDraw(Gfx* gfx, Object* sliderObj) {
    s32 i;
    s32 temp_v1;
    s32 left;
    s32 top;

    if (gNumPlayers == 1) {
        switch (gMachineSettingsState) {
            case MACHINE_SETTINGS_ACTIVE:
            case MACHINE_SETTINGS_EXIT:
                if (1) {
                    gfx = func_8070D4A8(gfx, 0);
                }
                break;
            default:
                gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                break;
        }

        gfx = func_i2_800AF584(gfx, sEngineSliderCompTexInfo, (s32) (gPlayerEngine[0] * 128.0f) + 0x98, 0x54, 1, 0, 0,
                            1.0f, 1.0f, true);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            temp_v1 = 1;
            switch (gMachineSettingsState) {
                case MACHINE_SETTINGS_ACTIVE:
                case MACHINE_SETTINGS_EXIT:
                    if (gPlayerSelectionLock[i] == SELECTION_FREE) {
                        gfx = func_8070D4A8(gfx, 0);
                        break;
                    }
                default:
                    gDPSetPrimColor(gfx++, 0, 0, 0, 255, 0, 255);
                    break;
            }

            top = D_i4_80076FA4[i * 2 + 1] + 0x2E;
            left = D_i4_80076FA4[i * 2 + 0] + (s32) (gPlayerEngine[i] * 80.0f) + 0x23;
            gfx = func_i2_800AF584(gfx, sEngineSliderCompTexInfo, left, top, temp_v1, 0, 0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

Gfx* MachineSettings_SplitscreenDraw(Gfx* gfx) {

    gfx = func_8070A594(gfx, 255, 255, 255, 12, 119, 307, 120);
    if (gNumPlayers >= 3) {
        gfx = func_8070A594(gfx, 255, 255, 255, 158, 8, 159, 231);
    }
    return gfx;
}

extern s32 gDifficulty;
extern s8 gUnlockableLevel;
extern s32 gAntiPiracyAddedDifficulty;

Gfx* MachineSelect_DifficultyCupsDraw(Gfx* gfx, Object* difficultyCupsObj) {
    s32 i;
    s32 character;
    s32 difficulty;
    s32 trophyIndex;
    s32 pad;
    s32 cupsUnlocked;
    s8* var_t1;

    character = func_8070DBE0(sMachineSelectIndex[0]);
    difficulty = 0;
    switch (gMachineSelectState) {
        case MACHINE_SELECT_AWAIT_OK:
        case MACHINE_SELECT_CONTINUE:
            break;
        default:
            if (((gUnlockableLevel >= 2) || (gSettingEverythingUnlocked != 0)) &&
                (gSharedController.buttonCurrent & BTN_CUP)) {
                difficulty = MASTER + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CRIGHT) {
                difficulty = EXPERT + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CDOWN) {
                difficulty = STANDARD + 1;
            }
            if (gSharedController.buttonCurrent & BTN_CLEFT) {
                difficulty = NOVICE + 1;
            }
            break;
    }

    if (difficulty != 0) {
        difficulty--;
    } else {
        difficulty = gDifficulty - gAntiPiracyAddedDifficulty;
    }

    if ((gUnlockableLevel >= 2) || (gSettingEverythingUnlocked != 0)) {
        cupsUnlocked = 5;
    } else {
        if (gUnlockableLevel > 0) {
            cupsUnlocked = 4;
        } else {
            cupsUnlocked = 3;
        }
    }

    var_t1 = OBJECT_BUFFER(difficultyCupsObj) + difficulty * 210 + character * 7;

    for (i = 0; i < cupsUnlocked; i++) {

        if (((s8*)var_t1)[i ^ 0] == 0) {
            // No trophy
            trophyIndex = 20;
        } else {
            trophyIndex = (difficulty * 5) + i;
        }

        gfx = func_i2_800AF584(gfx, sTrophyCompTexInfos[trophyIndex], 20, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f, false);
    }

    if (1) {}

    for (i = 0; i < 2; i++) {

        if (((s8*)var_t1)[(i ^ 0) + 5] == 0) {
            // No trophy
            trophyIndex = 20;
        } else {
            trophyIndex = difficulty + 21;
        }

        gfx = func_i2_800AF584(gfx, sTrophyCompTexInfos[trophyIndex], 284, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f, false);
    }
    return func_i2_800AF584(gfx, sDifficultyCompTexInfos[difficulty], 30, 0xD1, 0, 0, 0, 1.0f, 1.0f, true);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F48.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F4C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F54.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F74.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076FA4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_NameDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_OkDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_800732A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_PortraitUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_PortraitUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorNumUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_MachineUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_MachineUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_NameCardUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_80073EA0.s")
