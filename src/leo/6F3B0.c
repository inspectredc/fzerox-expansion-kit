#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"
#include "libc/stdint.h"

extern s32 D_80794CD8;
extern OSMesgQueue D_80794D0C;
extern OSMesg D_80794CD4;
extern u8 D_8077B4D0[];
extern u8 D_80794D48;

s32 func_80761BB0(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    LEOCmd cmd;
    LEODiskTime diskTime;

    diskTime.pad = 0;
    diskTime.yearhi = (year > 6400) ? (year / 256) : ((year >= 150) ? 25 : 32);
    diskTime.yearlo = year % 256;
    diskTime.month = month;
    diskTime.day = day;
    diskTime.hour = hour;
    diskTime.minute = minute;
    diskTime.second = second / 2;
    D_80794CD8 = 10;
    if (D_80794D48 != 0) {
        return 0;
    }
    if (gLeoSetRTCFunc(&cmd, &diskTime, &D_80794D0C) < 0) {
        D_80794CD4 = 0xF7;
        return -1;
    }
    return func_80762390();
}

void func_80761CF4(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    func_80761BB0(Leo_EncodeTime(year % 100), Leo_EncodeTime(month), Leo_EncodeTime(day), Leo_EncodeTime(hour),
                  Leo_EncodeTime(minute), Leo_EncodeTime(second));
    return;
}

extern LEODiskTime D_807C6E40;

s32 func_80761DCC(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    LEOCmd cmd;

    D_80794CD8 = 9;
    if (D_80794D48 != 0) {
        if (year != NULL) {
            *year = D_807C6E40.yearlo;
        }
        if (month != NULL) {
            *month = D_807C6E40.month;
        }
        if (day != NULL) {
            *day = D_807C6E40.day;
        }
        if (hour != NULL) {
            *hour = D_807C6E40.hour;
        }
        if (minute != NULL) {
            *minute = D_807C6E40.minute;
        }
        if (second != NULL) {
            *second = D_807C6E40.second;
        }
    } else {
        if (gLeoReadRTCFunc(&cmd, &D_80794D0C) < 0) {
            D_80794CD4 = 0xF7;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
        if (year != NULL) {
            *year = cmd.data.time.yearlo;
        }
        if (month != NULL) {
            *month = cmd.data.time.month;
        }
        if (day != NULL) {
            *day = cmd.data.time.day;
        }
        if (hour != NULL) {
            *hour = cmd.data.time.hour;
        }
        if (minute != NULL) {
            *minute = cmd.data.time.minute;
        }
        if (second != NULL) {
            *second = cmd.data.time.second;
        }
    }
    return 0;
}

s32 func_80761FAC(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    s32 yearE;
    s32 monthE;
    s32 dayE;
    s32 hourE;
    s32 minuteE;
    s32 secondE;

    if (func_80761DCC(&yearE, &monthE, &dayE, &hourE, &minuteE, &secondE) < 0) {
        return -1;
    }
    if (year != NULL) {
        *year = Leo_DecodeTime(yearE);
    }
    if (month != NULL) {
        *month = Leo_DecodeTime(monthE);
    }
    if (day != NULL) {
        *day = Leo_DecodeTime(dayE);
    }
    if (hour != NULL) {
        *hour = Leo_DecodeTime(hourE);
    }
    if (minute != NULL) {
        *minute = Leo_DecodeTime(minuteE);
    }
    if (second != NULL) {
        *second = Leo_DecodeTime(secondE);
    }
    return 0;
}

s32 func_807620C0(LEODiskTime* arg0) {
    LEOCmd sp1C;

    D_80794CD8 = 9;
    if (D_80794D48 != 0) {
        bcopy(&D_807C6E40, arg0, 8);
    } else {
        if (gLeoReadRTCFunc(&sp1C, &D_80794D0C) < 0) {
            D_80794CD4 = 0xF7;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
        bcopy(&sp1C.data, arg0, 8);
    }

    return 0;
}

void func_80762184(LEODiskTime* diskTime, unk_leo_timeformat* arg1) {
    s32 sp1C;

    sp1C = Leo_DecodeTime(diskTime->yearlo);
    if ((sp1C < 0x60) && (sp1C >= 0x16)) {
        sp1C = (sp1C + 0x4B) % 100;
    }

    arg1->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 1) & 0xFE) | (arg1->unkb0 & 0xFF01))
                                 : ((((sp1C + 3) << 1) & 0xFE) | (arg1->unkb0 & 0xFF01));

    arg1->unks0 = (((Leo_DecodeTime(diskTime->month) & 0xF) << 5) & 0x1E0) | (arg1->unks0 & 0xFE1F);
    arg1->unkb1 = (Leo_DecodeTime(diskTime->day) & 0x1F & 0x1F) | (arg1->unkb1 & 0xFFE0);

    arg1->unkb2 = ((((Leo_DecodeTime(diskTime->hour) & 0x1F) << 3) & 0xF8) | (arg1->unkb2 & 0xFF07));
    arg1->unks2 = (((Leo_DecodeTime(diskTime->minute) & 0x3F) << 5) & 0x7E0) | (arg1->unks2 & 0xF81F);
    arg1->unkb3 = ((Leo_DecodeTime(diskTime->second) / 2) & 0x1F & 0x1F) | (arg1->unkb3 & 0xFFE0);
}

void func_80762330(LEODiskTime* diskTime) {
    if (diskTime == NULL) {
        D_80794D48 = 0;
        return;
    }
    D_80794D48 = 1;
    bcopy(diskTime, &D_807C6E40, 8);
}

extern s32 D_80794CC4;
extern OSMesgQueue* D_80794CC8;
extern OSMesg D_80794CCC;

s32 func_80762390(void) {
    if (D_80794CC4 != 0) {
        while (osRecvMesg(&D_80794D0C, &D_80794CD4, OS_MESG_NOBLOCK) < 0) {
            osSendMesg(D_80794CC8, D_80794CCC, OS_MESG_BLOCK);
        }
    } else {
        osRecvMesg(&D_80794D0C, &D_80794CD4, OS_MESG_BLOCK);
    }
    if (D_80794CD4 != NULL) {
        return -1;
    }
    return 0;
}

s32 func_80762458(u8 arg0) {
    LEOCmd sp1C;

    if (arg0 == 2) {
        D_80794CD8 = 6;
    } else {
        D_80794CD8 = 7;
    }
    if (gLeoSpdlMotorFunc(&sp1C, arg0, &D_80794D0C) < 0) {
        D_80794CD4 = 0xF7;
        return -1;
    }
    return func_80762390();
}

s32 func_807624F0(u32 arg0, u32 arg1) {
    LEOCmd sp1C;

    D_80794CD8 = 0xB;
    if (gLeoModeSelectAsyncFunc(&sp1C, arg0, arg1, &D_80794D0C) < 0) {
        D_80794CD4 = 0xF7;
        return -1;
    }
    return func_80762390();
}

s32 func_80762570(u32 arg0, u8* arg1, u32 arg2) {
    LEOCmd cmd;
    s32 i;
    s32 sp24;
    u8* sp20;

    sp20 = arg1;
    if (!((uintptr_t) arg1 & 0xF)) {
        LeoLBAToByte(arg0, arg2, &sp24);
        osInvalDCache(arg1, sp24);
        D_80794CD8 = 2;
        if (gLeoReadWriteFunc(&cmd, 0, arg0, arg1, arg2, &D_80794D0C) < 0) {
            D_80794CD4 = 0xF7;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
        osWritebackDCache(arg1, sp24);
    } else {
        osInvalDCache(D_8077B4D0, 0x4D10);

        for (i = 0; i < arg2; i++) {
            LeoLBAToByte(arg0 + i, 1, &sp24);
            D_80794CD8 = 2;
            if (gLeoReadWriteFunc(&cmd, 0, arg0 + i, D_8077B4D0, 1U, &D_80794D0C) < 0) {
                D_80794CD4 = 0xF7;
                return -1;
            }
            if (func_80762390() < 0) {
                return -1;
            }
            bcopy(D_8077B4D0, arg1, sp24);
            arg1 += sp24;
        }

        LeoLBAToByte(arg0, arg2, &sp24);
        osWritebackDCache(sp20, sp24);
    }

    return 0;
}

s32 func_80762768(u32 arg0, u8* arg1, u32 arg2) {
    LEOCmd sp2C;
    s32 i;
    s32 sp24;

    if (!((uintptr_t) arg1 & 0xF)) {
        LeoLBAToByte(arg0, arg2, &sp24);
        osWritebackDCache(arg1, sp24);
        D_80794CD8 = 3;
        if (gLeoReadWriteFunc(&sp2C, 1, arg0, arg1, arg2, &D_80794D0C) < 0) {
            D_80794CD4 = 0xF7;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
    } else {

        LeoLBAToByte(arg0, arg2, &sp24);
        osWritebackDCache(arg1, sp24);

        for (i = 0; i < arg2; i++) {

            LeoLBAToByte(arg0 + i, 1, &sp24);
            bcopy(arg1, D_8077B4D0, sp24);
            osWritebackDCache(D_8077B4D0, 0x4D10);
            D_80794CD8 = 3;
            if (gLeoReadWriteFunc(&sp2C, 1, arg0 + i, D_8077B4D0, 1, &D_80794D0C) < 0) {
                D_80794CD4 = 0xF7;
                return -1;
            }
            if (func_80762390() < 0) {
                return -1;
            }
            arg1 += sp24;
        }
    }
    return 0;
}

s32 Leo_strcmp(u8* s1, u8* s2) {
    u8* p1 = s1;
    u8* p2 = s2;

    while (*p1 != 0) {
        if (*p1 < *p2) {
            return -1;
        }
        if (*p1++ > *p2++) {
            return 1;
        }
    }

    if (*p2 == 0) {
        return 0;
    }
    return -1;
}

s32 Leo_bcmp(u8* b1, u8* b2, size_t length) {
    u8* p1 = b1;
    u8* p2 = b2;

    while ((length != 0) && (*p1 != 0) && (*p2 != 0)) {

        if (*p1 < *p2) {
            return -1;
        }
        if (*p1++ > *p2++) {
            return 1;
        }
        length--;
    }

    if (length == 0) {
        return 0;
    }
    if ((*p1 == 0) && (*p2 == 0)) {
        return 0;
    }

    return (*p1 != 0) ? 1 : -1;
}

s32 Leo_strlen(u8* str) {
    s32 len = 0;

    if (str == NULL) {
        return 0;
    }
    while (*str++) {
        len++;
    }

    return len;
}

s32 Leo_strcpy(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

s32 Leo_bcopy(u8* dest, u8* src, size_t length) {
    u8* p1 = dest;
    u8* p2 = src;
    size_t i;

    i = 0;
    while (*p2) {
        *p1++ = *p2++;

        if (++i == length) {
            return 0;
        }
    }

    *p1 = 0;
    return 0;
}

s32 Leo_strcat(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p1) {
        p1++;
    }
    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

s32 Leo_DecodeTime(s32 arg0) {
    return ((arg0 >> 4) * 10) + (arg0 & 0xF);
}

s32 Leo_EncodeTime(s32 arg0) {
    return ((arg0 / 10) << 4) + (arg0 % 10);
}
