#ifndef LEO_FUNCTIONS_H
#define LEO_FUNCTIONS_H

#include "libultra/ultra64.h"
#include "gfx.h"
#include "PR/leo.h"
#include "libc/stdint.h"
#include "unk_leo.h"

void func_8075F2B0(u16);
void func_8075F3A0(u8*);
void func_8075F3FC(void);
void func_8075F438(u16);
void func_8075F454(u8*);
void func_8075F4B0(s32);
void func_8075F4C8(u16, u8*);
void func_8075F520(s32);
void func_8075F538(u16);
void func_8075F554(void);
s32 func_8075F584(u16);
s32 func_8075F600(u16);
void func_8075F67C(u16);
s32 func_8075F714(u16);
u16 func_8075F7C0(u16, u8*, u8*);
u16 func_8075F904(u16, u8*);
u16 func_8075F9E0(u16);
u16 func_8075FABC(void);
s32 func_8075FB38(u32, s32*, s32*, s32*);
s32 func_8076007C(s32, OSMesg*, s32);
void func_80760244(void);
s32 func_80760260(LEODiskID*);
s32 func_80760320(void);
s32 func_807603A8(void);
s32 func_807608A4(void);
s32 func_807609F4(void);
s32 func_80760A84(void);
s32 func_80760C2C(void);
s32 func_80760C6C(void);
s32 func_80760D78(void);
s32 func_80760E5C(void);
s32 func_80760FE4(void);
s32 func_807610AC(void);
s32 func_80761238(void);
s32 func_80761390(s32);
s32 func_80761590(u16);
s32 func_807620C0(LEODiskTime*);
void func_80762184(LEODiskTime*, unk_leo_timeformat*);
s32 func_80762390(void);
s32 func_80762458(u8);
s32 func_80762570(u32, u8*, u32);
s32 func_80762768(u32, u8*, u32);
s32 Leo_bcmp(u8*, u8*, size_t);
s32 Leo_bcopy(u8*, u8*, size_t);
s32 Leo_strcpy(u8* dest, u8* src);
s32 Leo_strcmp(u8* s1, u8* s32);
s32 Leo_DecodeTime(s32);
s32 Leo_EncodeTime(s32);
s32 Leo_strlen(u8*);
s32 func_80762D80(u8*);
s32 func_8076321C(u16, u8*, u8*, s32, u32, s32, s32, s32);
s32 func_807648D0(void);
s32 func_80764914(void);
s32 func_80764958(s32*, s32, s32);
s32 func_80764A4C(s32);
s32 func_80764B04(s32*, u32, s32*);
s32 func_80764C54(s32*, u32, s32*);
s32 func_80764D4C(s32);
s32 func_80764E90(u16, u8*, u8*, s32);
s32 func_8076543C(u16, u8*, u8*, u8*, s32);
s32 func_80765BC8(u16, u8*, u8*, u8*, s32, s32);
s32 func_80766124(s32, u8*, u32, s32);
s32 func_80766248(s32, u8*, u32, s32);
s32 func_80766434(u16, u8*, u8*, u8*, u8*, s32);
void func_80766860(void);
s32 func_80766CC0(s32, u16, u16, u16);

#endif // LEO_FUNCTIONS_H
