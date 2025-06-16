#include "global.h"

char* func_xk1_800290D0(char* buffer, const char* fmt, size_t size) {
    return (char*) memcpy(buffer, fmt, size) + size;
}

extern Gfx D_7020850[];
extern Gfx D_7020890[];
extern Gfx D_70208D0[];
extern u32 D_xk1_80032ACC;

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
    gSPTextureRectangle(gfx++, arg1 << 2, arg2 << 2, (arg1 + 8) << 2, (arg2 + 8) << 2, 0, ((arg3 % 16) * 8) << 5, ((arg3 / 16) * 8) << 5, 1 << 10, 1 << 10);

    return gfx;
}

extern s32 D_xk1_80032AD0;

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

extern s32 D_xk1_80032AC4;

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

extern s32 D_xk1_80032AC0;
extern u8 D_xk1_8003A560[];

void func_xk1_800294AC(void) {
    s32 i;

    D_xk1_80032AC0 = 0;

    for (i = 0; i < 9; i++) {
        D_xk1_8003A560[i] = 0;
    }
}

extern s32 D_xk1_80032AC8;
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

extern u8 D_xk1_8003A5D8[][0x24];
extern s32 D_80119880;

s32 func_xk1_80029560(void) {
    s32 var_s1;

    var_s1 = 0;
    if ((D_80119880 == -1) || ((D_80119880 != 3) && (D_80119880 == 9))) {
        var_s1 = 1;
    }
    while (var_s1 < func_xk1_8002BFA4()) {
        if (Leo_strcmp(D_xk1_8003A5D8[var_s1], D_xk1_8003A560) == 0) {
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

extern const char D_xk1_80032AD4[];

void func_xk1_80029658(void) {
    s32 var_a0;
    s32 var_v1;
    u8* var_v0;
    u8 sp1B;

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/func_xk1_80029B48.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032AC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032AC4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032AC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032ACC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032AD0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/D_xk1_80032AD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/func_xk1_8002AC24.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/func_xk1_8002AC70.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_xk1/A6340/func_xk1_8002AEB4.s")
