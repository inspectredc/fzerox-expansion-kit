#include "audio.h"
#include "macros.h"

s8 audioPad806ECA00[0x10];
AudioContext gAudioCtx;
AudioCustomUpdateFunction gAudioCustomUpdateFunction;
OSMesgQueue D_806F2328 ALIGNED(8);
OSMesg D_806F2340[1];
LbaVaddrPair D_806F2348;
AudioDiskInfo D_806F2350;

ReverbSettings sReverbSettings[] = {
    { 1, 0x20, 0x7000, 0, 0, 0x7FFF, 0x0000, 0x0000, 0xFF, 0x0, 0x0, 0x0 },
};

AudioSpec gAudioSpecs[] = {
    { 32000, 1, 10, 2, 0, 0, ARRAY_COUNT(sReverbSettings), sReverbSettings, 0x400, 0x200, 0x7FFF, 0, 0, 0x2AB00, 0, 0,
      0x24C100, 0x52F00, 0 },
};

s32 D_80771DC0 = 0x384;
s32 D_80771DC4 = 0x38E;
s32 gSoundFontTableLba = 0x3E8;
s32 gSequenceTableLba = 0x3EA;
s32 gSampleBankTableLba = 0x3EC;
