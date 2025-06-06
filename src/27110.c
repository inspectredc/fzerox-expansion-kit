#include "global.h"
#include "unk_gfx.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_assets.h"
#include "fzx_machine.h"

s32 gTotalRacers;
Racer* sLastRacer;
Racer* sRivalRacer;
Vtx* D_807A15DC;
Vtx* D_807A15E0;
s16 gPlayerLives[4];
s16 D_807A15F0[4];
s16 D_807A15F8[4];
f32 gPlayerEngine[4];
s32 D_807A1610[4];
s32 D_807A1620[4];
s32 D_807A1630[4];
s32 D_807A1640[4];
Racer* gRacersByPosition[30];
s32 D_807A16C8;
s16 D_807A16CC;
s16 D_807A16CE;
s16 D_807A16D0;
s16 gRacersRetired;
s16 gRacersFinished;
s16 gCpuRacersRetired;
s16 gPlayerRacersRetired;
s16 gPlayerRacersFinished;
s16 sLastMultiplayerTotalRacerCount;
s16 sLastMultiplayerPlayerCount;
s16 D_807A16E0;
s16 gRacersKOd;
s16 D_807A16E4;
s16 D_807A16E6;
s32 sRaceFrameCount;
s32 gPracticeBestLap;
s16 gStartNewBestLap;
s16 D_807A16F2;
s16 D_807A16F4;
s16 D_807A16F6;
Vec3s* D_807A16F8;
Vec3s* D_807A16FC;
s32 D_807A1700;
Ghost gGhosts[3];
Ghost* gFastestGhost;
s8 sGhostReplayRecordingBuffer[16200];
s32 sGhostReplayRecordingSize;
s32 sGhostReplayRecordingEnd;
s32 sReplayRecordFrameCount;
s8* sGhostReplayRecordingPtr;
s32 sReplayRecordPosX;
s32 sReplayRecordPosY;
s32 sReplayRecordPosZ;
s16 D_807B14F4;
s16 D_807B14F6;
s16 D_807B14F8;
s16 D_807B14FA;
GhostRacer gGhostRacers[3];
s32 D_807B159C;
GhostRacer* gFastestGhostRacer;
UNUSED s32 D_807B15A4;
s32 gRaceIntroTimer;
RacerPairInfo sRacerPairInfo[TOTAL_RACER_COUNT * (TOTAL_RACER_COUNT - 1) / 2];
f32 D_807B37AC;
f32 D_807B37B0;
f32 D_807B37B4;
s32 D_807B37B8[4];
s32 D_807B37C8;
f32 D_807B37CC;
f32 D_807B37D0;
s16 D_807B37D4;
Machine gMachines[30];
CustomMachineInfo sCustomMachineInfo[30];
u8 D_807B3C14[7];

TexturePtr sPosition1PMarkerTexs[] = {
    aFirstPlaceMarker1PTex,
    aSecondPlaceMarker1PTex,
    aThirdPlaceMarker1PTex,
};

TexturePtr sPositionMPMarkerTexs[] = {
    aFirstPlaceMarkerMPTex,
    aSecondPlaceMarkerMPTex,
    aThirdPlaceMarkerMPTex,
};

TexturePtr D_8076D8D8[] = {
    aExplosion1Tex, aExplosion2Tex, aExplosion3Tex, aExplosion4Tex,
    aExplosion5Tex, aExplosion6Tex, aExplosion7Tex, aExplosion8Tex,
};

// Machine Models
Gfx* D_8076D8F8[] = {
    D_9001210, D_9001DA0, D_90027D0, D_9003050, D_9003870, D_9003F90, D_900CF48, D_90057A8, D_90061A0, D_9006A70,
    D_90078F0, D_9008060, D_90089A0, D_9009358, D_9009980, D_900A150, D_900AC40, D_900B288, D_900BD28, D_900C550,
    D_9004B98, D_900D898, D_900DFF8, D_900E698, D_900EFE8, D_900F790, D_90100F8, D_9010C38, D_90113D8, D_9011EA8,
};

Gfx* D_8076D970[] = {
    D_9015400, D_9015938, D_9015658, D_9014B40, D_9014DE0, D_9015088, D_90148F8,
};

Gfx* D_8076D98C[] = {
    D_9015B58, D_9017350, D_9016DA0, D_9015F50, D_9016298, D_9016530, D_9016948,
};

Gfx* D_8076D9A8[] = {
    D_90186C0, D_9017B18, D_9018230, D_9017BF0, D_90183F0, D_9017D20, D_9017EC8,
};

Vtx* D_8076D9C4[] = {
    D_3004F18, D_3006C78, D_3008C18, D_300A4E8, D_300BB78, D_300D3F8, D_3020758, D_30104F8, D_3011778,
    D_3012EC8, D_30140D8, D_3015418, D_3016958, D_30177D8, D_3018E98, D_301A2E8, D_301B7B8, D_301CA98,
    D_301E058, D_301F328, D_300E9A8, D_3022178, D_3023358, D_3024D78, D_3025DB8, D_3027068, D_30285C8,
    D_3029648, D_302A908, D_302B9F8, D_3036A78, D_3036EB8, D_30372F8, D_3037738, D_3037B78, D_3037FB8,
    D_30383F8, D_3038838, D_3038C78, D_30390B8, D_30394F8, D_3039938, D_3039D78, D_303A1B8,
};

TexturePtr D_8076DA74[] = {
    D_3004F58, D_3006CB8, D_3008C58, D_300A528, D_300BBB8, D_300D438, D_3020798, D_3010538, D_30117B8,
    D_3012F08, D_3014118, D_3015458, D_3016998, D_3017818, D_3018ED8, D_301A328, D_301B7F8, D_301CAD8,
    D_301E098, D_301F368, D_300E9E8, D_30221B8, D_3023398, D_3024DB8, D_3025DF8, D_30270A8, D_3028608,
    D_3029688, D_302A948, D_302BA38, D_3036AB8, D_3036EF8, D_3037338, D_3037778, D_3037BB8, D_3037FF8,
    D_3038438, D_3038878, D_3038CB8, D_30390F8, D_3039538, D_3039978, D_3039DB8, D_303A1F8,
};

u8 D_8076DB24[] = { 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28,
                    0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27, 0x28, 0x29, 0x25, 0x2B, 0x2A, 0x26, 0x27,
                    0x28, 0x29, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F,
                    0x20, 0x21, 0x22, 0x1E, 0x24, 0x23, 0x1F, 0x20, 0x21, 0x22 };

// Machine Load Textures
Gfx* D_8076DB58[] = {
    D_8022FE40, D_80230E60, D_80231E80, D_80232EA0, D_80233EC0, D_80234EE0, D_80235F00, D_80236F20,
    D_80237F40, D_80238F60, D_80239F80, D_8023AFA0, D_8023BFC0, D_8023CFE0, D_8023E000, D_8023F020,
    D_80240040, D_80241060, D_80242080, D_802430A0, D_802440C0, D_802450E0, D_80246100, D_80247120,
    D_80248140, D_80249160, D_8024A180, D_8024B1A0, D_8024C1C0, D_8024D1E0,
};

// Machine Models (6 Different LOD)
Gfx* D_8076DBD0[] = {
    D_8022FFD8, D_802303C8, D_80230718, D_80230A00, D_80230C70, D_7045098,  D_80230FF8, D_802313E8, D_80231738,
    D_80231A20, D_80231C90, D_7045098,  D_80232018, D_80232408, D_80232758, D_80232A40, D_80232CB0, D_7045098,
    D_80233038, D_80233428, D_80233778, D_80233A60, D_80233CD0, D_7045098,  D_80234058, D_80234448, D_80234798,
    D_80234A80, D_80234CF0, D_7045098,  D_80235078, D_80235468, D_802357B8, D_80235AA0, D_80235D10, D_7045098,
    D_80236098, D_80236488, D_802367D8, D_80236AC0, D_80236D30, D_7045098,  D_802370B8, D_802374A8, D_802377F8,
    D_80237AE0, D_80237D50, D_7045098,  D_802380D8, D_802384C8, D_80238818, D_80238B00, D_80238D70, D_7045098,
    D_802390F8, D_802394E8, D_80239838, D_80239B20, D_80239D90, D_7045098,  D_8023A118, D_8023A508, D_8023A858,
    D_8023AB40, D_8023ADB0, D_7045098,  D_8023B138, D_8023B528, D_8023B878, D_8023BB60, D_8023BDD0, D_7045098,
    D_8023C158, D_8023C548, D_8023C898, D_8023CB80, D_8023CDF0, D_7045098,  D_8023D178, D_8023D568, D_8023D8B8,
    D_8023DBA0, D_8023DE10, D_7045098,  D_8023E198, D_8023E588, D_8023E8D8, D_8023EBC0, D_8023EE30, D_7045098,
    D_8023F1B8, D_8023F5A8, D_8023F8F8, D_8023FBE0, D_8023FE50, D_7045098,  D_802401D8, D_802405C8, D_80240918,
    D_80240C00, D_80240E70, D_7045098,  D_802411F8, D_802415E8, D_80241938, D_80241C20, D_80241E90, D_7045098,
    D_80242218, D_80242608, D_80242958, D_80242C40, D_80242EB0, D_7045098,  D_80243238, D_80243628, D_80243978,
    D_80243C60, D_80243ED0, D_7045098,  D_80244258, D_80244648, D_80244998, D_80244C80, D_80244EF0, D_7045098,
    D_80245278, D_80245668, D_802459B8, D_80245CA0, D_80245F10, D_7045098,  D_80246298, D_80246688, D_802469D8,
    D_80246CC0, D_80246F30, D_7045098,  D_802472B8, D_802476A8, D_802479F8, D_80247CE0, D_80247F50, D_7045098,
    D_802482D8, D_802486C8, D_80248A18, D_80248D00, D_80248F70, D_7045098,  D_802492F8, D_802496E8, D_80249A38,
    D_80249D20, D_80249F90, D_7045098,  D_8024A318, D_8024A708, D_8024AA58, D_8024AD40, D_8024AFB0, D_7045098,
    D_8024B338, D_8024B728, D_8024BA78, D_8024BD60, D_8024BFD0, D_7045098,  D_8024C358, D_8024C748, D_8024CA98,
    D_8024CD80, D_8024CFF0, D_7045098,  D_8024D378, D_8024D768, D_8024DAB8, D_8024DDA0, D_8024E010, D_7045098,
};

Gfx* D_8076DEA0[] = {
    D_7045278, D_70469D8, D_70476D8, D_7047F70, D_7048550, D_7045098,
};

Gfx* (*sMachineLoadTexturesFuncs[])(Gfx*) = {
    Machine_DrawLoadBlueFalconTextures,      // CAPTAIN_FALCON
    Machine_DrawLoadGoldenFoxTextures,       // DR_STEWART
    Machine_DrawLoadWildGooseTextures,       // PICO
    Machine_DrawLoadFireStingrayTextures,    // SAMURAI_GOROH
    Machine_DrawLoadWhiteCatTextures,        // JODY_SUMMER
    Machine_DrawLoadRedGazelleTextures,      // MIGHTY_GAZELLE
    Machine_DrawLoadGreatStarTextures,       // MR_EAD
    Machine_DrawLoadIronTigerTextures,       // BABA
    Machine_DrawLoadDeepClawTextures,        // OCTOMAN
    Machine_DrawLoadTwinNorittaTextures,     // GOMAR_AND_SHIOH
    Machine_DrawLoadSuperPiranhaTextures,    // KATE_ALEN
    Machine_DrawLoadMightyHurricaneTextures, // ROGER_BUSTER
    Machine_DrawLoadLittleWyvernTextures,    // JAMES_MCCLOUD
    Machine_DrawLoadSpaceAnglerTextures,     // LEON
    Machine_DrawLoadGreenPantherTextures,    // ANTONIO_GUSTER
    Machine_DrawLoadBlackBullTextures,       // BLACK_SHADOW
    Machine_DrawLoadWildBoarTextures,        // MICHAEL_CHAIN
    Machine_DrawLoadAstroRobinTextures,      // JACK_LEVIN
    Machine_DrawLoadKingMeteorTextures,      // SUPER_ARROW
    Machine_DrawLoadQueenMeteorTextures,     // MRS_ARROW
    Machine_DrawLoadWonderWaspTextures,      // JOHN_TANAKA
    Machine_DrawLoadHyperSpeederTextures,    // BEASTMAN
    Machine_DrawLoadDeathAnchorTextures,     // ZODA
    Machine_DrawLoadCrazyBearTextures,       // DR_CLASH
    Machine_DrawLoadNightThunderTextures,    // SILVER_NEELSEN
    Machine_DrawLoadBigFangTextures,         // BIO_REX
    Machine_DrawLoadMightyTyphoonTextures,   // DRAQ
    Machine_DrawLoadMadWolfTextures,         // BILLY
    Machine_DrawLoadSonicPhantomTextures,    // THE_SKULL
    Machine_DrawLoadBloodHawkTextures,       // BLOOD_FALCON
    Machine_DrawLoadBlueFalconTextures,      // Super Falcon
    Machine_DrawLoadFireStingrayTextures,    // Super Stingray
    Machine_DrawLoadWhiteCatTextures,        // Super Cat
};

Gfx* (*sMachineDrawFuncs[][5])(Gfx*) = {
    { Machine_DrawBlueFalconLod1, Machine_DrawBlueFalconLod2, Machine_DrawBlueFalconLod3, Machine_DrawBlueFalconLod4,
      Machine_DrawBlueFalconLod5 }, // CAPTAIN_FALCON
    { Machine_DrawGoldenFoxLod1, Machine_DrawGoldenFoxLod2, Machine_DrawGoldenFoxLod3, Machine_DrawGoldenFoxLod4,
      Machine_DrawGoldenFoxLod5 }, // DR_STEWART
    { Machine_DrawWildGooseLod1, Machine_DrawWildGooseLod2, Machine_DrawWildGooseLod3, Machine_DrawWildGooseLod4,
      Machine_DrawWildGooseLod5 }, // PICO
    { Machine_DrawFireStingrayLod1, Machine_DrawFireStingrayLod2, Machine_DrawFireStingrayLod3,
      Machine_DrawFireStingrayLod4, Machine_DrawFireStingrayLod5 }, // SAMURAI_GOROH
    { Machine_DrawWhiteCatLod1, Machine_DrawWhiteCatLod2, Machine_DrawWhiteCatLod3, Machine_DrawWhiteCatLod4,
      Machine_DrawWhiteCatLod5 }, // JODY_SUMMER
    { Machine_DrawRedGazelleLod1, Machine_DrawRedGazelleLod2, Machine_DrawRedGazelleLod3, Machine_DrawRedGazelleLod4,
      Machine_DrawRedGazelleLod5 }, // MIGHTY_GAZELLE
    { Machine_DrawGreatStarLod1, Machine_DrawGreatStarLod2, Machine_DrawGreatStarLod3, Machine_DrawGreatStarLod4,
      Machine_DrawGreatStarLod5 }, // MR_EAD
    { Machine_DrawIronTigerLod1, Machine_DrawIronTigerLod2, Machine_DrawIronTigerLod3, Machine_DrawIronTigerLod4,
      Machine_DrawIronTigerLod5 }, // BABA
    { Machine_DrawDeepClawLod1, Machine_DrawDeepClawLod2, Machine_DrawDeepClawLod3, Machine_DrawDeepClawLod4,
      Machine_DrawDeepClawLod5 }, // OCTOMAN
    { Machine_DrawTwinNorittaLod1, Machine_DrawTwinNorittaLod2, Machine_DrawTwinNorittaLod3,
      Machine_DrawTwinNorittaLod4, Machine_DrawTwinNorittaLod5 }, // GOMAR_AND_SHIOH
    { Machine_DrawSuperPiranhaLod1, Machine_DrawSuperPiranhaLod2, Machine_DrawSuperPiranhaLod3,
      Machine_DrawSuperPiranhaLod4, Machine_DrawSuperPiranhaLod5 }, // KATE_ALEN
    { Machine_DrawMightyHurricaneLod1, Machine_DrawMightyHurricaneLod2, Machine_DrawMightyHurricaneLod3,
      Machine_DrawMightyHurricaneLod4, Machine_DrawMightyHurricaneLod5 }, // ROGER_BUSTER
    { Machine_DrawLittleWyvernLod1, Machine_DrawLittleWyvernLod2, Machine_DrawLittleWyvernLod3,
      Machine_DrawLittleWyvernLod4, Machine_DrawLittleWyvernLod5 }, // JAMES_MCCLOUD
    { Machine_DrawSpaceAnglerLod1, Machine_DrawSpaceAnglerLod2, Machine_DrawSpaceAnglerLod3,
      Machine_DrawSpaceAnglerLod4, Machine_DrawSpaceAnglerLod5 }, // LEON
    { Machine_DrawGreenPantherLod1, Machine_DrawGreenPantherLod2, Machine_DrawGreenPantherLod3,
      Machine_DrawGreenPantherLod4, Machine_DrawGreenPantherLod5 }, // ANTONIO_GUSTER
    { Machine_DrawBlackBullLod1, Machine_DrawBlackBullLod2, Machine_DrawBlackBullLod3, Machine_DrawBlackBullLod4,
      Machine_DrawBlackBullLod5 }, // BLACK_SHADOW
    { Machine_DrawWildBoarLod1, Machine_DrawWildBoarLod2, Machine_DrawWildBoarLod3, Machine_DrawWildBoarLod4,
      Machine_DrawWildBoarLod5 }, // MICHAEL_CHAIN
    { Machine_DrawAstroRobinLod1, Machine_DrawAstroRobinLod2, Machine_DrawAstroRobinLod3, Machine_DrawAstroRobinLod4,
      Machine_DrawAstroRobinLod5 }, // JACK_LEVIN
    { Machine_DrawKingMeteorLod1, Machine_DrawKingMeteorLod2, Machine_DrawKingMeteorLod3, Machine_DrawKingMeteorLod4,
      Machine_DrawKingMeteorLod5 }, // SUPER_ARROW
    { Machine_DrawQueenMeteorLod1, Machine_DrawQueenMeteorLod2, Machine_DrawQueenMeteorLod3,
      Machine_DrawQueenMeteorLod4, Machine_DrawQueenMeteorLod5 }, // MRS_ARROW
    { Machine_DrawWonderWaspLod1, Machine_DrawWonderWaspLod2, Machine_DrawWonderWaspLod3, Machine_DrawWonderWaspLod4,
      Machine_DrawWonderWaspLod5 }, // JOHN_TANAKA
    { Machine_DrawHyperSpeederLod1, Machine_DrawHyperSpeederLod2, Machine_DrawHyperSpeederLod3,
      Machine_DrawHyperSpeederLod4, Machine_DrawHyperSpeederLod5 }, // BEASTMAN
    { Machine_DrawDeathAnchorLod1, Machine_DrawDeathAnchorLod2, Machine_DrawDeathAnchorLod3,
      Machine_DrawDeathAnchorLod4, Machine_DrawDeathAnchorLod5 }, // ZODA
    { Machine_DrawCrazyBearLod1, Machine_DrawCrazyBearLod2, Machine_DrawCrazyBearLod3, Machine_DrawCrazyBearLod4,
      Machine_DrawCrazyBearLod5 }, // DR_CLASH
    { Machine_DrawNightThunderLod1, Machine_DrawNightThunderLod2, Machine_DrawNightThunderLod3,
      Machine_DrawNightThunderLod4, Machine_DrawNightThunderLod5 }, // SILVER_NEELSEN
    { Machine_DrawBigFangLod1, Machine_DrawBigFangLod2, Machine_DrawBigFangLod3, Machine_DrawBigFangLod4,
      Machine_DrawBigFangLod5 }, // BIO_REX
    { Machine_DrawMightyTyphoonLod1, Machine_DrawMightyTyphoonLod2, Machine_DrawMightyTyphoonLod3,
      Machine_DrawMightyTyphoonLod4, Machine_DrawMightyTyphoonLod5 }, // DRAQ
    { Machine_DrawMadWolfLod1, Machine_DrawMadWolfLod2, Machine_DrawMadWolfLod3, Machine_DrawMadWolfLod4,
      Machine_DrawMadWolfLod5 }, // BILLY
    { Machine_DrawSonicPhantomLod1, Machine_DrawSonicPhantomLod2, Machine_DrawSonicPhantomLod3,
      Machine_DrawSonicPhantomLod4, Machine_DrawSonicPhantomLod5 }, // THE_SKULL
    { Machine_DrawBloodHawkLod1, Machine_DrawBloodHawkLod2, Machine_DrawBloodHawkLod3, Machine_DrawBloodHawkLod4,
      Machine_DrawBloodHawkLod5 }, // BLOOD_FALCON
    { Machine_DrawSuperFalconLod1, Machine_DrawSuperFalconLod2, Machine_DrawSuperFalconLod3,
      Machine_DrawSuperFalconLod4, Machine_DrawSuperFalconLod5 }, // Super Falcon
    { Machine_DrawSuperStingrayLod1, Machine_DrawSuperStingrayLod2, Machine_DrawSuperStingrayLod3,
      Machine_DrawSuperStingrayLod4, Machine_DrawSuperStingrayLod5 }, // Super Stingray
    { Machine_DrawSuperCatLod1, Machine_DrawSuperCatLod2, Machine_DrawSuperCatLod3, Machine_DrawSuperCatLod4,
      Machine_DrawSuperCatLod5 }, // Super Cat
};

#define VOICE_FEMALE 0
#define VOICE_MALE 1

u8 sCharacterVoices[] = {
    VOICE_MALE,   // CAPTAIN_FALCON
    VOICE_MALE,   // DR_STEWART
    VOICE_MALE,   // PICO
    VOICE_MALE,   // SAMURAI_GOROH
    VOICE_FEMALE, // JODY_SUMMER
    VOICE_MALE,   // MIGHTY_GAZELLE
    VOICE_MALE,   // MR_EAD
    VOICE_FEMALE, // BABA
    VOICE_MALE,   // OCTOMAN
    VOICE_MALE,   // GOMAR_AND_SHIOH
    VOICE_FEMALE, // KATE_ALEN
    VOICE_MALE,   // ROGER_BUSTER
    VOICE_MALE,   // JAMES_MCCLOUD
    VOICE_MALE,   // LEON
    VOICE_MALE,   // ANTONIO_GUSTER
    VOICE_MALE,   // BLACK_SHADOW
    VOICE_MALE,   // MICHAEL_CHAIN
    VOICE_MALE,   // JACK_LEVIN
    VOICE_MALE,   // SUPER_ARROW
    VOICE_FEMALE, // MRS_ARROW
    VOICE_MALE,   // JOHN_TANAKA
    VOICE_MALE,   // BEASTMAN
    VOICE_MALE,   // ZODA
    VOICE_MALE,   // DR_CLASH
    VOICE_MALE,   // SILVER_NEELSEN
    VOICE_MALE,   // BIO_REX
    VOICE_MALE,   // DRAQ
    VOICE_MALE,   // BILLY
    VOICE_MALE,   // THE_SKULL
    VOICE_MALE,   // BLOOD_FALCON
};

// Dma Read Data
u8 D_8076E1F0[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0A, 0x14, 0x1E, 0x28, 0x32, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x3C, 0x32, 0x28, 0x1E,
    0x14, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x1E, 0x32, 0x46, 0x5A,
    0x6E, 0x5A, 0x46, 0x32, 0x1E, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x14, 0x32, 0x50, 0x6E, 0x8C, 0xAA, 0xC8, 0xE6, 0xC8,
    0xAA, 0x8C, 0x6E, 0x50, 0x32, 0x14, 0x00, 0x00, 0x00,
};

s16 gSettingVsHandicap = 0;
s16 gSettingVsCom = 1;

f32 D_8076E2F8 = 2000.0f;

s8 gTotalLives[] = { 5, 4, 3, 2 };

Vec3s D_8076E300[] = {
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 },
    { 200, 255, 0 },   { 55, 55, 0 }, { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
    { 140, 220, 255 }, { 205, 0, 0 }, { 200, 255, 0 },   { 55, 55, 0 },
};

Vec3s D_8076E3F0[] = {
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },
    { 55, 255, 105 }, { 255, 160, 100 }, { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
    { 150, 130, 70 }, { 155, 55, 255 },  { 55, 255, 105 }, { 255, 160, 100 },
};

s32 gRacePositionPoints[] = {
    100, 93, 87, 81, 76, 71, 66, 62, 58, 54, 50, 47, 44, 41, 38,
    35,  33, 31, 29, 27, 25, 23, 22, 21, 20, 19, 18, 17, 16, 15,
};

s32 D_8076E558[] = { 5, 3, 1, 0 };

f32 D_8076E568 = 0.1f;
f32 D_8076E56C = 0.1f;
f32 D_8076E570 = 0.1f;

f32 D_8076E574 = 250.0f;

UNUSED Vec3f D_8076E578 = { 0 };

s16 D_8076E584 = 60;
s32 D_8076E588 = 700;
f32 D_8076E58C = 0.01f;
f32 D_8076E590 = 25.0f;
s32 sInitialBoostTimer = 100;
f32 sEnergyRefillScale = 0.008f;
s16 D_8076E59C = 0;
s16 D_8076E5A0 = 1;
s16 D_8076E5A4 = 0;
s16 D_8076E5A8 = 0;

// clang-format off
BoosterInfo sBoosterInfos[] = {
    { 4, { { -87.0f, 22.0f, -208.0f }, { -87.0f, 60.0f, -208.0f }, { 87.0f, 22.0f, -208.0f }, { 87.0f, 60.0f, -208.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 4, { { -73.0f, 25.0f, -202.0f }, { -26.0f, 25.0f, -202.0f }, { 24.0f, 25.0f, -202.0f }, { 72.0f, 25.0f, -202.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 3, { { 28.0f, 36.0f, -236.0f }, { -31.0f, 36.0f, -236.0f }, { 0.0f, 127.0f, -262.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -33.0f, 55.0f, -170.0f }, { 33.0f, 52.0f, -170.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 4, { { -50.0f, 19.0f, -222.0f }, { 48.0f, 19.0f, -222.0f }, { -83.0f, 19.0f, -222.0f }, { 81.0f, 19.0f, -222.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 1, { { 2.0f, 29.0f, -226.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 21.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -68.0f, 58.0f, -205.0f }, { -23.0f, 58.0f, -205.0f }, { 22.0f, 58.0f, -205.0f }, { 67.0f, 58.0f, -205.0f } }, { 12.0f, 12.0f, 12.0f, 12.0f } },
    { 2, { { -85.0f, 31.0f, -276.0f }, { 85.0f, 31.0f, -276.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 4, { { -52.0f, 29.0f, -213.0f }, { -17.0f, 29.0f, -213.0f }, { 17.0f, 29.0f, -213.0f }, { 52.0f, 29.0f, -213.0f } }, { 10.0f, 10.0f, 10.0f, 10.0f } },
    { 2, { { -82.0f, 40.0f, -215.0f }, { 82.0f, 40.0f, -215.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 12.0f, 12.0f, 0.0f, 0.0f } },
    { 2, { { -35.0f, 36.0f, -188.0f }, { 35.0f, 36.0f, -188.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 86.0f, -200.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 23.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -67.0f, 50.0f, -218.0f }, { 67.0f, 50.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 42.0f, -230.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 36.0f, -201.0f }, { 27.0f, 36.0f, -201.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -56.0f, 30.0f, -235.0f }, { 54.0f, 30.0f, -235.0f }, { 0.0f, 30.0f, -235.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 2, { { -30.0f, 37.0f, -218.0f }, { 29.0f, 37.0f, -218.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 35.0f, -229.0f }, { 33.0f, 35.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 9.0f, 9.0f, 0.0f, 0.0f } },
    { 3, { { -45.0f, 37.0f, -208.0f }, { 45.0f, 37.0f, -208.0f }, { 0.0f, 115.0f, -208.0f }, { 0.0f, 0.0f, 0.0f } }, { 19.0f, 19.0f, 19.0f, 0.0f } },
    { 2, { { 0.0f, 32.0f, -228.0f }, { 0.0f, 95.0f, -221.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -27.0f, 94.0f, -136.0f }, { 27.0f, 94.0f, -136.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 0.0f, 0.0f } },
    { 3, { { -86.0f, 28.0f, -242.0f }, { 87.0f, 28.0f, -242.0f }, { 0.0f, 33.0f, -242.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 20.0f, 0.0f } },
    { 1, { { 0.0f, 91.0f, -220.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 18.0f, 0.0f, 0.0f, 0.0f } },
    { 3, { { -62.0f, 65.0f, -226.0f }, { 60.0f, 65.0f, -226.0f }, { 0.0f, 65.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 15.0f, 0.0f } },
    { 4, { { -83.0f, 30.0f, -220.0f }, { -28.0f, 30.0f, -220.0f }, { 28.0f, 30.0f, -220.0f }, { 83.0f, 30.0f, -220.0f } }, { 15.0f, 15.0f, 15.0f, 15.0f } },
    { 3, { { -75.0f, 31.0f, -226.0f }, { 75.0f, 31.0f, -226.0f }, { 0.0f, 100.0f, -226.0f }, { 0.0f, 0.0f, 0.0f } }, { 22.0f, 22.0f, 20.0f, 0.0f } },
    { 3, { { 0.0f, 33.0f, -210.0f }, { 0.0f, 90.0f, -210.0f }, { 0.0f, 150.0f, -210.0f }, { 0.0f, 0.0f, 0.0f } }, { 17.0f, 17.0f, 17.0f, 0.0f } },
    { 1, { { 0.0f, 123.0f, -206.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 1, { { 0.0f, 28.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 0.0f, 0.0f, 0.0f } },
    { 4, { { -84.0f, 25.0f, -234.0f }, { -28.0f, 25.0f, -234.0f }, { 28.0f, 25.0f, -234.0f }, { 83.0f, 25.0f, -234.0f } }, { 17.0f, 17.0f, 17.0f, 17.0f } },
    { 1, { { 0.0f, 34.0f, -224.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 0.0f, 0.0f, 0.0f } },
    { 2, { { -130.0f, 40.0f, -225.0f }, { 130.0f, 40.0f, -225.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 2, { { -30.0f, 46.0f, -228.0f }, { 30.0f, 46.0f, -228.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 15.0f, 15.0f, 0.0f, 0.0f } },
    { 2, { { -32.0f, 33.0f, -232.0f }, { 32.0f, 33.0f, -232.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 3, { { -65.0f, 30.0f, -240.0f }, { 65.0f, 30.0f, -240.0f }, { 0.0f, 30.0f, -240.0f }, { 0.0f, 0.0f, 0.0f } }, { 16.0f, 16.0f, 16.0f, 0.0f } },
    { 2, { { -95.0f, 30.0f, -229.0f }, { 100.0f, 30.0f, -229.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f } }, { 20.0f, 20.0f, 0.0f, 0.0f } },
    { 4, { { -98.0f, 34.0f, -229.0f }, { -33.0f, 34.0f, -229.0f }, { 32.0f, 34.0f, -229.0f }, { 97.0f, 34.0f, -229.0f } }, { 18.0f, 18.0f, 18.0f, 18.0f } },
};
// clang-format on

f32 D_8076EF80 = 0.1f;

f32 gBodyHealthValues[] = {
    190.0f, 178.0f, 166.0f, 154.0f, 142.0f,
};

f32 D_8076EF98[] = {
    0.210f, 0.207f, 0.204f, 0.201f, 0.198f,
};

f32 D_8076EFAC[] = {
    1.277f, 1.237f, 1.197f, 1.157f, 1.117f,
};

f32 D_8076EFC0[] = {
    0.397f, 0.367f, 0.337f, 0.307f, 0.277f,
};

// clang-format off
Machine sDefaultMachines[] = {
    { CUSTOM_MACHINE_DEFAULT, 0, 0, { 0, 211, 0, 77 }, { 0, 0, 87, 77 }, { 255, 102, 48, 77 }, 7, { BODY_B, BOOST_C, GRIP_B }, 1260 },                // CAPTAIN_FALCON
    { CUSTOM_MACHINE_DEFAULT, 1, 1, { 255, 226, 43, 120 }, { 205, 255, 133, 80 }, { 25, 255, 255, 160 }, 3, { BODY_D, BOOST_A, GRIP_D }, 1420 },      // DR_STEWART
    { CUSTOM_MACHINE_DEFAULT, 2, 2, { 0, 75, 190, 100 }, { 134, 81, 65, 100 }, { 73, 163, 16, 100 }, 6, { BODY_B, BOOST_B, GRIP_C }, 1620 },          // PICO
    { CUSTOM_MACHINE_DEFAULT, 3, 3, { 245, 52, 72, 43 }, { 72, 52, 121, 120 }, { 146, 52, 245, 65 }, 5, { BODY_A, BOOST_D, GRIP_B }, 1960 },          // SAMURAI_GOROH
    { CUSTOM_MACHINE_DEFAULT, 4, 4, { 111, 255, 0, 255 }, { 79, 0, 182, 168 }, { 184, 0, 133, 0 }, 2, { BODY_C, BOOST_C, GRIP_A }, 1150 },            // JODY_SUMMER
    { CUSTOM_MACHINE_DEFAULT, 5, 5, { 255, 0, 74, 36 }, { 0, 0, 74, 101 }, { 0, 190, 74, 46 }, 1, { BODY_E, BOOST_A, GRIP_C }, 1330 },                // MIGHTY_GAZELLE
    { CUSTOM_MACHINE_DEFAULT, 6, 6, { 143, 255, 77, 57 }, { 73, 104, 198, 188 }, { 232, 3, 216, 35 }, 9, { BODY_E, BOOST_A, GRIP_D }, 1870 },         // MR_EAD
    { CUSTOM_MACHINE_DEFAULT, 7, 7, { 143, 60, 146, 220 }, { 144, 60, 216, 220 }, { 192, 60, 146, 146 }, 4, { BODY_B, BOOST_D, GRIP_A }, 1780 },      // BABA
    { CUSTOM_MACHINE_DEFAULT, 8, 8, { 146, 255, 14, 44 }, { 0, 108, 75, 148 }, { 17, 0, 26, 196 }, 8, { BODY_B, BOOST_B, GRIP_C }, 990 },             // OCTOMAN
    { CUSTOM_MACHINE_DEFAULT, 9, 9, { 100, 240, 239, 92 }, { 100, 201, 98, 184 }, { 100, 64, 195, 227 }, 22, { BODY_E, BOOST_A, GRIP_C }, 780 },      // GOMAR_AND_SHIOH
    { CUSTOM_MACHINE_DEFAULT, 10, 10, { 71, 255, 58, 99 }, { 202, 240, 58, 223 }, { 196, 0, 58, 102 }, 12, { BODY_B, BOOST_C, GRIP_B }, 1010 },       // KATE_ALEN
    { CUSTOM_MACHINE_DEFAULT, 11, 11, { 0, 196, 20, 121 }, { 90, 33, 41, 101 }, { 90, 33, 121, 20 }, 28, { BODY_E, BOOST_B, GRIP_B }, 1780 },         // ROGER_BUSTER
    { CUSTOM_MACHINE_DEFAULT, 12, 12, { 160, 255, 223, 123 }, { 160, 168, 112, 251 }, { 180, 0, 255, 255 }, 10, { BODY_E, BOOST_B, GRIP_B }, 1390 },  // JAMES_MCCLOUD
    { CUSTOM_MACHINE_DEFAULT, 13, 13, { 71, 255, 255, 150 }, { 79, 198, 84, 150 }, { 151, 0, 144, 150 }, 19, { BODY_C, BOOST_C, GRIP_A }, 910 },      // LEON
    { CUSTOM_MACHINE_DEFAULT, 14, 14, { 10, 53, 255, 92 }, { 50, 201, 240, 238 }, { 20, 255, 0, 63 }, 17, { BODY_A, BOOST_B, GRIP_D }, 2060 },        // ANTONIO_GUSTER
    { CUSTOM_MACHINE_DEFAULT, 15, 15, { 30, 54, 82, 122 }, { 30, 35, 54, 107 }, { 30, 192, 82, 14 }, 30, { BODY_A, BOOST_E, GRIP_A }, 2340 },         // BLACK_SHADOW
    { CUSTOM_MACHINE_DEFAULT, 16, 16, { 206, 25, 249, 22 }, { 84, 168, 218, 217 }, { 22, 29, 3, 174 }, 24, { BODY_A, BOOST_C, GRIP_C }, 2110 },       // MICHAEL_CHAIN
    { CUSTOM_MACHINE_DEFAULT, 17, 17, { 71, 255, 28, 56 }, { 79, 0, 80, 56 }, { 151, 0, 42, 56 }, 14, { BODY_B, BOOST_D, GRIP_A }, 1050 },            // JACK_LEVIN
    { CUSTOM_MACHINE_DEFAULT, 18, 18, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 20, { BODY_E, BOOST_B, GRIP_B }, 860 },          // SUPER_ARROW
    { CUSTOM_MACHINE_DEFAULT, 19, 19, { 141, 29, 46, 38 }, { 15, 21, 46, 130 }, { 36, 184, 46, 29 }, 21, { BODY_E, BOOST_B, GRIP_B }, 1140 },         // MRS_ARROW
    { CUSTOM_MACHINE_DEFAULT, 20, 20, { 14, 200, 213, 22 }, { 145, 51, 14, 95 }, { 213, 195, 14, 38 }, 26, { BODY_D, BOOST_A, GRIP_D }, 900 },        // JOHN_TANAKA
    { CUSTOM_MACHINE_DEFAULT, 21, 21, { 19, 190, 165, 20 }, { 64, 190, 12, 60 }, { 90, 190, 12, 20 }, 18, { BODY_C, BOOST_C, GRIP_A }, 1460 },        // BEASTMAN
    { CUSTOM_MACHINE_DEFAULT, 22, 22, { 26, 219, 217, 155 }, { 30, 230, 0, 24 }, { 57, 255, 0, 156 }, 13, { BODY_E, BOOST_A, GRIP_C }, 1620 },        // ZODA
    { CUSTOM_MACHINE_DEFAULT, 23, 23, { 203, 121, 255, 255 }, { 203, 205, 255, 149 }, { 84, 212, 255, 244 }, 29, { BODY_A, BOOST_B, GRIP_E }, 2220 }, // DR_CLASH
    { CUSTOM_MACHINE_DEFAULT, 24, 24, { 3, 218, 28, 118 }, { 3, 17, 181, 118 }, { 46, 17, 104, 118 }, 23, { BODY_B, BOOST_A, GRIP_E }, 1530 },        // SILVER_NEELSEN
    { CUSTOM_MACHINE_DEFAULT, 25, 25, { 51, 203, 0, 9 }, { 48, 0, 126, 131 }, { 28, 0, 20, 166 }, 15, { BODY_B, BOOST_D, GRIP_A }, 1520 },            // BIO_REX
    { CUSTOM_MACHINE_DEFAULT, 26, 26, { 72, 21, 179, 69 }, { 90, 120, 49, 72 }, { 0, 149, 67, 137 }, 27, { BODY_C, BOOST_A, GRIP_D }, 950 },          // DRAQ
    { CUSTOM_MACHINE_DEFAULT, 27, 27, { 254, 227, 20, 104 }, { 244, 62, 72, 99 }, { 65, 34, 24, 150 }, 11, { BODY_B, BOOST_B, GRIP_C }, 1490 },       // BILLY
    { CUSTOM_MACHINE_DEFAULT, 28, 28, { 31, 232, 192, 91 }, { 63, 0, 0, 91 }, { 223, 0, 176, 91 }, 16, { BODY_C, BOOST_A, GRIP_D }, 1010 },           // THE_SKULL
    { CUSTOM_MACHINE_DEFAULT, 29, 29, { 200, 0, 63, 40 }, { 0, 72, 214, 38 }, { 0, 255, 42, 105 }, 25, { BODY_B, BOOST_A, GRIP_E }, 1170 },           // BLOOD_FALCON
    { CUSTOM_MACHINE_SUPER_FALCON, 0, 0, { 223, 34, 12, 224 }, { 199, 34, 50, 239 }, { 33, 34, 109, 240 }, 7, { BODY_A, BOOST_B, GRIP_A }, 790 },
    { CUSTOM_MACHINE_SUPER_STINGRAY, 3, 3, { 55, 42, 85, 10 }, { 55, 59, 11, 123 }, { 55, 136, 24, 125 }, 5, { BODY_B, BOOST_A, GRIP_A }, 2210 },
    { CUSTOM_MACHINE_SUPER_CAT, 4, 4, { 33, 42, 0, 134 }, { 55, 42, 134, 0 }, { 137, 42, 73, 72 }, 2, { BODY_A, BOOST_A, GRIP_B }, 1840 },
};
// clang-format on

s16 D_8076F2AC[] = {
    270, 290, 320, 350, 420, 580, 630,
};

s16 D_8076F2BC[] = {
    510, 560, 630, 720, 890, 930, 1170,
};

s16 D_8076F2CC[] = {
    0, 100, 120, 140, 190, 250, 420,
};

void (*D_8076F2DC[])(Racer*) = {
    func_8071FDE4, // TRACK_SHAPE_ROAD
    func_8071FE04, // TRACK_SHAPE_WALLED_ROAD
    func_8071FE44, // TRACK_SHAPE_PIPE
    func_807206FC, // TRACK_SHAPE_CYLINDER
    func_80720E2C, // TRACK_SHAPE_HALF_PIPE
    func_8071FE24, // TRACK_SHAPE_TUNNEL
    func_8072163C, // TRACK_SHAPE_AIR
    func_80721714, // TRACK_SHAPE_BORDERLESS_ROAD
};

u8 D_8076F2FC[] = {
    0, 1, 2, 5, 4, 3, 7, 6, 5, 0, 4, 8, 2, 1, 7, 6, 8, 0, 9, 5, 6, 2, 3, 8,
};

s32 func_80719910(s32 position) {
    s32 i;

    for (i = 0; i < gTotalRacers; i++) {
        if (position == gRacers[i].position) {
            return i;
        }
    }
    return -1;
}

extern s32 gNumPlayers;
extern s32 gGameMode;
extern s8 D_8076C7D8;

// Set up racer positions before the start line
void func_80719958(void) {
    f32 var_fs0;
    f32 var_fs4;
    f32 var_fs1;
    f32 var_fv0;
    s32 i;
    s32 j;
    CourseSegment* temp_v0;
    CourseSegment* temp_v1;
    CourseSegment* var_s2;
    Racer* temp_s1;
    Vec3f sp84;
    s32 index;

    func_i3_8003F364();

    var_s2 = gCurrentCourseInfo->courseSegments->prev;
    var_fs0 = 1.0f;
    for (i = 20; i > 0; i--) {
        var_fs0 -= 7.3f / func_i2_800B2500(var_s2, var_fs0, &gRacers[0].unk_0C.unk_0C);
    }

    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) && (D_8076C7D8 == 0) &&
        (gGameMode != GAMEMODE_COURSE_EDIT)) {
        if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
            var_fs4 = 1.99f;
        } else {
            var_fs4 = 0;
        }
    } else {
        var_fs4 = 7.99f;
    }

    for (j = 1; j <= gTotalRacers; j++) {
        index = func_80719910(j);
        temp_s1 = &gRacers[index];
        temp_s1->unk_0C.courseSegment = var_s2;
        temp_s1->unk_0C.unk_04 = var_fs0;
        func_i2_800B26B8(var_s2, var_fs0, &temp_s1->unk_0C.unk_1C);
        sp84 = temp_s1->unk_0C.unk_1C;
        temp_s1->unk_0C.unk_44 = sp84;
        temp_s1->unk_0C.unk_34 = sp84;
        temp_s1->unk_0C.unk_28.x = 0.0f;
        temp_s1->unk_0C.unk_28.y = 0.0f;
        temp_s1->unk_0C.unk_28.z = 0.0f;
        temp_s1->unk_0C.unk_40 = 0.0f;
        temp_s1->unk_0C.unk_18 =
            func_i2_800B2500(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->unk_0C.unk_0C);
        temp_s1->unk_0C.unk_08 =
            func_i2_800B20D0(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->lapDistance);
        func_i2_800B2824(temp_s1->unk_0C.courseSegment, temp_s1->unk_0C.unk_04, &temp_s1->unk_24C,
                         temp_s1->unk_0C.unk_08);

        temp_v0 = temp_s1->unk_0C.courseSegment;
        temp_v1 = temp_v0->next;
        var_fs1 = ((temp_s1->unk_0C.unk_08 * (temp_v1->radiusLeft - temp_v0->radiusLeft)) + temp_v0->radiusLeft +
                   (temp_s1->unk_0C.unk_08 * (temp_v1->radiusRight - temp_v0->radiusRight)) + temp_v0->radiusRight) *
                  0.125f;
        if (var_fs1 > 50.0f) {
            var_fs1 = 50.0f;
        }

        if (gTotalRacers >= 4) {
            var_fv0 = 3.0f;
        } else {
            var_fv0 = gTotalRacers - 1;
        }
        var_fv0 = (((j - 1) & 3) * 2 - var_fv0) * var_fs1;
        func_i2_800B2C00(&temp_s1->unk_0C,
                         temp_s1->unk_0C.unk_34.x + (var_fs4 * temp_s1->unk_24C.y.x) + (var_fv0 * temp_s1->unk_24C.z.x),
                         temp_s1->unk_0C.unk_34.y + (var_fs4 * temp_s1->unk_24C.y.y) + (var_fv0 * temp_s1->unk_24C.z.y),
                         temp_s1->unk_0C.unk_34.z + (var_fs4 * temp_s1->unk_24C.y.z) + (var_fv0 * temp_s1->unk_24C.z.z),
                         100, 1.0f);
        if (gNumPlayers == 1) {
            var_fv0 = 100.0f;
        } else if (var_fs1 <= 23.0f) {
            var_fv0 = 46.0f;
        } else {
            var_fv0 = 0.1f;
        }

        for (i = 20; i > 0; i--) {
            var_fs0 -= (var_fv0 / 20.0f) / temp_s1->unk_0C.unk_18;
            if (var_fs0 < 0.0f) {
                var_s2 = var_s2->prev;
                var_fs0 *= (temp_s1->unk_0C.unk_18 / func_i2_800B2500(var_s2, 1.0f, &temp_s1->unk_0C.unk_0C));
                var_fs0 += 1.0f;
            }
        }
    }
}

void func_80719D70(void) {
    s16 temp_a0;
    s16 temp_a1;
    s32 var_a2;
    s32 var_a3;
    s32 temp_t5;
    s32 temp_t9;
    Racer* temp;
    Racer* var_a0;
    Racer* var_v0;
    Racer* var_v1;

    if ((gGameMode != GAMEMODE_GP_RACE) || ((gTotalRacers - gRacersRetired) < 2) || (D_8076C7D8 != 0)) {
        sRivalRacer = NULL;
        return;
    }
    var_v0 = gRacers;
    while (var_v0->stateFlags & RACER_STATE_RETIRED) {
        var_v0++;
    }
    var_v1 = var_v0 + 1;
    while (var_v1->stateFlags & RACER_STATE_RETIRED) {
        var_v1++;
    }

    if (var_v0->points < var_v1->points) {
        temp = var_v0;
        var_v0 = var_v1;
        var_v1 = temp;
        var_a2 = var_v1->points;
        var_a3 = var_v0->points;
    } else {
        var_a2 = var_v0->points;
        var_a3 = var_v1->points;
    }

    var_a0 = sLastRacer;
    do {
        if (!(var_a0->stateFlags & RACER_STATE_RETIRED)) {
            if (var_a2 < var_a0->points) {
                var_v1 = var_v0;
                var_a3 = var_a2;
                var_v0 = var_a0;
                var_a2 = var_a0->points;
            } else if ((var_a3 < var_a0->points) && (var_a0 != var_v0)) {
                var_v1 = var_a0;
                var_a3 = var_a0->points;
            }
        }
        var_a0--;
    } while (var_a0 >= gRacers);

    if (var_a2 == 0) {
        sRivalRacer = NULL;
        return;
    }
    if (var_v0 == gRacers) {
        sRivalRacer = var_v1;
        return;
    }
    sRivalRacer = var_v0;
}

void func_80719EDC(s32 playerIndex) {

    gPlayerLives[playerIndex]++;

    func_i3_80053BE0();
    func_i3_TriggerLivesIncrease();
    if (D_807A16E0 != 0) {
        func_8074122C(0);
    }
    D_807B37D4 = 0;
}

void func_80719F38(s32 playerIndex) {

    if (--gPlayerLives[playerIndex] >= 0) {
        func_i3_TriggerLivesDecrease();
    }
    if (D_807A16E0 != 0) {
        func_8074122C(44);
    }
    D_807B37D4 = 0;
}

void func_80719F9C(Racer* racer) {

    if (!(racer->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_RETIRED))) {
        racer->stateFlags |= RACER_STATE_RETIRED;
        racer->energy = 0.0f;
        gRacersRetired++;
        if (racer->id < gNumPlayers) {
            gPlayerRacersRetired++;
        } else if (D_807A16CC == 0) {
            gCpuRacersRetired++;
            if ((gGameMode == GAMEMODE_DEATH_RACE) && (gTotalRacers == (gCpuRacersRetired + 1))) {
                gRacers[0].stateFlags |= (RACER_STATE_FLAGS_2000000 | RACER_STATE_CPU_CONTROLLED);
                gRacers[0].raceTime += Math_Rand2() % 16;
                D_807A16CC = 1;
                gRacers[0].energy = gRacers[0].maxEnergy;
                D_807B14F8 = D_807A16CC;
                func_80740B98(gRacers[0].id);
                func_80741550(gRacers[0].id);
                func_8070DAFC();
            }
        }
        racer->raceDistancePosition = (sRaceFrameCount + ((gTotalRacers - racer->position) / 10.0f)) - 600000.0f;
        if (gGameMode == GAMEMODE_GP_RACE) {
            if (racer->id < gNumPlayers) {
                D_807B37D4 = -1;
            }
            if (racer == sRivalRacer) {
                func_80719D70();
            }
        }
    }
}

void func_8071A17C(Racer* arg0) {

    if (D_807A16E0 != 0) {
        if (arg0->unk_08 & 0x800) {
            arg0->unk_08 &= ~0x800;
            func_80740CE8(arg0->id, 4);
        }
        if (arg0->unk_08 & 0x400) {
            arg0->unk_08 &= ~0x400;
            func_80740CE8(arg0->id, 5);
        }
        if (arg0->unk_08 & 0x20) {
            arg0->unk_08 &= ~0x20;
            func_80740CE8(arg0->id, 11);
        }
        if (arg0->unk_08 & 0x200) {
            arg0->unk_08 &= ~0x200;
            func_80740CE8(arg0->id, 6);
        }
        if (arg0->unk_08 & 0x40) {
            arg0->unk_08 &= ~0x40;
            func_80740CE8(arg0->id, 10);
        }
        if (arg0->unk_08 & 0x2000) {
            arg0->unk_08 &= ~0x2000;
            func_80740CE8(arg0->id, 8);
        }
        if (arg0->unk_08 & 0x100) {
            arg0->unk_08 &= ~0x100;
            func_80741538(arg0->id);
        }
        if (arg0->unk_08 & 0x80) {
            arg0->unk_08 &= ~0x80;
            func_80740CE8(arg0->id, 9);
        }
        func_80741550(arg0->id);
    } else {
        arg0->unk_08 &= ~(0x800 | 0x400 | 0x20 | 0x200 | 0x40 | 0x2000 | 0x100 | 0x80);
    }
}

f32 func_8071A2C8(f32 arg0) {
    if (arg0 != 0.0f) {
        return 1.0f / (((1.0f + 0.6899998f) / arg0) - 0.6899998f);
    }
    return 0.0f;
}

f32 func_8071A310(f32 arg0) {
    if (arg0 != 0.0f) {
        return (1.0f + 0.6899998f) / ((1.0f / arg0) + 0.6899998f);
    }
    return 0.0f;
}

void func_8071A358(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        gRacers[i].character = D_807A15F0[i];
        gRacers[i].machineSkinIndex = D_807A15F8[i];
    }
}

void func_8071A3E0(void) {
    s32 i;

    for (i = gNumPlayers - 1; i >= 0; i--) {
        D_807A15F0[i] = gRacers[i].character;
        D_807A15F8[i] = gRacers[i].machineSkinIndex;
        gRacers[i].unk_1A8 = func_8071A2C8(gPlayerEngine[i]);
    }
}

void func_8071A4BC(void) {
    s32 i;
    s16 j;
    s32 index0;
    s32 index1;

    j = 0;

    for (i = 1; i < 30; i++) {
        if (j == D_807A15F0[0]) {
            j++;
        }
        gRacers[i].character = j++;
        gRacers[i].machineSkinIndex = 0;
    }

    for (i = 0; i < 28; i++) {
        index0 = (Math_Rand1() & 0x1FFFF) % 29 + 1;
        index1 = (Math_Rand2() & 0x1FFFF) % 29 + 1;

        j = gRacers[index0].character;
        gRacers[index0].character = gRacers[index1].character;
        gRacers[index1].character = j;
    }
}

void func_8071A5F0(void) {
    s32 i;
    s32 j;
    s32 var_s0;
    Racer* temp_s1;
    Racer* var_v0;

    for (i = 1; i < gTotalRacers; i++) {
        if (i >= gNumPlayers) {
            do {
                gRacers[i].character = (Math_Rand2() & 0x1FFFF) % 30;
                gRacers[i].machineSkinIndex = (Math_Rand1() & 0x1FFFF) % 4;
                for (j = 0; j < gNumPlayers; j++) {
                    if ((gRacers[i].character == gRacers[j].character) &&
                        (gRacers[i].machineSkinIndex == gRacers[j].machineSkinIndex)) {
                        break;
                    }
                }
            } while (j < gNumPlayers);
        }
    }
}

void func_8071A730(MachineInfo* arg0) {
    u8 customType;
    CustomMachineInfo* temp_v0;

    arg0->character = gRacers[0].character;
    arg0->bodyR = (s32) gRacers[0].bodyRF;
    arg0->bodyG = (s32) gRacers[0].bodyGF;
    arg0->bodyB = (s32) gRacers[0].bodyBF;
    arg0->customType = customType = gRacers[0].customType;
    if (customType == CUSTOM_MACHINE_EDITED) {
        temp_v0 = &sCustomMachineInfo[gRacers[0].character];
        arg0->frontType = temp_v0->frontType;
        arg0->rearType = temp_v0->rearType;
        arg0->wingType = temp_v0->wingType;
        arg0->logo = temp_v0->logo;
        arg0->number = gMachines[gRacers[0].character].number - 1;
        arg0->decal = temp_v0->decal;
        arg0->numberR = temp_v0->numberR;
        arg0->numberG = temp_v0->numberG;
        arg0->numberB = temp_v0->numberB;
        arg0->decalR = temp_v0->decalR;
        arg0->decalG = temp_v0->decalG;
        arg0->decalB = temp_v0->decalB;
        arg0->cockpitR = temp_v0->cockpitR;
        arg0->cockpitG = temp_v0->cockpitG;
        arg0->cockpitB = temp_v0->cockpitB;
    } else {
        arg0->frontType = arg0->rearType = arg0->wingType = arg0->logo = arg0->number = arg0->decal = arg0->numberR =
            arg0->numberG = arg0->numberB = arg0->decalR = arg0->decalG = arg0->decalB = arg0->cockpitR =
                arg0->cockpitG = arg0->cockpitB = 0;
    }
}

extern s32 gCurrentGhostType;

void func_8071A88C(void) {
    s32 i;
    s32 j;
    s32 var_a1_3;
    s32* var_a0_3;
    s32* var_v1_10;
    Ghost* ghost;

    if (D_807B14F8 != 0) {
        for (i = 0; i < 5; i++) {
            if (gRacers[0].raceTime < gCurrentCourseInfo->timeRecord[i]) {
                D_807A16F2 = i + 1;

                for (j = 3; j >= i; j--) {

                    gCurrentCourseInfo->timeRecord[j + 1] = gCurrentCourseInfo->timeRecord[j];
                    gCurrentCourseInfo->recordMachineInfos[j + 1] = gCurrentCourseInfo->recordMachineInfos[j];
                    gCurrentCourseInfo->recordEngines[j + 1] = gCurrentCourseInfo->recordEngines[j];
                    *(s32*) &gCurrentCourseInfo->recordNames[j + 1] = *(s32*) &gCurrentCourseInfo->recordNames[j];

                    D_807B3C14[j + 1] = D_807B3C14[j];
                }

                gCurrentCourseInfo->timeRecord[i] = gRacers[0].raceTime;

                func_8071A730(&gCurrentCourseInfo->recordMachineInfos[i]);

                gCurrentCourseInfo->recordEngines[i] = gPlayerEngine[0];
                D_807B3C14[i] = gRacers[0].machineIndex;
                break;
            }
        }

        if (gCurrentCourseInfo->maxSpeed < gRacers[0].maxSpeed) {
            D_807A16F4 = 1;
            gCurrentCourseInfo->maxSpeed = gRacers[0].maxSpeed;

            func_8071A730(&gCurrentCourseInfo->maxSpeedMachine);
            D_807B3C14[5] = gRacers[0].machineIndex;
        }

        var_a1_3 = gCurrentCourseInfo->bestTime;
        for (i = 0; i < 3; i++) {
            if (gRacers[0].lapTimes[i] < var_a1_3) {
                j = i;
                var_a1_3 = gRacers[0].lapTimes[i];
            }
        }

        if (var_a1_3 < gCurrentCourseInfo->bestTime) {
            D_807A16F6 = j + 1;
            gCurrentCourseInfo->bestTime = var_a1_3;
            func_8071A730(&gCurrentCourseInfo->bestTimeMachine);
            D_807B3C14[6] = gRacers[0].machineIndex;
        }
    }

    if (D_807B14FA != 0) {
        for (j = 0; j < 3; j++) {
            if (gGhosts[j].encodedCourseIndex == 0) {
                break;
            }
        }

        var_a1_3 = -1;
        if (j == 3) {
            for (i = 0; i < 3; i++) {
                if ((gGhosts[i].encodedCourseIndex != gCurrentCourseInfo->encodedCourseIndex) ||
                    ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                    j = i;
                    var_a1_3 = gGhosts[i].raceTime;
                    break;
                }
            }

            // FAKE
            if (1) {}

            if (var_a1_3 != -1) {
                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) ||
                        ((gCurrentGhostType == GHOST_PLAYER) && (gGhosts[i].ghostType != GHOST_PLAYER))) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }
            } else {
                for (i = 0; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        j = i;
                        var_a1_3 = gGhosts[i].raceTime;
                        break;
                    }
                }

                for (i = j + 1; i < 3; i++) {
                    if ((gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) &&
                        (gGhosts[i].ghostType == GHOST_PLAYER)) {
                        if (var_a1_3 < gGhosts[i].raceTime) {
                            j = i;
                            var_a1_3 = gGhosts[i].raceTime;
                        }
                    }
                }

                if (gRacers[0].raceTime >= var_a1_3) {
                    j = 3;
                }
            }
        }

        if (j < 3) {
            ghost = &gGhosts[j];

            for (i = 0; i < 3; i++) {
                if (ghost == gGhostRacers[i].ghost) {
                    gGhostRacers[i].exists = gGhostRacers[i].initialized = false;
                }
            }
            ghost->ghostType = GHOST_PLAYER;
            ghost->encodedCourseIndex = gCurrentCourseInfo->encodedCourseIndex;
            ghost->raceTime = gRacers[0].raceTime;

            for (i = 0; i < 3; i++) {
                ghost->lapTimes[i] = gRacers[0].lapTimes[i];
            }

            ghost->replayEnd = sGhostReplayRecordingEnd;
            ghost->replaySize = sGhostReplayRecordingSize;

            func_8071A730(&ghost->machineInfo);

            i = (sGhostReplayRecordingSize - 1) & ~3;
            var_v1_10 = (s32*) &sGhostReplayRecordingBuffer[i];
            var_a0_3 = (s32*) &ghost->replayData[i];
            ghost->replayChecksum = 0;
            do {
                ghost->replayChecksum += * var_a0_3-- = *var_v1_10--;
            } while (var_v1_10 >= (s32*) sGhostReplayRecordingBuffer);
            if ((gFastestGhost == NULL) || (ghost->raceTime < gFastestGhost->raceTime)) {
                gFastestGhost = ghost;
            }
        }
    }
}

void func_8071B634(void) {
    Racer* activeRacer;
    Racer* finishedRacer;
    s32 bestRaceTime;
    Racer* racer;
    s32 position;
    s32 lastPosition;
    f32 var_fv0;

    racer = sLastRacer;
    do {
        racer->position = 0;
        racer--;
    } while (racer >= gRacers);

    position = 1;
    lastPosition = gTotalRacers;

    do {
        activeRacer = NULL;
        finishedRacer = NULL;
        racer = sLastRacer;
        // FAKE
        if (gRacersByPosition[0]) {}

        do {
            if (racer->position == 0) {
                if (racer->stateFlags & RACER_STATE_FLAGS_2000000) {
                    if ((finishedRacer == NULL) || (racer->raceTime < bestRaceTime)) {
                        bestRaceTime = racer->raceTime;
                        finishedRacer = racer;
                    }
                } else if ((activeRacer == NULL) || (racer->raceDistancePosition < var_fv0)) {
                    var_fv0 = racer->raceDistancePosition;
                    activeRacer = racer;
                }
            }
            racer--;
        } while (racer >= gRacers);

        if (finishedRacer != NULL) {
            gRacersByPosition[position - 1] = finishedRacer;

            finishedRacer->position = position;
            position++;
        }
        if (activeRacer != NULL) {
            gRacersByPosition[lastPosition - 1] = activeRacer;

            activeRacer->position = lastPosition;
            lastPosition--;
        }
    } while (lastPosition >= position);
}

extern s32 gTotalLapCount;

void func_8071B748(void) {
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    Racer* racer;

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_FLAGS_2000000) {
            continue;
        }

        if (racer->stateFlags & RACER_STATE_CRASHED) {
            racer->raceTime = 0;
        } else if (racer->stateFlags & RACER_STATE_FLAGS_80000) {
            racer->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            racer->stateFlags |= RACER_STATE_CRASHED;
            D_807A16D0++;
            func_80719F9C(racer);
            racer->raceTime = 0;
        } else {
            racer->stateFlags |= RACER_STATE_FLAGS_2000000;
            var_a0 = 0;
            if (racer->lapTimes[1] != 0) {
                var_a1 = racer->lapTimes[0] - racer->lapTimes[1];
                if (var_a1 < 0) {
                    var_a1 = 0;
                }
            } else {
                var_a1 = 0;
            }

            racer->raceTime = (s32) (((racer->raceTime - var_a1) * gTotalLapCount) * gCurrentCourseInfo->length /
                                     racer->raceDistance) +
                              var_a1;

            var_a1 = 0;
            var_a0 = 0;
            while (true) {
                if (racer->lapTimes[var_a0] == 0) {
                    break;
                }

                var_a1 += racer->lapTimes[var_a0];

                var_a0++;

                if (var_a0 >= gTotalLapCount) {
                    break;
                }
            }

            while (var_a0 < gTotalLapCount) {
                racer->lapTimes[var_a0] = (racer->raceTime - var_a1) / (gTotalLapCount - var_a0);
                var_a1 += racer->lapTimes[var_a0];
                var_a0++;
            }
        }
    }
    func_8071B634();
    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000)) {
        var_v1 = gTotalRacers - 1;
        while (var_v1 >= 0) {
            if (gRacersByPosition[var_v1]->raceTime != 0) {
                break;
            }
            var_v1--;
        }

        while (var_v1 >= 0) {
            gRacersByPosition[var_v1]->points += gRacePositionPoints[var_v1];
            var_v1--;
        }
        D_807A16E6 = D_807A16E4;
    }
}

void func_8071B9F4(void) {
    Racer* racer1;
    Racer* racer2;
    f32 closestDistanceBehind;
    f32 racerPairDistance;
    Racer* closestRacerBehind;
    f32 lapDistanceDiff;
    f32 halfLapDistance;
    s32 temp_a2;
    u32 i;
    RacerPairInfo* racerPairInfo;

    if (gTotalRacers < 2) {
        gRacers[0].racerAhead = gRacers[0].racerBehind = NULL;
        gRacers[0].distanceToRacerAhead = gRacers[0].distanceFromRacerBehind = gCurrentCourseInfo->length;
        return;
    }

    halfLapDistance = gCurrentCourseInfo->length * 0.5f;
    racerPairInfo = &sRacerPairInfo[((s32) (gTotalRacers * (gTotalRacers - 1)) >> 1) - 1];
    racer1 = sLastRacer;

    do {
        racer2 = racer1 - 1;
        do {
            lapDistanceDiff = racer2->lapDistance - racer1->lapDistance;
            if (lapDistanceDiff < 0.0f) {
                lapDistanceDiff = -lapDistanceDiff;
                if (lapDistanceDiff < halfLapDistance) {
                    racerPairInfo->leadRacer = racer1;
                    racerPairInfo->trailRacer = racer2;
                    racerPairInfo->trailToLeadDistance = lapDistanceDiff;
                    racerPairInfo->leadToTrailDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                } else {
                    racerPairInfo->leadRacer = racer2;
                    racerPairInfo->trailRacer = racer1;
                    racerPairInfo->trailToLeadDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                    racerPairInfo->leadToTrailDistance = lapDistanceDiff;
                }
            } else if (lapDistanceDiff < halfLapDistance) {
                racerPairInfo->leadRacer = racer2;
                racerPairInfo->trailRacer = racer1;
                racerPairInfo->trailToLeadDistance = lapDistanceDiff;
                racerPairInfo->leadToTrailDistance = gCurrentCourseInfo->length - lapDistanceDiff;
            } else {
                racerPairInfo->leadRacer = racer1;
                racerPairInfo->trailRacer = racer2;
                racerPairInfo->trailToLeadDistance = gCurrentCourseInfo->length - lapDistanceDiff;
                racerPairInfo->leadToTrailDistance = lapDistanceDiff;
            }
            racer2--;
            racerPairInfo--;
        } while (racer2 >= gRacers);
        racer1--;
    } while (racer1 > gRacers);

    racer1 = sLastRacer;
    temp_a2 = (s32) (racer1->id * (racer1->id - 1)) >> 1;

    closestDistanceBehind = gCurrentCourseInfo->length + 10.0f;

    for (racer2 = racer1 - 1; racer2 >= gRacers; racer2--) {

        racer2->racerAhead = NULL;
        racerPairInfo = &sRacerPairInfo[temp_a2 + racer2->id];
        if (racer2 == racerPairInfo->trailRacer) {
            racerPairDistance = racerPairInfo->trailToLeadDistance;
        } else {
            racerPairDistance = racerPairInfo->leadToTrailDistance;
        }
        if (racerPairDistance < closestDistanceBehind) {
            closestDistanceBehind = racerPairDistance;
            closestRacerBehind = racer2;
        }
    }

    racer1->racerBehind = closestRacerBehind;
    closestRacerBehind->racerAhead = racer1;
    closestRacerBehind->distanceToRacerAhead = closestDistanceBehind;
    racer1->distanceFromRacerBehind = closestDistanceBehind;

    for (i = gTotalRacers - 2; i > 0; i--) {
        racer1 = closestRacerBehind;
        closestDistanceBehind = gCurrentCourseInfo->length + 10.0f;
        temp_a2 = (s32) (closestRacerBehind->id * (closestRacerBehind->id - 1)) >> 1;

        for (racer2 = gRacers; racer2 < racer1; racer2++) {
            if (racer2->racerAhead != NULL) {
                continue;
            }

            racerPairInfo = &sRacerPairInfo[temp_a2 + racer2->id];
            if (racer2 == racerPairInfo->trailRacer) {
                racerPairDistance = racerPairInfo->trailToLeadDistance;
            } else {
                racerPairDistance = racerPairInfo->leadToTrailDistance;
            }
            if (racerPairDistance < closestDistanceBehind) {
                closestDistanceBehind = racerPairDistance;
                closestRacerBehind = racer2;
            }
        }

        for (racer2 = racer2 + 1; racer2 < sLastRacer; racer2++) {
            if (racer2->racerAhead != NULL) {
                continue;
            }

            temp_a2 = racer2->id;
            racerPairInfo = &sRacerPairInfo[((s32) (temp_a2 * (temp_a2 - 1)) >> 1) + racer1->id];
            if (racer2 == racerPairInfo->trailRacer) {
                racerPairDistance = racerPairInfo->trailToLeadDistance;
            } else {
                racerPairDistance = racerPairInfo->leadToTrailDistance;
            }
            if (racerPairDistance < closestDistanceBehind) {
                closestDistanceBehind = racerPairDistance;
                closestRacerBehind = racer2;
            }
        }
        racer1->racerBehind = closestRacerBehind;
        closestRacerBehind->racerAhead = racer1;
        closestRacerBehind->distanceToRacerAhead = closestDistanceBehind;
        racer1->distanceFromRacerBehind = closestDistanceBehind;
    }

    racer1 = sLastRacer;
    closestRacerBehind->racerBehind = racer1;
    racer1->racerAhead = closestRacerBehind;
    racerPairInfo = &sRacerPairInfo[((s32) (racer1->id * (racer1->id - 1)) >> 1) + closestRacerBehind->id];
    if (closestRacerBehind == racerPairInfo->leadRacer) {
        closestDistanceBehind = racerPairInfo->trailToLeadDistance;
    } else {
        closestDistanceBehind = racerPairInfo->leadToTrailDistance;
    }
    racer1->distanceToRacerAhead = closestDistanceBehind;
    closestRacerBehind->distanceFromRacerBehind = closestDistanceBehind;
}

void func_8071BE0C(void) {
    s32 i;
    f32 closestDistance;

    closestDistance = gCurrentCourseInfo->length;

    for (i = gTotalRacers - 1; i > 0; i--) {
        if (sRacerPairInfo[(i * (i - 1)) >> 1].trailToLeadDistance < closestDistance) {
            closestDistance = sRacerPairInfo[(i * (i - 1)) >> 1].trailToLeadDistance;
            D_807A16C8 = i;
        }
    }
}

extern s32 gDifficulty;
extern s16 gLastRandomCourseIndex;

void func_8071BE88(void) {
    s32 numRacers = ARRAY_COUNT(gRacers) - 1;
    s32 i;

    if (numRacers) {}

    D_807A16E6 = D_807A1700 = 0;
    gLastRandomCourseIndex = -1;

    for (i = numRacers; i >= 0; i--) {
        gRacers[i].points = 0;
    }

    gPlayerLives[0] = gPlayerLives[1] = gPlayerLives[2] = gPlayerLives[3] = gTotalLives[gDifficulty];
}

s32 func_8071BEF8(MachineInfo* arg0, MachineInfo* arg1) {
    s32 i;
    u8* var_v0 = (u8*) arg0;
    u8* var_v1 = (u8*) arg1;

    for (i = sizeof(MachineInfo); i > 0; i--, var_v0++, var_v1++) {
        if (*var_v0 != *var_v1) {
            return -1;
        }
    }

    return 0;
}

f32 func_8071BF94(Racer* arg0, f32 arg1) {
    Machine* temp_a1;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fs1;
    f32 temp_fv1;
    f32 temp_ret;
    f32 temp_fa1;

    temp_fs0 = (arg0->unk_1F0 - 780.0f) / 1560.0f;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x078) >> 0xF) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x50C) >> 0x13) & 0xFF) | 0x600) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x780) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x390) >> 9) & 0xFF) * 0.001f);

    arg0->unk_1B4 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 = arg0->unk_1B4;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((f32) ((ROM_READ(0x0A0) >> 0x15) & 0xFF) * 0.1f) -
                 ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f)) *
                temp_fs0) +
               ((f32) (((ROM_READ(0x540) >> 0xD) & 0xFF) | 0x800) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x95C) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x50C) >> 6) & 0xFF) * 0.001f);
    arg0->unk_1B0 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv0 - temp_fv1) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1B0;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x1BC) >> 0x13) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x57C) >> 0xF) & 0xFF) * 0.1f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0x978) >> 0x15) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f)) *
          temp_fs0)) +
        ((f32) ((ROM_READ(0x550) >> 0x13) & 0xFF) * 0.001f);
    arg0->unk_1B8 = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1B8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x2C4) >> 0xE) & 0xFF) - (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x5D8) >> 4) & 0xFF);
    temp_fv1 = (((f32) ((ROM_READ(0x988) >> 0x18) & 0xFF) - (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x57C) >> 0xA) & 0xFF);
    arg0->unk_1BC = ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1BC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        ((((f32) ((ROM_READ(0x2FC) >> 0x12) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f)) *
         temp_fs0) +
        ((f32) ((ROM_READ(0x660) >> 0x10) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((f32) ((ROM_READ(0xA20) >> 0xC) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f)) *
          temp_fs0) +
         ((f32) ((ROM_READ(0x5E4) >> 0x14) & 0xFF) * 0.01f));
    arg0->unk_1C8 =
        ((temp_fv1 - temp_fv0) * arg1) + temp_fv0 + (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f)));
    temp_fs1 += arg0->unk_1C8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((f32) ((ROM_READ(0x36C) >> 0x10) & 0xFF) - (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF)) * temp_fs0) +
               (f32) ((ROM_READ(0x6A0) >> 0xC) & 0xFF);
    temp_fv1 = ((((f32) ((ROM_READ(0x1BC) >> 0xA) & 0xFF) - (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF)) * temp_fs0) +
                (f32) ((ROM_READ(0x60C) >> 0x16) & 0xFF));
    arg0->unk_1CC = arg0->unk_1C8 / (((temp_fv1 - temp_fv0) * arg1) + temp_fv0 +
                                     (0.2f * (temp_fv1 - temp_fv0) * (1.0f - SQ((2.0f * arg1) - 1.0f))));
    temp_fs1 += arg0->unk_1CC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = ((((ROM_READ(0x374) >> 3) & 0xFF) - ((f32) ((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
               (((ROM_READ(0x6D8) >> 2) & 0xFF) * 0.01f);
    temp_fv1 =
        (((((ROM_READ(0x1C8) >> 4) & 0xFF) * 0.01f) - ((f32) ((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f)) * temp_fs0) +
        (((ROM_READ(0x664) >> 2) & 0xFF) * 0.01f);
    temp_a1 = &gMachines[arg0->character];
    arg0->unk_1F8 = D_8076EFAC[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1F8;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 =
        (((f32) ((ROM_READ(0x384) >> 5) & 0xFF) - ((f32) ((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0xD) & 0xFF) * 0.001f);
    temp_fv1 =
        ((((f32) ((ROM_READ(0x248) >> 0xB) & 0xFF) * 0.001f) - ((f32) ((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f)) *
         temp_fs0) +
        (((ROM_READ(0x6A0) >> 0xE) & 0xFF) * 0.01f);
    arg0->unk_1FC = D_8076EFC0[temp_a1->machineStats[GRIP_STAT]] + ((temp_fv1 - temp_fv0) * arg1) + temp_fv0;
    temp_fs1 += arg0->unk_1FC;

    while (IO_READ(PI_STATUS_REG) & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {}

    temp_fv0 = (((ROM_READ(0x38C) & 0xFF) - (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f)) * temp_fs0) +
               (((ROM_READ(0x740) >> 0x12) & 0xFF) * 0.001f);
    temp_fv1 =
        (((((ROM_READ(0x250) >> 3) & 0xFF) * 0.001f) - (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f)) * temp_fs0) +
        (((ROM_READ(0x718) >> 0x17) & 0xFF) * 0.001f);

    temp_fa1 = ((temp_fv1 - temp_fv0) * arg0->unk_1A8) + temp_fv0;

    arg0->unk_1C0 = (D_8076EF98[temp_a1->machineStats[BOOST_STAT]] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C0;
    arg0->unk_1C4 = (D_8076EF98[2] + temp_fa1) / arg0->unk_1B8;
    temp_fs1 += arg0->unk_1C4;
    temp_ret = func_8071A310(arg1);
    temp_ret = func_8071A310(temp_ret);
    temp_ret = func_8071A310(temp_ret);
    arg0->unk_1D0 = ((D_8076EF80 - 1.0f) * temp_ret) + 1.0f;

    return temp_ret;
}

void func_8071CE08(Racer* arg0) {
    s32 pad[7];
    f32 temp;
    f32 temp_fv0_4;
    f32 var_fs0;
    s32 i;
    Mtx3F spE8;
    Machine* temp_s2;

    temp_s2 = &gMachines[arg0->character];
    arg0->customType = temp_s2->customType;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        arg0->machineIndex = 0;
    } else {
        arg0->machineIndex = arg0->character;
    }

    arg0->shadowType = temp_s2->shadowType;
    arg0->boostersType = temp_s2->boostersType;
    arg0->bodyRF = arg0->bodyR = temp_s2->red[arg0->machineSkinIndex];
    arg0->bodyGF = arg0->bodyG = temp_s2->green[arg0->machineSkinIndex];
    arg0->bodyBF = arg0->bodyB = temp_s2->blue[arg0->machineSkinIndex];
    arg0->unk_2DA = arg0->unk_2DC = arg0->unk_2DE = arg0->shadowR = arg0->shadowG = arg0->shadowB = 0;
    arg0->unk_2EC = 255.0f;
    arg0->unk_2F0 = 0.0f;
    arg0->unk_2F4 = 0.0f;
    arg0->unk_2F8 = arg0->bodyRF - arg0->unk_2EC;
    arg0->unk_2FC = arg0->bodyGF - arg0->unk_2F0;
    arg0->unk_300 = arg0->bodyBF - arg0->unk_2F4;
    if ((D_8076C7D8 != 0) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE) ||
        (gGameMode == GAMEMODE_COURSE_EDIT)) {
        arg0->stateFlags =
            RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_100000 | RACER_STATE_FLAGS_8000;
    } else {
        arg0->stateFlags = RACER_STATE_FLAGS_40000000 | RACER_STATE_FLAGS_20000000 | RACER_STATE_FLAGS_8000;
    }
    if ((arg0->id >= gNumPlayers) || (D_8076E59C != 0) || (gGameMode == GAMEMODE_RECORDS) ||
        (gGameMode == GAMEMODE_GP_END_CS) || (D_8076C7D8 != 0)) {
        arg0->stateFlags |= RACER_STATE_CPU_CONTROLLED;
    }
    arg0->unk_0C.unk_08 = func_i2_800B20D0(arg0->unk_0C.courseSegment, arg0->unk_0C.unk_04, &arg0->lapDistance);

    func_i2_800B2824(arg0->unk_0C.courseSegment, arg0->unk_0C.unk_04, &arg0->unk_24C, arg0->unk_0C.unk_08);
    // FAKE spE8 is compiler stack from a chain struct copy
    spE8 = arg0->unk_24C;
    arg0->unk_C0 = spE8;
    arg0->unk_E8 = spE8;

    spE8.x = arg0->unk_0C.unk_34;

    arg0->unk_180 = spE8.x;
    arg0->unk_10C = spE8.x;

    arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_19C.x = arg0->unk_C0.y.x;
    arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_19C.y = arg0->unk_C0.y.y;
    arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_19C.z = arg0->unk_C0.y.z;

    for (i = 0; i < 3; i++) {
        arg0->lapTimes[i] = NULL;
    }

    arg0->machineLod = arg0->unk_2B2 = arg0->unk_2B3 = 1;
    arg0->unk_168.y = -54321.0f;
    arg0->lapsCompletedDistance = -gCurrentCourseInfo->length;
    arg0->unk_284 = 0;
    arg0->unk_286 = 0;
    arg0->raceDistance = arg0->raceDistancePosition = arg0->lapsCompletedDistance + arg0->lapDistance;
    arg0->unk_2A4 = ((Math_Rand2() & 0x1FFFF) % 150) + 1;
    arg0->lapsCompleted = 1;
    arg0->unk_28C = NULL;
    arg0->unk_08 = 0x8000;
    arg0->startNewPracticeLap = arg0->unk_288 = arg0->unk_278 = arg0->unk_27A = arg0->unk_27C = arg0->unk_220 =
        arg0->spinOutTimer = arg0->completedLapsTime = arg0->raceTime = arg0->lap = arg0->unk_204 = arg0->unk_208 =
            arg0->unk_20C = arg0->boostTimer = arg0->unk_214 = arg0->unk_210 = 0;
    arg0->unk_118.x = arg0->unk_118.y = arg0->unk_118.z = arg0->pitForceFieldSize = arg0->unk_1DC = arg0->unk_E4 =
        arg0->unk_238 = arg0->unk_200 = arg0->unk_A0 = arg0->unk_1D4 = arg0->unk_1D8 = arg0->speed = arg0->maxSpeed =
            arg0->unk_198 = arg0->unk_18C.x = arg0->unk_18C.y = arg0->unk_18C.z = arg0->unk_68.x = arg0->unk_68.y =
                arg0->unk_68.z = arg0->unk_5C.x = arg0->unk_5C.y = arg0->unk_5C.z = arg0->unk_80.x = arg0->unk_80.y =
                    arg0->unk_80.z = arg0->velocity.x = arg0->velocity.y = arg0->velocity.z = var_fs0 = 0.0f;
    arg0->unk_A4 = arg0->unk_230 = arg0->unk_178 = arg0->unk_1E8 = 0.0f;
    arg0->shadowColorStrength = 1.0f;
    arg0->unk_1EC = 2500.0f / 27.0f;
    arg0->unk_17C = D_807B37B4;

    arg0->unk_1E0 = (((temp_s2->weight - 780.0f) * -0.0050000027f) / 1560.0f) + 0.054f;
    arg0->unk_1E4 = (((temp_s2->weight - 780.0f) * -0.004999999f) / 1560.0f) + 0.03f;
    arg0->unk_1F0 = temp_s2->weight;
    arg0->unk_1F4 =
        ((4 - temp_s2->machineStats[BODY_STAT]) * 312.0f) + 780.0f + ((312.0f * (temp_s2->weight - 780.0f)) / 1560.0f);

    // arg0->unk_1F4 = SQ(arg0->unk_1F4);
    // FAKE
    arg0->unk_1F4 = arg0->unk_1F4 * (temp = arg0->unk_1F4);

    for (i = 0; i < 2;) {
        temp_fv0_4 = func_8071BF94(arg0, arg0->unk_1A8);
        if (temp_fv0_4 == var_fs0) {
            i++;
        } else {
            i = 0;
        }
        var_fs0 = temp_fv0_4;
    }

    arg0->unk_234 = 1.7f;

    arg0->energy = arg0->maxEnergy = gBodyHealthValues[temp_s2->machineStats[BODY_STAT]];
    arg0->boostEnergyUsage = arg0->maxEnergy * 0.0015f;
    arg0->unk_31C = arg0->unk_1C4 - 1.0f;
    arg0->unk_320 = (0.5f - arg0->unk_1A8) * 0.5f;
    arg0->unk_324 = 1.0f / (2.0f * arg0->unk_1BC);
    arg0->unk_328 = 1.0f - arg0->unk_1D0;
    arg0->energyIncrease = arg0->maxEnergy * sEnergyRefillScale;

    arg0->unk_270 = (arg0->unk_0C.unk_08 *
                     (arg0->unk_0C.courseSegment->next->radiusLeft - arg0->unk_0C.courseSegment->radiusLeft)) +
                    arg0->unk_0C.courseSegment->radiusLeft;
    arg0->unk_274 = (arg0->unk_0C.unk_08 *
                     (arg0->unk_0C.courseSegment->next->radiusRight - arg0->unk_0C.courseSegment->radiusRight)) +
                    arg0->unk_0C.courseSegment->radiusRight;
}

extern OSMesgQueue D_8079A0F0;
extern GfxPool D_8024E260[];
extern s16 gRacerPositionsById[];
extern s16 gPlayer1OverallPosition;

void func_8071D48C(void) {
    s32 i;
    s32 j;
    s32 var_a3;
    s32 var_t0;
    Racer* var_s1_2;
    GhostRacer* temp_s0_2;
    MachineInfo sp6C;
    OSMesg sp68;

    D_807A16F8 = &D_8076E300[gCourseCtx.courseData.venue * 4];
    D_807A16FC = &D_8076E3F0[gCourseCtx.courseData.venue * 4];
    gPracticeBestLap = 600000 - 1;
    D_807B37AC = D_807B37B0 = 0.0f;
    sRaceFrameCount = gStartNewBestLap = gRacersKOd = D_807B37D4 = D_807B37C8 = D_807A16CC = D_807A16CE = D_807A16D0 =
        gRacersRetired = gRacersFinished = gCpuRacersRetired = gPlayerRacersRetired = gPlayerRacersFinished = 0;
    D_807B37CC = gCurrentCourseInfo->length * 0.5;
    D_807B37D0 = -D_807B37CC;
    if (gGameMode != GAMEMODE_GP_RACE) {
        D_807A16E6 = 0;
    }
    D_807A16E4 = D_807A16E6;
    D_807A1700++;

    if (gNumPlayers == 1) {
        switch (gGameMode) {
            case GAMEMODE_RECORDS:
            case GAMEMODE_COURSE_EDIT:
            case GAMEMODE_TIME_ATTACK:
                gTotalRacers = 1;
                break;
            case GAMEMODE_GP_END_CS:
                if (gPlayer1OverallPosition < 4) {
                    gTotalRacers = 3;
                    for (i = 1; i < 4; i++) {
                        for (j = 0; j < 30; j++) {
                            if (gRacerPositionsById[j] == i) {
                                break;
                            }
                        }
                        gRacers[0].lapTimes[i - 1] = (gRacers[j].character << 0x10) | gRacers[j].machineSkinIndex;
                    }

                    for (i = 0; i < 3; i++) {
                        gRacers[i].character = (gRacers[0].lapTimes[i] >> 0x10);
                        gRacers[i].machineSkinIndex = gRacers[0].lapTimes[i] & 0xFFFF;
                    }
                } else {
                    gTotalRacers = 1;
                }
                break;
            default:
                if (gGameMode == GAMEMODE_PRACTICE || gGameMode == GAMEMODE_DEATH_RACE || D_807A1700 == 1) {
                    func_8071A4BC();
                }
                gTotalRacers = 30;
                break;
        }
    } else {
        if (gSettingVsCom != 0) {
            gTotalRacers = 4;
            func_8071A5F0();
        } else {
            gTotalRacers = gNumPlayers;
        }
        if ((gTotalRacers != sLastMultiplayerTotalRacerCount) || (gNumPlayers != sLastMultiplayerPlayerCount)) {
            sLastMultiplayerTotalRacerCount = gTotalRacers;
            sLastMultiplayerPlayerCount = gNumPlayers;
            for (i = 0; i < 4; i++) {
                D_807A1610[i] = D_807A1620[i] = 0;
            }
        }
    }
    sLastRacer = &gRacers[gTotalRacers - 1];
    if (D_8076C7D8 != 0) {
        for (i = 29; i >= 0; i--) {
            gRacers[i].character = i;
            gRacers[i].machineSkinIndex = 0;
        }
        var_a3 = 0x21;
        for (var_a3 = 33; var_a3 > 0; var_a3--) {
            i = (Math_Rand1() & 0x1FFFF) % 30;
            j = (Math_Rand2() & 0x1FFFF) % 30;

            var_t0 = gRacers[i].character;
            gRacers[i].character = gRacers[j].character;
            gRacers[j].character = var_t0;
        }
    }
    if (gNumPlayers >= 2) {
        for (i = 0; i < gTotalRacers; i++) {
            gRacers[i].position = i + 1;
        }
    }

    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
        D_807B37B4 = 7.0f;
    } else {
        D_807B37B4 = 5.0f;
    }
    func_80719958();
    osRecvMesg(&D_8079A0F0, &sp68, OS_MESG_NOBLOCK);
    osRecvMesg(&D_8079A0F0, &sp68, OS_MESG_BLOCK);
    for (i = 0; i < gTotalRacers; i++) {
        gRacers[i].id = i;
        if (gGameMode != GAMEMODE_COURSE_EDIT) {
            func_i3_80040180(&gRacers[i]);
        }
        func_8071CE08(&gRacers[i]);
        if (i < gNumPlayers) {
            gRacers[i].unk_2A4 = 0;
            gControllers[gPlayerControlPorts[i]].unk_72 = gControllers[gPlayerControlPorts[i]].unk_78 = 1;
            D_807A1640[i] = 0;
            D_807A1630[i] = 0;
        }
    }

    func_8071B9F4();
    func_8071B634();
    func_8071BE0C();

    for (i = 0; i < ARRAY_COUNT(sRacerPairInfo); i++) {
        sRacerPairInfo[i].unk_10 = 0;
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            Lights_SetSource(&D_8024E260[i].unk_33A88[j], 100, 100, 100, 255, 255, 255, 69, 69, 69);
        }
    }

    for (i = 0; i < 4; i++) {
        D_807B37B8[i] = 0;
    }

    if (gGameMode == GAMEMODE_DEATH_RACE) {
        for (var_s1_2 = sLastRacer; var_s1_2 > gRacers; var_s1_2--) {
            var_s1_2->energy *= 0.5f;
            var_s1_2->maxEnergy *= 0.5f;
        }
    }
    if ((gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS) && (D_8076C7D8 == 0)) {
        D_807A16E0 = 1;
        if (gGameMode == GAMEMODE_COURSE_EDIT) {
            D_8076E5A0 = 0;
            gRaceIntroTimer = 100;
            for (var_s1_2 = sLastRacer; var_s1_2 >= gRacers; var_s1_2--) {
                var_s1_2->unk_17C = 13.0f;
                var_s1_2->unk_2A4 = 0;
            }
        } else {
            D_8076E5A0 = 1;
            gRaceIntroTimer = 460;
        }
    } else {
        D_807A16E0 = 0;
        gRaceIntroTimer = 0;

        if (D_8076C7D8 != 0 && gGameMode != GAMEMODE_RECORDS) {
            D_8076E5A0 = 1;
        } else {
            D_8076E5A0 = 0;
        }
        for (var_s1_2 = sLastRacer; var_s1_2 >= gRacers; var_s1_2--) {
            var_s1_2->stateFlags |= RACER_STATE_FLAGS_400000;
            var_s1_2->unk_17C = 13.0f;
            var_s1_2->unk_2A4 = 0;
        }
    }
    func_80719D70();

    for (i = 0; i < 3; i++) {
        gGhostRacers[i].exists = false;
    }
    D_807A16F2 = D_807A16F4 = D_807A16F6 = D_807B14F4 = D_807B14FA = D_807B14F8 = 0;
    gFastestGhostRacer = NULL;
    gFastestGhost = NULL;
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        sReplayRecordPosX = Math_Round(gRacers[0].unk_0C.unk_34.x);
        sReplayRecordPosY = Math_Round(gRacers[0].unk_0C.unk_34.y);
        sReplayRecordPosZ = Math_Round(gRacers[0].unk_0C.unk_34.z);
        if (gCurrentGhostType != GHOST_NONE) {
            func_8071A730(&sp6C);
            var_a3 = var_t0 = 0x40000000;

            for (i = 0; i < 3; i++) {
                if (gCurrentCourseInfo->encodedCourseIndex != gGhosts[i].encodedCourseIndex) {
                    continue;
                }

                if (gGhosts[i].ghostType == GHOST_PLAYER) {
                    if (gGhosts[i].raceTime < var_t0) {
                        var_t0 = gGhosts[i].raceTime;
                        gFastestGhost = &gGhosts[i];
                    }
                }
                if (gGhosts[i].ghostType != gCurrentGhostType) {
                    continue;
                }

                temp_s0_2 = &gGhostRacers[i];

                if (gGhosts[i].raceTime < var_a3) {
                    var_a3 = gGhosts[i].raceTime;
                    gFastestGhostRacer = temp_s0_2;
                }
                temp_s0_2->exists = true;
                temp_s0_2->ghost = &gGhosts[i];
                temp_s0_2->replayPtr = gGhosts[i].replayData;
                temp_s0_2->frameCount = 0;
                temp_s0_2->replayIndex = 0;
                temp_s0_2->initialized = false;
                temp_s0_2->scale = 1.0f;
                temp_s0_2->replayPosX = sReplayRecordPosX;
                temp_s0_2->replayPosY = sReplayRecordPosY;
                temp_s0_2->replayPosZ = sReplayRecordPosZ;
                temp_s0_2->racer = &gRacers[i + 1];
                gRacers[i + 1] = gRacers[0];
                var_s1_2 = temp_s0_2->racer;

                var_s1_2->id = i + 1;
                var_s1_2->character = temp_s0_2->ghost->machineInfo.character;

                if (func_8071BEF8(&temp_s0_2->ghost->machineInfo, &sp6C) != 0) {
                    var_s1_2->machineIndex = i + 7;
                } else {
                    var_s1_2->machineIndex = gRacers[0].machineIndex;
                }

                if (temp_s0_2->ghost->machineInfo.customType == CUSTOM_MACHINE_EDITED) {
                    var_s1_2->shadowType = D_8076DB24[temp_s0_2->ghost->machineInfo.frontType * 7 +
                                                      temp_s0_2->ghost->machineInfo.rearType];
                    var_s1_2->boostersType = temp_s0_2->ghost->machineInfo.rearType + 30;
                } else {
                    var_s1_2->shadowType = sDefaultMachines[var_s1_2->character].shadowType;
                    var_s1_2->boostersType = sDefaultMachines[var_s1_2->character].boostersType;
                }

                var_s1_2->bodyR = temp_s0_2->ghost->machineInfo.bodyR;
                var_s1_2->bodyG = temp_s0_2->ghost->machineInfo.bodyG;
                var_s1_2->bodyB = temp_s0_2->ghost->machineInfo.bodyB;
            }
        }
        sGhostReplayRecordingPtr = sGhostReplayRecordingBuffer;
        D_807B14F6 = sReplayRecordFrameCount = sGhostReplayRecordingSize = 0;
    }
}

typedef struct unk_806F2400_unk_00 {
    u8 body;
    u8 boost;
    u8 grip;
    u8 frontType;
    u8 rearType;
    u8 wingType;
    u8 logo;
    u8 unk_07;
    u8 decal;
    u8 red;
    u8 green;
    u8 blue;
    u8 numberR;
    u8 numberG;
    u8 numberB;
    u8 decalR;
    u8 decalG;
    u8 decalB;
    u8 cockpitR;
    u8 cockpitG;
    u8 cockpitB;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u8 unk_18;
    u8 unk_19;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
} unk_806F2400_unk_00;

typedef struct unk_806F2400 {
    unk_806F2400_unk_00 unk_00[30];
    s8 unk_3C0[30];
} unk_806F2400; // size = 0x3DE
extern unk_806F2400 D_806F2400;

extern u8 D_800D1308[];

#ifdef NON_MATCHING
void func_8071E0C0(void) {
    CustomMachineInfo* temp_a2;
    s32 characterSlot;
    s32 i;
    unk_806F2400_unk_00* temp_a1;

    for (i = 29; i >= 0; i--) {
        characterSlot = func_8070DBF0(i);
        temp_a1 = &D_806F2400.unk_00[characterSlot];
        if (D_806F2400.unk_3C0[characterSlot] > 0) {
            temp_a2 = &sCustomMachineInfo[i];
            temp_a2->decalR = temp_a1->decalR;
            temp_a2->decalG = temp_a1->decalG;
            temp_a2->decalB = temp_a1->decalB;
            temp_a2->numberR = temp_a1->numberR;
            temp_a2->numberG = temp_a1->numberG;
            temp_a2->numberB = temp_a1->numberB;
            temp_a2->cockpitR = temp_a1->cockpitR;
            temp_a2->cockpitG = temp_a1->cockpitG;
            temp_a2->cockpitB = temp_a1->cockpitB;
            temp_a2->frontType = temp_a1->frontType;
            temp_a2->rearType = temp_a1->rearType;
            temp_a2->wingType = temp_a1->wingType;
            temp_a2->decal = temp_a1->decal - 1;
            temp_a2->logo = temp_a1->logo - 1;
            gMachines[i].shadowType = D_8076DB24[(temp_a2->frontType * 7) + temp_a2->rearType];
            gMachines[i].boostersType = temp_a2->rearType + 30;
            gMachines[i].customType = CUSTOM_MACHINE_EDITED;
            gMachines[i].number = sDefaultMachines[i].number;
            gMachines[i].red[0] = temp_a1->red;
            gMachines[i].green[0] = temp_a1->green;
            gMachines[i].blue[0] = temp_a1->blue;
            gMachines[i].red[1] = temp_a1->red + 0x40;
            gMachines[i].green[1] = temp_a1->green + 0x40;
            gMachines[i].blue[1] = temp_a1->blue + 0x40;
            gMachines[i].red[2] = temp_a1->red + 0x80;
            gMachines[i].green[2] = temp_a1->green + 0x80;
            gMachines[i].blue[2] = temp_a1->blue + 0x80;
            gMachines[i].red[3] = temp_a1->red + 0xC0;
            gMachines[i].green[3] = temp_a1->green + 0xC0;
            gMachines[i].blue[3] = temp_a1->blue + 0xC0;
            gMachines[i].machineStats[BODY_STAT] = BODY_E - temp_a1->body;
            gMachines[i].machineStats[BOOST_STAT] = BOOST_E - temp_a1->boost;
            gMachines[i].machineStats[GRIP_STAT] = GRIP_E - temp_a1->grip;
            gMachines[i].weight =
                D_8076F2AC[temp_a2->frontType] + D_8076F2BC[temp_a2->rearType] + D_8076F2CC[temp_a2->wingType];
        } else if (D_806F2400.unk_3C0[characterSlot] < 0) {
            if ((i == CAPTAIN_FALCON) && (D_800D1308[CAPTAIN_FALCON] != 0)) {
                gMachines[i] = sDefaultMachines[30];
            } else {
                if ((i == SAMURAI_GOROH) && (D_800D1308[SAMURAI_GOROH] != 0)) {
                    gMachines[i] = sDefaultMachines[31];
                } else if ((i == JODY_SUMMER) && (D_800D1308[JODY_SUMMER] != 0)) {
                    gMachines[i] = sDefaultMachines[32];
                } else {
                    gMachines[i] = sDefaultMachines[i];
                }
            }
        } else {
            gMachines[i] = sDefaultMachines[i];
        }
    }
}
#else
void func_8071E0C0(void);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/27110/func_8071E0C0.s")
#endif

void func_8071E564(s32 character, s32 arg1) {
    Gfx* gfx;
    s32 i;
    Machine* machine = &gMachines[character];

    if (machine->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_8076DB58[arg1], sCustomMachineInfo[character].logo, machine->number - 1,
                                             sCustomMachineInfo[character].decal);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = Machine_DrawCustom(D_8076DBD0[arg1 * 6 + i], i, sCustomMachineInfo[character].frontType,
                                     sCustomMachineInfo[character].rearType, sCustomMachineInfo[character].wingType,
                                     sCustomMachineInfo[character].decalR, sCustomMachineInfo[character].decalG,
                                     sCustomMachineInfo[character].decalB, sCustomMachineInfo[character].numberR,
                                     sCustomMachineInfo[character].numberG, sCustomMachineInfo[character].numberB, 255,
                                     255, 255, sCustomMachineInfo[character].cockpitR,
                                     sCustomMachineInfo[character].cockpitG, sCustomMachineInfo[character].cockpitB);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (machine->customType != CUSTOM_MACHINE_DEFAULT) {
        character = machine->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
    } else {
        character = character;
    }

    gfx = sMachineLoadTexturesFuncs[character](D_8076DB58[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = sMachineDrawFuncs[character][i](D_8076DBD0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8071E794(MachineInfo* arg0, s32 arg1) {
    s32 pad[2];
    s32 var_v1;
    Gfx* gfx;
    s32 i;

    if (arg0->customType == CUSTOM_MACHINE_EDITED) {
        gfx = Machine_DrawLoadCustomTextures(D_8076DB58[arg1], arg0->logo, arg0->number, arg0->decal);
        gSPEndDisplayList(gfx);

        for (i = 4; i >= 0; i--) {
            gfx = Machine_DrawCustom(D_8076DBD0[arg1 * 6 + i], i, arg0->frontType, arg0->rearType, arg0->wingType,
                                     arg0->decalR, arg0->decalG, arg0->decalB, arg0->numberR, arg0->numberG,
                                     arg0->numberB, 255, 255, 255, arg0->cockpitR, arg0->cockpitG, arg0->cockpitB);
            gSPEndDisplayList(gfx);
        }

        return;
    }
    if (arg0->customType != CUSTOM_MACHINE_DEFAULT) {
        var_v1 = arg0->customType - CUSTOM_MACHINE_SUPER_FALCON + 30;
    } else {
        var_v1 = arg0->character;
    }

    gfx = sMachineLoadTexturesFuncs[var_v1](D_8076DB58[arg1]);
    gSPEndDisplayList(gfx);

    for (i = 4; i >= 0; i--) {
        gfx = sMachineDrawFuncs[var_v1][i](D_8076DBD0[arg1 * 6 + i]);
        gSPEndDisplayList(gfx);
    }
}

void func_8071E988(void) {
    s32 i;

    for (i = 29; i >= 0; i--) {
        func_8071E564(i, i);
    }
}

extern s32 gCourseIndex;

void func_8071E9C4(void) {
    CourseInfo* sp2C;
    s32 i;
    u8 var;

    sp2C = &gCourseInfos[gCourseIndex];

    for (i = 4; i >= 0; i--) {
        D_807B3C14[i] = i + 1;
        func_8071E794(&sp2C->recordMachineInfos[i], D_807B3C14[i]);
    }

    var = 5;
    D_807B3C14[var] = var + 1;
    func_8071E794(&sp2C->maxSpeedMachine, D_807B3C14[var]);
    var = 6;
    D_807B3C14[var] = var + 1;
    func_8071E794(&sp2C->bestTimeMachine, D_807B3C14[var]);
}

void func_8071EA88(void) {
    s32 i;

    func_8071E564(D_807A15F0[0], 0);
    func_8071E9C4();

    for (i = 0; i < 3; i++) {
        if (gCurrentCourseInfo->encodedCourseIndex == gGhosts[i].encodedCourseIndex) {
            func_8071E794(&gGhosts[i].machineInfo, i + 7);
        }
    }
}

void func_8071EB18(void) {
    Gfx* gfx;
    s32 i;
    s32 index;
    s32 j;

    for (i = 29; i >= 0; i--) {
        index = i;
        gfx = sMachineLoadTexturesFuncs[index](D_8076DB58[i]);
        gSPEndDisplayList(gfx);
        for (j = 4; j >= 0; j--) {
            gfx = sMachineDrawFuncs[index][j](D_8076DBD0[i * 6 + j]);
            gSPEndDisplayList(gfx);
        }
    }
}

void func_8071EC04(void) {
    s32 i;

    D_807A16E6 = D_807A1700 = 0;
    sLastMultiplayerTotalRacerCount = sLastMultiplayerPlayerCount = 0;

    for (i = 0; i < ARRAY_COUNT(gRacers); i++) {
        gRacers[i].character = (s8) (i % ARRAY_COUNT(gRacers));
        gRacers[i].machineSkinIndex = 0;
        gRacers[i].unk_1A8 = func_8071A2C8(0.5f);
        if (i < 4) {
            D_807A15F0[i] = (s16) gRacers[i].character;
            D_807A15F8[i] = gRacers[i].machineSkinIndex;
            gPlayerEngine[i] = 0.5f;
        }
    }
    func_8071E0C0();
}

void func_8071ED34(void) {
    func_8071EC04();
}

void func_8071ED54(Racer* arg0, s32 arg1) {
    Racer* temp_v0;

    if (arg1 < arg0->unk_288) {
        return;
    }

    temp_v0 = arg0->unk_28C;
    if (temp_v0 == NULL) {
        return;
    }
    if (temp_v0->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_RETIRED | RACER_STATE_SPINNING_OUT)) {
        return;
    }

    D_807A16E4++;
    gRacersKOd++;
    if ((gGameMode == GAMEMODE_GP_RACE) && (gRacersKOd == 5)) {
        gPlayerLives[0]++;
        func_i3_80053BE0();
        func_i3_TriggerLivesIncrease();
        if (D_807A16E0 != 0) {
            func_8074122C(0);
        }
    }
    temp_v0->unk_230 += temp_v0->maxEnergy * 0.125f;
    if ((gNumPlayers == 1) && (D_807A16E0 != 0)) {
        func_8074122C(0x39);
    }
}

void func_8071EE74(Racer* arg0, f32 arg1) {
    s32 pad[7];
    Vec3f sp90;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 i;

    if (arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000)) {
        if (((arg0->stateFlags & (RACER_STATE_FLAGS_40000000 | RACER_STATE_CRASHED)) ==
             (RACER_STATE_FLAGS_40000000 | RACER_STATE_CRASHED)) &&
            (D_8076E590 < arg1)) {
            arg0->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            arg0->unk_C0 = arg0->unk_24C;
            D_807A16D0++;
            if (arg0->id < gNumPlayers) {
                func_8071A17C(arg0);
            }
            if (D_807A16E0 != 0) {
                func_80741014(arg0->id, 8);
            }
            if (arg0->machineLod != 0) {
                if (arg0->unk_28C == NULL) {
                    sp90.x = 0.0f;
                    sp90.y = 0.0f;
                    sp90.z = 0.0f;
                } else {
                    sp90.z = arg0->unk_28C->velocity.x;
                    sp90.y = arg0->unk_28C->velocity.y;
                    sp90.x = arg0->unk_28C->velocity.z;
                }
                func_i2_800AC808(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, sp90.z, sp90.y,
                                 sp90.x, 40.0f, arg0);

                temp_s5 = arg0->bodyRF;
                temp_s6 = arg0->bodyGF;
                temp_s7 = arg0->bodyBF;

                i = (arg0->id < gNumPlayers) ? 60 : 30;
                do {

                    temp_fs2 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    temp_fs0 = ((Math_Rand2() & 0x1FFFF) * (7.0f / 131071.0f)) + 3.5f;

                    temp_fs1 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;

                    func_i2_800ACBE8(((s32) (Math_Rand2() % 32) - 0x10) + arg0->unk_0C.unk_34.x,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.y,
                                     ((s32) (Math_Rand1() % 32) - 0x10) + arg0->unk_0C.unk_34.z,
                                     sp90.z + (arg0->unk_C0.z.x * temp_fs2) + (temp_fs0 * arg0->unk_C0.y.x) +
                                         (temp_fs1 * arg0->unk_C0.x.x),
                                     sp90.y + (arg0->unk_C0.z.y * temp_fs2) + (temp_fs0 * arg0->unk_C0.y.y) +
                                         (temp_fs1 * arg0->unk_C0.x.y),
                                     sp90.x + (arg0->unk_C0.z.z * temp_fs2) + (temp_fs0 * arg0->unk_C0.y.z) +
                                         (temp_fs1 * arg0->unk_C0.x.z),
                                     &arg0->unk_C0, temp_s5, temp_s6, temp_s7, arg0);
                    i--;
                } while (i != 0);
            }
        }
    } else {
        if (D_8076E5A0 != 0) {
            arg0->energy -= arg1;
        }
        arg0->stateFlags |= RACER_STATE_FLAGS_20000;
        if (arg0->energy < 0.0f) {
            if (arg0->machineLod == 0) {
                arg0->energy = 0.1f;
                return;
            }
            arg0->energy = 0.0f;
            arg0->unk_238 = 0.2f * arg1;
            if (arg0->unk_238 > 1.0f) {
                arg0->unk_238 = 1.0f;
            }
            if (Math_Rand1() % 2) {
                arg0->unk_238 *= -1.0f;
            }

            if (!(arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
                arg0->stateFlags |= RACER_STATE_SPINNING_OUT;
                arg0->stateFlags &= ~RACER_STATE_FLAGS_400000;
                arg0->spinOutTimer = 1;
                arg0->unk_234 = 2.0f;
                func_8071ED54(arg0, 60);
            }
        }
    }
}

void func_8071F334(Racer* arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 pad;
    Racer* var;
    f32 var_fv0;

    var_fv0 = arg0->unk_24C.z.x * arg3;
    arg0->unk_0C.unk_28.x -= var_fv0;
    arg0->unk_0C.unk_34.x -= var_fv0;
    arg0->unk_0C.unk_44.x -= var_fv0;

    var_fv0 = arg0->unk_24C.z.y * arg3;
    arg0->unk_0C.unk_28.y -= var_fv0;
    arg0->unk_0C.unk_34.y -= var_fv0;
    arg0->unk_0C.unk_44.y -= var_fv0;

    var_fv0 = arg0->unk_24C.z.z * arg3;
    arg0->unk_0C.unk_28.z -= var_fv0;
    arg0->unk_0C.unk_34.z -= var_fv0;
    arg0->unk_0C.unk_44.z -= var_fv0;

    arg0->unk_0C.unk_40 = sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));

    if (arg1 * arg2 <= 0.0f) {
        return;
    }

    if (arg1 * arg2 > 0.01f) {
        if (arg0->machineLod != 0) {
            func_i2_800AC680(arg0->unk_0C.unk_34.x + ((arg2 * 15.0f) * arg0->unk_24C.z.x),
                             arg0->unk_0C.unk_34.y + ((arg2 * 15.0f) * arg0->unk_24C.z.y),
                             arg0->unk_0C.unk_34.z + ((arg2 * 15.0f) * arg0->unk_24C.z.z), arg0->velocity.x,
                             arg0->velocity.y, arg0->velocity.z, (arg1 * arg2 * 1.5f) + 18.0f, arg0);
        }
        if (D_807A16E0 != 0) {
            func_80741014(arg0->id, 3);
        }
        func_8071EE74(arg0, arg1 * arg2 * 0.7f);
    }

    arg0->velocity.x = (arg0->velocity.x - arg0->unk_234 * arg1 * arg0->unk_24C.z.x) * 0.998f;
    arg0->velocity.y = (arg0->velocity.y - arg0->unk_234 * arg1 * arg0->unk_24C.z.y) * 0.998f;
    arg0->velocity.z = (arg0->velocity.z - arg0->unk_234 * arg1 * arg0->unk_24C.z.z) * 0.998f;

    // FAKE
    var = arg0;
    var->unk_118.x = var->unk_24C.z.x * (-0.15f * arg1);
    var->unk_118.y = var->unk_24C.z.y * (-0.15f * arg1);
    var->unk_118.z = var->unk_24C.z.z * (-0.15f * arg1);

    arg0->stateFlags |= RACER_STATE_FLAGS_2000;
}

void func_8071F5C4(Racer* arg0) {
    f32 temp_fv0;
    f32 temp_fv1;

    temp_fv0 =
        ((arg0->unk_A8.x * arg0->unk_B4.x) + (arg0->unk_A8.y * arg0->unk_B4.y) + (arg0->unk_A8.z * arg0->unk_B4.z)) *
        0.15f * arg0->unk_E4;

    arg0->unk_B4.x = arg0->unk_C0.y.x + (temp_fv0 * arg0->unk_C0.x.x);
    arg0->unk_B4.y = arg0->unk_C0.y.y + (temp_fv0 * arg0->unk_C0.x.y);
    arg0->unk_B4.z = arg0->unk_C0.y.z + (temp_fv0 * arg0->unk_C0.x.z);

    temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
    arg0->unk_B4.x *= temp_fv1;
    arg0->unk_B4.y *= temp_fv1;
    arg0->unk_B4.z *= temp_fv1;
}

void func_8071F6B0(Racer* arg0) {

    arg0->unk_A8.x -= 0.5f * arg0->unk_A8.x;
    arg0->unk_A8.y += 0.5f * (1.0f - arg0->unk_A8.y);
    arg0->unk_A8.z -= 0.5f * arg0->unk_A8.z;
}

void func_8071F6F8(Racer* arg0, f32 arg1) {
    f32 temp_ft4;
    f32 sp50;
    f32 temp_fv0;

    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        arg0->unk_270 += 57.5f;
        arg0->unk_274 += 57.5f;
        func_80721714(arg0);

        arg0->unk_270 -= 57.5f;
        arg0->unk_274 -= 57.5f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            return;
        }
        sp50 = (arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z);
        if ((sp50 < -arg0->unk_274) || (arg0->unk_270 < sp50)) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000;
            func_8071EE74(arg0, 2.0f);
            func_i2_800AC680(arg0->unk_0C.unk_34.x, arg0->unk_0C.unk_34.y, arg0->unk_0C.unk_34.z, arg0->velocity.x,
                             arg0->velocity.y, arg0->velocity.z, 40.0f, arg0);
            if (D_807A16E0 != 0) {
                func_80741014(arg0->id, 3);
            }
        }
    } else {
        sp50 = (arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
               (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z);
        arg0->unk_A0 = (arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                       (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z);
        arg0->unk_19C.x = arg0->unk_24C.y.x;
        arg0->unk_19C.y = arg0->unk_24C.y.y;
        arg0->unk_19C.z = arg0->unk_24C.y.z;

        if (arg1 < arg0->unk_A0) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_807A16E0 != 0) {
                        func_80740BF8(arg0->id, 8);
                    }
                }
            }
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }

        if (arg0->unk_A0 < 0.0f) {
            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.x;
            arg0->unk_0C.unk_28.x -= temp_fv0;
            arg0->unk_0C.unk_34.x -= temp_fv0;
            arg0->unk_0C.unk_44.x -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.y;
            arg0->unk_0C.unk_28.y -= temp_fv0;
            arg0->unk_0C.unk_34.y -= temp_fv0;
            arg0->unk_0C.unk_44.y -= temp_fv0;

            temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.z;
            arg0->unk_0C.unk_28.z -= temp_fv0;
            arg0->unk_0C.unk_34.z -= temp_fv0;
            arg0->unk_0C.unk_44.z -= temp_fv0;

            arg0->unk_A0 = 0.0f;

            temp_ft4 = (arg0->unk_24C.y.x * arg0->velocity.x) + (arg0->unk_24C.y.y * arg0->velocity.y) +
                       (arg0->unk_24C.y.z * arg0->velocity.z);
            if (temp_ft4 < 0.0f) {
                arg0->velocity.x -= temp_ft4 * arg0->unk_24C.y.x;
                arg0->velocity.y -= temp_ft4 * arg0->unk_24C.y.y;
                arg0->velocity.z -= temp_ft4 * arg0->unk_24C.y.z;
                if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                    func_8074241C(arg0->id, temp_ft4);
                }
            }
        }

        if (arg0->unk_A0 <= 15.0f) {
            arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {

                if (arg0->unk_08 & 0x2000) {
                    arg0->unk_08 &= ~0x2000;
                    if (D_807A16E0 != 0) {
                        func_80740CE8(arg0->id, 8);
                    }
                }
            }

            arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.y.x;
            arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.y.y;
            arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.y.z;

        } else {
            arg0->stateFlags |= RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_807A16E0 != 0) {
                        func_80740BF8(arg0->id, 8);
                    }
                }
            }
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);

            if (arg0->unk_A0 < 30.0f) {

                temp_ft4 = (arg0->unk_A0 - 15.0f) / 15.0f;
                arg0->unk_A8.x = (arg0->unk_A8.x - arg0->unk_24C.y.x) * temp_ft4 + arg0->unk_24C.y.x;
                arg0->unk_A8.y = (arg0->unk_A8.y - arg0->unk_24C.y.y) * temp_ft4 + arg0->unk_24C.y.y;
                arg0->unk_A8.z = (arg0->unk_A8.z - arg0->unk_24C.y.z) * temp_ft4 + arg0->unk_24C.y.z;

                arg0->unk_B4.x = (arg0->unk_B4.x - arg0->unk_24C.y.x) * temp_ft4 + arg0->unk_B4.x;
                arg0->unk_B4.y = (arg0->unk_B4.y - arg0->unk_24C.y.y) * temp_ft4 + arg0->unk_B4.y;
                arg0->unk_B4.z = (arg0->unk_B4.z - arg0->unk_24C.y.z) * temp_ft4 + arg0->unk_B4.z;

                temp_fv0 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
                arg0->unk_B4.x *= temp_fv0;
                arg0->unk_B4.y *= temp_fv0;
                arg0->unk_B4.z *= temp_fv0;
            }
        }

        if (sp50 < -arg0->unk_274) {
            func_8071F334(arg0,
                          (arg0->unk_24C.z.x * arg0->velocity.x) + (arg0->unk_24C.z.y * arg0->velocity.y) +
                              (arg0->unk_24C.z.z * arg0->velocity.z),
                          -1.0f, arg0->unk_274 + sp50);
        } else if (arg0->unk_270 < sp50) {
            func_8071F334(arg0,
                          (arg0->unk_24C.z.x * arg0->velocity.x) + (arg0->unk_24C.z.y * arg0->velocity.y) +
                              (arg0->unk_24C.z.z * arg0->velocity.z),
                          1.0f, sp50 - arg0->unk_270);
        } else {
            arg0->unk_0C.unk_40 =
                sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
        }

        arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.y.x);
        arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.y.y);
        arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.y.z);
    }
}

void func_8071FDE4(Racer* arg0) {
    func_8071F6F8(arg0, 40.0f);
}

void func_8071FE04(Racer* arg0) {
    func_8071F6F8(arg0, 145.0f);
}

void func_8071FE24(Racer* arg0) {
    func_8071F6F8(arg0, 210.0f);
}

extern f32 D_800C18F8[];

void func_8071FE44(Racer* arg0) {
    f32 var_fv0;
    f32 temp_fv0;
    f32 var_fv1;
    f32 sp60;
    f32 var_fs0;
    f32 sp58;
    f32 sp54;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        var_fv0 = sp60 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp60 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        var_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * var_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * var_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * var_fv1;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = ((arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z)) -
                  23.0f;
        if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
            if ((var_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
                func_8071F5C4(arg0);
                func_8071F6B0(arg0);
                arg0->unk_168.y = -54321.0f;
                return;
            }
            arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
        } else if (var_fv1 >= 0.0f) {
            arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
            if (arg0->id < gNumPlayers) {
                if (!(arg0->unk_08 & 0x2000)) {
                    arg0->unk_08 |= 0x2000;
                    if (D_807A16E0 != 0) {
                        func_80740BF8(arg0->id, 8);
                    }
                }
            }
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
    } else if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if (arg0->unk_270 < arg0->unk_0C.unk_40) {
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    }

    if (var_fs0 != 0.0f) {
        var_fv1 = var_fv0 + (arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                  (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z);
        if (var_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = var_fv1;
            arg0->unk_19C.x = arg0->unk_24C.y.x;
            arg0->unk_19C.y = arg0->unk_24C.y.y;
            arg0->unk_19C.z = arg0->unk_24C.y.z;

            arg0->unk_B4.x = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.y.x) +
                             (var_fs0 * arg0->unk_24C.x.x);
            arg0->unk_B4.y = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.y.y) +
                             (var_fs0 * arg0->unk_24C.x.y);
            arg0->unk_B4.z = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_24C.y.z) +
                             (var_fs0 * arg0->unk_24C.x.z);

            if (false) {
                // FAKE: ARTIFICIALLY INCREASE COMPILER STACK
                arg0->unk_B4.x = arg0->unk_B4.y = arg0->unk_B4.z;
            }

            var_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= var_fv1;
            arg0->unk_B4.y *= var_fv1;
            arg0->unk_B4.z *= var_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.x;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.y;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.z;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.y.x * arg0->velocity.x) + (arg0->unk_24C.y.y * arg0->velocity.y) +
                          (arg0->unk_24C.y.z * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->unk_24C.y.x;
                    arg0->velocity.y -= var_fs0 * arg0->unk_24C.y.y;
                    arg0->velocity.z -= var_fs0 * arg0->unk_24C.y.z;
                    if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                        func_8074241C(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }
        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.y.x) * sp60) + arg0->unk_24C.y.x;
        sp58 = ((arg0->unk_B4.y - arg0->unk_24C.y.y) * sp60) + arg0->unk_24C.y.y;
        sp54 = ((arg0->unk_B4.z - arg0->unk_24C.y.z) * sp60) + arg0->unk_24C.y.z;

        var_fv1 = sqrtf(SQ(var_fs0) + SQ(sp58) + SQ(sp54));
        if (var_fv1 > 0.01f) {
            var_fv1 = 1.0f / var_fv1;
            arg0->unk_B4.x = var_fv1 * var_fs0;
            arg0->unk_B4.y = var_fv1 * sp58;
            arg0->unk_B4.z = var_fv1 * sp54;
        }

        arg0->unk_A8.x = ((arg0->unk_19C.x - arg0->unk_24C.y.x) * sp60) + arg0->unk_24C.y.x;
        arg0->unk_A8.y = ((arg0->unk_19C.y - arg0->unk_24C.y.y) * sp60) + arg0->unk_24C.y.y;
        arg0->unk_A8.z = ((arg0->unk_19C.z - arg0->unk_24C.y.z) * sp60) + arg0->unk_24C.y.z;
    } else {
        arg0->unk_A8 = arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        var_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= var_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;

        arg0->unk_0C.unk_28.y *= var_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;

        arg0->unk_0C.unk_28.z *= var_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                func_8074241C(arg0->id, var_fs0);
            }
        }
    }

    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_807A16E0 != 0) {
                    func_80740CE8(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
    }
}

#ifdef NON_MATCHING
// https://decomp.me/scratch/F15P1 stack
void func_807206FC(Racer* arg0) {
    f32 var_fa1;
    f32 temp_fv1;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fv0;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        sp5C = sp58 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        sp5C *= arg0->unk_270;
        var_fa1 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fa1 = -arg0->unk_270;
        sp5C = sp58 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        sp5C *= arg0->unk_270;
    } else {
        var_fa1 = 0.0f;
        sp5C = arg0->unk_270;
    }

    arg0->unk_A0 = arg0->unk_0C.unk_40 - sp5C;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        temp_fv1 = 1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * temp_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * temp_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * temp_fv1;
    }

    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((arg0->unk_270 + 200.0f) < arg0->unk_0C.unk_40) {
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->unk_270 + 200.0f) < arg0->unk_0C.unk_40) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
        func_8071F5C4(arg0);
        func_8071F6B0(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (var_fa1 != 0.0f) {

        sp54 = ((arg0->unk_19C.x - arg0->unk_24C.y.x) * sp58) + arg0->unk_24C.y.x;
        sp50 = ((arg0->unk_19C.y - arg0->unk_24C.y.y) * sp58) + arg0->unk_24C.y.y;
        sp4C = ((arg0->unk_19C.z - arg0->unk_24C.y.z) * sp58) + arg0->unk_24C.y.z;

        temp_fv1 = sqrtf(SQ(sp54) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->unk_B4.x = temp_fv1 * sp54;
            arg0->unk_B4.y = temp_fv1 * sp50;
            arg0->unk_B4.z = temp_fv1 * sp4C;
        }

        temp_fv1 = 1.0f - sp58;
        sp54 = arg0->unk_24C.y.x * SQ(temp_fv1);
        sp50 = arg0->unk_24C.y.y * SQ(temp_fv1);
        sp4C = arg0->unk_24C.y.z * SQ(temp_fv1);

        arg0->unk_A8.x = ((arg0->unk_19C.x - sp54) * sp58) + sp54;
        arg0->unk_A8.y = ((arg0->unk_19C.y - sp50) * sp58) + sp50;
        arg0->unk_A8.z = ((arg0->unk_19C.z - sp4C) * sp58) + sp4C;
        temp_fv1 = (sp58 * 200.0f) + sp5C + (arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) +
                   (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) + (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z);
        if (temp_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = temp_fv1;
            arg0->unk_19C.x = arg0->unk_24C.y.x;
            arg0->unk_19C.y = arg0->unk_24C.y.y;
            arg0->unk_19C.z = arg0->unk_24C.y.z;
            if (arg0->unk_A0 < 0.0f) {

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.x;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.y;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.z;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;
            }
        }
    } else {
        arg0->unk_A8 = arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_0C.unk_40 < sp5C) {
        temp_fv1 = sp5C / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = sp5C;

        arg0->unk_0C.unk_28.x *= temp_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;

        arg0->unk_0C.unk_28.y *= temp_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;

        arg0->unk_0C.unk_28.z *= temp_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fa1 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fa1 < 0.0f) {
            arg0->velocity.x -= (var_fa1 * arg0->unk_19C.x);
            arg0->velocity.y -= (var_fa1 * arg0->unk_19C.y);
            arg0->velocity.z -= (var_fa1 * arg0->unk_19C.z);
            // FAKE: lowers stack
            if (1) {}
            if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                func_8074241C(arg0->id, var_fa1);
            }
        }
    }

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_807A16E0 != 0) {
                    func_80740CE8(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/27110/func_807206FC.s")
#endif

void func_80720E2C(Racer* arg0) {
    f32 var_fv0;
    f32 var_fs0;
    f32 temp_fv1;
    f32 sp58;
    f32 temp_fv0;
    f32 sp50;
    f32 sp4C;

    if (arg0->unk_0C.unk_04 < arg0->unk_0C.courseSegment->unk_68) {
        var_fv0 = sp58 = arg0->unk_0C.unk_08 / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = arg0->unk_270;
    } else if (arg0->unk_0C.courseSegment->unk_6C < arg0->unk_0C.unk_04) {
        var_fv0 = sp58 = (1.0f - arg0->unk_0C.unk_08) / arg0->unk_0C.courseSegment->unk_70;
        var_fv0 *= arg0->unk_270;
        var_fs0 = -arg0->unk_270;
    } else {
        var_fv0 = arg0->unk_270;
        var_fs0 = 0.0f;
    }

    arg0->unk_A0 = arg0->unk_270 - arg0->unk_0C.unk_40;
    if (arg0->unk_0C.unk_40 > 0.01f) {
        temp_fv1 = -1.0f / arg0->unk_0C.unk_40;
        arg0->unk_19C.x = arg0->unk_0C.unk_28.x * temp_fv1;
        arg0->unk_19C.y = arg0->unk_0C.unk_28.y * temp_fv1;
        arg0->unk_19C.z = arg0->unk_0C.unk_28.z * temp_fv1;
    }

    temp_fv1 = (((arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                 (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z)) -
                23.0f) +
               (var_fv0 * 0.3826834f);
    if (arg0->stateFlags & RACER_STATE_FLAGS_80000000) {
        if ((temp_fv1 >= 0.0f) || (arg0->unk_270 < arg0->unk_0C.unk_40)) {
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;

    } else if (temp_fv1 >= 0.0f) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
        func_8071F5C4(arg0);
        func_8071F6B0(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (var_fs0 != 0.0f) {
        temp_fv1 = var_fv0 + (arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z);
        if (temp_fv1 < arg0->unk_A0) {
            arg0->unk_A0 = temp_fv1;
            arg0->unk_19C.x = arg0->unk_24C.y.x;
            arg0->unk_19C.y = arg0->unk_24C.y.y;
            arg0->unk_19C.z = arg0->unk_24C.y.z;
            arg0->unk_B4.x = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.x) +
                             (var_fs0 * arg0->unk_24C.x.x);
            arg0->unk_B4.y = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.y) +
                             (var_fs0 * arg0->unk_24C.x.y);
            arg0->unk_B4.z = (D_800C18F8[TRACK_SHAPE_INDEX(TRACK_SHAPE_HALF_PIPE)] * arg0->unk_19C.z) +
                             (var_fs0 * arg0->unk_24C.x.z);

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));

            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;

            if (arg0->unk_A0 < 0.0f) {
                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.x;
                arg0->unk_0C.unk_28.x -= temp_fv0;
                arg0->unk_0C.unk_34.x -= temp_fv0;
                arg0->unk_0C.unk_44.x -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.y;
                arg0->unk_0C.unk_28.y -= temp_fv0;
                arg0->unk_0C.unk_34.y -= temp_fv0;
                arg0->unk_0C.unk_44.y -= temp_fv0;

                temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.z;
                arg0->unk_0C.unk_28.z -= temp_fv0;
                arg0->unk_0C.unk_34.z -= temp_fv0;
                arg0->unk_0C.unk_44.z -= temp_fv0;

                arg0->unk_0C.unk_40 =
                    sqrtf(SQ(arg0->unk_0C.unk_28.x) + SQ(arg0->unk_0C.unk_28.y) + SQ(arg0->unk_0C.unk_28.z));
                arg0->unk_A0 = 0.0f;

                var_fs0 = (arg0->unk_24C.y.x * arg0->velocity.x) + (arg0->unk_24C.y.y * arg0->velocity.y) +
                          (arg0->unk_24C.y.z * arg0->velocity.z);
                if (var_fs0 < 0.0f) {
                    arg0->velocity.x -= var_fs0 * arg0->unk_24C.y.x;
                    arg0->velocity.y -= var_fs0 * arg0->unk_24C.y.y;
                    arg0->velocity.z -= var_fs0 * arg0->unk_24C.y.z;
                    if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                        func_8074241C(arg0->id, var_fs0);
                    }
                }
            }
        } else {
            arg0->unk_B4 = arg0->unk_19C;
        }

        var_fs0 = ((arg0->unk_B4.x - arg0->unk_24C.y.x) * sp58) + arg0->unk_24C.y.x;
        sp50 = ((arg0->unk_B4.y - arg0->unk_24C.y.y) * sp58) + arg0->unk_24C.y.y;
        sp4C = ((arg0->unk_B4.z - arg0->unk_24C.y.z) * sp58) + arg0->unk_24C.y.z;

        temp_fv1 = sqrtf(SQ(var_fs0) + SQ(sp50) + SQ(sp4C));
        if (temp_fv1 > 0.01f) {
            temp_fv1 = 1.0f / temp_fv1;
            arg0->unk_B4.x = temp_fv1 * var_fs0;
            arg0->unk_B4.y = temp_fv1 * sp50;
            arg0->unk_B4.z = temp_fv1 * sp4C;
        }
    } else {
        arg0->unk_B4 = arg0->unk_19C;
    }

    if (arg0->unk_270 < arg0->unk_0C.unk_40) {
        temp_fv1 = arg0->unk_270 / arg0->unk_0C.unk_40;
        arg0->unk_0C.unk_40 = arg0->unk_270;

        arg0->unk_0C.unk_28.x *= temp_fv1;
        arg0->unk_0C.unk_34.x = arg0->unk_0C.unk_44.x = arg0->unk_0C.unk_28.x + arg0->unk_0C.unk_1C.x;
        arg0->unk_0C.unk_28.y *= temp_fv1;
        arg0->unk_0C.unk_34.y = arg0->unk_0C.unk_44.y = arg0->unk_0C.unk_28.y + arg0->unk_0C.unk_1C.y;
        arg0->unk_0C.unk_28.z *= temp_fv1;
        arg0->unk_0C.unk_34.z = arg0->unk_0C.unk_44.z = arg0->unk_0C.unk_28.z + arg0->unk_0C.unk_1C.z;

        arg0->unk_A0 = 0.0f;

        var_fs0 = (arg0->unk_19C.x * arg0->velocity.x) + (arg0->unk_19C.y * arg0->velocity.y) +
                  (arg0->unk_19C.z * arg0->velocity.z);
        if (var_fs0 < 0.0f) {
            arg0->velocity.x -= var_fs0 * arg0->unk_19C.x;
            arg0->velocity.y -= var_fs0 * arg0->unk_19C.y;
            arg0->velocity.z -= var_fs0 * arg0->unk_19C.z;
            if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                func_8074241C(arg0->id, var_fs0);
            }
        }
    }

    arg0->unk_A8.x = arg0->unk_24C.y.x;
    arg0->unk_A8.y = arg0->unk_24C.y.y;
    arg0->unk_A8.z = arg0->unk_24C.y.z;
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_19C.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_19C.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_19C.z);

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_807A16E0 != 0) {
                    func_80740CE8(arg0->id, 8);
                }
            }
        }
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
    }
}

void func_8072163C(Racer* arg0) {

    arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
    if (arg0->id < gNumPlayers) {
        if (!(arg0->unk_08 & 0x2000)) {
            arg0->unk_08 |= 0x2000;
            if (D_807A16E0 != 0) {
                func_80740BF8(arg0->id, 8);
            }
        }
    }

    arg0->unk_168.y = -54321.0f;

    arg0->unk_A0 = (arg0->unk_0C.unk_28.x * arg0->unk_24C.y.x) + (arg0->unk_0C.unk_28.y * arg0->unk_24C.y.y) +
                   (arg0->unk_0C.unk_28.z * arg0->unk_24C.y.z);

    arg0->unk_19C.x = arg0->unk_24C.y.x;
    arg0->unk_19C.y = arg0->unk_24C.y.y;
    arg0->unk_19C.z = arg0->unk_24C.y.z;
    func_8071F5C4(arg0);
    func_8071F6B0(arg0);
}

void func_80721714(Racer* arg0) {
    f32 temp_fv1;
    f32 sp48;
    f32 temp_fv0;

    sp48 = (arg0->unk_24C.z.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.z.y * arg0->unk_0C.unk_28.y) +
           (arg0->unk_24C.z.z * arg0->unk_0C.unk_28.z);

    arg0->unk_A0 = (arg0->unk_24C.y.x * arg0->unk_0C.unk_28.x) + (arg0->unk_24C.y.y * arg0->unk_0C.unk_28.y) +
                   (arg0->unk_24C.y.z * arg0->unk_0C.unk_28.z);

    arg0->unk_19C.x = arg0->unk_24C.y.x;
    arg0->unk_19C.y = arg0->unk_24C.y.y;
    arg0->unk_19C.z = arg0->unk_24C.y.z;

    // FAKE
    if ((arg0->stateFlags ^ 0) & RACER_STATE_FLAGS_80000000) {
        if ((arg0->unk_A0 < -100.0f) || (arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
            func_8071F5C4(arg0);
            func_8071F6B0(arg0);
            arg0->unk_168.y = -54321.0f;
            return;
        }
        arg0->stateFlags &= ~RACER_STATE_FLAGS_80000000;
    } else if ((arg0->unk_A0 > 30.0f) || (sp48 < -arg0->unk_274) || (arg0->unk_270 < sp48)) {
        arg0->stateFlags |= RACER_STATE_FLAGS_80000000 | RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
        func_8071F5C4(arg0);
        func_8071F6B0(arg0);
        arg0->unk_168.y = -54321.0f;
        return;
    }

    if (arg0->unk_A0 < 0.0f) {

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.x;
        arg0->unk_0C.unk_28.x -= temp_fv0;
        arg0->unk_0C.unk_34.x -= temp_fv0;
        arg0->unk_0C.unk_44.x -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.y;
        arg0->unk_0C.unk_28.y -= temp_fv0;
        arg0->unk_0C.unk_34.y -= temp_fv0;
        arg0->unk_0C.unk_44.y -= temp_fv0;

        temp_fv0 = arg0->unk_A0 * arg0->unk_24C.y.z;
        arg0->unk_0C.unk_28.z -= temp_fv0;
        arg0->unk_0C.unk_34.z -= temp_fv0;
        arg0->unk_0C.unk_44.z -= temp_fv0;

        arg0->unk_A0 = 0.0f;
        sp48 = (arg0->unk_24C.y.x * arg0->velocity.x) + (arg0->unk_24C.y.y * arg0->velocity.y) +
               (arg0->unk_24C.y.z * arg0->velocity.z);

        if (sp48 < 0.0f) {
            arg0->velocity.x -= sp48 * arg0->unk_24C.y.x;
            arg0->velocity.y -= sp48 * arg0->unk_24C.y.y;
            arg0->velocity.z -= sp48 * arg0->unk_24C.y.z;
            if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
                func_8074241C(arg0->id, sp48);
            }
        }
    }

    if (arg0->unk_A0 <= 15.0f) {
        arg0->stateFlags &= ~RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (arg0->unk_08 & 0x2000) {
                arg0->unk_08 &= ~0x2000;
                if (D_807A16E0 != 0) {
                    func_80740CE8(arg0->id, 8);
                }
            }
        }
        arg0->unk_A8.x = arg0->unk_B4.x = arg0->unk_24C.y.x;
        arg0->unk_A8.y = arg0->unk_B4.y = arg0->unk_24C.y.y;
        arg0->unk_A8.z = arg0->unk_B4.z = arg0->unk_24C.y.z;
    } else {
        arg0->stateFlags |= RACER_STATE_AIRBORNE;
        if (arg0->id < gNumPlayers) {
            if (!(arg0->unk_08 & 0x2000)) {
                arg0->unk_08 |= 0x2000;
                if (D_807A16E0 != 0) {
                    func_80740BF8(arg0->id, 8);
                }
            }
        }
        func_8071F5C4(arg0);
        func_8071F6B0(arg0);

        if (arg0->unk_A0 < 30.0f) {
            temp_fv1 = (arg0->unk_A0 - 15.0f) / 15.0f;

            arg0->unk_A8.x = ((arg0->unk_A8.x - arg0->unk_24C.y.x) * temp_fv1) + arg0->unk_24C.y.x;
            arg0->unk_A8.y = ((arg0->unk_A8.y - arg0->unk_24C.y.y) * temp_fv1) + arg0->unk_24C.y.y;
            arg0->unk_A8.z = ((arg0->unk_A8.z - arg0->unk_24C.y.z) * temp_fv1) + arg0->unk_24C.y.z;

            arg0->unk_B4.x = ((arg0->unk_B4.x - arg0->unk_24C.y.x) * temp_fv1) + arg0->unk_B4.x;
            arg0->unk_B4.y = ((arg0->unk_B4.y - arg0->unk_24C.y.y) * temp_fv1) + arg0->unk_B4.y;
            arg0->unk_B4.z = ((arg0->unk_B4.z - arg0->unk_24C.y.z) * temp_fv1) + arg0->unk_B4.z;

            temp_fv1 = 1.0f / sqrtf(SQ(arg0->unk_B4.x) + SQ(arg0->unk_B4.y) + SQ(arg0->unk_B4.z));
            arg0->unk_B4.x *= temp_fv1;
            arg0->unk_B4.y *= temp_fv1;
            arg0->unk_B4.z *= temp_fv1;
        }
    }
    arg0->unk_168.x = arg0->unk_0C.unk_34.x - (arg0->unk_A0 * arg0->unk_24C.y.x);
    arg0->unk_168.y = arg0->unk_0C.unk_34.y - (arg0->unk_A0 * arg0->unk_24C.y.y);
    arg0->unk_168.z = arg0->unk_0C.unk_34.z - (arg0->unk_A0 * arg0->unk_24C.y.z);
}

void func_80721CA8(Racer* arg0) {

    if (!(arg0->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
        func_8071ED54(arg0, 120);
    }
    arg0->stateFlags = (arg0->stateFlags & ~RACER_STATE_FLAGS_400000) | RACER_STATE_FLAGS_80000;

    if ((arg0->id < gNumPlayers) && (D_807A16E0 != 0)) {
        if (sCharacterVoices[arg0->character] != VOICE_FEMALE) {
            func_80741014(arg0->id, 52);
        } else {
            func_80741014(arg0->id, 53);
        }
        func_8071A17C(arg0);
    }
}

extern u32 gGameFrameCount;

#ifdef NON_MATCHING
void func_80721D78(Racer* racer, Controller* controller) {
    bool var_v1;
    s32 i;
    s32 sp13C;
    s32 sp138;
    s32 sp134;
    f32 var_fa1; // sp130
    f32 sp12C;
    f32 sp128;
    f32 var_fv1;
    f32 var_fs1;
    f32 var_fs0;
    f32 var_ft4; // sp118
    Vec3f sp10C;
    Mtx3F spE8;
    f32 spE4;
    CourseSegment* temp_v1;
    unk_802D3E38* temp_a0;
    unk_802D3E38* var_v0;
    unk_802D3978* var_v0_2;
    unk_802D3978* temp2;
    unk_802D3D38* var_v0_3;
    unk_802D3D38* temp;
    u16 buttonReleased; // spC6
    u16 buttonCurrent;
    u16 buttonPressed;
    f32 temp_fa0;
    s32 pad;

    if (!(racer->stateFlags & RACER_STATE_FLAGS_400000)) {
        buttonReleased = 0;
        buttonPressed = 0;
        buttonCurrent = 0;
        racer->unk_E4 = 0.0f;
        sp12C = racer->unk_238;
        racer->unk_238 *= 0.99f;
    } else {
        buttonCurrent = controller->buttonCurrent;
        buttonPressed = controller->buttonPressed;
        buttonReleased = controller->buttonReleased;
        racer->unk_E4 = controller->stickY / 63.0f;

        if (racer->unk_E4 < -1.0f) {
            racer->unk_E4 = -1.0f;
        } else if (racer->unk_E4 > 1.0f) {
            racer->unk_E4 = 1.0f;
        }
        sp12C = controller->stickX / 63.0f;

        if (sp12C < -1.0f) {
            sp12C = -1.0f;
        } else if (sp12C > 1.0f) {
            sp12C = 1.0f;
        }
    }

    spE8 = racer->unk_C0;

    sp10C.x = racer->unk_0C.unk_34.x + racer->velocity.x;
    sp10C.y = racer->unk_0C.unk_34.y + racer->velocity.y;
    sp10C.z = racer->unk_0C.unk_34.z + racer->velocity.z;
    temp_v1 = racer->unk_0C.courseSegment;

    racer->stateFlags &= ~COURSE_EFFECT_MASK;
    var_v0 = temp_v1->unk_54;
    if ((var_v0 != NULL) && !(racer->stateFlags & RACER_STATE_AIRBORNE)) {
        temp_a0 = temp_v1->unk_58;
        if (temp_v1->trackSegmentInfo & TRACK_FLAG_8000000) {
            var_fa1 = (racer->unk_0C.unk_28.x * racer->unk_24C.z.x) + (racer->unk_0C.unk_28.y * racer->unk_24C.z.y) +
                      (racer->unk_0C.unk_28.z * racer->unk_24C.z.z) + (0.5f * (racer->unk_274 - racer->unk_270));

            do {
                if (var_fa1 < var_v0->unk_0C.x) {
                    continue;
                }
                if (var_v0->unk_18.x < var_fa1) {
                    continue;
                }
                if (racer->unk_0C.unk_04 < var_v0->unk_04) {
                    continue;
                }
                if (var_v0->unk_08 < racer->unk_0C.unk_04) {
                    continue;
                }
                racer->stateFlags |= var_v0->effectType;
                break;
            } while (++var_v0 != temp_a0);

        } else {

            do {
                if (racer->unk_0C.unk_04 < var_v0->unk_04) {
                    continue;
                }

                if (var_v0->unk_08 < racer->unk_0C.unk_04) {
                    continue;
                }

                if ((((racer->unk_0C.unk_28.y * var_v0->unk_0C.z) - (racer->unk_0C.unk_28.z * var_v0->unk_0C.y)) *
                     racer->unk_24C.x.x) +
                        (((racer->unk_0C.unk_28.z * var_v0->unk_0C.x) - (racer->unk_0C.unk_28.x * var_v0->unk_0C.z)) *
                         racer->unk_24C.x.y) +
                        (((racer->unk_0C.unk_28.x * var_v0->unk_0C.y) - (racer->unk_0C.unk_28.y * var_v0->unk_0C.x)) *
                         racer->unk_24C.x.z) <
                    0.0f) {
                    continue;
                }

                if ((((var_v0->unk_18.y * racer->unk_0C.unk_28.z) - (var_v0->unk_18.z * racer->unk_0C.unk_28.y)) *
                     racer->unk_24C.x.x) +
                        (((var_v0->unk_18.z * racer->unk_0C.unk_28.x) - (var_v0->unk_18.x * racer->unk_0C.unk_28.z)) *
                         racer->unk_24C.x.y) +
                        (((var_v0->unk_18.x * racer->unk_0C.unk_28.y) - (var_v0->unk_18.y * racer->unk_0C.unk_28.x)) *
                         racer->unk_24C.x.z) <
                    0.0f) {
                    continue;
                }

                racer->stateFlags |= var_v0->effectType;
                break;

            } while (++var_v0 != temp_a0);
        }
    }
    if ((sp12C > 0.1f) || (sp12C < -0.1f)) {
        var_fs1 = racer->unk_C0.x.x;
        var_fs0 = racer->unk_C0.x.y;
        var_ft4 = racer->unk_C0.x.z;

        if (racer->spinOutTimer != 0) {
            var_fa1 = 0.2f;
        } else {
            if (buttonCurrent & (BTN_Z | BTN_R)) {
                if (racer->unk_1D8 != 0.f) {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.4f) + racer->unk_1E4;
                } else {
                    var_fa1 = racer->unk_1E0;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (buttonCurrent & BTN_A) {
                    var_fa1 = racer->unk_1E4;
                } else {
                    var_fa1 = ((racer->unk_1E0 - racer->unk_1E4) * 0.125f) + racer->unk_1E4;
                }
            } else {
                var_fa1 = racer->unk_1E0;
            }
        }
        var_fa1 *= sp12C;

        racer->unk_C0.x.x -= (var_fa1 * racer->unk_C0.z.x);
        racer->unk_C0.x.y -= (var_fa1 * racer->unk_C0.z.y);
        racer->unk_C0.x.z -= (var_fa1 * racer->unk_C0.z.z);

        racer->unk_C0.z.x = (racer->unk_C0.y.y * racer->unk_C0.x.z) - (racer->unk_C0.y.z * racer->unk_C0.x.y);

        racer->unk_C0.z.y = (racer->unk_C0.y.z * racer->unk_C0.x.x) - (racer->unk_C0.y.x * racer->unk_C0.x.z);

        racer->unk_C0.z.z = (racer->unk_C0.y.x * racer->unk_C0.x.y) - (racer->unk_C0.y.y * racer->unk_C0.x.x);

        temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_C0.z.x) + SQ(racer->unk_C0.z.y) + SQ(racer->unk_C0.z.z));
        racer->unk_C0.z.x *= temp_fa0;
        racer->unk_C0.z.y *= temp_fa0;
        racer->unk_C0.z.z *= temp_fa0;

        var_fs1 -= racer->unk_C0.x.x =
            (racer->unk_C0.z.y * racer->unk_C0.y.z) - (racer->unk_C0.z.z * racer->unk_C0.y.y);
        var_fs0 -= racer->unk_C0.x.y =
            (racer->unk_C0.z.z * racer->unk_C0.y.x) - (racer->unk_C0.z.x * racer->unk_C0.y.z);
        var_ft4 -= racer->unk_C0.x.z =
            (racer->unk_C0.z.x * racer->unk_C0.y.y) - (racer->unk_C0.z.y * racer->unk_C0.y.x);
        spE4 = sqrtf(SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4));
    } else {
        spE4 = 0.0f;
    }
    if (racer->spinOutTimer != 0) {
        var_fs1 = var_ft4 = 0.997f;
    } else if (racer->stateFlags & RACER_STATE_CRASHED) {
        var_fs1 = var_ft4 = 0.98305196f;
    } else {
        var_ft4 = 0.997f;
        var_fs1 = 0.996f;
    }
    if ((racer->boostTimer == 0) &&
        ((racer->stateFlags & (RACER_STATE_AIRBORNE | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DIRT)) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x400)) {
                racer->unk_08 |= 0x400;
                if (D_807A16E0 != 0) {
                    func_80740BF8(racer->id, 5);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x400) {
            racer->unk_08 &= ~0x400;
            if (D_807A16E0 != 0) {
                func_80740CE8(racer->id, 5);
            }
        }
    }

    if (buttonCurrent & BTN_CDOWN) {
        var_fs1 *= 0.987f;
        var_ft4 *= 0.987f;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            var_fs1 *= 0.9f;
            var_ft4 *= 0.9f;
        }
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x80)) {
                racer->unk_08 |= 0x80;
                if (D_807A16E0 != 0) {
                    func_80740BF8(racer->id, 9);
                }
            }
        }
    } else if (racer->id < gNumPlayers) {
        if (racer->unk_08 & 0x80) {
            racer->unk_08 &= ~0x80;
            if (D_807A16E0 != 0) {
                func_80740CE8(racer->id, 9);
            }
        }
    }

    var_fs1 *= ((racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                (racer->unk_C0.z.z * racer->velocity.z));
    var_fs0 = ((racer->unk_C0.y.x * racer->velocity.x) + (racer->unk_C0.y.y * racer->velocity.y) +
               (racer->unk_C0.y.z * racer->velocity.z)) *
              0.94f;
    var_ft4 *= ((racer->unk_C0.x.x * racer->velocity.x) + (racer->unk_C0.x.y * racer->velocity.y) +
                (racer->unk_C0.x.z * racer->velocity.z));
    racer->velocity.x = (racer->unk_C0.z.x * var_fs1) + (racer->unk_C0.y.x * var_fs0) + (racer->unk_C0.x.x * var_ft4);
    racer->velocity.y = (racer->unk_C0.z.y * var_fs1) + (racer->unk_C0.y.y * var_fs0) + (racer->unk_C0.x.y * var_ft4);
    racer->velocity.z = (racer->unk_C0.z.z * var_fs1) + (racer->unk_C0.y.z * var_fs0) + (racer->unk_C0.x.z * var_ft4);

    if ((buttonPressed & BTN_B) && (racer->boostTimer == 0) && (racer->energy != 0.0) &&
        (racer->stateFlags & RACER_STATE_FLAGS_100000)) {
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = racer->shadowBaseB = 91.0f;
        racer->shadowBaseG = 255.0f;
        racer->boostTimer = sInitialBoostTimer;
        racer->unk_08 |= 0x1000;
        if (D_807A16E0 != 0) {
            func_80741014(racer->id, 7);
        }
    } else {
        if ((racer->stateFlags & (RACER_STATE_CRASHED | COURSE_EFFECT_MASK)) == COURSE_EFFECT_DASH &&
            racer->stateFlags & RACER_STATE_FLAGS_400000) {
            buttonCurrent |= BTN_A;
            racer->shadowColorStrength = 1.3f;
            racer->shadowBaseR = 255.0f;
            racer->shadowBaseG = 223.0f;
            racer->shadowBaseB = 0.0f;
            racer->stateFlags |= RACER_STATE_DASH_PAD_BOOST;
            racer->boostTimer = sInitialBoostTimer;
            if (!(racer->unk_08 & 0x1000)) {
                racer->unk_08 |= 0x1000;
                if (D_807A16E0 != 0) {
                    func_80741014(racer->id, 7);
                }
            }
        } else {
            racer->unk_08 &= ~0x1000;
        }
    }

    if (!(racer->stateFlags & RACER_STATE_FLAGS_10000)) {
        temp_v1 = racer->unk_0C.courseSegment;
        var_v0_2 = temp_v1->unk_4C;
        if (var_v0_2 != NULL) {
            temp2 = temp_v1->unk_50;
            do {
                var_fs1 = var_v0_2->unk_04.x - racer->unk_0C.unk_34.x;
                var_fs0 = var_v0_2->unk_04.y - racer->unk_0C.unk_34.y;
                var_ft4 = var_v0_2->unk_04.z - racer->unk_0C.unk_34.z;
                if ((SQ(var_fs1) + SQ(var_fs0) + SQ(var_ft4)) < 900.0f) {
                    racer->acceleration.x += (15.0f * racer->unk_B4.x);
                    racer->acceleration.y += (15.0f * racer->unk_B4.y);
                    racer->acceleration.z += (15.0f * racer->unk_B4.z);
                    racer->stateFlags |= RACER_STATE_FLAGS_10000;
                    func_8071EE74(racer, 12.5f);
                    if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 1);
                    }
                    break;
                }
            } while (++var_v0_2 != temp2);
        }
    }

    if (!(racer->stateFlags & RACER_STATE_FLAGS_200000)) {
        temp_v1 = racer->unk_0C.courseSegment;
        var_v0_3 = temp_v1->unk_44;
        if (var_v0_3 != NULL) {
            temp = temp_v1->unk_48;
            do {
                var_fs1 = racer->unk_0C.unk_34.x - var_v0_3->unk_00.x;
                var_fs0 = racer->unk_0C.unk_34.y - var_v0_3->unk_00.y;
                var_ft4 = racer->unk_0C.unk_34.z - var_v0_3->unk_00.z;
                var_fa1 = (var_v0_3->unk_0C.x.x * var_fs1) + (var_v0_3->unk_0C.x.y * var_fs0) +
                          (var_v0_3->unk_0C.x.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.z < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.z.x * var_fs1) + (var_v0_3->unk_0C.z.y * var_fs0) +
                          (var_v0_3->unk_0C.z.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.x < var_fa1) {
                    continue;
                }

                var_fa1 = (var_v0_3->unk_0C.y.x * var_fs1) + (var_v0_3->unk_0C.y.y * var_fs0) +
                          (var_v0_3->unk_0C.y.z * var_ft4);

                if (var_fa1 < 0.0f) {
                    continue;
                }

                if (var_v0_3->unk_30.y < var_fa1) {
                    continue;
                }

                racer->stateFlags |= RACER_STATE_FLAGS_200000;
                racer->unk_1DC = (racer->speed * 0.3f) + 0.5f;
                if ((racer->id < gNumPlayers) && (D_807A16E0 != 0)) {
                    func_80741014(racer->id, 0x37);
                }
                break;

            } while (++var_v0_3 != temp);
        }
    }
    racer->acceleration.x += (-1.0f * racer->unk_A8.x);
    racer->acceleration.y += (-1.0f * racer->unk_A8.y);
    racer->acceleration.z += (-1.0f * racer->unk_A8.z);
    if (racer->stateFlags & RACER_STATE_FLAGS_200000) {
        racer->acceleration.x += (racer->unk_1DC * racer->unk_B4.x);
        racer->acceleration.y += (racer->unk_1DC * racer->unk_B4.y);
        racer->acceleration.z += (racer->unk_1DC * racer->unk_B4.z);
        racer->unk_1DC *= 0.8f;
    }
    if (!(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        var_fa1 = racer->unk_17C - racer->unk_A0;
        if (var_fa1 > 0.0f) {
            var_fa1 -= ((racer->velocity.x * racer->unk_19C.x) + (racer->velocity.y * racer->unk_19C.y) +
                        (racer->velocity.z * racer->unk_19C.z));

            racer->unk_198 = var_fa1 * 0.2f;

            racer->acceleration.x += (racer->unk_198 * racer->unk_19C.x);
            racer->acceleration.y += (racer->unk_198 * racer->unk_19C.y);
            racer->acceleration.z += (racer->unk_198 * racer->unk_19C.z);
            if (racer->unk_1DC < 0.5f) {
                racer->stateFlags &= ~(RACER_STATE_FLAGS_200000 | RACER_STATE_FLAGS_10000);
            }
        } else {
            racer->unk_198 = 0.0f;
        }
    } else {
        racer->unk_198 = 0.0f;
    }
    racer->unk_278++;
    racer->unk_27A++;
    if (buttonPressed & BTN_R_Z_COMBO) {
        buttonPressed |= BTN_Z;
        buttonCurrent |= BTN_R;
        racer->unk_278 = 10;
    } else if (buttonPressed & BTN_Z_R_COMBO) {
        buttonPressed |= BTN_R;
        buttonCurrent |= BTN_Z;
        racer->unk_27A = 10;
    }

    switch (buttonPressed & (BTN_Z | BTN_R)) {
        case BTN_Z:
            if ((racer->unk_278 < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0x80;
                racer->unk_280 = 0x100;
                if (buttonCurrent & BTN_R) {
                    racer->unk_284 = 2;
                    if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 6);
                    }
                }
            }
            racer->unk_278 = 0;
            break;
        case BTN_R:
            if ((racer->unk_27A < 0xF) && (racer->unk_27C == 0)) {
                racer->unk_27C = 0xF80;
                racer->unk_280 = -0x100;
                if (buttonCurrent & BTN_Z) {
                    racer->unk_284 = 2;
                    if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 2);
                    }
                } else {
                    racer->unk_284 = 1;
                    if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 6);
                    }
                }
            }
            racer->unk_27A = 0;
            break;
        default:
            break;
    }

    var_v1 = false;
    if (racer->unk_284 == 1) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 5.0f;
        } else if (var_fa1 < 6.0f) {
            racer->unk_1D8 = 5.0f - (0.8333333f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
        var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
        var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
        var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->unk_A8.z));
        } else {
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
        }
    } else if (racer->unk_284 == 2) {
        if (racer->unk_280 < 0) {
            racer->unk_286 = 1;
            var_fa1 = -racer->unk_5C.x;
        } else {
            var_fa1 = racer->unk_5C.x;
            racer->unk_286 = 0;
        }
        if (var_fa1 < 0.0f) {
            racer->unk_1D8 = 0.5f;
        } else if (var_fa1 < 2.0f) {
            racer->unk_1D8 = 0.5f - (0.25f * var_fa1);
        } else {
            racer->unk_1D8 = 0.0f;
        }

        var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
        var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
        var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
        if (racer->unk_286 == 1) {
            racer->acceleration.x -= var_fs1;
            racer->acceleration.y -= var_fs0;
            racer->acceleration.z -= var_ft4;
        } else {
            racer->acceleration.x += var_fs1;
            racer->acceleration.y += var_fs0;
            racer->acceleration.z += var_ft4;
        }
    } else {
        switch (buttonCurrent & (BTN_Z | BTN_R)) {
            case 0:
            case (BTN_Z | BTN_R):
                racer->unk_1D8 = 0.0f;
                break;
            default:
                if ((buttonCurrent & (BTN_Z | BTN_R)) == BTN_Z) {
                    var_fa1 = racer->unk_5C.x;
                    racer->unk_286 = 0;
                } else {
                    racer->unk_286 = 1;
                    var_fa1 = -racer->unk_5C.x;
                }
                if (var_fa1 < 0.0f) {
                    racer->unk_1D8 = 1.0f;
                } else if (var_fa1 < 8.0f) {
                    racer->unk_1D8 = 1.0f - (0.125f * var_fa1);
                } else {
                    racer->unk_1D8 = 0.0f;
                }
                if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
                    racer->unk_1D8 *= 0.2f;
                }

                var_fs1 = racer->unk_1D8 * racer->unk_C0.z.x;
                var_fs0 = racer->unk_1D8 * racer->unk_C0.z.y;
                var_ft4 = racer->unk_1D8 * racer->unk_C0.z.z;
                var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
                if (racer->unk_286 == 1) {
                    racer->acceleration.x -= (var_fs1 - (var_fa1 * racer->unk_A8.x));
                    racer->acceleration.y -= (var_fs0 - (var_fa1 * racer->unk_A8.y));
                    racer->acceleration.z -= (var_ft4 - (var_fa1 * racer->unk_A8.z));
                } else {
                    racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
                    racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
                    racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
                }

                var_v1 = true;
                break;
        }
    }
    if (racer->id < gNumPlayers) {
        if (var_v1) {
            if (!(racer->unk_08 & 0x40)) {
                racer->unk_08 |= 0x40;
                if (D_807A16E0 != 0) {
                    func_80740BF8(racer->id, 0xA);
                }
            }
        } else {
            if (racer->unk_08 & 0x40) {
                racer->unk_08 &= ~0x40;
                if (D_807A16E0 != 0) {
                    func_80740CE8(racer->id, 0xA);
                }
            }
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT)) &&
        ((racer->stateFlags & COURSE_EFFECT_MASK) != COURSE_EFFECT_ICE)) {
        sp128 = (racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                (racer->unk_C0.z.z * racer->velocity.z);

        if (sp128 < 0.0f) {
            var_fa1 = -1.0f;
            sp128 = -sp128;
        } else {
            var_fa1 = 1.0f;
        }
        if (buttonPressed & BTN_A) {
            racer->unk_204 = 0x1E;
            racer->unk_214 = 0x1B;
            if ((racer->id < gNumPlayers) && (D_807A16E0 != 0)) {
                func_80741014(racer->id, 0x29);
            }
        } else {
            if (racer->unk_214 != 0) {
                racer->unk_214--;
            }
        }
        if ((racer->stateFlags & (RACER_STATE_AIRBORNE | RACER_STATE_FLAGS_20000)) || (racer->unk_208 != 0) ||
            (buttonCurrent & (BTN_Z | BTN_R))) {

            if (racer->unk_208 != 0) {
                racer->unk_208--;
            }

            if (racer->unk_204 != 0) {
                racer->unk_204--;
            }
            racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;

            if (racer->unk_1FC < sp128) {
                sp128 = racer->unk_1FC;
            }
        } else {
            if ((racer->unk_204 != 0) || !(buttonCurrent & BTN_A)) {
                if (racer->unk_204 != 0) {
                    racer->unk_204--;
                }
                racer->stateFlags |= RACER_STATE_FLAGS_20000000;

                if (racer->unk_1F8 < sp128) {
                    sp128 = racer->unk_1F8;
                }
            } else if (racer->stateFlags & RACER_STATE_FLAGS_20000000) {
                if (racer->unk_1F8 < sp128) {
                    racer->stateFlags &= ~RACER_STATE_FLAGS_20000000;
                    sp128 = racer->unk_1FC;
                }
            } else {
                if (racer->unk_1FC < sp128) {
                    sp128 = racer->unk_1FC;
                } else {
                    racer->stateFlags |= RACER_STATE_FLAGS_20000000;
                }
            }
        }

        sp128 *= var_fa1;
        racer->velocity.x -= sp128 * racer->unk_C0.z.x;
        racer->velocity.y -= sp128 * racer->unk_C0.z.y;
        racer->velocity.z -= sp128 * racer->unk_C0.z.z;
        if (((racer->unk_5C.x < -8.0f) || (racer->unk_5C.x > 8.0f)) && !(racer->stateFlags & RACER_STATE_AIRBORNE)) {

            racer->unk_20C++;
            var_fa1 = racer->unk_20C / 100.0f;
            if (var_fa1 >= 1.0f) {
                racer->unk_200 = racer->unk_1C8;
            } else if (racer->unk_200 < var_fa1) {
                racer->unk_200 = racer->unk_1C8 * var_fa1;
            }
            if (racer->id < gNumPlayers) {
                if (!(racer->unk_08 & 0x200)) {
                    racer->unk_08 |= 0x200;
                    if (D_807A16E0 != 0) {
                        func_80740BF8(racer->id, 6);
                    }
                }
            }
        } else {
            racer->unk_20C = 0;
            if (racer->id < gNumPlayers) {
                if (racer->unk_08 & 0x200) {
                    racer->unk_08 &= ~0x200;
                    if (D_807A16E0 != 0) {
                        func_80740CE8(racer->id, 6);
                    }
                }
            }
        }
    } else {
        racer->unk_20C = 0;
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x200) {
                racer->unk_08 &= ~0x200;
                if (D_807A16E0 != 0) {
                    func_80740CE8(racer->id, 6);
                }
            }
        }
    }

    if (racer->unk_200 != 0.0f) {
        var_fs1 = racer->unk_1B4;
        var_fs0 = racer->unk_1B8;
        var_ft4 = (racer->unk_31C * racer->unk_200) + 1.0f;
        racer->unk_200 -= racer->unk_1CC;
        if (racer->unk_200 < 0.0f) {
            racer->unk_200 = 0.0f;
        }
    } else {
        var_fs1 = racer->unk_1B0;
        var_fs0 = racer->unk_1B8;
        var_ft4 = 1.0f;
    }
    if ((gNumPlayers >= 2) && (gSettingVsHandicap == 2)) {
        var_fv1 = (gRacersByPosition[0]->raceDistance - racer->raceDistance);
        var_fv1 /= D_8076E2F8;
        if (var_fv1 >= 1.0f) {
            var_fs1 += 0.03f;
            var_fs0 += 0.03f;
        } else {
            var_fs1 += 0.03f * var_fv1;
            var_fs0 += 0.03f * var_fv1;
        }
    }
    if (racer->boostTimer != 0) {
        if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
            if (var_ft4 < racer->unk_1C4) {
                var_ft4 = racer->unk_1C4;
            }
        } else {
            if (var_ft4 < racer->unk_1C0) {
                var_ft4 = racer->unk_1C0;
            }
            if (gGameMode != GAMEMODE_COURSE_EDIT) {
                if ((gNumPlayers == 1) || (gSettingVsHandicap == 0)) {
                    sp128 = racer->boostEnergyUsage;
                } else {
                    sp128 = (gRacersByPosition[0]->raceDistance - racer->raceDistance);
                    sp128 /= D_8076E2F8;
                    if (sp128 >= 1.0f) {
                        sp128 = racer->boostEnergyUsage * 0.1f;
                    } else {
                        sp128 = (((1.0f - sp128) * 0.9f) + 0.1f) * racer->boostEnergyUsage;
                    }
                }
                racer->energy -= sp128;
                if (racer->energy < 0.0f) {
                    racer->boostTimer = 1;
                    racer->energy = 0.0f;
                }
            }
        }
        racer->boostTimer--;
        if (racer->boostTimer == 0) {
            racer->stateFlags &= ~RACER_STATE_DASH_PAD_BOOST;
            racer->unk_08 &= ~0x1000;
        }
    }
    var_fs1 *= var_ft4;
    var_fs0 *= var_ft4;

    if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_ICE) {
        if (racer->id < gNumPlayers) {
            if (!(racer->unk_08 & 0x20)) {
                racer->unk_08 |= 0x20;
                if (D_807A16E0 != 0) {
                    func_80740BF8(racer->id, 0xB);
                }
            }
        }
        var_ft4 = racer->speed;
    } else {
        if (racer->id < gNumPlayers) {
            if (racer->unk_08 & 0x20) {
                racer->unk_08 &= ~0x20;
                if (D_807A16E0 != 0) {
                    func_80740CE8(racer->id, 0xB);
                }
            }
        }
        var_ft4 = racer->unk_5C.z;
    }
    if (((buttonCurrent | buttonReleased) & BTN_A) && (racer->speed < racer->unk_1EC)) {
        if (var_ft4 <= 0.0f) {
            var_ft4 = 0.0f;
            var_fv1 = var_fs1;
        } else {
            var_fv1 = racer->unk_1BC;
            if (var_ft4 < var_fv1) {
                var_fa1 = var_ft4 / var_fv1;

                sp128 = 1.0f - SQ((2.0f * var_fa1) - 1.0f);
                if (var_fs1 < var_fs0) {
                    sp128 *= (var_fs0 - var_fs1) * racer->unk_320;
                } else {
                    sp128 *= (var_fs1 - var_fs0) * racer->unk_320;
                }
                var_fv1 = ((var_fs0 - var_fs1) * var_fa1) + var_fs1 + sp128;
            } else {
                if (racer->unk_1E8 == 0.0f) {
                    var_fv1 = var_fs0;
                } else {
                    var_fv1 = ((D_8076EF98[4] - var_fs0) * racer->unk_1E8) + var_fs0;
                }
            }
        }
        var_fv1 -= ((spE4 * 0.5f) + (racer->unk_1D8 * 0.16f));
        if (var_fv1 < 0.0f) {
            racer->unk_1D4 = 0.0f;
        } else {
            if (var_fv1 <= racer->unk_1D4) {
                racer->unk_1D4 = var_fv1;
            } else {
                var_ft4 *= racer->unk_324;
                if (var_ft4 < 1.0f) {
                    var_ft4 = (racer->unk_328 * var_ft4) + racer->unk_1D0;
                } else {
                    var_ft4 = 1.0f;
                }
                racer->unk_1D4 += ((var_fv1 - racer->unk_1D4) * var_ft4);
            }

            var_fs1 = racer->unk_1D4 * racer->unk_C0.x.x;
            var_fs0 = racer->unk_1D4 * racer->unk_C0.x.y;
            var_ft4 = racer->unk_1D4 * racer->unk_C0.x.z;
            var_fa1 = (racer->unk_A8.x * var_fs1) + (var_fs0 * racer->unk_A8.y) + (var_ft4 * racer->unk_A8.z);
            racer->acceleration.x += (var_fs1 - (var_fa1 * racer->unk_A8.x));
            racer->acceleration.y += (var_fs0 - (var_fa1 * racer->unk_A8.y));
            racer->acceleration.z += (var_ft4 - (var_fa1 * racer->unk_A8.z));
        }
    } else {
        racer->unk_1D4 = 0.0f;
    }
    racer->velocity.x += racer->acceleration.x;
    racer->velocity.y += racer->acceleration.y;
    racer->velocity.z += racer->acceleration.z;
    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));
    if (racer->stateFlags & RACER_STATE_FLAGS_80000) {
        racer->velocity.x *= 0.94f;
        racer->velocity.z *= 0.94f;
        racer->unk_0C.unk_34.x += racer->velocity.x;
        racer->unk_0C.unk_34.y += racer->velocity.y;
        racer->unk_0C.unk_34.z += racer->velocity.z;
        racer->unk_0C.unk_28.x += racer->velocity.x;
        racer->unk_0C.unk_28.y += racer->velocity.y;
        racer->unk_0C.unk_28.z += racer->velocity.z;
        racer->unk_0C.unk_40 =
            sqrtf(SQ(racer->unk_0C.unk_28.x) + SQ(racer->unk_0C.unk_28.y) + SQ(racer->unk_0C.unk_28.z));
        D_8076F2DC[TRACK_SHAPE_INDEX(TRACK_SHAPE_AIR)](racer);
        if (racer->unk_0C.unk_34.y < -2750.0f) {
            racer->stateFlags &= ~RACER_STATE_FLAGS_40000000;
            if (gGameMode != GAMEMODE_COURSE_EDIT) {
                racer->stateFlags |= RACER_STATE_CRASHED;
            }
            D_807A16D0++;
            func_80719F9C(racer);

            if (racer->id < gNumPlayers) {
                func_8071A17C(racer);
            }
            if ((racer->id < gNumPlayers) || (gRacers[0].stateFlags & RACER_STATE_FLAGS_80000)) {
                func_i2_800AC750(racer->unk_0C.unk_34.x, racer->unk_0C.unk_34.y, racer->unk_0C.unk_34.z, 0.0f, 0.0f,
                                 0.0f, 600.0f, racer);
                if (D_807A16E0 != 0) {
                    func_80741014(racer->id, 8);
                    if ((racer->id == 0) && (gNumPlayers == 1)) {
                        func_80741EC4();
                    }
                }
                racer->unk_C0.x.y = 0.0f;
                racer->unk_C0.y.x = 0.0f;
                racer->unk_C0.z.z = 0.0f;
                racer->unk_C0.x.x = 0.0f;
                racer->unk_C0.y.z = 0.0f;
                racer->unk_C0.z.y = 0.0f;
                racer->unk_C0.x.z = 1.0f;
                racer->unk_C0.y.y = 1.0f;
                racer->unk_C0.z.x = 1.0f;
                func_i2_800ACB74(14.0f, racer);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 0x2710;
                controller->unk_8C = 0x1F4;
                controller->unk_90 = 5;
            }
        }
    } else {
        if (racer->speed > 138.9f) {
            var_fa1 = 138.9f / racer->speed;
            racer->speed = 138.9f;
            racer->velocity.x *= var_fa1;
            racer->velocity.y *= var_fa1;
            racer->velocity.z *= var_fa1;
        }
        if (racer->id < gNumPlayers) {
            var_fa1 = 1.0f;
            i = 100;
        } else {
            var_fa1 = 5.0f;
            i = 3;
        }

        if (func_i2_800B2C00(&racer->unk_0C, racer->unk_0C.unk_34.x + racer->velocity.x,
                             racer->unk_0C.unk_34.y + racer->velocity.y, racer->unk_0C.unk_34.z + racer->velocity.z, i,
                             var_fa1) == 0) {
            sp128 = racer->lapDistance;
            racer->lapDistance = func_i2_800B1F68(&racer->unk_0C);
            temp_v1 = racer->unk_0C.courseSegment;

            racer->unk_270 =
                (racer->unk_0C.unk_08 * (temp_v1->next->radiusLeft - temp_v1->radiusLeft)) + temp_v1->radiusLeft;
            racer->unk_274 =
                (racer->unk_0C.unk_08 * (temp_v1->next->radiusRight - temp_v1->radiusRight)) + temp_v1->radiusRight;

            var_fa1 = 1.0f / racer->unk_0C.unk_18;
            racer->unk_24C.x.x = racer->unk_0C.unk_0C.x * var_fa1;
            racer->unk_24C.x.y = racer->unk_0C.unk_0C.y * var_fa1;
            racer->unk_24C.x.z = racer->unk_0C.unk_0C.z * var_fa1;

            racer->unk_24C.y.x =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.x - temp_v1->unk_0C.x)) + temp_v1->unk_0C.x;
            racer->unk_24C.y.y =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.y - temp_v1->unk_0C.y)) + temp_v1->unk_0C.y;
            racer->unk_24C.y.z =
                (racer->unk_0C.unk_08 * (temp_v1->next->unk_0C.z - temp_v1->unk_0C.z)) + temp_v1->unk_0C.z;

            if ((racer->unk_24C.y.x == 0.0f) && (racer->unk_24C.y.y == 0.0f) && (racer->unk_24C.y.z == 0.0f)) {
                func_i2_800B0FAC(temp_v1, &racer->unk_24C);
            } else {
                racer->unk_24C.z.x =
                    (racer->unk_24C.y.y * racer->unk_24C.x.z) - (racer->unk_24C.y.z * racer->unk_24C.x.y);
                racer->unk_24C.z.y =
                    (racer->unk_24C.y.z * racer->unk_24C.x.x) - (racer->unk_24C.y.x * racer->unk_24C.x.z);
                racer->unk_24C.z.z =
                    (racer->unk_24C.y.x * racer->unk_24C.x.y) - (racer->unk_24C.y.y * racer->unk_24C.x.x);
                if ((racer->unk_24C.z.x == 0.0f) && (racer->unk_24C.z.y == 0.0f) && (racer->unk_24C.z.z == 0.0f)) {
                    func_i2_800B0FAC(racer->unk_0C.courseSegment, &racer->unk_24C);
                } else {
                    temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_24C.z.x) + SQ(racer->unk_24C.z.y) + SQ(racer->unk_24C.z.z));

                    racer->unk_24C.z.x *= temp_fa0;
                    racer->unk_24C.z.y *= temp_fa0;
                    racer->unk_24C.z.z *= temp_fa0;

                    racer->unk_24C.y.x =
                        (racer->unk_24C.x.y * racer->unk_24C.z.z) - (racer->unk_24C.x.z * racer->unk_24C.z.y);
                    racer->unk_24C.y.y =
                        (racer->unk_24C.x.z * racer->unk_24C.z.x) - (racer->unk_24C.x.x * racer->unk_24C.z.z);
                    racer->unk_24C.y.z =
                        (racer->unk_24C.x.x * racer->unk_24C.z.y) - (racer->unk_24C.x.y * racer->unk_24C.z.x);
                }
            }
            if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_80000)) &&
                (gRaceIntroTimer < 40) && (gGameMode != GAMEMODE_RECORDS)) {

                sp128 -= racer->lapDistance;
                racer->unk_288++;
                racer->unk_2A4++;
                racer->raceTime = (s32) (racer->unk_2A4 * 50) / 3;
                if (D_807B37CC < sp128) {
                    racer->lapsCompletedDistance += gCurrentCourseInfo->length;
                    racer->lap++;
                    if ((racer->lap == racer->lapsCompleted + 1) && ((gTotalLapCount + 1) >= racer->lap)) {
                        racer->lapsCompleted = racer->lap;
                        racer->stateFlags |= RACER_STATE_FLAGS_100000;
                        i = racer->raceTime -
                            (s32) ((50.0f * racer->lapDistance) / (3.0f * (gCurrentCourseInfo->length - sp128)));
                        racer->lapTimes[racer->lap - 2] = (s32) (i - racer->completedLapsTime);
                        racer->completedLapsTime = i;
                        racer->startNewPracticeLap = true;
                        if ((gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE) ||
                            (gGameMode == GAMEMODE_COURSE_EDIT)) {
                            if (racer == gRacers) {
                                if (racer->lapTimes[racer->lap - 2] < gPracticeBestLap) {
                                    gPracticeBestLap = racer->lapTimes[racer->lap - 2];
                                    gStartNewBestLap = true;
                                }
                            }
                            if ((gTotalLapCount + 1) == racer->lap) {
                                racer->lap = racer->lapsCompleted = 1;
                                racer->lapsCompletedDistance = 0;
                            }
                        } else if ((gTotalLapCount + 1) == racer->lap) {
                            racer->raceTime = i;
                            racer->stateFlags |= RACER_STATE_FLAGS_2000000 | RACER_STATE_CPU_CONTROLLED;
                            racer->energy = racer->maxEnergy;

                            if (racer->id < gNumPlayers) {
                                gControllers[gPlayerControlPorts[racer->id]].unk_72 = 0;
                                gPlayerRacersFinished++;
                            }
                            gRacersFinished++;
                            D_807B14F8 = 1;

                            if (racer->id < gNumPlayers) {
                                if (D_807A16E0 != 0) {
                                    func_80741014(racer->id, 0xF);
                                    func_80740B98(racer->id);
                                }
                                func_8071A17C(racer);
                                if (gNumPlayers == 1) {
                                    func_8070DAFC();
                                } else if (gRacersFinished == 1) {
                                    func_8070DAFC();
                                }
                            }
                        }
                    }
                } else if (sp128 < D_807B37D0) {
                    racer->lap--;
                    racer->lapsCompletedDistance -= gCurrentCourseInfo->length;
                }
                racer->raceDistance = racer->raceDistancePosition = racer->lapsCompletedDistance + racer->lapDistance;
            }

            D_8076F2DC[TRACK_SHAPE_INDEX((u32) racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK)](
                racer);
            if (racer->stateFlags & RACER_STATE_FLAGS_80000000) {
                if ((racer->unk_0C.unk_34.x < -20000.0f) || (racer->unk_0C.unk_34.x > 20000.0f) ||
                    (racer->unk_0C.unk_34.z < -20000.0f) || (racer->unk_0C.unk_34.z > 20000.0f) ||
                    ((racer->velocity.y < 0.0f) && (racer->unk_0C.unk_28.y < -racer->unk_270) &&
                     (((racer->unk_0C.unk_28.x * racer->velocity.x) + (racer->unk_0C.unk_28.y * racer->velocity.y) +
                       (racer->unk_0C.unk_28.z * racer->velocity.z)) >= 0.0f))) {
                    func_80721CA8(racer);
                }
            }
        } else {
            racer->unk_0C.unk_34 = sp10C;
            func_80721CA8(racer);
        }
    }
    racer->unk_C0.y.x += 0.19f * racer->unk_B4.x;
    racer->unk_C0.y.y += 0.19f * racer->unk_B4.y;
    racer->unk_C0.y.z += 0.19f * racer->unk_B4.z;
    if (func_806F6F64(&racer->unk_C0) != 0) {
        racer->unk_C0 = spE8;
    }
    if (racer->unk_198 != 0.0f) {
        sp128 = racer->unk_A0;
    } else {
        sp128 = racer->unk_17C;
    }

    var_fa1 = racer->unk_180.x;
    var_fv1 = racer->unk_0C.unk_34.x - (sp128 * racer->unk_C0.y.x);
    racer->unk_180.x = var_fv1;
    racer->unk_18C.x = var_fv1 - var_fa1;

    var_fa1 = racer->unk_180.y;
    var_fv1 = racer->unk_0C.unk_34.y - (sp128 * racer->unk_C0.y.y);
    racer->unk_180.y = var_fv1;
    racer->unk_18C.y = var_fv1 - var_fa1;

    var_fa1 = racer->unk_180.z;
    var_fv1 = racer->unk_0C.unk_34.z - (sp128 * racer->unk_C0.y.z);
    racer->unk_180.z = var_fv1;
    racer->unk_18C.z = var_fv1 - var_fa1;

    racer->unk_80.x = racer->unk_0C.unk_34.x - sp10C.x;
    racer->unk_80.y = racer->unk_0C.unk_34.y - sp10C.y;
    racer->unk_80.z = racer->unk_0C.unk_34.z - sp10C.z;

    racer->unk_68.x = (spE8.z.x * racer->unk_80.x) + (spE8.z.y * racer->unk_80.y) + (spE8.z.z * racer->unk_80.z);
    racer->unk_68.y = (spE8.y.x * racer->unk_80.x) + (spE8.y.y * racer->unk_80.y) + (spE8.y.z * racer->unk_80.z);
    racer->unk_68.z = (spE8.x.x * racer->unk_80.x) + (spE8.x.y * racer->unk_80.y) + (spE8.x.z * racer->unk_80.z);
    racer->unk_5C.x = (racer->unk_C0.z.x * racer->velocity.x) + (racer->unk_C0.z.y * racer->velocity.y) +
                      (racer->unk_C0.z.z * racer->velocity.z);
    racer->unk_5C.y = (racer->unk_C0.y.x * racer->velocity.x) + (racer->unk_C0.y.y * racer->velocity.y) +
                      (racer->unk_C0.y.z * racer->velocity.z);
    racer->unk_5C.z = (racer->unk_C0.x.x * racer->velocity.x) + (racer->unk_C0.x.y * racer->velocity.y) +
                      (racer->unk_C0.x.z * racer->velocity.z);
    if ((racer->id < gNumPlayers) && (controller->unk_74 != 0)) {

        if (!(racer->stateFlags & (RACER_STATE_RETIRED | RACER_STATE_SPINNING_OUT))) {
            if (racer->stateFlags & RACER_STATE_FLAGS_20000) {
                if (D_807A1630[racer->id] == 0) {
                    D_807A1630[racer->id] = 1;
                    controller->unk_88 = 4000;
                    controller->unk_8C = 0;
                    controller->unk_90 = 0;
                    goto skip;
                }
            } else {
                if (D_807A1630[racer->id] != 0) {
                    D_807A1630[racer->id]--;
                }
                if (racer->boostTimer == sInitialBoostTimer - 1) {
                    controller->unk_88 = 1000;
                    controller->unk_8C = controller->unk_90 = 0;
                    goto skip;
                } else if (racer->boostTimer != 0) {
                    controller->unk_8C = (racer->boostTimer * 300) / sInitialBoostTimer;
                    goto skip;
                }
            }

            if ((racer->stateFlags & COURSE_EFFECT_MASK) == COURSE_EFFECT_DIRT) {
                if (D_807A1640[racer->id] == 0) {
                    D_807A1640[racer->id] = 150;
                    controller->unk_88 = 2000;
                    controller->unk_8C = 300;
                    controller->unk_90 = 1;
                    goto skip;
                } else if (D_807A1640[racer->id] >= 2) {
                    D_807A1640[racer->id]--;
                    goto skip;
                }
            } else {
                D_807A1640[racer->id] = 0;
            }

            var_ft4 = racer->unk_80.x;
            var_fs0 = racer->unk_80.y;
            var_fs1 = racer->unk_80.z;
            i = (s32) (sqrtf(SQ(var_ft4) + SQ(var_fs0) + SQ(var_fs1)) * D_8076E574);
            if (i > 1000) {
                i = 1000;
            }
            controller->unk_8C = i;
            controller->unk_90 = 0;
        skip:;
        }
    }

    if ((racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_AIRBORNE | RACER_STATE_SPINNING_OUT |
                              COURSE_EFFECT_MASK)) == COURSE_EFFECT_PIT) {
        racer->energy += racer->energyIncrease;
        if (racer->maxEnergy < racer->energy) {
            racer->energy = racer->maxEnergy;
        }

        if (racer->pitForceFieldSize < 1.0f) {
            racer->pitForceFieldSize += 0.1f;
            if (racer->pitForceFieldSize >= 1.0f) {
                racer->pitForceFieldSize = 1.0f;
            } else if ((racer->id < gNumPlayers) && (racer->pitForceFieldSize == 0.1f)) {
                racer->unk_08 |= 0x800;
                if (D_807A16E0 != 0) {
                    func_80740BF8(racer->id, 4);
                }
            }
        }
    } else {
        if (racer->pitForceFieldSize > 0.0f) {
            racer->pitForceFieldSize -= 0.1f;
            if (racer->pitForceFieldSize <= 0.0f) {
                racer->pitForceFieldSize = 0.0f;
                if (racer->id < gNumPlayers) {
                    racer->unk_08 &= ~0x800;
                    if (D_807A16E0 != 0) {
                        func_80740CE8(racer->id, 4);
                    }
                }
            }
        }
    }
    racer->unk_210 = (racer->unk_210 + (s32) (racer->unk_1D4 * 4000.0f)) & 0xFFF;

    var_fa1 = SIN(racer->unk_210) * (racer->speed * 0.007f);
    if (racer->unk_08 & 0x400) {
        var_fa1 *= 5.0f;
    }
    racer->unk_10C.x = racer->unk_0C.unk_34.x + (var_fa1 * racer->unk_E8.y.x);
    racer->unk_10C.y = racer->unk_0C.unk_34.y + (var_fa1 * racer->unk_E8.y.y);
    racer->unk_10C.z = racer->unk_0C.unk_34.z + (var_fa1 * racer->unk_E8.y.z);
    if (racer->spinOutTimer != 0) {
        racer->unk_10C.x += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.y += ((f32) (Math_Rand1() & 0xFFFF) * 0.000027466238f) - 0.9f;
        racer->unk_10C.z += ((f32) (Math_Rand2() & 0xFFFF) * 0.000027466238f) - 0.9f;
    }

    if (racer->unk_27C != 0) {
        if (racer->unk_284 == 1) {
            racer->unk_E8.x.x = racer->unk_C0.x.x;
            racer->unk_E8.x.y = racer->unk_C0.x.y;
            racer->unk_E8.x.z = racer->unk_C0.x.z;
        } else {
            var_fs1 = COS(racer->unk_27C);
            var_fs0 = SIN(racer->unk_27C);
            racer->unk_E8.x.x = (racer->unk_C0.x.x * var_fs1) + (var_fs0 * racer->unk_C0.z.x);
            racer->unk_E8.x.y = (racer->unk_C0.x.y * var_fs1) + (var_fs0 * racer->unk_C0.z.y);
            racer->unk_E8.x.z = (racer->unk_C0.x.z * var_fs1) + (var_fs0 * racer->unk_C0.z.z);
        }

        if (racer->unk_284 == 1) {
            racer->unk_27C += racer->unk_280;
            if ((racer->unk_27C == -0x80) || (racer->unk_27C == 0x1080)) {
                racer->unk_204 = 0x1E;
                racer->unk_27C = 0;
                racer->unk_284 = 0;
            }
        } else {
            racer->unk_27C += racer->unk_280;
            if (racer->unk_280 < 0) {
                racer->unk_280 += 2;
                if (racer->unk_27C <= 0) {
                    racer->unk_27C += 0x1000;
                    if (racer->unk_280 >= -0x31) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 2);
                    }
                }
            } else {
                racer->unk_280 -= 2;
                if (racer->unk_27C >= 0x1000) {
                    racer->unk_27C -= 0x1000;
                    if (racer->unk_280 < 0x32) {
                        racer->unk_27C = 0;
                        racer->unk_284 = 0;
                    } else if (D_807A16E0 != 0) {
                        func_80741014(racer->id, 2);
                    }
                }
            }
        }
    } else {
        racer->unk_E8.x.x = racer->unk_C0.x.x;
        racer->unk_E8.x.y = racer->unk_C0.x.y;
        racer->unk_E8.x.z = racer->unk_C0.x.z;
        if (gGameMode == GAMEMODE_GP_END_CS) {
            racer->unk_10C.x += (var_fs1 = racer->unk_A4 * racer->unk_C0.y.x);
            racer->unk_10C.y += (var_fs0 = racer->unk_A4 * racer->unk_C0.y.y);
            racer->unk_10C.z += (var_ft4 = racer->unk_A4 * racer->unk_C0.y.z);
            racer->unk_168.x += var_fs1;
            racer->unk_168.y += var_fs0;
            racer->unk_168.z += var_ft4;
        }
    }
    var_fa1 = racer->unk_68.x * 0.6f;

    racer->unk_E8.y.x += 0.19f * (racer->unk_C0.y.x + (var_fa1 * racer->unk_C0.z.x));
    racer->unk_E8.y.y += 0.19f * (racer->unk_C0.y.y + (var_fa1 * racer->unk_C0.z.y));
    racer->unk_E8.y.z += 0.19f * (racer->unk_C0.y.z + (var_fa1 * racer->unk_C0.z.z));

    racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
    racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
    racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

    temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

    racer->unk_E8.z.x *= temp_fa0;
    racer->unk_E8.z.y *= temp_fa0;
    racer->unk_E8.z.z *= temp_fa0;

    racer->unk_E8.y.x = (racer->unk_E8.x.y * racer->unk_E8.z.z) - (racer->unk_E8.x.z * racer->unk_E8.z.y);
    racer->unk_E8.y.y = (racer->unk_E8.x.z * racer->unk_E8.z.x) - (racer->unk_E8.x.x * racer->unk_E8.z.z);
    racer->unk_E8.y.z = (racer->unk_E8.x.x * racer->unk_E8.z.y) - (racer->unk_E8.x.y * racer->unk_E8.z.x);
    if (racer->stateFlags & RACER_STATE_FLAGS_2000) {
        racer->unk_E8.y.x += racer->unk_118.x *= 0.8f;
        racer->unk_E8.y.y += racer->unk_118.y *= 0.8f;
        racer->unk_E8.y.z += racer->unk_118.z *= 0.8f;

        var_fa1 = 1.0f / sqrtf(SQ(racer->unk_E8.y.x) + SQ(racer->unk_E8.y.y) + SQ(racer->unk_E8.y.z));
        if (var_fa1 > 0.99f) {
            racer->stateFlags &= ~RACER_STATE_FLAGS_2000;
        }

        racer->unk_E8.y.x *= var_fa1;
        racer->unk_E8.y.y *= var_fa1;
        racer->unk_E8.y.z *= var_fa1;

        racer->unk_E8.z.x = (racer->unk_E8.y.y * racer->unk_E8.x.z) - (racer->unk_E8.y.z * racer->unk_E8.x.y);
        racer->unk_E8.z.y = (racer->unk_E8.y.z * racer->unk_E8.x.x) - (racer->unk_E8.y.x * racer->unk_E8.x.z);
        racer->unk_E8.z.z = (racer->unk_E8.y.x * racer->unk_E8.x.y) - (racer->unk_E8.y.y * racer->unk_E8.x.x);

        temp_fa0 = 1.0f / sqrtf(SQ(racer->unk_E8.z.x) + SQ(racer->unk_E8.z.y) + SQ(racer->unk_E8.z.z));

        racer->unk_E8.z.x *= temp_fa0;
        racer->unk_E8.z.y *= temp_fa0;
        racer->unk_E8.z.z *= temp_fa0;

        racer->unk_E8.x.x = (racer->unk_E8.z.y * racer->unk_E8.y.z) - (racer->unk_E8.z.z * racer->unk_E8.y.y);
        racer->unk_E8.x.y = (racer->unk_E8.z.z * racer->unk_E8.y.x) - (racer->unk_E8.z.x * racer->unk_E8.y.z);
        racer->unk_E8.x.z = (racer->unk_E8.z.x * racer->unk_E8.y.y) - (racer->unk_E8.z.y * racer->unk_E8.y.x);
    }

    if (racer->unk_220 != 0) {
        racer->unk_220--;
    }
    if (racer->spinOutTimer != 0) {
        if (!((racer->id + gGameFrameCount) & 3) && (racer->machineLod != 0)) {
            sp10C.x = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z;
            func_i2_800AC750(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x, racer->velocity.y, racer->velocity.z,
                             (f32) ((Math_Rand2() & 0xF) + ((s32) (racer->spinOutTimer * 5) / 150) + 5), racer);
            if (!((racer->id + gGameFrameCount) & 4) && (D_807A16E0 != 0)) {
                func_80741014(racer->id, 5);
            }
            if (racer->id < gNumPlayers) {
                controller->unk_88 = 0xBB8;
                controller->unk_8C = 0;
                controller->unk_90 = 0;
            }

            for (i = 2; i > 0; i--) {
                var_fs1 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
                var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.000038147264f) + 2.0f;
                var_ft4 = ((f32) (Math_Rand2() & 0x1FFFF) * 0.000068665075f) - 4.5f;
                func_i2_800AC8C0(sp10C.x, sp10C.y, sp10C.z,
                                 racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                     (var_ft4 * racer->unk_C0.x.x),
                                 racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                     (var_ft4 * racer->unk_C0.x.y),
                                 racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                     (var_ft4 * racer->unk_C0.x.z),
                                 racer);
            }
        }

        racer->spinOutTimer++;
        if (racer->spinOutTimer > 150) {

            racer->stateFlags &= ~RACER_STATE_SPINNING_OUT;
            racer->spinOutTimer = 0;
            racer->stateFlags |= RACER_STATE_CRASHED;
            racer->unk_17C = 10.0f;
            D_807A16CE++;
            func_80719F9C(racer);
            if (racer->machineLod != 0) {
                func_i2_800AC808(racer->unk_0C.unk_34.x, racer->unk_0C.unk_34.y, racer->unk_0C.unk_34.z,
                                 racer->velocity.x, racer->velocity.y, racer->velocity.z, 80.0f, racer);
                if (racer->id < gNumPlayers) {
                    i = 60;
                } else {
                    i = 30;
                }
                sp13C = racer->bodyRF;
                sp138 = racer->bodyGF;
                sp134 = racer->bodyBF;
                do {
                    var_fs1 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    var_fs0 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00005340617f) + 3.5f;
                    var_ft4 = ((f32) (Math_Rand1() & 0x1FFFF) * 0.00011444179f) - 7.5f;
                    func_i2_800ACBE8((s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x,
                                     (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y,
                                     (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z,
                                     racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                         (var_ft4 * racer->unk_C0.x.x),
                                     racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                         (var_ft4 * racer->unk_C0.x.y),
                                     racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                         (var_ft4 * racer->unk_C0.x.z),
                                     &racer->unk_C0, sp13C, sp138, sp134, racer);
                    i--;
                } while (i != 0);
                if (D_807A16E0 != 0) {
                    func_80741014(racer->id, 8);
                }
                if (racer->id < gNumPlayers) {
                    controller->unk_88 = 10000;
                    controller->unk_8C = 500;
                    controller->unk_90 = 5;
                }
            }
        }
    }
    if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
        var_fa1 = racer->energy / racer->maxEnergy;
        if ((racer->id < gNumPlayers) && (var_fa1 < 0.3f) && (racer->spinOutTimer == 0) && (D_807A16E0 != 0)) {
            if (var_fa1 >= 0.2f) {
                if (!(gGameFrameCount & 0x1F)) {
                    func_80741014(racer->id, 0x13);
                }
            } else if (var_fa1 >= 0.1f) {
                if (!(gGameFrameCount & 0xF)) {
                    func_80741014(racer->id, 0x14);
                }
            } else if (!(gGameFrameCount & 7)) {
                func_80741014(racer->id, 0x15);
            }
        }
        if (!(gGameFrameCount & 8) && ((var_fa1 < 0.2f) || ((var_fa1 < 0.5f) && !(gGameFrameCount & 0x10)))) {
            var_fa1 *= 2;
            var_fs1 = (racer->unk_2F8 * var_fa1) + racer->unk_2EC;
            var_fs0 = (racer->unk_2FC * var_fa1) + racer->unk_2F0;
            var_ft4 = (racer->unk_300 * var_fa1) + racer->unk_2F4;
            var_fa1 = (f32) (gGameFrameCount & 7) / 7.0f;
            var_fs1 += ((racer->bodyRF - var_fs1) * var_fa1);
            var_fs0 += ((racer->bodyGF - var_fs0) * var_fa1);
            var_ft4 += ((racer->bodyBF - var_ft4) * var_fa1);
        } else {
            var_fs1 = racer->bodyRF;
            var_fs0 = racer->bodyGF;
            var_ft4 = racer->bodyBF;
        }

        var_fa1 = racer->unk_220 / 5.0f;
        racer->bodyR = ((255.0f - var_fs1) * var_fa1) + var_fs1;
        racer->bodyG = ((255.0f - var_fs0) * var_fa1) + var_fs0;
        racer->bodyB = ((255.0f - var_ft4) * var_fa1) + var_ft4;
        if (racer->unk_284 == 2) {
            var_fa1 = SIN(racer->unk_27C & 0x7FF);
            racer->unk_178 = (0.1f * var_fa1) + 1.05f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0xFF - (s32) (255.0f * var_fa1);
            racer->unk_2DE = 0;
        } else if (racer->unk_284 == 1) {
            racer->unk_178 = 1.075f;
            racer->unk_2DA = 0xFF;
            racer->unk_2DC = 0;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
        }
    } else {
        racer->bodyR = racer->bodyRF;
        racer->bodyG = racer->bodyGF;
        racer->bodyB = racer->bodyBF;
        if (((Math_Rand1() & 0x1FFFF) < 0x444) && (racer->machineLod != 0)) {
            var_fs1 = (((f32) (Math_Rand1() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            var_fs0 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 1.5f) + 0.5f;
            var_ft4 = (((f32) (Math_Rand2() & 0x1FFFF) / 131071.0f) * 3.0f) - 1.5f;
            sp10C.x = (s32) ((Math_Rand2() & 0x1F) - 0x10) + racer->unk_0C.unk_34.x;
            sp10C.y = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.y;
            sp10C.z = (s32) ((Math_Rand1() & 0x1F) - 0x10) + racer->unk_0C.unk_34.z;

            func_i2_800AC680(sp10C.x, sp10C.y, sp10C.z,
                             racer->velocity.x + (var_fs1 * racer->unk_C0.z.x) + (var_fs0 * racer->unk_C0.y.x) +
                                 (var_ft4 * racer->unk_C0.x.x),
                             racer->velocity.y + (var_fs1 * racer->unk_C0.z.y) + (var_fs0 * racer->unk_C0.y.y) +
                                 (var_ft4 * racer->unk_C0.x.y),
                             racer->velocity.z + (var_fs1 * racer->unk_C0.z.z) + (var_fs0 * racer->unk_C0.y.z) +
                                 (var_ft4 * racer->unk_C0.x.z),
                             10.0f, racer);
            func_i2_800ACABC(sp10C.x, sp10C.y, sp10C.z, racer->velocity.x + racer->unk_B4.x,
                             racer->velocity.y + racer->unk_B4.y, racer->velocity.z + racer->unk_B4.z, 20.0f, racer);

            if (racer->id < gNumPlayers) {
                func_80741014(racer->id, 0x32);
            }
            racer->unk_178 = 1.03f;
            racer->unk_2DA = racer->unk_2DC = 0xFF;
            racer->unk_2DE = 0;
        } else {
            racer->unk_178 = 0.0f;
        }
    }

    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_8000))) {
        racer->unk_17C += ((13.0f - racer->unk_17C) * 0.05f);
        if (racer->unk_17C > 13.0f) {
            racer->unk_17C = 13.0f;
            racer->stateFlags |= RACER_STATE_FLAGS_8000;
        }
    } else if ((D_807B37B4 == racer->unk_17C) && (controller->buttonCurrent != 0) && (gRaceIntroTimer < 250)) {
        racer->stateFlags &= ~RACER_STATE_FLAGS_8000;
        racer->shadowColorStrength = 1.3f;
        racer->shadowBaseR = 0.0f;
        racer->shadowBaseG = 205.0f;
        racer->shadowBaseB = 255.0f;
        if (racer->id < gNumPlayers) {
            func_8074184C(racer->id);
            func_80741014(racer->id, 0x28);
        }
    }

    if (racer->shadowColorStrength != 1.0f) {
        var_fa1 = (racer->shadowColorStrength - 1.0f) / 0.29999995f;
        var_fa1 *= var_fa1;
        racer->shadowR = racer->shadowBaseR * var_fa1;
        racer->shadowG = racer->shadowBaseG * var_fa1;
        racer->shadowB = racer->shadowBaseB * var_fa1;
        racer->shadowColorStrength -= 0.003f;
        if (racer->shadowColorStrength < 1.f) {
            racer->shadowColorStrength = 1.0f;
        }
    } else {
        racer->shadowR = racer->shadowG = racer->shadowB = 0;
    }
    if (racer->id < gNumPlayers) {
        if ((racer->unk_0C.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) &&
            !(racer->stateFlags & RACER_STATE_FLAGS_80000000)) {
            if (!(racer->unk_08 & 0x100)) {
                racer->unk_08 |= 0x100;
                if (D_807A16E0 != 0) {
                    func_8074151C(racer->id);
                }
            }
        } else {

            if (racer->unk_08 & 0x100) {
                racer->unk_08 &= ~0x100;
                if (D_807A16E0 != 0) {
                    func_80741538(racer->id);
                }
            }
        }
    }
}
#else
void func_80721D78(Racer* racer, Controller* controller);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/27110/func_80721D78.s")
#endif

void func_80726254(s32 position) {
    if (!(position > -0x80 && position < 0x80)) {
        sGhostReplayRecordingSize += 3;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = -0x80;
            *sGhostReplayRecordingPtr++ = ((position & 0xFFFF) >> 8);
            *sGhostReplayRecordingPtr++ = position & 0xFF;
        } else {
            sGhostReplayRecordingSize -= 3;
            D_807B14F6 = 1;
            D_807B14F4 = 0;
        }
    } else {
        sGhostReplayRecordingSize++;
        if (sGhostReplayRecordingSize <= 16200) {
            *sGhostReplayRecordingPtr++ = position;
        } else {
            sGhostReplayRecordingSize--;
            D_807B14F6 = 1;
            D_807B14F4 = 0;
        }
    }
}

s32 func_80726348(GhostRacer* arg0) {
    s32 temp1 = *arg0->replayPtr++;

    if (temp1 == -0x80) {
        temp1 = *arg0->replayPtr++;
        temp1 <<= 8;
        temp1 |= (u8) *arg0->replayPtr++;
        arg0->replayIndex += 3;
    } else {
        arg0->replayIndex++;
    }

    return temp1;
}

void func_807263A4(void) {
    s32 i;

    for (i = 0; i < gNumPlayers; i++) {
        gControllers[gPlayerControlPorts[i]].unk_72 = 0;
    }

    if (D_807B37D4 == 1) {
        func_80719EDC(0);
    } else if (D_807B37D4 == -1) {
        func_80719F38(0);
    }
}

void func_8072643C(Racer* racer) {
    Controller dummyController;
    f32 preInputEnergy;

    if (racer->stateFlags & RACER_STATE_CPU_CONTROLLED) {
        preInputEnergy = racer->energy;
        Cpu_GenerateInputs(racer, &dummyController);
        if (preInputEnergy < racer->energy) {
            racer->energy = preInputEnergy;
        }
        if ((gRaceIntroTimer > 40) && (racer->unk_2A4 != 0)) {
            dummyController.buttonCurrent = 0;
            if (gRaceIntroTimer < 250) {
                racer->unk_2A4--;
            }
        }
        func_80721D78(racer, &dummyController);
    } else {
        func_80721D78(racer, &gControllers[gPlayerControlPorts[racer->id]]);
        racer->unk_33C = -racer->unk_0C.unk_28.x * racer->unk_24C.z.x - racer->unk_0C.unk_28.y * racer->unk_24C.z.y -
                         racer->unk_0C.unk_28.z * racer->unk_24C.z.z;
    }
}

extern GfxPool* gGfxPool;
extern s8 gGamePaused;
extern s32 gFastestGhostTime;
extern Player gPlayers[];

void func_80726554(void) {
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 sp128;
    f32 temp_fv1_3;
    f32 var_fa0;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fs1;
    f32 sp110;
    f32 sp10C;
    f32 sp108;
    f32 var_fs2;
    f32 var_ft4;
    s32 posDiff;
    GhostRacer* var_s0;
    RacerPairInfo* temp_s2;
    s32 i;
    Mtx3F spCC;
    Racer* racer;
    Racer* racer2;
    bool spC0;
    Player* var_s1_2;

    sRaceFrameCount++;
    spC0 = false;
    if (gRaceIntroTimer != 0) {
        if (!gGamePaused) {
            if (gRaceIntroTimer == 460) {
                func_8070DA84();
                if (D_8076C7D8 == 0) {
                    func_80741E88();
                }
            }

            gRaceIntroTimer--;
            if (gRaceIntroTimer == 40) {
                if (func_807424CC() != 0) {
                    gRaceIntroTimer++;
                    spC0 = true;
                } else {
                    for (racer = sLastRacer; racer >= gRacers; racer--) {
                        racer->stateFlags |= RACER_STATE_FLAGS_400000;
                    }
                }
            } else if ((gRaceIntroTimer == 255) && (gGameMode == GAMEMODE_TIME_ATTACK)) {
                D_807B14F4 = 1;
                sReplayRecordFrameCount = 0;
                sReplayRecordPosX = Math_Round(gRacers[0].unk_0C.unk_34.x);
                sReplayRecordPosY = Math_Round(gRacers[0].unk_0C.unk_34.y);
                sReplayRecordPosZ = Math_Round(gRacers[0].unk_0C.unk_34.z);

                for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
                    if (var_s0->exists) {
                        var_s0->initialized = true;
                        var_s0->frameCount = 0;
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosX = posDiff + sReplayRecordPosX;
                        var_s0->pos.x = gRacers[0].unk_0C.unk_34.x + (posDiff * 0.5f);
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosY = posDiff + sReplayRecordPosY;
                        var_s0->pos.y = gRacers[0].unk_0C.unk_34.y + (posDiff * 0.5f);
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosZ = posDiff + sReplayRecordPosZ;
                        var_s0->pos.z = gRacers[0].unk_0C.unk_34.z + (posDiff * 0.5f);
                    }
                }
            }
        }

        for (i = gNumPlayers - 1; i >= 0; i--) {
            racer2 = &gRacers[i];
            var_s1_2 = &gPlayers[i];
            spCC.x.x = -var_s1_2->unk_5C.x.x;
            spCC.x.y = -var_s1_2->unk_5C.x.y;
            spCC.x.z = -var_s1_2->unk_5C.x.z;
            spCC.y.x = racer2->unk_C0.y.x;
            spCC.y.y = racer2->unk_C0.y.y;
            spCC.y.z = racer2->unk_C0.y.z;
            func_806F6F64(&spCC);
            if (gRaceIntroTimer > 220) {
                var_fs0 = (gRaceIntroTimer - 220) / 240.0f;
            } else if (gRaceIntroTimer > 30) {
                var_fs0 = 0.0f;
            } else {
                var_fs0 = (30 - gRaceIntroTimer) / 30.0f;
            }
            var_fs0 = (1500.0f * var_fs0 * var_fs0) + 33.0f;
            var_fs2 = var_fs0 - racer2->unk_A0;
            func_806F7FCC(&gGfxPool->unk_33988[i], NULL, 0.2f, 0.2f, 0.2f, spCC.x.x, spCC.x.y, spCC.x.z, spCC.y.x,
                          spCC.y.y, spCC.y.z,
                          (racer2->unk_0C.unk_34.x + (var_fs2 * racer2->unk_C0.y.x) + (50.0f * racer2->unk_C0.x.x)) -
                              (var_fs0 * var_s1_2->unk_5C.x.x),
                          (racer2->unk_0C.unk_34.y + (var_fs2 * racer2->unk_C0.y.y) + (50.0f * racer2->unk_C0.x.y)) -
                              (var_fs0 * var_s1_2->unk_5C.x.y),
                          (racer2->unk_0C.unk_34.z + (var_fs2 * racer2->unk_C0.y.z) + (50.0f * racer2->unk_C0.x.z)) -
                              (var_fs0 * var_s1_2->unk_5C.x.z));
        }
    }

    if (gGamePaused) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        }
        gControllers[(gGameFrameCount & 3)].unk_78 = 1;
        return;
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        racer->unk_164 = racer->unk_165 = racer->unk_166 = 0;
        racer->stateFlags &= ~RACER_STATE_FLAGS_20000;
        racer->acceleration.z = 0.0f;
        racer->acceleration.y = 0.0f;
        racer->acceleration.x = 0.0f;
        if ((racer->unk_230 != 0.0f) && !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            racer->energy += racer->unk_230;
            if (racer->maxEnergy < racer->energy) {
                racer->energy = racer->maxEnergy;
            }
            racer->unk_230 = 0.0f;
        }
    }

    if (gNumPlayers != 1) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 1;
        }
    }
    if (gTotalRacers >= 2) {
        racer = sLastRacer;
        do {
            if (!(racer->stateFlags & RACER_STATE_FLAGS_40000000)) {
                continue;
            }

            i = (s32) (racer->id * (racer->id - 1)) >> 1;
            racer2 = racer - 1;
            do {
                if (racer2->stateFlags & RACER_STATE_FLAGS_40000000) {
                    temp_s2 = &sRacerPairInfo[i + racer2->id];
                    if (temp_s2->trailToLeadDistance > 92.0f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }

                    var_fa0 = racer2->unk_0C.unk_34.x - racer->unk_0C.unk_34.x;
                    var_fa1 = racer2->unk_0C.unk_34.z - racer->unk_0C.unk_34.z;
                    sp110 = var_fa0;
                    sp108 = var_fa1;
                    if (SQ(var_fa0) + SQ(var_fa1) > 2116.0f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }

                    sp10C = racer2->unk_0C.unk_34.y - racer->unk_0C.unk_34.y;
                    if ((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)) > 2116.0f) {
                        temp_s2->unk_10 = 0;
                        continue;
                    }

                    sp128 = sqrtf((SQ(var_fa0) + SQ(var_fa1) + SQ(sp10C)));
                    if (racer->stateFlags & RACER_STATE_CRASHED) {
                        var_fs2 = racer->unk_1F4 * 0.333f;
                    } else {
                        var_fs2 = racer->unk_1F4;
                    }
                    if (racer2->stateFlags & RACER_STATE_CRASHED) {
                        var_fs1 = racer2->unk_1F4 * 0.333f;
                    } else {
                        var_fs1 = racer2->unk_1F4;
                    }
                    temp_fv1_3 = var_fs2 + var_fs1;
                    var_fs2 /= temp_fv1_3;
                    var_fs1 /= temp_fv1_3;
                    temp_fs3 = racer2->velocity.x - racer->velocity.x;
                    temp_fs4 = racer2->velocity.y - racer->velocity.y;
                    temp_fs5 = racer2->velocity.z - racer->velocity.z;
                    if (temp_s2->unk_10 == 0) {
                        if (racer->id < gNumPlayers) {
                            racer2->unk_288 = 0;
                            racer2->unk_28C = racer;
                        }
                        if (racer2->id < gNumPlayers) {
                            racer->unk_288 = 0;
                            racer->unk_28C = racer2;
                        }
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = 1.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                            var_fa0 = temp_fv1_3 * temp_fs3;
                            var_fa1 = temp_fv1_3 * temp_fs4;
                            var_ft4 = temp_fv1_3 * temp_fs5;
                        } else {
                            temp_fv1_3 = 1.0f / sp128;
                            var_fa0 = temp_fv1_3 * sp110;
                            var_fa1 = temp_fv1_3 * sp10C;
                            var_ft4 = temp_fv1_3 * sp108;
                        }
                        var_fs0 = (var_fa0 * temp_fs3) + (var_fa1 * temp_fs4) + (var_ft4 * temp_fs5);

                        if (var_fs0 < 0.0f) {
                            var_fs0 = -var_fs0;
                        }
                        if ((racer2->machineLod != 0) &&
                            (func_i2_800AC680(((racer->unk_0C.unk_34.x + racer2->unk_0C.unk_34.x) * 0.5f) +
                                                  (6.0f * racer->unk_C0.y.x),
                                              ((racer->unk_0C.unk_34.y + racer2->unk_0C.unk_34.y) * 0.5f) +
                                                  (6.0f * racer->unk_C0.y.y),
                                              ((racer->unk_0C.unk_34.z + racer2->unk_0C.unk_34.z) * 0.5f) +
                                                  (6.0f * racer->unk_C0.y.z),
                                              (racer->velocity.x + racer2->velocity.x) * 0.5f,
                                              (racer->velocity.y + racer2->velocity.y) * 0.5f,
                                              (racer->velocity.z + racer2->velocity.z) * 0.5f, var_fs0 + 12.0f,
                                              racer2) == 0)) {
                            racer->unk_220 = racer2->unk_220;
                        }
                        var_fs0 *= 1.1f;
                        if (racer->unk_284 == 0) {
                            if (racer2->unk_284 == 0) {
                                func_8071EE74(racer, var_fs1 * var_fs0);
                                func_8071EE74(racer2, var_fs2 * var_fs0);
                            } else if ((racer2 == gRacers) && (gNumPlayers == 1)) {
                                func_8071EE74(racer, var_fs0 * 10.0f);
                            } else {
                                func_8071EE74(racer, var_fs0);
                            }
                        } else if (racer2->unk_284 == 0) {
                            func_8071EE74(racer2, var_fs0);
                        } else {
                            func_8071EE74(racer, var_fs1 * var_fs0);
                            func_8071EE74(racer2, var_fs2 * var_fs0);
                        }
                        if (D_807A16E0 != 0) {
                            func_80741014(racer2->id, 4);
                        }
                    }
                    temp_s2->unk_10 = 1;
                    if (((sp110 * temp_fs3) + (sp10C * temp_fs4) + (sp108 * temp_fs5)) <= 0.0f) {
                        if (sp128 < 0.01f) {
                            temp_fv1_3 = -46.0f / sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fs5));
                            var_fa0 = temp_fv1_3 * temp_fs3;
                            var_fa1 = temp_fv1_3 * temp_fs4;
                            var_ft4 = temp_fv1_3 * temp_fs5;
                        } else {
                            if ((racer->unk_284 | racer2->unk_284) != 0) {
                                var_fs0 = 46.0f - sp128;
                                if (var_fs0 < 3) {
                                    var_fs0 = 3;
                                }
                                var_fs0 /= sp128;
                            } else {
                                var_fs0 = 46.0f - sp128;
                                var_fs0 /= sp128;
                            }
                            var_fa0 = var_fs0 * sp110;
                            var_fa1 = var_fs0 * sp10C;
                            var_ft4 = var_fs0 * sp108;
                        }
                        if (racer->unk_284 != 0) {
                            if (racer2->unk_284 == 0) {
                                var_fs2 = 3.0f;
                                var_fs1 = 0.0f;
                                racer2->unk_208 = 0x3C;
                            }
                        } else if (racer2->unk_284 != 0) {
                            var_fs2 = 0.0f;
                            var_fs1 = 3.0f;
                            racer->unk_208 = 0x3C;
                        }
                        racer->acceleration.x -= var_fs1 * var_fa0;
                        racer->acceleration.y -= var_fs1 * var_fa1;
                        racer->acceleration.z -= var_fs1 * var_ft4;
                        racer->unk_118.x = (-0.15f * var_fs1) * var_fa0;
                        racer->unk_118.y = (-0.15f * var_fs1) * var_fa1;
                        racer->unk_118.z = (-0.15f * var_fs1) * var_ft4;
                        racer->stateFlags |= RACER_STATE_FLAGS_2000;
                        racer2->acceleration.x += var_fs2 * var_fa0;
                        racer2->acceleration.y += var_fs2 * var_fa1;
                        racer2->acceleration.z += var_fs2 * var_ft4;
                        racer2->unk_118.x = (0.15f * var_fs2) * var_fa0;
                        racer2->unk_118.y = (0.15f * var_fs2) * var_fa1;
                        racer2->unk_118.z = (0.15f * var_fs2) * var_ft4;
                        racer2->stateFlags |= RACER_STATE_FLAGS_2000;
                    }
                }
            } while (--racer2 >= gRacers);
        } while (--racer > gRacers);
    }
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->stateFlags & RACER_STATE_FLAGS_40000000) {
            func_8072643C(racer);
        }
    }

    for (i = 0; i < gNumPlayers; i++) {
        racer2 = &gRacers[i];
        if ((racer2->maxSpeed < racer2->speed) &&
            !(racer2->stateFlags &
              (RACER_STATE_CRASHED | RACER_STATE_AIRBORNE | RACER_STATE_FLAGS_2000000 | RACER_STATE_FLAGS_80000)) &&
            (D_807B37B8[i] == 0)) {
            racer2->maxSpeed = racer2->speed;
        }
    }

    if (gGameMode == GAMEMODE_TIME_ATTACK && !spC0) {
        sReplayRecordFrameCount++;
        if ((D_807B14F4 != 0) && !(sReplayRecordFrameCount & 1)) {
            var_fs0 = gRacers[0].unk_0C.unk_34.x;
            i = Math_Round(var_fs0);
            func_80726254(i - sReplayRecordPosX);
            sReplayRecordPosX = i;
            var_fs0 = gRacers[0].unk_0C.unk_34.y;
            i = Math_Round(var_fs0);
            func_80726254(i - sReplayRecordPosY);
            sReplayRecordPosY = i;
            var_fs0 = gRacers[0].unk_0C.unk_34.z;
            i = Math_Round(var_fs0);
            func_80726254(i - sReplayRecordPosZ);
            sReplayRecordPosZ = i;
            if ((D_807B14F8 != 0) && (D_807B14F6 == 0) && (D_807B14FA == 0)) {
                D_807B14FA = 1;
                sGhostReplayRecordingEnd = sGhostReplayRecordingSize;
            }
        }
        for (var_s0 = &gGhostRacers[2]; var_s0 >= gGhostRacers; var_s0--) {
            if ((var_s0->exists) && (var_s0->initialized)) {
                racer = var_s0->racer;
                sp110 = racer->unk_10C.x + racer->velocity.x;
                sp10C = racer->unk_10C.y + racer->velocity.y;
                sp108 = racer->unk_10C.z + racer->velocity.z;
                racer->velocity.x = var_s0->pos.x - racer->unk_10C.x;
                racer->velocity.y = var_s0->pos.y - racer->unk_10C.y;
                racer->velocity.z = var_s0->pos.z - racer->unk_10C.z;
                racer->unk_10C = var_s0->pos;

                if (func_i2_800B2C00(&racer->unk_0C, racer->unk_10C.x, racer->unk_10C.y, racer->unk_10C.z, 100, 1.0f) !=
                    0) {
                    var_s0->exists = var_s0->initialized = false;
                } else {
                    racer->unk_0C.unk_08 =
                        func_i2_800B20D0(racer->unk_0C.courseSegment, racer->unk_0C.unk_04, &racer->lapDistance);

                    func_i2_800B2824(racer->unk_0C.courseSegment, racer->unk_0C.unk_04, &racer->unk_24C,
                                     racer->unk_0C.unk_08);
                    racer->unk_270 = (racer->unk_0C.unk_08 * (racer->unk_0C.courseSegment->next->radiusLeft -
                                                              racer->unk_0C.courseSegment->radiusLeft)) +
                                     racer->unk_0C.courseSegment->radiusLeft;
                    racer->unk_274 = (racer->unk_0C.unk_08 * (racer->unk_0C.courseSegment->next->radiusRight -
                                                              racer->unk_0C.courseSegment->radiusRight)) +
                                     racer->unk_0C.courseSegment->radiusRight;
                    D_8076F2DC[TRACK_SHAPE_INDEX((u32) racer->unk_0C.courseSegment->trackSegmentInfo &
                                                 TRACK_SHAPE_MASK)](racer);

                    var_s0->frameCount++;
                    if (var_s0->frameCount & 1) {
                        var_s0->pos.x = var_s0->replayPosX;
                        var_s0->pos.y = var_s0->replayPosY;
                        var_s0->pos.z = var_s0->replayPosZ;
                        if (var_s0->replayIndex >= var_s0->ghost->replaySize) {
                            var_s0->exists = var_s0->initialized = false;
                        }
                    } else {
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosX += posDiff;
                        var_s0->pos.x += (posDiff * 0.5f);
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosY += posDiff;
                        var_s0->pos.y += (posDiff * 0.5f);
                        posDiff = func_80726348(var_s0);
                        var_s0->replayPosZ += posDiff;
                        var_s0->pos.z += (posDiff * 0.5f);
                    }

                    racer->speed = sqrtf(SQ(racer->velocity.x) + SQ(racer->velocity.y) + SQ(racer->velocity.z));

                    spCC = racer->unk_C0;
                    if (racer->speed > 1.0f) {
                        racer->unk_C0.x.x = var_s0->pos.x - racer->unk_10C.x;
                        racer->unk_C0.x.y = var_s0->pos.y - racer->unk_10C.y;
                        racer->unk_C0.x.z = var_s0->pos.z - racer->unk_10C.z;
                    }
                    racer->unk_C0.y.x += 0.19f * racer->unk_B4.x;
                    racer->unk_C0.y.y += 0.19f * racer->unk_B4.y;
                    racer->unk_C0.y.z += 0.19f * racer->unk_B4.z;
                    if (func_806F6F64(&racer->unk_C0) != 0) {
                        racer->unk_C0 = spCC;
                    }

                    racer->unk_80.x = racer->unk_10C.x - sp110;
                    racer->unk_80.y = racer->unk_10C.y - sp10C;
                    racer->unk_80.z = racer->unk_10C.z - sp108;
                    var_fs0 = racer->unk_68.x;
                    racer->unk_68.x = ((spCC.z.x * (racer->unk_80.x)) + (spCC.z.y * racer->unk_80.y) +
                                       (spCC.z.z * racer->unk_80.z) + var_fs0) *
                                      0.5f;
                    racer->unk_68.y =
                        (spCC.y.x * (racer->unk_80.x)) + (spCC.y.y * racer->unk_80.y) + (spCC.y.z * racer->unk_80.z);
                    racer->unk_68.z =
                        (spCC.x.x * (racer->unk_80.x)) + (spCC.x.y * racer->unk_80.y) + (spCC.x.z * racer->unk_80.z);
                    racer->unk_5C.x = (racer->unk_C0.z.x * racer->velocity.x) +
                                      (racer->unk_C0.z.y * racer->velocity.y) + (racer->unk_C0.z.z * racer->velocity.z);
                    racer->unk_5C.y = (racer->unk_C0.y.x * racer->velocity.x) +
                                      (racer->unk_C0.y.y * racer->velocity.y) + (racer->unk_C0.y.z * racer->velocity.z);
                    racer->unk_5C.z = (racer->unk_C0.x.x * racer->velocity.x) +
                                      (racer->unk_C0.x.y * racer->velocity.y) + (racer->unk_C0.x.z * racer->velocity.z);
                    racer->unk_E8.x.x = racer->unk_C0.x.x;
                    racer->unk_E8.x.y = racer->unk_C0.x.y;
                    racer->unk_E8.x.z = racer->unk_C0.x.z;

                    var_fs0 = racer->unk_68.x * 0.6f;
                    racer->unk_E8.y.x += 0.19f * (racer->unk_C0.y.x + (var_fs0 * racer->unk_C0.z.x));
                    racer->unk_E8.y.y += 0.19f * (racer->unk_C0.y.y + (var_fs0 * racer->unk_C0.z.y));
                    racer->unk_E8.y.z += 0.19f * (racer->unk_C0.y.z + (var_fs0 * racer->unk_C0.z.z));
                    func_806F6D8C(&racer->unk_E8);
                    if (var_s0->ghost->replayEnd < var_s0->replayIndex) {
                        if (var_s0->scale != 0.f) {
                            var_s0->scale -= 0.02f;
                            if (var_s0->scale <= 0.0f) {
                                var_s0->exists = var_s0->initialized = false;
                            }
                        }
                    }
                }
            }
        }
    }
    if (gGameFrameCount & 1) {
        func_8071B9F4();
    } else {
        if ((D_807A16CC == 0) || (gNumPlayers == 1)) {
            func_8071B634();
        }

        for (i = 0; i < gNumPlayers; i++) {
            racer2 = &gRacers[i];
            if ((((racer2->unk_24C.x.x * racer2->velocity.x) + (racer2->unk_24C.x.y * racer2->velocity.y) +
                  (racer2->unk_24C.x.z * racer2->velocity.z)) < -0.3f) &&
                !(racer2->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_80000))) {
                D_807B37B8[i]++;
                if (D_807B37B8[i] == 100) {
                    func_8074122C(0x3C);
                }
            } else {
                D_807B37B8[i] = 0;
            }
        }
    }
    if (gTotalRacers >= 2) {
        if (gNumPlayers == 1) {
            func_8071BE0C();
            if (D_807A16E0 != 0) {
                func_80740BE8(D_807A16C8);
            }
        }
        if ((gRacersByPosition[0]->id < gNumPlayers) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_COURSE_EDIT)) {
            var_fs0 = gRacersByPosition[0]->raceDistance - gRacersByPosition[1]->raceDistance;
            if (var_fs0 > 4000.0f) {
                if (!(gRacersByPosition[0]->unk_08 & 0x4000)) {
                    gRacersByPosition[0]->unk_08 |= 0x4000;
                    if (D_807A16E0 != 0) {
                        func_8074122C(0x3B);
                    }
                }
            } else if (var_fs0 < 2000.0f) {
                gRacersByPosition[0]->unk_08 &= ~0x4000;
            }
        }
    }
    if (D_807A16CC == 0) {
        if (gNumPlayers == 1) {
            if (gRacers[0].stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000)) {
                D_807A16CC = 1;
            }
        } else {
            i = gRacersRetired + gRacersFinished;

            if ((i >= (gTotalRacers - 1)) || (gNumPlayers == (gPlayerRacersRetired + gPlayerRacersFinished))) {
                D_807A16CC = 1;
                if (gGameFrameCount & 1) {
                    func_8071B634();
                }
                for (racer = &gRacers[gTotalRacers - 1]; racer >= gRacers; racer--) {
                    if (!(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000))) {
                        racer->stateFlags |= RACER_STATE_FLAGS_2000000 | RACER_STATE_CPU_CONTROLLED;
                        racer->energy = racer->maxEnergy;
                        if (D_807A16E0 != 0) {
                            if (racer->position == 1) {
                                func_80741014(racer->id, 0xF);
                            }
                            func_80740B98(racer->id);
                            func_80741550(racer->id);
                            if ((i != 0) && (gPlayerRacersFinished == 0)) {
                                i = 0;
                                func_8070DAFC();
                            }
                        }
                    }
                }

                for (i = gTotalRacers - 2; i >= 0; i--) {
                    D_807A1620[gRacersByPosition[i]->id] += D_8076E558[i];
                }
                D_807A1610[gRacersByPosition[0]->id]++;
            }
        }
    } else {
        D_807B37C8++;
        switch (D_807B37C8) {
            case 60:
                func_807263A4();
                break;
            case 30:
                if (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000) {
                    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_DEATH_RACE)) {
                        func_8074122C(0x3D);
                        break;
                    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
                        if ((gCurrentGhostType == (u32) GHOST_PLAYER) || (gCurrentGhostType == GHOST_NONE)) {
                            func_8074122C(0x3D);
                        } else if (gRacers[0].raceTime < gFastestGhostTime) {
                            func_8074122C(0x43);
                        }
                    }
                }
                break;
            case 120:
                if ((gGameMode == GAMEMODE_GP_RACE) && (gRacers[0].stateFlags & RACER_STATE_FLAGS_2000000) &&
                    (gRacers[0].position == (u32) 1)) {
                    func_8074122C(0x33);
                }
                break;
        }
    }
}

extern unk_80111870 D_800D1330[32];
extern s32 D_800D17B0;
extern s32 D_800D17B4;
extern unk_80111870 D_800D17B8[32];
extern s32 D_800D1C38;
extern s32 D_800D1C3C;
extern unk_80111870 D_800D1C40[8];
extern s32 D_800D1D60;
extern s32 D_800D1D64;
extern unk_801122A8 D_800D1D68[32];
extern s32 D_800D25E8;
extern s32 D_800D25EC;
extern unk_80111870 D_800D25F0[32];
extern s32 D_800D2A70;
extern s32 D_800D2A74;
extern unk_80112FB8 D_800D2A78[32];
extern s32 D_800D2BF8;
extern s32 D_800D2BFC;
extern unk_80113140 D_800D2C00[128];
extern s32 D_800D5800;
extern s32 D_800D5804;

extern GfxPool D_1000000;

#ifdef NON_EQUIVALENT
Gfx* func_80727F54(Gfx* gfx, s32 playerIndex) {
    s32 var_s3; // sp5CC
    s32 var_s4; // sp5C8
    s32 sp5C4;
    MtxF sp580;
    f32 sp574;
    f32 sp570;
    f32 sp56C;
    f32 sp568;
    f32 sp564;
    f32 sp560;
    f32 sp55C;
    f32 sp558;
    f32 temp_fs4; // sp554
    f32 temp_fs5; // sp550
    f32 sp54C;
    f32 temp_fs1; // sp548
    f32 temp_fs3; // sp544
    f32 temp_fs2; // sp540
    f32 sp53C;
    f32 sp538;
    f32 sp534;
    GhostRacer* sp4F8;
    Player* player;
    Racer* playerRacer;
    f32 sp84;
    s32 i;
    Lights1* temp_v0_7;
    Racer* racer;
    Racer* temp_v0_14;
    Racer* temp_v0_27;
    Vec3s* var_v0;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fa0_3;
    f32 temp_fa0_4;
    f32 temp_fa0_5;
    f32 temp_fa0_6;
    f32 temp_fa1;
    f32 temp_fa1_2;
    f32 temp_fa1_3;
    f32 temp_fa1_4;
    f32 temp_fs0;
    f32 temp_fs0_10;
    f32 temp_fs0_11;
    f32 temp_fs0_14;
    f32 temp_fs0_15;
    f32 temp_fs0_18;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fv0;
    f32 temp_fv0_10;
    f32 temp_fv0_11;
    f32 temp_fv0_12;
    f32 temp_fv0_13;
    f32 temp_fv0_14;
    f32 temp_fv0_15;
    f32 temp_fv0_16;
    f32 temp_fv0_17;
    f32 temp_fv0_18;
    f32 temp_fv0_19;
    f32 temp_fv0_20;
    f32 temp_fv0_21;
    f32 temp_fv0_22;
    f32 temp_fv0_23;
    f32 temp_fv0_24;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0_8;
    f32 temp_fv0_9;
    f32 temp_fv1;
    f32 temp_fv1_10;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 temp_fv1_7;
    f32 temp_fv1_9;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs3;

    s32 temp_s7_7;
    s32 temp_a3_4;

    s32 temp_a1_2;
    s32 temp_s4;
    s32 temp_v1_2;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_6;
    s32 var_s4_5;
    s32 var_s7;
    TexturePtr var_s2;
    CourseSegment* temp_v0_6;
    BoosterInfo* boosterInfo;
    GhostRacer* temp_t8;
    GhostRacer* temp_v0_10;
    GhostRacer* temp_v0_4;
    GhostRacer* var_v1;
    unk_80111870* temp_s1;
    unk_80111870* temp_s1_4;
    unk_80111870* temp_s1_5;
    unk_801122A8* temp_s1_3;
    unk_80112FB8* temp_s1_6;
    Mtx* mtx;
    unk_80113140* temp_v0_13;
    s32 temp;

    player = &gPlayers[playerIndex];

    temp_fv1 = (player->unk_5C.x.x * 100.0f) - player->unk_50.x;
    temp_fv0 = (player->unk_5C.x.y * 100.0f) - player->unk_50.y;
    temp_fa0 = (player->unk_5C.x.z * 100.0f) - player->unk_50.z;
    temp_fa1 = ((-temp_fv1 * player->unk_15C.zx) - (temp_fv0 * player->unk_15C.zy)) - (player->unk_15C.zz * temp_fa0);
    sp580.ww = temp_fa1;
    sp580.zw = player->unk_11C.zw - (temp_fa1 * player->unk_11C.zz);
    sp580.xw = (player->unk_11C.xx *
                ((temp_fv1 * player->unk_15C.xx) + (temp_fv0 * player->unk_15C.xy) + (temp_fa0 * player->unk_15C.xz))) -
               (temp_fa1 * player->unk_11C.xz);
    sp580.xx = player->unk_19C.xx;
    sp580.xy = player->unk_19C.xy;
    sp580.yw = (player->unk_11C.yy *
                ((temp_fv1 * player->unk_15C.yx) + (temp_fv0 * player->unk_15C.yy) + (temp_fa0 * player->unk_15C.yz))) -
               (temp_fa1 * player->unk_11C.yz);
    sp580.yx = player->unk_19C.yx;
    sp580.zx = player->unk_19C.zx;
    sp580.wx = player->unk_19C.wx;
    sp580.yy = player->unk_19C.yy;
    sp580.zy = player->unk_19C.zy;
    sp580.wy = player->unk_19C.wy;
    sp580.xz = player->unk_19C.xz;
    sp580.yz = player->unk_19C.yz;
    sp580.zz = player->unk_19C.zz;
    sp580.wz = player->unk_19C.wz;
    if (gGameMode == GAMEMODE_GP_END_CS || gGameMode == GAMEMODE_COURSE_EDIT) {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = 1;
            racer->unk_2B3 = 2;
        }
    } else {
        for (racer = sLastRacer; racer >= gRacers; racer--) {
            racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
            if (racer->stateFlags & RACER_STATE_FLAGS_40000000) {
                temp_fv0_2 = racer->unk_0C.unk_34.x;
                temp_fv1_2 = racer->unk_0C.unk_34.y;
                temp_fa1_2 = racer->unk_0C.unk_34.z;
                temp_fa0_2 = sp580.zw + ((sp580.zx * temp_fv0_2) + (sp580.zy * temp_fv1_2) + (sp580.zz * temp_fa1_2));
                if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                    continue;
                }
                sp574 =
                    1.0f / (sp580.ww + ((sp580.wx * temp_fv0_2) + (sp580.wy * temp_fv1_2) + (sp580.wz * temp_fa1_2)));

                temp_fs0 =
                    (sp580.xw + ((sp580.xx * temp_fv0_2) + (sp580.xy * temp_fv1_2) + (sp580.xz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                temp_fs0 =
                    (sp580.yw + ((sp580.yx * temp_fv0_2) + (sp580.yy * temp_fv1_2) + (sp580.yz * temp_fa1_2))) * sp574;
                if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                    continue;
                }

                if (temp_fa0_2 < 230.0f) {
                    racer->machineLod = 1;
                } else if (temp_fa0_2 < 290.0f) {
                    racer->machineLod = 2;
                } else if (temp_fa0_2 < 380.0f) {
                    racer->machineLod = 3;
                } else if (temp_fa0_2 < 470.0f) {
                    racer->machineLod = 4;
                } else if (temp_fa0_2 < 1500.0f) {
                    racer->machineLod = 5;
                } else {
                    racer->machineLod = 6;
                }

                if (temp_fa0_2 < 800.0f) {
                    racer->unk_2B2 = 1;
                }
                if (temp_fa0_2 < 400.0f) {
                    racer->unk_2B3 = 2;
                } else if (temp_fa0_2 < 900.0f) {
                    racer->unk_2B3 = 1;
                }
            }
        }
    }
    if (gNumPlayers >= 3) {
        for (racer = &gRacers[gNumPlayers - 1]; racer >= gRacers; racer--) {
            if ((racer->machineLod != 0) && (racer->machineLod < 6)) {
                racer->machineLod++;
            }
            if (racer->unk_2B3 == 2) {
                racer->unk_2B3 = 1;
            }
        }
    } else if (gGameMode == GAMEMODE_TIME_ATTACK) {
        for (var_v1 = &gGhostRacers[2]; var_v1 >= gGhostRacers; var_v1--) {
            if (var_v1->exists) {
                racer = var_v1->racer;
                racer->machineLod = racer->unk_2B2 = racer->unk_2B3 = 0;
                if (var_v1->exists) {
                    temp_fv0_3 = racer->unk_0C.unk_34.x;
                    temp_fv1_3 = racer->unk_0C.unk_34.y;
                    temp_fa1_3 = racer->unk_0C.unk_34.z;
                    temp_fa0_2 =
                        sp580.zw + ((sp580.zx * temp_fv0_3) + (sp580.zy * temp_fv1_3) + (sp580.zz * temp_fa1_3));
                    if ((temp_fa0_2 < 0.0f) || (temp_fa0_2 > 2500.0f)) {
                        continue;
                    }
                    sp574 = 1.0f /
                            (sp580.ww + ((sp580.wx * temp_fv0_3) + (sp580.wy * temp_fv1_3) + (sp580.wz * temp_fa1_3)));

                    temp_fs0 =
                        (sp580.xw + ((sp580.xx * temp_fv0_3) + (sp580.xy * temp_fv1_3) + (sp580.xz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }
                    temp_fs0 =
                        (sp580.yw + ((sp580.yx * temp_fv0_3) + (sp580.yy * temp_fv1_3) + (sp580.yz * temp_fa1_3))) *
                        sp574;
                    if ((temp_fs0 < -1.0f) || (temp_fs0 > 1.0f)) {
                        continue;
                    }

                    if (temp_fa0_2 < 230.0f) {
                        racer->machineLod = 1;
                    } else if (temp_fa0_2 < 290.0f) {
                        racer->machineLod = 2;
                    } else if (temp_fa0_2 < 380.0f) {
                        racer->machineLod = 3;
                    } else if (temp_fa0_2 < 470.0f) {
                        racer->machineLod = 4;
                    } else if (temp_fa0_2 < 1500.0f) {
                        racer->machineLod = 5;
                    } else {
                        racer->machineLod = 6;
                    }

                    if (temp_fa0_2 < 800.0f) {
                        racer->unk_2B2 = 1;
                    }
                    if (temp_fa0_2 < 400.0f) {
                        racer->unk_2B3 = 2;
                    } else if (temp_fa0_2 < 900.0f) {
                        racer->unk_2B3 = 1;
                    }
                }
            }
        }
    }
    if (gRaceIntroTimer < 280) {
        gSPDisplayList(gfx++, D_303A758);
        if (gGameMode == GAMEMODE_GP_END_CS) {
            gSPSetGeometryMode(gfx++, G_ZBUFFER);
            gDPSetRenderMode(gfx++, G_RM_ZB_XLU_DECAL, G_RM_ZB_XLU_DECAL2);
        }

        for (racer = sLastRacer; racer >= gRacers; racer--) {

            if ((racer->unk_2B2 != 0) && (racer->unk_168.y != -54321.0f)) {
                if (racer->unk_165 == 0) {
                    if (racer->unk_284 == 1) {
                        var_fs0 = ((COS(racer->unk_27C) * 0.15f) + 0.85f) * D_8076E570;
                    } else {
                        var_fs0 = D_8076E570;
                    }

                    func_806F8314(&gGfxPool->unk_32A88[racer->id], NULL, racer->shadowColorStrength * D_8076E568, 0.1f,
                                  racer->shadowColorStrength * var_fs0, &racer->unk_E8.x, &racer->unk_19C,
                                  &racer->unk_168);
                    racer->unk_165 = 1;
                }
                gSPMatrix(gfx++, &D_1000000.unk_32A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

                if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                    gDPLoadTextureBlock_4b(gfx++, D_8076DA74[racer->shadowType], G_IM_FMT_I, 32, 64, 0,
                                           G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                           G_TX_NOLOD);
                    gDPSetPrimColor(gfx++, 0, 0, racer->shadowR, racer->shadowG, racer->shadowB, 200);
                    gSPVertex(gfx++, D_8076D9C4[racer->shadowType], 4, 0);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, D_70488A8, G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
                    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);
                    gSPVertex(gfx++, D_7048868, 4, 0);
                }
                gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
            }
        }
        if (gGameMode == GAMEMODE_TIME_ATTACK) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);

            for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
                if (sp4F8->exists) {
                    racer = sp4F8->racer;
                    if ((racer->unk_2B2 != 0) && (racer->unk_168.y != -54321.0f)) {
                        func_806F8314(&gGfxPool->unk_32A88[racer->id], NULL, sp4F8->scale * D_8076E568, 0.1f,
                                      sp4F8->scale * D_8076E570, &racer->unk_E8.x, &racer->unk_19C, &racer->unk_168);
                        gSPMatrix(gfx++, &D_1000000.unk_32A88[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                        gDPLoadTextureBlock_4b(gfx++, D_8076DA74[racer->shadowType], G_IM_FMT_I, 32, 64, 0,
                                               G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD,
                                               G_TX_NOLOD);
                        gSPVertex(gfx++, D_8076D9C4[racer->shadowType], 4, 0);
                        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
                    }
                }
            }
        }
    } else {
        gRacers[0].speed = gRacers[1].speed = gRacers[2].speed = gRacers[3].speed = 0.0f;
    }

    gSPDisplayList(gfx++, D_303A7D8);

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->unk_178 != 0.0f) {
            if ((racer->machineLod != 0) && (racer->machineLod < 6)) {
                if (racer->unk_166 == 0) {
                    func_806F85C0(&gGfxPool->unk_33208[racer->id], NULL, racer->unk_178 * D_8076E568,
                                  racer->unk_178 * D_8076E56C, racer->unk_178 * D_8076E570, &racer->unk_E8,
                                  &racer->unk_10C);
                    racer->unk_166 = 1;
                }
                gSPMatrix(gfx++, &D_1000000.unk_33208[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gfx++);
                gDPSetBlendColor(gfx++, racer->unk_2DA, racer->unk_2DC, racer->unk_2DE, 255);

                if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                    gSPDisplayList(gfx++, D_8076DBD0[racer->machineIndex * 6 + racer->machineLod - 1]);
                } else {
                    gSPDisplayList(gfx++, D_8076DEA0[racer->machineLod - 1]);
                }
            }
        }
    }
    playerRacer = &gRacers[playerIndex];

    temp_v0_6 = playerRacer->unk_0C.courseSegment;
    if (temp_v0_6->trackSegmentInfo & TRACK_FLAG_20000000) {
        if (temp_v0_6->unk_6C < playerRacer->unk_0C.unk_04) {
            var_fs0_2 = (1.0f - playerRacer->unk_0C.unk_08) / temp_v0_6->unk_70;
        } else if (playerRacer->unk_0C.unk_04 < temp_v0_6->unk_68) {
            var_fs0_2 = playerRacer->unk_0C.unk_08 / temp_v0_6->unk_70;
        } else {
            var_s3 = 50;
            var_s4 = 50;
            sp5C4 = 50;
            goto block_115;
        }
        var_s3 = Math_Round(var_fs0_2 * -50.0f) + 100;
        var_s4 = Math_Round(var_fs0_2 * -50.0f) + 100;
        sp5C4 = Math_Round(var_fs0_2 * -50.0f) + 100;
    } else {
        var_s3 = 100;
        var_s4 = 100;
        sp5C4 = 100;
    }
block_115:
    temp_v0_7 = &gGfxPool->unk_33A88[playerIndex];
    temp_v0_7->a.l.colc[0] = var_s3;
    temp_v0_7->a.l.col[0] = var_s3;
    temp_v0_7->a.l.colc[1] = var_s4;
    temp_v0_7->a.l.col[1] = var_s4;
    temp_v0_7->a.l.colc[2] = sp5C4;
    temp_v0_7->a.l.col[2] = sp5C4;
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_303A5F8);
    } else {
        gSPDisplayList(gfx++, D_303A6A8);
    }

    gSPLight(gfx++, &D_1000000.unk_33A88[playerIndex].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_33A88[playerIndex].a, 2);

    if ((playerRacer->unk_0C.courseSegment->trackSegmentInfo & TRACK_FLAG_20000000) &&
        !(playerRacer->stateFlags & RACER_STATE_FLAGS_80000000)) {
        sp560 = playerRacer->unk_24C.y.x;
        gGfxPool->unk_33A88[playerIndex].l[0].l.dir[0] = Math_Round(sp560 * 120.0f);
        sp55C = playerRacer->unk_24C.y.y;
        gGfxPool->unk_33A88[playerIndex].l[0].l.dir[1] = Math_Round(sp55C * 120.0f);
        sp558 = playerRacer->unk_24C.y.z;
        gGfxPool->unk_33A88[playerIndex].l[0].l.dir[2] = Math_Round(sp558 * 120.0f);
        if ((playerRacer->unk_0C.courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_PIPE) {
            var_v0 = &D_807A16F8[playerRacer->unk_0C.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        } else {
            var_v0 = &D_807A16FC[playerRacer->unk_0C.courseSegment->trackSegmentInfo & TRACK_TYPE_MASK];
        }
        var_s3 = var_v0->x;
        sp5C4 = var_v0->y;
        var_s4 = var_v0->z;
    } else {
        gGfxPool->unk_33A88[playerIndex].l[0].l.dir[0] = gGfxPool->unk_33A88[playerIndex].l[0].l.dir[1] =
            gGfxPool->unk_33A88[playerIndex].l[0].l.dir[2] = 0x45;
        sp560 = 0.57735f;
        sp55C = 0.57735f;
        sp558 = 0.57735f;
        var_s3 = gCurrentCourseInfo->unk_14[3];
        sp5C4 = gCurrentCourseInfo->unk_14[4];
        var_s4 = gCurrentCourseInfo->unk_14[5];
    }
    if (gGameMode != GAMEMODE_GP_END_CS) {
        gGfxPool->unk_33AE8[playerIndex].l.unk_08[0] = Math_Round((sp560 - player->unk_5C.x.x) * 16383.0f);
        gGfxPool->unk_33AE8[playerIndex].l.unk_08[1] = Math_Round((sp55C - player->unk_5C.x.y) * 16383.0f);
        gGfxPool->unk_33AE8[playerIndex].l.unk_08[2] = Math_Round((sp558 - player->unk_5C.x.z) * 16383.0f);
        gSPDmaRead(gfx++, 0x8B0, D_8076E1F0, ARRAY_COUNT(D_8076E1F0));
        gSPLookAtY(gfx++, &D_1000000.unk_33AE8[playerIndex]);
        gDPSetFogColor(gfx++, var_s3, sp5C4, var_s4, 255);
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if (racer->machineLod != 0) {
            if (racer->unk_164 == 0) {
                func_806F85C0(&gGfxPool->unk_32308[racer->id], &racer->unk_124, D_8076E568, D_8076E56C, D_8076E570,
                              &racer->unk_E8, &racer->unk_10C);
                racer->unk_164 = 1;
            }
            if (!(racer->stateFlags & RACER_STATE_CRASHED)) {
                gSPMatrix(gfx++, &D_1000000.unk_32308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gSPDisplayList(gfx++, D_8076DB58[racer->machineIndex]);
                gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 255);
                gSPDisplayList(gfx++, D_8076DBD0[racer->machineIndex * 6 + racer->machineLod - 1]);
            }
        }
    }
    if (gGameMode == GAMEMODE_GP_END_CS) {
        gSPDisplayList(gfx++, D_90186C8);
        Light_SetLookAtSource(&gGfxPool->unk_33B28, &player->unk_15C);
        gSPLookAt(gfx++, &gGfxPool->unk_33B28);
        gSPTexture(gfx++, D_8076E588, D_8076E588, 0, G_TX_RENDERTILE, G_ON);

        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        if (gCourseCtx.courseData.skybox == SKYBOX_BLUE) {
            var_s2 = D_9000A10;
        } else {
            var_s2 = D_9000208;
        }

        gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, var_s2);
        gDPLoadBlock(gfx++, G_TX_RENDERTILE, 0, 0, 1023, 256);
        gDPTileSync(gfx++);
        gDPSetTile(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_MIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 5, G_TX_NOLOD);

        D_807B37AC += ((player->unk_5C.z.x * gRacers->velocity.x) + (player->unk_5C.z.y * gRacers->velocity.y) +
                       (player->unk_5C.z.z * gRacers->velocity.z)) *
                      D_8076E58C;
        temp_a1_2 = (s32) (D_807B37AC * 4.0f) & 0xFF;

        D_807B37B0 += ((player->unk_5C.y.x * gRacers->velocity.x) + (player->unk_5C.y.y * gRacers->velocity.y) +
                       (player->unk_5C.y.z * gRacers->velocity.z)) *
                      D_8076E58C;
        temp_v1_2 = (s32) (D_807B37B0 * 4.0f) & 0xFF;

        gDPSetTileSize(gfx++, G_TX_RENDERTILE, temp_a1_2, temp_v1_2, temp_v1_2 + 0xFC, temp_v1_2 + 0xFC);

        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_8076E584);

        for (racer = sLastRacer; racer >= gRacers; racer--) {
            gSPMatrix(gfx++, &D_1000000.unk_32308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gfx = func_8072E1F0(gfx, racer->character);
        }
    }

    var_s7 = 0;
    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if ((racer->machineLod != 0) && (racer->stateFlags & RACER_STATE_CRASHED)) {
            if (var_s7 == 0) {
                gSPDisplayList(gfx++, D_7045150);
                var_s7 = 1;
            }
            gSPMatrix(gfx++, &D_1000000.unk_32308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 255);
            gSPDisplayList(gfx++, D_8076DEA0[racer->machineLod - 1]);
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++,
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
                         Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_XLU | FORCE_BL |
                             GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->machineLod != 0) {
                    func_806F85C0(&gGfxPool->unk_32308[racer->id], &racer->unk_124, sp4F8->scale * D_8076E568,
                                  sp4F8->scale * D_8076E56C, sp4F8->scale * D_8076E570, &racer->unk_E8,
                                  &racer->unk_10C);
                    gSPMatrix(gfx++, &D_1000000.unk_32308[racer->id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPDisplayList(gfx++, D_8076DB58[racer->machineIndex]);
                    gDPSetEnvColor(gfx++, racer->bodyR, racer->bodyG, racer->bodyB, 240);
                    gSPDisplayList(gfx++, D_8076DBD0[racer->machineIndex * 6 + racer->machineLod - 1]);
                }
            }
        }
    }
    sp560 = player->unk_5C.z.x;
    sp55C = player->unk_5C.z.y;
    sp558 = player->unk_5C.z.z;
    sp56C = player->unk_5C.y.x;
    sp568 = player->unk_5C.y.y;
    sp564 = player->unk_5C.y.z;

    gSPDisplayList(gfx++, aSetupBoosterDL);

    if (!gGamePaused) {
        sp5C4 = gGameFrameCount;
    } else {
        sp5C4 = 1;
    }

    for (racer = sLastRacer; racer >= gRacers; racer--) {
        if ((racer->unk_2B3 != 0) && !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_SPINNING_OUT))) {
            boosterInfo = &sBoosterInfos[racer->boostersType];

            var_s3_3 = (3 - (sp5C4 & 3)) * 2;
            if (var_s3_3 < racer->unk_334) {
                var_s3_3 = racer->unk_334;
            }
            sp574 = var_s3_3 * 0.2f;

            // Boost color
            temp_fs0_5 = (f32) racer->boostTimer / sInitialBoostTimer;
            if (temp_fs0_5 != 0.0f) {
                sp574 += (7.5f * sqrtf(temp_fs0_5));
                if (racer->stateFlags & RACER_STATE_DASH_PAD_BOOST) {
                    gDPSetEnvColor(gfx++, 255, 223, 0, 255);
                } else {
                    gDPSetEnvColor(gfx++, 91, 255, 91, 255);
                }
            } else {
                gDPSetEnvColor(gfx++, 0, 255, 255, 255);
            }

            sp570 = (racer->unk_17C - D_807B37B4) / (13.0f - D_807B37B4);

            for (var_s3_4 = boosterInfo->count - 1; var_s3_4 >= 0; var_s3_4--) {
                temp_fs0_6 = boosterInfo->size[var_s3_4] * 0.35f;
                temp_fv0_12 = boosterInfo->pos[var_s3_4].x;
                temp_fv1_4 = boosterInfo->pos[var_s3_4].y;
                temp_fa0_4 = boosterInfo->pos[var_s3_4].z - (temp_fs0_6 * 3.6f);
                temp_fs4 = racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_12) + (racer->unk_124.xy * temp_fv1_4) +
                                                (racer->unk_124.xz * temp_fa0_4));
                temp_fs5 = racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_12) + (racer->unk_124.yy * temp_fv1_4) +
                                                (racer->unk_124.yz * temp_fa0_4));
                sp54C = racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_12) + (racer->unk_124.zy * temp_fv1_4) +
                                             (racer->unk_124.zz * temp_fa0_4));

                temp_fs0_6 += sp574;
                temp_fs0_6 *= sp570;
                temp_fs1 = temp_fs0_6 * sp56C;
                D_807A15DC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp568;
                D_807A15DC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp564;
                D_807A15DC[0].v.ob[2] = Math_Round(sp54C + temp_fs3);

                D_807A15DC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                D_807A15DC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                D_807A15DC[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                temp_fs1 = temp_fs0_6 * sp560;
                D_807A15DC[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
                temp_fs2 = temp_fs0_6 * sp55C;
                D_807A15DC[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
                temp_fs3 = temp_fs0_6 * sp558;
                D_807A15DC[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
                D_807A15DC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                D_807A15DC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                D_807A15DC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0;
                D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x3FF;
                if (racer->unk_2B3 == 2) {
                    temp_fs0_6 = racer->speed * 0.9f;
                    D_807A15DC[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_6));
                    D_807A15DC[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_6));
                    D_807A15DC[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_6));
                    D_807A15DC[4].v.tc[0] = 0x3FF;
                    D_807A15DC[4].v.tc[1] = 0;
                    D_807A15DC += 5;
                } else {
                    D_807A15DC += 4;
                }
            }
            if (racer->unk_2B3 == 2) {
                temp = boosterInfo->count * 5;
                gSPVertex(gfx++, D_807A15DC - temp, temp, 0);

                switch (boosterInfo->count) {
                    case 4:
                        gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                        gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                        gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                        gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                        gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                        break;
                    case 3:
                        gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                        gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                        gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        gSP1Triangle(gfx++, 1, 4, 3, 0);
                        break;
                }

            } else {
                gSPVertex(gfx++, D_807A15DC - boosterInfo->count * 4, boosterInfo->count * 4, 0);

                switch (boosterInfo->count) {
                    case 4:
                        gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                    /* fallthrough */
                    case 3:
                        gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                    /* fallthrough */
                    case 2:
                        gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                    /* fallthrough */
                    case 1:
                        gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                        break;
                }
            }
        }
    }
    if (gGameMode == GAMEMODE_TIME_ATTACK) {
        gDPPipeSync(gfx++);
        gDPSetEnvColor(gfx++, 255, 0, 255, 160);

        for (sp4F8 = &gGhostRacers[2]; sp4F8 >= gGhostRacers; sp4F8--) {
            if (sp4F8->exists) {
                racer = sp4F8->racer;
                if (racer->unk_2B3 != 0) {
                    boosterInfo = &sBoosterInfos[racer->boostersType];

                    sp84 = (f32) ((3 - (sp5C4 & 3)) * 2) * 0.2f;
                    for (var_s3_4 = boosterInfo->count - 1; var_s3_4 >= 0; var_s3_4--) {

                        temp_fs0_10 = boosterInfo->size[var_s3_4] * 0.35f;
                        temp_fv0_13 = boosterInfo->pos[var_s3_4].x;
                        temp_fv1_5 = boosterInfo->pos[var_s3_4].y;
                        temp_fa0_5 = boosterInfo->pos[var_s3_4].z - (temp_fs0_10 * 3.6f);
                        temp_fs4 =
                            racer->unk_124.xw + ((racer->unk_124.xx * temp_fv0_13) + (racer->unk_124.xy * temp_fv1_5) +
                                                 (racer->unk_124.xz * temp_fa0_5));
                        temp_fs5 =
                            racer->unk_124.yw + ((racer->unk_124.yx * temp_fv0_13) + (racer->unk_124.yy * temp_fv1_5) +
                                                 (racer->unk_124.yz * temp_fa0_5));
                        sp54C =
                            racer->unk_124.zw + ((racer->unk_124.zx * temp_fv0_13) + (racer->unk_124.zy * temp_fv1_5) +
                                                 (racer->unk_124.zz * temp_fa0_5));

                        D_807A15DC[0].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp56C));
                        D_807A15DC[0].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp568));
                        D_807A15DC[0].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp564));
                        D_807A15DC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        D_807A15DC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        D_807A15DC[2].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        temp_fs0_10 += sp84;

                        D_807A15DC[1].v.ob[0] = Math_Round(temp_fs4 + (temp_fs1 = temp_fs0_10 * sp560));
                        D_807A15DC[1].v.ob[1] = Math_Round(temp_fs5 + (temp_fs2 = temp_fs0_10 * sp55C));
                        D_807A15DC[1].v.ob[2] = Math_Round(sp54C + (temp_fs3 = temp_fs0_10 * sp558));
                        D_807A15DC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
                        D_807A15DC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
                        D_807A15DC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
                        D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] =
                            0;
                        D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] =
                            0x3FF;
                        if (racer->unk_2B3 == 2) {
                            temp_fs0_11 = racer->speed * 0.9f;
                            D_807A15DC[4].v.ob[0] = Math_Round(temp_fs4 - (racer->unk_E8.x.x * temp_fs0_11));
                            D_807A15DC[4].v.ob[1] = Math_Round(temp_fs5 - (racer->unk_E8.x.y * temp_fs0_11));
                            D_807A15DC[4].v.ob[2] = Math_Round(sp54C - (racer->unk_E8.x.z * temp_fs0_11));
                            D_807A15DC[4].v.tc[0] = 0x3FF;
                            D_807A15DC[4].v.tc[1] = 0;
                            D_807A15DC += 5;
                        } else {
                            D_807A15DC += 4;
                        }
                    }
                    if (racer->unk_2B3 == 2) {
                        temp = boosterInfo->count * 5;
                        gSPVertex(gfx++, D_807A15DC - temp, temp, 0);

                        switch (boosterInfo->count) {
                            case 4:
                                gSP2Triangles(gfx++, 16, 17, 18, 0, 15, 16, 18, 0);
                                gSP2Triangles(gfx++, 10, 11, 13, 0, 16, 19, 18, 0);
                                gSP2Triangles(gfx++, 11, 14, 13, 0, 11, 12, 13, 0);
                            /* fallthrough */
                            case 2:
                                gSP2Triangles(gfx++, 6, 7, 8, 0, 5, 6, 8, 0);
                                gSP2Triangles(gfx++, 0, 1, 3, 0, 6, 9, 8, 0);
                                gSP2Triangles(gfx++, 1, 4, 3, 0, 1, 2, 3, 0);
                                break;
                            case 3:
                                gSP2Triangles(gfx++, 11, 12, 13, 0, 10, 11, 13, 0);
                                gSP2Triangles(gfx++, 5, 6, 8, 0, 11, 14, 13, 0);
                                gSP2Triangles(gfx++, 6, 9, 8, 0, 6, 7, 8, 0);
                            /* fallthrough */
                            case 1:
                                gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                                gSP1Triangle(gfx++, 1, 4, 3, 0);
                                break;
                        }
                    } else {
                        temp = boosterInfo->count * 4;
                        gSPVertex(gfx++, D_807A15DC - temp, temp, 0);

                        switch (boosterInfo->count) {
                            case 4:
                                gSP2Triangles(gfx++, 13, 14, 15, 0, 12, 13, 15, 0);
                            /* fallthrough */
                            case 3:
                                gSP2Triangles(gfx++, 9, 10, 11, 0, 8, 9, 11, 0);
                            /* fallthrough */
                            case 2:
                                gSP2Triangles(gfx++, 5, 6, 7, 0, 4, 5, 7, 0);
                            /* fallthrough */
                            case 1:
                                gSP2Triangles(gfx++, 1, 2, 3, 0, 0, 1, 3, 0);
                                break;
                        }
                    }
                }
            }
        }
    }
    gSPDisplayList(gfx++, D_4007FB8);

    var_s3_6 = D_800D1C3C;

    var_s7 = (D_800D1C38 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((u32) (D_807A15E0 - 3) >= (u32) D_807A15DC)) {
        temp_s1 = &D_800D17B8[var_s7];

        temp_fs1 = temp_s1->unk_18 * sp56C;
        temp_fs3 = temp_s1->unk_18 * sp568;
        temp_fs2 = temp_s1->unk_18 * sp564;
        sp53C = temp_s1->unk_18 * sp560;
        sp538 = temp_s1->unk_18 * sp55C;
        sp534 = temp_s1->unk_18 * sp558;

        D_807A15DC[0].v.ob[0] = Math_Round(temp_s1->unk_00.x + temp_fs1);
        D_807A15DC[0].v.ob[1] = Math_Round(temp_s1->unk_00.y + temp_fs3);
        D_807A15DC[0].v.ob[2] = Math_Round(temp_s1->unk_00.z + temp_fs2);
        D_807A15DC[2].v.ob[0] = Math_Round(temp_s1->unk_00.x - temp_fs1);
        D_807A15DC[2].v.ob[1] = Math_Round(temp_s1->unk_00.y - temp_fs3);
        D_807A15DC[2].v.ob[2] = Math_Round(temp_s1->unk_00.z - temp_fs2);
        D_807A15DC[1].v.ob[0] = Math_Round(temp_s1->unk_00.x + sp53C);
        D_807A15DC[1].v.ob[1] = Math_Round(temp_s1->unk_00.y + sp538);
        D_807A15DC[1].v.ob[2] = Math_Round(temp_s1->unk_00.z + sp534);
        D_807A15DC[3].v.ob[0] = Math_Round(temp_s1->unk_00.x - sp53C);
        D_807A15DC[3].v.ob[1] = Math_Round(temp_s1->unk_00.y - sp538);
        D_807A15DC[3].v.ob[2] = Math_Round(temp_s1->unk_00.z - sp534);

        D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0;
        D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x7FF;

        gSPVertex(gfx++, D_807A15DC, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->unk_1C < 8) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 16), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->unk_1C * 32), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 16), 255);
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->unk_1C * 32), 0, 0, 0x17F - (temp_s1->unk_1C * 16));
        }

        gDPLoadTextureBlock(gfx++, D_8076D8D8[temp_s1->unk_1C >> 1], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 0x1F;

        D_807A15DC += 4;
    }
    var_s3_6 = D_800D1D64;
    var_s7 = (D_800D1D60 - 1) & 7;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 3) >= D_807A15DC)) {
        temp_s1 = &D_800D1C40[var_s7];
        temp_fs1 = temp_s1->unk_18 * sp56C;
        temp_fs3 = temp_s1->unk_18 * sp568;
        temp_fs2 = temp_s1->unk_18 * sp564;
        sp538 = temp_s1->unk_18 * sp55C;
        sp53C = temp_s1->unk_18 * sp560;
        sp534 = temp_s1->unk_18 * sp558;

        D_807A15DC[0].v.ob[0] = Math_Round(temp_s1->unk_00.x + temp_fs1);
        D_807A15DC[0].v.ob[1] = Math_Round(temp_s1->unk_00.y + temp_fs3);
        D_807A15DC[0].v.ob[2] = Math_Round(temp_s1->unk_00.z + temp_fs2);
        D_807A15DC[2].v.ob[0] = Math_Round(temp_s1->unk_00.x - temp_fs1);
        D_807A15DC[2].v.ob[1] = Math_Round(temp_s1->unk_00.y - temp_fs3);
        D_807A15DC[2].v.ob[2] = Math_Round(temp_s1->unk_00.z - temp_fs2);
        D_807A15DC[1].v.ob[0] = Math_Round(temp_s1->unk_00.x + sp53C);
        D_807A15DC[1].v.ob[1] = Math_Round(temp_s1->unk_00.y + sp538);
        D_807A15DC[1].v.ob[2] = Math_Round(temp_s1->unk_00.z + sp534);
        D_807A15DC[3].v.ob[0] = Math_Round(temp_s1->unk_00.x - sp53C);
        D_807A15DC[3].v.ob[1] = Math_Round(temp_s1->unk_00.y - sp538);
        D_807A15DC[3].v.ob[2] = Math_Round(temp_s1->unk_00.z - sp534);

        D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0;
        D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x7FF;

        gSPVertex(gfx++, D_807A15DC, 4, 0);
        gDPPipeSync(gfx++);

        if (temp_s1->unk_1C < 16) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1->unk_1C * 16), 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 0x1FF - (temp_s1->unk_1C * 16), 0, 0, 0x17F - (temp_s1->unk_1C * 8));
        }

        gDPLoadTextureBlock(gfx++, D_8076D8D8[temp_s1->unk_1C >> 2], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 0, 0, G_TX_NOLOD, G_TX_NOLOD);

        gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);

        var_s3_6--;

        var_s7 = (var_s7 - 1) & 7;

        D_807A15DC += 4;
    }

    gSPDisplayList(gfx++, D_4007FD8);

    var_s3_6 = D_800D5804;

    var_s7 = (D_800D5800 - 1) & 0x7F;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 2) >= D_807A15DC)) {

        temp_v0_13 = &D_800D2C00[var_s7];
        D_807A15DC[0].v.ob[0] = temp_v0_13->unk_00.x;
        D_807A15DC[0].v.ob[1] = temp_v0_13->unk_00.y;
        D_807A15DC[0].v.ob[2] = temp_v0_13->unk_00.z;
        D_807A15DC[1].v.ob[0] = temp_v0_13->unk_0C.x;
        D_807A15DC[1].v.ob[1] = temp_v0_13->unk_0C.y;
        D_807A15DC[1].v.ob[2] = temp_v0_13->unk_0C.z;
        D_807A15DC[2].v.ob[0] = temp_v0_13->unk_18.x;
        D_807A15DC[2].v.ob[1] = temp_v0_13->unk_18.y;
        D_807A15DC[2].v.ob[2] = temp_v0_13->unk_18.z;
        D_807A15DC[0].v.cn[0] = temp_v0_13->unk_48;
        D_807A15DC[0].v.cn[1] = temp_v0_13->unk_4A;
        D_807A15DC[0].v.cn[2] = temp_v0_13->unk_4C;
        D_807A15DC[0].v.cn[3] = temp_v0_13->unk_4E;
        gSPVertex(gfx++, D_807A15DC, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x7F;
        D_807A15DC += 3;
    }

    gSPDisplayList(gfx++, D_4008000);

    var_s3_6 = D_800D25EC;
    var_s7 = (D_800D25E8 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 2) >= D_807A15DC)) {
        temp_s1_3 = &D_800D1D68[var_s7];
        D_807A15DC[0].v.ob[0] = Math_Round(temp_s1_3->unk_00.x - (3.0f * temp_s1_3->unk_0C.x));
        D_807A15DC[0].v.ob[1] = Math_Round(temp_s1_3->unk_00.y - (3.0f * temp_s1_3->unk_0C.y));
        D_807A15DC[0].v.ob[2] = Math_Round(temp_s1_3->unk_00.z - (3.0f * temp_s1_3->unk_0C.z));
        D_807A15DC[1].v.ob[0] = Math_Round(temp_s1_3->unk_00.x + temp_s1_3->unk_30.x);
        D_807A15DC[1].v.ob[1] = Math_Round(temp_s1_3->unk_00.y + temp_s1_3->unk_30.y);
        D_807A15DC[1].v.ob[2] = Math_Round(temp_s1_3->unk_00.z + temp_s1_3->unk_30.z);
        D_807A15DC[2].v.ob[0] = Math_Round(temp_s1_3->unk_00.x - temp_s1_3->unk_30.x);
        D_807A15DC[2].v.ob[1] = Math_Round(temp_s1_3->unk_00.y - temp_s1_3->unk_30.y);
        D_807A15DC[2].v.ob[2] = Math_Round(temp_s1_3->unk_00.z - temp_s1_3->unk_30.z);

        D_807A15DC[0].v.cn[0] = 0xFF;
        D_807A15DC[0].v.cn[1] = D_807A15DC[0].v.cn[2] = 0;
        D_807A15DC[0].v.cn[3] = 0;
        D_807A15DC[1].v.cn[0] = D_807A15DC[2].v.cn[0] = D_807A15DC[1].v.cn[1] = D_807A15DC[2].v.cn[1] = 0xFF;
        D_807A15DC[1].v.cn[2] = D_807A15DC[2].v.cn[2] = 0;
        D_807A15DC[1].v.cn[3] = D_807A15DC[2].v.cn[3] = 0xFF;
        gSPVertex(gfx++, D_807A15DC, 3, 0);
        gSP1Triangle(gfx++, 0, 1, 2, 0);

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
        D_807A15DC += 3;
    }

    gSPDisplayList(gfx++, D_4008028);

    var_s3_6 = D_800D17B4;
    var_s7 = (D_800D17B0 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 3) >= D_807A15DC)) {
        temp_s1_4 = &D_800D1330[var_s7];
        temp_v0_14 = temp_s1_4->unk_20;
        if (temp_v0_14->unk_2B3 != 0) {
            temp_fv1_6 = SQ(temp_s1_4->unk_1C - 1) * -0.15f;
            temp_fs4 = temp_s1_4->unk_00.x + (temp_fv1_6 * temp_v0_14->unk_C0.y.x);
            temp_fs5 = temp_s1_4->unk_00.y + (temp_fv1_6 * temp_v0_14->unk_C0.y.y);
            sp54C = temp_s1_4->unk_00.z + (temp_fv1_6 * temp_v0_14->unk_C0.y.z);

            temp_fv0_16 = temp_s1_4->unk_18;
            temp_fs1 = temp_fv0_16 * sp56C;
            temp_fs3 = temp_fv0_16 * sp568;
            temp_fs2 = temp_fv0_16 * sp564;
            sp53C = temp_fv0_16 * sp560;
            sp538 = temp_fv0_16 * sp55C;
            sp534 = temp_fv0_16 * sp558;

            D_807A15DC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            D_807A15DC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
            D_807A15DC[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
            D_807A15DC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_807A15DC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
            D_807A15DC[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
            D_807A15DC[1].v.ob[0] = Math_Round(temp_fs4 + sp53C);
            D_807A15DC[1].v.ob[1] = Math_Round(temp_fs5 + sp538);
            D_807A15DC[1].v.ob[2] = Math_Round(sp54C + sp534);
            D_807A15DC[3].v.ob[0] = Math_Round(temp_fs4 - sp53C);
            D_807A15DC[3].v.ob[1] = Math_Round(temp_fs5 - sp538);
            D_807A15DC[3].v.ob[2] = Math_Round(sp54C - sp534);
            D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0;
            D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x7FF;

            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_4->unk_1C >> 1, G_ON);
            gSPVertex(gfx++, D_807A15DC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255 - (temp_s1_4->unk_1C * 8), 255);
            gDPSetEnvColor(gfx++, 255, 255 - (temp_s1_4->unk_1C * 16), 0, 255 - (temp_s1_4->unk_1C * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_807A15DC += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, D_4008130);

    var_s3_6 = D_800D2A74;
    var_s7 = (D_800D2A70 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 3) >= D_807A15DC)) {
        temp_s1_5 = &D_800D25F0[var_s7];
        if (temp_s1_5->unk_20->unk_2B3 != 0) {
            temp_fv0_17 = temp_s1_5->unk_18;
            temp_fs1 = temp_fv0_17 * sp56C;
            temp_fs3 = temp_fv0_17 * sp568;
            temp_fs2 = temp_fv0_17 * sp564;
            sp53C = temp_fv0_17 * sp560;
            sp538 = temp_fv0_17 * sp55C;
            sp534 = temp_fv0_17 * sp558;
            D_807A15DC[0].v.ob[0] = Math_Round(temp_s1_5->unk_00.x + temp_fs1);
            D_807A15DC[0].v.ob[1] = Math_Round(temp_s1_5->unk_00.y + temp_fs3);
            D_807A15DC[0].v.ob[2] = Math_Round(temp_s1_5->unk_00.z + temp_fs2);
            D_807A15DC[2].v.ob[0] = Math_Round(temp_s1_5->unk_00.x - temp_fs1);
            D_807A15DC[2].v.ob[1] = Math_Round(temp_s1_5->unk_00.y - temp_fs3);
            D_807A15DC[2].v.ob[2] = Math_Round(temp_s1_5->unk_00.z - temp_fs2);
            D_807A15DC[1].v.ob[0] = Math_Round(temp_s1_5->unk_00.x + sp53C);
            D_807A15DC[1].v.ob[1] = Math_Round(temp_s1_5->unk_00.y + sp538);
            D_807A15DC[1].v.ob[2] = Math_Round(temp_s1_5->unk_00.z + sp534);
            D_807A15DC[3].v.ob[0] = Math_Round(temp_s1_5->unk_00.x - sp53C);
            D_807A15DC[3].v.ob[1] = Math_Round(temp_s1_5->unk_00.y - sp538);
            D_807A15DC[3].v.ob[2] = Math_Round(temp_s1_5->unk_00.z - sp534);
            D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0;
            D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x7FF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, temp_s1_5->unk_1C >> 1, G_ON);
            gSPVertex(gfx++, D_807A15DC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetEnvColor(gfx++, 180, 150, 100, 230 - (temp_s1_4->unk_1C * 4));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_807A15DC += 4;
        }
        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    gSPDisplayList(gfx++, aSetupPitForceFieldDL);

    if (!gGamePaused) {
        var_s3_6 = gGameFrameCount & 7;
    } else {
        var_s3_6 = 0;
    }

    racer = sLastRacer;
    while ((racer >= gRacers) && ((D_807A15E0 - 3) >= D_807A15DC)) {
        if ((racer->pitForceFieldSize != 0.0f) && (racer->unk_2B3 != 0)) {
            temp_fs0_14 = 3.0f - ((1.0f - racer->pitForceFieldSize) * 19.0f);
            temp_fs4 = racer->unk_0C.unk_34.x + (temp_fs0_14 * racer->unk_C0.y.x);
            temp_fs5 = racer->unk_0C.unk_34.y + (temp_fs0_14 * racer->unk_C0.y.y);
            temp_fs0_15 = racer->pitForceFieldSize * 38.0f;
            sp54C = racer->unk_0C.unk_34.z + (temp_fs0_14 * racer->unk_C0.y.z);
            temp_fs1 = temp_fs0_15 * sp56C;
            temp_fs3 = temp_fs0_15 * sp568;
            temp_fs2 = temp_fs0_15 * sp564;
            temp_fs0_15 = racer->pitForceFieldSize * 40.0f;
            D_807A15DC[0].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            D_807A15DC[0].v.ob[1] = Math_Round(temp_fs5 + temp_fs3);
            D_807A15DC[0].v.ob[2] = Math_Round(sp54C + temp_fs2);
            D_807A15DC[2].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_807A15DC[2].v.ob[1] = Math_Round(temp_fs5 - temp_fs3);
            D_807A15DC[2].v.ob[2] = Math_Round(sp54C - temp_fs2);
            temp_fs1 = temp_fs0_15 * sp560;
            D_807A15DC[1].v.ob[0] = Math_Round(temp_fs4 + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            D_807A15DC[1].v.ob[1] = Math_Round(temp_fs5 + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
            D_807A15DC[1].v.ob[2] = Math_Round(sp54C + temp_fs3);
            D_807A15DC[3].v.ob[0] = Math_Round(temp_fs4 - temp_fs1);
            D_807A15DC[3].v.ob[1] = Math_Round(temp_fs5 - temp_fs2);
            D_807A15DC[3].v.ob[2] = Math_Round(sp54C - temp_fs3);
            D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = D_807A15DC[0].v.tc[1] = 0x20;
            D_807A15DC[2].v.tc[1] = D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = 0x7E0;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, var_s3_6, G_ON);
            gSPVertex(gfx++, D_807A15DC, 4, 0);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_807A15DC += 4;
        }
        racer--;
    }

    gSPDisplayList(gfx++, aSetupFallExplosionDL);

    var_s3_6 = D_800D2BFC;
    var_s7 = (D_800D2BF8 - 1) & 0x1F;
    while ((var_s3_6 != 0) && ((D_807A15E0 - 7) >= D_807A15DC)) {
        temp_s1_6 = &D_800D2A78[var_s7];
        racer = temp_s1_6->unk_08;
        temp_s4 = temp_s1_6->unk_04 - 5;
        if (temp_s1_6->unk_04 == 0) {
            break;
        }

        if ((temp_s4 >= 0) && (temp_s4 < 60)) {
            f32 temp;
            if ((D_807A15E0 - 3) < D_807A15DC) {
                break;
            }

            temp = SIN(((s32) (temp_s4 << 0xA) / 60)) * 163.64f;

            if (temp_s4 < 20) {
                sp5C4 = 255;
            } else {
                sp5C4 = (s32) ((60 - temp_s4) * 255) / 40;
            }

            temp_fs0_15 = temp * temp_s1_6->unk_00;
            temp_fs1 = temp_fs0_15 * sp56C;
            D_807A15DC[0].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp568;
            D_807A15DC[0].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp564;
            D_807A15DC[0].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs3);
            D_807A15DC[2].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_807A15DC[2].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs2);
            D_807A15DC[2].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs3);
            temp_fs1 = temp_fs0_15 * sp560;
            D_807A15DC[1].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            temp_fs2 = temp_fs0_15 * sp55C;
            D_807A15DC[1].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs2);
            temp_fs3 = temp_fs0_15 * sp558;
            D_807A15DC[1].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs3);
            D_807A15DC[3].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_807A15DC[3].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs2);
            D_807A15DC[3].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs3);
            D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1] = 0x40;
            D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1] = 0x1FBF;
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 0, G_ON);
            gSPVertex(gfx++, D_807A15DC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 255, sp5C4, 80, 255);
            gDPSetEnvColor(gfx++, sp5C4, 0, 0, sp5C4);
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_807A15DC += 4;
        }

        if (temp_s1_6->unk_04 < 0x1A) {
            if ((D_807A15E0 - 3) < D_807A15DC) {
                break;
            }
            temp_fs0_18 = (temp_s1_6->unk_00 * 163.64f * (f32) temp_s1_6->unk_04) / 26.0f;
            temp_fs1 = racer->unk_C0.x.x * temp_fs0_18;
            temp_fs3 = racer->unk_C0.x.y * temp_fs0_18;
            temp_fs2 = racer->unk_C0.x.z * temp_fs0_18;
            sp53C = racer->unk_C0.z.x * temp_fs0_18;
            sp538 = racer->unk_C0.z.y * temp_fs0_18;
            sp534 = racer->unk_C0.z.z * temp_fs0_18;
            D_807A15DC[0].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + temp_fs1);
            D_807A15DC[0].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + temp_fs3);
            D_807A15DC[0].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + temp_fs2);
            D_807A15DC[2].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - temp_fs1);
            D_807A15DC[2].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - temp_fs3);
            D_807A15DC[2].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - temp_fs2);
            D_807A15DC[1].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x + sp53C);
            D_807A15DC[1].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y + sp538);
            D_807A15DC[1].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z + sp534);
            D_807A15DC[3].v.ob[0] = Math_Round(racer->unk_0C.unk_34.x - sp53C);
            D_807A15DC[3].v.ob[1] = Math_Round(racer->unk_0C.unk_34.y - sp538);
            D_807A15DC[3].v.ob[2] = Math_Round(racer->unk_0C.unk_34.z - sp534);
            D_807A15DC[2].v.tc[1] = 0x40;

            D_807A15DC[0].v.tc[0] = D_807A15DC[1].v.tc[0] = D_807A15DC[1].v.tc[1] = D_807A15DC[2].v.tc[1];
            D_807A15DC[3].v.tc[1] = 0x1FBF;
            D_807A15DC[0].v.tc[1] = D_807A15DC[2].v.tc[0] = D_807A15DC[3].v.tc[0] = D_807A15DC[3].v.tc[1];
            gSPTexture(gfx++, 0x8000, 0x8000, 0, 1, G_ON);
            gSPVertex(gfx++, D_807A15DC, 4, 0);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 100, 255, 255, 255);
            gDPSetEnvColor(gfx++, 0, 0, 255, (((26 - temp_s1_6->unk_04) * 255) / 26));
            gSP2Triangles(gfx++, 0, 1, 3, 0, 1, 2, 3, 0);
            D_807A15DC += 4;
        }

        var_s3_6--;
        var_s7 = (var_s7 - 1) & 0x1F;
    }

    if (gRaceIntroTimer != 0) {
        gSPDisplayList(gfx++, D_400A258);

        gSPMatrix(gfx++, &D_1000000.unk_33988[playerIndex], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        gSPDisplayList(gfx++, aCountdownSignDL);

        if (((gRaceIntroTimer <= 220) && (gRaceIntroTimer >= 210)) ||
            ((gRaceIntroTimer <= 160) && (gRaceIntroTimer >= 150)) ||
            ((gRaceIntroTimer <= 100) && (gRaceIntroTimer >= 90)) || (gRaceIntroTimer <= 40)) {
            var_s2 = aCountdownMrZeroMouthOpenTex;
        } else {
            var_s2 = aCountdownMrZeroMouthClosedTex;
        }

        gDPPipeSync(gfx++);
        gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                            G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);

        gSPDisplayList(gfx++, D_400A480);

        if (gRaceIntroTimer > 220) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        } else {
            if (gRaceIntroTimer > 160) {
                var_s2 = aCountdown3Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 220)) {
                    func_8074122C(0x2F);
                }
            } else if (gRaceIntroTimer > 100) {
                var_s2 = aCountdown2Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 160)) {
                    func_8074122C(9);
                }
            } else if (gRaceIntroTimer > 40) {
                var_s2 = aCountdown1Tex;
                if ((playerIndex == 0) && (!gGamePaused) && (gRaceIntroTimer == 100)) {
                    func_8074122C(0xA);
                }
            } else {
                var_s2 = aCountdownGoTex;
                if ((playerIndex == 0) && (!gGamePaused)) {
                    if (gRaceIntroTimer == 40) {
                        func_8074122C(0xB);
                    }
                    if ((gRaceIntroTimer == 1) && (D_8076C7D8 == 0)) {
                        if (gCurrentCourseInfo->courseIndex < COURSE_EDIT_1) {
                            func_8070DAA4(D_8076F2FC[gCurrentCourseInfo->courseIndex]);
                        } else if (gCurrentCourseInfo->courseIndex == 0x36) {
                            func_8070DAA4(0x1D);
                        } else {
                            func_8070DAA4(func_80703228());
                        }
                    }
                }
            }

            gDPPipeSync(gfx++);
            gDPLoadTextureBlock(gfx++, var_s2, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP,
                                G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPVertex(gfx++, D_400AA28, 4, 0);
        gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 2, 3, 0);
    } else if ((gTotalRacers >= 2) && !(playerRacer->stateFlags & (RACER_STATE_FLAGS_2000000 | RACER_STATE_RETIRED)) &&
               (gGameMode != GAMEMODE_GP_END_CS)) {
        gSPDisplayList(gfx++, D_4007EA8);
        if ((gGameMode != GAMEMODE_PRACTICE) && (gGameMode != GAMEMODE_DEATH_RACE) &&
            (gGameMode != GAMEMODE_COURSE_EDIT)) {
            if (gTotalRacers < 3) {
                var_s4_5 = gTotalRacers;
            } else {
                var_s4_5 = 3;
            }

            for (i = 0; i < var_s4_5; i++) {

                racer = gRacersByPosition[i];
                if (racer->machineLod != 0) {
                    if ((playerIndex != racer->id) &&
                        !(racer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000))) {
                        if (racer->id < playerIndex) {
                            var_s7 = ((s32) ((playerIndex - 1) * playerIndex) >> 1) + racer->id;
                        } else {
                            var_s7 = ((s32) (racer->id * (racer->id - 1)) >> 1) + playerIndex;
                        }

                        if ((sRacerPairInfo[var_s7].trailToLeadDistance < 800.0f)) {
                            continue;
                        }

                        temp_fs4 = racer->unk_0C.unk_34.x + (20.0f * racer->unk_C0.y.x);
                        temp_fs5 = racer->unk_0C.unk_34.y + (20.0f * racer->unk_C0.y.y);
                        temp_fv0_19 = racer->unk_0C.unk_34.z + (20.0f * racer->unk_C0.y.z);
                        temp_fv1_7 = 1.0f / (player->unk_19C.ww +
                                             ((player->unk_19C.wx * temp_fs4) + (player->unk_19C.wy * temp_fs5) +
                                              (player->unk_19C.wz * temp_fv0_19)));
                        sp56C =
                            (player->unk_19C.xw + ((player->unk_19C.xx * temp_fs4) + (player->unk_19C.xy * temp_fs5) +
                                                   (player->unk_19C.xz * temp_fv0_19))) *
                            temp_fv1_7;
                        sp568 =
                            (player->unk_19C.yw + ((player->unk_19C.yx * temp_fs4) + (player->unk_19C.yy * temp_fs5) +
                                                   (player->unk_19C.yz * temp_fv0_19))) *
                            temp_fv1_7;
                        sp564 =
                            (player->unk_19C.zw + ((player->unk_19C.zx * temp_fs4) + (player->unk_19C.zy * temp_fs5) +
                                                   (player->unk_19C.zz * temp_fv0_19))) *
                            temp_fv1_7;
                        gDPPipeSync(gfx++);
                        gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);

                        if (gNumPlayers < 2) {
                            gDPLoadTextureBlock(gfx++, sPosition1PMarkerTexs[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 30, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 = ((s32) ((player->unk_E8 * sp56C) + player->unk_F0 + 0.5f) - 0xC) << 2;
                            sp5C4 = ((s32) ((-player->unk_EC * sp568) + player->unk_F4 + 0.5f) - 0x1E) << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (24 * 4 - 1),
                                                    sp5C4 + (30 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        } else {
                            gDPLoadTextureBlock(gfx++, sPositionMPMarkerTexs[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0,
                                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                                G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                            temp_s7_7 = ((s32) ((player->unk_E8 * sp56C) + player->unk_F0 + 0.5f) - 8) << 2;
                            sp5C4 = ((s32) ((-player->unk_EC * sp568) + player->unk_F4 + 0.5f) - 0x10) << 2;
                            gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (16 * 4 - 1),
                                                    sp5C4 + (16 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                        }
                    }
                }
            }
            if ((gGameMode == GAMEMODE_GP_RACE) && (sRivalRacer != NULL) && (sRivalRacer->machineLod != 0) &&
                !(sRivalRacer->stateFlags & (RACER_STATE_CRASHED | RACER_STATE_FLAGS_2000000)) &&
                (gRacers[0].position >= sRivalRacer->position)) {
                temp_fs4 = sRivalRacer->unk_0C.unk_34.x + (20.0f * sRivalRacer->unk_C0.y.x);
                temp_fs5 = sRivalRacer->unk_0C.unk_34.y + (20.0f * sRivalRacer->unk_C0.y.y);
                temp_fv0_19 = sRivalRacer->unk_0C.unk_34.z + (20.0f * sRivalRacer->unk_C0.y.z);
                temp_fv1_7 =
                    1.0f / (player->unk_19C.ww + ((player->unk_19C.wx * temp_fs4) + (player->unk_19C.wy * temp_fs5) +
                                                  (player->unk_19C.wz * temp_fv0_19)));
                sp56C = (player->unk_19C.xw + ((player->unk_19C.xx * temp_fs4) + (player->unk_19C.xy * temp_fs5) +
                                               (player->unk_19C.xz * temp_fv0_19))) *
                        temp_fv1_7;
                sp568 = (player->unk_19C.yw + ((player->unk_19C.yx * temp_fs4) + (player->unk_19C.yy * temp_fs5) +
                                               (player->unk_19C.yz * temp_fv0_19))) *
                        temp_fv1_7;
                sp564 = (player->unk_19C.zw + ((player->unk_19C.zx * temp_fs4) + (player->unk_19C.zy * temp_fs5) +
                                               (player->unk_19C.zz * temp_fv0_19))) *
                        temp_fv1_7;
                gDPPipeSync(gfx++);
                gDPSetPrimDepth(gfx++, (s32) ((sp564 * 16352.0f) + 16352.0f), 0);
                gDPLoadTextureBlock(gfx++, aRivalMarkerTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                temp_s7_7 = ((s32) ((player->unk_E8 * sp56C) + player->unk_F0 + 0.5f) - 0x10) << 2;
                sp5C4 = ((s32) ((-player->unk_EC * sp568) + player->unk_F4 + 0.5f) - 0x10) << 2;
                gSPScisTextureRectangle(gfx++, temp_s7_7, sp5C4, temp_s7_7 + (32 * 4 - 1), sp5C4 + (16 * 4 - 1), 0, 0,
                                        0, 1 << 10, 1 << 10);
            }
            gDPPipeSync(gfx++);
        }

        gDPSetDepthSource(gfx++, G_ZS_PIXEL);

        if (playerRacer->distanceFromRacerBehind < 3000.0f) {
            temp_v0_27 = playerRacer->racerBehind;
            if ((temp_v0_27->position == (playerRacer->position + 1)) &&
                !(temp_v0_27->stateFlags & RACER_STATE_RETIRED)) {
                temp_fa0_6 = playerRacer->unk_0C.unk_34.x - temp_v0_27->unk_0C.unk_34.x;
                temp_fv1_9 = playerRacer->unk_0C.unk_34.y - temp_v0_27->unk_0C.unk_34.y;
                sp564 = playerRacer->unk_0C.unk_34.z - temp_v0_27->unk_0C.unk_34.z;
                if ((((player->unk_5C.x.x * temp_fa0_6) + (temp_fv1_9 * player->unk_5C.x.y) +
                      (sp564 * player->unk_5C.x.z)) < 0.0f)) {
                    goto end;
                }
                var_fs1 = (player->unk_5C.z.x * temp_fa0_6) + (temp_fv1_9 * player->unk_5C.z.y) +
                          (sp564 * player->unk_5C.z.z);
                var_fs3 = (player->unk_5C.y.x * temp_fa0_6) + (temp_fv1_9 * player->unk_5C.y.y) +
                          (sp564 * player->unk_5C.y.z);
                temp_fv0_21 = SQ(var_fs1) + SQ(var_fs3);

                if ((temp_fv0_21 < 0.1f)) {
                    goto end;
                }
                temp_fa1_4 = ((player->unk_B8 - player->unk_B0) * 0.5f) + 4.0f;
                sp568 = ((player->unk_BC - player->unk_B4) * 0.5f) - 4.0f;
                temp_fv0_22 = sqrtf((SQ(temp_fa1_4) + SQ(sp568)) / temp_fv0_21);
                var_fs1 *= temp_fv0_22;
                var_fs3 *= temp_fv0_22;
                if (sp568 < var_fs3) {
                    temp_fv0_22 = sp568 / var_fs3;
                    var_fs1 *= temp_fv0_22;
                    var_fs3 *= temp_fv0_22;
                }

                gSPClearGeometryMode(gfx++, G_ZBUFFER);
                gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

                if (gGamePaused) {
                    var_s7 = 255;
                } else {
                    var_s7 = 255 - ((gGameFrameCount & 0xF) * 0x10);
                }

                gDPSetPrimColor(gfx++, 0, 0, 255, var_s7, 0,
                                (255 - (s32) (playerRacer->distanceFromRacerBehind * 0.085f)));

                if (gNumPlayers < 2) {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarker1PTex, G_IM_FMT_IA, 32, 23, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 = ((s32) (((player->unk_B0 + player->unk_B8) * 0.5f) + var_fs1 + 0.5f) - 0x10) << 2;
                    temp_a3_4 = ((s32) (((player->unk_B4 + player->unk_BC) * 0.5f) + var_fs3 + 0.5f) - 0x1C) << 2;

                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (32 * 4 - 1),
                                            temp_a3_4 + (23 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                } else {
                    gDPLoadTextureBlock_4b(gfx++, aCheckMarkerMPTex, G_IM_FMT_IA, 16, 10, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                    temp_s7_7 = ((s32) (((player->unk_B0 + player->unk_B8) * 0.5f) + var_fs1 + 0.5f) - 8) << 2;
                    temp_a3_4 = ((s32) (((player->unk_B4 + player->unk_BC) * 0.5f) + var_fs3 + 0.5f) - 0xA) << 2;
                    gSPScisTextureRectangle(gfx++, temp_s7_7, temp_a3_4, temp_s7_7 + (16 * 4 - 1),
                                            temp_a3_4 + (10 * 4 - 1), 0, 0, 0, 1 << 10, 1 << 10);
                }

                if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_DEATH_RACE)) {
                    if (playerRacer->distanceFromRacerBehind < 1000.0f) {
                        if (!(playerRacer->unk_08 & 0x8000)) {
                            playerRacer->unk_08 |= 0x8000;
                            if (D_807A16E0 != 0) {
                                func_8074122C(0x3A);
                            }
                        }
                    } else if (playerRacer->distanceFromRacerBehind > 2500.0f) {
                        playerRacer->unk_08 &= ~0x8000;
                    }
                }
            }
        }
    }
end:
    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/27110/func_80727F54.s")
#endif

Gfx* func_8072DE6C(Gfx* gfx, s32 arg1, s32 red, s32 green, s32 blue) {
    u8 character;

    if (arg1 < 6) {
        character = D_807B3C14[arg1 - 1];
    } else if (arg1 == 6) {
        character = D_807B3C14[5];
    } else {
        character = D_807B3C14[6];
    }

    gSPDisplayList(gfx++, D_8076DB58[character]);
    gDPSetEnvColor(gfx++, red, green, blue, 255);
    gSPDisplayList(gfx++, D_8076DBD0[character * 6]);
    return gfx;
}

Gfx* func_8072DF40(Gfx* gfx, s32 character, s32 arg2) {
    Machine* temp_t0 = &gMachines[character];
    s32 color;

    gSPDisplayList(gfx++, D_8076DB58[character]);

    if ((D_8076E5A8 != 0) && (temp_t0->customType == CUSTOM_MACHINE_DEFAULT)) {
        color = (temp_t0->red[arg2] * 77) + (temp_t0->green[arg2] * 151) + (temp_t0->blue[arg2] * 28);
        color >>= 8;
        gDPSetEnvColor(gfx++, color, color, color, 255);
    } else {
        gDPSetEnvColor(gfx++, temp_t0->red[arg2], temp_t0->green[arg2], temp_t0->blue[arg2], 255);
    }
    gSPDisplayList(gfx++, D_8076DBD0[character * 6]);
    return gfx;
}

Gfx* func_8072E0B0(Gfx* gfx, s32 character) {
    Machine* temp_v1 = &gMachines[character];

    gDPLoadTextureBlock_4b(gfx++, D_8076DA74[temp_v1->shadowType], G_IM_FMT_I, 32, 64, 0, G_TX_MIRROR | G_TX_CLAMP,
                           G_TX_MIRROR | G_TX_CLAMP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);

    gSPVertex(gfx++, D_8076D9C4[temp_v1->shadowType], 4, 0);
    gSP2Triangles(gfx++, 0, 1, 2, 0, 0, 3, 1, 0);
    return gfx;
}

Gfx* func_8072E1C0(Gfx* gfx, s32 character) {
    gSPDisplayList(gfx++, D_8076DBD0[character * 6]);
    return gfx;
}

Gfx* func_8072E1F0(Gfx* gfx, s32 character) {
    s32 characterSlot;
    unk_806F2400_unk_00* temp_v1_2;

    characterSlot = func_8070DBF0(character);

    if (D_806F2400.unk_3C0[characterSlot] > 0) {
        temp_v1_2 = &D_806F2400.unk_00[characterSlot];
        gSPDisplayList(gfx++, D_8076D970[temp_v1_2->frontType]);
        gSPDisplayList(gfx++, D_8076D98C[temp_v1_2->rearType]);
        gSPDisplayList(gfx++, D_8076D9A8[temp_v1_2->wingType]);
    } else if (D_806F2400.unk_3C0[characterSlot] < 0) {
        if ((character == CAPTAIN_FALCON) && (D_800D1308[CAPTAIN_FALCON] != 0)) {
            gSPDisplayList(gfx++, D_9012718);
        } else if ((character == SAMURAI_GOROH) && (D_800D1308[SAMURAI_GOROH] != 0)) {
            gSPDisplayList(gfx++, D_9013460);
        } else if ((character == JODY_SUMMER) && (D_800D1308[JODY_SUMMER] != 0)) {
            gSPDisplayList(gfx++, D_9013D58);
        } else {
            gSPDisplayList(gfx++, D_8076D8F8[character]);
        }
    } else {
        gSPDisplayList(gfx++, D_8076D8F8[character]);
    }
    return gfx;
}
