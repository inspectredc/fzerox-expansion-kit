#include "global.h"
#include "leo/leo_internal.h"

void func_80708050(void) {
}

extern OSMesgQueue gDmaMesgQueue;
extern OSIoMesg gDmaIOMsg;
extern OSPiHandle* gCartRomHandle;

void func_80708058(u8* romAddr, u8* ramAddr, size_t size) {
    OSMesg msgBuf[7];

    gDmaIOMsg.hdr.pri = 0;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gCartRomHandle, &gDmaIOMsg, OS_READ);
    osRecvMesg(&gDmaMesgQueue, msgBuf, OS_MESG_BLOCK);
}

void func_807080E8(u8* romAddr, u8* ramAddr, size_t size, u8* bssAddr, size_t bssSize) {
    OSMesg msgBuf[7];

    gDmaIOMsg.hdr.pri = 0;
    gDmaIOMsg.hdr.retQueue = &gDmaMesgQueue;
    gDmaIOMsg.dramAddr = osPhysicalToVirtual(ramAddr);
    gDmaIOMsg.devAddr = romAddr;
    gDmaIOMsg.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gCartRomHandle, &gDmaIOMsg, OS_READ);
    bzero(bssAddr, bssSize);
    osRecvMesg(&gDmaMesgQueue, msgBuf, OS_MESG_BLOCK);
}

void func_8070818C(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80708058(romAddr, ramAddr, 0x400);
        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        func_80708058(romAddr, ramAddr, remainder);
    }
}

void func_80708218(u8* romAddr, u8* ramAddr, size_t size, void* bssAddr, size_t bssSize) {
    s32 remainder;
    s32 i;
    s32 numBlocks;

    numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80708058(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }
    remainder = size % 1024;
    if (remainder != 0) {
        func_807080E8(romAddr, ramAddr, remainder, bssAddr, bssSize);
    }
}
