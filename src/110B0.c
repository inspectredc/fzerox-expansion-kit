#include "global.h"

extern Controller D_8079A7F0;
extern OSMesgQueue gSerialEventQueue;

void func_807038B0(void) {
    s32 sp24;

    PRINTF("WAIT MEDIA INIT\n");
    PRINTF("WAIT MEDIA START\n");
    PRINTF("WAIT RECOVER MANAGE AREA\n");

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

void func_80703948(void) {
    s32 sp24;

    func_8070F8A4(-1, 7);
    sp24 = osRecvMesg(&gSerialEventQueue, NULL, 0);
    do {
        osContStartReadData(&gSerialEventQueue);
        func_806F5B70();
    } while (!(D_8079A7F0.buttonPressed & BTN_A));
    if (sp24 != -1) {
        osContStartReadData(&gSerialEventQueue);
    }
}

extern s32 D_8076CB44;
extern u8 D_8077B4D0[];
extern OSMesgQueue gDmaMesgQueue;

s32 func_807039D4(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
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

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize, lbaCount);
    PRINTF("========================================================\n");

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        SLLeoReadWrite(&sp34, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, 1);
    }
    diskSize -= nBytes;
    SLLeoReadWrite(&sp34, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_8077B4D0), 1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, 1);
    bcopy(D_8077B4D0, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    D_8076CB44 = 0;
    return sp58;
}

s32 func_80703B40(s32 startLba, void* vram, s32 diskSize, s32 bssSize) {
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

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize, lbaCount);
    PRINTF("========================================================\n");

    if (lbaCount - 1) {
        LeoLBAToByte(startLba, lbaCount - 1, &nBytes);
        func_80768AF0(&sp34, OS_READ, startLba, osPhysicalToVirtual((uintptr_t) vram), lbaCount - 1, &gDmaMesgQueue);
        osRecvMesg(&gDmaMesgQueue, NULL, 1);
    }
    diskSize -= nBytes;
    func_80768AF0(&sp34, OS_READ, (startLba + lbaCount) - 1, osPhysicalToVirtual((uintptr_t) D_8077B4D0), 1, &gDmaMesgQueue);
    osRecvMesg(&gDmaMesgQueue, NULL, 1);
    bcopy(D_8077B4D0, osPhysicalToVirtual((uintptr_t) vram + nBytes), diskSize);
    bzero((uintptr_t) vram + nBytes + diskSize, bssSize);
    return sp58;
}

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

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize, lbaCount);
    PRINTF("========================================================\n");

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
    s32 lbaCount;
    s32 var_a0;
    LEOCmd sp4C;
    OSMesg sp48;
    s32 pad[2];

    LeoByteToLBA(startLba, diskSize, &lbaCount);
    osVirtualToPhysical(vram);
    bssStart = (uintptr_t) vram + diskSize;
    osVirtualToPhysical(bssStart);
    osVirtualToPhysical((uintptr_t) bssStart + bssSize);
    func_80768A5C(&sp4C, OS_READ, startLba, vram, lbaCount, &gDmaMesgQueue);

    PRINTF("========================================================\n");
    PRINTF("LBA %d, dist 0x%x-0x%x-0x%x , %dLBAs\n", startLba, vram, bssStart, (uintptr_t) bssStart + bssSize, lbaCount);
    PRINTF("========================================================\n");

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
}

extern u8 D_807C70A0[];

void func_80703F90(void) {
    size_t size = osAppNMIBuffer[1] - osAppNMIBuffer[0];
    func_80701C04(osAppNMIBuffer[0], D_807C70A0, size);
}

extern FrameBuffer* gFrameBuffers[];

void func_80703FC8(void) {
    u8 i;
    u64* var_v0;
    u64* temp;

    SLForceWritebackDCacheAll();

    for (i = 0; i < 3; i++) {
        // FAKE
        temp = gFrameBuffers[i]->buffer;
        var_v0 = &gFrameBuffers[i]->buffer[19199];
        while (var_v0 >= temp) {
            var_v0--;
            *(var_v0 + 1) = 0x0001000100010001;
        }
    }
    SLForceWritebackDCacheAll();
}
