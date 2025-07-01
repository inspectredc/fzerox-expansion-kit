#ifndef FZX_SAVE_H
#define FZX_SAVE_H

#include "libc/stdbool.h"
#include "fzx_ghost.h"

typedef struct SaveCourseRecords {
    u16 checksum;
    s16 unk_02;
    s32 timeRecord[5];
    f32 engines[5];
    f32 maxSpeed;
    s32 bestTime;
    u8 name[5][4];
    u8 unk_48[8];
    unk_80141C88_unk_1D unk_50[5];
    unk_80141C88_unk_1D unk_F0;
} SaveCourseRecords; // size = 0x110

typedef struct CharacterSave {
    u16 checksum;
    u16 unk_02;
    s32 unk_04;
    f32 characterEngine[30];
} CharacterSave; // size = 0x80

typedef struct SaveEditCup {
    u16 checksum;
    s16 unk_02;
    s32 unk_04;
    s16 unk_08;
    u8 editCupTrackNames[6][9];
} SaveEditCup; // size = 0x40

typedef struct SaveEditCup2 {
    u16 checksum;
    u16 unk_02;
    u8 unk_04[30 * 2];
} SaveEditCup2; // size = 0x40

typedef struct SaveSettings {
    u8 fileName[8];
    u8 settings;
    u8 customUnlocks;
    u8 cupDifficultiesCleared[4];
    u16 checksum;
} SaveSettings; // size = 0x10

typedef struct SaveDeathRace {
    u16 checksum;
    s16 unk_02;
    s32 timeRecord[1];
    u8 unk_08[8];
} SaveDeathRace; // size = 0x10

typedef struct ProfileSave {
    SaveSettings saveSettings;
    SaveDeathRace deathRace;
    SaveCourseRecords courses[24];
    union {
        SaveEditCup editCup;
        SaveEditCup2 editCup2;
    };
} ProfileSave; // size = 0x19E0

typedef struct GhostRecord {
    u16 checksum;
    u16 ghostType;
    s32 replayChecksum;
    s32 encodedCourseIndex;
    s32 raceTime;
    u16 unk_10;
    s8 unk_12[5];
    u8 trackName[9];
    unk_80141C88_unk_1D unk_20;
} GhostRecord; // size = 0x40

typedef struct GhostReplayInfo {
    /* 0x00 */ u16 checksum;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 lapTimes[3];
    /* 0x10 */ s32 end;
    /* 0x14 */ u32 size;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} GhostReplayInfo; // size = 0x20

typedef struct GhostData {
    /* 0x0000 */ GhostReplayInfo replayInfo;
    /* 0x0020 */ u8 replayData[16200];
    /* 0x3F68 */ s8 unk_3F68[0x18];
} GhostData; // size = 0x3F80

typedef struct CupSave {
    u16 checksum;
    s8 unk_02[0xE];
    u16 cupCompletion[4][10];
} CupSave; // size = 0x60

typedef struct GhostSave {
    GhostRecord record;
    GhostData data;
} GhostSave;

typedef struct SaveContext {
    ProfileSave profileSaves[2];
    GhostSave ghostSave;
    CharacterSave characterSaves[24];
    CupSave cupSave;
    s8 unk_7FE0[0x20];
} SaveContext; // size = 0x8000

// extern u8 gSaveBuffer[];
extern SaveContext gSaveContext;

s32 func_i2_800A5F58(s32 courseIndex, s32 encodedCourseIndex);
s32 Save_LoadPlayerGhost(s32 courseIndex, s32 encodedCourseIndex, s32 ghostIndex);

bool func_i2_800A68A8(GhostInfo* ghostInfo);

void Save_SaveGhostRecord(Ghost* ghost);
void Save_SaveGhostData(Ghost* ghost);
void Save_SaveSettings(SaveSettings* saveSettings);
void Save_SaveDeathRace(SaveDeathRace* deathRace);
void Save_SaveCourseRecord(SaveCourseRecords* courseRecords, s32 courseIndex);
void Save_SaveCharacterSave(CharacterSave* characterSave);

s32 Save_Init(SaveContext* saveContext, s32 arg1);
void Save_CreateNew(SaveContext* saveContext, s32 arg1);

void Save_InitSaveSettings(SaveSettings* saveSettings, bool shouldClear);
void Save_InitDeathRace(SaveDeathRace* deathRace, bool shouldClear);
void Save_InitEditCup(SaveEditCup* editCup, bool shouldClear);
void Save_InitCourseRecord(SaveCourseRecords* courseRecords, bool shouldClear);
void Save_InitGhostRecord(GhostRecord* ghostRecord, bool shouldClear);
void Save_InitGhostData(GhostData* ghostData, bool shouldClear);
void Save_InitCharacterSave(CharacterSave* characterSave, bool shouldClear);

void func_i2_800A7438(GhostRecord* ghostRecord, GhostInfo* ghostInfo);
void func_i2_800A7C84(GhostRecord* ghostRecord);

void func_i2_800A88D8(unk_80141C88_unk_1D* arg0, MachineInfo* arg1);

void Save_Load(SaveContext* saveContext);
void Save_LoadSaveSettings(ProfileSave* profileSaves, bool arg1);
void Save_LoadDeathRace(ProfileSave* profileSaves);
void Save_LoadCourseRecord(ProfileSave* profileSaves, s32 courseIndex);
void Save_LoadCourseRecord2(SaveCourseRecords* courseRecord, s32 courseIndex);
s32 Save_LoadGhostInfo(GhostInfo* ghostInfo);
void Save_LoadGhostRecord(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3);
void Save_LoadGhostData(GhostRecord* ghostRecord, GhostData* ghostData, Ghost* ghost, bool arg3);
void Save_LoadCharacterSave(CharacterSave* characterSave, s32 courseIndex);
void Save_LoadCupSave(CupSave* cupSave, u8* arg1);
void Save_LoadEditCup2(ProfileSave* profileSaves, u8* arg1, u16* arg2);

s32 Save_CalculateSaveSettingsChecksum(ProfileSave* profileSave);
s32 Save_CalculateSaveDeathRaceChecksum(ProfileSave* profileSave);
s32 Save_CalculateProfileSaveCourseRecordChecksum(ProfileSave* profileSave, s32 courseIndex);
s32 Save_CalculateSaveCourseRecordChecksum(SaveCourseRecords* courseRecords);
s32 Save_CalculateSaveEditCupChecksum(ProfileSave* profileSave);
s32 Save_CalculateSaveEditCup2Checksum(ProfileSave* profileSave);
s32 Save_CalculateGhostRecordChecksum(GhostRecord* ghostRecord);
s32 Save_CalculateGhostDataChecksum(GhostData* ghostData);
s32 Save_CalculateCharacterSaveChecksum(CharacterSave* characterSave);
s32 Save_CalculateCupSaveChecksum(CupSave* cupSave);

void Save_ClearData(void* data, s32 size);

void Sram_ReadWrite(s32 direction, u32 offset, void* dramAddr, size_t size);

void func_i2_800A9894(GhostRecord* ghostRecord, s32 courseIndex);
void func_i2_800A98E4(GhostData* ghostData, s32 courseIndex);
s32 Save_LoadStaffGhost(s32 courseIndex, s32 encodedCourseIndex);
void func_i2_800A9A54(GhostData* ghostData, s32 courseIndex);

void func_i2_800A9CE0(s32 courseIndex, GhostRecord* ghostRecord);
void func_i2_800AA024(s32 courseIndex, s32 ghostIndex, GhostData* ghostData);
void func_i2_800AA864(s32 courseIndex);
void func_i2_800AAA14(s32 ghostIndex, GhostRecord* ghostRecord);
void func_i2_800AAA64(s32 ghostIndex, GhostData* ghostData);
void func_i2_800AAAC0(s32 courseIndex);

#define REPLAY_DATA_LARGE_FLAG -0x80
#define REPLAY_DATA_LARGE(x) REPLAY_DATA_LARGE_FLAG, (((x) >> 8) & 0xFF), ((x) & 0xFF)

#endif // FZX_SAVE_H
