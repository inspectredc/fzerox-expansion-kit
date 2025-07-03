#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern s32 D_80794CD4;
extern u16 gWorkingDirectory;
extern u16 D_807C6E60;
extern u16 D_807C6E62;
extern s32 gDirectoryEntryCount;
extern MfsRamArea gMfsRamArea;

s32 func_80766660(u16 arg0) {
    UNUSED s32 pad;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = gWorkingDirectory;
    }
    if (arg0 == 0xFFFC) {
        arg0 = Mfs_GetParentDir(0xFFFB);
        if ((arg0 == 0xFFFE) || (arg0 == 0xFFFF)) {
            D_80794CD4 = 0x104;
            return -1;
        }
    }
    if ((arg0 == 0xFFFF) || (Mfs_GetDirectoryIndex(arg0) == 0xFFFF)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (func_80766CC0(0x48, 0, 0, arg0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    D_807C6E62 = 0;
    D_807C6E60 = arg0;
    return 0;
}

u16 func_80766788(void) {
    while (D_807C6E62 < gDirectoryEntryCount) {
        if ((gMfsRamArea.directoryEntry[D_807C6E62].parentDirId == D_807C6E60) &&
            (gMfsRamArea.directoryEntry[D_807C6E62].attr & MFS_FILE_ATTR_FILE)) {
            return D_807C6E62++;
        }
        D_807C6E62++;
    }

    return -1;
}
