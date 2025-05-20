#include "global.h"
#include "fzx_course.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B0D10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B0FAC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B10A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B1AF0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B1E74.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B1F68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B20D0.s")

// Get un-normalised tangent vector along course segment (and magnitude)
f32 func_i2_800B2500(CourseSegment* arg0, f32 arg1, Vec3f* arg2) {
    f32 square;
    f32 temp_fv0;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    CourseSegment* temp_v0 = arg0->next;
    CourseSegment* temp_v1 = arg0->prev;
    CourseSegment* temp_a1 = temp_v0->next;

    square = SQ(arg1);
    temp_fv0 = arg0->unk_24;

    sp44 = (4.0f * arg1 - 1.0f - (3.0f * square)) * temp_fv0;
    sp40 = (6.0f - 3.0f * temp_fv0) * square + (2.0f * temp_fv0 - 6.0f) * arg1;
    sp3C = (3.0f * temp_fv0 - 6.0f) * square + (6.0f - 4.0f * temp_fv0) * arg1 + temp_fv0;
    sp38 = ((3.0f * square) - 2.0f * arg1) * temp_fv0;

    arg2->x = sp44 * temp_v1->pos.x + sp40 * arg0->pos.x + sp3C * temp_v0->pos.x + sp38 * temp_a1->pos.x;
    arg2->y = sp44 * temp_v1->pos.y + sp40 * arg0->pos.y + sp3C * temp_v0->pos.y + sp38 * temp_a1->pos.y;
    arg2->z = sp44 * temp_v1->pos.z + sp40 * arg0->pos.z + sp3C * temp_v0->pos.z + sp38 * temp_a1->pos.z;

    return sqrtf(SQ(arg2->x) + SQ(arg2->y) + SQ(arg2->z));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B26B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B2824.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B2C00.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B3360.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B340C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B3640.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B39B4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B3B4C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B3F54.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B42E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B4338.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B4728.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B47A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B4838.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B489C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B4BD0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B4FE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B53D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5468.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5548.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B562C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B57E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B58B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5B9C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5C2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5C80.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5CD8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B7060.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B71B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B74C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B8FF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B904C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B91AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9290.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B934C.s")

void func_800B94D8(void) {
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B94E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9618.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B97AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9830.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9A10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9BEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9C98.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9D2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B9DD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BA1A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BA57C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BA850.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BB1A4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BBB00.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BBC14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BC070.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BC4D8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BC580.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BC968.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BCD5C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BCDFC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BCF0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BD024.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BD3F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BD7EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BDAA4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BDE60.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BE8BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BE9D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800BEA18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/D_i2_800C30D0.s")
