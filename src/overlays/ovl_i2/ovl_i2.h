#ifndef OVL_I2_H
#define OVL_I2_H

#include "libultra/ultra64.h"
#include "other_types.h"

typedef struct unk_8010D778_unk_18 {
    s8 unk_00;
    u8 unk_01;
} unk_8010D778_unk_18; // size = 0x2

typedef struct unk_8010D778_unk_18_2 {
    s8 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} unk_8010D778_unk_18_2; // size = 0x1C

typedef struct unk_8010D778_unk_18_3 {
    s8 unk_00;
    s8 unk_01;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_8010D778_unk_18_3; // size = 0x14

typedef struct unk_8010D778_unk_1C {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
} unk_8010D778_unk_1C; // size = 0x14

typedef struct unk_8010D778 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    TexturePtr unk_14;
    void* unk_18;
    unk_8010D778_unk_1C unk_1C;
} unk_8010D778; // size = 0x30

s32 func_i2_800A250C(s32, s32);
void func_i2_800A26C0(s32, s32);
s32 func_i2_800A26D4(s32, s32);
s32 func_i2_800A27C4(void);
void func_i2_800A28D0(unk_8010D778*);
void func_i2_800A2E34(unk_8010D778*);
void func_i2_800A2F14(unk_8010D778*);
bool func_i2_800A2FC0(unk_8010D778*);
s32 func_i2_800A31C8(unk_8010D778*, s32, s32*);
s32 func_i2_800A32C0(unk_8010D778*, s32);
void func_i2_800A3300(unk_8010D778*, s32, s8);
Gfx* func_i2_800A3350(Gfx*, unk_8010D778*);
void func_i2_800A3564(unk_8010D778*);
void func_i2_800A35B8(unk_8010D778*);
bool func_i2_800A3620(unk_8010D778*);
Gfx* func_i2_800A380C(Gfx*, unk_8010D778*);
void func_i2_800A3AC4(unk_8010D778*);
void func_i2_800A3E6C(unk_8010D778*);
bool func_i2_800A4078(unk_8010D778*);
Gfx* func_i2_800A44B4(Gfx*, unk_8010D778*);
void func_i2_800A4860(unk_8010D778*);
void func_i2_800A4C0C(unk_8010D778*);
bool func_i2_800A4E1C(unk_8010D778*);
void func_i2_800A5130(unk_8010D778*, s32, s32);
void func_i2_800A515C(unk_8010D778*);
Gfx* func_i2_800A52A4(Gfx*, unk_8010D778*);
void func_i2_800A5350(unk_8010D778*);
void func_i2_800A53BC(unk_8010D778*);
Gfx* func_i2_800A557C(Gfx*, unk_8010D778*);
void func_i2_800A55F0(unk_8010D778*);
void func_i2_800A5634(unk_8010D778*);
bool func_i2_800A56D4(unk_8010D778*);
Gfx* func_i2_800A5874(Gfx*, unk_8010D778*);
void func_i2_800A5BA8(unk_8010D778*);
void func_i2_800A5BD0(unk_8010D778*);
bool func_i2_800A5C70(unk_8010D778*);
Gfx* func_i2_800A5CD4(Gfx*, unk_8010D778*);

#endif // OVL_I2_H
