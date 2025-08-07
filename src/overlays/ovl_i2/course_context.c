#include "sys.h"
#include "fzx_course.h"
#include "macros.h"

//! @bug gCourseCtx is treated as though it is size 0xC830 which overlaps with D_800CF950
CourseBuffer gCourseCtx = {
    { CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 } },
    { 0 }
};

CourseData D_800CF950 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};
CourseData D_i2_800D0130 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};

CourseData D_800D0910 = {
    CREATOR_NINTENDO, 0, 0, 0, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }, { 0 }
};

char gEditCupTrackNames[6 * 4][9] = { 0 };

s32 D_800D11C8[] = { 1, 1, 1, 1, 4, 0 };

s32 gLivesChangeCounter = 0;
s32 gPreviousLivesCount = 0;
