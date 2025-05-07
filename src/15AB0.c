#include "global.h"
#include "fzx_game.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807082B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807083D8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708430.s")

extern uintptr_t D_8079FA80[];

u8* func_80708474(s32 arg0, size_t arg1) {
    u8* ret = D_8079FA80[arg0];

    arg1 = ALIGN16(arg1);
    D_8079FA80[arg0] += arg1;

    return ret;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807084A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807084B8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807084E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/Segment_SetPhysicalAddress.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708790.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807087A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807087C4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/Segment_SetTableAddresses.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807088A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708A44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708B34.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708C1C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708CE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708D88.s")

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80708F4C.s")
extern s16 D_8076CBD0;
extern s32 gGameMode;

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
        case 0x16:
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
        {
            OSIntMask prevMask = osGetIntMask();
            osSetIntMask(OS_IM_NONE);
            osInvalICache(vramTextStart, segmentTextSize);
            osSetIntMask(prevMask);
        }
        {
            OSIntMask prevMask = osGetIntMask();
            osSetIntMask(OS_IM_NONE);
            osInvalDCache(vramDataStart, segmentDataSize);
            osSetIntMask(prevMask);
        }
        func_80703CA4(diskStart, vramStart, segmentRomSize, segmentBssSize);
    }
    D_8076CBD0 = 1;
    func_807088A8();
    func_80708A44();
    func_80708B34();
    func_80708C1C();
    func_80708CE0();
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_807093F4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709620.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709760.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709914.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709A38.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709A64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709B5C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/15AB0/func_80709C3C.s")
