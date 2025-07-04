#include "leo/unk_leo.h"
#include "leo/leo_functions.h"

extern s32 gMfsError;
extern MfsRamArea gMfsRamArea;
extern u16 gWorkingDirectory;

s32 Mfs_ChangeFileAttr(u16 entryId, u16 attributeToAdd, u16 attributeToRemove) {
    u16 attr;

    if (!(gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_FILE) ||
        (gMfsRamArea.directoryEntry[entryId].attr & MFS_FILE_ATTR_DIRECTORY)) {
        gMfsError = 0xF2;
        return -1;
    }
    if ((attributeToAdd & MFS_FILE_ATTR_DIRECTORY) || (attributeToRemove & MFS_FILE_ATTR_FILE)) {
        gMfsError = 0xF4;
        return -1;
    }
    attr = gMfsRamArea.directoryEntry[entryId].attr;
    attr |= attributeToAdd;
    attr &= attributeToRemove ^ 0xFFFF;
    gMfsRamArea.directoryEntry[entryId].attr = attr;
    return 0;
}

s32 Mfs_CheckAndChangeFileAttr(u16 entryId, s32 attributeToAdd, s32 attributeToRemove, bool writeChanges) {
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ChangeFileAttr(entryId, attributeToAdd, attributeToRemove) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_ChangeFileInDirAttr(u16 dirId, char* name, char* extension, s32 attributeToAdd, s32 attributeToDelete,
                            bool writeChanges) {
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
    if (Mfs_ChangeFileAttr(entryId, attributeToAdd, attributeToDelete) < 0) {
        return -1;
    }
    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}

s32 Mfs_GetFileInDirAttr(u16 dirId, char* name, char* extension) {
    u16 entryId;

    gMfsError = LEO_ERROR_GOOD;
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
    return gMfsRamArea.directoryEntry[entryId].attr;
}
