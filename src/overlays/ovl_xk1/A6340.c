#include "global.h"
#include "fzx_game.h"
#include "fzx_assets.h"

s32 D_xk1_80032AC0 = 0;
s32 D_xk1_80032AC4 = 1;
s32 D_xk1_80032AC8 = 0;
u32 D_xk1_80032ACC = -1;
s32 D_xk1_80032AD0 = 0;

char D_xk1_80032AD4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,'& 0123456789";
UNUSED s32 D_xk1_80032B00 = 0x202D;

char* func_xk1_800290D0(char* buffer, const char* fmt, size_t size) {
    return (char*) memcpy(buffer, fmt, size) + size;
}

extern Gfx D_7020850[];
extern Gfx D_7020890[];
extern Gfx D_70208D0[];

Gfx* func_xk1_800290F4(Gfx* gfx, s32 arg1, s32 arg2, u32 arg3) {

    D_xk1_80032ACC = arg3 / 96;
    switch (arg3 / 96) {
        case 0:
            gSPDisplayList(gfx++, D_7020850);
            break;
        case 1:
            arg3 -= 0x60;
            gSPDisplayList(gfx++, D_7020890);
            break;
        case 2:
            arg3 -= 0xC0;
            gSPDisplayList(gfx++, D_70208D0);
            break;
    }
    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 8) << 2, (arg2 + 8) << 2, 0, ((arg3 % 16) * 8) << 5,
                        ((arg3 / 16) * 8) << 5, 1 << 10, 1 << 10);

    return gfx;
}

s32 func_xk1_80029218(s32 arg0) {
    if (arg0 < 0x80) {
        return arg0 - 0x20;
    }
    if (D_xk1_80032AD0 == 0) {
        return arg0 - 0x20;
    }
    return arg0 + 0x40;
}

Gfx* func_xk1_8002924C(Gfx* gfx, s32 xPos, s32 yPos, const char* fmt, ...) {
    s32 charRemaining;
    u8* charPtr;
    char buffer[0x100];
    s32 charIndex;
    va_list args;
    va_start(args, fmt);

    D_xk1_80032ACC = -1;
    charRemaining = _Printf(func_xk1_800290D0, buffer, fmt, args);

    if (charRemaining > 0) {
        charPtr = (s8*) buffer;
        while (charRemaining > 0) {
            if (*charPtr == 1) {
                D_xk1_80032AD0 = 0;
            } else if (*charPtr == 2) {
                D_xk1_80032AD0 = 1;
            } else {
                gfx = func_xk1_800290F4(gfx, xPos, yPos, func_xk1_80029218(*charPtr));
                xPos += 8;
            }
            charRemaining--;
            charPtr++;
        }
    }
    va_end(args);

    return gfx;
}

void func_xk1_80029350(s32 arg0) {
    D_xk1_80032AC4 = arg0;
}

void func_xk1_8002935C(u8 arg0, s32* arg1, s32* arg2) {
    s32 sp4;
    s32 sp0;
    s32 temp_a1;

    switch (arg0) {
        case ' ':
            sp4 = 6;
            sp0 = 4;
            break;
        case ',':
            sp4 = 6;
            sp0 = 2;
            break;
        case '.':
            sp4 = 7;
            sp0 = 2;
            break;
        case '&':
            sp4 = 8;
            sp0 = 2;
            break;
        case '\'':
            sp4 = 7;
            sp0 = 2;
            break;
        case '-':
            sp4 = 7;
            sp0 = 4;
            break;
        case '\0':
            sp4 = 9;
            sp0 = 4;
            break;
    }

    if ((arg0 >= '0') && (arg0 <= '9')) {
        sp4 = arg0 - '0';
        sp0 = 3;
    }
    if ((arg0 >= 'A') && (arg0 <= 'Z')) {
        temp_a1 = arg0 - 'A';
        sp4 = temp_a1 % 10;
        sp0 = temp_a1 / 10;
    }
    *arg1 = sp4;
    *arg2 = sp0;
}

extern u8 D_xk1_8003A560[];

void func_xk1_800294AC(void) {
    s32 i;

    D_xk1_80032AC0 = 0;

    for (i = 0; i < 9; i++) {
        D_xk1_8003A560[i] = 0;
    }
}

extern s32 D_xk1_8003A550;
extern s32 D_xk1_8003A554;
extern s32 D_xk1_8003A5BC;
extern s32 D_xk1_8003A5C0;
extern void (*D_xk1_8003A5C4)(void);

void func_xk1_800294EC(void (*arg0)(void)) {
    D_xk1_8003A5BC = 0;
    D_xk1_8003A5C0 = 0;
    D_xk1_80032AC8 = 1;
    D_xk1_8003A5C4 = arg0;
    D_xk1_80032AC0 = 0;
    D_xk1_8003A550 = 0x58;
    D_xk1_8003A554 = 0x58;
    while (true) {
        if (D_xk1_8003A560[D_xk1_80032AC0] == 0) {
            break;
        }
        D_xk1_80032AC0++;
    }
}

extern unk_8003A5D8 D_xk1_8003A5D8[];
extern s32 D_80119880;

s32 func_xk1_80029560(void) {
    s32 var_s1;

    var_s1 = 0;
    if ((D_80119880 == -1) || ((D_80119880 != 3) && (D_80119880 == 9))) {
        var_s1 = 1;
    }
    while (var_s1 < func_xk1_8002BFA4()) {
        if (Leo_strcmp(D_xk1_8003A5D8[var_s1].unk_00, D_xk1_8003A560) == 0) {
            return 1;
        }
        var_s1++;
    }

    return 0;
}

void func_xk1_8002961C(void) {
    if ((D_xk1_80032AC0 != 0) && (D_xk1_8003A5C4 != NULL)) {
        D_xk1_8003A5C4();
    }
}

void func_xk1_80029658(void) {
    s32 var_a0;
    s32 var_v1;
    u8* var_v0;
    u8 sp1B;

    // TODO: move to appropriate section
    PRINTF("MOJI %d,%d\n");
    PRINTF("NAMEINPUTc\n");
    PRINTF("GET_FILE_NAMES_START\n");

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        if (D_xk1_80032AC0 >= 9) {
            func_8074122C(0x20);
            return;
        }
        var_v1 = D_xk1_8003A5BC;
        var_a0 = D_xk1_8003A5C0;
        sp1B = D_xk1_80032AD4[var_a0 * 10 + var_v1];
        if ((sp1B != 0) && (D_xk1_80032AC0 >= 8)) {
            func_8074122C(0x20);
            return;
        }

        if (sp1B == 0) {
            if (D_xk1_80032AC0 == 0) {
                func_8074122C(0x20);
            } else {
                func_8074122C(0x21);
                D_xk1_8003A560[D_xk1_80032AC0] = sp1B;
                var_v0 = &D_xk1_8003A560[D_xk1_80032AC0];
                var_v0--;
                while (*var_v0 == 0x20) {
                    *var_v0-- = 0;
                    D_xk1_80032AC0--;
                }
                func_xk1_8002961C();
                D_xk1_80032AC0++;
            }
        } else if ((D_xk1_80032AC0 == 0) && (sp1B == 0x20)) {
            func_8074122C(0x20);
        } else {
            func_8074122C(0x27);
            D_xk1_8003A560[D_xk1_80032AC0] = sp1B;
            D_xk1_80032AC0++;
        }
        if (D_xk1_80032AC0 >= 8) {
            D_xk1_8003A5BC = 9;
            D_xk1_8003A5C0 = 4;
        }
    }
}

void func_xk1_80029830(void) {
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_START) {
        D_xk1_8003A5BC = 9;
        D_xk1_8003A5C0 = 4;
    }
}

extern s32 D_xk1_80030610;

void func_xk1_80029884(void) {

    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        func_8074122C(0x25);
        if (D_xk1_80032AC0 != 0) {
            D_xk1_80032AC0--;
            D_xk1_8003A560[D_xk1_80032AC0] = 0;
            return;
        }
        if (D_xk1_8003A5C4 != NULL) {
            D_xk1_8003A5C4();
        }
        D_xk1_80030610 = -1;
    }
}

void func_xk1_80029924(void) {
    if (D_xk1_8003A5C0 != 4) {
        func_8074122C(0x23);
        return;
    }
    if ((D_xk1_8003A5BC >= 6) && (D_xk1_8003A5BC < 9)) {
        func_8074122C(0x23);
    }
}

void func_xk1_80029980(void) {
    s32 sp1C;
    Controller* controller;
    s32 stickXMag;
    s32 stickYMag;

    controller = &gControllers[gPlayerControlPorts[0]];

    stickXMag = ABS(controller->stickX);
    stickYMag = ABS(controller->stickY);

    if (stickYMag < stickXMag) {
        sp1C = D_xk1_8003A5BC;
        func_xk1_8002DAE0(&D_xk1_8003A5BC, 9, 1);
        if (sp1C != D_xk1_8003A5BC) {
            func_xk1_80029924();
        }
    } else {
        sp1C = D_xk1_8003A5C0;
        func_xk1_8002DBD4(&D_xk1_8003A5C0, 4, 0);
        if (sp1C != D_xk1_8003A5C0) {
            func_8074122C(0x23);
        }
    }
    if (D_xk1_8003A5C0 == 4) {
        if (D_xk1_8003A5BC < 6) {
            D_xk1_8003A5BC = 6;
        }
        if (D_xk1_8003A5BC > 8) {
            D_xk1_8003A5BC = 8;
        }
    }
}

void func_xk1_80029AB4(s32 arg0, s32 arg1) {
    if (D_xk1_80032AC8 != 0) {
        D_xk1_80032AC8 = 0;
        return;
    }
    func_xk1_80029830();
    func_xk1_80029980();
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_A) {
        func_xk1_80029658();
    } else {
        func_xk1_80029884();
    }
}

typedef struct unk_80128C94 {
    s8 unk_0000[0x53A0];
    Vtx unk_53A0[0x30];
    Vtx unk_56A0[0x30];
    s8 unk_59A0[0xC00];
    Vtx unk_65A0[0x800];
    Vtx unk_E5A0[0x80];
    s8 unk_EDA0[0x400];
    Mtx unk_F1A0[0x1];
    s8 pad_F1E0[0x1EE8];
    Gfx unk_110C8[1];
} unk_80128C94;

extern unk_80128C94* D_80128C94;

extern Gfx D_3000510[];
extern Gfx D_60110C8[];
extern u8 D_700B480[];
extern u8 D_700B520[];
extern u8 D_700FF80[];

extern u32 gGameFrameCount;
extern s32 gGameMode;

Gfx* func_xk1_80029B48(Gfx* gfx, s32 arg1, s32 arg2) {
    Gfx* var_v0;
    s32 sp208;
    s32 sp204;
    u8 var_a0;
    s32 i;

    sp208 = D_xk1_8003A5BC;
    if (D_xk1_8003A5C0 < 5) {
        var_a0 = D_xk1_80032AD4[D_xk1_8003A5C0 * 10 + sp208];
        sp204 = D_xk1_8003A5C0;
    } else {
        sp204 = D_xk1_8003A5C0;
        var_a0 = 0;
    }

    gSPDisplayList(gfx++, D_8014940);
    gSPDisplayList(gfx++, D_3000510);
    gDPSetPrimColor(gfx++, 0, 0, 128, 128, 255, 255);

    gSPTextureRectangle(gfx++, 78 << 2, 78 << 2, 242 << 2, 80 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, 78 << 2, 200 << 2, 242 << 2, 202 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, 78 << 2, 80 << 2, 80 << 2, 200 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gSPTextureRectangle(gfx++, 240 << 2, 80 << 2, 242 << 2, 200 << 2, 0, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 200);
    gSPTextureRectangle(gfx++, 80 << 2, 80 << 2, 240 << 2, 200 << 2, 0, 0, 0, 1 << 10, 1 << 10);

    if (var_a0 != 0) {
        gDPPipeSync(gfx++);
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        gSPTextureRectangle(gfx++, ((sp208 * 0x10) + 0x50) << 2, ((sp204 * 0x10) + 0x50) << 2,
                            ((sp208 * 0x10) + 0x60) << 2, ((sp204 * 0x10) + 0x60) << 2, 0, 0, 0, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gDPSetTextureConvert(gfx++, G_TC_FILT);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(gfx++, D_700FF80);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetAlphaCompare(gfx++, G_AC_NONE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    if (gGameMode == GAMEMODE_COURSE_EDIT) {
        var_v0 = D_80128C94->unk_110C8;
        for (i = 0; i < 120; i++) {
            gDPLoadTextureBlock(var_v0++, D_700B480 + i * 160, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 1, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(var_v0++, 80 << 2, (i + 0x50) << 2, 240 << 2, (i + 0x51) << 2, 0, 0, 0, 1 << 10,
                                1 << 10);
        }
        gSPEndDisplayList(var_v0++);
        gSPDisplayList(gfx++, D_60110C8);
    } else {
        for (i = 0; i < 120; i++) {
            gDPLoadTextureBlock(gfx++, D_700B480 + i * 160, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 1, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, 80 << 2, (i + 0x50) << 2, 240 << 2, (i + 0x51) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
    }
    gDPPipeSync(gfx++);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    for (i = 0; i < 8; i++) {
        var_a0 = D_xk1_8003A560[i];
        if (var_a0 == 0) {
            continue;
        }

        func_xk1_8002935C(var_a0, &sp208, &sp204);
        gDPPipeSync(gfx++);

        gDPLoadTextureTile(gfx++, D_700B480, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 1, sp208 * 16, sp204 * 16,
                           (sp208 * 16) + 15, (sp204 * 16) + 15, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, ((i * 16) + 0x6F) << 2, 176 << 2, ((i * 16) + 0x7E) << 2, 191 << 2, 0,
                            (sp208 * 16) << 5, (sp204 * 16) << 5, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);

    if ((gGameFrameCount % (6 / D_xk1_80032AC4)) < (3 / D_xk1_80032AC4)) {
        gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    } else {
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
    }
    if (D_xk1_80032AC0 < 8) {
        gDPLoadTextureTile(gfx++, D_700B480, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 1, (D_xk1_80032AC0 * 16) + 0x1F, 96,
                           (D_xk1_80032AC0 * 16) + 0x2F, 116, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gfx++, ((D_xk1_80032AC0 * 0x10) + 0x6F) << 2, 176 << 2,
                            ((D_xk1_80032AC0 * 0x10) + 0x7F) << 2, 196 << 2, 0, ((D_xk1_80032AC0 * 0x10) + 0x1F) << 5,
                            96 << 5, 1 << 10, 1 << 10);
    }
    gDPPipeSync(gfx++);
    gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);

    if (((D_xk1_8003A5BC == 8) || (D_xk1_8003A5BC == 9)) && (D_xk1_8003A5C0 == 4)) {
        if ((gGameFrameCount % (6 / D_xk1_80032AC4)) < (3 / D_xk1_80032AC4)) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        }
    } else {
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }

    gDPLoadTextureTile(gfx++, D_700B480, G_IM_FMT_CI, G_IM_SIZ_8b, 160, 1, 128, 64, 160, 84, 0,
                       G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                       G_TX_NOLOD);

    gSPTextureRectangle(gfx++, 208 << 2, 144 << 2, 240 << 2, 164 << 2, 0, 128 << 5, 64 << 5, 1 << 10, 1 << 10);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    return gfx;
}

extern s32 D_800D6CA0[];

void func_xk1_8002AC24(void) {
    if (D_xk1_80032AC0 == 0) {
        D_800D6CA0[2] = 0;
    } else {
        D_800D6CA0[2] = 0x34;
        func_8076877C(1, "CRSD");
    }
}

extern u8 D_xk1_8003A570[];
extern u8 D_xk1_8003A598[];
extern u8 D_xk1_8003A5B5[];
extern s32 D_xk1_80032C20;
extern s32 D_xk2_80104378;

void func_xk1_8002AC70(void) {

    // TODO: move to appropriate section
    PRINTF("SAME FILENAME!!\n");
    PRINTF("NEW FILE SAVE FAILD\n");
    PRINTF("SAME_FILE_NAME!! UWAGAKI\n");

    if (func_xk1_80029560() != 0) {
        switch (D_80119880) {
            case -1:
            case 9:
                D_xk2_80104378 = 4;
                D_xk1_80032C20 = 0;
                D_800D6CA0[2] = 0x10;
                D_xk1_80030610 = -1;
                return;
            case 1:
                break;
            default:
                D_xk2_80104378 = 5;
                D_xk1_80032C20 = 0;
                D_800D6CA0[2] = 0x10;
                D_xk1_80030610 = -1;
                return;
        }
    }

    switch (D_80119880) {
        case -1:
            if (func_xk2_800EAA1C(D_xk1_8003A560) != 0) {
                D_xk1_80030610 = -1;
            } else {
                D_xk1_80030610 = -1;
            }
            return;
        case 1:
            Leo_strcpy(D_xk1_8003A560, D_xk1_8003A570);
            if ((func_xk1_80029560() == 0) && ((func_xk1_8002BFA4() - 1) >= 100)) {
                D_80119880 = -2;
                D_xk2_80104378 = 6;
                D_xk1_80032C20 = 0;
                D_800D6CA0[2] = 0x10;
            } else if (func_xk2_800EAA1C(D_xk1_8003A570) != 0) {
                D_xk1_80030610 = -1;
            } else {
                D_xk1_80030610 = -1;
            }
            return;
        case 9:
            if ((func_xk1_8002BFA4() - 1) >= 100) {
                D_xk2_80104378 = 6;
                D_xk1_80032C20 = 0;
                D_800D6CA0[2] = 0x10;
            } else {
                func_xk2_800EAC28(D_xk1_8003A560);
                D_xk1_80030610 = -1;
            }
            return;
        case 3:
            func_xk2_800EBFE8(D_xk1_8003A598);
            func_80768844(0xFFFB, D_xk1_8003A598, D_xk1_8003A5B5, D_xk1_8003A560, D_xk1_8003A5B5, 1);
            D_xk1_80030610 = -1;
            D_800D6CA0[2] = 0x22;
            return;
    }
    D_800D6CA0[2] = 0;
}

void func_xk1_8002AEB4(s32 arg0, s32 arg1) {
    D_xk1_8003A5BC = arg0;
    D_xk1_8003A5C0 = arg1;
}
