#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"
#include "fzx_assets.h"

uintptr_t gSegments[16];
uintptr_t gArenaStartPtrs[4];
uintptr_t gArenaEndPtrs[4];

u16 D_8076CBD0 = 0;
s8 D_8076CBD4 = false;
s8 D_8076CBD8 = false;
s8 D_8076CBDC = false;
s8 D_8076CBE0 = -1;
s8 D_8076CBE4 = false;

u8* D_8076CBE8[] = {
    SEGMENT_VRAM_START(segment_235130), // VENUE_MUTE_CITY
    SEGMENT_VRAM_START(segment_239A80), // VENUE_PORT_TOWN
    SEGMENT_VRAM_START(segment_23EC50), // VENUE_BIG_BLUE
    SEGMENT_VRAM_START(segment_243D90), // VENUE_SAND_OCEAN
    SEGMENT_VRAM_START(segment_24A270), // VENUE_DEVILS_FOREST
    SEGMENT_VRAM_START(segment_2507F0), // VENUE_WHITE_LAND
    SEGMENT_VRAM_START(segment_255100), // VENUE_SECTOR
    SEGMENT_VRAM_START(segment_259600), // VENUE_RED_CANYON
    SEGMENT_VRAM_START(segment_25F360), // VENUE_FIRE_FIELD
    SEGMENT_VRAM_START(segment_266C20), // VENUE_SILENCE
    SEGMENT_VRAM_START(segment_26D780), // VENUE_ENDING
};

u8* D_8076CC14[] = {
    SEGMENT_VRAM_END(segment_235130), // VENUE_MUTE_CITY
    SEGMENT_VRAM_END(segment_239A80), // VENUE_PORT_TOWN
    SEGMENT_VRAM_END(segment_23EC50), // VENUE_BIG_BLUE
    SEGMENT_VRAM_END(segment_243D90), // VENUE_SAND_OCEAN
    SEGMENT_VRAM_END(segment_24A270), // VENUE_DEVILS_FOREST
    SEGMENT_VRAM_END(segment_2507F0), // VENUE_WHITE_LAND
    SEGMENT_VRAM_END(segment_255100), // VENUE_SECTOR
    SEGMENT_VRAM_END(segment_259600), // VENUE_RED_CANYON
    SEGMENT_VRAM_END(segment_25F360), // VENUE_FIRE_FIELD
    SEGMENT_VRAM_END(segment_266C20), // VENUE_SILENCE
    SEGMENT_VRAM_END(segment_26D780), // VENUE_ENDING
};

s32 D_8076CC40 = 0;

extern u8 D_800D6D90[];
extern u8 D_8012CAC0[];
extern u8 D_8023F020[];
extern u8 D_8024E200[];
extern u8 D_807C7190[];

extern s32 gSegment17B1E0VramEnd;
extern s32 gSegment17B960VramEnd;
extern s32 gGameMode;

void Arena_StartInit(void) {
    uintptr_t* block1 = &gArenaStartPtrs[0];
    uintptr_t* block2 = &gArenaStartPtrs[1];
    uintptr_t* block3 = &gArenaStartPtrs[2];
    uintptr_t* block4 = &gArenaStartPtrs[3];

    *block1 = ALIGN16((uintptr_t) D_800D6D90);
    *block3 = ALIGN16((uintptr_t) D_8024E200);
    *block4 = ALIGN16((uintptr_t) D_807C7190);

    switch (gGameMode) {
        case GAMEMODE_TIME_ATTACK:
            *block3 = ALIGN16((uintptr_t) D_8023F020);
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            *block2 = ALIGN16((uintptr_t) osPhysicalToVirtual(gSegment17B960VramEnd));
            break;
        default:
            *block2 = ALIGN16((uintptr_t) osPhysicalToVirtual(gSegment17B1E0VramEnd));
            break;
    }
}

void Arena_DefaultStartInit(void) {
    gArenaStartPtrs[0] = ALIGN16((uintptr_t) D_8012CAC0);
    gArenaStartPtrs[1] = 0x803DD000;
    gArenaStartPtrs[2] = ALIGN16((uintptr_t) D_8024E200);
    gArenaStartPtrs[3] = ALIGN16((uintptr_t) D_807C7190);
}

void Arena_EndInit(void) {
    gArenaEndPtrs[0] = 0x801D9800;
    gArenaEndPtrs[1] = 0x803DD000;
    gArenaEndPtrs[2] = ALIGN16((uintptr_t) D_8024E200);
    gArenaEndPtrs[3] = 0x80800000;
}

// Add to memory start and return start of newly allocated block
void* Arena_AllocateFront(s32 arenaIndex, size_t size) {
    void* ret = gArenaStartPtrs[arenaIndex];

    size = ALIGN16(size);
    gArenaStartPtrs[arenaIndex] += size;

    return ret;
}

// Get memory block (non-allocating mode, used for compressed blocks)
void* Arena_GetStartPtr(s32 arenaIndex, size_t size) {
    void* ret = gArenaStartPtrs[arenaIndex];

    return ret;
}

// Take from memory end and return new memory end
void* Arena_AllocateBack(s32 arenaIndex, size_t size) {

    size = ALIGN16(size);
    gArenaEndPtrs[arenaIndex] -= size;

    return (u8*) gArenaEndPtrs[arenaIndex];
}

void* Arena_Allocate(s32 allocationType, size_t size) {
    size_t arenaSizes[4];
    s8 sortedArenaIndices[4];
    u8* allocatePtr;
    s32 i;
    s32 j;
    s32 temp;

    // Sets initial array of memory indexes and the sizes left in the 3 memory blocks
    for (i = 0; i < 4; i++) {
        sortedArenaIndices[i] = i;
        arenaSizes[i] = gArenaEndPtrs[i] - gArenaStartPtrs[i];
    }

    // Sort memory indexes in order of size (without disturbing order of memory blocks)
    // Smallest -> Largest
    for (i = 3; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arenaSizes[sortedArenaIndices[j]] >= arenaSizes[sortedArenaIndices[j + 1]]) {
                temp = sortedArenaIndices[j];
                sortedArenaIndices[j] = sortedArenaIndices[j + 1];
                sortedArenaIndices[j + 1] = temp;
            }
        }
    }

    // Check the smallest memory block this can be allocated into
    for (i = 0; i < 4; i++) {
        if (size < arenaSizes[sortedArenaIndices[i]]) {
            break;
        }
    }

    // If not enough size in any block, default to memory block with largest available space
    // Exit with NULL when allocating from back (memory must be guaranteed for these)
    if (i >= 4) {
        i = 3;
        if (allocationType == ALLOC_BACK) {
            return NULL;
        }
    }

    switch (allocationType) {
        case ALLOC_FRONT:
            allocatePtr = Arena_AllocateFront(sortedArenaIndices[i], size);
            break;
        case ALLOC_PEEK:
            allocatePtr = Arena_GetStartPtr(sortedArenaIndices[i], size);
            break;
        case ALLOC_BACK:
            allocatePtr = Arena_AllocateBack(sortedArenaIndices[i], size);
            break;
    }
    return allocatePtr;
}

s32 Segment_SetPhysicalAddress(s32 segment, s32 addr) {
    gSegments[segment] = K0_TO_PHYS(addr);
    return gSegments[segment];
}

s32 Segment_SetAddress(s32 segment, s32 addr) {
    gSegments[segment] = addr;
    return gSegments[segment];
}

s32 Segment_GetAddress(s32 segment) {
    return PHYS_TO_K0(gSegments[segment]);
}

s32 Segment_SegmentedToVirtual(uintptr_t segmentedAddr) {
    return PHYS_TO_K0(gSegments[SEGMENT_NUMBER(segmentedAddr)] + SEGMENT_OFFSET(segmentedAddr));
}

Gfx* Segment_SetTableAddresses(Gfx* gfx) {
    s32 i;

    for (i = 0; i < 16; i++) {
        gSPSegment(gfx++, i, gSegments[i]);
    }

    return gfx;
}

extern unk_80128C94* D_80128C90;
extern s32 gSegment1B8550VramStart;
extern s32 gSegment1B8550VramEnd;

void Segment_SetupSegment4(void) {
    size_t segmentSize;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_CREATE_MACHINE:
            segmentSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            D_8076CBD0 = 2;
            break;
        case GAMEMODE_COURSE_EDIT:
            D_8076CBD0 = 2;
            segmentSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            D_80128C90 = Arena_AllocateFront(1, 2 * sizeof(unk_80128C94));
            break;
        case GAMEMODE_RECORDS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            D_8076CBD0 = 2;
            Segment_SetAddress(4, gSegment1B8550VramStart);
            return;
        default:
            D_8076CBD0 = 0;
            Segment_SetAddress(4, gSegment1B8550VramStart);
            return;
    }
    gSegment1B8550VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment1B8550VramEnd = ALIGN16(gSegment1B8550VramStart + segmentSize);
    Segment_SetAddress(4, gSegment1B8550VramStart);
}

extern s32 gSegment1E23F0VramStart;
extern s32 gSegment1E23F0VramEnd;

void Segment_SetupSegment7(void) {
    size_t ramSize;

    D_8076CBD4 = true;
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            ramSize = SEGMENT_VRAM_SIZE(segment_1E23F0);
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            ramSize = SEGMENT_VRAM_SIZE(expansion_kit_textures);
            break;
        default:
            D_8076CBD4 = false;
            Segment_SetAddress(7, gSegment1E23F0VramStart);
            return;
    }

    gSegment1E23F0VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, ramSize));
    gSegment1E23F0VramEnd = ALIGN16(gSegment1E23F0VramStart + ramSize);
    Segment_SetAddress(7, gSegment1E23F0VramStart);
}

extern s32 gSegment22B0A0VramStart;
extern s32 gSegment22B0A0VramEnd;

void Segment_SetupSegment9(void) {
    size_t segmentSize;

    D_8076CBD8 = true;
    switch (gGameMode) {
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            segmentSize = SEGMENT_DATA_SIZE_CONST(segment_22B0A0);
            break;
        case GAMEMODE_COURSE_EDIT:
            segmentSize = SEGMENT_VRAM_SIZE(course_edit_textures);
            break;
        default:
            D_8076CBD8 = false;
            Segment_SetAddress(9, gSegment22B0A0VramStart);
            return;
    }
    gSegment22B0A0VramStart = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    gSegment22B0A0VramEnd = ALIGN16(gSegment22B0A0VramStart + segmentSize);
    Segment_SetAddress(9, gSegment22B0A0VramStart);
}

extern s32 D_8079A44C;
extern s32 D_8079A450;

void Segment_SetupSegment10(void) {
    size_t segmentSize;

    D_8076CBDC = true;
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            segmentSize = SEGMENT_DATA_SIZE_CONST(segment_235130);
            break;
        default:
            D_8076CBDC = false;
            Segment_SetAddress(10, D_8079A44C);
            return;
    }
    D_8079A44C = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    D_8079A450 = ALIGN16(D_8079A44C + segmentSize);
    Segment_SetAddress(10, D_8079A44C);
}

extern s32 D_8079A454;
extern s32 D_8079A458;

void Segment_SetupSegment5(void) {
    size_t segmentSize;

    D_8076CBE4 = true;
    switch (gGameMode) {
        case GAMEMODE_GP_END_CS:
            segmentSize = SEGMENT_DATA_SIZE_CONST(segment_2738A0);
            break;
        default:
            D_8076CBE4 = false;
            Segment_SetAddress(5, D_8079A454);
            return;
    }
    D_8079A454 = osVirtualToPhysical(Arena_Allocate(ALLOC_FRONT, segmentSize));
    D_8079A458 = ALIGN16(D_8079A454 + segmentSize);
    Segment_SetAddress(5, D_8079A454);
}

bool func_80708D88(void) {
    bool sp54;
    RomOffset diskStart;
    uintptr_t vramStart;
    uintptr_t vramTextStart;
    uintptr_t vramDataStart;
    uintptr_t vramBssStart;
    RomOffset romStart;
    size_t segmentRomSize;
    size_t segmentVramSize;
    size_t segmentTextSize;
    size_t segmentDataSize;
    size_t segmentBssSize;

    if (gGameMode == GAMEMODE_EAD_DEMO) {
        D_8076CC40 = 1;
        return false;
    }
    sp54 = false;
    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        CLEAR_TEXT_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9));
        CLEAR_DATA_CACHE(SEGMENT_DATA_START(ovl_i9), SEGMENT_DATA_SIZE(ovl_i9));
        DiskDrive_LoadOverlay(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9),
                      SEGMENT_BSS_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
        D_8076CC40 = 1;
    } else {
        Arena_AllocateFront(0, SEGMENT_VRAM_SIZE(ovl_i9));
        if (D_8076CC40 == 1) {
            CLEAR_TEXT_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9));
            CLEAR_DATA_CACHE(SEGMENT_DATA_START(ovl_i9), SEGMENT_DATA_SIZE(ovl_i9));
            DiskDrive_LoadOverlay(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9),
                          SEGMENT_BSS_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
            sp54 = true;
        }
        D_8076CC40 = 0;
    }
    return sp54;
}

void Segment_LoadOverlays(void) {
    s32 pad;
    bool isOverlay = false;
    RomOffset diskStart;
    uintptr_t vramStart;
    uintptr_t vramTextStart;
    uintptr_t vramDataStart;
    uintptr_t vramBssStart;
    RomOffset romStart;
    size_t segmentRomSize;
    size_t segmentVramSize;
    size_t segmentTextSize;
    size_t segmentDataSize;
    size_t segmentBssSize;

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            vramTextStart = SEGMENT_TEXT_START(ovl_i3);
            vramStart = SEGMENT_VRAM_START(ovl_i3);
            vramDataStart = SEGMENT_DATA_START(ovl_i3);
            vramBssStart = SEGMENT_BSS_START(ovl_i3);
            diskStart = SEGMENT_DISK_START(ovl_i3);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i3);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i3);
            segmentRomSize = SEGMENT_BSS_START(ovl_i3) - SEGMENT_VRAM_START(ovl_i3);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i3);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i3);
            break;
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_TITLE:
        case GAMEMODE_FLX_MACHINE_SELECT:
            vramTextStart = SEGMENT_TEXT_START(ovl_i4);
            vramStart = SEGMENT_VRAM_START(ovl_i4);
            vramDataStart = SEGMENT_DATA_START(ovl_i4);
            vramBssStart = SEGMENT_BSS_START(ovl_i4);
            diskStart = SEGMENT_DISK_START(ovl_i4);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i4);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i4);
            segmentRomSize = SEGMENT_BSS_START(ovl_i4) - SEGMENT_VRAM_START(ovl_i4);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i4);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i4);
            break;
        case GAMEMODE_FLX_COURSE_SELECT:
        case GAMEMODE_FLX_GP_RACE_NEXT_COURSE:
        case GAMEMODE_FLX_RECORDS_COURSE_SELECT:
            vramTextStart = SEGMENT_TEXT_START(course_select);
            vramStart = SEGMENT_VRAM_START(course_select);
            vramDataStart = SEGMENT_DATA_START(course_select);
            vramBssStart = SEGMENT_BSS_START(course_select);
            diskStart = SEGMENT_DISK_START(course_select);
            segmentTextSize = SEGMENT_TEXT_SIZE(course_select);
            segmentDataSize = SEGMENT_DATA_SIZE(course_select);
            segmentRomSize = SEGMENT_BSS_START(course_select) - SEGMENT_VRAM_START(course_select);
            segmentVramSize = SEGMENT_VRAM_SIZE(course_select);
            segmentBssSize = SEGMENT_BSS_SIZE(course_select);
            break;
        case GAMEMODE_FLX_MAIN_MENU:
        case GAMEMODE_FLX_SKIPPABLE_CREDITS:
        case GAMEMODE_FLX_UNSKIPPABLE_CREDITS:
        case GAMEMODE_FLX_OPTIONS_MENU:
            vramTextStart = SEGMENT_TEXT_START(ovl_i6);
            vramStart = SEGMENT_VRAM_START(ovl_i6);
            vramDataStart = SEGMENT_DATA_START(ovl_i6);
            vramBssStart = SEGMENT_BSS_START(ovl_i6);
            diskStart = SEGMENT_DISK_START(ovl_i6);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_i6);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_i6);
            segmentRomSize = SEGMENT_BSS_START(ovl_i6) - SEGMENT_VRAM_START(ovl_i6);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_i6);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_i6);
            break;
        case GAMEMODE_COURSE_EDIT:
            isOverlay = true;
            vramTextStart = SEGMENT_TEXT_START(course_edit);
            vramStart = SEGMENT_VRAM_START(course_edit);
            vramDataStart = SEGMENT_DATA_START(course_edit);
            vramBssStart = SEGMENT_BSS_START(course_edit);
            diskStart = SEGMENT_DISK_START(course_edit);
            segmentTextSize = SEGMENT_TEXT_SIZE(course_edit);
            segmentDataSize = SEGMENT_DATA_SIZE(course_edit);
            segmentRomSize = SEGMENT_BSS_START(course_edit) - SEGMENT_VRAM_START(course_edit);
            segmentVramSize = SEGMENT_VRAM_SIZE(course_edit);
            segmentBssSize = SEGMENT_BSS_SIZE(course_edit);
            break;
        case GAMEMODE_CREATE_MACHINE:
            isOverlay = true;
            vramTextStart = SEGMENT_TEXT_START(machine_create);
            vramStart = SEGMENT_VRAM_START(machine_create);
            vramDataStart = SEGMENT_DATA_START(machine_create);
            vramBssStart = SEGMENT_BSS_START(machine_create);
            diskStart = SEGMENT_DISK_START(machine_create);
            segmentTextSize = SEGMENT_TEXT_SIZE(machine_create);
            segmentDataSize = SEGMENT_DATA_SIZE(machine_create);
            segmentRomSize = SEGMENT_BSS_START(machine_create) - SEGMENT_VRAM_START(machine_create);
            segmentVramSize = SEGMENT_VRAM_SIZE(machine_create);
            segmentBssSize = SEGMENT_BSS_SIZE(machine_create);
            break;
        case GAMEMODE_EAD_DEMO:
            isOverlay = true;
            vramTextStart = SEGMENT_TEXT_START(ead_demo);
            vramStart = SEGMENT_VRAM_START(ead_demo);
            vramDataStart = SEGMENT_DATA_START(ead_demo);
            vramBssStart = SEGMENT_BSS_START(ead_demo);
            diskStart = SEGMENT_DISK_START(ead_demo);
            segmentTextSize = SEGMENT_TEXT_SIZE(ead_demo);
            segmentDataSize = SEGMENT_DATA_SIZE(ead_demo);
            segmentRomSize = SEGMENT_BSS_START(ead_demo) - SEGMENT_VRAM_START(ead_demo);
            segmentVramSize = SEGMENT_VRAM_SIZE(ead_demo);
            segmentBssSize = SEGMENT_BSS_SIZE(ead_demo);
            break;
        default:
            return;
    }

    if (isOverlay) {
        Arena_AllocateFront(0, segmentVramSize);
        CLEAR_TEXT_CACHE(vramTextStart, segmentTextSize);
        CLEAR_DATA_CACHE(vramDataStart, segmentDataSize);
        DiskDrive_LoadOverlay(diskStart, vramStart, segmentRomSize, segmentBssSize);
    }
    D_8076CBD0 = 1;
    Segment_SetupSegment4();
    Segment_SetupSegment7();
    Segment_SetupSegment9();
    Segment_SetupSegment10();
    Segment_SetupSegment5();
}

extern s32 gSegment17B960VramStart;

extern RomOffset gRomSegmentPairs[][2];

void Segment_LoadSegment4(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;

    if (D_8076CBD0 == 0) {
        return;
    }
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            Dma_LoadAssetsAsync(gRomSegmentPairs[10][0], osPhysicalToVirtual(gSegment17B960VramStart),
                          SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = gRomSegmentPairs[8][0];
            ramSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_CREATE_MACHINE:
            Dma_LoadAssetsAsync(gRomSegmentPairs[10][0], osPhysicalToVirtual(gSegment17B960VramStart),
                          SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = gRomSegmentPairs[28][0];
            ramSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            break;
        case GAMEMODE_COURSE_EDIT:
            Dma_LoadAssetsAsync(gRomSegmentPairs[10][0], osPhysicalToVirtual(gSegment17B960VramStart),
                          SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = gRomSegmentPairs[8][0];
            ramSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_RECORDS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            Dma_LoadAssetsAsync(gRomSegmentPairs[10][0], osPhysicalToVirtual(gSegment17B960VramStart),
                          SEGMENT_VRAM_SIZE(segment_17B960));
        default:
            D_8076CBD0 = 0;
            return;
    }

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    Dma_LoadAssets(romOffset, osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    D_8076CBD0 = 0;
}

void Segment_LoadSegment7(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;

    if (!D_8076CBD4) {
        return;
    }
    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_DEATH_RACE:
            romOffset = gRomSegmentPairs[9][0];
            ramSize = SEGMENT_VRAM_SIZE(segment_1E23F0);
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            loadFromDisk = true;
            diskOffset = SEGMENT_DISK_START(expansion_kit_textures);
            ramSize = SEGMENT_VRAM_SIZE(expansion_kit_textures);
            break;
        default:
            D_8076CBD4 = false;
            return;
    }
    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    if (loadFromDisk) {
        DiskDrive_LoadOverlay(diskOffset, osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize, 0);
    } else {
        Dma_LoadAssets(romOffset, osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    }
    D_8076CBD4 = false;
}

void Segment_LoadSegment9(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (!D_8076CBD8) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            romOffset = gRomSegmentPairs[14][0];
            ramSize = SEGMENT_VRAM_SIZE(segment_22B0A0);
            break;
        case GAMEMODE_COURSE_EDIT:
            loadFromDisk = true;
            diskOffset = SEGMENT_DISK_START(course_edit_textures);
            ramSize = SEGMENT_VRAM_SIZE(course_edit_textures);
            break;
        default:
            D_8076CBD8 = false;
            return;
    }

    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        if (loadFromDisk) {
            DiskDrive_LoadOverlay(diskOffset, osPhysicalToVirtual(gSegment22B0A0VramStart), ramSize, 0);
        } else {
            Dma_LoadAssets(romOffset, osPhysicalToVirtual(gSegment22B0A0VramStart), ramSize);
        }
    } else {
        vram = Arena_Allocate(ALLOC_PEEK, ramSize);
        CLEAR_DATA_CACHE(vram, ramSize);

        if (loadFromDisk) {
            DiskDrive_LoadOverlay(diskOffset, vram, ramSize, 0);
        } else {
            Dma_LoadAssets(romOffset, vram, ramSize);
        }
        if (*(s32*) vram == (s32) 'MIO0') {
            mio0Decode(vram, osPhysicalToVirtual(gSegment22B0A0VramStart));
        }
    }
    D_8076CBD8 = false;
}

extern s32 D_8079A44C;

void Segment_LoadSegment10(void) {
    s32 pad;
    s32 venue;
    s32 pad2;
    RomOffset romOffset;
    size_t ramSize;
    u8* vram;

    if (!D_8076CBDC) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_GP_RACE:
        case GAMEMODE_PRACTICE:
        case GAMEMODE_VS_2P:
        case GAMEMODE_VS_3P:
        case GAMEMODE_VS_4P:
        case GAMEMODE_RECORDS:
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_TIME_ATTACK:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_DEATH_RACE:
            venue = COURSE_CONTEXT()->courseData.venue;
            romOffset = gRomSegmentPairs[16 + venue][0];
            ramSize = D_8076CC14[venue] - D_8076CBE8[venue];
            break;
        default:
            D_8076CBDC = false;
            return;
    }
    vram = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(vram, ramSize);
    Dma_LoadAssets(romOffset, vram, ramSize);
    if (*(s32*) vram == (s32) 'MIO0') {
        mio0Decode(vram, osPhysicalToVirtual(D_8079A44C));
    }
    D_8076CBDC = false;
    func_i2_800B0D10(venue);
}

void func_80709A38(s32 venue) {
    if ((venue >= VENUE_MUTE_CITY) && (venue <= VENUE_SILENCE) && (D_8076CBE0 < 0)) {
        D_8076CBE0 = venue;
    }
}

void Segment_LoadSegment10CourseEdit(void) {
    s32 pad;
    s32 venue;
    s32 pad2;
    RomOffset romOffset;
    size_t ramSize;
    u8* sp18;

    if (D_8076CBE0 < 0) {
        return;
    }
    venue = D_8076CBE0;

    switch (gGameMode) {
        case GAMEMODE_COURSE_EDIT:
            romOffset = gRomSegmentPairs[16 + venue][0];
            ramSize = D_8076CC14[venue] - D_8076CBE8[venue];
            break;
        default:
            return;
    }

    sp18 = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(sp18, ramSize);
    Dma_LoadAssets(romOffset, sp18, ramSize);
    if (*(s32*) sp18 == (s32) 'MIO0') {
        mio0Decode(sp18, osPhysicalToVirtual(D_8079A44C));
    }
    D_8076CBE0 = -1;
    func_i2_800B0D10(venue);
}

void Segment_LoadSegment5(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;
    u8* sp24;

    if (!D_8076CBE4) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_GP_END_CS:
            romOffset = gRomSegmentPairs[27][0];
            ramSize = SEGMENT_VRAM_SIZE(segment_2738A0);
            break;
        default:
            D_8076CBE4 = false;
            return;
    }

    sp24 = Arena_Allocate(ALLOC_PEEK, ramSize);

    CLEAR_DATA_CACHE(sp24, ramSize);
    Dma_LoadAssets(romOffset, sp24, ramSize);
    if (*(s32*) sp24 == (s32) 'MIO0') {
        mio0Decode(sp24, osPhysicalToVirtual(D_8079A454));
    }
    D_8076CBE4 = false;
}

void Segment_LoadAssets(void) {
    Segment_LoadSegment4();
    Segment_LoadSegment7();
    Segment_LoadSegment9();
    Segment_LoadSegment10();
    Segment_LoadSegment10CourseEdit();
    Segment_LoadSegment5();
}
