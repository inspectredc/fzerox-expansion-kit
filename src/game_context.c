#include "global.h"
#include "fzx_racer.h"

CourseInfo gCourseInfos[COURSE_MAX]; // 0x3480
SegmentChunk gSegmentChunks[0x301];  // 0x12060
CourseSegment D_802D0620[64];        // 0x2900
Racer gRacers[TOTAL_RACER_COUNT];    // 0x6DB0
