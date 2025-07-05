#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern MfsRamDirectoryEntry gCurrentDirectoryEntry;
extern s32 gMfsError;

s32 Mfs_RenameFile(u16 dirId, char* newName, char* newExtension) {
    s32 err;

    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                            MFS_VALIDATION_CHECK_PARENT,
                                        dirId, 0, 0) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    err = Mfs_CopyDirEntryFromRam(dirId);
    Mfs_SetDirEntryName(newName);
    Mfs_SetDirEntryExtension(newExtension);
    if (Mfs_GetFileIndex(gCurrentDirectoryEntry.parentDirId, gCurrentDirectoryEntry.name,
                         gCurrentDirectoryEntry.extension) != MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = 0x105;
        return -1;
    }
    Mfs_CopyDirEntryToRam(dirId);
    return 0;
}

extern s32 D_80794CDC;

s32 Mfs_RenameFileInDir(u16 dirId, char* oldName, char* oldExtension, char* newName, char* newExtension,
                        bool writeChanges) {
    u16 entryId;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    entryId = Mfs_GetFileIndex(dirId, oldName, oldExtension);
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_RenameFile(entryId, newName, newExtension) < 0) {
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
extern MfsRamArea gMfsRamArea;

s32 Mfs_CheckAndRenameFile(u16 entryId, char* newName, char* newExtension, bool writeChanges) {
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if ((entryId < 0) || (entryId > gDirectoryEntryCount)) {
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
    if (Mfs_RenameFile(entryId, newName, newExtension) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
