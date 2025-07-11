#include "global.h"
#include "fzx_course.h"
#include "fzx_save.h"

char D_i2_800BF030[] = "GHOST00";

extern OSMesgQueue D_8079F998;
extern u8 gEditCupTrackNames[][9];

void func_i2_800A9CE0(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    PRINTF("Load Ghost Info\n");
    PRINTF("Load Ghost Info2\n");
    PRINTF("idCourse info %d\n");
    PRINTF("machine No %d\n");

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) &&
        gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
        for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
            *ghostRecord = ghostSave->record;
        }
        return;
    }
    func_i2_800AA80C();
    func_807684AC(0xFFFB, D_i2_800BF030, "GOST", COURSE_CONTEXT()->ghostSave, 0x7E0,
                  3 * sizeof(GhostSave) + sizeof(SaveCourseRecords));
    osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        PRINTF("Ghost Name %s\n");
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record) * 1) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            func_i2_800A7C84(&ghostSave->record);
            func_i2_800A7CB8(courseRecords);
            PRINTF("ghost time %d:%d:%d\n");
            COURSE_CONTEXT()->courseData.fileName[0] = '\0';
        }
        *ghostRecord = ghostSave->record;
    }
}

void func_i2_800A9ED0(s32 courseIndex, GhostRecord* ghostRecord) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    for (i = 0; i < 3; i++, ghostRecord++, ghostSave++) {
        if (ghostSave->record.checksum != Save_CalculateGhostRecordChecksum(&ghostSave->record) * 1) {
            PRINTF("GHOST_INFO_DATA_BROKEN\n");
            func_i2_800A7C84(&ghostSave->record);
            func_i2_800A7CB8(courseRecords);
            PRINTF("ghost time %d:%d:%d\n");
        }
        *ghostRecord = ghostSave->record;
    }
}

bool func_i2_800A9F98(void) {
    s32 i;
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;
    SaveCourseRecords* courseRecord = &COURSE_CONTEXT()->saveCourseRecord;

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
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    PRINTF("Load Ghost Data\n");
    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6) &&
        gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
        *ghostData = ghostSave[ghostIndex].data;
        return;
    }
    func_i2_800AA80C();
    func_807684AC(0xFFFB, D_i2_800BF030, "GOST", COURSE_CONTEXT()->ghostSave, 0x7E0, 3 * sizeof(GhostSave));
    osRecvMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
    *ghostData = ghostSave[ghostIndex].data;
}

void func_i2_800AA1C0(s32 courseIndex, s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    *ghostData = ghostSave[ghostIndex].data;
}

extern CourseData D_i2_800D0130;

void func_i2_800AA220(s32 courseIndex, s32 ghostIndex, Ghost* ghost) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave + ghostIndex;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';
    COURSE_CONTEXT()->courseData = D_i2_800D0130;
    func_80707E58();
    if (ghost != NULL) {
        Save_SaveGhostRecord(ghost);
        Save_SaveGhostData(ghost);
    }
    *ghostSave = gSaveContext.ghostSave;

    func_807680EC(0xFFFB, D_i2_800BF030, "GOST", COURSE_CONTEXT(), 0xC830, 0, 0xFF, 1);
}

void func_i2_800AA368(s32 courseIndex, s32 ghostIndex, Ghost* ghost) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave + ghostIndex;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';

    COURSE_CONTEXT()->courseData = D_i2_800D0130;
    if (ghost != NULL) {
        Save_SaveGhostRecord(ghost);
        Save_SaveGhostData(ghost);
    }
    *ghostSave = gSaveContext.ghostSave;
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            func_807680EC(0xFFFB, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD", COURSE_CONTEXT(), 0xC830, 0,
                          0xFF, 1);
            return;
        }
    }
    func_807680EC(0xFFFB, &D_i2_800BF030, "GOST", COURSE_CONTEXT(), 0xC830, 0, 0xFF, 1);
    PRINTF("ERASE DISK GHOST %d\n");
}

void func_i2_800AA520(s32 courseIndex) {
    GhostSave* ghostSave;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';

    ghostSave = COURSE_CONTEXT()->ghostSave;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            COURSE_CONTEXT()->courseData = D_i2_800D0130;
            func_807680EC(0xFFFB, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD", COURSE_CONTEXT(), 0xC830, 0,
                          0xFF, 1);
            return;
        }
    }
    func_807680EC(0xFFFB, D_i2_800BF030, "GOST", COURSE_CONTEXT(), 0xC830, 0, 0xFF, 1);
}

void func_i2_800AA694(s32 courseIndex) {
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';

    func_i2_800A7CB8(courseRecords);
    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            COURSE_CONTEXT()->courseData = D_i2_800D0130;
            func_807680EC(0xFFFB, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD", COURSE_CONTEXT(), 0xC830, 0,
                          0xFF, 1);
            func_i2_800A8CE4(courseRecords, courseIndex);
            return;
        }
    }
    func_807680EC(0xFFFB, D_i2_800BF030, "GOST", COURSE_CONTEXT(), 0xC830, 0, 0xFF, 1);
    func_i2_800A8CE4(courseRecords, courseIndex);
}

void func_i2_800AA80C(void) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
}

SaveCourseRecords* func_i2_800AA84C(void) {
    return &COURSE_CONTEXT()->saveCourseRecord;
}

GhostSave* func_i2_800AA858(void) {
    return COURSE_CONTEXT()->ghostSave;
}

void func_i2_800AA864(s32 courseIndex) {

    COURSE_CONTEXT()->courseData = D_i2_800D0130;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';

    if ((courseIndex >= COURSE_EDIT_1) && (courseIndex <= COURSE_EDIT_6)) {
        if (gEditCupTrackNames[courseIndex - COURSE_EDIT_1][0] != '\0') {
            func_807680EC(0xFFFB, gEditCupTrackNames[courseIndex - COURSE_EDIT_1], "CRSD", COURSE_CONTEXT(), 0xC830, 0,
                          0xFF, 1);
            return;
        }
    }
    func_807680EC(0xFFFB, &D_i2_800BF030, "GOST", COURSE_CONTEXT(), 0xC830, 0, 0xFF, 1);
}

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

        PRINTF("=========================================\n");
        PRINTF("courseID 0x%X -> right data is 0x7B4113D8\n");
        PRINTF("=========================================\n");
        gCourseInfos[courseIndex].encodedCourseIndex = (Course_CalculateChecksum() << 5) | var_s1;
    }
}

void func_i2_800AAA14(s32 ghostIndex, GhostRecord* ghostRecord) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    if (1) {}
    *ghostRecord = ghostSave[ghostIndex].record;
}

void func_i2_800AAA64(s32 ghostIndex, GhostData* ghostData) {
    GhostSave* ghostSave = COURSE_CONTEXT()->ghostSave;

    if (1) {}
    *ghostData = ghostSave[ghostIndex].data;
}

extern u8 D_342[];

void func_i2_800AAAC0(s32 courseIndex) {

    courseIndex -= COURSE_EDIT_6 + 1;
    if (courseIndex < 0) {
        courseIndex = 0;
    }
    func_80703B40(D_342 + courseIndex, COURSE_CONTEXT()->ghostSave, 0xBF40, 0);
}

void func_i2_800AAB0C(s32 courseIndex) {
    GhostSave* ghostSave;

    D_i2_800BF030[5] = (courseIndex / 10) + '0';
    D_i2_800BF030[6] = (courseIndex % 10) + '0';

    PRINTF("STUFF GHOST IS READING BY REAL DISK\n");

    ghostSave = COURSE_CONTEXT()->ghostSave;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    ghostSave++;
    func_i2_800A7C84(&ghostSave->record);
    func_80704050(1);
    PRINTF("ERASE DISK GHOST %d\n");
    SLMFSDeleteFile(0xFFFB, D_i2_800BF030, "GOST", 0);
    func_80704050(0);
}
