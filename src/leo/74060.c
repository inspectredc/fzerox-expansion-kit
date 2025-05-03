#include "leo/leo_internal.h"

void func_80766860(void) {
    gLeoReadWriteFunc = LeoReadWrite;
    gLeoSeekFunc = LeoSeek;
    gLeoSpdlMotorFunc = LeoSpdlMotor;
    gLeoReadDiskIDFunc = LeoReadDiskID;
    gLeoReadRTCFunc = LeoReadRTC;
    gLeoSetRTCFunc = LeoSetRTC;
    gLeoModeSelectAsyncFunc = LeoModeSelectAsync;
    gLeoRezeroFunc = LeoRezero;
    return;
}
