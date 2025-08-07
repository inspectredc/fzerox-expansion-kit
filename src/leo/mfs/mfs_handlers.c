#include "leo/leo_internal.h"

void Mfs_SetLeoHandlerFuncs(void) {
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
