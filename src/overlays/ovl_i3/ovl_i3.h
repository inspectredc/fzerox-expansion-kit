#ifndef OVL_I3_H
#define OVL_I3_H

#include "unk_structs.h"

typedef struct unk_8013E7A8 {
    s16 unk_00;
    s8 unk_02;
    s8 unk_03[3];
    s8 unk_06[8];
} unk_8013E7A8; // size = 0xE

typedef struct unk_801437C0 {
    s8 unk_00;
    s8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
} unk_801437C0; // size = 0xA

typedef struct unk_8012F450 {
    /* 0x00 */ s32 time;
    /* 0x04 */ u8 hours;
    /* 0x05 */ u8 minutes;
    /* 0x08 */ f32 minuteFraction;
} unk_8012F450; // size = 0xC

typedef struct unk_80141EA8 {
    s32 unk_00;
    s32 unk_04;
    s32 lapIntervalCounter;
    unk_8012F450 unk_0C;
    s8 unk_18[0x30];
} unk_80141EA8; // size = 0x48


typedef enum RaceMenuTextures{
    /* 0x00 */ RACE_MENU_RETRY,                 // retry
    /* 0x01 */ RACE_MENU_SETTINGS,              // settings
    /* 0x02 */ RACE_MENU_QUIT,                  // quit
    /* 0x03 */ RACE_MENU_CHANGE_MACHINE,        // change machine
    /* 0x04 */ RACE_MENU_CHANGE_COURSE,         // change course
    /* 0x05 */ RACE_MENU_GHOST_SAVE,            // ghost save
    /* 0x06 */ RACE_MENU_OVERWRITE_DATA1,       // overwrite data?
    /* 0x07 */ RACE_MENU_SAVING,                // saving
    /* 0x08 */ RACE_MENU_TO_GAME_PAK,           // to game pak
    /* 0x09 */ RACE_MENU_TO_DISK,               // to disk
    /* 0x0A */ RACE_MENU_OVERWRITE_DATA2,       // overwrite data?
    /* 0x0B */ RACE_MENU_CLEAR_RECORD,          // clear record
    /* 0x0C */ RACE_MENU_ERASE_COURSE_DATA1,    // erase saved data for this course?
    /* 0x0D */ RACE_MENU_CLEAR_GHOST,           // clear ghost
    /* 0x0E */ RACE_MENU_ERASE_COURSE_DATA2,    // erase saved data for this course?
    /* 0x0F */ RACE_MENU_CONTINUE,              // continue
    /* 0x10 */ RACE_MENU_YES,                   // yes
    /* 0x11 */ RACE_MENU_NO,                    // no
    /* 0x12 */ RACE_MENU_SAVED,                 // saved
    /* 0x13 */ RACE_MENU_NEW_GHOST,             // new ghost
    /* 0x14 */ RACE_MENU_SAVED_GHOST,           // saved ghost
    /* 0x15 */ RACE_MENU_CANNOT_SAVE_GHOST,     // race data cannot be saved for ghost
    /* 0x16 */ RACE_MENU_LEFT_ARROW,            // left arrow
    /* 0x17 */ RACE_MENU_RIGHT_ARROW,           // right arrow
    /* 0x18 */ RACE_MENU_MAX,
} RaceMenuTextures;

typedef enum TimeAttackFinishOptions {
    /* 0 */ TIME_ATTACK_RETRY,
    /* 1 */ TIME_ATTACK_SAVE_GHOST,
    /* 2 */ TIME_ATTACK_SETTINGS,
    /* 3 */ TIME_ATTACK_CHANGE_MACHINE,
    /* 4 */ TIME_ATTACK_CHANGE_COURSE,
    /* 5 */ TIME_ATTACK_QUIT,
} TimeAttackFinishOptions;

typedef enum PauseGeneralOptions {
    /* 0 */ PAUSE_GENERAL_CONTINUE,
    /* 1 */ PAUSE_GENERAL_RETRY,
    /* 2 */ PAUSE_GENERAL_SETTINGS,
    /* 3 */ PAUSE_GENERAL_CHANGE_MACHINE,
    /* 4 */ PAUSE_GENERAL_CHANGE_COURSE,
    /* 5 */ PAUSE_GENERAL_QUIT,
} PauseGeneralOptions;

typedef enum PauseDeathRaceOptions {
    /* 0 */ PAUSE_DEATH_RACE_CONTINUE,
    /* 1 */ PAUSE_DEATH_RACE_RETRY,
    /* 2 */ PAUSE_DEATH_RACE_SETTINGS,
    /* 3 */ PAUSE_DEATH_RACE_CHANGE_MACHINE,
    /* 4 */ PAUSE_DEATH_RACE_QUIT,
} PauseDeathRaceOptions;

typedef enum PauseGpOptions {
    /* 0 */ PAUSE_GP_CONTINUE,
    /* 1 */ PAUSE_GP_RETRY,
    /* 2 */ PAUSE_GP_SETTINGS,
    /* 3 */ PAUSE_GP_QUIT,
} PauseGpOptions;

#define MENU_STATE_PAUSE_GAME (1 << 0)
#define MENU_STATE_UNPAUSE_GAME (1 << 1)
#define MENU_STATE_RACE_FINISH_SAVE (1 << 2)
#define MENU_STATE_RETRY (1 << 3)
#define MENU_STATE_QUIT (1 << 4)
#define MENU_STATE_CHANGE_MACHINE (1 << 5)
#define MENU_STATE_CHANGE_COURSE (1 << 6)
#define MENU_STATE_SETTINGS (1 << 7)
#define MENU_STATE_100 (1 << 8)
#define MENU_STATE_GP_NEXT_COURSE (1 << 9)
#define MENU_STATE_400 (1 << 10)

extern s32 gPlayerLapNumbers[];
extern TexturePtr gCharacterPortraitTextures[];

extern s32 gPlayerMinimapLapCounterToggle[];

Gfx* func_i3_DrawRaceTimeInterval(Gfx* gfx, s32 time, s32 left, s32 top, f32 scale);
Gfx* func_i3_DrawBlankTimeHundredths(Gfx* gfx, s32 left, s32 top);
Gfx* func_i3_DrawBlankTimeThousandths(Gfx* gfx, s32 left, s32 top);

Gfx* func_i3_80059D90(Gfx* gfx, s32 playerIndex);

Gfx* func_i3_80066D80(Gfx*, s32, MachineInfo*);
Gfx* func_i3_80066DF8(Gfx*, s32, s32, f32);
void func_i3_80067150(s32 courseIndex);
void func_i3_80067208(void);
void func_i3_80067280(void);
void func_i3_8006735C(void);
void func_i3_80067580(void);
void func_i3_800675B4(s32);
void func_i3_800678D8(void);
s32 func_i3_800683B4(s8 character);
void func_i3_80068414(CourseInfo* courseInfo);
Gfx* func_i3_800684CC(Gfx* gfx);

#endif // OVL_I3_H
