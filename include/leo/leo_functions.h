#ifndef LEO_FUNCTIONS_H
#define LEO_FUNCTIONS_H

#include "libultra/ultra64.h"
#include "gfx.h"
#include "PR/leo.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
#include "unk_leo.h"

void Mfs_SetDirEntryAttr(u16);
void Mfs_SetDirEntryName(char* name);
void Mfs_SetDirEntryCreateTime(void);
void Mfs_SetDirEntryDirId(u16);
void Mfs_SetDirEntryExtension(u8*);
void Mfs_SetDirEntryFileSize(s32);
void Mfs_CreateDirEntry(u16 parentDirId, char* name);
void Mfs_SetDirEntryCopyCount(s32);
void Mfs_SetDirEntryRenewalCounter(u16);
void Mfs_InitDirEntry(void);
s32 Mfs_CopyDirEntryToRam(u16);
s32 Mfs_CopyDirEntryFromRam(u16);
void Mfs_IncreaseFileRC(u16);
s32 func_8075F714(u16);
u16 Mfs_GetFileIndex(u16, char*, char*);
u16 Mfs_GetDirectoryIndexFromParent(u16, u8*);
u16 Mfs_GetDirectoryIndex(u16);
u16 Mfs_GetNextFreeDirectoryEntry(void);
s32 func_8075FB38(u32, s32*, s32*, s32*);
s32 func_8076007C(s32, OSMesg*, s32);
void func_80760244(void);
s32 Mfs_ReadDiskId(LEODiskID*);
s32 func_80760320(void);
s32 func_807603A8(void);
s32 Mfs_WriteRamArea(void);
s32 Mfs_ValidateRamVolume(void);
s32 func_80760A84(void);
s32 func_80760C2C(void);
s32 func_80760C6C(void);
s32 func_80760D78(void);
s32 Mfs_RamGetFreeSize(void);
s32 func_80760FE4(void);
s32 func_807610AC(void);
s32 func_80761238(void);
s32 Mfs_CreateRootDirectory(bool);
s32 Mfs_GetParentDir(u16);
s32 Mfs_ReadRtc(LEODiskTime*);
void Mfs_LEODiskTimeToMfsTime(LEODiskTime* diskTime, MfsTimeFormat* mfsTime);
s32 func_80762390(void);
s32 Mfs_SpdlMotor(LEOSpdlMode mode);
s32 Mfs_ReadLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 Mfs_WriteLBA(u32 startLBA, u8* buf, u32 nLBAs);
s32 mfsStrnCmp(u8*, u8*, size_t);
s32 mfsStrnCpy(u8*, u8*, size_t);
s32 mfsStrCpy(u8* dest, u8* src);
s32 mfsStrCmp(u8* s1, u8* s2);
s32 Mfs_DecodeTime(s32);
s32 Mfs_EncodeTime(s32);
s32 mfsStrLen(u8*);
s32 Mfs_ValidateFileName(char*);
s32 func_8076321C(u16, u8*, u8*, s32, u32, s32, s32, s32);
s32 Mfs_CopyFATFromRam(void);
s32 Mfs_CopyFATToRam(void);
s32 func_80764958(s32*, s32, s32);
s32 func_80764A4C(s32);
s32 func_80764B04(s32*, u32, s32*);
s32 func_80764C54(s32*, u32, s32*);
s32 func_80764D4C(s32);
s32 func_80764E90(u16, u8*, u8*, s32);
s32 func_8076543C(u16, u8*, u8*, u8*, s32);
s32 func_80765BC8(u16, char*, u8*, u8*, s32, s32);
s32 Mfs_WriteFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 Mfs_ReadFile(s32 startLBA, u8* buf, u32 nLBAs, bool isEncoded);
s32 func_80766434(u16, u8*, u8*, u8*, u8*, s32);
void func_80766860(void);
s32 func_80766CC0(s32, u16, u16, u16);

#endif // LEO_FUNCTIONS_H
