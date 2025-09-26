#ifndef AUDIO_FUNCS_H
#define AUDIO_FUNCS_H

#include "audio.h"

// Temp include for external audio funcs and unmigrated funcs

s32 AudioLoad_GetStartLbaAddr(s32 lba, uintptr_t* devAddrPtr);
void AudioLoad_DiskDrive(s32 lba, uintptr_t devAddr, u8* ramAddr, s32 totalSize);
s32 AudioLoad_DiskInit(AudioDiskInfo* diskInfo, s32 lba, uintptr_t devAddr, u8* ramAddr, s32 bytesRemaining);
s32 AudioLoad_DiskLoad(AudioDiskInfo* diskInfo);
void func_80738B84(unk_807C1948* arg0);

void func_80738944(void);
void func_80739EE0(void);

void Audio_Reset(u8 playerIndex);
void func_8074184C(u8 playerIndex);
void Audio_SEStart(u8 channelIndex, u8 ioData);
void Audio_StopChannelSE(u8 channelIndex);
void Audio_DisablePlayerSE(void);


#endif // AUDIO_FUNCS_H
