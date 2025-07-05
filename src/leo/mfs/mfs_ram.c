#include "leo/unk_leo.h"
#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "libc/stdbool.h"
#include "libc/stddef.h"

extern OSMesg D_80794D08[1];
extern OSMesgQueue D_80794D0C;

void func_8075FE60(void) {
    osCreateMesgQueue(&D_80794D0C, D_80794D08, ARRAY_COUNT(D_80794D08));
}

extern s32 gMfsError;
extern LEODiskID D_80794CE8;

s32 func_8075FE98(void) {
    s32 i = 0;

    LeoResetClear();

    while (true) {
        if (Mfs_ReadDiskId(&D_80794CE8) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch (gMfsError) {
            case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
                gMfsError = 0xF9;
                return -1;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                break;
            default:
                return -1;
        }
    }

    return 0;
}

s32 func_8075FF6C(void) {
    return func_8075FE98();
}

s32 func_8075FF9C(void) {
    s32 i = 0;

    while (true) {
        if (Mfs_ReadDiskId(&D_80794CE8) == 0) {
            break;
        }

        if (++i >= 4) {
            return -1;
        }

        switch (gMfsError) {
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return -1;
        }

        return -1;
    }

    if (bcmp(&leoBootID, &D_80794CE8, sizeof(LEODiskID)) == 0) {
        return 0;
    }

    gMfsError = N64DD_DISKID_ILLEGAL;
    return -1;
}

extern s32 D_80794CC4;
extern s32 D_80794D30;
extern s32 D_80794CD8;
extern char gCompanyCode[2];
extern char gGameCode[4];

s32 Mfs_CreateLeoManager(s32 region, OSMesg* cmdBuf, s32 cmdMsgCount) {
    s32 i = 0;

    D_80794CC4 = 0;
    Mfs_SetLeoHandlerFuncs();

    if ((gCompanyCode[0] == 0) || (gGameCode[0] == 0)) {
        D_80794D30 = 0x107;
        gMfsError = 0x107;
        return -1;
    }

    func_8075FE60();
    func_80760244();
    switch (region) {
        case LEO_MANAGER_REGION_NONE:
            D_80794CD8 = 0xD;
            gMfsError = LeoCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_JP:
            D_80794CD8 = 0xE;
            gMfsError = LeoCJCreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        case LEO_MANAGER_REGION_US:
            D_80794CD8 = 0xE;
            gMfsError = LeoCACreateLeoManager(0x95, 0x96, cmdBuf, cmdMsgCount);
            break;
        default:
            gMfsError = N64DD_ARGUMENT_ILLEGAL;
            return -1;
            break;
    }

    if (gMfsError != LEO_ERROR_GOOD) {
        return -1;
    }

    if (region == LEO_MANAGER_REGION_NONE) {

    } else {
        return func_8075FF6C();
    }

    D_80794D30 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
    return 0;
}

extern MfsRamArea gMfsRamArea;

void func_80760244(void) {
    gMfsRamArea.id.diskId[0] = '\0';
}

extern OSMesgQueue D_80794D0C;

s32 Mfs_ReadDiskId(LEODiskID* diskId) {
    LEOCmd sp1C;

    D_80794CD8 = 8;
    osInvalDCache(diskId, 4);
    if (gLeoReadDiskIDFunc(&sp1C, diskId, &D_80794D0C) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_80762390();
}

void func_807602E4(void) {
    LeoGetKAdr(0);
    LeoGetAAdr(0, NULL, NULL, NULL);
}

extern s32 gDirectoryEntryCount;
extern LEOCapacity gRamAreaCapacity;

s32 func_80760320(void) {
    s32 sp1C;

    gMfsError = LeoReadCapacity(&gRamAreaCapacity, OS_WRITE);
    if (gMfsError != LEO_ERROR_GOOD) {
        return -1;
    }
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &sp1C);
    gDirectoryEntryCount = (sp1C - (s32) offsetof(MfsRamArea, directoryEntry)) / (s32) sizeof(MfsRamDirectoryEntry);
    return 0;
}

extern u16 gWorkingDirectory;

s32 func_807603A8(void) {
    if (Mfs_ReadDiskId(&D_80794CE8) != 0) {
        return -1;
    }
    if (D_80794D30 == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (func_80760A84() < 0) {
        return -1;
    }
    if (func_80760320() < 0) {
        return -1;
    }
    if (gRamAreaCapacity.nbytes == 0) {
        D_80794D30 = N64DD_READ_ONLY_MEDIA;
        gMfsError = N64DD_READ_ONLY_MEDIA;
        return -1;
    }
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    func_80760244();
    D_80794D30 = LEO_ERROR_GOOD;
    return 0;
}

// mfsRamGetDiskType
s32 Mfs_RamGetDiskType(void) {
    if (gRamAreaCapacity.startLBA == 1418) {
        return 0;
    }
    if (gRamAreaCapacity.startLBA == 1966) {
        return 1;
    }
    if (gRamAreaCapacity.startLBA == 2514) {
        return 2;
    }
    if (gRamAreaCapacity.startLBA == 3062) {
        return 3;
    }
    if (gRamAreaCapacity.startLBA == 3610) {
        return 4;
    }
    if (gRamAreaCapacity.startLBA == 4088) {
        return 5;
    }
    return 6;
}

s32 func_8076055C(void) {
    LEOStatus status;

    gMfsError = LEO_ERROR_GOOD;
    D_80794CD8 = 15;
    gMfsError = LeoTestUnitReady(&status);
    if (!(status & LEO_TEST_UNIT_MR)) {
        if (gMfsError == LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED) {}
        return 1;
    }
    if (gMfsError == LEO_SENSE_MEDIUM_NOT_PRESENT) {
        return 0;
    }
    return -1;
}

extern char D_80794D34[]; // "64dd-Multi"

s32 Mfs_InitRamArea(s32 arg0, u8 attr, u8* volumeName) {
    LEODiskTime formatDate;
    s32 i;
    bool sp20;
    s32 ramAreaSize;

    sp20 = false;
    if (arg0 == 1) {
        sp20 = true;
    } else if (arg0 == 2) {
        sp20 = false;
    } else {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }

    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    if (func_80760C2C() < 0) {
        return -1;
    }
    if (func_8076055C() <= 0) {
        return -1;
    }
    if (!sp20 && (func_80760C6C() < 0)) {
        sp20 = true;
    }
    for (i = 0; i < (s32) sizeof(MfsRamId); i++) {
        ((u8*) &gMfsRamArea.id)[i] = 0;
    }
    mfsStrnCpy(gMfsRamArea.id.diskId, D_80794D34, 10);
    gMfsRamArea.id.fsType[0] = '0';
    gMfsRamArea.id.fsType[1] = '1';
    gMfsRamArea.id.fsVersion[0] = '0';
    gMfsRamArea.id.fsVersion[1] = '1';
    gMfsRamArea.id.attr = attr;
    gMfsRamArea.id.diskType = Mfs_RamGetDiskType();
    if (volumeName != NULL) {
        mfsStrnCpy(&gMfsRamArea.id.volumeName, volumeName, 20);
    }
    gMfsRamArea.id.renewalCounter = 0;
    Mfs_ReadRtc(&formatDate);
    Mfs_LEODiskTimeToMfsTime(&formatDate, &gMfsRamArea.id.formatDate);
    if (sp20) {
        bzero(gMfsRamArea.fileAllocationTable, sizeof(gMfsRamArea.fileAllocationTable));
    } else {
        for (i = 0; i < ARRAY_COUNT(gMfsRamArea.fileAllocationTable); i++) {
            if (gMfsRamArea.fileAllocationTable[i] != MFS_FAT_OUT_OF_MANAGEMENT) {
                gMfsRamArea.fileAllocationTable[i] = MFS_FAT_UNUSED;
            }
        }
    }
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &ramAreaSize);
    bzero(gMfsRamArea.directoryEntry, ramAreaSize - offsetof(MfsRamArea, directoryEntry));
    Mfs_CreateRootDirectory(false);
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_80794D30 = LEO_ERROR_GOOD;
    if (Mfs_BackupRamArea() < 0) {
        func_80760244();
        return -1;
    } else {
        return 0;
    }
}

extern s32 D_80794CDC;

s32 Mfs_BackupRamArea(void) {
    D_80794CDC = 0;
    if (Mfs_ValidateRamVolume() < 0) {
        return -1;
    }
    gMfsRamArea.id.renewalCounter++;
    Mfs_CalculateVolumeChecksum();
    D_80794CDC = 2;
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    D_80794CDC = 3;
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA + 3, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 Mfs_ReadRamArea(void) {
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    if (Mfs_CheckChecksum() < 0) {
        D_80794D30 = 0x10A;
        gMfsError = 0x10A;
        return -1;
    }
    return 0;
}

s32 Mfs_ValidateRamVolume(void) {
    s32 i;
    s32 j = 0;

    gMfsError = LEO_ERROR_GOOD;

    for (i = 0; i < 10; i++) {
        if (gMfsRamArea.id.diskId[i] != D_80794D34[i]) {
            j++;
        }
    }

    if (j != 0) {
        gMfsError = N64DD_MEDIA_NOT_INIT;
        return -1;
    }
    return 0;
}

s32 func_80760A84(void) {
    if (D_80794CE8.ramUsage != 1) {
        gMfsError = 0x111;
        return -1;
    }
}

s32 func_80760ABC(void) {
    s32 i = 0;

    gMfsError = 0;
    if (func_80760C2C() < 0) {
        return -1;
    }

    while (true) {
        if (((i++ < 5) ^ 1)) {
            return -1;
        }

        if (Mfs_ReadRamArea() == 0) {
            break;
        }

        if (gMfsError == LEO_ERROR_GOOD) {
            break;
        }

        if (gMfsError == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
            if (Mfs_ReadDiskId(&D_80794CE8) < 0) {
                return -1;
            }
        } else {
            if (gMfsError == LEO_ERROR_UNRECOVERED_READ_ERROR) {
                gMfsError = N64DD_MEDIA_NOT_INIT;
                return 0;
            }
            if (gMfsError == 0x10A) {
                gMfsError = N64DD_MEDIA_NOT_INIT;
                return 0;
            }
            return -1;
        }
    }

    osWritebackDCache(gMfsRamArea.id.diskId, 10);

    if (Mfs_ValidateRamVolume() == 0) {
        return 1;
    }

    gMfsError = N64DD_MEDIA_NOT_INIT;

    return 0;
}

s32 func_80760C2C(void) {
    if (D_80794D30 != LEO_ERROR_GOOD) {
        gMfsError = D_80794D30;
        return -1;
    }
    return 0;
}

s32 func_80760C6C(void) {
    s32 err;

    gMfsError = LEO_ERROR_GOOD;
    if (func_80760C2C() < 0) {
        return -1;
    }
    err = func_8076055C();
    if (err <= 0) {
        return -1;
    }

    if (gMfsError == LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED) {
        func_80760244();
        D_80794D30 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
        return -1;
    } else {
        osWritebackDCache(&gMfsRamArea, sizeof(MfsRamArea));
        if (Mfs_ValidateRamVolume() == 0) {
            return 0;
        }
        if (gMfsError == N64DD_MEDIA_NOT_INIT) {
            if (Mfs_ReadRamArea() < 0) {
                return -1;
            }
            if (Mfs_ValidateRamVolume() == 0) {
                return 0;
            }
        }
    }

    return -1;
}

s32 Mfs_RamGetFreeSize(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_80760C6C() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 6; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
        if (gMfsRamArea.fileAllocationTable[i] != MFS_FAT_UNUSED) {
            continue;
        }
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

extern u16 gFileAllocationTable[];

s32 Mfs_WorkGetFreeSize(void) {
    s32 sp24;
    s32 sp20;
    s32 i;

    if (func_80760C6C() < 0) {
        return -1;
    }
    sp20 = 0;

    for (i = 6; i <= (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
        if (gFileAllocationTable[i] != MFS_FAT_UNUSED) {
            continue;
        }
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &sp24);
        sp20 += sp24;
    }

    return sp20;
}

void Mfs_SetGameCode(char* companyCode, char* gameCode) {
    if (companyCode != 0) {
        mfsStrnCpy(gCompanyCode, companyCode, 2);
    }
    if (gameCode != 0) {
        mfsStrnCpy(gGameCode, gameCode, 4);
    }
}

void Mfs_IncreaseVolumeRC(void) {
    gMfsRamArea.id.renewalCounter++;
}

void Mfs_ResetVolumeRC(void) {
    gMfsRamArea.id.renewalCounter = 0;
}

s32 Mfs_CalculateVolumeChecksum(void) {
    s32 size;
    s32* ptr;
    u32 i;
    s32 checksum;

    ptr = (s32*) &gMfsRamArea;
    checksum = 0;
    gMfsRamArea.id.checksum = 0;
    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &size);

    for (i = 0; i < (size / (s32) sizeof(s32)); i++) {
        checksum ^= *ptr++;
    }
    gMfsRamArea.id.checksum = checksum;
    return 0;
}

s32 Mfs_CheckChecksum(void) {
    s32 size;
    s32* ptr;
    u32 i;
    s32 checksum;

    ptr = (s32*) &gMfsRamArea;
    checksum = 0;

    LeoLBAToByte(gRamAreaCapacity.startLBA, 3, &size);

    for (i = 0; i < (size / (s32) sizeof(s32)); i++) {
        if (*ptr != 0) {}
        checksum ^= *ptr++;
    }
    checksum ^= gMfsRamArea.id.checksum;
    checksum ^= gMfsRamArea.id.checksum;

    return (checksum != 0) ? -1 : 0;
}

s32 Mfs_RefreshRamArea(void) {
    UNUSED s32 pad;
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    Mfs_CalculateVolumeChecksum();
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    return 0;
}

s32 Mfs_CopyRamAreaFromBackup(void) {
    UNUSED s32 pad;

    D_80794CDC = 1;
    if (Mfs_ReadLBA(gRamAreaCapacity.startLBA + 3, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    if (Mfs_ValidateRamVolume() < 0) {
        return -1;
    }
    gMfsRamArea.id.renewalCounter++;
    Mfs_CalculateVolumeChecksum();
    D_80794CDC = 2;
    if (Mfs_WriteLBA(gRamAreaCapacity.startLBA, (u8*) &gMfsRamArea, 3) < 0) {
        return -1;
    }
    if (D_80794D30 == 0x10A) {
        D_80794D30 = LEO_ERROR_GOOD;
    }
    return 0;
}

s32 Mfs_SpdlMotorBrake(void) {
    LEOCmd cmdBlock;

    if (gLeoSpdlMotorFunc(&cmdBlock, LEO_MOTOR_BRAKE, &D_80794D0C) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_80762390();
}
