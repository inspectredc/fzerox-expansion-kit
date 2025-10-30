#include "global.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_course.h"
#include "fzx_assets.h"
#include "fzx_segmentA.h"

#define VERTEX_MODIFIED_ST(s, t) ((((s) << 15) & 0xFFFF0000) | ((t) &0xFFFF))

typedef struct unk_800CF528 {
    s32 texture;
    f32 unk_04;
    s32 width;
    s32 tile;
    s32 unk_10;
    s16 unk_14;
    s16 unk_16;
    s16 unk_18;
    s16 unk_1A;
    s16 unk_1C;
    s16 unk_1E;
} unk_800CF528; // size = 0x20

typedef struct unk_800F8958 {
    unk_36ED0* unk_00;
    Gfx* unk_04;
    Gfx* unk_08;
    Gfx* unk_0C;
    Gfx* unk_10;
    Gfx* unk_14;
    Gfx* unk_18;
    Gfx* unk_1C;
    Gfx* unk_20;
    Gfx* unk_24;
    Gfx* unk_28;
    s32 unk_2C;
} unk_800F8958; // size = 0x30

typedef struct unk_800A8B74_arg_0 {
    unk_36ED0* unk_00;
    unk_36ED0* unk_04;
    f32 unk_08;
    s32 unk_0C;
} unk_800A8B74_arg_0; // size = 0x10

CourseInfo* gCurrentCourseInfo;
s32 gCourseIndex;
s32 D_800D65C8;
unk_36ED0* D_i2_800D65CC;
Vtx* D_800D65D0;
s32 D_i2_800D65D4;
unk_800A8B74_arg_0 D_i2_800D65D8[96];
s32 D_i2_800D6BD8;
s32 D_i2_800D6BDC;
s16 D_i2_800D6BE0[5];
s32 sRandomCourseInitSeed1;
s32 sRandomCourseInitMask1;
s32 sRandomCourseInitSeed2;
s32 sRandomCourseInitMask2;
f32 D_i2_800D6BFC;
f32 D_i2_800D6C00;
unk_800F8958 D_i2_800D6C08[2];
unk_800F8958* D_i2_800D6C68;
unk_800F8958* D_i2_800D6C6C;
s32 D_i2_800D6C70;
Gfx* D_i2_800D6C74;
unk_36ED0* D_i2_800D6C78;
unk_36ED0* D_i2_800D6C7C;
unk_36ED0* D_i2_800D6C80;
s32 D_i2_800D6C84;
bool D_i2_800D6C88;
s32 D_i2_800D6C8C;
f32 D_i2_800D6C90;
f32 D_i2_800D6C94;
f32 D_i2_800D6C98;

s32 D_i2_800C1510 = 0;
s16 gLastRandomCourseIndex = -1;
s32 D_i2_800C1518 = 990;
UNUSED s32 D_i2_800C151C = 0;

f32 D_i2_800C1520 = 6000.0f;
f32 D_i2_800C1524 = 1500.0f;
f32 D_i2_800C1528 = 3000.0f;
f32 D_i2_800C152C = 400.0f;
f32 D_i2_800C1530 = 5500.0f;
f32 D_i2_800C1534 = 1000.0f;

// TRACK_SHAPE_ROAD
unk_800CF528 D_i2_800C1538[] = {
    { D_A001000, 10.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_START_LINE
    { D_A000000, 10.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_1
    { D_A002000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_2
    { D_A003000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_3
    { D_A004000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_4
    { D_A005000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_5
    { D_A006000, 14.0f, 64, 4, 5, 1023, 32, 0xAE0, 0xF20, 0xF60, 0xFC0 }, // ROAD_6
};

// TRACK_SHAPE_WALLED_ROAD
unk_800CF528 D_i2_800C1618[] = {
    { D_A007000, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_0
    { D_8000008, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_1
    { D_8001008, 7.0f, 128, 0, 1, 511, 32, 0x1320, 0x1EA0, 0x1F60, 0x1FC0 }, // WALLED_ROAD_2
};

// TRACK_SHAPE_PIPE
unk_800CF528 D_i2_800C1678[] = {
    { D_8008008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_0
    { D_8009008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_1
    { D_800A008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_2
    { D_800B008, 2.8f, 128, 0, 2, 255, 32, 0x8A0, 0x1120, 0x1A20, 0x1FC0 }, // PIPE_3
};

// TRACK_SHAPE_CYLINDER
unk_800CF528 D_i2_800C16F8[] = {
    { D_800C008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_0
    { D_800D008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_1
    { D_800E008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_2
    { D_800F008, 9.3f, 128, 0, 1, 511, 32, 0x960, 0x12A0, 0x1B60, 0x1FC0 }, // CYLINDER_3
};

// TRACK_SHAPE_HALF_PIPE
unk_800CF528 D_i2_800C1778[] = {
    { D_8010008, 14.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 }, // HALF_PIPE_0
    { D_8011008, 4.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 },  // HALF_PIPE_1
    { D_8012008, 7.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 },  // HALF_PIPE_2
    { D_8013008, 14.0f, 64, 4, 5, 1023, 32, 0x5E0, 0xBE0, 0xDE0, 0xFC0 }, // HALF_PIPE_3
};

// TRACK_SHAPE_TUNNEL
unk_800CF528 D_i2_800C17F8[] = {
    { D_8004008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_0
    { D_8005008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_1
    { D_8006008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_2
    { D_8007008, 14.0f, 64, 4, 6, 1023, 32, 0x3A0, 0x660, 0x960, 0xFC0 }, // TUNNEL_3
};

// TRACK_SHAPE_BORDERLESS_ROAD
unk_800CF528 D_i2_800C1878[] = {
    { D_A008000, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_0
    { D_8002008, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_1
    { D_8003008, 14.0f, 64, 4, 5, 1023, 32, 0xB60, 0xEA0, 0xF20, 0xFC0 }, // BORDERLESS_ROAD_2
};

unk_800CF528* D_i2_800C18D8[] = {
    D_i2_800C1538, // TRACK_SHAPE_ROAD
    D_i2_800C1618, // TRACK_SHAPE_WALLED_ROAD
    D_i2_800C1678, // TRACK_SHAPE_PIPE
    D_i2_800C16F8, // TRACK_SHAPE_CYLINDER
    D_i2_800C1778, // TRACK_SHAPE_HALF_PIPE
    D_i2_800C17F8, // TRACK_SHAPE_TUNNEL
    NULL,          // TRACK_SHAPE_AIR
    D_i2_800C1878, // TRACK_SHAPE_BORDERLESS_ROAD
};

f32 gTrackJoinUpperLength[] = {
    0.0f,    // TRACK_SHAPE_ROAD
    50.0f,   // TRACK_SHAPE_WALLED_ROAD
    1000.0f, // TRACK_SHAPE_PIPE
    1000.0f, // TRACK_SHAPE_CYLINDER
    1000.0f, // TRACK_SHAPE_HALF_PIPE
    250.0f,  // TRACK_SHAPE_TUNNEL
    0.0f,    // TRACK_SHAPE_AIR
    50.0f,   // TRACK_SHAPE_BORDERLESS_ROAD
};

typedef void (*unk_800CF908)(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
typedef void (*unk_800CF928)(unk_36ED0*, unk_36ED0*, f32);

void func_i2_800B4728(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B47A8(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B4838(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B489C(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B4BD0(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B4FE0(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);
void func_i2_800B53D4(unk_36ED0*, f32, f32, Mtx3F*, Vec3f*, Vec3f*, Vec3f*, Vec3f*, Vec3f*);

unk_800CF908 D_i2_800C1918[] = {
    func_i2_800B4728, // TRACK_SHAPE_ROAD
    func_i2_800B47A8, // TRACK_SHAPE_WALLED_ROAD
    func_i2_800B4838, // TRACK_SHAPE_PIPE
    func_i2_800B489C, // TRACK_SHAPE_CYLINDER
    func_i2_800B4BD0, // TRACK_SHAPE_HALF_PIPE
    func_i2_800B4FE0, // TRACK_SHAPE_TUNNEL
    func_i2_800B4728, // TRACK_SHAPE_AIR
    func_i2_800B53D4, // TRACK_SHAPE_BORDERLESS_ROAD
};

void func_i2_800B5548(unk_36ED0*, unk_36ED0*, f32);
void func_i2_800B562C(unk_36ED0*, unk_36ED0*, f32);
void func_i2_800B57E0(unk_36ED0*, unk_36ED0*, f32);

unk_800CF928 D_i2_800C1938[] = {
    func_i2_800B57E0, // TRACK_SHAPE_ROAD
    func_i2_800B57E0, // TRACK_SHAPE_WALLED_ROAD
    func_i2_800B5548, // TRACK_SHAPE_PIPE
    func_i2_800B562C, // TRACK_SHAPE_CYLINDER
    func_i2_800B57E0, // TRACK_SHAPE_HALF_PIPE
    func_i2_800B5548, // TRACK_SHAPE_TUNNEL
    func_i2_800B57E0, // TRACK_SHAPE_AIR
    func_i2_800B57E0, // TRACK_SHAPE_BORDERLESS_ROAD
};

void func_i2_800BBC14(void);
void func_i2_800BC580(void);
void func_i2_800BA850(void);
void func_i2_800BCDFC(void);
void func_i2_800B9DD4(void);

void (*D_i2_800C1958[])(void) = {
    func_i2_800B9DD4, // TRACK_SHAPE_ROAD
    func_i2_800B9DD4, // TRACK_SHAPE_WALLED_ROAD
    func_i2_800BA850, // TRACK_SHAPE_PIPE
    func_i2_800BBC14, // TRACK_SHAPE_CYLINDER
    func_i2_800BC580, // TRACK_SHAPE_HALF_PIPE
    func_i2_800BA850, // TRACK_SHAPE_TUNNEL
    func_i2_800BCDFC, // TRACK_SHAPE_AIR
    func_i2_800B9DD4, // TRACK_SHAPE_BORDERLESS_ROAD
};

void func_i2_800BC070(void);
void func_i2_800BC968(void);
void func_i2_800BB1A4(void);
void func_i2_800BCF0C(void);
void func_i2_800BA1A0(void);

void (*D_i2_800C1978[])(void) = {
    func_i2_800BA1A0, // TRACK_SHAPE_ROAD
    func_i2_800BA1A0, // TRACK_SHAPE_WALLED_ROAD
    func_i2_800BB1A4, // TRACK_SHAPE_PIPE
    func_i2_800BC070, // TRACK_SHAPE_CYLINDER
    func_i2_800BC968, // TRACK_SHAPE_HALF_PIPE
    func_i2_800BB1A4, // TRACK_SHAPE_TUNNEL
    func_i2_800BCF0C, // TRACK_SHAPE_AIR
    func_i2_800BA1A0, // TRACK_SHAPE_BORDERLESS_ROAD
};

f32 D_i2_800C1998[] = {
    7.5f,
    15.0f,
    30.0f,
    60.0f,
};

f32 D_i2_800C19A8[] = {
    0.0f,
    350.0f,
    700.0f,
    1400.0f,
};

s32 D_i2_800C19B8[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
};

s32 D_i2_800C19C4[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_5,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_6,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_6,
};

s32 D_i2_800C19D0[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_4,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_2,
};

s32 D_i2_800C19DC[] = {
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_4,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
    TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_3,
};

s32 D_i2_800C19E8[] = {
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_0,
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_1,
    TRACK_FLAG_8000000 | TRACK_SHAPE_BORDERLESS_ROAD | BORDERLESS_ROAD_2,
};

s32 D_i2_800C19F4[] = {
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_0,
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_1,
    TRACK_FLAG_8000000 | TRACK_SHAPE_WALLED_ROAD | WALLED_ROAD_2,
};

s32 D_i2_800C1A00[] = {
    TRACK_FLAG_20000000 | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_0,
    TRACK_FLAG_20000000 | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_1,
    TRACK_FLAG_20000000 | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_2,
    TRACK_FLAG_20000000 | TRACK_FLAG_8000000 | TRACK_SHAPE_TUNNEL | TUNNEL_3,
};

s32 D_i2_800C1A10[] = {
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_0,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_1,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_2,
    TRACK_SHAPE_HALF_PIPE | HALF_PIPE_3,
};

s32 D_i2_800C1A20[] = {
    TRACK_FLAG_20000000 | TRACK_SHAPE_PIPE | PIPE_0,
    TRACK_FLAG_20000000 | TRACK_SHAPE_PIPE | PIPE_1,
    TRACK_FLAG_20000000 | TRACK_SHAPE_PIPE | PIPE_2,
    TRACK_FLAG_20000000 | TRACK_SHAPE_PIPE | PIPE_3,
};

s32 D_i2_800C1A30[] = {
    TRACK_SHAPE_CYLINDER | CYLINDER_0,
    TRACK_SHAPE_CYLINDER | CYLINDER_1,
    TRACK_SHAPE_CYLINDER | CYLINDER_2,
    TRACK_SHAPE_CYLINDER | CYLINDER_3,
};

void func_i2_800B0D10(s32 venue) {
    switch (venue) {
        case VENUE_MUTE_CITY:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_4].unk_04 =
                D_i2_800C1538[ROAD_5].unk_04 = D_i2_800C1538[ROAD_6].unk_04 = 16.0f;
            D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 = 14.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 7.0f;
            break;
        case VENUE_BIG_BLUE:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = 14.0f;
            D_i2_800C1538[ROAD_5].unk_04 = 1.0f;
            D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 = 1.0f;
            D_i2_800C1538[ROAD_4].unk_04 = 2.0f;
            D_i2_800C1538[ROAD_6].unk_04 = 6.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 7.0f;
            break;
        case VENUE_DEVILS_FOREST:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_4].unk_04 =
                D_i2_800C1538[ROAD_5].unk_04 = D_i2_800C1538[ROAD_6].unk_04 = D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 =
                    14.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 3.5f;
            break;
        case VENUE_SECTOR:
            D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 = 7.0f;
            D_i2_800C1538[ROAD_4].unk_04 = 5.0f;
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_5].unk_04 =
                D_i2_800C1538[ROAD_6].unk_04 = 10.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 3.5f;
            break;
        case VENUE_RED_CANYON:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_4].unk_04 =
                D_i2_800C1538[ROAD_5].unk_04 = D_i2_800C1538[ROAD_6].unk_04 = D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 =
                    14.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 3.5f;
            break;
        case VENUE_SILENCE:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_5].unk_04 =
                D_i2_800C1538[ROAD_6].unk_04 = D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 = 14.0f;
            D_i2_800C1538[ROAD_4].unk_04 = 7.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 7.0f;
            break;
        case VENUE_ENDING:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_4].unk_04 =
                D_i2_800C1538[ROAD_5].unk_04 = D_i2_800C1538[ROAD_6].unk_04 = 5.5f;
            D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 = 14.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 7.0f;
            break;
        default:
            D_i2_800C1538[ROAD_2].unk_04 = D_i2_800C1538[ROAD_3].unk_04 = D_i2_800C1538[ROAD_4].unk_04 =
                D_i2_800C1538[ROAD_5].unk_04 = D_i2_800C1538[ROAD_6].unk_04 = D_i2_800C1878[BORDERLESS_ROAD_0].unk_04 =
                    14.0f;
            D_i2_800C1618[WALLED_ROAD_0].unk_04 = 7.0f;
            break;
    }
}

void func_i2_800B0FAC(CourseSegment* segment, Mtx3F* basis) {
    f32 normalizingFactor;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    Vec3f forward;
    f32 temp_ft4;

    normalizingFactor = 1.0f / Course_SplineGetTangent(segment, 0.0f, &forward);
    forward.x *= normalizingFactor;
    forward.y *= normalizingFactor;
    forward.z *= normalizingFactor;

    sp38 = basis->x.x - forward.x;
    sp34 = basis->x.y - forward.y;
    sp30 = basis->x.z - forward.z;

    //! @bug This should probably use z instead of y twice
    temp_ft4 = ((sp38 * segment->up.x) + (sp34 * segment->up.y) + (sp38 * segment->up.y));
    temp_ft4 *= 2.0f;

    basis->y.x = (segment->up.x + sp38) - (temp_ft4 * segment->up.x);
    basis->y.y = (segment->up.y + sp34) - (temp_ft4 * segment->up.y);
    basis->y.z = (segment->up.z + sp30) - (temp_ft4 * segment->up.z);
    Math_OrthonormalizeAroundForward(basis);
}

s32 func_i2_800B10A8(RacerSegmentPositionInfo* arg0, f32 arg1, f32 arg2, f32 arg3, Mtx3F* arg4) {
    s32 i;
    Vec3f sp130;
    CourseSegment* var_s1_2;
    CourseSegment* var_v1;
    CourseSegment* var_v0;
    CourseSegment* var_a0;
    f32 tSquare;
    f32 tCube;
    f32 sp114;
    f32 sp110;
    f32 sp10C;
    f32 temp_fv1;
    f32 sp78;
    f32 sp74;
    s32 pad;
    f32 tension;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 spE8;
    CourseSegment* var_s0;
    CourseSegment* var_s1;
    CourseSegment* var_s2;
    CourseSegment* var_s3;
    RacerSegmentPositionInfo sp88;

    i = 3;

    sp130.x = arg1 - arg0->lastGroundedPos.x;
    sp130.y = arg2 - arg0->lastGroundedPos.y;
    sp130.z = arg3 - arg0->lastGroundedPos.z;

    var_s0 = arg0->courseSegment;
    var_s1 = var_s0->next;
    var_s2 = var_s0->prev;
    var_s3 = var_s1->next;
    tension = var_s0->tension;

    sp114 = tension - 2.0f;
    sp110 = sp114 - 1.0f;
    sp10C = sp110 + tension;
    sp78 = (sp10C - 3.0f) + tension;
    sp74 = sp78 + tension;

    sp88.segmentTValue = arg0->segmentTValue;
    sp88.courseSegment = arg0->courseSegment;
    sp88.segmentForward = arg0->segmentForward;
    sp88.segmentForwardMagnitude = arg0->segmentForwardMagnitude;

    while ((SQ_SUM(&sp130) > 5.0f) && (--i != 0)) {
        sp88.segmentTValue += (DOT_XYZ(&sp130, &sp88.segmentForward) / SQ(sp88.segmentForwardMagnitude));
        if (sp88.segmentTValue >= 1.0f) {
            if (sp88.segmentTValue > 1.9f) {
                return -1;
            }
            sp88.courseSegment = sp88.courseSegment->next;
            var_s2 = var_s0;
            var_s0 = var_s1;
            var_s1 = var_s3;
            var_s3 = sp88.courseSegment->next->next;
            tension = sp88.courseSegment->tension;
            sp114 = tension - 2.0f;
            sp110 = sp114 - 1.0f;
            sp10C = sp110 + tension;
            sp88.segmentTValue -= 1.0f;
            sp88.segmentTValue *=
                (sp88.segmentForwardMagnitude / Course_SplineGetTangent(sp88.courseSegment, 0.0f, &sp130));
        } else if (sp88.segmentTValue < 0.0f) {
            if (sp88.segmentTValue < -0.9f) {
                return -1;
            }
            sp88.courseSegment = sp88.courseSegment->prev;
            var_s3 = var_s1;
            var_s1 = var_s0;
            var_s0 = var_s2;
            var_s2 = sp88.courseSegment->prev;
            tension = sp88.courseSegment->tension;
            sp114 = tension - 2.0f;
            sp110 = sp114 - 1.0f;
            sp10C = sp110 + tension;

            sp88.segmentTValue *=
                (sp88.segmentForwardMagnitude / Course_SplineGetTangent(sp88.courseSegment, 1.0f, &sp130));
            sp88.segmentTValue += 1.0f;
        }
        tSquare = SQ(sp88.segmentTValue);
        tCube = tSquare * sp88.segmentTValue;
        temp_fa0 = (((2.0f * tSquare) - sp88.segmentTValue) - tCube) * tension;
        temp_fa1 = ((sp110 * tSquare) - sp114 * tCube) + 1.0f;
        temp_ft4 = (sp114 * tCube - (sp10C * tSquare)) + (tension * sp88.segmentTValue);
        spE8 = (tCube - tSquare) * tension;

        sp88.segmentPos.x = (temp_fa0 * var_s2->pos.x) + (temp_fa1 * var_s0->pos.x) + (temp_ft4 * var_s1->pos.x) +
                            (spE8 * var_s3->pos.x);
        sp88.segmentPos.y = (temp_fa0 * var_s2->pos.y) + (temp_fa1 * var_s0->pos.y) + (temp_ft4 * var_s1->pos.y) +
                            (spE8 * var_s3->pos.y);
        sp88.segmentPos.z = (temp_fa0 * var_s2->pos.z) + (temp_fa1 * var_s0->pos.z) + (temp_ft4 * var_s1->pos.z) +
                            (spE8 * var_s3->pos.z);

        sp78 = (sp10C - 3.0f) + tension;
        sp74 = sp78 + tension;

        temp_fa0 = (((4.0f * sp88.segmentTValue) - 1.0f) - (3.0f * tSquare)) * tension;
        temp_fa1 = ((sp10C - 3.0f) * sp88.segmentTValue) - sp78 * tSquare;
        temp_ft4 = (sp78 * tSquare - (sp74 * sp88.segmentTValue)) + tension;
        spE8 = ((3.0f * tSquare) - (2.0f * sp88.segmentTValue)) * tension;

        sp88.segmentForward.x = (temp_fa0 * var_s2->pos.x) + (temp_fa1 * var_s0->pos.x) + (temp_ft4 * var_s1->pos.x) +
                                (spE8 * var_s3->pos.x);
        sp88.segmentForward.y = (temp_fa0 * var_s2->pos.y) + (temp_fa1 * var_s0->pos.y) + (temp_ft4 * var_s1->pos.y) +
                                (spE8 * var_s3->pos.y);
        sp88.segmentForward.z = (temp_fa0 * var_s2->pos.z) + (temp_fa1 * var_s0->pos.z) + (temp_ft4 * var_s1->pos.z) +
                                (spE8 * var_s3->pos.z);

        sp88.segmentForwardMagnitude = sqrtf(SQ_SUM(&sp88.segmentForward));

        sp88.segmentDisplacement.x = arg1 - sp88.segmentPos.x;
        sp88.segmentDisplacement.y = arg2 - sp88.segmentPos.y;
        sp88.segmentDisplacement.z = arg3 - sp88.segmentPos.z;

        sp88.distanceFromSegment = sqrtf(SQ_SUM(&sp88.segmentDisplacement));

        if (sp88.distanceFromSegment < 0.001f) {
            break;
        }
        sp88.pos.x = CROSS_X(&sp88.segmentDisplacement, &sp88.segmentForward);
        sp88.pos.y = CROSS_Y(&sp88.segmentDisplacement, &sp88.segmentForward);
        sp88.pos.z = CROSS_Z(&sp88.segmentDisplacement, &sp88.segmentForward);

        sp88.segmentDisplacement.x = CROSS_X(&sp88.segmentForward, &sp88.pos);
        sp88.segmentDisplacement.y = CROSS_Y(&sp88.segmentForward, &sp88.pos);
        sp88.segmentDisplacement.z = CROSS_Z(&sp88.segmentForward, &sp88.pos);

        temp_fv1 = sp88.distanceFromSegment / sqrtf(SQ_SUM(&sp88.segmentDisplacement));
        sp130.x = arg1 - ((sp88.segmentDisplacement.x * temp_fv1) + sp88.segmentPos.x);
        sp130.y = arg2 - ((sp88.segmentDisplacement.y * temp_fv1) + sp88.segmentPos.y);
        sp130.z = arg3 - ((sp88.segmentDisplacement.z * temp_fv1) + sp88.segmentPos.z);
    }

    var_s1_2 = sp88.courseSegment;
    var_v0 = var_s1_2->next;
    var_v1 = var_s1_2->prev;
    var_a0 = var_v0->next;

    tSquare = SQ(sp88.segmentTValue);

    tension = var_s1_2->tension;
    temp_fa0 = (((4.0f * sp88.segmentTValue) - 1.0f) - 3.0f * tSquare) * tension;
    temp_fa1 = ((6.0f - 3.0f * tension) * tSquare) + (((2.0f * tension) - 6.0f) * sp88.segmentTValue);
    temp_ft4 = ((3.0f * tension - 6.0f) * tSquare) + ((6.0f - (4.0f * tension)) * sp88.segmentTValue) + tension;
    spE8 = (3.0f * tSquare - (2.0f * sp88.segmentTValue)) * tension;

    arg4->x.x =
        (temp_fa0 * var_v1->pos.x) + (temp_fa1 * var_s1_2->pos.x) + (temp_ft4 * var_v0->pos.x) + (spE8 * var_a0->pos.x);
    arg4->x.y =
        (temp_fa0 * var_v1->pos.y) + (temp_fa1 * var_s1_2->pos.y) + (temp_ft4 * var_v0->pos.y) + (spE8 * var_a0->pos.y);
    arg4->x.z =
        (temp_fa0 * var_v1->pos.z) + (temp_fa1 * var_s1_2->pos.z) + (temp_ft4 * var_v0->pos.z) + (spE8 * var_a0->pos.z);

    temp_fv1 = 1.0f / sqrtf(SQ_SUM(&arg4->x));
    arg4->x.x *= temp_fv1;
    arg4->x.y *= temp_fv1;
    arg4->x.z *= temp_fv1;

    arg4->y.x = ((var_s1_2->next->up.x - var_s1_2->up.x) * sp88.segmentTValue) + var_s1_2->up.x;
    arg4->y.y = ((var_s1_2->next->up.y - var_s1_2->up.y) * sp88.segmentTValue) + var_s1_2->up.y;
    arg4->y.z = ((var_s1_2->next->up.z - var_s1_2->up.z) * sp88.segmentTValue) + var_s1_2->up.z;

    if ((arg4->y.x == 0.0f) && (arg4->y.y == 0.0f) && (arg4->y.z == 0.0f)) {
        func_i2_800B0FAC(var_s1_2, arg4);
        return 0;
    }

    arg4->z.x = CROSS_X(&arg4->y, &arg4->x);
    arg4->z.y = CROSS_Y(&arg4->y, &arg4->x);
    arg4->z.z = CROSS_Z(&arg4->y, &arg4->x);

    if ((arg4->z.x == 0.0f) && (arg4->z.y == 0.0f) && (arg4->z.z == 0.0f)) {
        func_i2_800B0FAC(var_s1_2, arg4);
        return 0;
    }

    temp_fv1 = 1.0f / sqrtf(SQ_SUM(&arg4->z));
    arg4->z.x *= temp_fv1;
    arg4->z.y *= temp_fv1;
    arg4->z.z *= temp_fv1;
    return 0;
}

#ifdef NON_EQUIVALENT
void func_i2_800B1AF0(CourseSegment* segment, f32* arg1, f32* arg2) {
    f64 temp_ft5;
    f64 temp_fs0;
    f64 temp_fs1;
    f64 temp_fs2;
    f64 temp_fs3;
    f64 temp_fs4;
    f64 spB0;
    f64 spA8;
    f64 sp60;
    f64 sp58;
    f64 sp48;
    f64 temp_fv0_5;
    f64 temp_fa0_3;
    f64 temp_fa1_3;
    f64 temp_ft5_2;
    f64 temp_fv0_6;
    f64 temp_ft4;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* nextNextSegment = nextSegment->next;

    temp_ft5 = segment->pos.x - nextSegment->pos.x;
    temp_fs2 = prevSegment->pos.x - nextNextSegment->pos.x + temp_ft5;
    temp_fs0 = segment->pos.y - nextSegment->pos.y;
    temp_fs3 = prevSegment->pos.y - nextNextSegment->pos.y + temp_fs0;
    temp_fs1 = segment->pos.z - nextSegment->pos.z;
    temp_fs4 = prevSegment->pos.z - nextNextSegment->pos.z + temp_fs1;

    sp58 = ((temp_ft5 * temp_fs2) + (temp_fs0 * temp_fs3) + (temp_fs1 * temp_fs4)) * 0.75;
    spB0 = SQ(sp58);
    spA8 = (SQ(temp_ft5) + SQ(temp_fs0) + SQ(temp_fs1)) * 9.0;

    temp_fv0_5 = nextSegment->pos.x - prevSegment->pos.x;
    temp_fa0_3 = nextSegment->pos.y - prevSegment->pos.y;
    temp_fa1_3 = nextSegment->pos.z - prevSegment->pos.z;
    sp60 = (SQ(temp_fs2) + SQ(temp_fs3) + SQ(temp_fs4)) * 0.0625;
    sp48 = sp60 - SQ(temp_fv0_5) - SQ(temp_fa0_3) - SQ(temp_fa1_3);
    temp_ft5_2 = sp48 * spA8;

    if (temp_ft5_2 <= spB0) {
        temp_fv0_6 = sqrtf(spB0 - temp_ft5_2);
        temp_ft4 = 2.0 * sp48;
        if (temp_ft4 < -0.1) {
            *arg1 = (sp58 - temp_fv0_6) / temp_ft4;
        } else if (temp_ft4 > 0.1) {
            *arg1 = (sp58 + temp_fv0_6) / temp_ft4;
        } else {
            *arg1 = -1.0f;
        }
    } else {
        *arg1 = -1.0f;
    }

    temp_fv0_5 = nextNextSegment->pos.x - segment->pos.x;
    temp_fa0_3 = nextNextSegment->pos.y - segment->pos.y;
    temp_fa1_3 = nextNextSegment->pos.z - segment->pos.z;
    sp48 = sp60 - SQ(temp_fv0_5) - SQ(temp_fa0_3) - SQ(temp_fa1_3);
    temp_ft5_2 = sp48 * spA8;
    if (temp_ft5_2 <= spB0) {
        temp_fv0_6 = sqrtf(spB0 - temp_ft5_2);
        temp_ft4 = 2.0 * sp48;
        if (temp_ft4 < -0.1) {
            *arg2 = (sp58 - temp_fv0_6) / temp_ft4;
        } else if (temp_ft4 > 0.1) {
            *arg2 = (sp58 + temp_fv0_6) / temp_ft4;
        } else {
            *arg2 = -1.0f;
        }
    } else {
        *arg2 = -1.0f;
    }
}
#else
void func_i2_800B1AF0(CourseSegment*, f32*, f32*);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B1AF0.s")
#endif

s32 Course_SplineCalculateTensions(CourseInfo* courseInfo) {
    f32 alpha1;
    f32 alpha2;
    CourseSegment* segment = courseInfo->courseSegments;

    do {
        func_i2_800B1AF0(segment, &alpha1, &alpha2);
        if ((alpha1 < 0.0f) || (alpha1 > 2.0f) || (alpha2 < 0.0f) || (alpha2 > 2.0f)) {
            return -1;
        }
        segment->tension = (alpha1 + alpha2) * 0.5f;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);

    return 0;
}

// Get Rough Racer Lap Distance
f32 func_i2_800B1F68(RacerSegmentPositionInfo* arg0) {
    f32 length;
    Vec3f posDiff;

    if (arg0->segmentTValue < 0.5f) {
        if (arg0->segmentTValue < 0.25f) {
            length = 0.0f;
            posDiff.x = arg0->segmentPos.x - arg0->courseSegment->pos.x;
            posDiff.y = arg0->segmentPos.y - arg0->courseSegment->pos.y;
            posDiff.z = arg0->segmentPos.z - arg0->courseSegment->pos.z;
        } else {
            length = arg0->courseSegment->quarterMarkLength;
            posDiff.x = arg0->segmentPos.x - arg0->courseSegment->quarterMarkPos.x;
            posDiff.y = arg0->segmentPos.y - arg0->courseSegment->quarterMarkPos.y;
            posDiff.z = arg0->segmentPos.z - arg0->courseSegment->quarterMarkPos.z;
        }
    } else if (arg0->segmentTValue < 0.75f) {
        length = arg0->courseSegment->halfMarkLength;
        posDiff.x = arg0->segmentPos.x - arg0->courseSegment->halfMarkPos.x;
        posDiff.y = arg0->segmentPos.y - arg0->courseSegment->halfMarkPos.y;
        posDiff.z = arg0->segmentPos.z - arg0->courseSegment->halfMarkPos.z;
    } else {
        length = arg0->courseSegment->threeQuarterMarkLength;
        posDiff.x = arg0->segmentPos.x - arg0->courseSegment->threeQuarterMarkPos.x;
        posDiff.y = arg0->segmentPos.y - arg0->courseSegment->threeQuarterMarkPos.y;
        posDiff.z = arg0->segmentPos.z - arg0->courseSegment->threeQuarterMarkPos.z;
    }

    length += sqrtf(SQ(posDiff.x) + SQ(posDiff.y) + SQ(posDiff.z));
    arg0->segmentLengthProportion = length / arg0->courseSegment->length;
    return arg0->courseSegment->lengthFromStart + length;
}

// Get Length Into Course Segment
// Returns Length proportion along the track
f32 Course_SplineGetLengthInfo(CourseSegment* segment, f32 targetT, f32* lengthFromStart) {
    f32 tension;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 t;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 tSquare;
    f32 tCube;
    f32 tEnd;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_ft4;
    f32 spA4;
    Vec3f sp98;
    Vec3f sp8C;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    spD8 = tension - 2.0f;
    spD4 = tension - 3.0f;
    spD0 = 3.0f - (2.0f * tension);
    *lengthFromStart = 0.0f;
    if (targetT < 0.5f) {
        t = 0.0f;
        tEnd = targetT;
    } else {
        t = targetT;
        tEnd = 1.0f;
    }

    tSquare = SQ(t);
    tCube = tSquare * t;
    temp_fa0 = (2.0f * tSquare - t - tCube) * tension;
    temp_fa1 = spD4 * tSquare - spD8 * tCube + 1.0f;
    temp_ft4 = spD8 * tCube + spD0 * tSquare + tension * t;
    spA4 = (tCube - tSquare) * tension;

    sp98.x = temp_fa0 * prevSegment->pos.x + temp_fa1 * segment->pos.x + temp_ft4 * nextSegment->pos.x +
             spA4 * nextNextSegment->pos.x;
    sp98.y = temp_fa0 * prevSegment->pos.y + temp_fa1 * segment->pos.y + temp_ft4 * nextSegment->pos.y +
             spA4 * nextNextSegment->pos.y;
    sp98.z = temp_fa0 * prevSegment->pos.z + temp_fa1 * segment->pos.z + temp_ft4 * nextSegment->pos.z +
             spA4 * nextNextSegment->pos.z;

    while (t < tEnd) {
        t += 0.05f;
        if (tEnd < t) {
            t = tEnd;
        }

        tSquare = SQ(t);
        tCube = tSquare * t;
        temp_fa0 = (2.0f * tSquare - t - tCube) * tension;
        temp_fa1 = spD4 * tSquare - spD8 * tCube + 1.0f;
        temp_ft4 = spD8 * tCube + spD0 * tSquare + tension * t;
        spA4 = (tCube - tSquare) * tension;

        sp8C.x = (prevSegment->pos.x * temp_fa0) + (temp_fa1 * segment->pos.x) + (temp_ft4 * nextSegment->pos.x) +
                 (spA4 * nextNextSegment->pos.x);
        temp_fs2 = sp8C.x - sp98.x;
        sp8C.y = (prevSegment->pos.y * temp_fa0) + (temp_fa1 * segment->pos.y) + (temp_ft4 * nextSegment->pos.y) +
                 (spA4 * nextNextSegment->pos.y);
        temp_fv0 = sp8C.y - sp98.y;
        sp8C.z = (prevSegment->pos.z * temp_fa0) + (temp_fa1 * segment->pos.z) + (temp_ft4 * nextSegment->pos.z) +
                 (spA4 * nextNextSegment->pos.z);
        temp_fv1 = sp8C.z - sp98.z;

        *lengthFromStart += sqrtf(SQ(temp_fs2) + SQ(temp_fv0) + SQ(temp_fv1));

        sp98 = sp8C;
    }

    if (targetT >= 0.5f) {
        *lengthFromStart = segment->length - *lengthFromStart;
    }

    t = *lengthFromStart / segment->length;
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    *lengthFromStart += segment->lengthFromStart;
    return t;
}

// Get un-normalised tangent vector along course segment (and magnitude)
f32 Course_SplineGetTangent(CourseSegment* segment, f32 t, Vec3f* tangentVec) {
    f32 tSquare;
    f32 tension;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tSquare = SQ(t);
    tension = segment->tension;

    sp44 = (4.0f * t - 1.0f - (3.0f * tSquare)) * tension;
    sp40 = (6.0f - 3.0f * tension) * tSquare + (2.0f * tension - 6.0f) * t;
    sp3C = (3.0f * tension - 6.0f) * tSquare + (6.0f - 4.0f * tension) * t + tension;
    sp38 = ((3.0f * tSquare) - 2.0f * t) * tension;

    tangentVec->x =
        sp44 * prevSegment->pos.x + sp40 * segment->pos.x + sp3C * nextSegment->pos.x + sp38 * nextNextSegment->pos.x;
    tangentVec->y =
        sp44 * prevSegment->pos.y + sp40 * segment->pos.y + sp3C * nextSegment->pos.y + sp38 * nextNextSegment->pos.y;
    tangentVec->z =
        sp44 * prevSegment->pos.z + sp40 * segment->pos.z + sp3C * nextSegment->pos.z + sp38 * nextNextSegment->pos.z;

    return sqrtf(SQ(tangentVec->x) + SQ(tangentVec->y) + SQ(tangentVec->z));
}

// Get position along course segment
void Course_SplineGetPosition(CourseSegment* segment, f32 t, Vec3f* pos) {
    f32 tension;
    f32 tSquare;
    f32 tCube;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    tSquare = SQ(t);
    tCube = tSquare * t;
    sp30 = (2.0f * tSquare - t - tCube) * tension;
    sp2C = (2.0f - tension) * tCube + (tension - 3.0f) * tSquare + 1.0f;
    sp28 = (tension - 2.0f) * tCube + (3.0f - 2.0f * tension) * tSquare + tension * t;
    sp24 = (tCube - tSquare) * tension;

    pos->x =
        sp30 * prevSegment->pos.x + sp2C * segment->pos.x + sp28 * nextSegment->pos.x + sp24 * nextNextSegment->pos.x;
    pos->y =
        sp30 * prevSegment->pos.y + sp2C * segment->pos.y + sp28 * nextSegment->pos.y + sp24 * nextNextSegment->pos.y;
    pos->z =
        sp30 * prevSegment->pos.z + sp2C * segment->pos.z + sp28 * nextSegment->pos.z + sp24 * nextNextSegment->pos.z;
}

// Get segment basis matrix (forward = tangent vector, up = up, left-right = horizontal road slope vector)
// NOTE: z vector is positive in the left direction!
// Returns magnitude of tangent
f32 Course_SplineGetBasis(CourseSegment* segment, f32 t, Mtx3F* basis, f32 lengthProportionAlongSegment) {
    f32 tension;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    CourseSegment* nextSegment = segment->next;
    CourseSegment* prevSegment = segment->prev;
    CourseSegment* nextNextSegment = nextSegment->next;

    tension = segment->tension;
    sp50 = SQ(t);
    sp4C = (4.0f * t - 1.0f - 3.0f * sp50) * tension;
    sp48 = (6.0f - 3.0f * tension) * sp50 + (2.0f * tension - 6.0f) * t;
    sp44 = (3.0f * tension - 6.0f) * sp50 + (6.0f - 4.0f * tension) * t + tension;
    sp40 = (3.0f * sp50 - 2.0f * t) * tension;

    basis->x.x =
        sp4C * prevSegment->pos.x + sp48 * segment->pos.x + sp44 * nextSegment->pos.x + sp40 * nextNextSegment->pos.x;
    basis->x.y =
        sp4C * prevSegment->pos.y + sp48 * segment->pos.y + sp44 * nextSegment->pos.y + sp40 * nextNextSegment->pos.y;
    basis->x.z =
        sp4C * prevSegment->pos.z + sp48 * segment->pos.z + sp44 * nextSegment->pos.z + sp40 * nextNextSegment->pos.z;

    sp50 = sqrtf(SQ(basis->x.x) + SQ(basis->x.y) + SQ(basis->x.z));
    tension = 1.0f / sp50;

    basis->x.x *= tension;
    basis->x.y *= tension;
    basis->x.z *= tension;

    basis->y.x = (segment->next->up.x - segment->up.x) * lengthProportionAlongSegment + segment->up.x;
    basis->y.y = (segment->next->up.y - segment->up.y) * lengthProportionAlongSegment + segment->up.y;
    basis->y.z = (segment->next->up.z - segment->up.z) * lengthProportionAlongSegment + segment->up.z;

    if ((basis->y.x == 0.0f) && (basis->y.y == 0.0f) && (basis->y.z == 0.0f)) {
        func_i2_800B0FAC(segment, basis);
        return sp50;
    }

    basis->z.x = basis->y.y * basis->x.z - basis->y.z * basis->x.y;
    basis->z.y = basis->y.z * basis->x.x - basis->y.x * basis->x.z;
    basis->z.z = basis->y.x * basis->x.y - basis->y.y * basis->x.x;

    if ((basis->z.x == 0.0f) && (basis->z.y == 0.0f) && (basis->z.z == 0.0f)) {
        func_i2_800B0FAC(segment, basis);
        return sp50;
    }

    tension = 1.0f / sqrtf(SQ(basis->z.x) + SQ(basis->z.y) + SQ(basis->z.z));

    basis->z.x *= tension;
    basis->z.y *= tension;
    basis->z.z *= tension;

    basis->y.x = basis->x.y * basis->z.z - basis->x.z * basis->z.y;
    basis->y.y = basis->x.z * basis->z.x - basis->x.x * basis->z.z;
    basis->y.z = basis->x.x * basis->z.y - basis->x.y * basis->z.x;

    return sp50;
}

s32 func_i2_800B2C00(RacerSegmentPositionInfo* arg0, f32 xPos, f32 yPos, f32 zPos, s32 i, f32 arg5) {
    s32 pad2;
    Vec3f spD0;
    f32 temp_ft4;
    f32 temp_ft5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 spBC;
    f32 spB8;
    f32 spB4;
    f32 pad;
    f32 temp_fa0;
    f32 tension;
    f32 var_fs5;
    f32 tSquare;
    f32 tCube;
    CourseSegment* prevSegment;
    CourseSegment* nextNextSegment;
    CourseSegment* segment;
    CourseSegment* nextSegment;

    spD0.x = xPos - arg0->lastGroundedPos.x;
    spD0.y = yPos - arg0->lastGroundedPos.y;
    spD0.z = zPos - arg0->lastGroundedPos.z;

    segment = arg0->courseSegment;
    nextSegment = segment->next;
    prevSegment = segment->prev;
    nextNextSegment = nextSegment->next;

    tension = segment->tension;
    var_fs5 = tension - 2.0f;

    spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
    spB8 = spBC + tension;
    spB4 = spB8 + tension;

    while ((arg5 < (SQ_SUM(&spD0))) && (--i != 0)) {

        arg0->segmentTValue += DOT_XYZ(&spD0, &arg0->segmentForward) / SQ(arg0->segmentForwardMagnitude);

        if (arg0->segmentTValue >= 1.0f) {
            if (arg0->segmentTValue > 1.9f) {
                return -1;
            }
            arg0->courseSegment = arg0->courseSegment->next;
            prevSegment = segment;
            segment = nextSegment;
            nextSegment = nextNextSegment;
            nextNextSegment = arg0->courseSegment->next->next;
            tension = arg0->courseSegment->tension;

            var_fs5 = tension - 2.0f;

            spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
            spB8 = spBC + tension;
            spB4 = spB8 + tension;

            arg0->segmentTValue -= 1.0f;

            arg0->segmentTValue *=
                arg0->segmentForwardMagnitude / Course_SplineGetTangent(arg0->courseSegment, 0.0f, &spD0);
        } else if (arg0->segmentTValue < 0.0f) {
            if (arg0->segmentTValue < -0.9f) {
                return -1;
            }
            arg0->courseSegment = arg0->courseSegment->prev;
            nextNextSegment = nextSegment;
            nextSegment = segment;
            segment = prevSegment;
            prevSegment = arg0->courseSegment->prev;
            tension = arg0->courseSegment->tension;

            var_fs5 = tension - 2.0f;

            spBC = ((var_fs5 - 1.0f) + tension) - 3.0f;
            spB8 = spBC + tension;
            spB4 = spB8 + tension;

            arg0->segmentTValue *=
                arg0->segmentForwardMagnitude / Course_SplineGetTangent(arg0->courseSegment, 1.0f, &spD0);
            arg0->segmentTValue += 1.0f;
        }

        tCube = tSquare = SQ(arg0->segmentTValue);
        tCube *= arg0->segmentTValue;

        temp_ft4 = ((2.0f * tSquare) - arg0->segmentTValue - tCube) * tension;
        temp_ft5 = (((var_fs5 - 1.0f) * tSquare) - var_fs5 * tCube) + 1.0f;
        temp_fs1 = (var_fs5 * tCube - (((var_fs5 - 1.0f) + tension) * tSquare)) + (tension * arg0->segmentTValue);
        temp_fs2 = (tCube - tSquare) * tension;

        arg0->segmentPos.x = (temp_ft4 * prevSegment->pos.x) + (temp_ft5 * segment->pos.x) +
                             (temp_fs1 * nextSegment->pos.x) + (temp_fs2 * nextNextSegment->pos.x);
        arg0->segmentPos.y = (temp_ft4 * prevSegment->pos.y) + (temp_ft5 * segment->pos.y) +
                             (temp_fs1 * nextSegment->pos.y) + (temp_fs2 * nextNextSegment->pos.y);
        arg0->segmentPos.z = (temp_ft4 * prevSegment->pos.z) + (temp_ft5 * segment->pos.z) +
                             (temp_fs1 * nextSegment->pos.z) + (temp_fs2 * nextNextSegment->pos.z);

        temp_ft4 = (((arg0->segmentTValue * 4.0f) - 1.0f) - (3.0f * tSquare)) * tension;
        temp_ft5 = (arg0->segmentTValue * spBC) - spB8 * tSquare;
        temp_fs1 = (spB8 * tSquare - (spB4 * arg0->segmentTValue)) + tension;
        temp_fs2 = ((3.0f * tSquare) - (2.0f * arg0->segmentTValue)) * tension;

        arg0->segmentForward.x = (temp_ft4 * prevSegment->pos.x) + (temp_ft5 * segment->pos.x) +
                                 (temp_fs1 * nextSegment->pos.x) + (temp_fs2 * nextNextSegment->pos.x);
        arg0->segmentForward.y = (temp_ft4 * prevSegment->pos.y) + (temp_ft5 * segment->pos.y) +
                                 (temp_fs1 * nextSegment->pos.y) + (temp_fs2 * nextNextSegment->pos.y);
        arg0->segmentForward.z = (temp_ft4 * prevSegment->pos.z) + (temp_ft5 * segment->pos.z) +
                                 (temp_fs1 * nextSegment->pos.z) + (temp_fs2 * nextNextSegment->pos.z);

        arg0->segmentForwardMagnitude = sqrtf(SQ_SUM(&arg0->segmentForward));
        arg0->segmentDisplacement.x = xPos - arg0->segmentPos.x;
        arg0->segmentDisplacement.y = yPos - arg0->segmentPos.y;
        arg0->segmentDisplacement.z = zPos - arg0->segmentPos.z;
        arg0->distanceFromSegment = sqrtf(SQ_SUM(&arg0->segmentDisplacement));

        if (arg0->distanceFromSegment < 0.001f) {
            break;
        }

        arg0->pos.x = CROSS_X(&arg0->segmentDisplacement, &arg0->segmentForward);
        arg0->pos.y = CROSS_Y(&arg0->segmentDisplacement, &arg0->segmentForward);
        arg0->pos.z = CROSS_Z(&arg0->segmentDisplacement, &arg0->segmentForward);

        arg0->segmentDisplacement.x = CROSS_X(&arg0->segmentForward, &arg0->pos);
        arg0->segmentDisplacement.y = CROSS_Y(&arg0->segmentForward, &arg0->pos);
        arg0->segmentDisplacement.z = CROSS_Z(&arg0->segmentForward, &arg0->pos);

        temp_fa0 = SQ_SUM(&arg0->segmentDisplacement);
        if (temp_fa0 == 0.0f) {
            break;
        }

        temp_fa0 = arg0->distanceFromSegment / sqrtf(temp_fa0);

        arg0->segmentDisplacement.x *= temp_fa0;
        arg0->lastGroundedPos.x = pad = arg0->segmentDisplacement.x + arg0->segmentPos.x;
        spD0.x = xPos - arg0->lastGroundedPos.x;

        arg0->segmentDisplacement.y *= temp_fa0;
        arg0->lastGroundedPos.y = pad = arg0->segmentDisplacement.y + arg0->segmentPos.y;
        spD0.y = yPos - arg0->lastGroundedPos.y;

        arg0->segmentDisplacement.z *= temp_fa0;
        arg0->lastGroundedPos.z = pad = arg0->segmentDisplacement.z + arg0->segmentPos.z;
        spD0.z = zPos - arg0->lastGroundedPos.z;
    }

    arg0->segmentDisplacement.x = xPos - arg0->segmentPos.x;
    arg0->segmentDisplacement.y = yPos - arg0->segmentPos.y;
    arg0->segmentDisplacement.z = zPos - arg0->segmentPos.z;

    arg0->pos.x = xPos;
    arg0->pos.y = yPos;
    arg0->pos.z = zPos;
    arg0->distanceFromSegment = sqrtf(SQ_SUM(&arg0->segmentDisplacement));

    return 0;
}

s32 func_i2_800B3360(CourseInfo* courseInfo) {
    CourseSegment* var_s0 = courseInfo->courseSegments;
    Mtx3F sp30;

    do {
        sp30.y.x = var_s0->up.x;
        sp30.y.y = var_s0->up.y;
        sp30.y.z = var_s0->up.z;
        Course_SplineGetTangent(var_s0, 0.0f, &sp30.x);
        if (Math_OrthonormalizeAroundForward(&sp30) != 0) {
            return -1;
        }
        var_s0->up.x = sp30.y.x;
        var_s0->up.y = sp30.y.y;
        var_s0->up.z = sp30.y.z;
        var_s0 = var_s0->next;
    } while (var_s0 != courseInfo->courseSegments);

    return 0;
}

extern bool gInCourseEditor;

s32 Course_SegmentJoinsInit(CourseInfo* courseInfo) {
    s32 var_v1 = 0;
    CourseSegment* var_v0 = courseInfo->courseSegments;

    do {
        var_v0->trackSegmentInfo &= ~TRACK_JOIN_MASK;
        if (var_v0->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            continue;
        }

        if (var_v0->prev->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            var_v0->trackSegmentInfo |= TRACK_JOIN_PREVIOUS;
        }

        if (var_v0->next->trackSegmentInfo & TRACK_FLAG_JOINABLE) {
            var_v0->trackSegmentInfo |= TRACK_JOIN_NEXT;
        }

        switch (var_v0->trackSegmentInfo & TRACK_JOIN_MASK) {
            case TRACK_JOIN_PREVIOUS:
            case TRACK_JOIN_NEXT:
                if (var_v0->length <=
                    (gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) var_v0->trackSegmentInfo & TRACK_SHAPE_MASK)] +
                     100.0f)) {
                    var_v1 = -1;
                    if (gInCourseEditor) {
                        func_xk2_800F1330(var_v0 - courseInfo->courseSegments, 2);
                    }
                }
                break;
            case TRACK_JOIN_BOTH:
                if (var_v0->length <=
                    ((2.0f *
                      gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) var_v0->trackSegmentInfo & TRACK_SHAPE_MASK)]) +
                     100.0f)) {
                    var_v1 = -1;
                    if (gInCourseEditor) {
                        func_xk2_800F1330(var_v0 - courseInfo->courseSegments, 2);
                    }
                }
                break;
            default:
                break;
        }

    } while ((var_v0 = var_v0->next) != courseInfo->courseSegments);

    return var_v1;
}

void Course_SegmentLengthsInit(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    f32 spD8;
    f32 spD4;
    f32 spD0;
    f32 cube;
    f32 square;
    f32 temp_fv1;
    f32 temp_fa1;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fv0;
    f32 spB0;
    f32 spAC;
    f32 spA8;
    Vec3f sp9C;
    Vec3f sp90;
    s32 i;

    courseInfo->length = 0.0f;
    do {
        f32 tension = segment->tension;
        CourseSegment* nextSegment = segment->next;
        CourseSegment* prevSegment = segment->prev;
        CourseSegment* nextNextSegment = nextSegment->next;

        spD8 = tension - 2.0f;
        spD4 = tension - 3.0f;
        spD0 = 3.0f - (2.0f * tension);

        sp9C = segment->pos;
        segment->length = 0.0f;

        for (i = 1; i <= 50; i++) {
            temp_fv1 = (f32) i / 50.0f;
            square = SQ(temp_fv1);
            cube = square * temp_fv1;
            temp_fa1 = (2.0f * square - temp_fv1 - cube) * tension;
            spB0 = (spD4 * square - spD8 * cube) + 1.0f;
            spAC = spD8 * cube + spD0 * square + tension * temp_fv1;
            spA8 = (cube - square) * tension;

            sp90.x = temp_fa1 * prevSegment->pos.x + spB0 * segment->pos.x + spAC * nextSegment->pos.x +
                     spA8 * nextNextSegment->pos.x;
            temp_fs3 = sp90.x - sp9C.x;
            sp90.y = temp_fa1 * prevSegment->pos.y + spB0 * segment->pos.y + spAC * nextSegment->pos.y +
                     spA8 * nextNextSegment->pos.y;
            temp_fs4 = sp90.y - sp9C.y;
            sp90.z = temp_fa1 * prevSegment->pos.z + spB0 * segment->pos.z + spAC * nextSegment->pos.z +
                     spA8 * nextNextSegment->pos.z;
            temp_fv0 = sp90.z - sp9C.z;

            segment->length += sqrtf(SQ(temp_fs3) + SQ(temp_fs4) + SQ(temp_fv0));
            sp9C = sp90;
        }

        courseInfo->length += segment->length;
        segment = nextSegment;
        segment->lengthFromStart = courseInfo->length;
    } while (segment != courseInfo->courseSegments);
    courseInfo->courseSegments->lengthFromStart = 0.0f;
    segment = courseInfo->courseSegments;
    do {
        Course_SplineGetPosition(segment, 0.25f, &segment->quarterMarkPos);
        Course_SplineGetPosition(segment, 0.5f, &segment->halfMarkPos);
        Course_SplineGetPosition(segment, 0.75f, &segment->threeQuarterMarkPos);
        Course_SplineGetLengthInfo(segment, 0.25f, &segment->quarterMarkLength);
        segment->quarterMarkLength -= segment->lengthFromStart;
        Course_SplineGetLengthInfo(segment, 0.5f, &segment->halfMarkLength);
        segment->halfMarkLength -= segment->lengthFromStart;
        Course_SplineGetLengthInfo(segment, 0.75f, &segment->threeQuarterMarkLength);
        segment->threeQuarterMarkLength -= segment->lengthFromStart;
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);
}

s32 func_i2_800B39B4(CourseInfo* arg0) {
    Vec3f vec1;
    Vec3f vec2;
    f32 temp_fs0;
    CourseSegment* temp_s1;
    CourseSegment* temp_v0;
    CourseSegment* var_s0 = arg0->courseSegments;

    do {
        temp_v0 = var_s0->prev;
        temp_s1 = var_s0->next;
        vec1.x = var_s0->pos.x - temp_v0->pos.x;
        vec1.y = var_s0->pos.y - temp_v0->pos.y;
        vec1.z = var_s0->pos.z - temp_v0->pos.z;
        temp_fs0 = 1.0f / sqrtf(SQ_SUM(&vec1));

        vec1.x *= temp_fs0;
        vec1.y *= temp_fs0;
        vec1.z *= temp_fs0;

        vec2.x = temp_s1->pos.x - var_s0->pos.x;
        vec2.y = temp_s1->pos.y - var_s0->pos.y;
        vec2.z = temp_s1->pos.z - var_s0->pos.z;

        temp_fs0 = 1.0f / sqrtf(SQ_SUM(&vec2));

        vec2.x *= temp_fs0;
        vec2.y *= temp_fs0;
        vec2.z *= temp_fs0;

        if (DOT_XYZ(&vec1, &vec2) < -0.997f) {
            return var_s0 - arg0->courseSegments;
        }
        var_s0 = var_s0->next;
    } while (var_s0 != arg0->courseSegments);

    return -1;
}

f32 func_i2_800B3B4C(Mtx3F* arg0, Mtx3F* arg1, Vec3f* arg2, Vec3f* arg3) {
    f32 temp_v1;
    Vec3fFlip sp80;
    Vec3fFlip sp74;
    Vec3fFlip sp68;

    sp80.x = arg0->y.x + arg1->y.x;
    sp80.y = arg0->y.y + arg1->y.y;
    sp80.z = arg0->y.z + arg1->y.z;

    // normalize sp80
    if (SQ_SUM(&sp80) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp80));
    sp80.x *= temp_v1;
    sp80.y *= temp_v1;
    sp80.z *= temp_v1;

    // MAG(arg0->x()) * cos
    temp_v1 = DOT_XYZ(&arg0->x, &sp80);

    sp68.x = arg0->x.x - temp_v1 * sp80.x;
    sp68.y = arg0->x.y - temp_v1 * sp80.y;
    sp68.z = arg0->x.z - temp_v1 * sp80.z;

    // FAKE (Compiler Stack)
    goto dummy_label;
dummy_label:;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    // Perpendicular and normalized vector to sp80/sp68
    sp74.x = CROSS_X(&sp80, &sp68);
    sp74.y = CROSS_Y(&sp80, &sp68);
    sp74.z = CROSS_Z(&sp80, &sp68);

    temp_v1 = DOT_XYZ(&arg1->x, &sp80);

    sp68.x = arg1->x.x - temp_v1 * sp80.x;
    sp68.y = arg1->x.y - temp_v1 * sp80.y;
    sp68.z = arg1->x.z - temp_v1 * sp80.z;

    // normalize sp68
    if (SQ_SUM(&sp68) < 0.1f) {
        return 0.0f;
    }
    temp_v1 = 1.0f / sqrtf(SQ_SUM(&sp68));
    sp68.x *= temp_v1;
    sp68.y *= temp_v1;
    sp68.z *= temp_v1;

    temp_v1 = DOT_XYZ(&sp74, &sp68);
    if ((temp_v1 < 0.1f) && (temp_v1 > -0.1f)) {
        return 0.0f;
    }

    // sp68 . (arg3 - arg2)
    temp_v1 = DIST_DOT_XYZ(&sp68, arg3, arg2) / temp_v1;

    sp80.x = sp74.x * temp_v1 + arg2->x;
    sp80.y = sp74.y * temp_v1 + arg2->y;
    sp80.z = sp74.z * temp_v1 + arg2->z;

    sp74.x = arg2->x - sp80.x;
    sp74.y = arg2->y - sp80.y;
    sp74.z = arg2->z - sp80.z;

    sp68.x = arg3->x - sp80.x;
    sp68.y = arg3->y - sp80.y;
    sp68.z = arg3->z - sp80.z;

    return (sqrtf(SQ_SUM(&sp74)) + sqrtf(SQ_SUM(&sp68))) / 2.0f;
}

void Course_SegmentFormsInit(CourseInfo* courseInfo) {
    CourseSegment* segment = courseInfo->courseSegments;
    Mtx3F segmentStartBasis;
    Mtx3F segmentMidpointBasis;
    Mtx3F segmentEndBasis;
    Vec3f segmentStartPos;
    Vec3f segmentMidpointPos;
    Vec3f segmentEndPos;
    Vec3fFlip sp98;
    Vec3fFlip sp8C;
    f32 sp88;
    f32 sp7C;
    f32 temp_fs0;
    f32 temp_ft3;
    f32 temp_fv0;

    do {
        segment->trackSegmentInfo &= ~TRACK_FORM_MASK;
        Course_SplineGetBasis(segment, 0.0f, &segmentStartBasis, 0.0f);
        Course_SplineGetBasis(segment, 0.5f, &segmentMidpointBasis, 0.5f);
        Course_SplineGetBasis(segment, 1.0f, &segmentEndBasis, 1.0f);
        sp98.x = CROSS_X(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp98.y = CROSS_Y(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp98.z = CROSS_Z(&segmentStartBasis.x, &segmentMidpointBasis.x);
        sp8C.x = CROSS_X(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp8C.y = CROSS_Y(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp8C.z = CROSS_Z(&segmentMidpointBasis.x, &segmentEndBasis.x);
        sp88 = DOT_XYZ(&sp98, &segmentMidpointBasis.y);
        sp7C = DOT_XYZ(&sp8C, &segmentMidpointBasis.y);
        Course_SplineGetPosition(segment, 0.0f, &segmentStartPos);
        Course_SplineGetPosition(segment, 0.5f, &segmentMidpointPos);
        Course_SplineGetPosition(segment, 1.0f, &segmentEndPos);
        temp_fs0 = func_i2_800B3B4C(&segmentStartBasis, &segmentMidpointBasis, &segmentStartPos, &segmentMidpointPos);
        temp_fv0 = func_i2_800B3B4C(&segmentMidpointBasis, &segmentEndBasis, &segmentMidpointPos, &segmentEndPos);
        if (temp_fs0 != 0.0f) {
            if (temp_fv0 != 0.0f) {
                if (temp_fs0 < temp_fv0) {
                    segment->unk_64 = temp_fs0;
                } else {
                    segment->unk_64 = temp_fv0;
                }
                if (sp88 < 0.0f) {
                    if (sp7C < 0.0f) {
                        segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
                    } else {
                        segment->trackSegmentInfo |= TRACK_FORM_S_FLIPPED;
                    }
                } else if (sp7C < 0.0f) {
                    segment->trackSegmentInfo |= TRACK_FORM_S;
                } else {
                    segment->trackSegmentInfo |= TRACK_FORM_LEFT;
                }
            } else {
                segment->unk_64 = temp_fs0;
                if (sp88 < 0.0f) {
                    segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
                } else {
                    segment->trackSegmentInfo |= TRACK_FORM_LEFT;
                }
            }
        } else if (temp_fv0 != 0.0f) {
            segment->unk_64 = temp_fv0;
            if (sp7C < 0.0f) {
                segment->trackSegmentInfo |= TRACK_FORM_RIGHT;
            } else {
                segment->trackSegmentInfo |= TRACK_FORM_LEFT;
            }
        } else {
            segment->unk_64 = 0.0f;
            segment->trackSegmentInfo |= TRACK_FORM_STRAIGHT;
        }
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);
}

void Course_SegmentContinuousFlagInit(CourseInfo* courseInfo) {
    CourseSegment* var_v0 = courseInfo->courseSegments;
    CourseSegment* var_v1 = var_v0->prev;

    do {
        if ((var_v1->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) ==
            (var_v0->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
            var_v0->trackSegmentInfo |= TRACK_FLAG_CONTINUOUS;
        } else {
            var_v0->trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;
        }
        var_v1 = var_v0;
        var_v0 = var_v0->next;
    } while (var_v0 != courseInfo->courseSegments);
}

void func_i2_800B4338(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD) {
    f32 temp1;
    f32 temp2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;
    f32 sp6C;

    temp_fs4 = radiusLeft + 11.5f;
    temp_fs5 = radiusRight + 11.5f;
    temp1 = temp_fs4 - temp_fs5;
    temp2 = temp_fs4 + temp_fs5;
    temp_fs1 = temp1 / 2.0f;

    arg0->unk_26[0] = Math_Round(arg8->x = arg0->unk_14.x + (temp_fs1 * basis->z.x));
    arg0->unk_26[1] = Math_Round(arg8->y = arg0->unk_14.y + (temp_fs1 * basis->z.y));
    arg0->unk_26[2] = Math_Round(arg8->z = arg0->unk_14.z + (temp_fs1 * basis->z.z));

    arg0->unk_20[0] = Math_Round(arg8->x + ((argB - argC - argD) * basis->y.x));
    arg0->unk_20[1] = Math_Round(arg8->y + ((argB - argC - argD) * basis->y.y));
    arg0->unk_20[2] = Math_Round(arg8->z + ((argB - argC - argD) * basis->y.z));

    temp_fs1 = temp2 / 2.0f;

    arg6->x = (temp_fs2 = basis->y.x * temp_fs1) + arg8->x;
    arg6->y = (temp_fs3 = basis->y.y * temp_fs1) + arg8->y;
    arg6->z = (temp_fs0 = basis->y.z * temp_fs1) + arg8->z;

    arg7->x = arg8->x - temp_fs2;
    arg7->y = arg8->y - temp_fs3;
    arg7->z = arg8->z - temp_fs0;

    arg0->unk_38[0] = Math_Round(arg4->x = (temp_fs4 = basis->z.x * temp_fs1) + arg8->x);
    arg0->unk_38[1] = Math_Round(arg4->y = (temp_fs5 = basis->z.y * temp_fs1) + arg8->y);
    arg0->unk_38[2] = Math_Round(arg4->z = (sp6C = basis->z.z * temp_fs1) + arg8->z);

    arg0->unk_4A[0] = Math_Round(arg5->x = arg8->x - temp_fs4);
    arg0->unk_4A[1] = Math_Round(arg5->y = arg8->y - temp_fs5);
    arg0->unk_4A[2] = Math_Round(arg5->z = arg8->z - sp6C);

    temp_fs1 += arg9;

    arg0->unk_32[0] = Math_Round((temp_fs2 = arg8->x + (argB * basis->y.x)) + (temp_fs4 = basis->z.x * temp_fs1));
    arg0->unk_32[1] = Math_Round((temp_fs3 = arg8->y + (argB * basis->y.y)) + (temp_fs5 = basis->z.y * temp_fs1));
    arg0->unk_32[2] = Math_Round((temp_fs0 = arg8->z + (argB * basis->y.z)) + (sp6C = basis->z.z * temp_fs1));

    arg0->unk_44[0] = Math_Round(temp_fs2 - temp_fs4);
    arg0->unk_44[1] = Math_Round(temp_fs3 - temp_fs5);
    arg0->unk_44[2] = Math_Round(temp_fs0 - sp6C);

    temp_fs1 += argA;

    arg0->unk_2C[0] =
        Math_Round((temp_fs2 = arg8->x + ((argB - argC) * basis->y.x)) + (temp_fs4 = basis->z.x * temp_fs1));
    arg0->unk_2C[1] =
        Math_Round((temp_fs3 = arg8->y + ((argB - argC) * basis->y.y)) + (temp_fs5 = basis->z.y * temp_fs1));
    arg0->unk_2C[2] = Math_Round((temp_fs0 = arg8->z + ((argB - argC) * basis->y.z)) + (sp6C = basis->z.z * temp_fs1));

    arg0->unk_3E[0] = Math_Round(temp_fs2 - temp_fs4);
    arg0->unk_3E[1] = Math_Round(temp_fs3 - temp_fs5);
    arg0->unk_3E[2] = Math_Round(temp_fs0 - sp6C);
}

void func_i2_800B4728(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    func_i2_800B4338(arg0, radiusLeft, radiusRight, basis, arg4, arg5, arg6, arg7, arg8, 30.0f, 10.0f, 10.0f, 50.0f,
                     50.0f);
}

void func_i2_800B47A8(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    func_i2_800B4338(arg0, radiusLeft, radiusRight, basis, arg4, arg5, arg6, arg7, arg8, 30.0f, 20.0f, 120.0f, 155.0f,
                     50.0f);
}

void func_i2_800B4838(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    func_i2_800B489C(arg0, radiusLeft / gSinTable[0x501], radiusRight, basis, arg4, arg5, arg6, arg7, arg8);
}

void func_i2_800B489C(unk_36ED0* arg0, f32 radius, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5, Vec3f* arg6,
                      Vec3f* arg7, Vec3f* arg8) {
    f32 sp64;
    f32 sp60;
    f32 temp_fs1;
    f32 temp_fs0;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 temp_fs4;

    arg0->unk_32[0] = Math_Round(arg4->x = (arg8->x = arg0->unk_14.x) + (sp54 = basis->z.x * radius));
    arg0->unk_32[1] = Math_Round(arg4->y = (arg8->y = arg0->unk_14.y) + (sp50 = basis->z.y * radius));
    arg0->unk_32[2] = Math_Round(arg4->z = (arg8->z = arg0->unk_14.z) + (sp4C = basis->z.z * radius));

    arg0->unk_44[0] = Math_Round(arg5->x = arg0->unk_14.x - sp54);
    arg0->unk_44[1] = Math_Round(arg5->y = arg0->unk_14.y - sp50);
    arg0->unk_44[2] = Math_Round(arg5->z = arg0->unk_14.z - sp4C);

    arg0->unk_26[0] = Math_Round(arg6->x = (temp_fs2 = basis->y.x * radius) + arg0->unk_14.x);
    arg0->unk_26[1] = Math_Round(arg6->y = (temp_fs3 = basis->y.y * radius) + arg0->unk_14.y);
    arg0->unk_26[2] = Math_Round(arg6->z = (temp_fs4 = basis->y.z * radius) + arg0->unk_14.z);

    arg0->unk_20[0] = Math_Round(arg7->x = arg0->unk_14.x - temp_fs2);
    arg0->unk_20[1] = Math_Round(arg7->y = arg0->unk_14.y - temp_fs3);
    arg0->unk_20[2] = Math_Round(arg7->z = arg0->unk_14.z - temp_fs4);

    sp64 = gSinTable[0x200] * radius;

    arg0->unk_38[0] = Math_Round((sp60 = (sp54 = basis->z.x * sp64) + arg0->unk_14.x) + (temp_fs2 = basis->y.x * sp64));
    arg0->unk_38[1] =
        Math_Round((temp_fs1 = (sp50 = basis->z.y * sp64) + arg0->unk_14.y) + (temp_fs3 = basis->y.y * sp64));
    arg0->unk_38[2] =
        Math_Round((temp_fs0 = (sp4C = basis->z.z * sp64) + arg0->unk_14.z) + (temp_fs4 = basis->y.z * sp64));

    arg0->unk_2C[0] = Math_Round(sp60 - temp_fs2);
    arg0->unk_2C[1] = Math_Round(temp_fs1 - temp_fs3);
    arg0->unk_2C[2] = Math_Round(temp_fs0 - temp_fs4);

    arg0->unk_4A[0] = Math_Round((sp60 = arg0->unk_14.x - sp54) + temp_fs2);
    arg0->unk_4A[1] = Math_Round((temp_fs1 = arg0->unk_14.y - sp50) + temp_fs3);
    arg0->unk_4A[2] = Math_Round((temp_fs0 = arg0->unk_14.z - sp4C) + temp_fs4);

    arg0->unk_3E[0] = Math_Round(sp60 - temp_fs2);
    arg0->unk_3E[1] = Math_Round(temp_fs1 - temp_fs3);
    arg0->unk_3E[2] = Math_Round(temp_fs0 - temp_fs4);
}

void func_i2_800B4BD0(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    f32 sp64;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp58;
    f32 sp54;
    f32 temp_fs0;
    f32 temp_fs3;
    f32 temp_fs4;
    f32 temp_fs5;

    sp64 = radiusLeft / gSinTable[0x4C1];
    temp_fs1 = gSinTable[0xD00] * sp64;
    temp_fs2 = gSinTable[0x900] * sp64;

    arg0->unk_44[0] =
        Math_Round(arg5->x = (sp58 = arg0->unk_14.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    arg0->unk_44[1] =
        Math_Round(arg5->y = (sp54 = arg0->unk_14.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    arg0->unk_44[2] = Math_Round(arg5->z = (temp_fs0 = arg0->unk_14.z + (temp_fs2 * basis->y.z)) +
                                           (temp_fs5 = basis->z.z * temp_fs1));

    arg0->unk_32[0] = Math_Round(arg4->x = sp58 - temp_fs3);
    arg0->unk_32[1] = Math_Round(arg4->y = sp54 - temp_fs4);
    arg0->unk_32[2] = Math_Round(arg4->z = temp_fs0 - temp_fs5);

    temp_fs1 = gSinTable[0xE80] * sp64;
    temp_fs2 = gSinTable[0xA80] * sp64;

    arg0->unk_4A[0] =
        Math_Round((sp58 = arg0->unk_14.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    arg0->unk_4A[1] =
        Math_Round((sp54 = arg0->unk_14.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    arg0->unk_4A[2] =
        Math_Round((temp_fs0 = arg0->unk_14.z + (temp_fs2 * basis->y.z)) + (temp_fs5 = basis->z.z * temp_fs1));

    arg0->unk_38[0] = Math_Round(sp58 - temp_fs3);
    arg0->unk_38[1] = Math_Round(sp54 - temp_fs4);
    arg0->unk_38[2] = Math_Round(temp_fs0 - temp_fs5);

    arg0->unk_26[0] = Math_Round(arg7->x = arg0->unk_14.x - (sp58 = (sp64 * basis->y.x)));
    arg0->unk_26[1] = Math_Round(arg7->y = arg0->unk_14.y - (sp54 = (sp64 * basis->y.y)));
    arg0->unk_26[2] = Math_Round(arg7->z = arg0->unk_14.z - (temp_fs0 = (sp64 * basis->y.z)));

    arg6->x = arg0->unk_14.x + sp58;
    arg6->y = arg0->unk_14.y + sp54;
    arg6->z = arg0->unk_14.z + temp_fs0;

    sp64 *= 1.2f;
    temp_fs1 = gSinTable[0xE80] * sp64;
    temp_fs2 = gSinTable[0xA80] * sp64;

    arg0->unk_3E[0] =
        Math_Round((sp58 = arg0->unk_14.x + (temp_fs2 * basis->y.x)) + (temp_fs3 = basis->z.x * temp_fs1));
    arg0->unk_3E[1] =
        Math_Round((sp54 = arg0->unk_14.y + (temp_fs2 * basis->y.y)) + (temp_fs4 = basis->z.y * temp_fs1));
    arg0->unk_3E[2] =
        Math_Round((temp_fs0 = arg0->unk_14.z + (temp_fs2 * basis->y.z)) + (temp_fs5 = basis->z.z * temp_fs1));

    arg0->unk_2C[0] = Math_Round(sp58 - temp_fs3);
    arg0->unk_2C[1] = Math_Round(sp54 - temp_fs4);
    arg0->unk_2C[2] = Math_Round(temp_fs0 - temp_fs5);

    arg0->unk_20[0] = Math_Round((arg8->x = arg0->unk_14.x) - (sp64 * basis->y.x));
    arg0->unk_20[1] = Math_Round((arg8->y = arg0->unk_14.y) - (sp64 * basis->y.y));
    arg0->unk_20[2] = Math_Round((arg8->z = arg0->unk_14.z) - (sp64 * basis->y.z));
}

void func_i2_800B4FE0(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    f32 temp_fs4;
    f32 temp_fs5;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 temp_fs3;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;

    temp_fs4 = radiusLeft + 11.5f;
    temp_fs5 = radiusRight + 11.5f;

    temp_fs1 = (temp_fs4 - temp_fs5) / 2.0f;

    arg0->unk_20[0] = Math_Round(arg8->x = arg0->unk_14.x + (temp_fs1 * basis->z.x));
    arg0->unk_20[1] = Math_Round(arg8->y = arg0->unk_14.y + (temp_fs1 * basis->z.y));
    arg0->unk_20[2] = Math_Round(arg8->z = arg0->unk_14.z + (temp_fs1 * basis->z.z));

    arg0->unk_26[0] = Math_Round(arg6->x = (temp_fs2 = basis->y.x * 185.0f) + arg8->x);
    arg0->unk_26[1] = Math_Round(arg6->y = (temp_fs3 = basis->y.y * 185.0f) + arg8->y);
    arg0->unk_26[2] = Math_Round(arg6->z = (sp68 = basis->y.z * 185.0f) + arg8->z);

    arg7->x = arg8->x - temp_fs2;
    arg7->y = arg8->y - temp_fs3;
    arg7->z = arg8->z - sp68;
    temp_fs1 = (temp_fs4 + temp_fs5) / 2.0f;

    arg0->unk_2C[0] = Math_Round(arg4->x = (sp64 = basis->z.x * temp_fs1) + arg8->x);
    arg0->unk_2C[1] = Math_Round(arg4->y = (sp60 = basis->z.y * temp_fs1) + arg8->y);
    arg0->unk_2C[2] = Math_Round(arg4->z = (sp5C = basis->z.z * temp_fs1) + arg8->z);

    arg0->unk_3E[0] = Math_Round(arg5->x = arg8->x - sp64);
    arg0->unk_3E[1] = Math_Round(arg5->y = arg8->y - sp60);
    arg0->unk_3E[2] = Math_Round(arg5->z = arg8->z - sp5C);

    arg0->unk_32[0] = Math_Round((temp_fs2 = basis->y.x * 85.0f) + arg4->x);
    arg0->unk_32[1] = Math_Round((temp_fs3 = basis->y.y * 85.0f) + arg4->y);
    arg0->unk_32[2] = Math_Round((sp68 = basis->y.z * 85.0f) + arg4->z);

    arg0->unk_44[0] = Math_Round(arg5->x + temp_fs2);
    arg0->unk_44[1] = Math_Round(arg5->y + temp_fs3);
    arg0->unk_44[2] = Math_Round(arg5->z + sp68);

    temp_fs1 *= 0.625f;

    arg0->unk_38[0] = Math_Round((temp_fs2 = arg8->x + (160.0f * basis->y.x)) + (sp64 = basis->z.x * temp_fs1));
    arg0->unk_38[1] = Math_Round((temp_fs3 = arg8->y + (160.0f * basis->y.y)) + (sp60 = basis->z.y * temp_fs1));
    arg0->unk_38[2] = Math_Round((sp68 = arg8->z + (160.0f * basis->y.z)) + (sp5C = basis->z.z * temp_fs1));

    arg0->unk_4A[0] = Math_Round(temp_fs2 - sp64);
    arg0->unk_4A[1] = Math_Round(temp_fs3 - sp60);
    arg0->unk_4A[2] = Math_Round(sp68 - sp5C);
}

void func_i2_800B53D4(unk_36ED0* arg0, f32 radiusLeft, f32 radiusRight, Mtx3F* basis, Vec3f* arg4, Vec3f* arg5,
                      Vec3f* arg6, Vec3f* arg7, Vec3f* arg8) {
    func_i2_800B4338(arg0, radiusLeft - 15.410001f, radiusRight - 15.410001f, basis, arg4, arg5, arg6, arg7, arg8,
                     10.0f, 0.0f, -10.0f, 40.0f, 40.0f);
}

void func_i2_800B5468(s16* arg0, s16* arg1, f32 arg2, s16* arg3) {
    arg3[0] = (s16) Math_Round((arg1[0] - arg0[0]) * arg2) + arg0[0];
    arg3[1] = (s16) Math_Round((arg1[1] - arg0[1]) * arg2) + arg0[1];
    arg3[2] = (s16) Math_Round((arg1[2] - arg0[2]) * arg2) + arg0[2];
}

void func_i2_800B5548(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {
    func_i2_800B5468(arg0->unk_26, arg1->unk_20, arg2, arg1->unk_26);
    func_i2_800B5468(arg0->unk_20, arg1->unk_20, arg2, arg1->unk_20);
    func_i2_800B5468(arg0->unk_32, arg1->unk_32, arg2, arg1->unk_32);
    func_i2_800B5468(arg0->unk_44, arg1->unk_44, arg2, arg1->unk_44);
    func_i2_800B5468(arg0->unk_38, arg1->unk_2C, arg2, arg1->unk_38);
    func_i2_800B5468(arg0->unk_2C, arg1->unk_2C, arg2, arg1->unk_2C);
    func_i2_800B5468(arg0->unk_4A, arg1->unk_3E, arg2, arg1->unk_4A);
    func_i2_800B5468(arg0->unk_3E, arg1->unk_3E, arg2, arg1->unk_3E);
}

void func_i2_800B562C(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {

    if (arg2 == 0.0f) {
        arg1->unk_20[0] = arg0->unk_20[0];
        arg1->unk_20[1] = arg0->unk_20[1];
        arg1->unk_20[2] = arg0->unk_20[2];
        arg1->unk_26[0] = arg0->unk_26[0];
        arg1->unk_26[1] = arg0->unk_26[1];
        arg1->unk_26[2] = arg0->unk_26[2];
        arg1->unk_2C[0] = arg0->unk_2C[0];
        arg1->unk_2C[1] = arg0->unk_2C[1];
        arg1->unk_2C[2] = arg0->unk_2C[2];
        arg1->unk_32[0] = arg0->unk_32[0];
        arg1->unk_32[1] = arg0->unk_32[1];
        arg1->unk_32[2] = arg0->unk_32[2];
        arg1->unk_38[0] = arg0->unk_38[0];
        arg1->unk_38[1] = arg0->unk_38[1];
        arg1->unk_38[2] = arg0->unk_38[2];
        arg1->unk_3E[0] = arg0->unk_3E[0];
        arg1->unk_3E[1] = arg0->unk_3E[1];
        arg1->unk_3E[2] = arg0->unk_3E[2];
        arg1->unk_44[0] = arg0->unk_44[0];
        arg1->unk_44[1] = arg0->unk_44[1];
        arg1->unk_44[2] = arg0->unk_44[2];
        arg1->unk_4A[0] = arg0->unk_4A[0];
        arg1->unk_4A[1] = arg0->unk_4A[1];
        arg1->unk_4A[2] = arg0->unk_4A[2];
    } else {
        func_i2_800B5468(arg0->unk_26, arg1->unk_20, arg2, arg1->unk_20);
        func_i2_800B5468(arg0->unk_26, arg1->unk_26, arg2, arg1->unk_26);
        func_i2_800B5468(arg0->unk_26, arg1->unk_2C, arg2, arg1->unk_2C);
        func_i2_800B5468(arg0->unk_26, arg1->unk_32, arg2, arg1->unk_32);
        func_i2_800B5468(arg0->unk_26, arg1->unk_38, arg2, arg1->unk_38);
        func_i2_800B5468(arg0->unk_26, arg1->unk_3E, arg2, arg1->unk_3E);
        func_i2_800B5468(arg0->unk_26, arg1->unk_44, arg2, arg1->unk_44);
        func_i2_800B5468(arg0->unk_26, arg1->unk_4A, arg2, arg1->unk_4A);
    }
}

void func_i2_800B57E0(unk_36ED0* arg0, unk_36ED0* arg1, f32 arg2) {
    func_i2_800B5468(arg0->unk_20, arg1->unk_20, arg2, arg1->unk_20);
    func_i2_800B5468(arg0->unk_26, arg1->unk_26, arg2, arg1->unk_26);
    func_i2_800B5468(arg0->unk_2C, arg1->unk_2C, arg2, arg1->unk_2C);
    func_i2_800B5468(arg0->unk_32, arg1->unk_32, arg2, arg1->unk_32);
    func_i2_800B5468(arg0->unk_38, arg1->unk_38, arg2, arg1->unk_38);
    func_i2_800B5468(arg0->unk_3E, arg1->unk_3E, arg2, arg1->unk_3E);
    func_i2_800B5468(arg0->unk_44, arg1->unk_44, arg2, arg1->unk_44);
    func_i2_800B5468(arg0->unk_4A, arg1->unk_4A, arg2, arg1->unk_4A);
}

f32 Course_SegmentGetJoinLengths(CourseSegment* segment) {
    f32 temp_fv1;
    f32 joinLength;
    f32 length;
    Vec3f sp58;

    segment->joinScale = -1.0f;
    joinLength = gTrackJoinUpperLength[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)];

    switch (segment->trackSegmentInfo & TRACK_JOIN_MASK) {
        case TRACK_JOIN_PREVIOUS:
        case TRACK_JOIN_NEXT:
            if (segment->length <= (joinLength + 100.0f)) {
                joinLength = segment->length * 0.5f;
            }
            break;
        case TRACK_JOIN_BOTH:
            if (segment->length <= ((2.0f * joinLength) + 100.0f)) {
                joinLength = segment->length * 0.3f;
            }
            break;
    }

    if (segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
        segment->previousJoinEndTValue = 0.0f;
        length = 0.0f;
        do {
            temp_fv1 = 50.0f / Course_SplineGetTangent(segment, segment->previousJoinEndTValue, &sp58);
            segment->previousJoinEndTValue += temp_fv1;

            if (segment->previousJoinEndTValue >= 1.0f) {
                joinLength = length;
                segment->previousJoinEndTValue -= temp_fv1;
                break;
            }
            length += 50.0f;
        } while (length < joinLength);
        segment->joinScale = length / segment->length;
    } else {
        segment->previousJoinEndTValue = -99.0f;
    }

    if (segment->trackSegmentInfo & TRACK_JOIN_NEXT) {
        segment->nextJoinStartTValue = 1.0f;

        length = 0.0f;
        do {
            temp_fv1 = 50.0f / Course_SplineGetTangent(segment, segment->nextJoinStartTValue, &sp58);
            segment->nextJoinStartTValue -= temp_fv1;
            if (segment->nextJoinStartTValue <= 0.0f) {
                joinLength = length;
                segment->nextJoinStartTValue += temp_fv1;
                break;
            }
            length += 50.0f;
        } while (length < joinLength);
        segment->joinScale = length / segment->length;
    } else if (!(segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)) &&
               (segment->next->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
        segment->nextJoinStartTValue = 1.0f - (100.0f / Course_SplineGetTangent(segment, 1.0f, &sp58));
    } else {
        segment->nextJoinStartTValue = 99.0f;
    }
    if (segment->nextJoinStartTValue <= segment->previousJoinEndTValue) {
        segment->previousJoinEndTValue = 0.49f;
        segment->nextJoinStartTValue = 0.51f;
        segment->joinScale = 0.49f;
        joinLength = segment->length * 0.49f;
    }
    return joinLength;
}

bool func_i2_800B5B9C(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2) {
    Vec3f vec;
    f32 temp_fa1;

    vec.x = arg2->x - arg0->x;
    vec.y = arg2->y - arg0->y;
    vec.z = arg2->z - arg0->z;
    temp_fa1 = DOT_XYZ(arg1, &vec);
    if (SQ_SUM(&vec) - SQ(temp_fa1) < D_i2_800D6C98) {
        return false;
    }
    return true;
}

f32 func_i2_800B5C2C(Vec3f* arg0, Vec3f* arg1) {
    f32 diff;
    f32 sum;

    diff = arg0->x - arg1->x;
    sum = SQ(diff);
    diff = arg0->y - arg1->y;
    sum += SQ(diff);
    diff = arg0->z - arg1->z;
    sum += SQ(diff);

    return sqrtf(sum);
}

s32 func_i2_800B5C80(s32 trackSegmentInfo, f32 arg1) {

    if ((trackSegmentInfo & TRACK_TYPE_MASK) != TRACK_TYPE_NONE) {
        return (s32) (D_i2_800C18D8[TRACK_SHAPE_INDEX(trackSegmentInfo & TRACK_SHAPE_MASK)]
                                   [trackSegmentInfo & TRACK_TYPE_MASK]
                                       .unk_04 *
                      arg1) -
               0x8000;
    }
    return -0x8000;
}

extern unk_36ED0 D_802BE5C0[];
extern Mtx3F D_80033840[];

#ifdef NON_EQUIVALENT
s32 func_i2_800B5CD8(CourseInfo* courseInfo) {
    CourseSegment* sp294;
    f32 sp284;
    f32 sp280;
    f32 sp27C;
    f32 sp278;
    f32 sp274;
    Vec3f sp254;
    Vec3f sp248;
    Vec3f sp23C;
    Vec3f sp230;
    Vec3f sp224;
    Vec3f sp218;
    Vec3f sp20C;
    Vec3f sp200;
    Vec3f sp1F4;
    Vec3f sp1E8;
    Vec3f sp1DC;
    Vec3f sp1D0;
    Vec3f sp1C4;
    Vec3f sp1B8;
    Vec3f sp1AC;
    Vec3f sp1A0;
    Vec3f sp194;
    Vec3f sp188;
    Vec3f sp17C;
    Vec3f sp170;
    unk_36ED0 sp110;
    Mtx3F segmentBasis;
    f32 spE8;
    f32 spE4;
    f32 spE0;
    f32 spDC;
    s32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    f32 spB8;
    s32 spB4;
    Mtx3F* spB0;
    Vec3f* sp8C;
    Vec3f sp80;
    f32 temp_fv0_5;
    f32 temp_fv0_8;
    f32 var_fs0;
    f32 t;
    f32 var_fs3;
    s32 temp_s5;
    unk_36ED0* var_s0;
    unk_36ED0* var_s3;
    unk_36ED0* var_t2;
    CourseSegment* segment;
    CourseSegment* var_s4;
    unk_800CF528* temp_a3;
    s32 var_v1;

    segment = courseInfo->courseSegments;
    spB4 = 0;

    while (segment->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
        segment = segment->next;
    }

    sp294 = segment;
    var_s4 = segment->next;
    D_802BE5C0[0].trackSegmentInfo = (segment->trackSegmentInfo & ~TRACK_JOIN_MASK) | TRACK_FLAG_80000000;
    if (segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
        D_802BE5C0[0].trackSegmentInfo |= (TRACK_JOIN_PREVIOUS | TRACK_UNK1_800);
    } else if (segment->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {
        D_802BE5C0[0].trackSegmentInfo |= TRACK_JOIN_NEXT;
    }
    spB8 = Course_SegmentGetJoinLengths(segment);
    sp280 = Course_SplineGetBasis(segment, 0.0f, &segmentBasis, 0.0f);
    if (gInCourseEditor) {
        D_80033840[0] = segmentBasis;
        spB0 = &D_80033840[1];
    }
    Course_SplineGetPosition(segment, 0.0f, &D_802BE5C0[0].unk_14);
    if (D_802BE5C0[0].trackSegmentInfo & TRACK_JOIN_BOTH) {
        func_i2_800B4728(&D_802BE5C0[0], segment->radiusLeft, segment->radiusRight, &segmentBasis, &sp254, &sp248,
                         &sp23C, &sp230, &sp224);
    } else {
        D_i2_800C1918[TRACK_SHAPE_INDEX((u32) (segment->trackSegmentInfo & TRACK_SHAPE_MASK))](
            &D_802BE5C0[0], segment->radiusLeft, segment->radiusRight, &segmentBasis, &sp254, &sp248, &sp23C, &sp230,
            &sp224);
    }
    sp17C.x = segmentBasis.x.x;
    sp17C.y = segmentBasis.x.y;
    sp17C.z = segmentBasis.x.z;
    sp1AC = sp1DC = sp254;
    var_s3 = D_802BE5C0;
    spDC = 0.0f;
    spE0 = 0.0f;
    var_fs3 = 0.0f;
    t = 0.0f;

    var_s0 = &D_802BE5C0[1];
    sp1A0 = sp1D0 = sp248;
    sp194 = sp1C4 = sp23C;
    sp188 = sp1B8 = sp230;

    D_802BE5C0[0].unk_5C = D_802BE5C0[0].unk_5E = D_802BE5C0[0].unk_58 = D_802BE5C0[0].unk_5A = -0x8000;

    D_802BE5C0[0].segmentIndex = (s32) (segment - courseInfo->courseSegments);
    segment->unk_3C = D_802BE5C0;
    D_802BE5C0[0].segmentTValue = 0.0f;
    spE8 = 0.0f;
    spE4 = 0.0f;
    D_800D65C8 = 1;

    while (true) {
        temp_s5 = segment->trackSegmentInfo;
        sp274 = D_i2_800D6C90 / sp280;
        if (D_i2_800D65D4 != 0) {
            var_fs3 += D_i2_800D6C90;
        }

        if (((segment->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_AIR) ||
            (((t == segment->nextJoinStartTValue)) &&
             !(segment->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK)))) {
            segment->unk_40 = var_s0;
            segment = var_s4;
            t = 0.0f;
            if (var_s4 != sp294) {
                var_s4 = var_s4->next;
                segment->unk_3C = var_s0;
                spB8 = Course_SegmentGetJoinLengths(segment);
            } else {
                break;
            }
        } else if (t < segment->previousJoinEndTValue) {
            t += sp274;
            if (segment->previousJoinEndTValue <= t) {
                t = segment->previousJoinEndTValue;
            }
        } else if ((t < segment->nextJoinStartTValue) && (segment->nextJoinStartTValue < 1.0f)) {
            t += sp274;
            if (segment->nextJoinStartTValue <= t) {
                t = segment->nextJoinStartTValue;
            }
        } else {
            t += sp274;
            if (t >= 1.0f) {
                if (var_s4->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
                    if (t < 2.0f) {
                        t -= 1.0f;
                        t *= (sp280 / Course_SplineGetTangent(var_s4, 0.0f, &segmentBasis.x));
                    } else {
                        t = 0.0f;
                    }
                } else {
                    t = 0.0f;
                }
                segment->unk_40 = var_s0;
                segment = var_s4;
                if (var_s4 != sp294) {
                    var_s4 = var_s4->next;
                    if (t == 0.0f) {
                        segment->unk_3C = var_s0;
                    } else {
                        segment->unk_3C = var_s0 - 1;
                    }
                    spB8 = Course_SegmentGetJoinLengths(segment);

                } else {
                    break;
                }
            }
        }

        sp8C = &var_s0->unk_14;
        sp284 = Course_SplineGetLengthInfo(segment, t, &sp274);
        sp27C = ((var_s4->radiusLeft - segment->radiusLeft) * sp284) + segment->radiusLeft;
        sp278 = ((var_s4->radiusRight - segment->radiusRight) * sp284) + segment->radiusRight;
        sp280 = Course_SplineGetBasis(segment, t, &segmentBasis, sp284);
        Course_SplineGetPosition(segment, t, sp8C);
        D_i2_800C1918[TRACK_SHAPE_INDEX((u32) segment->trackSegmentInfo & TRACK_SHAPE_MASK)](
            var_s0, sp27C, sp278, &segmentBasis, &sp218, &sp20C, &sp200, &sp1F4, &sp1E8);
        spE8 += func_i2_800B5C2C(&sp218, &sp1DC);
        spE4 += func_i2_800B5C2C(&sp20C, &sp1D0);
        spE0 += func_i2_800B5C2C(&sp200, &sp1C4);
        spDC += func_i2_800B5C2C(&sp1F4, &sp1B8);
        sp1DC = sp218;
        sp1D0 = sp20C;
        sp1C4 = sp200;
        sp1B8 = sp1F4;
        if ((D_i2_800D65D4 == 0) || (D_i2_800D6C94 <= var_fs3) || (func_i2_800B5B9C(&sp254, &sp17C, &sp218) != 0) ||
            (func_i2_800B5B9C(&sp248, &sp17C, &sp20C) != 0) || (func_i2_800B5B9C(&sp23C, &sp17C, &sp200) != 0) ||
            (func_i2_800B5B9C(&sp230, &sp17C, &sp1F4) != 0) || (t == 0.0f) || (t == segment->previousJoinEndTValue) ||
            (t == segment->nextJoinStartTValue)) {
            sp17C.x = sp1E8.x - sp224.x;
            sp17C.y = sp1E8.y - sp224.y;
            sp17C.z = sp1E8.z - sp224.z;
            sp170.x = sp218.x - sp254.x;
            sp170.y = sp218.y - sp254.y;
            sp170.z = sp218.z - sp254.z;
            if ((sp170.x * sp17C.x) + (sp170.y * sp17C.y) + (sp170.z * sp17C.z) > 0.0f) {
                var_fs0 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));
                sp80.x = sp20C.x - sp248.x;
                sp80.y = sp20C.y - sp248.y;
                sp80.z = sp20C.z - sp248.z;
                if ((sp80.x * sp17C.x) + (sp80.y * sp17C.y) + (sp80.z * sp17C.z) > 0.0f) {
                    temp_fv0_5 = sqrtf(SQ(sp80.x) + SQ(sp80.y) + SQ(sp80.z));
                    if (var_fs0 < temp_fv0_5) {
                        sp274 = var_fs0 / temp_fv0_5;
                    } else {
                        sp274 = temp_fv0_5 / var_fs0;
                    }

                    if (sp274 > 0.044f) {
                        sp170.x = sp200.x - sp23C.x;
                        sp170.y = sp200.y - sp23C.y;
                        sp170.z = sp200.z - sp23C.z;
                        if ((sp170.x * sp17C.x) + (sp170.y * sp17C.y) + (sp170.z * sp17C.z) > 0.0f) {
                            var_fs0 = sqrtf(SQ(sp170.x) + SQ(sp170.y) + SQ(sp170.z));
                            sp80.x = sp1F4.x - sp230.x;
                            sp80.y = sp1F4.y - sp230.y;
                            sp80.z = sp1F4.z - sp230.z;
                            if ((sp80.x * sp17C.x) + (sp80.y * sp17C.y) + (sp80.z * sp17C.z) > 0.0f) {
                                temp_fv0_5 = sqrtf(SQ(sp80.x) + SQ(sp80.y) + SQ(sp80.z));
                                if (var_fs0 < temp_fv0_5) {
                                    sp274 = var_fs0 / temp_fv0_5;
                                } else {
                                    sp274 = temp_fv0_5 / var_fs0;
                                }
                                if (sp274 > 0.034f) {
                                    goto skip;
                                }
                            }
                        }
                    }
                }
            }

            if (!(spB4 & 0x10000)) {
                spB4 |= 0x10000;
                if (t < 0.5f) {
                    spB4 |= var_s0 - D_802BE5C0;
                } else {
                    spB4 |= (var_s0 - D_802BE5C0) + 1;
                }
            }

        skip:

            sp274 = SQ(sp17C.x) + SQ(sp17C.y) + SQ(sp17C.z);

            if (sp274 != 0.0f) {
                sp274 = 1.0f / sqrtf(sp274);
                sp17C.x *= sp274;
                sp17C.y *= sp274;
                sp17C.z *= sp274;
            } else {
                sp17C.x = 0.0f;
                sp17C.y = 0.0f;
                sp17C.z = 0.0f;
            }

            sp224 = sp1E8;
            sp254 = sp218;
            sp248 = sp20C;
            sp23C = sp200;
            sp230 = sp1F4;

            spD4 = func_i2_800B5C80(temp_s5, spE8);
            spD0 = func_i2_800B5C80(temp_s5, spE4);
            spCC = func_i2_800B5C80(temp_s5, spE0);
            spC8 = func_i2_800B5C80(temp_s5, spDC);
            if ((spD4 < 0x8000) && (spD0 < 0x8000) && (spCC < 0x8000) && (spC8 < 0x8000)) {
                var_s0->unk_54 = spD4;
                var_s0->unk_56 = spD0;
                var_s0->unk_50 = spCC;
                var_s0->unk_52 = spC8;
            } else {
                var_s3->trackSegmentInfo = (var_s3->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_FLAG_80000000;
                temp_a3 =
                    &D_i2_800C18D8[TRACK_SHAPE_INDEX((u32) temp_s5 & TRACK_SHAPE_MASK)][temp_s5 & TRACK_TYPE_MASK];

                temp_fv0_8 = temp_a3->unk_04;
                var_s3->unk_5C = (var_s3->unk_54 & temp_a3->unk_14) - 0x8000;
                var_s0->unk_54 = (spD4 - var_s3->unk_54) + var_s3->unk_5C;
                spE8 = (f32) (var_s0->unk_54 + 0x8000) / temp_fv0_8;

                var_s3->unk_5E = (var_s3->unk_56 & temp_a3->unk_14) - 0x8000;
                var_s0->unk_56 = (spD0 - var_s3->unk_56) + var_s3->unk_5E;
                spE4 = (f32) (var_s0->unk_56 + 0x8000) / temp_fv0_8;

                var_s3->unk_58 = (var_s3->unk_50 & temp_a3->unk_14) - 0x8000;
                var_s0->unk_50 = (spCC - var_s3->unk_50) + var_s3->unk_58;
                spE0 = (f32) (var_s0->unk_50 + 0x8000) / temp_fv0_8;

                var_s3->unk_5A = (var_s3->unk_52 & temp_a3->unk_14) - 0x8000;
                var_s0->unk_52 = (spC8 - var_s3->unk_52) + var_s3->unk_5A;
                spDC = (f32) (var_s0->unk_52 + 0x8000) / temp_fv0_8;
            }
            var_s0->trackSegmentInfo =
                segment->trackSegmentInfo & ~(TRACK_JOIN_MASK | TRACK_UNK1_MASK | TRACK_UNK2_MASK);
            var_s0->segmentTValue = t;
            var_s0->segmentIndex = segment - courseInfo->courseSegments;

            if ((segment->previousJoinEndTValue <= t) && (t <= segment->nextJoinStartTValue)) {
                if (t == segment->previousJoinEndTValue) {

                    if ((var_s0 - 1)->trackSegmentInfo & TRACK_FLAG_20000000) {
                        (var_s0 - 1)->trackSegmentInfo =
                            ((var_s0 - 1)->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_UNK2_2000;
                    } else {
                        (var_s0 - 1)->trackSegmentInfo |= TRACK_UNK2_2000;
                    }
                } else if (t == segment->nextJoinStartTValue) {
                    var_s0->trackSegmentInfo |= TRACK_UNK2_4000;
                    if (!(var_s0->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK))) {
                        var_s0->trackSegmentInfo = (var_s0->trackSegmentInfo & ~TRACK_TYPE_MASK) | 1;
                    }
                }
            } else {
                if (t < segment->previousJoinEndTValue) {
                    var_s0->trackSegmentInfo |= TRACK_JOIN_PREVIOUS;
                    if (spB8 != 0.0f) {
                        sp274 = (segment->length * sp284) / spB8;
                    } else {
                        sp274 = 0.0f;
                    }
                } else {
                    var_s0->trackSegmentInfo |= TRACK_JOIN_NEXT;
                    sp274 = (segment->length - (segment->length * sp284)) / spB8;
                }
                sp110.unk_14 = *sp8C;

                func_i2_800B4728(&sp110, sp27C, sp278, &segmentBasis, &sp218, &sp20C, &sp200, &sp1F4, &sp1E8);
                D_i2_800C1938[TRACK_SHAPE_INDEX((u32) (segment->trackSegmentInfo & TRACK_SHAPE_MASK))](&sp110, var_s0,
                                                                                                       sp274);
            }

            if ((t != 0.0f) && (t != segment->previousJoinEndTValue) && (t != segment->nextJoinStartTValue) &&
                (var_fs3 < D_i2_800D6C94)) {
                var_s0->trackSegmentInfo |= TRACK_FLAG_CONTINUOUS;
                var_fs3 = 0.0f;
            } else {
                var_s0->trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;

                var_fs3 = 0.0f;
                if (t == 0.0f) {
                    spDC = 0.0f;
                    spE0 = 0.0f;
                    if (segment->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {

                        var_s0->trackSegmentInfo |= TRACK_JOIN_NEXT;
                        if (((var_s0 - 1)->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) {
                            (var_s0 - 1)->trackSegmentInfo =
                                (s32) (((var_s0 - 1)->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_UNK1_1000);
                        } else {
                            (var_s0 - 1)->trackSegmentInfo |= TRACK_UNK1_1000;
                        }
                    }

                    if (var_s0->trackSegmentInfo & TRACK_JOIN_PREVIOUS) {
                        var_s0->trackSegmentInfo |= TRACK_UNK1_800;
                    }
                    var_s0->trackSegmentInfo |= TRACK_FLAG_80000000;
                    var_s0->unk_5C = var_s0->unk_5E = var_s0->unk_58 = var_s0->unk_5A = -0x8000;
                    spE8 = 0.0f;
                    spE4 = 0.0f;
                }
            }

            if (D_800D65C8 < 0x300) {
                var_s3 = var_s0;
                var_s0++;
                if (gInCourseEditor) {
                    *spB0++ = segmentBasis;
                }
                D_800D65C8++;
            } else {
                spB4 |= 0x20000;
            }
        }
    }

    spE8 += func_i2_800B5C2C(&sp1AC, &sp1DC);
    spE4 += func_i2_800B5C2C(&sp1A0, &sp1D0);
    spE0 += func_i2_800B5C2C(&sp194, &sp1C4);
    spDC += func_i2_800B5C2C(&sp188, &sp1B8);
    spD4 = func_i2_800B5C80(temp_s5, spE8);
    spD0 = func_i2_800B5C80(temp_s5, spE4);
    spCC = func_i2_800B5C80(temp_s5, spE0);
    spC8 = func_i2_800B5C80(temp_s5, spDC);
    if ((spD4 < 0x8000) && (spD0 < 0x8000) && (spCC < 0x8000) && (spC8 < 0x8000)) {
        D_802BE5C0[0].unk_54 = spD4;
        D_802BE5C0[0].unk_56 = spD0;
        D_802BE5C0[0].unk_50 = spCC;
        D_802BE5C0[0].unk_52 = spC8;
    } else {
        var_s3->trackSegmentInfo = (var_s3->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_FLAG_80000000;
        temp_a3 = &D_i2_800C18D8[TRACK_SHAPE_INDEX((u32) temp_s5 & TRACK_SHAPE_MASK)][temp_s5 & TRACK_TYPE_MASK];
        var_v1 = temp_a3->unk_14;

        var_s3->unk_5C = (var_s3->unk_54 & var_v1) - 0x8000;
        D_802BE5C0[0].unk_54 = (spD4 - var_s3->unk_54) + var_s3->unk_5C;

        var_s3->unk_5E = (var_s3->unk_56 & var_v1) - 0x8000;
        D_802BE5C0[0].unk_56 = (spD0 - var_s3->unk_56) + var_s3->unk_5E;

        var_s3->unk_58 = (var_s3->unk_50 & var_v1) - 0x8000;
        D_802BE5C0[0].unk_50 = (spCC - var_s3->unk_50) + var_s3->unk_58;

        var_s3->unk_5A = (var_s3->unk_52 & var_v1) - 0x8000;
        D_802BE5C0[0].unk_52 = (spC8 - var_s3->unk_52) + var_s3->unk_5A;
    }
    if (var_s4->prev->trackSegmentInfo & TRACK_JOIN_NEXT) {
        if ((var_s3->trackSegmentInfo & TRACK_SHAPE_MASK) == TRACK_SHAPE_CYLINDER) {
            var_s3->trackSegmentInfo = (var_s3->trackSegmentInfo & ~TRACK_FLAG_CONTINUOUS) | TRACK_UNK1_1000;
        } else {
            var_s3->trackSegmentInfo |= TRACK_UNK1_1000;
        }
    }

    D_i2_800D65CC = &D_802BE5C0[D_800D65C8];
    D_802BE5C0[D_800D65C8] = D_802BE5C0[0];
    return spB4;
}
#else
s32 func_i2_800B5CD8(CourseInfo* courseInfo);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/112650/func_i2_800B5CD8.s")
#endif

Vtx* func_i2_800B7060(Vtx* arg0, Vec3f* arg1, Mtx3F* arg2) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;
    f32 sp40;
    f32 sp3C;
    f32 sp38;

    temp_fs0 = arg2->y.x * 115.47f;
    temp_fs1 = arg2->y.y * 115.47f;
    temp_fs2 = arg2->y.z * 115.47f;
    sp40 = arg2->z.x * 200.0f;
    sp3C = arg2->z.y * 200.0f;
    sp38 = arg2->z.z * 200.0f;

    arg0->v.ob[0] = Math_Round(arg1->x + temp_fs0 + temp_fs0);
    arg0->v.ob[1] = Math_Round(arg1->y + temp_fs1 + temp_fs1);
    arg0->v.ob[2] = Math_Round(arg1->z + temp_fs2 + temp_fs2);
    arg0++;
    arg0->v.ob[0] = Math_Round((temp_fs0 = arg1->x - temp_fs0) + sp40);
    arg0->v.ob[1] = Math_Round((temp_fs1 = arg1->y - temp_fs1) + sp3C);
    arg0->v.ob[2] = Math_Round((temp_fs2 = arg1->z - temp_fs2) + sp38);
    arg0++;
    arg0->v.ob[0] = Math_Round(temp_fs0 - sp40);
    arg0->v.ob[1] = Math_Round(temp_fs1 - sp3C);
    arg0->v.ob[2] = Math_Round(temp_fs2 - sp38);
    arg0++;

    return arg0;
}

s32 func_i2_800B71B0(CourseInfo* arg0, Vtx* arg1) {
    CourseSegment* var_s0;
    f32 spD0;
    f32 var_fs1;
    f32 var_fs2;
    Vec3f spBC;
    Vec3f spB0;
    Vec3f spA4;
    Mtx3F sp80;
    s32 var_s2;
    Vtx* var_s3;

    D_i2_800D6C98 = 3000.0f;
    var_s0 = arg0->courseSegments;
    var_fs1 = 0.0f;
    var_fs2 = Course_SplineGetBasis(var_s0, 0.0f, &sp80, 0.0f);
    Course_SplineGetPosition(var_s0, 0.0f, &spA4);
    var_s3 = func_i2_800B7060(arg1, &spA4, &sp80);
    spBC.x = sp80.x.x;
    spBC.y = sp80.x.y;
    spBC.z = sp80.x.z;
    spB0 = spA4;
    var_s2 = 3;

    while (true) {
        var_fs1 += 300.0f / var_fs2;
        if (var_fs1 >= 1.0f) {
            var_s0 = var_s0->next;
            var_fs1 -= 1.0f;
            if (var_s0 != arg0->courseSegments) {
                var_fs1 *= (var_fs2 / Course_SplineGetTangent(var_s0, 0.0f, &spA4));
            } else {
                break;
            }
        }

        var_fs2 = Course_SplineGetBasis(var_s0, var_fs1, &sp80, Course_SplineGetLengthInfo(var_s0, var_fs1, &spD0));
        Course_SplineGetPosition(var_s0, var_fs1, &spA4);
        if (func_i2_800B5B9C(&spB0, &spBC, &spA4) != 0) {

            spBC.x = spA4.x - spB0.x;
            spBC.y = spA4.y - spB0.y;
            spBC.z = spA4.z - spB0.z;

            spD0 = SQ_SUM(&spBC);
            spD0 = 1.0f / sqrtf(spD0);
            spB0 = spA4;

            var_s2 += 3;

            spBC.x *= spD0;
            spBC.y *= spD0;
            spBC.z *= spD0;

            if (var_s2 < 0x900) {
                var_s3 = func_i2_800B7060(var_s3, &spA4, &sp80);
                continue;
            }
            return 0;
        }
    }

    var_s2 += 3;

    if (var_s2 < 0x900) {
        var_s3[0] = arg1[0];
        var_s3[1] = arg1[1];
        var_s3[2] = arg1[2];
        return var_s2;
    } else {
        return 0;
    }
}

extern s32 gRandSeed1;
extern s32 gRandMask1;
extern s32 gRandSeed2;
extern s32 gRandMask2;
extern s32 gGameMode;
extern s8 gTitleDemoState;
extern s32 gCourseIndex;

void Course_GenerateRandomCourse(void) {
    s32 var_s4;
    s32 temp_s3;
    s32 var_s6;
    s32 sp108;
    s32 sp104;
    CourseSegment* var_s0;
    CourseSegment* var_s1;
    CourseSegment* var_s2;
    ControlPoint* var_s1_2;
    ControlPoint* var_s0_4;
    ControlPoint* var_s3;
    f32 spE8;
    s32 temp_a0;
    s32 temp_s2;
    f32 var_fs4;
    f32 temp_fs5;
    Vec3f spCC;
    f32 temp_fs3;
    f32 temp_fs2;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_ft5;
    s32* spB4;
    ControlPoint* spB0;
    f32 var_fs0;
    f32 var_fs1;

    // Restore random generation seeding if track is re-done
    if ((gGameMode == GAMEMODE_GP_RACE) && (gTitleDemoState == TITLE_DEMO_INACTIVE) &&
        (gCourseIndex == gLastRandomCourseIndex)) {
        Math_Rand1Init(sRandomCourseInitSeed1, sRandomCourseInitMask1);
        Math_Rand2Init(sRandomCourseInitSeed2, sRandomCourseInitMask2);
    }
    gLastRandomCourseIndex = gCourseIndex;
    sRandomCourseInitSeed1 = gRandSeed1;
    sRandomCourseInitMask1 = gRandMask1;
    sRandomCourseInitSeed2 = gRandSeed2;
    sRandomCourseInitMask2 = gRandMask2;
    do {
    loop_start:
        do {
            if ((Math_Rand1() & 0x1FFFF) < 0x38E3) {
                if ((Math_Rand2() & 0x1FFFF) < 0x7FFF) {
                    sp108 = 3;
                } else if ((Math_Rand2() & 0x1FFFF) < 0xFFFF) {
                    sp108 = 2;
                } else {
                    sp108 = 1;
                }
            } else {
                sp108 = 0;
            }

            switch (sp108) {
                case 0:
                case 3:
                    D_i2_800C1520 = 1000.0f;
                    D_i2_800C1524 = 10000.0f;
                    D_i2_800C1528 = D_i2_800C19A8[Math_Rand1() & 3];
                    var_s4 = 9;
                    break;
                default:
                    D_i2_800C1520 = 6000.0f;
                    D_i2_800C1524 = 2500.0f;
                    D_i2_800C1528 = 2500.0f;
                    var_s4 = 6;
                    break;
            }

            gCurrentCourseInfo->segmentCount = ((Math_Rand2() & 0x1FFFF) % 5) + var_s4;
            var_s4 = (gCurrentCourseInfo->segmentCount * 3) + 1;
            var_s0 = var_s4 + gCurrentCourseInfo->courseSegments;
            var_s1 = gCurrentCourseInfo->courseSegments;
            do {
                var_s0->segmentIndex = var_s4;
                var_s0->prev = var_s0 - 1;
                var_s0->next = var_s1;
                var_s1 = var_s0;
                var_s0--;
                var_s4--;
            } while (var_s4 >= 0);

            var_fs4 = D_i2_800C1524 / 131071.0f;
            spE8 = 4096.0f / gCurrentCourseInfo->segmentCount;
            temp_fs5 = D_i2_800C1528 / 131071.0f;

            gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount * 3) + 2;

            do {
                gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount - 2) / 3;

                gCurrentCourseInfo->courseSegments[0].prev =
                    &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                gCurrentCourseInfo->courseSegments[0].prev->next = &gCurrentCourseInfo->courseSegments[0];
                temp_fs2 = 1.0f / (131071.0f * 5.0f);

                do {
                    var_fs1 = 0.0f;
                    var_s0 = gCurrentCourseInfo->courseSegments[0].prev;

                    do {

                        var_fs0 = ((Math_Rand2() & 0x1FFFF) * var_fs4) + D_i2_800C1520;

                        temp_a0 = ((((Math_Rand1() & 0x1FFFF) * temp_fs2) + var_fs1) * spE8);
                        var_s0->pos.x = COS(temp_a0) * var_fs0;
                        var_s0->pos.z = SIN(temp_a0) * var_fs0;
                        var_s0->pos.y = (f32) ((Math_Rand2() & 0x1FFFF) * temp_fs5);

                        var_s0--;
                        var_fs1 += 1.0f;
                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                } while (Course_SplineCalculateTensions(gCurrentCourseInfo) != 0);

                var_s1_2 = COURSE_CONTEXT()->courseData.controlPoint;
                var_s0 = gCurrentCourseInfo->courseSegments;

                do {
                    Course_SplineGetPosition(var_s0, 0.333333f, &spCC);
                    var_s1_2->pos = spCC;
                    var_s1_2++;
                    Course_SplineGetPosition(var_s0, 0.666667f, &spCC);
                    var_s1_2->pos = spCC;
                    var_s0 = var_s0->next;
                    var_s1_2++;
                    var_s1_2->pos = var_s0->pos;
                    var_s1_2++;
                } while (var_s0 != gCurrentCourseInfo->courseSegments);

                var_s1_2 -= 3;
                var_fs1 = 0.0f;
                var_s0_4 = var_s1_2 + 1;

                do {
                    temp_fs2 = var_s0_4->pos.x - var_s1_2->pos.x;
                    temp_ft5 = var_s0_4->pos.y - var_s1_2->pos.y;
                    temp_fs3 = var_s0_4->pos.z - var_s1_2->pos.z;
                    temp_fv0 = SQ(temp_fs2) + SQ(temp_ft5) + SQ(temp_fs3);
                    if (var_fs1 < temp_fv0) {
                        var_fs1 = temp_fv0;
                        spB0 = var_s1_2;
                    }
                    var_s1_2 -= 3;
                    var_s0_4 -= 3;
                } while (var_s1_2 >= COURSE_CONTEXT()->courseData.controlPoint);

                var_s0_4 = spB0 + 1;
                spCC.x = (spB0->pos.x + var_s0_4->pos.x) * 0.5f;
                spCC.y = (spB0->pos.y + var_s0_4->pos.y) * 0.5f;
                spCC.z = (spB0->pos.z + var_s0_4->pos.z) * 0.5f;
                temp_fv0 = sqrtf(var_fs1);
                temp_fv1 = 1587.5f / temp_fv0;
                temp_fs2 = (var_s0_4->pos.x - spB0->pos.x) * temp_fv1;
                temp_ft5 = (var_s0_4->pos.y - spB0->pos.y) * temp_fv1;
                temp_fs3 = (var_s0_4->pos.z - spB0->pos.z) * temp_fv1;

                if (temp_fv0 < 5000.0f) {
                    var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount * 3 - 1];
                    temp_fv1 = 3.1496062f - (temp_fv0 / 1587.5f);

                    do {
                        if ((((var_s1_2->pos.x - spCC.x) * temp_fs2) + ((var_s1_2->pos.y - spCC.y) * temp_ft5) +
                             ((var_s1_2->pos.z - spCC.z) * temp_fs3)) < 0.0f) {
                            var_s1_2->pos.x -= (temp_fv1 * temp_fs2);
                            var_s1_2->pos.y -= (temp_fv1 * temp_ft5);
                            var_s1_2->pos.z -= (temp_fv1 * temp_fs3);
                        }
                        var_s1_2--;
                    } while (var_s1_2 >= COURSE_CONTEXT()->courseData.controlPoint);
                    spCC.x -= (temp_fv1 * temp_fs2) * 0.5f;
                    spCC.y -= (temp_fv1 * temp_ft5) * 0.5f;
                    spCC.z -= (temp_fv1 * temp_fs3) * 0.5f;
                }
                gCurrentCourseInfo->segmentCount = (gCurrentCourseInfo->segmentCount * 3) + 2;

                gCurrentCourseInfo->courseSegments[0].prev->next = gCurrentCourseInfo->courseSegments[0].prev + 1;
                gCurrentCourseInfo->courseSegments[0].prev =
                    &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                gCurrentCourseInfo->courseSegments[0].prev->next = &gCurrentCourseInfo->courseSegments[0];

                var_s1_2 = spB0;
                var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

                do {
                    var_s0->pos = var_s1_2->pos;
                    var_s0--;
                    if (--var_s1_2 < COURSE_CONTEXT()->courseData.controlPoint) {
                        var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3];
                    }
                } while (var_s1_2 != spB0);

                var_s0->pos.x = spCC.x + temp_fs2;
                var_s0->pos.y = spCC.y + temp_ft5;
                var_s0->pos.z = spCC.z + temp_fs3;
                var_s0--;
                var_s0->pos.x = spCC.x - temp_fs2;
                var_s0->pos.y = spCC.y - temp_ft5;
                var_s0->pos.z = spCC.z - temp_fs3;
            } while (Course_SplineCalculateTensions(gCurrentCourseInfo) != 0);

            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                var_s1 = var_s0->next;
                if ((SQ(var_s0->pos.x - var_s1->pos.x) + SQ(var_s0->pos.y - var_s1->pos.y) +
                     SQ(var_s0->pos.z - var_s1->pos.z)) < 8500.0f) {
                    break;
                }
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            if (var_s0 >= gCurrentCourseInfo->courseSegments) {
                goto loop_start;
            }

            spE8 = 0.0f;
            var_fs4 = 5000.0f;
            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                if (var_s0->pos.y < var_fs4) {
                    var_fs4 = var_s0->pos.y;
                }
                if (spE8 < var_s0->pos.y) {
                    spE8 = var_s0->pos.y;
                }
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];

            do {
                var_s0->pos.y += (0 - var_fs4) + ((spE8 - var_fs4) * 0.5f);
                var_s0--;
            } while (var_s0 >= gCurrentCourseInfo->courseSegments);

            sp104 = Math_Rand1() % 2;
            switch (sp108) {
                case 0:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s1 = var_s0->next;
                        var_s2 = var_s0->prev;

                        temp_fs2 = var_s1->pos.x - var_s0->pos.x;
                        temp_fs3 = var_s1->pos.z - var_s0->pos.z;
                        spCC.x = var_s0->pos.x - var_s2->pos.x;
                        spCC.z = var_s0->pos.z - var_s2->pos.z;

                        var_fs0 = ((spCC.x * temp_fs3) - (spCC.z * temp_fs2)) /
                                  sqrtf((SQ(spCC.x) + SQ(spCC.z)) * (SQ(temp_fs2) + SQ(temp_fs3)));

                        if (((spCC.x * temp_fs2) + (spCC.z * temp_fs3)) < 0.0f) {
                            if (var_fs0 < 0.0f) {
                                var_fs0 = -1.0f;
                            } else {
                                var_fs0 = 1.0f;
                            }
                        }
                        var_fs1 = ((SQ(var_fs0) * 100.0f) + 500.0f) - 200.0f;
                        if (sp104 != 0) {
                            var_s2 = var_s1;
                        }
                        var_s0--;

                        var_s2->radiusLeft = ((0.5f - (SQ(var_fs0) * var_fs0 * 0.5f)) * var_fs1) + 100.0f;
                        var_s2->radiusRight = (((SQ(var_fs0) * var_fs0 * 0.5f) + 0.5f) * var_fs1) + 100.0f;

                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);

                    gCurrentCourseInfo->courseSegments[0].radiusLeft =
                        gCurrentCourseInfo->courseSegments[0].radiusRight =
                            gCurrentCourseInfo->courseSegments[1].radiusLeft =
                                gCurrentCourseInfo->courseSegments[1].radiusRight =
                                    (gCurrentCourseInfo->courseSegments[0].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[0].radiusRight +
                                     gCurrentCourseInfo->courseSegments[1].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[1].radiusRight) /
                                    4.0f;
                    break;
                case 3:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s1 = var_s0->next;
                        var_s2 = var_s0->prev;

                        temp_fs2 = var_s1->pos.x - var_s0->pos.x;
                        temp_fs3 = var_s1->pos.z - var_s0->pos.z;
                        spCC.x = var_s0->pos.x - var_s2->pos.x;
                        spCC.z = var_s0->pos.z - var_s2->pos.z;
                        var_fs0 = ((spCC.x * temp_fs3) - (spCC.z * temp_fs2)) /
                                  sqrtf((SQ(spCC.x) + SQ(spCC.z)) * (SQ(temp_fs2) + SQ(temp_fs3)));

                        if (((spCC.x * temp_fs2) + (spCC.z * temp_fs3)) < 0.0f) {
                            if (var_fs0 < 0.0f) {
                                var_fs0 = -1.0f;
                            } else {
                                var_fs0 = 1.0f;
                            }
                        }
                        if (sp104 != 0) {
                            var_s2 = var_s1;
                        }
                        var_s0--;
                        var_s2->radiusLeft = var_s2->radiusRight = (SQ(var_fs0) * 50.0f) + 200.0f;

                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                    gCurrentCourseInfo->courseSegments[0].radiusLeft =
                        gCurrentCourseInfo->courseSegments[0].radiusRight =
                            gCurrentCourseInfo->courseSegments[1].radiusLeft =
                                gCurrentCourseInfo->courseSegments[1].radiusRight =
                                    (gCurrentCourseInfo->courseSegments[0].radiusLeft +
                                     gCurrentCourseInfo->courseSegments[1].radiusLeft) *
                                    0.5f;
                    break;
                default:
                    var_s0 = &gCurrentCourseInfo->courseSegments[gCurrentCourseInfo->segmentCount - 1];
                    do {
                        var_s0->radiusRight = 250.0f;
                        var_s0->radiusLeft = 250.0f;
                        var_s0--;
                    } while (var_s0 >= gCurrentCourseInfo->courseSegments);
                    break;
            }

            COURSE_CONTEXT()->courseData.creatorId = CREATOR_NINTENDO;
            COURSE_CONTEXT()->courseData.controlPointCount = gCurrentCourseInfo->segmentCount;
            COURSE_CONTEXT()->courseData.venue = (Math_Rand2() & 0x1FFFF) % 10;
            COURSE_CONTEXT()->courseData.skybox = (Math_Rand1() & 0x1FFFF) % 8;
            COURSE_CONTEXT()->courseData.flag = 1;

            switch (Math_Rand1() & 3) {
                case 0: // ROAD GROUP 1
                    spB4 = D_i2_800C19B8;
                    break;
                case 1: // ROAD GROUP 2
                    spB4 = D_i2_800C19C4;
                    break;
                case 2: // ROAD GROUP 3
                    spB4 = D_i2_800C19D0;
                    break;
                case 3: // ROAD GROUP 4
                    spB4 = D_i2_800C19DC;
                    break;
            }
            var_s6 = 0;
            var_s4 = COURSE_CONTEXT()->courseData.controlPointCount - 1;
            if (sp104 != 0) {
                var_s0 = gCurrentCourseInfo->courseSegments[0].prev;
            } else {
                var_s0 = gCurrentCourseInfo->courseSegments[1].next;
            }

            do {
                var_s3 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4];
                var_s3->pos = var_s0->pos;
                var_s3->radiusLeft = var_s0->radiusLeft;
                var_s3->radiusRight = var_s0->radiusRight;
                var_s3->trackSegmentInfo = spB4[var_s6];
                var_s6++;
                if (var_s6 >= 3) {
                    var_s6 = 0;
                }

                COURSE_CONTEXT()->courseData.bankAngle[var_s4] = 0;
                COURSE_CONTEXT()->courseData.pit[var_s4] = PIT_NONE;
                COURSE_CONTEXT()->courseData.dash[var_s4] = DASH_NONE;
                COURSE_CONTEXT()->courseData.dirt[var_s4] = DIRT_NONE;
                COURSE_CONTEXT()->courseData.ice[var_s4] = ICE_NONE;
                COURSE_CONTEXT()->courseData.jump[var_s4] = JUMP_NONE;
                COURSE_CONTEXT()->courseData.landmine[var_s4] = LANDMINE_NONE;
                COURSE_CONTEXT()->courseData.gate[var_s4] = GATE_NONE;
                COURSE_CONTEXT()->courseData.building[var_s4] = BUILDING_NONE;
                COURSE_CONTEXT()->courseData.sign[var_s4] = SIGN_NONE;

                if (sp104 != 0) {
                    var_s0 = var_s0->prev;
                } else {
                    var_s0 = var_s0->next;
                }
                var_s4--;
            } while (var_s4 >= 0);

            // Override for start line
            COURSE_CONTEXT()->courseData.controlPoint[0].trackSegmentInfo =
                TRACK_FLAG_JOINABLE | TRACK_FLAG_8000000 | TRACK_SHAPE_ROAD | ROAD_START_LINE;
            COURSE_CONTEXT()->courseData.gate[1] = GATE_START;
            COURSE_CONTEXT()->courseData.controlPoint[1].trackSegmentInfo =
                COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 1].trackSegmentInfo =
                    spB4[1];
            COURSE_CONTEXT()->courseData.controlPoint[3].trackSegmentInfo =
                COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3].trackSegmentInfo =
                    spB4[0];

            if (((sp108 == 0) || (sp108 == 3)) && ((Math_Rand1() & 0x1FFFF) >= 0x8000)) {
                temp_a0 = Math_Rand2() & 3;
                var_fs1 = D_i2_800C1998[temp_a0];
                if ((temp_a0 < 2) && ((Math_Rand1() & 0x1FFFF) >= 0x10000)) {
                    var_s6 = 0;
                } else {
                    var_s6 = 1;
                }

                var_s4 = gCurrentCourseInfo->segmentCount - 4;

                do {
                    var_s3 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4];
                    var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4 + 1];
                    spB0 = &COURSE_CONTEXT()->courseData.controlPoint[var_s4 - 1];
                    spCC.x = var_s1_2->pos.x - var_s3->pos.x;
                    spCC.z = var_s1_2->pos.z - var_s3->pos.z;

                    temp_fv0 = sqrtf(SQ(spCC.x) + SQ(spCC.z));
                    spCC.x /= temp_fv0;
                    spCC.z /= temp_fv0;

                    temp_fs2 = var_s3->pos.x - spB0->pos.x;
                    temp_fs3 = var_s3->pos.z - spB0->pos.z;
                    temp_fv0 = sqrtf(SQ(temp_fs2) + SQ(temp_fs3));

                    temp_fs2 /= temp_fv0;
                    temp_fs3 /= temp_fv0;

                    var_fs0 = (spCC.x * temp_fs2) + (spCC.z * temp_fs3);
                    if (var_fs0 < 0.0f) {
                        var_fs0 = 0.0f;
                    }
                    if ((temp_fs2 * spCC.z) < (spCC.x * temp_fs3)) {
                        if (var_s6 != 0) {
                            COURSE_CONTEXT()->courseData.bankAngle[var_s4] =
                                360 - (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                        } else {
                            COURSE_CONTEXT()->courseData.bankAngle[var_s4] = (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                        }
                    } else if (var_s6 != 0) {
                        COURSE_CONTEXT()->courseData.bankAngle[var_s4] = (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                    } else {
                        COURSE_CONTEXT()->courseData.bankAngle[var_s4] = 360 - (s32) ((1.0f - SQ(var_fs0)) * var_fs1);
                    }
                    var_s4--;
                } while (var_s4 > 1);
            }

            if (sp108 == 0) {
                if (1) {}
                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 4];
                do {
                    var_s0_4 = var_s1_2 + 1;
                    if (((Math_Rand1() & 0x1FFFF) < 0x1112) && ((var_s1_2 - 1)->trackSegmentInfo & 0x10000000)) {
                        if ((var_s0_4 + 1)->trackSegmentInfo & 0x10000000) {
                            var_s1_2->trackSegmentInfo = var_s0_4->trackSegmentInfo =
                                D_i2_800C19E8[(Math_Rand1() & 0x1FFFF) % 3];
                        }
                    }
                    var_s1_2 -= 3;
                } while (var_s1_2 >= &COURSE_CONTEXT()->courseData.controlPoint[4]);

                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 3];
                do {
                    var_s0_4 = var_s1_2 + 1;
                    if (((Math_Rand1() & 0x1FFFF) < 0x1112) && ((var_s1_2 - 1)->trackSegmentInfo & 0x10000000)) {
                        if ((var_s0_4 + 1)->trackSegmentInfo & 0x10000000) {
                            var_s1_2->trackSegmentInfo = var_s0_4->trackSegmentInfo =
                                D_i2_800C19F4[(Math_Rand1() & 0x1FFFF) % 3];
                        }
                    }
                    var_s1_2 -= 3;
                } while (var_s1_2 >= &COURSE_CONTEXT()->courseData.controlPoint[2]);

                if ((Math_Rand2() & 0x1FFFF) < 0xFFFF) {
                    var_s1_2 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand1() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 1)) + 1];
                    var_s0_4 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 1)) + 1];
                    if ((var_s1_2 < var_s0_4) && ((var_s1_2 - 1)->trackSegmentInfo & 0x10000000) &&
                        ((var_s0_4 + 1)->trackSegmentInfo & 0x10000000)) {
                        var_s6 = Math_Rand1() & 3;
                        temp_s2 = D_i2_800C1A00[var_s6];
                        temp_a0 = D_i2_800C1A00[(((Math_Rand2() & 0x1FFFF) % 3) + var_s6 + 1) & 3];
                        spB0 = var_s1_2;
                        do {
                            spB0->trackSegmentInfo = temp_s2;
                            spB0++;
                        } while (spB0 <= var_s0_4);

                        var_s4 = (s32) (var_s0_4 - var_s1_2) / 3;
                        while (var_s4 != 0) {
                            var_s4--;
                            (var_s1_2 + var_s4)->trackSegmentInfo = (var_s0_4 - var_s4)->trackSegmentInfo = temp_a0;
                        }
                    }
                }

                // Ensure there are pit zones
                COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 3] =
                    COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 4] = PIT_BOTH;
            } else {
                if (sp108 == 1) { // PIPE
                    spB4 = D_i2_800C1A20;
                } else if (sp108 == 2) { // CYLINDER
                    spB4 = D_i2_800C1A30;
                } else { // HALF PIPE
                    spB4 = D_i2_800C1A10;
                }
                var_s6 = Math_Rand2() & 3;
                temp_s3 = ((Math_Rand1() & 0x1FFFF) % 3) + 1;
                var_s1_2 = &COURSE_CONTEXT()->courseData.controlPoint[2];
                var_s0_4 = &COURSE_CONTEXT()->courseData.controlPoint[gCurrentCourseInfo->segmentCount - 5];

                var_s4 = 4;
                do {
                    if (var_s0_4 >= var_s1_2) {
                        var_fs1 = (((Math_Rand1() & 0x1FFFF) / 131071.0f) * 200.0f) + 100.0f;

                        if (sp108 == 2) {
                            var_fs1 += 30.0f;
                        }
                        temp_s2 = spB4[var_s6];
                        if (sp108 == 3) {
                            do {
                                var_s1_2->trackSegmentInfo = temp_s2;
                                var_s1_2++;
                            } while (var_s1_2 < var_s0_4);
                        } else {
                            do {
                                var_s1_2->trackSegmentInfo = temp_s2;
                                var_s1_2->radiusLeft = var_s1_2->radiusRight = var_fs1;
                                var_s1_2++;
                            } while (var_s1_2 < var_s0_4);
                        }
                        var_s1_2->trackSegmentInfo = temp_s2;
                    }
                    var_s6 = (var_s6 + temp_s3) & 3;
                    var_s1_2 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand1() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2];
                    var_s0_4 =
                        &COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2];
                    var_s4--;
                } while (var_s4 > 0);
                // Ensure there are pit zones
                COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 1] =
                    COURSE_CONTEXT()->courseData.pit[gCurrentCourseInfo->segmentCount - 2] = PIT_BOTH;
            }
            temp_s3 = Math_Rand1() & 7;
            while (temp_s3 != 0) {
                do {
                    var_s4 = ((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 6)) + 2;
                    if (COURSE_CONTEXT()->courseData.controlPoint[var_s4].trackSegmentInfo & 0x08000000) {
                        break;
                    }
                } while (COURSE_CONTEXT()
                             ->courseData
                             .controlPoint[((var_s4 + gCurrentCourseInfo->segmentCount) - 1) %
                                           gCurrentCourseInfo->segmentCount]
                             .trackSegmentInfo !=
                         COURSE_CONTEXT()
                             ->courseData.controlPoint[(var_s4 + 1) % gCurrentCourseInfo->segmentCount]
                             .trackSegmentInfo);

                COURSE_CONTEXT()->courseData.dash[var_s4] = (Math_Rand1() & 0x1FFFF) % 3;
                temp_s3--;
            }
            var_s6 = (Math_Rand1() & 0x1FFFF) % 3;

            temp_s3 = (Math_Rand2() & 7) - 1;
            while (temp_s3 >= 0) {
                var_s4 = ((Math_Rand2() & 0x1FFFF) % (gCurrentCourseInfo->segmentCount - 2)) + 2;
                temp_s2 = COURSE_CONTEXT()->courseData.controlPoint[var_s4].trackSegmentInfo & TRACK_SHAPE_MASK;
                if ((temp_s2 == TRACK_SHAPE_ROAD) || (temp_s2 == TRACK_SHAPE_BORDERLESS_ROAD)) {
                    temp_s2 = COURSE_CONTEXT()->courseData.controlPoint[var_s4 - 1].trackSegmentInfo & TRACK_SHAPE_MASK;
                    if ((temp_s2 == TRACK_SHAPE_ROAD) || (temp_s2 == TRACK_SHAPE_BORDERLESS_ROAD)) {
                        if ((Math_Rand2() & 0x1FFFF) < 0xAAAA) {
                            COURSE_CONTEXT()->courseData.sign[var_s4] = (Math_Rand1() & 1) + 3;
                        } else {
                            COURSE_CONTEXT()->courseData.sign[var_s4] = var_s6;
                        }
                    }
                }
                temp_s3--;
            }
            func_80702BC4(gCourseIndex);
            Course_SegmentLengthsInit(gCurrentCourseInfo);
        } while (Course_SegmentJoinsInit(gCurrentCourseInfo) != 0);
    } while (func_i2_800B5CD8(gCurrentCourseInfo) != 0);

    for (temp_s3 = 0; temp_s3 < 5; temp_s3++) {
        gCurrentCourseInfo->timeRecord[temp_s3] = 600000 - 1;
    }

    gCurrentCourseInfo->maxSpeed = 0.0f;
    gCurrentCourseInfo->bestTime = 600000 - 1;
    COURSE_CONTEXT()->courseData.bgm = (Math_Rand2() & 0x1FFFF) % 14;
}

extern CourseSegment D_802D0620[];

void func_i2_800B8FF4(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gCourseInfos); i++) {
        gCourseInfos[i].courseIndex = i;
        gCourseInfos[i].courseSegments = D_802D0620;
    }
}

extern GfxPool D_8024E260[];

void func_i2_800B904C(void) {
    Vtx* var_a0;
    Vtx* var_v1;
    s32 i;

    D_i2_800D6C08[0].unk_04 = D_80140F0;
    D_i2_800D6C08[0].unk_08 = D_8014180;
    D_i2_800D6C08[0].unk_0C = D_80140F0;
    D_i2_800D6C08[0].unk_10 = D_8014210;
    D_i2_800D6C08[0].unk_14 = D_80142C0;
    D_i2_800D6C08[0].unk_18 = D_8014308;
    D_i2_800D6C08[0].unk_1C = D_80143E0;
    D_i2_800D6C08[0].unk_20 = D_8014430;
    D_i2_800D6C08[0].unk_24 = D_8014520;
    D_i2_800D6C08[0].unk_28 = D_80145E0;
    D_i2_800D6C08[0].unk_2C = 0;
    D_i2_800D6C08[1].unk_04 = D_8014138;
    D_i2_800D6C08[1].unk_08 = D_80141C8;
    D_i2_800D6C08[1].unk_0C = D_8014138;
    D_i2_800D6C08[1].unk_10 = D_8014268;
    D_i2_800D6C08[1].unk_14 = D_8014350;
    D_i2_800D6C08[1].unk_18 = D_8014398;
    D_i2_800D6C08[1].unk_1C = D_8014480;
    D_i2_800D6C08[1].unk_20 = D_80144D0;
    D_i2_800D6C08[1].unk_24 = D_8014580;
    D_i2_800D6C08[1].unk_28 = D_8014640;
    D_i2_800D6C08[1].unk_2C = 8;

    var_a0 = &D_8024E260[0].unk_1A308[0xFFF];
    var_v1 = &D_8024E260[1].unk_1A308[0xFFF];
    // FAKE
    goto dummy;
dummy:;
    do {
        var_a0->v.cn[0] = var_a0->v.cn[1] = var_a0->v.cn[2] = var_v1->v.cn[0] = var_v1->v.cn[1] = var_v1->v.cn[2] = 0;
        var_a0->v.cn[3] = var_v1->v.cn[3] = 255;

        var_a0--;
        var_v1--;
    } while ((u32) var_v1 >= (u32) D_8024E260[1].unk_1A308);

    func_i2_800B8FF4();
}

void func_i2_800B91AC(s32 arg0) {
    D_i2_800D65D4 = arg0;
    switch (D_i2_800D65D4) {
        case 0:
            D_i2_800D6C90 = 300.0f;
            break;
        case 1:
            D_i2_800D6BFC = 2000.0f;
            D_i2_800D6C00 = 300.0f;
            D_i2_800D6C98 = 400.0f;
            D_i2_800D6C90 = 20.0f;
            D_i2_800D6C94 = 2000.0f;
            break;
        case 2:
            D_i2_800D6BFC = 1500.0f;
            D_i2_800D6C00 = 100.0f;
            D_i2_800D6C98 = 700.0f;
            D_i2_800D6C90 = 20.0f;
            D_i2_800D6C94 = 4000.0f;
            break;
    }
}

void func_i2_800B9290(void) {

    gCurrentCourseInfo = &gCourseInfos[gCourseIndex];
    Course_Load(gCourseIndex);
    func_80702FF4(COURSE_CONTEXT()->courseData.venue);
    func_i2_800B0D10(COURSE_CONTEXT()->courseData.venue);
    func_80702E0C(gCurrentCourseInfo);
    Course_SplineCalculateTensions(gCurrentCourseInfo);
    if (gCurrentCourseInfo->courseIndex >= COURSE_EDIT_1) {
        gCurrentCourseInfo->encodedCourseIndex = COURSE_EDIT_1;
    } else {
        gCurrentCourseInfo->encodedCourseIndex = gCurrentCourseInfo->courseIndex;
    }
    gCurrentCourseInfo->encodedCourseIndex |= Course_CalculateChecksum() << 5;
}

extern s32 gNumPlayers;

void Course_Init(void) {
    CourseSegment* segment;

    if (gCourseIndex >= ARRAY_COUNT(gCourseInfos)) {
        gCourseIndex = ARRAY_COUNT(gCourseInfos) - 1;
    }
    if (gNumPlayers >= 3) {
        func_i2_800B91AC(2);
    } else {
        func_i2_800B91AC(1);
    }
    if (!gInCourseEditor) {
        func_i2_800B9290();
    }
    Course_SegmentsInit();
    Course_SegmentLengthsInit(gCurrentCourseInfo);
    Course_GadgetsInit(gCourseIndex);
    Course_SegmentJoinsInit(gCurrentCourseInfo);
    Course_SegmentContinuousFlagInit(gCurrentCourseInfo);
    Course_SegmentFormsInit(gCurrentCourseInfo);
    func_i2_800B5CD8(gCurrentCourseInfo);
    D_i2_800C1534 = 900.0f;
    segment = gCurrentCourseInfo->courseSegments;
    do {

        if (D_i2_800C1534 < segment->radiusLeft) {
            D_i2_800C1534 = segment->radiusLeft;
        }

        if (D_i2_800C1534 < segment->radiusRight) {
            D_i2_800C1534 = segment->radiusRight;
        }
        segment = segment->next;
    } while (segment != gCurrentCourseInfo->courseSegments);
    D_i2_800C1534 += 100.0f;
    D_i2_800C1530 = D_i2_800C1534 + 4500.0f;
    D_i2_800D6BFC += D_i2_800C1534 - 1000.0f;
    D_i2_800D6C00 += D_i2_800C1534 - 1000.0f;
}

void func_800B94D8(void) {
}

void func_i2_800B94E0(unk_36ED0* arg0) {
    D_800D65D0[0].v.ob[0] = arg0->unk_20[0];
    D_800D65D0[0].v.ob[1] = arg0->unk_20[1];
    D_800D65D0[0].v.ob[2] = arg0->unk_20[2];
    D_800D65D0[1].v.ob[0] = arg0->unk_3E[0];
    D_800D65D0[1].v.ob[1] = arg0->unk_3E[1];
    D_800D65D0[1].v.ob[2] = arg0->unk_3E[2];
    D_800D65D0[2].v.ob[0] = arg0->unk_44[0];
    D_800D65D0[2].v.ob[1] = arg0->unk_44[1];
    D_800D65D0[2].v.ob[2] = arg0->unk_44[2];
    D_800D65D0[3].v.ob[0] = arg0->unk_4A[0];
    D_800D65D0[3].v.ob[1] = arg0->unk_4A[1];
    D_800D65D0[3].v.ob[2] = arg0->unk_4A[2];
    D_800D65D0[4].v.ob[0] = arg0->unk_26[0];
    D_800D65D0[4].v.ob[1] = arg0->unk_26[1];
    D_800D65D0[4].v.ob[2] = arg0->unk_26[2];
    D_800D65D0[5].v.ob[0] = arg0->unk_38[0];
    D_800D65D0[5].v.ob[1] = arg0->unk_38[1];
    D_800D65D0[5].v.ob[2] = arg0->unk_38[2];
    D_800D65D0[6].v.ob[0] = arg0->unk_32[0];
    D_800D65D0[6].v.ob[1] = arg0->unk_32[1];
    D_800D65D0[6].v.ob[2] = arg0->unk_32[2];
    D_800D65D0[7].v.ob[0] = arg0->unk_2C[0];
    D_800D65D0[7].v.ob[1] = arg0->unk_2C[1];
    D_800D65D0[7].v.ob[2] = arg0->unk_2C[2];
    D_800D65D0 += 8;
}

void func_i2_800B9618(unk_36ED0* arg0) {
    D_800D65D0[0].v.tc[0] = D_i2_800D6BE0[4];
    D_800D65D0[1].v.tc[0] = D_800D65D0[7].v.tc[0] = D_i2_800D6BE0[3];
    D_800D65D0[2].v.tc[0] = D_800D65D0[6].v.tc[0] = D_i2_800D6BE0[2];
    D_800D65D0[3].v.tc[0] = D_800D65D0[5].v.tc[0] = D_i2_800D6BE0[1];
    D_800D65D0[4].v.tc[0] = D_i2_800D6BE0[0];
    D_800D65D0[0].v.ob[0] = arg0->unk_20[0];
    D_800D65D0[0].v.ob[1] = arg0->unk_20[1];
    D_800D65D0[0].v.ob[2] = arg0->unk_20[2];
    D_800D65D0[1].v.ob[0] = arg0->unk_3E[0];
    D_800D65D0[1].v.ob[1] = arg0->unk_3E[1];
    D_800D65D0[1].v.ob[2] = arg0->unk_3E[2];
    D_800D65D0[2].v.ob[0] = arg0->unk_44[0];
    D_800D65D0[2].v.ob[1] = arg0->unk_44[1];
    D_800D65D0[2].v.ob[2] = arg0->unk_44[2];
    D_800D65D0[3].v.ob[0] = arg0->unk_4A[0];
    D_800D65D0[3].v.ob[1] = arg0->unk_4A[1];
    D_800D65D0[3].v.ob[2] = arg0->unk_4A[2];
    D_800D65D0[4].v.ob[0] = arg0->unk_26[0];
    D_800D65D0[4].v.ob[1] = arg0->unk_26[1];
    D_800D65D0[4].v.ob[2] = arg0->unk_26[2];
    D_800D65D0[5].v.ob[0] = arg0->unk_38[0];
    D_800D65D0[5].v.ob[1] = arg0->unk_38[1];
    D_800D65D0[5].v.ob[2] = arg0->unk_38[2];
    D_800D65D0[6].v.ob[0] = arg0->unk_32[0];
    D_800D65D0[6].v.ob[1] = arg0->unk_32[1];
    D_800D65D0[6].v.ob[2] = arg0->unk_32[2];
    D_800D65D0[7].v.ob[0] = arg0->unk_2C[0];
    D_800D65D0[7].v.ob[1] = arg0->unk_2C[1];
    D_800D65D0[7].v.ob[2] = arg0->unk_2C[2];
    D_800D65D0 += 8;
}

void func_i2_800B97AC(unk_36ED0* arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v1;

    if (arg1 != 0) {
        var_v1 = arg0->unk_5E;
        var_a1 = arg0->unk_5C;
    } else {
        var_v1 = arg0->unk_56;
        var_a1 = arg0->unk_54;
    }

    D_800D65D0[1].v.tc[1] = D_800D65D0[2].v.tc[1] = D_800D65D0[3].v.tc[1] = var_v1;
    D_800D65D0[5].v.tc[1] = D_800D65D0[6].v.tc[1] = D_800D65D0[7].v.tc[1] = var_a1;
    D_800D65D0[0].v.tc[1] = D_800D65D0[4].v.tc[1] = (var_v1 + var_a1) >> 1;
    func_i2_800B9618(arg0);
}

void func_i2_800B9830(unk_36ED0* arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;

    if (arg1 != 0) {
        var_a2 = arg0->unk_5E;
        var_a3 = arg0->unk_5C;
        var_t0 = arg0->unk_58;
        var_a0 = arg0->unk_5A;
    } else {
        var_a2 = arg0->unk_56;
        var_a3 = arg0->unk_54;
        var_t0 = arg0->unk_50;
        var_a0 = arg0->unk_52;
    }
    if (arg0->trackSegmentInfo & 0x600) {
        D_800D65D0[0].v.tc[1] = D_800D65D0[4].v.tc[1] = var_a0;
        D_800D65D0[1].v.tc[1] = D_800D65D0[3].v.tc[1] = (var_a0 + var_a2) >> 1;
        D_800D65D0[2].v.tc[1] = var_a2;
        D_800D65D0[6].v.tc[1] = var_a3;
        D_800D65D0[7].v.tc[1] = D_800D65D0[5].v.tc[1] = (var_a3 + var_a0) >> 1;
        D_800D65D0[0].v.tc[0] = D_i2_800D6BE0[4];
        D_800D65D0[1].v.tc[0] = D_800D65D0[7].v.tc[0] = D_i2_800D6BE0[3];
        D_800D65D0[2].v.tc[0] = D_800D65D0[6].v.tc[0] = D_i2_800D6BE0[2];
        D_800D65D0[3].v.tc[0] = D_800D65D0[5].v.tc[0] = D_i2_800D6BE0[3];
        D_800D65D0[4].v.tc[0] = D_i2_800D6BE0[4];
    } else {
        D_800D65D0[0].v.tc[1] = var_a0;
        D_800D65D0[1].v.tc[1] = (var_a0 + var_a2) >> 1;
        D_800D65D0[2].v.tc[1] = var_a2;
        D_800D65D0[3].v.tc[1] = (var_a2 + var_t0) >> 1;
        D_800D65D0[4].v.tc[1] = var_t0;
        D_800D65D0[5].v.tc[1] = (var_t0 + var_a3) >> 1;
        D_800D65D0[6].v.tc[1] = var_a3;
        D_800D65D0[7].v.tc[1] = (var_a3 + var_a0) >> 1;
        D_800D65D0[0].v.tc[0] = D_i2_800D6BE0[4];
        D_800D65D0[1].v.tc[0] = D_800D65D0[7].v.tc[0] = D_i2_800D6BE0[3];
        D_800D65D0[2].v.tc[0] = D_800D65D0[6].v.tc[0] = D_i2_800D6BE0[2];
        D_800D65D0[3].v.tc[0] = D_800D65D0[5].v.tc[0] = D_i2_800D6BE0[1];
        D_800D65D0[4].v.tc[0] = D_i2_800D6BE0[0];
    }
    func_i2_800B94E0(arg0);
}

void func_i2_800B9A10(unk_36ED0* arg0) {
    Gfx* gfx;

    D_800D65D0[0].v.ob[0] = ((arg0->unk_44[0] - arg0->unk_32[0]) >> 5) + arg0->unk_44[0];
    D_800D65D0[0].v.ob[1] = ((arg0->unk_44[1] - arg0->unk_32[1]) >> 5) + arg0->unk_44[1];
    D_800D65D0[0].v.ob[2] = ((arg0->unk_44[2] - arg0->unk_32[2]) >> 5) + arg0->unk_44[2];

    D_800D65D0[1].v.ob[0] = ((arg0->unk_4A[0] - arg0->unk_2C[0]) >> 5) + arg0->unk_4A[0];
    D_800D65D0[1].v.ob[1] = ((arg0->unk_4A[1] - arg0->unk_2C[1]) >> 5) + arg0->unk_4A[1];
    D_800D65D0[1].v.ob[2] = ((arg0->unk_4A[2] - arg0->unk_2C[2]) >> 5) + arg0->unk_4A[2];

    D_800D65D0[2].v.ob[0] = ((arg0->unk_26[0] - arg0->unk_20[0]) >> 5) + arg0->unk_26[0];
    D_800D65D0[2].v.ob[1] = ((arg0->unk_26[1] - arg0->unk_20[1]) >> 5) + arg0->unk_26[1];
    D_800D65D0[2].v.ob[2] = ((arg0->unk_26[2] - arg0->unk_20[2]) >> 5) + arg0->unk_26[2];

    D_800D65D0[3].v.ob[0] = ((arg0->unk_38[0] - arg0->unk_3E[0]) >> 5) + arg0->unk_38[0];
    D_800D65D0[3].v.ob[1] = ((arg0->unk_38[1] - arg0->unk_3E[1]) >> 5) + arg0->unk_38[1];
    D_800D65D0[3].v.ob[2] = ((arg0->unk_38[2] - arg0->unk_3E[2]) >> 5) + arg0->unk_38[2];

    D_800D65D0[4].v.ob[0] = ((arg0->unk_32[0] - arg0->unk_44[0]) >> 5) + arg0->unk_32[0];
    D_800D65D0[4].v.ob[1] = ((arg0->unk_32[1] - arg0->unk_44[1]) >> 5) + arg0->unk_32[1];
    D_800D65D0[4].v.ob[2] = ((arg0->unk_32[2] - arg0->unk_44[2]) >> 5) + arg0->unk_32[2];

    gSPVertex(D_i2_800D6C74 - 1, D_800D65D0, 5, 16);

    D_800D65D0 += 5;
}

void func_i2_800B9BEC(unk_36ED0* arg0, s32 arg1) {
    s16 var_a1;
    s16 var_a2;
    s16 var_a3;
    s16 var_v1;

    if (arg1 != 0) {
        var_v1 = arg0->unk_5E;
        var_a1 = arg0->unk_5C;
        var_a2 = arg0->unk_58;
        var_a3 = arg0->unk_5A;
    } else {
        var_v1 = arg0->unk_56;
        var_a1 = arg0->unk_54;
        var_a2 = arg0->unk_50;
        var_a3 = arg0->unk_52;
    }
    D_800D65D0[0].v.tc[1] = var_a3;
    D_800D65D0[1].v.tc[1] = (var_a3 + var_v1) >> 1;
    D_800D65D0[2].v.tc[1] = var_v1;
    D_800D65D0[3].v.tc[1] = (var_v1 + var_a2) >> 1;
    D_800D65D0[4].v.tc[1] = var_a2;
    D_800D65D0[5].v.tc[1] = (var_a2 + var_a1) >> 1;
    D_800D65D0[6].v.tc[1] = var_a1;
    D_800D65D0[7].v.tc[1] = (var_a1 + var_a3) >> 1;
    func_i2_800B9618(arg0);
}

void func_i2_800B9C98(unk_36ED0* arg0, s32 arg1) {
    s32 var_a3;
    s32 var_t0;
    s32 var_v1;

    if (arg1 != 0) {
        var_a3 = arg0->unk_5E;
        var_t0 = arg0->unk_5C;
        var_v1 = arg0->unk_5A;
    } else {
        var_a3 = arg0->unk_56;
        var_t0 = arg0->unk_54;
        var_v1 = arg0->unk_52;
    }

    D_800D65D0[1].v.tc[1] = var_a3;
    D_800D65D0[2].v.tc[1] = D_800D65D0[3].v.tc[1] = (var_a3 + var_v1) >> 1;
    D_800D65D0[0].v.tc[1] = var_v1;
    D_800D65D0[4].v.tc[1] = var_v1;
    D_800D65D0[5].v.tc[1] = D_800D65D0[6].v.tc[1] = (var_t0 + var_v1) >> 1;
    D_800D65D0[7].v.tc[1] = var_t0;
    func_i2_800B9618(arg0);
}

void func_i2_800B9D2C(void) {

    gSPVertex(D_i2_800D6C74++, D_800D65D0, 16, 0);
    gSPDisplayList(D_i2_800D6C74++, D_80140F0);

    func_i2_800B97AC(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C7C;
    func_i2_800B97AC(D_i2_800D6C80, 0);
    D_i2_800D6C08[1].unk_00 = D_i2_800D6C80;
}

void func_i2_800B9DD4(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C7C == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5E) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C7C->unk_5E));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5E));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], D_i2_800D6C7C->unk_5E));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5E) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], D_i2_800D6C7C->unk_5C));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5C));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C7C->unk_5C));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);

        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_04);

        func_i2_800B97AC(D_i2_800D6C80, 0);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C80;
    } else {
        D_i2_800D6C70 = 1;
        func_i2_800B9D2C();
    }
}

void func_i2_800BA1A0(void) {
    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C80 == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_56) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C80->unk_56));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_56));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], D_i2_800D6C80->unk_56));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_56) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], D_i2_800D6C80->unk_54));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_54));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C80->unk_54));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];
        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_04);
        func_i2_800B97AC(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C7C;
    } else {
        D_i2_800D6C70 = 0;
        func_i2_800B9D2C();
    }
}

void func_i2_800BA57C(void) {

    gSPVertex(D_i2_800D6C74++, D_800D65D0, 16, 0);
    if (D_i2_800D6C8C != 0) {
        if (D_i2_800D6BDC != D_i2_800D6C84) {
            gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
            gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
            D_i2_800D6BDC = D_i2_800D6C84;
        }

        switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK2_MASK) {
            case TRACK_UNK2_0:
                gSPDisplayList(D_i2_800D6C74++, D_80140F0);
                break;
            case TRACK_UNK2_2000:
                gSPDisplayList(D_i2_800D6C74++, D_80142C0);
                break;
            default:
                gSPDisplayList(D_i2_800D6C74++, D_8014308);
                if (1) {}
                break;
        }
    } else {
        if (D_i2_800D6BDC != D_i2_800D6C84) {
            gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
            gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
            D_i2_800D6BDC = D_i2_800D6C84;
        }

        gSPDisplayList(D_i2_800D6C74++, D_8014180);
        if (D_i2_800D6C88) {
            if (D_i2_800D6BDC != (D_i2_800D6C84 + 1)) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84 + 1, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84 + 1;
            }
            gSPDisplayList(D_i2_800D6C74++, D_80140F0);
        }
    }
    func_i2_800B9830(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C7C;
    func_i2_800B9830(D_i2_800D6C80, 0);
    D_i2_800D6C08[1].unk_00 = D_i2_800D6C80;
}

void func_i2_800BA850(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C7C == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000) {
            if (D_i2_800D6C7C->trackSegmentInfo & TRACK_JOIN_BOTH) {
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C7C->unk_5A));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5E) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5E));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5E) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C7C->unk_5A));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5C) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5C));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5C) >> 1));
            } else {
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C7C->unk_5A));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5E) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5E));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_5E + D_i2_800D6C7C->unk_58) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C7C->unk_58));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_58 + D_i2_800D6C7C->unk_5C) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5C));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5A) >> 1));
            }
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);

        if (D_i2_800D6C8C != 0) {
            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK2_MASK) {
                case TRACK_UNK2_0:
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_04);
                    break;
                case TRACK_UNK2_2000:
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_14);
                    break;
                default:
                    func_i2_800B9A10(D_i2_800D6C7C);
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_20);
                    gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_18);
                    break;
            }
        } else {
            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_08);

            if (D_i2_800D6C88) {
                if (D_i2_800D6BDC != (D_i2_800D6C84 + 1)) {
                    gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                    gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84 + 1, G_ON);
                    D_i2_800D6BDC = D_i2_800D6C84 + 1;
                }

                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_04);
            }
        }
        func_i2_800B9830(D_i2_800D6C80, 0);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C80;
    } else {
        D_i2_800D6C70 = 1;
        func_i2_800BA57C();
    }
}

void func_i2_800BB1A4(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C80 == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_80000000) {
            if (D_i2_800D6C80->trackSegmentInfo & TRACK_JOIN_BOTH) {
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C80->unk_52));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_56) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_56));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_56) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C80->unk_52));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_54) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_54));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_54) >> 1));
            } else {
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C80->unk_52));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_56) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_56));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_56 + D_i2_800D6C80->unk_50) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C80->unk_50));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_50 + D_i2_800D6C80->unk_54) >> 1));
                gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                                VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_54));
                gSPModifyVertex(
                    D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                    VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_52) >> 1));
            }
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];
        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);

        if (D_i2_800D6C8C != 0) {
            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK2_MASK) {
                case TRACK_UNK2_0:
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_04);
                    break;
                case TRACK_UNK2_2000:
                    func_i2_800B9A10(D_i2_800D6C80);
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_1C);
                    gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_14);
                    break;
                default:
                    gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_18);
                    if (1) {}
                    break;
            }
        } else {
            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }
            gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_08);

            if (D_i2_800D6C88) {
                if (D_i2_800D6BDC != (D_i2_800D6C84 + 1)) {
                    gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                    gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84 + 1, G_ON);
                    D_i2_800D6BDC = D_i2_800D6C84 + 1;
                }
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_04);
            }
        }
        func_i2_800B9830(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C7C;
    } else {
        D_i2_800D6C70 = 0;
        func_i2_800BA57C();
    }
}

void func_i2_800BBB00(void) {

    gSPVertex(D_i2_800D6C74++, D_800D65D0, 16, 0);

    switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK1_MASK) {
        case TRACK_UNK1_0:
            gSPDisplayList(D_i2_800D6C74++, D_80140F0);
            break;
        case TRACK_UNK1_800:
            gSPDisplayList(D_i2_800D6C74++, D_8014520);
            break;
        default:
            gSPDisplayList(D_i2_800D6C74++, D_80145E0);
            if (1) {}
            break;
    }
    func_i2_800B9BEC(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C7C;
    func_i2_800B9BEC(D_i2_800D6C80, 0);
    D_i2_800D6C08[1].unk_00 = D_i2_800D6C80;
}

void func_i2_800BBC14(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C7C == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C7C->unk_5A));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5A + D_i2_800D6C7C->unk_5E) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5E));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_5E + D_i2_800D6C7C->unk_58) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C7C->unk_58));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_58 + D_i2_800D6C7C->unk_5C) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C7C->unk_5C));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5A) >> 1));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);

        switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK1_MASK) {
            case TRACK_UNK1_0:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_04);
                break;
            case TRACK_UNK1_800:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_24);
                break;
            default:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_28);
                if (1) {}
                break;
        }

        func_i2_800B9BEC(D_i2_800D6C80, 0);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C80;
    } else {
        D_i2_800D6C70 = 1;
        func_i2_800BBB00();
    }
}

void func_i2_800BC070(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];
    if (D_i2_800D6C80 == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C80->unk_52));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_52 + D_i2_800D6C80->unk_56) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_56));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_56 + D_i2_800D6C80->unk_50) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C80->unk_50));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_50 + D_i2_800D6C80->unk_54) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], D_i2_800D6C80->unk_54));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_52) >> 1));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);

        switch (D_i2_800D6C7C->trackSegmentInfo & TRACK_UNK1_MASK) {
            case TRACK_UNK1_0:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_04);
                break;
            case TRACK_UNK1_800:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_24);
                break;
            default:
                gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_28);
                if (1) {}
                break;
        }

        func_i2_800B9BEC(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C7C;
    } else {
        D_i2_800D6C70 = 0;
        func_i2_800BBB00();
    }
}

void func_i2_800BC4D8(void) {

    gSPVertex(D_i2_800D6C74++, D_800D65D0, 16, 0);
    gSPDisplayList(D_i2_800D6C74++, D_80140F0);

    func_i2_800B9C98(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C7C;
    func_i2_800B9C98(D_i2_800D6C80, 0);
    D_i2_800D6C08[1].unk_00 = D_i2_800D6C80;
}

void func_i2_800BC580(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C7C == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C7C->unk_5A));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C7C->unk_5E));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], (D_i2_800D6C7C->unk_5E + D_i2_800D6C7C->unk_5A) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_5E + D_i2_800D6C7C->unk_5A) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C7C->unk_5A));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5A) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], (D_i2_800D6C7C->unk_5C + D_i2_800D6C7C->unk_5A) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C7C->unk_5C));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];
        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_0C);
        func_i2_800B9C98(D_i2_800D6C80, 0);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C80;
    } else {
        D_i2_800D6C70 = 1;
        func_i2_800BC4D8();
    }
}

void func_i2_800BC968(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];

    if (D_i2_800D6C80 == D_i2_800D6C68->unk_00) {
        if (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_80000000) {
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 0, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[4], D_i2_800D6C80->unk_52));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 1, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C80->unk_56));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 2, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], (D_i2_800D6C80->unk_56 + D_i2_800D6C80->unk_52) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 3, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_56 + D_i2_800D6C80->unk_52) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 4, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[0], D_i2_800D6C80->unk_52));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 5, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[1], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_52) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 6, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[2], (D_i2_800D6C80->unk_54 + D_i2_800D6C80->unk_52) >> 1));
            gSPModifyVertex(D_i2_800D6C74++, D_i2_800D6C68->unk_2C + 7, G_MWO_POINT_ST,
                            VERTEX_MODIFIED_ST(D_i2_800D6BE0[3], D_i2_800D6C80->unk_54));
        }

        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];
        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_0C);
        func_i2_800B9C98(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C7C;
    } else {
        D_i2_800D6C70 = 0;
        func_i2_800BC4D8();
    }
}

void func_i2_800BCD5C(void) {

    gSPVertex(D_i2_800D6C74++, D_800D65D0, 16, 0);
    gSPDisplayList(D_i2_800D6C74++, D_8014210);
    func_i2_800B97AC(D_i2_800D6C7C, 0);
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C7C;
    func_i2_800B97AC(D_i2_800D6C80, 0);
    D_i2_800D6C08[1].unk_00 = D_i2_800D6C80;
}

void func_i2_800BCDFC(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];
    if (D_i2_800D6C7C == D_i2_800D6C68->unk_00) {
        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C68->unk_10);
        func_i2_800B97AC(D_i2_800D6C80, 0);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C80;
    } else {
        D_i2_800D6C70 = 1;
        func_i2_800BCD5C();
    }
}

void func_i2_800BCF0C(void) {

    D_i2_800D6C68 = &D_i2_800D6C08[D_i2_800D6C70];
    if (D_i2_800D6C80 == D_i2_800D6C68->unk_00) {
        D_i2_800D6C6C = &D_i2_800D6C08[D_i2_800D6C70 ^= 1];

        gSPVertex(D_i2_800D6C74++, D_800D65D0, 8, D_i2_800D6C6C->unk_2C);
        gSPDisplayList(D_i2_800D6C74++, D_i2_800D6C6C->unk_10);
        func_i2_800B97AC(D_i2_800D6C7C, D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_80000000);
        D_i2_800D6C6C->unk_00 = D_i2_800D6C7C;
    } else {
        D_i2_800D6C70 = 0;
        func_i2_800BCD5C();
    }
}

extern GfxPool* gGfxPool;

void func_i2_800BD024(unk_800A8B74_arg_0* arg0) {
    f32 var_fv0;
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a1;

    D_i2_800D6C7C = arg0->unk_00;
    D_i2_800D6C80 = arg0->unk_00 + 1;

    if (D_i2_800D6C80 == D_i2_800D65CC) {
        D_i2_800D6C80 = D_802BE5C0;
    }

    do {
        if (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
            if (D_i2_800D6C80 != arg0->unk_04) {

                D_i2_800D6C78 = D_i2_800D6C80 + 1;
                if (D_i2_800D6C78 == D_i2_800D65CC) {
                    D_i2_800D6C78 = D_802BE5C0;
                }
                var_fv0 = D_i2_800D6BFC;

                do {
                    var_fv0 += D_i2_800D6C00;
                    if (D_i2_800D6C78->unk_0C < var_fv0) {
                        break;
                    }

                    if ((D_i2_800D6C80 = D_i2_800D6C78) == arg0->unk_04) {
                        break;
                    }

                    D_i2_800D6C78++;
                    if (D_i2_800D6C78 == D_i2_800D65CC) {
                        D_i2_800D6C78 = D_802BE5C0;
                    }
                } while (D_i2_800D6C80->trackSegmentInfo & TRACK_FLAG_CONTINUOUS);
            }
        }

        if (D_800D65D0 >= &gGfxPool->unk_1A308[0xFF0]) {
            break;
        }

        trackShape = TRACK_SHAPE_INDEX((u32) D_i2_800D6C7C->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = D_i2_800D6C7C->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a1 = &D_i2_800C18D8[trackShape][trackType];
            D_i2_800D6C84 = temp_a1->unk_10;

            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            trackType = D_i2_800D6C7C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != D_i2_800D6BD8) {
                gDPLoadSync(D_i2_800D6C74++);
                gDPSetTextureImage(D_i2_800D6C74++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(D_i2_800D6C74++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                D_i2_800D6BD8 = trackType;
                D_i2_800D6BE0[0] = temp_a1->unk_16;
                D_i2_800D6BE0[1] = temp_a1->unk_18;
                D_i2_800D6BE0[2] = temp_a1->unk_1A;
                D_i2_800D6BE0[3] = temp_a1->unk_1C;
                D_i2_800D6BE0[4] = temp_a1->unk_1E;
            }
        }
        D_i2_800D6C8C = D_i2_800D6C7C->trackSegmentInfo & (TRACK_JOIN_MASK | TRACK_UNK1_MASK | TRACK_UNK2_MASK);
        D_i2_800C1958[trackShape]();

        D_i2_800D6C7C = D_i2_800D6C80++;
        if (D_i2_800D6C80 == D_i2_800D65CC) {
            D_i2_800D6C80 = D_802BE5C0;
        }
    } while (D_i2_800D6C7C != arg0->unk_04);
}

void func_i2_800BD3F0(unk_800A8B74_arg_0* arg0) {
    f32 var_fv0;
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a2;
    unk_36ED0* tempLimit = D_802BE5C0;

    D_i2_800D6C7C = arg0->unk_04 - 1;
    if (D_i2_800D6C7C < tempLimit) {
        D_i2_800D6C7C = D_i2_800D65CC - 1;
    }
    D_i2_800D6C80 = arg0->unk_04;

    do {
        if (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_CONTINUOUS) {
            if (D_i2_800D6C7C != arg0->unk_00) {
                D_i2_800D6C78 = D_i2_800D6C7C - 1;
                if (D_i2_800D6C78 < tempLimit) {
                    D_i2_800D6C78 = D_i2_800D65CC - 1;
                }
                var_fv0 = D_i2_800D6BFC;

                do {
                    var_fv0 += D_i2_800D6C00;
                    if (D_i2_800D6C78->unk_0C < var_fv0) {
                        break;
                    }

                    if ((D_i2_800D6C7C = D_i2_800D6C78) == arg0->unk_00) {
                        break;
                    }

                    D_i2_800D6C78--;
                    if (D_i2_800D6C78 < tempLimit) {
                        D_i2_800D6C78 = D_i2_800D65CC - 1;
                    }
                } while (D_i2_800D6C7C->trackSegmentInfo & TRACK_FLAG_CONTINUOUS);
            }
        }

        if (D_800D65D0 >= &gGfxPool->unk_1A308[0xFF0]) {
            break;
        }

        trackShape = TRACK_SHAPE_INDEX((u32) D_i2_800D6C7C->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = D_i2_800D6C7C->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a2 = &D_i2_800C18D8[trackShape][trackType];
            D_i2_800D6C84 = temp_a2->unk_10;

            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            trackType = D_i2_800D6C7C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != D_i2_800D6BD8) {
                gDPLoadSync(D_i2_800D6C74++);
                gDPSetTextureImage(D_i2_800D6C74++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a2->width, temp_a2->texture);
                gDPLoadBlock(D_i2_800D6C74++, temp_a2->tile, 0, 0, 2047, CALC_DXT(temp_a2->width, G_IM_SIZ_16b));
                D_i2_800D6BD8 = trackType;
                D_i2_800D6BE0[0] = temp_a2->unk_16;
                D_i2_800D6BE0[1] = temp_a2->unk_18;
                D_i2_800D6BE0[2] = temp_a2->unk_1A;
                D_i2_800D6BE0[3] = temp_a2->unk_1C;
                D_i2_800D6BE0[4] = temp_a2->unk_1E;
            }
        }
        D_i2_800D6C8C = D_i2_800D6C7C->trackSegmentInfo & (TRACK_JOIN_MASK | TRACK_UNK1_MASK | TRACK_UNK2_MASK);
        D_i2_800C1978[trackShape]();

        D_i2_800D6C80 = D_i2_800D6C7C--;
        if (D_i2_800D6C7C < tempLimit) {
            D_i2_800D6C7C = D_i2_800D65CC - 1;
        }
    } while (D_i2_800D6C80 != arg0->unk_00);
}

Gfx* func_i2_800BD7EC(Gfx* gfx, Vtx* arg1, s32 arg2) {
    s32 i;

    while (arg2 > 30) {
        gSPVertex(gfx++, arg1, 30, 0);

        for (i = 0; i < 27; i += 3) {
            gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
            gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
            gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        }
        arg2 -= 27;
        arg1 += 27;
    }

    gSPVertex(gfx++, arg1, arg2, 0);

    i = 0;
    do {
        gSP2Triangles(gfx++, i + 1, i + 0, i + 4, 0, i + 4, i + 0, i + 3, 0);
        gSP2Triangles(gfx++, i + 0, i + 2, i + 3, 0, i + 3, i + 2, i + 5, 0);
        gSP2Triangles(gfx++, i + 2, i + 1, i + 5, 0, i + 5, i + 1, i + 4, 0);
        i += 3;
        arg2 -= 3;
    } while (arg2 > 3);

    return gfx;
}

extern u32 gGameFrameCount;

Gfx* func_i2_800BDAA4(Gfx* gfx) {
    s32 trackType;
    u32 trackShape;
    unk_800CF528* temp_a1;

    if (D_800D65C8 < 3) {
        return gfx;
    }
    D_i2_800D6C88 = true;
    D_i2_800D6C74 = gfx;
    gSPDisplayList(D_i2_800D6C74++, D_8014040);
    gSPDisplayList(D_i2_800D6C74++, D_8014078);
    gDPSetPrimColor(D_i2_800D6C74++, 0, 0, (255 - (u8) (gGameFrameCount * 8)), 0, 0, 255);

    D_i2_800D6BD8 = D_i2_800D6BDC = -1;
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C08[1].unk_00 = 0;
    D_i2_800D6C70 = 0;
    D_i2_800D6C7C = D_802BE5C0;
    D_i2_800D6C80 = &D_802BE5C0[1];
    do {
        if (D_800D65D0 >= &gGfxPool->unk_2A308[0x7E5]) {
            return D_i2_800D6C74;
        }

        trackShape = TRACK_SHAPE_INDEX((u32) D_i2_800D6C7C->trackSegmentInfo & TRACK_SHAPE_MASK);
        trackType = D_i2_800D6C7C->trackSegmentInfo & TRACK_TYPE_MASK;
        if (trackType != TRACK_TYPE_NONE) {
            temp_a1 = &D_i2_800C18D8[trackShape][trackType];
            D_i2_800D6C84 = temp_a1->unk_10;
            if (D_i2_800D6BDC != D_i2_800D6C84) {
                gSPTexture(D_i2_800D6C74++, 0, 0, 0, D_i2_800D6BDC, G_OFF);
                gSPTexture(D_i2_800D6C74++, 0x8000, 0xFFFF, 0, D_i2_800D6C84, G_ON);
                D_i2_800D6BDC = D_i2_800D6C84;
            }

            trackType = D_i2_800D6C7C->trackSegmentInfo & (TRACK_SHAPE_MASK | TRACK_TYPE_MASK);
            if (trackType != D_i2_800D6BD8) {
                gDPLoadSync(D_i2_800D6C74++);
                gDPSetTextureImage(D_i2_800D6C74++, G_IM_FMT_RGBA, G_IM_SIZ_16b, temp_a1->width, temp_a1->texture);
                gDPLoadBlock(D_i2_800D6C74++, temp_a1->tile, 0, 0, 2047, CALC_DXT(temp_a1->width, G_IM_SIZ_16b));

                D_i2_800D6BD8 = trackType;
                D_i2_800D6BE0[0] = temp_a1->unk_16;
                D_i2_800D6BE0[1] = temp_a1->unk_18;
                D_i2_800D6BE0[2] = temp_a1->unk_1A;
                D_i2_800D6BE0[3] = temp_a1->unk_1C;
                D_i2_800D6BE0[4] = temp_a1->unk_1E;
            }
        }
        D_i2_800D6C8C = D_i2_800D6C7C->trackSegmentInfo & (TRACK_JOIN_MASK | TRACK_UNK1_MASK | TRACK_UNK2_MASK);
        D_i2_800C1958[trackShape]();

        D_i2_800D6C7C = D_i2_800D6C80++;

    } while (D_i2_800D6C7C != D_i2_800D65CC);

    return D_i2_800D6C74;
}

extern Camera gCameras[];

Gfx* func_i2_800BDE60(Gfx* gfx, s32 playerIndex) {
    MtxF sp60;
    f32 var_fv1;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fv1;
    s32 var_a1;
    unk_36ED0* temp_a2_2;
    unk_36ED0* var_v0;
    unk_36ED0* var_v1;
    unk_800A8B74_arg_0* var_s0;
    CourseSegment* segment;
    unk_800A8B74_arg_0* var_v1_3;
    unk_800A8B74_arg_0* temp;
    s32 var_a0;
    s32 var_t0;
    s32 var_a2;
    Racer* racer;
    Camera* camera;
    s32 i;

    camera = &gCameras[playerIndex];
    racer = &gRacers[camera->id];

    D_i2_800D6C74 = gfx;
    segment = racer->segmentPositionInfo.courseSegment;

    if (segment->trackSegmentInfo & TRACK_FLAG_20000000) {
        if (((segment->trackSegmentInfo & TRACK_JOIN_PREVIOUS) &&
             (racer->segmentPositionInfo.segmentTValue < segment->previousJoinEndTValue)) ||
            ((segment->trackSegmentInfo & TRACK_JOIN_NEXT) &&
             (segment->nextJoinStartTValue < racer->segmentPositionInfo.segmentTValue))) {
            D_i2_800D6C88 = true;
        } else {
            D_i2_800D6C88 = false;
        }
    } else {
        D_i2_800D6C88 = true;
    }

    temp_fv1 = (camera->basis.x.x * D_i2_800C1534) - camera->eye.x;
    temp_fa0 = (camera->basis.x.y * D_i2_800C1534) - camera->eye.y;
    temp_fa1 = (camera->basis.x.z * D_i2_800C1534) - camera->eye.z;

    sp60.m[3][2] = camera->projectionMtx.m[3][2] -
                   (camera->projectionMtx.m[2][2] *
                    (sp60.m[3][3] = ((-temp_fv1 * camera->viewMtx.m[0][2]) - (temp_fa0 * camera->viewMtx.m[1][2])) -
                                    (temp_fa1 * camera->viewMtx.m[2][2])));
    sp60.m[3][0] =
        (camera->projectionMtx.m[0][0] * ((temp_fv1 * camera->viewMtx.m[0][0]) + (temp_fa0 * camera->viewMtx.m[1][0]) +
                                          (temp_fa1 * camera->viewMtx.m[2][0]))) -
        (camera->projectionMtx.m[2][0] * sp60.m[3][3]);
    sp60.m[3][1] =
        (camera->projectionMtx.m[1][1] * ((temp_fv1 * camera->viewMtx.m[0][1]) + (temp_fa0 * camera->viewMtx.m[1][1]) +
                                          (temp_fa1 * camera->viewMtx.m[2][1]))) -
        (camera->projectionMtx.m[2][1] * sp60.m[3][3]);
    sp60.m[0][0] = camera->projectionViewMtx.m[0][0];
    sp60.m[0][1] = camera->projectionViewMtx.m[0][1];
    sp60.m[0][2] = camera->projectionViewMtx.m[0][2];
    sp60.m[0][3] = camera->projectionViewMtx.m[0][3];
    sp60.m[1][0] = camera->projectionViewMtx.m[1][0];
    sp60.m[1][1] = camera->projectionViewMtx.m[1][1];
    sp60.m[1][2] = camera->projectionViewMtx.m[1][2];
    sp60.m[1][3] = camera->projectionViewMtx.m[1][3];
    sp60.m[2][0] = camera->projectionViewMtx.m[2][0];
    sp60.m[2][1] = camera->projectionViewMtx.m[2][1];
    sp60.m[2][2] = camera->projectionViewMtx.m[2][2];
    sp60.m[2][3] = camera->projectionViewMtx.m[2][3];

    var_v1 = D_802BE5C0;

    do {
        var_v1->unk_0C = ((sp60.m[0][2] * var_v1->unk_14.x) + (sp60.m[1][2] * var_v1->unk_14.y) +
                          (sp60.m[2][2] * var_v1->unk_14.z)) +
                         sp60.m[3][2];

        if ((var_v1->unk_0C < 0.0f) || (D_i2_800C1530 < var_v1->unk_0C)) {
            var_v1->unk_10 = 0;
        } else {
            temp_fa0 = 1.0f / (((sp60.m[0][3] * var_v1->unk_14.x) + (sp60.m[1][3] * var_v1->unk_14.y) +
                                (sp60.m[2][3] * var_v1->unk_14.z)) +
                               sp60.m[3][3]);
            var_fv1 = temp_fa0 * (((sp60.m[0][0] * var_v1->unk_14.x) + (sp60.m[1][0] * var_v1->unk_14.y) +
                                   (sp60.m[2][0] * var_v1->unk_14.z)) +
                                  sp60.m[3][0]);
            if ((var_fv1 < -1.0f) || (var_fv1 > 1.0f)) {
                var_v1->unk_10 = 0;
            } else {
                temp_fa0 = 1.0f / (((sp60.m[0][3] * var_v1->unk_14.x) + (sp60.m[1][3] * var_v1->unk_14.y) +
                                    (sp60.m[2][3] * var_v1->unk_14.z)) +
                                   sp60.m[3][3]);
                var_fv1 = temp_fa0 * (((sp60.m[0][1] * var_v1->unk_14.x) + (sp60.m[1][1] * var_v1->unk_14.y) +
                                       (sp60.m[2][1] * var_v1->unk_14.z)) +
                                      sp60.m[3][1]);
                if ((var_fv1 < -1.0f) || (var_fv1 > 1.0f)) {
                    var_v1->unk_10 = 0;
                } else {
                    var_v1->unk_10 = 1;
                }
            }
        }
        var_v1++;
    } while (var_v1 != D_i2_800D65CC);
    D_i2_800D65CC->unk_0C = D_802BE5C0->unk_0C;
    D_i2_800D65CC->unk_10 = D_802BE5C0->unk_10;
    var_a1 = 1;
    D_i2_800C1510 = 0;
    var_v0 = &D_802BE5C0[1];
    var_v1 = D_802BE5C0;
    do {
        if ((var_v1->unk_10 != 0) || (var_v0->unk_10 != 0)) {
            var_fv1 = var_v0->unk_0C - var_v1->unk_0C;
            if (var_fv1 < -30.0f) {
                var_a1 = -1;
                var_v1->unk_10 = var_a1;
            } else if (var_fv1 > 30.0f) {
                var_a1 = 1;
                var_v1->unk_10 = var_a1;
            } else {
                var_v1->unk_10 = var_a1;
            }
            D_i2_800C1510++;
        } else {
            var_v1->unk_10 = 0;
        }
        var_v1 = var_v0;
        var_v0++;
    } while (D_i2_800D65CC >= var_v0);
    D_i2_800D65CC->unk_10 = D_802BE5C0->unk_10;
    if (D_i2_800C1510 == 0) {
        return D_i2_800D6C74;
    }
    if (D_i2_800C1510 == D_800D65C8) {
        temp = D_i2_800D65D8;
        temp->unk_00 = temp->unk_04 = D_802BE5C0;
        temp->unk_0C = 1;
        temp->unk_08 = 0.0f;
        var_v1_3 = temp + 1;
    } else {
        var_v1 = D_i2_800D65CC - 1;
        if (var_v1->unk_10 == 0) {
            var_v1 = D_802BE5C0;
            while (var_v1->unk_10 == 0) {
                var_v1++;
            }
        } else {
            var_v1--;
            while (var_v1->unk_10 != 0) {
                var_v1--;
            }
            var_v1++;
        }
        temp_a2_2 = var_v1;

        i = 0;
        temp = D_i2_800D65D8;
        do {
            temp->unk_00 = var_v1;
            temp->unk_08 = temp_fa0 = var_v1->unk_0C;
            temp->unk_0C = var_a1 = var_v1->unk_10;
            var_a0 = 1;

            while (true) {
                var_v1++;
                if (var_v1 == D_i2_800D65CC) {
                    var_v1 = D_802BE5C0;
                }
                var_a0++;
                temp->unk_08 += var_v1->unk_0C;
                var_fv1 = temp_fa0 - var_v1->unk_0C;
                if ((var_fv1 < -D_i2_800C152C) || (D_i2_800C152C < var_fv1) || (var_v1 == temp_a2_2) ||
                    (var_a1 != var_v1->unk_10)) {
                    break;
                }
            }

            temp->unk_04 = var_v1;
            temp->unk_08 /= var_a0;

            if (++temp == &D_i2_800D65D8[0x60]) {
                return D_i2_800D6C74;
            }
            while (var_v1->unk_10 == 0) {
                var_v1++;
                if (var_v1 == D_i2_800D65CC) {
                    var_v1 = D_802BE5C0;
                }
            }
        } while (var_v1 != temp_a2_2);
        var_v1_3 = temp;
    }

    gSPDisplayList(D_i2_800D6C74++, D_8014008);
    gSPDisplayList(D_i2_800D6C74++, D_8014078);
    gSPFogPosition(D_i2_800D6C74++, D_i2_800C1518, 1000);
    gDPSetPrimColor(D_i2_800D6C74++, 0, 0, 255 - ((gGameFrameCount * 8) % 256), 0, 0, 255);

    if (1) {}
    segment = racer->segmentPositionInfo.courseSegment;

    if (segment->trackSegmentInfo & TRACK_FLAG_20000000) {
        if (segment->nextJoinStartTValue < racer->segmentPositionInfo.segmentTValue) {
            var_fv1 = (1.0f - racer->segmentPositionInfo.segmentLengthProportion) / segment->joinScale;
        } else if (racer->segmentPositionInfo.segmentTValue < segment->previousJoinEndTValue) {
            var_fv1 = racer->segmentPositionInfo.segmentLengthProportion / segment->joinScale;
        } else {
            var_a0 = gCurrentCourseInfo->unk_14[0] >> 2;
            var_t0 = gCurrentCourseInfo->unk_14[1] >> 2;
            var_a2 = gCurrentCourseInfo->unk_14[2] >> 2;
            goto block_68;
        }
        var_a0 = gCurrentCourseInfo->unk_14[0] +
                 Math_Round(((gCurrentCourseInfo->unk_14[0] >> 2) - gCurrentCourseInfo->unk_14[0]) * var_fv1);
        var_t0 = gCurrentCourseInfo->unk_14[1] +
                 Math_Round(((gCurrentCourseInfo->unk_14[1] >> 2) - gCurrentCourseInfo->unk_14[1]) * var_fv1);
        var_a2 = gCurrentCourseInfo->unk_14[2] +
                 Math_Round(((gCurrentCourseInfo->unk_14[2] >> 2) - gCurrentCourseInfo->unk_14[2]) * var_fv1);
    } else {
        var_a0 = gCurrentCourseInfo->unk_14[0];
        var_t0 = gCurrentCourseInfo->unk_14[1];
        var_a2 = gCurrentCourseInfo->unk_14[2];
    }
block_68:

    gDPSetFogColor(D_i2_800D6C74++, var_a0, var_t0, var_a2, 255);

    D_i2_800D6BD8 = D_i2_800D6BDC = -1;
    D_i2_800D6C08[0].unk_00 = D_i2_800D6C08[1].unk_00 = NULL;
    D_i2_800D6C70 = 0;

    while (true) {
        var_fv1 = -10000.0f;

        temp = D_i2_800D65D8;
        do {
            if (var_fv1 < temp->unk_08) {
                var_fv1 = temp->unk_08;
                var_s0 = temp;
            }
            temp++;
        } while (temp != var_v1_3);

        if (var_fv1 == -10000.0f) {
            break;
        }

        if (var_s0->unk_0C == 1) {
            func_i2_800BD3F0(var_s0);
        } else {
            func_i2_800BD024(var_s0);
        }
        var_s0->unk_08 = -20000.0f;
    }

    if (D_i2_800D6BDC == 1) {
        gSPTexture(D_i2_800D6C74++, 0, 0, 0, 1, G_OFF);
    } else {
        gSPTexture(D_i2_800D6C74++, 0, 0, 0, 5, G_OFF);
    }
    return D_i2_800D6C74;
}

extern unk_800D6CA0 D_800D6CA0;

s32 func_i2_800BE8BC(CourseInfo* courseInfo) {
    s32 var_s3 = -1;
    f32 alpha1;
    f32 alpha2;
    CourseSegment* segment = courseInfo->courseSegments;

    if (1) {}
    do {
        func_i2_800B1AF0(segment, &alpha1, &alpha2);
        segment->tension = (alpha1 + alpha2) * 0.5f;
        if ((alpha1 < 0.0f) || (alpha1 > 2.0f) || (alpha2 < 0.0f) || (alpha2 > 2.0f)) {
            var_s3 = segment->segmentIndex;
            segment->tension = 0.1f;
        }
        segment = segment->next;
    } while (segment != courseInfo->courseSegments);

    D_800D6CA0.unk_20 = var_s3;
    return var_s3;
}

bool func_i2_800BE9D4(f32* regValue) {
    u32 regAsInt = *(u32*) regValue;
    s32 regExp = ((regAsInt & 0x7F800000) >> 0x17) - 0x7F;

    if (((-0x7F < regExp) && (regExp < 0x80)) || (regAsInt == 0)) {
        return false;
    } else {
        PRINTF("FLOATING POINT EXCEPTION\n");
        return true;
    }
}

s32 Course_CalculateChecksum(void) {
    s32 i;
    u32 var_v1 = COURSE_CONTEXT()->courseData.controlPointCount;

    for (i = 0; i < COURSE_CONTEXT()->courseData.controlPointCount; i++) {
        ControlPoint* controlPoint = &COURSE_CONTEXT()->courseData.controlPoint[i];

        controlPoint->trackSegmentInfo &= ~TRACK_JOIN_MASK;
        controlPoint->trackSegmentInfo &= ~TRACK_FORM_MASK;
        controlPoint->trackSegmentInfo &= ~TRACK_FLAG_CONTINUOUS;

        if (func_i2_800BE9D4(&controlPoint->pos.x)) {
            return -1;
        }

        if (controlPoint->pos.x < -15000.0f) {
            return -1;
        }
        if (controlPoint->pos.x > 15000.0f) {
            return -1;
        }

        if (func_i2_800BE9D4(&controlPoint->pos.y)) {
            return -1;
        }

        if (controlPoint->pos.y < -250.0f) {
            return -1;
        }
        if (controlPoint->pos.y > 5000.0f) {
            return -1;
        }

        if (func_i2_800BE9D4(&controlPoint->pos.z)) {
            return -1;
        }

        if (controlPoint->pos.z < -15000.0f) {
            return -1;
        }
        if (controlPoint->pos.z > 15000.0f) {
            return -1;
        }

        var_v1 += (s32) ((controlPoint->pos.x + ((1.1f + (0.7f * i)) * controlPoint->pos.y)) +
                         ((2.2f + (1.2f * i)) * controlPoint->pos.z * (4.4f + (0.9f * i))) + controlPoint->radiusLeft +
                         ((5.5f + (0.8f * i)) * controlPoint->radiusRight * 4.8f)) +
                  controlPoint->trackSegmentInfo * (0xFE - i) +
                  COURSE_CONTEXT()->courseData.bankAngle[i] * (0x93DE - i * 2);
    }

    for (i = 0; i < COURSE_CONTEXT()->courseData.controlPointCount; i++) {
        var_v1 += (COURSE_CONTEXT()->courseData.pit[i] * i);
        var_v1 += (COURSE_CONTEXT()->courseData.dash[i] * (i + 0x10));
        var_v1 += (COURSE_CONTEXT()->courseData.dirt[i] * (i + 0x80));
        var_v1 += (COURSE_CONTEXT()->courseData.ice[i] * (i + 0x100));
        var_v1 += (COURSE_CONTEXT()->courseData.jump[i] * (i + 0x800));
        var_v1 += (COURSE_CONTEXT()->courseData.landmine[i] * (i + 0x1000));
        var_v1 += (COURSE_CONTEXT()->courseData.gate[i] * (i + 0x8000));
        var_v1 += (COURSE_CONTEXT()->courseData.building[i] * (i + 0x10000));
        var_v1 += (COURSE_CONTEXT()->courseData.sign[i] * (i + 0x80000));
    }

    return var_v1;
}
