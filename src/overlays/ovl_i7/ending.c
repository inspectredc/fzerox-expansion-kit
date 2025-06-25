#include "global.h"
#include "ovl_i7.h"
#include "fzx_game.h"
#include "fzx_font.h"
#include "fzx_hud.h"
#include "fzx_racer.h"
#include "fzx_machine.h"
#include "fzx_assets.h"

unk_8014B480* D_i7_8009AD10;
s16 sTotalRacersKOd;
u16 D_8009AD16;
void* sEndingTex;
void* sEndingTextTex;
s16 sEndScreenState;
s16 sEndScreenFade;
s16 sEndScreenAlpha;
s32 D_i7_8009AD28; // state
s16 D_i7_8009AD2C; // counter
f32 D_i7_8009AD30; // scroll top
s16 D_i7_8009AD34; // congrats/ending alpha
s16 sCupNameIndex;
s16 sCupNameWidth;
s16 sCupDifficulty;
s16 D_i7_8009AD3C; // thanks for playing state
s16 sThanksForPlayingFade;
s16 D_i7_8009AD40;
unk_8014BE28 D_i7_8009AD48[10];
unk_8014BEC8 D_i7_8009ADE8[3];
u16 D_i7_8009AE48;
Vec3f D_i7_8009AE50[7];
s16 D_i7_8009AEA4;
UNUSED s16 D_i7_8009AEA6;
UNUSED s32 D_i7_8009AEA8;
UNUSED s32 D_i7_8009AEAC;

void* sEndingTextures[][2] = {
    { aEndingCaptainFalconMasterTex, aEndingTextCaptainFalconMasterTex },                 // CAPTAIN_FALCON
    { aEndingDrStewartTex, aEndingTextDrStewartTex },                                     // DR_STEWART
    { aEndingPicoTex, aEndingTextPicoTex },                                               // PICO
    { aEndingSamuraiGorohTex, aEndingTextSamuraiGorohTex },                               // SAMURAI_GOROH
    { aEndingJodySummerTex, aEndingTextJodySummerTex },                                   // JODY_SUMMER
    { aEndingMightyGazelleTex, aEndingTextMightyGazelleTex },                             // MIGHTY_GAZELLE
    { aEndingMrEadTex, aEndingTextMrEadTex },                                             // MR_EAD
    { aEndingBabaTex, aEndingTextBabaTex },                                               // BABA
    { aEndingOctomanTex, aEndingTextOctomanTex },                                         // OCTOMAN
    { aEndingGomarAndShiohTex, aEndingTextGomarAndShiohTex },                             // GOMAR_AND_SHIOH
    { aEndingKateAlenTex, aEndingTextKateAlenTex },                                       // KATE_ALEN
    { aEndingRogerBusterTex, aEndingTextRogerBusterTex },                                 // ROGER_BUSTER
    { aEndingJamesMcCloudTex, aEndingTextJamesMcCloudTex },                               // JAMES_MCCLOUD
    { aEndingLeonTex, aEndingTextLeonTex },                                               // LEON
    { aEndingAntonioGusterTex, aEndingTextAntonioGusterTex },                             // ANTONIO_GUSTER
    { aEndingBlackShadowTex, aEndingTextBlackShadowTex },                                 // BLACK_SHADOW
    { aEndingMichaelChainTex, aEndingTextMichaelChainTex },                               // MICHAEL_CHAIN
    { aEndingJackLevinTex, aEndingTextJackLevinTex },                                     // JACK_LEVIN
    { aEndingSuperArrowTex, aEndingTextSuperArrowTex },                                   // SUPER_ARROW
    { aEndingMrsArrowTex, aEndingTextMrsArrowTex },                                       // MRS_ARROW
    { aEndingJohnTanakaTex, aEndingTextJohnTanakaTex },                                   // JOHN_TANAKA
    { aEndingBeastmanTex, aEndingTextBeastmanTex },                                       // BEASTMAN
    { aEndingZodaTex, aEndingTextZodaTex },                                               // ZODA
    { aEndingDrClashTex, aEndingTextDrClashTex },                                         // DR_CLASH
    { aEndingSilverNeelsenTex, aEndingTextSilverNeelsenTex },                             // SILVER_NEELSEN
    { aEndingBioRexTex, aEndingTextBioRexTex },                                           // BIO_REX
    { aEndingDraqTex, aEndingTextDraqTex },                                               // DRAQ
    { aEndingBillyTex, aEndingTextBillyTex },                                             // BILLY
    { aEndingTheSkullTex, aEndingTextTheSkullTex },                                       // THE_SKULL
    { aEndingBloodFalconTex, aEndingTextBloodFalconTex },                                 // BLOOD_FALCON
    { aEndingCaptainFalconAltTex, NULL },                                                 // CAPTAIN_FALCON 2
    { aEndingCaptainFalconStandardExpertTex, aEndingTextCaptainFalconStandardExpertTex }, // CAPTAIN_FALCON 3
    { aEndingSamuraiGorohAltTex, NULL },                                                  // SAMURAI_GOROH 2
    { aEndingJodySummerAltTex, NULL },                                                    // JODY_SUMMER 2
};

void* sFinalResultPositionDigitTexs[] = {
    aFinalResultPosition0Tex, aFinalResultPosition1Tex, aFinalResultPosition2Tex, aFinalResultPosition3Tex,
    aFinalResultPosition4Tex, aFinalResultPosition5Tex, aFinalResultPosition6Tex, aFinalResultPosition7Tex,
    aFinalResultPosition8Tex, aFinalResultPosition9Tex,
};

void* sFinalResultsPositionSuffixTexs[] = { aFinalResultPositionSuffixSTTex, aFinalResultPositionSuffixNDTex,
                                            aFinalResultPositionSuffixRDTex, aFinalResultPositionSuffixTHTex };

Gfx* D_i7_80098EC8[] = { D_5000178, D_5001E38, D_5002B18 };

f32 D_i7_80098ED4 = 0.3f;
f32 D_i7_80098ED8 = 1.0f;

s16 D_i7_80098EDC[] = { 1, 3, 4, 4, 4, 4, 4, 4, 5, -1 };

char sTotalRankingStr[] = "TOTAL RANKING";

const char* sCupNames[] = { "JACK CUP", "QUEEN CUP", "KING CUP", "JOKER CUP",
                            "EDIT CUP", "X CUP",     "DD-1 CUP", "DD-2 CUP" };

char sThanksForPlayingStr[] = "THANKS FOR PLAYING!!";

s32 func_i7_GetEndScreenIndex(s32 difficulty, s16 character, s8 customType) {
    s32 endScreenCharacterIndex;

    switch (character) {
        case CAPTAIN_FALCON:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 30;
            } else {
                switch (difficulty) {
                    case STANDARD:
                    case EXPERT:
                        endScreenCharacterIndex = 31;
                        break;
                    case MASTER:
                        endScreenCharacterIndex = character;
                        break;
                }
            }
            break;
        case SAMURAI_GOROH:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 32;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        case JODY_SUMMER:
            if (IS_SUPER_MACHINE(customType)) {
                endScreenCharacterIndex = 33;
            } else {
                endScreenCharacterIndex = character;
            }
            break;
        default:
            endScreenCharacterIndex = character;
            break;
    }
    return endScreenCharacterIndex;
}

bool func_i7_80092880(void) {
    s8* sp1C;
    s32 i;
    bool var_a1;

    sp1C = func_807084E4(0, 4 * 30 * 7);
    Save_UpdateCupSave(sp1C);

    var_a1 = false;
    sp1C += 3 * 30 * 7;
    for (i = 0; i < 30 * 7; i++, sp1C++) {
        if (*sp1C == 0) {
            break;
        }
    }
    if (i == 30 * 7) {
        var_a1 = true;
    }

    return var_a1;
}

extern s16 D_8079FC7C;
extern s8 gUnlockableLevel;
extern s8 D_8079FB28[];
extern RaceStats gCupRaceStats[1][6];
extern s16 D_8076C7A8;
extern s32 D_i2_800BF040;
extern s8 gGamePaused;
extern s32 gNumPlayers;
extern s32 gCourseIndex;
extern s32 gDifficulty;
extern s16 gPlayer1OverallPosition;
extern s32 gCupType;

void EndingCutscene_Init(void) {
    unk_8014BE28* var_v1;
    s32 cupFirstCourseIndex;
    s32 pad;
    Racer* playerRacer = &gRacers[0];
    s32 i;
    s32 j;
    void** endingTextures;
    s32 var_a0;

    D_8076C7A8 = D_i2_800BF040 = 3;
    gGamePaused = false;
    gNumPlayers = 1;
    cupFirstCourseIndex = (gCourseIndex / 6) * 6;
    gCourseIndex = COURSE_ENDING;
    sCupDifficulty = gDifficulty;
    gDifficulty = MASTER;
    sTotalRacersKOd = 0;

    for (j = 0; j < 6; j++) {
        sTotalRacersKOd += gCupRaceStats[0][j].racersKOd;
    }

    func_i2_800B934C();
    func_i3_80040158();
    func_8071D48C();
    func_807160A0();
    func_8070F0B0(gCourseCtx.courseData.venue, gCourseCtx.courseData.skybox);
    func_i3_800617A0();
    func_i2_800AB6B0();
    func_806F9774();
    func_806FB3AC();
    func_806FBBC8();
    func_806FE8F8(0);
    func_i7_80096BB0();
    func_i7_800956E8();
    sEndScreenState = END_SCREEN_INACTIVE;
    sEndScreenFade = 0;
    sEndScreenAlpha = 0;
    D_8009AD16 = 0;
    if (gPlayer1OverallPosition < 4) {
        D_8009AD16 |= 0xF;
    } else {
        D_8009AD16 |= 0x40;
    }
    if (D_8079FC7C != 0) {
        D_8079FC7C = 0;
        D_8009AD16 |= 0x10;
    } else if (gCupType == DD_2_CUP) {
        if ((D_8079FB28[0] >= 3) && (D_8079FB28[1] >= 3) && (gPlayer1OverallPosition == 1)) {
            D_8009AD16 |= 0x10;
        }
    } else if (gUnlockableLevel >= 2) {
        switch (sCupDifficulty) {
            case EXPERT:
            case MASTER:
                if (gCupType == JOKER_CUP && gPlayer1OverallPosition == 1) {
                    D_8009AD16 |= 0x10;
                }
                break;
        }
    }

    if (gPlayer1OverallPosition == 1) {
        switch (sCupDifficulty) {
            case STANDARD:
            case EXPERT:
            case MASTER:
                D_8009AD16 |= 0x20;
                break;
        }
    }

    D_i7_8009AD30 = 0.0f;
    D_i7_8009AD34 = 0;
    D_i7_8009AD28 = 0;
    D_i7_8009AD2C = 0;

    switch (gCupType) {
        case JACK_CUP:
            sCupNameIndex = 0;
            break;
        case QUEEN_CUP:
            sCupNameIndex = 1;
            break;
        case KING_CUP:
            sCupNameIndex = 2;
            break;
        case JOKER_CUP:
            sCupNameIndex = 3;
            break;
        case X_CUP:
            sCupNameIndex = 5;
            break;
        case EDIT_CUP:
            sCupNameIndex = 4;
            break;
        case DD_1_CUP:
            sCupNameIndex = 6;
            break;
        case DD_2_CUP:
            sCupNameIndex = 7;
            break;
    }
    sCupNameWidth = Font_GetStringWidth(sCupNames[sCupNameIndex], FONT_SET_3, 1);
    D_i7_8009AD3C = 0;
    sThanksForPlayingFade = 0;
    D_i7_8009AE48 = 0;
    var_a0 = 0;

    var_v1 = D_i7_8009AD48;
    for (i = 0; D_i7_80098EDC[i] != -1; i++) {
        var_v1->unk_04 = 0;
        var_v1->unk_00 = D_i7_80098EDC[i];
        switch (var_v1->unk_00) {
            case 1:
                var_v1->track = 0;
                var_v1->unk_08 = 28.0f;
                var_v1->unk_0C = 104.0f;
                var_v1->unk_06 = 0x1F;
                break;
            case 2:
                var_v1->track = 0;
                var_v1->unk_08 = 76.0f;
                var_v1->unk_06 = 0xC3;
                var_v1->unk_0C = 70.0f;
                break;
            case 3:
                var_v1->track = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_06 = 0x34;
                var_v1->unk_0C = 236.0f;
                break;
            case 5:
                var_v1->track = 0;
                var_v1->unk_08 = 0.0f;
                var_v1->unk_0C = 100.0f;
                var_v1->unk_06 = 0x10A;
                break;
            case 4:
                var_v1->track = (s16) (cupFirstCourseIndex + var_a0);
                var_v1->unk_08 = 76.0f;

                if (var_a0 != 0) {
                    var_v1->unk_0C = 120.0f;
                } else {
                    var_v1->unk_0C = 120.0f;
                }

                var_v1->unk_06 = 0x50;
                var_a0++;
                break;
        }
        var_v1++;
    }
    D_i7_8009AD40 = var_v1 - D_i7_8009AD48;
    D_i7_8009AEA4 = func_i7_80092880();
    func_i2_800AE7C4(aCongratulationsTex, TEX_SIZE(aCongratulationsTex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition0Tex, TEX_SIZE(aFinalResultPosition0Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition1Tex, TEX_SIZE(aFinalResultPosition1Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition2Tex, TEX_SIZE(aFinalResultPosition2Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition3Tex, TEX_SIZE(aFinalResultPosition3Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition4Tex, TEX_SIZE(aFinalResultPosition4Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition5Tex, TEX_SIZE(aFinalResultPosition5Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition6Tex, TEX_SIZE(aFinalResultPosition6Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition7Tex, TEX_SIZE(aFinalResultPosition7Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition8Tex, TEX_SIZE(aFinalResultPosition8Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPosition9Tex, TEX_SIZE(aFinalResultPosition9Tex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPositionSuffixSTTex, TEX_SIZE(aFinalResultPositionSuffixSTTex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPositionSuffixNDTex, TEX_SIZE(aFinalResultPositionSuffixNDTex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPositionSuffixRDTex, TEX_SIZE(aFinalResultPositionSuffixRDTex, sizeof(u16)), 0, 0, 0);
    func_i2_800AE7C4(aFinalResultPositionSuffixTHTex, TEX_SIZE(aFinalResultPositionSuffixTHTex, sizeof(u16)), 0, 0, 0);

    if (D_8009AD16 & 0x20) {

        endingTextures =
            sEndingTextures[func_i7_GetEndScreenIndex(sCupDifficulty, playerRacer->character, playerRacer->customType)];

        sEndingTex = func_i2_800AE7C4(endingTextures[0], 168 * 99 * sizeof(u16), 0, 1, 0);

        if (endingTextures[1] != NULL) {
            sEndingTextTex = func_i2_800AE7C4(endingTextures[1], 196 * 16 * sizeof(u16), 0, 1, 0);
        } else {
            sEndingTextTex = NULL;
        }
    }
}

extern s32 D_8076C7C0;
extern s32 D_8079A35C;

s32 EndingCutscene_Update(void) {

    Controller_SetGlobalInputs(&gSharedController);
    D_i7_8009AD10 = &D_8009A3A0[D_8079A35C];
    func_i2_800AB82C();
    func_80726554();
    func_80717294();
    func_i3_80061C2C();
    func_800B94D8();
    func_8070304C();
    func_i7_80096DAC();
    if (D_i7_8009AD3C != 0) {
        func_i7_FadeInThanksForPlaying();
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        func_i7_FadeEndScreen();
    }
    func_i7_8009580C();

    switch (func_i7_8009318C()) {
        case 1:
            return GAMEMODE_FLX_MAIN_MENU;
        case 2:
            if (D_i7_8009AEA4 != 0) {
                D_8076C7C0 = GAMEMODE_FLX_UNSKIPPABLE_CREDITS;
                return GAMEMODE_16;
            }
            return GAMEMODE_FLX_UNSKIPPABLE_CREDITS;
        case 0:
        default:
            return GAMEMODE_GP_END_CS;
    }
}

extern u16 gInputButtonPressed;
extern s32 D_i3_8006CFF8;

s32 func_i7_8009318C(void) {
    unk_8014BE28* var_v0;
    Racer* racer;
    s32 sp1C;
    f32 var_fv0;
    bool var_a0;
    s32 i;

    sp1C = 0;
    switch (D_i7_8009AD28) {
        case 0:
            if (D_i7_8009AD2C >= 120) {
                D_i7_8009AD28 = 1;
                D_i7_8009AD2C = 0;
            } else {
                D_i7_8009AD2C++;
            }
            break;
        case 1:
            D_i7_8009AD2C++;
            var_fv0 = (f32) D_i7_8009AD2C / 30.0f;
            if (var_fv0 >= 1.0f) {
                var_fv0 = 1.0f;
            }
            D_i7_8009AD34 = 255.0f * var_fv0;
            if (D_i7_8009AD2C >= 120) {
                D_i7_8009AD28 = 2;
                D_i7_8009AD34 = 255;
                D_i7_8009AD2C = 0;
                func_8071985C(1);
            }
            break;
        case 2:
            D_i7_8009AD34 = 255;
            if (D_i7_8009AD2C <= 300) {
                D_i7_8009AD2C++;
            }
            if ((D_i7_8009AD2C == 300) && (D_8009AD16 & 8)) {
                D_i7_8009B168 = 1;
            }
            D_i7_8009AD30 -= 0.5f;

            var_a0 = true;
            var_v0 = D_i7_8009AD48;
            for (i = 0; i < D_i7_8009AD40; i++) {
                if (var_v0->unk_00 != 0) {
                    var_a0 = false;
                }
                var_v0++;
            }
            if (var_a0) {
                D_i7_8009AD28 = 6;
                D_i7_8009AD2C = 0;
                D_i7_8009B168 = 0;
                if (D_8009AD16 & 2) {
                    D_i3_8006CFF8 = 1;
                    D_i7_8009AD28 = 3;
                }
            }
            break;
        case 3:
            var_a0 = true;

            for (i = 0, racer = gRacers; i < 3; i++) {
                if (racer->speed > 0.1f) {
                    var_a0 = false;
                    break;
                }
                racer++;
            }

            if (var_a0) {
                D_i7_8009AD28 = 4;
                D_i7_8009AD2C = 0;
            }
            break;
        case 4:
            D_i7_8009AD2C++;

            if (D_i7_8009AD2C == 1) {
                D_i7_8009AE48 |= 4;
                func_8071985C(4);
            }
            if (D_i7_8009AD2C == 271) {
                D_i7_8009AE48 |= 2;
                func_8071985C(3);
            }
            if (D_i7_8009AD2C == 541) {
                D_i7_8009AE48 |= 1;
                func_8071985C(2);
            }
            if (D_i7_8009AD2C > 1020) {
                if (D_8009AD16 & 0x20) {
                    D_i7_8009AD28 = 5;
                    sEndScreenState = END_SCREEN_FADE_IN;
                } else {
                    D_i7_8009AD28 = 6;
                }
                D_i7_8009AD2C = 0;
            }
            break;
        case 5:
            if (sEndScreenState == END_SCREEN_INACTIVE) {
                D_i7_8009AD28 = 6;
                D_i7_8009AD2C = 0;
            }
            break;
        case 6:
            D_i7_8009AD2C++;
            if (D_i7_8009AD2C > 0) {
                D_i7_8009AD28 = 7;
                D_i7_8009AD2C = 0;
                if (D_8009AD16 & 1) {
                    D_i7_8009B168 = 2;
                }
            }
            break;
        case 7:
            if ((D_i7_8009B168 == 0) && (D_i7_8009AEB2 == 0)) {
                D_i7_8009AD2C++;
                if (D_i7_8009AD2C == 0x3C) {
                    D_i7_8009AD3C = 1;
                    func_80742028();
                }
            }
            if (D_i7_8009AD2C >= 360) {
                D_i7_8009AD2C = 360;
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    sp1C = 1;
                }
            }
            break;
    }

    var_v0 = D_i7_8009AD48;
    for (i = 0; i < D_i7_8009AD40; i++) {
        switch (var_v0->unk_00) {
            case 1:
                if ((D_i7_8009AD28 != 0) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
            case 2:
                if ((D_i7_8009AD28 != 0) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
            default:
                if ((D_i7_8009AD28 == 2) && (var_v0->unk_04 == 0)) {
                    var_v0->unk_04 = 1;
                }
                break;
        }
        var_v0++;
    }
    if ((sp1C != 0) && (D_8009AD16 & 0x10)) {
        sp1C = 2;
    }
    return sp1C;
}

extern Gfx D_8076CE28[];
extern Player gPlayers[];
extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A364;
extern GfxPool* gGfxPool;
extern GfxPool D_1000000;
extern Vtx* D_800D65D0;
extern Vtx* D_807A15DC;
extern Vtx* D_807A15E0;

Gfx* EndingCutscene_Draw(Gfx* gfx) {

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
    gfx = func_i7_80095D14(gfx);

    gSPLoadUcodeL(gfx++, gspF3DLX2_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);
    gDPPipeSync(gfx++);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(gFrameBuffers[D_8079A364]));
    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
    gSPMatrix(gfx++, D_1000000.unk_1A208, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    gfx = func_80713E38(gfx, 0, 0);
    gfx = func_80727F54(gfx, 0);
    gfx = func_i7_800969B8(gfx);
    return func_i7_80093A18(gfx);
}

Gfx* func_i7_80093A18(Gfx* gfx) {
    unk_8014BE28* var_s1;
    f32 textureTop;
    s32 i;

    textureTop = D_i7_8009AD30;

    var_s1 = D_i7_8009AD48;
    for (i = 0; i < D_i7_8009AD40; i++, var_s1++) {
        textureTop += var_s1->unk_0C;
        if ((var_s1->unk_00 == 0) || (var_s1->unk_04 == 0) || textureTop > 232.0f) {
            continue;
        }

        if ((var_s1->unk_06 + textureTop) < 8.0f) {
            var_s1->unk_00 = 0;
            continue;
        }
        switch (var_s1->unk_00) {
            case 1:
                if (D_8009AD16 & 4) {
                    gDPPipeSync(gfx++);
                    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8009AD34);

                    gfx = func_8070A99C(gfx, func_i2_800AEA90(aCongratulationsTex), var_s1->unk_08, textureTop, 264, 31,
                                        G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case 2:
                gDPPipeSync(gfx++);
                gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_i7_8009AD34);

                gfx = func_8070A99C(gfx, sEndingTex, var_s1->unk_08, textureTop, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                                    1, 1, 0, 0);

                if (sEndingTextTex != NULL) {
                    gfx = func_8070A99C(gfx, sEndingTextTex, var_s1->unk_08 + -14.0f, textureTop + 99.0f + 10.0f, 196,
                                        16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
                }
                break;
            case 3:
                gfx = func_i7_DrawFinalResultsCupInfo(gfx, var_s1, textureTop);
                break;
            case 4:
                gfx = func_i7_DrawFinalResultsRaceResult(gfx, var_s1, textureTop);
                break;
            case 5:
                gfx = func_i7_800943A0(gfx, var_s1, textureTop);
                break;
        }
    }

    if (D_i7_8009AD3C != 0) {
        gfx = func_i7_DrawThanksForPlayingWindow(gfx);
    }
    if (sEndScreenState != END_SCREEN_INACTIVE) {
        gfx = func_i7_DrawEndScreen(gfx);
    }
    return gfx;
}

extern const char* gTrackNames[];

Gfx* func_i7_DrawFinalResultsRaceResult(Gfx* gfx, unk_8014BE28* arg1, f32 baseYPos) {
    s32 cupTrackNo;
    f32 var_fv0;
    bool shouldHighlight;
    s32 pad[2];
    RaceStats* raceStats;
    const char* trackName;

    cupTrackNo = arg1->track % 6;
    raceStats = &gCupRaceStats[0][cupTrackNo];
    trackName = gTrackNames[arg1->track];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;

    gfx = Font_DrawString(gfx, (var_fv0 + 2.0f) - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2),
                          (baseYPos + 16.0f) + 2.0f, trackName, 1, FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    gfx = Font_DrawString(gfx, var_fv0 - (Font_GetStringWidth(trackName, FONT_SET_3, 1) / 2), (baseYPos + 16.0f),
                          trackName, 1, FONT_SET_3, 0);
    gSPDisplayList(gfx++, D_8014940);

    if (raceStats->position == 1) {
        shouldHighlight = true;
    } else {
        shouldHighlight = false;
    }

    gfx = func_i7_DrawFinalResultsPosition(gfx, 50, baseYPos + 26.0f, raceStats->position, shouldHighlight);
    gDPPipeSync(gfx++);
    if (0) {}
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    if (0) {}
    gDPLoadTextureBlock(gfx++, D_303C3F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 224, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gfx = func_i3_DrawTimerScisThousandths(gfx, raceStats->raceTime, 110, (baseYPos + 28.0f), 1.0f);
    gDPPipeSync(gfx++);
    gfx = func_i3_DrawSpeed(gfx, 194, (baseYPos + 28.0f), raceStats->maxSpeed, false, false);
    gDPPipeSync(gfx++);
    return func_i7_DrawResultsRacersKOd(gfx, 110, (baseYPos + 48.0f), raceStats->racersKOd);
}

Gfx* func_i7_DrawFinalResultsPosition(Gfx* gfx, s32 xPos, s32 yPos, s32 position, bool shouldHighlight) {
    s32 i;
    s32 xOffset;
    s32 width;
    s32 positionSuffix;
    s32 digits[2];
    s32 positionVar;
    s32 digit;

    positionVar = position;

    if ((position == 1) || (position == 21)) {
        positionSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        positionSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        positionSuffix = POSITION_SUFFIX_RD;
    } else {
        positionSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < 2; i++) {
        digits[i] = positionVar % 10;
        positionVar /= 10;
    }

    gDPPipeSync(gfx++);

    if (shouldHighlight) {
        gfx = func_8070D4A8(gfx, 0);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 250, 250, 255, 255);
    }

    for (i = 0; i < 2; i++) {
        digit = digits[1 - i];
        if ((i == 0) && (digit == 0)) {
            xPos += 16;
            continue;
        }

        if (digit != 1) {
            xOffset = 0;
            width = 16;
        } else {
            xOffset = 8;
            width = 8;
        }
        gfx = func_8070A99C(gfx, func_i2_800AEA90(sFinalResultPositionDigitTexs[digit]), xPos + xOffset, yPos, width,
                            16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
        xPos += 16;
    }

    return func_8070A99C(gfx, func_i2_800AEA90(sFinalResultsPositionSuffixTexs[positionSuffix]), xPos, yPos, 16, 16,
                         G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0, 0, 0);
}

Gfx* func_i7_800943A0(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    s32 i;
    f32 temp_fa1;
    f32 left;
    s32 positionDigits[2];
    s32 ordinalSuffix;
    s32 position;
    s32 positionDigit;
    char racersKOdStr[4];

    position = gPlayer1OverallPosition;
    if ((position == 1) || (position == 21)) {
        ordinalSuffix = POSITION_SUFFIX_ST;
    } else if ((position == 2) || (position == 22)) {
        ordinalSuffix = POSITION_SUFFIX_ND;
    } else if ((position == 3) || (position == 23)) {
        ordinalSuffix = POSITION_SUFFIX_RD;
    } else {
        ordinalSuffix = POSITION_SUFFIX_TH;
    }

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigits[i] = position % 10;
        position /= 10;
    }

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    left = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = Font_DrawString(gfx, (left + 2.0f) - (Font_GetStringWidth(sTotalRankingStr, FONT_SET_3, 1) / 2),
                          temp_fa1 + 2.0f, sTotalRankingStr, 1, FONT_SET_3, 0);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 250, 0, 255);
    gfx = Font_DrawString(gfx, left - (Font_GetStringWidth(sTotalRankingStr, FONT_SET_3, 1) / 2), temp_fa1,
                          sTotalRankingStr, 1, FONT_SET_3, 0);
    temp_fa1 += 10.0f;
    left = 122.0f;
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < ARRAY_COUNT(positionDigits); i++) {
        positionDigit = positionDigits[1 - i];
        if ((i == 0) && (positionDigit == 0)) {
            left += 28.0f;
            continue;
        }

        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, aPositionDigitTexs[positionDigit], G_IM_FMT_RGBA, G_IM_SIZ_16b, 28, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) (temp_fa1) << 2, (s32) (left + 28.0f) << 2,
                                (s32) (temp_fa1 + 32.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        left += 28.0f;
    }

    gDPLoadTextureBlock(gfx++, aPositionOrdinalSuffixTexs[ordinalSuffix], G_IM_FMT_RGBA, G_IM_SIZ_16b, 20, 20, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gSPScisTextureRectangle(gfx++, (s32) (left) << 2, (s32) ((temp_fa1 + 12.0f)) << 2, (s32) (left + 20.0f) << 2,
                            (s32) ((temp_fa1 + 12.0f) + 20.0f) << 2, 0, 0, 0, 1 << 10, 1 << 10);

    gfx = func_i7_DrawResultsRacersKOd(gfx, 0x6E, arg2 + 70.0f, sTotalRacersKOd);

    if (sTotalRacersKOd > 0) {

        for (i = 0; i < 4; i++) {
            racersKOdStr[i] = 0;
        }

        sprintf(racersKOdStr, "%d", sTotalRacersKOd);

        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

        i = sTotalRacersKOd / 10;
        if (sTotalRacersKOd % 10) {
            i++;
        }
        gfx = Font_DrawString(gfx, 0x6E, (arg2 + 70.0f) + 20.0f + (i * 10), racersKOdStr, 1, FONT_SET_3, 0);
    }
    return gfx;
}

extern const char* gDifficultyNames[];

Gfx* func_i7_DrawFinalResultsCupInfo(Gfx* gfx, unk_8014BE28* arg1, f32 arg2) {
    UNUSED s32 pad;
    f32 var_fv0;
    f32 temp_fa1;
    const char* name;

    name = sCupNames[sCupNameIndex];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    var_fv0 = 160.0f;
    temp_fa1 = arg2 + 16.0f;

    gfx = Font_DrawString(gfx, (var_fv0 + 2.0f) - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), temp_fa1 + 2.0f, name,
                          1, FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = Font_DrawString(gfx, var_fv0 - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), temp_fa1, name, 1, FONT_SET_3,
                          0);

    temp_fa1 += 20.0f;
    name = gDifficultyNames[sCupDifficulty];

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);

    gfx = Font_DrawString(gfx, (var_fv0 + 2.0f) - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), temp_fa1 + 2.0f, name,
                          1, FONT_SET_3, 0);

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    return Font_DrawString(gfx, var_fv0 - (Font_GetStringWidth(name, FONT_SET_3, 1) / 2), temp_fa1, name, 1, FONT_SET_3,
                           0);
}

void func_i7_FadeInThanksForPlaying(void) {
    if (sThanksForPlayingFade < 120) {
        sThanksForPlayingFade++;
    }
}

Gfx* func_i7_DrawThanksForPlayingWindow(Gfx* gfx) {
    static s32 sThanksForPlayingLeft;
    static s32 sThanksForPlayingTop;
    static s32 sThanksForPlayingWidth;
    static s32 sThanksForPlayingBackgroundAlpha;

    sThanksForPlayingBackgroundAlpha = (sThanksForPlayingFade * 255) / 120;

    gfx = func_80709C90(gfx, 12, 8, 308, 232, 0, 0, 0, sThanksForPlayingBackgroundAlpha);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sThanksForPlayingBackgroundAlpha);

    sThanksForPlayingWidth = Font_GetStringWidth(sThanksForPlayingStr, FONT_SET_1, 1);
    sThanksForPlayingLeft = (SCREEN_WIDTH - sThanksForPlayingWidth) / 2;
    sThanksForPlayingTop = SCREEN_HEIGHT / 2;

    return Font_DrawString(gfx, sThanksForPlayingLeft, sThanksForPlayingTop, sThanksForPlayingStr, 1, FONT_SET_1, 1);
}

void func_i7_FadeEndScreen(void) {
    switch (sEndScreenState) {
        case END_SCREEN_FADE_IN:
            sEndScreenFade++;
            sEndScreenAlpha = (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_WAIT;
                sEndScreenFade = 0;
                sEndScreenAlpha = 255;
            }
            return;
        case END_SCREEN_WAIT:
            sEndScreenFade++;
            if (sEndScreenFade >= 180) {
                sEndScreenState = END_SCREEN_FADE_OUT;
                sEndScreenFade = 0;
            }
            break;
        case END_SCREEN_FADE_OUT:
            sEndScreenFade++;
            sEndScreenAlpha = 255 - (sEndScreenFade * 255) / 120;
            if (sEndScreenFade >= 120) {
                sEndScreenState = END_SCREEN_INACTIVE;
                sEndScreenFade = 0;
                sEndScreenAlpha = 0;
            }
            break;
    }
}

Gfx* func_i7_DrawEndScreen(Gfx* gfx) {

    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, sEndScreenAlpha);

    gfx = func_8070A99C(gfx, sEndingTex, 76, 70, 168, 99, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    if (sEndingTextTex != NULL) {
        gfx = func_8070A99C(gfx, sEndingTextTex, 62, 179, 196, 16, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1, 0, 0);
    }
    return gfx;
}

Gfx* func_i7_DrawResultsRacersKOd(Gfx* gfx, s32 left, s32 top, s32 racersKOd) {
    s32 i;
    s32 j;
    s32 temp;
    s32 pad;
    s32 numBlocks;
    s32 remainder;

    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    gDPLoadTextureBlock(gfx++, aHudRacersKOdTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    numBlocks = racersKOd / 10;
    remainder = racersKOd % 10;

    for (i = 0; i < numBlocks; i++) {
        temp = i * 10;
        for (j = 0; j < 10; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + temp) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + temp) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }

    if (remainder > 0) {
        for (j = 0; j < remainder; j++) {
            gSPScisTextureRectangle(gfx++, (left + j * 10) << 2, (top + numBlocks * 10) << 2, (left + 8 + j * 10) << 2,
                                    (top + 8 + numBlocks * 10) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    return gfx;
}

void func_i7_800956E8(void) {
    f32 temp_fa0;
    s32 i;
    unk_8014BEC8* var_v0 = D_i7_8009ADE8;
    Vec3f* var = D_i7_8009AE50;

    if (1) {}

    for (i = 0; i < 3; var_v0++, i++) {
        var_v0->unk_00 = 0;
        var_v0->unk_02 = 0;
        var_v0->unk_04 = 0;
        var_v0->unk_10 = 0.0f;
        var_v0->unk_08 = 0.0f;
        var_v0->unk_0C = -160.0f;
        var_v0->unk_14 = 0.0f;
        var_v0->unk_18 = 0.0f;
        var_v0->unk_1C = 1.0f;
    }
    i = Math_Round(DEG_TO_FZXANG2(30));
    temp_fa0 = COS(i) * 60.0f;

    var->x = 0.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;

    var->x = 30.0f;
    var->y = 0.0f;
    var->z = temp_fa0;
    var++;

    var->x = -30.0f;
    var->y = 0.0f;
    var->z = temp_fa0;
    var++;

    var->x = -60.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;

    var->x = -30.0f;
    var->y = 0.0f;
    var->z = 0.0f - temp_fa0;
    var++;

    var->x = 30.0f;
    var->y = 0.0f;
    var->z = 0.0f - temp_fa0;
    var++;

    var->x = 60.0f;
    var->y = 0.0f;
    var->z = 0.0f;
    var++;
}

f32 D_i7_80098F38[] = { 0.0f, -40.0f, -60.0f };

void func_i7_8009580C(void) {
    unk_8014BEC8* var_s2;
    Racer* var_s4;
    s32 i;
    s32 j;
    s32 var_a1;
    s32 var_a2;
    Vtx* vtx;
    f32 var_fv0;
    f32 temp_fv0;

    for (i = 0, var_s2 = D_i7_8009ADE8, var_s4 = gRacers; i < 3; i++, var_s2++, var_s4++) {
        switch (var_s2->unk_00) {
            case 0:
                if (D_i7_8009AE48 & (1 << i)) {
                    var_s2->unk_00 = 1;
                    var_s2->unk_04 = 0;
                    var_s2->unk_08 = var_s4->unk_180.x;
                    var_s2->unk_10 = var_s4->unk_180.z;
                    var_s2->unk_14 = var_s4->unk_C0.x.x;
                    var_s2->unk_18 = var_s4->unk_C0.x.y;
                    var_s2->unk_1C = var_s4->unk_C0.x.z;
                    func_8074122C(0x40);
                }
                break;
            case 2:
                break;
            case 1:
                var_s2->unk_02 |= 3;
                var_s2->unk_04++;
                var_fv0 = var_s2->unk_04 / 60.0f;

                if (var_fv0 > 1.0f) {
                    var_fv0 = 1.0f;
                }

                vtx = D_i7_8009AD10->unk_180[i];
                for (j = 0; j < 13; j++) {
                    if (j < 7) {
                        var_a1 = D_i7_8009AE50[j].x;
                        var_a2 = D_i7_8009AE50[j].z;
                    } else if (j == 12) {
                        var_a1 = D_i7_8009AE50[1].x * var_fv0;
                        var_a2 = D_i7_8009AE50[1].z * var_fv0;
                    } else {
                        var_a1 = D_i7_8009AE50[j - 5].x * var_fv0;
                        var_a2 = D_i7_8009AE50[j - 5].z * var_fv0;
                    }

                    SET_VTX(vtx, var_a1, 0, var_a2, 0, 0, 0, 0, 0, 255);
                    vtx++;
                }

                var_s2->unk_0C = (((D_i7_80098F38[i] - -160.0f) * var_s2->unk_04) / 270.0f) + -160.0f;
                if (var_s2->unk_04 >= 0x10E) {
                    var_s2->unk_00 = 2;
                    var_s2->unk_0C = D_i7_80098F38[i];
                    var_s2->unk_04 = 0;
                }
                temp_fv0 = (var_s2->unk_0C + 120.0f) - var_s4->unk_168.y;
                if (temp_fv0 > 0.0f) {
                    var_s4->unk_A4 += temp_fv0;
                }
                break;
        }

        if (var_s2->unk_02 & 2) {
            func_806F7FCC(&D_i7_8009AD10->unk_C0[i], NULL, D_i7_80098ED8, D_i7_80098ED8, D_i7_80098ED8, var_s2->unk_14,
                          var_s2->unk_18, var_s2->unk_1C, 0.0f, 1.0f, 0.0f, var_s2->unk_08, 0.0f, var_s2->unk_10);
        }
        if (var_s2->unk_02 & 1) {
            func_806F7FCC(&D_i7_8009AD10->unk_00[i], NULL, D_i7_80098ED4, D_i7_80098ED4, D_i7_80098ED4, var_s2->unk_14,
                          var_s2->unk_18, var_s2->unk_1C, 0.0f, 1.0f, 0.0f, var_s2->unk_08, var_s2->unk_0C,
                          var_s2->unk_10);
        }
    }
}

#ifdef NON_MATCHING
Gfx* func_i7_80095D14(Gfx* gfx) {
    s32 i;

    gSPClearGeometryMode(gfx++, 0xFFFFFFFF);
    gSPSetGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CLIPPING);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTextureDetail(gfx++, G_TD_CLAMP);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);

    gDPPipeSync(gfx++);
    // gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetRenderMode(gfx++, (G_RM_AA_ZB_OPA_SURF) & ~Z_CMP, (G_RM_AA_ZB_OPA_SURF2) & ~Z_CMP);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetDepthSource(gfx++, G_ZS_PRIM);
    gDPSetPrimDepth(gfx++, 0x7FC0, 0);

    for (i = 0; i < 3; i++) {
        if (!(D_i7_8009ADE8[i].unk_02 & 2)) {
            continue;
        }
        gSPMatrix(gfx++, &D_i7_8009AD10->unk_C0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPVertex(gfx++, D_i7_8009AD10->unk_180[i], 13, 0);
        gSP2Triangles(gfx++, 0, 7, 1, 0, 0, 8, 2, 0);
        gSP2Triangles(gfx++, 0, 9, 3, 0, 0, 10, 4, 0);
        gSP2Triangles(gfx++, 0, 11, 5, 0, 0, 12, 6, 0);
    }

    gSPTexture(gfx++, 0xFFFF, 0xFFFF, 0, 0, G_ON);
    gDPPipeSync(gfx++);

    gDPSetDepthSource(gfx++, G_ZS_PIXEL);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < 3; i++) {
        if (!(D_i7_8009ADE8[i].unk_02 & 1)) {
            continue;
        }
        gSPMatrix(gfx++, &D_i7_8009AD10->unk_00[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_i7_80098EC8[i]);
    }

    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i7/ending/func_i7_80095D14.s")
#endif
