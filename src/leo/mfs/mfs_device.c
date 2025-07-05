#include "leo/leo_functions.h"
#include "leo/leo_internal.h"
#include "leo/unk_leo.h"
#include "libc/stdint.h"

extern s32 D_80794CD8;
extern OSMesgQueue D_80794D0C;
extern s32 gMfsError;
extern u8 D_8077B4D0[];
extern u8 D_80794D48;

s32 Mfs_SetRtc(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
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
    if (D_80794D48) {
        return 0;
    }
    if (gLeoSetRTCFunc(&cmd, &diskTime, &D_80794D0C) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_80762390();
}

void Mfs_EncodeAndSetRtc(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second) {
    Mfs_SetRtc(Mfs_EncodeTime(year % 100), Mfs_EncodeTime(month), Mfs_EncodeTime(day), Mfs_EncodeTime(hour),
               Mfs_EncodeTime(minute), Mfs_EncodeTime(second));
    return;
}

extern LEODiskTime D_807C6E40;

s32 func_80761DCC(s32* year, s32* month, s32* day, s32* hour, s32* minute, s32* second) {
    LEOCmd cmd;

    D_80794CD8 = 9;
    if (D_80794D48) {
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
            gMfsError = N64DD_MANAGER_NOT_CREATED;
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
        *year = Mfs_DecodeTime(yearE);
    }
    if (month != NULL) {
        *month = Mfs_DecodeTime(monthE);
    }
    if (day != NULL) {
        *day = Mfs_DecodeTime(dayE);
    }
    if (hour != NULL) {
        *hour = Mfs_DecodeTime(hourE);
    }
    if (minute != NULL) {
        *minute = Mfs_DecodeTime(minuteE);
    }
    if (second != NULL) {
        *second = Mfs_DecodeTime(secondE);
    }
    return 0;
}

s32 Mfs_ReadRtc(LEODiskTime* diskTime) {
    LEOCmd sp1C;

    D_80794CD8 = 9;
    if (D_80794D48) {
        bcopy(&D_807C6E40, diskTime, sizeof(LEODiskTime));
    } else {
        if (gLeoReadRTCFunc(&sp1C, &D_80794D0C) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
        bcopy(&sp1C.data, diskTime, sizeof(LEODiskTime));
    }

    return 0;
}

void Mfs_LEODiskTimeToMfsTime(LEODiskTime* diskTime, MfsTimeFormat* mfsTime) {
    s32 sp1C;

    sp1C = Mfs_DecodeTime(diskTime->yearlo);
    if ((sp1C < 0x60) && (sp1C >= 0x16)) {
        sp1C = (sp1C + 0x4B) % 100;
    }

    mfsTime->unkb0 = (sp1C >= 0x60) ? ((((sp1C - 0x60) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01))
                                    : ((((sp1C + 3) << 1) & 0xFE) | (mfsTime->unkb0 & 0xFF01));

    mfsTime->unks0 = (((Mfs_DecodeTime(diskTime->month) & 0xF) << 5) & 0x1E0) | (mfsTime->unks0 & 0xFE1F);
    mfsTime->unkb1 = (Mfs_DecodeTime(diskTime->day) & 0x1F & 0x1F) | (mfsTime->unkb1 & 0xFFE0);

    mfsTime->unkb2 = ((((Mfs_DecodeTime(diskTime->hour) & 0x1F) << 3) & 0xF8) | (mfsTime->unkb2 & 0xFF07));
    mfsTime->unks2 = (((Mfs_DecodeTime(diskTime->minute) & 0x3F) << 5) & 0x7E0) | (mfsTime->unks2 & 0xF81F);
    mfsTime->unkb3 = ((Mfs_DecodeTime(diskTime->second) / 2) & 0x1F & 0x1F) | (mfsTime->unkb3 & 0xFFE0);
}

void func_80762330(LEODiskTime* diskTime) {
    if (diskTime == NULL) {
        D_80794D48 = false;
        return;
    }
    D_80794D48 = true;
    bcopy(diskTime, &D_807C6E40, sizeof(LEODiskTime));
}

extern s32 D_80794CC4;
extern OSMesgQueue* D_80794CC8;
extern OSMesg D_80794CCC;

s32 func_80762390(void) {
    if (D_80794CC4 != 0) {
        while (osRecvMesg(&D_80794D0C, &gMfsError, OS_MESG_NOBLOCK) < 0) {
            osSendMesg(D_80794CC8, D_80794CCC, OS_MESG_BLOCK);
        }
    } else {
        osRecvMesg(&D_80794D0C, &gMfsError, OS_MESG_BLOCK);
    }
    if (gMfsError != NULL) {
        return -1;
    }
    return 0;
}

s32 Mfs_SpdlMotor(LEOSpdlMode mode) {
    LEOCmd cmdBlock;

    if (mode == LEO_MOTOR_SLEEP) {
        D_80794CD8 = 6;
    } else {
        D_80794CD8 = 7;
    }
    if (gLeoSpdlMotorFunc(&cmdBlock, mode, &D_80794D0C) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_80762390();
}

s32 Mfs_ModeSelectAsync(u32 standby, u32 sleep) {
    LEOCmd cmdBlock;

    D_80794CD8 = 0xB;
    if (gLeoModeSelectAsyncFunc(&cmdBlock, standby, sleep, &D_80794D0C) < 0) {
        gMfsError = N64DD_MANAGER_NOT_CREATED;
        return -1;
    }
    return func_80762390();
}

s32 Mfs_ReadLBA(u32 startLBA, u8* buf, u32 nLBAs) {
    LEOCmd cmd;
    s32 i;
    s32 sp24;
    u8* sp20;

    sp20 = buf;
    if (!((uintptr_t) buf & 0xF)) {
        LeoLBAToByte(startLBA, nLBAs, &sp24);
        osInvalDCache(buf, sp24);
        D_80794CD8 = 2;
        if (gLeoReadWriteFunc(&cmd, OS_READ, startLBA, buf, nLBAs, &D_80794D0C) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
        osWritebackDCache(buf, sp24);
    } else {
        osInvalDCache(D_8077B4D0, 0x4D10);

        for (i = 0; i < nLBAs; i++) {
            LeoLBAToByte(startLBA + i, 1, &sp24);
            D_80794CD8 = 2;
            if (gLeoReadWriteFunc(&cmd, OS_READ, startLBA + i, D_8077B4D0, 1, &D_80794D0C) < 0) {
                gMfsError = N64DD_MANAGER_NOT_CREATED;
                return -1;
            }
            if (func_80762390() < 0) {
                return -1;
            }
            bcopy(D_8077B4D0, buf, sp24);
            buf += sp24;
        }

        LeoLBAToByte(startLBA, nLBAs, &sp24);
        osWritebackDCache(sp20, sp24);
    }

    return 0;
}

s32 Mfs_WriteLBA(u32 startLBA, u8* buf, u32 nLBAs) {
    LEOCmd sp2C;
    s32 i;
    s32 sp24;

    if (!((uintptr_t) buf & 0xF)) {
        LeoLBAToByte(startLBA, nLBAs, &sp24);
        osWritebackDCache(buf, sp24);
        D_80794CD8 = 3;
        if (gLeoReadWriteFunc(&sp2C, OS_WRITE, startLBA, buf, nLBAs, &D_80794D0C) < 0) {
            gMfsError = N64DD_MANAGER_NOT_CREATED;
            return -1;
        }
        if (func_80762390() < 0) {
            return -1;
        }
    } else {

        LeoLBAToByte(startLBA, nLBAs, &sp24);
        osWritebackDCache(buf, sp24);

        for (i = 0; i < nLBAs; i++) {

            LeoLBAToByte(startLBA + i, 1, &sp24);
            bcopy(buf, D_8077B4D0, sp24);
            osWritebackDCache(D_8077B4D0, 0x4D10);
            D_80794CD8 = 3;
            if (gLeoReadWriteFunc(&sp2C, OS_WRITE, startLBA + i, D_8077B4D0, 1, &D_80794D0C) < 0) {
                gMfsError = N64DD_MANAGER_NOT_CREATED;
                return -1;
            }
            if (func_80762390() < 0) {
                return -1;
            }
            buf += sp24;
        }
    }
    return 0;
}

s32 mfsStrCmp(u8* s1, u8* s2) {
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

s32 mfsStrnCmp(u8* b1, u8* b2, size_t length) {
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

s32 mfsStrLen(u8* str) {
    s32 len = 0;

    if (str == NULL) {
        return 0;
    }
    while (*str++) {
        len++;
    }

    return len;
}

s32 mfsStrCpy(u8* dest, u8* src) {
    u8* p1 = dest;
    u8* p2 = src;

    while (*p2) {
        *p1++ = *p2++;
    }

    *p1 = 0;
    return 0;
}

s32 mfsStrnCpy(u8* dest, u8* src, size_t length) {
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

s32 mfsStrCat(u8* dest, u8* src) {
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

s32 Mfs_DecodeTime(s32 timeUnit) {
    return ((timeUnit >> 4) * 10) + (timeUnit & 0xF);
}

s32 Mfs_EncodeTime(s32 timeUnit) {
    return ((timeUnit / 10) << 4) + (timeUnit % 10);
}
