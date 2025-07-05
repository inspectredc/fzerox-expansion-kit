#ifndef UNK_STRUCTS_H
#define UNK_STRUCTS_H

#include "libultra/ultra64.h"
#include "PR/leo.h"
#include "fzx_machine.h"
#include "other_types.h"

typedef struct unk_807C6F10 {
    s32 unk_00;
    s32 lba;
    void* vAddr;
    s32 nLBAs;
    OSPiHandle* piHandle;
    OSIoMesg* ioMesg;
    s32 direction;
    LEOCmd* cmdBlock;
    OSMesgQueue* mq;
} unk_807C6F10;

typedef struct unk_807C6EA8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ u16 dirId;
    /* 0x18 */ char* name;
    /* 0x1C */ char* extension;
    /* 0x20 */ void* writeBuf;
    /* 0x24 */ s32 offset;
    /* 0x28 */ s32 fileSize;
    /* 0x2C */ s32 attr;
    /* 0x30 */ s32 copyCount;
    /* 0x34 */ bool writeChanges;
    /* 0x38 */ void* readBuf;
    /* 0x3C */ char* oldName;
    /* 0x40 */ char* oldExtension;
    /* 0x44 */ char* newName;
    /* 0x48 */ char* newExtension;
    /* 0x4C */ s32 attributeToAdd;
    /* 0x50 */ s32 attributeToRemove;
    /* 0x54 */ u8 unk_54;
    /* 0x58 */ s32 startLba;
    /* 0x5C */ s32 lbaBuf;
    /* 0x60 */ s32 bssSize;
} unk_807C6EA8;

typedef struct unk_80225800 {
    Mtx unk_000;
    Vtx unk_040[4 * 6];
    s8 pad_1C0[0x180];
    Vtx unk_1C0[48 * 5];
} unk_80225800; // size = 0x10C0

typedef struct Player {
    s32 id;
    u32 unk_04;
    s32 cameraSetting;
    s32 cameraLookBackRotate;
    s32 unk_10;
    f32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    Vec3f unk_20;
    Mtx3F unk_2C;
    Vec3f unk_50;
    Mtx3F unk_5C;
    f32 unk_80;
    f32 unk_84;
    Vec3f unk_88;
    Vec3f unk_94;
    f32 unk_A0;
    f32 unk_A4;
    f32 unk_A8;
    f32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    s32 unk_E0;
    s16 unk_E4;
    s16 unk_E6;
    f32 unk_E8;
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    f32 unk_F8;
    f32 unk_FC;
    f32 unk_100;
    f32 unk_104;
    f32 unk_108;
    f32 unk_10C;
    f32 unk_110;
    f32 unk_114;
    u16 unk_118;
    s8 unk_11A[0x2];
    MtxF unk_11C;
    MtxF unk_15C;
    MtxF unk_19C;
} Player; // size = 0x1DC

typedef struct CourseSegment {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ f32 radiusLeft;
    /* 0x1C */ f32 radiusRight;
    /* 0x20 */ s32 trackSegmentInfo;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 length;
    /* 0x2C */ f32 lengthFromStart;
    /* 0x30 */ s32 segmentIndex;
    /* 0x34 */ struct CourseSegment* next;
    /* 0x38 */ struct CourseSegment* prev;
    /* 0x3C */ struct unk_36ED0* unk_3C;
    /* 0x40 */ struct unk_36ED0* unk_40;
    /* 0x44 */ struct unk_802D3D38* unk_44;
    /* 0x48 */ struct unk_802D3D38* unk_48;
    /* 0x4C */ struct unk_802D3978* unk_4C;
    /* 0x50 */ struct unk_802D3978* unk_50;
    /* 0x54 */ struct unk_802D3E38* unk_54;
    /* 0x58 */ struct unk_802D3E38* unk_58;
    /* 0x5C */ s8 unk_5C[0x8]; // likely a pair of unk_802D2D78 struct ptrs
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 unk_68;
    /* 0x6C */ f32 unk_6C;
    /* 0x70 */ f32 unk_70;
    /* 0x74 */ Vec3f quarterMarkPos;
    /* 0x80 */ Vec3f halfMarkPos;
    /* 0x8C */ Vec3f threeQuarterMarkPos;
    /* 0x98 */ f32 quarterMarkLength;
    /* 0x9C */ f32 halfMarkLength;
    /* 0xA0 */ f32 threeQuarterMarkLength;
} CourseSegment; // size = 0xA4

typedef struct CourseInfo {
    /* 0x00 */ s32 encodedCourseIndex;
    /* 0x04 */ s32 courseIndex;
    /* 0x08 */ s32 segmentCount;
    /* 0x0C */ f32 length;
    /* 0x10 */ CourseSegment* courseSegments;
    /* 0x14 */ s16 unk_14[6];
    /* 0x20 */ s32 timeRecord[5];
    /* 0x34 */ MachineInfo recordMachineInfos[5];
    /* 0x98 */ f32 recordEngines[5];
    /* 0xAC */ u8 recordNames[5][4];
    /* 0xC0 */ f32 maxSpeed;
    /* 0xC4 */ MachineInfo maxSpeedMachine;
    /* 0xD8 */ s32 bestTime;
    /* 0xDC */ MachineInfo bestTimeMachine;
} CourseInfo; // size = 0xF0

typedef struct unk_36ED0 {
    s32 trackSegmentInfo;
    s32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    s32 unk_10;
    Vec3f unk_14;
    s16 unk_20[3];
    s16 unk_26[3];
    s16 unk_2C[3];
    s16 unk_32[3];
    s16 unk_38[3];
    s16 unk_3E[3];
    s16 unk_44[3];
    s16 unk_4A[3];
    s16 unk_50;
    s16 unk_52;
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
    s16 unk_5E;
} unk_36ED0; // size = 0x60

typedef struct unk_802D3D38 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    Vec3f unk_30;
    s8 unk_3C[0x4];
} unk_802D3D38; // size = 0x40

typedef struct unk_802D3978 {
    // s32 unk_00; Field Removed in DD Version
    Vec3f unk_04;
    s8 unk_10[0x4];
} unk_802D3978; // size = 0x10

typedef struct unk_802D3E38 {
    s32 effectType;
    f32 unk_04;
    f32 unk_08;
    Vec3f unk_0C;
    Vec3f unk_18;
    s8 unk_24[0x4];
} unk_802D3E38; // size = 0x28

typedef struct unk_8006FF90_arg_1 {
    s32 segmentIndex;
    s32 effectType;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
} unk_8006FF90_arg_1; // size = 0x18

typedef struct unk_802D1B60_unk_00 {
    s32 featureType;
    s32 segmentIndex;
    f32 unk_08;
    f32 unk_0C;
    Vec3f unk_10;
} unk_802D1B60_unk_00; // size = 0x1C

typedef struct unk_802D1B60 {
    unk_802D1B60_unk_00* unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
} unk_802D1B60;

typedef struct unk_802D08E0 {
    Vec3f unk_00;
    Mtx3F unk_0C;
    f32 unk_30;
    struct unk_36ED0* unk_34;
} unk_802D08E0; // size = 0x38

typedef struct unk_802D2D70 {
    unk_8006FF90_arg_1* unk_00;
    s32 count;
} unk_802D2D70;

typedef struct unk_802D2D78 {
    s32 effectType;
    Vtx* vtxStart;
    Vtx* vtxEnd;
    s8 unk_0C[0x4];
} unk_802D2D78; // size = 0x10

typedef struct Racer_unk_C {
    CourseSegment* courseSegment;
    f32 unk_04;
    f32 unk_08;
    Vec3f unk_0C;
    f32 unk_18;
    Vec3f unk_1C;
    Vec3f unk_28;
    Vec3f unk_34;
    f32 unk_40;
    Vec3f unk_44;
} Racer_unk_C; // size >= 0x50

typedef struct Racer {
    s32 id;
    s32 stateFlags;
    u16 unk_08;
    s16 points;
    Racer_unk_C unk_0C;
    Vec3f unk_5C;
    Vec3f unk_68;
    Vec3f velocity;
    Vec3f unk_80;
    Vec3f acceleration;
    f32 speed;
    f32 maxSpeed;
    f32 unk_A0;
    f32 unk_A4;
    Vec3f unk_A8;
    Vec3f unk_B4;
    Mtx3F unk_C0;
    f32 unk_E4;
    Mtx3F unk_E8;
    Vec3f unk_10C;
    Vec3f unk_118;
    MtxF unk_124;
    s8 unk_164;
    s8 unk_165;
    s8 unk_166;
    s8 customType;
    Vec3f unk_168;
    f32 shadowColorStrength;
    f32 unk_178;
    f32 unk_17C;
    Vec3f unk_180;
    Vec3f unk_18C;
    f32 unk_198;
    Vec3f unk_19C;
    f32 unk_1A8;
    f32 boostEnergyUsage;
    f32 unk_1B0;
    f32 unk_1B4;
    f32 unk_1B8;
    f32 unk_1BC;
    f32 unk_1C0;
    f32 unk_1C4;
    f32 unk_1C8;
    f32 unk_1CC;
    f32 unk_1D0;
    f32 unk_1D4;
    f32 unk_1D8;
    f32 unk_1DC;
    f32 unk_1E0;
    f32 unk_1E4;
    f32 unk_1E8;
    f32 unk_1EC;
    f32 unk_1F0;
    f32 unk_1F4;
    f32 unk_1F8;
    f32 unk_1FC;
    f32 unk_200;
    s32 unk_204;
    s32 unk_208;
    s32 unk_20C;
    s32 unk_210;
    s32 unk_214;
    s32 boostTimer;
    s32 spinOutTimer;
    s32 unk_220;
    f32 pitForceFieldSize;
    f32 energy;
    f32 maxEnergy;
    f32 unk_230;
    f32 unk_234;
    f32 unk_238;
    f32 raceDistance;
    f32 lapsCompletedDistance;
    f32 lapDistance;
    f32 raceDistancePosition;
    Mtx3F unk_24C;
    f32 unk_270;
    f32 unk_274;
    s16 unk_278;
    s16 unk_27A;
    s32 unk_27C;
    s32 unk_280;
    s16 unk_284;
    s16 unk_286;
    s32 unk_288;
    struct Racer* unk_28C;
    s32 lapTimes[3];
    s32 completedLapsTime;
    s32 raceTime;
    s32 unk_2A4;
    s16 lap;
    s16 lapsCompleted;
    s32 position;
    s16 startNewPracticeLap;
    s8 unk_2B2;
    s8 unk_2B3;
    s32 machineLod;
    struct Racer* racerAhead;
    struct Racer* racerBehind;
    f32 distanceToRacerAhead;
    f32 distanceFromRacerBehind;
    s8 character;
    s8 machineIndex;
    u8 shadowType;
    u8 boostersType;
    s16 machineSkinIndex;
    s16 bodyR;
    s16 bodyG;
    s16 bodyB;
    s16 shadowR;
    s16 shadowG;
    s16 shadowB;
    s16 unk_2DA;
    s16 unk_2DC;
    s16 unk_2DE;
    f32 bodyRF;
    f32 bodyGF;
    f32 bodyBF;
    f32 unk_2EC;
    f32 unk_2F0;
    f32 unk_2F4;
    f32 unk_2F8;
    f32 unk_2FC;
    f32 unk_300;
    f32 shadowBaseR;
    f32 shadowBaseG;
    f32 shadowBaseB;
    s8 unk_310[0xC];
    f32 unk_31C;
    f32 unk_320;
    f32 unk_324;
    f32 unk_328;
    f32 energyIncrease;
    f32 unk_330;
    f32 unk_334;
    f32 unk_338;
    f32 unk_33C;
    s32 unk_340;
    s8 segmentLandmine;
    s8 segmentJump;
    s8 segmentDirt;
    s8 segmentIce;
    s8 segmentPit;
    s8 segmentDash;
    s8 nextSegmentLandmine;
    s8 nextSegmentDirt;
    s8 nextSegmentDash;
    s8 unk_34D;
    s16 obstaclePriorityState;
    s16 unk_350;
    s16 unk_352;
    f32 unk_354;
    s32 lastSegmentIndex;
    s32 trackSegmentForm;
    f32 unk_360;
    f32 unk_364;
    u32 unk_368;
    s32 awarenessFlags;
    s32 unk_370;
    s32 lastStickX;
    s32 lastStickY;
    s32 lastButtonsPressed;
    s32 lastButtonsCurrent;
    s32 unk_384;
    f32 unk_388;
    f32 unk_38C;
    s32 driftingCounter;
    s32 unk_394;
    s32 unk_398;
    s32 unk_39C;
    s32 unk_3A0;
    s32 unk_3A4;
} Racer; // size = 0x3A8

typedef struct RaceStats {
    s32 raceTime;
    f32 maxSpeed;
    s16 position;
    s16 unk_0A;
    s16 racersKOd;
    s8 unk_0E[0x2];
} RaceStats; // size = 0x10

typedef Gfx* (*unk_800E51B8_unk_1C_func)(Gfx*, s32, s32);

typedef struct unk_800E51B8 {
    s32 unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    unk_800E51B8_unk_1C_func unk_20;
} unk_800E51B8; // size = 0x20

typedef struct unk_struct_20 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    f32 unk_1C;
} unk_struct_20; // size = 0x20

typedef struct unk_struct_54 {
    unk_struct_20 unk_00;
    f32 unk_20;
    Vec3f unk_24;
    Vec3f unk_30;
    Vec3f unk_3C;
    Vec3f unk_48;
} unk_struct_54; // size = 0x54

typedef struct unk_struct_68 {
    unk_struct_54 unk_00;
    Vec3f unk_54;
    f32 unk_60;
    f32 unk_64;
} unk_struct_68; // size = 0x68

typedef struct unk_struct_9C {
    unk_struct_68 unk_00;
    f32 unk_68[10];
    f32 unk_90;
    f32 unk_94;
    s32 unk_98;
} unk_struct_9C; // size = 0x9C

typedef struct unk_struct_58 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18[16];
} unk_struct_58; // size = 0x58

typedef struct unk_redo_1 {
    unk_struct_58 unk_00;
    unk_struct_20 unk_58;
} unk_redo_1; // size = 0x78

typedef struct unk_redo_2 {
    unk_struct_58 unk_00;
    unk_struct_54 unk_58;
} unk_redo_2; // size = 0xAC

typedef struct unk_redo_3 {
    unk_struct_58 unk_00;
    unk_struct_68 unk_58;
} unk_redo_3; // size = 0xC0

typedef struct unk_8008112C_arg_1 {
    unk_struct_58 unk_00;
    unk_struct_9C unk_58;
} unk_8008112C_arg_1; // size = 0xF4

typedef struct unk_struct_F8 {
    s32 unk_00;
    unk_8008112C_arg_1 unk_04;
} unk_struct_F8; // size = 0xF8

typedef struct unk_struct_14 {
    s32 unk_00;
    f32* unk_04[3];
    s32* unk_10;
} unk_struct_14; // size = 0x14

typedef struct unk_80085154_arg_2 {
    s32 unk_00;
    f32* unk_04;
    s32* unk_08;
} unk_80085154_arg_2; // size = 0xC

typedef struct unk_80085434_arg_2 {
    unk_struct_14 unk_00[2];
    unk_80085154_arg_2 unk_28;
} unk_80085434_arg_2; // size = 0x34

typedef struct unk_80085494_arg_2 {
    unk_struct_14 unk_00[3];
    unk_80085154_arg_2 unk_3C;
} unk_80085494_arg_2; // size = 0x48

typedef struct unk_80085434_arg_0 {
    Vec3f unk_00[2];
    f32 unk_18;
} unk_80085434_arg_0; // size = 0x1C

typedef struct unk_80085494_arg_0 {
    Vec3f unk_00[3];
    f32 unk_24;
} unk_80085494_arg_0; // size = 0x28

typedef struct unk_struct_8 {
    s32 unk_00;
    s32 unk_04;
} unk_struct_8; // size = 0x8

typedef struct unk_struct_20_2 {
    unk_struct_8 unk_00[4];
} unk_struct_20_2; // size = 0x20

typedef struct unk_struct_C {
    s32 unk_00;
    void* unk_04;
    void* unk_08;
} unk_struct_C; // size = 0xC

typedef struct unk_800E5D70 {
    unk_struct_F8* unk_00;
    unk_struct_C* unk_04;
    s32 unk_08;
    unk_struct_20_2* unk_0C;
    Vec3f* unk_10;
    Mtx3F* unk_14;
    Racer* unk_18;
    Vec3f* unk_1C;
    Mtx3F* unk_20;
} unk_800E5D70; // size = 0x24

typedef struct unk_800CD8B0 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3f unk_24;
    f32 unk_30;
    f32 unk_34;
} unk_800CD8B0; // size 0x38

typedef struct unk_800CD970 {
    s16 unk_00;
    s16 unk_02;
    f32 unk_04;
    f32* unk_08;
} unk_800CD970; // size 0xC

typedef struct unk_80111870 {
    Vec3f unk_00;
    Vec3f unk_0C;
    f32 unk_18;
    u32 unk_1C;
    Racer* unk_20;
} unk_80111870; // size = 0x24

typedef struct unk_80112FB8 {
    f32 unk_00;
    s32 unk_04;
    Racer* unk_08;
} unk_80112FB8; // size = 0xC

typedef struct unk_801122A8 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3f unk_24;
    Vec3f unk_30;
    u32 unk_3C;
    Racer* unk_40;
} unk_801122A8; // size = 0x44

typedef struct unk_80113140 {
    Vec3f unk_00;
    Vec3f unk_0C;
    Vec3f unk_18;
    Vec3i unk_24;
    Vec3f unk_30;
    Vec3f unk_3C;
    s16 unk_48;
    s16 unk_4A;
    s16 unk_4C;
    s16 unk_4E;
    u32 unk_50;
    Racer* unk_54;
} unk_80113140; // size = 0x58

typedef struct unk_80077D50 {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ void* unk_04; // segmented address
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ size_t compressedSize;
} unk_80077D50; // size = 0x10

typedef struct unk_800E33E0 {
    void* unk_00; // segmented address
    TexturePtr unk_04;
} unk_800E33E0; // size = 0x8

typedef struct unk_800792D8 {
    unk_80077D50* unk_00;
    s32 unk_04;
} unk_800792D8;

typedef struct unk_800E3F28 {
    unk_800792D8* unk_00;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    TexturePtr unk_0C; // primary texture
    TexturePtr unk_10; // alternate texture (defaults to primary)
} unk_800E3F28; // size = 0x14

typedef struct unk_800E4068 {
    unk_80077D50* unk_00;
    TexturePtr unk_04;
} unk_800E4068; // size = 0x8

typedef struct unk_806F2400_unk_00 {
    u8 body;
    u8 boost;
    u8 grip;
    u8 frontType;
    u8 rearType;
    u8 wingType;
    u8 logo;
    u8 number;
    u8 decal;
    u8 red;
    u8 green;
    u8 blue;
    u8 numberR;
    u8 numberG;
    u8 numberB;
    u8 decalR;
    u8 decalG;
    u8 decalB;
    u8 cockpitR;
    u8 cockpitG;
    u8 cockpitB;
    char machineName[9];
    u16 checksum;
} unk_806F2400_unk_00; // size = 0x20

typedef struct unk_806F2400 {
    unk_806F2400_unk_00 unk_00[30];
    s8 unk_3C0[30];
    u16 unk_3DE;
} unk_806F2400; // size = 0x3E0

typedef struct unk_80144F74 {
    void* unk_00;
    s16 width;
    s16 height;
} unk_80144F74; // size = 0x8

typedef struct unk_80144F44 {
    s32 unk_00;
    unk_80144F74 unk_04;
    s32 tlut;
} unk_80144F44; // size = 0x10

typedef struct unk_80144FE0 {
    Mtx unk_00;
    Vtx unk_40[4];
} unk_80144FE0; // size = 0x80

typedef struct unk_8009E224 {
    void* texture;
    void* tlut;
    s16 width;
    s16 height;
} unk_8009E224; // size = 0x10

typedef struct unk_8003A5D8 {
    char name[16];
    s32 attr;
    s8 unk_14[0x8];
    char unk_1C;
    char extension[5];
    u8 unk_22;
    s8 unk_23;
} unk_8003A5D8; //size = 0x24

typedef struct unk_80128C94 {
    Mtx unk_0000;
    Mtx unk_0040;
    s8 unk_0080[0x80];
    Mtx unk_0100;
    s8 unk_0140[0x40];
    Vtx unk_0180[64 * 6];
    Vtx unk_1980[898];
    s8 unk_51A0[0x200];
    Vtx unk_53A0[0x30];
    Vtx unk_56A0[0x30];
    s8 unk_59A0[0xC00];
    Vtx unk_65A0[0x800];
    Vtx unk_E5A0[0x80];
    s8 unk_EDA0[0x400];
    Mtx unk_F1A0[0x1];
    s8 pad_F1E0[0x7C0];
    Gfx unk_F9A0[1];
    s8 pad_F9A8[0x1720];
    Gfx unk_110C8[0x13C8];
} unk_80128C94; // size = 0x1AF08

typedef struct unk_80026914_unk_1C {
    void* unk_00;
    void* unk_04;
    void* unk_08;
    void* unk_0C;
    struct unk_80026914* unk_10;
    void (*unk_14)(void);
    u16 unk_18;
    u16 unk_1A;
    void* unk_1C;
    void* unk_20;
} unk_80026914_unk_1C; // size = 0x24

typedef struct unk_80026914 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    unk_80026914_unk_1C* unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32* unk_30;
} unk_80026914; // size = 0x34

typedef struct unk_80140E60 {
    s32 unk_00; // type
    s32 unk_04; // value
} unk_80140E60; // size = 0x8

typedef struct unk_801413F0 {
    Mtx unk_00;
    LookAt unk_40;
} unk_801413F0; // size = 0x60

typedef struct unk_807B3C20 {
    CourseSegment unk_0000[64];
    s32 unk_2900;
} unk_807B3C20; // size 0x2904

typedef struct unk_80128690 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} unk_80128690; // size = 0xC

typedef struct unk_8011C220 {
    s32 unk_00;
    f32 unk_04;
    Vec3f unk_08;
    Mtx3F unk_14;
} unk_8011C220; // size = 0x38

typedef struct unk_800D6CA0 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s8 unk_18[0x4];
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    CourseSegment unk_28;
} unk_800D6CA0; // size >= 0xCC

#endif // UNK_STRUCTS_H
