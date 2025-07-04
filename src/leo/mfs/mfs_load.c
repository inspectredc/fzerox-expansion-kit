#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern u8 D_8077B4D0[];
extern s32 D_80794CDC;
extern LEOCapacity gRamAreaCapacity;
extern MfsRamArea gMfsRamArea;

s32 Mfs_LoadFileIter(s32 fatId, u8* buf, u32 sizeToLoad, s32* nextFatIdPtr, u8** nextBufPos, s32* sizeLeftPtr,
                     bool isEncoded) {
    s32 nLBAs;
    s32 lbasToLoad;
    u32 blocksSize;

    D_80794CDC = 1;
    nLBAs = Mfs_GetFileLbaCount(fatId);

    for (lbasToLoad = 1; lbasToLoad <= nLBAs; lbasToLoad++) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToLoad, &blocksSize);
        if (blocksSize > sizeToLoad) {
            break;
        }
    }

    lbasToLoad--;
    if (lbasToLoad > 0) {
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, buf, lbasToLoad, isEncoded) < 0) {
            return -1;
        }
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToLoad, &blocksSize);
    } else {
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_8077B4D0, 1, isEncoded) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, buf, sizeToLoad);
        blocksSize = sizeToLoad;
    }

    *nextFatIdPtr = gMfsRamArea.fileAllocationTable[fatId + lbasToLoad - 1];
    *nextBufPos = buf + blocksSize;

    if (sizeToLoad <= blocksSize) {
        *sizeLeftPtr = 0;
    } else {
        *sizeLeftPtr = sizeToLoad - blocksSize;
    }
    return 0;
}

s32 Mfs_LoadFile(u16 entryId, u8* buf, s32 sizeToLoad) {
    s32 fatId;
    s32 newFatId;
    s32 attr;
    u8* newBufPos;
    s32 newSize;
    s32 sp38;

    sp38 = 0;
    fatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    while (sizeToLoad != 0) {
        attr = gMfsRamArea.directoryEntry[entryId].attr;

        if (Mfs_LoadFileIter(fatId, buf, sizeToLoad, &newFatId, &newBufPos, &newSize,
                             (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
            return -1;
        }
        fatId = newFatId;
        buf = newBufPos;
        sizeToLoad = newSize;
    }

    return 0;
}

extern s32 gMfsError;

s32 Mfs_CalculateSizeAndLoadFile(u16 entryId, u8* buf, u32 sizeToLoad) {
    u32 fileSize;
    s32 sp18;

    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_READ | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    if ((sizeToLoad == 0) || (fileSize < sizeToLoad)) {
        sizeToLoad = fileSize;
    }
    return sp18 = Mfs_LoadFile(entryId, buf, sizeToLoad);
}

extern u16 gWorkingDirectory;

s32 Mfs_LoadFileInDir(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad) {
    u16 entryId;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = 0xF4;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0xF2;
        return -1;
    }
    return Mfs_CalculateSizeAndLoadFile(entryId, buf, sizeToLoad);
}

extern s32 gDirectoryEntryCount;

s32 Mfs_CheckAndLoadFile(u16 entryId, u8* buf, s32 sizeToLoad) {
    s32 err;

    err = func_80760C6C();
    if (err < 0) {
        return -1;
    }
    if ((entryId < 0) || (entryId > gDirectoryEntryCount)) {
        gMfsError = 0xF4;
        return -1;
    }
    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE)) {
        gMfsError = 0xF2;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY) {
        gMfsError = 0xF2;
        return -1;
    }
    return Mfs_CalculateSizeAndLoadFile(entryId, buf, sizeToLoad);
}

extern u16 gFileAllocationTable[];

s32 Mfs_LoadFileFromOffset(u16 entryId, u8* buf, s32 offset, u32 sizeToLoad) {
    s32 fileSize;
    u32 sizeRemaining;
    u32 spaceAfterOffset;
    bool isEncoded;
    u32 blocksSize;
    s32 sizeLoaded;
    s32 fatId;
    s32 nLBAs;
    s32 lbasToLoad;
    u8* bufPtr;

    sizeRemaining = sizeToLoad;
    bufPtr = buf;
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    fatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_ENCODE) {
        isEncoded = true;
    } else {
        isEncoded = false;
    }
    D_80794CDC = 1;
    Mfs_CopyFATFromRam();
    Mfs_GetFileExtraBlockSpace2(&fatId, offset, &spaceAfterOffset);
    if (spaceAfterOffset != 0) {
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, 1, &blocksSize);
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_8077B4D0, 1, isEncoded) < 0) {
            return -1;
        }

        bcopy((blocksSize - spaceAfterOffset) + D_8077B4D0, buf,
              (spaceAfterOffset > sizeRemaining) ? sizeRemaining : spaceAfterOffset);
        sizeLoaded = (spaceAfterOffset > sizeRemaining) ? sizeRemaining : spaceAfterOffset;
        bufPtr += sizeLoaded;
        sizeRemaining -= sizeLoaded;
        if (sizeRemaining != 0) {
            fatId = gFileAllocationTable[fatId];
            if (fatId == MFS_ENTRY_DOES_NOT_EXIST) {
                gMfsError = 0xF3;
                return -1;
            }
        }
    }

    while (sizeRemaining != 0) {
        nLBAs = Mfs_GetFileLbaCount(fatId);

        for (lbasToLoad = 1; lbasToLoad <= nLBAs; lbasToLoad++) {
            LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToLoad, &blocksSize);
            if (blocksSize < sizeRemaining) {
                continue;
            }

            if (blocksSize == sizeRemaining) {
                if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, bufPtr, lbasToLoad, isEncoded) < 0) {
                    return -1;
                }
                sizeRemaining = 0;
                break;
            }
            if (--lbasToLoad == 0) {
                break;
            }

            LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, lbasToLoad, &blocksSize);
            if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, bufPtr, lbasToLoad, isEncoded) < 0) {
                return -1;
            }
            fatId += lbasToLoad;
            sizeRemaining -= blocksSize;
            bufPtr += blocksSize;
            break;
        }

        if (lbasToLoad <= nLBAs) {
            break;
        }
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, bufPtr, nLBAs, isEncoded) < 0) {
            return -1;
        }
        LeoLBAToByte(fatId + gRamAreaCapacity.startLBA, nLBAs, &blocksSize);
        sizeRemaining -= blocksSize;
        bufPtr += blocksSize;
        fatId = (fatId + nLBAs) - 1;

        if ((fatId = gFileAllocationTable[fatId]) == MFS_FAT_LAST_BLOCK) {
            gMfsError = 0xF3;
            return -1;
        }
    }

    if (sizeRemaining != 0) {
        if (Mfs_ReadFile(fatId + gRamAreaCapacity.startLBA, D_8077B4D0, 1, isEncoded) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, bufPtr, sizeRemaining);
    }

    return 0;
}

s32 Mfs_CalculateSizeAndLoadFileFromOffset(u16 entryId, u8* buf, s32 offset, u32 sizeToLoad) {
    s32 fileSize;

    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_READ | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    fileSize = gMfsRamArea.directoryEntry[entryId].fileSize;
    if ((sizeToLoad == 0) || (fileSize - offset) < sizeToLoad) {
        sizeToLoad = fileSize - offset;
    }
    return Mfs_LoadFileFromOffset(entryId, buf, offset, sizeToLoad);
}

s32 Mfs_LoadFileInDirFromOffset(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToLoad) {
    u16 entryId;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = 0xF4;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0xF2;
        return -1;
    }
    return Mfs_CalculateSizeAndLoadFileFromOffset(entryId, buf, offset, sizeToLoad);
}
