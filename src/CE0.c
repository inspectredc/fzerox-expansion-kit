#include "global.h"
#include "fzx_game.h"
#include "fzx_thread.h"

extern s32 D_8079A364;
extern s32 D_8079A368;
extern s32 D_8079A36C;

void func_806F34E0(void) {
    s32 temp_t7;

    temp_t7 = D_8079A368;
    D_8079A368 = D_8079A364;
    D_8079A364 = D_8079A36C;
    D_8079A36C = temp_t7;
}

extern s32 D_8079A35C;
extern s32 D_8079A360;
extern GfxPool* gGfxPool;
extern OSTask* sGfxTask;
extern Gfx* gMasterDisp;

extern GfxPool D_8024E260[2];
extern OSTask D_802BB0C0[];

void Gfx_InitBuffer(void) {

    D_8079A360 ^= 1;
    D_8079A35C ^= 1;
    sGfxTask = &D_802BB0C0[D_8079A35C];
    gGfxPool = &D_8024E260[D_8079A35C];
    Segment_SetPhysicalAddress(1, gGfxPool);
    gMasterDisp = gGfxPool->gfxBuffer;
}

extern s32 D_80128C90;

void Gfx_LoadSegments(void) {
    Segment_SetPhysicalAddress(6, (D_8079A35C * 0x1AF08) + D_80128C90);
    gMasterDisp = Segment_SetTableAddresses(gMasterDisp);
}

extern s32 D_8076C954;

void Gfx_FullSync(void) {

    if (D_8076C954 != 0) {
        gMasterDisp = func_8002ED64(gMasterDisp);
    }
    
    gMasterDisp = func_8002F9DC(gMasterDisp);
    
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);
}

extern OSMesgQueue gMainThreadMesgQueue;
extern s32 gGameMode;
extern OSTask* gCurGfxTask;

void Gfx_SetTask(OSTask* task) {

    task->t.type = M_GFXTASK;
    task->t.flags = OS_TASK_LOADABLE;
    task->t.ucode_boot = (u64*) rspbootTextStart;
    task->t.ucode_boot_size = (uintptr_t) rspbootTextEnd - (uintptr_t) rspbootTextStart;

    switch (gGameMode & GAMEMODE_F3D_MASK) {
        case GFXMODE_F3DEX:
            task->t.ucode = (u64*) gspF3DEX_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DEX_fifoDataStart;
            break;
        case GFXMODE_F3DLX:
            task->t.ucode = (u64*) gspF3DLX_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DLX_Rej_fifoDataStart;
            break;
        case GFXMODE_F3DFLX:
            task->t.ucode = (u64*) gspF3DFLX_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DFLX_Rej_fifoDataStart;
            break;
    }

    task->t.ucode_size = SP_UCODE_SIZE;
    task->t.ucode_data_size = SP_UCODE_DATA_SIZE;
    task->t.dram_stack = (u64*) gDramStack;
    task->t.dram_stack_size = SP_DRAM_STACK_SIZE8;
    task->t.output_buff = (u64*) gTaskOutputBuffer;
    task->t.output_buff_size = (u64*) (gTaskOutputBuffer + ARRAY_COUNT(gTaskOutputBuffer));
    task->t.data_ptr = (u64*) gGfxPool->gfxBuffer;
    task->t.data_size = (size_t) (gMasterDisp - gGfxPool->gfxBuffer) * sizeof(Gfx);
    task->t.yield_data_ptr = (u64*) gOSYieldData;
    task->t.yield_data_size = OS_YIELD_DATA_SIZE;
    gCurGfxTask = task;
    osSendMesg(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_GFX_TASK_SET, OS_MESG_BLOCK);
}

extern FrameBuffer* gFrameBuffers[];
extern OSMesgQueue D_8079A0F0;
extern OSMesgQueue D_8079A108;
extern OSMesg D_8079A370;

void func_806F37F0(void) {
    MQ_WAIT_FOR_MESG(&D_8079A0F0, &D_8079A370);
    func_80745CB8();
    Gfx_InitBuffer();
    func_806F5310();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    MQ_WAIT_FOR_MESG(&D_8079A108, &D_8079A370);

    while (osDpGetStatus() &
           (DPC_STATUS_DMA_BUSY | DPC_STATUS_CMD_BUSY | DPC_STATUS_PIPE_BUSY | DPC_STATUS_TMEM_BUSY)) {}

    func_80709C3C();
    func_800A2CCC();
    osViSwapBuffer(gFrameBuffers[D_8079A360]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[D_8079A360]) {}

    Gfx_SetTask(sGfxTask);
}

void func_806F3924(void) {
    s32 retries = 100000;

    MQ_WAIT_FOR_MESG(&D_8079A0F0, &D_8079A370);
    Gfx_InitBuffer();
    func_806F5310();
    func_806F34E0();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    func_80745CB8();
    MQ_WAIT_FOR_MESG(&D_8079A108, &D_8079A370);
    func_800A2CCC();
    osViSwapBuffer(gFrameBuffers[D_8079A368]);
    func_80709C3C();

    while ((osViGetCurrentFramebuffer() == gFrameBuffers[D_8079A364] ||
            osViGetNextFramebuffer() == gFrameBuffers[D_8079A364]) &&
           retries != 0) {
        retries--;
    }

    Gfx_SetTask(sGfxTask);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/CE0/Game_ThreadEntry.s")
