#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/mfs.h"

u16 gPreparedDirectoryId;
u16 gPreparedEntryIndexCounter;

extern s32 gMfsError;
extern u16 gWorkingDirectory;
extern s32 gDirectoryEntryCount;
extern MfsRamArea gMfsRamArea;

s32 Mfs_GetFilesPreparation(u16 dirId) {
    UNUSED s32 pad;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (dirId == MFS_ENTRY_WORKING_DIR) {
        dirId = gWorkingDirectory;
    }
    if (dirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        dirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
        if ((dirId == MFS_ENTRY_ROOT_PARENT_DIR) || (dirId == MFS_ENTRY_DOES_NOT_EXIST)) {
            gMfsError = 0x104;
            return -1;
        }
    }
    if ((dirId == MFS_ENTRY_DOES_NOT_EXIST) || (Mfs_GetDirectoryIndex(dirId) == MFS_ENTRY_DOES_NOT_EXIST)) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_READ | MFS_VALIDATION_CHECK_DIRECTORY, 0, 0, dirId) < 0) {
        gMfsError = 0x106;
        return -1;
    }
    gPreparedEntryIndexCounter = 0;
    gPreparedDirectoryId = dirId;
    return 0;
}

u16 Mfs_GetNextFileInPreparedDir(void) {
    while (gPreparedEntryIndexCounter < gDirectoryEntryCount) {
        if ((gMfsRamArea.directoryEntry[gPreparedEntryIndexCounter].parentDirId == gPreparedDirectoryId) &&
            (gMfsRamArea.directoryEntry[gPreparedEntryIndexCounter].attr & MFS_FILE_ATTR_FILE)) {
            return gPreparedEntryIndexCounter++;
        }
        gPreparedEntryIndexCounter++;
    }

    return MFS_ENTRY_DOES_NOT_EXIST;
}
