#include "leo/mfs.h"
#include "leo/leo_functions.h"

extern s32 gMfsError;
extern u16 gWorkingDirectory;

s32 Mfs_CreateRootDirectory(bool writeChanges) {
    u16 dirId;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_GetDirectoryIndexFromParent(MFS_ENTRY_ROOT_PARENT_DIR, "/") != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    dirId = Mfs_GetNextFreeDirectoryEntry();
    if (dirId != 0) {
        gMfsError = 0x103;
        return -1;
    }
    Mfs_InitDirEntry();
    Mfs_CreateDirEntry(MFS_ENTRY_ROOT_PARENT_DIR, "/");
    Mfs_SetDirEntryAttr(MFS_FILE_ATTR_DIRECTORY);
    Mfs_SetDirEntryDirId(MFS_ENTRY_ROOT_DIR);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_CopyDirEntryToRam(dirId);
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_SetWorkingDirImpl(u16 dirId) {
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        return 0;
    }
    if ((dirId == MFS_ENTRY_WORKING_PARENT_DIR) &&
        ((dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (dirId == MFS_ENTRY_ROOT_PARENT_DIR)) ||
         (dirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST) {
        return N64DD_NOT_FOUND;
    }
    gWorkingDirectory = dirId;
    return 0;
}

void Mfs_SetWorkingDir(u16 dirId) {
    Mfs_SetWorkingDirImpl(dirId);
    return;
}

extern MfsRamArea gMfsRamArea;

s32 Mfs_GetParentDir(u16 dirId) {
    u16 entryId;

    if (func_80760C6C() < 0) {
        return 0xFFF0;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        return MFS_ENTRY_ROOT_PARENT_DIR;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    return gMfsRamArea.directoryEntry[dirId].parentDirId;
}

s32 Mfs_MkDir(u16 dirId, u16 subDirId) {
    u16 parentDirId;
    u16 dirEntryIndex;
    u16 subDirEntryIndex;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (subDirId == MFS_ENTRY_WORKING_DIR) {
        subDirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (subDirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        subDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == 0) {
        gMfsError = 0x104;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        gMfsError = 0x104;
        return -1;
    }
    if (dirId == subDirId) {
        gMfsError = 0x104;
        return -1;
    }
    dirEntryIndex = Mfs_GetDirectoryIndex(dirId);
    if (dirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    subDirEntryIndex = Mfs_GetDirectoryIndex(subDirId);
    if (subDirEntryIndex == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT | MFS_VALIDATION_CHECK_SUB_ENTRY,
                                        dirEntryIndex, subDirEntryIndex, dirId) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    parentDirId = gMfsRamArea.directoryEntry[dirEntryIndex].parentDirId;
    if (parentDirId == subDirId) {
        return 0;
    }
    if (Mfs_GetDirectoryIndexFromParent(subDirId, gMfsRamArea.directoryEntry[dirEntryIndex].name) !=
        MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x100;
        return -1;
    }
    gMfsRamArea.directoryEntry[dirEntryIndex].parentDirId = subDirId;

    return 0;
}

extern s32 gDirectoryEntryCount;

s32 Mfs_DeleteDirEntry(u16 entryId, bool writeChanges) {
    u16 i;
    u16 dirId;
    s32 entriesInDir;

    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    dirId = gMfsRamArea.directoryEntry[entryId].dirId;

    for (i = 0, entriesInDir = 0; i < gDirectoryEntryCount; i++) {
        if (gMfsRamArea.directoryEntry[i].attr == 0) {
            continue;
        }
        if (gMfsRamArea.directoryEntry[i].parentDirId == dirId) {
            entriesInDir++;
        }
    }
    if (entriesInDir != 0) {
        gMfsError = 0x103;
        return -1;
    }
    bzero(&gMfsRamArea.directoryEntry[entryId], sizeof(MfsRamDirectoryEntry));
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

extern s32 D_80794CDC;

s32 Mfs_DeleteDir(u16 dirId, char* name, bool writeChanges) {
    u16 entryId;
    UNUSED s32 pad[2];
    s32 sp18;

    sp18 = 0;
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        gMfsError = 0x106;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_DeleteDirEntry(entryId, writeChanges) < 0) {
        return -1;
    }
    return 0;
}
