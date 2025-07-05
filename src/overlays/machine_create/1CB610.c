#include "global.h"
#include "leo/leo_functions.h"
#include "fzx_machine.h"

s32 D_xk3_80140E50;
s32 D_xk3_80140E54;
f32 D_xk3_80140E58;

unk_80140E60 D_xk3_80140E60;
unk_80140E60 D_xk3_80140E68;
unk_80140E60 D_xk3_80140E70;

f32 D_xk3_80140E78;
f32 D_xk3_80140E7C;
f32 D_xk3_80140E80;
f32 D_xk3_80140E84;
f32 D_xk3_80140E88;
f32 D_xk3_80140E8C;
unk_806F2400 D_xk3_80140E90;
unk_806F2400_unk_00 D_xk3_80141270;

u8 D_xk3_80141290;
u8 D_xk3_80141291;
s32 D_xk3_80141294;
char* D_xk3_80141298;

f32 D_xk3_80136540 = -7000.0f;
s8 D_xk3_80136544 = -1;
u8 D_xk3_80136548 = 0;
u8 D_xk3_8013654C = 0;
s32 D_xk3_80136550 = 0;
s32 D_xk3_80136554 = 0;

void func_xk3_8012B950(void) {
    D_xk3_80140E54 = 0x57;
    D_xk3_80140E58 = 87.0f;
    func_xk1_8002B150(0xA8, 0x57, &D_xk3_80140E50, &D_xk3_80140E54);
}

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

void func_xk3_8012BABC(void) {
    D_xk3_80140E80 = 1.0f;
    D_xk3_80140E84 = 1.0f;
    D_xk3_80140E88 = 0.0f;
    D_xk3_80140E8C = 0.0f;
    func_xk3_8012B99C();
    D_xk3_80140E78 = 0.0f;
    D_xk3_80140E7C = 0.0f;
}

u16 func_xk3_8012BB14(unk_806F2400_unk_00* arg0) {
    u8 i;
    u16 checksum = 0;
    u8* var_v0 = (u8*) arg0;

    for (i = 0; i < 30; i++) {
        checksum += *var_v0++;
    }

    return checksum;
}

extern s32 D_xk3_80136820;
extern u8 D_xk3_80140750[];
extern unk_806F2400_unk_00 D_xk1_800333D0;
extern unk_806F2400_unk_00 D_xk3_801365E0;
extern unk_806F2400 D_806F2400;

void func_xk3_8012BB48(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if (D_806F2400.unk_3C0[i] > 0) {
            if (mfsStrCmp(&D_806F2400.unk_00[i].machineName, &D_xk1_800333D0.machineName) == 0) {
                D_806F2400.unk_00[i] = D_xk1_800333D0;
                D_806F2400.unk_00[i].number = D_xk3_80140750[i];
                break;
            }
        }
    }

    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
    D_xk3_801365E0.checksum = func_xk3_8012BB14(&D_xk3_801365E0);
    func_80768244(MFS_ENTRY_WORKING_DIR, D_xk3_801365E0.machineName, "CARD", &D_xk3_801365E0, sizeof(unk_806F2400_unk_00), 0, 0xFF, true);
}

extern s32 D_xk3_80136820;
extern unk_800E51B8* D_xk3_80140E44;
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
extern s32 D_xk3_80140E50;
extern s32 D_xk3_80140E54;

void func_xk3_8012BD84(void) {

    switch (D_xk3_80136820) {
        case 20:
        case 21:
        case 22:
        case 23: {
            s32 sp34 = D_xk3_80140E68.unk_00;
            s32 sp30 = D_xk3_80140E68.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E68.unk_04 != 8) {
                func_xk1_8002DAE0(&D_xk3_80140E68, 7, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E68.unk_04, 8, 0);
            if ((sp34 != D_xk3_80140E68.unk_00) || (sp30 != D_xk3_80140E68.unk_04)) {
                func_8074122C(0x1E);
            }
            break;
        }
        case 17: {
            s32 sp2C = D_xk3_80140E60.unk_00;
            s32 sp28 = D_xk3_80140E60.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E60.unk_04 != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E60, 6, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E60.unk_04, 3, 0);
            if ((sp2C != D_xk3_80140E60.unk_00) || (sp28 != D_xk3_80140E60.unk_04)) {
                func_8074122C(0x1E);
            }
            break;
        }
        case 35: {
            s32 sp24 = D_xk3_80140E70.unk_00;
            s32 sp20 = D_xk3_80140E70.unk_04;
            func_xk1_8002D86C(0x1B, 6);
            func_xk1_8002D880(0x28);
            if (D_xk3_80140E70.unk_04 != 3) {
                func_xk1_8002DAE0(&D_xk3_80140E70, 4, 1);
            }
            func_xk1_8002DBD4(&D_xk3_80140E70.unk_04, 3, 0);
            if ((sp24 != D_xk3_80140E70.unk_00) || (sp20 != D_xk3_80140E70.unk_04)) {
                func_8074122C(0x1E);
            }
            break;
        }
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
        case 0: {
            s32 sp1C = D_xk3_80136550;
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
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_A) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R) != 0;
        }
        var_a0 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_B) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L) != 0;
        }
        var_a1 = var_v0;
    } else {
        var_a0 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_R;
        var_a1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_L;
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

void func_xk3_8012C408(void) {
    static u8 D_xk3_80136560 = 0;
    static u8 D_xk3_80136564 = 0;
    static u8 D_xk3_80136568 = 0;
    static u8 D_xk3_8013656C = 0;
    static f32 D_xk3_80136570 = 1.0f;
    static f32 D_xk3_80136574 = 1.0f;
    f32 temp_fa0;

    temp_fa0 = (35.0f * D_xk3_80140E80) + 40.0f;

    if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) &&
        (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT)) {
        D_xk3_8013656C = 0;
        D_xk3_80136568 = 0;
    } else {
        if ((gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) &&
            (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN)) {
            D_xk3_80136564 = 0;
            D_xk3_80136560 = 0;
        } else {
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CLEFT) {
                D_xk3_80140E88 -= 0.2f * D_xk3_80136568;
                if (D_xk3_80136568 < 15) {
                    D_xk3_80136568++;
                }
            } else {
                D_xk3_80136568 = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CRIGHT) {
                D_xk3_80140E88 += 0.2f * D_xk3_8013656C;
                if (D_xk3_8013656C < 15) {
                    D_xk3_8013656C++;
                }
            } else {
                D_xk3_8013656C = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CUP) {
                D_xk3_80140E8C -= 0.2f * D_xk3_80136560;
                if (D_xk3_80136560 < 15) {
                    D_xk3_80136560++;
                }
            } else {
                D_xk3_80136560 = 0;
            }
            if (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_CDOWN) {

                D_xk3_80140E8C += 0.2f * D_xk3_80136564;
                if (D_xk3_80136564 < 15) {
                    D_xk3_80136564++;
                }
            } else {
                D_xk3_80136564 = 0;
            }
        }
    }

    D_xk3_80140E88 *= ((35.0f * D_xk3_80140E80) + 40.0f) / ((35.0f * D_xk3_80136570) + 40.0f);
    D_xk3_80140E8C *= ((35.0f * D_xk3_80140E84) + 40.0f) / ((35.0f * D_xk3_80136574) + 40.0f);
    if (D_xk3_80140E88 < -temp_fa0) {
        D_xk3_80140E88 = -temp_fa0;
    } else if (temp_fa0 < D_xk3_80140E88) {
        D_xk3_80140E88 = temp_fa0;
    }
    if (D_xk3_80140E8C < -temp_fa0) {
        D_xk3_80140E8C = -temp_fa0;
    } else if (temp_fa0 < D_xk3_80140E8C) {
        D_xk3_80140E8C = temp_fa0;
    }
    D_xk3_80136570 = D_xk3_80140E80;
    D_xk3_80136574 = D_xk3_80140E84;
}

extern u8 D_xk3_80136548;

void func_xk3_8012C744(void) {
    static u8 D_xk3_80136578 = 0;
    static u8 D_xk3_8013657C = 0;
    static u8 D_xk3_80136580 = 0;
    static u8 D_xk3_80136584 = 0;
    s32 var_v0;
    u16 var_a1;
    u16 var_a2;
    u16 var_a3;
    u16 var_v1;

    if (D_xk3_80136548 != 0) {
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN) != 0;
        if (var_v0 == 0) {
            var_v0 = gControllers[gPlayerControlPorts[0]].stickY <= -50;
        }
        var_a1 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].stickY < 50) ^ 1;
        }
        var_a2 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT) != 0;
        if (var_v0 == 0) {
            var_v0 = (gControllers[gPlayerControlPorts[0]].stickX < 50) ^ 1;
        }
        var_a3 = var_v0;
        var_v0 = (gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT) != 0;
        if (var_v0 == 0) {
            var_v0 = gControllers[gPlayerControlPorts[0]].stickX <= -50;
        }
        var_v1 = var_v0;
    } else {
        var_a1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_DOWN;
        var_a2 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_UP;
        var_a3 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_RIGHT;
        var_v1 = gControllers[gPlayerControlPorts[0]].buttonCurrent & BTN_LEFT;
    }
    if (var_a2 && var_a1) {
        D_xk3_8013657C = 0;
        D_xk3_80136578 = 0;
    } else if (var_v1 && var_a3) {
        D_xk3_80136584 = 0;
        D_xk3_80136580 = 0;
    } else {
        if (var_a2) {
            D_xk3_80140E78 -= 0.1f * D_xk3_80136578;
            if (D_xk3_80136578 < 50) {
                D_xk3_80136578++;
            }
        } else {
            D_xk3_80136578 = 0;
        }
        if (var_a1) {

            D_xk3_80140E78 += 0.1f * D_xk3_8013657C;
            if (D_xk3_8013657C < 50) {
                D_xk3_8013657C++;
            }
        } else {
            D_xk3_8013657C = 0;
        }
        if (var_v1) {
            D_xk3_80140E7C -= 0.1f * D_xk3_80136580;
            if (D_xk3_80136580 < 50) {
                D_xk3_80136580++;
            }
        } else {
            D_xk3_80136580 = 0;
        }
        if (var_a3) {
            D_xk3_80140E7C += 0.1f * D_xk3_80136584;
            if (D_xk3_80136584 < 50) {
                D_xk3_80136584++;
            }
        } else {
            D_xk3_80136584 = 0;
        }
    }
    if (D_xk3_80140E78 > 360.0f) {
        D_xk3_80140E78 -= 360.0f;
    } else if (D_xk3_80140E78 < -360.0f) {
        D_xk3_80140E78 += 360.0f;
    }
    if (D_xk3_80140E7C > 360.0f) {
        D_xk3_80140E7C -= 360.0f;
    } else if (D_xk3_80140E7C < -360.0f) {
        D_xk3_80140E7C += 360.0f;
    }
}

extern unk_800E51B8* D_80140E40;
extern s32 D_xk3_80136820;

void func_xk3_8012CAC8(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        switch (D_xk3_80136820) {
            case 17:
                D_xk3_80140E60.unk_04 = 3;
                D_xk3_80136544 = 20;
                break;
            case 35:
                if (func_80711AC0(D_80140E40, 1) != 0) {
                    D_xk3_80140E70.unk_04 = 3;
                    D_xk3_80136544 = 20;
                }
                break;
            case 20:
            case 21:
            case 22:
            case 23:
                if (func_80711AC0(D_xk3_80140E44, 1) != 0) {
                    D_xk3_80140E68.unk_04 = 8;
                    D_xk3_80136544 = 20;
                }
                break;
            default:
                if (D_xk3_80136548 != 0) {
                    func_8074122C(0x44);
                    D_xk3_80136548 = 0;
                    func_xk1_80026908(1);
                } else if (D_xk3_80136820 == 0) {
                    func_8074122C(0x44);
                    D_xk3_80136548 = 1;
                    func_xk1_80026908(0);
                }
                break;
        }
    }
}

extern volatile unk_807C6EA8 D_807C6EA8;

void func_xk3_8012CC10(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        switch (D_xk3_80136820) {
            case 1:
            case 2:
            case 18:
            case 19:
                switch (D_xk3_80136820) {
                    case 18:
                    case 19:
                        D_xk1_800333D0 = D_xk3_801365E0;
                        break;
                    default:
                        break;
                }
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                func_xk1_80027B74(&D_xk1_80031E50);
                break;
            case 17:
            case 35:
                if (D_xk3_80136820 == 0x23) {
                    func_807113DC(D_80140E40);
                }
                D_xk1_800333D0 = D_xk3_801365E0;
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                func_8074122C(0x25);
                break;
            case 20:
            case 21:
            case 22:
            case 23:
                D_xk1_800333D0 = D_xk3_801365E0;
                func_xk3_8012BC98();
                func_8074122C(0x25);
                break;
            case 36:
                func_8074122C(0x25);
                D_807C6EA8.unk_08 = 0;
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            case 6:
            case 11:
            case 16:
            case 29:
            case 32:
            case 33:
            case 37:
                func_8074122C(0x25);
                D_807C6EA8.unk_08 = 0;
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            case 4:
            case 5:
            case 15:
            case 25:
            case 26:
            case 30:
            case 31:
                func_8074122C(0x25);
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                func_xk1_8002BD34();
                break;
            default:
                break;
        }
    }
}

extern const char* D_xk3_801366F4[];
extern u8 D_xk1_800333F0;
extern u8 D_xk3_80137160;
extern u8 D_800333F4;

void func_xk3_8012CE44(void) {
    u8 pad;

    if ((((D_xk3_80136820 != 0) && (D_xk3_80136820 != 2)) ||
         ((func_80711AC0(D_80140E40, 0) == 0) && (func_80711AC0(D_xk3_80140E44, 0) == 0))) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        if (D_xk1_80032C20 == 0) {
            switch (D_xk3_80136820) {
                case 6:
                case 11:
                case 16:
                case 29:
                case 32:
                case 33:
                case 37:
                    func_8074122C(0x25);
                    D_807C6EA8.unk_08 = 0;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    D_xk3_80136820 = 0;
                    return;
                default:
                    break;
            }
        }

        switch (D_xk3_80136820) {
            case 0:
            case 1:
            case 2:
            case 18:
            case 19:
                if ((D_xk1_800333F0 != 0) && (D_xk3_80136550 < 3)) {
                    D_807C6EA8.unk_08 = 0x16;
                    PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                    D_xk3_80136820 = 0x24;
                    func_8074122C(0x20);
                } else {
                    func_xk1_80027DC8(&D_xk1_80031E50, &D_xk3_80140E50, &D_xk3_80140E54);
                    D_xk3_80140E58 = D_xk3_80140E54;
                }
                break;
            case 17:
                switch (D_xk3_80140E60.unk_04) {
                    case 0:
                        if (D_xk3_80140E60.unk_00 != D_xk1_800333D0.frontType) {
                            D_xk1_800333D0.frontType = D_xk3_80140E60.unk_00;
                            func_8074122C(0x27);
                        }
                        break;
                    case 1:
                        if (D_xk3_80140E60.unk_00 != D_xk1_800333D0.rearType) {
                            D_xk1_800333D0.rearType = D_xk3_80140E60.unk_00;
                            func_8074122C(0x27);
                        }
                        break;
                    case 2:
                        if (D_xk3_80140E60.unk_00 != D_xk1_800333D0.wingType) {
                            D_xk1_800333D0.wingType = D_xk3_80140E60.unk_00;
                            func_8074122C(0x27);
                        }
                        break;
                    case 3:
                        PRINTF("WORKS MACHINE MODE : 0\n");
                        D_xk3_80136820 = 0;
                        func_8074122C(0x24);
                        break;
                }
                break;
            case 35:
                func_xk3_8013571C();
                break;
            case 20:
                func_xk3_80135E58(&D_xk1_800333D0.red, &D_xk1_800333D0.green, &D_xk1_800333D0.blue);
                break;
            case 21:
                func_xk3_80135E58(&D_xk1_800333D0.decalR, &D_xk1_800333D0.decalG, &D_xk1_800333D0.decalB);
                break;
            case 22:
                func_xk3_80135E58(&D_xk1_800333D0.numberR, &D_xk1_800333D0.numberG, &D_xk1_800333D0.numberB);
                break;
            case 23:
                func_xk3_80135E58(&D_xk1_800333D0.cockpitR, &D_xk1_800333D0.cockpitG, &D_xk1_800333D0.cockpitB);
                break;
            case 4:
                func_8074122C(0x24);
                if (func_xk1_8002BD14() == 0) {
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    D_xk3_80136820 = 0;
                    func_xk1_8002FFDC();
                    D_xk1_800333F0 = 0;
                } else if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 1)) {
                    PRINTF("WORKS MACHINE MODE : LOAD_SELECT_SUPER\n");
                    D_xk3_80136820 = 5;
                    func_xk3_801360B8();
                    func_xk3_8012B950();
                } else {
                    PRINTF("WORKS MACHINE MODE : LOAD_CONFIRM\n");
                    D_xk3_80136820 = 6;
                    D_xk3_80141298 = func_xk1_8002BCC4();
                }
                break;
            case 30:
                if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 0)) {
                    func_8074122C(0x24);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_SUPER\n");
                    D_xk3_80136820 = 0x1F;
                    func_xk3_80136320();
                } else {
                    D_xk3_80141298 = func_xk1_8002BCC4();
                    func_8074122C(0x24);
                    PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_CONFIRM\n");
                    D_xk3_80136820 = 0x20;
                }
                break;
            case 32: {
                u8 i;
                func_8074122C(0x27);
                if (mfsStrCmp(D_xk3_80141298, &D_xk1_800333D0.machineName) == 0) {
                    D_xk1_800333D0.number = 31;
                }
                for (i = 0; i < 30; i++) {
                    if ((D_806F2400.unk_3C0[i] > 0) &&
                        (mfsStrCmp(&D_806F2400.unk_00[i].machineName, D_xk3_80141298) == 0)) {
                        D_806F2400.unk_3C0[i] = 0;
                        D_806F2400.unk_00[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            }
            case 31:
                D_xk3_80141298 = func_xk1_8002BCC4();
                func_8074122C(0x24);
                PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SUPER_CONFIRM\n");
                D_xk3_80136820 = 0x21;
                break;
            case 33: {
                u8 i;
                func_8074122C(0x27);

                for (i = 0; i < 30; i++) {
                    if ((D_806F2400.unk_3C0[i] == -1) && (mfsStrCmp(D_xk3_80141298, D_xk3_801366F4[i]) == 0)) {
                        D_806F2400.unk_3C0[i] = 0;
                        D_806F2400.unk_00[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }

                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            }
            case 25:
                func_8074122C(0x24);
                if ((D_xk3_80137160 != 0) && (func_xk1_8002BD14() == 0)) {
                    PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_SUPER\n");
                    D_xk3_80136820 = 0x1A;
                    func_xk3_801360B8();
                } else {
                    D_xk3_80141298 = func_xk1_8002BCC4();
                    PRINTF("WORKS MACHINE MODE : ENTRY_LOAD_NOW\n");
                    D_xk3_80136820 = 0x1B;
                    func_80768638(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", &D_xk3_801365E0, sizeof(unk_806F2400_unk_00));
                    PRINTF("SUPER MACHINE No.%d\n");
                }
                break;
            case 5:
            case 26: {
                u8 i;
                if (D_xk3_80136820 == 0x1A) {
                    D_xk3_80141291 = D_800333F4;
                }
                func_8074122C(0x24);
                D_xk3_80141298 = func_xk1_8002BCC4();

                for (i = 0; i < 30; i++) {
                    if (mfsStrCmp(D_xk3_80141298, D_xk3_801366F4[i]) == 0) {
                        D_800333F4 = i;
                        break;
                    }
                }

                if (D_xk3_80136820 == 0x1A) {
                    D_xk3_80141270 = D_xk1_800333D0;
                    D_xk3_80141290 = D_xk1_800333F0;
                    D_xk1_800333F0 = 1;
                    PRINTF("WORKS MACHINE MODE : ENTRY\n");
                    D_xk3_80136820 = 0x1C;
                    func_xk3_80132F50();
                } else {
                    D_xk1_800333F0 = 1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    D_xk3_80136820 = 0;
                }
                break;
            }
            case 15:
                func_8074122C(0x24);
                PRINTF("WORKS MACHINE MODE : DELETE_CONFIRM\n");
                D_xk3_80136820 = 0x10;
                D_xk3_80141298 = func_xk1_8002BCC4();
                break;
            case 6:
                func_8074122C(0x24);
                PRINTF("WORKS MACHINE MODE : LOAD_NOW\n");
                D_xk3_80136820 = 7;
                func_80768574(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", &D_xk3_801365E0, sizeof(unk_806F2400_unk_00));
                break;
            case 16:
            case 37: {
                u8 i;
                if (mfsStrCmp(D_xk3_80141298, &D_xk1_800333D0.machineName) == 0) {
                    D_xk1_800333D0.number = 31;
                }

                for (i = 0; i < 30; i++) {
                    if ((D_806F2400.unk_3C0[i] > 0) &&
                        (mfsStrCmp(D_806F2400.unk_00[i].machineName, D_xk3_80141298) == 0)) {
                        D_806F2400.unk_3C0[i] = 0;
                        D_806F2400.unk_00[i].number = 31;
                        func_8071E0C0();
                        break;
                    }
                }

                func_8074122C(0x24);
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                func_807688D0(MFS_ENTRY_WORKING_DIR, D_xk3_80141298, "CARD", true);
                break;
            }
            case 11:
                func_8074122C(0x24);
                PRINTF("WORKS MACHINE MODE : OVERWRITE_GET_FILE\n");
                D_xk3_80136820 = 0xD;
                func_807687E0(0, "CARD");
                break;
            case 29:
                func_xk1_8002FC70();
                D_807C6EA8.unk_08 = 0;
                func_8074122C(5);
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            case 36:
                D_807C6EA8.unk_08 = 0;
                func_8074122C(0x25);
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            default:
                break;
        }
    }
}

void func_xk3_8012D700(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        if ((D_806F2400.unk_3C0[i] > 0) &&
            (mfsStrCmp(D_806F2400.unk_00[i].machineName, D_xk1_800333D0.machineName) == 0)) {
            D_xk1_800333D0.number = D_xk3_80140750[i];
            return;
        }
    }
    D_xk1_800333D0.number = 31;
}

extern volatile u8 D_80794E20;
extern volatile s32 D_807C6F0C;

void func_xk3_8012D79C(void) {
    u16 checksum;
    u8 i;

    switch (D_xk3_80136820) {
        case 7:
        case 27:
            checksum = func_xk3_8012BB14(&D_xk3_801365E0);
            if ((D_xk3_801365E0.checksum != checksum) || (checksum == 0) || (func_xk3_80135850(&D_xk3_801365E0) != 0)) {
                D_807C6EA8.unk_08 = 0x15;
                PRINTF("WORKS MACHINE MODE : CHECKSUM_ERROR\n");
                D_xk3_80136820 = 0x25;
            } else if (D_xk3_80136820 == 0x1B) {
                D_xk3_80141270 = D_xk1_800333D0;
                D_xk3_80141290 = D_xk1_800333F0;
                D_xk3_80141291 = D_800333F4;
                D_xk1_800333F0 = 0;
                D_xk1_800333D0 = D_xk3_801365E0;
                D_xk3_80140E90 = D_806F2400;

                for (i = 0; i < 30; i++) {
                    if ((D_806F2400.unk_3C0[i] > 0) &&
                        (mfsStrCmp(D_806F2400.unk_00[i].machineName, D_xk1_800333D0.machineName) == 0)) {
                        D_806F2400.unk_3C0[i] = 1;
                        break;
                    }
                }
                PRINTF("WORKS MACHINE MODE : ENTRY\n");
                D_xk3_80136820 = 0x1C;
                func_xk3_80132F50();
            } else {
                D_xk1_800333D0 = D_xk3_801365E0;
                func_xk3_8012D700();
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                D_xk1_800333F0 = 0;
            }
            break;
        case 3:
        case 24:
            if (D_807C6F0C == 0) {
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
                break;
            }
            if (D_xk3_80136820 == 0x18) {
                PRINTF("WORKS MACHINE MODE : ENTRY_SELECT_FILE\n");
                D_xk3_80136820 = 0x19;
            } else {
                PRINTF("WORKS MACHINE MODE : LOAD_SELECT_FILE\n");
                D_xk3_80136820 = 4;
            }
            func_xk3_8012B950();
            break;
        case 14:
            if (D_807C6F0C == 0) {
                PRINTF("WORKS MACHINE MODE : 0\n");
                D_xk3_80136820 = 0;
            } else {
                PRINTF("WORKS MACHINE MODE : DELETE_SELECT_FILE\n");
                D_xk3_80136820 = 0xF;
                func_xk3_8012B950();
            }
            break;
        case 9:
            if (D_80794E20 == 1) {
                D_807C6EA8.unk_08 = 0x12;
                PRINTF("WORKS MACHINE MODE : OVERWRITE_CONFIRM\n");
                D_xk3_80136820 = 0xB;
            } else {
                PRINTF("WORKS MACHINE MODE : SAVE_GET_FILE\n");
                D_xk3_80136820 = 0xA;
                func_807687E0(0, "CARD");
            }
            break;
        case 10:
            if (D_807C6F0C >= 100) {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                D_xk3_80136820 = 0x24;
            } else {
                func_xk3_8012BB48();
            }
            break;
        case 13:
            if (D_807C6F0C == 100) {
                PRINTF("WORKS MACHINE MODE : OVERWRITE_FILE_EXIST\n");
                D_xk3_80136820 = 0xC;
                func_8076870C(MFS_ENTRY_WORKING_DIR, D_xk1_800333D0.machineName, "CARD");
            } else if (D_807C6F0C > 100) {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                D_xk3_80136820 = 0x24;
            } else {
                func_xk3_8012BB48();
            }
            break;
        case 12:
            if (D_80794E20 == 1) {
                func_xk3_8012BB48();
            } else {
                D_807C6EA8.unk_08 = 0x13;
                PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
                D_xk3_80136820 = 0x24;
            }
            break;
        default:
            break;
    }
}

s32 D_xk3_80136588[] = {
    270, 290, 320, 350, 420, 580, 630,  // MACHINE_PART_FRONT
    510, 560, 630, 720, 890, 930, 1170, // MACHINE_PART_REAR
    0,   100, 120, 140, 190, 250, 420,  // MACHINE_PART_WING
};

void func_xk3_8012DBFC(void) {

    if (D_xk3_80136820 == 0x1C) {
        return;
    }
    if ((D_xk3_80136820 == 0x11) && (D_xk3_80136540 < 7000.0f)) {
        D_xk3_80136540 += 300.0f;
    }
    if ((D_xk3_80136550 == 5) && (D_xk3_80136548 == 0)) {
        D_xk3_8013654C = 1;
    } else {
        D_xk3_8013654C = 0;
    }
    if (D_xk1_800333F0 != 0) {
        return;
    }
    D_xk3_80141294 = D_xk3_80136588[D_xk1_800333D0.frontType] + D_xk3_80136588[D_xk1_800333D0.rearType + 7] +
                     D_xk3_80136588[D_xk1_800333D0.wingType + 14];
    switch (D_xk3_80136820) {
        case 18:
            D_xk1_800333D0.decal = MACHINE_DECAL((D_xk3_80140E54 - 0x34) / 16);
            break;
        case 19:
            D_xk1_800333D0.logo = MACHINE_LOGO((D_xk3_80140E54 - 0x34) / 16);
            break;
    }
    if ((D_xk3_80136820 == 0x23) && (func_80711AC0(D_80140E40, 1) != 0)) {
        D_807C6EA8.unk_08 = 0;
    }
    switch (D_xk3_80136820) {
        case 17:
            if ((D_xk3_80140E60.unk_04 == 3) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    D_xk3_80136820 = 0;
                    func_8074122C(0x24);
                } else {
                    D_xk3_80136544--;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        case 35:
            if ((D_xk3_80140E70.unk_04 == 3) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    PRINTF("WORKS MACHINE MODE : 0\n");
                    D_xk3_80136820 = 0;
                    func_8074122C(0x24);
                    func_807113DC(D_80140E40);
                } else {
                    D_xk3_80136544 -= 1;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        case 20:
        case 21:
        case 22:
        case 23:
            if ((D_xk3_80140E68.unk_04 == 8) && (D_xk3_80136544 >= 0)) {
                if (D_xk3_80136544 == 0) {
                    D_xk3_80136544 = -1;
                    func_xk3_8012BC98();
                    func_8074122C(0x24);
                } else {
                    D_xk3_80136544 -= 1;
                }
            } else {
                D_xk3_80136544 = -1;
            }
            break;
        default:
            D_xk3_80136544 = -1;
            break;
    }
}

extern s32 D_800BEE14;
extern volatile u8 D_80794E14;

s32 func_xk3_8012DF04(void) {

    func_xk1_800260E4();
    if (D_xk3_80136820 == 8) {
        PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST\n");
        D_xk3_80136820 = 9;
        func_8076869C(MFS_ENTRY_WORKING_DIR, D_xk1_800333D0.machineName, "CARD");
    }
    func_xk1_8002D974();
    if ((D_80794E14 == 0) && (D_800BEE14 == 0) && (D_xk3_80136548 == 0)) {
        func_xk3_8012BD84();
    }
    if (D_xk3_80136820 != 0x11) {
        func_xk3_8012C1C8();
        func_xk3_8012C408();
        func_xk3_8012B99C();
    }
    func_xk3_8012C744();
    if (D_xk3_80136820 != 0x22) {
        if (D_800BEE14 == 0) {
            func_xk3_8012CAC8();
        }
        if ((D_80794E14 == 0) && (D_800BEE14 == 0) && (D_xk3_80136548 == 0) &&
            (!(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) ||
             !(gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B))) {
            func_xk3_8012CC10();
            func_xk3_8012CE44();
        }
    } else {
        func_xk1_80029AB4(0, 0);
    }
    if (D_80794E14 == 0) {
        func_xk3_8012D79C();
        func_xk3_8012DBFC();
    }
    if ((D_xk3_8013654C != 0) && (D_80794E14 == 0) && (D_xk3_80136548 == 0) &&
        (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A)) {
        return 1;
    }
    return 0;
}
