#include "audio.h"
#include "macros.h"

typedef struct unk_806F2350 {
    s8 pad[0x6C];
} unk_806F2350; // size >= 0x6C

s8 audioPad806ECA00[0x10];
AudioContext gAudioCtx;
AudioCustomUpdateFunction gAudioCustomUpdateFunction;
OSMesgQueue D_806F2328; ALIGNED(8)
OSMesg D_806F2340[1];
s32 D_806F2348[2];
unk_806F2350 D_806F2350;
