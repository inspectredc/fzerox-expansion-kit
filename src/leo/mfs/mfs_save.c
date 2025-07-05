#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"

extern s32 gMfsError;
extern LEOCapacity gRamAreaCapacity;

s32 Mfs_WriteNewFile(u8* buf, u32 fileSize, bool isEncoded) {
    u32 sizeRemaining = fileSize;
    s32 blockSize;
    s32 lba;
    s32 nLBAs;
    s32 fatId = -1;
    u8* bufPtr = buf;

    Mfs_CopyFATFromRam();

    while (sizeRemaining != 0) {
        if (Mfs_FindBlocksForSize(sizeRemaining, &lba, &nLBAs, &blockSize) < 0) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteFile(lba + gRamAreaCapacity.startLBA, bufPtr, nLBAs, isEncoded) < 0) {
            return -1;
        }
        Mfs_AddFileAllocationTableEntry(&fatId, lba, nLBAs);
        if (blockSize >= sizeRemaining) {
            sizeRemaining = 0;
        } else {
            sizeRemaining -= blockSize;
        }
        bufPtr += blockSize;
    }
    return 0;
}

extern u8 D_80794DD0;

s32 Mfs_WriteNewFileInDir(u16 parentDirId, char* name, char* extension, u8* buf, s32 fileSize, s32 attr,
                          s32 copyCount) {
    u16 entryId;

    Mfs_InitDirEntry();
    if ((copyCount < 0) || (copyCount >= 0x100)) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (attr & MFS_FILE_ATTR_DIRECTORY) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    attr |= MFS_FILE_ATTR_FILE;
    if ((copyCount > 0) && (copyCount < 0xFE)) {
        attr |= MFS_FILE_ATTR_COPYLIMIT;
    }
    entryId = Mfs_GetNextFreeDirectoryEntry();
    if (entryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_AREA_LACKED;
        return -1;
    }

    if (Mfs_WriteNewFile(buf, fileSize, (attr & MFS_FILE_ATTR_ENCODE) ? true : false) < 0) {
        return -1;
    }
    Mfs_CreateDirEntry(parentDirId, name);
    Mfs_SetDirEntryAttr(attr);
    Mfs_SetDirEntryFileSize(fileSize);
    Mfs_SetDirEntryExtension(extension);
    Mfs_SetDirEntryCopyCount(copyCount);
    Mfs_SetDirEntryRenewalCounter(D_80794DD0);
    Mfs_CopyDirEntryToRam(entryId);
    Mfs_IncreaseFileRC(entryId);
    Mfs_CopyFATToRam();
    return 0;
}

extern MfsRamArea gMfsRamArea;
extern u16 gWorkingDirectory;

s32 Mfs_SaveFile(u16 parentDirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount,
                 bool writeChanges) {
    u16 fileEntryId;
    u16 parentDirEntryId;

    gMfsError = 0;
    if (func_80760C6C() < 0) {
        return -1;
    }
    if (fileSize == 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (Mfs_ValidateFileName(name) < 0) {
        gMfsError = N64DD_ARGUMENT_ILLEGAL;
        return -1;
    }
    if (parentDirId == MFS_ENTRY_WORKING_DIR) {
        parentDirId = gWorkingDirectory;
    }
    if (parentDirId == MFS_ENTRY_WORKING_PARENT_DIR) {
        parentDirId = Mfs_GetParentDir(MFS_ENTRY_WORKING_DIR);
    }
    parentDirEntryId = Mfs_GetDirectoryIndex(parentDirId);
    if (parentDirEntryId == MFS_ENTRY_DOES_NOT_EXIST) {
        gMfsError = N64DD_NOT_FOUND;
        return -1;
    }
    D_80794DD0 = 0;
    fileEntryId = Mfs_GetFileIndex(parentDirId, name, extension);
    if (fileEntryId != MFS_ENTRY_DOES_NOT_EXIST) {
        D_80794DD0 = gMfsRamArea.directoryEntry[fileEntryId].renewalCounter;
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY |
                                                MFS_VALIDATION_CHECK_PARENT,
                                            fileEntryId, 0, 0) < 0) {
            gMfsError = 0x106;
            return -1;
        }
        if (Mfs_RamGetFreeSize() < fileSize) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteNewFileInDir(parentDirId, "__TMP__", "_!TMP", buf, fileSize, attr, copyCount) < 0) {
            return -1;
        }
        Mfs_DeleteFileInDir(parentDirId, name, extension, 0);
        Mfs_RenameFileInDir(parentDirId, "__TMP__", "_!TMP", name, extension, 0);
    } else {
        if (Mfs_ValidateFileSystemOperation(MFS_VALIDATION_CHECK_WRITE | MFS_VALIDATION_CHECK_MAIN_ENTRY,
                                            parentDirEntryId, 0, 0) < 0) {
            gMfsError = 0x106;
            return -1;
        }
        if (Mfs_RamGetFreeSize() < fileSize) {
            gMfsError = N64DD_AREA_LACKED;
            return -1;
        }
        if (Mfs_WriteNewFileInDir(parentDirId, name, extension, buf, fileSize, attr, copyCount) < 0) {
            return -1;
        }
    }

    if (writeChanges) {
        if (Mfs_BackupRamArea() < 0) {
            return -1;
        }
    }
    return 0;
}
