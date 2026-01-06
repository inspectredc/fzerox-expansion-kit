#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/mfs.h"

extern MfsRamArea gMfsRamArea;
extern s32 gMfsError;

s32 Mfs_DeleteFile(u16 entryId) {
    s32 fatId;

    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        entryId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    Mfs_CopyFATFromRam();
    fatId = gMfsRamArea.directoryEntry[entryId].fileAllocationTableId;
    if (Mfs_ClearFileAllocationTableEntry(fatId) < 0) {
        return -1;
    }
    Mfs_CopyFATToRam();
    gMfsRamArea.directoryEntry[entryId].attr = 0;
    return 0;
}

extern s32 D_80794CDC;

s32 Mfs_DeleteFileInDir(u16 dirId, char* name, char* extension, bool writeChanges) {
    u16 entryId;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    entryId = Mfs_GetFileIndex(dirId, name, extension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_DeleteFile(entryId) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

extern s32 gDirectoryEntryCount;

s32 Mfs_CheckAndDeleteFile(u16 entryId, bool writeChanges) {
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (entryId < 0 || entryId > gDirectoryEntryCount) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_DeleteFile(entryId) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
