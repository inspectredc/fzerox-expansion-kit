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
    /* 0x20 */ void* readBuf;
    /* 0x24 */ s32 offset;
    /* 0x28 */ s32 fileSize;
    /* 0x2C */ s32 attr;
    /* 0x30 */ s32 copyCount;
    /* 0x34 */ bool writeChanges;
    /* 0x38 */ void* writeBuf;
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
    /* 0x0000 */ Mtx unk_000;
    /* 0x0040 */ Vtx jumpVtx[8 * 6];
    /* 0x0340 */ Vtx landmineVtx[48 * 5];
    /* 0x1240 */ Vtx terrainEffectVtx[0x800];
    /* 0x1A40 */ Vtx dashVtx[0x80];
    /* 0x2240 */ s8 pad_2240[0x400];
    /* 0x2640 */ Mtx decorationMtx[32];
} unk_80225800; // size = 0x2E40

typedef struct CourseSegment {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f up;
    /* 0x18 */ f32 radiusLeft;
    /* 0x1C */ f32 radiusRight;
    /* 0x20 */ s32 trackSegmentInfo;
    /* 0x24 */ f32 tension;
    /* 0x28 */ f32 length;
    /* 0x2C */ f32 lengthFromStart;
    /* 0x30 */ s32 segmentIndex;
    /* 0x34 */ struct CourseSegment* next;
    /* 0x38 */ struct CourseSegment* prev;
    /* 0x3C */ struct SegmentChunk* startChunk;
    /* 0x40 */ struct SegmentChunk* endChunk;
    /* 0x44 */ struct Jump* jumpsStart;
    /* 0x48 */ struct Jump* jumpsEnd;
    /* 0x4C */ struct Landmine* landminesStart;
    /* 0x50 */ struct Landmine* landminesEnd;
    /* 0x54 */ struct Effect* effectsStart;
    /* 0x58 */ struct Effect* effectsEnd;
    /* 0x5C */ s8 unk_5C[0x8]; // likely a pair of EffectDrawData struct ptrs
    /* 0x64 */ f32 unk_64;
    /* 0x68 */ f32 previousJoinEndTValue;
    /* 0x6C */ f32 nextJoinStartTValue;
    /* 0x70 */ f32 joinScale;
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

typedef struct SegmentChunk {
    s32 trackSegmentInfo;
    s32 segmentIndex;
    f32 segmentTValue;
    f32 depth;
    bool drawState;
    Vec3f pos;
    s16 referencePos1[3];
    s16 referencePos2[3];
    s16 referencePos3[3];
    s16 referencePos4[3];
    s16 referencePos5[3];
    s16 referencePos6[3];
    s16 referencePos7[3];
    s16 referencePos8[3];
    s16 topTextureCoord;
    s16 bottomTextureCoord;
    s16 leftTextureCoord;
    s16 rightTextureCoord;
    s16 topTextureCorrection;
    s16 bottomTextureCorrection;
    s16 leftTextureCorrection;
    s16 rightTextureCorrection;
} SegmentChunk; // size = 0x60

typedef struct Jump {
    Vec3f pos;
    Mtx3F basis;
    Vec3f dimensions; // width, height, depth
    s8 unk_3C[0x4];
} Jump; // size = 0x40

typedef struct Landmine {
    // s32 unk_00; Field Removed in DD Version
    Vec3f pos;
    s8 unk_10[0x4];
} Landmine; // size = 0x10

typedef struct Effect {
    s32 effectType;
    f32 segmentTValueStart;
    f32 segmentTValueEnd;
    Vec3f unk_0C;
    Vec3f unk_18;
    s8 unk_24[0x4];
} Effect; // size = 0x28

#define DASH_LATERAL_OFFSET(effect) ((effect)->rightEdgeDistance)
#define DASH_LATERAL_OFFSET2(effect) ((effect)->leftEdgeDistance)
#define DASH_ANGLE(effect) ((effect)->rightEdgeDistance)
#define DASH_ANGLE2(effect) ((effect)->leftEdgeDistance)

typedef struct CourseEffect {
    s32 segmentIndex;
    s32 effectType;
    f32 segmentTValueStart;
    f32 segmentTValueEnd;
    f32 rightEdgeDistance;
    f32 leftEdgeDistance;
} CourseEffect; // size = 0x18

typedef struct CourseFeature {
    s32 featureType;
    s32 segmentIndex;
    f32 segmentTValue;
    f32 lateralOffset;
    Vec3f dimensions;
} CourseFeature; // size = 0x1C

typedef struct CourseFeaturesInfo {
    CourseFeature* features;
    s32 featureCount;
    s32 landmineCount;
    s32 jumpCount;
} CourseFeaturesInfo;

typedef struct CourseDecoration {
    Vec3f pos;
    Mtx3F basis;
    f32 scale;
    struct SegmentChunk* loadChunk;
} CourseDecoration; // size = 0x38

typedef struct CourseEffectsInfo {
    CourseEffect* effects;
    s32 count;
} CourseEffectsInfo;

typedef struct EffectDrawData {
    s32 effectType;
    Vtx* vtxStart;
    Vtx* vtxEnd;
    s8 unk_0C[0x4];
} EffectDrawData; // size = 0x10

typedef struct RacerSegmentPositionInfo {
    /* 0x00 */ CourseSegment* courseSegment;
    /* 0x04 */ f32 segmentTValue;
    /* 0x08 */ f32 segmentLengthProportion;
    /* 0x0C */ Vec3f segmentForward;
    /* 0x18 */ f32 segmentForwardMagnitude;
    /* 0x1C */ Vec3f segmentPos;
    /* 0x28 */ Vec3f segmentDisplacement;
    /* 0x34 */ Vec3f pos;
    /* 0x40 */ f32 distanceFromSegment;
    /* 0x44 */ Vec3f lastGroundedPos;
} RacerSegmentPositionInfo; // size = 0x50

typedef struct Racer {
    /* 0x000 */ s32 id;
    /* 0x004 */ s32 stateFlags;
    /* 0x008 */ u16 soundEffectFlags;
    /* 0x00A */ s16 points;
    /* 0x00C */ RacerSegmentPositionInfo segmentPositionInfo;
    /* 0x05C */ Vec3f unk_5C;
    /* 0x068 */ Vec3f unk_68;
    /* 0x074 */ Vec3f velocity;
    /* 0x080 */ Vec3f unk_80;
    /* 0x08C */ Vec3f acceleration;
    /* 0x098 */ f32 speed;
    /* 0x09C */ f32 maxSpeed;
    /* 0x0A0 */ f32 heightAboveGround;
    /* 0x0A4 */ f32 podiumHeight;
    /* 0x0A8 */ Vec3f gravityUp;
    /* 0x0B4 */ Vec3f tiltUp;
    /* 0x0C0 */ Mtx3F trueBasis;
    /* 0x0E4 */ f32 tiltUpInput;
    /* 0x0E8 */ Mtx3F modelBasis;
    /* 0x10C */ Vec3f modelPos;
    /* 0x118 */ Vec3f recoilTilt;
    /* 0x124 */ MtxF modelMatrix;
    /* 0x164 */ s8 modelMatrixInit;
    /* 0x165 */ s8 shadowMatrixInit;
    /* 0x166 */ s8 attackHighlightMatrixInit;
    /* 0x167 */ s8 customType;
    /* 0x168 */ Vec3f shadowPos;
    /* 0x174 */ f32 shadowColorStrength;
    /* 0x178 */ f32 attackHighlightScale;
    /* 0x17C */ f32 unk_17C;
    /* 0x180 */ Vec3f focusPos;
    /* 0x18C */ Vec3f focusVelocity;
    /* 0x198 */ f32 unk_198;
    /* 0x19C */ Vec3f upFromGround;
    /* 0x1A8 */ f32 unk_1A8;
    /* 0x1AC */ f32 boostEnergyUsage;
    /* 0x1B0 */ f32 unk_1B0;
    /* 0x1B4 */ f32 unk_1B4;
    /* 0x1B8 */ f32 unk_1B8;
    /* 0x1BC */ f32 unk_1BC;
    /* 0x1C0 */ f32 unk_1C0;
    /* 0x1C4 */ f32 unk_1C4;
    /* 0x1C8 */ f32 unk_1C8;
    /* 0x1CC */ f32 unk_1CC;
    /* 0x1D0 */ f32 unk_1D0;
    /* 0x1D4 */ f32 accelerationForce;
    /* 0x1D8 */ f32 driftAttackForce;
    /* 0x1DC */ f32 jumpBoost;
    /* 0x1E0 */ f32 unk_1E0;
    /* 0x1E4 */ f32 unk_1E4;
    /* 0x1E8 */ f32 unk_1E8;
    /* 0x1EC */ f32 unk_1EC;
    /* 0x1F0 */ f32 unk_1F0;
    /* 0x1F4 */ f32 collidingStrength;
    /* 0x1F8 */ f32 unk_1F8;
    /* 0x1FC */ f32 unk_1FC;
    /* 0x200 */ f32 unk_200;
    /* 0x204 */ s32 unk_204;
    /* 0x208 */ s32 unk_208;
    /* 0x20C */ s32 unk_20C;
    /* 0x210 */ s32 vibrationStrength;
    /* 0x214 */ s32 unk_214;
    /* 0x218 */ s32 boostTimer;
    /* 0x21C */ s32 spinOutTimer;
    /* 0x220 */ s32 bodyWhiteTimer;
    /* 0x224 */ f32 pitForceFieldSize;
    /* 0x228 */ f32 energy;
    /* 0x22C */ f32 maxEnergy;
    /* 0x230 */ f32 energyRegain;
    /* 0x234 */ f32 unk_234;
    /* 0x238 */ f32 unk_238;
    /* 0x23C */ f32 raceDistance;
    /* 0x240 */ f32 lapsCompletedDistance;
    /* 0x244 */ f32 lapDistance;
    /* 0x248 */ f32 raceDistancePosition;
    /* 0x24C */ Mtx3F segmentBasis; // basis
    /* 0x270 */ f32 currentRadiusLeft;
    /* 0x274 */ f32 currentRadiusRight;
    /* 0x278 */ s16 zButtonTimer;
    /* 0x27A */ s16 rButtonTimer;
    /* 0x27C */ s32 unk_27C;
    /* 0x280 */ s32 unk_280;
    /* 0x284 */ s16 attackState;
    /* 0x286 */ s16 driftAttackDirection;
    /* 0x288 */ s32 unk_288;
    /* 0x28C */ struct Racer* unk_28C;
    /* 0x290 */ s32 lapTimes[3];
    /* 0x29C */ s32 completedLapsTime;
    /* 0x2A0 */ s32 raceTime;
    /* 0x2A4 */ s32 unk_2A4;
    /* 0x2A8 */ s16 lap;
    /* 0x2AA */ s16 lapsCompleted;
    /* 0x2AC */ s32 position;
    /* 0x2B0 */ s16 startNewPracticeLap;
    /* 0x2B2 */ s8 unk_2B2;
    /* 0x2B3 */ s8 unk_2B3;
    /* 0x2B4 */ s32 machineLod;
    /* 0x2B8 */ struct Racer* racerAhead;
    /* 0x2BC */ struct Racer* racerBehind;
    /* 0x2C0 */ f32 distanceToRacerAhead;
    /* 0x2C4 */ f32 distanceFromRacerBehind;
    /* 0x2C8 */ s8 character;
    /* 0x2C9 */ s8 machineIndex;
    /* 0x2CA */ u8 shadowType;
    /* 0x2CB */ u8 boostersType;
    /* 0x2CC */ s16 machineSkinIndex;
    /* 0x2CE */ s16 bodyR;
    /* 0x2D0 */ s16 bodyG;
    /* 0x2D2 */ s16 bodyB;
    /* 0x2D4 */ s16 shadowR;
    /* 0x2D6 */ s16 shadowG;
    /* 0x2D8 */ s16 shadowB;
    /* 0x2DA */ s16 attackHighlightR;
    /* 0x2DC */ s16 attackHighlightG;
    /* 0x2DE */ s16 attackHighlightB;
    /* 0x2E0 */ f32 bodyRF;
    /* 0x2E4 */ f32 bodyGF;
    /* 0x2E8 */ f32 bodyBF;
    /* 0x2EC */ f32 bodyLowEnergyR;
    /* 0x2F0 */ f32 bodyLowEnergyG;
    /* 0x2F4 */ f32 bodyLowEnergyB;
    /* 0x2F8 */ f32 bodyLowEnergyGradientR;
    /* 0x2FC */ f32 bodyLowEnergyGradientG;
    /* 0x300 */ f32 bodyLowEnergyGradientB;
    /* 0x304 */ f32 shadowBaseR;
    /* 0x308 */ f32 shadowBaseG;
    /* 0x30C */ f32 shadowBaseB;
    /* 0x310 */ s8 unk_310[0xC];
    /* 0x31C */ f32 unk_31C;
    /* 0x320 */ f32 unk_320;
    /* 0x324 */ f32 unk_324;
    /* 0x328 */ f32 unk_328;
    /* 0x32C */ f32 energyIncrease;
    /* 0x330 */ f32 unk_330;
    /* 0x334 */ f32 unk_334;
    /* 0x338 */ f32 unk_338;
    /* 0x33C */ f32 unk_33C;
    /* 0x340 */ s32 unk_340;
    /* 0x344 */ s8 segmentLandmine;
    /* 0x345 */ s8 segmentJump;
    /* 0x346 */ s8 segmentDirt;
    /* 0x347 */ s8 segmentIce;
    /* 0x348 */ s8 segmentPit;
    /* 0x349 */ s8 segmentDash;
    /* 0x34A */ s8 nextSegmentLandmine;
    /* 0x34B */ s8 nextSegmentDirt;
    /* 0x34C */ s8 nextSegmentDash;
    /* 0x34D */ s8 unk_34D;
    /* 0x34E */ s16 obstaclePriorityState;
    /* 0x350 */ s16 unk_350;
    /* 0x352 */ s16 unk_352;
    /* 0x354 */ f32 unk_354;
    /* 0x358 */ s32 lastSegmentIndex;
    /* 0x35C */ s32 trackSegmentForm;
    /* 0x360 */ f32 unk_360;
    /* 0x364 */ f32 unk_364;
    /* 0x368 */ u32 unk_368;
    /* 0x36C */ s32 awarenessFlags;
    /* 0x370 */ s32 unk_370;
    /* 0x374 */ s32 lastStickX;
    /* 0x378 */ s32 lastStickY;
    /* 0x37C */ s32 lastButtonsPressed;
    /* 0x380 */ s32 lastButtonsCurrent;
    /* 0x384 */ s32 unk_384;
    /* 0x388 */ f32 unk_388;
    /* 0x38C */ f32 unk_38C;
    /* 0x390 */ s32 driftingCounter;
    /* 0x394 */ s32 unk_394;
    /* 0x398 */ s32 unk_398;
    /* 0x39C */ s32 unk_39C;
    /* 0x3A0 */ s32 unk_3A0;
    /* 0x3A4 */ s32 unk_3A4;
} Racer; // size = 0x3A8

typedef struct RaceStats {
    s32 raceTime;
    f32 maxSpeed;
    s16 position;
    s16 unk_0A;
    s16 racersKOd;
    s8 unk_0E[0x2];
} RaceStats; // size = 0x10

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

typedef struct CustomMachine {
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
} CustomMachine; // size = 0x20

typedef struct CustomMachinesInfo {
    CustomMachine customMachines[30];
    s8 characterCustomState[30];
    u16 checksum;
} CustomMachinesInfo; // size = 0x3E0

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
    /* 0x00000 */ Mtx unk_0000;
    /* 0x00040 */ Mtx unk_0040;
    /* 0x00080 */ s8 unk_0080[0x80];
    /* 0x00100 */ Mtx unk_0100;
    /* 0x00140 */ s8 unk_0140[0x40];
    /* 0x00180 */ Vtx unk_0180[64 * 6];
    /* 0x01980 */ Vtx unk_1980[898];
    /* 0x051A0 */ s8 unk_51A0[0x200];
    /* 0x053A0 */ Vtx jumpVtx[8 * 6];
    /* 0x056A0 */ Vtx landmineVtx[5 * 48];
    /* 0x065A0 */ Vtx terrainEffectVtx[0x800];
    /* 0x0E5A0 */ Vtx dashVtx[0x80];
    /* 0x0EDA0 */ s8 unk_EDA0[0x400];
    /* 0x0F1A0 */ Mtx decorationMtx[0x20];
    /* 0x0F9A0 */ Gfx unk_F9A0[741];
    /* 0x110C8 */ Gfx unk_110C8[5064];
} unk_80128C94; // size = 0x1AF08

typedef struct MenuDropItem {
    /* 0x00 */ void* backgroundTex;
    /* 0x04 */ void* backgroundSelectedTex;
    /* 0x08 */ void* contentsTex;
    /* 0x0C */ void* subContentsRGBATex;
    /* 0x10 */ struct MenuWidget* widget;
    /* 0x14 */ void (*action)(void);
    /* 0x18 */ u16 contentsWidth;
    /* 0x1A */ u16 contentsHeight;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ void* subContentsI4Tex;
} MenuDropItem; // size = 0x24

typedef struct MenuWidget {
    /* 0x00 */ s32 numItems;
    /* 0x04 */ s32 openIndex;
    /* 0x08 */ s32 highlightedIndex;
    /* 0x0C */ s32 left;
    /* 0x10 */ s32 top;
    /* 0x14 */ s32 itemXOffset;
    /* 0x18 */ s32 itemYOffset;
    /* 0x1C */ MenuDropItem* menuItems;
    /* 0x20 */ s32 cursorMinPosX;
    /* 0x24 */ s32 cursorMinPosY;
    /* 0x28 */ s32 cursorMaxPosX;
    /* 0x2C */ s32 cursorMaxPosY;
    /* 0x30 */ s32* option;
} MenuWidget; // size = 0x34

typedef struct unk_80140E60 {
    /* 0x00 */ s32 unk_00; // type
    /* 0x04 */ s32 unk_04; // value
} unk_80140E60; // size = 0x8

typedef struct unk_801413F0 {
    /* 0x00 */ Mtx unk_00;
    /* 0x40 */ LookAt unk_40;
} unk_801413F0; // size = 0x60

typedef struct unk_807B3C20 {
    CourseSegment unk_0000[64];
    s32 controlPointCount;
} unk_807B3C20; // size 0x2904

typedef struct unk_80128690 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} unk_80128690; // size = 0xC

typedef struct unk_8011C220 {
    s32 unk_00;
    f32 unk_04;
    Vec3f pos;
    Mtx3F basis;
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

typedef struct TextureInfo {
    /* 0x00 */ TexturePtr texture;
    /* 0x04 */ s16 width;
    /* 0x06 */ s16 height;
} TextureInfo; // size = 0x8

typedef struct TexturePaletteInfo {
    /* 0x00 */ TexturePtr texture;
    /* 0x04 */ void* tlut;
    /* 0x08 */ s16 width;
    /* 0x0A */ s16 height;
} TexturePaletteInfo; // size = 0xC

#endif // UNK_STRUCTS_H
