#include "global.h"
#include "ovl_i4.h"
#include "fzx_game.h"
#include "fzx_racer.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_assets.h"

extern s16 D_8076C7A8;
extern s32 gSelectedMode;
extern s8 gPlayerSelectionLock[];
extern s32 gMachineSelectState;
extern s8 gSettingEverythingUnlocked;
extern f32 D_8076E568;
extern f32 D_8076E56C;
extern f32 D_8076E570;
extern s32 gNumPlayers;
extern s32 sMachinesUnlocked;
extern s16 sMachineSelectIndex[8];

void MachineSelect_Init(void) {
    s32 i;

    D_8076C7A8 = 3;
    D_8076E568 = D_8076E56C = D_8076E570 = 0.1f;
    func_807160A0();
    func_8071A358();
    gMachineSelectState = MACHINE_SELECT_ACTIVE;

    for (i = 0; i < 4; i++) {
        gPlayerSelectionLock[i] = SELECTION_FREE;
        sMachineSelectIndex[i] = func_8070DBF0(gRacers[i].character);
    }
    sMachinesUnlocked = ((func_8070DA54() / 3) * 6) + 6;
    if (gSettingEverythingUnlocked != 0) {
        sMachinesUnlocked = 30;
    }
    if (sMachinesUnlocked > 30) {
        sMachinesUnlocked = 30;
    }
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_MACHINE_SELECT_BACKGROUND, 0, 0, 4);
    Object_Init(OBJECT_MACHINE_SELECT_HEADER, 80, 13, 4);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR, 60, 10, 8);
    Object_Init(OBJECT_MACHINE_SELECT_MACHINE, 0, 0, 10);

    switch (gNumPlayers) {
        case 4:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_3, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_3, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_3, 260, 190, 6);
            /* fallthrough */
        case 3:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_2, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_2, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_2, 260, 10, 6);
            /* fallthrough */
        case 2:
            Object_Init(OBJECT_MACHINE_SELECT_STATS_1, 0, 0, 12);
            Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_1, 60, 10, 12);
            Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_1, 20, 190, 6);
            /* fallthrough */
        case 1:
            break;
    }

    if (gSelectedMode == MODE_GP_RACE) {
        Object_Init(OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS, 0, 0, 12);
    }
    Object_Init(OBJECT_MACHINE_SELECT_STATS_0, 0, 0, 12);
    Object_Init(OBJECT_MACHINE_SELECT_CURSOR_NUM_0, 60, 10, 12);
    Object_Init(OBJECT_MACHINE_SELECT_PORTRAIT_0, 20, 10, 6);

    if (gNumPlayers == 1) {
        Object_Init(OBJECT_MACHINE_SELECT_NAME, 0, 0, 12);
    }

    Object_Init(OBJECT_MACHINE_SELECT_OK, 0, 0, 12);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_Init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_Update.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_Update.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_Draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_Draw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_8007021C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_HeaderInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_80070288.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_PortraitInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_PortraitInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorNumInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_MachineInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_MachineInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_EngineWeightInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_StatsInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_NameCardInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_SliderInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_DifficultyCupsInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_StatsInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_OkInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_OkInit.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_BackgroundDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_HeaderDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_80071054.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_PortraitDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_StatsDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_PortraitDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorNumDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_MachineDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_OkDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_NameDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_MachineDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_EngineWeightDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_StatsDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_800729D8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_NameCardDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_SliderDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_SplitscreenDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_DifficultyCupsDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F48.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F4C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F54.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076F74.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/D_i4_80076FA4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_NameDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_OkDraw.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_800732A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_PortraitUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_PortraitUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorNumUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_CursorUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_MachineUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_MachineUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSelect_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_OkUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/MachineSettings_NameCardUpdate.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i4/DE7C0/func_i4_80073EA0.s")
