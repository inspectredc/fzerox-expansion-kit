#ifndef COURSE_SELECT_H
#define COURSE_SELECT_H

#include "libultra/ultra64.h"

void func_i5_80077080(void);
void func_i5_800770B4(void);
Gfx* func_i5_800774F0(Gfx* gfx);
void func_i5_800778E8(void);
void func_i5_80077B8C(s32 left);
void CourseModel_Init(s32 cupType);

extern Vp D_i5_8007AFB0[2][6];
extern s32 gCourseModelCupType;
extern s32 D_i5_8007B074;
extern s32 gCourseModelCupCourseNo;
extern s8 gCupSelectOption;

typedef enum CourseSelectState {
    /*  0 */ COURSE_SELECT_CUP_SELECT,
    /*  1 */ COURSE_SELECT_EXIT_RECORDS,
    /*  2 */ COURSE_SELECT_CHOOSE_COURSE,
    /*  3 */ COURSE_SELECT_AWAIT_OK,
    /*  4 */ COURSE_SELECT_CONTINUE,
    /*  5 */ COURSE_SELECT_START_EXIT,
    /*  6 */ COURSE_SELECT_EXIT,
    /* 10 */ COURSE_SELECT_NEXT_COURSE_AWAIT_INPUT = 10,
    /* 11 */ COURSE_SELECT_NEXT_COURSE_CONTINUE,
} CourseSelectState;

#endif // COURSE_SELECT_H
