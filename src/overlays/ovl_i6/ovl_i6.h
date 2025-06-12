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

#endif // OVL_I6_H
