#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern u8 D_8077B4D0[];
extern s32 D_80794CDC;
extern LEOCapacity gRamAreaCapacity;
extern MfsRamArea gMfsRamArea;

s32 func_807650A0(s32 arg0, u8* arg1, u32 arg2, s32* arg3, OSMesg* arg4, s32* arg5, bool arg6) {
    s32 sp24;
    s32 sp20;
    u32 sp1C;

    D_80794CDC = 1;
    sp24 = func_80764D4C(arg0);

    for (sp20 = 1; sp20 <= sp24; sp20++) {
        LeoLBAToByte(arg0 + gRamAreaCapacity.startLBA, sp20, &sp1C);
        if (sp1C > arg2) {
            break;
        }
    }

    sp20--;
    if (sp20 > 0) {
        if (Mfs_ReadFile(arg0 + gRamAreaCapacity.startLBA, arg1, sp20, arg6) < 0) {
            return -1;
        }
        LeoLBAToByte(arg0 + gRamAreaCapacity.startLBA, sp20, &sp1C);
    } else {
        if (Mfs_ReadFile(arg0 + gRamAreaCapacity.startLBA, D_8077B4D0, 1, arg6) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, arg1, arg2);
        sp1C = arg2;
    }

    *arg3 = gMfsRamArea.fileAllocationTable[arg0 + sp20 - 1];
    *arg4 = arg1 + sp1C;

    if (arg2 <= sp1C) {
        *arg5 = 0;
    } else {
        *arg5 = arg2 - sp1C;
    }
    return 0;
}

s32 func_8076527C(u16 arg0, u8* arg1, s32 arg2) {
    s32 sp4C;
    s32 sp48;
    s32 attr;
    s32 sp40;
    s32 sp3C;
    s32 sp38;

    sp38 = 0;
    sp4C = gMfsRamArea.directoryEntry[arg0].fileAllocationTableId;
    while (arg2 != 0) {
        attr = gMfsRamArea.directoryEntry[arg0].attr;

        if (func_807650A0(sp4C, arg1, arg2, &sp48, &sp40, &sp3C, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
            return -1;
        }
        sp4C = sp48;
        arg1 = sp40;
        arg2 = sp3C;
    }

    return 0;
}

extern s32 D_80794CD4;

s32 func_80765380(u16 arg0, u8* arg1, u32 arg2) {
    u32 sp1C;
    s32 sp18;

    if (func_80766CC0(0x70, arg0, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    sp1C = gMfsRamArea.directoryEntry[arg0].fileSize;
    if ((arg2 == 0) || (sp1C < arg2)) {
        arg2 = sp1C;
    }
    return sp18 = func_8076527C(arg0, arg1, arg2);
}

extern u16 gWorkingDirectory;

s32 func_8076543C(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4) {
    u16 sp1E;

    D_80794CDC = 4;
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
    return func_80765380(sp1E, arg3, arg4);
}

extern s32 gDirectoryEntryCount;

s32 func_8076553C(u16 arg0, u8* arg1, s32 arg2) {
    s32 sp1C;

    sp1C = func_80760C6C();
    if (sp1C < 0) {
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
    return func_80765380(arg0, arg1, arg2);
}

extern u16 gFileAllocationTable[];

s32 func_8076564C(u16 dirId, u8* arg1, s32 arg2, u32 arg3) {
    s32 fileSize;
    u32 sp48;
    u32 sp44;
    bool isEncoded;
    u32 sp3C;
    s32 sp38;
    s32 id;
    s32 sp30;
    s32 sp2C;
    u8* sp28;

    sp48 = arg3;
    sp28 = arg1;
    fileSize = gMfsRamArea.directoryEntry[dirId].fileSize;
    id = gMfsRamArea.directoryEntry[dirId].fileAllocationTableId;
    if (gMfsRamArea.directoryEntry[dirId].attr & MFS_FILE_ATTR_ENCODE) {
        isEncoded = true;
    } else {
        isEncoded = false;
    }
    D_80794CDC = 1;
    Mfs_CopyFATFromRam();
    func_80764C54(&id, arg2, &sp44);
    if (sp44 != 0) {
        LeoLBAToByte(id + gRamAreaCapacity.startLBA, 1, &sp3C);
        if (Mfs_ReadFile(id + gRamAreaCapacity.startLBA, D_8077B4D0, 1, isEncoded) < 0) {
            return -1;
        }

        bcopy((sp3C - sp44) + D_8077B4D0, arg1, (sp44 > sp48) ? sp48 : sp44);
        sp38 = (sp44 > sp48) ? sp48 : sp44;
        sp28 += sp38;
        sp48 -= sp38;
        if (sp48 != 0) {
            id = gFileAllocationTable[id];
            if (id == MFS_ENTRY_DOES_NOT_EXIST) {
                D_80794CD4 = 0xF3;
                return -1;
            }
        }
    }

    while (sp48 != 0) {
        sp30 = func_80764D4C(id);

        for (sp2C = 1; sp2C <= sp30; sp2C++) {
            LeoLBAToByte(id + gRamAreaCapacity.startLBA, sp2C, &sp3C);
            if (sp3C < sp48) {
                continue;
            }

            if (sp3C == sp48) {
                if (Mfs_ReadFile(id + gRamAreaCapacity.startLBA, sp28, sp2C, isEncoded) < 0) {
                    return -1;
                }
                sp48 = 0;
                break;
            }
            if (--sp2C == 0) {
                break;
            }

            LeoLBAToByte(id + gRamAreaCapacity.startLBA, sp2C, &sp3C);
            if (Mfs_ReadFile(id + gRamAreaCapacity.startLBA, sp28, sp2C, isEncoded) < 0) {
                return -1;
            }
            id += sp2C;
            sp48 -= sp3C;
            sp28 += sp3C;
            break;
        }

        if (sp2C <= sp30) {
            break;
        }
        if (Mfs_ReadFile(id + gRamAreaCapacity.startLBA, sp28, sp30, isEncoded) < 0) {
            return -1;
        }
        LeoLBAToByte(id + gRamAreaCapacity.startLBA, sp30, &sp3C);
        sp48 -= sp3C;
        sp28 += sp3C;
        id = (id + sp30) - 1;

        if ((id = gFileAllocationTable[id]) == MFS_ENTRY_DOES_NOT_EXIST) {
            D_80794CD4 = 0xF3;
            return -1;
        }
    }

    if (sp48 != 0) {
        if (Mfs_ReadFile(id + gRamAreaCapacity.startLBA, D_8077B4D0, 1, isEncoded) < 0) {
            return -1;
        }
        bcopy(D_8077B4D0, sp28, sp48);
    }

    return 0;
}

s32 func_80765AF8(u16 dirId, u8* arg1, s32 arg2, u32 arg3) {
    s32 fileSize;

    if (func_80766CC0(0x70, dirId, 0, 0) < 0) {
        D_80794CD4 = 0x106;
        return -1;
    }
    fileSize = gMfsRamArea.directoryEntry[dirId].fileSize;
    if ((arg3 == 0) || (fileSize - arg2) < arg3) {
        arg3 = fileSize - arg2;
    }
    return func_8076564C(dirId, arg1, arg2, arg3);
}

s32 func_80765BC8(u16 dirId, char* name, u8* arg2, u8* arg3, s32 arg4, s32 arg5) {
    u16 sp1E;

    if (func_80760C6C() < 0) {
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        D_80794CD4 = 0xF4;
        return -1;
    }
    if (dirId == 0xFFFB) {
        dirId = gWorkingDirectory;
    }
    if (dirId == 0xFFFC) {
        dirId = Mfs_GetParentDir(0xFFFB);
    }
    sp1E = Mfs_GetFileIndex(dirId, name, arg2);
    if (sp1E == 0xFFFF) {
        D_80794CD4 = 0xF2;
        return -1;
    }
    return func_80765AF8(sp1E, arg3, arg4, arg5);
}

void Mfs_DecodeFile(LEODiskID* diskId, u8* buf, s32 size) {
    s32 j;
    s32 i;
    u8 diskIdBuf[0x20];
    u8* sp1C;

    sp1C = buf;
    bcopy(diskId, diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }
    *sp1C ^= 0x59;

    *sp1C = (((*sp1C & 0x1F) << 3) | (*sp1C & 0xE0) >> 5) & 0xFF;

    for (j = 1; j < size; j++) {
        sp1C[j] =
            ((sp1C[j] + (((((sp1C[j - 1] ^ 0xBF) & 0xF) << 4) | (((sp1C[j - 1] ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF) ^
            diskIdBuf[j & 0x1F];
    }

    *sp1C = *sp1C ^ diskIdBuf[0x17];

    i = 0;
    while (i < size) {
        sp1C[i] = (sp1C[i] ^ 0xFE) + 0x6F;
        i = ((sp1C[i] & 0xF) >> 1) + i + 4;
    }
}

void Mfs_EncodeFile(LEODiskID* diskId, u8* buf, s32 size) {
    s32 j;
    s32 i;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    u8 diskIdBuf[0x20];
    u8* sp18;

    sp18 = buf;
    bcopy(diskId, &diskIdBuf, sizeof(LEODiskID));

    for (i = 0; i < 16; i++) {
        diskIdBuf[i] ^= diskIdBuf[i + 0x10] + 0x3F;
    }

    i = 0;
    while (i < size) {
        sp44 = ((sp18[i] & 0xF) >> 1) + i + 4;
        sp18[i] = ((sp18[i] - 0x6F) & 0xFF) ^ 0xFE;
        i = sp44;
    }
    *sp18 = *sp18 ^ diskIdBuf[0x17];
    sp40 = *sp18;

    for (j = 1; j < size; j++) {
        sp3C = sp18[j];
        sp3C ^= diskIdBuf[j & 0x1F];
        sp3C = (sp3C - (((((sp40 ^ 0xBF) & 0xF) << 4) | (((sp40 ^ 0xBF) & 0xF0) >> 4)) & 0xFF)) & 0xFF;
        sp40 = sp18[j];
        sp18[j] = sp3C;
    }

    *sp18 = (((*sp18 & 7) << 5) | ((*sp18 & 0xF8) >> 3)) & 0xFF;
    *sp18 ^= 0x59;
}

s32 Mfs_DecodeWriteFile(u8* buf, s32 size) {
    LEODiskID diskId;

    if (Mfs_ReadDiskId(&diskId) < 0) {
        return -1;
    }
    Mfs_DecodeFile(&diskId, buf, size);
    return 0;
}

s32 Mfs_DecodeReadFile(u8* buf, s32 size) {
    LEODiskID diskId;

    if (Mfs_ReadDiskId(&diskId) < 0) {
        return -1;
    }
    Mfs_DecodeFile(&diskId, buf, size);
    return 0;
}

s32 Mfs_WriteFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded) {
    s32 i;
    s32 lba;
    s32 size;
    u8* bufPtr;

    if (isEncoded) {
        lba = startLBA;
        bufPtr = buf;
        for (i = 0; i < nLBAs; i++, lba++) {

            LeoLBAToByte(lba, 1, &size);
            if (D_8077B4D0 != buf) {
                bcopy(bufPtr, D_8077B4D0, size);
            }
            Mfs_DecodeWriteFile(D_8077B4D0, size);
            if (Mfs_WriteLBA(lba, D_8077B4D0, 1) < 0) {
                return -1;
            }
            bufPtr += size;
        }
    } else {
        return Mfs_WriteLBA(startLBA, buf, nLBAs);
    }

    return 0;
}

s32 Mfs_ReadFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded) {
    s32 i;
    s32 lba;
    s32 size;
    u8* bufPtr;

    if (isEncoded) {
        lba = startLBA;
        bufPtr = buf;
        for (i = 0; i < nLBAs; i++, lba++) {
            LeoLBAToByte(lba, 1, &size);
            if (Mfs_ReadLBA(lba, D_8077B4D0, 1) < 0) {
                return -1;
            }
            Mfs_DecodeReadFile(D_8077B4D0, size);
            if (D_8077B4D0 != buf) {
                bcopy(D_8077B4D0, bufPtr, size);
            }
            bufPtr += size;
        }
    } else {
        return Mfs_ReadLBA(startLBA, buf, nLBAs);
    }
    return 0;
}
