#ifndef AUDIO_FUNCS_H
#define AUDIO_FUNCS_H

#include "audio.h"

// Temp include for external audio funcs and unmigrated funcs

s32 AudioLoad_GetStartLbaAddr(s32 lba, uintptr_t* devAddrPtr);
void AudioLoad_DiskDrive(s32 lba, uintptr_t devAddr, u8* ramAddr, s32 totalSize);
s32 AudioLoad_DiskInit(AudioDiskInfo*, s32, uintptr_t, u8*, s32);
s32 AudioLoad_DiskLoad(AudioDiskInfo*);
void func_80738B84(unk_807C1948* arg0);

void func_80738944(void);
void func_80739EE0(void);

void func_80740740(u8);
void func_8074184C(u8);
void func_80741888(u8 channelIndex, u8 ioData);
void func_807418D4(u8 channelIndex);
void func_8074251C(void);


#endif // AUDIO_FUNCS_H
