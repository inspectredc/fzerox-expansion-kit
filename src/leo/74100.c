#include "leo/unk_leo.h"
#include "leo/leo_functions.h"

extern s32 D_80794CD4;
extern MfsRamArea gMfsRamArea;
extern u16 gWorkingDirectory;

s32 Mfs_ChangeFileAttr(u16 dirId, u16 attributeToAdd, u16 attributeToRemove) {
    u16 attr;

    if (!(gMfsRamArea.directoryEntry[dirId].attr & MFS_FILE_ATTR_FILE) || (gMfsRamArea.directoryEntry[dirId].attr & MFS_FILE_ATTR_DIRECTORY)) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if ((attributeToAdd & MFS_FILE_ATTR_DIRECTORY) || (attributeToRemove & MFS_FILE_ATTR_FILE)) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    attr = gMfsRamArea.directoryEntry[dirId].attr;
    attr |= attributeToAdd;
    attr &= attributeToRemove ^ 0xFFFF;
    gMfsRamArea.directoryEntry[dirId].attr = attr;
    return 0;
}

s32 func_80766A04(u16 dirId, s32 attributeToAdd, s32 attributeToRemove, s32 arg3) {
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ChangeFileAttr(dirId, attributeToAdd, attributeToRemove) < 0) {
        return -1;
    }
    if ((arg3 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80766A98(u16 parentDirId, u8* arg1, s32 arg2, s32 attributeToAdd, s32 attributeToDelete, s32 arg5) {
    u16 dirId;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(arg1) < 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (parentDirId == 0xFFFB) {
        parentDirId = gWorkingDirectory;
    }
    if (parentDirId == 0xFFFC) {
        parentDirId = Mfs_GetParentDir(0xFFFB);
    }
    dirId = Mfs_GetFileIndex(parentDirId, arg1, arg2);
    if (dirId == MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    if (Mfs_ChangeFileAttr(dirId, attributeToAdd, attributeToDelete) < 0) {
        return -1;
    }
    if ((arg5 != 0) && (Mfs_WriteRamArea() < 0)) {
        return -1;
    }
    return 0;
}

s32 func_80766BC0(u16 arg0, u8* arg1, u8* arg2) {
    u16 sp1E;

    D_80794CD4 = 0;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(arg1) < 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (arg0 == 0xFFFB) {
        arg0 = gWorkingDirectory;
    }
    if (arg0 == 0xFFFC) {
        arg0 = Mfs_GetParentDir(0xFFFB);
    }
    sp1E = Mfs_GetFileIndex(arg0, arg1, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    return gMfsRamArea.directoryEntry[sp1E].attr;
}

extern u8 gCompanyCode[2];
extern u8 gGameCode[4];
extern LEODiskID D_80794CE8;

s32 func_80766CC0(s32 arg0, u16 arg1, u16 arg2, u16 arg3) {
    u16 sp1E;
    s32 sp18;

    sp1E = MFS_ENTRY_DOES_NOT_EXIST;
    if (arg0 & 0x80) {
        if (gMfsRamArea.id.attr & MFS_VOLUME_ATTR_WPROTECT) {
            return -1;
        }
        if ((gMfsRamArea.id.attr & MFS_VOLUME_ATTR_VPROTECT_WRITE) &&
            ((mfsStrnCmp(D_80794CE8.company, gCompanyCode, 2) != 0) || (mfsStrnCmp(D_80794CE8.gameName, gGameCode, 4) != 0))) {
            return -1;
        }
        if ((arg0 & 0x20) && (gMfsRamArea.directoryEntry[arg1].attr & MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if ((arg0 & 2) && (gMfsRamArea.directoryEntry[arg2].attr & MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if ((arg0 & 0x10) && (gMfsRamArea.directoryEntry[gMfsRamArea.directoryEntry[arg1].parentDirId].attr & MFS_FILE_ATTR_FORBID_W)) {
            return -1;
        }
        if (arg0 & 8) {
            sp1E = Mfs_GetDirectoryIndex(arg3);
            if (gMfsRamArea.directoryEntry[sp1E].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
        }
        if (arg0 & 4) {
            if ((sp1E = arg1) == MFS_ENTRY_DOES_NOT_EXIST) {
                sp1E = Mfs_GetDirectoryIndex(arg3);
            }
            if (gMfsRamArea.directoryEntry[sp1E].attr & MFS_FILE_ATTR_FORBID_W) {
                return -1;
            }
        }
    }

    sp1E = MFS_ENTRY_DOES_NOT_EXIST;
    if (arg0 & 0x40) {
        sp18 = func_8075F714(arg1);
        if ((gMfsRamArea.id.attr & MFS_VOLUME_ATTR_VPROTECT_READ) &&
            ((mfsStrnCmp(D_80794CE8.company, gCompanyCode, 2) != 0) || (mfsStrnCmp(&D_80794CE8, gGameCode, 4) != 0))) {
            return -1;
        }
        if ((arg0 & 0x20) && (gMfsRamArea.directoryEntry[arg1].attr & MFS_FILE_ATTR_FORBID_R) && (sp18 < 0)) {
            return -1;
        }
        if ((arg0 & 2) && (gMfsRamArea.directoryEntry[arg2].attr & MFS_FILE_ATTR_FORBID_R) && (sp18 < 0)) {
            return -1;
        }
        if ((arg0 & 0x10) && (gMfsRamArea.directoryEntry[gMfsRamArea.directoryEntry[arg1].parentDirId].attr & MFS_FILE_ATTR_FORBID_R)) {
            if (func_8075F714(gMfsRamArea.directoryEntry[arg1].parentDirId) < 0) {
                return -1;
            }
        }
        if (arg0 & 8) {
            sp1E = Mfs_GetDirectoryIndex(arg3);
            if ((gMfsRamArea.directoryEntry[sp1E].attr & MFS_FILE_ATTR_FORBID_R)) {
                if (func_8075F714(sp1E) < 0) {
                    return -1;
                }
            }
        }
        if (arg0 & 4) {
            if (sp1E == MFS_ENTRY_DOES_NOT_EXIST) {
                arg1 = Mfs_GetDirectoryIndex(arg3);
            }
            if ((gMfsRamArea.directoryEntry[sp1E].attr & MFS_FILE_ATTR_FORBID_W)) {
                if (func_8075F714(sp1E) < 0) {
                    return -1;
                }
            }
        }
    }
    return 0;
}

extern LEOCapacity gRamAreaCapacity;
extern u16 D_80784F2C[];

void func_80767170(s32* arg0, s32* arg1) {
    s32 i;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = 0;
    sp20 = 0;

    for (i = 6; i < gRamAreaCapacity.endLBA - gRamAreaCapacity.startLBA; i++) {
        LeoLBAToByte(i + gRamAreaCapacity.startLBA, 1, &sp1C);
        sp28 = D_80784F2C[i];
        if (sp28 == 0) {
            sp20 += sp1C;
        }
        if ((sp28 == 0xFFFF) || (sp28 < 0x7FFF)) {
            sp24 += sp1C;
        }
    }
    if (arg1 != NULL) {
        *arg1 = sp20;
    }
    if (arg0 != NULL) {
        *arg0 = sp24;
    }
}

extern u16 gFileAllocationTable[];
extern u8 D_8077B4D0[];
extern u8 D_807801E0[];

s32 func_8076729C(s32* arg0, s32* arg1, s32* arg2, s32 arg3) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp2C = *arg0;
    sp28 = *arg1;
    sp24 = *arg2;
    sp20 = 0;
    sp18 = arg3;
    while (sp18 > 0) {
        if (sp28 == sp2C) {
            Mfs_ReadLBA(sp24 + gRamAreaCapacity.startLBA, D_8077B4D0, 1);
            sp2C = 0;
            LeoLBAToByte(sp24 + gRamAreaCapacity.startLBA, 1, &sp28);
            sp24 = gFileAllocationTable[sp24];
        }
        sp1C = sp28 - sp2C;
        if (sp1C < sp18) {
            bcopy(&D_8077B4D0[sp2C], &D_807801E0[sp20], sp1C);
            sp2C += sp1C;
            sp20 += sp1C;
        } else {
            bcopy(&D_8077B4D0[sp2C], &D_807801E0[sp20], sp18);
            sp2C += sp18;
            sp20 += sp18;
        }
        sp18 = arg3 - sp20;
    }
    *arg0 = sp2C;
    *arg1 = sp28;
    *arg2 = sp24;
    return 0;
}

extern MfsRamDirectoryEntry gCurrentDirectoryEntry;

s32 func_80767470(s32 arg0, char* name, u16 parentDirId) {
    u16 sp4E;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp3C = -1;
    sp34 = 0;
    sp30 = 0;
    bcopy(&gMfsRamArea.directoryEntry[arg0], &gCurrentDirectoryEntry, sizeof(MfsRamDirectoryEntry));
    if (gMfsRamArea.directoryEntry[arg0].attr & MFS_FILE_ATTR_COPYLIMIT) {
        if (gMfsRamArea.directoryEntry[arg0].copyCount == 0) {
            D_80794CD4 = 0x110;
            return -1;
        }
    }
    sp48 = gMfsRamArea.directoryEntry[arg0].fileSize;
    sp4E = Mfs_GetNextFreeDirectoryEntry();
    if (sp4E == 0xFFFF) {
        D_80794CD4 = 0xF1;
        return -1;
    }
    func_80767170(0, &sp44);
    if (sp44 < sp48) {
        D_80794CD4 = 0xF1;
        return -1;
    }
    sp40 = gMfsRamArea.directoryEntry[arg0].fileAllocationTableId;
    Mfs_CopyFATFromRam();
    while (sp48 > 0) {
        func_8075FB38(sp48, &sp2C, &sp28, &sp24);
        if (sp2C == -1) {
            D_80794CD4 = 0xF1;
            return -1;
        }
        sp20 = 0;
        while ((sp20 < sp28) && (sp48 > 0)) {
            LeoLBAToByte(sp2C + gRamAreaCapacity.startLBA + sp20, 1, &sp38);
            if (sp48 < sp38) {
                sp38 = sp48;
            }
            func_8076729C(&sp34, &sp30, &sp40, sp38);
            Mfs_WriteLBA(sp2C + gRamAreaCapacity.startLBA + sp20, D_807801E0, 1);
            sp1C = sp2C + sp20;
            if (sp3C < 0) {
                gCurrentDirectoryEntry.fileAllocationTableId = sp1C;
            } else {
                gFileAllocationTable[sp3C] = sp1C;
            }
            sp3C = sp1C;
            sp20 += 1;
            sp48 -= sp38;
        }
        gFileAllocationTable[sp3C] = -1;
    }

    if (sp3C < 0) {
        gCurrentDirectoryEntry.fileAllocationTableId = -1;
    } else {
        gFileAllocationTable[sp3C] = -1;
    }
    Mfs_CopyFATToRam();
    Mfs_CreateDirEntry(parentDirId, name);
    Mfs_SetDirEntryRenewalCounter(0);
    Mfs_SetDirEntryExtension(gMfsRamArea.directoryEntry[arg0].extension);
    Mfs_CopyDirEntryToRam(sp4E);
}
