#include "global.h"
#include "fzx_course.h"
#include "fzx_save.h"

//! @bug (gCourseCtx.saveBuffer + 3 * sizeof(GhostSave)) starts to read into D_800CF950 which is used as CourseData elsewhere
extern char D_i2_800BF030[]; // = "GHOST00";
extern char D_i2_800D1018[][9];
extern OSMesgQueue D_8079F998;

void func_i2_800A9CE0(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;
    SaveCourseRecords* courseRecords = (SaveCourseRecords*)(gCourseCtx.saveBuffer + 3 * sizeof(GhostSave));

    PRINTF("Load Ghost Info\n");
    PRINTF("Load Ghost Info2\n");
    PRINTF("idCourse info %d\n");
    PRINTF("machine No %d\n");

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) && D_i2_800D1018[courseIndex][0] != '\0') {
        for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
            *ghostRecord = ghostSave->record;
        }
        return;
    }
    func_i2_800AA80C();
    func_807684AC(0xFFFB, D_i2_800BF030, "GOST", gCourseCtx.saveBuffer, offsetof(CourseContext, saveBuffer), 3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
    osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        PRINTF("Ghost Name %s\n");
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record) * 1) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            func_i2_800A7C84(ghostSave);
            func_i2_800A7CB8(courseRecords);
            PRINTF("ghost time %d:%d:%d\n");
            gCourseCtx.courseData.fileName[0] = '\0';
        }
        *ghostRecord = ghostSave->record;
    }
}

void func_i2_800A9ED0(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;
    SaveCourseRecords* courseRecords = (SaveCourseRecords*)(gCourseCtx.saveBuffer + 3 * sizeof(GhostSave));
    
    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record) * 1) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            func_i2_800A7C84(ghostSave);
            func_i2_800A7CB8(courseRecords);
            PRINTF("ghost time %d:%d:%d\n");
        }
        *ghostRecord = ghostSave->record;
    }
}

bool func_i2_800A9F98(void) {
    s32 i;
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;
    SaveCourseRecords* courseRecord = (SaveCourseRecords*)(gCourseCtx.saveBuffer + 3 * sizeof(GhostSave));
    
    for (i = 0; i < 3; i++, ghostSave++) {
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record) * 1) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            return true;
        }
    }
    
    if (courseRecord->checksum != Save_CalculateSaveCourseRecordChecksum(courseRecord) * 1) {
        PRINTF("RECORD_DATA_BROKEN\n");
        return true;
    }
    return false;
}

void func_i2_800AA024(s32 courseIndex, s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;
    
    PRINTF("Load Ghost Data\n");
    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) && D_i2_800D1018[courseIndex][0] != '\0') {
        *ghostData = ghostSave[ghostIndex].data;
        return;
    }
    func_i2_800AA80C();
    func_807684AC(0xFFFB, D_i2_800BF030, "GOST", gCourseCtx.saveBuffer, offsetof(CourseContext, saveBuffer), 3 * sizeof(GhostSave));
    osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
    *ghostData = ghostSave[ghostIndex].data;
}

void func_i2_800AA1C0(s32 courseIndex, s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;

    *ghostData = ghostSave[ghostIndex].data;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA220.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA368.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA520.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA694.s")

void func_i2_800AA80C(void) {
    GhostSave* ghostSave = (GhostSave*)gCourseCtx.saveBuffer;

    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
}

SaveCourseRecords* func_i2_800AA84C(void) {
    return (SaveCourseRecords*)(gCourseCtx.saveBuffer + 3 * sizeof(GhostSave));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA858.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AA864.s")

void func_i2_800AA994(void) {
    s32 courseIndex;
    s32 var_s1;

    for (courseIndex = 0; courseIndex < COURSE_EDIT_1; courseIndex++) {
        if (courseIndex >= COURSE_EDIT_1) {
            var_s1 = COURSE_EDIT_1;
        } else {
            var_s1 = courseIndex;
        }
        func_80701E90(courseIndex);
        gCourseInfos[courseIndex].encodedCourseIndex = (Course_CalculateChecksum() << 5) | var_s1;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAA14.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAA64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAAC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/10B620/func_i2_800AAB0C.s")
