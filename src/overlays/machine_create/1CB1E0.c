#include "global.h"
#include "fzx_game.h"

extern unk_806F2400 D_806F2400;
extern s16 D_8076C7A8;
extern unk_800E51B8* D_80140E40;
extern s32 D_xk3_80136820;
extern unk_800E51B8* D_xk3_80140E44;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern Vp D_xk3_801412A0[][7];
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
    func_xk1_80029350(1);
    func_xk1_80025C00(1);
    func_xk1_8002AF10(0xC);
    func_xk1_80025F98();
    func_xk1_8002B150(0xA8, 0x57, &D_xk3_80140E50, &D_xk3_80140E54);
    func_80704810(0);
    func_xk1_8002AED0();

    for (i = 0; i < 30; i++) {
        if (D_806F2400.unk_3C0[i] == 1) {
            D_806F2400.unk_3C0[i] = 2;
            break;
        }
    }

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 7; i++) {
            if ((j != 2) || (i >= 3)) {
                vp = &D_xk3_801412A0[j][i];
                vp->vp.vscale[0] = 0x280;
                vp->vp.vscale[1] = 0x1E0;
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
    }
    func_80711170(&D_80140E40);
    func_80711170(&D_xk3_80140E44);
    func_80711178();
    D_xk3_80136820 = 0;
    D_8076C954 = 1;
}

typedef struct unk_801413F0 {
    LookAt unk_00[3];
} unk_801413F0;

extern s16 D_8076C810;
extern s8 D_80794E10;
extern s32 D_8079A35C;
extern s32 D_xk3_80136820;
extern unk_801413F0 D_xk3_801413F0[];
extern unk_801413F0* D_xk3_801414B0;

s32 MachineCreate_Update(void) {
    D_xk3_801414B0 = &D_xk3_801413F0[D_8079A35C];
    if (D_xk3_80136820 == 0x1C) {
        func_xk3_801337A0();
        return GAMEMODE_CREATE_MACHINE;
    }
    if (func_xk3_8012DF04() != 0) {
        if (D_8076C810 != 0) {
            return GAMEMODE_FLX_MAIN_MENU;
        }
        func_80705E18();
        func_80742F04();
        D_80794E10 = 0;
        D_8076C954 = 0;
        PRINTF("WORKS MACHINE MODE : 0\n");
        D_xk3_80136820 = 0;
        func_xk1_8002FBB0();
        func_8071E0C0();
        func_xk1_80026908(1);
        func_80704810(1);
        osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
        return GAMEMODE_FLX_MAIN_MENU;
    }
    func_80711414();
    return GAMEMODE_CREATE_MACHINE;
}

extern s32 D_xk3_80136820;
extern Gfx D_xk3_80137300[];
extern Gfx D_xk3_80137460[];
extern FrameBuffer* gFrameBuffers[];
extern s32 D_8079A364;

Gfx* MachineCreate_Draw(Gfx* gfx) {
    gSPDisplayList(gfx++, D_xk3_80137300);
    gSPDisplayList(gfx++, D_xk3_80137460);

    gDPSetColorImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, PHYSICAL_TO_VIRTUAL(gFrameBuffers[D_8079A364]));

    if (D_xk3_80136820 == 0x1C) {
        gfx = func_xk3_8012F2F4(gfx, 0xC, 8, 0x133, 0xE7, 0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 60.0f);
        gfx = func_xk3_8013387C(gfx);
    } else {
        gfx = func_xk3_80131494(gfx);
    }
    return gfx;
}
