#include "global.h"
#include "ovl_i4.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_machine.h"
#include "fzx_font.h"
#include "fzx_assets.h"
#include "src/overlays/ovl_i2/transition.h"
#include "assets/overlays/ovl_i4/machine.h"

UNUSED s32 D_80077050;
static s32 sMachinesUnlocked;
f32 D_i4_80077058;
f32 D_i4_8007705C;
static s16 sMachineSelectIndex[8];

UNUSED s32 D_i4_80074F50 = 0;
#include "src/assets/overlays/ovl_i4/machine/machine.c"

unk_80077D50 sPortraitDrStewartCompTexInfo[] = { { 17, aFullPortraitDrStewartTex, TEX_WIDTH(aFullPortraitDrStewartTex),
                                                   TEX_HEIGHT(aFullPortraitDrStewartTex),
                                                   TEX_COMPRESSED_SIZE(aFullPortraitDrStewartTex) } };
unk_80077D50 sPortraitCaptainFalconCompTexInfo[] = {
    { 17, aFullPortraitCaptainFalconTex, TEX_WIDTH(aFullPortraitCaptainFalconTex),
      TEX_HEIGHT(aFullPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aFullPortraitCaptainFalconTex) },
};
unk_80077D50 sPortraitJodySummerCompTexInfo[] = {
    { 17, aFullPortraitJodySummerTex, TEX_WIDTH(aFullPortraitJodySummerTex), TEX_HEIGHT(aFullPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJodySummerTex) },
};
unk_80077D50 sPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aFullPortraitSamuraiGorohTex, TEX_WIDTH(aFullPortraitSamuraiGorohTex),
      TEX_HEIGHT(aFullPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aFullPortraitSamuraiGorohTex) },
};
unk_80077D50 sPortraitMightyGazelleCompTexInfo[] = {
    { 17, aFullPortraitMightyGazelleTex, TEX_WIDTH(aFullPortraitMightyGazelleTex),
      TEX_HEIGHT(aFullPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aFullPortraitMightyGazelleTex) },
};
unk_80077D50 sPortraitPicoCompTexInfo[] = { { 17, aFullPortraitPicoTex, TEX_WIDTH(aFullPortraitPicoTex),
                                              TEX_HEIGHT(aFullPortraitPicoTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitPicoTex) } };
unk_80077D50 sPortraitBabaCompTexInfo[] = { { 17, aFullPortraitBabaTex, TEX_WIDTH(aFullPortraitBabaTex),
                                              TEX_HEIGHT(aFullPortraitBabaTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitBabaTex) } };
unk_80077D50 sPortraitMrEadCompTexInfo[] = { { 17, aFullPortraitMrEadTex, TEX_WIDTH(aFullPortraitMrEadTex),
                                               TEX_HEIGHT(aFullPortraitMrEadTex),
                                               TEX_COMPRESSED_SIZE(aFullPortraitMrEadTex) } };
unk_80077D50 sPortraitOctomanCompTexInfo[] = { { 17, aFullPortraitOctomanTex, TEX_WIDTH(aFullPortraitOctomanTex),
                                                 TEX_HEIGHT(aFullPortraitOctomanTex),
                                                 TEX_COMPRESSED_SIZE(aFullPortraitOctomanTex) } };
unk_80077D50 sPortraitTheSkullCompTexInfo[] = { { 17, aFullPortraitTheSkullTex, TEX_WIDTH(aFullPortraitTheSkullTex),
                                                  TEX_HEIGHT(aFullPortraitTheSkullTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitTheSkullTex) } };
unk_80077D50 sPortraitBeastmanCompTexInfo[] = { { 17, aFullPortraitBeastmanTex, TEX_WIDTH(aFullPortraitBeastmanTex),
                                                  TEX_HEIGHT(aFullPortraitBeastmanTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitBeastmanTex) } };
unk_80077D50 sPortraitAntonioGusterCompTexInfo[] = {
    { 17, aFullPortraitAntonioGusterTex, TEX_WIDTH(aFullPortraitAntonioGusterTex),
      TEX_HEIGHT(aFullPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aFullPortraitAntonioGusterTex) },
};
unk_80077D50 sPortraitDraqCompTexInfo[] = { { 17, aFullPortraitDraqTex, TEX_WIDTH(aFullPortraitDraqTex),
                                              TEX_HEIGHT(aFullPortraitDraqTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitDraqTex) } };
unk_80077D50 sPortraitRogerBusterCompTexInfo[] = {
    { 17, aFullPortraitRogerBusterTex, TEX_WIDTH(aFullPortraitRogerBusterTex), TEX_HEIGHT(aFullPortraitRogerBusterTex),
      TEX_COMPRESSED_SIZE(aFullPortraitRogerBusterTex) },
};
unk_80077D50 sPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aFullPortraitSilverNeelsenTex, TEX_WIDTH(aFullPortraitSilverNeelsenTex),
      TEX_HEIGHT(aFullPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aFullPortraitSilverNeelsenTex) },
};
unk_80077D50 sPortraitSuperArrowCompTexInfo[] = {
    { 17, aFullPortraitSuperArrowTex, TEX_WIDTH(aFullPortraitSuperArrowTex), TEX_HEIGHT(aFullPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitSuperArrowTex) },
};
unk_80077D50 sPortraitMrsArrowCompTexInfo[] = { { 17, aFullPortraitMrsArrowTex, TEX_WIDTH(aFullPortraitMrsArrowTex),
                                                  TEX_HEIGHT(aFullPortraitMrsArrowTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitMrsArrowTex) } };
unk_80077D50 sPortraitZodaCompTexInfo[] = { { 17, aFullPortraitZodaTex, TEX_WIDTH(aFullPortraitZodaTex),
                                              TEX_HEIGHT(aFullPortraitZodaTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitZodaTex) } };
unk_80077D50 sPortraitJohnTanakaCompTexInfo[] = {
    { 17, aFullPortraitJohnTanakaTex, TEX_WIDTH(aFullPortraitJohnTanakaTex), TEX_HEIGHT(aFullPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aFullPortraitJohnTanakaTex) },
};
unk_80077D50 sPortraitBioRexCompTexInfo[] = { { 17, aFullPortraitBioRexTex, TEX_WIDTH(aFullPortraitBioRexTex),
                                                TEX_HEIGHT(aFullPortraitBioRexTex),
                                                TEX_COMPRESSED_SIZE(aFullPortraitBioRexTex) } };
unk_80077D50 sPortraitKateAlenCompTexInfo[] = { { 17, aFullPortraitKateAlenTex, TEX_WIDTH(aFullPortraitKateAlenTex),
                                                  TEX_HEIGHT(aFullPortraitKateAlenTex),
                                                  TEX_COMPRESSED_SIZE(aFullPortraitKateAlenTex) } };
unk_80077D50 sPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aFullPortraitGomarAndShiohTex, TEX_WIDTH(aFullPortraitGomarAndShiohTex),
      TEX_HEIGHT(aFullPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aFullPortraitGomarAndShiohTex) },
};
unk_80077D50 sPortraitMichaelChainCompTexInfo[] = {
    { 17, aFullPortraitMichaelChainTex, TEX_WIDTH(aFullPortraitMichaelChainTex),
      TEX_HEIGHT(aFullPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aFullPortraitMichaelChainTex) },
};
unk_80077D50 sPortraitBillyCompTexInfo[] = { { 17, aFullPortraitBillyTex, TEX_WIDTH(aFullPortraitBillyTex),
                                               TEX_HEIGHT(aFullPortraitBillyTex),
                                               TEX_COMPRESSED_SIZE(aFullPortraitBillyTex) } };
unk_80077D50 sPortraitDrClashCompTexInfo[] = { { 17, aFullPortraitDrClashTex, TEX_WIDTH(aFullPortraitDrClashTex),
                                                 TEX_HEIGHT(aFullPortraitDrClashTex),
                                                 TEX_COMPRESSED_SIZE(aFullPortraitDrClashTex) } };
unk_80077D50 sPortraitJackLevinCompTexInfo[] = { { 17, aFullPortraitJackLevinTex, TEX_WIDTH(aFullPortraitJackLevinTex),
                                                   TEX_HEIGHT(aFullPortraitJackLevinTex),
                                                   TEX_COMPRESSED_SIZE(aFullPortraitJackLevinTex) } };
unk_80077D50 sPortraitBloodFalconCompTexInfo[] = {
    { 17, aFullPortraitBloodFalconTex, TEX_WIDTH(aFullPortraitBloodFalconTex), TEX_HEIGHT(aFullPortraitBloodFalconTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBloodFalconTex) },
};
unk_80077D50 sPortraitLeonCompTexInfo[] = { { 17, aFullPortraitLeonTex, TEX_WIDTH(aFullPortraitLeonTex),
                                              TEX_HEIGHT(aFullPortraitLeonTex),
                                              TEX_COMPRESSED_SIZE(aFullPortraitLeonTex) } };
unk_80077D50 sPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aFullPortraitJamesMcCloudTex, TEX_WIDTH(aFullPortraitJamesMcCloudTex),
      TEX_HEIGHT(aFullPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aFullPortraitJamesMcCloudTex) },
};
unk_80077D50 sPortraitBlackShadowCompTexInfo[] = {
    { 17, aFullPortraitBlackShadowTex, TEX_WIDTH(aFullPortraitBlackShadowTex), TEX_HEIGHT(aFullPortraitBlackShadowTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBlackShadowTex) },
};
unk_80077D50 sPortraitCaptainFalconAltCompTexInfo[] = {
    { 17, aFullPortraitCaptainFalconAltTex, TEX_WIDTH(aFullPortraitCaptainFalconAltTex),
      TEX_HEIGHT(aFullPortraitCaptainFalconAltTex), TEX_COMPRESSED_SIZE(aFullPortraitCaptainFalconAltTex) },
};
unk_80077D50 sPortraitSamuraiGorohAltCompTexInfo[] = {
    { 17, aFullPortraitSamuraiGorohAltTex, TEX_WIDTH(aFullPortraitSamuraiGorohAltTex),
      TEX_HEIGHT(aFullPortraitSamuraiGorohAltTex), TEX_COMPRESSED_SIZE(aFullPortraitSamuraiGorohAltTex) },
};
unk_80077D50 sPortraitJodySummerAltCompTexInfo[] = {
    { 17, aFullPortraitJodySummerAltTex, TEX_WIDTH(aFullPortraitJodySummerAltTex),
      TEX_HEIGHT(aFullPortraitJodySummerAltTex), TEX_COMPRESSED_SIZE(aFullPortraitJodySummerAltTex) },
};
unk_80077D50 sPortraitBackgroundCompTexInfo[] = {
    { 17, aFullPortraitBackgroundTex, TEX_WIDTH(aFullPortraitBackgroundTex), TEX_HEIGHT(aFullPortraitBackgroundTex),
      TEX_COMPRESSED_SIZE(aFullPortraitBackgroundTex) },
};

unk_80077D50* sPortraitCompTexInfos[] = {
    sPortraitCaptainFalconCompTexInfo,    // CAPTAIN_FALCON
    sPortraitDrStewartCompTexInfo,        // DR_STEWART
    sPortraitPicoCompTexInfo,             // PICO
    sPortraitSamuraiGorohCompTexInfo,     // SAMURAI_GOROH
    sPortraitJodySummerCompTexInfo,       // JODY_SUMMER
    sPortraitMightyGazelleCompTexInfo,    // MIGHTY_GAZELLE
    sPortraitMrEadCompTexInfo,            // MR_EAD
    sPortraitBabaCompTexInfo,             // BABA
    sPortraitOctomanCompTexInfo,          // OCTOMAN
    sPortraitGomarAndShiohCompTexInfo,    // GOMAR_AND_SHIOH
    sPortraitKateAlenCompTexInfo,         // KATE_ALEN
    sPortraitRogerBusterCompTexInfo,      // ROGER_BUSTER
    sPortraitJamesMcCloudCompTexInfo,     // JAMES_MCCLOUD
    sPortraitLeonCompTexInfo,             // LEON
    sPortraitAntonioGusterCompTexInfo,    // ANTONIO_GUSTER
    sPortraitBlackShadowCompTexInfo,      // BLACK_SHADOW
    sPortraitMichaelChainCompTexInfo,     // MICHAEL_CHAIN
    sPortraitJackLevinCompTexInfo,        // JACK_LEVIN
    sPortraitSuperArrowCompTexInfo,       // SUPER_ARROW
    sPortraitMrsArrowCompTexInfo,         // MRS_ARROW
    sPortraitJohnTanakaCompTexInfo,       // JOHN_TANAKA
    sPortraitBeastmanCompTexInfo,         // BEASTMAN
    sPortraitZodaCompTexInfo,             // ZODA
    sPortraitDrClashCompTexInfo,          // DR_CLASH
    sPortraitSilverNeelsenCompTexInfo,    // SILVER_NEELSEN
    sPortraitBioRexCompTexInfo,           // BIO_REX
    sPortraitDraqCompTexInfo,             // DRAQ
    sPortraitBillyCompTexInfo,            // BILLY
    sPortraitTheSkullCompTexInfo,         // THE_SKULL
    sPortraitBloodFalconCompTexInfo,      // BLOOD_FALCON
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sPortraitSamuraiGorohAltCompTexInfo,  // GOROH_ALT
    sPortraitJodySummerAltCompTexInfo,    // SUMMERS_ALT
};

unk_800792D8 D_i4_80075498[] = { { sPortraitDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754A8[] = { { sPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754B8[] = { { sPortraitJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754C8[] = { { sPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754D8[] = { { sPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754E8[] = { { sPortraitPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800754F8[] = { { sPortraitBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075508[] = { { sPortraitMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075518[] = { { sPortraitOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075528[] = { { sPortraitTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075538[] = { { sPortraitBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075548[] = { { sPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075558[] = { { sPortraitDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075568[] = { { sPortraitRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075578[] = { { sPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075588[] = { { sPortraitSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075598[] = { { sPortraitMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755A8[] = { { sPortraitZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755B8[] = { { sPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755C8[] = { { sPortraitBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755D8[] = { { sPortraitKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755E8[] = { { sPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800755F8[] = { { sPortraitMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075608[] = { { sPortraitBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075618[] = { { sPortraitDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075628[] = { { sPortraitJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075638[] = { { sPortraitBloodFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075648[] = { { sPortraitLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075658[] = { { sPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075668[] = { { sPortraitBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075678[] = { { sPortraitCaptainFalconAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075688[] = { { sPortraitSamuraiGorohAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075698[] = { { sPortraitJodySummerAltCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_800756A8[] = {
    D_i4_800754A8, D_i4_80075498, D_i4_800754E8, D_i4_800754C8, D_i4_800754B8, D_i4_800754D8, D_i4_80075508,
    D_i4_800754F8, D_i4_80075518, D_i4_800755E8, D_i4_800755D8, D_i4_80075568, D_i4_80075658, D_i4_80075648,
    D_i4_80075548, D_i4_80075668, D_i4_800755F8, D_i4_80075628, D_i4_80075588, D_i4_80075598, D_i4_800755B8,
    D_i4_80075538, D_i4_800755A8, D_i4_80075618, D_i4_80075578, D_i4_800755C8, D_i4_80075558, D_i4_80075608,
    D_i4_80075528, D_i4_80075638, D_i4_80075678, D_i4_80075678, D_i4_80075678, D_i4_80075688, D_i4_80075698,
};

static unk_80077D50 sSmallPortraitDrStewartCompTexInfo[] = {
    { 17, aSmallPortraitDrStewartTex, TEX_WIDTH(aSmallPortraitDrStewartTex), TEX_HEIGHT(aSmallPortraitDrStewartTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitDrStewartTex) },
};
static unk_80077D50 sSmallPortraitCaptainFalconCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconTex, TEX_WIDTH(aSmallPortraitCaptainFalconTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconTex) },
};
static unk_80077D50 sSmallPortraitJodySummerCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerTex, TEX_WIDTH(aSmallPortraitJodySummerTex), TEX_HEIGHT(aSmallPortraitJodySummerTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerTex) },
};
static unk_80077D50 sSmallPortraitSamuraiGorohCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohTex, TEX_WIDTH(aSmallPortraitSamuraiGorohTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohTex) },
};
static unk_80077D50 sSmallPortraitMightyGazelleCompTexInfo[] = {
    { 17, aSmallPortraitMightyGazelleTex, TEX_WIDTH(aSmallPortraitMightyGazelleTex),
      TEX_HEIGHT(aSmallPortraitMightyGazelleTex), TEX_COMPRESSED_SIZE(aSmallPortraitMightyGazelleTex) },
};
static unk_80077D50 sSmallPortraitPicoCompTexInfo[] = { { 17, aSmallPortraitPicoTex, TEX_WIDTH(aSmallPortraitPicoTex),
                                                          TEX_HEIGHT(aSmallPortraitPicoTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitPicoTex) } };
static unk_80077D50 sSmallPortraitBabaCompTexInfo[] = { { 17, aSmallPortraitBabaTex, TEX_WIDTH(aSmallPortraitBabaTex),
                                                          TEX_HEIGHT(aSmallPortraitBabaTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitBabaTex) } };
static unk_80077D50 sSmallPortraitMrEadCompTexInfo[] = {
    { 17, aSmallPortraitMrEadTex, TEX_WIDTH(aSmallPortraitMrEadTex), TEX_HEIGHT(aSmallPortraitMrEadTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitMrEadTex) }
};
static unk_80077D50 sSmallPortraitOctomanCompTexInfo[] = {
    { 17, aSmallPortraitOctomanTex, TEX_WIDTH(aSmallPortraitOctomanTex), TEX_HEIGHT(aSmallPortraitOctomanTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitOctomanTex) }
};
static unk_80077D50 sSmallPortraitTheSkullCompTexInfo[] = {
    { 17, aSmallPortraitTheSkullTex, TEX_WIDTH(aSmallPortraitTheSkullTex), TEX_HEIGHT(aSmallPortraitTheSkullTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitTheSkullTex) },
};
static unk_80077D50 sSmallPortraitBeastmanCompTexInfo[] = {
    { 17, aSmallPortraitBeastmanTex, TEX_WIDTH(aSmallPortraitBeastmanTex), TEX_HEIGHT(aSmallPortraitBeastmanTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBeastmanTex) },
};
static unk_80077D50 sSmallPortraitAntonioGusterCompTexInfo[] = {
    { 17, aSmallPortraitAntonioGusterTex, TEX_WIDTH(aSmallPortraitAntonioGusterTex),
      TEX_HEIGHT(aSmallPortraitAntonioGusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitAntonioGusterTex) },
};
static unk_80077D50 sSmallPortraitDraqCompTexInfo[] = { { 17, aSmallPortraitDraqTex, TEX_WIDTH(aSmallPortraitDraqTex),
                                                          TEX_HEIGHT(aSmallPortraitDraqTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitDraqTex) } };
static unk_80077D50 sSmallPortraitRogerBusterCompTexInfo[] = {
    { 17, aSmallPortraitRogerBusterTex, TEX_WIDTH(aSmallPortraitRogerBusterTex),
      TEX_HEIGHT(aSmallPortraitRogerBusterTex), TEX_COMPRESSED_SIZE(aSmallPortraitRogerBusterTex) },
};
static unk_80077D50 sSmallPortraitSilverNeelsenCompTexInfo[] = {
    { 17, aSmallPortraitSilverNeelsenTex, TEX_WIDTH(aSmallPortraitSilverNeelsenTex),
      TEX_HEIGHT(aSmallPortraitSilverNeelsenTex), TEX_COMPRESSED_SIZE(aSmallPortraitSilverNeelsenTex) },
};
static unk_80077D50 sSmallPortraitSuperArrowCompTexInfo[] = {
    { 17, aSmallPortraitSuperArrowTex, TEX_WIDTH(aSmallPortraitSuperArrowTex), TEX_HEIGHT(aSmallPortraitSuperArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitSuperArrowTex) },
};
static unk_80077D50 sSmallPortraitMrsArrowCompTexInfo[] = {
    { 17, aSmallPortraitMrsArrowTex, TEX_WIDTH(aSmallPortraitMrsArrowTex), TEX_HEIGHT(aSmallPortraitMrsArrowTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitMrsArrowTex) },
};
static unk_80077D50 sSmallPortraitZodaCompTexInfo[] = { { 17, aSmallPortraitZodaTex, TEX_WIDTH(aSmallPortraitZodaTex),
                                                          TEX_HEIGHT(aSmallPortraitZodaTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitZodaTex) } };
static unk_80077D50 sSmallPortraitJohnTanakaCompTexInfo[] = {
    { 17, aSmallPortraitJohnTanakaTex, TEX_WIDTH(aSmallPortraitJohnTanakaTex), TEX_HEIGHT(aSmallPortraitJohnTanakaTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJohnTanakaTex) },
};
static unk_80077D50 sSmallPortraitBioRexCompTexInfo[] = {
    { 17, aSmallPortraitBioRexTex, TEX_WIDTH(aSmallPortraitBioRexTex), TEX_HEIGHT(aSmallPortraitBioRexTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBioRexTex) }
};
static unk_80077D50 sSmallPortraitKateAlenCompTexInfo[] = {
    { 17, aSmallPortraitKateAlenTex, TEX_WIDTH(aSmallPortraitKateAlenTex), TEX_HEIGHT(aSmallPortraitKateAlenTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitKateAlenTex) },
};
static unk_80077D50 sSmallPortraitGomarAndShiohCompTexInfo[] = {
    { 17, aSmallPortraitGomarAndShiohTex, TEX_WIDTH(aSmallPortraitGomarAndShiohTex),
      TEX_HEIGHT(aSmallPortraitGomarAndShiohTex), TEX_COMPRESSED_SIZE(aSmallPortraitGomarAndShiohTex) },
};
static unk_80077D50 sSmallPortraitMichaelChainCompTexInfo[] = {
    { 17, aSmallPortraitMichaelChainTex, TEX_WIDTH(aSmallPortraitMichaelChainTex),
      TEX_HEIGHT(aSmallPortraitMichaelChainTex), TEX_COMPRESSED_SIZE(aSmallPortraitMichaelChainTex) },
};
static unk_80077D50 sSmallPortraitBillyCompTexInfo[] = {
    { 17, aSmallPortraitBillyTex, TEX_WIDTH(aSmallPortraitBillyTex), TEX_HEIGHT(aSmallPortraitBillyTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitBillyTex) }
};
static unk_80077D50 sSmallPortraitDrClashCompTexInfo[] = {
    { 17, aSmallPortraitDrClashTex, TEX_WIDTH(aSmallPortraitDrClashTex), TEX_HEIGHT(aSmallPortraitDrClashTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitDrClashTex) }
};
static unk_80077D50 sSmallPortraitJackLevinCompTexInfo[] = {
    { 17, aSmallPortraitJackLevinTex, TEX_WIDTH(aSmallPortraitJackLevinTex), TEX_HEIGHT(aSmallPortraitJackLevinTex),
      TEX_COMPRESSED_SIZE(aSmallPortraitJackLevinTex) },
};
static unk_80077D50 sSmallPortraitBloodFalconCompTexInfo[] = {
    { 17, aSmallPortraitBloodFalconTex, TEX_WIDTH(aSmallPortraitBloodFalconTex),
      TEX_HEIGHT(aSmallPortraitBloodFalconTex), TEX_COMPRESSED_SIZE(aSmallPortraitBloodFalconTex) },
};
static unk_80077D50 sSmallPortraitLeonCompTexInfo[] = { { 17, aSmallPortraitLeonTex, TEX_WIDTH(aSmallPortraitLeonTex),
                                                          TEX_HEIGHT(aSmallPortraitLeonTex),
                                                          TEX_COMPRESSED_SIZE(aSmallPortraitLeonTex) } };
static unk_80077D50 sSmallPortraitJamesMcCloudCompTexInfo[] = {
    { 17, aSmallPortraitJamesMcCloudTex, TEX_WIDTH(aSmallPortraitJamesMcCloudTex),
      TEX_HEIGHT(aSmallPortraitJamesMcCloudTex), TEX_COMPRESSED_SIZE(aSmallPortraitJamesMcCloudTex) },
};
static unk_80077D50 sSmallPortraitBlackShadowCompTexInfo[] = {
    { 17, aSmallPortraitBlackShadowTex, TEX_WIDTH(aSmallPortraitBlackShadowTex),
      TEX_HEIGHT(aSmallPortraitBlackShadowTex), TEX_COMPRESSED_SIZE(aSmallPortraitBlackShadowTex) },
};
static unk_80077D50 sSmallPortraitCaptainFalconAltCompTexInfo[] = {
    { 17, aSmallPortraitCaptainFalconAltTex, TEX_WIDTH(aSmallPortraitCaptainFalconAltTex),
      TEX_HEIGHT(aSmallPortraitCaptainFalconAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconAltTex) },
};
static unk_80077D50 sSmallPortraitSamuraiGorohAltCompTexInfo[] = {
    { 17, aSmallPortraitSamuraiGorohAltTex, TEX_WIDTH(aSmallPortraitSamuraiGorohAltTex),
      TEX_HEIGHT(aSmallPortraitSamuraiGorohAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohAltTex) },
};
static unk_80077D50 sSmallPortraitJodySummerAltCompTexInfo[] = {
    { 17, aSmallPortraitJodySummerAltTex, TEX_WIDTH(aSmallPortraitJodySummerAltTex),
      TEX_HEIGHT(aSmallPortraitJodySummerAltTex), TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerAltTex) },
};

unk_80077D50* sSmallPortraitCompTexInfos[] = {
    sSmallPortraitCaptainFalconCompTexInfo,    // CAPTAIN_FALCON
    sSmallPortraitDrStewartCompTexInfo,        // DR_STEWART
    sSmallPortraitPicoCompTexInfo,             // PICO
    sSmallPortraitSamuraiGorohCompTexInfo,     // SAMURAI_GOROH
    sSmallPortraitJodySummerCompTexInfo,       // JODY_SUMMER
    sSmallPortraitMightyGazelleCompTexInfo,    // MIGHTY_GAZELLE
    sSmallPortraitMrEadCompTexInfo,            // MR_EAD
    sSmallPortraitBabaCompTexInfo,             // BABA
    sSmallPortraitOctomanCompTexInfo,          // OCTOMAN
    sSmallPortraitGomarAndShiohCompTexInfo,    // GOMAR_AND_SHIOH
    sSmallPortraitKateAlenCompTexInfo,         // KATE_ALEN
    sSmallPortraitRogerBusterCompTexInfo,      // ROGER_BUSTER
    sSmallPortraitJamesMcCloudCompTexInfo,     // JAMES_MCCLOUD
    sSmallPortraitLeonCompTexInfo,             // LEON
    sSmallPortraitAntonioGusterCompTexInfo,    // ANTONIO_GUSTER
    sSmallPortraitBlackShadowCompTexInfo,      // BLACK_SHADOW
    sSmallPortraitMichaelChainCompTexInfo,     // MICHAEL_CHAIN
    sSmallPortraitJackLevinCompTexInfo,        // JACK_LEVIN
    sSmallPortraitSuperArrowCompTexInfo,       // SUPER_ARROW
    sSmallPortraitMrsArrowCompTexInfo,         // MRS_ARROW
    sSmallPortraitJohnTanakaCompTexInfo,       // JOHN_TANAKA
    sSmallPortraitBeastmanCompTexInfo,         // BEASTMAN
    sSmallPortraitZodaCompTexInfo,             // ZODA
    sSmallPortraitDrClashCompTexInfo,          // DR_CLASH
    sSmallPortraitSilverNeelsenCompTexInfo,    // SILVER_NEELSEN
    sSmallPortraitBioRexCompTexInfo,           // BIO_REX
    sSmallPortraitDraqCompTexInfo,             // DRAQ
    sSmallPortraitBillyCompTexInfo,            // BILLY
    sSmallPortraitTheSkullCompTexInfo,         // THE_SKULL
    sSmallPortraitBloodFalconCompTexInfo,      // BLOOD_FALCON
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitCaptainFalconAltCompTexInfo, // FALCON_ALT
    sSmallPortraitSamuraiGorohAltCompTexInfo,  // GOROH_ALT
    sSmallPortraitJodySummerAltCompTexInfo,    // SUMMERS_ALT
};

unk_800792D8 D_i4_800759D0[] = { { sSmallPortraitDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800759E0[] = { { sSmallPortraitCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_800759F0[] = { { sSmallPortraitJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A00[] = { { sSmallPortraitSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A10[] = { { sSmallPortraitMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A20[] = { { sSmallPortraitPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A30[] = { { sSmallPortraitBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A40[] = { { sSmallPortraitMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A50[] = { { sSmallPortraitOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A60[] = { { sSmallPortraitTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A70[] = { { sSmallPortraitBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A80[] = { { sSmallPortraitAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075A90[] = { { sSmallPortraitDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AA0[] = { { sSmallPortraitRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AB0[] = { { sSmallPortraitSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AC0[] = { { sSmallPortraitSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AD0[] = { { sSmallPortraitMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AE0[] = { { sSmallPortraitZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075AF0[] = { { sSmallPortraitJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B00[] = { { sSmallPortraitBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B10[] = { { sSmallPortraitKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B20[] = { { sSmallPortraitGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B30[] = { { sSmallPortraitMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B40[] = { { sSmallPortraitBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B50[] = { { sSmallPortraitDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B60[] = { { sSmallPortraitJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B70[] = { { sSmallPortraitBloodFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B80[] = { { sSmallPortraitLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075B90[] = { { sSmallPortraitJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075BA0[] = { { sSmallPortraitBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075BB0[] = { { sSmallPortraitCaptainFalconAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075BC0[] = { { sSmallPortraitSamuraiGorohAltCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075BD0[] = { { sSmallPortraitJodySummerAltCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_80075BE0[] = {
    D_i4_800759E0, D_i4_800759D0, D_i4_80075A20, D_i4_80075A00, D_i4_800759F0, D_i4_80075A10,
    D_i4_80075A40, D_i4_80075A30, D_i4_80075A50, D_i4_80075B20, D_i4_80075B10, D_i4_80075AA0,
    D_i4_80075B90, D_i4_80075B80, D_i4_80075A80, D_i4_80075BA0, D_i4_80075B30, D_i4_80075B60,
    D_i4_80075AC0, D_i4_80075AD0, D_i4_80075AF0, D_i4_80075A70, D_i4_80075AE0, D_i4_80075B50,
    D_i4_80075AB0, D_i4_80075B00, D_i4_80075A90, D_i4_80075B40, D_i4_80075A60, D_i4_80075B70,
    D_i4_80075BB0, D_i4_80075BB0, D_i4_80075BB0, D_i4_80075BC0, D_i4_80075BD0, D_i4_80075BB0,
};

unk_80077D50 sNameCardCaptainFalconCompTexInfo[] = {
    { 18, aNameCardCaptainFalconTex, TEX_WIDTH(aNameCardCaptainFalconTex), TEX_HEIGHT(aNameCardCaptainFalconTex),
      TEX_COMPRESSED_SIZE(aNameCardCaptainFalconTex) },
};
unk_80077D50 sNameCardDrStewartCompTexInfo[] = { { 18, aNameCardDrStewartTex, TEX_WIDTH(aNameCardDrStewartTex),
                                                   TEX_HEIGHT(aNameCardDrStewartTex),
                                                   TEX_COMPRESSED_SIZE(aNameCardDrStewartTex) } };
unk_80077D50 sNameCardPicoCompTexInfo[] = { { 18, aNameCardPicoTex, TEX_WIDTH(aNameCardPicoTex),
                                              TEX_HEIGHT(aNameCardPicoTex), TEX_COMPRESSED_SIZE(aNameCardPicoTex) } };
unk_80077D50 sNameCardSamuraiGorohCompTexInfo[] = { { 18, aNameCardSamuraiGorohTex, TEX_WIDTH(aNameCardSamuraiGorohTex),
                                                      TEX_HEIGHT(aNameCardSamuraiGorohTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardSamuraiGorohTex) } };
unk_80077D50 sNameCardJodySummerCompTexInfo[] = { { 18, aNameCardJodySummerTex, TEX_WIDTH(aNameCardJodySummerTex),
                                                    TEX_HEIGHT(aNameCardJodySummerTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardJodySummerTex) } };
unk_80077D50 sNameCardMrEadCompTexInfo[] = { { 18, aNameCardMrEadTex, TEX_WIDTH(aNameCardMrEadTex),
                                               TEX_HEIGHT(aNameCardMrEadTex),
                                               TEX_COMPRESSED_SIZE(aNameCardMrEadTex) } };
unk_80077D50 sNameCardBabaCompTexInfo[] = { { 18, aNameCardBabaTex, TEX_WIDTH(aNameCardBabaTex),
                                              TEX_HEIGHT(aNameCardBabaTex), TEX_COMPRESSED_SIZE(aNameCardBabaTex) } };
unk_80077D50 sNameCardOctomanCompTexInfo[] = { { 18, aNameCardOctomanTex, TEX_WIDTH(aNameCardOctomanTex),
                                                 TEX_HEIGHT(aNameCardOctomanTex),
                                                 TEX_COMPRESSED_SIZE(aNameCardOctomanTex) } };
unk_80077D50 sNameCardGomarAndShiohCompTexInfo[] = {
    { 18, aNameCardGomarAndShiohTex, TEX_WIDTH(aNameCardGomarAndShiohTex), TEX_HEIGHT(aNameCardGomarAndShiohTex),
      TEX_COMPRESSED_SIZE(aNameCardGomarAndShiohTex) },
};
unk_80077D50 sNameCardKateAlenCompTexInfo[] = { { 18, aNameCardKateAlenTex, TEX_WIDTH(aNameCardKateAlenTex),
                                                  TEX_HEIGHT(aNameCardKateAlenTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardKateAlenTex) } };
unk_80077D50 sNameCardRogerBusterCompTexInfo[] = { { 18, aNameCardRogerBusterTex, TEX_WIDTH(aNameCardRogerBusterTex),
                                                     TEX_HEIGHT(aNameCardRogerBusterTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardRogerBusterTex) } };
unk_80077D50 sNameCardJamesMcCloudCompTexInfo[] = { { 18, aNameCardJamesMcCloudTex, TEX_WIDTH(aNameCardJamesMcCloudTex),
                                                      TEX_HEIGHT(aNameCardJamesMcCloudTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardJamesMcCloudTex) } };
unk_80077D50 sNameCardLeonCompTexInfo[] = { { 18, aNameCardLeonTex, TEX_WIDTH(aNameCardLeonTex),
                                              TEX_HEIGHT(aNameCardLeonTex), TEX_COMPRESSED_SIZE(aNameCardLeonTex) } };
unk_80077D50 sNameCardAntonioGusterCompTexInfo[] = {
    { 18, aNameCardAntonioGusterTex, TEX_WIDTH(aNameCardAntonioGusterTex), TEX_HEIGHT(aNameCardAntonioGusterTex),
      TEX_COMPRESSED_SIZE(aNameCardAntonioGusterTex) },
};
unk_80077D50 sNameCardBlackShadowCompTexInfo[] = { { 18, aNameCardBlackShadowTex, TEX_WIDTH(aNameCardBlackShadowTex),
                                                     TEX_HEIGHT(aNameCardBlackShadowTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardBlackShadowTex) } };
unk_80077D50 sNameCardMichaelChainCompTexInfo[] = { { 18, aNameCardMichaelChainTex, TEX_WIDTH(aNameCardMichaelChainTex),
                                                      TEX_HEIGHT(aNameCardMichaelChainTex),
                                                      TEX_COMPRESSED_SIZE(aNameCardMichaelChainTex) } };
unk_80077D50 sNameCardJackLevinCompTexInfo[] = { { 18, aNameCardJackLevinTex, TEX_WIDTH(aNameCardJackLevinTex),
                                                   TEX_HEIGHT(aNameCardJackLevinTex),
                                                   TEX_COMPRESSED_SIZE(aNameCardJackLevinTex) } };
unk_80077D50 sNameCardSuperArrowCompTexInfo[] = { { 18, aNameCardSuperArrowTex, TEX_WIDTH(aNameCardSuperArrowTex),
                                                    TEX_HEIGHT(aNameCardSuperArrowTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardSuperArrowTex) } };
unk_80077D50 sNameCardMrsArrowCompTexInfo[] = { { 18, aNameCardMrsArrowTex, TEX_WIDTH(aNameCardMrsArrowTex),
                                                  TEX_HEIGHT(aNameCardMrsArrowTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardMrsArrowTex) } };
unk_80077D50 sNameCardJohnTanakaCompTexInfo[] = { { 18, aNameCardJohnTanakaTex, TEX_WIDTH(aNameCardJohnTanakaTex),
                                                    TEX_HEIGHT(aNameCardJohnTanakaTex),
                                                    TEX_COMPRESSED_SIZE(aNameCardJohnTanakaTex) } };
unk_80077D50 sNameCardBeastmanCompTexInfo[] = { { 18, aNameCardBeastmanTex, TEX_WIDTH(aNameCardBeastmanTex),
                                                  TEX_HEIGHT(aNameCardBeastmanTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardBeastmanTex) } };
unk_80077D50 sNameCardZodaCompTexInfo[] = { { 18, aNameCardZodaTex, TEX_WIDTH(aNameCardZodaTex),
                                              TEX_HEIGHT(aNameCardZodaTex), TEX_COMPRESSED_SIZE(aNameCardZodaTex) } };
unk_80077D50 sNameCardDrClashCompTexInfo[] = { { 18, aNameCardDrClashTex, TEX_WIDTH(aNameCardDrClashTex),
                                                 TEX_HEIGHT(aNameCardDrClashTex),
                                                 TEX_COMPRESSED_SIZE(aNameCardDrClashTex) } };
unk_80077D50 sNameCardSilverNeelsenCompTexInfo[] = {
    { 18, aNameCardSilverNeelsenTex, TEX_WIDTH(aNameCardSilverNeelsenTex), TEX_HEIGHT(aNameCardSilverNeelsenTex),
      TEX_COMPRESSED_SIZE(aNameCardSilverNeelsenTex) },
};
unk_80077D50 sNameCardBioRexCompTexInfo[] = { { 18, aNameCardBioRexTex, TEX_WIDTH(aNameCardBioRexTex),
                                                TEX_HEIGHT(aNameCardBioRexTex),
                                                TEX_COMPRESSED_SIZE(aNameCardBioRexTex) } };
unk_80077D50 sNameCardDraqCompTexInfo[] = { { 18, aNameCardDraqTex, TEX_WIDTH(aNameCardDraqTex),
                                              TEX_HEIGHT(aNameCardDraqTex), TEX_COMPRESSED_SIZE(aNameCardDraqTex) } };
unk_80077D50 sNameCardBillyCompTexInfo[] = { { 18, aNameCardBillyTex, TEX_WIDTH(aNameCardBillyTex),
                                               TEX_HEIGHT(aNameCardBillyTex),
                                               TEX_COMPRESSED_SIZE(aNameCardBillyTex) } };
unk_80077D50 sNameCardBloodFalconCompTexInfo[] = { { 18, aNameCardBloodFalconTex, TEX_WIDTH(aNameCardBloodFalconTex),
                                                     TEX_HEIGHT(aNameCardBloodFalconTex),
                                                     TEX_COMPRESSED_SIZE(aNameCardBloodFalconTex) } };
unk_80077D50 sNameCardMightyGazelleCompTexInfo[] = {
    { 18, aNameCardMightyGazelleTex, TEX_WIDTH(aNameCardMightyGazelleTex), TEX_HEIGHT(aNameCardMightyGazelleTex),
      TEX_COMPRESSED_SIZE(aNameCardMightyGazelleTex) },
};
unk_80077D50 sNameCardTheSkullCompTexInfo[] = { { 18, aNameCardTheSkullTex, TEX_WIDTH(aNameCardTheSkullTex),
                                                  TEX_HEIGHT(aNameCardTheSkullTex),
                                                  TEX_COMPRESSED_SIZE(aNameCardTheSkullTex) } };

unk_80077D50* sNameCardCompTexInfos[] = {
    sNameCardCaptainFalconCompTexInfo, // CAPTAIN_FALCON
    sNameCardDrStewartCompTexInfo,     // DR_STEWART
    sNameCardPicoCompTexInfo,          // PICO
    sNameCardSamuraiGorohCompTexInfo,  // SAMURAI_GOROH
    sNameCardJodySummerCompTexInfo,    // JODY_SUMMER
    sNameCardMightyGazelleCompTexInfo, // MIGHTY_GAZELLE
    sNameCardMrEadCompTexInfo,         // MR_EAD
    sNameCardBabaCompTexInfo,          // BABA
    sNameCardOctomanCompTexInfo,       // OCTOMAN
    sNameCardGomarAndShiohCompTexInfo, // GOMAR_AND_SHIOH
    sNameCardKateAlenCompTexInfo,      // KATE_ALEN
    sNameCardRogerBusterCompTexInfo,   // ROGER_BUSTER
    sNameCardJamesMcCloudCompTexInfo,  // JAMES_MCCLOUD
    sNameCardLeonCompTexInfo,          // LEON
    sNameCardAntonioGusterCompTexInfo, // ANTONIO_GUSTER
    sNameCardBlackShadowCompTexInfo,   // BLACK_SHADOW
    sNameCardMichaelChainCompTexInfo,  // MICHAEL_CHAIN
    sNameCardJackLevinCompTexInfo,     // JACK_LEVIN
    sNameCardSuperArrowCompTexInfo,    // SUPER_ARROW
    sNameCardMrsArrowCompTexInfo,      // MRS_ARROW
    sNameCardJohnTanakaCompTexInfo,    // JOHN_TANAKA
    sNameCardBeastmanCompTexInfo,      // BEASTMAN
    sNameCardZodaCompTexInfo,          // ZODA
    sNameCardDrClashCompTexInfo,       // DR_CLASH
    sNameCardSilverNeelsenCompTexInfo, // SILVER_NEELSEN
    sNameCardBioRexCompTexInfo,        // BIO_REX
    sNameCardDraqCompTexInfo,          // DRAQ
    sNameCardBillyCompTexInfo,         // BILLY
    sNameCardTheSkullCompTexInfo,      // THE_SKULL
    sNameCardBloodFalconCompTexInfo,   // BLOOD_FALCON
    sNameCardCaptainFalconCompTexInfo,
};

unk_800792D8 D_i4_80075ECC[] = { { sNameCardCaptainFalconCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075EDC[] = { { sNameCardDrStewartCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075EEC[] = { { sNameCardPicoCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075EFC[] = { { sNameCardSamuraiGorohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F0C[] = { { sNameCardJodySummerCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F1C[] = { { sNameCardMightyGazelleCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F2C[] = { { sNameCardMrEadCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F3C[] = { { sNameCardBabaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F4C[] = { { sNameCardOctomanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F5C[] = { { sNameCardGomarAndShiohCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F6C[] = { { sNameCardKateAlenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F7C[] = { { sNameCardRogerBusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F8C[] = { { sNameCardJamesMcCloudCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075F9C[] = { { sNameCardLeonCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FAC[] = { { sNameCardAntonioGusterCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FBC[] = { { sNameCardBlackShadowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FCC[] = { { sNameCardMichaelChainCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FDC[] = { { sNameCardJackLevinCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FEC[] = { { sNameCardSuperArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_80075FFC[] = { { sNameCardMrsArrowCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007600C[] = { { sNameCardJohnTanakaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007601C[] = { { sNameCardBeastmanCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007602C[] = { { sNameCardZodaCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007603C[] = { { sNameCardDrClashCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007604C[] = { { sNameCardSilverNeelsenCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007605C[] = { { sNameCardBioRexCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007606C[] = { { sNameCardDraqCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007607C[] = { { sNameCardBillyCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007608C[] = { { sNameCardTheSkullCompTexInfo, 60 }, { 0 } };
unk_800792D8 D_i4_8007609C[] = { { sNameCardBloodFalconCompTexInfo, 60 }, { 0 } };

unk_800792D8* D_i4_800760AC[] = {
    D_i4_80075ECC, D_i4_80075EDC, D_i4_80075EEC, D_i4_80075EFC, D_i4_80075F0C, D_i4_80075F1C, D_i4_80075F2C,
    D_i4_80075F3C, D_i4_80075F4C, D_i4_80075F5C, D_i4_80075F6C, D_i4_80075F7C, D_i4_80075F8C, D_i4_80075F9C,
    D_i4_80075FAC, D_i4_80075FBC, D_i4_80075FCC, D_i4_80075FDC, D_i4_80075FEC, D_i4_80075FFC, D_i4_8007600C,
    D_i4_8007601C, D_i4_8007602C, D_i4_8007603C, D_i4_8007604C, D_i4_8007605C, D_i4_8007606C, D_i4_8007607C,
    D_i4_8007608C, D_i4_8007609C, D_i4_80075ECC,
};

unk_80077D50 sSelectMachineCompTexInfo[] = { { 4, aSelectMachineTex, TEX_WIDTH(aSelectMachineTex),
                                               TEX_HEIGHT(aSelectMachineTex), 0 } };
unk_80077D50 s1PIconCompTexInfo[] = { { 17, a1PIconTex, TEX_WIDTH(a1PIconTex), TEX_HEIGHT(a1PIconTex),
                                        TEX_COMPRESSED_SIZE(a1PIconTex) } };
unk_80077D50 s2PIconCompTexInfo[] = { { 17, a2PIconTex, TEX_WIDTH(a2PIconTex), TEX_HEIGHT(a2PIconTex),
                                        TEX_COMPRESSED_SIZE(a2PIconTex) } };
unk_80077D50 s3PIconCompTexInfo[] = { { 17, a3PIconTex, TEX_WIDTH(a3PIconTex), TEX_HEIGHT(a3PIconTex),
                                        TEX_COMPRESSED_SIZE(a3PIconTex) } };
unk_80077D50 s4PIconCompTexInfo[] = { { 17, a4PIconTex, TEX_WIDTH(a4PIconTex), TEX_HEIGHT(a4PIconTex),
                                        TEX_COMPRESSED_SIZE(a4PIconTex) } };

unk_80077D50* sPlayerNumIconCompTexInfos[] = {
    s1PIconCompTexInfo,
    s2PIconCompTexInfo,
    s3PIconCompTexInfo,
    s4PIconCompTexInfo,
};

static unk_80077D50 sMachineSelectCursorCompTexInfo[] = {
    { 17, aMachineSelectCursorTex, TEX_WIDTH(aMachineSelectCursorTex), TEX_HEIGHT(aMachineSelectCursorTex),
      TEX_COMPRESSED_SIZE(aMachineSelectCursorTex) }
};
unk_80077D50 sMachineInfoGraphCompTexInfo[] = { { 17, aMachineInfoGraphTex, TEX_WIDTH(aMachineInfoGraphTex),
                                                  TEX_HEIGHT(aMachineInfoGraphTex),
                                                  TEX_COMPRESSED_SIZE(aMachineInfoGraphTex) } };
unk_80077D50 sMachineAccelerationMaxSpeedCompTexInfo[] = {
    { 17, aMachineAccelerationMaxSpeedTex, TEX_WIDTH(aMachineAccelerationMaxSpeedTex),
      TEX_HEIGHT(aMachineAccelerationMaxSpeedTex), TEX_COMPRESSED_SIZE(aMachineAccelerationMaxSpeedTex) },
};
unk_80077D50 sMachineBodyBoostGripCompTexInfo[] = { { 17, aMachineBodyBoostGripTex, TEX_WIDTH(aMachineBodyBoostGripTex),
                                                      TEX_HEIGHT(aMachineBodyBoostGripTex),
                                                      TEX_COMPRESSED_SIZE(aMachineBodyBoostGripTex) } };
unk_80077D50 sMachineInfoGraphSmallCompTexInfo[] = {
    { 18, aMachineInfoGraphSmallTex, TEX_WIDTH(aMachineInfoGraphSmallTex), TEX_HEIGHT(aMachineInfoGraphSmallTex),
      TEX_COMPRESSED_SIZE(aMachineInfoGraphSmallTex) },
};
unk_80077D50 sMachineAccelerationMaxSpeedSmallCompTexInfo[] = {
    { 18, aMachineAccelerationMaxSpeedSmallTex, TEX_WIDTH(aMachineAccelerationMaxSpeedSmallTex),
      TEX_HEIGHT(aMachineAccelerationMaxSpeedSmallTex), TEX_COMPRESSED_SIZE(aMachineAccelerationMaxSpeedSmallTex) },
};
unk_80077D50 sMachineBodyBoostGripSmallCompTexInfo[] = {
    { 17, aMachineBodyBoostGripSmallTex, TEX_WIDTH(aMachineBodyBoostGripSmallTex),
      TEX_HEIGHT(aMachineBodyBoostGripSmallTex), TEX_COMPRESSED_SIZE(aMachineBodyBoostGripSmallTex) },
};
unk_80077D50 sEngineSliderCompTexInfo[] = { { 17, aEngineSliderTex, TEX_WIDTH(aEngineSliderTex),
                                              TEX_HEIGHT(aEngineSliderTex), TEX_COMPRESSED_SIZE(aEngineSliderTex) } };
unk_80077D50 sNoviceJackTrophyCompTexInfo[] = { { 17, aNoviceJackTrophyTex, TEX_WIDTH(aNoviceJackTrophyTex),
                                                  TEX_HEIGHT(aNoviceJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aNoviceJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sNoviceQueenTrophyCompTexInfo[] = { { 17, aNoviceQueenTrophyTex, TEX_WIDTH(aNoviceQueenTrophyTex),
                                                   TEX_HEIGHT(aNoviceQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aNoviceQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sNoviceKingTrophyCompTexInfo[] = { { 17, aNoviceKingTrophyTex, TEX_WIDTH(aNoviceKingTrophyTex),
                                                  TEX_HEIGHT(aNoviceKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aNoviceKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sNoviceJokerTrophyCompTexInfo[] = { { 17, aNoviceJokerTrophyTex, TEX_WIDTH(aNoviceJokerTrophyTex),
                                                   TEX_HEIGHT(aNoviceJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aNoviceJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sNoviceXTrophyCompTexInfo[] = { { 17, aNoviceXTrophyTex, TEX_WIDTH(aNoviceXTrophyTex),
                                               TEX_HEIGHT(aNoviceXTrophyTex), TEX_COMPRESSED_SIZE(aNoviceXTrophyTex) },
                                             { 0 } };
unk_80077D50 sStandardJackTrophyCompTexInfo[] = { { 17, aStandardJackTrophyTex, TEX_WIDTH(aStandardJackTrophyTex),
                                                    TEX_HEIGHT(aStandardJackTrophyTex),
                                                    TEX_COMPRESSED_SIZE(aStandardJackTrophyTex) },
                                                  { 0 } };
unk_80077D50 sStandardQueenTrophyCompTexInfo[] = { { 17, aStandardQueenTrophyTex, TEX_WIDTH(aStandardQueenTrophyTex),
                                                     TEX_HEIGHT(aStandardQueenTrophyTex),
                                                     TEX_COMPRESSED_SIZE(aStandardQueenTrophyTex) },
                                                   { 0 } };
unk_80077D50 sStandardKingTrophyCompTexInfo[] = { { 17, aStandardKingTrophyTex, TEX_WIDTH(aStandardKingTrophyTex),
                                                    TEX_HEIGHT(aStandardKingTrophyTex),
                                                    TEX_COMPRESSED_SIZE(aStandardKingTrophyTex) },
                                                  { 0 } };
unk_80077D50 sStandardJokerTrophyCompTexInfo[] = { { 17, aStandardJokerTrophyTex, TEX_WIDTH(aStandardJokerTrophyTex),
                                                     TEX_HEIGHT(aStandardJokerTrophyTex),
                                                     TEX_COMPRESSED_SIZE(aStandardJokerTrophyTex) },
                                                   { 0 } };
unk_80077D50 sStandardXTrophyCompTexInfo[] = { { 17, aStandardXTrophyTex, TEX_WIDTH(aStandardXTrophyTex),
                                                 TEX_HEIGHT(aStandardXTrophyTex),
                                                 TEX_COMPRESSED_SIZE(aStandardXTrophyTex) },
                                               { 0 } };
unk_80077D50 sExpertJackTrophyCompTexInfo[] = { { 17, aExpertJackTrophyTex, TEX_WIDTH(aExpertJackTrophyTex),
                                                  TEX_HEIGHT(aExpertJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aExpertJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sExpertQueenTrophyCompTexInfo[] = { { 17, aExpertQueenTrophyTex, TEX_WIDTH(aExpertQueenTrophyTex),
                                                   TEX_HEIGHT(aExpertQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aExpertQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sExpertKingTrophyCompTexInfo[] = { { 17, aExpertKingTrophyTex, TEX_WIDTH(aExpertKingTrophyTex),
                                                  TEX_HEIGHT(aExpertKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aExpertKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sExpertJokerTrophyCompTexInfo[] = { { 17, aExpertJokerTrophyTex, TEX_WIDTH(aExpertJokerTrophyTex),
                                                   TEX_HEIGHT(aExpertJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aExpertJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sExpertXTrophyCompTexInfo[] = { { 17, aExpertXTrophyTex, TEX_WIDTH(aExpertXTrophyTex),
                                               TEX_HEIGHT(aExpertXTrophyTex), TEX_COMPRESSED_SIZE(aExpertXTrophyTex) },
                                             { 0 } };
unk_80077D50 sMasterJackTrophyCompTexInfo[] = { { 17, aMasterJackTrophyTex, TEX_WIDTH(aMasterJackTrophyTex),
                                                  TEX_HEIGHT(aMasterJackTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aMasterJackTrophyTex) },
                                                { 0 } };
unk_80077D50 sMasterQueenTrophyCompTexInfo[] = { { 17, aMasterQueenTrophyTex, TEX_WIDTH(aMasterQueenTrophyTex),
                                                   TEX_HEIGHT(aMasterQueenTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aMasterQueenTrophyTex) },
                                                 { 0 } };
unk_80077D50 sMasterKingTrophyCompTexInfo[] = { { 17, aMasterKingTrophyTex, TEX_WIDTH(aMasterKingTrophyTex),
                                                  TEX_HEIGHT(aMasterKingTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aMasterKingTrophyTex) },
                                                { 0 } };
unk_80077D50 sMasterJokerTrophyCompTexInfo[] = { { 17, aMasterJokerTrophyTex, TEX_WIDTH(aMasterJokerTrophyTex),
                                                   TEX_HEIGHT(aMasterJokerTrophyTex),
                                                   TEX_COMPRESSED_SIZE(aMasterJokerTrophyTex) },
                                                 { 0 } };
unk_80077D50 sMasterXTrophyCompTexInfo[] = { { 17, aMasterXTrophyTex, TEX_WIDTH(aMasterXTrophyTex),
                                               TEX_HEIGHT(aMasterXTrophyTex), TEX_COMPRESSED_SIZE(aMasterXTrophyTex) },
                                             { 0 } };
unk_80077D50 sNoTrophyCompTexInfo[] = {
    { 17, aNoTrophyTex, TEX_WIDTH(aNoTrophyTex), TEX_HEIGHT(aNoTrophyTex), TEX_COMPRESSED_SIZE(aNoTrophyTex) }, { 0 }
};

unk_80077D50 sNoviceDDTrophyCompTexInfo[] = { { 17, aNoviceDDTrophyTex, TEX_WIDTH(aNoviceDDTrophyTex),
                                                TEX_HEIGHT(aNoviceDDTrophyTex),
                                                TEX_COMPRESSED_SIZE(aNoviceDDTrophyTex) },
                                              { 0 } };

unk_80077D50 sStandardDDTrophyCompTexInfo[] = { { 17, aStandardDDTrophyTex, TEX_WIDTH(aStandardDDTrophyTex),
                                                  TEX_HEIGHT(aStandardDDTrophyTex),
                                                  TEX_COMPRESSED_SIZE(aStandardDDTrophyTex) },
                                                { 0 } };

unk_80077D50 sExpertDDTrophyCompTexInfo[] = { { 17, aExpertDDTrophyTex, TEX_WIDTH(aExpertDDTrophyTex),
                                                TEX_HEIGHT(aExpertDDTrophyTex),
                                                TEX_COMPRESSED_SIZE(aExpertDDTrophyTex) },
                                              { 0 } };

unk_80077D50 sMasterDDTrophyCompTexInfo[] = { { 17, aMasterDDTrophyTex, TEX_WIDTH(aMasterDDTrophyTex),
                                                TEX_HEIGHT(aMasterDDTrophyTex),
                                                TEX_COMPRESSED_SIZE(aMasterDDTrophyTex) },
                                              { 0 } };

unk_80077D50* sTrophyCompTexInfos[] = {
    sNoviceJackTrophyCompTexInfo,    sNoviceQueenTrophyCompTexInfo,  sNoviceKingTrophyCompTexInfo,
    sNoviceJokerTrophyCompTexInfo,   sNoviceXTrophyCompTexInfo,      sStandardJackTrophyCompTexInfo,
    sStandardQueenTrophyCompTexInfo, sStandardKingTrophyCompTexInfo, sStandardJokerTrophyCompTexInfo,
    sStandardXTrophyCompTexInfo,     sExpertJackTrophyCompTexInfo,   sExpertQueenTrophyCompTexInfo,
    sExpertKingTrophyCompTexInfo,    sExpertJokerTrophyCompTexInfo,  sExpertXTrophyCompTexInfo,
    sMasterJackTrophyCompTexInfo,    sMasterQueenTrophyCompTexInfo,  sMasterKingTrophyCompTexInfo,
    sMasterJokerTrophyCompTexInfo,   sMasterXTrophyCompTexInfo,      sNoTrophyCompTexInfo,
    sNoviceDDTrophyCompTexInfo,      sStandardDDTrophyCompTexInfo,   sExpertDDTrophyCompTexInfo,
    sMasterDDTrophyCompTexInfo,
};

static unk_80077D50 sNoviceCompTexInfo[] = { { 17, aNoviceTex, TEX_WIDTH(aNoviceTex), TEX_HEIGHT(aNoviceTex),
                                               TEX_COMPRESSED_SIZE(aNoviceTex) } };
static unk_80077D50 sStandardCompTexInfo[] = { { 17, aStandardTex, TEX_WIDTH(aStandardTex), TEX_HEIGHT(aStandardTex),
                                                 TEX_COMPRESSED_SIZE(aStandardTex) } };
static unk_80077D50 sExpertCompTexInfo[] = { { 17, aExpertTex, TEX_WIDTH(aExpertTex), TEX_HEIGHT(aExpertTex),
                                               TEX_COMPRESSED_SIZE(aExpertTex) } };
static unk_80077D50 sMasterCompTexInfo[] = { { 17, aMasterTex, TEX_WIDTH(aMasterTex), TEX_HEIGHT(aMasterTex),
                                               TEX_COMPRESSED_SIZE(aMasterTex) } };

static unk_80077D50* sDifficultyCompTexInfos[] = {
    sNoviceCompTexInfo,
    sStandardCompTexInfo,
    sExpertCompTexInfo,
    sMasterCompTexInfo,
};

static unk_80077D50 sBoostCompTexInfo[] = { { 17, aBoostTex, TEX_WIDTH(aBoostTex), TEX_HEIGHT(aBoostTex),
                                              TEX_COMPRESSED_SIZE(aBoostTex) } };
static unk_80077D50 sBodyCompTexInfo[] = { { 17, aBodyTex, TEX_WIDTH(aBodyTex), TEX_HEIGHT(aBodyTex),
                                             TEX_COMPRESSED_SIZE(aBodyTex) } };
static unk_80077D50 sGripCompTexInfo[] = { { 17, aGripTex, TEX_WIDTH(aGripTex), TEX_HEIGHT(aGripTex),
                                             TEX_COMPRESSED_SIZE(aGripTex) } };

static unk_80077D50* sMachineStatCompTexInfos[] = {
    sBodyCompTexInfo,
    sBoostCompTexInfo,
    sGripCompTexInfo,
};

static unk_80077D50 sOKCompTexInfo[] = { { 17, aOKTex, TEX_WIDTH(aOKTex), TEX_HEIGHT(aOKTex),
                                           TEX_COMPRESSED_SIZE(aOKTex) } };

static const char* sMachineStatValueStr[] = { "a", "b", "c", "d", "e" };

UNUSED s32 D_i4_8007663C[] = { 100, 218, 252, 221 };

s32 D_i4_8007664C = -4;
s32 D_i4_80076650 = 10;
s32 D_i4_80076654 = -6;
s32 D_i4_80076658 = 14;

UNUSED s32 D_i4_8007665C[] = { 0, 0, 0, 10, 0, 40 };
UNUSED f32 D_i4_80076674 = 1.2f;

s16 D_i4_80076678 = 60; // alpha

s32 D_i4_8007667C = 2600; // texture scale

s8 D_i4_80076680[] = { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

const s32 D_i4_80076F54[] = { -4, 0, -6, -24, 2, -1, 5, -25 };

const s32 D_i4_80076F74[] = { 19, 60, 19, 136, 299, 60, 299, 136, 42, 10, 42, 120 };

const s32 D_i4_80076FA4[] = { 25, 20, 25, 125, 164, 20, 164, 125 };

extern s16 D_8076C7A8;
extern s32 gSelectedMode;
extern s8 gPlayerSelectionLock[];
extern s32 gMachineSelectState;
extern s8 gSettingEverythingUnlocked;
extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;
extern s32 gNumPlayers;

void MachineSelect_Init(void) {
    s32 i;

    D_8076C7A8 = 3;
    D_8076E568 = D_8076E56C = D_8076E570 = 0.1f;
    Camera_Init();
    func_8071A358();
    gMachineSelectState = MACHINE_SELECT_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        sMachineSelectIndex[i] = Character_GetSlotFromCharacter(gRacers[i].character);
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
    Camera_Init();
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
extern u16 gInputPressed;
extern u16 gInputButtonPressed;

s32 MachineSelect_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 pad;
    s16 pad2;
    s16 lastMachineIndex;

    Camera_Update();

    for (i = 3; i >= 0; i--) {

        Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[i]]);
        if (i >= gNumPlayers) {
            if ((gInputButtonPressed & BTN_B) && (gMachineSelectState == MACHINE_SELECT_ACTIVE)) {
                Audio_TriggerSystemSE(NA_SE_16);
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
                Audio_TriggerSystemSE(NA_SE_23);
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
                gRacers[i].character = Character_GetCharacterFromSlot(sMachineSelectIndex[i]);

                if (lastMachineIndex != sMachineSelectIndex[i]) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_30);
                    D_8076CC7C[i] = 1;
                    gPlayerEngine[i] = 0.5f;
                }

                if (gInputButtonPressed & BTN_B) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);

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
                        Audio_PlayerTriggerSEStart(i, NA_SE_33);
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
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);
                    break;
                }
                if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_62);
                    gMachineSelectState = MACHINE_SELECT_CONTINUE;
                    return GAMEMODE_LX_MACHINE_SETTINGS;
                }
                break;
        }
    }
    return gGameMode;
}

extern s32 gTransitionState;

s32 MachineSettings_Update(void) {
    s32 i;
    s32 j;
    s32 k;
    Controller* temp_s1;
    f32 temp_fa0;
    f32 temp_fv0;
    f32 var_fa1;
    s32 stickX;

    Camera_Update();
    if (gTransitionState != TRANSITION_INACTIVE) {
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
                        Audio_PlayerTriggerSEStart(i, NA_SE_30);
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
                        Audio_PlayerTriggerSEStart(i, NA_SE_22);
                    }
                    if (gNumPlayers == 1) {
                        gCharacterLastEngine[gRacers[0].character] = gPlayerEngine[0];
                    }
                }
                if (gInputButtonPressed & BTN_B) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);

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
                    Audio_PlayerTriggerSEStart(i, NA_SE_33);
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
                    Audio_PlayerTriggerSEStart(i, NA_SE_16);
                } else if (gInputButtonPressed & (BTN_A | BTN_START)) {
                    Audio_PlayerTriggerSEStart(i, NA_SE_62);
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

extern CustomMachinesInfo gCustomMachinesInfo;

s32 MachineSettings_GetCharacter(s32 character) {

    if (gCustomMachinesInfo.characterCustomState[character] == -1) {
        character += 30;
        if (character >= 36) {
            character %= 30;
        }
    }
    return character;
}

void MachineSelect_HeaderInit(void) {
    func_i2_800AE17C(sSelectMachineCompTexInfo, 0, true);
}

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

void MachineSelect_CursorNumInit(Object* cursorNumObj) {
    func_i2_800AE17C(sPlayerNumIconCompTexInfos[cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0], 0, true);
}

void MachineSelect_CursorInit(void) {
    func_i2_800AE17C(sMachineSelectCursorCompTexInfo, 0, true);
}

void MachineSelect_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = (Vp*) Arena_Allocate(ALLOC_FRONT, 30 * sizeof(Vp));
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
        gRacers[j].segmentPositionInfo.pos.x = gRacers[j].segmentPositionInfo.pos.y =
            gRacers[j].segmentPositionInfo.pos.z = 0.0f;
        gRacers[j].trueBasis.x.z = 1.0f;
        gRacers[j].trueBasis.y.y = 1.0f;
        gRacers[j].trueBasis.z.x = 1.0f;
        gRacers[j].trueBasis.x.x = 0.0f;
        gRacers[j].trueBasis.y.z = 0.0f;
        gRacers[j].trueBasis.z.y = 0.0f;
        gRacers[j].trueBasis.x.y = 0.0f;
        gRacers[j].trueBasis.y.x = 0.0f;
        gRacers[j].trueBasis.z.z = 0.0f;
    }
}

void MachineSettings_MachineInit(Object* machineObj) {
    Vp* vp;
    s32 i;
    s32 j;
    s32 k;

    vp = (Vp*) Arena_Allocate(ALLOC_FRONT, 2 * 4 * sizeof(Vp));
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
        gRacers[k].segmentPositionInfo.pos.x = gRacers[k].segmentPositionInfo.pos.y =
            gRacers[k].segmentPositionInfo.pos.z = 0.0f;
        gRacers[k].trueBasis.x.z = 1.0f;
        gRacers[k].trueBasis.y.y = 1.0f;
        gRacers[k].trueBasis.z.x = 1.0f;
        gRacers[k].trueBasis.x.x = 0.0f;
        gRacers[k].trueBasis.y.z = 0.0f;
        gRacers[k].trueBasis.z.y = 0.0f;
        gRacers[k].trueBasis.x.y = 0.0f;
        gRacers[k].trueBasis.y.x = 0.0f;
        gRacers[k].trueBasis.z.z = 0.0f;
    }
}

void MachineSettings_EngineWeightInit(void) {
    if (gNumPlayers == 1) {
        func_i2_800AE17C(sMachineInfoGraphCompTexInfo, 0, true);
        func_i2_800AE17C(sMachineAccelerationMaxSpeedCompTexInfo, 0, true);
    } else {
        func_i2_800AE17C(sMachineInfoGraphSmallCompTexInfo, 0, true);
        func_i2_800AE17C(sMachineAccelerationMaxSpeedSmallCompTexInfo, 0, true);
    }
}

void MachineSettings_StatsInit(void) {
    if (gNumPlayers == 1) {
        func_i2_800AE17C(sMachineBodyBoostGripCompTexInfo, 0, true);
    } else {
        func_i2_800AE17C(sMachineBodyBoostGripSmallCompTexInfo, 0, true);
    }
}

void MachineSettings_NameCardInit(Object* nameCardObj) {
    if (gNumPlayers == 1) {
        OBJECT_CACHE_INDEX(nameCardObj) = func_i2_800AF9F8(D_i4_800760AC[0]);
    }
}

void MachineSettings_SliderInit(void) {
    func_i2_800AE17C(sEngineSliderCompTexInfo, 0, true);
}

void MachineSelect_DifficultyCupsInit(Object* difficultyCupsObj) {
    s32 i;

    OBJECT_BUFFER(difficultyCupsObj) = Arena_Allocate(ALLOC_FRONT, 4 * 30 * 7);

    Save_UpdateCupSave(OBJECT_BUFFER(difficultyCupsObj));

    for (i = 0; i < 21; i++) {
        func_i2_800AE17C(sTrophyCompTexInfos[i], 0, false);
    }

    for (i = 21; i < 25; i++) {
        func_i2_800AE578(sTrophyCompTexInfos[i], false);
    }

    for (i = 0; i < 4; i++) {
        func_i2_800AE17C(sDifficultyCompTexInfos[i], 0, true);
    }
}

void MachineSelect_StatsInit(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_i2_800AE17C(sMachineStatCompTexInfos[i], 0, true);
    }
}

void MachineSelect_OkInit(Object* okObj) {
    func_i2_800AE17C(sOKCompTexInfo, 0, true);
    OBJECT_TOP(okObj) = 50;
}

void MachineSettings_OkInit(Object* okObj) {
    func_i2_800AE17C(sOKCompTexInfo, 0, true);
    OBJECT_LEFT(okObj) = 50;
}

Gfx* MachineSelect_BackgroundDraw(Gfx* gfx) {
    s32 color;
    s32 i;
    s32 r, g, b;
    s32 temp_a1;
    s32 temp_t1 = 224;
    s32 rmul2 = 0;
    s32 gmul2 = 0;
    s32 bmul2 = 0;
    s32 rmul = 10;
    s32 gmul = 0;
    s32 bmul = 60;

    gDPSetCycleType(gfx++, G_CYC_FILL);

    for (i = 0; i < 224; i++) {
        s32 temp_t6 = 224;
        temp_a1 = temp_t6 - i;
        r = ((((rmul2 * temp_a1) + (rmul * i)) / temp_t1) >> 3);
        g = ((((gmul2 * temp_a1) + (gmul * i)) / temp_t1) >> 3);
        b = ((((bmul2 * temp_a1) + (bmul * i)) / temp_t1) >> 3);

        gDPPipeSync(gfx++);
        gDPSetFillColor(gfx++, PACK_5551(r, g, b, 1) << 0x10 | PACK_5551(r, g, b, 1));
        gDPFillRectangle(gfx++, 12, i + 8, 307, i + 8);
    }
    return gfx;
}

Gfx* MachineSelect_HeaderDraw(Gfx* gfx, Object* headerObj) {
    gDPSetPrimColor(gfx++, 0, 0, 250, 250, 0, 255);

    return func_i2_800AF584(gfx, sSelectMachineCompTexInfo, OBJECT_LEFT(headerObj), OBJECT_TOP(headerObj), 0, 0, 0,
                            1.0f, 1.0f, true);
}

Gfx* func_i4_80071054(Gfx* gfx, Object* arg1) {
    s32 i;
    const s32* var_s0;

    if (gNumPlayers == 1) {
        gfx = func_i2_800AF584(gfx, sPortraitCompTexInfos[gRacers[0].character], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0,
                               0, 0, 1.0f, 1.0f, true);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_80076FA4[i * 2];
            gfx = func_i2_800AF584(gfx, sSmallPortraitCompTexInfos[gRacers[i].character], var_s0[0], var_s0[1] + 55, 0,
                                   0, 0, 1.0f, 1.0f, true);
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
            gfx = func_i2_800AF584(gfx, sPortraitBackgroundCompTexInfo, OBJECT_LEFT(portraitObj),
                                   OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], OBJECT_LEFT(portraitObj),
                                   OBJECT_TOP(portraitObj), 0, 0, 0, 1.0f, 1.0f, true);
            break;
        case 2:
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], positions[0] - 4,
                                   positions[1] + 0x1A, 0, 0, 0, 1.0f, 1.0f, true);
            break;
        default:
            gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(portraitObj)], positions[0], positions[1] + 0x37,
                                   0, 0, 0, 1.0f, 1.0f, true);
            break;
    }
    return gfx;
}

extern Machine gMachines[];

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
            gfx = func_i2_800AF584(gfx, sMachineStatCompTexInfos[i], temp_fp, (temp_t0 - 7) + i * 20, 0, 0, 0, 1.0f,
                                   1.0f, true);
            temp_s0 = sMachineStatValueStr[temp_a3[i]];
            gfx = Font_DrawString(gfx, temp_fp + 5, (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    } else {
        for (i = 0; i < 3; i++) {
            gfx = func_i2_800AF584(gfx, sMachineStatCompTexInfos[i], temp_fp - 20, (temp_t0 - 7) + i * 20, 0, 0, 0,
                                   1.0f, 1.0f, true);
            temp_s0 = sMachineStatValueStr[temp_a3[i]];
            gfx = Font_DrawString(gfx, (temp_fp - Font_GetStringWidth(temp_s0, FONT_SET_2, 0)) - 5,
                                  (temp_t0 + 10) + i * 20, temp_s0, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

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
            if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex[i]] != 0) {
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

            gfx = func_i2_800AF584(gfx, sMachineSelectCursorCompTexInfo, OBJECT_LEFT(cursorObj), OBJECT_TOP(cursorObj),
                                   1, 0, 0, 1.0f, 1.0f, true);
        }
    }
    return gfx;
}

extern Camera gCameras[];
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* MachineSelect_MachineDraw(Gfx* gfx, Object* machineObj) {
    bool var_t0;
    s32 i;
    s32 j;

    gSPLoadUcodeL(gfx++, gspF3DEX2_Rej_fifo);
    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);

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
        gfx = func_8072DF40(gfx, Character_GetCharacterFromSlot(i), 0);
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

Gfx* MachineSettings_NameDraw(Gfx* gfx) {
    s32 i;
    const char* machineName;
    const s32* var_s0;
    s32 characterSlot;

    if (gNumPlayers == 1) {
        characterSlot = Character_GetSlotFromCharacter(gRacers[0].character);
        if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
            machineName = gCustomMachinesInfo.customMachines[characterSlot].machineName;
        } else {
            machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
        }
        gfx = Font_DrawString(gfx, 0x122 - Font_GetStringWidth(machineName, FONT_SET_1, 0), 0x22, machineName, 0,
                              FONT_SET_1, 0);
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            var_s0 = &D_i4_80076FA4[i * 2];
            characterSlot = Character_GetSlotFromCharacter(gRacers[i].character);
            if (gCustomMachinesInfo.characterCustomState[characterSlot] > 0) {
                machineName = gCustomMachinesInfo.customMachines[characterSlot].machineName;
            } else {
                machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[i].character)];
            }
            gfx = Font_DrawString(gfx, (var_s0[0] - Font_GetStringWidth(machineName, FONT_SET_2, 0)) + 0x82,
                                  var_s0[1] + 0xA, machineName, 0, FONT_SET_2, 0);
        }
    }
    return gfx;
}

Gfx* MachineSettings_MachineDraw(Gfx* gfx, Object* machineObj) {
    s32 i;

    gSPPerspNormalize(gfx++, gCameras[0].perspectiveScale);

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

    Light_SetLookAtSource(&gGfxPool->unk_33B28, &gCameras[0].viewMtx);
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
            gfx = func_i2_800AF584(gfx, sMachineAccelerationMaxSpeedSmallCompTexInfo, temp_s0 + 0x2B, temp_s1 + 0xA, 1,
                                   0, 0, 1.0f, 1.0f, true);
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
        gfx = func_i2_800AF584(gfx, sMachineBodyBoostGripCompTexInfo, OBJECT_LEFT(statsObj), OBJECT_TOP(statsObj), 0, 0,
                               0, 1.0f, 1.0f, true);

        for (i = 0; i < 3; i++) {
            temp = gMachines[gRacers[0].character].machineStats;
            gfx = Font_DrawMachineStatValue(gfx, OBJECT_LEFT(statsObj) + 0x69, OBJECT_TOP(statsObj) + i * 23 + 3,
                                            temp[i]);
        }
    } else {
        for (i = 0; i < gNumPlayers; i++) {
            leftOffset = D_i4_80076FA4[i * 2 + 0];
            topOffset = D_i4_80076FA4[i * 2 + 1];

            gfx = func_i2_800AF584(gfx, sMachineBodyBoostGripSmallCompTexInfo, leftOffset + 0x2B, topOffset + 0x39, 0,
                                   0, 0, 1.0f, 1.0f, true);

            for (j = 0; j < 3; j++) {
                temp = gMachines[gRacers[i].character].machineStats;
                gfx = Font_DrawString(gfx, leftOffset + 0x6B, topOffset + 0x43 + j * 14, sMachineStatValueStr[temp[j]],
                                      0, FONT_SET_2, 0);
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
            temp2 = sMachineStatValueStr[temp[j]];
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

    character = Character_GetCharacterFromSlot(sMachineSelectIndex[0]);
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

    var_t1 = OBJECT_BUFFER(difficultyCupsObj) + difficulty * (30 * 7) + character * 7;

    for (i = 0; i < cupsUnlocked; i++) {

        if (((s8*) var_t1)[i ^ 0] == 0) {
            // No trophy
            trophyIndex = 20;
        } else {
            trophyIndex = (difficulty * 5) + i;
        }

        gfx = func_i2_800AF584(gfx, sTrophyCompTexInfos[trophyIndex], 20, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f, false);
    }

    if (1) {}

    for (i = 0; i < 2; i++) {

        if (((s8*) var_t1)[(i ^ 0) + 5] == 0) {
            // No trophy
            trophyIndex = 20;
        } else {
            trophyIndex = difficulty + 21;
        }

        gfx = func_i2_800AF584(gfx, sTrophyCompTexInfos[trophyIndex], 284, 0x73 + i * 20, 0, 0, 0, 1.0f, 1.0f, false);
    }
    return func_i2_800AF584(gfx, sDifficultyCompTexInfos[difficulty], 30, 0xD1, 0, 0, 0, 1.0f, 1.0f, true);
}

Gfx* MachineSelect_NameDraw(Gfx* gfx, Object* nameObj) {
    s32 pad[2];
    const char* machineName;

    if (gCustomMachinesInfo.characterCustomState[sMachineSelectIndex[0]] > 0) {
        machineName = gCustomMachinesInfo.customMachines[sMachineSelectIndex[0]].machineName;
    } else {
        machineName = gMachineNames[MachineSettings_GetCharacter(gRacers[0].character)];
    }

    gfx = Font_DrawString(gfx, 160 - (Font_GetStringWidth(machineName, FONT_SET_2, 0) / 2), 218, machineName, 0,
                          FONT_SET_2, 0);
    gfx = Font_DrawMachineWeightSmall(gfx, 252, 221,
                                      gMachines[Character_GetCharacterFromSlot(sMachineSelectIndex[0])].weight);
    return Font_DrawString(gfx, 252, 221, "$", 0, FONT_SET_2, 0);
}

Gfx* MachineSettings_OkDraw(Gfx* gfx, Object* okObj) {
    gfx = func_8070D4A8(gfx, 0);
    return func_i2_800AF584(gfx, sOKCompTexInfo, OBJECT_LEFT(okObj) + 0x10B, OBJECT_TOP(okObj) + 0xD0, 1, 0, 0, 1.0f,
                            1.0f, true);
}

void func_i4_800732A0(Object* arg0) {
}

void MachineSettings_PortraitUpdate(Object* portraitObj) {
    s32 index = portraitObj->cmdId - OBJECT_MACHINE_SETTINGS_PORTRAIT_0;
    s32 character = gRacers[index].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        if (gNumPlayers == 1) {
            func_i2_800AFB1C(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_800756A8[character]);
        } else {
            func_i2_800AFB1C(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_80075BE0[character]);
        }
    }
    PORTRAIT_CHARACTER(portraitObj) = character;
}

void MachineSelect_PortraitUpdate(Object* portraitObj) {
    s32 playerIndex = portraitObj->cmdId - OBJECT_MACHINE_SELECT_PORTRAIT_0;
    s32 character = gRacers[playerIndex].character;

    character = MachineSettings_GetCharacter(character);
    if (character != PORTRAIT_CHARACTER(portraitObj)) {
        func_i2_800AFB1C(OBJECT_CACHE_INDEX(portraitObj), 0, D_i4_80075BE0[character]);
    }
    PORTRAIT_CHARACTER(portraitObj) = character;
}

void MachineSelect_CursorNumUpdate(Object* cursorNumObj) {
    s32 playerIndex = cursorNumObj->cmdId - OBJECT_MACHINE_SELECT_CURSOR_NUM_0;
    s32 temp_v1;

    temp_v1 = sMachineSelectIndex[playerIndex];
    OBJECT_LEFT(cursorNumObj) = ((temp_v1 % 6) * 0x28) + 0x28;
    OBJECT_TOP(cursorNumObj) = ((temp_v1 / 6) * 0x22) + 0x25;
}

void MachineSelect_CursorUpdate(Object* cursorObj) {
}

void MachineSelect_MachineUpdate(Object* machineObj) {
    Racer* var_s0;
    f32 var_fv0;
    s32 i;

    if (MACHINE_MINI_STATE(machineObj) == 1) {
        if (D_i4_80077058 >= 0) {
            D_i4_8007705C -= 0.05f;
        } else {
            D_i4_8007705C += 0.05f;
        }
        var_fv0 = D_i4_80077058;
        D_i4_80077058 += D_i4_8007705C;
        if ((var_fv0 * D_i4_80077058) < 0) {
            if (D_i4_8007705C < 0) {
                var_fv0 = 0 - D_i4_8007705C;
            } else {
                var_fv0 = D_i4_8007705C;
            }
            if (var_fv0 < 0.1f) {
                MACHINE_MINI_STATE(machineObj) = 2;
                D_8076E570 = 0.105f;
                D_8076E56C = 0.125f;
                D_8076E568 = 0.075f;
            }
        }
        D_i4_8007705C *= 0.98f;
        // TODO: figure out matching floats
        D_8076E570 = (D_i4_80077058 * -0.004999995f) + 0.105f;
        D_8076E56C = (D_i4_80077058 * -0.024999999f) + 0.125f;
        D_8076E568 = (D_i4_80077058 * 0.024999999f) + 0.075f;
    }

    i = 3;
    var_s0 = &gRacers[3];
    while (var_s0 >= &gRacers[0]) {
        if (var_s0 == &gRacers[0]) {
            var_fv0 = 0.03f;
        } else {
            var_fv0 = 0.0f;
        }
        var_s0->trueBasis.x.x += var_fv0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.x.y += var_fv0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.x.z += var_fv0 * var_s0->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&var_s0->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_32308[i], NULL, D_8076E568, D_8076E56C, D_8076E570, var_s0->trueBasis.x.x,
                               var_s0->trueBasis.x.y, var_s0->trueBasis.x.z, var_s0->trueBasis.y.x,
                               var_s0->trueBasis.y.y, var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        var_s0--;
        i--;
    }
}

void MachineSettings_MachineUpdate(Object* machineObj) {
    Racer* var_s0;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fv0;
    s32 i;
    s32 var_a1;
    Vp* var_v0;

    var_v0 = MACHINE_VIEWPORT(machineObj);
    for (var_a1 = 4; var_a1 < 8; var_a1++) {
        switch (gNumPlayers) {
            case 1:
                var_v0[var_a1].vp.vtrans[0] = (D_i4_8007664C + 0xDC) << 2;
                var_v0[var_a1].vp.vtrans[1] = (D_i4_80076650 + 0xC8) << 2;
                break;
            case 2:
                var_v0[var_a1].vp.vtrans[0] = (D_i4_80076654 + 0xE9) << 2;
                var_v0[var_a1].vp.vtrans[1] = (((var_a1 % 2) * 0x69) + D_i4_80076658 + 0x50) << 2;
                break;
            default:
                var_v0[var_a1].vp.vtrans[0] = ((((var_a1 - 4) / 2) * 0x8C) + 0x29) << 2;
                var_v0[var_a1].vp.vtrans[1] = ((((var_a1 - 4) % 2) * 0x69) + 0x3A) << 2;
                break;
        }
    }

    switch (gNumPlayers) {
        case 1:
            var_fs2 = 10.0f;
            break;
        case 2:
            var_fs2 = 12.0f;
            break;
        default:
            var_fs2 = 5.0f;
    }

    var_s0 = &gRacers[gNumPlayers - 1];
    i = gNumPlayers - 1;
    while (var_s0 >= gRacers) {
        var_fs0 = 0.0f;
        var_fs1 = 0.0f;
        var_fv0 = 0.0f;
        var_a1 = gControllers[gPlayerControlPorts[i]].buttonCurrent & (BTN_CUP | BTN_CDOWN | BTN_CLEFT | BTN_CRIGHT);
        switch (var_a1) {
            case 3:
            case 12:
            case 15:
                break;
            case 0:
                var_fv0 = 0.015f;
                break;
            default:
                if (var_a1 & BTN_CLEFT) {
                    var_fs0 = 0.03f;
                }
                if (var_a1 & BTN_CDOWN) {
                    var_fs1 = 0.03f;
                }
                if (var_a1 & BTN_CUP) {
                    var_fs1 = -0.03f;
                }
                if (var_a1 & BTN_CRIGHT) {
                    var_fs0 = -0.03f;
                }
                break;
        }

        var_s0->trueBasis.x.x += var_fv0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.x.y += var_fv0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.x.z += var_fv0 * var_s0->trueBasis.z.z;
        var_s0->trueBasis.x.x += var_fs1 * var_s0->trueBasis.y.x;
        var_s0->trueBasis.x.y += var_fs1 * var_s0->trueBasis.y.y;
        var_s0->trueBasis.x.z += var_fs1 * var_s0->trueBasis.y.z;
        var_s0->trueBasis.y.x += var_fs0 * var_s0->trueBasis.z.x;
        var_s0->trueBasis.y.y += var_fs0 * var_s0->trueBasis.z.y;
        var_s0->trueBasis.y.z += var_fs0 * var_s0->trueBasis.z.z;
        Math_OrthonormalizeAroundForward(&var_s0->trueBasis);
        Matrix_SetLockedLookAt(&gGfxPool->unk_32308[i], NULL, var_fs2 * D_8076E568, var_fs2 * D_8076E56C,
                               var_fs2 * D_8076E570, var_s0->trueBasis.x.x, var_s0->trueBasis.x.y,
                               var_s0->trueBasis.x.z, var_s0->trueBasis.y.x, var_s0->trueBasis.y.y,
                               var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        Matrix_SetLockedLookAt(&gGfxPool->unk_33208[i], NULL, (var_fs2 * 1.05f) * D_8076E568,
                               (var_fs2 * 1.05f) * D_8076E56C, (var_fs2 * 1.05f) * D_8076E570, var_s0->trueBasis.x.x,
                               var_s0->trueBasis.x.y, var_s0->trueBasis.x.z, var_s0->trueBasis.y.x,
                               var_s0->trueBasis.y.y, var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        Matrix_SetLockedLookAt(&gGfxPool->unk_32A88[i], NULL, var_fs2 * D_8076E568, var_fs2 * D_8076E56C,
                               var_fs2 * D_8076E570, var_s0->trueBasis.x.x, var_s0->trueBasis.x.y,
                               var_s0->trueBasis.x.z, var_s0->trueBasis.y.x, var_s0->trueBasis.y.y,
                               var_s0->trueBasis.y.z, var_s0->segmentPositionInfo.pos.x,
                               var_s0->segmentPositionInfo.pos.y, var_s0->segmentPositionInfo.pos.z);
        var_s0--;
        i--;
    }
}

void MachineSelect_OkUpdate(Object* okObj) {
    switch (gMachineSelectState) {
        case MACHINE_SELECT_AWAIT_OK:
        case MACHINE_SELECT_CONTINUE:
            Object_LerpPosYToClampedTarget(okObj, 0);
            break;
        default:
            Object_LerpPosYToClampedTarget(okObj, 50);
            break;
    }
}

void MachineSettings_OkUpdate(Object* okObj) {
    switch (gMachineSettingsState) {
        case MACHINE_SETTINGS_AWAIT_OK:
        case MACHINE_SETTINGS_CONTINUE:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 0, 192);
            break;
        default:
            Object_LerpPosXToClampedTargetMaxStep(okObj, 50, 192);
            break;
    }
}

void MachineSettings_NameCardUpdate(Object* nameCardObj) {

    if (NAME_CARD_CHARACTER(nameCardObj) != gRacers[0].character) {
        if (gNumPlayers == 1) {
            func_i2_800AFB1C(OBJECT_CACHE_INDEX(nameCardObj), 0, D_i4_800760AC[gRacers[0].character % 30]);
        }
    }
    NAME_CARD_CHARACTER(nameCardObj) = gRacers[0].character;
}

void func_i4_80073EA0(void) {
    if ((gQueuedGameMode == GAMEMODE_LX_MACHINE_SETTINGS) &&
        (MACHINE_MINI_STATE(Object_Get(OBJECT_MACHINE_SELECT_MACHINE)) != 0)) {
        D_8076E568 = 0.075f;
        D_8076E56C = 0.125f;
        D_8076E570 = 0.105f;
    } else {
        D_8076E568 = D_8076E56C = D_8076E570 = 0.1f;
    }
}
