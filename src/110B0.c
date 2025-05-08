#include "global.h"

extern Controller D_8079A7F0;
extern OSMesgQueue gSerialEventQueue;

void func_807038B0(void) {
    s32 sp24;

    func_8070F8A4(-1, 6);
    sp24 = osRecvMesg(&gSerialEventQueue, NULL, 0);
    do {
        osContStartReadData(&gSerialEventQueue);
        func_806F5B70();
    } while (!(D_8079A7F0.buttonPressed & BTN_A));
    if (sp24 != -1) {
        osContStartReadData(&gSerialEventQueue);
    }
    func_8070F8A4(-1, 0xA);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/110B0/func_80703948.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/110B0/func_807039D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/110B0/func_80703B40.s")

extern u8 D_8077B4D0[];
extern OSMesgQueue gDmaMesgQueue;

s32 func_80703CA4(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp58;
    s32 lbaCount;
    s32 nBytes;
    LEOCmd sp34;

    nBytes = 0;
    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        func_80768A5C(&sp34, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, 1);
    }
    diskSize -= nBytes;
    func_80768A5C(&sp34, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_8077B4D0), 1,
                  &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, 1);
    bcopy(&D_8077B4D0, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    return sp58;
}

extern s32 D_8076C770;
extern s32 D_8076CB40;

s32 func_80703E08(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
    void* bssStart;
    s32 sp70;
    s32 sp6C;
    s32 var_a0;
    LEOCmd sp4C;
    OSMesg sp48;
    s32 pad[2];

    LeoByteToLBA(startLba, diskSize, &sp6C);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);
    func_80768A5C(&sp4C, 0, startLba, vram, sp6C, &gDmaMesgQueue);

    if (D_8076CB40 != -1) {
        func_i10_8012B854();
    }

    while (osRecvMesg(&gDmaMesgQueue, &sp48, 0) == -1) {
        if (D_8076CB40 != -1) {
            osWritebackDCacheAll();
            var_a0 = (D_8076C770 - D_8076CB40) / 6 + 160;
            if (var_a0 > 192) {
                var_a0 = 192;
            }
            func_i10_8012B894(var_a0);
            osWritebackDCacheAll();
        }
    }
    bzero(bssStart, bssSize);
    return sp70;

    // Todo: move into own funcs
    PRINTF("WAIT MEDIA INIT\n");
    PRINTF("WAIT MEDIA START\n");
    PRINTF("WAIT RECOVER MANAGE AREA\n");
    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n");
    PRINTF("========================================================\n");
    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n");
    PRINTF("========================================================\n");
    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n");
    PRINTF("========================================================\n");
    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n");
    PRINTF("========================================================\n");
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/110B0/func_80703F90.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/110B0/func_80703FC8.s")
