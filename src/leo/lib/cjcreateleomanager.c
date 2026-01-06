#include "libultra/ultra64.h"
#include "libc/stdbool.h"
#include "leo/leo_internal.h"
#include "PR/os_internal_exception.h"

s32 LeoCJCreateLeoManager(OSPri comPri, OSPri intPri, OSMesg* cmdBuf, s32 cmdMsgCnt) {
    OSPiHandle* driveRomHandle;
    OSPiHandle* leoDiskHandle;
    volatile LEOCmdInquiry cmdBlockInq;
    volatile LEOCmd cmdBlockID;
    LEODiskID thisID;
    u32 stat;
    u32 status;
    volatile s32 dummy;
    volatile s32 dummy2;

    if (__leoActive) {
        return LEO_ERROR_GOOD;
    }

    if (!LeoDriveExist()) {
        return LEO_ERROR_DEVICE_COMMUNICATION_FAILURE;
    }

    leoDiskHandle = osLeoDiskInit();
    driveRomHandle = osDriveRomInit();
    __leoActive = true;

    __osSetHWIntrRoutine(1, __osLeoInterrupt, leoDiskStack + sizeof(leoDiskStack) - 16);
    leoInitialize(comPri, intPri, cmdBuf, cmdMsgCnt);

    if (osResetType == 1) {
        __leoSetReset();
    }

    cmdBlockInq.header.command = 2;
    cmdBlockInq.header.reserve1 = 0;
    cmdBlockInq.header.control = 0;
    cmdBlockInq.header.reserve3 = 0;
    leoCommand((void*) &cmdBlockInq);

    dummy = (u32) &cmdBlockInq & 0xFFFFFF;
    while (dummy > 0) {
        dummy -= ((u32) __leoSetReset & 0xFFFFFF) | 0x403DF4;
    }

    while (cmdBlockInq.header.status == LEO_STATUS_BUSY) {}

    if (cmdBlockInq.header.status != 0) {
        return cmdBlockInq.header.sense;
    }

    __leoVersion.driver = cmdBlockInq.version;
    __leoVersion.drive = 6;
    __leoVersion.deviceType = cmdBlockInq.dev_type;
    __leoVersion.ndevices = cmdBlockInq.dev_num;

    if ((__leoVersion.driver & 0xF) == 4) {
        LEO_country_code = LEO_COUNTRY_NONE;
    } else if (((__leoVersion.driver & 0xF) == 3) || ((__leoVersion.driver & 0xF) == 1)) {

        osEPiReadIo(driveRomHandle, 0x9FF00, &status);
        status = ((status & 0xFF000000) >> 0x18);
        dummy2 = 0x3ED98F23;
        if (status != 0xC3) {
            while (true) {}
        }

        dummy2 *= status;
        dummy2 -= (u32) &cmdBlockInq;
        LEO_country_code = LEO_COUNTRY_JPN;
    } else {
        while (true) {}
    }

    return LEO_ERROR_GOOD;
}
