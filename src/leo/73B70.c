#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern MfsRamDirectoryEntry gCurrentDirectoryEntry;
extern s32 D_80794CD4;

s32 func_80766370(u16 arg0, char* name, char* extension) {
    s32 sp1C;

    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = Mfs_CopyDirEntryFromRam(arg0);
    Mfs_SetDirEntryName(name);
    Mfs_SetDirEntryExtension(extension);
    if (Mfs_GetFileIndex(gCurrentDirectoryEntry.parentDirId, gCurrentDirectoryEntry.name, gCurrentDirectoryEntry.extension) != MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0x105;
        return -1;
    }
    Mfs_CopyDirEntryToRam(arg0);
    return 0;
}

extern s32 D_80794CDC;

s32 func_80766434(u16 arg0, u8* arg1, u8* arg2, u8* arg3, u8* arg4, s32 arg5) {
    u16 sp1E;

    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    sp1E = Mfs_GetFileIndex(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766370(sp1E, arg3, arg4) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 gDirectoryEntryCount;
extern MfsRamArea gMfsRamArea;

s32 func_8076650C(u16 arg0, u8* arg1, s32 arg2, s32 arg3) {
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if ((arg0 < 0) || (arg0 > gDirectoryEntryCount)) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (!(gMfsRamArea.directoryEntry[arg0].attr & MFS_FILE_ATTR_FILE)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (gMfsRamArea.directoryEntry[arg0].attr & MFS_FILE_ATTR_DIRECTORY) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766370(arg0, arg1, arg2) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}
