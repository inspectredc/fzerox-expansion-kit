#include "global.h"
#include "audio.h"
#include "fzx_game.h"
#include "fzx_thread.h"

GfxPool* gGfxPool;
OSTask* sGfxTask;
Gfx* gMasterDisp;
s32 D_8079A35C;
s32 D_8079A360;
s32 D_8079A364;
s32 D_8079A368;
s32 D_8079A36C;
OSMesg D_8079A370;
uintptr_t gMainVramStart;
uintptr_t gMainVramEnd;
uintptr_t gOvl2VramStart;
uintptr_t gOvl2VramEnd;
uintptr_t gOvl3VramStart;
uintptr_t gOvl3VramEnd;
uintptr_t gOvl4VramStart;
uintptr_t gOvl4VramEnd;
uintptr_t gOvlCourseSelectVramStart;
uintptr_t gOvlCourseSelectVramEnd;
uintptr_t gOvl6VramStart;
uintptr_t gOvl6VramEnd;
uintptr_t gOvl7VramStart;
uintptr_t gOvl7VramEnd;
uintptr_t gOvl8VramStart;
uintptr_t gOvl8VramEnd;
uintptr_t gOvl9VramStart;
uintptr_t gOvl9VramEnd;
uintptr_t gOvl10VramStart;
uintptr_t gOvl10VramEnd;
UNUSED uintptr_t D_8079A3C4;
UNUSED uintptr_t D_8079A3C8;
UNUSED uintptr_t D_8079A3CC;
UNUSED uintptr_t D_8079A3D0;
uintptr_t D_8079A3D4;
uintptr_t D_8079A3D8;
uintptr_t D_8079A3DC;
uintptr_t D_8079A3E0;
uintptr_t gFramebuffer1VramStart;
uintptr_t gFramebuffer1VramEnd;
uintptr_t gFramebuffer2VramStart;
uintptr_t gFramebuffer2VramEnd;
uintptr_t gFramebuffer3VramStart;
uintptr_t gFramebuffer3VramEnd;
uintptr_t gFramebufferUnusedVramStart;
uintptr_t gFramebufferUnusedVramEnd;
uintptr_t gGfxPoolVramStart;
uintptr_t gGfxPoolVramEnd;
uintptr_t gUnkBssVramStart;
uintptr_t gUnkBssVramEnd;
uintptr_t gSegment16C8A0VramStart;
uintptr_t gSegment16C8A0VramEnd;
uintptr_t gSegment17B1E0VramStart;
uintptr_t gSegment17B1E0VramEnd;
uintptr_t gSegment17B960VramStart;
uintptr_t gSegment17B960VramEnd;
uintptr_t D_8079A42C;
uintptr_t D_8079A430;
uintptr_t gSegment1B8550VramStart;
uintptr_t gSegment1B8550VramEnd;
uintptr_t gSegment1E23F0VramStart;
uintptr_t gSegment1E23F0VramEnd;
uintptr_t gSegment22B0A0VramStart;
uintptr_t gSegment22B0A0VramEnd;
uintptr_t D_8079A44C;
uintptr_t D_8079A450;
uintptr_t D_8079A454;
uintptr_t D_8079A458;
uintptr_t gCourseEditTexturesVramStart;
uintptr_t gCourseEditTexturesVramEnd;
uintptr_t gCreateMachineTexturesVramStart;
uintptr_t gCreateMachineTexturesVramEnd;
uintptr_t D_8079A46C;
uintptr_t D_8079A470;
uintptr_t gBuffersVramStart;
uintptr_t gBuffersVramEnd;
uintptr_t gUnkGfxVramStart;
uintptr_t gUnkGfxVramEnd;
uintptr_t gUnkContextVramStart;
uintptr_t gUnkContextVramEnd;
uintptr_t gAudioContextVramStart;
uintptr_t gAudioContextVramEnd;

void func_806F34E0(void) {
    s32 temp_t7;

    temp_t7 = D_8079A368;
    D_8079A368 = D_8079A364;
    D_8079A364 = D_8079A36C;
    D_8079A36C = temp_t7;
}

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

extern unk_80128C94* D_80128C90;

void Gfx_LoadSegments(void) {
    Segment_SetPhysicalAddress(6, &D_80128C90[D_8079A35C]);
    gMasterDisp = Segment_SetTableAddresses(gMasterDisp);
}

extern bool gInCourseEditor;

void Gfx_FullSync(void) {

    if (gInCourseEditor) {
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
            task->t.ucode = (u64*) gspF3DEX2_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DEX2_fifoDataStart;
            break;
        case GFXMODE_F3DLX:
            task->t.ucode = (u64*) gspF3DLX2_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DLX2_Rej_fifoDataStart;
            break;
        case GFXMODE_F3DFLX:
            task->t.ucode = (u64*) gspF3DFLX2_Rej_fifoTextStart;
            task->t.ucode_data = (u64*) gspF3DFLX2_Rej_fifoDataStart;
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

void func_806F37F0(void) {
    osRecvMesg(&D_8079A0F0, &D_8079A370, OS_MESG_BLOCK);
    Audio_Update();
    Gfx_InitBuffer();
    func_806F5310();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    osRecvMesg(&D_8079A108, &D_8079A370, OS_MESG_BLOCK);

    while (osDpGetStatus() &
           (DPC_STATUS_DMA_BUSY | DPC_STATUS_CMD_BUSY | DPC_STATUS_PIPE_BUSY | DPC_STATUS_TMEM_BUSY)) {}

    Segment_LoadAssets();
    Transition_SetBackgroundBuffer();
    osViSwapBuffer(gFrameBuffers[D_8079A360]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[D_8079A360]) {}

    Gfx_SetTask(sGfxTask);
}

void func_806F3924(void) {
    s32 retries = 100000;

    osRecvMesg(&D_8079A0F0, &D_8079A370, OS_MESG_BLOCK);
    Gfx_InitBuffer();
    func_806F5310();
    func_806F34E0();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    Audio_Update();
    osRecvMesg(&D_8079A108, &D_8079A370, OS_MESG_BLOCK);
    Transition_SetBackgroundBuffer();
    osViSwapBuffer(gFrameBuffers[D_8079A368]);
    Segment_LoadAssets();

    while ((osViGetCurrentFramebuffer() == gFrameBuffers[D_8079A364] ||
            osViGetNextFramebuffer() == gFrameBuffers[D_8079A364]) &&
           retries != 0) {
        retries--;
    }

    Gfx_SetTask(sGfxTask);
}

extern s32 D_8076CB40;
extern s32 D_8076C770;

extern RomOffset gRomSegmentPairs[][2];
extern bool gRamDDCompatible;
extern s32 gLeoDriveConnectionState;

extern unk_80225800 D_80225800;
extern s16 gSettingSoundMode;

u32 gGameFrameCount = 0;
s16 D_8076C7A4 = 2;
s16 D_8076C7A8 = 2;

void Game_ThreadEntry(void* entry) {
    s32 startTime;
    OSMesg msgBuf[1];

    startTime = osGetTime();
    Audio_GuitarSeqStart();
    osRecvMesg(&D_8079A0F0, msgBuf, OS_MESG_BLOCK);

    // Segment Start and End Pairs
    gMainVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(main));
    gMainVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(main));
    gOvl2VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i2));
    gOvl2VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i2));
    gOvl3VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i3));
    gOvl3VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i3));
    gOvl4VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i4));
    gOvl4VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i4));
    gOvlCourseSelectVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(course_select));
    gOvlCourseSelectVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(course_select));
    gOvl6VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i6));
    gOvl6VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i6));
    gOvl7VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ending));
    gOvl7VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ending));
    gOvl8VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(records));
    gOvl8VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(records));
    gOvl9VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i9));
    gOvl9VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i9));
    gOvl10VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i10));
    gOvl10VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i10));
    gFramebuffer1VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer1));
    gFramebuffer1VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer1));
    gFramebuffer2VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer2));
    gFramebuffer2VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer2));
    gFramebuffer3VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer3));
    gFramebuffer3VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer3));
    gFramebufferUnusedVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(framebuffer_unused));
    gFramebufferUnusedVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(framebuffer_unused));
    gBuffersVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(buffers));
    gBuffersVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(buffers));
    gUnkGfxVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_gfx_segment));
    gUnkGfxVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_gfx_segment));
    gUnkContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(game_context));
    gUnkContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(game_context));
    gAudioContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(audio_context));
    gAudioContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(audio_context) + 0x10);
    gGfxPoolVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(gfxpool));
    gGfxPoolVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(gfxpool));
    gUnkBssVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_bss_segment));
    gUnkBssVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_bss_segment));

    gSegment16C8A0VramStart = gBuffersVramEnd;
    gSegment16C8A0VramEnd = gSegment16C8A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0);

    gSegment17B1E0VramStart = gSegment16C8A0VramEnd;
    gSegment17B1E0VramEnd = gSegment17B1E0VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_17B1E0);

    gSegment17B960VramStart = gSegment17B1E0VramEnd;
    gSegment17B960VramEnd = gSegment17B960VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_17B960);

    gSegment1B8550VramStart = gSegment17B960VramEnd;
    gSegment1B8550VramEnd = gSegment1B8550VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_1B8550);

    gSegment1E23F0VramStart = gOvl3VramEnd;
    gSegment1E23F0VramEnd = gSegment1E23F0VramStart + (size_t) SEGMENT_VRAM_SIZE(segment_1E23F0);

    gSegment22B0A0VramStart = gSegment17B960VramEnd;
    gSegment22B0A0VramEnd = gSegment22B0A0VramStart + (size_t) SEGMENT_DATA_SIZE_CONST(segment_22B0A0);

    D_8079A46C = gSegment17B1E0VramEnd;
    D_8079A470 = D_8079A46C + 0x35E10;

    gCourseEditTexturesVramStart = D_8079A470;
    gCourseEditTexturesVramEnd = gCourseEditTexturesVramStart + (size_t) SEGMENT_VRAM_SIZE(course_edit_textures);

    gCreateMachineTexturesVramStart = D_8079A470;
    gCreateMachineTexturesVramEnd =
        gCreateMachineTexturesVramStart + (size_t) SEGMENT_VRAM_SIZE(create_machine_textures);

    D_8079A3D4 = osVirtualToPhysical(SEGMENT_VRAM_START(course_edit));
    D_8079A3D8 = osVirtualToPhysical(SEGMENT_VRAM_END(course_edit));

    D_8079A42C = D_8079A3D8;
    D_8079A430 = D_8079A42C + (size_t) SEGMENT_VRAM_SIZE(expansion_kit_textures);

    D_8079A3DC = osVirtualToPhysical(SEGMENT_VRAM_START(machine_create));
    D_8079A3E0 = osVirtualToPhysical(SEGMENT_VRAM_END(machine_create));

    // Setup memory
    Segment_SetAddress(0, 0);
    Segment_SetAddress(2, gUnkBssVramStart);
    Segment_SetAddress(8, gSegment16C8A0VramStart);
    Segment_SetAddress(3, gSegment17B1E0VramStart);
    Segment_SetPhysicalAddress(6, &D_80128C90[D_8079A35C]);

    Controller_Init();
    Arena_DefaultStartInit();
    Arena_EndInit();

    while (func_80742790() != 2) {}

    while (func_807424CC() != 0) {}

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10), SEGMENT_DATA_START(ovl_i10),
                        SEGMENT_DATA_SIZE(ovl_i10));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10),
                                     SEGMENT_DISK_SIZE(ovl_i10), SEGMENT_BSS_SIZE(ovl_i10));

    D_8076CB40 = D_8076C770;

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(expansion_kit), SEGMENT_TEXT_SIZE(expansion_kit),
                        SEGMENT_DATA_START(expansion_kit),
                        SEGMENT_DATA_END(expansion_kit) - SEGMENT_DATA_START(expansion_kit));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(expansion_kit), SEGMENT_VRAM_START(expansion_kit),
                                     SEGMENT_DISK_SIZE(expansion_kit), SEGMENT_BSS_SIZE(expansion_kit));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i3), SEGMENT_TEXT_SIZE(ovl_i3), SEGMENT_DATA_START(ovl_i3),
                        SEGMENT_DATA_SIZE(ovl_i3));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ovl_i3), SEGMENT_VRAM_START(ovl_i3), SEGMENT_DISK_SIZE(ovl_i3),
                                     SEGMENT_BSS_SIZE(ovl_i3));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i4), SEGMENT_TEXT_SIZE(ovl_i4), SEGMENT_DATA_START(ovl_i4),
                        SEGMENT_DATA_SIZE(ovl_i4));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ovl_i4), SEGMENT_VRAM_START(ovl_i4), SEGMENT_DISK_SIZE(ovl_i4),
                                     SEGMENT_BSS_SIZE(ovl_i4));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(course_select), SEGMENT_TEXT_SIZE(course_select),
                        SEGMENT_DATA_START(course_select), SEGMENT_DATA_SIZE(course_select));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(course_select), SEGMENT_VRAM_START(course_select),
                                     SEGMENT_DISK_SIZE(course_select), SEGMENT_BSS_SIZE(course_select));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i6), SEGMENT_TEXT_SIZE(ovl_i6), SEGMENT_DATA_START(ovl_i6),
                        SEGMENT_DATA_SIZE(ovl_i6));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ovl_i6), SEGMENT_VRAM_START(ovl_i6), SEGMENT_DISK_SIZE(ovl_i6),
                                     SEGMENT_BSS_SIZE(ovl_i6));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ending), SEGMENT_TEXT_SIZE(ending), SEGMENT_DATA_START(ending),
                        SEGMENT_DATA_SIZE(ending));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ending), SEGMENT_VRAM_START(ending), SEGMENT_DISK_SIZE(ending),
                                     SEGMENT_BSS_SIZE(ending));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(records), SEGMENT_TEXT_SIZE(records), SEGMENT_DATA_START(records),
                        SEGMENT_DATA_SIZE(records));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(records), SEGMENT_VRAM_START(records),
                                     SEGMENT_DISK_SIZE(records), SEGMENT_BSS_SIZE(records));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2), SEGMENT_DATA_START(ovl_i2),
                        SEGMENT_DATA_END(ovl_i2) - SEGMENT_DATA_START(ovl_i2));

    DiskDrive_LoadOverlayProgressBar(SEGMENT_DISK_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2), SEGMENT_DISK_SIZE(ovl_i2),
                                     SEGMENT_BSS_SIZE(ovl_i2));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9), SEGMENT_DATA_START(ovl_i9),
                        SEGMENT_DATA_SIZE(ovl_i9));

    DiskDrive_LoadOverlay(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9), SEGMENT_DISK_SIZE(ovl_i9),
                          SEGMENT_BSS_SIZE(ovl_i9));

    D_8076CB40 = -1;
    func_i10_8012B904();

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment16C8A0VramStart), SEGMENT_DATA_SIZE_CONST(segment_16C8A0));

    Dma_LoadAssets(gRomSegmentPairs[15][0],
                   (uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                       (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
                   SEGMENT_VRAM_SIZE(segment_16C8A0));

    mio0Decode((uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                   (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               osPhysicalToVirtual(gSegment16C8A0VramStart));

    Dma_LoadAssets(gRomSegmentPairs[7][0], (uintptr_t) osPhysicalToVirtual(gSegment17B1E0VramStart),
                   SEGMENT_VRAM_SIZE(segment_17B1E0));

    Dma_LoadAssets(gRomSegmentPairs[10][0], (uintptr_t) osPhysicalToVirtual(gSegment17B960VramStart),
                   SEGMENT_VRAM_SIZE(segment_17B960));

    if ((gLeoDriveConnectionState != 0) && gRamDDCompatible) {
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
    Matrix_SetTransRot(&D_80225800.unk_000, 0, 1.0f, 0, 0, 0, 0.0f, 0.0f, 0.0f);

    Math_Rand1Init(osGetTime(), osGetTime() + osGetTime());
    func_i10_8012B520();

    if (gSettingSoundMode == 0) {
        Audio_SetOutMode(SOUNDMODE_SURROUND);
    } else {
        Audio_SetOutMode(SOUNDMODE_MONO);
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
