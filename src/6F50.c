#include "global.h"
#include "fzx_racer.h"
#include "fzx_thread.h"
#include "fzx_course.h"
#include "fzx_assets.h"
#include "segment_symbols.h"
#include "leo/leo_internal.h"

OSMesg D_8079E920;
UNUSED s8 D_8079E928[0x10];
s16 D_8079E938[0x800];
s32 D_8079F938;
s32 D_8079F93C;
s32 D_8079F940;
Vtx* D_8079F944;

bool CourseFeature_IsDecorational(s32 courseFeature) {
    if ((courseFeature >= COURSE_FEATURE_GATE_SQUARE) && (courseFeature <= COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT)) {
        return true;
    }
    return false;
}

extern unk_80225800 D_80225800;
extern unk_802D1B60 D_807BCB58;

s32 D_8076C950 = 0;
s32 D_8076C954 = 0;
s32 D_8076C958 = 90;
s32 D_8076C95C = 0;
s32 D_8076C960 = 0;
s32 D_8076C964 = 1;
s32 D_8076C968 = 0;
s32 D_8076C96C = 0;

extern unk_802D3978 D_807BF570[];

typedef struct unk_80128C94 {
    s8 unk_0000[0x53A0];
    Vtx unk_53A0[0x30];
    Vtx unk_56A0[0x30];
    s8 unk_59A0[0xC00];
    Vtx unk_65A0[0x800];
    Vtx unk_E5A0[0x80];
    s8 unk_EDA0[0x400];
    Mtx unk_F1A0[0x1];
} unk_80128C94;

extern unk_80128C94* D_80128C94;

void func_806F9774(void) {
    unk_802D1B60_unk_00* temp_s0;
    s32 i;
    s32 j;
    s32 k;
    f32 spAC;
    Vtx* vtx;
    CourseSegment* courseSegment;
    unk_802D1B60* var = &D_807BCB58;
    f32 temp;
    Vec3f sp90;
    Mtx3F sp6C;
    f32 temp_fs0;

    if (D_8076C954 != 0 && D_8076C950 == 0) {
        vtx = D_80128C94->unk_56A0;
    } else {
        vtx = D_80225800.unk_1C0;
    }

    var->unk_08 = 0;

    for (i = 0; i < var->unk_04; i++) {
        temp_s0 = &var->unk_00[i];
        temp_fs0 = 1.1547f;
        if (temp_s0->featureType != COURSE_FEATURE_LANDMINE) {
            continue;
        }

        courseSegment = &gCurrentCourseInfo->courseSegments[temp_s0->segmentIndex];
        temp = func_i2_800B20D0(courseSegment, temp_s0->unk_08, &spAC);
        func_i2_800B2824(courseSegment, temp_s0->unk_08, &sp6C, temp);
        func_i2_800B26B8(courseSegment, temp_s0->unk_08, &sp90);

        sp90.x += (temp_s0->unk_0C * sp6C.z.x) + (2 * sp6C.y.x);
        sp90.y += (temp_s0->unk_0C * sp6C.z.y) + (2 * sp6C.y.y);
        sp90.z += (temp_s0->unk_0C * sp6C.z.z) + (2 * sp6C.y.z);

        vtx->v.ob[0] = sp90.x + 16.0f * sp6C.y.x;
        vtx->v.ob[1] = sp90.y + 16.0f * sp6C.y.y;
        vtx->v.ob[2] = sp90.z + 16.0f * sp6C.y.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0;
        vtx++;
        vtx->v.ob[0] = sp90.x - (16.0f * temp_fs0) * sp6C.x.x;
        vtx->v.ob[1] = sp90.y - (16.0f * temp_fs0) * sp6C.x.y;
        vtx->v.ob[2] = sp90.z - (16.0f * temp_fs0) * sp6C.x.z;
        vtx->v.tc[0] = 0;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = sp90.x - (16.0f * temp_fs0) * sp6C.z.x;
        vtx->v.ob[1] = sp90.y - (16.0f * temp_fs0) * sp6C.z.y;
        vtx->v.ob[2] = sp90.z - (16.0f * temp_fs0) * sp6C.z.z;
        vtx->v.tc[0] = 0x800;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = sp90.x + (16.0f * temp_fs0) * sp6C.x.x;
        vtx->v.ob[1] = sp90.y + (16.0f * temp_fs0) * sp6C.x.y;
        vtx->v.ob[2] = sp90.z + (16.0f * temp_fs0) * sp6C.x.z;
        vtx->v.tc[0] = 0;
        vtx->v.tc[1] = 0x800;
        vtx++;
        vtx->v.ob[0] = sp90.x + (16.0f * temp_fs0) * sp6C.z.x;
        vtx->v.ob[1] = sp90.y + (16.0f * temp_fs0) * sp6C.z.y;
        vtx->v.ob[2] = sp90.z + (16.0f * temp_fs0) * sp6C.z.z;
        vtx->v.tc[0] = 0x800;
        vtx->v.tc[1] = 0x800;
        vtx++;
        D_807BF570[var->unk_08].unk_04.x = sp90.x;
        D_807BF570[var->unk_08].unk_04.y = sp90.y;
        D_807BF570[var->unk_08].unk_04.z = sp90.z;
        var->unk_08++;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].unk_4C = NULL;
        gCurrentCourseInfo->courseSegments[i].unk_50 = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0, k = 0; k < var->unk_04; k++) {
            temp_s0 = &var->unk_00[k];
            if (temp_s0->featureType != COURSE_FEATURE_LANDMINE) {
                continue;
            }

            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_50 = &D_807BF570[j + 1];
            }
            j++;
        }
    }

    //! @bug j is potentially uninitialised here
    var->unk_08 = j;

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = var->unk_08, k = var->unk_04 - 1; k >= 0; k--) {
            temp_s0 = &var->unk_00[k];
            if (temp_s0->featureType != COURSE_FEATURE_LANDMINE) {
                continue;
            }

            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_4C = &D_807BF570[j - 1];
            }
            j--;
        }
    }
}

extern Gfx D_9002188[];
extern Gfx D_9002388[];
extern Gfx D_9002B88[];
extern Gfx D_9002788[];

Gfx* D_8076C970 = D_9002188;
Gfx* D_8076C974 = D_9002388;
Gfx* D_8076C978 = D_9002B88;
Gfx* D_8076C97C = D_9002788;

Gfx* (*D_8076C980[])(Gfx*) = {
    func_806FC340, func_806FC3AC, func_806FC3E0, func_806FC44C, func_806FC44C, func_806FC47C,
    func_806FC47C, func_806FC4E4, func_806FC4E4, func_806FC54C, func_806FC5F4, func_806FC664,
    func_806FC70C, func_806FC70C, func_806FC804, func_806FC804, func_806FC900, func_806FC900,
    func_806FC9FC, func_806FC9FC, func_806FCAF8, func_806FCAF8,
};

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806F9DB4.s")

extern unk_802D3D38 D_807BF870[];

void func_806FB3AC(void) {
    unk_802D1B60* var = &D_807BCB58;
    s32 i;
    s32 j;
    s32 k;
    f32 spA4;
    Vtx* vtx;
    s32 pad[3];
    Vec3f sp88;
    f32 temp;
    CourseSegment* courseSegment;
    unk_802D1B60_unk_00* temp_s0;
    Mtx3F sp58;

    if ((D_8076C954 != 0) && (D_8076C950 == 0)) {
        vtx = D_80128C94->unk_53A0;
    } else {
        vtx = D_80225800.unk_040;
    }
    var->unk_0C = 0;

    for (i = 0; i < var->unk_04; i++) {
        temp_s0 = &var->unk_00[i];

        if (temp_s0->featureType != COURSE_FEATURE_JUMP) {
            continue;
        }
        courseSegment = &gCurrentCourseInfo->courseSegments[temp_s0->segmentIndex];
        temp = func_i2_800B20D0(courseSegment, temp_s0->unk_08, &spA4);
        func_i2_800B2824(courseSegment, temp_s0->unk_08, &sp58, temp);
        func_i2_800B26B8(courseSegment, temp_s0->unk_08, &sp88);

        sp88.x += temp_s0->unk_0C * sp58.z.x - 0.5 * temp_s0->unk_10.x * sp58.z.x;
        sp88.y += temp_s0->unk_0C * sp58.z.y - 0.5 * temp_s0->unk_10.x * sp58.z.y;
        sp88.z += temp_s0->unk_0C * sp58.z.z - 0.5 * temp_s0->unk_10.x * sp58.z.z;

        D_807BF870[var->unk_0C].unk_00.x = sp88.x;
        D_807BF870[var->unk_0C].unk_00.y = sp88.y;
        D_807BF870[var->unk_0C].unk_00.z = sp88.z;

        vtx->v.ob[0] = ((temp_s0->unk_10.y * sp58.y.x) + sp88.x) + (0.5 * temp_s0->unk_10.z * sp58.x.x);
        vtx->v.ob[1] = ((temp_s0->unk_10.y * sp58.y.y) + sp88.y) + (0.5 * temp_s0->unk_10.z * sp58.x.y);
        vtx->v.ob[2] = ((temp_s0->unk_10.y * sp58.y.z) + sp88.z) + (0.5 * temp_s0->unk_10.z * sp58.x.z);
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x240;
        vtx++;
        vtx->v.ob[0] = sp88.x;
        vtx->v.ob[1] = sp88.y;
        vtx->v.ob[2] = sp88.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x700;
        vtx++;
        vtx->v.ob[0] = ((temp_s0->unk_10.z * sp58.x.x) + sp88.x);
        vtx->v.ob[1] = ((temp_s0->unk_10.z * sp58.x.y) + sp88.y);
        vtx->v.ob[2] = ((temp_s0->unk_10.z * sp58.x.z) + sp88.z);
        vtx->v.tc[0] = 0;
        sp88.x += temp_s0->unk_10.x * sp58.z.x;
        sp88.y += temp_s0->unk_10.x * sp58.z.y;
        sp88.z += temp_s0->unk_10.x * sp58.z.z;

        vtx++;
        vtx->v.ob[0] = ((temp_s0->unk_10.y * sp58.y.x) + sp88.x) + (0.5 * temp_s0->unk_10.z * sp58.x.x);
        vtx->v.ob[1] = ((temp_s0->unk_10.y * sp58.y.y) + sp88.y) + (0.5 * temp_s0->unk_10.z * sp58.x.y);
        vtx->v.ob[2] = ((temp_s0->unk_10.y * sp58.y.z) + sp88.z) + (0.5 * temp_s0->unk_10.z * sp58.x.z);
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x240;
        vtx++;
        vtx->v.ob[0] = sp88.x;
        vtx->v.ob[1] = sp88.y;
        vtx->v.ob[2] = sp88.z;
        vtx->v.tc[0] = 0x400;
        vtx->v.tc[1] = 0x700;
        vtx++;
        vtx->v.ob[0] = (temp_s0->unk_10.z * sp58.x.x) + sp88.x;
        vtx->v.ob[1] = (temp_s0->unk_10.z * sp58.x.y) + sp88.y;
        vtx->v.ob[2] = (temp_s0->unk_10.z * sp58.x.z) + sp88.z;
        vtx->v.tc[0] = 0;
        vtx++;

        D_807BF870[var->unk_0C].unk_0C = sp58;
        D_807BF870[var->unk_0C].unk_30 = temp_s0->unk_10;

        var->unk_0C++;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].unk_44 = NULL;
        gCurrentCourseInfo->courseSegments[i].unk_48 = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0, k = 0; k < var->unk_04; k++) {
            temp_s0 = &var->unk_00[k];
            if (temp_s0->featureType != COURSE_FEATURE_JUMP) {
                continue;
            }

            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_48 = &D_807BF870[j + 1];
            }
            j++;
        }
    }
    //! @bug j is potentially uninitialised here
    var->unk_0C = j;

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = var->unk_0C, k = var->unk_04 - 1; k >= 0; k--) {
            temp_s0 = &var->unk_00[k];
            if (temp_s0->featureType != COURSE_FEATURE_JUMP) {
                continue;
            }

            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_44 = &D_807BF870[j - 1];
            }
            j--;
        }
    }
}

extern s32 D_800D65C8;
extern unk_802D08E0 D_807BB738[];
extern Mtx D_8022F640[];
extern unk_36ED0 D_802BE5C0[];

void func_806FBBC8(void) {
    CourseSegment* courseSegment;
    unk_36ED0* var_s1;
    unk_802D08E0* var_s0;
    s32 i;
    f32 sp14C;
    s32 j;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa0;
    f32 temp_fa1;
    s32 pad[2];
    unk_802D1B60* sp12C;
    f32 var_fs0;
    unk_802D1B60_unk_00* temp_s3;
    f32 temp;
    Mtx* mtx;
    MtxF spDC;
    Vec3f spD0;
    Mtx3F spAC;

    sp12C = &D_807BCB58;
    if ((D_8076C954 != 0) && (D_8076C950 == 0)) {
        mtx = D_80128C94->unk_F1A0;
    } else {
        mtx = D_8022F640;
    }

    var_s0 = D_807BB738;
    for (i = 0; i < sp12C->unk_04; i++) {
        temp_s3 = &sp12C->unk_00[i];
        if (!CourseFeature_IsDecorational(temp_s3->featureType)) {
            continue;
        }
        courseSegment = &gCurrentCourseInfo->courseSegments[temp_s3->segmentIndex];

        temp = func_i2_800B20D0(courseSegment, temp_s3->unk_08, &sp14C);
        func_i2_800B2824(courseSegment, temp_s3->unk_08, &spAC, temp);
        func_i2_800B26B8(courseSegment, temp_s3->unk_08, &spD0);

        if (COURSE_FEATURE_IS_BUILDING(temp_s3->featureType)) {
            if (SQ(spAC.x.y) > 0.95) {
                if (spAC.y.y > 0) {
                    spAC.x.x = -1.0f * spAC.y.x;
                    spAC.x.y = 0;
                    spAC.x.z = -1.0f * spAC.y.z;
                    func_80703320(&spAC.x.x, &spAC.x.z);
                    spAC.y.x = 0.0f;
                    spAC.y.y = 1.0f;
                    spAC.y.z = 0.0f;
                    spAC.z.x = spAC.x.z;
                    spAC.z.y = 0.0f;
                    spAC.z.z = 0.0f - spAC.x.x;
                } else {
                    spAC.x.x = spAC.y.x;
                    spAC.x.y = 0;
                    spAC.x.z = spAC.y.z;
                    func_80703320(&spAC.x.x, &spAC.x.z);
                    spAC.y.x = 0.0f;
                    spAC.y.y = 1.0f;
                    spAC.y.z = 0.0f;
                    spAC.z.x = spAC.x.z;
                    spAC.z.y = 0.0f;
                    spAC.z.z = 0.0f - spAC.x.x;
                }
            } else {
                spAC.x.y = 0.0f;
                func_80703320(&spAC.x.x, &spAC.x.z);
                spAC.y.x = 0.0f;
                spAC.y.y = 1.0f;
                spAC.y.z = 0.0f;
                spAC.z.x = spAC.x.z;
                spAC.z.y = 0.0f;
                spAC.z.z = 0.0f - spAC.x.x;
            }
        }

        spD0.x += temp_s3->unk_0C * spAC.z.x;
        spD0.y += temp_s3->unk_0C * spAC.z.y;
        spD0.z += temp_s3->unk_0C * spAC.z.z;
        var_s0->unk_00.x = spD0.x;
        var_s0->unk_00.y = spD0.y;
        var_s0->unk_00.z = spD0.z;
        var_s0->unk_0C = spAC;

        switch (temp_s3->featureType) {
            case COURSE_FEATURE_GATE_SQUARE:
            case COURSE_FEATURE_GATE_START:
            case COURSE_FEATURE_GATE_HEXAGONAL:
                var_s0->unk_30 = (courseSegment->radiusLeft + courseSegment->radiusRight + 165.0f) / 120.0f;
                break;
            case COURSE_FEATURE_SIGN_OVERHEAD:
                var_s0->unk_30 = (courseSegment->radiusLeft + courseSegment->radiusRight + 165.0f) / 520.0f;
                break;
            default:
                var_s0->unk_30 = 1.0f;
                break;
        }

        switch (temp_s3->featureType) {
            case COURSE_FEATURE_SIGN_TV_LEFT:
            case COURSE_FEATURE_SIGN_2_LEFT:
            case COURSE_FEATURE_SIGN_1_LEFT:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x * -1.0f,
                              var_s0->unk_0C.x.y * -1.0f, var_s0->unk_0C.x.z * -1.0f, var_s0->unk_0C.y.x,
                              var_s0->unk_0C.y.y, var_s0->unk_0C.y.z, var_s0->unk_00.x, var_s0->unk_00.y,
                              var_s0->unk_00.z);
                break;
            case COURSE_FEATURE_SIGN_NINTEX_RIGHT:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x,
                              var_s0->unk_0C.x.y, var_s0->unk_0C.x.z, var_s0->unk_0C.y.x, var_s0->unk_0C.y.y,
                              var_s0->unk_0C.y.z, var_s0->unk_00.x + (var_s0->unk_0C.y.x * 50.0f),
                              var_s0->unk_00.y + (var_s0->unk_0C.y.y * 50.0f),
                              var_s0->unk_00.z + (var_s0->unk_0C.y.z * 50.0f));
                break;
            case COURSE_FEATURE_SIGN_OVERHEAD:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x,
                              var_s0->unk_0C.x.y, var_s0->unk_0C.x.z, var_s0->unk_0C.y.x, var_s0->unk_0C.y.y,
                              var_s0->unk_0C.y.z, var_s0->unk_00.x + (var_s0->unk_0C.y.x * 100.0f * var_s0->unk_30),
                              var_s0->unk_00.y + (var_s0->unk_0C.y.y * 100.0f * var_s0->unk_30),
                              var_s0->unk_00.z + (var_s0->unk_0C.y.z * 100.0f * var_s0->unk_30));
                break;
            case COURSE_FEATURE_SIGN_NINTEX_LEFT:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x * -1.0f,
                              var_s0->unk_0C.x.y * -1.0f, var_s0->unk_0C.x.z * -1.0f, var_s0->unk_0C.y.x,
                              var_s0->unk_0C.y.y, var_s0->unk_0C.y.z, var_s0->unk_00.x + (var_s0->unk_0C.y.x * 50.0f),
                              var_s0->unk_00.y + (var_s0->unk_0C.y.y * 50.0f),
                              var_s0->unk_00.z + (var_s0->unk_0C.y.z * 50.0f));
                break;
            case COURSE_FEATURE_BUILDING_TALL_LEFT:
            case COURSE_FEATURE_BUILDING_TALL_RIGHT:
            case COURSE_FEATURE_BUILDING_SHORT_LEFT:
            case COURSE_FEATURE_BUILDING_SHORT_RIGHT:
            case COURSE_FEATURE_BUILDING_SPIRE_LEFT:
            case COURSE_FEATURE_BUILDING_SPIRE_RIGHT:
            case COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT:
            case COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT:
            case COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT:
            case COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x,
                              var_s0->unk_0C.x.y, var_s0->unk_0C.x.z, 0.0f, 1.0f, 0.0f, var_s0->unk_00.x, -750.0f,
                              var_s0->unk_00.z);
                break;
            default:
                func_806F7FCC(mtx, &spDC, var_s0->unk_30, var_s0->unk_30, var_s0->unk_30, var_s0->unk_0C.x.x,
                              var_s0->unk_0C.x.y, var_s0->unk_0C.x.z, var_s0->unk_0C.y.x, var_s0->unk_0C.y.y,
                              var_s0->unk_0C.y.z, var_s0->unk_00.x, var_s0->unk_00.y, var_s0->unk_00.z);
                break;
        }
        mtx++;

        var_fs0 = 1e8f;
        var_s1 = D_802BE5C0;
        for (j = 0; j < D_800D65C8; j++) {

            temp_fv0 = var_s1->unk_14.x - var_s0->unk_00.x;
            temp_fv1 = var_s1->unk_14.y - var_s0->unk_00.y;
            temp_fa0 = var_s1->unk_14.z - var_s0->unk_00.z;
            temp_fa1 = SQ(temp_fv0) + SQ(temp_fv1) + SQ(temp_fa0);
            if (temp_fa1 < var_fs0) {
                var_s0->unk_34 = var_s1;
                var_fs0 = temp_fa1;
            }
            var_s1++;
        }
        var_s0++;
    }
}

Gfx* func_806FC340(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (D_8079F938 != 5) {
        gSPDisplayList(gfx++, D_8017220);
    }
    D_8079F938 = 5;
    gSPDisplayList(gfx++, D_80172A0);

    return gfx;
}

Gfx* func_806FC3AC(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_8018618);

    return gfx;
}

Gfx* func_806FC3E0(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);
    if (D_8079F938 != 7) {
        gSPDisplayList(gfx++, D_801A1F8);
    }
    D_8079F938 = 7;
    gSPDisplayList(gfx++, D_801A278);

    return gfx;
}

Gfx* func_806FC44C(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    gSPDisplayList(gfx++, D_801AEF8);

    return gfx;
}

Gfx* func_806FC47C(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (D_8079F938 != 9) {
        gSPDisplayList(gfx++, D_801D030);
    }
    D_8079F938 = 9;
    gSPDisplayList(gfx++, D_801D0B0);

    return gfx;
}

Gfx* func_806FC4E4(Gfx* gfx) {

    gSPClearGeometryMode(gfx++, G_CULL_BACK);
    if (D_8079F938 != 10) {
        gSPDisplayList(gfx++, D_801E178);
    }
    D_8079F938 = 10;
    gSPDisplayList(gfx++, D_801E1F8);

    return gfx;
}

extern GfxPool D_1000000;

Gfx* func_806FC54C(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_8079F938 != 11) {
        gSPDisplayList(gfx++, D_3000688);
    }
    D_8079F938 = 11;

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_36628), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

Gfx* func_806FC5F4(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    gSPDisplayList(gfx++, D_30006D0);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_36668), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EAA8);

    return gfx;
}

Gfx* func_806FC664(Gfx* gfx) {

    gSPSetGeometryMode(gfx++, G_CULL_BACK);

    if (D_8079F938 != 12) {
        gSPDisplayList(gfx++, D_3000590);
    }
    D_8079F938 = 12;

    gSPDisplayList(gfx++, D_30005D8);

    gSPMatrix(gfx++, K0_TO_PHYS(D_1000000.unk_366A8), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);

    gSPDisplayList(gfx++, D_801EBF8);

    return gfx;
}

Gfx* func_806FC70C(Gfx* gfx) {

    if (D_8079F938 != 0) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8014A20, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801ED28);
    D_8079F938 = 0;
    return gfx;
}
extern u16 D_801F018[];

Gfx* func_806FC804(Gfx* gfx) {

    if (D_8079F938 != 1) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F018, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801EEA0);
    D_8079F938 = 1;
    return gfx;
}

Gfx* func_806FC900(Gfx* gfx) {

    if (D_8079F938 != 2) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_801F8C8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_801F818);
    D_8079F938 = 2;
    return gfx;
}

Gfx* func_806FC9FC(Gfx* gfx) {

    if (D_8079F938 != 3) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8020208, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_80200C8);
    D_8079F938 = 3;
    return gfx;
}

Gfx* func_806FCAF8(Gfx* gfx) {

    if (D_8079F938 != 4) {
        gDPPipeSync(gfx++);

        gDPLoadTextureBlock(gfx++, D_8021380, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                            G_TX_NOMIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
    }

    gSPDisplayList(gfx++, D_8021208);
    D_8079F938 = 4;
    return gfx;
}

void func_806FCBF4(CourseSegment* arg0, f32 arg1, Vec3f* arg2) {
    s32 pad;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 temp_fv0;
    Mtx3F sp28;

    temp_fv0 = func_i2_800B20D0(arg0, arg1, &sp58);

    sp54 = ((arg0->next->radiusLeft - arg0->radiusLeft) * temp_fv0) + arg0->radiusLeft;
    sp50 = ((arg0->next->radiusRight - arg0->radiusRight) * temp_fv0) + arg0->radiusRight;

    func_i2_800B2824(arg0, arg1, &sp28, temp_fv0);
    func_i2_800B26B8(arg0, arg1, arg2);
    sp58 = (sp54 - sp50) / 2.0f;

    arg2->x += sp58 * sp28.z.x;
    arg2->y += sp58 * sp28.z.y;
    arg2->z += sp58 * sp28.z.z;
}

extern s32 D_800D65C8;

void func_806FCCE4(s32 arg0, s32 arg1, f32 arg2) {
    s32 i = 0;
    s32 temp_v0;
    s32 pad;
    s32 sp0;

    //! @bug sp0 may not be initialised
    if (D_8076C954 == 0 || D_8076C950 != 0) {
        sp0 = D_800D65C8;
    }

    while (true) {
        temp_v0 = (i + sp0 - 1) % sp0;

        if ((D_802BE5C0[temp_v0].unk_04 < arg1 ||
             (arg1 == D_802BE5C0[temp_v0].unk_04 && D_802BE5C0[temp_v0].unk_08 <= arg2)) &&
            (arg1 < D_802BE5C0[i].unk_04 || (arg1 == D_802BE5C0[i].unk_04 && arg2 < D_802BE5C0[i].unk_08))) {
            break;
        }
        i++;
    }
    D_8079E938[arg0] = temp_v0;
}

f32 func_806FCE04(s32 arg0, f32 arg1) {
    s32 i;
    s32 sp0;

    i = 0;
    sp0 = D_800D65C8;

    do {
        if (arg0 == D_802BE5C0[i].unk_04) {
            goto next;
        }
        i++;
    } while (i < sp0);

    if (arg1 <= 0.00001f) {
        return 0.0001f;
    }

    return 1.0f;

next:
    while (true) {

        if (arg0 == D_802BE5C0[i].unk_04 && arg1 < D_802BE5C0[i].unk_08) {
            break;
        }

        i++;

        if (i == D_800D65C8) {
            return 1.0f;
        }

        if (arg0 != D_802BE5C0[i].unk_04) {
            return 1.0f;
        }
    }

    return D_802BE5C0[i].unk_08;
}

f32 D_8076C9D8 = 150.0f;
f32 D_8076C9DC = 50.0f;
f32 D_8076C9E0 = 50.0f;

extern unk_802D3E38 D_807BFA70[];

void func_806FCECC(s32 arg0, unk_8006FF90_arg_1* arg1, Vtx** arg2) {
    Vtx* vtx;
    f32 sp78;
    f32 sp74;
    s32 pad;
    f32 sp6C;
    Vec3f sp60;
    Vec3f sp54;
    Mtx3F sp30;
    CourseSegment* sp2C;

    sp78 = arg1->unk_08;
    sp2C = &gCurrentCourseInfo->courseSegments[arg1->segmentIndex];
    vtx = *arg2;

    sp74 = func_i2_800B2500(sp2C, sp78, &sp54);
    func_i2_800B2824(sp2C, arg1->unk_08, &sp30, func_i2_800B20D0(sp2C, arg1->unk_08, &sp6C));
    func_806FCBF4(sp2C, arg1->unk_08, &sp60);
    sp60.x += 5.0f * sp30.y.x;
    sp60.y += 5.0f * sp30.y.y;
    sp60.z += 5.0f * sp30.y.z;
    vtx->v.ob[0] = Math_Round(((arg1->unk_10 * sp30.z.x) + sp60.x) + (sp30.x.x * D_8076C9E0));
    vtx->v.ob[1] = Math_Round(((arg1->unk_10 * sp30.z.y) + sp60.y) + (sp30.x.y * D_8076C9E0));
    vtx->v.ob[2] = Math_Round(((arg1->unk_10 * sp30.z.z) + sp60.z) + (sp30.x.z * D_8076C9E0));
    vtx->v.tc[0] = 0x200;
    vtx->v.tc[1] = 0x100;
    vtx++;
    vtx->v.ob[0] = Math_Round(((arg1->unk_10 + D_8076C9DC) * sp30.z.x) + sp60.x);
    vtx->v.ob[1] = Math_Round(((arg1->unk_10 + D_8076C9DC) * sp30.z.y) + sp60.y);
    vtx->v.ob[2] = Math_Round(((arg1->unk_10 + D_8076C9DC) * sp30.z.z) + sp60.z);
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0;
    vtx++;
    vtx->v.ob[0] = Math_Round(((arg1->unk_10 - D_8076C9DC) * sp30.z.x) + sp60.x);
    vtx->v.ob[1] = Math_Round(((arg1->unk_10 - D_8076C9DC) * sp30.z.y) + sp60.y);
    vtx->v.ob[2] = Math_Round(((arg1->unk_10 - D_8076C9DC) * sp30.z.z) + sp60.z);
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0;

    sp78 += D_8076C9D8 / sp74;
    D_807BFA70[arg0].unk_08 = sp78;
    D_807BFA70[arg0].unk_0C.x = arg1->unk_10 - D_8076C9DC;
    D_807BFA70[arg0].unk_18.x = arg1->unk_10 + D_8076C9DC;

    sp60.x = sp60.x + sp30.x.x * D_8076C9D8;
    sp60.y = sp60.y + sp30.x.y * D_8076C9D8;
    sp60.z = sp60.z + sp30.x.z * D_8076C9D8;

    vtx++;
    vtx->v.ob[0] = Math_Round((arg1->unk_10 * sp30.z.x) + sp60.x);
    vtx->v.ob[1] = Math_Round((arg1->unk_10 * sp30.z.y) + sp60.y);
    vtx->v.ob[2] = Math_Round((arg1->unk_10 * sp30.z.z) + sp60.z);
    vtx->v.tc[0] = 0x200;
    vtx->v.tc[1] = 0x400;
    vtx++;
    vtx->v.ob[0] = Math_Round((((arg1->unk_10 + D_8076C9DC) * sp30.z.x) + sp60.x) - (sp30.x.x * D_8076C9E0));
    vtx->v.ob[1] = Math_Round((((arg1->unk_10 + D_8076C9DC) * sp30.z.y) + sp60.y) - (sp30.x.y * D_8076C9E0));
    vtx->v.ob[2] = Math_Round((((arg1->unk_10 + D_8076C9DC) * sp30.z.z) + sp60.z) - (sp30.x.z * D_8076C9E0));
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0x300;
    vtx++;
    vtx->v.ob[0] = Math_Round((((arg1->unk_10 - D_8076C9DC) * sp30.z.x) + sp60.x) - (sp30.x.x * D_8076C9E0));
    vtx->v.ob[1] = Math_Round((((arg1->unk_10 - D_8076C9DC) * sp30.z.y) + sp60.y) - (sp30.x.y * D_8076C9E0));
    vtx->v.ob[2] = Math_Round((((arg1->unk_10 - D_8076C9DC) * sp30.z.z) + sp60.z) - (sp30.x.z * D_8076C9E0));
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x300;

    vtx++;
    *arg2 = vtx;
}

void func_806FD3C0(s32 arg0, unk_8006FF90_arg_1* arg1, Vtx** arg2) {
    Vtx* vtx;
    f32 spF0;
    f32 spEC;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    Vec3f spD4;
    Vec3f spC8;
    Vec3f spBC;
    Vec3f spB0;
    Mtx3F sp8C;
    CourseSegment* sp88;
    s32 pad;
    MtxF sp44;

    spF0 = arg1->unk_08;
    sp88 = &gCurrentCourseInfo->courseSegments[arg1->segmentIndex];
    vtx = *arg2;

    spEC = func_i2_800B2500(sp88, spF0, &spBC);
    spE8 = func_i2_800B20D0(sp88, arg1->unk_08, &spE4);

    func_i2_800B2824(sp88, arg1->unk_08, &sp8C, spE8);

    spE0 = sp88->radiusLeft + sp88->radiusRight;
    spE0 = (((sp88->next->radiusLeft + sp88->next->radiusRight) - spE0) * spE8) + spE0;
    spE0 /= 2;

    func_806FCBF4(sp88, arg1->unk_08, &spC8);
    func_806F8868(NULL, &sp44, 1.0f, DEG_TO_FZXANG(arg1->unk_10), sp8C.x.x, sp8C.x.y, sp8C.x.z, 0.0f, 0.0f, 0.0f);
    spBC.x = sp44.m[0][0] * sp8C.z.x + sp44.m[1][0] * sp8C.z.y + sp44.m[2][0] * sp8C.z.z;
    spBC.y = sp44.m[0][1] * sp8C.z.x + sp44.m[1][1] * sp8C.z.y + sp44.m[2][1] * sp8C.z.z;
    spBC.z = sp44.m[0][2] * sp8C.z.x + sp44.m[1][2] * sp8C.z.y + sp44.m[2][2] * sp8C.z.z;
    func_80703444(&spBC, 1.0f);
    sp8C.z.x = spBC.x;
    sp8C.z.y = spBC.y;
    sp8C.z.z = spBC.z;
    spBC.x = sp44.m[0][0] * sp8C.y.x + sp44.m[1][0] * sp8C.y.y + sp44.m[2][0] * sp8C.y.z;
    spBC.y = sp44.m[0][1] * sp8C.y.x + sp44.m[1][1] * sp8C.y.y + sp44.m[2][1] * sp8C.y.z;
    spBC.z = sp44.m[0][2] * sp8C.y.x + sp44.m[1][2] * sp8C.y.y + sp44.m[2][2] * sp8C.y.z;
    func_80703444(&spBC, 1.0f);
    sp8C.y.x = spBC.x;
    sp8C.y.y = spBC.y;
    sp8C.y.z = spBC.z;
    spD4 = spC8;
    spC8.x += (5.0f - spE0) * spBC.x;
    spC8.y += (5.0f - spE0) * spBC.y;
    spC8.z += (5.0f - spE0) * spBC.z;

    vtx->v.ob[0] = Math_Round((sp8C.x.x * 50.0f) + spC8.x);
    vtx->v.ob[1] = Math_Round((sp8C.x.y * 50.0f) + spC8.y);
    vtx->v.ob[2] = Math_Round((sp8C.x.z * 50.0f) + spC8.z);
    vtx->v.tc[0] = 0x200;
    vtx->v.tc[1] = 0x100;
    vtx++;
    vtx->v.ob[0] = Math_Round((sp8C.z.x * 50.0f) + spC8.x);
    vtx->v.ob[1] = Math_Round((sp8C.z.y * 50.0f) + spC8.y);
    vtx->v.ob[2] = Math_Round((sp8C.z.z * 50.0f) + spC8.z);
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0;
    spB0.x = vtx->v.ob[0] - spD4.x;
    spB0.y = vtx->v.ob[1] - spD4.y;
    spB0.z = vtx->v.ob[2] - spD4.z;
    func_80703444(&spB0, 1.0f);

    D_807BFA70[arg0].unk_0C = spB0;
    vtx++;

    vtx->v.ob[0] = Math_Round(spC8.x - (sp8C.z.x * 50.0f));
    vtx->v.ob[1] = Math_Round(spC8.y - (sp8C.z.y * 50.0f));
    vtx->v.ob[2] = Math_Round(spC8.z - (sp8C.z.z * 50.0f));
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0;
    spB0.x = vtx->v.ob[0] - spD4.x;
    spB0.y = vtx->v.ob[1] - spD4.y;
    spB0.z = vtx->v.ob[2] - spD4.z;
    func_80703444(&spB0, 1.0f);
    D_807BFA70[arg0].unk_18 = spB0;
    D_807BFA70[arg0].unk_04 = spF0;
    spF0 += (150.0f / spEC);
    D_807BFA70[arg0].unk_08 = spF0;
    spC8.x = spC8.x + sp8C.x.x * 150.0f;
    spC8.y = spC8.y + sp8C.x.y * 150.0f;
    spC8.z = spC8.z + sp8C.x.z * 150.0f;

    vtx++;
    vtx->v.ob[0] = Math_Round(spC8.x);
    vtx->v.ob[1] = Math_Round(spC8.y);
    vtx->v.ob[2] = Math_Round(spC8.z);
    vtx->v.tc[0] = 0x200;
    vtx->v.tc[1] = 0x400;
    vtx++;
    vtx->v.ob[0] = Math_Round(((sp8C.z.x * 50.0f) + spC8.x) - (sp8C.x.x * 50.0f));
    vtx->v.ob[1] = Math_Round(((sp8C.z.y * 50.0f) + spC8.y) - (sp8C.x.y * 50.0f));
    vtx->v.ob[2] = Math_Round(((sp8C.z.z * 50.0f) + spC8.z) - (sp8C.x.z * 50.0f));
    vtx->v.tc[0] = 0;
    vtx->v.tc[1] = 0x300;
    vtx++;
    vtx->v.ob[0] = Math_Round((spC8.x - (sp8C.z.x * 50.0f)) - (sp8C.x.x * 50.0f));
    vtx->v.ob[1] = Math_Round((spC8.y - (sp8C.z.y * 50.0f)) - (sp8C.x.y * 50.0f));
    vtx->v.ob[2] = Math_Round((spC8.z - (sp8C.z.z * 50.0f)) - (sp8C.x.z * 50.0f));
    vtx->v.tc[0] = 0x400;
    vtx->v.tc[1] = 0x300;
    vtx++;
    *arg2 = vtx;
}

s32 D_8076C9E4 = 0;

extern u8 D_xk2_80104CA7;

Vtx* func_806FDA64(CourseSegment* arg0, f32 arg1, unk_8006FF90_arg_1* arg2, Vtx* arg3, f32 arg4, f32 arg5) {
    bool sp114 = false;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 var_fs2;
    f32 var_fs3;
    s32 var_s2;
    CourseSegment* temp_v0;
    f32 spF4;
    Vec3f spE8;
    Vec3f spDC;
    Vec3f spD0 = { 0.0f, 0.0f, 0.0f };
    Vec3f spC4 = { 0.0f, 0.0f, 0.0f };
    Vec3f spB8 = { 0.0f, 0.0f, 0.0f };
    Vec3f spAC = { 0.0f, 0.0f, 0.0f };
    Mtx3F sp88;

    var_s2 = 0;

    while (true) {
        if ((D_8076C954 == 0) || (D_8076C950 != 0)) {
            func_806FCCE4((s32) (arg3 - D_8079F944) / 2, arg0->segmentIndex, arg1);
        }
        func_i2_800B2500(arg0, arg1, &spDC);
        func_806FCBF4(arg0, arg1, &spE8);
        temp_fv0 = func_i2_800B20D0(arg0, arg1, &spF4);
        func_i2_800B2824(arg0, arg1, &sp88, temp_fv0);
        spE8.x += sp88.y.x * 10.0f;
        spE8.y += sp88.y.y * 10.0f;
        spE8.z += sp88.y.z * 10.0f;

        temp_fv1 = arg0->radiusLeft + arg0->radiusRight;
        temp_fv1 = (((arg0->next->radiusLeft + arg0->next->radiusRight) - temp_fv1) * temp_fv0) + temp_fv1;
        temp_fv1 /= 2.0f;

        if (arg2->unk_10 < -1.0f * temp_fv1) {
            var_fs2 = -1.0f * temp_fv1;
        } else {
            var_fs2 = arg2->unk_10;
        }

        if (temp_fv1 < arg2->unk_14) {
            var_fs3 = temp_fv1;
        } else {
            var_fs3 = arg2->unk_14;
        }
        spC4.x = Math_Round((sp88.z.x * var_fs2) + spE8.x);
        spC4.y = Math_Round((sp88.z.y * var_fs2) + spE8.y);
        spC4.z = Math_Round((sp88.z.z * var_fs2) + spE8.z);
        spAC.x = Math_Round((sp88.z.x * var_fs3) + spE8.x);
        spAC.y = Math_Round((sp88.z.y * var_fs3) + spE8.y);
        spAC.z = Math_Round((sp88.z.z * var_fs3) + spE8.z);
        if (!sp114) {
            spD0 = spC4;
            spB8 = spAC;
            sp114 = true;
        }
        arg4 += 4.5f * func_807032B0(spC4, spD0);
        arg5 += 4.5f * func_807032B0(spAC, spB8);
        if ((arg4 > 32768.0f) || (arg5 > 32768.0f)) {
            arg4 = (func_807032B0(spC4, spD0) * 4.5f) + -32768.0f;
            arg5 = (func_807032B0(spAC, spB8) * 4.5f) + -32768.0f;
        }
        arg3->v.ob[0] = spC4.x;
        arg3->v.ob[1] = spC4.y;
        arg3->v.ob[2] = spC4.z;
        spD0 = spC4;
        arg3->v.tc[0] = 0;
        arg3->v.tc[1] = arg4;
        arg3++;
        D_8076C9E4++;
        var_s2++;

        arg3->v.ob[0] = spAC.x;
        arg3->v.ob[1] = spAC.y;
        arg3->v.ob[2] = spAC.z;
        spB8 = spAC;
        arg3->v.tc[0] = func_807032B0(spC4, spAC) * 3.0f;
        arg3->v.tc[1] = arg5;
        arg3++;
        D_8076C9E4++;
        var_s2++;

        if (D_8076C9E4 >= D_8079F940) {
            D_xk2_80104CA7 = 1;
            return arg3;
        }

        if (arg1 == arg2->unk_0C) {
            break;
        }

        if (var_s2 == 0x20) {
            var_s2 = 0;
            while (true) {
                arg4 -= 1024.0f;
                arg5 -= 1024.0f;
                if (arg4 < -31744.0f || arg5 < -31744.0f) {
                    break;
                }
            }

        } else {
            arg1 = func_806FCE04(arg0->segmentIndex, arg1);

            if (arg2->unk_0C <= arg1) {
                if (1) {}
                arg1 = arg2->unk_0C;
            }
        }
    }
    return arg3;
}

extern s32 D_80128690[][3];
typedef struct unk_8011C220 {
    s8 unk_00[0x4];
    f32 unk_04;
    Vec3f unk_08;
    Mtx3F unk_14;
} unk_8011C220;

extern unk_8011C220 D_8011C220[];

Vtx* func_806FE174(CourseSegment* arg0, unk_8006FF90_arg_1* arg1, Vtx* arg2, f32 arg3, f32 arg4) {
    s32 i;
    bool sp120 = false;
    f32 temp_fv0;
    f32 sp118;
    s32 pad;
    f32 sp110;
    f32 sp10C;
    s32 var_s2;
    Vec3f spFC;
    f32 spF8;
    f32 spF4;
    f32 temp_fv1;
    Vec3f spE4;
    Vec3f spD8 = { 0.0f, 0.0f, 0.0f };
    Vec3f spCC = { 0.0f, 0.0f, 0.0f };
    Vec3f spC0 = { 0.0f, 0.0f, 0.0f };
    Vec3f spB4 = { 0.0f, 0.0f, 0.0f };
    Mtx3F sp90;

    var_s2 = 0;

    i = D_80128690[arg0->segmentIndex][0];

    if (i >= 0x10000) {
        return arg2;
    }

    sp118 = D_8011C220[i].unk_04;

    while (true) {
        temp_fv0 = func_i2_800B20D0(arg0, sp118, &spFC);
        spE4.x = D_8011C220[i].unk_08.x;
        spE4.y = D_8011C220[i].unk_08.y;
        spE4.z = D_8011C220[i].unk_08.z;
        sp90 = D_8011C220[i].unk_14;

        spE4.x += sp90.y.x * 10.0f;
        spE4.y += sp90.y.y * 10.0f;
        spE4.z += sp90.y.z * 10.0f;

        spF8 = arg0->radiusLeft + ((arg0->next->radiusLeft - arg0->radiusLeft) * temp_fv0);
        spF4 = arg0->radiusRight + ((arg0->next->radiusRight - arg0->radiusRight) * temp_fv0);

        temp_fv1 = spF8 + spF4;
        temp_fv1 /= 2.0f;

        if (arg1->unk_10 < -1.0f * temp_fv1) {
            sp110 = -1.0f * temp_fv1;
        } else {
            sp110 = arg1->unk_10;
        }

        if (temp_fv1 < arg1->unk_14) {
            sp10C = temp_fv1;
        } else {
            sp10C = arg1->unk_14;
        }

        spE4.x += sp90.z.x * (spF8 - temp_fv1);
        spE4.y += sp90.z.y * (spF8 - temp_fv1);
        spE4.z += sp90.z.z * (spF8 - temp_fv1);

        spCC.x = Math_Round((sp90.z.x * sp110) + spE4.x);
        spCC.y = Math_Round((sp90.z.y * sp110) + spE4.y);
        spCC.z = Math_Round((sp90.z.z * sp110) + spE4.z);
        spB4.x = Math_Round((sp90.z.x * sp10C) + spE4.x);
        spB4.y = Math_Round((sp90.z.y * sp10C) + spE4.y);
        spB4.z = Math_Round((sp90.z.z * sp10C) + spE4.z);
        if (!sp120) {
            spD8 = spCC;
            spC0 = spB4;
            sp120 = true;
        }
        arg3 += 4.5f * func_807032B0(spCC, spD8);
        arg4 += 4.5f * func_807032B0(spB4, spC0);
        if ((arg3 > 32768.0f) || (arg4 > 32768.0f)) {
            arg3 = (func_807032B0(spCC, spD8) * 4.5f) + -32768.0f;
            arg4 = (func_807032B0(spB4, spC0) * 4.5f) + -32768.0f;
        }
        arg2->v.ob[0] = spCC.x;
        arg2->v.ob[1] = spCC.y;
        arg2->v.ob[2] = spCC.z;
        spD8 = spCC;
        arg2->v.tc[0] = 0;
        arg2->v.tc[1] = arg3 * 1;
        arg2++;
        D_8076C9E4++;
        var_s2++;

        arg2->v.ob[0] = spB4.x;
        arg2->v.ob[1] = spB4.y;
        arg2->v.ob[2] = spB4.z;
        spC0 = spB4;
        arg2->v.tc[0] = func_807032B0(spCC, spB4) * 3.0f * 1;
        arg2->v.tc[1] = arg4 * 1;
        arg2++;
        D_8076C9E4++;
        var_s2++;

        if (D_8076C9E4 >= D_8079F940) {
            D_xk2_80104CA7 = 1;
            return arg2;
        }

        if (sp118 == arg1->unk_0C) {
            break;
        }

        if (var_s2 == 0x20) {
            var_s2 = 0;
            while (true) {
                arg3 -= 1024.0f;
                arg4 -= 1024.0f;
                if (arg3 < -31744.0f || arg4 < -31744.0f) {
                    break;
                }
            }
        } else {
            if (D_8011C220[i + 1].unk_04 < sp118) {
                sp118 = 1.0f;
            } else {
                sp118 = D_8011C220[i + 1].unk_04;
            }
            i++;
        }
    }
    return arg2;
}

extern s32 D_8079A35C;

extern Vtx D_80226A40[];
extern Vtx D_8022EA40[];
extern unk_802D2D70 D_807BDD68;
extern unk_802D2D78 D_807BDD70[][0xC0];

void func_806FE8F8(s32 arg0) {
    s32 i;
    s32 j;
    CourseSegment* courseSegment;
    unk_8006FF90_arg_1* temp_s0;
    s32 pad[2];
    unk_802D2D70* temp;
    f32 temp_fa0;
    f32 temp_fv0;
    Vtx* spA8;
    Vtx* spA4;
    unk_802D2D70* var_s2;
    s32 temp_v0;
    f32 var_fv0;
    f32 var_fv1;
    unk_802D2D78* var_a2;

    D_8076C9E4 = 0;
    if ((D_8076C954 != 0) && (D_8076C950 == 0)) {
        D_8079F93C = D_8079A35C;
        D_8079F940 = 0x400;
        D_8079F944 = D_80128C94->unk_65A0;
        spA8 = D_80128C94->unk_65A0;
        spA4 = D_80128C94->unk_E5A0;
        var_s2 = &D_807BDD68;
    } else {
        D_8079F93C = 0;
        D_8079F940 = 0x800;
        D_8079F944 = D_80226A40;
        spA8 = D_80226A40;
        spA4 = D_8022EA40;
        var_s2 = &D_807BDD68;
    }

    for (i = 0; i < var_s2->count; i++) {

        temp_s0 = &var_s2->unk_00[i];
        courseSegment = &gCurrentCourseInfo->courseSegments[temp_s0->segmentIndex];

        D_807BDD70[D_8079F93C][i].effectType = temp_s0->effectType;
        D_807BDD70[D_8079F93C][i].vtxStart = spA8;
        D_807BFA70[i].effectType = temp_s0->effectType;
        D_807BFA70[i].unk_04 = temp_s0->unk_08;
        D_807BFA70[i].unk_08 = temp_s0->unk_0C;
        D_807BFA70[i].unk_0C.x = temp_s0->unk_10;
        D_807BFA70[i].unk_18.x = temp_s0->unk_14;
        temp_fa0 = temp_s0->unk_08;

        if (temp_s0->effectType == COURSE_EFFECT_DASH) {
            var_fv1 = (courseSegment->radiusLeft + courseSegment->radiusRight) / 520.0f;
            if (var_fv1 < 1.0f) {
                var_fv1 = 1.0f;
            } else {
            }
            D_8076C9D8 = 150.0f * var_fv1;
            D_8076C9DC = 50.0f * var_fv1;
            D_8076C9E0 = 50.0f * var_fv1;

            switch (courseSegment->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_ROAD:
                case TRACK_SHAPE_WALLED_ROAD:
                case TRACK_SHAPE_TUNNEL:
                case TRACK_SHAPE_BORDERLESS_ROAD:
                    func_806FCECC(i, temp_s0, &spA4);
                    break;
                default:
                    func_806FD3C0(i, temp_s0, &spA4);
                    break;
            }
        } else {
            var_fv0 = -32768.0f;
            var_fv1 = -32768.0f;

            for (j = 0; j < i; j++) {
                if ((temp_s0->segmentIndex == (var_s2->unk_00[j].segmentIndex + 1)) &&
                    (temp_s0->effectType == var_s2->unk_00[j].effectType) && (var_s2->unk_00[j].unk_0C == 1.0f) &&
                    (temp_s0->unk_10 == var_s2->unk_00[j].unk_10) && (temp_s0->unk_14 == var_s2->unk_00[j].unk_14)) {
                    // float calculation just needs to be 1.0f
                    var_fv0 = (D_807BDD70[D_8079F93C][j].vtxEnd - 2)->v.tc[1] / (2.0f - 1.0f);
                    var_fv1 = (D_807BDD70[D_8079F93C][j].vtxEnd - 1)->v.tc[1] / (2.0f - 1.0f);
                    while (true) {
                        var_fv0 -= 1024.0f;
                        var_fv1 -= 1024.0f;
                        if (var_fv0 < -31744.0f || var_fv1 < -31744.0f) {
                            break;
                        }
                    }
                }
            }
            if (arg0 == 0) {
                spA8 = func_806FDA64(courseSegment, temp_fa0, temp_s0, spA8, var_fv0, var_fv1);
            } else {
                spA8 = func_806FE174(courseSegment, temp_s0, spA8, var_fv0, var_fv1);
            }
            if (D_8076C9E4 >= D_8079F940) {
                var_s2->count = i - 1;
            }
        }

        D_807BDD70[D_8079F93C][i].vtxEnd = spA8;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        gCurrentCourseInfo->courseSegments[i].unk_54 = NULL;
        gCurrentCourseInfo->courseSegments[i].unk_58 = NULL;
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = 0; j < var_s2->count; j++) {
            temp_s0 = &var_s2->unk_00[j];
            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_58 = &D_807BFA70[j + 1];
            }
        }
    }

    for (i = 0; i < gCurrentCourseInfo->segmentCount; i++) {
        for (j = var_s2->count - 1; j >= 0; j--) {
            temp_s0 = &var_s2->unk_00[j];
            if (i == temp_s0->segmentIndex) {
                gCurrentCourseInfo->courseSegments[i].unk_54 = &D_807BFA70[j];
            }
        }
    }

    for (i = 0; i < (temp = var_s2)->count; i++) {}
}

extern unk_8006FF90_arg_1 D_807BCB68[];

void func_806FEEEC(s32 courseIndex, s32 segmentIndex) {
    s32 index = D_807BDD68.count;
    unk_8006FF90_arg_1* var_v1 = &D_807BDD68.unk_00[index];
    CourseSegment* courseSegment;
    f32 var_fv0 = 100.0f;
    f32 var_fa0;
    f32 temp_fv1;
    f32 temp_ft4;
    f32 temp_fs1;
    f32 temp_fs3;
    f32 temp;
    s32 pad[6];

    courseSegment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];
    temp_fv1 = courseSegment->radiusLeft + courseSegment->radiusRight;
    temp_ft4 = courseSegment->next->radiusLeft + courseSegment->next->radiusRight;

    temp_fs3 = (courseSegment->radiusLeft - courseSegment->radiusRight) / 2;
    temp_fs1 = (courseSegment->next->radiusLeft - courseSegment->next->radiusRight) / 2;
    temp_fs1 -= temp_fs3;

    if (courseIndex >= COURSE_EDIT_1 || D_8076C950 != 0) {
        if (temp_fv1 < temp_ft4) {
            var_fa0 = temp_fv1;
        } else {
            var_fa0 = temp_ft4;
        }
        temp = var_fa0 / 2.0f;
        if (temp < 101.0f) {
            var_fv0 = temp - 10.0f;
        }
    }

    // clang-format off
    switch (gCourseCtx.courseData.pit[segmentIndex]) {
        case PIT_LEFT:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_PIT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            index++;
            break;
        case PIT_RIGHT:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_PIT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case PIT_BOTH:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_PIT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            var_v1++;
            index++;
            var_v1->effectType = COURSE_EFFECT_PIT;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case 3:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_PIT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -1.0f * var_fv0;
            var_v1->unk_14 = var_fv0;
            index++;
            break;
    }
    // clang-format on
    D_807BDD68.unk_00 = D_807BCB68;
    D_807BDD68.count = index;
}

void func_806FF12C(s32 courseIndex, s32 segmentIndex) {
    s32 index;
    unk_8006FF90_arg_1* var_v1;
    CourseSegment* courseSegment;
    f32 temp_fv1;
    f32 temp_ft4;
    f32 var_fv0 = 100.0f;
    f32 var_fa0;
    f32 temp;
    f32 temp_fs1;
    f32 temp_fs3;
    s32 pad[6];

    if (courseIndex == COURSE_RED_CANYON_2) {
        return;
    }

    index = D_807BDD68.count;
    var_v1 = &D_807BDD68.unk_00[index];

    courseSegment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];

    temp_fv1 = courseSegment->radiusLeft + courseSegment->radiusRight;
    temp_ft4 = courseSegment->next->radiusLeft + courseSegment->next->radiusRight;

    temp_fs3 = (courseSegment->radiusLeft - courseSegment->radiusRight) / 2;
    temp_fs1 = (courseSegment->next->radiusLeft - courseSegment->next->radiusRight) / 2;
    temp_fs1 -= temp_fs3;

    if (temp_fv1 < temp_ft4) {
        var_fa0 = temp_fv1;
    } else {
        var_fa0 = temp_ft4;
    }
    temp = var_fa0 / 2.0f;
    if (temp < 101.0f) {
        var_fv0 = temp - 10.0f;
    }

    // clang-format off
    switch (gCourseCtx.courseData.dirt[segmentIndex]) {
        case DIRT_LEFT:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_DIRT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            index++;
            break;
        case DIRT_RIGHT:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_DIRT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case DIRT_BOTH:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_DIRT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            var_v1++;
            index++;
            var_v1->effectType = COURSE_EFFECT_DIRT;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case DIRT_MIDDLE:
            var_v1->segmentIndex = segmentIndex;
            var_v1->effectType = COURSE_EFFECT_DIRT;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -1.0f * var_fv0;
            var_v1->unk_14 = var_fv0;
            index++;
            break;
    }
    // clang-format on

    D_807BDD68.unk_00 = D_807BCB68;
    D_807BDD68.count = index;
}

void func_806FF364(s32 courseIndex, s32 segmentIndex) {
    s32 index;
    unk_8006FF90_arg_1* var_v1;
    CourseSegment* courseSegment;
    f32 temp_fv1;
    f32 temp_ft4;
    f32 var_fv0 = 100.0f;
    f32 var_fa0;
    f32 temp;
    f32 temp_fs1;
    f32 temp_fs3;
    s32 pad[6];

    index = D_807BDD68.count;
    var_v1 = &D_807BDD68.unk_00[index];

    courseSegment = &gCourseInfos[courseIndex].courseSegments[segmentIndex];

    temp_fv1 = courseSegment->radiusLeft + courseSegment->radiusRight;
    temp_ft4 = courseSegment->next->radiusLeft + courseSegment->next->radiusRight;

    temp_fs3 = (courseSegment->radiusLeft - courseSegment->radiusRight) / 2;
    temp_fs1 = (courseSegment->next->radiusLeft - courseSegment->next->radiusRight) / 2;
    temp_fs1 -= temp_fs3;

    if (temp_fv1 < temp_ft4) {
        var_fa0 = temp_fv1;
    } else {
        var_fa0 = temp_ft4;
    }
    temp = var_fa0 / 2.0f;
    if (temp < 101.0f) {
        var_fv0 = temp - 10.0f;
    }

    // clang-format off
    switch (gCourseCtx.courseData.ice[segmentIndex]) {
        case ICE_LEFT:
            var_v1->effectType = COURSE_EFFECT_ICE;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            index++;
            break;
        case ICE_RIGHT:
            var_v1->effectType = COURSE_EFFECT_ICE;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case ICE_BOTH:
            var_v1->effectType = COURSE_EFFECT_ICE;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = var_fv0; \
            var_v1->unk_14 = 5000.0f;
            var_v1++;
            index++;
            var_v1->effectType = COURSE_EFFECT_ICE;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -5000.0f;
            var_v1->unk_14 = -1.0f * var_fv0;
            index++;
            break;
        case ICE_MIDDLE:
            var_v1->effectType = COURSE_EFFECT_ICE;
            var_v1->segmentIndex = segmentIndex;
            var_v1->unk_08 = 0.0f;
            var_v1->unk_0C = 1.0f;
            var_v1->unk_10 = -1.0f * var_fv0; \
            var_v1->unk_14 = var_fv0;
            index++;
            break;
    }
    // clang-format on

    D_807BDD68.unk_00 = D_807BCB68;
    D_807BDD68.count = index;
}

f32 func_806FF598(CourseSegment* arg0, f32 arg1, f32 arg2) {
    s32 i;
    s32 temp_v0;
    f32 temp;
    Vec3f sp38;

    temp_v0 = Math_Round(arg2 / 5.0f);

    for (i = 0; i < temp_v0; i++) {
        temp = func_i2_800B2500(arg0, arg1, &sp38);
        arg1 += 5.0f / temp;
    }
    return arg1;
}

void func_806FF630(s32 courseIndex) {
    unk_802D1B60_unk_00* var_s0;
    s32 i;
    s32 spBC;
    CourseSegment* courseSegment;
    f32 var_fs0;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_ft4;
    f32 temp_fs5;
    s32 var_s1;
    s32 var_s2;
    f32 temp;
    Vec3f sp88;

    var_s1 = D_807BCB58.unk_04;
    var_s2 = D_807BCB58.unk_08;
    spBC = D_807BCB58.unk_0C;
    var_s0 = &D_807BCB58.unk_00[var_s1];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        courseSegment = &gCourseInfos[courseIndex].courseSegments[i];
        temp_fs2 = courseSegment->length;

        temp_fs3 = courseSegment->radiusLeft + courseSegment->radiusRight;
        temp_ft4 = (courseSegment->next->radiusLeft + courseSegment->next->radiusRight);
        temp_fs4 = (courseSegment->radiusLeft - courseSegment->radiusRight) / 2;
        temp_fs5 = (courseSegment->next->radiusLeft - courseSegment->next->radiusRight) / 2;
        temp_ft4 -= temp_fs3;
        temp_fs5 -= temp_fs4;

        var_fs0 = 0.0f;

        switch (gCourseCtx.courseData.landmine[i]) {
            case LANDMINE_MIDDLE:
                if (temp_fs3) {}
                temp_fs2 /= 5.0f;
                temp = func_i2_800B2500(courseSegment, 0.0f, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - ((temp_fs3 + (temp_ft4 * var_fs0)) / 4);
                var_s0++;
                var_s1++;
                var_s2++;

                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) + ((temp_fs3 + (temp_ft4 * var_fs0)) / 4);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                var_s0->segmentIndex = i;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4;
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - ((temp_fs3 + (temp_ft4 * var_fs0)) / 4);
                var_s0++;
                var_s1++;
                var_s2++;

                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) + ((temp_fs3 + (temp_ft4 * var_fs0)) / 4);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4;
                var_s0++;
                var_s1++;
                var_s2++;
                if (var_fs0 > 1.0f) {
                    var_s0 -= 6;
                    var_s1 -= 6;
                    var_s2 -= 6;

                    func_806FF598(courseSegment, 0, temp_fs2);
                    var_s0->unk_08 = 0.2f;
                    var_s0->unk_0C = ((temp_fs5 * 0.2f) + temp_fs4) - ((temp_fs3 + (temp_ft4 * 0.2f)) / 4);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                    var_s0->unk_08 = 0.2f;
                    var_s0->unk_0C = ((temp_fs5 * 0.2f) + temp_fs4) + ((temp_fs3 + (temp_ft4 * 0.2f)) / 4);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                    func_806FF598(courseSegment, 0.2f, temp_fs2);
                    var_s0->unk_08 = 0.4f;
                    var_s0->unk_0C = (temp_fs5 * 0.4f) + temp_fs4;
                    var_s0++;
                    var_s1++;
                    var_s2++;
                    func_806FF598(courseSegment, 0.4f, temp_fs2);
                    var_s0->unk_08 = 0.6f;
                    var_s0->unk_0C = ((temp_fs5 * 0.6f) + temp_fs4) - ((temp_fs3 + (temp_ft4 * 0.6f)) / 4);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                    var_s0->unk_08 = 0.6f;
                    var_s0->unk_0C = ((temp_fs5 * 0.6f) + temp_fs4) + ((temp_fs3 + (temp_ft4 * 0.6f)) / 4);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                    func_806FF598(courseSegment, 0.6f, temp_fs2);
                    var_s0->unk_08 = 0.8f;
                    var_s0->unk_0C = (temp_fs5 * 0.8f) + temp_fs4;
                    var_s0++;
                    var_s1++;
                    var_s2++;
                }
                break;
            case LANDMINE_LEFT:
                temp_fs2 /= 6.0f;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                var_s0->segmentIndex = i;
                var_s0->unk_08 = 0.0f;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_0C = var_fs0 + temp_fs4 + ((temp_fs3 + var_fs0) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, 0.0f, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4 + (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4 + ((temp_fs3 + (temp_ft4 * var_fs0)) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4 + (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4 + ((temp_fs3 + (temp_ft4 * var_fs0)) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = (temp_fs5 * var_fs0) + temp_fs4 + (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;
                if (var_fs0 > 1.0f) {
                    var_s0 -= 6;
                    var_s1 -= 6;
                    var_s2 -= 6;

                    var_s0->unk_08 = 0;
                    var_s0->unk_0C = ((temp_fs5 * 0) + temp_fs4) + ((temp_fs3 + (temp_ft4 * 0)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.166667f;
                    var_s0->unk_0C =
                        ((temp_fs5 * 0.166667f) + temp_fs4) + (((temp_fs3 + (temp_ft4 * 0.166667f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.333333f;
                    var_s0->unk_0C = ((temp_fs5 * 0.333333f) + temp_fs4) + ((temp_fs3 + (temp_ft4 * 0.333333f)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.5f;
                    var_s0->unk_0C = ((temp_fs5 * 0.5f) + temp_fs4) + (((temp_fs3 + (temp_ft4 * 0.5f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.666667f;
                    var_s0->unk_0C = ((temp_fs5 * 0.666667f) + temp_fs4) + ((temp_fs3 + (temp_ft4 * 0.666667f)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.833333f;
                    var_s0->unk_0C =
                        ((temp_fs5 * 0.833333f) + temp_fs4) + (((temp_fs3 + (temp_ft4 * 0.833333f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                }
                break;
            case LANDMINE_RIGHT:
                temp_fs2 /= 6.0f;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                var_s0->segmentIndex = i;
                var_s0->unk_08 = 0.0f;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_0C = (var_fs0 + temp_fs4) - ((temp_fs3 + var_fs0) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, 0.0f, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - ((temp_fs3 + (temp_ft4 * var_fs0)) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - ((temp_fs3 + (temp_ft4 * var_fs0)) / 8);
                var_s0++;
                var_s1++;
                var_s2++;

                temp = func_i2_800B2500(courseSegment, var_fs0, &sp88);
                var_fs0 += temp_fs2 / temp;
                var_s0->segmentIndex = i;
                var_s0->featureType = COURSE_FEATURE_LANDMINE;
                // clang-format off
                var_s0->unk_10.x = 0.0f; \
                var_s0->unk_10.y = 0.0f; \
                var_s0->unk_10.z = 0.0f;
                // clang-format on
                var_s0->unk_08 = var_fs0;
                var_s0->unk_0C = ((temp_fs5 * var_fs0) + temp_fs4) - (((temp_fs3 + (temp_ft4 * var_fs0)) * 3.0f) / 8);
                var_s0++;
                var_s1++;
                var_s2++;
                if (var_fs0 > 1.0f) {
                    var_s0 -= 6;
                    var_s1 -= 6;
                    var_s2 -= 6;

                    var_s0->unk_08 = 0;
                    var_s0->unk_0C = ((temp_fs5 * 0) + temp_fs4) - ((temp_fs3 + (temp_ft4 * 0)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.166667f;
                    var_s0->unk_0C =
                        ((temp_fs5 * 0.166667f) + temp_fs4) - (((temp_fs3 + (temp_ft4 * 0.166667f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.333333f;
                    var_s0->unk_0C = ((temp_fs5 * 0.333333f) + temp_fs4) - ((temp_fs3 + (temp_ft4 * 0.333333f)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.5f;
                    var_s0->unk_0C = ((temp_fs5 * 0.5f) + temp_fs4) - (((temp_fs3 + (temp_ft4 * 0.5f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.666667f;
                    var_s0->unk_0C = ((temp_fs5 * 0.666667f) + temp_fs4) - ((temp_fs3 + (temp_ft4 * 0.666667f)) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;

                    var_s0->unk_08 = 0.833333f;
                    var_s0->unk_0C =
                        ((temp_fs5 * 0.833333f) + temp_fs4) - (((temp_fs3 + (temp_ft4 * 0.833333f)) * 3.0f) / 8);
                    var_s0++;
                    var_s1++;
                    var_s2++;
                }
                break;
        }
    }

    D_807BCB58.unk_08 = var_s2;
    D_807BCB58.unk_0C = spBC;
    D_807BCB58.unk_04 = var_s1;
}

void func_80700254(s32 courseIndex) {
    unk_802D1B60_unk_00* var_s0;
    s32 spC0;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_ft3;
    s32 i;
    s32 var_s2;
    s32 var_s3;
    f32 temp_fv1;
    CourseSegment* temp_a0;
    Vec3f sp88;

    spC0 = D_807BCB58.unk_08;
    var_s3 = D_807BCB58.unk_0C;
    var_s2 = D_807BCB58.unk_04;

    var_s0 = &D_807BCB58.unk_00[var_s2];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        temp_a0 = &gCourseInfos[courseIndex].courseSegments[i];

        temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
        temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
        temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
        temp_fs1 = ((temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2);
        temp_fs0 -= temp_fs2;
        temp_fs1 -= temp_fs3;

        temp_fv1 = 0.0f;

        switch (gCourseCtx.courseData.jump[i]) {
            case JUMP_ALL:
                temp_fv1 -= 100.0f / func_i2_800B2500(temp_a0, 1.0f, &sp88);
                temp_fv1 += 1.0f;

                var_s0->featureType = COURSE_FEATURE_JUMP;
                var_s0->segmentIndex = i;
                var_s0->unk_08 = temp_fv1;
                var_s0->unk_0C = (temp_fs1 * temp_fv1) + temp_fs3;
                var_s0->unk_10.x = temp_fs2 + (temp_fs0 * temp_fv1);
                var_s0->unk_10.y = 30.0f;
                var_s0->unk_10.z = 60.0f;
                var_s0++;
                var_s2++;
                var_s3++;
                break;
            case JUMP_LEFT:
                temp_fv1 -= 100.0f / func_i2_800B2500(temp_a0, 1.0f, &sp88);
                temp_fv1 += 1.0f;

                var_s0->featureType = COURSE_FEATURE_JUMP;
                var_s0->segmentIndex = i;
                var_s0->unk_08 = temp_fv1;
                var_s0->unk_0C = ((temp_fs1 * temp_fv1) + temp_fs3) + ((temp_fs2 + (temp_fs0 * temp_fv1)) / 4);
                var_s0->unk_10.x = (temp_fs2 + (temp_fs0 * temp_fv1)) / 2;
                var_s0->unk_10.y = 30.0f;
                var_s0->unk_10.z = 60.0f;
                var_s0++;
                var_s2++;
                var_s3++;
                break;
            case JUMP_RIGHT:
                temp_fv1 -= 100.0f / func_i2_800B2500(temp_a0, 1.0f, &sp88);
                temp_fv1 += 1.0f;

                var_s0->featureType = COURSE_FEATURE_JUMP;
                var_s0->segmentIndex = i;
                var_s0->unk_08 = temp_fv1;
                var_s0->unk_0C = ((temp_fs1 * temp_fv1) + temp_fs3) - ((temp_fs2 + (temp_fs0 * temp_fv1)) / 4);
                var_s0->unk_10.x = (temp_fs2 + (temp_fs0 * temp_fv1)) / 2;
                var_s0->unk_10.y = 30.0f;
                var_s0->unk_10.z = 60.0f;
                var_s0++;
                var_s2++;
                var_s3++;
                break;
        }
    }

    D_807BCB58.unk_08 = spC0;
    D_807BCB58.unk_0C = var_s3;
    D_807BCB58.unk_04 = var_s2;
}

void func_80700570(s32 courseIndex, s32 segmentIndex) {
    s32 sp5C;
    f32 sp58;
    f32 temp;
    f32 var_fs0;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    CourseSegment* sp3C;
    unk_8006FF90_arg_1* sp38;
    Vec3f sp2C;

    sp5C = D_807BDD68.count;
    sp38 = &D_807BDD68.unk_00[sp5C];
    sp3C = &gCourseInfos[courseIndex].courseSegments[segmentIndex];
    sp4C = sp3C->radiusLeft + sp3C->radiusRight;
    sp48 = sp3C->next->radiusLeft + sp3C->next->radiusRight;
    sp44 = (sp3C->radiusLeft - sp3C->radiusRight) / 2;
    sp40 = (sp3C->next->radiusLeft - sp3C->next->radiusRight) / 2;
    sp48 -= sp4C;
    sp40 -= sp44;
    sp58 = sp3C->length;

    var_fs0 = 0;

    switch (gCourseCtx.courseData.dash[segmentIndex]) {
        case DASH_MIDDLE:
            sp58 /= 2;
            temp = func_i2_800B2500(sp3C, 0, &sp2C);
            var_fs0 += sp58 / temp;
            sp38->segmentIndex = segmentIndex;
            sp38->effectType = COURSE_EFFECT_DASH;
            sp38->unk_08 = var_fs0;
            sp38->unk_0C = 1.0f;

            switch (sp3C->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 0.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 22.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    sp38->unk_10 = sp38->unk_14 = 202.5f;
                    break;
                default:
                    sp38->unk_10 = 0.0f;
                    sp38->unk_14 = 0.0f;
                    break;
            }
            sp5C++;
            break;
        case DASH_LEFT:
            sp58 /= 2;
            temp = func_i2_800B2500(sp3C, 0, &sp2C);
            var_fs0 += sp58 / temp;
            sp4C = (var_fs0 * sp48) + sp4C;
            sp38->segmentIndex = segmentIndex;
            sp38->effectType = COURSE_EFFECT_DASH;
            sp38->unk_08 = var_fs0;
            sp38->unk_0C = 1.0f;
            sp38->unk_10 = (sp4C / 2.0) - 100.0f;
            sp38->unk_14 = sp38->unk_10;
            if (sp38->unk_10 < 0.0f) {
                sp38->unk_10 = 0.0f;
            }
            sp38->unk_14 = sp38->unk_10;

            switch (sp3C->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 45.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 157.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    sp38->unk_10 = sp38->unk_14 = 337.5f;
                    break;
            }
            sp5C++;
            break;
        case DASH_RIGHT:
            sp58 /= 2;
            temp = func_i2_800B2500(sp3C, 0, &sp2C);
            var_fs0 += sp58 / temp;
            sp4C = (var_fs0 * sp48) + sp4C;
            sp38->segmentIndex = segmentIndex;
            sp38->effectType = COURSE_EFFECT_DASH;
            sp38->unk_08 = var_fs0;
            sp38->unk_0C = 1.0f;
            sp38->unk_10 = ((sp4C / 2.0) - 100.0f) * -1.0f;

            if (sp38->unk_10 > 0.0f) {
                sp38->unk_10 = 0.0f;
            }
            sp38->unk_14 = sp38->unk_10;

            switch (sp3C->trackSegmentInfo & TRACK_SHAPE_MASK) {
                case TRACK_SHAPE_HALF_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 315.0f;
                    break;
                case TRACK_SHAPE_PIPE:
                    sp38->unk_10 = sp38->unk_14 = 247.5f;
                    break;
                case TRACK_SHAPE_CYLINDER:
                    sp38->unk_10 = sp38->unk_14 = 67.5f;
                    break;
            }
            sp5C++;
            break;
    }

    D_807BDD68.unk_00 = D_807BCB68;
    D_807BDD68.count = sp5C;
}

void func_807009C8(s32 courseIndex) {
    s32 j;
    s32 i;
    s32 var_a1;
    CourseSegment* temp_t2;
    unk_802D1B60_unk_00* var_a2;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;

    var_a1 = D_807BCB58.unk_04;

    var_a2 = &D_807BCB58.unk_00[var_a1];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gCourseInfos[courseIndex].segmentCount; j++) {
            temp_t2 = &gCourseInfos[courseIndex].courseSegments[j];

            if (i == 3) {}

            temp_fs2 = temp_t2->radiusLeft + temp_t2->radiusRight;
            temp_fs0 = temp_t2->next->radiusLeft + temp_t2->next->radiusRight;
            temp_fs3 = (temp_t2->radiusLeft - temp_t2->radiusRight) / 2;
            temp_fs1 = (temp_t2->next->radiusLeft - temp_t2->next->radiusRight) / 2;
            temp_fs0 -= temp_fs2;
            temp_fs1 -= temp_fs3;

            if (i == gCourseCtx.courseData.gate[j]) {
                switch (gCourseCtx.courseData.gate[j]) {
                    case GATE_SQUARE:
                        var_a2->featureType = COURSE_FEATURE_GATE_SQUARE;
                        break;
                    case GATE_START:
                        var_a2->featureType = COURSE_FEATURE_GATE_START;
                        break;
                    case GATE_HEXAGONAL:
                        var_a2->featureType = COURSE_FEATURE_GATE_HEXAGONAL;
                        break;
                }
                var_a2->segmentIndex = j;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_fs3;
                var_a2->unk_10.x = 0.0f;
                var_a2->unk_10.y = 0.0f;
                var_a2->unk_10.z = 0.0f;
                var_a1++;
                var_a2++;
            }
        }
    }
    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
    D_807BCB58.unk_04 = var_a1;
}

void func_80700B18(s32 courseIndex) {
    s32 var_a1;
    s32 i;
    CourseSegment* temp_a0;
    unk_802D1B60_unk_00* var_a2;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;

    var_a1 = D_807BCB58.unk_04;

    var_a2 = &D_807BCB58.unk_00[var_a1];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        temp_a0 = &gCourseInfos[courseIndex].courseSegments[i];

        temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
        temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
        temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
        temp_fs1 = (temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2;
        temp_fs0 -= temp_fs2;
        temp_fs1 -= temp_fs3;

        switch (gCourseCtx.courseData.building[i]) {
            case BUILDING_TALL_LEFT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_TALL_RIGHT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_RIGHT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_TALL_BOTH:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                var_a2->segmentIndex = i;
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_RIGHT;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
        }
    }
    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
    D_807BCB58.unk_04 = var_a1;
}

void func_80700CE4(s32 courseIndex) {
    s32 var_a1;
    s32 i;
    s32 j;
    CourseSegment* temp_a0;
    unk_802D1B60_unk_00* var_a2;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;

    var_a1 = D_807BCB58.unk_04;

    var_a2 = &D_807BCB58.unk_00[var_a1];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        temp_a0 = &gCourseInfos[courseIndex].courseSegments[i];

        temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
        temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
        temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
        temp_fs1 = (temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2;
        temp_fs0 -= temp_fs2;
        temp_fs1 -= temp_fs3;

        switch (gCourseCtx.courseData.building[i]) {
            case BUILDING_SHORT_LEFT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SHORT_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_SHORT_RIGHT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SHORT_RIGHT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_SHORT_BOTH:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SHORT_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                var_a2->segmentIndex = i;
                var_a2->featureType = COURSE_FEATURE_BUILDING_SHORT_RIGHT;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
        }
    }

    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
    D_807BCB58.unk_04 = var_a1;
}

void func_80700EBC(s32 courseIndex) {
    s32 var_a1;
    s32 i;
    s32 j;
    CourseSegment* temp_a0;
    unk_802D1B60_unk_00* var_a2;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;

    var_a1 = D_807BCB58.unk_04;
    var_a2 = &D_807BCB58.unk_00[var_a1];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        temp_a0 = &gCourseInfos[courseIndex].courseSegments[i];

        temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
        temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
        temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
        temp_fs1 = (temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2;
        temp_fs0 -= temp_fs2;
        temp_fs1 -= temp_fs3;

        switch (gCourseCtx.courseData.building[i]) {
            case BUILDING_SPIRE_LEFT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SPIRE_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_SPIRE_RIGHT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SPIRE_RIGHT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_SPIRE_BOTH:
                var_a2->featureType = COURSE_FEATURE_BUILDING_SPIRE_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                var_a2->segmentIndex = i;
                var_a2->featureType = COURSE_FEATURE_BUILDING_SPIRE_RIGHT;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
        }
    }

    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
    D_807BCB58.unk_04 = var_a1;
}

void func_80701094(s32 courseIndex) {
    s32 var_a1;
    s32 i;
    s32 j;
    CourseSegment* temp_a0;
    unk_802D1B60_unk_00* var_a2;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;

    var_a1 = D_807BCB58.unk_04;

    var_a2 = &D_807BCB58.unk_00[var_a1];

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        temp_a0 = &gCourseInfos[courseIndex].courseSegments[i];

        temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
        temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
        temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
        temp_fs1 = (temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2;
        temp_fs0 -= temp_fs2;
        temp_fs1 -= temp_fs3;

        switch (gCourseCtx.courseData.building[i]) {
            case BUILDING_MOUNTAIN_BOTH:
                var_a2->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                var_a2->segmentIndex = i;
                var_a2->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_MOUNTAIN_LEFT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_MOUNTAIN_RIGHT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_MOUNTAIN_RIGHT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_TALL_GOLD_BOTH:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                var_a2->segmentIndex = i;
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_TALL_GOLD_LEFT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_LEFT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = temp_a0->radiusLeft + 500.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
            case BUILDING_TALL_GOLD_RIGHT:
                var_a2->featureType = COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT;
                var_a2->segmentIndex = i;
                var_a2->unk_08 = 0.0f;
                var_a2->unk_0C = (temp_a0->radiusRight + 500.0f) * -1.0f;
                // clang-format off
                var_a2->unk_10.x = 0.0f; \
                var_a2->unk_10.y = 0.0f; \
                var_a2->unk_10.z = 0.0f;
                // clang-format on
                var_a2++;
                var_a1++;
                break;
        }
    }

    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
    D_807BCB58.unk_04 = var_a1;
}

void func_80701328(s32 courseIndex) {
    func_80700B18(courseIndex);
    func_80700CE4(courseIndex);
    func_80700EBC(courseIndex);
    func_80701094(courseIndex);
}

void func_80701360(s32 courseIndex) {
    unk_802D1B60_unk_00* var_a2;
    s32 var_a1 = D_807BCB58.unk_04;
    s32 temp_v0 = D_807BCB58.unk_08;
    s32 temp_v1 = D_807BCB58.unk_0C;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    CourseSegment* temp_a0;
    s32 i;
    s32 j;

    var_a2 = &D_807BCB58.unk_00[var_a1];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < gCourseInfos[courseIndex].segmentCount; j++) {
            temp_a0 = &gCourseInfos[courseIndex].courseSegments[j];

            if (i == 5) {}

            temp_fs2 = temp_a0->radiusLeft + temp_a0->radiusRight;
            temp_fs0 = temp_a0->next->radiusLeft + temp_a0->next->radiusRight;
            temp_fs3 = (temp_a0->radiusLeft - temp_a0->radiusRight) / 2;
            temp_fs1 = (temp_a0->next->radiusLeft - temp_a0->next->radiusRight) / 2;
            temp_fs0 -= temp_fs2;
            temp_fs1 -= temp_fs3;

            if (i == gCourseCtx.courseData.sign[j]) {
                switch (gCourseCtx.courseData.sign[j]) {
                    case SIGN_TV:
                        var_a2->featureType = COURSE_FEATURE_SIGN_TV_RIGHT;
                        var_a2->segmentIndex = j;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = (temp_a0->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        var_a2->segmentIndex = j;
                        var_a2->featureType = COURSE_FEATURE_SIGN_TV_LEFT;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = temp_a0->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        break;
                    case SIGN_2:
                        var_a2->featureType = COURSE_FEATURE_SIGN_2_RIGHT;
                        var_a2->segmentIndex = j;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = (temp_a0->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        var_a2->segmentIndex = j;
                        var_a2->featureType = COURSE_FEATURE_SIGN_2_LEFT;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = temp_a0->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        break;
                    case SIGN_1:
                        var_a2->featureType = COURSE_FEATURE_SIGN_1_RIGHT;
                        var_a2->segmentIndex = j;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = (temp_a0->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        var_a2->segmentIndex = j;
                        var_a2->featureType = COURSE_FEATURE_SIGN_1_LEFT;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = temp_a0->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        break;
                    case SIGN_NINTEX:
                        var_a2->featureType = COURSE_FEATURE_SIGN_NINTEX_RIGHT;
                        var_a2->segmentIndex = j;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = (temp_a0->radiusRight + 23.0f + 20.0f) * -1.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        var_a2->segmentIndex = j;
                        var_a2->featureType = COURSE_FEATURE_SIGN_NINTEX_LEFT;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = temp_a0->radiusLeft + 23.0f + 20.0f;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        break;
                    case SIGN_OVERHEAD:
                        var_a2->featureType = COURSE_FEATURE_SIGN_OVERHEAD;
                        var_a2->segmentIndex = j;
                        var_a2->unk_08 = 0.0f;
                        var_a2->unk_0C = temp_fs3;
                        // clang-format off
                        var_a2->unk_10.x = 0.0f; \
                        var_a2->unk_10.y = 0.0f; \
                        var_a2->unk_10.z = 0.0f;
                        // clang-format on
                        var_a2++;
                        var_a1++;
                        break;
                }
            }
        }
    }

    D_807BCB58.unk_04 = var_a1;
    D_807BCB58.unk_08 = temp_v0;
    D_807BCB58.unk_0C = temp_v1;
}

extern s32 D_807B6520;

void func_807016AC(s32 courseIndex) {
    if ((D_8076C954 != 0) && (D_8076C950 == 0)) {
        if (D_807B6520 < 4) {
            return;
        }
    } else if (gCourseCtx.courseData.controlPointCount < 4) {
        return;
    }

    D_807BCB58.unk_08 = 0;
    D_807BCB58.unk_0C = 0;
    D_807BCB58.unk_04 = 0;
    func_806FF630(courseIndex);
    func_80700254(courseIndex);
    func_807009C8(courseIndex);
    func_80701328(courseIndex);
    func_80701360(courseIndex);
}

void func_80701754(s32 courseIndex) {
    s32 i;

    if ((D_8076C954 != 0) && (D_8076C950 == 0)) {
        if (D_807B6520 < 4) {
            return;
        }
    } else if (gCourseCtx.courseData.controlPointCount < 4) {
        return;
    }

    D_807BDD68.count = 0;

    for (i = 0; i < gCourseInfos[courseIndex].segmentCount; i++) {
        func_806FF364(courseIndex, i);
        func_806FF12C(courseIndex, i);
        func_806FEEEC(courseIndex, i);
        func_80700570(courseIndex, i);
    }
}

extern CourseData D_800CF950;
extern CourseData D_i2_800D0130;
extern s32 gCourseIndex;
extern CourseSegment D_807B8E30[];
extern CourseSegment D_802D0620[];

void func_8070183C(void) {
    CourseSegment* segment;
    CourseInfo* courseInfo;
    s32 var_a3;
    s32 i;

    D_i2_800D0130 = gCourseCtx.courseData;

    courseInfo = &gCourseInfos[gCourseIndex];
    courseInfo->courseSegments = D_802D0620;

    for (i = 0, segment = D_802D0620; i < courseInfo->segmentCount; i++) {
        segment->segmentIndex = i;
        segment->next = segment + 1;
        segment->prev = segment - 1;
        segment++;
    }

    courseInfo->courseSegments[0].prev = &courseInfo->courseSegments[courseInfo->segmentCount - 1];
    courseInfo->courseSegments[courseInfo->segmentCount - 1].next = courseInfo->courseSegments;

    var_a3 = 0;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        segment = &courseInfo->courseSegments[i];
        if (!(segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
            var_a3 = i;
            break;
        }
    }

    segment = &courseInfo->courseSegments[var_a3];

    for (i = 0; i < courseInfo->segmentCount; i++) {
        if (segment->next->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) {
            var_a3 = segment->segmentIndex;
            break;
        }
        segment = segment->next;
    }

    var_a3 = courseInfo->courseSegments[var_a3].next->segmentIndex;
    segment = &courseInfo->courseSegments[var_a3];
    for (i = 0; i < courseInfo->segmentCount; i++) {
        var_a3 = segment->segmentIndex;
        D_807B8E30[i] = *segment;

        D_800CF950.bankAngle[i] = gCourseCtx.courseData.bankAngle[var_a3];
        D_800CF950.pit[i] = gCourseCtx.courseData.pit[var_a3];
        D_800CF950.dash[i] = gCourseCtx.courseData.dash[var_a3];
        D_800CF950.dirt[i] = gCourseCtx.courseData.dirt[var_a3];
        D_800CF950.ice[i] = gCourseCtx.courseData.ice[var_a3];
        D_800CF950.jump[i] = gCourseCtx.courseData.jump[var_a3];
        D_800CF950.landmine[i] = gCourseCtx.courseData.landmine[var_a3];
        D_800CF950.gate[i] = gCourseCtx.courseData.gate[var_a3];
        D_800CF950.building[i] = gCourseCtx.courseData.building[var_a3];
        D_800CF950.sign[i] = gCourseCtx.courseData.sign[var_a3];
        segment = segment->next;
    }

    for (i = 0; i < courseInfo->segmentCount; i++) {
        courseInfo->courseSegments[i] = D_807B8E30[i];

        gCourseCtx.courseData.bankAngle[i] = D_800CF950.bankAngle[i];
        gCourseCtx.courseData.pit[i] = D_800CF950.pit[i];
        gCourseCtx.courseData.dash[i] = D_800CF950.dash[i];
        gCourseCtx.courseData.dirt[i] = D_800CF950.dirt[i];
        gCourseCtx.courseData.ice[i] = D_800CF950.ice[i];
        gCourseCtx.courseData.jump[i] = D_800CF950.jump[i];
        gCourseCtx.courseData.landmine[i] = D_800CF950.landmine[i];
        gCourseCtx.courseData.gate[i] = D_800CF950.gate[i];
        gCourseCtx.courseData.building[i] = D_800CF950.building[i];
        gCourseCtx.courseData.sign[i] = D_800CF950.sign[i];
    }

    segment = courseInfo->courseSegments;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        segment->segmentIndex = i;
        segment->next = segment + 1;
        segment->prev = segment - 1;
        segment++;
    }
    courseInfo->courseSegments[0].prev = &courseInfo->courseSegments[courseInfo->segmentCount - 1];
    courseInfo->courseSegments[courseInfo->segmentCount - 1].next = courseInfo->courseSegments;
}

extern OSIoMesg D_8079A308;
extern OSMesgQueue gDmaMesgQueue;
extern OSPiHandle* gCartRomHandle;

void func_80701C04(void* romAddr, void* ramAddr, size_t size) {
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_8079A308.hdr.pri = 0;
    D_8079A308.hdr.retQueue = &gDmaMesgQueue;
    D_8079A308.dramAddr = osPhysicalToVirtual(ramAddr);
    D_8079A308.devAddr = romAddr;
    D_8079A308.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gCartRomHandle, &D_8079A308, OS_READ);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

void func_80701CAC(void* romAddr, void* ramAddr, size_t size) {
    OSMesg sp20[8];

    if (gDmaMesgQueue.validCount >= gDmaMesgQueue.msgCount) {
        osRecvMesg(&gDmaMesgQueue, sp20, OS_MESG_BLOCK);
    }
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_8079A308.hdr.pri = OS_MESG_PRI_NORMAL;
    D_8079A308.hdr.retQueue = &gDmaMesgQueue;
    D_8079A308.dramAddr = osPhysicalToVirtual(ramAddr);
    D_8079A308.devAddr = (uintptr_t) romAddr;
    D_8079A308.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gCartRomHandle, &D_8079A308, OS_READ);
    osRecvMesg(&gDmaMesgQueue, sp20, OS_MESG_BLOCK);
}

void func_80701D7C(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80701CAC(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }

    remainder = size % 1024;
    if (remainder) {
        func_80701CAC(romAddr, ramAddr, remainder);
    }
}

void func_80701E08(void) {

    func_80704050(1);

    switch (func_8070595C()) {
        case 1:
            func_8070F8A4(-1, 3);
            break;
        case 0:
            func_8070F8A4(-1, 4);
            break;
        default:
            break;
    }
    while (func_8070595C() != 2) {}
    func_80704050(0);
}

// todo: move these to appropriate places
static const char devrostr00[] = "%d startVtx error %d/%d\n";
static const char devrostr01[] = "GADGET OVER !! OVER !! OVER !!\n";
static const char devrostr02[] = "devide idx error\n";
static const char devrostr03[] = "\n/***\nCOURSE GADGET TEXTURE OVER!! %f,%f\n***/\n";
static const char devrostr04[] = "GADGET OVER !! OVER !! OVER !!\n";
static const char devrostr05[] = "Gadget Vtx Over %d!!\n";
static const char devrostr06[] = "U ERROR RETRY\n";
static const char devrostr07[] = "U ERROR RETRY\n";
static const char devrostr08[] = "U ERROR RETRY\n";

extern u8 gEditCupTrackNames[][9];
extern s16 gPlayer1OverallPosition;
extern s32 D_807C70C8;
extern s32 D_800F7404;
extern u8 D_320[];
extern OSMesgQueue D_8079F998;
extern s32 D_8079F9B4;
extern s32 D_80794CD4;
extern u8 D_800BF044[];
extern s8 D_8076C7D8;

UNUSED s32 D_80773738 = 0;

void func_80701E90(s32 courseIndex) {
    s32 pad;
    s32 sp50;
    s32 pad2;
    s32 sp48;
    s32 pad3[2];

    PRINTF("============== COURSE LOAD %2d  ==============\n", courseIndex);

    func_i2_800AA80C();
    if (courseIndex >= COURSE_DEATH_RACE) {
        sp48 = D_807C70C8 + (courseIndex - 30) * sizeof(CourseData);
        func_80701D7C(sp48, osVirtualToPhysical(&gCourseCtx.courseData), sizeof(CourseData));
        PRINTF("ENTRY CHECK\n");
        if ((gPlayer1OverallPosition >= 4) && (courseIndex == COURSE_ENDING)) {
            gCourseCtx.courseData.skybox = SKYBOX_BLUE;
        }
    } else if (courseIndex >= COURSE_X_1) {
        Course_GenerateRandomCourse();
        return;
    } else if (courseIndex >= COURSE_EDIT_1) {
        PRINTF("ENTRY CHECK NONE(DEFAULT COURSE)\n");
        sp50 = courseIndex - COURSE_EDIT_1;
        func_80701E08();
        if (gEditCupTrackNames[sp50][0] == '\0' || sp50 >= 6) {
            char sp38[8] = { "GHOST00" };

            sp38[5] = (courseIndex / 10) + '0';
            sp38[6] = (courseIndex % 10) + '0';
            func_i2_800A7CB8(func_i2_800AA84C());
            func_8076852C(0xFFFB, sp38, "GOST", &gCourseCtx,
                          sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
            osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            Course_CalculateChecksum();
            if (func_i2_800A9F98()) {
                PRINTF("GHOST DATA WAS BROKEN\n");
                func_i2_800AA80C();
                func_i2_800A7CB8(func_i2_800AA84C());
            }
            PRINTF("DEF LOAD OK\n");
            func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
            func_80703B40(D_320 + sp50, &gCourseCtx.courseData, sizeof(CourseData), 0);
            if ((Course_CalculateChecksum() != gCourseCtx.courseData.checksum) ||
                (gCourseCtx.courseData.creatorId != CREATOR_NINTENDO) ||
                ((s8) gCourseCtx.courseData.fileName[0x16] >= 0xE)) {
                func_8070F8A4(-1, 9);
                while (true) {}
            }
        } else {
            func_8076852C(0xFFFB, gEditCupTrackNames[sp50], "CRSD", &gCourseCtx,
                          sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
            osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            PRINTF("ENTRY CHECK BUT NONE %s (DEFAULT COURSE)\n");
            if (D_8079F9B4 != 0) {
                if (D_80794CD4 == 0xF2) {
                    gEditCupTrackNames[sp50][0] = '\0';
                    {
                        char sp30[8] = { "GHOST00" };
                        sp30[5] = (courseIndex / 10) + '0';
                        sp30[6] = (courseIndex % 10) + '0';
                        func_i2_800A7CB8(func_i2_800AA84C());
                        func_8076852C(0xFFFB, sp30, "GOST", &gCourseCtx,
                                      sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
                        osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                        Course_CalculateChecksum();
                        if (func_i2_800A9F98()) {
                            PRINTF("GHOST DATA WAS BROKEN\n");
                            func_i2_800AA80C();
                            func_i2_800A7CB8(func_i2_800AA84C());
                        }
                        PRINTF("DEF LOAD OK\n");
                        func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
                        func_80703B40(D_320 + sp50, &gCourseCtx.courseData, sizeof(CourseData), 0);
                        if ((Course_CalculateChecksum() != gCourseCtx.courseData.checksum) ||
                            (gCourseCtx.courseData.creatorId != CREATOR_NINTENDO) ||
                            ((s8) gCourseCtx.courseData.fileName[0x16] >= 0xE)) {
                            func_8070F8A4(-1, 9);
                            while (true) {}
                        }
                    }
                }
            } else {
                PRINTF("ENTRY LOAD OK\n");
                PRINTF("course ID is %d\n", courseIndex);
                func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
            }
        }
        gCourseInfos[courseIndex].encodedCourseIndex = (Course_CalculateChecksum() << 5) | COURSE_EDIT_1;
    } else {
        char sp28[8] = { "GHOST00" };
        sp28[5] = (courseIndex / 10) + '0';
        sp28[6] = (courseIndex % 10) + '0';
        func_i2_800A7CB8(func_i2_800AA84C());
        if (D_8076C7D8 == 0) {
            func_8076852C(0xFFFB, sp28, "GOST", &gCourseCtx,
                          sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
            osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
        }
        sp48 = D_807C70C8 + courseIndex * sizeof(CourseData);
        PRINTF("UNPACK\n");
        func_80701D7C(sp48, osVirtualToPhysical(&gCourseCtx.courseData), sizeof(CourseData));
        PRINTF("UNPACK OK\n");
        gCourseCtx.courseData.fileName[0x16] = D_800BF044[courseIndex];
        if ((D_8076C954 != 0) && (courseIndex == COURSE_RED_CANYON_2)) {
            gCourseCtx.courseData.dirt[21] = DIRT_NONE;
            gCourseCtx.courseData.checksum = Course_CalculateChecksum();
        }
    }

    func_80702BC4(courseIndex);
    if (D_8076C954 != 0) {
        D_800F7404 = 1;
    }
}

void func_80702448(s32 courseIndex) {
    s32 pad[2];
    s32 sp4C;
    s32 sp48;
    s32 pad3[2];

    func_i2_800AA80C();
    if (courseIndex >= COURSE_DEATH_RACE) {
        PRINTF("ENTRY CHECK\n");
        PRINTF("INDEX %d\n");
        sp48 = D_807C70C8 + (courseIndex - 30) * sizeof(CourseData);
        func_80701D7C(sp48, osVirtualToPhysical(&gCourseCtx.courseData), sizeof(CourseData));
        if ((gPlayer1OverallPosition >= 4) && (courseIndex == COURSE_ENDING)) {
            gCourseCtx.courseData.skybox = SKYBOX_BLUE;
        }
    } else if (courseIndex >= COURSE_X_1) {
        Course_GenerateRandomCourse();
        return;
    } else if (courseIndex >= COURSE_EDIT_1) {
        PRINTF("ENTRY CHECK NONE(DEFAULT COURSE)\n");
        sp4C = courseIndex - COURSE_EDIT_1;
        switch (func_8070595C()) {
            case 1:
                func_8070F8A4(-1, 3);
                break;
            case 0:
                func_8070F8A4(-1, 4);
                break;
            default:
                break;
        }
        while (func_8070595C() != 2) {}
        if (gEditCupTrackNames[sp4C][0] == '\0' || sp4C >= 6) {
            char sp38[8] = { "GHOST00" };
            s32 pad;

            sp38[5] = (courseIndex / 10) + '0';
            sp38[6] = (courseIndex % 10) + '0';
            func_i2_800A7CB8(func_i2_800AA84C());
            func_8076852C(0xFFFB, sp38, "GOST", &gCourseCtx,
                          sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
            osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            Course_CalculateChecksum();
            if (func_i2_800A9F98()) {
                func_i2_800AA80C();
                func_i2_800A7CB8(func_i2_800AA84C());
            }
            PRINTF("course index is %d\n", courseIndex);
            PRINTF("DEF LOAD OK\n");
            func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
            func_80703B40(D_320 + sp4C, &gCourseCtx.courseData, sizeof(CourseData), 0);
            if ((Course_CalculateChecksum() != gCourseCtx.courseData.checksum) ||
                (gCourseCtx.courseData.creatorId != CREATOR_NINTENDO) ||
                ((s8) gCourseCtx.courseData.fileName[0x16] >= 0xE)) {
                func_8070F8A4(-1, 9);
                while (true) {}
            }
        } else {
            func_8076852C(0xFFFB, gEditCupTrackNames[sp4C], "CRSD", &gCourseCtx,
                          sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
            osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            PRINTF("ENTRY CHECK BUT NONE %s (DEFAULT COURSE)\n");
            if (D_8079F9B4 != 0) {
                if (D_80794CD4 == 0xF2) {
                    gEditCupTrackNames[sp4C][0] = '\0';
                    {
                        char sp30[8] = { "GHOST00" };
                        s32 pad;

                        sp30[5] = (courseIndex / 10) + '0';
                        sp30[6] = (courseIndex % 10) + '0';
                        func_i2_800A7CB8(func_i2_800AA84C());
                        func_8076852C(0xFFFB, sp30, "GOST", &gCourseCtx,
                                      sizeof(CourseData) + 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
                        osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                        Course_CalculateChecksum();
                        if (func_i2_800A9F98()) {
                            func_i2_800AA80C();
                            func_i2_800A7CB8(func_i2_800AA84C());
                        }
                        PRINTF("course index is %d\n", courseIndex);
                        PRINTF("DEF LOAD OK\n");
                        func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
                        func_80703B40(D_320 + sp4C, &gCourseCtx.courseData, sizeof(CourseData), 0);
                        if ((Course_CalculateChecksum() != gCourseCtx.courseData.checksum) ||
                            (gCourseCtx.courseData.creatorId != CREATOR_NINTENDO) ||
                            ((s8) gCourseCtx.courseData.fileName[0x16] >= 0xE)) {
                            func_8070F8A4(-1, 9);
                            while (true) {}
                        }
                    }
                }
            } else {
                PRINTF("ENTRY LOAD OK\n");
                PRINTF("course ID is %d\n", courseIndex);
                func_i2_800A8CE4(func_i2_800AA84C(), courseIndex);
            }
        }
        gCourseInfos[courseIndex].encodedCourseIndex = (Course_CalculateChecksum() << 5) | COURSE_EDIT_1;
    } else {
        sp48 = D_807C70C8 + courseIndex * sizeof(CourseData);

        func_80701D7C(sp48, osVirtualToPhysical(&gCourseCtx.courseData), sizeof(CourseData));
        if (D_8076C954 != 0 && courseIndex == COURSE_RED_CANYON_2) {
            gCourseCtx.courseData.dirt[21] = DIRT_NONE;
            gCourseCtx.courseData.checksum = Course_CalculateChecksum();
        }
    }
}

void func_80702974(s32 courseIndex) {
    func_807016AC(courseIndex);
    func_80701754(courseIndex);
}

void func_8070299C(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        gCourseCtx.courseData.bankAngle[i] = 0;
        gCourseCtx.courseData.pit[i] = PIT_NONE;
        gCourseCtx.courseData.dash[i] = DASH_NONE;
        gCourseCtx.courseData.dirt[i] = DIRT_NONE;
        gCourseCtx.courseData.ice[i] = ICE_NONE;
        gCourseCtx.courseData.jump[i] = JUMP_NONE;
        gCourseCtx.courseData.landmine[i] = LANDMINE_NONE;
        gCourseCtx.courseData.gate[i] = GATE_NONE;
        gCourseCtx.courseData.building[i] = BUILDING_NONE;
        gCourseCtx.courseData.sign[i] = SIGN_NONE;
    }
}

void func_80702A68(void) {
    func_8070299C();
    gCourseCtx.courseData.venue = VENUE_MUTE_CITY;
    gCourseCtx.courseData.skybox = SKYBOX_PURPLE;
}

extern u8 D_80030060;
extern s32 D_807B6520;
extern CourseData D_800D0910;
extern unk_802D1B60_unk_00 D_807BBE38[];

void func_80702A94(void) {
    s32 i;

    bzero(SEGMENT_VRAM_START(unk_context), SEGMENT_BSS_SIZE(unk_context));
    D_80030060 = 0;
    func_8070299C();
    D_807B6520 = 0;
    gCourseCtx.courseData.creatorId = CREATOR_NINTENDO;
    gCourseCtx.courseData.controlPointCount = 0;
    gCourseCtx.courseData.venue = VENUE_MUTE_CITY;
    gCourseCtx.courseData.skybox = SKYBOX_PURPLE;
    D_800D0910 = gCourseCtx.courseData;
    D_807BCB58.unk_00 = D_807BBE38;
    gCourseInfos[0].courseSegments = D_802D0620;
    D_807BDD68.unk_00 = D_807BCB68;

    for (i = 0; i < ARRAY_COUNT(gCourseInfos); i++) {}

    func_80701E90(0);
    func_8070299C();
    D_800D0910 = gCourseCtx.courseData;
    gCourseCtx.courseData.controlPointCount = 0;
    D_807B6520 = 0;
}

void func_80702BC4(s32 courseIndex) {
    s32 i;
    s32 sp20;
    CourseSegment* var_v0;
    CourseData* courseData = &gCourseCtx.courseData;

    if (courseData->controlPointCount == 0) {
        return;
    }

    gCourseInfos[courseIndex].courseSegments = D_802D0620;
    gCourseInfos[courseIndex].segmentCount = courseData->controlPointCount;

    for (i = 0; i < courseData->controlPointCount; i++) {
        D_802D0620[i].pos = courseData->controlPoint[i].pos;
        D_802D0620[i].radiusLeft = courseData->controlPoint[i].radiusLeft;
        D_802D0620[i].radiusRight = courseData->controlPoint[i].radiusRight;
        D_802D0620[i].trackSegmentInfo = courseData->controlPoint[i].trackSegmentInfo;
    }

    var_v0 = D_802D0620;
    for (i = 0; i < courseData->controlPointCount; i++, var_v0++) {
        var_v0->segmentIndex = i;
        var_v0->next = var_v0 + 1;
        var_v0->prev = var_v0 - 1;
    }

    D_802D0620[0].prev = &D_802D0620[courseData->controlPointCount - 1];
    D_802D0620[courseData->controlPointCount - 1].next = &D_802D0620[0];

    if (courseData->controlPointCount < 4) {
        return;
    }

    sp20 = func_i2_800B39B4(&gCourseInfos[courseIndex]);
    if (sp20 == -1) {
        sp20 = func_i2_800BE8BC(&gCourseInfos[courseIndex]);
    }
    func_807034F0(&gCourseInfos[courseIndex]);
    func_i2_800B3640(&gCourseInfos[courseIndex]);
    if (sp20 == -1) {
        func_807016AC(courseIndex);
    }
}

extern CourseSegment D_807B3C20[];

void func_80702D6C(void) {
    s32 i;
    CourseData* courseData = &gCourseCtx.courseData;

    courseData->controlPointCount = D_807B6520;

    for (i = 0; i < courseData->controlPointCount; i++) {
        courseData->controlPoint[i].pos = D_807B3C20[i].pos;
        courseData->controlPoint[i].radiusLeft = D_807B3C20[i].radiusLeft;
        courseData->controlPoint[i].radiusRight = D_807B3C20[i].radiusRight;
        courseData->controlPoint[i].trackSegmentInfo = D_807B3C20[i].trackSegmentInfo;
    }
}

// Centre the course around origin
void func_80702E0C(CourseInfo* courseInfo) {
    CourseSegment* courseSegment;
    s32 i;
    f32 minX = 65536.0f;
    f32 maxX = -65536.0f;
    f32 minZ = 65536.0f;
    f32 maxZ = -65536.0f;

    for (i = 0; i < courseInfo->segmentCount; i++) {

        courseSegment = &courseInfo->courseSegments[i];

        if (courseSegment->pos.x < minX) {
            minX = courseSegment->pos.x;
        }
        if (maxX < courseSegment->pos.x) {
            maxX = courseSegment->pos.x;
        }

        if (courseSegment->pos.z < minZ) {
            minZ = courseSegment->pos.z;
        }
        if (maxZ < courseSegment->pos.z) {
            maxZ = courseSegment->pos.z;
        }
    }

    for (i = 0; i < courseInfo->segmentCount; i++) {

        courseSegment = &courseInfo->courseSegments[i];

        courseSegment->pos.x -= ((minX + maxX) / 2);
        courseSegment->pos.z -= ((minZ + maxZ) / 2);
    }
}

void func_80702F1C(void) {
    CourseSegment* segment;
    s32 i;
    s32 trackShape;

    for (i = 0; i < D_807B6520; i++) {
        segment = &D_807B3C20[i];
        trackShape = segment->trackSegmentInfo & TRACK_SHAPE_MASK;
        switch (trackShape) {
            case TRACK_SHAPE_PIPE:
            case TRACK_SHAPE_CYLINDER:
            case TRACK_SHAPE_HALF_PIPE:
            case TRACK_SHAPE_AIR:
                gCourseCtx.courseData.pit[i] = PIT_NONE;
                gCourseCtx.courseData.dirt[i] = DIRT_NONE;
                gCourseCtx.courseData.ice[i] = ICE_NONE;
                gCourseCtx.courseData.jump[i] = JUMP_NONE;
                gCourseCtx.courseData.landmine[i] = LANDMINE_NONE;
                break;
        }
        switch (trackShape) {
            case TRACK_SHAPE_ROAD:
            case TRACK_SHAPE_BORDERLESS_ROAD:
                break;
            case TRACK_SHAPE_AIR:
                trackShape = segment->prev->trackSegmentInfo & TRACK_SHAPE_MASK;
                switch (trackShape) {
                    case TRACK_SHAPE_ROAD:
                    case TRACK_SHAPE_BORDERLESS_ROAD:
                        break;
                    default:
                        gCourseCtx.courseData.gate[i] = GATE_NONE;
                        gCourseCtx.courseData.sign[i] = SIGN_NONE;
                        break;
                }
                break;
            default:
                gCourseCtx.courseData.gate[i] = GATE_NONE;
                gCourseCtx.courseData.sign[i] = SIGN_NONE;
                break;
        }
    }
}

s32 D_8076CA74[] = { 1, 0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

extern s32 D_807C70D0;

void func_80702FF4(s32 venue) {
    void* sp1C = (D_8076CA74[venue] * 0x800) + D_807C70D0;

    func_80701D7C(sp1C, Segment_SegmentedToVirtual(D_8014A20), 0x800);
}

extern s8 gGamePaused;
extern GfxPool* gGfxPool;

void func_8070304C(void) {
    static s32 D_8076CAEC = 0;
    static s32 D_8076CAF0 = 0;
    f32 temp;
    MtxF sp3C;

    if (!gGamePaused) {
        D_8076CAEC = (D_8076CAEC + 0xFE9) & 0xFFF;
        D_8076CAF0 = (D_8076CAF0 + 0xFDE) & 0xFFF;
    }

    sp3C.m[2][1] = sp3C.m[0][1] = sp3C.m[1][0] = sp3C.m[1][2] = sp3C.m[3][0] = sp3C.m[3][1] = sp3C.m[3][2] =
        sp3C.m[0][3] = sp3C.m[1][3] = sp3C.m[2][3] = 0.0f;

    sp3C.m[3][3] = sp3C.m[1][1] = 1.0f;

    sp3C.m[2][0] = temp = SIN(0x1000 - D_8076CAEC);
    sp3C.m[0][2] = -temp;

    sp3C.m[0][0] = sp3C.m[2][2] = temp = COS(0x1000 - D_8076CAEC);

    Matrix_ToMtx(&sp3C, gGfxPool->unk_36628);

    sp3C.m[2][0] = temp = SIN(D_8076CAEC);
    sp3C.m[0][2] = -temp;
    sp3C.m[0][0] = sp3C.m[2][2] = temp = COS(D_8076CAEC);

    Matrix_ToMtx(&sp3C, gGfxPool->unk_36668);
    sp3C.m[1][2] = temp = SIN(D_8076CAF0);
    sp3C.m[2][1] = -temp;
    sp3C.m[2][2] = sp3C.m[1][1] = temp = COS(D_8076CAF0);

    sp3C.m[2][0] = sp3C.m[0][2] = 0.0f;
    sp3C.m[0][0] = 1.0f;
    Matrix_ToMtx(&sp3C, gGfxPool->unk_366A8);
}

Gfx D_8076CAF8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetDepthImage(0x3DBC00),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, 0x3DBC00),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPSetScissor(G_SC_NON_INTERLACE, 12, 8, 308, 232),
    gsDPFillRectangle(12, 8, 307, 231),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsSPEndDisplayList(),
};

s32 func_80703228(void) {
    return (s8) gCourseCtx.courseData.fileName[0x16];
}

void func_80703234(void) {
    s32 i;

    D_807BCB58.unk_08 = 0;
    D_807BCB58.unk_0C = 0;

    for (i = 0; i < D_807B6520; i++) {

        if (gCourseCtx.courseData.landmine[i] != -1) {
            D_807BCB58.unk_08 += 6;
        }

        if (gCourseCtx.courseData.jump[i] != -1) {
            D_807BCB58.unk_0C++;
        }
    }
}
