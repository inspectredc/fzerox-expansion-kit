#include "global.h"
#include "fzx_thread.h"
#include "PR/viint.h"
#include "PR/leo.h"

char sBootThreadStack[0x200];
char sIdleThreadStack[0x200];
char sMainThreadStack[0x400];
char sGameThreadStack[0x1000];
char sAudioThreadStack[0x800];
char D_80797670[0x1000];
char sResetThreadStack[0x200];
UNUSED char sUnusedThreadStack[0xE00];
OSThread sIdleThread;
OSThread sMainThread;
OSThread sAudioThread;
OSThread sGameThread;
OSThread sResetThread;
OSThread D_80799EE0;
OSMesgQueue sPiMgrCmdQueue;
OSMesgQueue gDmaMesgQueue;
OSMesgQueue gSerialEventQueue;
OSMesgQueue gAudioTaskMesgQueue;
OSMesgQueue D_8079A0F0;
OSMesgQueue D_8079A108;
OSMesgQueue gMainThreadMesgQueue;
OSMesgQueue gResetMesgQueue;
OSMesgQueue D_8079A150;
OSMesg sPiMgrCmdBuf[64];
OSMesg sDmaMsgBuf[1];
OSMesg sSerialEventBuf[1];
OSMesg sAudioTaskMsgBuf[1];
OSMesg D_8079A274[1];
OSMesg D_8079A278[1];
OSMesg sMainThreadMsgBuf[16];
OSMesg sResetMsgBuf[1];
OSMesg D_8079A2C4[1];
UNUSED s8 D_8079A2C8[0x20];
OSMesgQueue D_8079A2E8;
OSMesg D_8079A300[1];
OSIoMesg D_8079A308;
OSTask* gCurGfxTask;
OSTask* gCurAudioOSTask;
bool gResetStarted;
s32 D_8079A32C;
FrameBuffer* gFrameBuffers[3];
OSPiHandle* gCartRomHandle;
s32 D_8079A340;

void Idle_ThreadEntry(void*);
void Reset_ThreadEntry(void*);

void bootproc(void) {
    u64* ptr;
    u32 i;

    osInitialize();
    osCreateMesgQueue(&gResetMesgQueue, sResetMsgBuf, ARRAY_COUNT(sResetMsgBuf));
    osSetEventMesg(OS_EVENT_PRENMI, &gResetMesgQueue, (void*) 0x1B);

    ptr = (u64*) sIdleThreadStack;

    for (i = 0; i < sizeof(sIdleThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*) sMainThreadStack;

    for (i = 0; i < sizeof(sMainThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*) sGameThreadStack;

    for (i = 0; i < sizeof(sGameThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*) D_80797670;

    for (i = 0; i < sizeof(D_80797670) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*) sAudioThreadStack;

    for (i = 0; i < sizeof(sAudioThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    osCreateThread(&sIdleThread, THREAD_ID_IDLE, Idle_ThreadEntry, NULL, sIdleThreadStack + sizeof(sIdleThreadStack),
                   100);
    osStartThread(&sIdleThread);
}

s32 sSpTaskState = SP_TASK_INACTIVE;
bool sSpTaskActive = false;

void Sched_SpTaskYield(void) {
    osSpTaskYield();
    sSpTaskState = SP_TASK_YIELDING;
    sSpTaskActive = true;
}

void Sched_SpTaskStartAudio(void) {
    osSpTaskStart(gCurAudioOSTask);
    sSpTaskState = SP_TASK_AUDIO;
    sSpTaskActive = true;
}

void Sched_SpTaskClearStartGfx(void) {
    osDpSetStatus(DPC_CLR_TMEM_CTR | DPC_CLR_PIPE_CTR | DPC_CLR_CMD_CTR | DPC_CLR_CLOCK_CTR);
    osSpTaskStart(gCurGfxTask);
    sSpTaskState = SP_TASK_GFX;
    sSpTaskActive = true;
}

void Sched_SpTaskResumeGfx(void) {
    osSpTaskStart(gCurGfxTask);
    sSpTaskState = SP_TASK_GFX;
    sSpTaskActive = true;
}

bool sGfxTaskYielded = false;
bool sGfxTaskQueued = false;
s32 D_8076C770 = 1;
s32 D_8076C774 = 0;
s32 D_8076C778 = 1;
s32 D_8076C77C = 1;
bool gRamDDCompatible = false;
bool sAudioThreadCreated = false;
s8 sMainThreadStartEnabled = true;
s8 sGameThreadStartEnabled = true;
s8 sAudioThreadStartEnabled = true;
UNUSED s8 D_8076C794 = 1;

extern LEODiskID leoBootID;

void func_806F33D0(FrameBuffer* arg0);

void Main_ThreadEntry(void* arg0) {
    OSMesg msg;
    s32 var_a0;
    u64* var_v0;
    s32 i;

    // Init message queues
    osCreateMesgQueue(&gDmaMesgQueue, sDmaMsgBuf, ARRAY_COUNT(sDmaMsgBuf));
    osCreateMesgQueue(&gAudioTaskMesgQueue, sAudioTaskMsgBuf, ARRAY_COUNT(sAudioTaskMsgBuf));
    osCreateMesgQueue(&D_8079A0F0, D_8079A274, ARRAY_COUNT(D_8079A274));
    osCreateMesgQueue(&D_8079A108, D_8079A278, ARRAY_COUNT(D_8079A278));
    osCreateMesgQueue(&gMainThreadMesgQueue, sMainThreadMsgBuf, ARRAY_COUNT(sMainThreadMsgBuf));
    osCreateMesgQueue(&gSerialEventQueue, sSerialEventBuf, ARRAY_COUNT(sSerialEventBuf));
    osCreateMesgQueue(&D_8079A150, D_8079A2C4, ARRAY_COUNT(D_8079A2C4));
    osCreateMesgQueue(&D_8079A2E8, D_8079A300, ARRAY_COUNT(D_8079A300));
    osSetEventMesg(OS_EVENT_SI, &gSerialEventQueue, (OSMesg) EVENT_MESG_SI);
    osSetEventMesg(OS_EVENT_SP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_SP);
    osSetEventMesg(OS_EVENT_DP, &gMainThreadMesgQueue, (OSMesg) EVENT_MESG_DP);
    osViSetEvent(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_VI, 1);
    gResetStarted = false;

    func_80703F90();

    switch (osResetType) {
        case OS_TV_PAL:
        case OS_TV_NTSC:
            gRamDDCompatible = true;
            break;
        case OS_TV_MPAL:
            gRamDDCompatible = true;
            break;
    }

    if (gRamDDCompatible) {
        D_8079A32C = LeoDriveExist();
        D_8079A340 = osDriveRomInit();
        if (D_8079A32C != 0) {
            func_8070F240();
        }
        func_80704DB0("01", leoBootID.gameName);

        for (i = 0; i < 3; i++) {
            var_v0 = &gFrameBuffers[i]->buffer[19199];

            while (var_v0 >= gFrameBuffers[i]->buffer) {
                *var_v0-- = 0x0001000100010001;
            }
        }

        osViSwapBuffer(gFrameBuffers[0]);

        while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

        osViBlack(false);

        func_8070F0F0();
    }

    osCreateThread(&sResetThread, THREAD_ID_RESET, Reset_ThreadEntry, NULL,
                   sResetThreadStack + sizeof(sResetThreadStack), 100);
    osStartThread(&sResetThread);
    osViSwapBuffer(gFrameBuffers[1]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[1]) {}

    func_806F33D0(gFrameBuffers[0]);
    func_806F33D0(gFrameBuffers[1]);
    func_806F33D0(gFrameBuffers[2]);

    osViSwapBuffer(gFrameBuffers[0]);

    while (osViGetCurrentFramebuffer() != gFrameBuffers[0]) {}

    osViBlack(false);

    if (gRamDDCompatible) {
        osCreateThread(&D_80799EE0, THREAD_ID_6, &func_80767958, 0, D_80797670 + sizeof(D_80797670), 0x1E);
        if (D_8079A32C == 1) {
            osStartThread(&D_80799EE0);
            D_8079A32C = 2;
        }
    }

    func_80704F38(&sGameThread);

    func_8073631C(&func_80768C08);
    func_80736328(&func_80768AF0);

    osCreateThread(&sAudioThread, THREAD_ID_AUDIO, Audio_ThreadEntry, NULL,
                   sAudioThreadStack + sizeof(sAudioThreadStack), 20);
    if (sAudioThreadStartEnabled) {
        osStartThread(&sAudioThread);
    }
    sAudioThreadCreated = true;
    osCreateThread(&sGameThread, THREAD_ID_GAME, Game_ThreadEntry, NULL, sGameThreadStack + sizeof(sGameThreadStack),
                   10);
    if (sGameThreadStartEnabled) {
        osStartThread(&sGameThread);
    }

    while (true) {
        osRecvMesg(&gMainThreadMesgQueue, &msg, OS_MESG_BLOCK);
        if (msg == (OSMesg) EVENT_MESG_SP) {
            switch (sSpTaskState) {
                case SP_TASK_YIELDING:
                    if (osSpTaskYielded(gCurGfxTask)) {
                        sGfxTaskYielded = true;
                    }
                    Sched_SpTaskStartAudio();
                    break;
                case SP_TASK_AUDIO:
                    if (sGfxTaskYielded) {
                        sGfxTaskYielded = false;
                        Sched_SpTaskResumeGfx();
                    } else if (sGfxTaskQueued) {
                        sGfxTaskQueued = false;
                        Sched_SpTaskClearStartGfx();
                    } else {
                        sSpTaskState = SP_TASK_INACTIVE;
                        sSpTaskActive = false;
                    }
                    break;
                case SP_TASK_GFX:
                    sSpTaskState = SP_TASK_INACTIVE;
                    sSpTaskActive = false;
                    break;
            }
        } else if (msg == (OSMesg) EVENT_MESG_VI) {
            osSendMesg(&gAudioTaskMesgQueue, (OSMesg) EVENT_MESG_NEXT_AUDIO_TASK, OS_MESG_NOBLOCK);
            osSendMesg(&D_8079A2E8, (OSMesg) 1, OS_MESG_NOBLOCK);
            if ((++D_8076C770 - D_8076C774) >= D_8076C778) {
                D_8076C774 = D_8076C770;
                D_8076C778 = D_8076C77C;
                osSendMesg(&D_8079A0F0, (OSMesg) 0x29, OS_MESG_NOBLOCK);
            }
        } else if (msg == (OSMesg) EVENT_MESG_AUDIO_TASK_SET) {
            osWritebackDCacheAll();
            if (sSpTaskActive) {
                if (sSpTaskState != SP_TASK_YIELDING) {
                    Sched_SpTaskYield();
                }
            } else {
                Sched_SpTaskStartAudio();
            }
        } else if ((msg == (OSMesg) EVENT_MESG_GFX_TASK_SET) && !gResetStarted) {
            osWritebackDCacheAll();
            if (sSpTaskActive) {
                sGfxTaskQueued = true;
            } else {
                Sched_SpTaskClearStartGfx();
            }
        } else if (msg == (OSMesg) EVENT_MESG_DP) {
            osSendMesg(&D_8079A108, (OSMesg) 0x2A, OS_MESG_NOBLOCK);
        }
    }
}

extern FrameBuffer gFrameBuffer1;
extern FrameBuffer gFrameBuffer2;
extern FrameBuffer gFrameBuffer3;

void Idle_ThreadEntry(void* arg0) {
    gFrameBuffers[0] = &gFrameBuffer1;
    gFrameBuffers[1] = &gFrameBuffer2;
    gFrameBuffers[2] = &gFrameBuffer3;
    osCreateViManager(OS_PRIORITY_VIMGR);
    if (osTvType == OS_TV_TYPE_NTSC) {
        osViSetMode(&osViModeNtscLan1);
    } else {
        osViSetMode(&osViModeMpalLan1);
    }
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    osViSetSpecialFeatures(OS_VI_GAMMA_DITHER_OFF);
    osViSetSpecialFeatures(OS_VI_DIVOT_OFF);
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_OFF);
    osViBlack(true);
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrCmdQueue, sPiMgrCmdBuf, ARRAY_COUNT(sPiMgrCmdBuf));
    gCartRomHandle = osCartRomInit();

    Fault_Init();
    Fault_SetFrameBuffer(&gFrameBuffer1, SCREEN_WIDTH, 16);
    osCreateThread(&sMainThread, THREAD_ID_MAIN, Main_ThreadEntry, NULL, sMainThreadStack + sizeof(sMainThreadStack),
                   99);
    if (sMainThreadStartEnabled) {
        osStartThread(&sMainThread);
    }
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

    while (true) {}
}

void LeoReset(void);

void Reset_ThreadEntry(void* arg0) {
    OSMesg resetMsg;

    MQ_WAIT_FOR_MESG(&gResetMesgQueue, &resetMsg);
    if (!gResetStarted && sAudioThreadCreated) {
        Audio_PreNMI();
    }
    gResetStarted = true;
    osViBlack(true);
    osViSetYScale(1.0f);
    if (gRamDDCompatible && D_8079A32C) {
        LeoReset();
    }
    func_806F5A50();

    while (true) {}
}

extern u64 D_80769DF0[];

void func_806F33D0(FrameBuffer* arg0) {
    u64* var_s0 = &arg0->buffer[19199];
    u64* var;
    s32 i;
    s32 j;

    // Very FAKE Throughout
    while (var_s0 >= arg0->buffer) {
        *(--var_s0 + 1) = 0x1000100010001;
    }
    osWritebackDCache(arg0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(u16));

    var_s0 = &arg0->buffer[8023];

    for (i = 0; i < 39; i++) {
        for (j = 0; j < 34; j++) {
            var = &D_80769DF0[i * 34 + j];
            var_s0[j] = *var;
        }
        var_s0 += 80;
    }
}
