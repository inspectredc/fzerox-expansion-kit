#include "global.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80738FA0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80738FC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073954C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739930.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739984.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_807399CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739A64.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_QueueCmdF32.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_QueueCmdU32.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_QueueCmdS8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739B28.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739B58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739BBC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739BD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739D18.s")

extern OSMesgQueue D_806EE200;

u32 AudioThread_GetAsyncLoadStatus(u32* outData) {
    u32 loadStatus;

    if (osRecvMesg(&D_806EE200, &loadStatus, OS_MESG_NOBLOCK) == -1) {
        *outData = 0;
        return 0;
    }
    *outData = loadStatus & 0xFFFFFF;
    return loadStatus >> 0x18;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739E30.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739E50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_ResetComplete.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739EE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_ResetAudioHeap.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_PreNMIInternal.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A01C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A070.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A098.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A0C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A0D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A2AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A468.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A4B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A4D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A508.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A548.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A638.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A658.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A678.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A79C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_8073A7F4.s")
