#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "libultra/ultra64.h"
#include "gfx.h"
#include "PR/leo.h"

void Game_ThreadEntry(void* arg0);
void Audio_ThreadEntry(void* arg0);

void func_80703F90(void);
void func_80767958(void*);
s32 func_80768AF0(s32, s32, s32, s32, s32, s32);
s32 func_80768C08(s32, s32, s32);
s32 Segment_SetPhysicalAddress(s32 segment, s32 addr);
Gfx* Segment_SetTableAddresses(Gfx*);

s32 func_8075AA60(void);
s32 func_8075A020(void);
void func_8070F240(void);
void func_80704DB0(char*, LEODiskID*);
void func_8070F0F0(void);
void func_80704F38(OSThread*);
void func_8073631C(void*);
void func_80736328(void*);
void Fault_Init(void);
void Fault_SetFrameBuffer(FrameBuffer* buffer, u16 width, u16 height);
void Audio_PreNMI(void);
void func_806F5A50(void);

void func_806F5310(void);
Gfx* func_806F59E0(Gfx*);
void func_80709C3C(void);
void func_80745CB8(void);

Gfx* func_8002ED64(Gfx*);
Gfx* func_8002F9DC(Gfx*);

void func_800A2CCC(void);

#endif // FUNCTIONS_H
