#ifndef SYS_H
#define SYS_H

#include "PR/xstdio.h"
#include "PR/controller.h"
#include "libultra/ultra64.h"
#include "libc/stdarg.h"
#include "libc/stdbool.h"
#include "libc/stdint.h"
#include "libc/stddef.h"
#include "libc/string.h"
#include "gfx.h"
#include "buffers.h"
#include "other_types.h"
#include "segment_symbols.h"

#define CLEAR_OVERLAY_CACHE(textStart, textSize, dataStart, dataSize)  \
    {                                                                  \
        OSIntMask prevMask = osGetIntMask();                           \
        osSetIntMask(OS_IM_NONE);                                      \
        osInvalICache(textStart, textSize);                            \
        osInvalDCache(dataStart, dataSize);                            \
        osSetIntMask(prevMask);                                        \
    }

#define CLEAR_TEXT_CACHE(vaddr, nbytes)        \
    {                                          \
        OSIntMask prevMask = osGetIntMask();   \
        osSetIntMask(OS_IM_NONE);              \
        osInvalICache(vaddr, nbytes);          \
        osSetIntMask(prevMask);                \
    }

#define CLEAR_DATA_CACHE(vaddr, nbytes)        \
    {                                          \
        OSIntMask prevMask = osGetIntMask();   \
        osSetIntMask(OS_IM_NONE);              \
        osInvalDCache(vaddr, nbytes);          \
        osSetIntMask(prevMask);                \
    }

// FAKE!!
typedef struct unk_Light_t {
    s8 unk_00[0x8];
    s16 unk_08[3];
} unk_Light_t;

typedef union unk_Light {
    unk_Light_t l;
    long long int force_structure_alignment[2];
} unk_Light;

// ROUGH APPROXIMATIONS OF SIZES, NOT CORRECT!!

typedef struct GfxPool {
    Gfx gfxBuffer[1];
    s8 pad_00008[0x1A000];
    Mtx unk_1A008[4];
    Mtx unk_1A108[4];
    Mtx unk_1A208[4];
    Vtx unk_1A308[4096];
    Vtx unk_2A308[2048];
    Mtx unk_32308[30];
    Mtx unk_32A88[30];
    Mtx unk_33208[30];
    Mtx unk_33988[4];
    Lights1 unk_33A88[4];
    unk_Light unk_33AE8[4];
    LookAt unk_33B28;
    Vtx unk_33B48[28];
    Vtx unk_33D08[4];
    s8 pad_33D48[0x500];
    Vtx unk_34248[256];
    Mtx unk_35248[1];
    Mtx unk_35288[1];
    Mtx unk_352C8[64];
    Vp unk_362C8[4];
    Vp unk_36308[6];
    Mtx unk_36368[6];
    Vtx unk_364E8[4];
    u16 unk_36528[6][16];
    Vtx unk_365E8[4];
    Mtx unk_36628[1];
    Mtx unk_36668[1];
    Mtx unk_366A8[1];
    s8 pad_366E8[0x48];
} GfxPool; // size = 0x36730

typedef struct {
    /* 0x000 */ OSThread thread;
    /* 0x1B0 */ char stack[0x800];
    /* 0x9B0 */ OSMesgQueue mesgQueue;
    /* 0x9C8 */ OSMesg msg;
    /* 0x9CC */ FrameBuffer* fb;
    /* 0x9D0 */ u16 width;
    /* 0x9D2 */ u16 height;
} FaultMgr; // size = 0x9D8, 0x8 aligned

#endif // SYS_H
