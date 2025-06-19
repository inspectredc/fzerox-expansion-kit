#include "global.h"

extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern f32 D_xk3_80140E58;

void func_xk3_8012B950(void) {
    D_xk3_80140E54 = 0x57;
    D_xk3_80140E58 = 87.0f;
    func_xk1_8002B150(0xA8, 0x57, &D_xk3_80140E50, &D_xk3_80140E54);
}

extern f32 D_xk3_80140E80;
extern f32 D_xk3_80140E84;
extern f32 D_xk3_80140E88;
extern f32 D_xk3_80140E8C;
extern GfxPool* gGfxPool;

void func_xk3_8012B99C(void) {
    gGfxPool->unk_362C8[1].vp.vscale[0] = D_xk3_80140E80 * 640.0f;
    gGfxPool->unk_362C8[1].vp.vscale[1] = D_xk3_80140E84 * 480.0f;
    gGfxPool->unk_362C8[1].vp.vscale[2] = 0x1FF;
    gGfxPool->unk_362C8[1].vp.vscale[3] = 0;
    gGfxPool->unk_362C8[1].vp.vtrans[0] = (D_xk3_80140E88 + 25.0f + 64.0f) * 4.0f;
    gGfxPool->unk_362C8[1].vp.vtrans[1] = (D_xk3_80140E8C + 90.0f + 64.0f + 2.0f) * 4.0f;
    gGfxPool->unk_362C8[1].vp.vtrans[2] = 0x1FF;
    gGfxPool->unk_362C8[1].vp.vtrans[3] = 0;
}

extern f32 D_xk3_80140E78;
extern f32 D_xk3_80140E7C;

void func_xk3_8012BABC(void) {
    D_xk3_80140E80 = 1.0f;
    D_xk3_80140E84 = 1.0f;
    D_xk3_80140E88 = 0.0f;
    D_xk3_80140E8C = 0.0f;
    func_xk3_8012B99C();
    D_xk3_80140E78 = 0.0f;
    D_xk3_80140E7C = 0.0f;
}

s32 func_xk3_8012BB14(u8* arg0) {
    u8 i;
    u16 var_v1 = 0;
    u8* var_v0 = arg0;

    for (i = 0; i < 30; i++) {
        var_v1 += *var_v0++;
    }

    return var_v1;
}

extern s32 D_xk3_80136820;
extern u8 D_xk3_80140750[];
extern unk_806F2400_unk_00 D_xk1_800333D0;

typedef struct unk_801365E0 {
    u8 unk_00[30];
    u16 unk_1E;
} unk_801365E0;
extern unk_801365E0 D_xk3_801365E0;
extern unk_806F2400 D_806F2400;

void func_xk3_8012BB48(void) {
    u8 i;

    
    for (i = 0; i < 30; i++) {
        if (D_806F2400.unk_3C0[i] > 0) {
            if (Leo_strcmp(&D_806F2400.unk_00[i].machineName, &D_xk1_800333D0.machineName) == 0) {
                D_806F2400.unk_00[i] = D_xk1_800333D0;
                D_806F2400.unk_00[i].unk_07 = D_xk3_80140750[i];
                break;
            }
        }
    }
    
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
    D_xk3_801365E0.unk_1E = func_xk3_8012BB14(&D_xk3_801365E0);
    func_80768244(0xFFFB, &D_xk3_801365E0.unk_00[21], "CARD", &D_xk3_801365E0, 0x20, 0, 0xFF, 1);

    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : LOAD_SELECT_SUPER\n");
    PRINTF("WORKS MACHINE MODE : LOAD_CONFIRM\n");
    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_SUPER\n");
    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_CONFIRM\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SUPER_CONFIRM\n");
    PRINTF("WORKS MACHINE MODE : 0\n");
    PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_SUPER\n");
    PRINTF("WORKS MACHINE MODE : ENTRY_LOAD_NOW\n");
}

extern s32 D_xk3_80136820;
extern s32 D_xk3_80140E44;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern f32 D_xk3_80140E58;
extern unk_80026914 D_xk1_80031E50;

void func_xk3_8012BC98(void) {
    s32 sp1C;

    sp1C = D_xk3_80136820;
    D_xk3_80140E54 = 0x1C;
    func_xk1_80027DC8(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
    D_xk3_80140E54 = 0x44;
    func_xk1_80027DC8(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
    switch (sp1C) {
        case 20:
            D_xk3_80140E54 = 0x34;
            break;
        case 21:
            D_xk3_80140E54 = 0x44;
            break;
        case 22:
            D_xk3_80140E54 = 0x54;
            break;
        case 23:
            D_xk3_80140E54 = 0x64;
            break;
    }
    D_xk3_80140E58 = D_xk3_80140E54;
    func_807113DC(D_xk3_80140E44);
}

extern s32 D_xk1_80032C20;
extern s32 D_xk3_80136550;
extern s32 D_xk3_80136554;
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;
extern s32 D_xk3_80140E60[];
extern s32 D_xk3_80140E68[];
extern s32 D_xk3_80140E70[];

void func_xk3_8012BD84(void) {
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    switch (D_xk3_80136820) {
        case 20:
        case 21:
        case 22:
        case 23:
            sp34 = D_xk3_80140E68[0];
            sp30 = D_xk3_80140E68[1];
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E68[1] != 8) {
                func_xk1_8002DAE0(&D_xk3_80140E68, 7, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E68[1], 8, 0);
            if ((sp34 != D_xk3_80140E68[0]) || (sp30 != D_xk3_80140E68[1])) {
                func_8074122C(0x1E);
            }
            break;
        case 17:
            sp2C = D_xk3_80140E60[0];
            sp28 = D_xk3_80140E60[1];
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E60[1] != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E60, 6, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E60[1], 3, 0);
            if ((sp2C != D_xk3_80140E60[0]) || (sp28 != D_xk3_80140E60[1])) {
                func_8074122C(0x1E);
            }
            break;
        case 35:
            sp24 = D_xk3_80140E70[0];
            sp20 = D_xk3_80140E70[1];
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E70[1] != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E70, 4, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E70[1], 3, 0);
            if ((sp24 != D_xk3_80140E70[0]) || (sp20 != D_xk3_80140E70[1])) {
                func_8074122C(0x1E);
            }
            break;
        case 4:
        case 5:
        case 15:
        case 25:
        case 26:
        case 30:
        case 31:
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002BBA4();
            break;
        case 1:
            D_xk3_80136554 = (s32) (D_xk3_80140E54 - 0x24) / 16;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DBD4(&D_xk3_80136554, 2, 0);
            D_xk3_80140E54 = (D_xk3_80136554 * 0x10) + 0x24;
            func_xk1_800269F4(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
            func_xk1_80027CFC(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
            break;
        case 2:
        case 18:
        case 19:
            D_xk3_80136554 = (s32) (D_xk3_80140E54 - 0x34) / 16;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DBD4(&D_xk3_80136554, 7, 0);
            D_xk3_80140E54 = (D_xk3_80136554 * 0x10) + 0x34;
            func_xk1_800269F4(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
            func_xk1_80027CFC(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
            break;
        case 0:
            sp1C = D_xk3_80136550;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            func_xk1_8002DAE0(&D_xk3_80136550, 5, 1);
            D_xk3_80140E50 = (D_xk3_80136550 * 0x30) + 0x30;
            D_xk3_80140E54 = 0x1C;
            if (sp1C != D_xk3_80136550) {
                func_8074122C(0x23);
            }
            break;
    }
    switch (D_xk3_80136820) {
        case 6:
        case 11:
        case 16:
        case 29:
        case 32:
        case 33:
        case 37:
            func_xk1_8002D2F0();
            break;
        default:
            D_xk1_80032C20 = 0;
            break;
    }
}

extern u8 D_xk3_80136548;
extern f32 D_xk3_80140E80;
extern f32 D_xk3_80140E84;

#ifdef IMPORT_DATA
void func_xk3_8012C1C8(void) {
    static u8 D_xk3_80136558 = 0;
    static u8 D_xk3_8013655C = 0;
    f32 var_ft4;
    f32 var_fv0;
    u16 var_a0;
    u16 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a1;
    u16 temp_v1;

    if (D_xk3_80136548 != 0) {
        temp_v1 = gControllers[gPlayerControlPorts[0]].buttonCurrent;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x8000) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x10) != 0;
        }
        var_a0 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x4000) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x20) != 0;
        }
        var_a1 = var_v0;
    } else {
        var_a0 = gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x10;
        var_a1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & 0x20;
    }
    if (var_a1 && var_a0) {
        D_xk3_8013655C = 0;
        D_xk3_80136558 = 0;

    } else {
        if (var_a0) {
            D_xk3_80140E80 *= 1.0f + (0.002f * D_xk3_8013655C);
            D_xk3_80140E84 = D_xk3_80140E80;
            if (D_xk3_8013655C < 50) {
                D_xk3_8013655C++;
            }
        } else {
            D_xk3_8013655C = 0;
        }
        if (var_a1) {
            D_xk3_80140E80 /= (1.0f + (0.002f * D_xk3_80136558));
            D_xk3_80140E84 = D_xk3_80140E80;
            if (D_xk3_80136558 < 50) {
                D_xk3_80136558++;
            }
        } else {
            D_xk3_80136558 = 0;
        }
    }
    if (D_xk3_80140E80 > 6.0f) {
        D_xk3_80140E80 = D_xk3_80140E84 = 6.0f;
    }
    if (D_xk3_80140E80 < 0.2f) {
        D_xk3_80140E80 = D_xk3_80140E84 = 0.2f;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012C1C8.s")
#endif

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012C408.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012C744.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012CAC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012CC10.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012CE44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012D700.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012D79C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012DBFC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/machine_create/1CB610/func_xk3_8012DF04.s")
