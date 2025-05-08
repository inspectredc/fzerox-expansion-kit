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
    s8 pad_00008[0x36728];
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
