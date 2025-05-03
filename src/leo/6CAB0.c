#include "leo/unk_leo.h"
#include "leo/leo_functions.h"
#include "libc/stdbool.h"

extern unk_leo_804285D0 D_80793620;

void func_8075F2B0(u16 arg0) {
    D_80793620.unk_00 = arg0;
}

void func_8075F2CC(u16 arg0) {
    D_80793620.unk_02 = arg0;
}

void func_8075F2E8(u8* arg0) {
    bzero(D_80793620.unk_04, 2);
    if (arg0 != NULL) {
        Leo_bcopy(D_80793620.unk_04, arg0, 2);
    }
}

void func_8075F344(u8* arg0) {
    bzero(D_80793620.unk_06, 4);
    if (arg0 != NULL) {
        Leo_bcopy(D_80793620.unk_06, arg0, 4);
    }
}

void func_8075F3A0(u8* arg0) {
    bzero(D_80793620.unk_10, 20);
    if (arg0 != NULL) {
        Leo_bcopy(D_80793620.unk_10, arg0, 20);
    }
}

void func_8075F3FC(void) {
    LEODiskTime sp18;

    func_807620C0(&sp18);
    func_80762184(&sp18, &D_80793620.unk_2C);
}

void func_8075F438(u16 arg0) {
    D_80793620.unk_0A = arg0;
}

void func_8075F454(u8* arg0) {
    bzero(D_80793620.unk_24, 5);
    if (arg0 != NULL) {
        Leo_bcopy(D_80793620.unk_24, arg0, 5);
    }
}

void func_8075F4B0(s32 arg0) {
    D_80793620.unk_0C = arg0;
}

extern char D_80794D40[];
extern char D_80794D44[];

void func_8075F4C8(u16 arg0, u8* arg1) {
    func_8075F2CC(arg0);
    func_8075F3A0(arg1);
    func_8075F3FC();
    func_8075F2E8(D_80794D40);
    func_8075F344(D_80794D44);
}

void func_8075F520(s32 arg0) {
    D_80793620.unk_29 = arg0;
}

void func_8075F538(u16 arg0) {
    D_80793620.unk_2A = arg0;
}

void func_8075F554(void) {
    bzero(&D_80793620, sizeof(unk_leo_804285D0));
}

extern s32 D_80794CD0;
extern unk_leo_80419EA0 D_80784EF0;

s32 func_8075F584(u16 arg0) {
    if (arg0 > D_80794CD0) {
        return -1;
    }
    bcopy(&D_80793620, &D_80784EF0.unk_16B0[arg0], sizeof(unk_leo_804285D0));
    return 0;
}

s32 func_8075F600(u16 arg0) {
    if (arg0 > D_80794CD0) {
        return -1;
    }
    bcopy(&D_80784EF0.unk_16B0[arg0], &D_80793620, sizeof(unk_leo_804285D0));
    return 0;
}

void func_8075F67C(u16 arg0) {

    if (D_80784EF0.unk_16B0[arg0].unk_2A < 0xFF) {
        D_80784EF0.unk_16B0[arg0].unk_2A++;
    }
}

void func_8075F6E8(u16 arg0) {
    D_80784EF0.unk_16B0[arg0].unk_2A = 0;
}

s32 func_8075F714(u16 arg0) {

    if (Leo_bcmp(D_80784EF0.unk_16B0[arg0].unk_04, D_80794D40, 2) != 0) {
        return -1;
    }

    if (Leo_bcmp(D_80784EF0.unk_16B0[arg0].unk_06, D_80794D44, 4) != 0) {
        return -1;
    }

    return 0;
}

extern OSMesg D_80794CD4;
extern u16 D_80794CE0;

u16 func_8075F7C0(u16 arg0, u8* arg1, u8* arg2) {
    s32 i;

    D_80794CD4 = 0;
    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }

    for (i = 0; i < D_80794CD0; i++) {
        if ((D_80784EF0.unk_16B0[i].unk_00 & 0x4000) && (D_80784EF0.unk_16B0[i].unk_02 == arg0) &&
            (Leo_bcmp(D_80784EF0.unk_16B0[i].unk_10, arg1, 0x14) == 0) &&
            (Leo_bcmp(D_80784EF0.unk_16B0[i].unk_24, arg2, 5) == 0)) {
            return i;
        }
    }

    D_80794CD4 = 0xF2;
    return -1;
}

u16 func_8075F904(u16 arg0, u8* arg1) {
    s32 i;

    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }

    for (i = 0; i < D_80794CD0; i++) {
        if ((D_80784EF0.unk_16B0[i].unk_00 & 0x8000) && (D_80784EF0.unk_16B0[i].unk_02 == arg0) &&
            (Leo_bcmp(D_80784EF0.unk_16B0[i].unk_10, arg1, 0x14) == 0)) {
            return i;
        }
    }

    return -1;
}

u16 func_8075F9E0(u16 arg0) {
    s32 i;

    if (arg0 == 0xFFFB) {
        arg0 = D_80794CE0;
    }
    if (arg0 == 0xFFFC) {
        arg0 = func_80761590(0xFFFB);
    }

    for (i = 0; i < D_80794CD0; i++) {
        if ((D_80784EF0.unk_16B0[i].unk_00 & 0x8000) && (D_80784EF0.unk_16B0[i].unk_0A == arg0)) {
            return i;
        }
    }

    return -1;
}

u16 func_8075FABC(void) {
    s32 i;

    for (i = 0; i < D_80794CD0; i++) {
        if (D_80784EF0.unk_16B0[i].unk_00 == 0) {
            return i;
        }
    }

    return -1;
}

extern u16 D_80793650[];
extern LEOCapacity D_80794D24;

s32 func_8075FB38(u32 arg0, s32* arg1, s32* arg2, s32* arg3) {
    u32 sp34;
    s32 sp30;
    u32 sp2C;
    s32 sp28;
    s32 i;
    s32 j;
    s32 sp1C;
    s32 sp18;

    sp34 = -1;
    sp30 = -1;
    sp2C = 0;
    sp18 = 1;

    for (i = 6; i < (D_80794D24.endLBA - D_80794D24.startLBA); i++) {
        if (D_80793650[i] != 0) {
            continue;
        }
        j = i;
        while (j < (D_80794D24.endLBA - D_80794D24.startLBA)) {
            if (D_80793650[j] != 0) {
                break;
            }
            j++;
        }

        LeoLBAToByte(i + D_80794D24.startLBA, j - i, &sp28);
        sp1C = 0;
        if (sp18 != 0) {
            sp1C++;
            sp18 = 0;
        }
        if ((sp2C < arg0) && (sp28 > arg0)) {
            sp1C++;
        }
        if ((sp28 <= arg0) && (sp2C < sp28)) {
            sp1C++;
        }
        if ((sp28 >= arg0) && (sp2C > sp28)) {
            sp1C++;
        }
        if (sp1C != 0) {
            sp34 = i;
            sp30 = j - i;
            sp2C = sp28;
        }
        i = j;
    }

    if (false) {
        *arg1 = -1;
        *arg2 = 0;
        *arg3 = 0;
        return -1;
    }

    if (sp2C > arg0) {
        for (j = 1; j <= sp30; j++) {
            LeoLBAToByte(sp34 + D_80794D24.startLBA, j, &sp28);
            if (sp28 >= arg0) {
                break;
            }
        }

        sp30 = j;
        sp2C = sp28;
    }
    *arg1 = sp34;
    *arg2 = sp30;
    *arg3 = sp2C;

    return 0;
}
