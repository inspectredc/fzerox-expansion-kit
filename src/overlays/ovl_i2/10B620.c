#include "global.h"
#include "fzx_course.h"

//! @bug Not sure what is going on here, it is a different type from what is normally used
extern SaveCourseRecords D_800CF950;

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/D_i2_800C1CF0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800A9CE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800A9ED0.s")

typedef struct unk_save {
    u16 checksum;
    s8 unk_02[0x3FBE];
} unk_save;
extern u8 gSaveBuffer[];

bool func_i2_800A9F98(void) {
    s32 i;
    unk_save* var_s0 = gSaveBuffer;
    SaveCourseRecords* courseRecord = &D_800CF950;

    for (i = 0; i < 3; i++, var_s0++) {
        if (var_s0->checksum != func_i2_800A9564(var_s0) * 1) {
            return true;
        }
    }

    if (courseRecord->checksum != Save_CalculateSaveCourseRecordChecksum(courseRecord) * 1) {
        return true;
    }
    return false;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA024.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA1C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA220.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA368.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA520.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA694.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA80C.s")

SaveCourseRecords* func_i2_800AA84C(void) {
    return &D_800CF950;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA858.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA864.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA994.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAA14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAA64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAAC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAB0C.s")
