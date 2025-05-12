#include "global.h"
#include "audio.h"
#include "fzx_thread.h"

extern OSMesgQueue gAudioTaskMesgQueue;
extern OSMesgQueue gMainThreadMesgQueue;
extern OSTask* gCurAudioOSTask;
extern RomOffset D_807C70A0[];

OSMesg sAudioTaskMsg;

void Audio_ThreadEntry(void* arg0) {
    static AudioTask* sCurAudioTask = NULL;
    Audio_Init(D_807C70A0[4], D_807C70A0[0], D_807C70A0[2]);

    while (true) {
        osRecvMesg(&gAudioTaskMesgQueue, &sAudioTaskMsg, OS_MESG_NOBLOCK);
        osRecvMesg(&gAudioTaskMesgQueue, &sAudioTaskMsg, OS_MESG_BLOCK);

        if (sCurAudioTask != NULL) {
            gCurAudioOSTask = &sCurAudioTask->task;
            osSendMesg(&gMainThreadMesgQueue, (OSMesg) EVENT_MESG_AUDIO_TASK_SET, OS_MESG_BLOCK);
        }
        sCurAudioTask = Audio_SetupCreateTask();
    }
}
