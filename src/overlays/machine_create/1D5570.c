#include "global.h"

u8 D_xk3_801414D0;
u8 D_xk3_801414D1;

u8 D_xk3_801370A0[][8][3] = {
    { { 255, 0, 0 }, { 201, 0, 0}, { 147, 0, 0 }, { 93, 0, 0 }, { 0, 255, 0 }, { 0, 201, 0 }, { 0, 147, 0 }, { 0, 93, 0 } },
    { { 255, 127, 0 }, { 201, 100, 0}, { 147, 73, 0 }, { 93, 46, 0 }, { 0, 154, 80 }, { 0, 121, 63 }, { 0, 89, 45 }, { 0, 56, 28 } },
    { { 255, 255, 0 }, { 201, 201, 0}, { 147, 147, 0 }, { 93, 93, 0 }, { 255, 255, 127 }, { 201, 201, 100 }, { 147, 147, 73 }, { 93, 93, 46 } },
    { { 0, 0, 255 }, { 0, 0, 201}, { 0, 0, 147 }, { 0, 0, 93 }, { 127, 0, 255 }, { 100, 0, 201 }, { 73, 0, 147 }, { 46, 0, 93 } },
    { { 0, 255, 255 }, { 0, 201, 201}, { 0, 147, 147 }, { 0, 93, 93 }, { 255, 0, 255 }, { 201, 0, 201 }, { 147, 0, 147 }, { 93, 0, 93 } },
    { { 159, 223, 223 }, { 125, 175, 175}, { 91, 128, 128 }, { 57, 81, 81 }, { 223, 159, 223 }, { 175, 125, 175 }, { 128, 91, 128 }, { 81, 57, 81 } },
    { { 101, 101, 255 }, { 178, 101, 255}, { 255, 101, 255 }, { 255, 101, 178 }, { 255, 101, 101 }, { 255, 178, 101 }, { 255, 229, 101 }, { 255, 244, 182 } },
    { { 0, 0, 0 }, { 34, 34, 34}, { 68, 68, 68 }, { 102, 102, 102 }, { 136, 136, 136 }, { 170, 170, 170 }, { 204, 204, 204 }, { 255, 255, 255 } },
};

void func_xk3_801358B0(u8 arg0, u8 arg1, u8 arg2) {

    for (D_xk3_801414D1 = 0; D_xk3_801414D1 < 8; D_xk3_801414D1++) {
        for (D_xk3_801414D0 = 0; D_xk3_801414D0 < 8; D_xk3_801414D0++) {
            if ((arg0 == D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][0]) &&
                (arg1 == D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][1]) &&
                (arg2 == D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][2])) {
                return;
            }
        }
    }
}

extern s32 D_xk3_80136820;
extern unk_806F2400_unk_00 D_xk1_800333D0;

Gfx* func_xk3_8013598C(Gfx* gfx) {

    switch (D_xk3_80136820) {
        case 20:
            func_xk3_801358B0(D_xk1_800333D0.red, D_xk1_800333D0.green, D_xk1_800333D0.blue);
            break;
        case 21:
            func_xk3_801358B0(D_xk1_800333D0.decalR, D_xk1_800333D0.decalG, D_xk1_800333D0.decalB);
            break;
        case 22:
            func_xk3_801358B0(D_xk1_800333D0.numberR, D_xk1_800333D0.numberG, D_xk1_800333D0.numberB);
            break;
        case 23:
            func_xk3_801358B0(D_xk1_800333D0.cockpitR, D_xk1_800333D0.cockpitG, D_xk1_800333D0.cockpitB);
            break;
    }
    if ((D_xk3_801414D0 != 8) && (D_xk3_801414D1 != 8)) {
        gfx = func_xk1_8002FCA0(gfx, D_xk3_801414D0 * 15 + 0xA8, D_xk3_801414D1 * 15 + 0x2C, D_xk3_801414D0 * 15 + 0xB7,
                                D_xk3_801414D1 * 15 + 0x3B, GPACK_RGBA5551(255, 255, 255, 1), 2, 2);
    }
    return gfx;
}

extern u16 D_xk3_8013A180[];
extern u16 D_xk3_8013A580[];
extern Gfx D_xk3_80137378[];
extern unk_80140E60 D_xk3_80140E68;

Gfx* func_xk3_80135AD4(Gfx* gfx) {

    if (D_xk3_80140E68.unk_04 == 8) {
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A580, 257, 165, 32, 16);
    } else {

        gfx = func_xk1_8002FDF8(gfx, D_xk3_80140E68.unk_00 * 15 + 0xA8, D_xk3_80140E68.unk_04 * 15 + 0x2C,
                                D_xk3_80140E68.unk_00 * 15 + 0xB7, D_xk3_80140E68.unk_04 * 15 + 0x3B, 255, 64, 64,
                                func_xk1_800290C0(), 2, 2);
        gSPDisplayList(gfx++, D_xk3_80137378);
        gfx = func_xk3_8012E120(gfx, D_xk3_8013A180, 257, 165, 32, 16);
    }
    return gfx;
}

extern Gfx D_xk3_80137440[];

Gfx* func_xk3_80135C0C(Gfx* gfx, s32 arg1, s32 arg2) {

    gSPDisplayList(gfx++, D_xk3_80137440);
    gDPSetFillColor(gfx++, GPACK_RGBA5551(0, 0, 0, 1) << 16 | GPACK_RGBA5551(0, 0, 0, 1))
        gDPFillRectangle(gfx++, 168, 44, 288, 164);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    for (D_xk3_801414D1 = 0; D_xk3_801414D1 < 8; D_xk3_801414D1++) {
        for (D_xk3_801414D0 = 0; D_xk3_801414D0 < 8; D_xk3_801414D0++) {
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][0],
                            D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][1],
                            D_xk3_801370A0[D_xk3_801414D1][D_xk3_801414D0][2], 255);
            gDPFillRectangle(gfx++, (D_xk3_801414D0 * 15) + 0xA9, (D_xk3_801414D1 * 15) + 0x2D,
                             (D_xk3_801414D0 * 15) + 0xB7, (D_xk3_801414D1 * 15) + 0x3B);
        }
    }
    gfx = func_xk3_8013598C(gfx);
    gfx = func_xk3_80135AD4(gfx);
    return gfx;
}

extern unk_800E51B8* D_xk3_80140E44;

void func_xk3_80135E58(u8* arg0, u8* arg1, u8* arg2) {

    if (func_80711AC0(D_xk3_80140E44, 1) == 0) {
        return;
    }

    if (D_xk3_80140E68.unk_04 == 8) {
        func_xk3_8012BC98();
        func_8074122C(0x24);
    } else if ((*arg0 != D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][0]) ||
               (*arg1 != D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][1]) ||
               (*arg2 != D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][2])) {
        *arg0 = D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][0];
        *arg1 = D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][1];
        *arg2 = D_xk3_801370A0[D_xk3_80140E68.unk_04][D_xk3_80140E68.unk_00][2];
        func_8074122C(0x27);
    }
}
