#include "global.h"
#include "audio.h"
#include "audio_funcs.h"
#include "audiothread_cmd.h"
#include "fzx_racer.h"

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
extern u16 D_80771B30;
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

extern u8 D_80771AC8;
extern u8 D_80771ACC;
extern u8 D_80771AD0;
extern u8 D_80771AD4;
extern u16 D_80771AD8;
extern u16 D_80771ADC;
extern u16 D_80771AE0;
extern u16 D_80771AE4;

void func_8074114C(u8 arg0, u16 arg1) {

    if ((arg0 != D_80771AC8) && (arg0 != D_80771ACC) && (arg0 != D_80771AD0) && (arg0 != D_80771AD4)) {
        if (D_80771AD8 != 0) {
            if (D_80771ADC != 0) {
                if (D_80771AE0 != 0) {
                    if (D_80771AE4 == 0) {
                        D_80771AD4 = arg0;
                        D_80771AE4 = arg1;
                    }
                } else {
                    D_80771AD0 = arg0;
                    D_80771AE0 = arg1;
                }
            } else {
                D_80771ACC = arg0;
                D_80771ADC = arg1;
            }
        } else {
            D_80771AC8 = arg0;
            D_80771AD8 = arg1;
        }
    }
}

extern s32 D_800D11D4;
extern u8 D_80771C94;

void func_8074122C(u8 arg0) {
    u8 i;

    if ((D_80771C94 == 1) && (D_800D11D4 == 0)) {
        return;
    }

    if (arg0 == 0xB) {
        D_80771CA8 = 0;
        for (i = 0; i < D_80771AF8 + 1; i++) {
            if (D_80771AC0 == 0) {
                func_8074184C(i);
            }
        }
    }
    if (arg0 == 0x11) {
        func_8074114C(arg0, 0x83);
    } else if (arg0 == 0x12) {
        func_8074114C(arg0, 0xB3);
    } else if (arg0 == 0x2A) {
        func_8074114C(arg0, 0xBE);
    } else if (arg0 == 0x2C) {
        func_8074114C(arg0, 0xC6);
    } else if (arg0 == 0x30) {
        func_8074114C(arg0, 0x9A);
    } else if (arg0 == 0x33) {
        func_8074114C(arg0, 0x9B);
    } else if (arg0 == 0x34) {
        func_8074114C(arg0, 0xE9);
    } else if (arg0 == 0x35) {
        func_8074114C(arg0, 0xCD);
    } else if (arg0 == 0x38) {
        func_8074114C(arg0, 0x71);
    } else if (arg0 == 0x3A) {
        func_8074114C(arg0, 0x68);
    } else if (arg0 == 0x3B) {
        func_8074114C(arg0, 0xB5);
    } else if (arg0 == 0x3C) {
        func_8074114C(arg0, 0x99);
    } else if (arg0 == 0x3D) {
        func_8074114C(arg0, 0x83);
    } else if (arg0 == 0x43) {
        func_8074114C(arg0, 0x9B);
    } else {
        func_8074110C(arg0);
    }
}

void func_80741470(u8 arg0, u8 arg1) {
    f32 volumeScale;

    AUDIOCMD_CHANNEL_SET_PAN(0, 15, func_80740838(arg0));

    if (arg1 >= 0x80) {
        arg1 = 0x7F;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }

    volumeScale = arg1 / 127.0f;
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
    func_80741888(15, 0x2D);
}

void func_8074151C(u8 arg0) {
    D_80771B70[arg0] = 1;
}

void func_80741538(u8 arg0) {
    D_80771B70[arg0] = 0;
}

void func_80741550(u8 arg0) {
    func_807418D4(arg0 + 2);
    D_80771B54[arg0] = 0;
}

void func_80741588(u8 arg0) {

    switch (D_80771AF8) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0x3F);
            if (D_80771B74[arg0] == 0) {
                func_80741888(arg0 + 2, 2);
            } else {
                func_80741888(arg0 + 2, 7);
            }
            break;
        case 1:
            switch (arg0) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0x7F);
                    break;
            }
            if (D_80771B74[arg0] == 0) {
                func_80741888(arg0 + 2, 0xC);
            } else {
                func_80741888(arg0 + 2, 0x11);
            }
            break;
        case 2:
            switch (arg0) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 4, 0x7F);
                    break;
            }
            if (D_80771B74[arg0] == 0) {
                func_80741888(arg0 + 2, 0x16);
            } else {
                func_80741888(arg0 + 2, 0x1B);
            }
            break;
        case 3:
            switch (arg0) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 2, 0);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 3, 0);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 4, 0x7F);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 5, 0x7F);
                    break;
            }
            if (D_80771B74[arg0] == 0) {
                func_80741888(arg0 + 2, 0x16);
            } else {
                func_80741888(arg0 + 2, 0x1B);
            }
    }
    func_80739B58();
}

void func_8074184C(u8 arg0) {
    func_80741588(arg0);
    D_80771B54[arg0] = 1;
}

void func_80741880(u8 arg0) {
}

void func_80741888(u8 channelIndex, u8 ioData) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 0, ioData);
    func_80739B58();
}

void func_807418D4(u8 channelIndex) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 5, 1);
}

extern u8 D_80771C5C;
extern u8 D_80771C78;
extern u8 D_80771C7C;
extern u16 D_80771C80;

void func_80741910(u8 arg0) {

    if ((D_80771C80 != 0) || (D_80771C7C != 0)) {
        D_80771C5C = arg0 + 1;
        return;
    }
    D_80771C78 = arg0;
    D_80771C7C = 1;

    AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(D_80771C78 + 4, 0, 0x3F);
    func_80739B58();
}

extern u8 D_80771C68;
extern u16 D_80771C6C;

void func_8074199C(void) {

    if (D_80771C6C == 0) {
        return;
    }

    D_80771C6C++;
    if (D_80771C6C == 30) {
        D_80771C6C = 0;
        func_80741910(D_80771C68);
        D_80771C68 = 0;
    }
}

void func_807419F0(u8 arg0) {
    D_80771C68 = arg0;
    D_80771C6C = 1;
}

extern u8 D_80771C60;
extern u8 D_80771C98;
extern u16 D_80771C9C;
extern u8 D_80771CA0;
extern u8 D_80771CA4;

void func_80741A0C(u8 arg0) {

    if (D_80771AC0 == 1) {
        return;
    }

    if ((D_80771C7C != 0) || (D_80771CA4 == 1)) {
        D_80771C60 = arg0 + 1;
        return;
    }
    D_80771B40 = arg0;
    D_80771CA0 = 1;
    D_80771C74 = 1;

    AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
    AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, arg0 + 2, 1.0f);
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, arg0 + 2, 0, 0);
    if (arg0 == 0x12) {
        D_80771C98 = 0;
        D_80771C9C = 0;
    }
    func_80739B58();
}

extern u8 D_80771C64;

void func_80741AF4(u8 arg0) {

    if ((D_80771C7C != 0) || (D_80771CA4 == 1)) {
        D_80771C64 = arg0;
        return;
    }
    D_80771CA0 = 1;
    D_80771C74 = 1;
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);
    D_80771B40 = arg0;
    D_80771C64 = arg0;
    D_80771C98 = 1;
    func_80739B58();
}

void func_80741B84(void) {
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 120);
    D_80771CA0 = 0;
    D_80771C74 = 0;
    D_80771C98 = 0;
    D_80771C9C = 0;
}

void func_80741BC4(u8 arg0) {
}

void func_80741BCC(void) {
}

extern u8 D_80771C58;

void func_80741BD4(u8 arg0) {

    if (arg0 != 0xE) {
        if ((D_80771C80 == 0) && (D_80771C7C == 0)) {
            D_80771C80 = 1;
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(arg0 + 4, 0, 1);
            return;
        }
        D_80771C58 = arg0 + 1;
    }
}

void func_80741C58(void) {
    u8 temp_a0;

    if ((D_80771C58 != 0) && (D_80771C80 != 1)) {
        temp_a0 = D_80771C58 - 1;
        if (D_80771C7C == 0) {
            D_80771C58 = 0;
            func_80741BD4(temp_a0);
        }
    }
}

extern u16 D_80771B2C;
extern u8 D_80771C54;

void func_80741CB4(u8 arg0) {
    s32 pad;

    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 1.0f);

    D_80771B40 = arg0;
    D_80771B28 = 0;
    D_80771B2C = 0;
    if (arg0 == 0x19) {
        func_80741B84();
    }
    switch (arg0) {
        case 14:
            AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, arg0 + 2, 0, 0);
            break;
        case 15:
        case 16:
            if (D_80771C80 == 0) {
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
                AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, arg0 + 2, 0, 0);
            } else {
                D_80771C54 = arg0 + 1;
            }
            break;
        default:
            func_80741888(0, arg0);
            break;
    }
    func_80739B58();
}

void func_80741DD4(void) {
    switch (D_80771B40) {
        case 14:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
            break;
        case 15:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
            break;
        case 16:
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
            break;
    }
    if (D_80771B28 == 0) {
        D_80771B28 = 1;
    }
}

void func_80741E64(void) {
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
}

void func_80741E88(void) {
    D_80771CA8 = 1;
    func_80741CB4(0x1C);
}

void func_80741EB4(void) {
    D_80771AC0 = 1;
}

void func_80741EC4(void) {
    func_8074251C();
    D_80771B38 = 1;
    D_80771AE8 = 1;
}

extern u16 D_80771B24;

void func_80741EF4(void) {
    D_80771B24 = 0;
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
    D_80771B1C = 64;
    D_80771B20 = 0;
    D_80771B38 = 0;
    D_80771B30 = 0;
    D_80771B28 = 0;
    func_80740740(0);
    func_8074184C(0);
}

void func_80741FB4(void) {
    D_80771AE8 = 0;
    D_80771B30 = 0;
    D_80771B38 = 0;
    D_80771B24 = 0;
    D_80771B20 = 0;
    func_807418D4(0xE);
    func_80740740(0);
}

void func_80742004(void) {
    if (D_80771B28 == 0) {
        D_80771B28 = 2;
    }
}

void func_80742028(void) {
    if (D_80771B28 == 0) {
        D_80771B28 = 3;
    }
}

extern u8 D_80771C50;
extern u8 D_80771CAC;
extern u16 D_80771CB0;

void func_8074204C(u8 arg0) {
    u32 sp34;
    u8 sp33;

    switch (arg0) {
        case 0:
            D_80771B20 = 0;
            if (D_80771C74 == 1) {
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            }
            break;
        case 1:
            D_80771B20 = 1;
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            if (D_80771C74 == 1) {
                AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 0.4f);
            }
            break;
        case 2:
            func_807418D4(2);
            func_807418D4(3);
            func_807418D4(4);
            func_807418D4(5);
            func_807418D4(6);
            func_807418D4(7);
            func_807418D4(8);
            func_807418D4(9);
            func_807418D4(14);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, 0.0f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, 0.0f);
            AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);

            switch (D_80771C7C) {
                case 0:
                    break;
                case 1:
                    sp33 = true;
                    D_80771CAC = 1;
                    while (sp33) {
                        if ((AudioThread_GetAsyncLoadStatus(&sp34) == 0x3F) || (D_80771CB0 > 300)) {
                            D_80771CB0 = 0;
                            D_80771C5C = 0;
                            D_80771C60 = 0;
                            D_80771C50 = 0;
                            D_80771C7C = 0;
                            sp33 = false;
                            D_80771CAC = 0;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
    }
    func_80739B58();
}

extern u8 D_80771B3C;
extern u8 D_80771C84;

void func_8074230C(s32 specId) {
    if (specId != D_80771B3C) {
        D_80771B3C = specId;
        D_80771C84 = 1;
        AudioThread_ResetAudioHeap(specId);
        do {
        } while (AudioThread_ResetComplete() == 0);
        D_80771C84 = 0;
    }
}

void func_80742360(u8 numPlayersIndex) {
    D_80771AF8 = numPlayersIndex;
}

void func_80742370(void) {
    func_807408AC();
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(0, 0);
    func_80739B58();
    if (D_80771C74 == 1) {
        AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);
    }
}

void func_807423C4(void) {
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 1, 0, 0);
    func_80739B58();
}

void func_807423F4(s32 arg0) {
    func_807408AC();
    func_80739B58();
}

void func_8074241C(u8 racerId, f32 arg1) {

    if (D_80771B6C[racerId] != 0) {
        return;
    }

    if (arg1 < -48.0f) {
        arg1 = -48.0f;
    }

    if (arg1 > -2.5f) {
        return;
    }
    D_80771BD8[racerId] = 0.2f - (arg1 / 58.0f);
    if (D_80771BD8[racerId] > 0.75f) {
        D_80771BD8[racerId] = 0.75f;
    }
    func_80740F80(racerId, 0x36);
}

s32 func_807424CC(void) {
    if ((D_80771CA0 == 0) && (D_80771C7C == 0)) {
        D_80771CA4 = 0;
    } else {
        D_80771CA4 = 1;
    }
    return D_80771CA4;
}

extern u8 D_80771CBC;

u8 func_80742510(void) {
    return D_80771CBC;
}

void func_8074251C(void) {
    D_80771AEC = 1;
}

void func_8074252C(void) {
    u8 sp1F;

    if (D_80771C98 == 0) {
        return;
    }

    D_80771C9C++;
    if (D_80771C9C == 30) {
        sp1F = D_80771C64;
        AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(1, sp1F + 2, 1.0f);
        AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, sp1F + 2, 0, 0);
        D_80771C9C = 0;
        D_80771C98 = 0;
    }
}

void func_807425D0(void) {
    u8 seqLoadComplete;
    u8 fontLoadComplete;
    u8 sampleLoadComplete;

    if (D_80771CA0 == 0) {
        return;
    }

    seqLoadComplete = AudioLoad_IsSeqLoadComplete(D_80771B40 + 2);
    fontLoadComplete = AudioLoad_IsFontLoadComplete(D_80771B40 + 2);
    sampleLoadComplete = AudioLoad_IsSampleLoadComplete(D_80771B40 + 4);
    if ((seqLoadComplete == true) && (fontLoadComplete == true) && (sampleLoadComplete == true)) {
        D_80771CA0 = 0;
    }
}

void func_80742654(void) {
    u32 sp24;

    if (D_80771C80 == 1) {
        return;
    }

    switch (D_80771C7C) {
        case 0:
            break;
        case 1:
            if (AudioThread_GetAsyncLoadStatus(&sp24) == 0x3F) {
                if (D_80771C5C != 0) {
                    func_807419F0(D_80771C5C - 1);
                    D_80771C5C = 0;
                }
                if (D_80771C60 != 0) {
                    func_80741A0C(D_80771C60 - 1);
                    D_80771C60 = 0;
                }
                if (D_80771C50 != 0) {
                    func_80741CB4(D_80771C50 - 1);
                    D_80771C50 = 0;
                }
                D_80771C7C = 0;
            }
            break;
        default:
            break;
    }
}

void func_8074270C(void) {
    u32 sp1C;

    if (D_80771C80 != 1) {
        return;
    }

    if (AudioThread_GetAsyncLoadStatus(&sp1C) == 1) {
        D_80771C80 = 0;
        if (D_80771C54 != 0) {
            AUDIOCMD_SEQPLAYER_FADE_VOLUME_SCALE(1, 1.0f);
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, D_80771C54 + 1, 0, 0);
            D_80771C54 = 0;
        }
    }
}

extern u8 D_80771C88;

s32 func_80742790(void) {
    return D_80771C88;
}

extern u16 D_80771C70;

void func_8074279C(void) {
    D_80771C70 = 1;
    D_80771B40 = 99;
    D_80771C88 = 1;
}

extern u8 D_80771CB4;

void func_807427C0(void) {
    u8 loadStatus;
    u32 sp20;
    u8 sp1F;
    u8 sp1E;
    u8 sp1D;

    switch (D_80771C70) {
        case 1:
            AUDIOCMD_GLOBAL_SYNC_LOAD_SEQ_PARTS(1, 2);
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(2, 0, 0x10);
            AUDIOCMD_GLOBAL_ASYNC_LOAD_SAMPLE_BANK(3, 0, 0x11);
            D_80771CB4 = 0;
            D_80771C70 = 2;
            break;
        case 2:
            loadStatus = AudioThread_GetAsyncLoadStatus(&sp20);
            if (loadStatus == 0x10) {
                D_80771CB4 |= 1;
            }
            if (loadStatus == 0x11) {
                D_80771CB4 |= 2;
            }
            if (D_80771CB4 == 3) {
                AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 0, 0, 0);
                D_80771C70 = 3;
                break;
            }
            break;
        case 3:
            sp1F = AudioLoad_IsSampleLoadComplete(2);
            sp1E = AudioLoad_IsFontLoadComplete(0);
            sp1D = AudioLoad_IsSeqLoadComplete(0);
            if ((sp1F == 1) && (sp1E == 1) && (sp1D == 1)) {
                D_80771C88 = 2;
                AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(1, 0x12);
                D_80771C70 = 4;
                break;
            }
            break;
        case 4:
            loadStatus = AudioThread_GetAsyncLoadStatus(&sp20);
            switch (loadStatus) {
                case 0x12:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(2, 0, 0x13);
                    break;
                case 0x13:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(3, 0, 0x14);
                    break;
                case 0x14:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(4, 0, 0x15);
                    break;
                case 0x15:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(5, 0, 0x16);
                    break;
                case 0x16:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(6, 0, 0x17);
                    break;
                case 0x17:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(7, 0, 0x18);
                    break;
                case 0x18:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(8, 0, 0x19);
                    break;
                case 0x19:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(9, 0, 0x1A);
                    break;
                case 0x1A:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(10, 0, 0x1B);
                    break;
                case 0x1B:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(11, 0, 0x1C);
                    break;
                case 0x1C:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(12, 0, 0x1D);
                    break;
                case 0x1D:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(13, 0, 0x1E);
                    break;
                case 0x1E:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(14, 0, 0x1F);
                    break;
                case 0x1F:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(15, 0, 0x20);
                    break;
                case 0x20:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(16, 0, 0x21);
                    break;
                case 0x21:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(17, 0, 0x22);
                    break;
                case 0x22:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(18, 0, 0x23);
                    break;
                case 0x23:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(19, 0, 0x24);
                    break;
                case 0x24:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(20, 0, 0x25);
                    break;
                case 0x25:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(21, 0, 0x26);
                    break;
                case 0x26:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_FONT(22, 0, 0x27);
                    break;
                case 0x27:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(2, 0x28);
                    break;
                case 0x28:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(3, 0x29);
                    break;
                case 0x29:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(4, 0x2A);
                    break;
                case 0x2A:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(5, 0x2B);
                    break;
                case 0x2B:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(6, 0x2C);
                    break;
                case 0x2C:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(7, 0x2D);
                    break;
                case 0x2D:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(8, 0x2E);
                    break;
                case 0x2E:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(9, 0x2F);
                    break;
                case 0x2F:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(10, 0x30);
                    break;
                case 0x30:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(11, 0x31);
                    break;
                case 0x31:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(14, 0x32);
                    break;
                case 0x32:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(13, 0x33);
                    break;
                case 0x33:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(12, 0x34);
                    break;
                case 0x34:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(15, 0x35);
                    break;
                case 0x35:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(16, 0x36);
                    break;
                case 0x36:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(17, 0x37);
                    break;
                case 0x37:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(18, 0x38);
                    break;
                case 0x38:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(19, 0x39);
                    break;
                case 0x39:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(20, 0x3A);
                    break;
                case 0x3A:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(21, 0x3B);
                    break;
                case 0x3B:
                    AUDIOCMD_GLOBAL_ASYNC_LOAD_SEQ(22, 0x3C);
                    break;
                case 0x3C:
                    D_80771C70 = 0;
                    break;
            }
            break;
        case 0:
        default:
            break;
    }
}

extern u16 D_80771C8C;

void func_80742D50(void) {
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
    func_80741910(0x12);
    D_80771C8C = 1;
    func_80742360(0);
}

extern s32 D_800D11D0;

void func_80742D90(void) {

    if (D_80771C8C == 0) {
        return;
    }

    D_80771C8C++;
    if ((D_80771C8C > 180) && (D_80771C7C == 0)) {
        if (D_800D11D0 == 1) {
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, 20, 0, 0);
            D_80771C74 = 1;
            D_80771B40 = 0x12;
        }
        D_80771C8C = 0;
        D_80771C94 = 1;
    }
}

extern u16 D_80771C90;

void func_80742E2C(void) {
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
    func_80741910(0x13);
    D_80771C90 = 1;
    func_80742360(0);
}

void func_80742E6C(void) {

    if (D_80771C90 == 0) {
        return;
    }

    D_80771C90++;
    if ((D_80771C90 > 150) && (D_80771C7C == 0)) {
        if (D_800D11D0 == 1) {
            AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, 21, 0, 0);
            D_80771B40 = 0x13;
        }
        D_80771C90 = 0;
        D_80771C94 = 1;
    }
    func_80739B58();
}

void func_80742F04(void) {
    func_8074122C(0x10);
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
    func_807419F0(0xF);
    D_80771C94 = 0;
    func_80739B58();
}

void func_80742F44(void) {
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 200);
}

void func_80742F68(void) {
    if (D_800D11D0 == 1) {
        AUDIOCMD_GLOBAL_INIT_SEQPLAYER(1, 20, 0, 0);
        D_80771C74 = 1;
        D_80771B40 = 0x12;
    }
}

void func_80742FB8(void) {
    f32 volumeScale;

    switch (D_80771B28) {
        case 1:
            D_80771B2C++;
            if (D_80771B2C == 0x22) {
                D_80771B28 = 0;
                D_80771B2C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_807418D4(0);
            } else {
                volumeScale = 1.0f - (D_80771B2C * (1.0f / 35.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
    
            break;
        case 2:
            D_80771B2C++;
            if (D_80771B2C == 0x45) {
                D_80771B28 = 0;
                D_80771B2C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_807418D4(0);
            } else {
                volumeScale = 1.0f - (D_80771B2C * (1.0f / 70.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 3:
            D_80771B2C++;
            if (D_80771B2C == 0x15D) {
                D_80771B28 = 0;
                D_80771B2C = 0;
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, 0.0f);
                func_807418D4(0);
            } else {
                volumeScale = 1.0f - (D_80771B2C * (1.0f / 350.0f));
                AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
            }
            break;
        case 0:
        default:
            break;
    }
}

void func_807431A8(void) {
    f32 volumeScale;
    s8 reverbVolume;

    if (D_80771B38 == 0 || D_80771B20 == 2) {
        return;
    }

    D_80771B30++;
    if (D_80771B30 == 29) {
        D_80771B38 = 0;
        D_80771B30 = 0;
        func_807418D4(2);
        func_807418D4(3);
        func_807418D4(4);
        func_807418D4(5);
        func_807418D4(6);
        func_807418D4(7);
        func_807418D4(8);
        func_807418D4(9);
        func_807418D4(14);
        D_80771B54[0] = 0;
        D_80771B54[1] = 0;
        D_80771B54[2] = 0;
        D_80771B54[3] = 0;
        return;
    }
    reverbVolume = 0x50 - (D_80771B30 * 2);
    if (D_80771B54[0] == 1) {
        volumeScale = D_80771B78[2] - ((D_80771B78[2] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 2, volumeScale);
        if (D_80771B70[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, reverbVolume);
        }
    }
    if (D_80771B54[1] == 1) {
        volumeScale = D_80771B78[3] - ((D_80771B78[3] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 3, volumeScale);
        if (D_80771B70[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, reverbVolume);
        }
    }
    if (D_80771B54[2] == 1) {
        volumeScale = D_80771B78[4] - ((D_80771B78[4] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 4, volumeScale);
        if (D_80771B70[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, reverbVolume);
        }
    }
    if (D_80771B54[3] == 1) {
        volumeScale = D_80771B78[5] - ((D_80771B78[5] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 5, volumeScale);
        if (D_80771B70[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, reverbVolume);
        }
    }
    if ((D_80771B54[0] != 0) && (D_80771D48[0][0] != 0) && (D_80771B78[6] != 0.0f)) {
        volumeScale = D_80771B78[6] - ((D_80771B78[6] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 6, volumeScale);
        if (D_80771B70[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, reverbVolume);
        }
    }
    if ((D_80771B54[1] != 0) && (D_80771D48[1][0] != 0) && (D_80771B78[7] != 0.0f)) {
        volumeScale = D_80771B78[7] - ((D_80771B78[7] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 7, volumeScale);
        if (D_80771B70[1] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, reverbVolume);
        }
    }
    if ((D_80771B54[2] != 0) && (D_80771D48[2][0] != 0) && (D_80771B78[8] != 0.0f)) {
        volumeScale = D_80771B78[8] - ((D_80771B78[8] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 8, volumeScale);
        if (D_80771B70[2] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, reverbVolume);
        }
    }
    if ((D_80771B54[3] != 0) && (D_80771D48[3][0] != 0) && (D_80771B78[9] != 0.0f)) {
        volumeScale = D_80771B78[9] - ((D_80771B78[9] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 9, volumeScale);
        if (D_80771B70[3] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, reverbVolume);
        }
    }
    if ((D_80771AFC != 0) && (D_80771B78[14] != 0.0f)) {
        volumeScale = D_80771B78[14] - ((D_80771B78[14] / 30.0f) * D_80771B30);
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, volumeScale);
        if (D_80771B70[0] == 1) {
            AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, reverbVolume);
        }
    }
}

void func_807437CC(void) {
    f32 volumeScale;

    if (D_80771B20 == 2) {
        D_80771B24++;
        if (D_80771B24 == 0x31) {
            D_80771B20 = 0;
            D_80771B24 = 0;
            func_807418D4(0);
        } else {
            volumeScale = 0.4f - (D_80771B24 * 0.008f);
            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 0, volumeScale);
        }
    }
}

void func_80743874(u8 playerNum, u8 arg1) {

    if (D_80771D48[playerNum][0] == 0) {
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][1] == 0) {
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][2] == 0) {
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][3] == 0) {
        D_80771D48[playerNum][3] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][4] == 0) {
        D_80771D48[playerNum][4] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][5] == 0) {
        D_80771D48[playerNum][5] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][6] == 0) {
        D_80771D48[playerNum][6] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    } else if (D_80771D48[playerNum][7] == 0) {
        D_80771D48[playerNum][7] = D_80771D48[playerNum][6];
        D_80771D48[playerNum][6] = D_80771D48[playerNum][5];
        D_80771D48[playerNum][5] = D_80771D48[playerNum][4];
        D_80771D48[playerNum][4] = D_80771D48[playerNum][3];
        D_80771D48[playerNum][3] = D_80771D48[playerNum][2];
        D_80771D48[playerNum][2] = D_80771D48[playerNum][1];
        D_80771D48[playerNum][1] = D_80771D48[playerNum][0];
        D_80771D48[playerNum][0] = arg1;
    }
    switch (D_80771AF8) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0x3F);
            func_80741888(6, arg1);
            break;
        case 1:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_80741888(6, arg1 + 10);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0x7F);
                    func_80741888(7, arg1 + 10);
                    break;
            }
            break;
        case 2:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_80741888(6, arg1 + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    func_80741888(7, arg1 + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    func_80741888(8, arg1 + 20);
                    break;
            }
            break;
        case 3:
            switch (playerNum) {
                case 0:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0);
                    func_80741888(6, arg1 + 20);
                    break;
                case 1:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 7, 0);
                    func_80741888(7, arg1 + 20);
                    break;
                case 2:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 8, 0x7F);
                    func_80741888(8, arg1 + 20);
                    break;
                case 3:
                    AUDIOCMD_CHANNEL_SET_PAN(0, 9, 0x7F);
                    func_80741888(9, arg1 + 20);
                    break;
            }
            break;
    }
}

void func_80743BCC(u8 arg0) {

    if (D_80771CA8 == 1) {
        return;
    }

    if (D_80771D38[arg0][0] != 0) {
        func_80743874(arg0, D_80771D38[arg0][0]);
        D_80771D38[arg0][0] = D_80771D38[arg0][1];
        D_80771D38[arg0][1] = D_80771D38[arg0][2];
        D_80771D38[arg0][2] = D_80771D38[arg0][3];
        D_80771D38[arg0][3] = 0;
    }
}

extern Player gPlayers[];

void func_80743C40(u8 arg0, u8 arg1) {
    f32 volumeScale;
    f32 freqScale;
    f32 var_fv1;
    Vec3f vec;
    u8 pan;

    if ((D_80771B54[arg0] != 0) || (arg1 == 0x16) || (arg1 == 0x10) || (arg1 == 0x21) || (arg1 == 0x1E) ||
        (arg1 == 5) || (arg1 == 8) || (arg1 == 0xF) || (arg1 == 0x30) || (arg1 == 0x31) || (arg1 == 0x34) ||
        (arg1 == 0x35) || (arg1 == 0x3E)) {
        D_80771BB8[arg0] = arg1;
        switch (D_80771AF8) {
            case 0:
                if (arg0 == 0) {
                    AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0x3F);
                    volumeScale = D_80771BD8[arg0];
                    AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);

                    if (arg1 >= 0x3F || arg1 < 0) {
                        arg1 = 0;
                    }
                    func_80741888(10, arg1);
                } else if (D_80771AFC != 0) {
                    if (arg0 == D_80771B00) {
                        var_fv1 = D_80771B10;
                    } else {
                        vec.x = gRacers[arg0].unk_0C.unk_34.x - gPlayers[0].unk_50.x;
                        vec.y = gRacers[arg0].unk_0C.unk_34.y - gPlayers[0].unk_50.y;
                        vec.z = gRacers[arg0].unk_0C.unk_34.z - gPlayers[0].unk_50.z;

                        var_fv1 = sqrtf(SQ_SUM(&vec));
                    }
                    if ((var_fv1 < 10000.0f) && (var_fv1 > 0.0f)) {
                        volumeScale = (-(9.0f / 190000.0f) * var_fv1) + 0.87f;
                        if (volumeScale > 0.24f) {
                            if (volumeScale > 0.68f) {
                                volumeScale = 0.68f;
                            }

                            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 15, volumeScale);
                            if (arg0 == D_80771B00) {
                                freqScale = (D_80771B18 * (2.0f / 7.0f)) + 0.2f;
                            } else {
                                freqScale = volumeScale * 1.2f;
                            }
                            if (freqScale > 2.0f) {
                                freqScale = 2.0f;
                            }
                            if (freqScale < 0.1f) {
                                freqScale = 0.1f;
                            }

                            AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, 15, freqScale);

                            if (arg0 == D_80771B00) {
                                pan = func_80740838(D_80771B1C);
                            } else {
                                pan = 0x3F;
                            }
                            AUDIOCMD_CHANNEL_SET_PAN(0, 15, pan);
                            func_80741888(15, arg1);
                        }
                    }
                }
                break;
            case 1:
                volumeScale = D_80771BD8[arg0] * 0.975f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_80741888(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_80741888(11, arg1);
                        break;
                }
                break;
            case 2:
                volumeScale = D_80771BD8[arg0] * 0.95f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_80741888(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_80741888(11, arg1);
                        break;
                    case 2:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                        func_80741888(12, arg1);
                        break;
                }
                break;
            case 3:
                volumeScale = D_80771BD8[arg0] * 0.95f;
                switch (arg0) {
                    case 0:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 10, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 10, volumeScale);
                        func_80741888(10, arg1);
                        break;
                    case 1:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 11, 0);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 11, volumeScale);
                        func_80741888(11, arg1);
                        break;
                    case 2:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 12, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 12, volumeScale);
                        func_80741888(12, arg1);
                        break;
                    case 3:
                        AUDIOCMD_CHANNEL_SET_PAN(0, 13, 0x7F);
                        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 13, volumeScale);
                        func_80741888(13, arg1);
                        break;
                }
                break;
        }
    }
}

void func_80744280(u8 racerId) {

    if (D_80771CC0[racerId][0] != 0) {
        func_80743C40(racerId, D_80771CC0[racerId][0]);
        D_80771CC0[racerId][0] = D_80771CC0[racerId][1];
        D_80771CC0[racerId][1] = D_80771CC0[racerId][2];
        D_80771CC0[racerId][2] = D_80771CC0[racerId][3];
        D_80771CC0[racerId][3] = 0;
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807442E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807443F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807447CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80744BDC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_807450E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80745AF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/Audio_SetupCreateTask.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/func_80745CB8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/4DF40/D_80777A20.s")
