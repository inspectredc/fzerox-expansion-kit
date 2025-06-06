#include "global.h"
#include "audio.h"
#include "audio_funcs.h"
#include "audiothread_cmd.h"
#include "fzx_game.h"
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
}

void func_80740BD8(u8 arg0) {
    D_80771B1C = arg0;
}

void func_80740BE8(u8 arg0) {
    D_80771B00 = arg0;
}

void func_80740BF8(u8 playerIndex, u8 arg1) {

    if ((D_80771B6C[playerIndex] == 0) && (arg1 != D_80771D48[playerIndex][0]) && (arg1 != D_80771D48[playerIndex][1]) &&
        (arg1 != D_80771D48[playerIndex][2]) && (arg1 != D_80771D48[playerIndex][3]) &&
        (arg1 != D_80771D48[playerIndex][4]) && (arg1 != D_80771D48[playerIndex][5]) &&
        (arg1 != D_80771D48[playerIndex][6]) && (arg1 != D_80771D48[playerIndex][7])) {
        if (D_80771D38[playerIndex][0] != 0) {
            if (D_80771D38[playerIndex][1] != 0) {
                if (D_80771D38[playerIndex][2] != 0) {
                    if (D_80771D38[playerIndex][3] == 0) {
                        D_80771D38[playerIndex][3] = arg1;
                    }
                } else {
                    D_80771D38[playerIndex][2] = arg1;
                }
            } else {
                D_80771D38[playerIndex][1] = arg1;
            }
        } else {
            D_80771D38[playerIndex][0] = arg1;
        }
    }
}

void func_80740CE8(u8 playerIndex, u8 arg1) {
    s32 temp;

    if (arg1 == D_80771D38[playerIndex][0]) {
        D_80771D38[playerIndex][0] = 0;
        if (D_80771D38[playerIndex][1] != 0) {
            D_80771D38[playerIndex][0] = D_80771D38[playerIndex][1];
            D_80771D38[playerIndex][1] = D_80771D38[playerIndex][2];
            D_80771D38[playerIndex][2] = D_80771D38[playerIndex][3];
            D_80771D38[playerIndex][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerIndex][1]) {
        D_80771D38[playerIndex][1] = 0;
        if (D_80771D38[playerIndex][2] != 0) {
            D_80771D38[playerIndex][1] = D_80771D38[playerIndex][2];
            D_80771D38[playerIndex][2] = D_80771D38[playerIndex][3];
            D_80771D38[playerIndex][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerIndex][2]) {
        D_80771D38[playerIndex][2] = 0;
        if (D_80771D38[playerIndex][3] != 0) {
            D_80771D38[playerIndex][2] = D_80771D38[playerIndex][3];
            D_80771D38[playerIndex][3] = 0;
        }
    }
    if (arg1 == D_80771D38[playerIndex][3]) {
        D_80771D38[playerIndex][3] = 0;
    }

    if (arg1 == D_80771D48[playerIndex][0]) {
        D_80771D48[playerIndex][0] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
        if (D_80771D48[playerIndex][0] == 0) {
            func_807418D4(playerIndex + 6);
        } else {
            func_807418D4(playerIndex + 6);
            temp = D_80771D48[playerIndex][0];
            D_80771D48[playerIndex][0] = 0;
            func_80740BF8(playerIndex, temp);
        }
    } else if (arg1 == D_80771D48[playerIndex][1]) {
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][2]) {
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][3]) {
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][4]) {
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][5]) {
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][6]) {
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][7];
        D_80771D48[playerIndex][7] = 0;
    } else if (arg1 == D_80771D48[playerIndex][7]) {
        D_80771D48[playerIndex][7] = 0;
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
}

void func_8074184C(u8 arg0) {
    func_80741588(arg0);
    D_80771B54[arg0] = 1;
}

void func_80741880(u8 arg0) {
}

void func_80741888(u8 channelIndex, u8 ioData) {
    AUDIOCMD_CHANNEL_SET_IO(0, channelIndex, 0, ioData);
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
    if (D_80771C74 == 1) {
        AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 0);
    }
}

void func_807423C4(void) {
    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 1, 0, 0);
    AudioThread_ScheduleProcessCmds();
}

void func_807423F4(s32 arg0) {
    func_807408AC();
    AudioThread_ScheduleProcessCmds();
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
    AudioThread_ScheduleProcessCmds();
}

void func_80742F04(void) {
    func_8074122C(0x10);
    AUDIOCMD_GLOBAL_DISABLE_SEQPLAYER(1, 100);
    func_807419F0(0xF);
    D_80771C94 = 0;
    AudioThread_ScheduleProcessCmds();
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

void func_80743874(u8 playerIndex, u8 arg1) {

    if (D_80771D48[playerIndex][0] == 0) {
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][1] == 0) {
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][2] == 0) {
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][3] == 0) {
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][4] == 0) {
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][5] == 0) {
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][6] == 0) {
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    } else if (D_80771D48[playerIndex][7] == 0) {
        D_80771D48[playerIndex][7] = D_80771D48[playerIndex][6];
        D_80771D48[playerIndex][6] = D_80771D48[playerIndex][5];
        D_80771D48[playerIndex][5] = D_80771D48[playerIndex][4];
        D_80771D48[playerIndex][4] = D_80771D48[playerIndex][3];
        D_80771D48[playerIndex][3] = D_80771D48[playerIndex][2];
        D_80771D48[playerIndex][2] = D_80771D48[playerIndex][1];
        D_80771D48[playerIndex][1] = D_80771D48[playerIndex][0];
        D_80771D48[playerIndex][0] = arg1;
    }
    switch (D_80771AF8) {
        case 0:
            AUDIOCMD_CHANNEL_SET_PAN(0, 6, 0x3F);
            func_80741888(6, arg1);
            break;
        case 1:
            switch (playerIndex) {
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
            switch (playerIndex) {
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
            switch (playerIndex) {
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

extern s32 gNumPlayers;
extern s8 D_8076C7D8;
extern s32 gGameMode;

void func_807442E4(void) {
    s32 temp_lo;
    SequenceLayer* layer;
    Note* note;

    if ((D_80771B40 == 0xE) && (IS_SEQUENCE_CHANNEL_VALID(gAudioCtx.seqPlayers[1].channels[0]))) {
        layer = gAudioCtx.seqPlayers[1].channels[0]->layers[0];
        if (layer != NULL) {
            note = layer->note;
            if (note != NULL) {
                temp_lo = (s32) note->synthesisState.samplePosInt / 100;

                switch (gNumPlayers) {
                    case 1:
                    case 2:
                        break;
                    default:
                        // FAKE
                        if (note && note && note) {}
                        break;
                }

                if ((temp_lo > 2100) && (temp_lo < 2110) && (gGameMode == GAMEMODE_FLX_TITLE) && (D_8076C7D8 == 0)) {
                    if (!note) {}
                    D_8076C7D8 = 1;
                }
                if ((temp_lo > 8200) && (temp_lo < 8210) && (D_8076C7D8 == 1)) {
                    D_8076C7D8 = 3;
                }
                if (temp_lo > 250 && temp_lo < 260) {
                    AUDIOCMD_GLOBAL_INIT_SEQPLAYER(0, 1, 0, 0);
                }
            }
        }
    }
}

void func_807443F0(void) {
    Vec3f vec;

    if ((D_80771AC0 != 1) && (D_80771AF8 == 0) && (D_80771B00 != 0) && (D_80771B20 != 1) && (D_80771B20 != 2) &&
        ((gGameMode == GAMEMODE_GP_RACE) || (gGameMode == GAMEMODE_PRACTICE) || (gGameMode == GAMEMODE_DEATH_RACE)) &&
        (D_80771B38 == 0) && (D_80771B6C[0] == 0)) {
        if (gRacers[D_80771B00].unk_17C > 9.0f) {
            vec.x = gRacers[D_80771B00].unk_0C.unk_34.x - gPlayers[0].unk_50.x;
            vec.y = gRacers[D_80771B00].unk_0C.unk_34.y - gPlayers[0].unk_50.y;
            vec.z = gRacers[D_80771B00].unk_0C.unk_34.z - gPlayers[0].unk_50.z;
            D_80771B10 = sqrtf(SQ_SUM(&vec));
        }
        if (gRacers[D_80771B00].unk_17C > 9.0f) {
            if ((D_80771B10 < 820.0f) && (D_80771B10 != 0.0f)) {
                if (D_80771AFC == 0) {
                    if (D_80771B6C[0] == 0) {
                        if (D_80771AE8 == 0) {
                            func_80741888(14, 1);
                        }
                        D_80771AFC = 2;
                    }
                } else {
                    D_80771AFC = 1;
                }
            } else {
                if (D_80771AFC == 1) {
                    func_807418D4(14);
                    D_80771AFC = 0;
                }
            }
        }
        if (D_80771AFC != 0) {
            D_80771B14 = 1.0f - (D_80771B10 * (1.0f / 1000.0f));
            if (D_80771B14 > 0.9f) {
                D_80771B14 = 0.9f;
            }
            if (D_80771B14 < 0.001f) {
                D_80771B14 = 0.001f;
            }
            if (D_80771B00 == D_80771B04) {
                D_80771B0C = (D_80771B08 - D_80771B10) * (1.0f / 30.0f);
            }
            D_80771B08 = D_80771B10;
            D_80771B04 = D_80771B00;

            D_80771B18 = ((gRacers[D_80771B00].speed + 0.01f) * (1.0f / 21.0f)) + 0.5f + D_80771B0C;
            if (D_80771B18 < 0.1f) {
                D_80771B18 = 0.1f;
            }

            AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, 14, D_80771B14);
            D_80771B78[14] = D_80771B14;
            AUDIOCMD_CHANNEL_SET_PAN(0, 14, func_80740838(D_80771B1C));
            AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, 14, D_80771B18);
        }
    }
}

void func_807447CC(u8 playerId) {
    f32 freqScale;
    f32 volumeScale;

    if ((D_80771B20 != 1) && (D_80771B20 != 2)) {
        if (D_80771B54[playerId] == 0) {
            if (D_80771B74[playerId] == 0) {
                return;
            }
        }

        if (gRacers[playerId].speed < D_80771B5C[playerId]) {
            D_80771B58[playerId] = 1;
        } else {
            D_80771B58[playerId] = 0;
        }
        D_80771B5C[playerId] = gRacers[playerId].speed;
        if (D_80771B74[playerId] == 0) {
            if ((gRacers[playerId].unk_1D4 != 0.0f) && (gRacers[playerId].speed > 27.0f)) {
                if (D_80771B58[playerId] == 1) {
                    if (D_80771B44[playerId] > -0.5f) {
                        D_80771B44[playerId] -= 0.004f;
                    }
                } else {
                    D_80771B44[playerId] += 0.004f;
                }
            } else {
                D_80771B44[playerId] = 0.0f;
            }
            if (gRacers[playerId].unk_20C != 0) {
                D_80771B44[playerId] = 0.0f;
            }
        } else {
            // FAKE
        }

        freqScale = (((0.01f + gRacers[playerId].speed) * (1.0f / 21.0f)) + 0.25f) + D_80771B44[playerId];
        AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, playerId + 2, freqScale);

        if ((gRacers[playerId].unk_1D4 == 0.0f) && (gRacers[playerId].unk_1D8 == 0.0f)) {
            if (D_80771B74[playerId] == 1) {
                Vec3f vec;
                f32 temp;

                vec.x = gRacers[playerId].unk_0C.unk_34.x - gPlayers[playerId].unk_50.x;
                vec.y = gRacers[playerId].unk_0C.unk_34.y - gPlayers[playerId].unk_50.y;
                vec.z = gRacers[playerId].unk_0C.unk_34.z - gPlayers[playerId].unk_50.z;
                temp = sqrtf(SQ_SUM(&vec));
                volumeScale = (-0.002f * temp + 1.2f) * 0.65f;

                if (volumeScale > 0.7f) {
                    volumeScale = 0.7f;
                }
                if (volumeScale < 0.01f) {
                    volumeScale = 0.01f;
                }
            } else {
                volumeScale = 0.75f;
            }
        } else if (D_80771B74[playerId] == 1) {
            Vec3f vec;
            f32 temp;

            vec.x = gRacers[playerId].unk_0C.unk_34.x - gPlayers[playerId].unk_50.x;
            vec.y = gRacers[playerId].unk_0C.unk_34.y - gPlayers[playerId].unk_50.y;
            vec.z = gRacers[playerId].unk_0C.unk_34.z - gPlayers[playerId].unk_50.z;
            temp = sqrtf(SQ_SUM(&vec));
            volumeScale = -0.002f * temp + 1.2f;

            if (volumeScale > 0.73f) {
                volumeScale = 0.73f;
            }
            if (volumeScale < 0.01f) {
                volumeScale = 0.01f;
            }
        } else {
            volumeScale = 1.0f;
        }

        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, playerId + 2, volumeScale);
        D_80771B78[playerId + 2] = volumeScale;
    }
}

void func_80744BDC(u8 arg0) {
    f32 freqScale;
    f32 volumeScale;

    if (D_80771CA8 == 1) {
        return;
    }

    if (D_80771B6C[arg0] != 0) {
        if (D_80771B6C[arg0] < 8) {
            D_80771B6C[arg0] += 1;
        }

        if (D_80771B6C[arg0] == 8) {
            func_807418D4(arg0 + 2);
            func_807418D4(arg0 + 6);
        }
    }

    if ((D_80771B20 != 1) && (D_80771B20 != 2) && (D_80771B54[arg0] != 0) && (D_80771B38 == 0)) {
        switch (D_80771D48[arg0][0]) {
            case 0:
                volumeScale = 0.0f;
                freqScale = 1.0f;
                break;
            case 3:
            case 4:
            case 10:
            case 13:
            case 14:
            case 20:
            case 23:
            case 24:
            case 30:
                volumeScale = 1.0f;
                freqScale = 1.0f;
                break;
            case 5:
            case 15:
            case 25:
                volumeScale = (gRacers[arg0].speed * (1.0f / 45.0f)) + 0.5f;
                if (gRacers[arg0].speed < 0.1f) {
                    volumeScale = 0.0f;
                }
                if (volumeScale > 1.0f) {
                    volumeScale = 1.0f;
                }
                if (volumeScale < 0.1f) {
                    volumeScale = 0.0f;
                }
                freqScale = 1.0f;
                break;
            case 11:
            case 21:
            case 31:
                volumeScale = (gRacers[arg0].speed * (1.0f / 45.0f)) + 0.5f;
                if (gRacers[arg0].speed < 0.1f) {
                    volumeScale = 0.0f;
                }
                if (volumeScale > 1.0f) {
                    volumeScale = 1.0f;
                }
                if (volumeScale < 0.1f) {
                    volumeScale = 0.0f;
                }
                freqScale = 1.0f;
                break;
            case 8:
            case 18:
            case 28:
                volumeScale = 0.8f;
                freqScale = (gRacers[arg0].speed * (1.0f / 30.0f)) - (8.0f / 10.0f);
                if (freqScale > 2.5f) {
                    freqScale = 2.5f;
                }
                if (freqScale < 0.3f) {
                    freqScale = 0.3f;
                }
                break;
            case 9:
            case 19:
            case 29:
                volumeScale = 0.85f;
                freqScale = gRacers[arg0].speed * (1.0f / 20.0f);
                if (freqScale > 8.0f) {
                    freqScale = 8.0f;
                }
                if (freqScale < 0.1f) {
                    freqScale = 0.1f;
                }
                break;
            case 6:
            case 16:
            case 26:
                if (gRacers[arg0].unk_5C.x > 0.0f) {
                    volumeScale = gRacers[arg0].unk_5C.x * (2.0f / 30.0f);
                    freqScale = (gRacers[arg0].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
                    if (volumeScale > 1.0f) {
                        volumeScale = 1.0f;
                    }
                    if (volumeScale < 0.1f) {
                        volumeScale = 0.0f;
                    }
                    if (freqScale > 1.3f) {
                        freqScale = 1.3f;
                    }
                    if (freqScale < 0.3f) {
                        freqScale = 0.3f;
                    }
                } else {
                    volumeScale = -gRacers[arg0].unk_5C.x * (1.0f / 15.0f);
                    freqScale = (-gRacers[arg0].unk_5C.x * (1.0f / 80.0f)) + 1.0f;
                    if (volumeScale > 1.0f) {
                        volumeScale = 1.0f;
                    }
                    if (volumeScale < 0.1f) {
                        volumeScale = 0.0f;
                    }
                    if (freqScale > 1.3f) {
                        freqScale = 1.3f;
                    }
                    if (freqScale < 0.3f) {
                        freqScale = 0.3f;
                    }
                }
                break;
        }

        D_80771B78[arg0 + 6] = volumeScale;
        AUDIOCMD_CHANNEL_SET_VOL_SCALE(0, arg0 + 6, volumeScale);
        AUDIOCMD_CHANNEL_SET_FREQ_SCALE(0, arg0 + 6, freqScale);
    }
}

void func_807450E0(u8 arg0) {
    switch (D_80771AF8) {
        case 0:
            if (D_80771B70[0] == 1) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 80);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_80771BB8[0] == 19) || (D_80771BB8[0] == 20) || (D_80771BB8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_80771D48[0][0] == 3) || (D_80771D48[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 15, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 14, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            break;
        case 1:
            if ((D_80771B70[0] == 1) || (D_80771B70[1] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (D_80771B70[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_80771BB8[0] == 19) || (D_80771BB8[0] == 20) || (D_80771BB8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_80771D48[0][0] == 3) || (D_80771D48[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_80771B70[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_80771BB8[1] == 19) || (D_80771BB8[1] == 20) || (D_80771BB8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_80771D48[1][0] == 3) || (D_80771D48[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            break;
        case 2:
            if ((D_80771B70[0] == 1) || (D_80771B70[1] == 1) || (D_80771B70[2] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (D_80771B70[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_80771BB8[0] == 19) || (D_80771BB8[0] == 20) || (D_80771BB8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_80771D48[0][0] == 3) || (D_80771D48[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_80771B70[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_80771BB8[1] == 19) || (D_80771BB8[1] == 20) || (D_80771BB8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_80771D48[1][0] == 3) || (D_80771D48[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (D_80771B70[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((D_80771BB8[2] == 19) || (D_80771BB8[2] == 20) || (D_80771BB8[2] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((D_80771D48[2][0] == 3) || (D_80771D48[2][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            break;
        case 3:
            if ((D_80771B70[0] == 1) || (D_80771B70[1] == 1) || (D_80771B70[2] == 1) || (D_80771B70[3] == 1)) {
                gAudioCtx.synthesisReverbs[0].volume = 0x7FFF;
            } else {
                gAudioCtx.synthesisReverbs[0].volume = 0;
            }
            if (D_80771B70[0] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 80);
                if ((D_80771BB8[0] == 19) || (D_80771BB8[0] == 20) || (D_80771BB8[0] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 80);
                }
                if ((D_80771D48[0][0] == 3) || (D_80771D48[0][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 2, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 10, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 6, 0);
            }
            if (D_80771B70[1] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 80);
                if ((D_80771BB8[1] == 19) || (D_80771BB8[1] == 20) || (D_80771BB8[1] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 80);
                }
                if ((D_80771D48[1][0] == 3) || (D_80771D48[1][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 3, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 11, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 7, 0);
            }
            if (D_80771B70[2] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 80);
                if ((D_80771BB8[2] == 19) || (D_80771BB8[2] == 20) || (D_80771BB8[2] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 80);
                }
                if ((D_80771D48[2][0] == 3) || (D_80771D48[2][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 4, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 12, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 8, 0);
            }
            if (D_80771B70[3] == 1) {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 80);
                if ((D_80771BB8[3] == 19) || (D_80771BB8[3] == 20) || (D_80771BB8[3] == 21)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 80);
                }
                if ((D_80771D48[3][0] == 3) || (D_80771D48[3][0] == 4)) {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 0);
                } else {
                    AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 80);
                }
            } else {
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 5, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 13, 0);
                AUDIOCMD_CHANNEL_SET_REVERB_VOLUME(0, 9, 0);
            }
            break;
    }
}

extern u8 D_80771AC4;

void func_80745AF4(void) {

    if ((D_80771AC4 == 0) && (D_80771AC8 != 0)) {
        func_8074110C(D_80771AC8);
    }

    D_80771AC4 = D_80771AC8;
    if (D_80771AD8 != 0) {
        D_80771AD8--;
        if (D_80771AD8 == 0) {
            D_80771AC8 = D_80771ACC;
            D_80771AD8 = D_80771ADC;
            D_80771ACC = D_80771AD0;
            D_80771ADC = D_80771AE0;
            D_80771AD0 = D_80771AD4;
            D_80771AE0 = D_80771AE4;
            D_80771AC4 = 0;
            D_80771AD4 = 0;
            D_80771AE4 = 0;
        }
    }
}

extern AudioTask* gCurAudioTask;
extern s32 D_80771968;
extern u8 D_80771CB8;

AudioTask* Audio_SetupCreateTask(void) {
    AudioTask* curAudioTask;

    if (D_80771C84 == 0) {
        func_807427C0();
    }
    func_80742D90();
    func_80742E6C();
    if (D_80771CAC == 1) {
        D_80771CB0++;
    }
    if (D_80771968 == 0) {
        if (D_80771CB8 > 10) {
            D_80771CBC = 0;
        } else {
            D_80771CB8++;
        }
    } else {
        D_80771CB8 = 0;
        D_80771CBC = D_80771968;
    }
    func_80742FB8();
    func_807431A8();
    func_807437CC();
    AudioThread_ScheduleProcessCmds();
    gCurAudioTask = curAudioTask = AudioThread_CreateTask();

    return curAudioTask;
}

void func_80745CB8(void) {
    u8 i;

    func_80742654();
    func_8074252C();
    func_8074270C();
    func_80741C58();
    func_807425D0();
    func_8074199C();
    func_807443F0();
    func_807442E4();
    func_80745AF4();

    for (i = 0; i < D_80771AF8 + 1; i++) {
        func_807447CC(i);
        func_807450E0(i);
        func_80743BCC(i);
        func_80744BDC(i);
    }
    if (D_80771AF8 == 0) {
        for (i = 0; i < 30; i++) {
            func_80744280(i);
        }
    } else {
        for (i = 0; i < D_80771AF8 + 1; i++) {
            func_80744280(i);
        }
    }
    AudioThread_ScheduleProcessCmds();
}

// Todo: Migrate these to their appropriate places in the above functions

static const char devrostring000[] = "==BANDO== Na_Reset Called\n";
static const char devrostring001[] = "==BANDO== Nas_InitAudio_DD Called\n";
static const char devrostring002[] = "==BANDO== SEQ ROM START = %x\n";
static const char devrostring003[] = "==BANDO== BNK ROM START = %x\n";
static const char devrostring004[] = "==BANDO== TBL ROM START = %x\n";
static const char devrostring005[] = "==BANDO== Na_SetOutMode Called. mode = %d\n";
static const char devrostring006[] = "==BANDO== Na_Player_Goal player = %d\n";
static const char devrostring007[] = "==BANDO== Na_PlyLevelSE_Start Called player =  %02x SE number = %02x\n";
static const char devrostring008[] = "==BANDO== PLAYER LEVEL SE STACK OVER!!\n";
static const char devrostring009[] = "==BANDO== Na_PlyLevelSE_Stop Called player = %02x num = %02x \n";
static const char devrostring010[] = "==BANDO== NON ENTRIED LEVEL SE STOPED! SE NUMBER = %02x\n";
static const char devrostring011[] = "==BANDO== Na_PlyTrgSE_Start Called. player = %02x num = %02x\n";
static const char devrostring012[] = "==BANDO== Na_PlyTrgSE_Start Called BUT RETURN! cause GOAL\n";
static const char devrostring013[] = "==BANDO== Na_PlyTrgSE_Start Called BUT RETURN! cause GOAL\n";
static const char devrostring014[] = "==BANDO== VOICE SE STACK OVER!!\n";
static const char devrostring015[] = "==BANDO== System SE = %02x\n";
static const char devrostring016[] = "==BANDO== Na_hanabi Called. pan = %02x volume = %02x \n";
static const char devrostring017[] = "==BANDO== ENGINE SOUND ECHO START MACHINE NO = %02x\n";
static const char devrostring018[] = "==BANDO== ENGINE SOUND ECHO STOPED! MACHINE No.= %02x\n";
static const char devrostring019[] = "==BANDO== ENGINE SOUND STOPED! MACHINE No.= %02x\n";
static const char devrostring020[] = "==BANDO== Na_PlyEng_Start Called player = %02x\n";
static const char devrostring021[] = "==BANDO== WINING RUN ENGINE SOUND START! MACHINE No.= %02x\n";
static const char devrostring022[] = "==BANDO== Na_SE_Start CALLED!! setype = %02x(hex) senum = %02x(hex) \n";
static const char devrostring023[] = "==BANDO== Na_DDBgm_Ready_Inter Called num = %02x\n";
static const char devrostring024[] = "==BANDO== in dd_bgm_ready_taiki count up complete!\n";
static const char devrostring025[] = "==BANDO== in dd_bgm_ready_taiki calling Na_DDBgm_Ready_Inter...\n";
static const char devrostring026[] = "==BANDO== Na_DDBgm_Ready Called num = %02x\n";
static const char devrostring027[] = "==BANDO== Na_DDBgm_Start num =%d\n";
static const char devrostring028[] = "==BANDO== Na_DDBgm_Start2 num = %d\n";
static const char devrostring029[] = "==BANDO== Na_DDBgm_Stop Called\n";
static const char devrostring030[] = "==BANDO== Na_BetaBgm_Start num = %02x\n";
static const char devrostring031[] = "==BANDO== Na_BetaBgm_Stop Called\n";
static const char devrostring032[] = "==BANDO== Na_ROMBgm_Ready Called %02x\n";
static const char devrostring033[] = "==BANDO== in Na_ROMBgm_Ready Wave Data BG Load Start\n";
static const char devrostring034[] = "==BANDO== in Na_ROMBgm_Ready Ready Bgm Stack\n";
static const char devrostring035[] = "==BANDO== in rom_bgm_ready_taiki Na_ROMBgm_Ready Calling num = %02x\n";
static const char devrostring036[] = "==BANDO== Na_ROMBgm_Start Called num = %02x\n";
static const char devrostring037[] = "==BANDO== GAMEOVER BGM CALLED so DDBgm Stoping!! for ILLEGULALL COURSE MAKING\n";
static const char devrostring038[] = "==BANDO== Na_ROMBgm_Start SELECT or OPTION BGM START\n";
static const char devrostring039[] = "==BANDO== Na_ROMBgm_Stop Called\n";
static const char devrostring040[] = "==BANDO== Na_ROMBgm_Stop Called\n";
static const char devrostring041[] = "==BANDO== Na_START_DEMO Called\n";
static const char devrostring042[] = "==BANDO== Na_RETIRE CALLED!!\n";
static const char devrostring043[] = "==BANDO== Na_Level_SE_Fadeout Called\n";
static const char devrostring044[] = "==BANDO== Na_Test_Run_Start Called\n";
static const char devrostring045[] = "==BANDO== Na_Test_Run_End Called\n";
static const char devrostring046[] = "==BANDO== Na_BetaBgm_Stop2 Called\n";
static const char devrostring047[] = "==BANDO== Na_BetaBgm_Stop3 Called\n";
static const char devrostring048[] = "==BANDO== Pause Called!! Status =  %02x\n";
static const char devrostring049[] = "==BANDO== Na_PauseSet DD BGM Volume Down\n";
static const char devrostring050[] = "==BANDO== in Na_PauseSet Wave Data Load End\n";
static const char devrostring051[] = "==BANDO== Spec Change No = %02x\n";
static const char devrostring052[] = "==BANDO== Player Mode = %02x\n";
static const char devrostring053[] = "==BANDO== All Sound Off\n";
static const char devrostring054[] = "==BANDO== Na_SeSeq_Start for 64DD Called\n";
static const char devrostring055[] = "==BANDO== Na_ChangeSoundMode Called. course = %02x\n";
static const char devrostring056[] = "==BANDO== Na_chakuchi Called BUT RETURN! cause GOAL\n";
static const char devrostring057[] = "==BANDO== Na_chakuchi Edited volume = %f \n";
static const char devrostring058[] = "==BANDO== dd_bgm_data_load2 -SeqStart-\n";
static const char devrostring059[] = "==BANDO== dd_bgm_forground_load_check end num = %d\n";
static const char devrostring060[] = "==BANDO== dd_bgm_data_load WAVE Data Load End\n";
static const char devrostring061[] = "==BANDO== ROM BGM LOAD OK!\n";
static const char devrostring062[] = "==BANDO== TAIKI ROM BGM START!\n";
static const char devrostring063[] = "==BANDO== Na_Guitor_Start Called\n";
static const char devrostring064[] = "==BANDO== Na_Guitor_Start for 64DD Called\n";
static const char devrostring065[] = "==BANDO== SE BANK LOAD START\n";
static const char devrostring066[] = "==BANDO== GUITOR & SE ROM WAVE DMA END\n";
static const char devrostring067[] = "==BANDO== ALL GUITOR DATA LOAD END CHECKING... wav =%d bnk=%d seq=%d\n";
static const char devrostring068[] = "==BANDO== ALL GUITOR DATA LOAD END\n";
static const char devrostring069[] = "==BANDO== SE DATA LOAD END\n";
static const char devrostring070[] = "==BANDO== DDBGM_MUTE_CITY BANK DATA LOAD END\n";
static const char devrostring071[] = "==BANDO== DDBGM_SILENCE BANK DATA LOAD END\n";
static const char devrostring072[] = "==BANDO== DDBGM_SAND_OCEAN BANK DATA LOAD END\n";
static const char devrostring073[] = "==BANDO== DDBGM_PORT_TOWN BANK DATA LOAD END\n";
static const char devrostring074[] = "==BANDO== DDBGM_BIG_BLUE BANK DATA LOAD END\n";
static const char devrostring075[] = "==BANDO== DDBGM_DEVILS_FOREST BANK DATA LOAD END\n";
static const char devrostring076[] = "==BANDO== DDBGM_RED_CANYON BANK DATA LOAD END\n";
static const char devrostring077[] = "==BANDO== DDBGM_SECTOR BANK DATA LOAD END\n";
static const char devrostring078[] = "==BANDO== DDBGM_WHITE_LAND BANK DATA LOAD END\n";
static const char devrostring079[] = "==BANDO== DDBGM_RAINBOW_ROAD BANK DATA LOAD END\n";
static const char devrostring080[] = "==BANDO== DDBGM_NEW_03 BANK DATA LOAD END\n";
static const char devrostring081[] = "==BANDO== DDBGM_NEW_02 BANK DATA LOAD END\n";
static const char devrostring082[] = "==BANDO== DDBGM_NEW_01 BANK DATA LOAD END\n";
static const char devrostring083[] = "==BANDO== DDBGM_NEW_04 BANK DATA LOAD END\n";
static const char devrostring084[] = "==BANDO== DDBGM_TITLE BANK DATA LOAD END\n";
static const char devrostring085[] = "==BANDO== DDBGM_SELECT BANK DATA LOAD END\n";
static const char devrostring086[] = "==BANDO== DDBGM_OPTION BANK DATA LOAD END\n";
static const char devrostring087[] = "==BANDO== DDBGM_DEATHRACE BANK DATA LOAD END\n";
static const char devrostring088[] = "==BANDO== DDBGM_COURSE_EDITOR BANK DATA LOAD END\n";
static const char devrostring089[] = "==BANDO== DDBGM_MACHINE_EDITOR BANK DATA LOAD END\n";
static const char devrostring090[] = "==BANDO== DDBGM_EAD_DEMO BANK DATA LOAD END\n";
static const char devrostring091[] = "==BANDO== DDBGM_MUTE_CITY SEQ DATA LOAD END\n";
static const char devrostring092[] = "==BANDO== DDBGM_SILENCE SEQ DATA LOAD END\n";
static const char devrostring093[] = "==BANDO== DDBGM_SAND_OCEAN SEQ DATA LOAD END\n";
static const char devrostring094[] = "==BANDO== DDBGM_PORT_TOWN SEQ DATA LOAD END\n";
static const char devrostring095[] = "==BANDO== DDBGM_BIG_BLUE SEQ DATA LOAD END\n";
static const char devrostring096[] = "==BANDO== DDBGM_DEVILS_FOREST SEQ DATA LOAD END\n";
static const char devrostring097[] = "==BANDO== DDBGM_RED_CANYON SEQ DATA LOAD END\n";
static const char devrostring098[] = "==BANDO== DDBGM_SECTOR SEQ DATA LOAD END\n";
static const char devrostring099[] = "==BANDO== DDBGM_WHITE_LAND SEQ DATA LOAD END\n";
static const char devrostring100[] = "==BANDO== DDBGM_RAINBOW_ROAD SEQ DATA LOAD END\n";
static const char devrostring101[] = "==BANDO== DDBGM_NEW_01 SEQ DATA LOAD END\n";
static const char devrostring102[] = "==BANDO== DDBGM_NEW_02 SEQ DATA LOAD END\n";
static const char devrostring103[] = "==BANDO== DDBGM_NEW_03 SEQ DATA LOAD END\n";
static const char devrostring104[] = "==BANDO== DDBGM_NEW_04 SEQ DATA LOAD END\n";
static const char devrostring105[] = "==BANDO== DDBGM_TITLE SEQ DATA LOAD END\n";
static const char devrostring106[] = "==BANDO== DDBGM_SELECT SEQ DATA LOAD END\n";
static const char devrostring107[] = "==BANDO== DDBGM_OPTION SEQ DATA LOAD END\n";
static const char devrostring108[] = "==BANDO== DDBGM_DEATHRACE SEQ DATA LOAD END\n";
static const char devrostring109[] = "==BANDO== DDBGM_COURSE_EDITOR SEQ DATA LOAD END\n";
static const char devrostring110[] = "==BANDO== DDBGM_MACHINE_EDITOR SEQ DATA LOAD END\n";
static const char devrostring111[] = "==BANDO== DDBGM_EAD_DEMO SEQ DATA LOAD END\n";
static const char devrostring112[] = "==BANDO== Na_Init_Editor Called\n";
static const char devrostring113[] = "==BANDO== dd_editor_bgm_delay_set -- SEQ START\n";
static const char devrostring114[] = "==BANDO== Na_Init_Editor2 Called\n";
static const char devrostring115[] = "==BANDO== dd_editor2_bgm_delay_set -- SEQ START\n";
static const char devrostring116[] = "==BANDO== Na_Exit_Editor Called\n";
static const char devrostring117[] = "==BANDO== Na_Editor_Bgm_Stop Called \n";
static const char devrostring118[] = "==BANDO== Na_Editor_Bgm_Restart Called \n";
static const char devrostring119[] = "==BANDO== BGM FADEOUT1 COMPLETE ROUTINE\n";
static const char devrostring120[] = "==BANDO== BGM FADEOUT2 COMPLETE ROUTINE\n";
static const char devrostring121[] = "==BANDO== BGM FADEOUT3 COMPLETE ROUTINE\n";
static const char devrostring122[] = "==BANDO== LEVEL SE FADEOUT COMPLETE ROUTINE\n";
static const char devrostring123[] = "==BANDO== BGM FADEOUT COMPLETE ROUTINE (in the PAUSE ROUTINE)\n";
static const char devrostring124[] = "==BANDO== LEVEL SE INTERNAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring125[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring126[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring127[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring128[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring129[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring130[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring131[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring132[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring133[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring134[] = "==BANDO== LEVEL SE FINAL CALL! player=%02x SE Number= %02x \n";
static const char devrostring135[] = "==BANDO== Ouch!! UN-SUPORTED TRG SE NUM WAS CALLED !!!!!!! num = %02x\n";
static const char devrostring136[] = "==BANDO== SE SEQ START\n";
static const char devrostring137[] = "==BANDO== ENEMY ENGINE START MACHINE No.= %02x\n";
static const char devrostring138[] = "==BANDO== ENEMY ENGINE STOP!\n";
static const char devrostring139[] = "==BANDO== len = %d\n";
