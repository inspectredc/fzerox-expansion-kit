#include "global.h"
#include "audio.h"
#include "audio_funcs.h"
#include "audiothread_cmd.h"

extern f32 D_80771B44[];
extern u8 D_80771B54[];
extern u8 D_80771B58[];
extern f32 D_80771B5C[];
extern u8 D_80771B6C[];
extern u8 D_80771B70[];
extern u8 D_80771B74[];
extern u8 D_80771D38[][4];
extern u8 D_80771D48[][8];

void func_80740740(u8 arg0) {

    D_80771B44[arg0] = 0.0f;
    D_80771B54[arg0] = 0;
    D_80771B58[arg0] = 0;
    D_80771B5C[arg0] = 0;
    D_80771B6C[arg0] = 0;
    D_80771D48[arg0][0] = 0;
    D_80771D48[arg0][1] = 0;
    D_80771D48[arg0][2] = 0;
    D_80771D48[arg0][3] = 0;
    D_80771D48[arg0][4] = 0;
    D_80771D48[arg0][5] = 0;
    D_80771D48[arg0][6] = 0;
    D_80771D48[arg0][7] = 0;
    D_80771B70[arg0] = 0;
    D_80771D38[arg0][0] = 0;
    D_80771D38[arg0][1] = 0;
    D_80771D38[arg0][2] = 0;
    D_80771D38[arg0][3] = 0;

    func_807418D4(arg0 + 2);
    func_807418D4(arg0 + 6);
    D_80771B74[arg0] = 0;
    func_80739B58();
}

s32 func_80740838(u8 arg0) {
    u8 var_v1;

    if (arg0 == 0x3F) {
        return 0x3F;
    }

    if (arg0 >= 0x40) {
        var_v1 = (arg0 >= 0x5F) ? 0x7F : arg0 * 2 - 0x3F;
        return var_v1;
    }

    if (arg0 < 0x3F) {
        var_v1 = (arg0 < 0x20) ? 0 : arg0 * 2 - 0x3F;
        return var_v1;
    }
}

extern u8 D_80771AC0;
extern u8 D_80771AE8;
extern u8 D_80771AEC;
extern u8 D_80771AFC;
extern u8 D_80771B00;
extern u8 D_80771B04;
extern f32 D_80771B08;
extern f32 D_80771B0C;
extern f32 D_80771B10;
extern f32 D_80771B14;
extern f32 D_80771B18;
extern u8 D_80771B1C;
extern u8 D_80771B20;
extern u8 D_80771B28;
extern s16 D_80771B30;
extern u8 D_80771B38;
extern u8 D_80771B40;
extern f32 D_80771B78[];
extern u8 D_80771BB8[];
extern u8 D_80771C74;
extern u8 D_80771CA8;
extern u8 D_80771CC0[][4];

void func_80740740(u8);

void func_807408AC(void) {
    u8 i;

    func_807418D4(0);
    func_807418D4(14);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
    if (D_80771C74 == 1) {
        AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 0.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, D_80771B40 + 2, 0.0f);
        D_80771C74 = 0;
    }
    D_80771CA8 = 0;
    D_80771AC0 = 0;
    D_80771AE8 = 0;
    D_80771AEC = 0;
    D_80771AFC = 0;
    D_80771B00 = 0;
    D_80771B04 = 0;
    D_80771B08 = 0.0f;
    D_80771B0C = 1.0f;
    D_80771B10 = 0.0f;
    D_80771B14 = 0.0f;
    D_80771B18 = 0.0f;
    D_80771B1C = 0x40;
    D_80771B20 = 0;
    D_80771B38 = 0;
    D_80771B30 = 0;
    D_80771B28 = 0;

    for (i = 0; i < 4; i++) {
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, i + 2, 0.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, i + 6, 0.0f);
        AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, i + 2, 0);
        AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, i + 6, 0);
        func_80740740(i);
        D_80771BB8[i] = 0;
    }

    for (i = 0; i < 16; i++) {
        D_80771B78[i] = 0.0f;
    }

    for (i = 0; i < 30; i++) {
        D_80771CC0[i][0] = 0;
        D_80771CC0[i][1] = 0;
        D_80771CC0[i][2] = 0;
        D_80771CC0[i][3] = 0;
    }
}

u8 func_80740B04(void) {
    return D_80771B40;
}

void Audio_PreNMI(void) {
    AudioThread_PreNMIInternal();
}

extern RomOffset D_807C1BE0;
extern RomOffset D_807C1BE4;
extern RomOffset D_807C1BE8;

void Audio_Init(RomOffset audioSequenceStart, RomOffset audioBankStart, RomOffset audioTableStart) {
    D_807C1BE0 = audioSequenceStart;
    D_807C1BE4 = audioBankStart;
    D_807C1BE8 = audioTableStart;
    AudioLoad_Init(NULL, 0);
}

void Audio_SetSoundMode(u8 soundMode) {
    AUDIOCMD_GLOBAL_SET_SOUND_MODE(soundMode);
}

void func_80740B98(u8 arg0) {

    D_80771B6C[arg0] = 1;
    func_807418D4(14);
    func_80739B58();
}

void func_80740BD8(u8 arg0) {
    D_80771B1C = arg0;
}

void func_80740BE8(u8 arg0) {
    D_80771B00 = arg0;
}

void func_80740BF8(u8 playerNum, u8 arg1) {

    if ((D_80771B6C[playerNum] == 0) && (arg1 != D_80771D48[playerNum][0]) && (arg1 != D_80771D48[playerNum][1]) &&
        (arg1 != D_80771D48[playerNum][2]) && (arg1 != D_80771D48[playerNum][3]) &&
        (arg1 != D_80771D48[playerNum][4]) && (arg1 != D_80771D48[playerNum][5]) &&
        (arg1 != D_80771D48[playerNum][6]) && (arg1 != D_80771D48[playerNum][7])) {
        if (D_80771D38[playerNum][0] != 0) {
            if (D_80771D38[playerNum][1] != 0) {
                if (D_80771D38[playerNum][2] != 0) {
                    if (D_80771D38[playerNum][3] == 0) {
                        D_80771D38[playerNum][3] = arg1;
                    }
                } else {
                    D_80771D38[playerNum][2] = arg1;
                }
            } else {
                D_80771D38[playerNum][1] = arg1;
            }
        } else {
            D_80771D38[playerNum][0] = arg1;
        }
    }
}

void func_80740CE8(u8 playerNum, u8 arg1) {
    s32 temp;

    if (arg1 == D_80771D38[playerNum][0]) {
        D_80771D38[playerNum][0] = 0;
        if (D_80771D38[playerNum][1] != 0) {
            D_80771D38[playerNum][0] = D_80771D38[playerNum][1];
            D_80771D38[playerNum][1] = D_80771D38[playerNum][2];
            D_80771D38[playerNum][2] = D_80771D38[playerNum][3];
            D_80771D38[playerNum][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerNum][1]) {
        D_80771D38[playerNum][1] = 0;
        if (D_80771D38[playerNum][2] != 0) {
            D_80771D38[playerNum][1] = D_80771D38[playerNum][2];
            D_80771D38[playerNum][2] = D_80771D38[playerNum][3];
            D_80771D38[playerNum][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerNum][2]) {
        D_80771D38[playerNum][2] = 0;
        if (D_80771D38[playerNum][3] != 0) {
            D_80771D38[playerNum][2] = D_80771D38[playerNum][3];
            D_80771D38[playerNum][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerNum][3]) {
        D_80771D38[playerNum][3] = 0;
    }

    if (arg1 == D_80771D48[playerNum][0]) {
        D_80771D48[playerNum][0] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
        if (D_80771D48[playerNum][0] == 0) {
            func_807418D4(playerNum + 6);
        } else {
            func_807418D4(playerNum + 6);
            temp = D_80771D48[playerNum][0];
            D_80771D48[playerNum][0] = 0;
            func_80740BF8(playerNum, temp);
        }
    } else if (arg1 == D_80771D48[playerNum][1]) {
        D_80771D48[playerNum][1] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][2]) {
        D_80771D48[playerNum][2] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][3]) {
        D_80771D48[playerNum][3] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][4]) {
        D_80771D48[playerNum][4] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][5]) {
        D_80771D48[playerNum][5] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][6]) {
        D_80771D48[playerNum][6] = D_80771D48[playerNum][7];
        D_80771D48[playerNum][7] = 0;
    } else if (arg1 == D_80771D48[playerNum][7]) {
        D_80771D48[playerNum][7] = 0;
    }
}

void func_80740F80(u8 racerId, u8 arg1) {

    if (arg1 != D_80771CC0[racerId][0] && arg1 != D_80771CC0[racerId][1] && arg1 != D_80771CC0[racerId][2] &&
        arg1 != D_80771CC0[racerId][3]) {
        if (D_80771CC0[racerId][0] != 0) {
            if (D_80771CC0[racerId][1] != 0) {
                if (D_80771CC0[racerId][2] != 0) {
                    if (D_80771CC0[racerId][3] == 0) {
                        D_80771CC0[racerId][3] = arg1;
                    }
                } else {
                    D_80771CC0[racerId][2] = arg1;
                }
            } else {
                D_80771CC0[racerId][1] = arg1;
            }
        } else {
            D_80771CC0[racerId][0] = arg1;
        }
    }
}

extern u8 D_80771AF8;
extern f32 D_80771BD8[];

void func_80741014(u8 racerId, u8 arg1) {

    switch (D_80771AF8) {
        case 0:
        default:
            if (D_80771B6C[0] != 0) {
                return;
            }
            break;
        case 1:
        case 2:
        case 3:
            if (D_80771B6C[racerId] != 0) {
                return;
            }
            break;
    }

    if (arg1 == 0x1E) {
        goto block_5;
    }
    if (arg1 == 0x21) {
        goto block_5;
    }
    if (D_80771AC0 == 1) {
        return;
    }
block_5:

    if ((racerId == 0) || (racerId == 1) || (racerId == 2) || (racerId == 3)) {
        D_80771BD8[racerId] = 1.0f;
    } else if (D_80771AEC == 1) {
        return;
    }
    func_80740F80(racerId, arg1);
}

void func_8074110C(u8 ioData) {
    AUDIOCMD_CHANNEL_SET_PAN(0, 1, 0x3F);
    func_80741888(1, ioData);
    func_80739B58();
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074114C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074122C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741470.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074151C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741538.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741550.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741588.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074184C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741880.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741888.s")

void func_807418D4(u8 channelIndex) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 5, 1);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741910.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074199C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807419F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741A0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741AF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741B84.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741BC4.s")

void func_80741BCC(void) {
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741BD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741C58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741CB4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741DD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741E64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741E88.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741EB4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741EC4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741EF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80741FB4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742004.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742028.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074204C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074230C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742360.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742370.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807423C4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807423F4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074241C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807424CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742510.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074251C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074252C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807425D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742654.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074270C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742790.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_8074279C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807427C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742D50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742D90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742E2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742E6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742F04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742F44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742F68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80742FB8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807431A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807437CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80743874.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80743BCC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80743C40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80744280.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807442E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807443F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807447CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80744BDC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807450E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80745AF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/Audio_SetupCreateTask.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80745CB8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/D_80777A20.s")
