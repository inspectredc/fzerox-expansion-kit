#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern MfsRamArea gMfsRamArea;
extern s32 D_80794CD4;

s32 func_80764DD0(u16 arg0) {
    s32 sp1C;

    if (func_80766CC0(0xB0, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    Mfs_CopyFATFromRam();
    sp1C = gMfsRamArea.directoryEntry[arg0].fileAllocationTableId;
    if (func_80764A4C(sp1C) < 0) {
        return -1;
    }
    Mfs_CopyFATToRam();
    gMfsRamArea.directoryEntry[arg0].attr = 0;
    return 0;
}

extern s32 D_80794CDC;

s32 func_80764E90(u16 arg0, u8* arg1, u8* arg2, s32 arg3) {
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
    if (func_80764DD0(sp1E) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}

extern s32 gDirectoryEntryCount;

s32 func_80764F60(u16 arg0, s32 arg1) {
    D_80794CDC = 4;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 < 0 || arg0 > gDirectoryEntryCount) {
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
    if (func_80764DD0(arg0) < 0) {
        return -1;
    }
    if ((arg1 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}
