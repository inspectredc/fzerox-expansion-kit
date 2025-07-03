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

void Mfs_SetDirEntryExtension(u8* extension) {
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

s32 Mfs_CopyDirEntryToRam(u16 dirId) {
    if (dirId > gDirectoryEntryCount) {
        return -1;
    }
    bcopy(&gCurrentDirectoryEntry, &gMfsRamArea.directoryEntry[dirId], sizeof(MfsRamDirectoryEntry));
    return 0;
}

s32 Mfs_CopyDirEntryFromRam(u16 dirId) {
    if (dirId > gDirectoryEntryCount) {
        return -1;
    }
    bcopy(&gMfsRamArea.directoryEntry[dirId], &gCurrentDirectoryEntry, sizeof(MfsRamDirectoryEntry));
    return 0;
}

void Mfs_IncreaseFileRC(u16 dirId) {

    if (gMfsRamArea.directoryEntry[dirId].renewalCounter < 0xFF) {
        gMfsRamArea.directoryEntry[dirId].renewalCounter++;
    }
}

void Mfs_ResetFileRC(u16 dirId) {
    gMfsRamArea.directoryEntry[dirId].renewalCounter = 0;
}

s32 func_8075F714(u16 dirId) {

    if (mfsStrnCmp(gMfsRamArea.directoryEntry[dirId].companyCode, gCompanyCode, 2) != 0) {
        return -1;
    }

    if (mfsStrnCmp(gMfsRamArea.directoryEntry[dirId].gameCode, gGameCode, 4) != 0) {
        return -1;
    }

    return 0;
}

extern s32 D_80794CD4;
extern u16 gWorkingDirectory;

u16 Mfs_GetFileIndex(u16 dirId, char* name, char* extension) {
    s32 i;

    D_80794CD4 = 0;
    if (dirId == 0xFFFB) {
        dirId = gWorkingDirectory;
    }
    if (dirId == 0xFFFC) {
        dirId = Mfs_GetParentDir(0xFFFB);
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_FILE) && (gMfsRamArea.directoryEntry[i].parentDirId == dirId) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].name, name, 20) == 0) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].extension, extension, 5) == 0)) {
            return i;
        }
    }

    D_80794CD4 = 0xF2;
    return MFS_ENTRY_DOES_NOT_EXIST;
}

u16 Mfs_GetDirectoryIndexFromParent(u16 dirId, u8* name) {
    s32 i;

    if (dirId == 0xFFFB) {
        dirId = gWorkingDirectory;
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) && (gMfsRamArea.directoryEntry[i].parentDirId == dirId) &&
            (mfsStrnCmp(gMfsRamArea.directoryEntry[i].name, name, 20) == 0)) {
            return i;
        }
    }

    return MFS_ENTRY_DOES_NOT_EXIST;
}

u16 Mfs_GetDirectoryIndex(u16 dirId) {
    s32 i;

    if (dirId == 0xFFFB) {
        dirId = gWorkingDirectory;
    }
    if (dirId == 0xFFFC) {
        dirId = Mfs_GetParentDir(0xFFFB);
    }

    for (i = 0; i < gDirectoryEntryCount; i++) {
        if ((gMfsRamArea.directoryEntry[i].attr & MFS_FILE_ATTR_DIRECTORY) && (gMfsRamArea.directoryEntry[i].dirId == dirId)) {
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

s32 func_8075FB38(u32 arg0, s32* arg1, s32* arg2, s32* arg3) {
    u32 sp34;
    s32 sp30;
    u32 sp2C;
    s32 sp28;
    s32 i;
    s32 j;
    s32 sp1C;
    s32 sp18;

    sp34 = -1;
    sp30 = -1;
    sp2C = 0;
    sp18 = 1;

    for (i = 6; i < (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA); i++) {
        if (gFileAllocationTable[i] != 0) {
            continue;
        }
        j = i;
        while (j < (gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA)) {
            if (gFileAllocationTable[j] != 0) {
                break;
            }
            j++;
        }

        LeoLBAToByte(i + gRamAreaCapacity.startLBA, j - i, &sp28);
        sp1C = 0;
        if (sp18 != 0) {
            sp1C++;
            sp18 = 0;
        }
        if ((sp2C < arg0) && (sp28 > arg0)) {
            sp1C++;
        }
        if ((sp28 <= arg0) && (sp2C < sp28)) {
            sp1C++;
        }
        if ((sp28 >= arg0) && (sp2C > sp28)) {
            sp1C++;
        }
        if (sp1C != 0) {
            sp34 = i;
            sp30 = j - i;
            sp2C = sp28;
        }
        i = j;
    }

    if (false) {
        *arg1 = -1;
        *arg2 = 0;
        *arg3 = 0;
        return -1;
    }

    if (sp2C > arg0) {
        for (j = 1; j <= sp30; j++) {
            LeoLBAToByte(sp34 + gRamAreaCapacity.startLBA, j, &sp28);
            if (sp28 >= arg0) {
                break;
            }
        }

        sp30 = j;
        sp2C = sp28;
    }
    *arg1 = sp34;
    *arg2 = sp30;
    *arg3 = sp2C;

    return 0;
}
