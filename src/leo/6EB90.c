#include "leo/unk_leo.h"
#include "leo/leo_functions.h"

extern s32 D_80794CD4;
extern u16 gWorkingDirectory;

s32 Mfs_CreateRootDirectory(bool arg0) {
    u16 dirId;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_GetDirectoryIndexFromParent(MFS_ENTRY_ROOT_PARENT_DIR, "/") != MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0x100;
        return -1;
    }
    dirId = Mfs_GetNextFreeDirectoryEntry();
    if (dirId != 0) {
        D_80794CD4 = 0x103;
        return -1;
    }
    Mfs_InitDirEntry();
    Mfs_CreateDirEntry(MFS_ENTRY_ROOT_PARENT_DIR, "/");
    Mfs_SetDirEntryAttr(MFS_FILE_ATTR_DIRECTORY);
    Mfs_SetDirEntryDirId(MFS_ENTRY_ROOT_DIR);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_CopyDirEntryToRam(dirId);
    if (arg0) {
        if (Mfs_WriteRamArea() < 0) {
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
    if ((dirId == MFS_ENTRY_WORKING_PARENT_DIR) && ((dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR), (dirId == MFS_ENTRY_ROOT_PARENT_DIR)) || (dirId == MFS_ENTRY_DOES_NOT_EXIST))) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST) {
        return 0xF2;
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
        D_80794CD4 = 0xF2;
        return MFS_ENTRY_DOES_NOT_EXIST;
    }
    return gMfsRamArea.directoryEntry[dirId].parentDirId;
}

s32 Mfs_AddToDir(u16 dirId1, u16 dirId2) {
    u16 parentDirId;
    u16 entryIndex1;
    u16 entryIndex2;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (dirId1 == MFS_ENTRY_WORKING_DIR) {
        dirId1 = gWorkingDirectory;
    }
    if (dirId2 == MFS_ENTRY_WORKING_DIR) {
        dirId2 = gWorkingDirectory;
    }
    if (dirId1 == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId1 = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId2 == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId2 = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId1 == 0) {
        D_80794CD4 = 0x104;
        return -1;
    }
    if (dirId1 == MFS_ENTRY_ROOT_PARENT_DIR) {
        D_80794CD4 = 0x104;
        return -1;
    }
    if (dirId1 == dirId2) {
        D_80794CD4 = 0x104;
        return -1;
    }
    entryIndex1 = Mfs_GetDirectoryIndex(dirId1);
    if (entryIndex1 == MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    entryIndex2 = Mfs_GetDirectoryIndex(dirId2);
    if (entryIndex2 == MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766CC0(0xB2, entryIndex1, entryIndex2, dirId1) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    parentDirId = gMfsRamArea.directoryEntry[entryIndex1].parentDirId;
    if (parentDirId == dirId2) {
        return 0;
    }
    if (Mfs_GetDirectoryIndexFromParent(dirId2, gMfsRamArea.directoryEntry[entryIndex1].name) != MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0x100;
        return -1;
    }
    gMfsRamArea.directoryEntry[entryIndex1].parentDirId = dirId2;

    return 0;
}

extern s32 gDirectoryEntryCount;

s32 Mfs_DeleteDirEntry(u16 entryId, bool writeChanges) {
    u16 i;
    u16 dirId;
    s32 entriesInDir;

    if (func_80766CC0(0xB0, entryId, 0, 0) < 0) {
        D_80794CD4 = 0x106;
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
        D_80794CD4 = 0x103;
        return -1;
    }
    bzero(&gMfsRamArea.directoryEntry[entryId], sizeof(MfsRamDirectoryEntry));
    if (writeChanges) {
        if (Mfs_WriteRamArea() < 0) {
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
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    if (dirId == MFS_ENTRY_ROOT_DIR) {
        D_80794CD4 = 0x106;
        return -1;
    }
    if (dirId == MFS_ENTRY_ROOT_PARENT_DIR) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    entryId = Mfs_GetDirectoryIndex(dirId);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (Mfs_DeleteDirEntry(entryId, writeChanges) < 0) {
        return -1;
    }
    return 0;
}
