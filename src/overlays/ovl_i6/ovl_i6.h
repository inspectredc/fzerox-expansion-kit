#ifndef OVL_I6_H
#define OVL_I6_H

typedef enum OptionsRow {
    /* 0 */ OPTIONS_VS_COM,
    /* 1 */ OPTIONS_VS_SLOT,
    /* 2 */ OPTIONS_VS_HANDICAP,
    /* 3 */ OPTIONS_SOUND_MODE,
    /* 4 */ OPTIONS_DATA_CLEAR,
    /* 5 */ OPTIONS_GHOST_COPY,
    /* 6 */ OPTIONS_EXIT,
    /* 7 */ OPTIONS_MAX
} OptionsRow;

#define OPTIONS_DATA_CLEAR_MENU_CLOSED 0
#define OPTIONS_DATA_CLEAR_MENU_OPEN 1

typedef struct OptionsTextureInfo {
    /* 0x00 */ void* textureOffset;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
} OptionsTextureInfo; // size = 0x8

#define OPTIONS_REQUIRE_SELECTING 1
#define OPTIONS_SHOWN 2

typedef struct OptionsInfo {
    /* 0x00 */ OptionsRow row;
    /* 0x04 */ u16 flags;
    /* 0x08 */ s32 totalSelectionStates;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ OptionsTextureInfo* selectionStateTextureInfo;
    /* 0x18 */ OptionsTextureInfo optionTextureInfo;
} OptionsInfo; // size = 0x20

void Credits_ObjectInit(s32 cmdId, s32 left, s32 top, s8 priority);

void func_i6_80082A24(void);
bool func_i6_80082DB4(void);
void func_i6_800831E8(void);
void func_i6_80083390(void);
Gfx* func_i6_800837F4(Gfx*, s32, s32);
void func_i6_80083A20(void);
Gfx* func_i6_80083F54(Gfx* gfx);

s32 func_i6_80084260(void);

#endif // OVL_I6_H
