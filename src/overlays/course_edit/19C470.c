#include "global.h"
#include "leo/leo_functions.h"
#include "fzx_course.h"

u8 D_xk2_800F7400 = 255;
s32 D_xk2_800F7404 = 0;
CourseContext D_xk2_800F7408 = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { 0 },
    { 0 }
};

void func_xk2_800EA9B0(s8* arg0, s8* arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
    arg0[3] = arg1[3];
    arg0[4] = arg1[4];
}

extern s32 D_80794CD4;

void func_xk2_800EA9DC(s32 arg0) {
    if (D_80794CD4 < 0x2A) {
        PRINTF("%s DEVICE COMMUNICATION FAILURE\n");
        return;
    }
    // TODO: Figure out order of PRINTFs
    switch (D_80794CD4) {
        case 0xF0:
            PRINTF("%s MEDIA_NOT_INIT\n");
            break;
        case 0xF1:
            PRINTF("%s AREA_LACKED\n");
            break;
        case 0xF2:
            PRINTF("%s NOT_FOUND\n");
            break;
        case 0xF3:
            PRINTF("%s DISK_DAMAGED\n");
            break;
        case 0xF4:
            PRINTF("%s ARGUMENT_ILLEGAL\n");
            break;
        case 0xF5:
            PRINTF("%s DISKID_ILLEGAL\n");
            break;
        case 0xF6:
            PRINTF("%s READ_ONLY_MEDIA\n");
            break;
        case 0xF7:
            PRINTF("%s MANAGER_NOT_CREATED\n");
            break;
        default:
            PRINTF("%s UNKNOWN ERROR -> 0x%X\n");
            break;
    }
    // TODO: move to more appropriate place
    PRINTF("FILE OVER\n");
    PRINTF("saving checksum is %d\n");
    PRINTF("file_access_mode %d\n");
}

extern u8 D_80030060[];
extern u8 D_8003006C[];
extern s32 D_80119880;
extern unk_8003A5D8 D_xk1_8003A598;
extern s32 D_xk2_80104378;
extern unk_800D6CA0 D_800D6CA0;
extern s32 D_xk1_80032C20;
extern unk_807B3C20 D_807B3C20;

s32 func_xk2_800EAA1C(u8* arg0) {
    SaveCourseRecords* courseRecords = &COURSE_CONTEXT()->saveCourseRecord;
    GhostSave* ghostSave;
    s32 i;
    u32 sp18;

    if ((func_xk1_8002BFA4() > 100) && (D_80119880 == -1)) {
        D_xk2_80104378 = 6;
        D_xk1_80032C20 = 0;
        D_800D6CA0.unk_08 = 0x10;
        return -1;
    }
    COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
    COURSE_CONTEXT()->courseData.controlPointCount = D_807B3C20.unk_2900;

    for (i = 0; i < D_807B3C20.unk_2900; i++) {
        COURSE_CONTEXT()->courseData.controlPoint[i].pos = D_807B3C20.unk_0000[i].pos;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusLeft = D_807B3C20.unk_0000[i].radiusLeft;
        COURSE_CONTEXT()->courseData.controlPoint[i].radiusRight = D_807B3C20.unk_0000[i].radiusRight;
        COURSE_CONTEXT()->courseData.controlPoint[i].trackSegmentInfo = D_807B3C20.unk_0000[i].trackSegmentInfo;
    }
    sp18 = Course_CalculateChecksum();
    ghostSave = COURSE_CONTEXT()->ghostSave;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    ghostSave++;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    ghostSave++;
    ghostSave->record.encodedCourseIndex = 0;
    ghostSave->record.raceTime = MAX_TIMER;
    Save_InitCourseRecord(courseRecords, true);
    COURSE_CONTEXT()->courseData.checksum = sp18;
    if ((D_80119880 == -1) || (D_80119880 == 1)) {
        if (COURSE_CONTEXT()->courseData.flag != 0) {
            mfsStrCpy(D_xk1_8003A598.unk_00, arg0);
            func_xk2_800EA9B0(D_xk1_8003A598.unk_1D, "CRSD");
            D_800D6CA0.unk_08 = 0x14;
        } else {
            mfsStrCpy(D_xk1_8003A598.unk_00, arg0);
            func_xk2_800EA9B0(D_xk1_8003A598.unk_1D, "CRSE");
            D_800D6CA0.unk_08 = 0x14;
        }
    }
    mfsStrCpy(D_80030060, arg0);
    mfsStrCpy(D_8003006C, arg0);
    return 0;
}

s32 func_xk2_800EAC28(u8* arg0) {
    if (D_xk2_800F7408.courseData.flag != 0) {
        mfsStrCpy(&D_xk1_8003A598, arg0);
        func_xk2_800EA9B0(D_xk1_8003A598.unk_1D, "CRSD");
        D_800D6CA0.unk_08 = 0x14;
    } else {
        mfsStrCpy(&D_xk1_8003A598, arg0);
        func_xk2_800EA9B0(D_xk1_8003A598.unk_1D, "CRSE");
        D_800D6CA0.unk_08 = 0x14;
    }
    PRINTF("COURSE DATA CHECK SUM ERROR 0x%x(DATA WAS BROKEN 0x%x)\n");
    PRINTF("CHECK SUM IS OK 0x%x\n");
    PRINTF("UNPACK BEFORE\n");
    PRINTF("UNPACK AFTER\n");
    PRINTF("LOAD TYPE %c%c%c%c\n");
    PRINTF("WAIT GET FILE NAMES\n");
    return 0;
}

extern s32 D_80119880;
extern volatile u8 D_80794E10;
extern s32 D_xk2_800F7060;
extern s32 D_xk2_800F7064;
extern CourseSegment D_802D0620[];
extern s32 D_xk1_8003066C;
extern s32 D_xk1_80030670;
extern s32 D_xk1_80030674;
extern s32 D_xk1_800328B4[];
extern unk_80026914 D_xk1_80031140;
extern s32 D_xk2_800F7040;

void func_xk2_800EACB0(void) {
    CourseInfo* courseInfo;
    s32 i;

    D_80794E10 = 0;
    D_xk2_800F7400 = 0xFF;
    if (D_80119880 == 7) {
        return;
    }
    if (D_80119880 == 0) {
        *COURSE_CONTEXT() = D_xk2_800F7408;
    }
    if ((Course_CalculateChecksum() != COURSE_CONTEXT()->courseData.checksum) ||
        (COURSE_CONTEXT()->courseData.creatorId != CREATOR_NINTENDO) ||
        ((s8) (COURSE_CONTEXT()->courseData.fileName[0x16]) >= 0xE)) {
        func_xk2_800EE664(0xA);
        func_xk2_800EF8B0();
        return;
    }

    D_xk1_80031140.unk_08 = D_xk1_8003066C = COURSE_CONTEXT()->courseData.venue;
    D_xk1_80030670 = COURSE_CONTEXT()->courseData.skybox;
    D_xk1_80030674 = D_xk1_800328B4[(s8) (COURSE_CONTEXT()->courseData.fileName[0x16])];
    func_80709A38(COURSE_CONTEXT()->courseData.venue);
    func_80702FF4(D_xk1_8003066C);
    func_80702BC4(0);

    courseInfo = &gCourseInfos[0];
    D_807B3C20.unk_2900 = courseInfo->segmentCount;
    for (i = 0; i < courseInfo->segmentCount; i++) {
        D_807B3C20.unk_0000[i] = D_802D0620[i];
        D_807B3C20.unk_0000[i].segmentIndex = i;
        D_807B3C20.unk_0000[i].next = &D_807B3C20.unk_0000[i + 1];
        D_807B3C20.unk_0000[i].prev = &D_807B3C20.unk_0000[i - 1];
    }

    D_800D6CA0.unk_0C = 0;
    D_807B3C20.unk_0000[0].prev = &D_807B3C20.unk_0000[courseInfo->segmentCount - 1];
    D_807B3C20.unk_0000[courseInfo->segmentCount - 1].next = &D_807B3C20.unk_0000[0];
    func_xk2_800DC3F8();
    func_xk2_800EF78C();
    func_xk2_800F0FE8();
    D_xk2_800F7040 = 3;
    D_xk2_800F7060 = Math_Rand2() % 30;
    D_xk2_800F7064 = Math_Rand2() & 3;
    D_xk2_800F7404 = 1;
}

extern unk_8003A5D8 D_xk1_8003A5D8[];
extern s32 D_xk2_80119884;

s32 func_xk2_800EAF24(unk_8003A5D8* arg0) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(0xFFFB, arg0->unk_00, &D_xk1_8003A5D8[D_xk2_80119884].unk_1D, &D_xk2_800F7408, 0xC830);
    mfsStrCpy(&D_80030060, arg0);
    return 0;
}

s32 func_xk2_800EAFA8(unk_8003A5D8* arg0) {
    D_80794E10 = 0;
    D_xk2_800F7400 = 0;
    func_80768574(0xFFFB, arg0->unk_00, &D_xk1_8003A5D8[D_xk2_80119884].unk_1D, &D_xk2_800F7408, 0xC830);
    return 0;
}

extern s32 D_xk1_80030610;
extern s32 D_xk1_80030678;
extern s32 D_xk1_80032BF8;
extern s32 D_xk2_800F684C;
extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;

void func_xk2_800EB018(void) {
    s32 pad;
    u8 sp20[9] = { 0x20, 0x8E, 0xCC, 0xAB, 0xD9, 0xC4, 0x00, 0x00, 0x00 };

    if ((D_xk1_80032BF8 != 0) && (D_xk2_800F7400 == 1)) {
        D_xk1_80032BF8 = 0;
        D_xk2_800F7400 = 0xFF;
        if ((func_xk1_8002BFA4() == 0) && (D_80119880 != 1)) {
            D_xk1_80030610 = -1;
            D_xk1_80030678 = -1;
            D_800D6CA0.unk_08 = 0;
            return;
        }
        D_800D6CA0.unk_08 = 3;
        switch (D_80119880) {
            case 0:
                mfsStrCpy(D_xk1_8003A5D8[0].unk_00, "OFFICIAL");
                mfsStrCpy(D_xk1_8003A5D8[0].unk_1D, "CRSD");
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 1:
                mfsStrCpy(D_xk1_8003A5D8[0].unk_00, "NEWFILE");
                mfsStrCpy(D_xk1_8003A5D8[0].unk_1D, "CRSD");
                PRINTF("EDIT_MODE_COURSE 08\n");
                PRINTF("EDIT_MODE_COURSE 09\n");
                PRINTF("EDIT_MODE_FILE_LOADING 0\n");
                PRINTF("EDIT_MODE_COURSE 11\n");
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 5:
                func_xk1_8002B150(0xD8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            case 7:
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                D_xk2_800F684C = 0;
                break;
            default:
                D_xk2_800F684C = 0;
                func_xk1_8002B150(0xA8, 0x68, &D_xk1_8003A550, &D_xk1_8003A554);
                break;
        }
    }
}

void func_xk2_800EB20C(void) {
    s32 i;

    for (i = 0; i < 100; i++) {
        D_xk1_8003A5D8[i].unk_1C = '0';
        D_xk1_8003A5D8[i].unk_1D[4] = '0';
    }
}

void func_xk2_800EB250(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        COURSE_CONTEXT()->courseData.pit[i] = PIT_NONE;
        COURSE_CONTEXT()->courseData.dash[i] = DASH_NONE;
        COURSE_CONTEXT()->courseData.dirt[i] = DIRT_NONE;
        COURSE_CONTEXT()->courseData.ice[i] = ICE_NONE;
        COURSE_CONTEXT()->courseData.jump[i] = JUMP_NONE;
        COURSE_CONTEXT()->courseData.landmine[i] = LANDMINE_NONE;
        COURSE_CONTEXT()->courseData.gate[i] = GATE_NONE;
        COURSE_CONTEXT()->courseData.building[i] = BUILDING_NONE;
        COURSE_CONTEXT()->courseData.sign[i] = SIGN_NONE;
    }
}

void func_xk2_800EB304(s32 arg0, s32 arg1) {
    if (arg1 & 0x2000) {
        func_807689BC(0xFFFB, arg0, &D_xk1_8003A5D8[D_xk2_80119884].unk_1D, 0, 0x2000, 1);
    } else {
        func_807689BC(0xFFFB, arg0, &D_xk1_8003A5D8[D_xk2_80119884].unk_1D, 0x2000, 0, 1);
    }
}

void func_xk2_800EB3B4(void) {
    if (D_800D6CA0.unk_08 != 3) {
        return;
    }
    func_xk1_8002BD34();
    D_800D6CA0.unk_08 = 0;
    D_xk1_80030610 = -1;
    D_xk1_80030678 = -1;
}

extern s32 D_xk1_80030610;
extern u8 D_xk1_8003A560[];
extern s32 D_xk2_80103F10;
extern s32 D_xk2_80104378;
extern s32 D_xk2_80119884;
extern u8 gEditCupTrackNames[][9];

void func_xk2_800EB400(void) {
    s32 courseIndex;
    unk_8003A5D8* temp_v1;

    if (D_800D6CA0.unk_08 != 3) {
        return;
    }
    func_8074122C(0x24);
    courseIndex = func_xk1_8002BD14();
    D_xk2_80119884 = courseIndex;
    temp_v1 = &D_xk1_8003A5D8[D_xk2_80119884];
    switch (D_80119880) {
        case 6:
            if (D_807B3C20.unk_2900 == 0) {
                func_xk2_800F5C50();
                if (courseIndex >= COURSE_EDIT_1) {
                    func_80701E90(courseIndex + 6);
                } else {
                    func_80701E90(courseIndex);
                }
                D_80030060[0] = 0;
                func_xk2_800EACB0();
                D_xk1_80030610 = -1;
                D_800D6CA0.unk_08 = 0;
                D_xk2_800F7040 = 3;
                D_xk2_800F7060 = Math_Rand2() % 30;
                D_xk2_800F7064 = Math_Rand2() % 4;
            } else {
                D_xk2_80104378 = 1;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 8:
            func_80701E90(courseIndex);
            func_xk2_800EACB0();
            D_xk1_80030610 = -1;
            D_800D6CA0.unk_08 = 0x30;
            D_80119880 = 7;
            D_xk2_800F7040 = 3;
            D_xk2_800F7060 = Math_Rand2() % 30;
            D_xk2_800F7064 = Math_Rand2() % 4;
            break;
        case 0:
            if (courseIndex == 0) {
                func_xk1_8002D16C();
                D_80119880 = 6;
            } else if (D_807B3C20.unk_2900 == 0) {
                func_xk2_800F5C50();
                func_xk2_800EAF24(&D_xk1_8003A5D8[courseIndex]);
                D_xk1_80030610 = -1;
                D_800D6CA0.unk_08 = 0x13;
            } else {
                D_xk2_80104378 = 1;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 1:
            if (courseIndex == 0) {
                D_80119880 = -1;
                if ((func_xk1_8002BFA4() - 1) >= 100) {
                    D_xk2_80104378 = 6;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                } else {
                    func_xk1_800294AC();
                    func_xk1_800294EC(func_xk1_8002AC24);
                    D_xk1_8003A550 = 0x58;
                    D_xk1_8003A554 = 0x68;
                    D_800D6CA0.unk_08 = 2;
                }
            } else {
                if (D_xk1_8003A5D8[courseIndex].unk_10 & 0x2000) {
                    D_xk2_80104378 = 8;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                } else {
                    D_xk2_80104378 = 2;
                    D_xk1_80032C20 = 0;
                    D_800D6CA0.unk_08 = 0x10;
                }
            }
            break;
        case 3:

            D_xk1_8003A598 = *temp_v1;
            if (D_xk1_8003A5D8[courseIndex].unk_10 & 0x2000) {
                D_xk2_80104378 = 8;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            } else {
                func_xk1_800294AC();
                func_xk1_800294EC(func_xk1_8002AC24);
                D_xk1_8003A550 = 0x58;
                D_xk1_8003A554 = 0x68;
                D_800D6CA0.unk_08 = 2;
            }
            break;
        case 2:
            if (D_xk1_8003A5D8[courseIndex].unk_10 & 0x2000) {
                D_xk2_80104378 = 8;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            } else {
                D_xk2_80104378 = 3;
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 0x10;
            }
            break;
        case 4:
            func_xk2_800EB304(D_xk1_8003A5D8[courseIndex].unk_00, D_xk1_8003A5D8[courseIndex].unk_10);
            D_xk1_80030610 = -1;
            D_800D6CA0.unk_08 = 0;
            break;
        case 5:
            if (D_xk1_8003A5D8[D_xk2_80119884].unk_1D[3] == 'E') {
                func_8074122C(0x20);
                func_xk1_8002D290();
                break;
            }
            mfsStrCpy(gEditCupTrackNames[D_xk2_80103F10], D_xk1_8003A5D8[courseIndex].unk_00);
            func_xk2_800EC110();
            D_800D6CA0.unk_08 = 0x37;
            break;
        case 7:
            func_xk1_800294AC();
            mfsStrCpy(D_xk1_8003A560, D_xk1_8003A5D8[courseIndex].unk_00);
            func_xk2_800EAFA8(D_xk1_8003A5D8[courseIndex].unk_00);
            D_xk1_80030610 = -1;
            D_800D6CA0.unk_08 = 0x33;
            break;
        default:
            break;
    }
}

void func_xk2_800EB938(u16 arg0, u8* arg1, u8* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    if (arg2[3] == 'D') {
        SLMFSDeleteFile(arg0, arg1, "CRSE", arg7);
    } else {
        SLMFSDeleteFile(arg0, arg1, "CRSD", arg7);
    }
    SLMFSSave(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
