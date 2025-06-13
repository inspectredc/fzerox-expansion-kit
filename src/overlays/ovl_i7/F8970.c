#include "global.h"
#include "ovl_i7.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_machine.h"
#include "fzx_assets.h"

s16 D_i7_8009AEB0;
s16 D_i7_8009AEB2;
unk_8014BF94* D_i7_8009AEB4;
unk_8014BF98* D_i7_8009AEB8;
UNUSED u8 D_i7_8009AEC0[0x80];
s32 D_i7_8009AF40;
UNUSED s32 D_i7_8009AF44;
u16* D_i7_8009AF48[3];
u16* D_i7_8009AF54;
u16* D_i7_8009AF58;
u16* D_i7_8009AF5C;
u16* D_i7_8009AF60;
s32 D_i7_8009AF64;
u8 D_i7_8009AF68[0x200];
s32 D_i7_8009B168;

s32 D_i7_80099B00 = 0;
UNUSED s32 D_i7_80099B04 = 0x800;

void* sFullPortraits[] = {
    aFullPortraitCaptainFalconTex, // CAPTAIN_FALCON
    aFullPortraitDrStewartTex,     // DR_STEWART
    aFullPortraitPicoTex,          // PICO
    aFullPortraitSamuraiGorohTex,  // SAMURAI_GOROH
    aFullPortraitJodySummerTex,    // JODY_SUMMER
    aFullPortraitMightyGazelleTex, // MIGHTY_GAZELLE
    aFullPortraitMrEadTex,         // MR_EAD
    aFullPortraitBabaTex,          // BABA
    aFullPortraitOctomanTex,       // OCTOMAN
    aFullPortraitGomarAndShiohTex, // GOMAR_AND_SHIOH
    aFullPortraitKateAlenTex,      // KATE_ALEN
    aFullPortraitRogerBusterTex,   // ROGER_BUSTER
    aFullPortraitJamesMcCloudTex,  // JAMES_MCCLOUD
    aFullPortraitLeonTex,          // LEON
    aFullPortraitAntonioGusterTex, // ANTONIO_GUSTER
    aFullPortraitBlackShadowTex,   // BLACK_SHADOW
    aFullPortraitMichaelChainTex,  // MICHAEL_CHAIN
    aFullPortraitJackLevinTex,     // JACK_LEVIN
    aFullPortraitSuperArrowTex,    // SUPER_ARROW
    aFullPortraitMrsArrowTex,      // MRS_ARROW
    aFullPortraitJohnTanakaTex,    // JOHN_TANAKA
    aFullPortraitBeastmanTex,      // BEASTMAN
    aFullPortraitZodaTex,          // ZODA
    aFullPortraitDrClashTex,       // DR_CLASH
    aFullPortraitSilverNeelsenTex, // SILVER_NEELSEN
    aFullPortraitBioRexTex,        // BIO_REX
    aFullPortraitDraqTex,          // DRAQ
    aFullPortraitBillyTex,         // BILLY
    aFullPortraitTheSkullTex,      // THE_SKULL
    aFullPortraitBloodFalconTex,   // BLOOD_FALCON
    aFullPortraitCaptainFalconAltTex,
    aFullPortraitSamuraiGorohAltTex,
    aFullPortraitJodySummerAltTex,
};

u8 D_i7_80099B8C[] = { 1 << 7, 1 << 6, 1 << 5, 1 << 4, 1 << 3, 1 << 2, 1 << 1, 1 << 0 };

// Icon Textures (Less than 4b size), used as some kind of mask
// Fireworks?
void* D_i7_80099B94[] = {
    D_F265E80, // CAPTAIN_FALCON
    D_F268A80, // DR_STEWART
    D_F266880, // PICO
    D_F267A80, // SAMURAI_GOROH
    D_F268680, // JODY_SUMMER
    D_F266280, // MIGHTY_GAZELLE
    D_F267C80, // MR_EAD
    D_F266080, // BABA
    D_F267880, // OCTOMAN
    D_F267080, // GOMAR_AND_SHIOH
    D_F269680, // KATE_ALEN
    D_F266480, // ROGER_BUSTER
    D_F268080, // JAMES_MCCLOUD
    D_F269280, // LEON
    D_F268C80, // ANTONIO_GUSTER
    D_F266A80, // BLACK_SHADOW
    D_F269480, // MICHAEL_CHAIN
    D_F266680, // JACK_LEVIN
    D_F267280, // SUPER_ARROW
    D_F268880, // MRS_ARROW
    D_F269080, // JOHN_TANAKA
    D_F267480, // BEASTMAN
    D_F268E80, // ZODA
    D_F266E80, // DR_CLASH
    D_F269880, // SILVER_NEELSEN
    D_F268480, // BIO_REX
    D_F266C80, // DRAQ
    D_F267680, // BILLY
    D_F268280, // THE_SKULL
    D_F267E80, // BLOOD_FALCON
};

void* D_i7_80099C0C = D_F269A80;
void* D_i7_80099C10 = D_F269C80;
void* D_i7_80099C14 = D_F269E80;

void* D_i7_80099C18[] = { D_F26A080, D_F26A280, D_F26A480, D_F26A680 };

void* D_i7_80099C28 = D_F26A880;

u8 D_i7_80099C2C[][3] = {
    { 255, 255, 255 }, { 255, 248, 248 }, { 255, 240, 240 }, { 255, 232, 232 }, { 255, 224, 224 }, { 255, 216, 216 },
    { 255, 208, 208 }, { 255, 200, 200 }, { 255, 192, 192 }, { 255, 184, 184 }, { 255, 176, 176 }, { 255, 168, 168 },
    { 255, 160, 160 }, { 255, 152, 152 }, { 255, 144, 144 }, { 255, 136, 136 }, { 255, 128, 128 }, { 255, 120, 120 },
    { 255, 112, 112 }, { 255, 104, 104 }, { 255, 96, 96 },   { 255, 88, 88 },   { 255, 80, 80 },   { 255, 72, 72 },
    { 255, 64, 64 },   { 255, 56, 56 },   { 255, 48, 48 },   { 255, 40, 40 },   { 255, 32, 32 },   { 255, 24, 24 },
    { 255, 16, 16 },   { 255, 8, 8 },
};

TexturePtr D_i7_80099C8C[] = {
    D_i7_80099CA8,
    D_i7_80099D30,
    D_i7_80099DB8,
    NULL,
};

// Possible separate file?
UNUSED Gfx D_i7_80099CA0[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_80099CA8[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF,
    0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

UNUSED Gfx D_i7_80099D28[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_80099D30[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

UNUSED Gfx D_i7_80099DB0[] = {
    gsSPEndDisplayList(),
};

u16 D_i7_80099DB8[] = {
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFE, 0xFFFE, 0xFFFF, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
    0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE, 0xFFFE,
};

Vtx D_i7_80099E38[] = {
    VTX(-160, 420, 0, 0, 0, 0, 0, 0, 255),
    VTX(160, 420, 0, 992, 0, 0, 0, 0, 255),
    VTX(160, 0, 0, 992, 1312, 0, 0, 0, 255),
    VTX(-160, 0, 0, 0, 1312, 0, 0, 0, 255),
};

Gfx D_i7_80099E78[] = {
    gsSPVertex(D_i7_80099E38, 4, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSP1Triangle(0, 3, 2, 0),
    gsSPEndDisplayList(),
};

extern s32 gTotalRacers;
extern s16 gPlayer1OverallPosition;

void func_i7_800960B0(void) {
    s32 var_a0;
    s32 var_v0;
    s32 i;
    s32 j;
    s32 character;

    D_i7_8009AF64 = 0;
    if ((sCupDifficulty > NOVICE) && (gPlayer1OverallPosition < 4)) {
        D_i7_8009AF64 = 1;
        D_i7_8009AF58 = func_807084E4(0, 0xA80);
        D_i7_8009AF5C = func_807084E4(0, 0xA80);
        D_i7_8009AF60 = func_807084E4(0, 0xA80);

        for (j = 0; j < 0x540; j++) {
            D_i7_8009AF58[j] = D_i7_8009AF5C[j] = D_i7_8009AF60[j] = 0;
        }

        for (i = gTotalRacers - 1; i >= 0; i--) {

            character = gRacers[i].character;
            j = character;
            if ((character == CAPTAIN_FALCON) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 30;
            } else if ((character == SAMURAI_GOROH) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 31;
            } else if ((character == JODY_SUMMER) && IS_SUPER_MACHINE(gRacers[i].customType)) {
                j = 32;
            }
            D_i7_8009AF54 = func_i2_800AE7C4(sFullPortraits[j], 180 * 245 * sizeof(u16), 0, 1, 1);

            for (j = 0; j != 0x2A; j++) {
                for (var_a0 = 0; var_a0 < 32; var_a0++) {
                    var_v0 = (s32) (var_a0 * 5.625f) + (s32) (5.8333335f * j) * 180;
                    D_i7_8009AF58[var_a0 + j * 32] = D_i7_8009AF54[var_v0];
                }
            }

            j = 0;
            while (j == 0) {
                j = 0;

                for (var_a0 = 0x520; var_a0 < 0x540; var_a0++) {
                    if (D_i7_8009AF58[var_a0] != 0) {
                        j++;
                    }
                }

                if (j == 0) {

                    for (var_a0 = 41; var_a0 > 0; var_a0--) {
                        for (var_v0 = 0; var_v0 < 32; var_v0++) {
                            D_i7_8009AF58[var_a0 * 32 + var_v0] = D_i7_8009AF58[var_a0 * 32 + var_v0 - 32];
                        }
                    }

                    for (var_v0 = 0; var_v0 < 32; var_v0++) {
                        D_i7_8009AF58[var_v0] = 0;
                    }
                }
            }

            for (j = 0; j < 32; j++) {
                D_i7_8009AF58[j] = 0;
            }

            if (i == 2) {
                for (j = 0; j < 0x540; j++) {
                    D_i7_8009AF60[j] = D_i7_8009AF58[j];
                }
            }

            if (i == 1) {
                for (j = 0; j < 0x540; j++) {
                    D_i7_8009AF5C[j] = D_i7_8009AF58[j];
                }
            }
        }
        D_i7_8009AF48[0] = D_i7_8009AF58;
        D_i7_8009AF48[1] = D_i7_8009AF5C;
        D_i7_8009AF48[2] = D_i7_8009AF60;
    }
}

extern Player gPlayers[];

void func_i7_800967D8(void) {
    Racer* racer;
    s32 i;

    if (D_i7_8009AF64 == 1) {
        for (i = 0; i < gTotalRacers; i++) {
            racer = &gRacers[i];
            func_806F7FCC(
                &D_i7_8009AD10->unk_3F0[i], NULL, 0.04f, 0.04f, 0.04f, -gPlayers[0].unk_5C.x.x, -gPlayers[0].unk_5C.x.y,
                -gPlayers[0].unk_5C.x.z, racer->unk_C0.y.x, racer->unk_C0.y.y, racer->unk_C0.y.z,
                racer->unk_168.x + ((racer->unk_C0.x.x * 23.0f * 3.0f) / 2) + (racer->unk_C0.z.x * 23.0f * 0.8f),
                (D_i7_8009ADE8[i].unk_0C + 120.0f) - 1.0f,
                racer->unk_168.z + ((racer->unk_C0.x.z * 23.0f * 3.0f) / 2) + (racer->unk_C0.z.z * 23.0f * 0.8f));
        }
    }
}

Gfx* func_i7_800969B8(Gfx* gfx) {
    s32 i;

    if ((D_i7_8009AF64 == 1) && (D_i7_8009AE48 != 0)) {
        gSPDisplayList(gfx++, D_400A258);
        gDPPipeSync(gfx++);
        gDPSetRenderMode(gfx++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

        for (i = 0; i < gTotalRacers; i++) {
            gDPPipeSync(gfx++);

            gDPLoadTextureBlock(gfx++, D_i7_8009AF48[i], G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 42, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPMatrix(gfx++, &D_i7_8009AD10->unk_3F0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

            gSPDisplayList(gfx++, D_i7_80099E78);
        }
    }
    return gfx;
}

extern s32 gCupType;
extern s16 gRacersRemaining;

void func_i7_80096BB0(void) {
    s32 i;

    gRacersRemaining = gTotalRacers;
    if (gPlayer1OverallPosition < 4) {
        func_i7_800960B0();
        D_i7_8009AEB4 = func_807084E4(0, 0xCB20);
        D_i7_8009AEB8 = func_807084E4(0, 0x280);
        D_i7_8009AEB0 = 10;

        for (i = 0; i < D_i7_8009AEB0; i++) {
            D_i7_8009AEB8[i].unk_24 = 0;
        }

        D_i7_8009B168 = 0;
        D_i7_8009AF40 = 0;
        if (gPlayer1OverallPosition == 1) {
            if (gCupType == X_CUP) {
                func_i2_800AE100(D_i7_80099C18[Math_Rand1() % 4], 0x200, D_i7_8009AF68);
            } else if ((gRacers[0].character == CAPTAIN_FALCON) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_i2_800AE100(D_i7_80099C0C, 0x200, D_i7_8009AF68);
            } else if ((gRacers[0].character == SAMURAI_GOROH) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_i2_800AE100(D_i7_80099C10, 0x200, D_i7_8009AF68);
            } else if ((gRacers[0].character == JODY_SUMMER) && IS_SUPER_MACHINE(gRacers[0].customType)) {
                func_i2_800AE100(D_i7_80099C14, 0x200, D_i7_8009AF68);
            } else {
                func_i2_800AE100(D_i7_80099B94[gRacers[0].character], 0x200, D_i7_8009AF68);
            }
        } else {
            func_i2_800AE100(D_i7_80099C28, 0x200, D_i7_8009AF68);
        }
    }
}

void func_i7_80096DAC(void) {
    s32 var_s1;
    s32 i;
    s32 j;
    Player* var = &gPlayers[0];
    unk_8014BF98* temp_s4;
    unk_8014BF94* temp_s0;
    bool var_a1;
    f32 var_fs0;
    f32 var_fs0_2;
    f32 var_fs1;
    f32 var_fs1_2;
    f32 var_fs2;
    f32 var_fa0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fa1;
    f32 temp_fv0_6;
    f32 temp_fv0_9;
    f32 temp_fv0_12;
    f32 var_fv1;
    f32 temp_fv1_5;
    f32 temp1;
    s32 pad[21];

    if (gPlayer1OverallPosition >= 4) {
        return;
    }

    func_i7_800967D8();
    D_i7_80099B00++;

    for (i = 0; i < D_i7_8009AEB0; i++) {
        temp_s4 = &D_i7_8009AEB8[i];
        temp_s4->unk_25 = temp_s4->unk_24;

        switch (D_i7_8009AEB8[i].unk_24) {
            case 0:
                temp_s4->unk_00 = (Math_Rand1() % 256) - 128.1f;
                temp_s4->unk_08 = (Math_Rand1() % 256) - 128.1f;

                var_fv1 = sqrtf(SQ(temp_s4->unk_00) + SQ(temp_s4->unk_08));

                if (var_fv1 < 0.001f) {
                    var_fv1 = 0.001f;
                }

                var_fv1 = 1.0f / var_fv1;

                temp_s4->unk_00 = temp_s4->unk_00 * var_fv1 * 700.0f;
                temp_s4->unk_08 = temp_s4->unk_08 * var_fv1 * 700.0f;

                temp_s4->unk_04 = ((Math_Rand1() % 16) + 0x190) * -1.0f;
                temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                temp_s4->unk_1C = 25.0f;
                temp_s4->unk_18 = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                temp_s4->unk_20 = ((Math_Rand1() % 256) - 128.0f) * 0.01f;
                temp_s4->unk_3C = Math_Rand1() % 7;
                temp_s4->unk_2C = Math_Rand1() % 7;
                temp_s4->unk_34 = Math_Rand1() % (128 - (sCupDifficulty * 32));
                temp_s4->unk_28 = 1.2f;
                switch (D_i7_8009B168) {
                    case 0:
                        break;
                    case 1:
                        temp_s4->unk_2E = i * 100;
                        temp_s4->unk_30 = 100;
                        temp_s4->unk_24 = 1;
                        break;
                    case 2:
                        if (i == 0) {
                            var_a1 = false;
                            for (var_s1 = 0; var_s1 < D_i7_8009AEB0; var_s1++) {
                                if (D_i7_8009AEB8[var_s1].unk_24 != 0) {
                                    var_a1 = true;
                                }
                            }

                            if (!var_a1) {
                                temp_s4->unk_2E = 0;
                                temp_s4->unk_30 = 0x320;
                                temp_s4->unk_24 = 1;
                                temp_s4->unk_2C = 0x20;
                                D_i7_8009B168 = 0;
                                temp_s4->unk_00 = var->unk_5C.x.x * 700.0f;
                                temp_s4->unk_08 = var->unk_5C.x.z * 700.0f;
                                temp_s4->unk_18 = 0.0f;
                                temp_s4->unk_20 = 0.0f;
                                temp_s4->unk_04 = -500.0f;
                                temp_s4->unk_28 = 1.5f;
                                temp_s4->unk_1C = 28.0f;
                                D_i7_8009AEB0 = 1;
                            }
                        }
                        break;
                }
                if (temp_s4->unk_24 == 1) {
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8009AEB4[j];
                        temp_s0->unk_2C = 0;
                        temp_s0->unk_28 = 0;
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    }
                }
                break;
            case 1:
                if (temp_s4->unk_34 > 0) {
                    temp_s4->unk_34--;
                } else {
                    temp_s4->unk_24 = 2;
                }
                break;
            case 2:
                temp_s4->unk_00 += temp_s4->unk_18;
                temp_s4->unk_04 += temp_s4->unk_1C;
                temp_s4->unk_08 += temp_s4->unk_20;
                temp_s4->unk_1C -= 0.5f;
                if (temp_s4->unk_1C < 0.0f) {
                    temp_s4->unk_24 = 3;
                    var_s1 = 0;
                    if (temp_s4->unk_2C == 0x20) {
                        func_80741470(0x40, 0x7F);
                    } else {
                        var_fs0_2 = temp_s4->unk_00;
                        temp_ft4 = temp_s4->unk_04;
                        temp_ft5 = temp_s4->unk_08;
                        var_fa0 = sqrtf(SQ(var_fs0_2) + SQ(temp_ft4) + SQ(temp_ft5));

                        if (var_fa0 != 0.0f) {
                            var_fv1 = -((var->unk_5C.z.z * temp_ft5) +
                                        ((var_fs0_2 * var->unk_5C.z.x) + (temp_ft4 * var->unk_5C.z.y))) /
                                      var_fa0;
                            var_fa0 *= var_fv1;
                        }
                        if ((var_fa0 >= -1000) && (var_fa0 <= 1000)) {
                            func_80741470((s32) (f32) (u32) (((var_fa0 + 1000.0f) / 2000.0f) * 127.0f), 0x40);
                        }
                    }
                    var_fs1_2 = sqrtf(SQ(gPlayers[0].unk_5C.z.x) + SQ(gPlayers[0].unk_5C.z.z));

                    if (var_fs1_2 < 0.0001f) {
                        var_fs1_2 = 0.0001f;
                    }

                    var_fs1_2 = 1.0f / var_fs1_2;
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8009AEB4[j];
                        temp_s0->unk_00 = temp_s4->unk_00;
                        temp_s0->unk_04 = temp_s4->unk_04;
                        temp_s0->unk_08 = temp_s4->unk_08;

                        switch (temp_s4->unk_2C) {
                            case 0:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 5) + 5.1f;
                                break;
                            case 1:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = Math_Rand1() % 5;
                                break;
                            case 2:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 3:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = 0.0f;
                                break;
                            case 4:
                                temp_s0->unk_18 = 0.0f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 5:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = 0.0f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                            case 6:
                                switch (j % 3) {
                                    case 0:
                                        temp_s0->unk_20 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_18 = 0.0f;
                                        temp_s0->unk_1C = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    case 1:
                                        temp_s0->unk_18 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_1C = 0.0f;
                                        temp_s0->unk_20 = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                    default:
                                        temp_s0->unk_18 = (Math_Rand1() % 10) - 5.0f;
                                        temp_s0->unk_20 = 0.0f;
                                        temp_s0->unk_1C = (Math_Rand1() % 10) - 5.0f;
                                        break;
                                }
                                break;
                            case 32:
                                while (!(D_i7_8009AF68[var_s1 >> 3] & D_i7_80099B8C[var_s1 & 7])) {
                                    var_s1++;
                                    if (var_s1 >= 0x1000) {
                                        var_s1 = 0;
                                    }
                                }

                                temp_fv0_6 = -(((var_s1 & 0x3F) - 0x20) * 0.12f);

                                temp_s0->unk_18 = ((gPlayers[0].unk_5C.z.x * var_fs1_2 * 0.866f) -
                                                   (gPlayers[0].unk_5C.z.z * var_fs1_2 * 0.5f)) *
                                                  temp_fv0_6;
                                temp_s0->unk_20 = ((gPlayers[0].unk_5C.z.z * var_fs1_2 * 0.866f) +
                                                   (gPlayers[0].unk_5C.z.x * var_fs1_2 * 0.5f)) *
                                                  temp_fv0_6;

                                temp_s0->unk_1C = ((-(f32) ((var_s1 >> 6) - 0x48)) * 0.12f);
                                var_s1++;
                                break;
                            default:
                                temp_s0->unk_18 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_20 = (Math_Rand1() % 10) - 5.1f;
                                temp_s0->unk_1C = (Math_Rand1() % 10) - 5.1f;
                                break;
                        }
                        if (temp_s4->unk_2C != 0x20) {
                            var_fs0 = sqrtf(SQ(temp_s0->unk_18) + SQ(temp_s0->unk_1C) + SQ(temp_s0->unk_20));

                            if (var_fs0 < 0.0001f) {
                                var_fs0 = 0.0001f;
                            }

                            temp_fv0_9 = (((Math_Rand1() % 100) / 100.0f) - 0.5f) + 4.0f;
                            temp_s0->unk_18 = (temp_s0->unk_18 / var_fs0) * temp_fv0_9;
                            temp_s0->unk_1C = (temp_s0->unk_1C / var_fs0) * temp_fv0_9;
                            temp_s0->unk_20 = (temp_s0->unk_20 / var_fs0) * temp_fv0_9;
                        }
                    }
                }
                break;
            case 3:
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                    temp_s0 = &D_i7_8009AEB4[j];
                    temp_s0->unk_00 += temp_s0->unk_18;
                    temp_s0->unk_04 += temp_s0->unk_1C;
                    temp_s0->unk_08 += temp_s0->unk_20;
                    if (temp_s4->unk_2C != 0x20) {
                        temp_s0->unk_1C = (temp_s0->unk_1C * 0.98f) - 0.05f;
                        temp_s0->unk_18 = temp_s0->unk_18 * 0.98f;
                        temp_s0->unk_20 = temp_s0->unk_20 * 0.98f;
                    } else {
                        temp_s0->unk_1C = (temp_s0->unk_1C * 0.985f) - 0.04f;
                        temp_s0->unk_18 = temp_s0->unk_18 * 0.985f;
                        temp_s0->unk_20 = temp_s0->unk_20 * 0.985f;
                    }
                }
                if (temp_s4->unk_2C != 0x20) {
                    temp_s4->unk_28 -= 0.01f;
                } else {
                    temp_s4->unk_28 -= 0.007f;
                }
                if (temp_s4->unk_28 <= 0) {
                    temp_s4->unk_24 = 0;
                    temp_s4->unk_10 = 0x200;
                    temp_s4->unk_0C = 0x200;
                    temp_s4->unk_28 = 0;
                    for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                        temp_s0 = &D_i7_8009AEB4[j];
                        temp_s0->unk_10 = 0x200;
                        temp_s0->unk_0C = 0x200;
                    }
                }
                break;
        }

        if ((temp_s4->unk_24 >= 3) || ((D_i7_8009AF40 != 0) && (temp_s4->unk_24 > 0))) {
            var_fs2 = temp_s4->unk_00;
            var_fs0 = temp_s4->unk_08;
            var_fa0 = sqrtf(SQ(var_fs2) + SQ(var_fs0));

            if (var_fa0 < 0.001f) {
                var_fa0 = 0.001f;
            }
            var_fa0 = 1.0f / var_fa0;
            var_fs2 *= var_fa0;
            var_fs0 *= var_fa0;
            if (((var_fs0 * var->unk_5C.x.z) + (var_fs2 * var->unk_5C.x.x)) < 0.4f) {
                temp_s4->unk_24 = 0;
                temp_s4->unk_28 = 0;
                temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                    temp_s0 = &D_i7_8009AEB4[j];
                    temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                }
            }
        }

        if (temp_s4->unk_24 >= 2) {
            if (temp_s4->unk_24 != 3) {
                temp_s0 = &D_i7_8009AEB4[temp_s4->unk_2E];
                temp_fv0_12 = var->unk_50.x + temp_s4->unk_00;
                temp_fv1_5 = temp_s4->unk_04;
                temp_fa1 = var->unk_50.z + temp_s4->unk_08;

                var_fs0_2 = (temp_fv0_12 - var->unk_50.x);
                temp_ft4 = (temp_fv1_5 - var->unk_50.y);
                temp_ft5 = (temp_fa1 - var->unk_50.z);
                var_fa0 = (var_fs0_2 * var->unk_5C.x.x) + (temp_ft4 * var->unk_5C.x.y) + (temp_ft5 * var->unk_5C.x.z);
                if (var_fa0 <= 0) {
                    temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                } else {
                    var_fs2 = var->unk_19C.xw + ((var->unk_19C.xx * temp_fv0_12) + (var->unk_19C.xy * temp_fv1_5) +
                                                 (var->unk_19C.xz * temp_fa1));
                    var_fs1 = var->unk_19C.yw + ((var->unk_19C.yx * temp_fv0_12) + (var->unk_19C.yy * temp_fv1_5) +
                                                 (var->unk_19C.yz * temp_fa1));
                    temp1 = var->unk_19C.zw + ((var->unk_19C.zx * temp_fv0_12) + (var->unk_19C.zy * temp_fv1_5) +
                                               (var->unk_19C.zz * temp_fa1));
                    var_fs0 = var->unk_19C.ww + ((var->unk_19C.wx * temp_fv0_12) + (var->unk_19C.wy * temp_fv1_5) +
                                                 (var->unk_19C.wz * temp_fa1));
                    if (func_i3_fabsf(var_fs0) < 0.001f) {
                        temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                    } else {
                        temp_s4->unk_0C = var->unk_F0 + ((var_fs2 * var->unk_E8) / var_fs0);
                        temp_s4->unk_10 = var->unk_F4 - ((var_fs1 * var->unk_EC) / var_fs0);

                        if ((temp_s4->unk_0C < var->unk_B0) || (var->unk_B8 < temp_s4->unk_0C) ||
                            (temp_s4->unk_10 < var->unk_B4) || (var->unk_BC < temp_s4->unk_10)) {
                            temp_s4->unk_0C = temp_s4->unk_10 = 0x200;
                        }
                    }
                }
            } else {
                for (j = temp_s4->unk_2E; j < temp_s4->unk_2E + temp_s4->unk_30; j++) {
                    temp_s0 = &D_i7_8009AEB4[j];
                    temp_fv0_12 = gPlayers[0].unk_50.x + temp_s0->unk_00;
                    temp_fv1_5 = temp_s0->unk_04;
                    temp_fa1 = gPlayers[0].unk_50.z + temp_s0->unk_08;

                    var_fs0_2 = (temp_fv0_12 - var->unk_50.x);
                    temp_ft4 = (temp_fv1_5 - var->unk_50.y);
                    temp_ft5 = (temp_fa1 - var->unk_50.z);
                    var_fa0 =
                        (var_fs0_2 * var->unk_5C.x.x) + (temp_ft4 * var->unk_5C.x.y) + (temp_ft5 * var->unk_5C.x.z);
                    if (var_fa0 <= 0) {
                        temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                    } else {
                        var_fs2 = var->unk_19C.xw + ((var->unk_19C.xx * temp_fv0_12) + (var->unk_19C.xy * temp_fv1_5) +
                                                     (var->unk_19C.xz * temp_fa1));
                        var_fs1 = var->unk_19C.yw + ((var->unk_19C.yx * temp_fv0_12) + (var->unk_19C.yy * temp_fv1_5) +
                                                     (var->unk_19C.yz * temp_fa1));
                        temp1 = var->unk_19C.zw + ((var->unk_19C.zx * temp_fv0_12) + (var->unk_19C.zy * temp_fv1_5) +
                                                   (var->unk_19C.zz * temp_fa1));
                        var_fs0 = var->unk_19C.ww + ((var->unk_19C.wx * temp_fv0_12) + (var->unk_19C.wy * temp_fv1_5) +
                                                     (var->unk_19C.wz * temp_fa1));
                        if (func_i3_fabsf(var_fs0) < 0.001f) {
                            temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                        } else {
                            temp_s0->unk_0C = var->unk_F0 + ((var_fs2 * var->unk_E8) / var_fs0);
                            temp_s0->unk_10 = var->unk_F4 - ((var_fs1 * var->unk_EC) / var_fs0);

                            if ((temp_s0->unk_0C < var->unk_B0) || (var->unk_B8 < temp_s0->unk_0C) ||
                                (temp_s0->unk_10 < var->unk_B4) || (var->unk_BC < temp_s0->unk_10)) {
                                temp_s0->unk_0C = temp_s0->unk_10 = 0x200;
                            }
                        }
                    }
                }
            }
        }
    }
    D_i7_8009AEB2 = 0;
    for (j = 0; j < D_i7_8009AEB0; j++) {
        if (D_i7_8009AEB8[j].unk_24 != 0) {
            D_i7_8009AEB2++;
        }
    }
}

Gfx* func_i7_80098650(Gfx* gfx) {
    unk_8014BF98* temp_s6;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 i;
    s32 j;
    s32 red;
    s32 green;
    s32 blue;
    f32 var_fs1;
    s32 temp_t6;
    unk_8014BF94* temp_a0;
    unk_8014BF98* temp_v0;

    if (gPlayer1OverallPosition >= 4) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_8014940);
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    for (i = 0; i < D_i7_8009AEB0; i++) {

        if (D_i7_8009AEB8[i].unk_24 >= 2) {
            temp_s6 = &D_i7_8009AEB8[i];
            var_fs1 = temp_s6->unk_28 * 0.5f;

            if (var_fs1 > 0.8f) {
                var_fs1 = 0.8f;
            }

            if (var_fs1 < 0.1f) {
                continue;
            }

            func_806F7138((i * 0x600) / D_i7_8009AEB0, Math_Rand1() % 256, 255, &red, &green, &blue);
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, red, green, blue, (s32) ((var_fs1 / 0.8f) * 255.0f));
            gDPLoadTextureBlock(gfx++, D_i7_80099C8C[Math_Rand1() % 3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            if (D_i7_8009AEB8[i].unk_24 != 3) {
                if (temp_s6->unk_0C != 0x200) {
                    left = (s32) ((temp_s6->unk_0C * 4.0f) - (4.0f * var_fs1));
                    top = (s32) ((temp_s6->unk_10 * 4.0f) - (4.0f * var_fs1));
                    right = (s32) (((temp_s6->unk_0C + 7.0f) * 4.0f) + (4.0f * var_fs1));
                    bottom = (s32) (((temp_s6->unk_10 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                    gSPTextureRectangle(gfx++, left, top, right, bottom, 0, 0, 0, (s32) (1024.0f / var_fs1),
                                        (s32) (1024.0f / var_fs1));
                }
            } else {
                for (j = D_i7_8009AEB8[i].unk_2E; j < D_i7_8009AEB8[i].unk_2E + D_i7_8009AEB8[i].unk_30; j++) {
                    if ((temp_s6->unk_2C == 0x20) && !(j & 0x1F)) {
                        temp_t6 = Math_Rand1() % 32;

                        gDPPipeSync(gfx++);
                        gDPSetPrimColor(gfx++, 0, 0, D_i7_80099C2C[temp_t6][0], D_i7_80099C2C[temp_t6][1],
                                        D_i7_80099C2C[temp_t6][2], (s32) ((var_fs1 / 0.8f) * 255.0f));
                        gDPLoadTextureBlock(gfx++, D_i7_80099C8C[Math_Rand1() % 3], G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 8,
                                            0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                                            G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                    }

                    temp_a0 = &D_i7_8009AEB4[j];
                    if (temp_a0->unk_0C != 0x200) {
                        left = (s32) ((temp_a0->unk_0C * 4.0f) - (4.0f * var_fs1));
                        top = (s32) ((temp_a0->unk_10 * 4.0f) - (4.0f * var_fs1));
                        right = (s32) (((temp_a0->unk_0C + 7.0f) * 4.0f) + (4.0f * var_fs1));
                        bottom = (s32) (((temp_a0->unk_10 + 7.0f) * 4.0f) + (4.0f * var_fs1));
                        gSPTextureRectangle(gfx++, left, top, right, bottom, 0, 0, 0, (s32) (1024.0f / var_fs1),
                                            (s32) (1024.0f / var_fs1));
                    }
                }
            }
        }
    }

    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);

    return gfx;
}
