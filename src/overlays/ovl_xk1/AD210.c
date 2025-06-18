#include "global.h"
#include "fzx_racer.h"
#include "fzx_machine.h"

extern unk_806F2400 D_806F2400;

void func_xk1_8002FFA0(void) {
    u8 i;

    for (i = 0; i < 30; i++) {
        D_806F2400.unk_00[i].unk_07 = 0x1F;
        D_806F2400.unk_3C0[i] = 0;
    }
}

extern unk_806F2400_unk_00 D_xk1_800333D0;

void func_xk1_8002FFDC(void) {
    D_xk1_800333D0.body = BODY_A;
    D_xk1_800333D0.boost = BOOST_A;
    D_xk1_800333D0.grip = GRIP_A;
    D_xk1_800333D0.frontType = FRONT_0;
    D_xk1_800333D0.rearType = REAR_0;
    D_xk1_800333D0.wingType = WING_NONE;
    D_xk1_800333D0.logo = LOGO_ARROW_PLANE;
    D_xk1_800333D0.unk_07 = 0x1F;
    D_xk1_800333D0.decal = DECAL_THIN_STRIPE;
    D_xk1_800333D0.red = 0;
    D_xk1_800333D0.green = 255;
    D_xk1_800333D0.blue = 0;
    D_xk1_800333D0.numberR = 255;
    D_xk1_800333D0.numberG = 255;
    D_xk1_800333D0.numberB = 255;
    D_xk1_800333D0.decalR = 255;
    D_xk1_800333D0.decalG = 255;
    D_xk1_800333D0.decalB = 0;
    D_xk1_800333D0.cockpitR = 0;
    D_xk1_800333D0.cockpitG = 0;
    D_xk1_800333D0.cockpitB = 93;
    D_xk1_800333D0.machineName[0] = '\0';
}
