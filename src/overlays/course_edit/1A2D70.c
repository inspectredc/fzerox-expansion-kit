#include "global.h"

extern u8 D_xk2_80128D00[];
extern u8 D_xk2_80104CA0[];
extern unk_800D6CA0 D_800D6CA0;

void func_xk2_800F12B0(void) {
    s32 i;

    D_800D6CA0.unk_1C = -1;

    for (i = 0; i < 12; i++) {
        if ((i != 0xA) && (i != 1) && (i != 3)) {
            D_xk2_80104CA0[i] = 0;
        }
    }

    for (i = 0; i < 64; i++) {
        D_xk2_80128D00[i] = 0;
    }
}

void func_xk2_800F1330(s32 arg0, s32 arg1) {
    if (&arg1) {}
    D_xk2_80128D00[arg0] |= arg1;
}

u8 func_xk2_800F1350(s32 arg0) {
    return D_xk2_80128D00[arg0];
}

extern s32 D_xk2_80104CB0;
extern s32 D_xk2_80104CB4;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CBC;
extern s32 D_xk2_80104CC0;
extern s32 D_xk2_80128D48;
extern s32 D_xk2_80128D4C;
extern s32 D_xk2_80128D50;
extern s32 D_xk2_80128D54;
extern s32 D_xk2_80128D58;
extern s32 D_xk2_80128D5C;

void func_xk2_800F1360(void) {
    D_xk2_80128D48 = D_xk2_80104CB0;
    D_xk2_80128D4C = D_800D6CA0.unk_14;
    D_xk2_80128D50 = D_xk2_80104CB4;
    D_xk2_80128D54 = D_xk2_80104CB8;
    D_xk2_80128D58 = D_xk2_80104CBC;
    D_xk2_80128D5C = D_xk2_80104CC0;
}

void func_xk2_800F13C4(void) {
    D_xk2_80104CB0 = D_xk2_80128D48;
    D_800D6CA0.unk_14 = D_xk2_80128D4C;
    D_xk2_80104CB4 = D_xk2_80128D50;
    D_xk2_80104CB8 = D_xk2_80128D54;
    D_xk2_80104CBC = D_xk2_80128D58;
    D_xk2_80104CC0 = D_xk2_80128D5C;
}

extern Mtx D_2000000[];
extern Player gPlayers[];
extern s32 D_8076C950;
extern unk_80128C94 D_6000000;
extern unk_80128C94* D_80128C94;

extern f32 D_xk2_80128D60;
extern f32 D_xk2_80128D64;
extern f32 D_xk2_80128D68;

extern f32 D_xk2_80128D40;
extern f32 D_xk2_80128D44;

#ifdef NON_MATCHING
// stack
Gfx* func_xk2_800F1428(Gfx* gfx) {
    u16 sp13E;
    s32 pad[9];
    s32 temp_v0;
    s32 temp_v1;
    Player* player = gPlayers;
    Mtx spC8;
    MtxF sp88;

    if (D_8076C950 != 0) {
        return func_80719890();
    }
    if (D_8076C950 != 0) {
        func_806F9384(&D_80128C94->unk_0000, NULL, (gPlayers[0].unk_94.x * 320.0f) / 240.0f, 32.0f, 4096.0f, 320.0f, 0.0f, 240.0f, 0.0f, &sp13E);
    } else {
        func_806F9384(&D_80128C94->unk_0000, NULL, (gPlayers[0].unk_94.x * 320.0f) / 240.0f, 128.0f, 32768.0f, 320.0f, 0.0f, 240.0f, 0.0f, &sp13E);
        sp13E = 0x10;
    }
    gSPPerspNormalize(gfx++, sp13E);
    gSPMatrix(gfx++, &D_6000000.unk_0000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    Matrix_FromMtx(&D_80128C94->unk_0000, &gPlayers[0].unk_11C);
    temp_v0 = (D_xk2_80104CB0 * 0x1000) / 360;
    D_xk2_80128D64 = SIN(temp_v0);
    D_xk2_80128D68 = COS(temp_v0);
    temp_v1 = (D_800D6CA0.unk_14 * 0x1000) / 360;
    D_xk2_80128D60 = SIN(temp_v1) * D_xk2_80128D68;
    D_xk2_80128D64 = (-1.0f * D_xk2_80128D64);
    D_xk2_80128D68 = COS(temp_v1) * (-1.0f * D_xk2_80128D68);
    gPlayers[0].unk_5C.x.x = D_xk2_80128D60;
    gPlayers[0].unk_5C.x.y = D_xk2_80128D64;
    gPlayers[0].unk_5C.x.z = D_xk2_80128D68;

    gPlayers[0].unk_50.x = D_xk2_80104CB8 - (D_xk2_80104CB4 * D_xk2_80128D60);
    gPlayers[0].unk_50.y = D_xk2_80104CBC - (D_xk2_80104CB4 * D_xk2_80128D64);
    gPlayers[0].unk_50.z = D_xk2_80104CC0 - (D_xk2_80104CB4 * D_xk2_80128D68);
    
    D_xk2_80128D40 = SIN(temp_v1);
    D_xk2_80128D44 = COS(temp_v1);
    
    gPlayers[0].unk_5C.y.x = 0 - (D_xk2_80128D64 * D_xk2_80128D40);
    gPlayers[0].unk_5C.y.y = (D_xk2_80128D60 * D_xk2_80128D40) - (D_xk2_80128D68 * D_xk2_80128D44);
    gPlayers[0].unk_5C.y.z = D_xk2_80128D64 * D_xk2_80128D44;

    gPlayers[0].unk_5C.z.x = (D_xk2_80128D68 * gPlayers[0].unk_5C.y.y) - (D_xk2_80128D64 * gPlayers[0].unk_5C.y.z);
    gPlayers[0].unk_5C.z.y = (D_xk2_80128D60 * gPlayers[0].unk_5C.y.z) - (D_xk2_80128D68 * gPlayers[0].unk_5C.y.x);
    gPlayers[0].unk_5C.z.z = (D_xk2_80128D64 * gPlayers[0].unk_5C.y.x) - (D_xk2_80128D60 * gPlayers[0].unk_5C.y.y);
    func_806F8FE0(&D_80128C94->unk_0040, NULL, gPlayers[0].unk_50.x, gPlayers[0].unk_50.y, gPlayers[0].unk_50.z, D_xk2_80104CB8, D_xk2_80104CBC, D_xk2_80104CC0, gPlayers[0].unk_5C.y.x, gPlayers[0].unk_5C.y.y, gPlayers[0].unk_5C.y.z);

    gSPMatrix(gfx++, &D_6000000.unk_0040, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(gfx++, D_2000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    Matrix_FromMtx(&D_80128C94->unk_0040, &gPlayers[0].unk_15C);
    func_80713204(&gPlayers[0].unk_19C, &gPlayers[0].unk_11C, &gPlayers[0].unk_15C);
    func_806F7FCC(&spC8, NULL, 0.3f, 0.3f, 0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    Matrix_FromMtx(&spC8, &sp88);
    func_xk2_800F1FF0(&sp88, &gPlayers[0].unk_19C, &gPlayers[0].unk_19C);
    return gfx;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/1A2D70/func_xk2_800F1428.s")
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/course_edit/1A2D70/func_xk2_800F1938.s")
