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
    s32 direction;
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

typedef struct MachineInfo {
    /* 0x00 */ u8 character;
    /* 0x01 */ u8 customType;
    /* 0x02 */ u8 frontType;
    /* 0x03 */ u8 rearType;
    /* 0x04 */ u8 wingType;
    /* 0x05 */ u8 logo;
    /* 0x06 */ u8 number;
    /* 0x07 */ u8 decal;
    /* 0x08 */ u8 bodyR;
    /* 0x09 */ u8 bodyG;
    /* 0x0A */ u8 bodyB;
    /* 0x0B */ u8 numberR;
    /* 0x0C */ u8 numberG;
    /* 0x0D */ u8 numberB;
    /* 0x0E */ u8 decalR;
    /* 0x0F */ u8 decalG;
    /* 0x10 */ u8 decalB;
    /* 0x11 */ u8 cockpitR;
    /* 0x12 */ u8 cockpitG;
    /* 0x13 */ u8 cockpitB;
} MachineInfo; // size = 0x14

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
    s32 unk_00;
    Vec3f unk_04;
    s8 unk_10[0x4];
} unk_802D3978; // size = 0x14

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

#endif // UNK_STRUCTS_H
