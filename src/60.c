#include "global.h"
#include "fzx_thread.h"
#include "PR/viint.h"
#include "PR/leo.h"

extern char sBootThreadStack[0x200];
extern char sIdleThreadStack[0x200];
extern char sMainThreadStack[0x400];
extern char sGameThreadStack[0x1000];
extern char sAudioThreadStack[0x800];
extern char sResetThreadStack[0x1200];
extern OSThread sIdleThread;
extern OSThread sMainThread;
extern OSThread sAudioThread;
extern OSThread sGameThread;
extern OSThread sResetThread;
extern OSMesgQueue sPiMgrCmdQueue;
extern OSMesgQueue gResetMesgQueue;
extern OSMesg sPiMgrCmdBuf[64];
extern OSMesg sResetMsgBuf[1];
extern OSTask* gCurGfxTask;
extern OSTask* gCurAudioOSTask;
extern FrameBuffer* gFrameBuffers[3];
extern OSPiHandle* gCartRomHandle;

void Idle_ThreadEntry(void*);
void Reset_ThreadEntry(void*);

void bootproc(void) {
    u64* ptr;
    u32 i;
    
    osInitialize();
    osCreateMesgQueue(&gResetMesgQueue, sResetMsgBuf, ARRAY_COUNT(sResetMsgBuf));
    osSetEventMesg(OS_EVENT_PRENMI, &gResetMesgQueue, (void*) 0x1B);

    ptr = (u64*)sIdleThreadStack;

    for (i = 0; i < sizeof(sIdleThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*)sMainThreadStack;

    for (i = 0; i < sizeof(sMainThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*)sGameThreadStack;

    for (i = 0; i < sizeof(sGameThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*)sResetThreadStack;

    for (i = 0; i < sizeof(sResetThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }

    ptr = (u64*)sAudioThreadStack;

    for (i = 0; i < sizeof(sAudioThreadStack) / sizeof(u64); i++) {
        ptr[i] = 0x8877665544332211;
    }
    
    osCreateThread(&sIdleThread, THREAD_ID_IDLE, Idle_ThreadEntry, NULL, sIdleThreadStack + sizeof(sIdleThreadStack),
                   100);
    osStartThread(&sIdleThread);
}

extern s32 sSpTaskState;
extern bool sSpTaskActive;

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

extern bool sGfxTaskYielded;
extern bool sGfxTaskQueued;
extern s32 D_8076C770;
extern s32 D_8076C774;
extern s32 D_8076C778;
extern s32 D_8076C77C;
extern bool gRamDDCompatible;
extern bool sAudioThreadCreated;
extern s8 sMainThreadStartEnabled;
extern s8 sGameThreadStartEnabled;
extern s8 sAudioThreadStartEnabled;

extern s32 D_8076C780;
extern s32 D_8079A32C;
extern s32 D_8079A340;

extern OSMesgQueue gDmaMesgQueue;
extern OSMesgQueue gSerialEventQueue;
extern OSMesgQueue gAudioTaskMesgQueue;
extern OSMesgQueue gMainThreadMesgQueue;
extern OSMesg sDmaMsgBuf[1];
extern OSMesg sSerialEventBuf[1];
extern OSMesg sAudioTaskMsgBuf[1];
extern OSMesg sMainThreadMsgBuf[16];
extern LEODiskID leoBootID;
extern bool gResetStarted;
extern bool gLeoDDConnected;

extern OSMesgQueue D_8079A0F0;
extern OSMesgQueue D_8079A108;
extern OSMesgQueue D_8079A150;
extern OSMesg D_8079A274[1];
extern OSMesg D_8079A278[1];
extern OSMesg D_8079A2C4[1];
extern OSMesgQueue D_8079A2E8;
extern OSMesg D_8079A300[1];
extern OSThread D_80799EE0;
void func_80767958(void*);
extern char D_80797670[0x1000];
void func_80703F90(void);
s32 func_80768C08(s32 arg0, s32 arg1, s32 arg2);
s32 func_80768AF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

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
            D_8076C780 = 1;
            break;
        case OS_TV_MPAL:
            D_8076C780 = 1;
            break;
    }


    if (D_8076C780 != 0) {
        D_8079A32C = func_8075AA60();
        D_8079A340 = func_8075A020();
        if (D_8079A32C != 0) {
            func_8070F240();
        }
        func_80704DB0("01", &leoBootID);

        for (i = 0; i < 3; i++) {
            var_v0 = &gFrameBuffers[i]->data[19199 * 4];
    
            while (var_v0 >= (u64*)gFrameBuffers[i]->data) {
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

    if (D_8076C780 != 0) {
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
    if (gRamDDCompatible && gLeoDDConnected) {
        LeoReset();
    }
    func_806F5A50();

    while (true) {}
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/60/func_806F33D0.s")
