#include "global.h"
#include "audio.h"
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
        gMasterDisp = func_xk1_8002ED64(gMasterDisp);
    }

    gMasterDisp = func_xk1_8002F9DC(gMasterDisp);

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
    func_i2_800A2CCC();
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
    func_i2_800A2CCC();
    osViSwapBuffer(gFrameBuffers[D_8079A368]);
    func_80709C3C();

    while ((osViGetCurrentFramebuffer() == gFrameBuffers[D_8079A364] ||
            osViGetNextFramebuffer() == gFrameBuffers[D_8079A364]) &&
           retries != 0) {
        retries--;
    }

    Gfx_SetTask(sGfxTask);
}

// #pragma GLOBAL_ASM("asm/jp/nonmatchings/CE0/Game_ThreadEntry.s")

extern u32 D_8079A374;
extern u32 D_8079A378;
extern u32 D_8079A37C;
extern u32 D_8079A380;
extern u32 D_8079A384;
extern u32 D_8079A388;
extern u32 D_8079A38C;
extern u32 D_8079A390;
extern u32 D_8079A394;
extern u32 D_8079A398;
extern u32 D_8079A39C;
extern u32 D_8079A3A0;
extern u32 D_8079A3A4;
extern u32 D_8079A3A8;
extern u32 D_8079A3AC;
extern u32 D_8079A3B0;
extern u32 D_8079A3B4;
extern u32 D_8079A3B8;
extern u32 D_8079A3BC;
extern u32 D_8079A3C0;
extern u32 D_8079A3E4;
extern u32 D_8079A3E8;
extern u32 D_8079A3EC;
extern u32 D_8079A3F0;
extern u32 D_8079A3F4;
extern u32 D_8079A3F8;
extern u32 D_8079A3FC;
extern u32 D_8079A400;
extern u32 D_8079A474;
extern u32 D_8079A478;
extern u32 D_8079A47C;
extern u32 D_8079A480;
extern u32 D_8079A484;
extern u32 D_8079A488;
extern u32 D_8079A48C;
extern u32 D_8079A490;
extern u32 D_8079A404;
extern u32 D_8079A408;
extern u32 D_8079A40C;
extern u32 D_8079A410;

extern u32 D_8079A414;
extern u32 D_8079A478;
extern u32 D_8079A418;
extern u32 D_8079A41C;
extern u32 D_8079A420;
extern u32 D_8079A424;
extern u32 D_8079A428;
extern u32 D_8079A434;
extern u32 D_8079A438;
extern u32 D_8079A43C;
extern u32 D_8079A388;
extern u32 D_8079A440;
extern u32 D_8079A444;
extern u32 D_8079A448;
extern u32 D_8079A46C;
extern u32 D_8079A470;
extern u32 D_8079A45C;
extern u32 D_8079A460;
extern u32 D_8079A464;
extern u32 D_8079A468;
extern u32 D_8079A3D4;
extern u32 D_8079A3D8;
extern u32 D_8079A42C;
extern u32 D_8079A430;
extern u32 D_8079A3DC;
extern u32 D_8079A3E0;

extern u8 D_800D6D90[];
extern u8 D_8013A7F0[];
extern u8 D_8012B520[];
extern u8 D_801414E0[];
extern u8 D_7000000_VRAM[];
extern u8 D_7000000_VRAM_END[];

extern s32 D_8076CB40;
extern s32 D_8076C770;

extern s32 D_807C70D8;
extern s32 D_807C70F0;
extern s32 D_807C7118;
extern s32 gRamDDCompatible;
extern s32 D_8079A32C;

extern unk_80225800 D_80225800;
extern s16 gSettingSoundMode;
extern u32 gGameFrameCount;
extern s16 D_8076C7A4;
extern s16 D_8076C7A8;

void Game_ThreadEntry(void* entry) {
    s32 startTime;
    OSMesg msgBuf[1];

    startTime = osGetTime();
    func_8074279C();
    osRecvMesg(&D_8079A0F0, msgBuf, OS_MESG_BLOCK);

    // Segment Start and End Pairs
    D_8079A374 = osVirtualToPhysical(SEGMENT_VRAM_START(main));
    D_8079A378 = osVirtualToPhysical(SEGMENT_VRAM_END(main));
    D_8079A37C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i2));
    D_8079A380 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i2));
    D_8079A384 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i3));
    D_8079A388 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i3));
    D_8079A38C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i4));
    D_8079A390 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i4));
    D_8079A394 = osVirtualToPhysical(SEGMENT_VRAM_START(course_select));
    D_8079A398 = osVirtualToPhysical(SEGMENT_VRAM_END(course_select));
    D_8079A39C = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i6));
    D_8079A3A0 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i6));
    D_8079A3A4 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i7));
    D_8079A3A8 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i7));
    D_8079A3AC = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i8));
    D_8079A3B0 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i8));
    D_8079A3B4 = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i9));
    D_8079A3B8 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i9));
    D_8079A3BC = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i10));
    D_8079A3C0 = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i10));
    D_8079A3E4 = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer1));
    D_8079A3E8 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer1));
    D_8079A3EC = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer2));
    D_8079A3F0 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer2));
    D_8079A3F4 = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer3));
    D_8079A3F8 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer3));
    D_8079A3FC = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer_unused));
    D_8079A400 = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer_unused));
    D_8079A474 = osVirtualToPhysical(SEGMENT_VRAM_START(buffers));
    D_8079A478 = osVirtualToPhysical(SEGMENT_VRAM_END(buffers));
    D_8079A47C = osVirtualToPhysical(SEGMENT_VRAM_START(unk_gfx_segment));
    D_8079A480 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_gfx_segment));
    D_8079A484 = osVirtualToPhysical(SEGMENT_VRAM_START(unk_context));
    D_8079A488 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_context));
    D_8079A48C = osVirtualToPhysical(SEGMENT_VRAM_START(audio_context));
    D_8079A490 = osVirtualToPhysical(SEGMENT_VRAM_END(audio_context) + 0x10);
    D_8079A404 = osVirtualToPhysical(SEGMENT_VRAM_START(gfxpool));
    D_8079A408 = osVirtualToPhysical(SEGMENT_VRAM_END(gfxpool));
    D_8079A40C = osVirtualToPhysical(SEGMENT_VRAM_START(unk_bss_segment));
    D_8079A410 = osVirtualToPhysical(SEGMENT_VRAM_END(unk_bss_segment));

    D_8079A414 = D_8079A478;
    D_8079A418 = D_8079A414 + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0);

    D_8079A41C = D_8079A418;
    D_8079A420 = D_8079A41C + (size_t) SEGMENT_VRAM_SIZE(segment_17B1E0);

    D_8079A424 = D_8079A420;
    D_8079A428 = D_8079A424 + (size_t) SEGMENT_VRAM_SIZE(segment_17B960);

    D_8079A434 = D_8079A428;
    D_8079A438 = D_8079A434 + (size_t) SEGMENT_VRAM_SIZE(segment_1B8550);

    D_8079A43C = D_8079A388;
    D_8079A440 = D_8079A43C + (size_t) SEGMENT_VRAM_SIZE(segment_1E23F0);

    D_8079A444 = D_8079A428;
    D_8079A448 = D_8079A444 + (size_t) SEGMENT_DATA_SIZE_CONST(segment_22B0A0);

    D_8079A46C = D_8079A420;
    D_8079A470 = D_8079A46C + 0x35E10;

    D_8079A45C = D_8079A470;
    D_8079A460 = D_8079A45C + (size_t) SEGMENT_VRAM_SIZE(course_edit_textures);

    D_8079A464 = D_8079A470;
    D_8079A468 = D_8079A464 + (size_t) SEGMENT_VRAM_SIZE(create_machine_textures);

    D_8079A3D4 = osVirtualToPhysical(D_800D6D90);
    D_8079A3D8 = osVirtualToPhysical(D_8013A7F0);

    D_8079A42C = D_8079A3D8;
    D_8079A430 = D_8079A42C + (size_t) SEGMENT_VRAM_SIZE(D_7000000);

    D_8079A3DC = osVirtualToPhysical(D_8012B520);
    D_8079A3E0 = osVirtualToPhysical(D_801414E0);

    // Setup memory
    Segment_SetAddress(0, 0);
    Segment_SetAddress(2, D_8079A40C);
    Segment_SetAddress(8, D_8079A414);
    Segment_SetAddress(3, D_8079A41C);
    Segment_SetPhysicalAddress(6, (D_8079A35C * 0x1AF08) + D_80128C90);
    
    func_806F6094();
    func_807083D8();
    func_80708430();

    while (func_80742790() != 2) {}
    
    while (func_807424CC() != 0) {}

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10), SEGMENT_DATA_START(ovl_i10), SEGMENT_DATA_SIZE(ovl_i10));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10),
                  SEGMENT_DISK_SIZE(ovl_i10), SEGMENT_BSS_SIZE(ovl_i10));

    D_8076CB40 = D_8076C770;
                  
    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_xk1), SEGMENT_TEXT_SIZE(ovl_xk1), SEGMENT_DATA_START(ovl_xk1), SEGMENT_DATA_END(ovl_xk1) - SEGMENT_DATA_START(ovl_xk1));
    
    func_80703E08(SEGMENT_DISK_START(ovl_xk1), SEGMENT_VRAM_START(ovl_xk1),
                SEGMENT_DISK_SIZE(ovl_xk1), SEGMENT_BSS_SIZE(ovl_xk1));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i3), SEGMENT_TEXT_SIZE(ovl_i3), SEGMENT_DATA_START(ovl_i3), SEGMENT_DATA_SIZE(ovl_i3));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i3), SEGMENT_VRAM_START(ovl_i3),
                  SEGMENT_DISK_SIZE(ovl_i3), SEGMENT_BSS_SIZE(ovl_i3));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i4), SEGMENT_TEXT_SIZE(ovl_i4), SEGMENT_DATA_START(ovl_i4), SEGMENT_DATA_SIZE(ovl_i4));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i4), SEGMENT_VRAM_START(ovl_i4),
                  SEGMENT_DISK_SIZE(ovl_i4), SEGMENT_BSS_SIZE(ovl_i4));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(course_select), SEGMENT_TEXT_SIZE(course_select), SEGMENT_DATA_START(course_select), SEGMENT_DATA_SIZE(course_select));
    
    func_80703E08(SEGMENT_DISK_START(course_select), SEGMENT_VRAM_START(course_select),
                  SEGMENT_DISK_SIZE(course_select), SEGMENT_BSS_SIZE(course_select));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i6), SEGMENT_TEXT_SIZE(ovl_i6), SEGMENT_DATA_START(ovl_i6), SEGMENT_DATA_SIZE(ovl_i6));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i6), SEGMENT_VRAM_START(ovl_i6),
                  SEGMENT_DISK_SIZE(ovl_i6), SEGMENT_BSS_SIZE(ovl_i6));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i7), SEGMENT_TEXT_SIZE(ovl_i7), SEGMENT_DATA_START(ovl_i7), SEGMENT_DATA_SIZE(ovl_i7));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i7), SEGMENT_VRAM_START(ovl_i7),
                  SEGMENT_DISK_SIZE(ovl_i7), SEGMENT_BSS_SIZE(ovl_i7));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i8), SEGMENT_TEXT_SIZE(ovl_i8), SEGMENT_DATA_START(ovl_i8), SEGMENT_DATA_SIZE(ovl_i8));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i8), SEGMENT_VRAM_START(ovl_i8),
                  SEGMENT_DISK_SIZE(ovl_i8), SEGMENT_BSS_SIZE(ovl_i8));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2), SEGMENT_DATA_START(ovl_i2), SEGMENT_DATA_END(ovl_i2) - SEGMENT_DATA_START(ovl_i2));
    
    func_80703E08(SEGMENT_DISK_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2),
                  SEGMENT_DISK_SIZE(ovl_i2), SEGMENT_BSS_SIZE(ovl_i2));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9), SEGMENT_DATA_START(ovl_i9), SEGMENT_DATA_SIZE(ovl_i9));
    
    func_80703CA4(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9),
                  SEGMENT_DISK_SIZE(ovl_i9), SEGMENT_BSS_SIZE(ovl_i9));

    D_8076CB40 = -1;
    func_i10_8012B904();

    CLEAR_DATA_CACHE(osPhysicalToVirtual(D_8079A414), SEGMENT_DATA_SIZE_CONST(segment_16C8A0));

    func_8070818C(D_807C7118,
               (uintptr_t) osPhysicalToVirtual(D_8079A414) + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               SEGMENT_VRAM_SIZE(segment_16C8A0));

    mio0Decode((uintptr_t) osPhysicalToVirtual(D_8079A414) + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               osPhysicalToVirtual(D_8079A414));

    func_8070818C(D_807C70D8, (uintptr_t) osPhysicalToVirtual(D_8079A41C), SEGMENT_VRAM_SIZE(segment_17B1E0));

    func_8070818C(D_807C70F0, (uintptr_t) osPhysicalToVirtual(D_8079A424), SEGMENT_VRAM_SIZE(segment_17B960));


    if ((D_8079A32C != 0) && gRamDDCompatible) {
        if (osAppNMIBuffer[13] != 0x20DE1529) {
            osAppNMIBuffer[13] = 0x20DE1529;
            func_xk1_8002FFA0();
        }
        func_xk1_8002FFDC();
    }

    // FrameBuffer Indexes
    D_8079A35C = 0;
    D_8079A360 = 1;
    D_8079A368 = 2;
    D_8079A364 = 0;
    D_8079A36C = 1;

    // General Initialisation
    Math_SinTableInit();
    if (gRamDDCompatible) {
        func_80702A68();
    }
    func_80702A94();
    func_806F86C0(&D_80225800.unk_000, 0, 1.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f);

    Math_Rand1Init(osGetTime(), osGetTime() + osGetTime());
    func_i10_8012B520();

    if (gSettingSoundMode == 0) {
        Audio_SetSoundMode(SOUNDMODE_SURROUND);
    } else {
        Audio_SetSoundMode(SOUNDMODE_MONO);
    }

    while (true) {
        if (OS_CYCLES_TO_NSEC(osGetTime() - startTime) * 6e-8 > 230.0) {
            break;
        }
    }

    Math_Rand2Init(osGetTime() + osGetTime(), osGetTime());
    osSetTime(0);
    osViSwapBuffer(gFrameBuffers[0]);
    Gfx_InitBuffer();
    func_806F34E0();

    gMoveWd(gMasterDisp++, 6, 0, 0);
    gDPFullSync(gMasterDisp++);
    gSPEndDisplayList(gMasterDisp++);

    Gfx_SetTask(sGfxTask);
    Game_Init();
    gGameFrameCount = 0;

    while (true) {
        if (D_8076C7A4 != D_8076C7A8) {
            D_8076C7A4 = D_8076C7A8;
            D_8079A364 = D_8079A35C;
            D_8079A368 = D_8079A364 - 1;
            if (D_8079A368 == -1) {
                D_8079A368 = 2;
            }
            D_8079A36C = D_8079A364 + 1;
            if (D_8079A36C == 3) {
                D_8079A36C = 0;
            }
        }

        // Game main loops
        switch (D_8076C7A4) {
            case 2:
                func_806F37F0();
                break;
            case 3:
                func_806F3924();
                break;
        }
        gGameFrameCount++;
    }
}
