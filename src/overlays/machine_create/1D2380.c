#include "global.h"
#include "leo/leo_functions.h"
#include "fzx_machine.h"

s32 D_xk3_80136820 = 0;

extern s32 D_xk1_800318B4;

void func_xk3_801326C0(void) {
    D_xk1_800318B4 = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    D_xk3_80136820 = 1;
}

extern s32 D_xk1_800318A4;

void func_xk3_801326D8(void) {
    D_xk1_800318A4 = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    D_xk3_80136820 = 1;
}

extern s32 D_xk1_800318B0;
extern volatile unk_807C6EA8 D_807C6EA8;
extern unk_806F2400_unk_00 D_xk1_800333D0;
extern unk_806F2400_unk_00 D_xk3_801365E0;

void func_xk3_801326F0(void) {
    D_807C6EA8.unk_08 = 0;
    D_xk1_800318B0 = 0;
    D_xk3_801365E0 = D_xk1_800333D0;
    PRINTF("WORKS MACHINE MODE : MENU_COLOR\n");
    D_xk3_80136820 = 2;
}

extern s32 D_xk1_800318B8;

void func_xk3_80132764(void) {
    D_xk1_800318B8 = 0;
    PRINTF("WORKS MACHINE MODE : MENU\n");
    D_xk3_80136820 = 1;
}

void func_xk3_8013277C(void) {
    PRINTF("WORKS MACHINE MODE : ENTRY_GET_FILE\n");
    D_xk3_80136820 = 0x18;
    func_xk3_80135F90();
}

extern volatile s8 D_80794E1C;

void func_xk3_801327A4(void) {
    if (func_xk3_8013618C(1) != 0) {
        func_xk3_8012B950();
        PRINTF("WORKS MACHINE MODE : ENTRY_CLEAR_SELECT_FILE\n");
        D_xk3_80136820 = 0x1E;
    } else {
        PRINTF("WORKS MACHINE MODE : 0\n");
        D_xk3_80136820 = 0;
        D_80794E1C = 1;
        D_807C6EA8.unk_08 = 0x1B;
    }
}

void func_xk3_80132808(void) {
    D_807C6EA8.unk_08 = 0x14;
    PRINTF("WORKS MACHINE MODE : ENTRY_ALLCLEAR_CONFIRM\n");
    D_xk3_80136820 = 0x1D;
}

void func_xk3_80132828(void) {
    PRINTF("WORKS MACHINE MODE : LOAD_GET_FILE\n");
    D_xk3_80136820 = 3;
    func_xk3_80135F90();
}

void func_xk3_80132850(void) {
    PRINTF("WORKS MACHINE MODE : DELETE_GET_FILE\n");
    D_xk3_80136820 = 0xE;
    func_8076877C(0, "CARD");
}

extern f32 D_xk3_80136540;
extern unk_80140E60 D_xk3_80140E60;

void func_xk3_80132884(void) {
    D_807C6EA8.unk_08 = 0;
    D_xk3_801365E0 = D_xk1_800333D0;
    PRINTF("WORKS MACHINE MODE : PARTS\n");
    D_xk3_80136820 = 0x11;
    D_xk3_80140E60.unk_00 = 0;
    D_xk3_80140E60.unk_04 = 0;
    D_xk3_80136540 = -7000.0f;
}

extern s32 D_xk1_800318A8;

void func_xk3_80132910(void) {
    D_807C6EA8.unk_08 = 0;
    D_xk1_800318A8 = D_xk1_800333D0.decal - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_LINE\n");
    D_xk3_80136820 = 0x12;
    D_xk3_801365E0 = D_xk1_800333D0;
}

void func_xk3_8013298C(void) {
    D_xk1_800333D0.decal = MACHINE_DECAL(DECAL_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_801329A4(void) {
    D_xk1_800333D0.decal = MACHINE_DECAL(DECAL_THIN_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_801329BC(void) {
    D_xk1_800333D0.decal = MACHINE_DECAL(DECAL_DOUBLE_STRIPE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_801329D4(void) {
    D_xk1_800333D0.decal = MACHINE_DECAL(DECAL_TRIPLE_STRIPE_UNEVEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_801329EC(void) {
    D_xk1_800333D0.decal = MACHINE_DECAL(DECAL_BLOCK);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

extern s32 D_xk1_800318AC;

void func_xk3_80132A04(void) {
    D_807C6EA8.unk_08 = 0;
    D_xk1_800318AC = D_xk1_800333D0.logo - 1;
    PRINTF("WORKS MACHINE MODE : SELECT_MARK\n");
    D_xk3_80136820 = 0x13;
    D_xk3_801365E0 = D_xk1_800333D0;
}

void func_xk3_80132A80(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_SHIELD);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132A98(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_ARROW_PLANE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132AB0(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_CIRCLE);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132AC8(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_SKULL);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132AE0(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_YELLOW_GREEN);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132AF8(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_KANJI);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132B10(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_X);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

void func_xk3_80132B28(void) {
    D_xk1_800333D0.logo = MACHINE_LOGO(LOGO_N64);
    PRINTF("WORKS MACHINE MODE : 0\n");
    D_xk3_80136820 = 0;
}

extern unk_80140E60 D_xk3_80140E68;
extern unk_800E51B8* D_xk3_80140E44;

void func_xk3_80132B40(void) {
    PRINTF("WORKS MACHINE MODE : BODY_COLOR\n");
    D_xk3_80136820 = 0x14;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    D_xk3_80140E44 = func_807112A0(1, 0xA8, 0x2C, 0x79, 0x79, 1, 1, func_xk3_80135C0C);
}

void func_xk3_80132BB0(void) {
    PRINTF("WORKS MACHINE MODE : LINE_COLOR\n");
    D_xk3_80136820 = 0x15;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    D_xk3_80140E44 = func_807112A0(1, 0xA8, 0x2C, 0x79, 0x79, 1, 1, func_xk3_80135C0C);
}

void func_xk3_80132C20(void) {
    PRINTF("WORKS MACHINE MODE : NUMBER_COLOR\n");
    D_xk3_80136820 = 0x16;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    D_xk3_80140E44 = func_807112A0(1, 0xA8, 0x2C, 0x79, 0x79, 1, 1, func_xk3_80135C0C);
}

void func_xk3_80132C90(void) {
    PRINTF("WORKS MACHINE MODE : COCKPIT_COLOR\n");
    D_xk3_80136820 = 0x17;
    D_xk3_80140E68.unk_00 = 0;
    D_xk3_80140E68.unk_04 = 0;
    D_xk3_80140E44 = func_807112A0(1, 0xA8, 0x2C, 0x79, 0x79, 1, 1, func_xk3_80135C0C);
}

extern u8 D_xk1_8003A560[];

void func_xk3_80132D00(void) {
    D_807C6EA8.unk_08 = 0;
    if (gControllers[gPlayerControlPorts[0]].buttonPressed & BTN_B) {
        PRINTF("WORKS MACHINE MODE : 0\n");
        D_xk3_80136820 = 0;
        return;
    }
    mfsStrCpy(D_xk1_800333D0.machineName, &D_xk1_8003A560);
    D_xk3_801365E0 = D_xk1_800333D0;
    D_xk3_801365E0.number = 31;
    func_xk3_8012D700();
    PRINTF("WORKS MACHINE MODE : SAVE_FILE_EXIST_BEFORE\n");
    D_xk3_80136820 = 8;
}

extern u8 D_xk1_800333F0;

void func_xk3_80132DDC(void) {
    if (D_xk1_800333F0 != 0) {
        D_807C6EA8.unk_08 = 0x17;
        PRINTF("WORKS MACHINE MODE : MESSAGE_BUTTON\n");
        D_xk3_80136820 = 0x24;
        func_8074122C(0x20);
    } else {
        PRINTF("WORKS MACHINE MODE : MNAME\n");
        D_xk3_80136820 = 0x22;
        D_807C6EA8.unk_08 = 0x11;
        func_xk1_8002D86C(0x1B, 6);
        func_xk1_8002D880(0x28);
        func_xk1_800294AC();
        mfsStrCpy(&D_xk1_8003A560, D_xk1_800333D0.machineName);
        func_xk1_800294EC(func_xk3_80132D00);
    }
}

extern unk_80140E60 D_xk3_80140E70;
extern unk_800E51B8* D_80140E40;

void func_xk3_80132E84(void) {
    D_xk3_801365E0 = D_xk1_800333D0;
    PRINTF("WORKS MACHINE MODE : SETTING\n");
    D_xk3_80136820 = 0x23;
    D_xk3_80140E70.unk_00 = 0;
    D_xk3_80140E70.unk_04 = 0;
    D_80140E40 = func_807112A0(1, 0x7A, 0x26, 0xAE, 0x4F, 1, 1, func_xk3_801352A4);
}
