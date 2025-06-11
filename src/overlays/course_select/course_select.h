#ifndef OVL_I5_H
#define OVL_I5_H

#include "libultra/ultra64.h"

void func_i5_800778E8(void);

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

#endif // OVL_I5_H
