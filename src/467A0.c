#include "global.h"
#include "audio.h"
#include "audiothread_cmd.h"
#include "audio_funcs.h"

AudioTask* AudioThread_CreateTaskImpl(void);

AudioTask* AudioThread_CreateTask(void) {
    return AudioThread_CreateTaskImpl();
}

extern AudioCustomUpdateFunction gAudioCustomUpdateFunction;
extern s32 D_80771968;
extern s32 D_8077196C;
extern s32 D_80771970;
extern s32 D_80771974;

#ifdef IMPORT_DATA
AudioTask* AudioThread_CreateTaskImpl(void) {
    static s32 sMaxAbiCmdCount = 128;
    static AudioTask* sWaitingAudioTask = NULL;
    u32 samplesRemainingInAi;
    s32 abiCmdCount;
    s32 pad;
    s32 j;
    s32 sp5C;
    s16* curAiBuffer;
    OSTask* task;
    s32 index;
    u32 sp4C;
    s32 sp48;
    s32 i;

    gAudioCtx.totalTaskCount++;
    if (gAudioCtx.totalTaskCount % (gAudioCtx.audioBufferParameters.specUnk4) != 0) {
        if (gAudioCustomUpdateFunction != NULL) {
            gAudioCustomUpdateFunction();
        }

        if ((gAudioCtx.totalTaskCount % gAudioCtx.audioBufferParameters.specUnk4) + 1 ==
            gAudioCtx.audioBufferParameters.specUnk4) {
            return sWaitingAudioTask;
        } else {
            return NULL;
        }
    }

    osSendMesg(gAudioCtx.taskStartQueueP, (OSMesg)gAudioCtx.totalTaskCount, OS_MESG_NOBLOCK);
    gAudioCtx.rspTaskIndex ^= 1;
    gAudioCtx.curAiBufIndex++;
    gAudioCtx.curAiBufIndex %= 3;
    index = (gAudioCtx.curAiBufIndex - 2 + 3) % 3;
    samplesRemainingInAi = osAiGetLength() / 4;

    if (gAudioCtx.resetTimer < 16) {
        if (gAudioCtx.aiBufLengths[index] != 0) {
            func_8073A8A0(gAudioCtx.aiBuffers[index], gAudioCtx.aiBufLengths[index] * 4);
            if (gAudioCtx.aiBuffers[index]) {}
            if (gAudioCtx.aiBufLengths[index]) {}
        }
    }

    if (gAudioCustomUpdateFunction != NULL) {
        gAudioCustomUpdateFunction();
    }

    sp5C = gAudioCtx.curAudioFrameDmaCount;
    for (i = 0; i < gAudioCtx.curAudioFrameDmaCount; i++) {
        if (osRecvMesg(&gAudioCtx.curAudioFrameDmaQueue, NULL, OS_MESG_NOBLOCK) == 0) {
            sp5C--;
        }
    }

    if (sp5C != 0) {
        for (i = 0; i < sp5C; i++) {
            osRecvMesg(&gAudioCtx.curAudioFrameDmaQueue, NULL, OS_MESG_BLOCK);
        }
    }

    sp48 = MQ_GET_COUNT(&gAudioCtx.curAudioFrameDmaQueue);
    if (sp48 != 0) {
        for (i = 0; i < sp48; i++) {
            osRecvMesg(&gAudioCtx.curAudioFrameDmaQueue, NULL, OS_MESG_NOBLOCK);
        }
    }

    gAudioCtx.curAudioFrameDmaCount = 0;
    
    D_80771968 = 0;
    D_8077196C = 0;
    D_80771970 = 0;
    D_80771974 = 0;
    
    AudioLoad_DecreaseSampleDmaTtls();
    AudioLoad_ProcessLoads(gAudioCtx.resetStatus);
    AudioLoad_ProcessScriptLoads();

    if (gAudioCtx.resetStatus != 0) {
        if (AudioHeap_ResetStep() == 0) {
            if (gAudioCtx.resetStatus == 0) {
                osSendMesg(gAudioCtx.audioResetQueueP, (OSMesg)(u32)gAudioCtx.specId, OS_MESG_NOBLOCK);
            }

            sWaitingAudioTask = NULL;
            return NULL;
        }
    }

    if (gAudioCtx.resetTimer > 16) {
        return NULL;
    }
    if (gAudioCtx.resetTimer != 0) {
        gAudioCtx.resetTimer++;
    }
    gAudioCtx.curTask = &gAudioCtx.rspTask[gAudioCtx.rspTaskIndex];
    gAudioCtx.curAbiCmdBuf = gAudioCtx.abiCmdBufs[gAudioCtx.rspTaskIndex];

    index = gAudioCtx.curAiBufIndex;
    curAiBuffer = gAudioCtx.aiBuffers[index];

    gAudioCtx.aiBufLengths[index] =
        (s16)((((gAudioCtx.audioBufferParameters.samplesPerFrameTarget - samplesRemainingInAi) +
                EXTRA_BUFFERED_AI_SAMPLES_TARGET) &
               ~0xF) +
              SAMPLES_TO_OVERPRODUCE);
    if (gAudioCtx.aiBufLengths[index] < gAudioCtx.audioBufferParameters.minAiBufferLength) {
        gAudioCtx.aiBufLengths[index] = gAudioCtx.audioBufferParameters.minAiBufferLength;
    }

    if (gAudioCtx.aiBufLengths[index] > gAudioCtx.audioBufferParameters.maxAiBufferLength) {
        gAudioCtx.aiBufLengths[index] = gAudioCtx.audioBufferParameters.maxAiBufferLength;
    }

    j = 0;
    if (gAudioCtx.resetStatus == 0) {
        while (osRecvMesg(gAudioCtx.threadCmdProcQueueP, &sp4C, OS_MESG_NOBLOCK) != -1) {
            AudioThread_ProcessCmds(sp4C);
            if (1) {}
            j++;
        }
        if ((j == 0) && (gAudioCtx.threadCmdQueueFinished)) {
            AudioThread_ScheduleProcessCmds();
        }
    }

    gAudioCtx.curAbiCmdBuf = func_8072E8A4(gAudioCtx.curAbiCmdBuf, &abiCmdCount, curAiBuffer, gAudioCtx.aiBufLengths[index]);
    gAudioCtx.audioRandom = (gAudioCtx.audioRandom + gAudioCtx.totalTaskCount) * osGetCount();
    gAudioCtx.audioRandom = gAudioCtx.audioRandom + gAudioCtx.aiBuffers[index][gAudioCtx.totalTaskCount & 0xFF];

    index = gAudioCtx.rspTaskIndex;

    gAudioCtx.curTask->msgQueue = NULL;
    gAudioCtx.curTask->unk_44 = NULL;

    task = &gAudioCtx.curTask->task;
    
    task->t.type = M_AUDTASK;
    task->t.flags = 0;
    task->t.ucode_boot = (u64*) aspMainTextStart;
    task->t.ucode_boot_size = SP_UCODE_SIZE;

    task->t.ucode_data_size = (size_t) (aspMainDataEnd - aspMainDataStart) * sizeof(u64) - 1;
    task->t.ucode = (u64*) aspMainTextStart;
    task->t.ucode_data = (u64*) aspMainDataStart;
    task->t.ucode_size = SP_UCODE_SIZE;

    task->t.dram_stack = NULL;
    task->t.dram_stack_size = 0;

    task->t.output_buff = NULL;
    task->t.output_buff_size = NULL;
    if (1) {}
    task->t.data_ptr = (u64*) gAudioCtx.abiCmdBufs[index];
    task->t.data_size = abiCmdCount * sizeof(Acmd);

    task->t.yield_data_ptr = NULL;
    task->t.yield_data_size = 0;

    if (sMaxAbiCmdCount < abiCmdCount) {
        sMaxAbiCmdCount = abiCmdCount;
    }

    if (gAudioCtx.audioBufferParameters.specUnk4 == 1) {
        return gAudioCtx.curTask;
    } else {
        sWaitingAudioTask = gAudioCtx.curTask;
        return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_CreateTaskImpl.s")
#endif

void AudioThread_SetFadeOutTimer(s32 seqPlayId, s32 fadeTime);
void AudioThread_SetFadeInTimer(s32 seqPlayId, s32 fadeTime);

void AudioThread_ProcessGlobalCmd(AudioCmd* cmd) {
    s32 i;
    s32 pad[3];
    u32 flags;

    switch (cmd->op) {
        case AUDIOCMD_OP_GLOBAL_SYNC_LOAD_SEQ_PARTS:
            AudioLoad_SyncLoadSeqParts(cmd->arg1, cmd->arg2);
            break;

        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER:
            AudioLoad_SyncInitSeqPlayer(cmd->arg0, cmd->arg1, cmd->arg2);
            AudioThread_SetFadeInTimer(cmd->arg0, cmd->asInt);
            break;

        case AUDIOCMD_OP_GLOBAL_INIT_SEQPLAYER_SKIP_TICKS:
            AudioLoad_SyncInitSeqPlayerSkipTicks(cmd->arg0, cmd->arg1, cmd->asInt);
            break;

        case AUDIOCMD_OP_GLOBAL_DISABLE_SEQPLAYER:
            if (gAudioCtx.seqPlayers[cmd->arg0].enabled) {
                if (cmd->asInt == 0) {
                    AudioSeq_SequencePlayerDisable(&gAudioCtx.seqPlayers[cmd->arg0]);
                } else {
                    AudioThread_SetFadeOutTimer(cmd->arg0, cmd->asInt);
                }
            }
            break;

        case AUDIOCMD_OP_GLOBAL_SET_SOUND_MODE:
            gAudioCtx.soundMode = cmd->asUInt;
            break;

        case AUDIOCMD_OP_GLOBAL_MUTE:
            for (i = 0; i < gAudioCtx.audioBufferParameters.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[i];

                seqPlayer->muted = true;
                seqPlayer->recalculateVolume = true;
            }
            break;

        case AUDIOCMD_OP_GLOBAL_UNMUTE:
            if (cmd->asUInt == 1) {
                for (i = 0; i < gAudioCtx.numNotes; i++) {
                    Note* note = &gAudioCtx.notes[i];
                    NoteSubEu* subEu = &note->noteSubEu;

                    if (subEu->bitField0.enabled && (note->playbackState.unk_04 == 0) &&
                        (note->playbackState.parentLayer->channel->muteBehavior & MUTE_BEHAVIOR_3)) {
                        subEu->bitField0.finished = true;
                    }
                }
            }

            for (i = 0; i < gAudioCtx.audioBufferParameters.numSequencePlayers; i++) {
                SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[i];

                seqPlayer->muted = false;
                seqPlayer->recalculateVolume = true;
            }
            break;

        case AUDIOCMD_OP_GLOBAL_SYNC_LOAD_INSTRUMENT:
            AudioLoad_SyncLoadInstrument(cmd->arg0, cmd->arg1, cmd->arg2);
            break;

        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_SAMPLE_BANK:
            AudioLoad_AsyncLoadSampleBank(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioCtx.externalLoadQueue);
            break;

        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_FONT:
            AudioLoad_AsyncLoadFont(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioCtx.externalLoadQueue);
            break;

        case AUDIOCMD_OP_GLOBAL_ASYNC_LOAD_SEQ:
            AudioLoad_AsyncLoadSeq(cmd->arg0, cmd->arg1, cmd->arg2, &gAudioCtx.externalLoadQueue);
            break;

        case AUDIOCMD_OP_GLOBAL_DISCARD_SEQ_FONTS:
            AudioLoad_DiscardSeqFonts(cmd->arg1);
            break;

        case AUDIOCMD_OP_GLOBAL_SET_CHANNEL_MASK:
            gAudioCtx.threadCmdChannelMask[cmd->arg0] = cmd->asUShort;
            break;

        case AUDIOCMD_OP_GLOBAL_RESET_AUDIO_HEAP:
            gAudioCtx.resetStatus = 5;
            gAudioCtx.specId = cmd->asUInt;
            func_80738944();
            break;

        case AUDIOCMD_OP_GLOBAL_SET_CUSTOM_UPDATE_FUNCTION:
            gAudioCustomUpdateFunction = (AudioCustomUpdateFunction)cmd->asUInt;
            break;

        case AUDIOCMD_OP_GLOBAL_SET_DRUM_FONT:
        case AUDIOCMD_OP_GLOBAL_SET_SFX_FONT:
        case AUDIOCMD_OP_GLOBAL_SET_INSTRUMENT_FONT:
            if (Audio_SetFontInstrument(cmd->op - AUDIOCMD_OP_GLOBAL_SET_DRUM_FONT, cmd->arg0, cmd->arg1, cmd->data)) {}
            break;

        case AUDIOCMD_OP_GLOBAL_DISABLE_ALL_SEQPLAYERS:
            flags = cmd->asUInt;
            if (flags == 1) {
                for (i = 0; i < gAudioCtx.audioBufferParameters.numSequencePlayers; i++) {
                    SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[i];

                    if (seqPlayer->enabled) {
                        AudioSeq_SequencePlayerDisable(seqPlayer);
                    }
                }
            }
            func_8073A678(flags);
            break;

        case AUDIOCMD_OP_GLOBAL_POP_PERSISTENT_CACHE:
            AudioHeap_PopPersistentCache(cmd->asInt);
            break;

        default:
            break;
    }
}

void AudioThread_SetFadeOutTimer(s32 seqPlayerIndex, s32 fadeTimer) {
    SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[seqPlayerIndex];

    if (fadeTimer == 0) {
        fadeTimer = 1;
    }

    seqPlayer->fadeVelocity = -(seqPlayer->fadeVolume / fadeTimer);
    seqPlayer->state = 2;
    seqPlayer->fadeTimer = fadeTimer;
}

void AudioThread_SetFadeInTimer(s32 seqPlayerIndex, s32 fadeTimer) {
    SequencePlayer* seqPlayer;

    if (fadeTimer != 0) {
        seqPlayer = &gAudioCtx.seqPlayers[seqPlayerIndex];
        seqPlayer->state = 1;
        seqPlayer->fadeTimerUnkEu = fadeTimer;
        seqPlayer->fadeTimer = fadeTimer;
        seqPlayer->fadeVolume = 0.0f;
        seqPlayer->fadeVelocity = 0.0f;
    }
}

void AudioThread_InitMesgQueuesImpl(void) {
    gAudioCtx.threadCmdWritePos = 0;
    gAudioCtx.threadCmdReadPos = 0;
    gAudioCtx.threadCmdQueueFinished = false;

    gAudioCtx.taskStartQueueP = &gAudioCtx.taskStartQueue;
    gAudioCtx.threadCmdProcQueueP = &gAudioCtx.threadCmdProcQueue;
    gAudioCtx.audioResetQueueP = &gAudioCtx.audioResetQueue;

    osCreateMesgQueue(gAudioCtx.taskStartQueueP, gAudioCtx.taskStartMsgBuf, ARRAY_COUNT(gAudioCtx.taskStartMsgBuf));
    osCreateMesgQueue(gAudioCtx.threadCmdProcQueueP, gAudioCtx.threadCmdProcMsgBuf,
                      ARRAY_COUNT(gAudioCtx.threadCmdProcMsgBuf));
    osCreateMesgQueue(gAudioCtx.audioResetQueueP, gAudioCtx.audioResetMsgBuf, ARRAY_COUNT(gAudioCtx.audioResetMsgBuf));
}

void AudioThread_QueueCmd(u32 opArgs, void** data) {
    AudioCmd* cmd = &gAudioCtx.threadCmdBuf[gAudioCtx.threadCmdWritePos & 0xFF];

    cmd->opArgs = opArgs;
    cmd->data = *data;

    gAudioCtx.threadCmdWritePos++;

    if (gAudioCtx.threadCmdWritePos == gAudioCtx.threadCmdReadPos) {
        gAudioCtx.threadCmdWritePos--;
    }
}

void AudioThread_QueueCmdF32(s32 opArgs, f32 data) {
    AudioThread_QueueCmd(opArgs, (void**)&data);
}

void AudioThread_QueueCmdS32(s32 opArgs, s32 data) {
    AudioThread_QueueCmd(opArgs, (void**)&data);
}

void AudioThread_QueueCmdS8(s32 opArgs, s8 data) {
    u32 uData = data << 0x18;

    AudioThread_QueueCmd(opArgs, (void**)&uData);
}

void AudioThread_QueueCmdU16(s32 opArgs, u16 data) {
    u32 uData = data << 0x10;

    AudioThread_QueueCmd(opArgs, (void**)&uData);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_ScheduleProcessCmds.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739BBC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/func_80739BD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/467A0/AudioThread_ProcessCmds.s")

extern OSMesgQueue D_806EE200;

u32 AudioThread_GetAsyncLoadStatus(u32* outData) {
    u32 loadStatus;

    if (osRecvMesg(&D_806EE200, (OSMesg*)&loadStatus, OS_MESG_NOBLOCK) == -1) {
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
