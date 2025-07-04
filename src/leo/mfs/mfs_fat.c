#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"
#include "libc/stdbool.h"

extern MfsRamArea gMfsRamArea;
extern u16 gFileAllocationTable[0xB3A];

s32 Mfs_CopyFATFromRam(void) {
    bcopy(gMfsRamArea.fileAllocationTable, gFileAllocationTable, sizeof(gFileAllocationTable));
    return 0;
}

s32 Mfs_CopyFATToRam(void) {
    bcopy(gFileAllocationTable, gMfsRamArea.fileAllocationTable, sizeof(gFileAllocationTable));
    return 0;
}

extern MfsRamDirectoryEntry gCurrentDirectoryEntry;
extern s32 gMfsError;

s32 Mfs_AddFileAllocationTableEntry(s32* fatIdPtr, s32 lba, s32 nLBAs) {
    s32 lbaIndex;
    s32 fatId;

    lbaIndex = lba;
    fatId = *fatIdPtr;
    if (fatId < 0) {
        fatId = gCurrentDirectoryEntry.fileAllocationTableId = lbaIndex;
    } else {
        gFileAllocationTable[fatId] = lbaIndex;
        fatId = lbaIndex;
    }
    lbaIndex++;
    while (--nLBAs > 0) {
        gFileAllocationTable[fatId] = lbaIndex;
        fatId = lbaIndex++;
    }
    if (fatId < 0) {
        gCurrentDirectoryEntry.fileAllocationTableId = MFS_FAT_LAST_BLOCK;
    } else {
        gFileAllocationTable[fatId] = MFS_FAT_LAST_BLOCK;
    }
    *fatIdPtr = fatId;
    return 0;
}

s32 Mfs_ClearFileAllocationTableEntry(s32 fatId) {
    s32 fatIdToClear = fatId;
    s32 fatValue;

    while (true) {
        fatValue = gFileAllocationTable[fatIdToClear];
        gFileAllocationTable[fatIdToClear] = MFS_FAT_UNUSED;
        if (fatValue == MFS_FAT_LAST_BLOCK) {
            break;
        }
        if (fatValue == MFS_FAT_UNUSED) {
            gMfsError = 0xF3;
            return -1;
        }
        if (fatValue == MFS_FAT_PROHIBITED) {
            gMfsError = 0xF3;
            return -1;
        }
        fatIdToClear = fatValue;
    }

    return 0;
}

extern LEOCapacity gRamAreaCapacity;

s32 Mfs_GetFileExtraBlockSpace(s32* fatIdPtr, u32 fileSize, s32* extraSpace) {
    s32 fatId;
    s32 blockSize;

    fatId = *fatIdPtr;
    while (gFileAllocationTable[fatId] != MFS_FAT_LAST_BLOCK) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blockSize);
        if (fileSize < blockSize) {
            gMfsError = 0xF3;
            return -1;
        }
        fileSize -= blockSize;
        fatId = gFileAllocationTable[fatId];
    }

    LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blockSize);
    if (fileSize > blockSize) {
        gMfsError = 0xF3;
        return -1;
    }
    *extraSpace = blockSize - fileSize;
    *fatIdPtr = fatId;
    return 0;
}

s32 Mfs_GetFileExtraBlockSpace2(s32* fatIdPtr, u32 fileSize, s32* extraSpace) {
    s32 fatId;
    s32 blockSize;

    fatId = *fatIdPtr;

    while (true) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blockSize);
        if (fileSize < blockSize) {
            break;
        }
        fileSize -= blockSize;
        if (fatId == MFS_FAT_LAST_BLOCK) {
            return 0xF4;
        }
        fatId = gFileAllocationTable[fatId];
    }
    if (fileSize == 0) {
        *extraSpace = 0;
    } else {
        *extraSpace = blockSize - fileSize;
    }
    *fatIdPtr = fatId;
    return 0;
}

s32 Mfs_GetFileLbaCount(s32 fatId) {
    s32 nLBAs = 0;

    while (true) {
        nLBAs++;
        if (gMfsRamArea.fileAllocationTable[fatId] == MFS_FAT_LAST_BLOCK) {
            break;
        }
        if (gMfsRamArea.fileAllocationTable[fatId] != fatId + 1) {
            break;
        }
        fatId++;
    }
    return nLBAs;
}
