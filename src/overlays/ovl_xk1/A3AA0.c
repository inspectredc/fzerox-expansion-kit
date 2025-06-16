#include "global.h"

extern u16 D_xk1_800300F0[];

void func_xk1_80026830(u8* arg0, s8* arg1) {
    u16 temp_t9;

    while (true) {
        if (*arg0 == 0) {
            break;
        }
        temp_t9 = D_xk1_800300F0[*arg0];
        *arg1++ = temp_t9 >> 8;
        *arg1++ = temp_t9 & 0xFF;
        arg0++;

    }
    *arg1 = 0;
}
