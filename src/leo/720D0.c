#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"
#include "libc/stdbool.h"

extern unk_leo_80419EA0 D_80784EF0;
extern u16 D_80793650[];

s32 func_807648D0(void) {
    bcopy(D_80784EF0.unk_3C, D_80793650, 0x1674);
    return 0;
}

s32 func_80764914(void) {
    bcopy(D_80793650, D_80784EF0.unk_3C, 0x1674);
    return 0;
}

extern unk_leo_804285D0 D_80793620;
extern OSMesg D_80794CD4;

s32 func_80764958(s32* arg0, s32 arg1, s32 arg2) {
    s32 sp4;
    s32 sp0;

    sp4 = arg1;
    sp0 = *arg0;
    if (sp0 < 0) {
        sp0 = D_80793620.unk_0A = sp4;
    } else {
        D_80793650[sp0] = sp4;
        sp0 = sp4;
    }
    sp4++;
    while (--arg2 > 0) {
        D_80793650[sp0] = sp4;
        sp0 = sp4++;
    }
    if (sp0 < 0) {
        D_80793620.unk_0A = -1;
    } else {
        D_80793650[sp0] = -1;
    }
    *arg0 = sp0;
    return 0;
}

s32 func_80764A4C(s32 arg0) {
    s32 sp4 = arg0;
    s32 sp0;

    while (true) {
        sp0 = D_80793650[sp4];
        D_80793650[sp4] = 0;
        if (sp0 == 0xFFFF) {
            break;
        }
        if (sp0 == 0) {
            D_80794CD4 = 0xF3;
            return -1;
        }
        if (sp0 == 0xFFFE) {
            D_80794CD4 = 0xF3;
            return -1;
        }
        sp4 = sp0;
    }

    return 0;
}

extern LEOCapacity D_80794D24;

s32 func_80764B04(s32* arg0, u32 arg1, s32* arg2) {
    s32 sp1C;
    s32 sp18;

    sp1C = *arg0;
    while (D_80793650[sp1C] != 0xFFFF) {
        LeoLBAToByte(sp1C + D_80794D24.startLBA, 1, &sp18);
        if (arg1 < sp18) {
            D_80794CD4 = 0xF3;
            return -1;
        }
        arg1 -= sp18;
        sp1C = D_80793650[sp1C];
    }

    LeoLBAToByte(sp1C + D_80794D24.startLBA, 1, &sp18);
    if (arg1 > sp18) {
        D_80794CD4 = 0xF3;
        return -1;
    }
    *arg2 = sp18 - arg1;
    *arg0 = sp1C;
    return 0;
}

s32 func_80764C54(s32* arg0, u32 arg1, s32* arg2) {
    s32 sp1C;
    s32 sp18;

    sp1C = *arg0;

    while (true) {
        LeoLBAToByte(sp1C + D_80794D24.startLBA, 1, &sp18);
        if (arg1 < sp18) {
            break;
        }
        arg1 -= sp18;
        if (sp1C == 0xFFFF) {
            return 0xF4;
        }
        sp1C = D_80793650[sp1C];
    }
    if (arg1 == 0) {
        *arg2 = 0;
    } else {
        *arg2 = sp18 - arg1;
    }
    *arg0 = sp1C;
    return 0;
}

extern u16 D_80784F2C[];

s32 func_80764D4C(s32 arg0) {
    s32 sp4 = 0;

    while (true) {
        sp4++;
        if (D_80784F2C[arg0] == 0xFFFF) {
            break;
        }
        if (D_80784F2C[arg0] != arg0 + 1) {
            break;
        }
        arg0++;
    }
    return sp4;
}
