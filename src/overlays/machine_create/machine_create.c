#include "global.h"
#include "machine_create.h"
#include "fzx_game.h"
#include "fzx_bordered_box.h"

BorderedBoxWidget* gMachineCreateStatsBox;
BorderedBoxWidget* gMachineCreateColorBox;

extern CustomMachinesInfo gCustomMachinesInfo;
extern s16 D_8076C7A8;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern Vp gMachinePartViewports[][7];
extern s32 D_8076C954;

void MachineCreate_Init(void) {
    Vp* vp;
    u8 i;
    u8 j;

    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    func_i2_800B079C();
    Object_Init(OBJECT_174, 256, 186, 6);
    Object_Init(OBJECT_170, 20, 10, 6);
    Object_Init(OBJECT_173, 0, 0, 8);
    Object_Init(OBJECT_172, 0, 0, 10);
    Object_Init(OBJECT_171, 0, 0, 12);
    D_8076C7A8 = 3;
    func_xk1_8002FB80();
    func_xk3_8012BABC();
    func_xk1_8002E9D0(1);
    ExpansionKit_SetInputIndicatorFlashRate(1);
    func_xk1_80025C00(1);
    func_xk1_8002AF10(0xC);
    func_xk1_80025F98();
    func_xk1_8002B150(0xA8, 0x57, &D_xk3_80140E50, &D_xk3_80140E54);
    func_80704810(0);
    func_xk1_8002AED0();

    for (i = 0; i < 30; i++) {
        if (gCustomMachinesInfo.characterCustomState[i] == 1) {
            gCustomMachinesInfo.characterCustomState[i] = 2;
            break;
        }
    }

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 7; i++) {
            if ((j == MACHINE_PART_WING) && (i < 3)) {
                continue;
            }
            vp = &gMachinePartViewports[j][i];
            vp->vp.vscale[0] = (SCREEN_WIDTH / 2) << 2;
            vp->vp.vscale[1] = (SCREEN_HEIGHT / 2) << 2;
            vp->vp.vscale[2] = 0x1FF;
            vp->vp.vscale[3] = 0;
            vp->vp.vtrans[0] = ((i * 0x27) + 0x2B) << 2;
            if (j == 2) {
                vp->vp.vtrans[1] = ((j * 0x30) + 0x2F) << 2;
            } else {
                vp->vp.vtrans[1] = ((j * 0x33) + 0x2F) << 2;
            }
            vp->vp.vtrans[2] = 0x1FF;
            vp->vp.vtrans[3] = 0;
        }
    }
    BorderedBox_CleanWidget(&gMachineCreateStatsBox);
    BorderedBox_CleanWidget(&gMachineCreateColorBox);
    BorderedBox_ClearAll();
    gWorksMachineMode = MACHINE_MODE_0;
    D_8076C954 = 1;
}

extern s16 D_8076C810;
extern s8 D_80794E10;
extern s32 D_8079A35C;
extern unk_801413F0 D_xk3_801413F0[];
extern unk_801413F0* D_xk3_801414B0;

s32 MachineCreate_Update(void) {
    D_xk3_801414B0 = &D_xk3_801413F0[D_8079A35C];
    if (gWorksMachineMode == MACHINE_MODE_ENTRY) {
        MachineCreate_MachineSelectUpdate();
        return GAMEMODE_CREATE_MACHINE;
    }
    if (func_xk3_8012DF04()) {
        if (D_8076C810 != 0) {
            return GAMEMODE_FLX_MAIN_MENU;
        }
        func_80705E18();
        func_80742F04();
        D_80794E10 = 0;
        D_8076C954 = 0;
        PRINTF("WORKS MACHINE MODE : 0\n");
        gWorksMachineMode = MACHINE_MODE_0;
        func_xk1_8002FBB0();
        func_8071E0C0();
        ExpansionKit_SetMenuHighlightDrawFlag(true);
        func_80704810(1);
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
        return GAMEMODE_FLX_MAIN_MENU;
    }
    BorderedBox_Update();
    return GAMEMODE_CREATE_MACHINE;
}

extern Gfx D_xk3_80137300[];
extern Gfx D_xk3_80137460[];
extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A364;

Gfx* MachineCreate_Draw(Gfx* gfx) {
    gSPDisplayList(gfx++, D_xk3_80137300);
    gSPDisplayList(gfx++, D_xk3_80137460);

    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, PHYSICAL_TO_VIRTUAL(gFrameBuffers[D_8079A364]));

    if (gWorksMachineMode == MACHINE_MODE_ENTRY) {
        gfx = MachineCreate_DrawColorGradientRectangle(gfx, 12, 8, 307, 231, 0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 60.0f);
        gfx = MachineCreate_DrawMachineSelect(gfx);
    } else {
        gfx = func_xk3_80131494(gfx);
    }
    return gfx;
}
