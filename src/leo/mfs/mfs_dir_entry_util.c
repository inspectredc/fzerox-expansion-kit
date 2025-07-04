#include "leo/unk_leo.h"
#include "leo/leo_functions.h"
#include "libc/stdbool.h"

extern MfsRamDirectoryEntry gCurrentDirectoryEntry;

void Mfs_SetDirEntryAttr(u16 attr) {
    gCurrentDirectoryEntry.attr = attr;
}

void Mfs_SetDirEntryParentDir(u16 dirId) {
    gCurrentDirectoryEntry.parentDirId = dirId;
}

void Mfs_SetDirEntryCompanyCode(char* companyCode) {
    bzero(gCurrentDirectoryEntry.companyCode, 2);
    if (companyCode != NULL) {
        mfsStrnCpy(gCurrentDirectoryEntry.companyCode, companyCode, 2);
    }
}

void Mfs_SetDirEntryGameCode(char* gameCode) {
    bzero(gCurrentDirectoryEntry.gameCode, 4);
    if (gameCode != NULL) {
        mfsStrnCpy(gCurrentDirectoryEntry.gameCode, gameCode, 4);
    }
}

void Mfs_SetDirEntryName(char* name) {
    bzero(gCurrentDirectoryEntry.name, 20);
    if (name != NULL) {
        mfsStrnCpy(gCurrentDirectoryEntry.name, name, 20);
    }
}

void Mfs_SetDirEntryCreateTime(void) {
    LEODiskTime diskTime;

    Mfs_ReadRtc(&diskTime);
    Mfs_LEODiskTimeToMfsTime(&diskTime, &gCurrentDirectoryEntry.creationDate);
}

void Mfs_SetDirEntryDirId(u16 dirId) {
    gCurrentDirectoryEntry.dirId = dirId;
}

void Mfs_SetDirEntryExtension(char* extension) {
    bzero(gCurrentDirectoryEntry.extension, 5);
    if (extension != NULL) {
        mfsStrnCpy(gCurrentDirectoryEntry.extension, extension, 5);
    }
}

void Mfs_SetDirEntryFileSize(s32 fileSize) {
    gCurrentDirectoryEntry.fileSize = fileSize;
}

extern char gCompanyCode[];
extern char gGameCode[];

void Mfs_CreateDirEntry(u16 parentDirId, char* name) {
    Mfs_SetDirEntryParentDir(parentDirId);
    Mfs_SetDirEntryName(name);
    Mfs_SetDirEntryCreateTime();
    Mfs_SetDirEntryCompanyCode(gCompanyCode);
    Mfs_SetDirEntryGameCode(gGameCode);
}

void Mfs_SetDirEntryCopyCount(s32 copyCount) {
    gCurrentDirectoryEntry.copyCount = copyCount;
}

void Mfs_SetDirEntryRenewalCounter(u16 renewalCounter) {
    gCurrentDirectoryEntry.renewalCounter = renewalCounter;
}

void Mfs_InitDirEntry(void) {
    bzero(&gCurrentDirectoryEntry, sizeof(MfsRamDirectoryEntry));
}

extern s32 gDirectoryEntryCount;
extern MfsRamArea gMfsRamArea;

s32 Mfs_CopyDirEntryToRam(u16 entryId) {
    if (entryId > gDirectoryEntryCount) {
        return -1;
    }
    bcopy(&gCurrentDirectoryEntry, &gMfsRamArea.directoryEntry[entryId], sizeof(MfsRamDirectoryEntry));
    return 0;
}

s32 Mfs_CopyDirEntryFromRam(u16 entryId) {
    if (entryId > gDirectoryEntryCount) {
        return -1;
    }
    bcopy(&gMfsRamArea.directoryEntry[entryId], &gCurrentDirectoryEntry, sizeof(MfsRamDirectoryEntry));
    return 0;
}

void Mfs_IncreaseFileRC(u16 entryId) {

    if (gMfsRamArea.directoryEntry[entryId].renewalCounter < 0xFF) {
        gMfsRamArea.directoryEntry[entryId].renewalCounter++;
    }
}

void Mfs_ResetFileRC(u16 entryId) {
    gMfsRamArea.directoryEntry[entryId].renewalCounter = 0;
}

s32 Mfs_ValidateGameCode(u16 entryId) {

    if (mfsStrnCmp(gMfsRamArea.directoryEntry[entryId].companyCode, gCompanyCode, 2) != 0) {
        return -1;
    }

    if (mfsStrnCmp(gMfsRamArea.directoryEntry[entryId].gameCode, gGameCode, 4) != 0) {
        return -1;
    }

    return 0;
}

extern s32 gMfsError;
extern u16 gWorkingDirectory;

u16 Mfs_GetFileIndex(u16 dirId, char* name, char* extension) {
    s32 i;

    gMfsError = 0;
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_FILE) &&
            (gMfsRamArea.directoryEntry[i].parentDirId == dirId) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].name, name, 20) == 0) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].extension, extension, 5) == 0)) {
            return i;
        }
    }

    gMfsError = 0xF2;
    return MFS_ENTRY_DOES_NOT_EXIST;
}

u16 Mfs_GetDirectoryIndexFromParent(u16 parentDirId, char* name) {
    s32 i;

    if (parentDirId == MFS_ENTRY_WORKING_DIR) {
        parentDirId = gWorkingDirectory;
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) &&
            (gMfsRamArea.directoryEntry[i].parentDirId == parentDirId) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].name, name, 20) == 0)) {
            return i;
        }
    }

    return MFS_ENTRY_DOES_NOT_EXIST;
}

u16 Mfs_GetDirectoryIndex(u16 dirId) {
    s32 i;

    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) &&
            (gMfsRamArea.directoryEntry[i].dirId == dirId)) {
            return i;
        }
    }

    return MFS_ENTRY_DOES_NOT_EXIST;
}

u16 Mfs_GetNextFreeDirectoryEntry(void) {
    s32 i;

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if (gMfsRamArea.directoryEntry[i].attr == 0) {
            return i;
        }
    }

    return -1;
}

extern u16 gFileAllocationTable[];
extern LEOCapacity gRamAreaCapacity;

s32 Mfs_FindBlocksForSize(u32 sizeRequired, s32* lbaPtr, s32* nLBAsPtr, s32* blockSizePtr) {
    u32 lba;
    s32 nLBAs;
    u32 bestBlockSize;
    s32 availableBlockSize;
    s32 i;
    s32 j;
    s32 updateBestBlockConditionsSatisfied;
    bool firstAvailableBlock;

    lba = -1;
    nLBAs = -1;
    bestBlockSize = 0;
    firstAvailableBlock = true;

    for (i = 6; i < (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
        if (gFileAllocationTable[i] != MFS_FAT_UNUSED) {
            continue;
        }
        j = i;
        while (j < (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA)) {
            if (gFileAllocationTable[j] != MFS_FAT_UNUSED) {
                break;
            }
            j++;
        }

        LeoLBAToByte(i + gRamAreaCapacity.startLBA, j - i, &availableBlockSize);
        updateBestBlockConditionsSatisfied = 0;
        if (firstAvailableBlock) {
            updateBestBlockConditionsSatisfied++;
            firstAvailableBlock = false;
        }
        if ((bestBlockSize < sizeRequired) && (availableBlockSize > sizeRequired)) {
            updateBestBlockConditionsSatisfied++;
        }
        if ((availableBlockSize <= sizeRequired) && (bestBlockSize < availableBlockSize)) {
            updateBestBlockConditionsSatisfied++;
        }
        if ((availableBlockSize >= sizeRequired) && (bestBlockSize > availableBlockSize)) {
            updateBestBlockConditionsSatisfied++;
        }
        if (updateBestBlockConditionsSatisfied != 0) {
            lba = i;
            nLBAs = j - i;
            bestBlockSize = availableBlockSize;
        }
        i = j;
    }

    if (false) {
        *lbaPtr = -1;
        *nLBAsPtr = 0;
        *blockSizePtr = 0;
        return -1;
    }

    if (bestBlockSize > sizeRequired) {
        for (j = 1; j <= nLBAs; j++) {
            LeoLBAToByte(lba + gRamAreaCapacity.startLBA, j, &availableBlockSize);
            if (availableBlockSize >= sizeRequired) {
                break;
            }
        }

        nLBAs = j;
        bestBlockSize = availableBlockSize;
    }
    *lbaPtr = lba;
    *nLBAsPtr = nLBAs;
    *blockSizePtr = bestBlockSize;

    return 0;
}
