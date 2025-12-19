#include "leo/leo_internal.h"

s32 (*gLeoReadWriteFunc)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);
s32 (*gLeoSeekFunc)(LEOCmd*, u32, OSMesgQueue*);
s32 (*gLeoSpdlMotorFunc)(LEOCmd*, u8, OSMesgQueue*);
s32 (*gLeoReadDiskIDFunc)(LEOCmd*, LEODiskID*, OSMesgQueue*);
s32 (*gLeoReadRTCFunc)(LEOCmd*, OSMesgQueue*);
s32 (*gLeoSetRTCFunc)(LEOCmd*, LEODiskTime*, OSMesgQueue*);
s32 (*gLeoModeSelectAsyncFunc)(LEOCmd*, u32, u32, OSMesgQueue*);
s32 (*gLeoRezeroFunc)(LEOCmd*, OSMesgQueue*);

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
