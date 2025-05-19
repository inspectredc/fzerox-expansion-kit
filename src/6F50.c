#include "global.h"
#include "fzx_racer.h"
#include "fzx_thread.h"
#include "fzx_course.h"
#include "fzx_assets.h"
#include "segment_symbols.h"
#include "leo/leo_internal.h"

bool CourseFeature_IsDecorational(s32 courseFeature) {
    if ((courseFeature >= COURSE_FEATURE_GATE_SQUARE) && (courseFeature <= COURSE_FEATURE_BUILDING_TALL_GOLD_RIGHT)) {
        return true;
    }
    return false;
}

extern unk_80225800 D_80225800;
extern unk_802D1B60 D_807BCB58;

extern s32 D_8076C950;
extern s32 D_8076C954;
extern unk_802D3978 D_807BF570[];

typedef struct unk_80128C94 {
    s8 unk_0000[0x53A0];
    Vtx unk_53A0[0x30];
    Vtx unk_56A0[0x30];
    s8 unk_59A0[0x9800];
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

extern s32 D_8079F938;

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

extern s16 D_8079E938[];
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

extern f32 D_8076C9D8;
extern f32 D_8076C9DC;
extern f32 D_8076C9E0;
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

#ifdef IMPORT_DATA
extern s32 D_8076C9E4;
extern s32 D_8079F940;
extern u8 D_xk2_80104CA7;
extern Vtx* D_8079F944;

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
    f32 temp = 1.0f;

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
                arg1 = arg2->unk_0C;
                continue;
            }
        }
    }
    return arg3;
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FDA64.s")
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FE174.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FE8F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FEEEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF12C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF364.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF598.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF630.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700254.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700570.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_807009C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700B18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700CE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700EBC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701094.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701328.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701360.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_807016AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701754.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070183C.s")

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701E08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/D_807735F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701E90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702448.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702974.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070299C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702A68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702A94.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702BC4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702D6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702E0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702F1C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702FF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070304C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80703228.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80703234.s")
