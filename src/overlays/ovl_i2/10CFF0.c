#include "global.h"

unk_80111870 D_800D1330[32];
s32 D_800D17B0;
s32 D_800D17B4;
unk_80111870 D_800D17B8[32];
s32 D_800D1C38;
s32 D_800D1C3C;
unk_80111870 D_800D1C40[8];
s32 D_800D1D60;
s32 D_800D1D64;
unk_801122A8 D_800D1D68[32];
s32 D_800D25E8;
s32 D_800D25EC;
unk_80111870 D_800D25F0[32];
s32 D_800D2A70;
s32 D_800D2A74;
unk_80112FB8 D_800D2A78[32];
s32 D_800D2BF8;
s32 D_800D2BFC;
unk_80113140 D_800D2C00[128];
s32 D_800D5800;
s32 D_800D5804;

void func_i2_800AB6B0(void) {
    s32 i;

    D_800D17B0 = D_800D17B4 = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D1330); i++) {
        D_800D1330[i].unk_1C = 0;
    }

    D_800D1C38 = D_800D1C3C = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D17B8); i++) {
        D_800D17B8[i].unk_1C = 0;
    }

    D_800D1D60 = D_800D1D64 = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D1C40); i++) {
        D_800D1C40[i].unk_1C = 0;
    }

    D_800D25E8 = D_800D25EC = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D1D68); i++) {
        D_800D1D68[i].unk_3C = 0;
    }

    D_800D2A70 = D_800D2A74 = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D25F0); i++) {
        D_800D25F0[i].unk_1C = 0;
    }

    D_800D2BF8 = D_800D2BFC = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D2A78); i++) {
        D_800D2A78[i].unk_04 = 0;
    }

    D_800D5800 = D_800D5804 = 0;

    for (i = 0; i < ARRAY_COUNT(D_800D2C00); i++) {
        D_800D2C00[i].unk_50 = 0;
    }
}

extern s8 gGamePaused;

void func_i2_800AB82C(void) {
    u32 var_s2;
    s32 var_s3;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    unk_80111870* var;
    unk_801122A8* var2;
    unk_80112FB8* var3;
    unk_80113140* var4;

    if (gGamePaused) {
        return;
    }

    for (var_s3 = D_800D17B4, var_s2 = (D_800D17B0 - 1), var_s2 %= ARRAY_COUNT(D_800D1330); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D1330), var_s3--) {
        var = &D_800D1330[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 16;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.05f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_800D17B4--;
        }
    }

    for (var_s3 = D_800D1C3C, var_s2 = (D_800D1C38 - 1), var_s2 %= ARRAY_COUNT(D_800D17B8); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D17B8), var_s3--) {
        var = &D_800D17B8[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 16;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_800D1C3C--;
        }
    }

    for (var_s3 = D_800D1D64, var_s2 = (D_800D1D60 - 1), var_s2 %= ARRAY_COUNT(D_800D1C40); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D1C40), var_s3--) {
        var = &D_800D1C40[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 32;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_800D1D64--;
        }
    }

    for (var_s3 = D_800D25EC, var_s2 = (D_800D25E8 - 1), var_s2 %= ARRAY_COUNT(D_800D1D68); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D1D68), var_s3--) {
        var2 = &D_800D1D68[var_s2];
        var2->unk_3C = (var2->unk_3C + 1) % 64;

        if (var2->unk_3C != 0) {
            Racer* racer = var2->unk_40;
            var2->unk_00.x += var2->unk_0C.x -= 0.4f * racer->unk_A8.x;
            var2->unk_00.y += var2->unk_0C.y -= 0.4f * racer->unk_A8.y;
            var2->unk_00.z += var2->unk_0C.z -= 0.4f * racer->unk_A8.z;

            temp_fv1 = 1.0f / sqrtf(SQ(var2->unk_0C.x) + SQ(var2->unk_0C.y) + SQ(var2->unk_0C.z));
            var2->unk_18.x = var2->unk_0C.x * temp_fv1;
            var2->unk_18.y = var2->unk_0C.y * temp_fv1;
            var2->unk_18.z = var2->unk_0C.z * temp_fv1;

            var2->unk_24.x += var2->unk_30.x;
            var2->unk_24.y += var2->unk_30.y;
            var2->unk_24.z += var2->unk_30.z;

            var2->unk_30.x = (var2->unk_24.y * var2->unk_18.z) - (var2->unk_24.z * var2->unk_18.y);
            var2->unk_30.y = (var2->unk_24.z * var2->unk_18.x) - (var2->unk_24.x * var2->unk_18.z);
            var2->unk_30.z = (var2->unk_24.x * var2->unk_18.y) - (var2->unk_24.y * var2->unk_18.x);

            temp_fv1 = 1.0f / sqrtf(SQ(var2->unk_30.x) + SQ(var2->unk_30.y) + SQ(var2->unk_30.z));
            var2->unk_30.x *= temp_fv1;
            var2->unk_30.y *= temp_fv1;
            var2->unk_30.z *= temp_fv1;

            var2->unk_24.x = (var2->unk_18.y * var2->unk_30.z) - (var2->unk_18.z * var2->unk_30.y);
            var2->unk_24.y = (var2->unk_18.z * var2->unk_30.x) - (var2->unk_18.x * var2->unk_30.z);
            var2->unk_24.z = (var2->unk_18.x * var2->unk_30.y) - (var2->unk_18.y * var2->unk_30.x);
        } else {
            D_800D25EC--;
        }
    }

    for (var_s3 = D_800D2A74, var_s2 = (D_800D2A70 - 1), var_s2 %= ARRAY_COUNT(D_800D25F0); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D25F0), var_s3--) {
        var = &D_800D25F0[var_s2];
        var->unk_1C = (var->unk_1C + 1) % 32;
        if (var->unk_1C != 0) {
            var->unk_18 *= 1.02f;
            var->unk_00.x += var->unk_0C.x;
            var->unk_00.y += var->unk_0C.y;
            var->unk_00.z += var->unk_0C.z;
        } else {
            D_800D2A74--;
        }
    }

    for (var_s3 = D_800D2BFC, var_s2 = (D_800D2BF8 - 1), var_s2 %= ARRAY_COUNT(D_800D2A78); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D2A78), var_s3--) {
        var3 = &D_800D2A78[var_s2];
        var3->unk_04++;
        if (var3->unk_04 > 65) {
            var3->unk_04 = 0;
            D_800D2BFC--;
        }
        if (var3->unk_04 >= 53 && var3->unk_04 < 63) {
            Racer* racer = var3->unk_08;
            temp_fs2 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            temp_fs0 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 0.4f) + 0.4f;
            temp_fs1 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 1.8f) - 0.9f;
            func_i2_800ACABC(((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.x,
                             ((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.y,
                             ((s32) (Math_Rand1() % 16) - 8) + racer->segmentPositionInfo.pos.z,
                             racer->velocity.x + (temp_fs2 * racer->unk_C0.z.x) + (temp_fs0 * racer->unk_C0.y.x) +
                                 (temp_fs1 * racer->unk_C0.x.x),
                             racer->velocity.y + (temp_fs2 * racer->unk_C0.z.y) + (temp_fs0 * racer->unk_C0.y.y) +
                                 (temp_fs1 * racer->unk_C0.x.y),
                             racer->velocity.z + (temp_fs2 * racer->unk_C0.z.z) + (temp_fs0 * racer->unk_C0.y.z) +
                                 (temp_fs1 * racer->unk_C0.x.z),
                             30.0f, var3->unk_08);
        }
    }

    for (var_s3 = D_800D5804, var_s2 = (D_800D5800 - 1), var_s2 %= ARRAY_COUNT(D_800D2C00); var_s3 != 0;
         var_s2 = (var_s2 - 1) % ARRAY_COUNT(D_800D2C00), var_s3--) {
        var4 = &D_800D2C00[var_s2];
        var4->unk_50 = (var4->unk_50 + 1) % 64;
        if (var4->unk_50 != 0) {
            var4->unk_24.x += 0xCC;

            temp_fv0 = SIN(var4->unk_24.x) * 1.5f;
            var4->unk_00.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_00.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_00.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_24.y += 0xCC;
            temp_fv0 = SIN(var4->unk_24.y) * 1.5f;
            var4->unk_0C.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_0C.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_0C.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_24.z += 0xCC;
            temp_fv0 = SIN(var4->unk_24.z) * 1.5f;
            var4->unk_18.x += var4->unk_30.x + (temp_fv0 * var4->unk_3C.x);
            var4->unk_18.y += var4->unk_30.y + (temp_fv0 * var4->unk_3C.y);
            var4->unk_18.z += var4->unk_30.z + (temp_fv0 * var4->unk_3C.z);

            var4->unk_30.x = (var4->unk_30.x * 0.98f) - (0.2f * var4->unk_54->unk_A8.x);
            var4->unk_30.y = (var4->unk_30.y * 0.98f) - (0.2f * var4->unk_54->unk_A8.y);
            var4->unk_30.z = (var4->unk_30.z * 0.98f) - (0.2f * var4->unk_54->unk_A8.z);
            var4->unk_4E = 255 - (s32) (SIN(var4->unk_24.x & 0x7FF) * 255.0f);
        } else {
            D_800D5804--;
        }
    }
}

s32 func_i2_800AC680(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_800D17B4 < 0x20) {
        if (arg7->unk_220 != 0) {
            return -1;
        }
        arg7->unk_220 = 5;
        temp_v1 = &D_800D1330[D_800D17B0];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_800D17B0 = (D_800D17B0 + 1) % 32U;
        D_800D17B4++;
        return 0;
    }
    return -1;
}

s32 func_i2_800AC750(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_800D1C3C < 0x20) {
        temp_v1 = &D_800D17B8[D_800D1C38];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_800D1C38 = (D_800D1C38 + 1) % 32U;
        D_800D1C3C++;
        return 0;
    }
    return -1;
}

s32 func_i2_800AC808(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_800D1D64 < 8) {
        temp_v1 = &D_800D1C40[D_800D1D60];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_800D1D60 = (D_800D1D60 + 1) % 8U;
        D_800D1D64++;
        return 0;
    }
    return -1;
}

s32 func_i2_800AC8C0(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Racer* arg6) {
    unk_801122A8* temp_v1;
    f32 temp_fa1;

    if (D_800D25EC < 0x20) {
        temp_v1 = &D_800D1D68[D_800D25E8];
        temp_fa1 = SQ(arg3) + SQ(arg4) + SQ(arg5);
        if (temp_fa1 < 0.01f) {
            return -1;
        }

        temp_fa1 = 1.0f / sqrtf(temp_fa1);

        temp_v1->unk_18.x = temp_fa1 * arg3;
        temp_v1->unk_18.y = temp_fa1 * arg4;
        temp_v1->unk_18.z = temp_fa1 * arg5;

        temp_fa1 = SQ(temp_v1->unk_18.z) + SQ(temp_v1->unk_18.x);

        if (temp_fa1 < 0.01f) {
            return -1;
        }

        temp_fa1 = 1.0f / sqrtf(temp_fa1);

        temp_v1->unk_30.x = temp_v1->unk_18.z * temp_fa1;
        temp_v1->unk_30.y = 0.0f;
        temp_v1->unk_30.z = -temp_v1->unk_18.x * temp_fa1;

        temp_v1->unk_24.x = temp_v1->unk_18.y * temp_v1->unk_30.z;
        temp_v1->unk_24.y = (temp_v1->unk_18.z * temp_v1->unk_30.x) - (temp_v1->unk_18.x * temp_v1->unk_30.z);
        temp_v1->unk_24.z = -temp_v1->unk_18.y * temp_v1->unk_30.x;
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_40 = arg6;
        D_800D25E8 = (D_800D25E8 + 1) % 32U;
        D_800D25EC++;
        return 0;
    }

    return -1;
}

s32 func_i2_800ACABC(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, Racer* arg7) {
    unk_80111870* temp_v1;

    if (D_800D2A74 < 0x20) {
        temp_v1 = &D_800D25F0[D_800D2A70];
        temp_v1->unk_00.x = arg0 + arg3;
        temp_v1->unk_00.y = arg1 + arg4;
        temp_v1->unk_00.z = arg2 + arg5;
        temp_v1->unk_0C.x = arg3;
        temp_v1->unk_0C.y = arg4;
        temp_v1->unk_0C.z = arg5;
        temp_v1->unk_18 = arg6;
        temp_v1->unk_20 = arg7;
        D_800D2A70 = (D_800D2A70 + 1) % 32U;
        D_800D2A74++;
        return 0;
    }

    return -1;
}

s32 func_i2_800ACB74(f32 arg0, Racer* arg1) {
    unk_80112FB8* temp_v1;

    if (D_800D2BFC < 32) {
        temp_v1 = &D_800D2A78[D_800D2BF8];
        temp_v1->unk_00 = arg0;
        temp_v1->unk_08 = arg1;
        D_800D2BF8 = (D_800D2BF8 + 1) % 32U;
        D_800D2BFC++;
        return 0;
    }
    return -1;
}

s32 func_i2_800ACBE8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, Mtx3F* arg6, s32 arg7, s32 arg8,
                     s32 arg9, Racer* argA) {
    unk_80113140* temp_s1;
    f32 temp_fs0;
    f32 temp_fv0;

    if (D_800D5804 < 128) {
        temp_s1 = &D_800D2C00[D_800D5800];
        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_00.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_00.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_00.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);

        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_0C.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_0C.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_0C.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);

        temp_fs0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_fv0 = ((Math_Rand1() & 0x1FFFF) * (15.0f / 131071.0f)) - 7.5f;
        temp_s1->unk_18.x = arg0 + (temp_fs0 * arg6->z.x) + (temp_fv0 * arg6->x.x);
        temp_s1->unk_18.y = arg1 + (temp_fs0 * arg6->z.y) + (temp_fv0 * arg6->x.y);
        temp_s1->unk_18.z = arg2 + (temp_fs0 * arg6->z.z) + (temp_fv0 * arg6->x.z);
        temp_s1->unk_24.x = Math_Rand1() % 4096;
        temp_s1->unk_24.y = Math_Rand1() % 4096;
        temp_s1->unk_24.z = Math_Rand1() % 4096;
        temp_s1->unk_30.x = arg3;
        temp_s1->unk_30.y = arg4;
        temp_s1->unk_30.z = arg5;
        temp_s1->unk_3C.x = arg6->y.x;
        temp_s1->unk_3C.y = arg6->y.y;
        temp_s1->unk_3C.z = arg6->y.z;
        temp_s1->unk_48 = arg7;
        temp_s1->unk_4A = arg8;
        temp_s1->unk_4C = arg9;
        temp_s1->unk_4E = 0;
        temp_s1->unk_54 = argA;
        D_800D5800 = (D_800D5800 + 1) % 128U;
        D_800D5804++;
        return 0;
    }
    return -1;
}
