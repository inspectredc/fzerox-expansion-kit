#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "PR/leo.h"

typedef struct unk_807C6F10 {
    s32 unk_00;
    s32 lba;
    s32 unk_08;
    s32 unk_0C;
    OSPiHandle* unk_10;
    OSIoMesg* unk_14;
    s32 unk_18;
    LEOCmd* cmdBlock;
    OSMesgQueue* mq;
} unk_807C6F10;

typedef struct unk_807C6EA8 {
    s32 unk_00;
    s8 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s8 unk_14[0x2];
    u16 unk_16;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    s32 unk_34;
    s32 unk_38;
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    s32 unk_48;
    s32 unk_4C;
    s32 unk_50;
    u8 unk_54;
    s32 unk_58;
    s32 unk_5C;
    s32 unk_60;
} unk_807C6EA8;

typedef struct unk_80225800 {
    Mtx unk_000;
    Vtx unk_040[4][6];
    Vtx unk_1C0[48][5];
} unk_80225800; // size = 0x10C0

#endif // UNK_STRUCTS_H
