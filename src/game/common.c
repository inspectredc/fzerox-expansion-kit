#include "global.h"
#include "fzx_game.h"
#include "fzx_ghost.h"
#include "fzx_assets.h"
#include "src/overlays/ovl_i4/ovl_i4.h"

f32 gCharacterLastEngine[30];
UNUSED s32 D_8079FB18;
u16 gInputPressed;
u16 gInputButtonPressed;
u16 gRetriggeredButtonCurrentPressed;
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
    if (controller->retriggerCurrentButtonPress) {
        gRetriggeredButtonCurrentPressed = controller->buttonCurrent | STICK_TO_BUTTON(controller->stickCurrent);
    } else {
        gRetriggeredButtonCurrentPressed = 0;
    }
    gInputPressed = gInputButtonPressed | gRetriggeredButtonCurrentPressed;
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
extern s16 gForceCredits;

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
                gForceCredits = true;
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
                gForceCredits = true;
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

extern s16 gPlayerCharacters[];
extern s16 gPlayerMachineSkins[];

void func_8070DE6C(void) {
    s32 i;
    s32 j;

    for (i = 3; i >= 0; i--) {
        gPlayerCharacters[i] = i;
        gPlayerMachineSkins[i] = 0;
    }

    for (i = 0; i < 8; i++) {
        gModeSubOption[i] = 0;
    }

    gLastCourseSelectCourseIndex = 0;
    gLastRecordsCourseIndex = 0;
    gCurrentGhostType = GHOST_PLAYER;
}
