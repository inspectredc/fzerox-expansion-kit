#include "global.h"
#include "leo/unk_leo.h"

extern LEODiskID D_8076CB50;

#define LEO_DISK_TIME(yearhi, yearlo, month, day, hour, minute, second) \
    { 0, 0x##yearhi, 0x##yearlo, 0x##month, 0x##day, 0x##hour, 0x##minute, 0x##second }

void func_8070F0F0(void) {
    // 1999-12-31 23:59:59
    LEODiskTime diskTime = LEO_DISK_TIME(19, 99, 12, 31, 23, 59, 59);

    func_80762330(&diskTime);
    Mfs_SetGameCode("01", "EFZJ");
    SLMFSCreateManager(LEO_MANAGER_REGION_NONE);
    func_8070481C();
    SLLeoReadDiskID(&D_8076CB50);
    SLLeoModeSelectAsync(0, 0);
}
