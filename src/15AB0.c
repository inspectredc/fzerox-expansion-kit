#include "global.h"
#include "fzx_game.h"
#include "fzx_course.h"

extern uintptr_t D_8079FA80[];
extern uintptr_t D_8079FA90[];
extern u8 D_800D6D90[];
extern u8 D_8012CAC0[];
extern u8 D_8023F020[];
extern u8 D_8024E200[];
extern u8 D_807C7190[];

extern s32 gSegment17B1E0VramEnd;
extern s32 gSegment17B960VramEnd;
extern s32 gGameMode;

void func_807082B0(void) {
    uintptr_t* block1 = &D_8079FA80[0];
    uintptr_t* block2 = &D_8079FA80[1];
    uintptr_t* block3 = &D_8079FA80[2];
    uintptr_t* block4 = &D_8079FA80[3];

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

void func_807083D8(void) {
    D_8079FA80[0] = ALIGN16((uintptr_t) D_8012CAC0);
    D_8079FA80[1] = 0x803DD000;
    D_8079FA80[2] = ALIGN16((uintptr_t) D_8024E200);
    D_8079FA80[3] = ALIGN16((uintptr_t) D_807C7190);
}

void func_80708430(void) {
    D_8079FA90[0] = 0x801D9800;
    D_8079FA90[1] = 0x803DD000;
    D_8079FA90[2] = ALIGN16((uintptr_t) D_8024E200);
    D_8079FA90[3] = 0x80800000;
}

// Add to memory start and return start of newly allocated block
void* func_80708474(s32 arg0, size_t arg1) {
    void* ret = D_8079FA80[arg0];

    arg1 = ALIGN16(arg1);
    D_8079FA80[arg0] += arg1;

    return ret;
}

// Get memory block (non-allocating mode, used for compressed blocks)
void* func_807084A0(s32 arg0, size_t arg1) {
    void* ret = D_8079FA80[arg0];

    return ret;
}

// Take from memory end and return new memory end
void* func_807084B8(s32 arg0, size_t arg1) {

    arg1 = ALIGN16(arg1);
    D_8079FA90[arg0] -= arg1;

    return (u8*) D_8079FA90[arg0];
}

void* func_807084E4(s32 arg0, size_t arg1) {
    size_t sp54[4];
    s8 sp50[4];
    u8* sp4C;
    s32 i;
    s32 j;
    s32 temp;

    // Sets initial array of memory indexes and the sizes left in the 3 memory blocks
    for (i = 0; i < 4; i++) {
        sp50[i] = i;
        sp54[i] = D_8079FA90[i] - D_8079FA80[i];
    }

    // Sort memory indexes in order of size (without disturbing order of memory blocks)
    // Smallest -> Largest
    for (i = 3; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (sp54[sp50[j]] >= sp54[sp50[j + 1]]) {
                temp = sp50[j];
                sp50[j] = sp50[j + 1];
                sp50[j + 1] = temp;
            }
        }
    }

    // Check the smallest memory block this can be allocated into
    for (i = 0; i < 4; i++) {
        if (arg1 < sp54[sp50[i]]) {
            break;
        }
    }

    // If not enough size in any block, default to memory block with largest available space
    // Exit with NULL under a certain condition (todo)
    if (i >= 4) {
        i = 3;
        if (arg0 == 2) {
            return NULL;
        }
    }

    switch (arg0) {
        case 0:
            sp4C = func_80708474(sp50[i], arg1);
            break;
        case 1:
            sp4C = func_807084A0(sp50[i], arg1);
            break;
        case 2:
            sp4C = func_807084B8(sp50[i], arg1);
            break;
    }
    return sp4C;
}

extern u32 gSegments[];

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
extern u16 D_8076CBD0;
extern s32 gSegment1B8550VramStart;
extern s32 gSegment1B8550VramEnd;

void func_807088A8(void) {
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
            D_80128C90 = func_80708474(1, 2 * sizeof(unk_80128C94));
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
    gSegment1B8550VramStart = osVirtualToPhysical(func_807084E4(0, segmentSize));
    gSegment1B8550VramEnd = ALIGN16(gSegment1B8550VramStart + segmentSize);
    Segment_SetAddress(4, gSegment1B8550VramStart);
}

extern s8 D_8076CBD4;
extern s32 gSegment1E23F0VramStart;
extern s32 gSegment1E23F0VramEnd;

void func_80708A44(void) {
    size_t ramSize;

    D_8076CBD4 = 1;
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
            ramSize = SEGMENT_VRAM_SIZE(segment_145B70);
            break;
        default:
            D_8076CBD4 = 0;
            Segment_SetAddress(7, gSegment1E23F0VramStart);
            return;
    }

    gSegment1E23F0VramStart = osVirtualToPhysical(func_807084E4(0, ramSize));
    gSegment1E23F0VramEnd = ALIGN16(gSegment1E23F0VramStart + ramSize);
    Segment_SetAddress(7, gSegment1E23F0VramStart);
}

extern s8 D_8076CBD8;
extern s32 gSegment22B0A0VramStart;
extern s32 gSegment22B0A0VramEnd;

void func_80708B34(void) {
    size_t segmentSize;

    D_8076CBD8 = 1;
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
            D_8076CBD8 = 0;
            Segment_SetAddress(9, gSegment22B0A0VramStart);
            return;
    }
    gSegment22B0A0VramStart = osVirtualToPhysical(func_807084E4(0, segmentSize));
    gSegment22B0A0VramEnd = ALIGN16(gSegment22B0A0VramStart + segmentSize);
    Segment_SetAddress(9, gSegment22B0A0VramStart);
}

extern s8 D_8076CBDC;
extern s32 D_8079A44C;
extern s32 D_8079A450;

void func_80708C1C(void) {
    size_t segmentSize;

    D_8076CBDC = 1;
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
            D_8076CBDC = 0;
            Segment_SetAddress(10, D_8079A44C);
            return;
    }
    D_8079A44C = osVirtualToPhysical(func_807084E4(0, segmentSize));
    D_8079A450 = ALIGN16(D_8079A44C + segmentSize);
    Segment_SetAddress(10, D_8079A44C);
}

extern s8 D_8076CBE4;
extern s32 D_8079A454;
extern s32 D_8079A458;

void func_80708CE0(void) {
    size_t segmentSize;

    D_8076CBE4 = 1;
    if (gGameMode != GAMEMODE_GP_END_CS) {
        D_8076CBE4 = 0;
        Segment_SetAddress(5, D_8079A454);
        return;
    }
    segmentSize = SEGMENT_DATA_SIZE_CONST(segment_2738A0);
    D_8079A454 = osVirtualToPhysical(func_807084E4(0, segmentSize));
    D_8079A458 = ALIGN16(D_8079A454 + segmentSize);
    Segment_SetAddress(5, D_8079A454);
}

extern s32 D_8076CC40;

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

    if (gGameMode == GAMEMODE_16) {
        D_8076CC40 = 1;
        return 0;
    }
    sp54 = false;
    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        CLEAR_TEXT_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9));
        CLEAR_DATA_CACHE(SEGMENT_DATA_START(ovl_i9), SEGMENT_DATA_SIZE(ovl_i9));
        func_80703CA4(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9),
                      SEGMENT_BSS_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
        D_8076CC40 = 1;
    } else {
        func_80708474(0, SEGMENT_VRAM_SIZE(ovl_i9));
        if (D_8076CC40 == 1) {
            CLEAR_TEXT_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9));
            CLEAR_DATA_CACHE(SEGMENT_DATA_START(ovl_i9), SEGMENT_DATA_SIZE(ovl_i9));
            func_80703CA4(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9),
                          SEGMENT_BSS_START(ovl_i9) - SEGMENT_VRAM_START(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));
            sp54 = true;
        }
        D_8076CC40 = 0;
    }
    return sp54;
}

void func_80708F4C(void) {
    s32 pad;
    bool var_t1 = false;
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
            var_t1 = true;
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
            var_t1 = true;
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
        case GAMEMODE_16:
            var_t1 = true;
            vramTextStart = SEGMENT_TEXT_START(ovl_xk4);
            vramStart = SEGMENT_VRAM_START(ovl_xk4);
            vramDataStart = SEGMENT_DATA_START(ovl_xk4);
            vramBssStart = SEGMENT_BSS_START(ovl_xk4);
            diskStart = SEGMENT_DISK_START(ovl_xk4);
            segmentTextSize = SEGMENT_TEXT_SIZE(ovl_xk4);
            segmentDataSize = SEGMENT_DATA_SIZE(ovl_xk4);
            segmentRomSize = SEGMENT_BSS_START(ovl_xk4) - SEGMENT_VRAM_START(ovl_xk4);
            segmentVramSize = SEGMENT_VRAM_SIZE(ovl_xk4);
            segmentBssSize = SEGMENT_BSS_SIZE(ovl_xk4);
            break;
        default:
            return;
    }

    if (var_t1) {
        func_80708474(0, segmentVramSize);
        CLEAR_TEXT_CACHE(vramTextStart, segmentTextSize);
        CLEAR_DATA_CACHE(vramDataStart, segmentDataSize);
        func_80703CA4(diskStart, vramStart, segmentRomSize, segmentBssSize);
    }
    D_8076CBD0 = 1;
    func_807088A8();
    func_80708A44();
    func_80708B34();
    func_80708C1C();
    func_80708CE0();
}

extern s32 gSegment17B960VramStart;

extern s32 D_807C70E0;
extern s32 D_807C70F0;
extern s32 D_807C7180;

void func_807093F4(void) {
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
            func_80701D7C(D_807C70F0, osPhysicalToVirtual(gSegment17B960VramStart), SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = D_807C70E0;
            ramSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_CREATE_MACHINE:
            func_80701D7C(D_807C70F0, osPhysicalToVirtual(gSegment17B960VramStart), SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = D_807C7180;
            ramSize = SEGMENT_VRAM_SIZE(create_machine_textures);
            break;
        case GAMEMODE_COURSE_EDIT:
            func_80701D7C(D_807C70F0, osPhysicalToVirtual(gSegment17B960VramStart), SEGMENT_VRAM_SIZE(segment_17B960));
            romOffset = D_807C70E0;
            ramSize = SEGMENT_VRAM_SIZE(segment_1B8550);
            break;
        case GAMEMODE_RECORDS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
        case GAMEMODE_FLX_MACHINE_SELECT:
            func_80701D7C(D_807C70F0, osPhysicalToVirtual(gSegment17B960VramStart), SEGMENT_VRAM_SIZE(segment_17B960));
        default:
            D_8076CBD0 = 0;
            return;
    }

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    func_8070818C(romOffset, osPhysicalToVirtual(gSegment1B8550VramStart), ramSize);
    D_8076CBD0 = 0;
}

extern s32 D_807C70E8;
extern u8 D_2AC[];

void func_80709620(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;

    if (D_8076CBD4 == 0) {
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
            romOffset = D_807C70E8;
            ramSize = SEGMENT_VRAM_SIZE(segment_1E23F0);
            break;
        case GAMEMODE_COURSE_EDIT:
        case GAMEMODE_CREATE_MACHINE:
            loadFromDisk = true;
            diskOffset = D_2AC;
            // diskOffset = SEGMENT_DISK_START(segment_145B70);
            ramSize = SEGMENT_VRAM_SIZE(segment_145B70);
            break;
        default:
            D_8076CBD4 = 0;
            return;
    }
    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    if (loadFromDisk) {
        func_80703CA4(diskOffset, osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize, 0);
    } else {
        func_8070818C(romOffset, osPhysicalToVirtual(gSegment1E23F0VramStart), ramSize);
    }
    D_8076CBD4 = 0;
}

extern u8 D_2B4[];
extern s32 D_807C7110;

void func_80709760(void) {
    bool loadFromDisk = false;
    u32 diskOffset;
    RomOffset romOffset;
    size_t ramSize;
    u8* sp1C;

    if (D_8076CBD8 == 0) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_CREATE_MACHINE:
        case GAMEMODE_GP_END_CS:
        case GAMEMODE_LX_MACHINE_SETTINGS:
        case GAMEMODE_LX_GP_RACE_NEXT_MACHINE_SETTINGS:
            romOffset = D_807C7110;
            ramSize = SEGMENT_VRAM_SIZE(segment_22B0A0);
            break;
        case GAMEMODE_COURSE_EDIT:
            loadFromDisk = true;
            diskOffset = D_2B4;
            // diskOffset = SEGMENT_DISK_START(course_edit_textures);
            ramSize = SEGMENT_VRAM_SIZE(course_edit_textures);
            break;
        default:
            D_8076CBD8 = 0;
            return;
    }

    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        if (loadFromDisk) {
            func_80703CA4(diskOffset, osPhysicalToVirtual(gSegment22B0A0VramStart), ramSize, 0);
        } else {
            func_8070818C(romOffset, osPhysicalToVirtual(gSegment22B0A0VramStart), ramSize);
        }
    } else {
        sp1C = func_807084E4(1, ramSize);
        CLEAR_DATA_CACHE(sp1C, ramSize);

        if (loadFromDisk) {
            func_80703CA4(diskOffset, sp1C, ramSize, 0);
        } else {
            func_8070818C(romOffset, sp1C, ramSize);
        }
        if (*(s32*) sp1C == (s32) 'MIO0') {
            mio0Decode(sp1C, osPhysicalToVirtual(gSegment22B0A0VramStart));
        }
    }
    D_8076CBD8 = 0;
}

extern u8* D_8076CBE8[];
extern u8* D_8076CC14[];
extern s32 D_8079A44C;
extern RomOffset D_807C7120[][2];

void func_80709914(void) {
    s32 pad;
    s32 venue;
    s32 pad2;
    RomOffset romOffset;
    size_t ramSize;
    u8* sp20;

    if (D_8076CBDC == 0) {
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
            romOffset = D_807C7120[venue][0];
            ramSize = D_8076CC14[venue] - D_8076CBE8[venue];
            break;
        default:
            D_8076CBDC = 0;
            return;
    }
    sp20 = func_807084E4(1, ramSize);

    CLEAR_DATA_CACHE(sp20, ramSize);
    func_8070818C(romOffset, sp20, ramSize);
    if (*(s32*) sp20 == (s32) 'MIO0') {
        mio0Decode(sp20, osPhysicalToVirtual(D_8079A44C));
    }
    D_8076CBDC = 0;
    func_i2_800B0D10(venue);
}

extern s8 D_8076CBE0;

void func_80709A38(s32 venue) {
    if ((venue >= VENUE_MUTE_CITY) && (venue <= VENUE_SILENCE) && (D_8076CBE0 < 0)) {
        D_8076CBE0 = venue;
    }
}

void func_80709A64(void) {
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
            romOffset = D_807C7120[venue][0];
            ramSize = D_8076CC14[venue] - D_8076CBE8[venue];
            break;
        default:
            return;
    }

    sp18 = func_807084E4(1, ramSize);

    CLEAR_DATA_CACHE(sp18, ramSize);
    func_8070818C(romOffset, sp18, ramSize);
    if (*(s32*) sp18 == (s32) 'MIO0') {
        mio0Decode(sp18, osPhysicalToVirtual(D_8079A44C));
    }
    D_8076CBE0 = -1;
    func_i2_800B0D10(venue);
}

extern s32 D_807C7178;

void func_80709B5C(void) {
    s32 pad[2];
    RomOffset romOffset;
    size_t ramSize;
    u8* sp24;

    if (D_8076CBE4 == 0) {
        return;
    }

    switch (gGameMode) {
        case GAMEMODE_GP_END_CS:
            romOffset = D_807C7178;
            ramSize = SEGMENT_VRAM_SIZE(segment_2738A0);
            break;
        default:
            D_8076CBE4 = 0;
            return;
    }

    sp24 = func_807084E4(1, ramSize);

    CLEAR_DATA_CACHE(sp24, ramSize);
    func_8070818C(romOffset, sp24, ramSize);
    if (*(s32*) sp24 == (s32) 'MIO0') {
        mio0Decode(sp24, osPhysicalToVirtual(D_8079A454));
    }
    D_8076CBE4 = 0;
}

void func_80709C3C(void) {
    func_807093F4();
    func_80709620();
    func_80709760();
    func_80709914();
    func_80709A64();
    func_80709B5C();
}
