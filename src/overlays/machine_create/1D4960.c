#include "global.h"

extern u8 D_4006840[];
extern u8 D_4006540[];
extern u8 D_4006240[];
extern u8 D_4005F40[];
extern u8 D_4005C40[];
extern u8 D_4005940[];
extern u8 D_4005640[];
extern u8 D_4005340[];
extern u8 D_4005040[];
extern u8 D_4004D40[];
extern u8 D_4004A40[];
extern u8 D_4004740[];
extern u8 D_4004440[];
extern u8 D_4004140[];
extern u8 D_4003E40[];

u8 D_xk3_80136FA0 = 2;
u8 D_xk3_80136FA4 = 1;
u8 D_xk3_80136FA8 = 1;
u8 D_xk3_80136FAC = 1;
u8 D_xk3_80136FB0 = 1;
u8 D_xk3_80136FB4 = 2;
u8 D_xk3_80136FB8 = 1;
u8 D_xk3_80136FBC = 1;
u8 D_xk3_80136FC0 = 1;
u8 D_xk3_80136FC4 = 1;
u8 D_xk3_80136FC8 = 2;
u8 D_xk3_80136FCC = 1;
u8 D_xk3_80136FD0 = 1;
u8 D_xk3_80136FD4 = 1;
u8 D_xk3_80136FD8 = 1;

u8* D_xk3_80136FDC[][5] = {
    &D_xk3_80136FA0,
    &D_xk3_80136FA4,
    &D_xk3_80136FA8,
    &D_xk3_80136FAC,
    &D_xk3_80136FB0,
    &D_xk3_80136FB4,
    &D_xk3_80136FB8,
    &D_xk3_80136FBC,
    &D_xk3_80136FC0,
    &D_xk3_80136FC4,
    &D_xk3_80136FC8,
    &D_xk3_80136FCC,
    &D_xk3_80136FD0,
    &D_xk3_80136FD4,
    &D_xk3_80136FD8,
};

u8* D_xk3_80137018[][3] = {
    { D_4006840, D_4006540, D_4006240 },
    { D_4005F40, D_4005C40, D_4005940 },
    { D_4005640, D_4005340, D_4005040 },
    { D_4004D40, D_4004A40, D_4004740 },
    { D_4004440, D_4004140, D_4003E40 },
};

u16 D_xk3_80137054[][5] = {
    { 163, 189, 215, 241, 267 },
    { 163, 189, 215, 241, 267 },
    { 163, 189, 215, 241, 267 },
};

u8 D_xk3_80137074[][5] = {
    { 41, 41, 41, 41, 41 },
    { 60, 60, 60, 60, 60 },
    { 79, 79, 79, 79, 79 },
};

u8 D_xk3_80137084[][5] = {
    { 0, 1, 2, 4, 5 },
    { 0, 1, 2, 6, 8 },
    { 0, 1, 2, 6, 8 },
};

void func_xk3_80134CA0(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {

    if (arg2 >= (D_xk3_80137084[arg0][arg3] - D_xk3_80137084[arg0][arg1])) {
        *D_xk3_80136FDC[arg0][arg3] = 1;
    } else {
        *D_xk3_80136FDC[arg0][arg3] = 0;
    }
}

void func_xk3_80134D48(u8 arg0, u8 arg1, u8 arg2) {

    switch (arg1) {
        case 0:
            *D_xk3_80136FDC[arg0][0] = 2;
            func_xk3_80134CA0(arg0, arg1, arg2, 1);
            func_xk3_80134CA0(arg0, arg1, arg2, 2);
            func_xk3_80134CA0(arg0, arg1, arg2, 3);
            func_xk3_80134CA0(arg0, arg1, arg2, 4);
            break;
        case 1:
            *D_xk3_80136FDC[arg0][0] = 1;
            *D_xk3_80136FDC[arg0][1] = 2;
            func_xk3_80134CA0(arg0, arg1, arg2, 2);
            func_xk3_80134CA0(arg0, arg1, arg2, 3);
            func_xk3_80134CA0(arg0, arg1, arg2, 4);
            break;
        case 2:
            *D_xk3_80136FDC[arg0][0] = 1;
            *D_xk3_80136FDC[arg0][1] = 1;
            *D_xk3_80136FDC[arg0][2] = 2;
            func_xk3_80134CA0(arg0, arg1, arg2, 3);
            func_xk3_80134CA0(arg0, arg1, arg2, 4);
            break;
        case 3:
            *D_xk3_80136FDC[arg0][0] = 1;
            *D_xk3_80136FDC[arg0][1] = 1;
            *D_xk3_80136FDC[arg0][2] = 1;
            *D_xk3_80136FDC[arg0][3] = 2;
            func_xk3_80134CA0(arg0, arg1, arg2, 4);
            break;
        case 4:
            *D_xk3_80136FDC[arg0][0] = 1;
            *D_xk3_80136FDC[arg0][1] = 1;
            *D_xk3_80136FDC[arg0][2] = 1;
            *D_xk3_80136FDC[arg0][3] = 1;
            *D_xk3_80136FDC[arg0][4] = 2;
            break;
        default:
            break;
    }
}

void func_xk3_80134FA4(u8 arg0, u8 arg1, u8 arg2) {
    u8 sp18;
    u8 var_v0;
    u8 var_v1;
    u8 var_a3;

    var_v0 = D_xk3_80137084[0][arg0];
    var_v1 = D_xk3_80137084[1][arg1];
    var_a3 = D_xk3_80137084[2][arg2];
    sp18 = (-var_v0 - var_v1 - var_a3) + 13;

    func_xk3_80134D48(0, arg0, sp18);
    func_xk3_80134D48(1, arg1, sp18);
    func_xk3_80134D48(2, arg2, sp18);
}

Gfx* func_xk3_80135034(s32 gfx) {
    u8 i;
    u8 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            gfx = func_xk3_8012E120(gfx, D_xk3_80137018[j][*D_xk3_80136FDC[i][j]], D_xk3_80137054[i][j],
                                    D_xk3_80137074[i][j], 24, 16);
        }
    }
    return gfx;
}

extern unk_80140E60 D_xk3_80140E70;
extern u16 D_xk3_8013A180[];
extern u16 D_xk3_8013A580[];
extern Gfx D_xk3_80137378[];

Gfx* func_xk3_80135158(Gfx* gfx) {

    if (D_xk3_80140E70.unk_04 == 3) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A580, 259, 98, 32, 16);
    } else {
        gfx = func_xk1_8002FDF8(gfx, D_xk3_80137054[D_xk3_80140E70.unk_04][D_xk3_80140E70.unk_00],
                                D_xk3_80137074[D_xk3_80140E70.unk_04][D_xk3_80140E70.unk_00],
                                D_xk3_80137054[D_xk3_80140E70.unk_04][D_xk3_80140E70.unk_00] + 0x17,
                                D_xk3_80137074[D_xk3_80140E70.unk_04][D_xk3_80140E70.unk_00] + 0xF, 255, 64, 64,
                                func_xk1_800290C0(), 2, 2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A180, 259, 98, 32, 16);
    }
    return gfx;
}

extern u8 D_4003840[];
extern u8 D_4003A40[];
extern u8 D_4003C40[];
extern Gfx D_xk3_801373F0[];
extern Gfx D_xk3_80137440[];
extern unk_806F2400_unk_00 D_xk1_800333D0;

Gfx* func_xk3_801352A4(Gfx* gfx, s32 arg1, s32 arg2) {

    gSPDisplayList(gfx++, D_xk3_80137440);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1))
        gDPFillRectangle(gfx++, 122, 38, 295, 116);
    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);
    gfx = func_xk3_8012E740(gfx, D_4003840, 127, 41, 32, 16);
    gfx = func_xk3_8012E740(gfx, D_4003A40, 127, 60, 32, 16);
    gfx = func_xk3_8012E740(gfx, D_4003C40, 127, 79, 32, 16);
    gSPDisplayList(gfx++, D_xk3_80137378);
    func_xk3_80134FA4(D_xk1_800333D0.body, D_xk1_800333D0.boost, D_xk1_800333D0.grip);
    gfx = func_xk3_80135034(gfx);
    gfx = func_xk3_80135158(gfx);
    return gfx;
}

void func_xk3_801353F8(char** arg0, u8 arg1) {

    switch (arg1) {
        case 4:
            *arg0 = "a";
            break;
        case 3:
            *arg0 = "b";
            break;
        case 2:
            *arg0 = "c";
            break;
        case 1:
            *arg0 = "d";
            break;
        case 0:
            *arg0 = "e";
            break;
        default:
            break;
    }
}

extern u8 D_4003840[];
extern u8 D_4003A40[];
extern u8 D_4003C40[];
extern u8 D_xk1_800333F0;
extern u8 D_800333F4;
extern u8 D_xk3_801407B0[][3];

Gfx* func_xk3_80135474(Gfx* gfx) {

    gSPDisplayList(gfx++, D_xk3_801373F0);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    gfx = func_xk3_8012E740(gfx, &D_4003840, 190, 133, 32, 16);
    gfx = func_xk3_8012E740(gfx, &D_4003A40, 190, 150, 32, 16);
    gfx = func_xk3_8012E740(gfx, &D_4003C40, 190, 167, 32, 16);

    gSPDisplayList(gfx++, D_xk3_80137378);
    if (D_xk1_800333F0 != 0) {
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk3_801407B0[D_800333F4][0]][2], 230, 133, 24, 16);
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk3_801407B0[D_800333F4][1]][2], 230, 150, 24, 16);
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk3_801407B0[D_800333F4][2]][2], 230, 167, 24, 16);
    } else {
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk1_800333D0.body][2], 230, 133, 24, 16);
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk1_800333D0.boost][2], 230, 150, 24, 16);
        gfx = func_xk3_8012E120(gfx, D_xk3_80137018[D_xk1_800333D0.grip][2], 230, 167, 24, 16);
    }
    return gfx;
}

extern s32 D_xk3_80136820;
extern unk_800E51B8* D_80140E40;

void func_xk3_8013571C(void) {
    if (func_80711AC0(D_80140E40, 1) == 0) {
        return;
    }
    if (D_xk3_80140E70.unk_04 == 3) {
        PRINTF("WORKS MACHINE MODE : 0\n");
        D_xk3_80136820 = 0;
        func_8074122C(0x24);
        func_807113DC(D_80140E40);
    } else if (*D_xk3_80136FDC[D_xk3_80140E70.unk_04][D_xk3_80140E70.unk_00] != 0) {
        switch (D_xk3_80140E70.unk_04) {
            case 0:
                if (D_xk3_80140E70.unk_00 != D_xk1_800333D0.body) {
                    D_xk1_800333D0.body = D_xk3_80140E70.unk_00;
                    func_8074122C(0x27);
                    break;
                }
                break;
            case 1:
                if (D_xk3_80140E70.unk_00 != D_xk1_800333D0.boost) {
                    D_xk1_800333D0.boost = D_xk3_80140E70.unk_00;
                    func_8074122C(0x27);
                    break;
                }
                break;
            case 2:
                if (D_xk3_80140E70.unk_00 != D_xk1_800333D0.grip) {
                    D_xk1_800333D0.grip = D_xk3_80140E70.unk_00;
                    func_8074122C(0x27);
                    break;
                }
                break;
        }
    } else {
        func_8074122C(0x20);
    }
}

s32 func_xk3_80135850(unk_806F2400_unk_00* arg0) {
    if (D_xk3_80137084[0][arg0->body] + D_xk3_80137084[1][arg0->boost] + D_xk3_80137084[2][arg0->grip] > 13) {
        return 1;
    }
    return 0;
}
