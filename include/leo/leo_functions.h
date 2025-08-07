#ifndef LEO_FUNCTIONS_H
#define LEO_FUNCTIONS_H

#include "libultra/ultra64.h"
#include "gfx.h"
#include "PR/leo.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
#include "unk_leo.h"

void func_80762330(LEODiskTime* diskTime);
void Mfs_SetGameCode(char* companyCode, char* gameCode);
u16 Mfs_GetNextFileInPreparedDir(void);
s32 Mfs_GetFilesPreparation(u16 dirId);
s32 Mfs_ChangeFileInDirAttr(u16 dirId, char* name, char* extension, s32 attributeToAdd, s32 attributeToRemove, bool writeChanges);
s32 Mfs_GetFileInDirAttr(u16 dirId, char* name, char* extension);
void Mfs_SetDirEntryAttr(u16 attr);
void Mfs_SetDirEntryName(char* name);
void Mfs_SetDirEntryCreateTime(void);
void Mfs_SetDirEntryDirId(u16 dirId);
void Mfs_SetDirEntryExtension(char* extension);
void Mfs_SetDirEntryFileSize(s32 fileSize);
void Mfs_CreateDirEntry(u16 parentDirId, char* name);
void Mfs_SetDirEntryCopyCount(s32 copyCount);
void Mfs_SetDirEntryRenewalCounter(u16 renewalCounter);
void Mfs_InitDirEntry(void);
s32 Mfs_CopyDirEntryToRam(u16 entryId);
s32 Mfs_CopyDirEntryFromRam(u16 entryId);
void Mfs_IncreaseFileRC(u16 entryId);
s32 Mfs_ValidateGameCode(u16 entryId);
u16 Mfs_GetFileIndex(u16 dirId, char* name, char* extension);
u16 Mfs_GetDirectoryIndexFromParent(u16 parentDirId, char* name);
u16 Mfs_GetDirectoryIndex(u16 dirId);
u16 Mfs_GetNextFreeDirectoryEntry(void);
s32 Mfs_FindBlocksForSize(u32 sizeRequired, s32* lbaPtr, s32* nLBAsPtr, s32* blockSizePtr);
s32 Mfs_CreateLeoManager(s32 region, OSMesg* cmdBuf, s32 cmdMsgCount);
void func_80760244(void);
s32 Mfs_ReadDiskId(LEODiskID* diskId);
s32 func_80760320(void);
s32 func_807603A8(void);
s32 Mfs_BackupRamArea(void);
s32 Mfs_ValidateRamVolume(void);
s32 func_80760A84(void);
s32 func_80760C2C(void);
s32 func_80760C6C(void);
s32 Mfs_RamGetFreeSize(void);
s32 Mfs_WorkGetFreeSize(void);
s32 Mfs_CalculateVolumeChecksum(void);
s32 Mfs_CheckChecksum(void);
s32 Mfs_CopyRamAreaFromBackup(void);
s32 Mfs_CreateRootDirectory(bool writeChanges);
s32 Mfs_GetParentDir(u16 dirId);
s32 Mfs_ReadRtc(LEODiskTime* diskTime);
void Mfs_LEODiskTimeToMfsTime(LEODiskTime* diskTime, MfsTimeFormat* mfsTime);
s32 func_80762390(void);
s32 Mfs_SpdlMotor(LEOSpdlMode mode);
s32 Mfs_ReadLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 Mfs_WriteLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 mfsStrnCmp(u8* b1, u8* b2, size_t length);
s32 mfsStrnCpy(u8* dest, u8* src, size_t length);
s32 mfsStrCpy(u8* dest, u8* src);
s32 mfsStrCmp(u8* s1, u8* s2);
s32 Mfs_DecodeTime(s32);
s32 Mfs_EncodeTime(s32);
s32 mfsStrLen(u8* str);
s32 Mfs_ValidateFileName(char* name);
s32 Mfs_SaveFile(u16 parentDirId, char* name, char* extension, u8* buf, u32 fileSize, s32 attr, s32 copyCount, bool writeChanges);
s32 Mfs_CopyFATFromRam(void);
s32 Mfs_CopyFATToRam(void);
s32 Mfs_AddFileAllocationTableEntry(s32* fatIdPtr, s32 lba, s32 nLBAs);
s32 Mfs_ClearFileAllocationTableEntry(s32 fatId);
s32 Mfs_GetFileExtraBlockSpace(s32* fatIdPtr, u32 fileSize, s32* extraSpace);
s32 Mfs_GetFileExtraBlockSpace2(s32* fatIdPtr, u32 fileSize, s32* extraSpace);
s32 Mfs_GetFileLbaCount(s32 fatId);
s32 Mfs_DeleteFileInDir(u16 dirId, char* name, char* extension, bool writeChanges);
s32 Mfs_LoadFileInDir(u16 dirId, char* name, char* extension, u8* buf, s32 sizeToLoad);
s32 Mfs_LoadFileInDirFromOffset(u16 dirId, char* name, char* extension, u8* buf, s32 offset, s32 sizeToLoad);
s32 Mfs_WriteFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 Mfs_ReadFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 Mfs_RenameFileInDir(u16 dirId, char* oldName, char* oldExtension, char* newName, char* newExtension, bool writeChanges);
void Mfs_SetLeoHandlerFuncs(void);
s32 Mfs_ValidateFileSystemOperation(s32 validationFlags, u16 entryIndex, u16 subEntryIndex, u16 dirId);

#endif // LEO_FUNCTIONS_H
