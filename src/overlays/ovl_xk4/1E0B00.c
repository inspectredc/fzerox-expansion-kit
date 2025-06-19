#include "global.h"
#include "assets/overlays/ovl_xk4/ending_dd_animation.h"
#include "assets/overlays/ovl_xk4/a1E0B00.h"
#include "assets/overlays/ovl_xk4/ending_dd_congratulations.h"

#define PHYSICAL_TO_VIRTUAL(x) (((uintptr_t) x) + 0x80000000)

typedef struct unk_800D7AB4 {
    Gfx* unk_00;
    Vec3f unk_04;
    Vec3f unk_10;
    Vec3s unk_1C;
    struct unk_800D7AB4* unk_24;
    struct unk_800D7AB4* unk_28;
    struct unk_800D7AB4* unk_2C;
    Gfx* unk_30;
    s16 unk_34;
} unk_800D7AB4;

typedef struct unk_800D80E8 {
    s16 unk_00;
    s16 unk_02;
    f32* unk_04;
    s32* unk_08;
    s16* unk_0C;
    s32* unk_10;
    s16* unk_14;
    s32* unk_18;
} unk_800D80E8;

extern unk_800D7AB4 D_xk4_800EC998;
extern unk_800D7AB4 D_xk4_800EC960;
extern unk_800D7AB4 D_xk4_800EC928;
extern unk_800D7AB4 D_xk4_800EC8F0;
extern unk_800D7AB4 D_xk4_800EC8B8;
extern unk_800D7AB4 D_xk4_800EC880;
extern unk_800D7AB4 D_xk4_800EC848;
extern unk_800D7AB4 D_xk4_800EC810;
extern unk_800D7AB4 D_xk4_800EC7D8;
extern unk_800D7AB4 D_xk4_800EC7A0;
extern unk_800D7AB4 D_xk4_800EC768;
extern unk_800D7AB4 D_xk4_800EC730;
extern unk_800D7AB4 D_xk4_800EC6F8;
extern unk_800D7AB4 D_xk4_800EC6C0;
extern unk_800D7AB4 D_xk4_800EC688;
extern unk_800D7AB4 D_xk4_800EC650;
extern unk_800D7AB4 D_xk4_800EC618;
extern unk_800D7AB4 D_xk4_800EC5E0;
extern unk_800D7AB4 D_xk4_800EC5A8;
extern unk_800D7AB4 D_xk4_800EC570;
extern unk_800D7AB4 D_xk4_800EC538;
extern unk_800D7AB4 D_xk4_800EC500;
extern unk_800D7AB4 D_xk4_800EC4C8;
extern unk_800D7AB4 D_xk4_800EC490;
extern unk_800D7AB4 D_xk4_800EC458;
extern unk_800D7AB4 D_xk4_800EC420;
extern unk_800D7AB4 D_xk4_800EC3E8;
extern unk_800D7AB4 D_xk4_800EC3B0;
extern unk_800D7AB4 D_xk4_800EC378;
extern unk_800D7AB4 D_xk4_800EC340;
extern unk_800D7AB4 D_xk4_800EC308;
extern unk_800D7AB4 D_xk4_800EC2D0;
extern unk_800D7AB4 D_xk4_800EC298;
extern unk_800D7AB4 D_xk4_800EC260;
extern unk_800D7AB4 D_xk4_800EC228;
extern unk_800D7AB4 D_xk4_800EC1F0;
extern unk_800D7AB4 D_xk4_800EC1B8;
extern unk_800D7AB4 D_xk4_800EC180;
extern unk_800D7AB4 D_xk4_800EC148;
extern unk_800D7AB4 D_xk4_800EC110;
extern unk_800D7AB4 D_xk4_800EC0D8;
extern unk_800D7AB4 D_xk4_800EC0A0;

f32 D_800F1AE0[0x1400];
f32* D_xk4_800F6AE0;
Gfx* D_xk4_800F6AE4;
UNUSED s32 D_xk4_800F6AE8;
UNUSED s32 D_xk4_800F6AEC;
s32 D_xk4_800F6AF0[16];
s16 D_xk4_800F6B30;
s32* D_xk4_800F6B34;
s32* D_xk4_800F6B38;
s32* D_xk4_800F6B3C;
f32* D_xk4_800F6B40;
s16* D_xk4_800F6B44;
s16* D_xk4_800F6B48;
Mtx* D_xk4_800F6B4C;
UNUSED s32 D_xk4_800F6B50;

// clang-format off
UNUSED Mtx D_xk4_800D8A60 = {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1,
};
// clang-format on

#include "src/assets/overlays/ovl_xk4/ending_dd_animation/ending_dd_animation.c"

unk_800D80E8 D_xk4_800DA22C = {
    40, 42, D_xk4_800D8AA0, D_xk4_800D963C, D_xk4_800D8AAC, D_xk4_800D9A2C, D_xk4_800D9564, D_xk4_800D9E1C,
};

UNUSED s32 D_xk4_800DA248 = 0;
UNUSED s32 D_xk4_800DA24C = 0;

#include "src/assets/overlays/ovl_xk4/a1E0B00/a1E0B00.c"

// TODO: Extract via Torch
unk_800D7AB4 D_xk4_800EC0A0 = {
    D_xk4_800EBC00, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC420,      D_xk4_800EBBE0,       41,
};

unk_800D7AB4 D_xk4_800EC0D8 = {
    D_xk4_800EBC68, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC0A0,      D_xk4_800EBC48,       40,
};

unk_800D7AB4 D_xk4_800EC110 = {
    D_xk4_800EBCB8, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC0D8,      D_xk4_800EBCA0,       39,
};

unk_800D7AB4 D_xk4_800EC148 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 450.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC110, NULL, NULL, NULL, 38,
};

unk_800D7AB4 D_xk4_800EC180 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 472.0f, 0.0f, 0.0f },
    { 0x1C96, 0, 0x1212 },
    &D_xk4_800EC0D8,
    &D_xk4_800EC148,
    NULL,
    NULL,
    37,
};

unk_800D7AB4 D_xk4_800EC1B8 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 571.0f, 0.0f, 0.0f },
    { 0x2A50, 0x9ED8, 0xD0EE },
    &D_xk4_800EC0A0,
    &D_xk4_800EC180,
    NULL,
    NULL,
    36,
};

unk_800D7AB4 D_xk4_800EC1F0 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0xD5F4, 0xA515 }, NULL, &D_xk4_800EC1B8, NULL, NULL, 35,
};

unk_800D7AB4 D_xk4_800EC228 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 667.0f, 374.0f, 0.0f }, { 0, 0, 0xBFBD }, NULL, &D_xk4_800EC1F0, NULL, NULL, 34,
};

unk_800D7AB4 D_xk4_800EC260 = {
    D_xk4_800EBCF8, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC420,      D_xk4_800EBCD8,       33,
};

unk_800D7AB4 D_xk4_800EC298 = {
    D_xk4_800EBD60, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC260,      D_xk4_800EBD40,       32,
};

unk_800D7AB4 D_xk4_800EC2D0 = {
    D_xk4_800EBDB0, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC298,      D_xk4_800EBD98,       31,
};

unk_800D7AB4 D_xk4_800EC308 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 450.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC2D0, NULL, NULL, NULL, 30,
};

unk_800D7AB4 D_xk4_800EC340 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 472.0f, 0.0f, 0.0f },
    { 0xFE7B, 0xFF8B, 0xE31F },
    &D_xk4_800EC298,
    &D_xk4_800EC308,
    NULL,
    NULL,
    29,
};

unk_800D7AB4 D_xk4_800EC378 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 571.0f, 0.0f, 0.0f },
    { 0x8813, 0x7F02, 0x7902 },
    &D_xk4_800EC260,
    &D_xk4_800EC340,
    NULL,
    NULL,
    28,
};

unk_800D7AB4 D_xk4_800EC3B0 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0x8001, 0x8689, 0x235C }, NULL, &D_xk4_800EC378, NULL, NULL, 27,
};

unk_800D7AB4 D_xk4_800EC3E8 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 662.0f, -370.0f, 0.0f },
    { 0, 0x7FFE, 0xBFBD },
    &D_xk4_800EC228,
    &D_xk4_800EC3B0,
    NULL,
    NULL,
    26,
};

unk_800D7AB4 D_xk4_800EC420 = {
    D_xk4_800EBDE8, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC3E8,
    NULL,           &D_xk4_800EC8F0,      D_xk4_800EBDD0,       25,
};

unk_800D7AB4 D_xk4_800EC458 = {
    D_xk4_800EBE40, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC420,      D_xk4_800EBE28,       24,
};

unk_800D7AB4 D_xk4_800EC490 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 522.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC458, NULL, NULL, NULL, 23,
};

unk_800D7AB4 D_xk4_800EC4C8 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 682.0f, 0.0f, 0.0f },
    { 0x0507, 0xFE2F, 0x02E8 },
    &D_xk4_800EC420,
    &D_xk4_800EC490,
    NULL,
    NULL,
    22,
};

unk_800D7AB4 D_xk4_800EC500 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0xFAEE, 0, 0x42EB }, NULL, &D_xk4_800EC4C8, NULL, NULL, 21,
};

unk_800D7AB4 D_xk4_800EC538 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { -93.0f, -1.0f, 0.0f }, { 0, 0, 0x407A }, NULL, &D_xk4_800EC500, NULL, NULL, 20,
};

unk_800D7AB4 D_xk4_800EC570 = {
    D_xk4_800EBEC0, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC8F0,      D_xk4_800EBEA8,       19,
};

unk_800D7AB4 D_xk4_800EC5A8 = {
    D_xk4_800EBF28, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC570,      D_xk4_800EBF10,       18,
};

unk_800D7AB4 D_xk4_800EC5E0 = {
    D_xk4_800EBF78, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC5A8,      D_xk4_800EBF68,       17,
};

unk_800D7AB4 D_xk4_800EC618 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 543.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC5E0, NULL, NULL, NULL, 16,
};

unk_800D7AB4 D_xk4_800EC650 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 843.0f, 0.0f, 0.0f },
    { 0xFE5C, 0x00B6, 0xC906 },
    &D_xk4_800EC5A8,
    &D_xk4_800EC618,
    NULL,
    NULL,
    15,
};

unk_800D7AB4 D_xk4_800EC688 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 631.0f, 0.0f, 0.0f }, { 0, 0, 0x1CFF }, &D_xk4_800EC570, &D_xk4_800EC650, NULL, NULL,
    14,
};

unk_800D7AB4 D_xk4_800EC6C0 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0xFFB9, 0x00A5, 0xAD43 }, NULL, &D_xk4_800EC688, NULL, NULL, 13,
};

unk_800D7AB4 D_xk4_800EC6F8 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 254.0f, -296.0f, 37.0f },
    { 0, 0x2A67, 0x407A },
    &D_xk4_800EC538,
    &D_xk4_800EC6C0,
    NULL,
    NULL,
    12,
};

unk_800D7AB4 D_xk4_800EC730 = {
    D_xk4_800EBFA8, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC8F0,      D_xk4_800EBF90,       11,
};

unk_800D7AB4 D_xk4_800EC768 = {
    D_xk4_800EC010, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC730,      D_xk4_800EBFF8,       10,
};

unk_800D7AB4 D_xk4_800EC7A0 = {
    D_xk4_800EC060, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, NULL,
    NULL,           &D_xk4_800EC768,      D_xk4_800EC050,       9,
};

unk_800D7AB4 D_xk4_800EC7D8 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 543.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC7A0, NULL, NULL, NULL, 8,
};

unk_800D7AB4 D_xk4_800EC810 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 843.0f, 0.0f, 0.0f },
    { 0xFF94, 0xFF6C, 0xC2E2 },
    &D_xk4_800EC768,
    &D_xk4_800EC7D8,
    NULL,
    NULL,
    7,
};

unk_800D7AB4 D_xk4_800EC848 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 631.0f, 0.0f, 0.0f }, { 0, 0, 0x0037 }, &D_xk4_800EC730, &D_xk4_800EC810, NULL, NULL,
    6,
};

unk_800D7AB4 D_xk4_800EC880 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0x0002, 0xFCA1, 0xBE6D }, NULL, &D_xk4_800EC848, NULL, NULL, 5,
};

unk_800D7AB4 D_xk4_800EC8B8 = {
    NULL,
    { 1.0f, 1.0f, 1.0f },
    { 247.0f, 288.0f, 37.0f },
    { 0x7E29, 0x2D3D, 0xBCCD },
    &D_xk4_800EC6F8,
    &D_xk4_800EC880,
    NULL,
    NULL,
    4,
};

unk_800D7AB4 D_xk4_800EC8F0 = {
    D_xk4_800EC078, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC8B8, NULL, NULL, NULL, 3,
};

unk_800D7AB4 D_xk4_800EC928 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 379.0f, 0.0f, 0.0f }, { 0, 0, 0 }, &D_xk4_800EC8F0, NULL, NULL, NULL, 2,
};

unk_800D7AB4 D_xk4_800EC960 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0, 0, 0xBF86 }, NULL, &D_xk4_800EC928, NULL, NULL, 1,
};

unk_800D7AB4 D_xk4_800EC998 = {
    NULL, { 1.0f, 1.0f, 1.0f }, { 843.0f, -279.0f, 0.0f }, { 0, 0, 0 }, NULL, &D_xk4_800EC960, NULL, NULL, 0,
};

unk_800D7AB4* D_xk4_800EC9D0[] = {
    &D_xk4_800EC998, &D_xk4_800EC960, &D_xk4_800EC928, &D_xk4_800EC8F0, &D_xk4_800EC8B8, &D_xk4_800EC880,
    &D_xk4_800EC848, &D_xk4_800EC810, &D_xk4_800EC7D8, &D_xk4_800EC7A0, &D_xk4_800EC768, &D_xk4_800EC730,
    &D_xk4_800EC6F8, &D_xk4_800EC6C0, &D_xk4_800EC688, &D_xk4_800EC650, &D_xk4_800EC618, &D_xk4_800EC5E0,
    &D_xk4_800EC5A8, &D_xk4_800EC570, &D_xk4_800EC538, &D_xk4_800EC500, &D_xk4_800EC4C8, &D_xk4_800EC490,
    &D_xk4_800EC458, &D_xk4_800EC420, &D_xk4_800EC3E8, &D_xk4_800EC3B0, &D_xk4_800EC378, &D_xk4_800EC340,
    &D_xk4_800EC308, &D_xk4_800EC2D0, &D_xk4_800EC298, &D_xk4_800EC260, &D_xk4_800EC228, &D_xk4_800EC1F0,
    &D_xk4_800EC1B8, &D_xk4_800EC180, &D_xk4_800EC148, &D_xk4_800EC110, &D_xk4_800EC0D8, &D_xk4_800EC0A0,
};

#include "src/assets/overlays/ovl_xk4/ending_dd_congratulations/ending_dd_congratulations.c"

f32 func_xk4_800D6D90(f32 arg0) {
    s32 i;
    f64 var_fv1 = arg0;
    f64 var_fa1 = -var_fv1 * var_fv1 * var_fv1;
    f64 var_ft4 = -var_fv1 * var_fv1;
    f64 var_ft5 = 6.0;
    f64 var_fa0;

    for (i = 2; i < 14; i++) {
        var_fa0 = var_fa1 / var_ft5;
        var_fa1 *= var_ft4;
        var_ft5 *= i * ((i << 2) + 2);
        var_fv1 += var_fa0;
    }
    return var_fv1;
}

void func_xk4_800D6F38(void) {
    s32 i;

    for (i = 0; i < 0x1400; i++) {
        D_800F1AE0[i] = func_xk4_800D6D90(2.0f * (((f32) i / 4096) * 3.1415927f));
    }
    D_xk4_800F6AE0 = &D_800F1AE0[0x400];
}

void func_xk4_800D6FD0(Mtx* arg0, MtxF* arg1) {
    s32 temp_ft2;

    temp_ft2 = arg1->m[3][3] * 65536.0f;
    arg0->u.i[3][3] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[3][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[3][2] * 65536.0f;
    arg0->u.i[2][3] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[2][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[3][1] * 65536.0f;
    arg0->u.i[1][3] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[1][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[3][0] * 65536.0f;
    arg0->u.i[0][3] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[0][3] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[2][3] * 65536.0f;
    arg0->u.i[3][2] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[3][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[2][2] * 65536.0f;
    arg0->u.i[2][2] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[2][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[2][1] * 65536.0f;
    arg0->u.i[1][2] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[1][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[2][0] * 65536.0f;
    arg0->u.i[0][2] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[0][2] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[1][3] * 65536.0f;
    arg0->u.i[3][1] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[3][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[1][2] * 65536.0f;
    arg0->u.i[2][1] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[2][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[1][1] * 65536.0f;
    arg0->u.i[1][1] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[1][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[1][0] * 65536.0f;
    arg0->u.i[0][1] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[0][1] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[0][3] * 65536.0f;
    arg0->u.i[3][0] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[3][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[0][2] * 65536.0f;
    arg0->u.i[2][0] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[2][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[0][1] * 65536.0f;
    arg0->u.i[1][0] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[1][0] = temp_ft2 & 0xFFFF;
    temp_ft2 = arg1->m[0][0] * 65536.0f;
    arg0->u.i[0][0] = ((u32) temp_ft2 >> 0x10);
    arg0->u.f[0][0] = temp_ft2 & 0xFFFF;
}

void func_xk4_800D71DC(MtxF* arg0, MtxF* arg1, MtxF* arg2) {
    arg0->m[0][0] = (arg1->m[0][0] * arg2->m[0][0]) + (arg1->m[0][1] * arg2->m[1][0]) + (arg1->m[0][2] * arg2->m[2][0]);
    arg0->m[0][1] = (arg1->m[0][0] * arg2->m[0][1]) + (arg1->m[0][1] * arg2->m[1][1]) + (arg1->m[0][2] * arg2->m[2][1]);
    arg0->m[0][2] = (arg1->m[0][0] * arg2->m[0][2]) + (arg1->m[0][1] * arg2->m[1][2]) + (arg1->m[0][2] * arg2->m[2][2]);
    arg0->m[0][3] = (arg1->m[0][0] * arg2->m[0][3]) + (arg1->m[0][1] * arg2->m[1][3]) +
                    (arg1->m[0][2] * arg2->m[2][3]) + arg1->m[0][3];
    arg0->m[1][0] = (arg1->m[1][0] * arg2->m[0][0]) + (arg1->m[1][1] * arg2->m[1][0]) + (arg1->m[1][2] * arg2->m[2][0]);
    arg0->m[1][1] = (arg1->m[1][0] * arg2->m[0][1]) + (arg1->m[1][1] * arg2->m[1][1]) + (arg1->m[1][2] * arg2->m[2][1]);
    arg0->m[1][2] = (arg1->m[1][0] * arg2->m[0][2]) + (arg1->m[1][1] * arg2->m[1][2]) + (arg1->m[1][2] * arg2->m[2][2]);
    arg0->m[1][3] = (arg1->m[1][0] * arg2->m[0][3]) + (arg1->m[1][1] * arg2->m[1][3]) +
                    (arg1->m[1][2] * arg2->m[2][3]) + arg1->m[1][3];
    arg0->m[2][0] = (arg1->m[2][0] * arg2->m[0][0]) + (arg1->m[2][1] * arg2->m[1][0]) + (arg1->m[2][2] * arg2->m[2][0]);
    arg0->m[2][1] = (arg1->m[2][0] * arg2->m[0][1]) + (arg1->m[2][1] * arg2->m[1][1]) + (arg1->m[2][2] * arg2->m[2][1]);
    arg0->m[2][2] = (arg1->m[2][0] * arg2->m[0][2]) + (arg1->m[2][1] * arg2->m[1][2]) + (arg1->m[2][2] * arg2->m[2][2]);
    arg0->m[2][3] = (arg1->m[2][0] * arg2->m[0][3]) + (arg1->m[2][1] * arg2->m[1][3]) +
                    (arg1->m[2][2] * arg2->m[2][3]) + arg1->m[2][3];
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk4_800D7454(MtxF* arg0) {
    arg0->m[0][0] = arg0->m[1][1] = arg0->m[2][2] = arg0->m[3][3] = 1.0f;
    arg0->m[0][1] = arg0->m[0][2] = arg0->m[0][3] = arg0->m[1][0] = arg0->m[1][2] = arg0->m[1][3] = arg0->m[2][0] =
        arg0->m[2][1] = arg0->m[2][3] = arg0->m[3][0] = arg0->m[3][1] = arg0->m[3][2] = 0.0f;
}

void func_xk4_800D74A4(MtxF* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->m[0][0] = arg1;
    arg0->m[1][1] = arg2;
    arg0->m[2][2] = arg3;
    arg0->m[0][1] = 0.0f;
    arg0->m[0][2] = 0.0f;
    arg0->m[1][0] = 0.0f;
    arg0->m[1][2] = 0.0f;
    arg0->m[2][0] = 0.0f;
    arg0->m[2][1] = 0.0f;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[0][3] = 0.0f;
    arg0->m[1][3] = 0.0f;
    arg0->m[2][3] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

s32 func_xk4_800D7504(s32 arg0, s32 arg1) {
    D_xk4_800F6AF0[arg0] = arg1;
    return arg1;
}

s32 func_xk4_800D751C(s32 arg0) {
    return D_xk4_800F6AF0[arg0];
}

Gfx* func_xk4_800D7530(Gfx* gfx, FrameBuffer* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 color;
    s32 i;
    s32 r;
    s32 g;
    s32 b;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_FILL);
    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, PHYSICAL_TO_VIRTUAL(arg1));
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    for (i = 8; i < 232; i++) {
        gDPPipeSync(gfx++);
        r = ((arg2 * (239 - i)) / 239) + ((arg5 * i) / 239);
        g = ((arg3 * (239 - i)) / 239) + ((arg6 * i) / 239);
        b = ((arg4 * (239 - i)) / 239) + ((arg7 * i) / 239);
        gDPSetFillColor(gfx++, GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1));
        gDPFillRectangle(gfx++, 12, i, 307, i);
    }
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);

    return gfx;
}

extern u32 gSegments[];

intptr_t func_xk4_SegmentedToVirtual(uintptr_t segmentedAddr) {
    return PHYSICAL_TO_VIRTUAL(gSegments[SEGMENT_NUMBER(segmentedAddr)] + SEGMENT_OFFSET(segmentedAddr));
}

void func_xk4_800D7894(s32* arg0, s32 arg1) {
    s32 sp1C;
    s32* temp;
    s16 temp_a0;

    sp1C = arg0[0];
    temp = (s32*) func_xk4_SegmentedToVirtual(arg0[3]);
    temp_a0 = *(s16*) func_xk4_SegmentedToVirtual(temp[sp1C]);

    arg0[1] += arg1;
    if (arg0[1] >= temp_a0) {
        arg0[1] -= temp_a0;
    } else if (arg0[1] < 0) {
        arg0[1] += temp_a0;
    }
}

void func_xk4_800D7918(MtxF* arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 var_v0;
    s32 pad;

    var_v0 = (arg1 << 0xC) >> 0x10;
    if (var_v0 < 0) {
        var_v0 += 0x1000;
    }
    temp_fv0 = D_800F1AE0[var_v0];
    temp_fv1 = D_xk4_800F6AE0[var_v0];

    var_v0 = (arg2 << 0xC) >> 0x10;
    if (var_v0 < 0) {
        var_v0 += 0x1000;
    }
    temp_fa0 = D_800F1AE0[var_v0];
    temp_fa1 = D_xk4_800F6AE0[var_v0];

    var_v0 = (arg3 << 0xC) >> 0x10;
    if (var_v0 < 0) {
        var_v0 += 0x1000;
    }
    temp_ft4 = D_800F1AE0[var_v0];
    temp_ft5 = D_xk4_800F6AE0[var_v0];

    arg0->m[0][0] = temp_fa1 * temp_ft5;
    arg0->m[1][0] = temp_fa1 * temp_ft4;
    arg0->m[2][0] = -temp_fa0;
    arg0->m[0][1] = (temp_fv0 * temp_fa0 * temp_ft5) - (temp_fv1 * temp_ft4);
    arg0->m[1][1] = (temp_fv0 * temp_fa0 * temp_ft4) + (temp_fv1 * temp_ft5);
    arg0->m[2][1] = temp_fv0 * temp_fa1;
    arg0->m[0][2] = (temp_fv1 * temp_fa0 * temp_ft5) + (temp_fv0 * temp_ft4);
    arg0->m[1][2] = (temp_fv1 * temp_fa0 * temp_ft4) - (temp_fv0 * temp_ft5);
    arg0->m[2][2] = temp_fv1 * temp_fa1;
    arg0->m[0][3] = arg4;
    arg0->m[1][3] = arg5;
    arg0->m[2][3] = arg6;
    arg0->m[3][0] = 0.0f;
    arg0->m[3][1] = 0.0f;
    arg0->m[3][2] = 0.0f;
    arg0->m[3][3] = 1.0f;
}

void func_xk4_800D7AAC(void) {
}

void func_xk4_800D7AB4(unk_800D7AB4* arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_v1;
    s32* temp_v0;

    temp_v0 = &D_xk4_800F6B34[D_xk4_800F6B30 * 6];
    temp_v1 = *temp_v0++;
    temp_a2 = *temp_v0++;
    temp_a3 = *temp_v0++;
    temp_t0 = *temp_v0++;
    temp_t1 = *temp_v0++;
    temp_t2 = *temp_v0++;

    if (arg1 < temp_v1) {
        arg0->unk_04.x = D_xk4_800F6B40[temp_a2 + arg1];
    } else {
        arg0->unk_04.x = D_xk4_800F6B40[temp_a2 + temp_v1 - 1];
    }
    if (arg1 < temp_a3) {
        arg0->unk_04.y = D_xk4_800F6B40[temp_t0 + arg1];
    } else {
        arg0->unk_04.y = D_xk4_800F6B40[temp_t0 + temp_a3 - 1];
    }
    if (arg1 < temp_t1) {
        arg0->unk_04.z = D_xk4_800F6B40[temp_t2 + arg1];
    } else {
        arg0->unk_04.z = D_xk4_800F6B40[temp_t2 + temp_t1 - 1];
    }
    temp_v0 = &D_xk4_800F6B38[D_xk4_800F6B30 * 6];
    temp_v1 = *temp_v0++;
    temp_a2 = *temp_v0++;
    temp_a3 = *temp_v0++;
    temp_t0 = *temp_v0++;
    temp_t1 = *temp_v0++;
    temp_t2 = *temp_v0++;

    if (arg1 < temp_v1) {
        arg0->unk_1C.x = D_xk4_800F6B44[temp_a2 + arg1];
    } else {
        arg0->unk_1C.x = D_xk4_800F6B44[temp_a2 + temp_v1 - 1];
    }
    if (arg1 < temp_a3) {
        arg0->unk_1C.y = D_xk4_800F6B44[temp_t0 + arg1];
    } else {
        arg0->unk_1C.y = D_xk4_800F6B44[temp_t0 + temp_a3 - 1];
    }
    if (arg1 < temp_t1) {
        arg0->unk_1C.z = D_xk4_800F6B44[temp_t2 + arg1];
    } else {
        arg0->unk_1C.z = D_xk4_800F6B44[temp_t2 + temp_t1 - 1];
    }
    temp_v0 = &D_xk4_800F6B3C[D_xk4_800F6B30 * 6];
    temp_v1 = *temp_v0++;
    temp_a2 = *temp_v0++;
    temp_a3 = *temp_v0++;
    temp_t0 = *temp_v0++;
    temp_t1 = *temp_v0++;
    temp_t2 = *temp_v0++;

    if (arg1 < temp_v1) {
        arg0->unk_10.x = D_xk4_800F6B48[temp_a2 + arg1];
    } else {
        arg0->unk_10.x = D_xk4_800F6B48[temp_a2 + temp_v1 - 1];
    }
    if (arg1 < temp_a3) {
        arg0->unk_10.y = D_xk4_800F6B48[temp_t0 + arg1];
    } else {
        arg0->unk_10.y = D_xk4_800F6B48[temp_t0 + temp_a3 - 1];
    }
    if (arg1 < temp_t1) {
        arg0->unk_10.z = D_xk4_800F6B48[temp_t2 + arg1];
    } else {
        arg0->unk_10.z = D_xk4_800F6B48[temp_t2 + temp_t1 - 1];
    }
}

void func_xk4_800D7E58(void) {
}

void func_xk4_800D7E60(void) {
}

void func_xk4_800D7E68(unk_800D7AB4* arg0, MtxF* arg1, Vec3f* arg2, s32 arg3) {
    unk_800D7AB4* temp_v0;
    MtxF sp104;
    MtxF spC4;
    MtxF sp84;
    s32 temp_s3;
    Vec3f sp74;

    while (arg0 != 0) {
        temp_v0 = (unk_800D7AB4*) func_xk4_SegmentedToVirtual(arg0);
        if ((temp_v0->unk_2C != NULL) && (temp_v0->unk_30 != NULL)) {
            temp_s3 = ((unk_800D7AB4*) func_xk4_SegmentedToVirtual(temp_v0->unk_2C))->unk_34;

            gSPMatrix(D_xk4_800F6AE4++, &D_xk4_800F6B4C[temp_s3], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

            gSPDisplayList(D_xk4_800F6AE4++, temp_v0->unk_30);
            gSPPopMatrix(D_xk4_800F6AE4++, G_MTX_MODELVIEW);
        }
        temp_s3 = temp_v0->unk_34;
        func_xk4_800D7AB4(temp_v0, arg3);
        func_xk4_800D7918(&sp104, temp_v0->unk_1C.x, temp_v0->unk_1C.y, temp_v0->unk_1C.z, temp_v0->unk_10.x * arg2->x,
                          temp_v0->unk_10.y * arg2->y, temp_v0->unk_10.z * arg2->z);
        sp74.x = arg2->x * temp_v0->unk_04.x;
        sp74.y = arg2->y * temp_v0->unk_04.y;
        sp74.z = arg2->z * temp_v0->unk_04.z;
        func_xk4_800D71DC(&spC4, arg1, &sp104);
        func_xk4_800D74A4(&sp84, sp74.x, sp74.y, sp74.z);
        func_xk4_800D71DC(&sp104, &spC4, &sp84);

        func_xk4_800D6FD0(&D_xk4_800F6B4C[temp_s3], &sp104);
        gSPMatrix(D_xk4_800F6AE4++, &D_xk4_800F6B4C[temp_s3], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);

        if (temp_v0->unk_00 != NULL) {
            gSPDisplayList(D_xk4_800F6AE4++, temp_v0->unk_00);
        }

        gSPPopMatrix(D_xk4_800F6AE4++, G_MTX_MODELVIEW);
        D_xk4_800F6B30++;
        arg0 = temp_v0->unk_28;
        if (arg0 != 0) {
            func_xk4_800D7E68(arg0, &spC4, &sp74, arg3);
        }
        arg0 = temp_v0->unk_24;
    }
}

extern GfxPool* gGfxPool;

UNUSED s32 D_xk4_800F1A78 = 0;
Vec3f D_xk4_800F1A7C = { 1.0f, 1.0f, 1.0f };

void func_xk4_800D80E8(unk_800D7AB4** arg0, unk_800D80E8* arg1, s32 arg2) {
    unk_800D80E8* temp_s0;
    unk_800D7AB4** sp70;
    MtxF sp30;
    Vec3f sp24;

    temp_s0 = func_xk4_SegmentedToVirtual(arg1);
    sp70 = func_xk4_SegmentedToVirtual(arg0);
    sp24 = D_xk4_800F1A7C;
    D_xk4_800F6B30 = 0;
    D_xk4_800F6B34 = func_xk4_SegmentedToVirtual(temp_s0->unk_08);
    D_xk4_800F6B38 = func_xk4_SegmentedToVirtual(temp_s0->unk_10);
    D_xk4_800F6B3C = func_xk4_SegmentedToVirtual(temp_s0->unk_18);
    D_xk4_800F6B40 = func_xk4_SegmentedToVirtual(temp_s0->unk_04);
    D_xk4_800F6B44 = func_xk4_SegmentedToVirtual(temp_s0->unk_0C);
    D_xk4_800F6B48 = func_xk4_SegmentedToVirtual(temp_s0->unk_14);
    D_xk4_800F6B4C = gGfxPool->unk_32308;
    func_xk4_800D7454(&sp30);
    func_xk4_800D7E68(*sp70, &sp30, &sp24, arg2);
}

void func_xk4_800D81F4(Gfx** gfxP) {
    static s32 D_xk4_800F1A88 = 0;

    D_xk4_800F6AE4 = *gfxP;
    D_xk4_800F1A88 = (D_xk4_800F1A88 + 1) % 40;

    func_xk4_800D80E8(D_xk4_800EC9D0, &D_xk4_800DA22C, D_xk4_800F1A88);
    *gfxP = D_xk4_800F6AE4;
}
