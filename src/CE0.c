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

void func_806F37F0(void) {
    osRecvMesg(&D_8079A0F0, &D_8079A370, OS_MESG_BLOCK);
    func_80745CB8();
    Gfx_InitBuffer();
    func_806F5310();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    osRecvMesg(&D_8079A108, &D_8079A370, OS_MESG_BLOCK);

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

    osRecvMesg(&D_8079A0F0, &D_8079A370, OS_MESG_BLOCK);
    Gfx_InitBuffer();
    func_806F5310();
    func_806F34E0();
    Gfx_LoadSegments();
    gMasterDisp = func_806F59E0(gMasterDisp);
    Gfx_FullSync();
    func_80745CB8();
    osRecvMesg(&D_8079A108, &D_8079A370, OS_MESG_BLOCK);
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

u32 gGameFrameCount = 0;
s16 D_8076C7A4 = 2;
s16 D_8076C7A8 = 2;

void Game_ThreadEntry(void* entry) {
    s32 startTime;
    OSMesg msgBuf[1];

    startTime = osGetTime();
    func_8074279C();
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
    gOvl7VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i7));
    gOvl7VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i7));
    gOvl8VramStart = osVirtualToPhysical(SEGMENT_VRAM_START(ovl_i8));
    gOvl8VramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(ovl_i8));
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
    gUnkContextVramStart = osVirtualToPhysical(SEGMENT_VRAM_START(unk_context));
    gUnkContextVramEnd = osVirtualToPhysical(SEGMENT_VRAM_END(unk_context));
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

    D_8079A3D4 = osVirtualToPhysical(D_800D6D90);
    D_8079A3D8 = osVirtualToPhysical(D_8013A7F0);

    D_8079A42C = D_8079A3D8;
    D_8079A430 = D_8079A42C + (size_t) SEGMENT_VRAM_SIZE(D_7000000);

    D_8079A3DC = osVirtualToPhysical(D_8012B520);
    D_8079A3E0 = osVirtualToPhysical(D_801414E0);

    // Setup memory
    Segment_SetAddress(0, 0);
    Segment_SetAddress(2, gUnkBssVramStart);
    Segment_SetAddress(8, gSegment16C8A0VramStart);
    Segment_SetAddress(3, gSegment17B1E0VramStart);
    Segment_SetPhysicalAddress(6, (D_8079A35C * 0x1AF08) + D_80128C90);

    Controller_Init();
    func_807083D8();
    func_80708430();

    while (func_80742790() != 2) {}

    while (func_807424CC() != 0) {}

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i10), SEGMENT_TEXT_SIZE(ovl_i10), SEGMENT_DATA_START(ovl_i10),
                        SEGMENT_DATA_SIZE(ovl_i10));

    func_80703E08(SEGMENT_DISK_START(ovl_i10), SEGMENT_VRAM_START(ovl_i10), SEGMENT_DISK_SIZE(ovl_i10),
                  SEGMENT_BSS_SIZE(ovl_i10));

    D_8076CB40 = D_8076C770;

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_xk1), SEGMENT_TEXT_SIZE(ovl_xk1), SEGMENT_DATA_START(ovl_xk1),
                        SEGMENT_DATA_END(ovl_xk1) - SEGMENT_DATA_START(ovl_xk1));

    func_80703E08(SEGMENT_DISK_START(ovl_xk1), SEGMENT_VRAM_START(ovl_xk1), SEGMENT_DISK_SIZE(ovl_xk1),
                  SEGMENT_BSS_SIZE(ovl_xk1));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i3), SEGMENT_TEXT_SIZE(ovl_i3), SEGMENT_DATA_START(ovl_i3),
                        SEGMENT_DATA_SIZE(ovl_i3));

    func_80703E08(SEGMENT_DISK_START(ovl_i3), SEGMENT_VRAM_START(ovl_i3), SEGMENT_DISK_SIZE(ovl_i3),
                  SEGMENT_BSS_SIZE(ovl_i3));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i4), SEGMENT_TEXT_SIZE(ovl_i4), SEGMENT_DATA_START(ovl_i4),
                        SEGMENT_DATA_SIZE(ovl_i4));

    func_80703E08(SEGMENT_DISK_START(ovl_i4), SEGMENT_VRAM_START(ovl_i4), SEGMENT_DISK_SIZE(ovl_i4),
                  SEGMENT_BSS_SIZE(ovl_i4));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(course_select), SEGMENT_TEXT_SIZE(course_select),
                        SEGMENT_DATA_START(course_select), SEGMENT_DATA_SIZE(course_select));

    func_80703E08(SEGMENT_DISK_START(course_select), SEGMENT_VRAM_START(course_select),
                  SEGMENT_DISK_SIZE(course_select), SEGMENT_BSS_SIZE(course_select));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i6), SEGMENT_TEXT_SIZE(ovl_i6), SEGMENT_DATA_START(ovl_i6),
                        SEGMENT_DATA_SIZE(ovl_i6));

    func_80703E08(SEGMENT_DISK_START(ovl_i6), SEGMENT_VRAM_START(ovl_i6), SEGMENT_DISK_SIZE(ovl_i6),
                  SEGMENT_BSS_SIZE(ovl_i6));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i7), SEGMENT_TEXT_SIZE(ovl_i7), SEGMENT_DATA_START(ovl_i7),
                        SEGMENT_DATA_SIZE(ovl_i7));

    func_80703E08(SEGMENT_DISK_START(ovl_i7), SEGMENT_VRAM_START(ovl_i7), SEGMENT_DISK_SIZE(ovl_i7),
                  SEGMENT_BSS_SIZE(ovl_i7));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i8), SEGMENT_TEXT_SIZE(ovl_i8), SEGMENT_DATA_START(ovl_i8),
                        SEGMENT_DATA_SIZE(ovl_i8));

    func_80703E08(SEGMENT_DISK_START(ovl_i8), SEGMENT_VRAM_START(ovl_i8), SEGMENT_DISK_SIZE(ovl_i8),
                  SEGMENT_BSS_SIZE(ovl_i8));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i2), SEGMENT_TEXT_SIZE(ovl_i2), SEGMENT_DATA_START(ovl_i2),
                        SEGMENT_DATA_END(ovl_i2) - SEGMENT_DATA_START(ovl_i2));

    func_80703E08(SEGMENT_DISK_START(ovl_i2), SEGMENT_VRAM_START(ovl_i2), SEGMENT_DISK_SIZE(ovl_i2),
                  SEGMENT_BSS_SIZE(ovl_i2));

    CLEAR_OVERLAY_CACHE(SEGMENT_TEXT_START(ovl_i9), SEGMENT_TEXT_SIZE(ovl_i9), SEGMENT_DATA_START(ovl_i9),
                        SEGMENT_DATA_SIZE(ovl_i9));

    func_80703CA4(SEGMENT_DISK_START(ovl_i9), SEGMENT_VRAM_START(ovl_i9), SEGMENT_DISK_SIZE(ovl_i9),
                  SEGMENT_BSS_SIZE(ovl_i9));

    D_8076CB40 = -1;
    func_i10_8012B904();

    CLEAR_DATA_CACHE(osPhysicalToVirtual(gSegment16C8A0VramStart), SEGMENT_DATA_SIZE_CONST(segment_16C8A0));

    func_8070818C(D_807C7118,
                  (uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                      (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
                  SEGMENT_VRAM_SIZE(segment_16C8A0));

    mio0Decode((uintptr_t) osPhysicalToVirtual(gSegment16C8A0VramStart) +
                   (size_t) SEGMENT_DATA_SIZE_CONST(segment_16C8A0),
               osPhysicalToVirtual(gSegment16C8A0VramStart));

    func_8070818C(D_807C70D8, (uintptr_t) osPhysicalToVirtual(gSegment17B1E0VramStart),
                  SEGMENT_VRAM_SIZE(segment_17B1E0));

    func_8070818C(D_807C70F0, (uintptr_t) osPhysicalToVirtual(gSegment17B960VramStart),
                  SEGMENT_VRAM_SIZE(segment_17B960));

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
