#include "global.h"
#include "leo/leo_internal.h"
#include "leo/leo_functions.h"

s32 D_8079F950;
LEOStatus D_8079F954;
LEOCmd D_8079F958;
OSMesgQueue D_8079F978;
OSMesg D_8079F990[1];
OSMesgQueue D_8079F998;
OSMesg D_8079F9B0[1];
s32 D_8079F9B4;
s32 D_8079F9B8;
s32 D_8079F9BC;
UNUSED s32 D_8079F9C0;
u8 D_8079F9C4[2];
u8 D_8079F9C8[4];
s32 D_8079F9CC;
OSMesg D_8079F9D0[16];
LEODiskID D_8079FA10;

extern s32 D_8076CBB0;
extern s32 D_8076CBBC;
extern s32 D_8076CBC8;
extern s32 D_8076CBCC;
extern s32 D_80794CD4;

void func_80704050(s32 arg0) {
    D_8076CBCC = arg0;
}

void func_8070405C(s32 arg0) {
    D_8076CBC8 = arg0;
}

extern OSThread* D_8076CBC0;
extern s32 D_8076CBC4;

void func_80704068(void) {
    if ((D_8076CBC0 != NULL) && (D_8076CBC4 == 0) && (D_8076CBCC == 0)) {
        osStopThread(D_8076CBC0);
    }
    D_8076CBC4++;
}

void func_807040C8(void) {
    D_8076CBC4--;
    if ((D_8076CBC0 != NULL) && (D_8076CBC4 == 0) && (D_8076CBCC == 0)) {
        osStartThread(D_8076CBC0);
    }
}

s32 func_80704120(LEODiskID diskId) {
    s32 i;

    if (diskId.company[0] != D_8079F9C4[0]) {
        return 1;
    }
    if (diskId.company[1] != D_8079F9C4[1]) {
        return 1;
    }

    if (diskId.gameName[0] < D_8079F9C8[0]) {
        return 1;
    }

    for (i = 1; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_8079F9C8[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 func_807041C0(LEODiskID diskId) {
    s32 i;

    if (diskId.company[0] != D_8079F9C4[0]) {
        return 1;
    }
    if (diskId.company[1] != D_8079F9C4[1]) {
        return 1;
    }

    for (i = 0; i < ARRAY_COUNT(diskId.gameName); i++) {
        if (D_8079F9C8[i] != diskId.gameName[i]) {
            return 1;
        }
    }
    return 2;
}

s32 SLMFSLoadSpecial(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4) {
    PRINTF("SLMFSLoadSpecial LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9B4 = func_8076543C(arg0, arg1, arg2, arg3, arg4);

        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoadSP Good Return\n");
            return D_8079F9B4;
        }
        PRINTF("SLMFSLoadSP error N64DD_NOT_FOUND %s\n", arg1);
        PRINTF("SLMFSLoadSP error 0x%X\n", D_80794CD4);
        PRINTF("name %s, type %s\n", arg1, arg2);

        D_8079F9B8 = D_80794CD4;
        if (D_80794CD4 == 0xF2) {}
        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("FILE NOT FOUND\n");
                return 0;
            case 0xF2:
                return D_8079F9B8;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge43\n");
                PRINTF("hoge44\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadSP\n");
                return 0xF2;
            case 0x10A:
                return 0x10A;
            case 0xF0:
                PRINTF("MEDIAINIT_AND_WAIT 12\n");
                PRINTF("MEDIAINIT_AND_WAIT 13\n");
                return 0xF0;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern s32 D_80794CDC;

s32 SLMFSLoadSpecial2(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4) {
    PRINTF("hoge45\n");

    PRINTF("SLMFSLoadSpecial2 LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9B4 = func_8076543C(arg0, arg1, arg2, arg3, arg4);

        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoadSpecial2 Good Return\n");
            return D_8079F9B4;
        }

        PRINTF("SLMFSLoadSP2 error N64DD_NOT_FOUND %s\n", arg1);
        PRINTF("SLMFSLoadSP2 error 0x%X\n", D_80794CD4);
        PRINTF("name %s, type %s\n", arg1, arg2);

        D_8079F9B8 = D_80794CD4;

        if (D_80794CD4 == 0xF2) {}
        if (1) {}

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("FILE NOT FOUND SP2\n");
                return 0;
            case 0xF2:
                return D_8079F9B8;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge432\n");
                PRINTF("hoge442\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadSP2\n");
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                    return 0xF2;
                }
                if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoadSP2\n");
                    SLMFSDeleteFile(arg0, arg1, arg2, 1);
                }
                return 0xF2;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                PRINTF("MEDIAINIT_AND_WAIT SP2\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern u8 gEditCupTrackNames[][9];

void func_8070470C(void) {
    s32 i;
    PRINTF("hoge45\n");

    if (D_8076CBC8 == 0) {
        return;
    }

    gEditCupTrackNames[0][0] = '\0';
    gEditCupTrackNames[1][0] = '\0';
    gEditCupTrackNames[2][0] = '\0';
    gEditCupTrackNames[3][0] = '\0';
    gEditCupTrackNames[4][0] = '\0';
    gEditCupTrackNames[5][0] = '\0';

    SLMFSLoadSpecial(0xFFFB, "CRS_ENTRY", "CENT", gEditCupTrackNames[0], 0xD8);

    PRINTF("===============================================\n");
    PRINTF("ENTRY LOAD AGAIN\n");
    PRINTF("===============================================\n");

    for (i = 0; i < 6; i++) {
        if (Mfs_ValidateFileName(&gEditCupTrackNames[i]) != 0) {
            gEditCupTrackNames[i][0] = '\0';
        }
    }
}

void func_807047AC(void) {
    if (D_8076CBC8 != 0) {
        gEditCupTrackNames[0][0] = '\0';
        gEditCupTrackNames[1][0] = '\0';
        gEditCupTrackNames[2][0] = '\0';
        gEditCupTrackNames[3][0] = '\0';
        gEditCupTrackNames[4][0] = '\0';
        gEditCupTrackNames[5][0] = '\0';
        SLMFSLoadSpecial2(0xFFFB, "CRS_ENTRY", "CENT", gEditCupTrackNames[0], 0xD8);
    }

    PRINTF("Mesg Wait Before\n");
    PRINTF("===============================================\n");
    PRINTF("ENTRY LOAD AGAIN\n");
    PRINTF("===============================================\n");
}

extern s32 D_8076CBB4;
extern LEODiskID D_8076CB50;
extern LEODiskID D_8076CB70;
extern LEODiskID D_8076CB90;

void func_80704810(s32 arg0) {
    D_8076CBB4 = arg0;
}

void func_8070481C(void) {
    PRINTF("NEWDISK_FOR_FZERO2\n");
    D_8076CB70 = leoBootID;
}

void func_80704870(void) {
    func_80704050(1);
    SLLeoReadDiskID(&D_8079FA10);

    if (func_807041C0(D_8079FA10) == 2) {
        PRINTF("RECORD_GAME_DISK_ID\n");
        D_8076CB70 = D_8079FA10;
    } else {
        PRINTF("ID INT NOT EQUAL IN RECORD_GAME_DISKID\n");
        D_8076CB70 = leoBootID;
    }
    if (func_80704F44(D_8079FA10, D_8076CB50) != 0) {
        D_8076CB50 = D_8079FA10;
        SLMFSNewDisk();
    }
    func_80704050(0);
}

void func_80704AA8(void) {
    func_80704050(1);
    SLLeoReadDiskID(&D_8079FA10);

    if (func_807041C0(D_8079FA10) == 2) {
        PRINTF("RECORD_GAME_DISK_GHOT_COPY_ID\n");
        D_8076CB90 = D_8079FA10;
    } else {
        PRINTF("ID INT NOT EQUAL IN RECORD_GAME_DISKID\n");
        D_8076CB90 = leoBootID;
    }
    if (func_80704F44(D_8079FA10, D_8076CB50) != 0) {
        D_8076CB50 = D_8079FA10;
        SLMFSNewDisk();
    }
    func_80704050(0);
}

void func_80704CE0(void) {
    OSTime initTime = osGetTime();

    while (osGetTime() - initTime <= 0xB9B30) {}
}

void SLForceWritebackDCacheAll(void) {
    OSIntMask prevMask = osGetIntMask();

    osSetIntMask(OS_IM_NONE);
    osWritebackDCacheAll();
    osSetIntMask(prevMask);
}

void func_80704DB0(char* arg0, char* arg1) {
    s32 i;

    for (i = 0; i < 2; i++) {
        D_8079F9C4[i] = *arg0++;
    }

    for (i = 0; i < 4; i++) {
        D_8079F9C8[i] = *arg1++;
    }
}

s32 SLCheckDiskChange(void) {

    PRINTF("SLCheckDiskChange LOOP\n");

    while (true) {
        D_8079F9B8 = LeoTestUnitReady(&D_8079F954);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return 0;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return 1;
            case LEO_ERROR_BUSY:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                return 0;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern LEODiskID D_80794CE8;
extern u16 gWorkingDirectory;
extern s32 D_80794D30;
extern MfsRamArea gMfsRamArea;

void func_80704EB8(void) {
    D_80794CE8 = D_8076CB50;
    func_80760320();
    gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
    D_80794D30 = 0;
    gMfsRamArea.id.diskId[0] = '\0';
}

void func_80704F38(OSThread* arg0) {
    D_8076CBC0 = arg0;
}

bool func_80704F44(LEODiskID diskId1, LEODiskID diskId2) {
    s32 i;
    s32* ptr1 = (s32*) &diskId1;
    s32* ptr2 = (s32*) &diskId2;

    PRINTF("hoge0\n");

    for (i = 0; i < sizeof(LEODiskID) / sizeof(s32); i++, ptr1++, ptr2++) {
        if (*ptr1 != *ptr2) {
            return true;
        }
    }

    return false;
}

s32 SLLeoReadDiskID(LEODiskID* diskId) {
    PRINTF("SLLeoReadDiskID LOOP\n");

    while (true) {
        LeoReadDiskID(&D_8079F958, diskId, &D_8079F978);
        osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);

        PRINTF("GAME ID IS %c%c%c%c\n", diskId->gameName[0], diskId->gameName[2], diskId->gameName[2],
               diskId->gameName[3]);
        PRINTF("KO-JO- LINE NUM iS %d\n", diskId->serialNumber.lineNumber);
        PRINTF("TIME is %d\n", diskId->serialNumber.rawTime);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                D_8076CBBC = 1;
                return D_8079F9B8;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case LEO_ERROR_QUEUE_FULL:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 SLLeoReadDiskID_for_start(void) {
    PRINTF("hoge2\n");
    PRINTF("hoge3\n");
    PRINTF("hoge4\n");
    PRINTF("SLLeoReadDiskID_for_start\n");

    LeoReadDiskID(&D_8079F958, &D_8076CB50, &D_8079F978);
    osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);

    switch (D_8079F9B8) {
        case LEO_ERROR_GOOD:
            D_8076CBBC = 1;
            return D_8079F9B8;
        case LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED:
            return LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_8070F8A4(D_8079F9B8, 2);
            while (func_80707780() != 0) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_8070F8A4(D_8079F9B8, 1);
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
        default:
            func_8070F8A4(D_8079F9B8, 0);
            while (true) {}
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
    }

    PRINTF("SLLeoReadDiskID_for_start end\n");
    return D_8079F9B8;
}

s32 func_80705270(void) {
    PRINTF("hoge5\n");
    PRINTF("hoge6\n");
    PRINTF("hoge7\n");

    D_8079F9B8 = LeoTestUnitReady(&D_8079F954);

    switch (D_8079F9B8) {
        case LEO_ERROR_GOOD:
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            SLMFSNewDisk();
            break;
        case LEO_ERROR_BUSY:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            func_8070F8A4(D_8079F9B8, 0);
            while (true) {}
    }

    if (D_8079F954 & 1) {
        return 1;
    } else {
        return 0;
    }
}

s32 SLLeoReadWrite_DATA(LEOCmd* cmdBlock, s32 direction, s32 lba, u8* vAddr, u32 nLbas, OSMesgQueue* mq) {
    PRINTF("hoge10\n");

    PRINTF("SLLeoReadWrite_DATA LOOP %d-%d LBA\n", lba, lba + nLbas);

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        LeoLBAToByte(lba, nLbas, &D_8079F950);
        osInvalDCache(osPhysicalToVirtual(vAddr), D_8079F950);
        LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &D_8079F978);
        osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);

        PRINTF("SLLeoReadWrite_DATA Finished\n");

        if (D_8079F9B8 == NULL) {
            PRINTF("MFSMesgQ Send 12\n");
            osSendMesg(mq, D_8079F9B8, OS_MESG_NOBLOCK);
        }

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return 0;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_QUEUE_FULL:
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 SLLeoReadWrite(LEOCmd* cmdBlock, s32 direction, s32 lba, u8* vAddr, u32 nLbas, OSMesgQueue* mq) {
    PRINTF("hoge11\n");
    PRINTF("hoge12\n");
    PRINTF("hoge13\n");

    PRINTF("SLLeoReadWrite %d LBA\n", lba);
    PRINTF("SLLeoReadWrite LOOP\n");

    while (true) {
        func_80704068();
        while (func_80704F44(D_8076CB50, leoBootID) != 0) {
            func_8070F8A4(D_8079F9B8, 5);
            while (func_80707780() != 0) {}
            while (SLCheckDiskInsert() != 0) {}
        }
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }

        if (0) {
            PRINTF("SLLeoReadWrite 0\n");
            PRINTF("SLLeoReadWrite 1\n");
            PRINTF("SLLeoReadWrite 2\n");
        }

        func_807040C8();
        LeoLBAToByte(lba, nLbas, &D_8079F950);
        osInvalDCache(osPhysicalToVirtual(vAddr), D_8079F950);
        LeoReadWrite(cmdBlock, direction, lba, vAddr, nLbas, &D_8079F978);
        osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);

        PRINTF("SLLeoReadWrite ERROR %d\n", D_8079F9B8);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 14\n");
                osSendMesg(mq, D_8079F9B8, OS_MESG_NOBLOCK);
                if (0) {
                    PRINTF("Stop on SLLeoReadWrite 0\n");
                    PRINTF("Stop on SLLeoReadWrite 1\n");
                    PRINTF("Stop on SLLeoReadWrite 2\n");
                }
                return 0;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_QUEUE_FULL:
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                if (direction == OS_READ) {
                    PRINTF("hoge14\n");
                    PRINTF("hoge15\n");
                    PRINTF("MFSMesgQ Send 14\n");
                    osSendMesg(mq, D_8079F9B8, OS_MESG_NOBLOCK);
                    return 0;
                }
                /* fallthrough */
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern s32 D_8076CBB8;

s32 func_8070595C(void) {
    static s32 D_8079FA30;

    if (D_8076CBB8 == 0) {
        return 0;
    }

    while ((D_8079FA30 = SLCheckDiskInsert()) == 2) {}

    if (D_8079FA30 == 0) {
        if (func_807041C0(D_8076CB50) == 2) {
            return 2;
        }
        return 1;
    }

    return 0;
}

void func_80705A38(LEODiskID arg0) {
    D_8076CB50 = arg0;
}

void func_80705A98(void) {
    osCreateMesgQueue(&D_8079F978, D_8079F990, 1);
    osCreateMesgQueue(&D_8079F998, D_8079F9B0, 1);
}

s32 SLLeoCreateManager(s32 arg0) {

    func_80705A98();
    switch (arg0) {
        case 0:
            D_8079F9B8 = LeoCreateLeoManager(0x95, 0x96, D_8079F9D0, ARRAY_COUNT(D_8079F9D0));
            break;
        case 1:
            D_8079F9B8 = LeoCJCreateLeoManager(0x95, 0x96, D_8079F9D0, ARRAY_COUNT(D_8079F9D0));
            break;
        case 2:
            D_8079F9B8 = LeoCACreateLeoManager(0x95, 0x96, D_8079F9D0, ARRAY_COUNT(D_8079F9D0));
            break;
    }
    if (D_8079F9B8 == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE) {
        func_8070F8A4(D_8079F9B8, 0);
        while (true) {}
    }
    D_8076CBB8 = 1;
    return 0;
}

void SLLeoResetClear(void) {
    s32 i;
    PRINTF("hoge16\n");

    for (i = 0; i < 30; i++) {
        if (0) {
            PRINTF("hoge17\n");
            PRINTF("Reset Clear Try\n");
            PRINTF("Reset Clear Try2\n");
            PRINTF("Reset Clear Try3\n");
        }
        func_80704CE0();
        LeoResetClear();
        D_8079F9B8 = SLLeoReadDiskID_for_start();
        if (D_8079F9B8 != LEO_ERROR_POWERONRESET_DEVICERESET_OCCURED) {
            PRINTF("Leo Reset Clear Success\n");
            return;
        }
    }
    func_8070F8A4(D_8079F9B8, 0);
    while (true) {}
}

void SLLeo_mfs_newdisk(void) {
    PRINTF("hoge18\n");

    PRINTF("mfs_newdisk LOOP\n");

    while (true) {
        switch (SLLeoReadDiskID(&D_8076CB50)) {
            case LEO_ERROR_GOOD:
                func_80704EB8();
                PRINTF("Stop on mfs_newdisk\n");
                return;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
        }
    }
}

void SLLeoModeSelectAsync(u32 standby, u32 sleep) {
    PRINTF("hoge20\n");

    PRINTF("SLLeoModeSelectAsync LOOP\n");

    while (true) {
        LeoModeSelectAsync(&D_8079F958, standby, sleep, &D_8079F978);
        osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);
        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern FrameBuffer* gFrameBuffers[];

void func_80705E18(void) {
    func_80704050(1);
    if (SLCheckDiskChange() != 0) {
        SLMFSNewDisk();
        D_8076CB50 = D_80794CE8;
    }
    while (func_80704F44(D_8076CB50, leoBootID) != 0) {

        osViSwapBuffer(gFrameBuffers[0]);
        while (osViGetNextFramebuffer() != gFrameBuffers[0]) {}
        func_8070F8A4(-1, 5);
        osViSwapBuffer(gFrameBuffers[1]);
        while (osViGetNextFramebuffer() != gFrameBuffers[1]) {}
        func_8070F8A4(-1, 5);
        osViSwapBuffer(gFrameBuffers[2]);
        while (osViGetNextFramebuffer() != gFrameBuffers[2]) {}
        func_8070F8A4(-1, 5);
        while (func_80707780() != 0) {}
        while (SLCheckDiskInsert() != 0) {}
    }
    func_80704050(0);
}

void SLMFSRecoverManageArea(void) {
    PRINTF("hoge21\n");
    PRINTF("WAIT_SET_BOOT_DISK\n");
    PRINTF("SLMFSRecoverManageArea LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk2();
            D_8076CBB0 = 0;
        }
        if (func_80761238() == 0) {
            PRINTF("SLMFSRecoverManageArea Good Return\n");
            break;
        }

        D_8079F9B8 = D_80794CD4;
        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("SLMFSRecoverManageArea Good Return\n");
                return;
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge22\n");
                PRINTF("hoge23\n");
                PRINTF("MEDIAINIT_AND_WAIT 0\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            case 0xF0:
                PRINTF("MEDIA_NOT_INIT on RecoverManageArea\n");
                PRINTF("MEDIAINIT_AND_WAIT 1\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

void SLMFSGetFilesPreparation(u16 arg0) {
    PRINTF("hoge24\n");
    PRINTF("SLMFSGetFilesPreparation\n");
    PRINTF("SLMFSGetFilesPreparation LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        if (func_80766660(arg0) == 0) {
            return;
        }
        D_8079F9B8 = D_80794CD4;
        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("hoge25\n");
                PRINTF("hoge26\n");
                PRINTF("MEDIAINIT_AND_WAIT 2\n");
                PRINTF("MEDIAINIT_AND_WAIT 3\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern u8 D_34E[];
extern u8 D_391[];
extern u8 D_8077B4D0[];
extern OSMesgQueue gDmaMesgQueue;

void func_80706518(s32 arg0, s32 arg1, s32 arg2) {
    PRINTF("hoge27\n");
    PRINTF("SLMFSMediaInit Mario Artist Custum !!\n");
    PRINTF("correct disk !!\n");
    PRINTF("MEDIA INIT OK !!\n");

    func_80707B08();

    for (D_8079F9CC = 0; D_8079F9CC < D_391 - D_34E; D_8079F9CC++) {
        osWritebackDCacheAll();
        SLLeoReadWrite_DATA(&D_8079F958, OS_READ, (u32) D_34E + D_8079F9CC, D_8077B4D0, 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
        osWritebackDCacheAll();
        SLLeoReadWrite_DATA(&D_8079F958, OS_WRITE, 0xBF6 + D_8079F9CC, D_8077B4D0, 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
    }
    osWritebackDCacheAll();
    SLMFSNewDisk();
}

void SLMFSDeleteFile(u16 arg0, u8* arg1, u8* arg2, s32 arg3) {
    PRINTF("SLMFSDeleteFile name:%s, type:%s\n", arg1, arg2);
    PRINTF("SLMFSDeleteFile LOOP\n");

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        if (func_80764E90(arg0, arg1, arg2, arg3) == 0) {
            PRINTF("SLMFSDeleteFile Good Return\n");
            return;
        }

        D_8079F9B8 = D_80794CD4;
        PRINTF("SLMFSDeleteFile Return %d\n", D_8079F9B8);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
            case 0xF2:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("hoge40\n");
                PRINTF("hoge41\n");
                PRINTF("MEDIAINIT_AND_WAIT 9\n");
                PRINTF("MEDIAINIT_AND_WAIT 10\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 SLMFSLoad(u16 arg0, u8* arg1, u8* arg2, u8* arg3, s32 arg4) {
    PRINTF("hoge42\n");
    PRINTF("============================================================\n");
    PRINTF("SLMFSLoad LOOP %s\n", arg1);

    osRecvMesg(&D_8079F998, NULL, OS_MESG_NOBLOCK);

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        D_8079F9B4 = func_8076543C(arg0, arg1, arg2, arg3, arg4);
        if (D_8079F9B4 == 0) {
            PRINTF("SLMFSLoad good\n");
            PRINTF("MFSMesgQ Send 16\n");
            osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            return D_8079F9B4;
        }
        D_8079F9B8 = D_80794CD4;

        PRINTF("SLMFSLoad error N64DD_NOT_FOUND %s\n", arg1);
        PRINTF("SLMFSLoad error 0x%2X\n", D_8079F9B8);
        PRINTF("name %s, type %s\n", arg1, arg2);

        if (D_80794CD4 == 0xF2) {}
        if (1) {}

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 17\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                PRINTF("FILE NOT FOUND\n");
                return 0;
            case 0xF2:
                PRINTF("MFSMesgQ Send 18\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                return D_8079F9B8;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge43\n");
                PRINTF("hoge44\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoad\n");
                PRINTF("MEDIAINIT_AND_WAIT 11\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                } else if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoad\n");
                    SLMFSDeleteFile(arg0, arg1, arg2, 1);
                }
                PRINTF("MFSMesgQ Send 19\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                return 0xF2;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("MEDIAINIT_AND_WAIT 12\n");
                PRINTF("MEDIAINIT_AND_WAIT 13\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 SLMFSLoadHalfway(u16 arg0, char* name, u8* arg2, u8* arg3, s32 arg4, s32 arg5) {
    PRINTF("hoge45\n");
    PRINTF("SLMFSLoadHalfway LOOP\n");

    osRecvMesg(&D_8079F998, NULL, OS_MESG_NOBLOCK);

    while (true) {
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        D_8079F9B4 = func_80765BC8(arg0, name, arg2, arg3, arg4, arg5);

        if (D_8079F9B4 == 0) {
            PRINTF("MFSMesgQ Send 20\n");
            osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            PRINTF("SLMFSLoadHalfway Finished\n");
            return 0;
        }
        D_8079F9B8 = D_80794CD4;
        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 21\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                return 0;
            case 0xF2:
                PRINTF("MFSMesgQ Send 22\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                return D_8079F9B8;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                PRINTF("MAY_HAVE_CHANGED_IN_LOAD_HALFWAY\n");
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                PRINTF("hoge46\n");
                PRINTF("hoge47\n");
                PRINTF("UNRECOVERD_READ_ERROR ON SLMFSLoadHalfway\n");
                PRINTF("MEDIAINIT_AND_WAIT 14\n");
                if (D_80794CDC == 4) {
                    func_80703948();
                    SLMFSRecoverManageArea();
                } else if (D_80794CDC == 1) {
                    PRINTF("FILE DELETE ON SLMFSLoadHalfway\n");
                    SLMFSDeleteFile(arg0, name, arg2, 1);
                }
                PRINTF("MFSMesgQ Send 23\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                return 0xF2;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("MEDIAINIT_AND_WAIT 15\n");
                PRINTF("MEDIAINIT_AND_WAIT 16\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return 0xF2;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

void SLMFSSave(u16 arg0, u8* arg1, u8* arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    PRINTF("hoge48\n");
    PRINTF("SLMFSSave\n");
    PRINTF("SLMFSSave LOOP\n");

    osRecvMesg(&D_8079F998, NULL, OS_MESG_NOBLOCK);
    while (true) {
        func_80704068();
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        func_807040C8();
        if (func_8076321C(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) == 0) {
            PRINTF("MFSMesgQ Send 24\n");
            osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
            return;
        }
        D_8079F9B8 = D_80794CD4;
        PRINTF("SLMFSSave Error %d\n", D_8079F9B8);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                PRINTF("MFSMesgQ Send 25\n");
                osSendMesg(&D_8079F998, NULL, OS_MESG_BLOCK);
                if (0) {
                    PRINTF("SLMFSSave 0\n");
                    PRINTF("SLMFSSave 1\n");
                    PRINTF("SLMFSSave 2\n");
                    PRINTF("hoge49\n");
                    PRINTF("SLMFSSave 3\n");
                    PRINTF("hoge50\n");
                }
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_UNRECOVERED_READ_ERROR:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0x10A:
                func_80703948();
                SLMFSRecoverManageArea();
                break;
            case 0xF0:
                PRINTF("MEDIAINIT_AND_WAIT 17\n");
                PRINTF("MEDIAINIT_AND_WAIT 18\n");
                PRINTF("MEDIAINIT_AND_WAIT 19\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                break;
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 SLMFSCreateManager(s32 region) {
    PRINTF("hoge51\n");
    PRINTF("hoge52\n");

    func_80705A98();
    if ((func_8076007C(region, D_8079F9D0, 0x10) != 0) &&
        (D_80794CD4 == LEO_ERROR_DEVICE_COMMUNICATION_FAILURE)) {
        func_8070F8A4(D_8079F9B8, 0);
        while (true) {}
    }
    PRINTF("MFS Create Manager Success\n");
    D_8076CBB8 = 1;
    return 0;
}

void SLMFSNewDisk(void) {
    PRINTF("SLMFSNewDisk\n");
    PRINTF("SLMFSNewDisk LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9BC = func_807603A8();
        if (D_8079F9BC == 0) {
            func_8070470C();
            PRINTF("SLMFSNewDisk return %d\n", D_8079F9BC);
            return;
        }
        D_8079F9B8 = D_80794CD4;

        PRINTF("SLMFSNewDisk OK (ENTRY LOAD BEFORE)\n");
        PRINTF("SLMFSNewDisk OK (ENTRY LOAD AFTER)\n");
        PRINTF("ERROR SLMFSNewDisk %d\n", D_8079F9B8);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
            case 0xF6:
                PRINTF("SLMFSNewDisk Good case\n");
                PRINTF("hoge53\n");
                PRINTF("hoge54\n");
                PRINTF("hoge55 %d <-> %d\n");
                PRINTF("hoge55_2\n");
                PRINTF("SLMFSNewDisk Function End\n");
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case 0xF7:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

void SLMFSNewDisk2(void) {
    PRINTF("SLMFSNewDisk\n");
    PRINTF("SLMFSNewDisk LOOP\n");

    while (true) {
        func_80707B08();
        D_8079F9BC = func_807603A8();

        if (D_8079F9BC == 0) {
            PRINTF("SLMFSNewDisk return %d\n", D_8079F9BC);
            return;
        }

        D_8079F9B8 = D_80794CD4;
        PRINTF("ERROR SLMFSNewDisk %d\n", D_8079F9B8);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
            case 0xF6:
                PRINTF("SLMFSNewDisk Good case\n");
                PRINTF("hoge53\n");
                PRINTF("hoge54\n");
                PRINTF("hoge55 %d <-> %d\n");
                PRINTF("hoge55_2\n");
                PRINTF("SLMFSNewDisk Function End\n");
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                break;
            case LEO_ERROR_COMMAND_TERMINATED:
            case 0xF7:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

void SLMFSFlushManageArea(void) {
    PRINTF("SLMFSFlushManageArea LOOP\n");

    while (true) {
        func_80704068();
        func_80707B08();
        if (D_8076CBB0 != 0) {
            SLMFSNewDisk();
            D_8076CBB0 = 0;
        }
        func_807040C8();
        if (Mfs_WriteRamArea() == 0) {
            return;
        }
        D_8079F9B8 = D_80794CD4;
        PRINTF("SLMFSFlushManageArea Error %d\n", D_8079F9B8);

        if (0) {
            PRINTF("SLMFSFlush 0\n");
            PRINTF("SLMFSFlush 1\n");
            PRINTF("SLMFSFlush 2\n");
            PRINTF("hoge56\n");
            PRINTF("SLMFSFlush 3\n");
        }

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return;
            case LEO_ERROR_BUSY:
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 4);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                func_80704068();
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_DIAGNOSTIC_FAILURE:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 2);
                while (func_80707780() != 0) {}
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
                func_80704068();
                func_8070F8A4(D_8079F9B8, 1);
                while (SLCheckDiskInsert() != 0) {}
                func_807040C8();
                break;
            case 0xF0:
                PRINTF("hoge57\n");
                PRINTF("MEDIAINIT_AND_WAIT 20\n");
                PRINTF("hoge58\n");
                func_80704068();
                func_807038B0();
                func_80706518(1, 0x20, 0);
                func_807040C8();
                return;
            case LEO_ERROR_COMMAND_TERMINATED:
            case LEO_ERROR_DEVICE_COMMUNICATION_FAILURE:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

extern LEOCmd D_8079F958;

s32 func_80707780(void) {
    while (true) {
        LeoSpdlMotor(&D_8079F958, LEO_MOTOR_BRAKE, &D_8079F978);
        osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);
        switch (D_8079F9B8) {
            case LEO_ERROR_QUEUE_FULL:
                func_80704CE0();
                break;
            case LEO_ERROR_GOOD:
                return 1;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                return 0;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                return 0;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

s32 func_80707868(LEODiskID* diskId) {
    PRINTF("hoge1\n");

    LeoReadDiskID(&D_8079F958, diskId, &D_8079F978);
    osRecvMesg(&D_8079F978, &D_8079F9B8, OS_MESG_BLOCK);

    PRINTF("GAME ID IS %c%c%c%c\n", diskId->gameName[0], diskId->gameName[1], diskId->gameName[2], diskId->gameName[3]);

    switch (D_8079F9B8) {
        case LEO_ERROR_GOOD:
            D_8076CBBC = 1;
            return D_8079F9B8;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            break;
        case LEO_ERROR_DIAGNOSTIC_FAILURE:
            func_8070F8A4(D_8079F9B8, 2);
            while (func_80707780() != 0) {}
            break;
        case LEO_ERROR_EJECTED_ILLEGALLY_RESUME:
            func_8070F8A4(D_8079F9B8, 1);
            break;
        case LEO_ERROR_COMMAND_TERMINATED:
        case LEO_ERROR_QUEUE_FULL:
        default:
            func_8070F8A4(D_8079F9B8, 0);
            while (true) {}
    }
    return D_8079F9B8;
}

s32 SLCheckDiskInsert(void) {
    PRINTF("hoge4\n");

    D_8079F9B8 = LeoTestUnitReady(&D_8079F954);
    switch (D_8079F9B8) {
        case LEO_ERROR_GOOD:
            PRINTF("Test Unit Ready In check_insert -> GOOD\n");
            if (D_8076CBBC == 0) {
                if (func_80707868(&D_8076CB50) == 0) {
                    D_8076CBB0 = 1;
                    return 0;
                }
                return 1;
            }
            return 0;
        case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
            PRINTF("Test Unit Ready -> MAY_HAVE_CHANGED\n");
            if (func_80707868(&D_8076CB50) == 0) {
                D_8076CBB0 = 1;
                return 0;
            }
            break;
        case LEO_ERROR_BUSY:
            return 2;
        case LEO_ERROR_MEDIUM_NOT_PRESENT:
            return 1;
        case LEO_ERROR_COMMAND_TERMINATED:
        default:
            func_8070F8A4(D_8079F9B8, 0);
            while (true) {}
    }
    return 1;
}

s32 SLCheckDiskChange2(void) {
    PRINTF("hoge8\n");
    PRINTF("hoge0\n");

    while (true) {
        D_8079F9B8 = LeoTestUnitReady(&D_8079F954);

        switch (D_8079F9B8) {
            case LEO_ERROR_GOOD:
                return 0;
            case LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED:
                PRINTF("MAY_HAVE_CHANGE in SLCheckDiskChange2 newdisk request\n");
                PRINTF("In Edit\n");
                return 1;
            case LEO_ERROR_BUSY:
                func_80704CE0();
                break;
            case LEO_ERROR_MEDIUM_NOT_PRESENT:
                PRINTF("In Game\n");
                PRINTF("MAY_HAVE_CHANGE in SLCheckDiskChange2 newdisk request\n");
                return 1;
            case LEO_ERROR_COMMAND_TERMINATED:
            default:
                func_8070F8A4(D_8079F9B8, 0);
                while (true) {}
        }
    }
}

void func_80707B08(void) {
    if (SLCheckDiskChange2() != 0) {
        SLLeoReadDiskID(&D_8076CB50);
        D_8076CBB0 = 1;
    }
    if (D_8076CBB4 == 0) {
        func_80704068();
        while (func_807041C0(D_8076CB50) != 2) {
            func_8070F8A4(D_8079F9B8, 3);
            while (func_80707780() != 0) {}
            while (SLCheckDiskInsert() != 0) {}
            D_8076CBB0 = 1;
        }
        func_807040C8();
    } else {
        func_80704068();
        while (func_80704F44(D_8076CB50, D_8076CB70)) {
            func_8070F8A4(D_8079F9B8, 8);
            while (func_80707780() == 1) {}
            while (SLCheckDiskInsert() != 0) {}
            D_8076CBB0 = 1;
        }
        func_807040C8();
    }
}

void func_80707E58(void) {
    if (SLCheckDiskChange2() != 0) {
        SLLeoReadDiskID(&D_8076CB50);
        D_8076CBB0 = 1;
    }
    while (func_80704F44(D_8076CB50, D_8076CB90) != 0) {
        func_8070F8A4(-1, 12);
        while (func_80707780() == 1) {}
        while (SLCheckDiskInsert() != 0) {}
        D_8076CBB0 = 1;
    }
}
