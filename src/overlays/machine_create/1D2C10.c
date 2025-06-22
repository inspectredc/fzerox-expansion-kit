#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_font.h"
#include "fzx_machine.h"
#include "fzx_assets.h"

s32 D_xk3_801414C0;
s32 D_xk3_801414C4;
s32 D_xk3_801414C8;

unk_80077D50 D_xk3_80136830[] = { { 17, aSmallPortraitDrStewartTex, TEX_WIDTH(aSmallPortraitDrStewartTex),
                                    TEX_HEIGHT(aSmallPortraitDrStewartTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitDrStewartTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136850[] = { { 17, aSmallPortraitCaptainFalconTex, TEX_WIDTH(aSmallPortraitCaptainFalconTex),
                                    TEX_HEIGHT(aSmallPortraitCaptainFalconTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136870[] = { { 17, aSmallPortraitJodySummerTex, TEX_WIDTH(aSmallPortraitJodySummerTex),
                                    TEX_HEIGHT(aSmallPortraitJodySummerTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136890[] = { { 17, aSmallPortraitSamuraiGorohTex, TEX_WIDTH(aSmallPortraitSamuraiGorohTex),
                                    TEX_HEIGHT(aSmallPortraitSamuraiGorohTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801368B0[] = { { 17, aSmallPortraitMightyGazelleTex, TEX_WIDTH(aSmallPortraitMightyGazelleTex),
                                    TEX_HEIGHT(aSmallPortraitMightyGazelleTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitMightyGazelleTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801368D0[] = { { 17, aSmallPortraitPicoTex, TEX_WIDTH(aSmallPortraitPicoTex),
                                    TEX_HEIGHT(aSmallPortraitPicoTex), TEX_COMPRESSED_SIZE(aSmallPortraitPicoTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801368F0[] = { { 17, aSmallPortraitBabaTex, TEX_WIDTH(aSmallPortraitBabaTex),
                                    TEX_HEIGHT(aSmallPortraitBabaTex), TEX_COMPRESSED_SIZE(aSmallPortraitBabaTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136910[] = { { 17, aSmallPortraitMrEadTex, TEX_WIDTH(aSmallPortraitMrEadTex),
                                    TEX_HEIGHT(aSmallPortraitMrEadTex), TEX_COMPRESSED_SIZE(aSmallPortraitMrEadTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136930[] = { { 17, aSmallPortraitOctomanTex, TEX_WIDTH(aSmallPortraitOctomanTex),
                                    TEX_HEIGHT(aSmallPortraitOctomanTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitOctomanTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136950[] = { { 17, aSmallPortraitTheSkullTex, TEX_WIDTH(aSmallPortraitTheSkullTex),
                                    TEX_HEIGHT(aSmallPortraitTheSkullTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitTheSkullTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136970[] = { { 17, aSmallPortraitBeastmanTex, TEX_WIDTH(aSmallPortraitBeastmanTex),
                                    TEX_HEIGHT(aSmallPortraitBeastmanTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitBeastmanTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136990[] = { { 17, aSmallPortraitAntonioGusterTex, TEX_WIDTH(aSmallPortraitAntonioGusterTex),
                                    TEX_HEIGHT(aSmallPortraitAntonioGusterTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitAntonioGusterTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801369B0[] = { { 17, aSmallPortraitDraqTex, TEX_WIDTH(aSmallPortraitDraqTex),
                                    TEX_HEIGHT(aSmallPortraitDraqTex), TEX_COMPRESSED_SIZE(aSmallPortraitDraqTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801369D0[] = { { 17, aSmallPortraitRogerBusterTex, TEX_WIDTH(aSmallPortraitRogerBusterTex),
                                    TEX_HEIGHT(aSmallPortraitRogerBusterTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitRogerBusterTex) },
                                  { 0 } };
unk_80077D50 D_xk3_801369F0[] = { { 17, aSmallPortraitSilverNeelsenTex, TEX_WIDTH(aSmallPortraitSilverNeelsenTex),
                                    TEX_HEIGHT(aSmallPortraitSilverNeelsenTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitSilverNeelsenTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136A10[] = { { 17, aSmallPortraitSuperArrowTex, TEX_WIDTH(aSmallPortraitSuperArrowTex),
                                    TEX_HEIGHT(aSmallPortraitSuperArrowTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitSuperArrowTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136A30[] = { { 17, aSmallPortraitMrsArrowTex, TEX_WIDTH(aSmallPortraitMrsArrowTex),
                                    TEX_HEIGHT(aSmallPortraitMrsArrowTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitMrsArrowTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136A50[] = { { 17, aSmallPortraitZodaTex, TEX_WIDTH(aSmallPortraitZodaTex),
                                    TEX_HEIGHT(aSmallPortraitZodaTex), TEX_COMPRESSED_SIZE(aSmallPortraitZodaTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136A70[] = { { 17, aSmallPortraitJohnTanakaTex, TEX_WIDTH(aSmallPortraitJohnTanakaTex),
                                    TEX_HEIGHT(aSmallPortraitJohnTanakaTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitJohnTanakaTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136A90[] = { { 17, aSmallPortraitBioRexTex, TEX_WIDTH(aSmallPortraitBioRexTex),
                                    TEX_HEIGHT(aSmallPortraitBioRexTex), TEX_COMPRESSED_SIZE(aSmallPortraitBioRexTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136AB0[] = { { 17, aSmallPortraitKateAlenTex, TEX_WIDTH(aSmallPortraitKateAlenTex),
                                    TEX_HEIGHT(aSmallPortraitKateAlenTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitKateAlenTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136AD0[] = { { 17, aSmallPortraitGomarAndShiohTex, TEX_WIDTH(aSmallPortraitGomarAndShiohTex),
                                    TEX_HEIGHT(aSmallPortraitGomarAndShiohTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitGomarAndShiohTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136AF0[] = { { 17, aSmallPortraitMichaelChainTex, TEX_WIDTH(aSmallPortraitMichaelChainTex),
                                    TEX_HEIGHT(aSmallPortraitMichaelChainTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitMichaelChainTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136B10[] = { { 17, aSmallPortraitBillyTex, TEX_WIDTH(aSmallPortraitBillyTex),
                                    TEX_HEIGHT(aSmallPortraitBillyTex), TEX_COMPRESSED_SIZE(aSmallPortraitBillyTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136B30[] = { { 17, aSmallPortraitDrClashTex, TEX_WIDTH(aSmallPortraitDrClashTex),
                                    TEX_HEIGHT(aSmallPortraitDrClashTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitDrClashTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136B50[] = { { 17, aSmallPortraitJackLevinTex, TEX_WIDTH(aSmallPortraitJackLevinTex),
                                    TEX_HEIGHT(aSmallPortraitJackLevinTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitJackLevinTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136B70[] = { { 17, aSmallPortraitBloodFalconTex, TEX_WIDTH(aSmallPortraitBloodFalconTex),
                                    TEX_HEIGHT(aSmallPortraitBloodFalconTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitBloodFalconTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136B90[] = { { 17, aSmallPortraitLeonTex, TEX_WIDTH(aSmallPortraitLeonTex),
                                    TEX_HEIGHT(aSmallPortraitLeonTex), TEX_COMPRESSED_SIZE(aSmallPortraitLeonTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136BB0[] = { { 17, aSmallPortraitJamesMcCloudTex, TEX_WIDTH(aSmallPortraitJamesMcCloudTex),
                                    TEX_HEIGHT(aSmallPortraitJamesMcCloudTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitJamesMcCloudTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136BD0[] = { { 17, aSmallPortraitBlackShadowTex, TEX_WIDTH(aSmallPortraitBlackShadowTex),
                                    TEX_HEIGHT(aSmallPortraitBlackShadowTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitBlackShadowTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136BF0[] = { { 17, aSmallPortraitCaptainFalconAltTex, TEX_WIDTH(aSmallPortraitCaptainFalconAltTex),
                                    TEX_HEIGHT(aSmallPortraitCaptainFalconAltTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitCaptainFalconAltTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136C10[] = { { 17, aSmallPortraitSamuraiGorohAltTex, TEX_WIDTH(aSmallPortraitSamuraiGorohAltTex),
                                    TEX_HEIGHT(aSmallPortraitSamuraiGorohAltTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitSamuraiGorohAltTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136C30[] = { { 17, aSmallPortraitJodySummerAltTex, TEX_WIDTH(aSmallPortraitJodySummerAltTex),
                                    TEX_HEIGHT(aSmallPortraitJodySummerAltTex),
                                    TEX_COMPRESSED_SIZE(aSmallPortraitJodySummerAltTex) },
                                  { 0 } };

unk_800792D8 D_xk3_80136C50[] = { { D_xk3_80136830, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C60[] = { { D_xk3_80136850, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C70[] = { { D_xk3_80136870, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C80[] = { { D_xk3_80136890, 60 }, { 0 } };
unk_800792D8 D_xk3_80136C90[] = { { D_xk3_801368B0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CA0[] = { { D_xk3_801368D0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CB0[] = { { D_xk3_801368F0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CC0[] = { { D_xk3_80136910, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CD0[] = { { D_xk3_80136930, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CE0[] = { { D_xk3_80136950, 60 }, { 0 } };
unk_800792D8 D_xk3_80136CF0[] = { { D_xk3_80136970, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D00[] = { { D_xk3_80136990, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D10[] = { { D_xk3_801369B0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D20[] = { { D_xk3_801369D0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D30[] = { { D_xk3_801369F0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D40[] = { { D_xk3_80136A10, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D50[] = { { D_xk3_80136A30, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D60[] = { { D_xk3_80136A50, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D70[] = { { D_xk3_80136A70, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D80[] = { { D_xk3_80136A90, 60 }, { 0 } };
unk_800792D8 D_xk3_80136D90[] = { { D_xk3_80136AB0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DA0[] = { { D_xk3_80136AD0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DB0[] = { { D_xk3_80136AF0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DC0[] = { { D_xk3_80136B10, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DD0[] = { { D_xk3_80136B30, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DE0[] = { { D_xk3_80136B50, 60 }, { 0 } };
unk_800792D8 D_xk3_80136DF0[] = { { D_xk3_80136B70, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E00[] = { { D_xk3_80136B90, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E10[] = { { D_xk3_80136BB0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E20[] = { { D_xk3_80136BD0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E30[] = { { D_xk3_80136BF0, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E40[] = { { D_xk3_80136C10, 60 }, { 0 } };
unk_800792D8 D_xk3_80136E50[] = { { D_xk3_80136C30, 60 }, { 0 } };

unk_800792D8* D_xk3_80136E60[] = {
    D_xk3_80136C60, D_xk3_80136C50, D_xk3_80136CA0, D_xk3_80136C80, D_xk3_80136C70, D_xk3_80136C90,
    D_xk3_80136CC0, D_xk3_80136CB0, D_xk3_80136CD0, D_xk3_80136DA0, D_xk3_80136D90, D_xk3_80136D20,
    D_xk3_80136E10, D_xk3_80136E00, D_xk3_80136D00, D_xk3_80136E20, D_xk3_80136DB0, D_xk3_80136DE0,
    D_xk3_80136D40, D_xk3_80136D50, D_xk3_80136D70, D_xk3_80136CF0, D_xk3_80136D60, D_xk3_80136DD0,
    D_xk3_80136D30, D_xk3_80136D80, D_xk3_80136D10, D_xk3_80136DC0, D_xk3_80136CE0, D_xk3_80136DF0,
    D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E30, D_xk3_80136E40, D_xk3_80136E50, D_xk3_80136E30,
};

unk_80077D50 D_xk3_80136EF0[] = { { 17, aMachineSelectCursorTex, TEX_WIDTH(aMachineSelectCursorTex),
                                    TEX_HEIGHT(aMachineSelectCursorTex), TEX_COMPRESSED_SIZE(aMachineSelectCursorTex) },
                                  { 0 } };
unk_80077D50 D_xk3_80136F10[] = {
    { 17, aBoostTex, TEX_WIDTH(aBoostTex), TEX_HEIGHT(aBoostTex), TEX_COMPRESSED_SIZE(aBoostTex) }, { 0 }
};
unk_80077D50 D_xk3_80136F30[] = { { 17, aBodyTex, TEX_WIDTH(aBodyTex), TEX_HEIGHT(aBodyTex), 0x4E }, { 0 } };
unk_80077D50 D_xk3_80136F50[] = {
    { 17, aGripTex, TEX_WIDTH(aGripTex), TEX_HEIGHT(aGripTex), TEX_COMPRESSED_SIZE(aGripTex) }, { 0 }
};

unk_80077D50* D_xk3_80136F70[] = {
    D_xk3_80136F30,
    D_xk3_80136F10,
    D_xk3_80136F50,
};

const char* D_xk3_80136F7C[] = { "a", "b", "c", "d", "e" };

u8 D_xk3_80136F90 = 0;

extern s16 D_8076E5A8;
extern u8 D_800333F4;
extern u8 D_xk1_800333F0;
extern s8 gSettingEverythingUnlocked;

void func_xk3_80132F50(void) {
    func_807160A0();
    D_8076E5A8 = 1;
    func_8071EB18();
    if (D_xk1_800333F0 != 0) {
        D_xk3_801414C0 = D_800333F4;
    } else {
        D_xk3_801414C0 = 0;
    }
    D_xk3_801414C4 = ((func_8070DA54() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        D_xk3_801414C4 = 30;
    }
    if (D_xk3_801414C4 > 30) {
        D_xk3_801414C4 = 30;
    }
    func_80717294();
}

extern u16 gInputPressed;

void func_xk3_80133014(void) {
    s32 temp_a2;

    Controller_SetGlobalInputs(&gControllers[gPlayerControlPorts[0]]);
    temp_a2 = D_xk3_801414C0;

    if (D_xk1_800333F0 != 0) {
        if (D_xk3_801414C0 == 30) {
            if ((gInputPressed & BTN_DOWN) || (gInputPressed & BTN_LEFT)) {
                D_xk3_801414C0 = D_800333F4;
                D_xk3_80136F90 = 0;
            }
        } else if ((gInputPressed & BTN_UP) || (gInputPressed & BTN_RIGHT)) {
            D_xk3_801414C0 = 30;
        }
    } else if (D_xk3_801414C0 == 30) {
        if (gInputPressed & BTN_UP) {
            D_xk3_801414C0 = D_xk3_801414C4 - 1;
            D_xk3_80136F90 = 0;

        } else if ((gInputPressed & BTN_DOWN) && (gInputPressed & BTN_LEFT)) {
            D_xk3_801414C0 = 4;
            D_xk3_80136F90 = 0;
        } else if (gInputPressed & BTN_DOWN) {
            D_xk3_801414C0 = 5;
            D_xk3_80136F90 = 0;
        }
    } else {
        if (gInputPressed & BTN_LEFT) {
            if ((D_xk3_801414C0 % 6) != 0) {
                D_xk3_801414C0--;
            } else {
                D_xk3_801414C0 += 5;
            }
        } else if (gInputPressed & BTN_RIGHT) {
            if ((D_xk3_801414C0 % 6) < 5) {
                D_xk3_801414C0++;
            } else {
                D_xk3_801414C0 -= 5;
            }
        }
        if (gInputPressed & BTN_UP) {
            if (D_xk3_801414C0 == 5) {
                D_xk3_801414C0 = 30;
            } else {
                D_xk3_801414C0 -= 6;
            }
        } else if (gInputPressed & BTN_DOWN) {
            if (D_xk3_801414C0 == D_xk3_801414C4 - 1) {
                D_xk3_801414C0 = 30;
            } else if (D_xk3_801414C0 == 24) {
                D_xk3_801414C0 = 0;
            } else {
                D_xk3_801414C0 += 6;
            }
        }
        if (D_xk3_801414C0 != 30) {
            D_xk3_801414C0 += D_xk3_801414C4;
            D_xk3_801414C0 %= D_xk3_801414C4;
        }
    }
    if (temp_a2 != D_xk3_801414C0) {
        func_8074122C(0x1E);
    }
}

extern s16 D_8076E5A8;
extern u8 D_xk3_80141290;
extern u8 D_xk3_80141291;
extern u8 D_xk3_80140750[];
extern unk_806F2400 D_xk3_80140E90;
extern unk_806F2400 D_806F2400;
extern s32 D_xk3_80136820;
extern unk_806F2400_unk_00 D_xk1_800333D0;
extern unk_806F2400_unk_00 D_xk3_801365E0;
extern unk_806F2400_unk_00 D_xk3_80141270;

void func_xk3_801332B4(void) {
    u8 i;

    if (D_xk3_801414C0 == 30) {
        for (i = 0; i < 30; i++) {
            if (D_806F2400.unk_3C0[i] == 1) {
                D_806F2400.unk_3C0[i] = 2;
                break;
            }
        }
        D_8076E5A8 = 0;
        D_xk3_80136F90 = 0;
        PRINTF("WORKS MACHINE MODE : 0\n");
        D_xk3_80136820 = 0;
        func_8074122C(0x24);
        D_xk1_800333D0 = D_xk3_80141270;
        D_xk1_800333F0 = D_xk3_80141290;
        D_800333F4 = D_xk3_80141291;
        func_xk3_8012D700();
    } else {
        D_xk3_80140E90 = D_806F2400;

        if (D_xk1_800333F0 != 0) {
            D_806F2400.unk_3C0[D_xk3_801414C0] = -1;
            func_8071E0C0();
        } else {
            D_xk3_801365E0 = D_xk1_800333D0;

            for (i = 0; i < 30; i++) {
                if (D_806F2400.unk_3C0[i] == 1) {
                    D_806F2400.unk_3C0[i] = 0;
                    D_806F2400.unk_00[i].number = 31;
                    func_8071E0C0();
                    break;
                }
            }
            D_806F2400.unk_3C0[D_xk3_801414C0] = 1;
            D_xk1_800333D0.number = D_xk3_80140750[D_xk3_801414C0];
            D_806F2400.unk_00[D_xk3_801414C0] = D_xk1_800333D0;
        }
        func_8074122C(0x27);
        D_xk3_801414C8 = D_xk3_801414C0;
        D_xk3_801414C0 = 30;
        D_xk3_80136F90 = 1;
    }
}

void func_xk3_8013358C(void) {

    if (D_xk3_801414C0 < 30) {
        if (D_806F2400.unk_3C0[D_xk3_801414C0] == 0) {
            return;
        }

        D_xk3_80140E90 = D_806F2400;

        if (D_xk1_800333F0 == 0) {
            D_xk3_801365E0 = D_xk1_800333D0;
            if (D_806F2400.unk_3C0[D_xk3_801414C0] == 1) {
                if (1) {}
                D_xk1_800333D0.number = 31;
            }
        }
        D_806F2400.unk_3C0[D_xk3_801414C0] = 0;
        D_806F2400.unk_00[D_xk3_801414C0].number = 31;
        D_xk3_801414C8 = D_xk3_801414C0;
        D_xk3_801414C0 = 30;
        D_xk3_80136F90 = 1;
    } else if (D_xk3_801414C0 == 30) {
        if (D_xk3_80136F90 == 0) {
            return;
        }
        if (D_xk3_80136F90 == 1) {
            D_xk3_80136F90 = 0;
            D_806F2400 = D_xk3_80140E90;
            if (D_xk1_800333F0 == 0) {
                D_xk1_800333D0 = D_xk3_801365E0;
            }
            D_xk3_801414C0 = D_xk3_801414C8;
        }
    }
    func_8074122C(0x25);
    func_8071E0C0();
}

extern s32 D_xk3_801414C0;

void func_xk3_801337A0(void) {

    func_80717294();
    func_xk3_80133014();

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        func_xk3_801332B4();
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        func_xk3_8013358C();
    }
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        D_xk3_801414C0 = 30;
    }
}

extern u16 D_7004900[];
extern u8 D_xk3_80139430[];
extern u8 D_xk3_801395F0[];
extern u16 D_xk3_8013A180[];
extern u16 D_xk3_8013A580[];
extern u16 D_xk3_8013C180[];
extern u16 D_xk3_8013C340[];
extern Gfx D_xk3_80137378[];
extern Gfx D_xk3_801373F0[];

Gfx* func_xk3_8013387C(Gfx* gfx) {

    gfx = Object_UpdateAndDrawAll(gfx);
    func_i2_800AF7E0();
    gSPDisplayList(gfx++, D_xk3_80137378);

    if (D_xk3_801414C0 == 30) {
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A580, 244, 18, 32, 16);
    } else {
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A180, 244, 18, 32, 16);
        if (D_806F2400.unk_3C0[D_xk3_801414C0] > 0) {
            gfx = func_xk3_8012E120(gfx, D_xk3_8013C180, 70, 19, 28, 8);
        } else if (D_806F2400.unk_3C0[D_xk3_801414C0] < 0) {
            gfx = func_xk3_8012E120(gfx, D_xk3_8013C340, 70, 19, 36, 8);
        }
    }

    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPLoadTextureBlock(gfx++, D_7004900, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 120 << 2, 212 << 2, (120 + 16 - 1) << 2, (212 + 16 - 1) << 2, 0, 0, 0, 4 * (1 << 10),
                        1 << 10);
    gSPTextureRectangle(gfx++, 214 << 2, 212 << 2, (214 + 16 - 1) << 2, (212 + 16 - 1) << 2, 0, 0, 16 << 5,
                        4 * (1 << 10), 1 << 10);

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk3_8012E740(gfx, D_xk3_80139430, 140, 216, 56, 8);
    gfx = func_xk3_8012E740(gfx, D_xk3_801395F0, 234, 216, 48, 8);

    return gfx;
}

void func_xk3_80133B4C(Object* arg0) {
    OBJECT_CACHE_INDEX(arg0) = func_i2_800AF9F8(D_xk3_80136E60[0]);
    OBJECT_STATE(arg0) = -1;
}

extern unk_80077D50* D_xk3_80136F70[];

void func_xk3_80133B84(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        func_i2_800AE17C(D_xk3_80136F70[i], 0, false);
    }
}

void func_xk3_80133BD4(Object* arg0) {
    Vp* vp;
    s32 i;
    s32 j;

    vp = func_807084E4(0, 30 * sizeof(Vp));
    MACHINE_VIEWPORT(arg0) = vp;
    for (i = 0; i < 30; i++) {
        vp[i].vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
        vp[i].vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
        vp[i].vp.vscale[2] = 0x1FF;
        vp[i].vp.vscale[3] = 0;
        vp[i].vp.vtrans[0] = (((i % 6) * 0x28) + 0x3B) << 2;
        vp[i].vp.vtrans[1] = (((i / 6) * 0x22) + 0x3B) << 2;
        vp[i].vp.vtrans[2] = 0x1FF;
        vp[i].vp.vtrans[3] = 0;
    }

    for (j = 1; j >= 0; j--) {
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

extern unk_80077D50 D_xk3_80136EF0[];

void func_xk3_80133F40(void) {
    func_i2_800AE17C(D_xk3_80136EF0, 0, false);
}

extern const char* gMachineNames[];
extern unk_800E3F28 D_800D63F8[];
extern const char* D_xk3_801366F4[];

Gfx* func_xk3_80133F6C(Gfx* gfx, Object* arg1) {

    if (D_xk3_80136820 != 0x1C) {
        return gfx;
    }
    if (D_xk3_801414C0 < 30) {
        gfx = func_i2_800AF678(gfx, &D_800D63F8[OBJECT_CACHE_INDEX(arg1)], OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0, 0,
                               1.0f, 1.0f, 0);
        if (D_806F2400.unk_3C0[D_xk3_801414C0] > 0) {
            gfx = Font_DrawString(gfx, 0x46, 0x25, D_806F2400.unk_00[D_xk3_801414C0].machineName, 0, 2, 0);
        } else if (D_806F2400.unk_3C0[D_xk3_801414C0] < 0) {
            gfx = Font_DrawString(gfx, 0x46, 0x25, D_xk3_801366F4[D_xk3_801414C0], 0, 2, 0);
        } else {
            gfx = Font_DrawString(gfx, 0x46, 0x25, gMachineNames[func_8070DBE0(D_xk3_801414C0)], 0, 2, 0);
        }
    }
    return gfx;
}

extern const char* D_xk3_80136F7C[];
extern u8 D_xk3_801407B0[][3];
extern Machine gMachines[];

Gfx* func_xk3_801340DC(Gfx* gfx, Object* arg1) {
    s32 pad;
    s32 var_s6;
    s32 i;
    s8* temp_s7;
    char* sp7C;

    if (D_xk3_80136820 != 0x1C) {
        return gfx;
    }

    if (D_xk3_801414C0 < 30) {
        temp_s7 = gMachines[func_8070DBE0(D_xk3_801414C0)].machineStats;

        var_s6 = 53;
        for (i = 0; i < 3; i++) {
            gfx = func_i2_800AF584(gfx, D_xk3_80136F70[i], 19, var_s6 + i * 20, 0, 0, 0, 1.0f, 1.0f, 0);

            if (D_806F2400.unk_3C0[D_xk3_801414C0] > 0) {
                switch (i) {
                    case 0:
                        func_xk3_801353F8(&sp7C, D_806F2400.unk_00[D_xk3_801414C0].body);
                        break;
                    case 1:
                        func_xk3_801353F8(&sp7C, D_806F2400.unk_00[D_xk3_801414C0].boost);
                        break;
                    case 2:
                        func_xk3_801353F8(&sp7C, D_806F2400.unk_00[D_xk3_801414C0].grip);
                        break;
                }
            } else if (D_806F2400.unk_3C0[D_xk3_801414C0] < 0) {
                func_xk3_801353F8(&sp7C, D_xk3_801407B0[D_xk3_801414C0][i]);
            } else {
                sp7C = D_xk3_80136F7C[temp_s7[i]];
            }
            gfx = Font_DrawString(gfx, 24, 70 + i * 20, sp7C, 0, 2, 0);
        }
    }
    return gfx;
}

Gfx* func_xk3_8013430C(Gfx* gfx, s32 arg1) {

    gfx = Machine_DrawLoadCustomTextures(gfx, D_806F2400.unk_00[arg1].logo - 1, D_806F2400.unk_00[arg1].number - 1,
                                         D_806F2400.unk_00[arg1].decal - 1);
    gDPSetEnvColor(gfx++, D_806F2400.unk_00[arg1].red, D_806F2400.unk_00[arg1].green, D_806F2400.unk_00[arg1].blue,
                   255);

    gfx = Machine_DrawCustom(
        gfx, 0, D_806F2400.unk_00[arg1].frontType, D_806F2400.unk_00[arg1].rearType, D_806F2400.unk_00[arg1].wingType,
        D_806F2400.unk_00[arg1].decalR, D_806F2400.unk_00[arg1].decalG, D_806F2400.unk_00[arg1].decalB,
        D_806F2400.unk_00[arg1].numberR, D_806F2400.unk_00[arg1].numberG, D_806F2400.unk_00[arg1].numberB, 255, 255,
        255, D_806F2400.unk_00[arg1].cockpitR, D_806F2400.unk_00[arg1].cockpitG, D_806F2400.unk_00[arg1].cockpitB);

    return gfx;
}

extern Player gPlayers[];
extern GfxPool D_1000000;
extern GfxPool* gGfxPool;

Gfx* func_xk3_80134408(Gfx* gfx, Object* arg1) {
    s32 i;

    if (D_xk3_80136820 != 0x1C) {
        return gfx;
    }
    gSPLoadUcodeL(gfx++, gspF3DEX_Rej_fifo);
    gfx = Segment_SetTableAddresses(gfx);
    gSPClipRatio(gfx++, FRUSTRATIO_3);

    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);

    gSPMatrix(gfx++, &D_1000000.unk_1A208[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gfx++, D_303A5F8);

    gSPLight(gfx++, &D_1000000.unk_33A88[0].l[0], 1);
    gSPLight(gfx++, &D_1000000.unk_33A88[0].a, 2);
    gSPNumLights(gfx++, NUMLIGHTS_1);
    Lights_SetSource(gGfxPool->unk_33A88, 0, 0, 0, 255, 255, 255, 100, 50, 69);
    Lights_SetSource(&gGfxPool->unk_33A88[1], 0, 0, 0, 100, 70, 70, 100, 50, 69);

    for (i = 0; i < 30; i++) {

        if (i < D_xk3_801414C4) {
            gSPLight(gfx++, &D_1000000.unk_33A88[0].l[0], 1);
            gSPLight(gfx++, &D_1000000.unk_33A88[0].a, 2);
        } else {
            gSPLight(gfx++, &D_1000000.unk_33A88[1].l[0], 1);
            gSPLight(gfx++, &D_1000000.unk_33A88[1].a, 2);
        }

        gSPViewport(gfx++, MACHINE_VIEWPORT(arg1) + i);

        if (i == D_xk3_801414C0) {
            gSPMatrix(gfx++, &D_1000000.unk_32308[0], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        } else {
            gSPMatrix(gfx++, &D_1000000.unk_32308[1], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
        gDPSetRenderMode(gfx++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);

        if (D_806F2400.unk_3C0[i] > 0) {
            gfx = func_xk3_8013430C(gfx, i);
        } else if (D_806F2400.unk_3C0[i] < 0) {
            D_8076E5A8 = 0;
            switch (i) {
                case CAPTAIN_FALCON:
                    gfx = Machine_DrawLoadBlueFalconTextures(gfx);
                    gDPSetEnvColor(gfx++, 223, 199, 33, 255);
                    gfx = Machine_DrawSuperFalconLod1(gfx);
                    break;
                case SAMURAI_GOROH:
                    gfx = Machine_DrawLoadFireStingrayTextures(gfx);
                    gDPSetEnvColor(gfx++, 55, 55, 55, 255);
                    gfx = Machine_DrawSuperStingrayLod1(gfx);
                    break;
                case JODY_SUMMER:
                    gfx = Machine_DrawLoadWhiteCatTextures(gfx);
                    gDPSetEnvColor(gfx++, 33, 55, 137, 255);
                    gfx = Machine_DrawSuperCatLod1(gfx);
                    break;
            }
            D_8076E5A8 = 1;
        } else {
            gfx = func_8072DF40(gfx, func_8070DBE0(i), 0);
        }
    }

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* func_xk3_80134854(Gfx* gfx, Object* arg1) {
    u16 temp_a3;
    s32 green;
    s32 blue;

    if (D_xk3_80136820 != 0x1C) {
        return gfx;
    }
    if (D_xk3_801414C0 < 30) {
        temp_a3 = gGameFrameCount % 30;
        green = 255;
        blue = 255;
        if (D_806F2400.unk_3C0[D_xk3_801414C0] != 0) {
            green = 155;
            blue = 55;
        }
        if (temp_a3 >= 15) {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 255, green, blue, 255 - ((temp_a3 * 510) / 30));
        }
        OBJECT_LEFT(arg1) = ((D_xk3_801414C0 % 6) * 0x28) + 0x28;
        OBJECT_TOP(arg1) = ((D_xk3_801414C0 / 6) * 0x22) + 0x27;
        gfx = func_i2_800AF584(gfx, D_xk3_80136EF0, OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 1, 0, 0, 1.0f, 1.0f, 0);
    }
    return gfx;
}

void func_xk3_80134A48(Object* arg0) {
    s32 var_v1;

    if (D_xk3_80136820 != 0x1C) {
        return;
    }

    if (D_xk3_801414C0 != OBJECT_STATE(arg0)) {
        var_v1 = func_8070DBE0(D_xk3_801414C0);
        if (D_806F2400.unk_3C0[D_xk3_801414C0] == -1) {
            var_v1 += 30;
            if (var_v1 >= 36) {
                var_v1 %= 30;
            }
        }
        func_i2_800AFB1C(OBJECT_CACHE_INDEX(arg0), 0, D_xk3_80136E60[var_v1]);
    }
    OBJECT_STATE(arg0) = D_xk3_801414C0;
}

extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;

void func_xk3_80134B04(Object* arg0) {
    Racer* racer;
    f32 var_fv0;
    s32 i;

    if (D_xk3_80136820 != 0x1C) {
        return;
    }

    for (i = 1, racer = &gRacers[i]; racer >= gRacers; i--, racer--) {

        if (racer == gRacers) {
            var_fv0 = 0.03f;
        } else {
            var_fv0 = 0.0f;
        }
        racer->unk_C0.x.x += var_fv0 * racer->unk_C0.z.x;
        racer->unk_C0.x.y += var_fv0 * racer->unk_C0.z.y;
        racer->unk_C0.x.z += var_fv0 * racer->unk_C0.z.z;
        func_806F6D8C(&racer->unk_C0);
        func_806F7FCC(&gGfxPool->unk_32308[i], NULL, D_8076E568, D_8076E56C, D_8076E570, racer->unk_C0.x.x,
                      racer->unk_C0.x.y, racer->unk_C0.x.z, racer->unk_C0.y.x, racer->unk_C0.y.y, racer->unk_C0.y.z,
                      racer->unk_0C.unk_34.x, racer->unk_0C.unk_34.y, racer->unk_0C.unk_34.z);
    }
}
