#ifndef FZX_GHOST_H
#define FZX_GHOST_H

#include "libultra/ultra64.h"
#include "fzx_math.h"
#include "fzx_racer.h"
#include "fzx_machine.h"

typedef enum GhostType {
    /* 0 */ GHOST_NONE,
    /* 1 */ GHOST_PLAYER,
    /* 2 */ GHOST_STAFF,
    /* 3 */ GHOST_CELEBRITY,
    /* 4 */ GHOST_CHAMP,
} GhostType;

typedef struct GhostInfo {
    /* 0x00 */ s32 courseIndex;
    /* 0x04 */ s32 encodedCourseIndex;
    /* 0x08 */ s32 raceTime;
    /* 0x0C */ s32 replayChecksum;
    /* 0x10 */ u16 ghostType;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ char trackName[9];
    /* 0x1D */ unk_80141C88_unk_1D unk_1D;
} GhostInfo; // size = 0x40

typedef struct Ghost {
    /* 0x0000 */ s32 encodedCourseIndex;
    /* 0x0004 */ s32 raceTime;
    /* 0x0008 */ s32 lapTimes[3];
    /* 0x0014 */ s32 replayEnd;
    /* 0x0018 */ s32 replaySize;
    /* 0x001C */ s8 replayData[16200];
    /* 0x3F64 */ s32 replayChecksum;
    /* 0x3F68 */ s16 ghostType;
    /* 0x3F6A */ MachineInfo machineInfo;
} Ghost; // size = 0x3F80

typedef struct GhostRacer {
    s32 frameCount;
    Ghost* ghost;
    s8* replayPtr;
    s32 replayIndex;
    s16 initialized;
    s16 exists;
    s32 replayPosX;
    s32 replayPosY;
    s32 replayPosZ;
    Vec3f pos;
    f32 scale;
    Racer* racer;
} GhostRacer; // size 0x34

#endif // FZX_GHOST_H
