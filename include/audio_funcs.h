#ifndef AUDIO_FUNCS_H
#define AUDIO_FUNCS_H

#include "audio.h"

// Temp include for external audio funcs and unmigrated funcs

s32 func_80735ECC(s32 unkMediumParam, uintptr_t* devAddrPtr);
void func_807383B0(s32 unkMediumParam, uintptr_t devAddr, u8* ramAddr, size_t size);

void func_80738944(void);
void func_80739EE0(void);

void func_80740740(u8);
void func_8074184C(u8);
void func_80741888(u8 channelIndex, u8 ioData);
void func_807418D4(u8 channelIndex);
void func_8074251C(void);


#endif // AUDIO_FUNCS_H
