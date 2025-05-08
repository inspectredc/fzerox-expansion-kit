#include "global.h"
#include "leo/leo_internal.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806F9750.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806F9774.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806F9DB4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FB3AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FBBC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC340.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC3AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC3E0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC44C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC47C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC4E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC54C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC5F4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC664.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC70C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC804.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC900.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FC9FC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FCAF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FCBF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FCCE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FCE04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FCECC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FD3C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FDA64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FE174.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FE8F8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FEEEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF12C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF364.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF598.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_806FF630.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700254.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700570.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_807009C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700B18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700CE4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80700EBC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701094.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701328.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701360.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_807016AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701754.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070183C.s")

extern OSIoMesg D_8079A308;
extern OSMesgQueue gDmaMesgQueue;
extern OSPiHandle* gCartRomHandle;

void func_80701C04(void* romAddr, void* ramAddr, size_t size) {
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_8079A308.hdr.pri = 0;
    D_8079A308.hdr.retQueue = &gDmaMesgQueue;
    D_8079A308.dramAddr = osPhysicalToVirtual(ramAddr);
    D_8079A308.devAddr = romAddr;
    D_8079A308.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    osEPiStartDma(gCartRomHandle, &D_8079A308, OS_READ);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

void func_80701CAC(void* romAddr, void* ramAddr, size_t size) {
    OSMesg sp20[8];

    if (gDmaMesgQueue.validCount >= gDmaMesgQueue.msgCount) {
        osRecvMesg(&gDmaMesgQueue, sp20, OS_MESG_BLOCK);
    }
    osInvalDCache(osPhysicalToVirtual(ramAddr), size);
    D_8079A308.hdr.pri = OS_MESG_PRI_NORMAL;
    D_8079A308.hdr.retQueue = &gDmaMesgQueue;
    D_8079A308.dramAddr = osPhysicalToVirtual(ramAddr);
    D_8079A308.devAddr = (uintptr_t) romAddr;
    D_8079A308.size = size;
    gCartRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    func_80768B88(gCartRomHandle, &D_8079A308, OS_READ);
    osRecvMesg(&gDmaMesgQueue, sp20, OS_MESG_BLOCK);
}

void func_80701D7C(u8* romAddr, u8* ramAddr, size_t size) {
    s32 remainder;
    s32 i;
    s32 numBlocks = size / 1024;

    for (i = 0; i < numBlocks; i++) {
        func_80701CAC(romAddr, ramAddr, 0x400);

        romAddr += 0x400;
        ramAddr += 0x400;
    }

    remainder = size % 1024;
    if (remainder) {
        func_80701CAC(romAddr, ramAddr, remainder);
    }
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701E08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/D_807735F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80701E90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702448.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702974.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070299C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702A68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702A94.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702BC4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702D6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702E0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702F1C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80702FF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_8070304C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80703228.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/6F50/func_80703234.s")
