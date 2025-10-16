#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_assets.h"

Player gPlayers[4];
unk_struct_F8 D_807A10A0[4];
unk_800E5D70 D_807A1480[4];
unk_struct_20_2 D_807A1510[4];
s32 D_807A1590;
s32 D_807A1594;
s16 D_807A1598;
s16 D_807A159A;
UNUSED s16 D_807A159C;
Vec3f D_807A15A0[4];

const unk_redo_1 D_807763D0 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
};

const unk_redo_2 D_80776448 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

UNUSED const unk_8008112C_arg_1 D_807764F4 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 120.0f, 120.0f, 1.0f, 35.0f, 35.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

const unk_redo_3 D_807765E8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
};

const unk_redo_2 D_807766A8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 400.0f, 400.0f, 1.0f, 40.0f, 40.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const unk_redo_2 D_80776754 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
      0.0f, 1500.0f, 1500.0f, 1.0f, 35.0f, 35.0f, 1.0f, 50.0f, 50.0f, 1.0f },
};

const unk_redo_2 D_80776800 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 1.0f, 60.0f, 60.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,     0.0f,     0.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 10500.0f, 10500.0f, 1.0f, 20.0f, 20.0f, 1.0f, 0.0f, 0.0f, 1.0f },
};

const unk_redo_1 D_807768AC = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 4000.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f, 30.0f, 30.0f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

UNUSED const unk_redo_1 D_80776924 = {
    { 0.0f, 50.0f, 0.0f,  0.0f,  150.0f, 500.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
      0.0f, 0.0f,  75.0f, 75.0f, 0.0f,   0.0f,   0.0f, 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};

const unk_redo_2 D_8077699C = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 75.0f, 75.0f, 1.0f, 0.0f, 77.0f, 0.0f, 77.0f, 1.0f, 1.0f },
    { 0.0f, 0.0f,    0.0f,    0.0f, 0.0f,  1.0f,  0.0f, 1.0f,   0.0f,   1.0f, 0.0f,
      0.0f, 1000.0f, 1000.0f, 1.0f, 35.0f, 35.0f, 1.0f, 180.0f, 180.0f, 1.0f },
};

const Vec3f D_80776A48[] = {
    { 80.0f, 400.0f, 50.0f },
    { 75.0f, 90.0f, 25.0f },
    { 75.0f, 120.0f, 35.0f },
    { 100.0f, 120.0f, 50.0f },
};

const Vec3f D_80776A78[] = {
    { 100.0f, 400.0f, 50.0f },
    { 90.0f, 100.0f, 25.0f },
    { 100.0f, 120.0f, 35.0f },
    { 110.0f, 125.0f, 40.0f },
};

const unk_8008112C_arg_1 D_80776AA8 = {
    { 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 400.0f, 0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
      0.0f, 1.0f, 80.0f, 80.0f, 0.2f, 0.0f,   77.0f, 0.0f, 77.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

const unk_8008112C_arg_1 D_80776B9C = {
    { 0.0f, 0.0f, 0.0f,   0.0f,   0.0f, 400.0f, 0.0f,   1.0f, 0.0f,   0.0f, 1.0f,
      0.0f, 1.0f, 100.0f, 100.0f, 0.2f, 0.0f,   -15.0f, 0.0f, -15.0f, 0.1f, 0.2f },
    { 0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   0.0f,
      0.0f, 0.0f,   0.0f,   0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,   1.0f,
      0.0f, 400.0f, 400.0f, 0.2f, 50.0f, 50.0f, 0.2f, 0.0f, 0.0f, 1.0f, 0.0f, 300.0f, 0.0f },
};

s32 D_8076D6C0 = -1;
s32 D_8076D6C4 = 1;

f32 D_8076D6C8[] = {
    2000.0f,
    0.0f,
    25.0f,
};

f32 D_8076D6D4[] = {
    4000.0f,
    -0.9f,
    50.0f,
};

f32 D_8076D6E0[] = {
    -7.0f, 0.0f, 63.0f, -7.0f, 0.0f, 63.0f, 26.0f, 20.0f, -65.0f, 26.0f, 20.0f, -65.0f, 0.0f, 0.0f,
};

f32 D_8076D718[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -50.0f, 40.0f, 40.0f, -50.0f, 40.0f, -40.0f, 0.0f, 1.0f,
};

f32 D_8076D750[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -40.0f, 30.0f, 104.0f, 40.0f, 30.0f, 104.0f, 0.0f, 1.0f,
};

unk_800CD970 D_8076D788[] = {
    { 0, 88, 60.0f, D_8076D6C8 }, { 1, 23, 60.0f, D_8076D6E0 },  { 1, 23, 60.0f, D_8076D718 },
    { 1, 23, 80.0f, D_8076D750 }, { 0, 284, 60.0f, D_8076D6D4 },
};

const s32 D_80776C90[] = { 0 };

const s32 D_80776C94[] = { 1, 2 };

const s32 D_80776C9C[] = { 5, 7, 6 };

const s32 D_80776CA8[] = { 5, 7, 6, 8 };

const s32* D_8076D7C4[] = {
    NULL, D_80776C90, D_80776C94, D_80776C9C, D_80776CA8,
};

ScissorBox D_8076D7D8 = { 12, 8, 308, 232 };
ScissorBox D_8076D7E8 = { 12, 8, 307, 119 };
ScissorBox D_8076D7F8 = { 12, 120, 307, 231 };
ScissorBox D_8076D808 = { 12, 8, 159, 231 };
ScissorBox D_8076D818 = { 160, 8, 307, 231 };
ScissorBox D_8076D828 = { 12, 8, 159, 119 };
ScissorBox D_8076D838 = { 160, 8, 307, 119 };
ScissorBox D_8076D848 = { 12, 120, 159, 231 };
ScissorBox D_8076D858 = { 160, 120, 307, 231 };
ScissorBox D_8076D868 = { 86, 8, 233, 119 };
ScissorBox D_8076D878 = { 86, 120, 233, 231 };
ScissorBox D_8076D888 = { 12, 64, 159, 175 };
ScissorBox D_8076D898 = { 160, 64, 307, 175 };

f32 D_8076D8A8 = 25.4629631f;
f32 D_8076D8AC = 46.29629517f;
f32 D_8076D8B0 = 120.0f;
s32 sMaxCameraLookBackRotate = 8;

void func_80711B20(unk_struct_F8* arg0, unk_struct_20* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = *arg1;
}

void func_80711B6C(unk_struct_F8* arg0, unk_redo_1* arg1) {
    arg0->unk_00 = 1;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00.unk_00 = arg1->unk_58;
}

void func_80711BF0(unk_struct_F8* arg0, unk_struct_9C* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_58 = *arg1;
}

void func_80711C30(unk_struct_F8* arg0, unk_8008112C_arg_1* arg1) {
    arg0->unk_00 = 4;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58 = arg1->unk_58;
}

void func_80711CA8(unk_struct_F8* arg0, s32 arg1, unk_struct_54* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_58.unk_00.unk_00 = *arg2;
}

void func_80711CE4(unk_struct_F8* arg0, s32 arg1, unk_redo_2* arg2) {
    arg0->unk_00 = arg1;
    arg0->unk_04.unk_00 = arg2->unk_00;
    arg0->unk_04.unk_58.unk_00.unk_00 = arg2->unk_58;
}

void func_80711D58(unk_struct_F8* arg0, unk_struct_68* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_58.unk_00 = *arg1;
}

void func_80711DA4(unk_struct_F8* arg0, unk_redo_3* arg1) {
    arg0->unk_00 = 5;
    arg0->unk_04.unk_00 = arg1->unk_00;
    arg0->unk_04.unk_58.unk_00 = arg1->unk_58;
}

void func_80711E28(unk_struct_F8* arg0) {
    f32* var = arg0->unk_04.unk_00.unk_18;

    var[0] += (var[3] - var[0]) * var[6];
    var[1] += (var[4] - var[1]) * var[6];
    var[2] += (var[5] - var[2]) * var[6];
    var[7] += (var[8] - var[7]) * var[9];
    var[10] += (var[12] - var[10]) * var[14];
    var[11] += (var[13] - var[11]) * var[15];
}

// Likely uses the previously defined structs
void func_80711EDC(unk_struct_F8* arg0) {
    unk_struct_20* var2 = &arg0->unk_04.unk_58.unk_00.unk_00.unk_00;
    unk_struct_58* var = &arg0->unk_04.unk_00;

    var->unk_00.x += (var2->unk_00.x - var->unk_00.x) * var2->unk_18;
    var->unk_00.y += (var2->unk_00.y - var->unk_00.y) * var2->unk_18;
    var->unk_00.z += (var2->unk_00.z - var->unk_00.z) * var2->unk_18;
    var->unk_0C.x += (var2->unk_0C.x - var->unk_0C.x) * var2->unk_1C;
    var->unk_0C.y += (var2->unk_0C.y - var->unk_0C.y) * var2->unk_1C;
    var->unk_0C.z += (var2->unk_0C.z - var->unk_0C.z) * var2->unk_1C;
}

void func_80711F90(unk_struct_F8* arg0) {
    f32 temp_fa0;
    f32 sp40;
    f32 sp3C;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_v0;
    f32 sp28;
    unk_struct_58* temp_v0_4;
    unk_struct_54* temp_v1 = &arg0->unk_04.unk_58.unk_00.unk_00;

    temp_v1->unk_30.x += (temp_v1->unk_30.y - temp_v1->unk_30.x) * temp_v1->unk_30.z;
    temp_v1->unk_3C.x += (temp_v1->unk_3C.y - temp_v1->unk_3C.x) * temp_v1->unk_3C.z;
    temp_v1->unk_48.x += (temp_v1->unk_48.y - temp_v1->unk_48.x) * temp_v1->unk_48.z;
    temp_v0 = Math_Round(DEG_TO_FZXANG2(temp_v1->unk_3C.x));

    sp3C = temp_v1->unk_30.x * SIN(temp_v0);
    sp40 = temp_v1->unk_30.x * COS(temp_v0);

    temp_v0 = Math_Round(DEG_TO_FZXANG2(temp_v1->unk_48.x));
    temp_fv0 = SIN(temp_v0) * sp40;
    temp_fv1 = COS(temp_v0) * sp40;

    temp_fa0 = (temp_v1->unk_00.unk_0C.x * temp_fv1) + (temp_v1->unk_24.x * temp_fv0) + (temp_v1->unk_00.unk_18 * sp3C);
    temp_ft5 = (temp_v1->unk_00.unk_0C.y * temp_fv1) + (temp_v1->unk_24.y * temp_fv0) + (temp_v1->unk_00.unk_1C * sp3C);
    sp28 = (temp_v1->unk_00.unk_0C.z * temp_fv1) + (temp_v1->unk_24.z * temp_fv0) + (temp_v1->unk_20 * sp3C);

    temp_v0_4 = &arg0->unk_04.unk_00;
    switch (arg0->unk_00) {
        case 2:
            temp_v0_4->unk_00 = temp_v1->unk_00.unk_00;
            temp_v0_4->unk_0C.x = temp_v1->unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_0C.y = temp_v1->unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_0C.z = temp_v1->unk_00.unk_00.z + sp28;
            break;
        case 3:
            temp_v0_4->unk_0C = temp_v1->unk_00.unk_00;
            temp_v0_4->unk_00.x = temp_v1->unk_00.unk_00.x + temp_fa0;
            temp_v0_4->unk_00.y = temp_v1->unk_00.unk_00.y + temp_ft5;
            temp_v0_4->unk_00.z = temp_v1->unk_00.unk_00.z + sp28;
            break;
    }
}

extern s32 gNumPlayers;
extern s8 gGamePaused;

void func_807121D4(unk_struct_F8* arg0, Player* player) {
    s32 angle;
    f32 var_fv1;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    Racer* racer = &gRacers[player->id];
    Vec3f sp7C;
    Vec3f sp70;
    f32 temp_fv0;
    unk_8008112C_arg_1* temp_s1 = &arg0->unk_04;
    unk_struct_9C* temp_s2 = &arg0->unk_04.unk_58;

    temp_s2->unk_68[1] += (temp_s2->unk_68[2] - temp_s2->unk_68[1]) * temp_s2->unk_68[3];
    temp_s2->unk_68[4] += (temp_s2->unk_68[5] - temp_s2->unk_68[4]) * temp_s2->unk_68[6];
    temp_s2->unk_68[7] += (temp_s2->unk_68[8] - temp_s2->unk_68[7]) * temp_s2->unk_68[9];

    player->unk_20.x = racer->unk_180.x;
    player->unk_20.y = racer->unk_180.y;
    player->unk_20.z = racer->unk_180.z;

    var_fv1 = (racer->unk_18C.x * racer->unk_A8.x) + (racer->unk_18C.y * racer->unk_A8.y) +
              (racer->unk_18C.z * racer->unk_A8.z);
    sp98.x = (temp_s2->unk_00.unk_54.x - player->unk_20.x) + (var_fv1 * racer->unk_A8.x);
    sp98.y = (temp_s2->unk_00.unk_54.y - player->unk_20.y) + (var_fv1 * racer->unk_A8.y);
    sp98.z = (temp_s2->unk_00.unk_54.z - player->unk_20.z) + (var_fv1 * racer->unk_A8.z);
    var_fv1 = sqrtf(SQ(sp98.x) + SQ(sp98.y) + SQ(sp98.z));

    if (var_fv1 < 0.01f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp98.x *= var_fv1;
    sp98.y *= var_fv1;
    sp98.z *= var_fv1;
    if (!gGamePaused) {
        temp_fv0 = temp_s2->unk_68[1];
        temp_s2->unk_00.unk_54.x = player->unk_20.x + (temp_fv0 * sp98.x);
        temp_s2->unk_00.unk_54.y = player->unk_20.y + (temp_fv0 * sp98.y);
        temp_s2->unk_00.unk_54.z = player->unk_20.z + (temp_fv0 * sp98.z);
    }

    temp_fv0 = (racer->unk_18C.x * player->unk_5C.y.x) + (racer->unk_18C.y * player->unk_5C.y.y) +
               (racer->unk_18C.z * player->unk_5C.y.z);
    if (temp_s2->unk_68[8] >= 50.0f) {
        var_fv1 = 0.0f;
    } else {
        var_fv1 = (50.0f - temp_s2->unk_68[8]) * 0.02f;
    }

    temp_s1->unk_00.unk_00.x = player->unk_20.x + (var_fv1 * (racer->unk_18C.x - (temp_fv0 * player->unk_5C.y.x)));
    temp_s1->unk_00.unk_00.y = player->unk_20.y + (var_fv1 * (racer->unk_18C.y - (temp_fv0 * player->unk_5C.y.y)));
    temp_s1->unk_00.unk_00.z = player->unk_20.z + (var_fv1 * (racer->unk_18C.z - (temp_fv0 * player->unk_5C.y.z)));
    sp8C.x = racer->unk_A8.x - player->unk_2C.y.x;
    sp8C.y = racer->unk_A8.y - player->unk_2C.y.y;
    sp8C.z = racer->unk_A8.z - player->unk_2C.y.z;

    var_fv1 = sqrtf(SQ(sp8C.x) + SQ(sp8C.y) + SQ(sp8C.z)) * 0.2f;
    player->unk_2C.y.x += var_fv1 * sp8C.x;
    temp_s2->unk_00.unk_00.unk_30.x = player->unk_2C.y.x;
    player->unk_2C.y.y += var_fv1 * sp8C.y;
    temp_s2->unk_00.unk_00.unk_30.y = player->unk_2C.y.y;
    player->unk_2C.y.z += var_fv1 * sp8C.z;

    temp_s2->unk_00.unk_00.unk_30.z = player->unk_2C.y.z;
    sp7C.x = (temp_s2->unk_00.unk_00.unk_30.y * sp98.z) - (temp_s2->unk_00.unk_00.unk_30.z * sp98.y);
    sp7C.y = (temp_s2->unk_00.unk_00.unk_30.z * sp98.x) - (temp_s2->unk_00.unk_00.unk_30.x * sp98.z);
    sp7C.z = (temp_s2->unk_00.unk_00.unk_30.x * sp98.y) - (temp_s2->unk_00.unk_00.unk_30.y * sp98.x);
    var_fv1 = sqrtf(SQ(sp7C.x) + SQ(sp7C.y) + SQ(sp7C.z));
    if (var_fv1 < 0.1f) {
        return;
    }

    var_fv1 = 1.0f / var_fv1;
    sp7C.x *= var_fv1;
    sp7C.y *= var_fv1;
    sp7C.z *= var_fv1;

    sp70.x = (sp98.y * sp7C.z) - (sp98.z * sp7C.y);
    sp70.y = (sp98.z * sp7C.x) - (sp98.x * sp7C.z);
    sp70.z = (sp98.x * sp7C.y) - (sp98.y * sp7C.x);

    var_fv1 = 1.0f / sqrtf(SQ(sp70.x) + SQ(sp70.y) + SQ(sp70.z));

    sp70.x *= var_fv1;
    sp70.y *= var_fv1;
    sp70.z *= var_fv1;
    angle = Math_Round(DEG_TO_FZXANG2(temp_s2->unk_68[4]));

    var_fv1 = temp_s2->unk_68[1] * SIN(angle) *
              ((sp70.x * racer->unk_C0.y.x) + (sp70.y * racer->unk_C0.y.y) + (sp70.z * racer->unk_C0.y.z));
    spA4 = temp_s2->unk_68[1] * COS(angle);

    angle = Math_Round(DEG_TO_FZXANG2(temp_s2->unk_68[8]));
    temp_fv0 = COS(angle) * spA4;
    spA4 = SIN(angle) * spA4;
    temp_s1->unk_00.unk_0C.x = player->unk_20.x + (spA4 * sp7C.x) + (temp_fv0 * sp98.x) + (var_fv1 * sp70.x);
    temp_s1->unk_00.unk_0C.y = player->unk_20.y + (spA4 * sp7C.y) + (temp_fv0 * sp98.y) + (var_fv1 * sp70.y);
    temp_s1->unk_00.unk_0C.z = player->unk_20.z + (spA4 * sp7C.z) + (temp_fv0 * sp98.z) + (var_fv1 * sp70.z);
    temp_s2->unk_00.unk_00.unk_24.x = temp_s1->unk_00.unk_00.x - temp_s1->unk_00.unk_0C.x;
    temp_s2->unk_00.unk_00.unk_24.y = temp_s1->unk_00.unk_00.y - temp_s1->unk_00.unk_0C.y;
    temp_s2->unk_00.unk_00.unk_24.z = temp_s1->unk_00.unk_00.z - temp_s1->unk_00.unk_0C.z;
    func_806F6D8C((Mtx3F*) &temp_s2->unk_00.unk_00.unk_24);
    if (!gGamePaused) {
        temp_s1->unk_00.unk_18[3] = temp_s1->unk_00.unk_18[0] = temp_s2->unk_00.unk_00.unk_30.x;
        temp_s1->unk_00.unk_18[4] = temp_s1->unk_00.unk_18[1] = temp_s2->unk_00.unk_00.unk_30.y;
        temp_s1->unk_00.unk_18[5] = temp_s1->unk_00.unk_18[2] = temp_s2->unk_00.unk_00.unk_30.z;
    }
    temp_s1->unk_00.unk_18[10] = 0.0f;
    temp_s1->unk_00.unk_18[12] = 0.0f;
    if (gNumPlayers == 2) {
        temp_s1->unk_00.unk_18[11] = -15.0f;
        temp_s1->unk_00.unk_18[13] = -15.0f;
    } else {
        temp_s1->unk_00.unk_18[11] = 77.0f;
        temp_s1->unk_00.unk_18[13] = 77.0f;
    }
}

void func_80712864(unk_struct_F8* arg0) {
    unk_struct_58* var = &arg0->unk_04.unk_00;
    unk_struct_68* var2 = &arg0->unk_04.unk_58.unk_00;

    var2->unk_00.unk_30.x += (var2->unk_00.unk_3C.x - var2->unk_00.unk_30.x) * var2->unk_60;
    var2->unk_00.unk_30.y += (var2->unk_00.unk_3C.y - var2->unk_00.unk_30.y) * var2->unk_60;
    var2->unk_00.unk_30.z += (var2->unk_00.unk_3C.z - var2->unk_00.unk_30.z) * var2->unk_60;

    var2->unk_00.unk_48.x += (var2->unk_54.x - var2->unk_00.unk_48.x) * var2->unk_64;
    var2->unk_00.unk_48.y += (var2->unk_54.y - var2->unk_00.unk_48.y) * var2->unk_64;
    var2->unk_00.unk_48.z += (var2->unk_54.z - var2->unk_00.unk_48.z) * var2->unk_64;

    var->unk_00.x = var2->unk_00.unk_00.unk_00.x + (var2->unk_00.unk_24.x * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_00.unk_18 * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.x * var2->unk_00.unk_30.z);
    var->unk_00.y = var2->unk_00.unk_00.unk_00.y + (var2->unk_00.unk_24.y * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_00.unk_1C * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.y * var2->unk_00.unk_30.z);
    var->unk_00.z = var2->unk_00.unk_00.unk_00.z + (var2->unk_00.unk_24.z * var2->unk_00.unk_30.x) +
                    (var2->unk_00.unk_20 * var2->unk_00.unk_30.y) +
                    (var2->unk_00.unk_00.unk_0C.z * var2->unk_00.unk_30.z);

    var->unk_0C.x = var2->unk_00.unk_00.unk_00.x + (var2->unk_00.unk_24.x * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_00.unk_18 * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.x * var2->unk_00.unk_48.z);
    var->unk_0C.y = var2->unk_00.unk_00.unk_00.y + (var2->unk_00.unk_24.y * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_00.unk_1C * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.y * var2->unk_00.unk_48.z);
    var->unk_0C.z = var2->unk_00.unk_00.unk_00.z + (var2->unk_00.unk_24.z * var2->unk_00.unk_48.x) +
                    (var2->unk_00.unk_20 * var2->unk_00.unk_48.y) +
                    (var2->unk_00.unk_00.unk_0C.z * var2->unk_00.unk_48.z);
}

void func_80712AA8(unk_struct_F8* arg0, Player* player) {

    switch (arg0->unk_00) {
        case 1:
            func_80711EDC(arg0);
            break;
        case 4:
            func_807121D4(arg0, player);
            break;
        case 2:
        case 3:
            func_80711F90(arg0);
            break;
        case 5:
            func_80712864(arg0);
            break;
    }
    func_80711E28(arg0);
}

void func_80712B34(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_0C.x = arg2->x;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_00.unk_0C.z = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_80712BBC(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_30.y = arg2->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg2->y;
        temp_v0->unk_00.unk_00.unk_3C.y = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

void func_80712C44(unk_struct_F8* arg0, Vec3f* arg1, Mtx3F* arg2, Vec3f* arg3, Vec3f* arg4, Vec3f* arg5, f32* arg6) {
    unk_struct_58* temp_v0_4 = &arg0->unk_04.unk_00;
    unk_struct_68* temp_v0 = &arg0->unk_04.unk_58.unk_00;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_00.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_00.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_00.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_00.unk_00.unk_0C.x += arg2->x.x * 0.2f;
        temp_v0->unk_00.unk_00.unk_0C.y += arg2->x.y * 0.2f;
        temp_v0->unk_00.unk_00.unk_0C.z += arg2->x.z * 0.2f;
        temp_v0->unk_00.unk_00.unk_18 += arg2->y.x * 0.2f;
        temp_v0->unk_00.unk_00.unk_1C += arg2->y.y * 0.2f;
        temp_v0->unk_00.unk_20 += arg2->y.z * 0.2f;
        temp_v0->unk_00.unk_24.x += arg2->z.x * 0.2f;
        temp_v0->unk_00.unk_24.y += arg2->z.y * 0.2f;
        temp_v0->unk_00.unk_24.z += arg2->z.z * 0.2f;
        func_806F6D8C((Mtx3F*) &temp_v0->unk_00.unk_00.unk_0C);
    }
    if (arg3 != NULL) {
        temp_v0->unk_00.unk_3C.x = arg3->x;
        temp_v0->unk_00.unk_3C.y = arg3->y;
        temp_v0->unk_00.unk_3C.z = arg3->z;
    }
    if (arg4 != NULL) {
        temp_v0->unk_54.x = arg4->x;
        temp_v0->unk_54.y = arg4->y;
        temp_v0->unk_54.z = arg4->z;
    }
    if (arg5 != NULL) {
        temp_v0_4->unk_18[3] = arg5->x;
        temp_v0_4->unk_18[4] = arg5->y;
        temp_v0_4->unk_18[5] = arg5->z;
    }
    if (arg6 != NULL) {
        temp_v0_4->unk_18[8] = *arg6;
    }
}

void func_80712DE0(unk_struct_F8* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, f32* arg4) {
    unk_8008112C_arg_1* temp_v0_3 = &arg0->unk_04;
    unk_struct_9C* temp_v0 = &arg0->unk_04.unk_58;

    if (arg1 != NULL) {
        temp_v0->unk_00.unk_00.unk_48.x = arg1->x;
        temp_v0->unk_00.unk_00.unk_48.y = arg1->y;
        temp_v0->unk_00.unk_00.unk_48.z = arg1->z;
    }
    if (arg2 != NULL) {
        temp_v0->unk_68[2] = arg2->x;
        temp_v0->unk_68[8] = arg2->y;
        temp_v0->unk_68[5] = arg2->z;
    }
    if (arg3 != NULL) {
        temp_v0_3->unk_00.unk_18[3] = arg3->x;
        temp_v0_3->unk_00.unk_18[4] = arg3->y;
        temp_v0_3->unk_00.unk_18[5] = arg3->z;
    }
    if (arg4 != NULL) {
        arg0->unk_04.unk_00.unk_18[8] = *arg4;
    }
}

f32 func_80712E68(CourseSegment** arg0, f32 arg1, f32 arg2) {
    f32 temp_fs3;
    s32 i;
    s32 sp54;
    s32 pad[4];
    Vec3f sp80;
    Mtx3F sp5C;

    sp54 = (s32) arg2 / 20;
    temp_fs3 = Course_SplineGetBasis(*arg0, arg1, &sp5C, 0.0f);

    for (i = 0; i < sp54; i++) {
        arg1 += 20.0f / temp_fs3;
        if (arg1 >= 1.0f) {
            *arg0 = (*arg0)->next;
            arg1 -= 1.0f;
            arg1 *= (temp_fs3 / Course_SplineGetTangent(*arg0, 0.0f, &sp80));
        }
    }

    arg1 += ((arg2 - ((f32) sp54 * 20.0f)) / temp_fs3);
    if (arg1 >= 1.0f) {
        *arg0 = (*arg0)->next;
        arg1 -= 1.0f;
        arg1 *= (temp_fs3 / Course_SplineGetTangent(*arg0, 0.0f, &sp80));
    }
    return arg1;
}

Mtx3F* func_80712FE4(Mtx3F* arg0, CourseSegment* arg1, f32 arg2) {
    s32 pad;
    f32 sp40;
    Mtx3F sp1C;

    Course_SplineGetBasis(arg1, arg2, &sp1C, Course_SplineGetLengthInfo(arg1, arg2, &sp40));
    *arg0 = sp1C;

    return arg0;
}

void func_80713064(Player* player, unk_8008112C_arg_1* arg1, unk_struct_9C* arg2, s32 arg3) {
    Vec3f* var_v0;

    if (arg3 == 2) {
        var_v0 = &D_80776A78[player->cameraSetting];
    } else {
        var_v0 = &D_80776A48[player->cameraSetting];
    }
    arg2->unk_68[2] = var_v0->y;
    arg2->unk_68[5] = var_v0->z;
    arg1->unk_00.unk_18[8] = player->unk_14 = var_v0->x;

    player->unk_10 = 2;

    switch (player->cameraSetting) {
        case 1:
        case 2:
            player->unk_10 |= 1;
            break;
        default:
            break;
    }
}

void func_807130F8(Player* player, unk_struct_F8* arg1) {
    player->unk_50 = arg1->unk_04.unk_00.unk_0C;

    player->unk_88 = arg1->unk_04.unk_00.unk_00;

    player->unk_5C.y.x = arg1->unk_04.unk_00.unk_18[0];
    player->unk_5C.y.y = arg1->unk_04.unk_00.unk_18[1];
    player->unk_5C.y.z = arg1->unk_04.unk_00.unk_18[2];
    player->unk_94.x = arg1->unk_04.unk_00.unk_18[7];
    player->unk_94.y = arg1->unk_04.unk_00.unk_18[10];
    player->unk_94.z = arg1->unk_04.unk_00.unk_18[11];
}

void func_8071315C(Player* player) {
    Mtx3F* temp_a0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;

    player->unk_5C.x.x = player->unk_88.x - player->unk_50.x;
    player->unk_5C.x.y = player->unk_88.y - player->unk_50.y;
    player->unk_5C.x.z = player->unk_88.z - player->unk_50.z;

    func_806F6D8C(&player->unk_5C);
    temp_fv0 = player->unk_5C.x.x;
    temp_fv1 = player->unk_5C.x.z;
    temp_fv0_2 = sqrtf(SQ(temp_fv0) + SQ(temp_fv1));
    if (temp_fv0_2 != 0.0f) {
        player->unk_80 = (f32) (player->unk_5C.x.x / temp_fv0_2);
        player->unk_84 = (f32) (player->unk_5C.x.z / temp_fv0_2);
    }
}

void func_80713204(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    arg0->m[0][0] = (arg1->m[0][0] * arg2->m[0][0]) + (arg1->m[2][0] * arg2->m[0][2]);
    arg0->m[0][1] = (arg1->m[1][1] * arg2->m[0][1]) + (arg1->m[2][1] * arg2->m[0][2]);
    arg0->m[0][2] = arg1->m[2][2] * arg2->m[0][2];
    arg0->m[0][3] = -arg2->m[0][2];
    arg0->m[1][0] = (arg1->m[0][0] * arg2->m[1][0]) + (arg1->m[2][0] * arg2->m[1][2]);
    arg0->m[1][1] = (arg1->m[1][1] * arg2->m[1][1]) + (arg1->m[2][1] * arg2->m[1][2]);
    arg0->m[1][2] = arg1->m[2][2] * arg2->m[1][2];
    arg0->m[1][3] = -arg2->m[1][2];
    arg0->m[2][0] = (arg1->m[0][0] * arg2->m[2][0]) + (arg1->m[2][0] * arg2->m[2][2]);
    arg0->m[2][1] = (arg1->m[1][1] * arg2->m[2][1]) + (arg1->m[2][1] * arg2->m[2][2]);
    arg0->m[2][2] = arg1->m[2][2] * arg2->m[2][2];
    arg0->m[2][3] = -arg2->m[2][2];
    arg0->m[3][0] = (arg1->m[0][0] * arg2->m[3][0]) + (arg1->m[2][0] * arg2->m[3][2]);
    arg0->m[3][1] = (arg1->m[1][1] * arg2->m[3][1]) + (arg1->m[2][1] * arg2->m[3][2]);
    arg0->m[3][2] = (arg1->m[2][2] * arg2->m[3][2]) + arg1->m[3][2];
    arg0->m[3][3] = -arg2->m[3][2];
}

void func_807133A0(MtxF* mtxF, Mtx* mtx2) {
    s32 pad[3];
    s64 var_v1;
    f32 temp_fv0;
    s32 i;
    s32 j;
    Mtx* mtx = mtx2;

    for (i = 3; i >= 0; i--) {
        for (j = 3; j >= 0; j--) {
            temp_fv0 = mtxF->m[i][j] * 65536.0f;
            if (temp_fv0 < 0.0f) {
                var_v1 = temp_fv0 - 0.5f;
            } else {
                var_v1 = temp_fv0 + 0.5f;
            }

            mtx->u.i[i][j] = var_v1 >> 0x10;
            mtx->u.f[i][j] = var_v1 & 0xFFFF;
        }
    }
}

void func_807134AC(GfxPool* arg0, Player* player) {
    Vec3f sp74;
    Vec3f sp68;
    f32 var_fv0;
    f32 temp_fa0;
    s32 pad[2];

    Matrix_SetFrustrum(&arg0->unk_1A008[player->id], &player->unk_11C, player->unk_94.x, player->unk_A0, player->unk_A4,
                       player->unk_A8, player->unk_94.y, player->unk_AC, player->unk_94.z, &player->unk_118);
    sp68 = player->unk_50;
    sp74 = player->unk_88;

    Matrix_SetLookAt(&arg0->unk_1A108[player->id], &player->unk_15C, sp68.x, sp68.y, sp68.z, sp74.x, sp74.y, sp74.z,
                     player->unk_5C.y.x, player->unk_5C.y.y, player->unk_5C.y.z);
    func_80713204(&player->unk_19C, &player->unk_11C, &player->unk_15C);
    if (gNumPlayers != 2) {
        if (player->unk_19C.m[3][1] >= 0.0f) {
            var_fv0 = player->unk_19C.m[3][1];
        } else {
            var_fv0 = -player->unk_19C.m[3][1];
        }
        if (var_fv0 > 30000.0f) {
            var_fv0 -= 30000.0f;
            var_fv0 /= 2767.0f;
            if (var_fv0 >= 1.0f) {
                var_fv0 = 1.0f;
            }
            temp_fa0 = player->unk_94.x + ((85.0f - player->unk_94.x) * var_fv0);

            Matrix_SetFrustrum(&arg0->unk_1A008[player->id], &player->unk_11C, temp_fa0, player->unk_A0, player->unk_A4,
                               player->unk_A8, player->unk_94.y, player->unk_AC, player->unk_94.z, &player->unk_118);
            func_80713204(&player->unk_19C, &player->unk_11C, &player->unk_15C);
        }
    }
    func_807133A0(&player->unk_19C, &arg0->unk_1A208[player->id]);
}

extern s32 D_807A16C8;

void func_8071370C(Player* arg0) {
    Racer* racer;
    f32 var_fv1;
    f32 var_fa0;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    racer = &gRacers[D_807A16C8];
    sp20 = racer->unk_0C.unk_34.x - arg0->unk_50.x;
    sp1C = racer->unk_0C.unk_34.y - arg0->unk_50.y;
    sp18 = racer->unk_0C.unk_34.z - arg0->unk_50.z;

    var_fv1 = sqrtf((sp20 * sp20) + (sp1C * sp1C) + (sp18 * sp18));

    if (var_fv1 != 0.0f) {
        var_fa0 = -((arg0->unk_5C.z.x * sp20) + (sp1C * arg0->unk_5C.z.y) + (sp18 * arg0->unk_5C.z.z)) / var_fv1;
        var_fv1 *= var_fa0;
    }
    if ((var_fv1 >= -1000.0f) && (var_fv1 <= 1000.0f)) {
        Audio_SetEnemyEnginePan(((var_fv1 + 1000.0f) / 2000.0f) * 127.0f);
    }
}

void func_807138CC(f32* x, f32* y, f32* z) {
    f32 normalizeScale;

    normalizeScale = 1.0f / (SQ(*x) + SQ(*y) + SQ(*z));
    *x *= normalizeScale;
    *y *= normalizeScale;
    *z *= normalizeScale;
}

void func_8071391C(MtxF* mtxF, f32 angle, f32 x, f32 y, f32 z) {
    s32 pad[2];
    f32 temp_fa0;
    f32 temp_ft1;
    f32 cos;
    f32 sp18;
    f32 temp_fv0;
    f32 sin;
    s32 temp_v0;

    func_807138CC(&x, &y, &z);
    temp_v0 = Math_Round(DEG_TO_FZXANG2(angle));
    sin = SIN(temp_v0);
    cos = COS(temp_v0);
    temp_fv0 = 1.0f - cos;
    temp_ft1 = x * y * temp_fv0;
    temp_fa0 = y * z * temp_fv0;
    sp18 = z * x * temp_fv0;
    mtxF->m[0][0] = ((1.0f - SQ(x)) * cos) + SQ(x);
    mtxF->m[2][1] = temp_fa0 - (x * sin);
    mtxF->m[1][2] = (x * sin) + temp_fa0;
    mtxF->m[1][1] = ((1.0f - SQ(y)) * cos) + SQ(y);
    mtxF->m[2][0] = (y * sin) + sp18;
    mtxF->m[0][2] = sp18 - (y * sin);
    mtxF->m[2][2] = ((1.0f - SQ(z)) * cos) + SQ(z);
    mtxF->m[1][0] = temp_ft1 - (z * sin);
    mtxF->m[0][1] = (z * sin) + temp_ft1;
    mtxF->m[3][3] = 1.0f;
    mtxF->m[0][3] = mtxF->m[1][3] = mtxF->m[2][3] = mtxF->m[3][0] = mtxF->m[3][1] = mtxF->m[3][2] = 0.0f;
}

typedef struct unk_800832EC_arg_2 {
    u32 unk_00;
    u32 unk_04;
    s32* unk_08;
    u8* unk_0C;
} unk_800832EC_arg_2;

void func_80713AC0(unk_800832EC_arg_2* arg0) {
    u32 i;

    for (i = 0; i < arg0->unk_04; i++) {
        arg0->unk_08[i] = 0;
    }
}

u8* func_80713B00(u32 arg0, unk_800832EC_arg_2* arg1) {
    s32 var_v0;
    u32 temp_a2;
    u32 temp_v0;
    s32 var_a0;
    u32 var_a3;

    if ((arg0 % arg1->unk_00) != 0) {
        var_v0 = 1;
    } else {
        var_v0 = 0;
    }

    temp_a2 = var_v0 + (arg0 / arg1->unk_00);
    if (arg1->unk_04 < temp_a2) {
        return NULL;
    }

    temp_v0 = (arg1->unk_04 - temp_a2) + 1;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
        for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
            if (arg1->unk_08[var_a0 + var_a3] != 0) {
                break;
            }
        }
        if (var_a3 >= temp_a2) {
            for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
                arg1->unk_08[var_a0 + var_a3] = temp_a2 - var_a3;
            }
            return &arg1->unk_0C[arg1->unk_00 * var_a0];
        }
    }
    return NULL;
}

void func_80713C9C(u8* arg0, unk_800832EC_arg_2* arg1) {
    s32 temp_v1;
    u32 i;
    u32 temp_lo;

    if (arg0 != NULL) {
        temp_lo = (size_t) (arg0 - arg1->unk_0C) / arg1->unk_00;
        temp_v1 = arg1->unk_08[temp_lo];

        for (i = 0; i < temp_v1; i++) {
            arg1->unk_08[temp_lo + i] = 0;
        }
    }
}

u8* func_80713D78(u8* arg0, u32 arg1, unk_800832EC_arg_2* arg2) {
    u8* temp_v0;
    u32 var_a2;
    s32 var_v1;

    temp_v0 = func_80713B00(arg1, arg2);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if (arg0 == NULL) {
        return temp_v0;
    }
    var_v1 = arg2->unk_08[(size_t) (arg0 - arg2->unk_0C) / arg2->unk_00];
    var_a2 = arg2->unk_00 * var_v1;
    if (arg1 < var_a2) {
        var_a2 = arg1;
    }

    bcopy(arg0, temp_v0, var_a2);
    func_80713C9C(arg0, arg2);
    return temp_v0;
}

extern s32 gGameMode;
extern GfxPool D_1000000;
extern Player gPlayers[];

Gfx* func_80713E38(Gfx* gfx, s32 arg1, s32 playerIndex) {
    Player* player = &gPlayers[playerIndex];

    switch (player->unk_E0) {
        case 1:
            gSPViewport(gfx++, &D_1000000.unk_362C8[playerIndex]);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, player->unk_B0, player->unk_B4, player->unk_B8, player->unk_BC);
            break;
        default:
            gfx = func_806F6360(gfx, arg1);
            if ((gNumPlayers == 1) && (gGameMode != GAMEMODE_RECORDS) && (gGameMode != GAMEMODE_GP_END_CS)) {
                gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 16, 308, 224);
            }
            break;
    }

    return gfx;
}

void func_80713F8C(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {

    D_807A10A0[arg0].unk_04.unk_58.unk_68[1] = D_807A10A0[arg0].unk_04.unk_58.unk_68[2] = arg1;
    D_807A10A0[arg0].unk_04.unk_58.unk_68[4] = D_807A10A0[arg0].unk_04.unk_58.unk_68[5] = arg2;
    D_807A10A0[arg0].unk_04.unk_58.unk_68[7] = D_807A10A0[arg0].unk_04.unk_58.unk_68[8] = arg3;
}

void func_80713FD4(unk_800E5D70* arg0, unk_struct_F8* arg1) {
    arg0->unk_00 = arg1;
}

void func_80713FDC(unk_800E5D70* arg0, unk_struct_20_2* arg1) {
    arg0->unk_0C = arg1;
}

void func_80713FE4(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2, Racer* arg3) {
    arg0->unk_10 = arg1;
    arg0->unk_14 = arg2;
    arg0->unk_18 = arg3;
}

void func_80713FF4(unk_800E5D70* arg0, Vec3f* arg1, Mtx3F* arg2) {
    arg0->unk_1C = arg1;
    arg0->unk_20 = arg2;
}

void func_80714000(unk_800E5D70* arg0, unk_struct_C* arg1) {
    arg0->unk_04 = arg1;
    arg0->unk_08 = 0;
}

void func_8071400C(unk_800E5D70* arg0, s32 arg1) {
    func_80715768(arg0->unk_0C, arg1);
}

void func_8071402C(unk_800E5D70* arg0, f32* arg1) {
    arg0->unk_00->unk_04.unk_00.unk_18[13] = *arg1;
}

bool func_8071403C(unk_800E5D70* arg0) {
    bool ret;
    unk_struct_C* var_s0;

    while (true) {
        ret = false;
        var_s0 = arg0->unk_04;
        if (var_s0 == NULL) {
            return true;
        }

        if (var_s0->unk_04 != NULL) {
            ((void (*)(unk_800E5D70*, void*)) var_s0->unk_04)(arg0, var_s0->unk_08);
        }
        switch (var_s0->unk_00) {
            case 0:
                arg0->unk_04++;
                continue;
            case -1:
                arg0->unk_08 = 0;
                var_s0 = NULL;
                ret = true;
                break;
            case -2:
                arg0->unk_08++;
                ret = true;
                break;
            default:
                if (++arg0->unk_08 >= var_s0->unk_00) {
                    var_s0++;
                    arg0->unk_08 = 0;
                }
                break;
        }
        break;
    }

    arg0->unk_04 = var_s0;
    return ret;
}

void func_80714130(unk_800E5D70* arg0, unk_redo_1* arg1) {
    func_80711B6C(arg0->unk_00, arg1);
}

void func_80714150(unk_800E5D70* arg0, unk_redo_2* arg1) {
    func_80711CE4(arg0->unk_00, 2, arg1);
}

void func_80714178(unk_800E5D70* arg0, unk_redo_2* arg1) {
    func_80711CE4(arg0->unk_00, 3, arg1);
}

void func_807141A0(unk_800E5D70* arg0, unk_8008112C_arg_1* arg1) {
    func_80711C30(arg0->unk_00, arg1);
}

void func_807141C0(unk_800E5D70* arg0, unk_redo_3* arg1) {
    func_80711DA4(arg0->unk_00, arg1);
}

void func_80083754(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80715E1C(sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;
    func_80712B34(arg0->unk_00, &sp2C, &sp38[1], NULL, NULL);
}

void func_80714268(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp34[3];
    Vec3f sp28;

    func_80715E60(sp34, arg0->unk_0C, arg1);
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;
    func_80712B34(arg0->unk_00, &sp28, &sp34[1], &sp34[2], NULL);
}

void func_807142F0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80715EC0(&sp34, arg0->unk_0C, arg1);
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;
    func_80712B34(arg0->unk_00, &sp28, &sp34.unk_00[1], NULL, &sp34.unk_18);
}

void func_8071437C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80715F20(&sp38, arg0->unk_0C, arg1);
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;
    func_80712B34(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80714408(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp48[2];
    Vec3f sp3C;
    Vec3f sp30;

    func_80715E1C(sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48[0].x + arg0->unk_10->x;
    sp3C.y = sp48[0].y + arg0->unk_10->y;
    sp3C.z = sp48[0].z + arg0->unk_10->z;

    sp30.x =
        arg0->unk_1C->x + arg0->unk_20->x.x * sp48[1].z + arg0->unk_20->y.x * sp48[1].y + arg0->unk_20->z.x * sp48[1].x;
    sp30.y =
        arg0->unk_1C->y + arg0->unk_20->x.y * sp48[1].z + arg0->unk_20->y.y * sp48[1].y + arg0->unk_20->z.y * sp48[1].x;
    sp30.z =
        arg0->unk_1C->z + arg0->unk_20->x.z * sp48[1].z + arg0->unk_20->y.z * sp48[1].y + arg0->unk_20->z.z * sp48[1].x;
    func_80712B34(arg0->unk_00, &sp3C, &sp30, NULL, NULL);
}

void func_80714538(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp44[3];
    Vec3f sp38;
    Vec3f sp2C;

    func_80715E60(sp44, arg0->unk_0C, arg1);
    sp38.x = sp44[0].x + arg0->unk_10->x;
    sp38.y = sp44[0].y + arg0->unk_10->y;
    sp38.z = sp44[0].z + arg0->unk_10->z;

    sp2C.x =
        arg0->unk_1C->x + arg0->unk_20->x.x * sp44[1].z + arg0->unk_20->y.x * sp44[1].y + arg0->unk_20->z.x * sp44[1].x;
    sp2C.y =
        arg0->unk_1C->y + arg0->unk_20->x.y * sp44[1].z + arg0->unk_20->y.y * sp44[1].y + arg0->unk_20->z.y * sp44[1].x;
    sp2C.z =
        arg0->unk_1C->z + arg0->unk_20->x.z * sp44[1].z + arg0->unk_20->y.z * sp44[1].y + arg0->unk_20->z.z * sp44[1].x;
    func_80712B34(arg0->unk_00, &sp38, &sp2C, &sp44[2], NULL);
}

void func_80714668(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp44;
    Vec3f sp38;
    Vec3f sp2C;

    func_80715EC0(&sp44, arg0->unk_0C, arg1);
    sp38.x = sp44.unk_00[0].x + arg0->unk_10->x;
    sp38.y = sp44.unk_00[0].y + arg0->unk_10->y;
    sp38.z = sp44.unk_00[0].z + arg0->unk_10->z;

    sp2C.x = arg0->unk_1C->x + arg0->unk_20->x.x * sp44.unk_00[1].z + arg0->unk_20->y.x * sp44.unk_00[1].y +
             arg0->unk_20->z.x * sp44.unk_00[1].x;
    sp2C.y = arg0->unk_1C->y + arg0->unk_20->x.y * sp44.unk_00[1].z + arg0->unk_20->y.y * sp44.unk_00[1].y +
             arg0->unk_20->z.y * sp44.unk_00[1].x;
    sp2C.z = arg0->unk_1C->z + arg0->unk_20->x.z * sp44.unk_00[1].z + arg0->unk_20->y.z * sp44.unk_00[1].y +
             arg0->unk_20->z.z * sp44.unk_00[1].x;
    func_80712B34(arg0->unk_00, &sp38, &sp2C, NULL, &sp44.unk_18);
}

void func_8071479C(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp48;
    Vec3f sp3C;
    Vec3f sp30;

    func_80715F20(&sp48, arg0->unk_0C, arg1);
    sp3C.x = sp48.unk_00[0].x + arg0->unk_10->x;
    sp3C.y = sp48.unk_00[0].y + arg0->unk_10->y;
    sp3C.z = sp48.unk_00[0].z + arg0->unk_10->z;

    sp30.x = arg0->unk_1C->x + arg0->unk_20->x.x * sp48.unk_00[1].z + arg0->unk_20->y.x * sp48.unk_00[1].y +
             arg0->unk_20->z.x * sp48.unk_00[1].x;
    sp30.y = arg0->unk_1C->y + arg0->unk_20->x.y * sp48.unk_00[1].z + arg0->unk_20->y.y * sp48.unk_00[1].y +
             arg0->unk_20->z.y * sp48.unk_00[1].x;
    sp30.z = arg0->unk_1C->z + arg0->unk_20->x.z * sp48.unk_00[1].z + arg0->unk_20->y.z * sp48.unk_00[1].y +
             arg0->unk_20->z.z * sp48.unk_00[1].x;
    func_80712B34(arg0->unk_00, &sp3C, &sp30, &sp48.unk_00[2], &sp48.unk_24);
}

void func_807148D0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_8071491C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80714968(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_807149B8(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712B34(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714A08(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20[0], &sp20[1], NULL, NULL);
}

void func_80714A54(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24[0], &sp24[1], &sp24[2], NULL);
}

void func_80714AA0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24.unk_00[0], &sp24.unk_00[1], NULL, &sp24.unk_18);
}

void func_80714AF0(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20.unk_00[0], &sp20.unk_00[1], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714B40(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp20[2];

    func_80715E1C(sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20[1], &sp20[0], NULL, NULL);
}

void func_80714B8C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    Vec3f sp24[3];

    func_80715E60(sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24[1], &sp24[0], &sp24[2], NULL);
}

void func_80714BD8(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    unk_80085434_arg_0 sp24;

    func_80715EC0(&sp24, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp24.unk_00[1], &sp24.unk_00[0], NULL, &sp24.unk_18);
}

void func_80714C28(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    unk_80085494_arg_0 sp20;

    func_80715F20(&sp20, arg0->unk_0C, arg1);
    func_80712BBC(arg0->unk_00, &sp20.unk_00[1], &sp20.unk_00[0], &sp20.unk_00[2], &sp20.unk_24);
}

void func_80714C78(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    Vec3f sp3C[2];
    Vec3f sp30;
    s32 pad;

    func_80715E1C(sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp3C[0].x;
    sp30.x = COS(sp64) * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - SIN(sp64) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp30, &sp3C[1], NULL, NULL);
}

void func_80714D90(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 sp6C;
    s32 temp_v0;
    f32 sp64;
    f32 sp60;
    f32 temp_fv0;
    Vec3f sp38[3];
    Vec3f sp2C;
    s32 pad;

    func_80715E60(sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp6C = Math_Round(DEG_TO_FZXANG2(sp64));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp60));
    temp_fv0 = COS(temp_v0) * sp38[0].x;
    sp2C.x = COS(sp6C) * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - SIN(sp6C) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp2C, &sp38[1], &sp38[2], NULL);
}

void func_80714EA8(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 sp64;
    s32 temp_v0;
    f32 sp5C;
    f32 sp58;
    f32 temp_fv0;
    unk_80085434_arg_0 sp38;
    Vec3f sp2C;
    s32 pad;

    func_80715EC0(&sp38, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp64 = Math_Round(DEG_TO_FZXANG2(sp5C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp58));
    temp_fv0 = COS(temp_v0) * sp38.unk_00[0].x;
    sp2C.x = COS(sp64) * temp_fv0 + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp2C.z = arg0->unk_10->z - SIN(sp64) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp2C, &sp38.unk_00[1], NULL, &sp38.unk_18);
}

void func_80714FC4(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 sp74;
    s32 temp_v0;
    f32 sp6C;
    f32 sp68;
    f32 temp_fv0;
    unk_80085494_arg_0 sp3C;
    Vec3f sp30;
    s32 pad;

    func_80715F20(&sp3C, arg0->unk_0C, arg1);
    //! @bug uninitialised angles
    sp74 = Math_Round(DEG_TO_FZXANG2(sp6C));
    temp_v0 = Math_Round(DEG_TO_FZXANG2(sp68));
    temp_fv0 = COS(temp_v0) * sp3C.unk_00[0].x;
    sp30.x = COS(sp74) * temp_fv0 + arg0->unk_10->x;
    sp30.y = sp3C.unk_00[0].x * SIN(temp_v0) + arg0->unk_10->y;
    sp30.z = arg0->unk_10->z - SIN(sp74) * temp_fv0;
    func_80712BBC(arg0->unk_00, &sp30, &sp3C.unk_00[1], &sp3C.unk_00[2], &sp3C.unk_24);
}

void func_807150E0(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    Vec3f sp64[2];
    Vec3f sp58;
    Mtx3F sp34;

    func_80715E1C(sp64, arg0->unk_0C, arg1->unk_00);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80712C44(arg0->unk_00, &sp58, &sp34, &sp64[0], &sp64[1], NULL, NULL);
}

void func_8071518C(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad;
    Vec3f sp60[3];
    Vec3f sp54;
    Mtx3F sp30;

    func_80715E60(sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80712C44(arg0->unk_00, &sp54, &sp30, &sp60[0], &sp60[1], &sp60[2], NULL);
}

void func_8071523C(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad;
    unk_80085434_arg_0 sp60;
    Vec3f sp54;
    Mtx3F sp30;

    func_80715EC0(&sp60, arg0->unk_0C, arg1);
    sp54.x = arg0->unk_10->x;
    sp54.y = arg0->unk_10->y;
    sp54.z = arg0->unk_10->z;
    sp30 = *arg0->unk_14;
    func_80712C44(arg0->unk_00, &sp54, &sp30, &sp60.unk_00[0], &sp60.unk_00[1], NULL, &sp60.unk_18);
}

void func_807152EC(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad;
    unk_80085494_arg_0 sp64;
    Vec3f sp58;
    Mtx3F sp34;

    func_80715F20(&sp64, arg0->unk_0C, arg1);
    sp58.x = arg0->unk_10->x;
    sp58.y = arg0->unk_10->y;
    sp58.z = arg0->unk_10->z;
    sp34 = *arg0->unk_14;
    func_80712C44(arg0->unk_00, &sp58, &sp34, &sp64.unk_00[0], &sp64.unk_00[1], &sp64.unk_00[2], &sp64.unk_24);
}

// TODO: sort out unk_struct_20 and unk_struct_68 (conflicting struct copies)
void func_807153A0(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp38[2];
    Vec3f sp2C;

    func_80715E1C(sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp2C.x = sp38[0].x + arg0->unk_10->x;
    sp2C.y = sp38[0].y + arg0->unk_10->y;
    sp2C.z = sp38[0].z + arg0->unk_10->z;

    func_80712DE0(arg0->unk_00, &sp2C, &sp38[1], 0, 0);
}

void func_80715490(unk_800E5D70* arg0, unk_struct_14* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    Vec3f sp34[3];
    Vec3f sp28;

    func_80715E60(sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp28.x = sp34[0].x + arg0->unk_10->x;
    sp28.y = sp34[0].y + arg0->unk_10->y;
    sp28.z = sp34[0].z + arg0->unk_10->z;

    func_80712DE0(arg0->unk_00, &sp28, &sp34[1], &sp34[2], 0);
}

void func_80715580(unk_800E5D70* arg0, unk_80085434_arg_2* arg1) {
    s32 pad[6];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085434_arg_0 sp34;
    Vec3f sp28;

    func_80715EC0(&sp34, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp28.x = sp34.unk_00[0].x + arg0->unk_10->x;
    sp28.y = sp34.unk_00[0].y + arg0->unk_10->y;
    sp28.z = sp34.unk_00[0].z + arg0->unk_10->z;

    func_80712DE0(arg0->unk_00, &sp28, &sp34.unk_00[1], 0, &sp34.unk_18);
}

void func_80715674(unk_800E5D70* arg0, unk_80085494_arg_2* arg1) {
    s32 pad[4];
    unk_struct_9C* temp_v0;
    Racer* temp_v1;
    unk_80085494_arg_0 sp38;
    Vec3f sp2C;

    func_80715F20(&sp38, arg0->unk_0C, arg1);
    temp_v1 = arg0->unk_18;
    temp_v0 = &arg0->unk_00->unk_04.unk_58;
    *((Mtx3F*) &temp_v0->unk_00.unk_00.unk_00) = *arg0->unk_14;
    *((Vec3f*) &temp_v0->unk_00.unk_60) = temp_v1->unk_B4;
    temp_v0->unk_90 = temp_v1->speed;
    temp_v0->unk_98 = temp_v1->unk_0C.courseSegment->trackSegmentInfo;
    sp2C.x = sp38.unk_00[0].x + arg0->unk_10->x;
    sp2C.y = sp38.unk_00[0].y + arg0->unk_10->y;
    sp2C.z = sp38.unk_00[0].z + arg0->unk_10->z;

    func_80712DE0(arg0->unk_00, &sp2C, &sp38.unk_00[1], &sp38.unk_00[2], &sp38.unk_24);
}

void func_80715768(unk_struct_20_2* arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0->unk_00[i].unk_04 = 0;
        arg0->unk_00[i].unk_00 = 0;
    }
}

f32 func_807157DC(f32 arg0, s32 arg1, f32* arg2, s32 arg3) {
    s32 pad[2];
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 sp4;

    if (arg1 == 0) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0);
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (arg0 * 3.0f);
        spC = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == 1) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        sp4 = CB(temp_fv0) / 4.0f;
        temp_fa1 = temp_fv1 * arg0;
        sp8 = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (arg0 / 4.0f) + 7.0f / 12.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if ((arg3 < 7) || (arg1 < (arg3 - 5))) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = SQ(arg0);
        temp_fa1 = temp_fv1 * arg0;
        sp4 = CB(temp_fv0) / 6.0f;
        sp8 = ((temp_fa1 / 2.0f) - temp_fv1) + 2.0f / 3.0f;
        spC = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (arg0 / 2.0f) + 1.0f / 6.0f;
        sp10 = temp_fa1 / 6.0f;
    } else if (arg1 == arg3 - 5) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = (-temp_fa1 / 2.0f) + (temp_fv1 / 2.0f) + (temp_fv0 / 2.0f) + 1.0f / 6.0f;
        spC = (((temp_fa1 * 7.0f) / 12.0f) - (temp_fv1 * 5.0f / 4.0f)) + (temp_fv0 / 4.0f) + 7.0f / 12.0f;
        sp10 = CB(arg0) / 4.0f;
    } else if (arg1 == arg3 - 4) {
        temp_fv0 = 1.0f - arg0;
        temp_fv1 = temp_fv0 * temp_fv0;
        temp_fa1 = temp_fv1 * temp_fv0;
        sp4 = temp_fa1 / 6.0f;
        sp8 = ((-temp_fa1 * 11.0f) / 12.0f) + (temp_fv1 * 3.0f / 2.0f);
        spC = (((temp_fa1 * 21.0f) / 12.0f) - (temp_fv1 * 9.0f / 2.0f)) + (temp_fv0 * 3.0f);
        sp10 = CB(arg0);
    }

    return sp4 * arg2[arg1] + sp8 * arg2[arg1 + 1] + spC * arg2[arg1 + 2] + sp10 * arg2[arg1 + 3];
}

void func_80715BE0(f32* arg0, unk_struct_8* arg1, unk_80085154_arg_2* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;

    while (arg2->unk_08[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    *arg0 =
        func_807157DC((f32) arg1->unk_00 / (f32) arg2->unk_08[arg1->unk_04], arg1->unk_04, arg2->unk_04, arg2->unk_00);

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_08[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80715CD8(Vec3f* arg0, unk_struct_8* arg1, unk_struct_14* arg2) {
    s32 temp_s0;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_t9;
    s32 var_s0;
    s32 var_v0;
    s32 i;

    while (arg2->unk_10[arg1->unk_04] == 0) {
        arg1->unk_04++;
    }

    for (i = 0; i < 3; i++) {
        arg0->v[i] = func_807157DC((f32) arg1->unk_00 / (f32) arg2->unk_10[arg1->unk_04], arg1->unk_04, arg2->unk_04[i],
                                   arg2->unk_00);
    }

    arg1->unk_00++;

    if (arg1->unk_00 >= arg2->unk_10[arg1->unk_04]) {
        arg1->unk_00 = 0;
        arg1->unk_04++;
        if (arg1->unk_04 >= (arg2->unk_00 - 3)) {
            arg1->unk_04 = -1;
        }
    }
}

void func_80715E1C(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_80715CD8(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_80715CD8(&arg0[1], &arg1->unk_00[1], &arg2[1]);
}

void func_80715E60(Vec3f* arg0, unk_struct_20_2* arg1, unk_struct_14* arg2) {
    func_80715CD8(&arg0[0], &arg1->unk_00[0], &arg2[0]);
    func_80715CD8(&arg0[1], &arg1->unk_00[1], &arg2[1]);
    func_80715CD8(&arg0[2], &arg1->unk_00[2], &arg2[2]);
}

void func_80715EC0(unk_80085434_arg_0* arg0, unk_struct_20_2* arg1, unk_80085434_arg_2* arg2) {
    func_80715CD8(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_80715CD8(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_80715BE0(&arg0->unk_18, &arg1->unk_00[2], &arg2->unk_28);
}

void func_80715F20(unk_80085494_arg_0* arg0, unk_struct_20_2* arg1, unk_80085494_arg_2* arg2) {
    func_80715CD8(&arg0->unk_00[0], &arg1->unk_00[0], &arg2->unk_00[0]);
    func_80715CD8(&arg0->unk_00[1], &arg1->unk_00[1], &arg2->unk_00[1]);
    func_80715CD8(&arg0->unk_00[2], &arg1->unk_00[2], &arg2->unk_00[2]);
    func_80715BE0(&arg0->unk_24, &arg1->unk_00[3], &arg2->unk_3C);
}

void func_80715F9C(void) {
    unk_800E5D70* var_s1;
    s32 i;
    Racer* temp_a3;
    Player* var_s0;
    unk_struct_20_2* var_s4;
    unk_struct_F8* var_s3;

    for (i = 0, var_s0 = gPlayers, var_s1 = D_807A1480, var_s3 = D_807A10A0, var_s4 = D_807A1510; i < 4; i++) {
        var_s0->id = (s16) i;
        var_s0->cameraSetting = 2;
        var_s0->unk_E0 = 0;
        func_80713FD4(var_s1, var_s3);
        func_80713FDC(var_s1, var_s4);
        temp_a3 = &gRacers[var_s0->id];
        func_80713FE4(var_s1, &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);

        var_s1++;
        var_s3++;
        var_s4++;
        var_s0++;
    }
    D_807A159A = 1;
}

extern s8 D_8076C7D8;

// FAKE! Very hacky tricks to get 1 to load into v0
void func_807160A0(void) {
    s32 i;
    Player* var_s0;
    Racer* temp_a3;
    s32 v0;

    D_807A1594 = 0;

    for (i = 0, var_s0 = gPlayers; i < 4; i++, var_s0++) {
        temp_a3 = &gRacers[var_s0->id];
        func_80713FE4(&D_807A1480[i], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
    }
    switch (gGameMode) {
        case GAMEMODE_FLX_TITLE:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = 0;
            func_807166B8(gPlayers, D_807A10A0, D_807A1480);
            break;
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = v0;
            func_807166B8(gPlayers, D_807A10A0, D_807A1480);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = 2;
            func_807166B8(gPlayers, D_807A10A0, D_807A1480);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = 3;
            func_807166B8(gPlayers, D_807A10A0, D_807A1480);
            break;
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
            D_8076D6C0 = -1;
            D_807A1590 = gNumPlayers;
            for (i = 0; i < D_807A1590; i++) {
                if (D_8076C7D8 != 0) {
                    gPlayers[i].unk_04 = 15;
                } else {
                    gPlayers[i].unk_04 = 4;
                }

                gPlayers[i].unk_20 = gRacers[i].unk_0C.unk_34;

                gPlayers[i].unk_2C = gRacers[i].unk_C0;

                func_807166B8(&gPlayers[i], &D_807A10A0[i], &D_807A1480[i]);
            }

            break;
        case GAMEMODE_TIME_ATTACK:
            v0 = 0;
            if (1) {}
            D_8076D6C0 = -1;
            if (D_8076C7D8 != 0) {
                D_807A1590 = ++v0;
                gPlayers[0].unk_04 = 15;
            } else {
                D_807A1590 = 2;
                gPlayers[0].unk_04 = 4;
            }
            gPlayers[0].unk_20 = gRacers[0].unk_0C.unk_34;
            gPlayers[0].unk_2C = gRacers[0].unk_C0;

            gPlayers[1].unk_04 = 12;
            for (i = 0; i < D_807A1590; i++) {
                func_807166B8(&gPlayers[i], &D_807A10A0[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_COURSE_EDIT:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = 6;

            gPlayers[0].unk_20 = gRacers[0].unk_0C.unk_34;
            gPlayers[0].unk_2C = gRacers[0].unk_C0;

            for (i = 0; i < D_807A1590; i++) {
                func_807166B8(&gPlayers[i], &D_807A10A0[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_RECORDS:

            D_807A1590 = 2;
            gPlayers[0].unk_04 = 0xB;
            gPlayers[0].unk_20 = gRacers[0].unk_0C.unk_34;
            gPlayers[0].unk_2C = gRacers[0].unk_C0;
            gPlayers[1].unk_04 = 0xC;
            for (i = 0; i < D_807A1590; i++) {
                func_807166B8(&gPlayers[i], &D_807A10A0[i], &D_807A1480[i]);
            }
            break;
        case GAMEMODE_GP_END_CS:
            v0 = 0;
            if (1) {}
            D_807A1590 = ++v0;
            gPlayers[0].unk_04 = 0xE;
            func_807166B8(gPlayers, D_807A10A0, D_807A1480);
            break;
    }
}

extern s16 gPlayer1OverallPosition;

void func_807166B8(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 pad;
    s32 sp48;
    bool sp44;
    f32 angle;
    s32 pad2;
    Vec3f* sp38;
    Vec3f sp2C;
    Racer* racer;

    player->cameraLookBackRotate = 0;
    player->unk_18 = 0;
    player->unk_1C = 0;
    sp44 = false;

    switch (player->unk_04) {
        case 1:
        case 12:
            player->unk_A0 = 16.0f;
            player->unk_A4 = 8192.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711CE4(arg1, 2, &D_807766A8);
            break;
        case 2:
            player->unk_A0 = 16.0f;
            player->unk_A4 = 8192.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711CE4(arg1, 2, &D_80776754);
            if (gNumPlayers >= 2) {
                arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = 30.0f;
            }
            break;
        case 3:
            player->unk_A0 = 16.0f;
            player->unk_A4 = 16384.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711CE4(arg1, 2, &D_80776800);
            break;
        case 4:
            func_80711CE4(arg1, 2, &D_8077699C);
            if (gNumPlayers == 2) {
                player->unk_A0 = 16.0f;
                player->unk_A4 = 8192.0f;
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -15.0f;
                arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 100.0f;
            } else {
                player->unk_A0 = 16.0f;
                player->unk_A4 = 8192.0f;
            }
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            sp44 = 1;
            break;
        case 6:
        case 15:
            if (D_8076C7D8 != 0) {
                sp48 = 2;
            } else {
                sp48 = player->cameraSetting;
            }
            if (gNumPlayers == 2) {
                player->unk_A0 = 16.0f;
                player->unk_A4 = 8192.0f;
                player->unk_A8 = 320.0f;
                player->unk_AC = 240.0f;

                func_80711C30(arg1, &D_80776B9C);

                sp38 = &D_80776A78[sp48];
            } else {
                player->unk_A0 = 16.0f;
                player->unk_A4 = 8192.0f;
                player->unk_A8 = 320.0f;
                player->unk_AC = 240.0f;

                func_80711C30(arg1, &D_80776AA8);

                sp38 = &D_80776A48[sp48];
            }
            arg1->unk_04.unk_58.unk_68[2] = arg1->unk_04.unk_58.unk_68[1] = sp38->y;
            arg1->unk_04.unk_58.unk_68[5] = arg1->unk_04.unk_58.unk_68[4] = sp38->z;
            arg1->unk_04.unk_00.unk_18[8] = arg1->unk_04.unk_00.unk_18[7] = sp38->x;

            Math_Round(DEG_TO_FZXANG2(arg1->unk_04.unk_58.unk_68[4]));
            racer = &gRacers[player->id];
            arg1->unk_04.unk_58.unk_00.unk_54.x = racer->unk_180.x - (sp38->y * racer->unk_C0.x.x);
            arg1->unk_04.unk_58.unk_00.unk_54.y = racer->unk_180.y - (sp38->y * racer->unk_C0.x.y);
            arg1->unk_04.unk_58.unk_00.unk_54.z = racer->unk_180.z - (sp38->y * racer->unk_C0.x.z);
            player->unk_14 = arg1->unk_04.unk_00.unk_18[8];
            player->unk_10 = 0;
            if ((sp48 == 1) || (sp48 == 2)) {
                player->unk_10 |= 1;
            }
            sp44 = true;
            break;
        case 7:
            sp2C = arg1->unk_04.unk_00.unk_0C;
            func_80711B6C(arg1, &D_807763D0);
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = sp2C;
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -50.0f;
            }
            break;
        case 8:
            func_80711B6C(arg1, &D_807763D0);
            arg1->unk_04.unk_00.unk_18[8] = D_8076D788[0].unk_04;
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -30.0f;
            }

            racer = &gRacers[player->id];
            func_80718F58(&D_807A15A0[player->id], racer->unk_0C.courseSegment, racer->unk_0C.segmentTValue,
                          &D_8076D788[0]);
            break;
        case 9:
            racer = &gRacers[player->id];

            func_80711CE4(arg1, 2, &D_80776448);
            if (gNumPlayers == 2) {
                arg1->unk_04.unk_00.unk_18[11] = arg1->unk_04.unk_00.unk_18[13] = -30.0f;
            }
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_30.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = 125.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 35.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = -50.0f;

            *(Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = racer->unk_C0;

            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_18 = racer->unk_B4.x;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_1C = racer->unk_B4.y;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_20 = racer->unk_B4.z;
            break;
        case 10:
            sp2C = arg1->unk_04.unk_00.unk_0C;
            func_80711B6C(arg1, &D_807763D0);
            arg1->unk_04.unk_00.unk_18[7] = arg1->unk_04.unk_00.unk_18[8] = 80.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C = sp2C;
            break;
        case 11:
            player->unk_A0 = 16.0f;
            player->unk_A4 = 8192.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711C30(arg1, &D_80776AA8);
            arg1->unk_04.unk_58.unk_68[2] = arg1->unk_04.unk_58.unk_68[1] = D_80776A48[1].y;
            arg1->unk_04.unk_58.unk_68[5] = arg1->unk_04.unk_58.unk_68[4] = 15.0f;
            arg1->unk_04.unk_00.unk_18[8] = arg1->unk_04.unk_00.unk_18[7] = D_80776A48[1].x;
            angle = 15.0f;
            sp38 = &D_80776A48[1];
            Math_Round(DEG_TO_FZXANG2(angle));
            racer = &gRacers[0];
            arg1->unk_04.unk_58.unk_00.unk_54.x = racer->unk_180.x - (sp38->y * racer->unk_C0.x.x);
            arg1->unk_04.unk_58.unk_00.unk_54.y = racer->unk_180.y - (sp38->y * racer->unk_C0.x.y);
            arg1->unk_04.unk_58.unk_00.unk_54.z = racer->unk_180.z - (sp38->y * racer->unk_C0.x.z);
            player->unk_14 = arg1->unk_04.unk_00.unk_18[8];
            player->unk_10 = 0;
            sp44 = true;
            break;
        case 13:
            player->unk_A0 = 512.0f;
            player->unk_A4 = 8192.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711B6C(arg1, &D_807768AC);
            break;
        case 14:
            player->unk_A0 = 16.0f;
            player->unk_A4 = 8192.0f;
            player->unk_A8 = 320.0f;
            player->unk_AC = 240.0f;
            func_80711CE4(arg1, 3, &D_80776448);
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.x = 196.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.y = 25.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00.z = -3000.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_30.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = 258.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = -7.0f;
            arg1->unk_04.unk_58.unk_00.unk_00.unk_48.x = arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = 269.0f;
            sp44 = true;
            if (gPlayer1OverallPosition < 4) {
                D_807A1598 = gPlayer1OverallPosition - 1;
            } else {
                D_807A1598 = 0;
            }
            break;
    }
    if (sp44) {
        player->unk_E0 = 0;
        player->unk_E4 = player->unk_E6 = 0;
        func_80716F38(player);
    }
}

extern s32 D_807A1590;

void func_80716F38(Player* player) {
    s32* temp = D_8076D7C4[D_807A1590];
    s32 temp2 = temp[player->id];
    Vp* sp24;
    ScissorBox* sp20;

    switch (temp2) {
        case 0:
            sp24 = Segment_SegmentedToVirtual(&D_80146A8);
            sp20 = &D_8076D7D8;
            break;
        case 1:
            sp24 = Segment_SegmentedToVirtual(&D_80146B8);
            sp20 = &D_8076D7E8;
            break;
        case 2:
            sp24 = Segment_SegmentedToVirtual(&D_80146C8);
            sp20 = &D_8076D7F8;
            break;
        case 3:
            sp24 = Segment_SegmentedToVirtual(&D_80146D8);
            sp20 = &D_8076D808;
            break;
        case 4:
            sp24 = Segment_SegmentedToVirtual(&D_80146E8);
            sp20 = &D_8076D818;
            break;
        case 5:
            sp24 = Segment_SegmentedToVirtual(&D_80146F8);
            sp20 = &D_8076D828;
            break;
        case 6:
            sp24 = Segment_SegmentedToVirtual(&D_8014708);
            sp20 = &D_8076D838;
            break;
        case 7:
            sp24 = Segment_SegmentedToVirtual(&D_8014718);
            sp20 = &D_8076D848;
            break;
        case 8:
            sp24 = Segment_SegmentedToVirtual(&D_8014728);
            sp20 = &D_8076D858;
            break;
        case 9:
            sp24 = Segment_SegmentedToVirtual(&D_8014738);
            sp20 = &D_8076D868;
            break;
        case 10:
            sp24 = Segment_SegmentedToVirtual(&D_8014748);
            sp20 = &D_8076D878;
            break;
        case 11:
            sp24 = Segment_SegmentedToVirtual(&D_8014758);
            sp20 = &D_8076D888;
            break;
        case 12:
            sp24 = Segment_SegmentedToVirtual(&D_8014768);
            sp20 = &D_8076D898;
            break;
    }

    player->unk_E8 = player->unk_F8 = player->unk_108 = sp24->vp.vscale[0] * 0.25f;
    player->unk_EC = player->unk_FC = player->unk_10C = sp24->vp.vscale[1] * 0.25f;

    player->unk_F0 = sp24->vp.vtrans[0] * 0.25f;
    player->unk_F4 = sp24->vp.vtrans[1] * 0.25f;

    player->unk_100 = player->unk_110 = player->unk_F0 - player->unk_E8;
    player->unk_104 = player->unk_114 = player->unk_F4 - player->unk_EC;

    player->unk_B0 = player->unk_C0 = player->unk_D0 = sp20->left;
    player->unk_B4 = player->unk_C4 = player->unk_D4 = sp20->top;
    player->unk_B8 = player->unk_C8 = player->unk_D8 = sp20->right;
    player->unk_BC = player->unk_CC = player->unk_DC = sp20->bottom;
}

void func_80717294(void) {
    s32 i;

    for (i = 0; i < D_807A1590; i++) {
        func_80717354(&gPlayers[i], &D_807A10A0[i], &D_807A1480[i]);
    }

    if ((gGameMode == GAMEMODE_VS_2P) || (gGameMode == GAMEMODE_VS_3P) || (gGameMode == GAMEMODE_VS_4P)) {
        func_80717B20();
    }
}

extern GfxPool* gGfxPool;

void func_80717354(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_fv0;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    bool var_v0;
    u32 temp_s4;
    u32 var_v1;

    do {
        temp_s4 = var_v1 = player->unk_04;
        switch (var_v1) {
            case 0:
            case 1:
            case 2:
            case 16:
            default:
                break;
            case 3:
                func_80718964(player, arg1);
                break;
            case 4:
                if (!gGamePaused) {
                    func_807181F8(player, arg1);
                }
                break;
            case 5:

                var_v0 = true;

                temp_fv0 = arg1->unk_04.unk_00.unk_18[8] - arg1->unk_04.unk_00.unk_18[7];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_00.unk_18[13] - arg1->unk_04.unk_00.unk_18[11];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[2] - arg1->unk_04.unk_58.unk_68[1];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                temp_fv0 = arg1->unk_04.unk_58.unk_68[5] - arg1->unk_04.unk_58.unk_68[4];
                if (ABS(temp_fv0) > 0.5f) {
                    var_v0 = false;
                }

                if (var_v0) {
                    player->unk_04 = 6;
                    arg1->unk_04.unk_00.unk_18[9] = 0.2f;
                    arg1->unk_04.unk_00.unk_18[6] = 1.0f;
                    arg1->unk_04.unk_00.unk_18[14] = 0.1f;
                    arg1->unk_04.unk_00.unk_18[15] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[3] = 0.2f;
                    arg1->unk_04.unk_58.unk_68[6] = 0.2f;
                }
                break;
            case 6:
                func_80718530(player, arg1, arg2);
                break;
            case 15:
                func_80718908(player, arg1, arg2);
                break;
            case 7:
                if (!gGamePaused) {
                    func_80718AB0(player, arg1);
                }
                break;
            case 8:
                if (!gGamePaused) {
                    func_80718AFC(player, arg1, arg2);
                }
                break;
            case 9:
                if (!gGamePaused) {
                    func_807191B0(player, arg1, arg2);
                }
                break;
            case 10:
                if (!gGamePaused) {
                    func_80719140(player, arg1, arg2);
                }
                break;
            case 11:
                func_80719420(player, arg1, arg2);
                break;
            case 14:
                func_80719480(player, arg1, arg2);
                break;
        }
        var_v1 = player->unk_04;
    } while (temp_s4 != var_v1);

    func_80712AA8(arg1, player);
    func_807176B4(player, arg1);
    func_807130F8(player, arg1);
    func_8071315C(player);
    func_807134AC(gGfxPool, player);
    if ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_TIME_ATTACK) ||
        (gGameMode == GAMEMODE_DEATH_RACE)) {
        func_8071370C(player);
    }
}

void func_807176B4(Player* player, unk_struct_F8* arg1) {
    Vec3f* var_s1;
    s32 angle;
    f32 temp1;
    f32 temp2;
    f32 temp3;
    Mtx3F sp48;
    f32 temp_fv0;
    f32 temp_fv1;
    unk_8008112C_arg_1* temp_v1 = &arg1->unk_04;
    Racer* temp_s0;

    if (player->unk_04 == 4) {
        if (gNumPlayers == 2) {
            var_s1 = &D_80776A78[2];
        } else {
            var_s1 = &D_80776A48[2];
        }

        temp_s0 = &gRacers[player->id];

        sp48.x.x = 0.0f - (var_s1->y * temp_s0->unk_C0.x.x);
        sp48.x.y = 0.0f - (var_s1->y * temp_s0->unk_C0.x.y);
        sp48.x.z = 0.0f - (var_s1->y * temp_s0->unk_C0.x.z);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.x.x) + SQ(sp48.x.y) + SQ(sp48.x.z));
        sp48.x.x *= temp_fv1;
        sp48.x.y *= temp_fv1;
        sp48.x.z *= temp_fv1;

        sp48.z.x = (temp_s0->unk_C0.y.y * sp48.x.z) - (temp_s0->unk_C0.y.z * sp48.x.y);
        sp48.z.y = (temp_s0->unk_C0.y.z * sp48.x.x) - (temp_s0->unk_C0.y.x * sp48.x.z);
        sp48.z.z = (temp_s0->unk_C0.y.x * sp48.x.y) - (temp_s0->unk_C0.y.y * sp48.x.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.z.x) + SQ(sp48.z.y) + SQ(sp48.z.z));
        sp48.z.x *= temp_fv1;
        sp48.z.y *= temp_fv1;
        sp48.z.z *= temp_fv1;

        sp48.y.x = (sp48.x.y * sp48.z.z) - (sp48.x.z * sp48.z.y);
        sp48.y.y = (sp48.x.z * sp48.z.x) - (sp48.x.x * sp48.z.z);
        sp48.y.z = (sp48.x.x * sp48.z.y) - (sp48.x.y * sp48.z.x);
        temp_fv1 = 1.0f / sqrtf(SQ(sp48.y.x) + SQ(sp48.y.y) + SQ(sp48.y.z));
        sp48.y.x *= temp_fv1;
        sp48.y.y *= temp_fv1;
        sp48.y.z *= temp_fv1;

        angle = Math_Round(DEG_TO_FZXANG2(var_s1->z));

        temp_fv0 = (SIN(angle) * var_s1->y) * ((sp48.y.x * temp_s0->unk_C0.y.x) + (sp48.y.y * temp_s0->unk_C0.y.y) +
                                               (sp48.y.z * temp_s0->unk_C0.y.z));
        temp_fv1 = COS(angle) * var_s1->y;

        temp1 = (temp_s0->unk_180.x + (temp_fv1 * sp48.x.x) + (temp_fv0 * sp48.y.x));
        temp2 = (temp_s0->unk_180.y + (temp_fv1 * sp48.x.y) + (temp_fv0 * sp48.y.y));
        temp3 = (temp_s0->unk_180.z + (temp_fv1 * sp48.x.z) + (temp_fv0 * sp48.y.z));

        temp_fv0 = (f32) (player->unk_1C - 1) / 300.0f;

        temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);

        temp_v1->unk_00.unk_0C.x = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.x) + (temp_fv0 * temp1);
        temp_v1->unk_00.unk_0C.y = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.y) + (temp_fv0 * temp2);
        temp_v1->unk_00.unk_0C.z = ((1.0f - temp_fv0) * temp_v1->unk_00.unk_0C.z) + (temp_fv0 * temp3);

        sp48.x.x = temp_v1->unk_00.unk_00.x - temp_v1->unk_00.unk_0C.x;
        sp48.x.y = temp_v1->unk_00.unk_00.y - temp_v1->unk_00.unk_0C.y;
        sp48.x.z = temp_v1->unk_00.unk_00.z - temp_v1->unk_00.unk_0C.z;
        sp48.y.x = temp_s0->unk_C0.y.x;
        sp48.y.y = temp_s0->unk_C0.y.y;
        sp48.y.z = temp_s0->unk_C0.y.z;
        func_806F6D8C(&sp48);
        temp_v1->unk_00.unk_18[3] = sp48.y.x;
        temp_v1->unk_00.unk_18[0] = temp_v1->unk_00.unk_18[3];
        temp_v1->unk_00.unk_18[4] = sp48.y.y;
        temp_v1->unk_00.unk_18[1] = temp_v1->unk_00.unk_18[4];
        temp_v1->unk_00.unk_18[5] = sp48.y.z;
        temp_v1->unk_00.unk_18[2] = temp_v1->unk_00.unk_18[5];
    }
}

extern s32 D_8006D544;
extern s32 D_8006D548;
extern s32 D_800BF040;
extern s32 D_807A1590;
extern s16 D_807A16CC;

void func_80717B20(void) {
    Racer* var_a1;
    f32 temp_fv0;
    s32 i;
    Player* var_a0;
    Vp* vp;

    if (D_8076D6C0 == -1) {
        if ((D_807A16CC != 0) && (D_8006D544 != 0)) {
            D_800BF040 = 30;

            for (i = 0, var_a0 = gPlayers; i < D_807A1590; i++, var_a0++) {
                var_a1 = &gRacers[i];
                if (var_a1->position == 1) {
                    D_8076D6C0 = i;
                }
                var_a0->unk_E0 = 1;
                var_a0->unk_E4 = 0;
                var_a0->unk_E6 = 0x1E;
            }

            switch (gGameMode) {
                case GAMEMODE_VS_2P:
                    if (D_8076D6C0 == 0) {
                        gPlayers[0].unk_D4 = 8.0f;
                        gPlayers[0].unk_DC = 231.0f;
                        gPlayers[0].unk_10C = 120.0f;
                        gPlayers[0].unk_114 = 0.0f;
                        gPlayers[1].unk_D4 = 231.0f;
                        gPlayers[1].unk_DC = 231.0f;
                        gPlayers[1].unk_10C = 0.0f;
                        gPlayers[1].unk_114 = 240.0f;
                    } else {
                        gPlayers[0].unk_D4 = 8.0f;
                        gPlayers[0].unk_DC = 8.0f;
                        gPlayers[0].unk_10C = 0.0f;
                        gPlayers[0].unk_114 = 0.0f;
                        gPlayers[1].unk_D4 = 8.0f;
                        gPlayers[1].unk_DC = 231.0f;
                        gPlayers[1].unk_10C = 120.0f;
                        gPlayers[1].unk_114 = 0.0f;
                    }
                    break;
                case GAMEMODE_VS_3P:
                case GAMEMODE_VS_4P:
                    switch (D_8076D6C0) {
                        case 0:
                            gPlayers[0].unk_D0 = 12.0f;
                            gPlayers[0].unk_D4 = 8.0f;
                            gPlayers[0].unk_D8 = 307.0f;
                            gPlayers[0].unk_DC = 231.0f;
                            gPlayers[0].unk_108 = 160.0f;
                            gPlayers[0].unk_10C = 120.0f;
                            gPlayers[0].unk_110 = 0.0f;
                            gPlayers[0].unk_114 = 0.0f;
                            gPlayers[1].unk_D0 = 12.0f;
                            gPlayers[1].unk_D4 = 231.0f;
                            gPlayers[1].unk_D8 = 307.0f;
                            gPlayers[1].unk_DC = 231.0f;
                            gPlayers[1].unk_108 = 160.0f;
                            gPlayers[1].unk_10C = 0.0f;
                            gPlayers[1].unk_110 = 0.0f;
                            gPlayers[1].unk_114 = 240.0f;
                            gPlayers[2].unk_D0 = 307.0f;
                            gPlayers[2].unk_D4 = 8.0f;
                            gPlayers[2].unk_DC = 231.0f;
                            gPlayers[2].unk_D8 = 307.0f;
                            gPlayers[2].unk_108 = 0.0f;
                            gPlayers[2].unk_10C = 120.0f;
                            gPlayers[2].unk_110 = 320.0f;
                            gPlayers[2].unk_114 = 0.0f;
                            gPlayers[3].unk_D0 = 307.0f;
                            gPlayers[3].unk_D4 = 231.0f;
                            gPlayers[3].unk_D8 = 307.0f;
                            gPlayers[3].unk_DC = 231.0f;
                            gPlayers[3].unk_108 = 0.0f;
                            gPlayers[3].unk_10C = 0.0f;
                            gPlayers[3].unk_110 = 320.0f;
                            gPlayers[3].unk_114 = 240.0f;
                            break;
                        case 1:
                            gPlayers[0].unk_D0 = 12.0f;
                            gPlayers[0].unk_D4 = 8.0f;
                            gPlayers[0].unk_D8 = 307.0f;
                            gPlayers[0].unk_DC = 8.0f;
                            gPlayers[0].unk_108 = 160.0f;
                            gPlayers[0].unk_10C = 0.0f;
                            gPlayers[0].unk_110 = 0.0f;
                            gPlayers[0].unk_114 = 0.0f;
                            gPlayers[1].unk_D0 = 12.0f;
                            gPlayers[1].unk_D4 = 8.0f;
                            gPlayers[1].unk_D8 = 307.0f;
                            gPlayers[1].unk_DC = 231.0f;
                            gPlayers[1].unk_108 = 160.0f;
                            gPlayers[1].unk_10C = 120.0f;
                            gPlayers[1].unk_110 = 0.0f;
                            gPlayers[1].unk_114 = 0.0f;
                            gPlayers[2].unk_D0 = 307.0f;
                            gPlayers[2].unk_D4 = 8.0f;
                            gPlayers[2].unk_D8 = 307.0f;
                            gPlayers[2].unk_DC = 8.0f;
                            gPlayers[2].unk_108 = 0.0f;
                            gPlayers[2].unk_10C = 0.0f;
                            gPlayers[2].unk_110 = 320.0f;
                            gPlayers[2].unk_114 = 0.0f;
                            gPlayers[3].unk_D0 = 307.0f;
                            gPlayers[3].unk_D4 = 8.0f;
                            gPlayers[3].unk_D8 = 307.0f;
                            gPlayers[3].unk_DC = 231.0f;
                            gPlayers[3].unk_108 = 0.0f;
                            gPlayers[3].unk_10C = 120.0f;
                            gPlayers[3].unk_110 = 320.0f;
                            gPlayers[3].unk_114 = 0.0f;
                            break;
                        case 2:
                            gPlayers[0].unk_D0 = 12.0f;
                            gPlayers[0].unk_D4 = 8.0f;
                            gPlayers[0].unk_D8 = 12.0f;
                            gPlayers[0].unk_DC = 231.0f;
                            gPlayers[0].unk_108 = 0.0f;
                            gPlayers[0].unk_10C = 120.0f;
                            gPlayers[0].unk_110 = 0.0f;
                            gPlayers[0].unk_114 = 0.0f;
                            gPlayers[1].unk_D0 = 12.0f;
                            gPlayers[1].unk_D4 = 231.0f;
                            gPlayers[1].unk_D8 = 12.0f;
                            gPlayers[1].unk_DC = 231.0f;
                            gPlayers[1].unk_108 = 0.0f;
                            gPlayers[1].unk_10C = 0.0f;
                            gPlayers[1].unk_110 = 0.0f;
                            gPlayers[1].unk_114 = 240.0f;
                            gPlayers[2].unk_D0 = 12.0f;
                            gPlayers[2].unk_D4 = 8.0f;
                            gPlayers[2].unk_D8 = 307.0f;
                            gPlayers[2].unk_DC = 231.0f;
                            gPlayers[2].unk_108 = 160.0f;
                            gPlayers[2].unk_10C = 120.0f;
                            gPlayers[2].unk_110 = 0.0f;
                            gPlayers[2].unk_114 = 0.0f;
                            gPlayers[3].unk_D0 = 12.0f;
                            gPlayers[3].unk_D4 = 231.0f;
                            gPlayers[3].unk_D8 = 307.0f;
                            gPlayers[3].unk_DC = 231.0f;
                            gPlayers[3].unk_108 = 160.0f;
                            gPlayers[3].unk_10C = 0.0f;
                            gPlayers[3].unk_110 = 0.0f;
                            gPlayers[3].unk_114 = 240.0f;
                            break;
                        case 3:
                            gPlayers[0].unk_108 = 0.0f;
                            gPlayers[0].unk_10C = 0.0f;
                            gPlayers[0].unk_D0 = 12.0f;
                            gPlayers[0].unk_D8 = 12.0f;
                            gPlayers[0].unk_110 = 0.0f;
                            gPlayers[0].unk_114 = 0.0f;
                            gPlayers[0].unk_D4 = 8.0f;
                            gPlayers[0].unk_DC = 8.0f;
                            gPlayers[1].unk_D0 = 12.0f;
                            gPlayers[1].unk_D8 = 12.0f;
                            gPlayers[2].unk_D0 = 12.0f;
                            gPlayers[3].unk_D0 = 12.0f;
                            gPlayers[1].unk_D4 = 8.0f;
                            gPlayers[2].unk_D4 = 8.0f;
                            gPlayers[2].unk_DC = 8.0f;
                            gPlayers[3].unk_D4 = 8.0f;
                            gPlayers[1].unk_10C = 120.0f;
                            gPlayers[3].unk_10C = 120.0f;
                            gPlayers[1].unk_DC = 231.0f;
                            gPlayers[3].unk_DC = 231.0f;
                            gPlayers[2].unk_108 = 160.0f;
                            gPlayers[3].unk_108 = 160.0f;
                            gPlayers[2].unk_D8 = 307.0f;
                            gPlayers[3].unk_D8 = 307.0f;
                            gPlayers[1].unk_108 = 0.0f;
                            gPlayers[1].unk_110 = 0.0f;
                            gPlayers[1].unk_114 = 0.0f;
                            gPlayers[2].unk_10C = 0.0f;
                            gPlayers[2].unk_110 = 0.0f;
                            gPlayers[2].unk_114 = 0.0f;
                            gPlayers[3].unk_110 = 0.0f;
                            gPlayers[3].unk_114 = 0.0f;
                            break;
                    }
                    break;
            }
        }
    } else if ((gPlayers[D_8076D6C0].unk_E4 == 0x1E) && (D_8006D548 == 0)) {
        D_8006D548 = 1;
    }

    for (i = 0, var_a0 = gPlayers; i < D_807A1590; i++, var_a0++) {
        if (var_a0->unk_E0 == 1) {
            if (var_a0->unk_E4 < var_a0->unk_E6) {
                var_a0->unk_E4++;
            }

            temp_fv0 = (f32) var_a0->unk_E4 / var_a0->unk_E6;

            var_a0->unk_B0 = var_a0->unk_C0 + ((var_a0->unk_D0 - var_a0->unk_C0) * temp_fv0);
            var_a0->unk_B4 = var_a0->unk_C4 + ((var_a0->unk_D4 - var_a0->unk_C4) * temp_fv0);

            var_a0->unk_B8 = var_a0->unk_C8 + ((var_a0->unk_D8 - var_a0->unk_C8) * temp_fv0);
            var_a0->unk_BC = var_a0->unk_CC + ((var_a0->unk_DC - var_a0->unk_CC) * temp_fv0);
            var_a0->unk_E8 = var_a0->unk_F8 + ((var_a0->unk_108 - var_a0->unk_F8) * temp_fv0);
            var_a0->unk_EC = var_a0->unk_FC + ((var_a0->unk_10C - var_a0->unk_FC) * temp_fv0);
            var_a0->unk_F0 = var_a0->unk_100 + ((var_a0->unk_110 - var_a0->unk_100) * temp_fv0) + var_a0->unk_E8;
            var_a0->unk_F4 = var_a0->unk_104 + ((var_a0->unk_114 - var_a0->unk_104) * temp_fv0) + var_a0->unk_EC;

            vp = &gGfxPool->unk_362C8[i];
            vp->vp.vscale[0] = var_a0->unk_E8 * 4.0f;
            vp->vp.vscale[1] = var_a0->unk_EC * 4.0f;
            vp->vp.vscale[2] = 0x1FF;
            vp->vp.vscale[3] = 0;
            vp->vp.vtrans[0] = var_a0->unk_F0 * 4.0f;
            vp->vp.vtrans[1] = var_a0->unk_F4 * 4.0f;
            vp->vp.vtrans[2] = 0x1FF;
            vp->vp.vtrans[3] = 0;
        }
    }
}

void func_807181F8(Player* player, unk_struct_F8* arg1) {
    Vec3f* var_v1;
    f32 temp_fv0;
    s32 index;
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;
    Racer* temp_t3 = &gRacers[player->id];
    unk_struct_9C* temp_a3 = &arg1->unk_04.unk_58;
    Racer* temp_t4;
    s32 pad[5];

    temp_a3->unk_00.unk_00.unk_00.unk_00 = temp_t3->unk_180;

    *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_t3->unk_C0;

    temp_fv0 = (f32) player->unk_1C / 300.0f;
    temp_fv0 = (-2.0f * temp_fv0 * temp_fv0 * temp_fv0) + (3.0f * temp_fv0 * temp_fv0);
    arg1->unk_04.unk_58.unk_00.unk_00.unk_30.y = (-880.0f * temp_fv0) + 1000.0f;
    arg1->unk_04.unk_58.unk_00.unk_00.unk_48.y = (-360.0f * temp_fv0) + 180.0f;

    if (player->unk_1C >= 0x12C) {
        if (gNumPlayers == 2) {
            func_80711BF0(arg1, &D_80776B9C.unk_58);
            var_v1 = &D_80776A78[2];
        } else {
            func_80711BF0(arg1, &D_80776AA8.unk_58);
            var_v1 = &D_80776A48[2];
        }
        player->unk_04 = 5;
        temp_a3->unk_00.unk_00.unk_48.x = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.y = 0.0f;
        temp_a3->unk_00.unk_00.unk_48.z = 0.0f;

        temp_a3->unk_68[1] = var_v1->y;
        temp_a3->unk_68[4] = var_v1->z;
        temp_a0->unk_00.unk_18[7] = var_v1->x;

        if (gNumPlayers == 2) {
            var_v1 = &D_80776A78[player->cameraSetting];
        } else {
            var_v1 = &D_80776A48[player->cameraSetting];
        }
        temp_a3->unk_68[2] = var_v1->y;
        temp_a3->unk_68[5] = var_v1->z;
        temp_a0->unk_00.unk_18[8] = var_v1->x;

        temp_t4 = &gRacers[player->id];
        temp_a3->unk_00.unk_54.x = temp_t4->unk_180.x - (var_v1->y * temp_t4->unk_C0.x.x);
        temp_a3->unk_00.unk_54.y = temp_t4->unk_180.y - (var_v1->y * temp_t4->unk_C0.x.y);
        temp_a3->unk_00.unk_54.z = temp_t4->unk_180.z - (var_v1->y * temp_t4->unk_C0.x.z);

        player->unk_20 = temp_t4->unk_180;
        player->unk_2C = temp_t4->unk_C0;

        player->unk_14 = arg1->unk_04.unk_00.unk_18[8];
        player->unk_10 = 0;
        if ((player->cameraSetting == 1) || (player->cameraSetting == 2)) {
            player->unk_10 |= 1;
        }
        temp_a3->unk_68[6] = 0.1f;
        temp_a3->unk_68[3] = 0.1f;
        temp_a0->unk_00.unk_18[6] = 0.1f;
        temp_a0->unk_00.unk_18[9] = 0.1f;
        temp_a0->unk_00.unk_18[15] = 0.1f;
    } else {
        player->unk_1C++;
    }
}

extern s16 D_807A16CC;
extern s32 gCurrentGhostType;
extern s32 gFastestGhostTime;

void func_80718530(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    f32 var_fa0;
    f32 var_fv1;
    s32 playerIndex;
    bool var_v1;
    unk_8008112C_arg_1* temp_a1;
    s32 pad[4];
    Racer* temp_t0;
    unk_struct_9C* temp_a2 = &arg1->unk_04.unk_58;
    Controller* controller;

    playerIndex = player->id;
    temp_t0 = &gRacers[playerIndex];
    if (!gGamePaused) {
        if (temp_t0->stateFlags & RACER_STATE_FLAGS_80000) {
            player->unk_04 = 7;
            func_807166B8(player, arg1, arg2);
            return;
        }
        if (temp_t0->stateFlags & RACER_STATE_FLAGS_2000000) {
            if ((gNumPlayers >= 2) && (D_807A16CC != 0)) {
                player->unk_04 = 9;
                func_807166B8(player, arg1, arg2);
                return;
            }
            if (gGameMode == GAMEMODE_TIME_ATTACK) {
                if ((gCurrentGhostType != GHOST_STAFF) && (gCurrentGhostType != GHOST_CELEBRITY) &&
                    (gCurrentGhostType != GHOST_CHAMP)) {
                    player->unk_04 = 8;
                } else if (temp_t0->raceTime < gFastestGhostTime) {
                    player->unk_04 = 8;
                } else {
                    player->unk_04 = 10;
                }
            } else {
                player->unk_04 = 8;
            }
            func_807166B8(player, arg1, arg2);
            return;
        }
    }

    controller = &gControllers[gPlayerControlPorts[playerIndex]];
    var_v1 = false;

    if (!(temp_t0->stateFlags & RACER_STATE_RETIRED) && (controller->buttonPressed & BTN_CRIGHT)) {
        var_v1 = true;
        if (++player->cameraSetting == 4) {
            player->cameraSetting = 0;
        }
    }
    if (var_v1) {
        func_80713064(player, &arg1->unk_04, temp_a2, gNumPlayers);
    }
    temp_a1 = &arg1->unk_04;
    if ((D_8076D6C4 != 0) && (!gGamePaused)) {
        if ((controller->buttonCurrent & BTN_CUP) && !(temp_t0->stateFlags & RACER_STATE_RETIRED)) {
            if (++player->cameraLookBackRotate > sMaxCameraLookBackRotate) {
                player->cameraLookBackRotate = sMaxCameraLookBackRotate;
            }
        } else {
            if (--player->cameraLookBackRotate < 0) {
                player->cameraLookBackRotate = 0;
            }
        }
        temp_a2->unk_68[8] = (player->cameraLookBackRotate * 180.0f) / sMaxCameraLookBackRotate;
    }
    if (player->unk_10 & 1) {

        var_fv1 = sqrtf(SQ(temp_t0->unk_5C.x) + SQ(temp_t0->unk_5C.z)) - D_8076D8A8;
        if (var_fv1 < 0.0f) {
            var_fa0 = player->unk_14;
        } else {
            var_fv1 /= (D_8076D8AC - D_8076D8A8);
            if (var_fv1 > 1.0f) {
                var_fv1 = 1.0f;
            }

            var_fa0 = player->unk_14 + ((120.0f - player->unk_14) * var_fv1);
        }
        if (player->unk_10 & 2) {
            temp_a1->unk_00.unk_18[8] = var_fa0;
        } else {
            temp_a1->unk_00.unk_18[8] = var_fa0;
            temp_a1->unk_00.unk_18[7] = var_fa0;
        }
    }
    var_fv1 = temp_a1->unk_00.unk_18[8] - temp_a1->unk_00.unk_18[7];

    if (ABS(var_fv1) < 0.1f) {
        player->unk_10 &= ~2;
    }
}

void func_80718908(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 playerIndex = player->id;

    if (gRacers[playerIndex].stateFlags & RACER_STATE_FLAGS_80000) {
        player->unk_04 = 7;
        func_807166B8(player, arg1, arg2);
    }
}

extern s8 D_8007B9DC;

void func_80718964(Player* player, unk_struct_F8* arg1) {
    s32 i;
    unk_struct_9C* temp_v0 = &arg1->unk_04.unk_58;

    if (D_8007B9DC != 0) {
        temp_v0->unk_00.unk_00.unk_48.y += 1.0f;
        if (temp_v0->unk_00.unk_00.unk_48.y >= 360.0f) {
            temp_v0->unk_00.unk_00.unk_48.y -= 360.0f;
        }
        if (player->unk_18 == 0) {
            for (i = 0; i < gNumPlayers; i++) {
                Controller* controller = &gControllers[gPlayerControlPorts[i]];

                if (controller->buttonCurrent & BTN_CUP) {
                    temp_v0->unk_00.unk_00.unk_3C.y += 0.1f;
                }
                if (controller->buttonCurrent & BTN_CDOWN) {
                    temp_v0->unk_00.unk_00.unk_3C.y -= 0.1f;
                }
            }
        } else {
            player->unk_18 = 0;
            temp_v0->unk_00.unk_00.unk_3C.y = 20.0f;
        }

        if (temp_v0->unk_00.unk_00.unk_3C.y < -50.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = -50.0f;
        } else if (temp_v0->unk_00.unk_00.unk_3C.y > 90.0f) {
            temp_v0->unk_00.unk_00.unk_3C.y = 90.0f;
        }
    }
}

void func_80718AB0(Player* player, unk_struct_F8* arg1) {
    arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[player->id].unk_180;
}

void func_80718AFC(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Vec3f* temp_s1 = &D_807A15A0[player->id];
    unk_800CD970* temp_a3 = &D_8076D788[player->unk_18];
    unk_8008112C_arg_1* temp_t0 = &arg1->unk_04;
    s16 temp_t1 = temp_a3->unk_00;
    Racer* temp_t2 = &gRacers[player->id];
    unk_800CD8B0* temp_v0_2;
    s32 pad[2];

    if (temp_t2->stateFlags & RACER_STATE_FLAGS_80000) {
        player->unk_04 = 7;
        func_807166B8(player, arg1, arg2);
        return;
    }
    switch (temp_a3->unk_00) {
        case 0:
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
            temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
            break;
        case 1:
            temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;

            *((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C) = temp_t2->unk_C0;

            temp_t0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
            temp_t0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
            temp_t0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;
            temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;

            temp_v1->unk_00.unk_00.unk_3C.x =
                temp_v0_2->unk_00.x +
                ((((temp_v0_2->unk_0C.x - temp_v0_2->unk_00.x) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.y =
                temp_v0_2->unk_00.y +
                ((((temp_v0_2->unk_0C.y - temp_v0_2->unk_00.y) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_30);
            temp_v1->unk_00.unk_00.unk_3C.z =
                temp_v0_2->unk_00.z +
                ((((temp_v0_2->unk_0C.z - temp_v0_2->unk_00.z) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_30);

            temp_v1->unk_00.unk_54.x =
                temp_v0_2->unk_18.x +
                ((((temp_v0_2->unk_24.x - temp_v0_2->unk_18.x) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.y =
                temp_v0_2->unk_18.y +
                ((((temp_v0_2->unk_24.y - temp_v0_2->unk_18.y) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_34);
            temp_v1->unk_00.unk_54.z =
                temp_v0_2->unk_18.z +
                ((((temp_v0_2->unk_24.z - temp_v0_2->unk_18.z) * player->unk_1C) / temp_a3->unk_02) *
                 temp_v0_2->unk_34);
        default:
            break;
    }

    if (player->unk_1C >= temp_a3->unk_02) {
        player->unk_1C = 0;
        if (++player->unk_18 >= 5) {
            player->unk_04 = 9;
            func_807166B8(player, arg1, arg2);
            return;
        }
        temp_a3 = &D_8076D788[player->unk_18];
        temp_t0->unk_00.unk_18[8] = temp_a3->unk_04;

        switch (temp_a3->unk_00) {
            case 0:
                if (temp_t1 != temp_a3->unk_00) {
                    func_80711B20(arg1, &D_807763D0.unk_58);
                }
                temp_t0->unk_00.unk_18[3] = 0.0f;
                temp_t0->unk_00.unk_18[4] = 1.0f;
                temp_t0->unk_00.unk_18[5] = 0.0f;
                func_80718F58(temp_s1, temp_t2->unk_0C.courseSegment, temp_t2->unk_0C.segmentTValue, temp_a3);
                temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_t2->unk_180;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.x = temp_s1->x;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.y = temp_s1->y;
                temp_v1->unk_00.unk_00.unk_00.unk_0C.z = temp_s1->z;
                break;
            case 1:
                if (temp_t1 != temp_a3->unk_00) {
                    func_80711D58(arg1, &D_807765E8.unk_58);
                }
                temp_v0_2 = (unk_800CD8B0*) temp_a3->unk_08;
                temp_v1->unk_00.unk_00.unk_3C = temp_v0_2->unk_00;
                temp_v1->unk_00.unk_54 = temp_v0_2->unk_18;
                break;
            default:
                break;
        }
    } else {
        player->unk_1C++;
    }
}

void func_80718F58(Vec3f* arg0, CourseSegment* arg1, f32 arg2, unk_800CD970* arg3) {
    f32 abs;
    f32 sp60;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 var_fa0;
    f32 var_fv0;
    Mtx3F sp2C;
    unk_800CD8B0* sp28 = (unk_800CD8B0*) arg3->unk_08;

    sp60 = func_80712E68(&arg1, arg2, sp28->unk_00.x);

    Course_SplineGetPosition(arg1, sp60, arg0);
    func_80712FE4(&sp2C, arg1, sp60);

    temp_ft4 = arg1->radiusLeft * (1.0f - sp60) + arg1->next->radiusLeft * sp60;
    temp_fa1 = arg1->radiusRight * (1.0f - sp60) + arg1->next->radiusRight * sp60;

    switch (arg1->trackSegmentInfo & TRACK_SHAPE_MASK) {
        case TRACK_SHAPE_CYLINDER:
            var_fv0 = sp28->unk_00.y * temp_fa1;
            var_fa0 = sp28->unk_00.z + temp_fa1;
            break;
        case TRACK_SHAPE_HALF_PIPE:
            var_fv0 = sp28->unk_00.y * temp_ft4;
            var_fa0 = sp28->unk_00.z;
            break;
        default:
            if (sp28->unk_00.y >= 0.0f) {
                var_fv0 = sp28->unk_00.y * temp_ft4;
            } else {
                var_fv0 = sp28->unk_00.y * temp_fa1;
            }
            var_fa0 = sp28->unk_00.z;
            break;
    }

    abs = ABS(var_fv0);
    if (D_8076D8B0 < abs) {
        abs = D_8076D8B0;
        if (var_fv0 < 0) {
            var_fv0 = 0.0f - abs;
        } else {
            var_fv0 = abs;
        }
    }

    arg0->x += (sp2C.y.x * var_fa0) + (sp2C.z.x * var_fv0);
    arg0->y += (sp2C.y.y * var_fa0) + (sp2C.z.y * var_fv0);
    arg0->z += (sp2C.y.z * var_fa0) + (sp2C.z.z * var_fv0);
}

void func_80719140(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {

    if (player->unk_1C <= 60) {
        arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = gRacers[player->id].unk_0C.unk_34;
        player->unk_1C++;
    }
}

void func_807191B0(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 pad;
    f32 temp;
    unk_struct_9C* temp_v1 = &arg1->unk_04.unk_58;
    Racer* temp_a3 = &gRacers[player->id];
    unk_8008112C_arg_1* temp_a0 = &arg1->unk_04;

    if (temp_a3->stateFlags & RACER_STATE_FLAGS_80000) {
        player->unk_04 = 7;
        func_807166B8(player, arg1, arg2);
        return;
    }
    temp_v1->unk_00.unk_00.unk_00.unk_18 += temp_a3->unk_B4.x * 0.3f;
    temp_v1->unk_00.unk_00.unk_00.unk_1C += temp_a3->unk_B4.y * 0.3f;
    temp_v1->unk_00.unk_00.unk_20 += temp_a3->unk_B4.z * 0.3f;

    func_806F6F64((Mtx3F*) &temp_v1->unk_00.unk_00.unk_00.unk_0C);

    temp_a0->unk_00.unk_18[3] = temp_v1->unk_00.unk_00.unk_00.unk_18;
    temp_a0->unk_00.unk_18[4] = temp_v1->unk_00.unk_00.unk_00.unk_1C;
    temp_a0->unk_00.unk_18[5] = temp_v1->unk_00.unk_00.unk_20;

    temp_v1->unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;

    switch (player->unk_18) {
        case 0:
            if (++player->unk_1C >= 180) {
                player->unk_18 = 1;
                player->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.z = 0.005f;
            }
            break;
        case 1:
            if (++player->unk_1C >= 300) {
                player->unk_1C = 0;
                temp_v1->unk_00.unk_00.unk_30.y = (Math_Rand1() % 451) + 50.0f;
            }
            temp_v1->unk_00.unk_00.unk_48.y += 0.4f;

            if (temp_v1->unk_00.unk_00.unk_48.y >= 360.0f) {
                temp_v1->unk_00.unk_00.unk_48.y -= 360.0f;
            }
            break;
        default:
            break;
    }

    if ((D_8076D6C0 == player->id) && (gNumPlayers == 2)) {

        if (player->unk_E4 < player->unk_E6) {
            temp = (f32) (player->unk_E4 + 1) / player->unk_E6;
            arg1->unk_04.unk_00.unk_18[13] = -30.0f - (-30.0f * temp);
        } else {
            arg1->unk_04.unk_00.unk_18[13] = 0.0f;
        }
    }
}

void func_80719420(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    Racer* racer = &gRacers[player->id];

    if (racer->stateFlags & RACER_STATE_FLAGS_80000) {
        player->unk_04 = 7;
        func_807166B8(player, arg1, arg2);
    }
}

extern unk_struct_C D_800993D0[];
extern unk_struct_C D_800996E0[];
extern unk_struct_C D_80099A60[];
extern unk_struct_C D_80099F70[];
extern unk_struct_C D_8009A090[];
extern unk_struct_C D_8009A210[];
extern u16 D_8009AD16;

void func_80719480(Player* player, unk_struct_F8* arg1, unk_800E5D70* arg2) {
    s32 var_s3 = true;
    Racer* temp_a3;
    unk_struct_9C* temp_v0;
    unk_struct_C* var_a1;

    while (var_s3) {

        var_s3 = false;
        switch (player->unk_18) {
            case 0:
                if (func_80719868(1)) {
                    if (D_8009AD16 & 0x40) {
                        var_s3 = true;
                        player->unk_18 = 2;
                        func_80711D58(arg1, &D_807765E8.unk_58);
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                        arg1->unk_04.unk_58.unk_00.unk_54.z = -132.0f;
                    } else {
                        player->unk_18 = 1;
                        player->unk_1C = 0;
                        if (D_807A1598 == 0) {
                            var_a1 = D_800993D0;
                        } else if (D_807A1598 == 1) {
                            var_a1 = D_80099A60;
                        } else {
                            var_a1 = D_800996E0;
                        }
                        func_80714000(arg2, var_a1);
                        temp_a3 = &gRacers[D_807A1598];
                        func_80713FE4(&D_807A1480[player->id], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    }
                }
                break;
            case 1:
                if (func_8071403C(arg2)) {
                    player->unk_18 = 2;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.y = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_00.unk_3C.z = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.x = 0.0f;
                    arg1->unk_04.unk_58.unk_00.unk_54.y = 37.0f;
                    var_s3 = true;
                    temp_v0 = &arg1->unk_04.unk_58;
                    if (D_8009AD16 & 2) {
                        temp_v0->unk_00.unk_54.z = 132.0f;
                    } else {
                        temp_v0->unk_00.unk_54.z = -132.0f;
                    }
                }
                break;
            case 2:
                temp_a3 = &gRacers[D_807A1598];
                *((Mtx3F*) &arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_0C) = temp_a3->unk_C0;
                arg1->unk_04.unk_58.unk_00.unk_00.unk_00.unk_00 = temp_a3->unk_180;
                if (func_80719868(4)) {
                    player->unk_18 = 3;
                    player->unk_1C = 0;
                    temp_a3 = &gRacers[2];
                    func_80713FE4(&D_807A1480[player->id], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80714000(arg2, D_8009A210);
                }
                break;
            case 3:
                if (func_8071403C(arg2) && func_80719868(3)) {
                    player->unk_18 = 4;
                    player->unk_1C = 0;
                    temp_a3 = &gRacers[1];
                    func_80713FE4(&D_807A1480[player->id], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80714000(arg2, D_8009A090);
                }
                break;
            case 4:
                if (func_8071403C(arg2) && func_80719868(2)) {
                    player->unk_18 = 5;
                    player->unk_1C = 0;
                    temp_a3 = &gRacers[0];
                    func_80713FE4(&D_807A1480[player->id], &temp_a3->unk_180, &temp_a3->unk_C0, temp_a3);
                    func_80714000(arg2, D_80099F70);
                }
                break;
            case 5:
                func_8071403C(arg2);
                break;
        }
    }
    // FAKE, likely some recast somewhere
    if (!arg1) {}
}

void func_8071985C(s32 arg0) {
    D_807A1594 = arg0;
}

bool func_80719868(s32 arg0) {
    bool var_v1 = false;

    if (arg0 == D_807A1594) {
        var_v1 = true;
        D_807A1594 = 0;
    }
    return var_v1;
}

Gfx* func_80719890(Gfx* gfx) {

    gSPPerspNormalize(gfx++, gPlayers[0].unk_118);
    gSPMatrix(gfx++, &D_1000000.unk_1A208[gPlayers[0].id], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    return func_80713E38(gfx, 0, gPlayers->id);
}
