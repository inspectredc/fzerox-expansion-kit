#include "global.h"
#include "audio.h"
#include "audio_funcs.h"

void AudioLoad_DecreaseSampleDmaTtls(void) {
    u32 i;

    for (i = 0; i < gAudioCtx.sampleDmaListSize1; i++) {
        SampleDma* dma = &gAudioCtx.sampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gAudioCtx.sampleDmaReuseQueue1WrPos;
                gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1WrPos] = i;
                gAudioCtx.sampleDmaReuseQueue1WrPos++;
            }
        }
    }

    for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
        SampleDma* dma = &gAudioCtx.sampleDmas[i];

        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->reuseIndex = gAudioCtx.sampleDmaReuseQueue2WrPos;
                gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2WrPos] = i;
                gAudioCtx.sampleDmaReuseQueue2WrPos++;
            }
        }
    }

    gAudioCtx.unused1DF8 = 0;
}

void* AudioLoad_DmaSampleData(uintptr_t devAddr, size_t size, s32 arg2, u8* dmaIndexRef, s32 medium) {
    s32 pad1;
    SampleDma* dma;
    s32 hasDma = false;
    u32 dmaDevAddr;
    u32 pad2;
    u32 dmaIndex;
    u32 transfer;
    s32 bufferPos;
    u32 i;

    if (arg2 != 0 || *dmaIndexRef >= gAudioCtx.sampleDmaListSize1) {
        for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
            dma = &gAudioCtx.sampleDmas[i];
            bufferPos = devAddr - dma->devAddr;
            if (0 <= bufferPos && bufferPos <= dma->size - size) {
                // We already have a DMA request for this memory range.
                if (dma->ttl == 0 && gAudioCtx.sampleDmaReuseQueue2RdPos != gAudioCtx.sampleDmaReuseQueue2WrPos) {
                    // Move the DMA out of the reuse queue, by swapping it with the
                    // read pos, and then incrementing the read pos.
                    if (dma->reuseIndex != gAudioCtx.sampleDmaReuseQueue2RdPos) {
                        gAudioCtx.sampleDmaReuseQueue2[dma->reuseIndex] =
                            gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos];
                        gAudioCtx.sampleDmas[gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos]]
                            .reuseIndex = dma->reuseIndex;
                    }
                    gAudioCtx.sampleDmaReuseQueue2RdPos++;
                }
                dma->ttl = 32;
                *dmaIndexRef = i;
                return &dma->ramAddr[devAddr - dma->devAddr];
            }
        }

        if (arg2 == 0) {
            goto search_short_lived;
        }

        if (gAudioCtx.sampleDmaReuseQueue2RdPos != gAudioCtx.sampleDmaReuseQueue2WrPos && arg2 != 0) {
            // Allocate a DMA from reuse queue 2, unless full.
            dmaIndex = gAudioCtx.sampleDmaReuseQueue2[gAudioCtx.sampleDmaReuseQueue2RdPos];
            gAudioCtx.sampleDmaReuseQueue2RdPos++;
            dma = gAudioCtx.sampleDmas + dmaIndex;
            hasDma = true;
        }
    } else {
    search_short_lived:
        dma = gAudioCtx.sampleDmas + *dmaIndexRef;
        i = 0;
    again:
        bufferPos = devAddr - dma->devAddr;
        if (0 <= bufferPos && bufferPos <= dma->size - size) {
            // We already have DMA for this memory range.
            if (dma->ttl == 0) {
                // Move the DMA out of the reuse queue, by swapping it with the
                // read pos, and then incrementing the read pos.
                if (dma->reuseIndex != gAudioCtx.sampleDmaReuseQueue1RdPos) {
                    gAudioCtx.sampleDmaReuseQueue1[dma->reuseIndex] =
                        gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos];
                    gAudioCtx.sampleDmas[gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos]]
                        .reuseIndex = dma->reuseIndex;
                }
                gAudioCtx.sampleDmaReuseQueue1RdPos++;
            }
            dma->ttl = 2;
            return dma->ramAddr + (devAddr - dma->devAddr);
        }
        dma = gAudioCtx.sampleDmas + i++;
        if (i <= gAudioCtx.sampleDmaListSize1) {
            goto again;
        }
    }

    if (!hasDma) {
        if (gAudioCtx.sampleDmaReuseQueue1RdPos == gAudioCtx.sampleDmaReuseQueue1WrPos) {
            return NULL;
        }
        // Allocate a DMA from reuse queue 1.
        dmaIndex = gAudioCtx.sampleDmaReuseQueue1[gAudioCtx.sampleDmaReuseQueue1RdPos++];
        dma = gAudioCtx.sampleDmas + dmaIndex;
        hasDma = true;
    }

    transfer = dma->size;
    dmaDevAddr = devAddr & ~0xF;
    dma->ttl = 3;
    dma->devAddr = dmaDevAddr;
    dma->sizeUnused = transfer;
    AudioLoad_Dma(&gAudioCtx.curAudioFrameDmaIoMsgBuf[gAudioCtx.curAudioFrameDmaCount++], OS_MESG_PRI_NORMAL, OS_READ,
                  dmaDevAddr, dma->ramAddr, transfer, &gAudioCtx.curAudioFrameDmaQueue, medium, "SUPERDMA");
    *dmaIndexRef = dmaIndex;
    return (devAddr - dmaDevAddr) + dma->ramAddr;
}

void AudioLoad_InitSampleDmaBuffers(s32 numNotes) {
    SampleDma* dma;
    s32 i;
    s32 temp_lo;
    s32 j;

    gAudioCtx.sampleDmaBufSize = gAudioCtx.sampleDmaBufSize1;
    gAudioCtx.sampleDmas = AudioHeap_Alloc(&gAudioCtx.miscPool, 4 * gAudioCtx.numNotes * sizeof(SampleDma) *
                                                                    gAudioCtx.audioBufferParameters.specUnk4);
    temp_lo = 3 * gAudioCtx.numNotes * gAudioCtx.audioBufferParameters.specUnk4;
    for (i = 0; i < temp_lo; i++) {
        dma = &gAudioCtx.sampleDmas[gAudioCtx.sampleDmaCount];
        dma->ramAddr = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, gAudioCtx.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            AudioHeap_WritebackDCache(dma->ramAddr, gAudioCtx.sampleDmaBufSize);
            dma->size = gAudioCtx.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioCtx.sampleDmaCount++;
        }
    }

    for (i = 0; i < gAudioCtx.sampleDmaCount; i++) {
        gAudioCtx.sampleDmaReuseQueue1[i] = i;
        gAudioCtx.sampleDmas[i].reuseIndex = i;
    }

    for (i = gAudioCtx.sampleDmaCount; i < 0x100; i++) {
        gAudioCtx.sampleDmaReuseQueue1[i] = 0;
    }

    gAudioCtx.sampleDmaReuseQueue1RdPos = 0;
    gAudioCtx.sampleDmaReuseQueue1WrPos = gAudioCtx.sampleDmaCount;
    gAudioCtx.sampleDmaListSize1 = gAudioCtx.sampleDmaCount;
    gAudioCtx.sampleDmaBufSize = gAudioCtx.sampleDmaBufSize2;

    for (j = 0; j < gAudioCtx.numNotes; j++) {
        dma = &gAudioCtx.sampleDmas[gAudioCtx.sampleDmaCount];
        dma->ramAddr = AudioHeap_AllocAttemptExternal(&gAudioCtx.miscPool, gAudioCtx.sampleDmaBufSize);
        if (dma->ramAddr == NULL) {
            break;
        } else {
            AudioHeap_WritebackDCache(dma->ramAddr, gAudioCtx.sampleDmaBufSize);
            dma->size = gAudioCtx.sampleDmaBufSize;
            dma->devAddr = 0;
            dma->sizeUnused = 0;
            dma->unused = 0;
            dma->ttl = 0;
            gAudioCtx.sampleDmaCount++;
        }
    }

    for (i = gAudioCtx.sampleDmaListSize1; i < gAudioCtx.sampleDmaCount; i++) {
        gAudioCtx.sampleDmaReuseQueue2[i - gAudioCtx.sampleDmaListSize1] = i;
        gAudioCtx.sampleDmas[i].reuseIndex = i - gAudioCtx.sampleDmaListSize1;
    }

    for (i = gAudioCtx.sampleDmaCount; i < 0x100; i++) {
        gAudioCtx.sampleDmaReuseQueue2[i] = gAudioCtx.sampleDmaListSize1;
    }

    gAudioCtx.sampleDmaReuseQueue2RdPos = 0;
    gAudioCtx.sampleDmaReuseQueue2WrPos = gAudioCtx.sampleDmaCount - gAudioCtx.sampleDmaListSize1;
}

bool AudioLoad_IsFontLoadComplete(s32 fontId) {
    if (fontId == 0xFF) {
        return true;
    } else if (gAudioCtx.fontLoadStatus[fontId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.fontLoadStatus[AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId)] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool AudioLoad_IsSeqLoadComplete(s32 seqId) {
    if (seqId == 0xFF) {
        return true;
    } else if (gAudioCtx.seqLoadStatus[seqId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.seqLoadStatus[AudioLoad_GetLoadTableIndex(SEQUENCE_TABLE, seqId)] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

bool AudioLoad_IsSampleLoadComplete(s32 sampleBankId) {
    if (sampleBankId == 0xFF) {
        return true;
    } else if (gAudioCtx.sampleFontLoadStatus[sampleBankId] >= LOAD_STATUS_COMPLETE) {
        return true;
    } else if (gAudioCtx.sampleFontLoadStatus[AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankId)] >=
               LOAD_STATUS_COMPLETE) {
        return true;
    } else {
        return false;
    }
}

void AudioLoad_SetFontLoadStatus(s32 fontId, s32 loadStatus) {
    if ((fontId != 0xFF) && (gAudioCtx.fontLoadStatus[fontId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.fontLoadStatus[fontId] = loadStatus;
    }
}

void AudioLoad_SetSeqLoadStatus(s32 seqId, s32 loadStatus) {
    if ((seqId != 0xFF) && (gAudioCtx.seqLoadStatus[seqId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.seqLoadStatus[seqId] = loadStatus;
    }
}

void AudioLoad_SetSampleFontLoadStatusAndApplyCaches(s32 sampleBankId, s32 loadStatus) {
    if (sampleBankId != 0xFF) {
        if (gAudioCtx.sampleFontLoadStatus[sampleBankId] != LOAD_STATUS_PERMANENTLY_LOADED) {
            gAudioCtx.sampleFontLoadStatus[sampleBankId] = loadStatus;
        }

        if ((gAudioCtx.sampleFontLoadStatus[sampleBankId] == LOAD_STATUS_PERMANENTLY_LOADED) ||
            (gAudioCtx.sampleFontLoadStatus[sampleBankId] == LOAD_STATUS_COMPLETE)) {
            AudioHeap_ApplySampleBankCache(sampleBankId);
        }
    }
}

void AudioLoad_SetSampleFontLoadStatus(s32 sampleBankId, s32 loadStatus) {
    if ((sampleBankId != 0xFF) && (gAudioCtx.sampleFontLoadStatus[sampleBankId] != LOAD_STATUS_PERMANENTLY_LOADED)) {
        gAudioCtx.sampleFontLoadStatus[sampleBankId] = loadStatus;
    }
}

void AudioLoad_InitTable(AudioTable* table, u32 romAddr, u16 unkMediumParam) {
    s32 i;

    table->header.unkMediumParam = unkMediumParam;
    table->header.romAddr = romAddr;

    for (i = 0; i < table->header.numEntries; i++) {
        if ((table->entries[i].size != 0) && (table->entries[i].medium == MEDIUM_CART)) {
            table->entries[i].romAddr += romAddr;
        }
    }
}

void* AudioLoad_SyncLoadSeqFonts(s32 seqId, u32* outDefaultFontId) {
    s32 pad[2];
    s32 index;
    void* fontData;
    s32 numFonts;
    s32 fontId;
    s32 i;

    fontId = 0xFF;
    index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        fontId = gAudioCtx.sequenceFontTable[index++];
        fontData = AudioLoad_SyncLoadFont(fontId);
        numFonts--;
    }

    *outDefaultFontId = fontId;
    return fontData;
}

void AudioLoad_SyncLoadSeqParts(s32 seqId, s32 flags) {
    s32 pad;
    u32 defaultFontId;

    if (flags & 2) {
        AudioLoad_SyncLoadSeqFonts(seqId, &defaultFontId);
    }
    if (flags & 1) {
        AudioLoad_SyncLoadSeq(seqId);
    }
}

s32 AudioLoad_SyncLoadSample(Sample* sample, s32 fontId) {
    u8* sampleAddr;

    if ((sample->isRelocated == 1) && (sample->medium != 0)) {
        sampleAddr = AudioHeap_AllocSampleCache(sample->size, fontId, sample->sampleAddr, sample->medium, 1);
        if (sampleAddr == NULL) {
            return -1;
        }
        if (sample->medium == MEDIUM_UNK) {
            AudioLoad_SyncDmaUnkMedium(sample->sampleAddr, sampleAddr, sample->size,
                                       gAudioCtx.sampleBankTable->header.unkMediumParam);
        } else {
            AudioLoad_SyncDma(sample->sampleAddr, sampleAddr, sample->size, sample->medium);
        }
        sample->medium = MEDIUM_RAM;
        sample->sampleAddr = sampleAddr;
    }
    //! @bug Missing return.
}

s32 AudioLoad_SyncLoadInstrument(s32 fontId, s32 instId, s32 drumId) {
    Instrument* instrument;
    Drum* drum;

    if (instId < 0x7F) {
        instrument = Audio_GetInstrument(fontId, instId);
        if (instrument == NULL) {
            return -1;
        }
        if (instrument->normalRangeLo != 0) {
            AudioLoad_SyncLoadSample(instrument->lowPitchTunedSample.sample, fontId);
        }
        AudioLoad_SyncLoadSample(instrument->normalPitchTunedSample.sample, fontId);
        if (instrument->normalRangeHi != 0x7F) {
            AudioLoad_SyncLoadSample(instrument->highPitchTunedSample.sample, fontId);
        }
    } else if (instId == 0x7F) {
        drum = Audio_GetDrum(fontId, drumId);
        if (drum == NULL) {
            return -1;
        }
        AudioLoad_SyncLoadSample(drum->tunedSample.sample, fontId);
        return 0;
    }
    //! @bug Missing return.
}

void AudioLoad_AsyncLoad(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    if (AudioLoad_AsyncLoadInner(tableType, id, nChunks, retData, retQueue) == NULL) {
        osSendMesg(retQueue, (OSMesg) -1, OS_MESG_NOBLOCK);
    }
}

void AudioLoad_AsyncLoadSeq(s32 seqId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(SEQUENCE_TABLE, seqId, 0, retData, retQueue);
}

void AudioLoad_AsyncLoadSampleBank(s32 sampleBankId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(SAMPLE_TABLE, sampleBankId, 0, retData, retQueue);
}

void AudioLoad_AsyncLoadFont(s32 fontId, s32 arg1, s32 retData, OSMesgQueue* retQueue) {
    AudioLoad_AsyncLoad(FONT_TABLE, fontId, 0, retData, retQueue);
}

u8* AudioLoad_GetFontsForSequence(s32 seqId, u32* outNumFonts) {
    s32 index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];

    *outNumFonts = gAudioCtx.sequenceFontTable[index++];
    if (*outNumFonts == 0) {
        return NULL;
    }
    return &gAudioCtx.sequenceFontTable[index];
}

void AudioLoad_DiscardSeqFonts(s32 seqId) {
    s32 fontId;
    s32 index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    s32 numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        numFonts--;
        fontId = AudioLoad_GetLoadTableIndex(FONT_TABLE, gAudioCtx.sequenceFontTable[index++]);
        if (AudioHeap_SearchPermanentCache(FONT_TABLE, fontId) == NULL) {
            AudioLoad_DiscardFont(fontId);
            AudioLoad_SetFontLoadStatus(fontId, LOAD_STATUS_NOT_LOADED);
        }
    }
}

void AudioLoad_DiscardFont(s32 fontId) {
    AudioCache* cache = &gAudioCtx.fontCache;
    AudioTemporaryCache* tcache;
    AudioPersistentCache* pcache;
    s32 i;

    tcache = &cache->temporary;
    if (tcache->entries[0].id == fontId) {
        tcache->entries[0].id = -1;
    } else if (tcache->entries[1].id == fontId) {
        tcache->entries[1].id = -1;
    }
    pcache = &cache->persistent;
    for (i = 0; i < pcache->numEntries; i++) {
        if (pcache->entries[i].id == fontId) {
            pcache->entries[i].id = -1;
        }
    }
    AudioHeap_DiscardFont(fontId);
}

s32 AudioLoad_SyncInitSeqPlayer(s32 playerIdx, s32 seqId, s32 arg2) {
    if (gAudioCtx.resetTimer != 0) {
        return 0;
    }

    gAudioCtx.seqPlayers[playerIdx].skipTicks = 0;
    AudioLoad_SyncInitSeqPlayerInternal(playerIdx, seqId, arg2);
    //! @bug Missing return.
}

s32 AudioLoad_SyncInitSeqPlayerSkipTicks(s32 playerIdx, s32 seqId, s32 skipTicks) {
    if (gAudioCtx.resetTimer != 0) {
        return 0;
    }

    gAudioCtx.seqPlayers[playerIdx].skipTicks = skipTicks;
    AudioLoad_SyncInitSeqPlayerInternal(playerIdx, seqId, 0);
    //! @bug Missing return.
}

s32 AudioLoad_SyncInitSeqPlayerInternal(s32 playerIdx, s32 seqId, s32 arg2) {
    SequencePlayer* seqPlayer = &gAudioCtx.seqPlayers[playerIdx];
    u8* seqData;
    s32 index;
    s32 numFonts;
    s32 fontId;

    AudioSeq_SequencePlayerDisable(seqPlayer);

    fontId = 0xFF;
    index = ((u16*) gAudioCtx.sequenceFontTable)[seqId];
    numFonts = gAudioCtx.sequenceFontTable[index++];

    while (numFonts > 0) {
        fontId = gAudioCtx.sequenceFontTable[index++];
        AudioLoad_SyncLoadFont(fontId);
        numFonts--;
    }

    seqData = AudioLoad_SyncLoadSeq(seqId);
    if (seqData == NULL) {
        return 0;
    }

    AudioSeq_ResetSequencePlayer(seqPlayer);
    seqPlayer->seqId = seqId;
    seqPlayer->defaultFont = AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId);
    seqPlayer->seqData = seqData;
    seqPlayer->enabled = true;
    seqPlayer->scriptState.pc = seqData;
    seqPlayer->scriptState.depth = 0;
    seqPlayer->delay = 0;
    seqPlayer->finished = false;
    seqPlayer->playerIdx = playerIdx;
    AudioSeq_SkipForwardSequence(seqPlayer);
    //! @bug Missing return.
}

void* AudioLoad_SyncLoadSeq(s32 seqId) {
    s32 pad;
    s32 didAllocate;

    if (gAudioCtx.seqLoadStatus[AudioLoad_GetLoadTableIndex(SEQUENCE_TABLE, seqId)] == LOAD_STATUS_IN_PROGRESS) {
        return NULL;
    }

    return AudioLoad_SyncLoad(SEQUENCE_TABLE, seqId, &didAllocate);
}

void* AudioLoad_GetSampleBank(u32 sampleBankId, u32* outMedium) {
    return AudioLoad_TrySyncLoadSampleBank(sampleBankId, outMedium, true);
}

void* AudioLoad_TrySyncLoadSampleBank(u32 sampleBankId, u32* outMedium, bool noLoad) {
    void* ramAddr;
    AudioTable* sampleBankTable;
    u32 realTableId = AudioLoad_GetLoadTableIndex(SAMPLE_TABLE, sampleBankId);
    s8 cachePolicy;

    sampleBankTable = AudioLoad_GetLoadTable(SAMPLE_TABLE);
    ramAddr = AudioLoad_SearchCaches(SAMPLE_TABLE, realTableId);
    if (ramAddr != NULL) {
        if (gAudioCtx.sampleFontLoadStatus[realTableId] != LOAD_STATUS_IN_PROGRESS) {
            AudioLoad_SetSampleFontLoadStatus(realTableId, LOAD_STATUS_COMPLETE);
        }
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }

    cachePolicy = sampleBankTable->entries[sampleBankId].cachePolicy;
    if (cachePolicy == 4 || noLoad == true) {
        *outMedium = sampleBankTable->entries[sampleBankId].medium;
        return sampleBankTable->entries[realTableId].romAddr;
    }

    ramAddr = AudioLoad_SyncLoad(SAMPLE_TABLE, sampleBankId, &noLoad);
    if (ramAddr != NULL) {
        *outMedium = MEDIUM_RAM;
        return ramAddr;
    }

    *outMedium = sampleBankTable->entries[sampleBankId].medium;
    return sampleBankTable->entries[realTableId].romAddr;
}

void* AudioLoad_SyncLoadFont(s32 fontId) {
    void* fontData;
    s32 sampleBankId1;
    s32 sampleBankId2;
    s32 didAllocate;
    SampleBankRelocInfo sampleBankReloc;
    s32 realFontId = AudioLoad_GetLoadTableIndex(FONT_TABLE, fontId);

    if (gAudioCtx.fontLoadStatus[realFontId] == LOAD_STATUS_IN_PROGRESS) {
        return NULL;
    }
    sampleBankId1 = gAudioCtx.soundFontList[realFontId].sampleBankId1;
    sampleBankId2 = gAudioCtx.soundFontList[realFontId].sampleBankId2;

    sampleBankReloc.sampleBankId1 = sampleBankId1;
    sampleBankReloc.sampleBankId2 = sampleBankId2;
    if (sampleBankId1 != 0xFF) {
        sampleBankReloc.baseAddr1 = AudioLoad_TrySyncLoadSampleBank(sampleBankId1, &sampleBankReloc.medium1, false);
    } else {
        sampleBankReloc.baseAddr1 = 0;
    }

    if (sampleBankId2 != 0xFF) {
        sampleBankReloc.baseAddr2 = AudioLoad_TrySyncLoadSampleBank(sampleBankId2, &sampleBankReloc.medium2, false);
    } else {
        sampleBankReloc.baseAddr2 = 0;
    }

    fontData = AudioLoad_SyncLoad(FONT_TABLE, fontId, &didAllocate);
    if (fontData == NULL) {
        return NULL;
    }
    if (didAllocate == true) {
        AudioLoad_RelocateFontAndPreloadSamples(realFontId, fontData, &sampleBankReloc, false);
    }

    return fontData;
}

void* AudioLoad_SyncLoad(u32 tableType, u32 id, s32* didAllocate) {
    size_t size;
    AudioTable* table;
    s32 pad;
    u32 medium;
    s32 loadStatus;
    uintptr_t romAddr;
    s32 cachePolicy;
    void* ramAddr;
    u32 realId;

    realId = AudioLoad_GetLoadTableIndex(tableType, id);
    ramAddr = AudioLoad_SearchCaches(tableType, realId);
    if (ramAddr != NULL) {
        *didAllocate = false;
        loadStatus = LOAD_STATUS_COMPLETE;
    } else {
        table = AudioLoad_GetLoadTable(tableType);
        size = table->entries[realId].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        romAddr = table->entries[realId].romAddr;
        switch (cachePolicy) {
            case 0:
                ramAddr = AudioHeap_AllocPermanent(tableType, realId, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 1:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_PERSISTENT, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 2:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_TEMPORARY, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 3:
            case 4:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_EITHER, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }

        *didAllocate = true;
        if (medium == MEDIUM_UNK) {
            AudioLoad_SyncDmaUnkMedium(romAddr, ramAddr, size, (s16) table->header.unkMediumParam);
        } else {
            AudioLoad_SyncDma(romAddr, ramAddr, size, medium);
        }

        loadStatus = (cachePolicy == 0) ? LOAD_STATUS_PERMANENTLY_LOADED : LOAD_STATUS_COMPLETE;
    }

    switch (tableType) {
        case SEQUENCE_TABLE:
            AudioLoad_SetSeqLoadStatus(realId, loadStatus);
            break;

        case FONT_TABLE:
            AudioLoad_SetFontLoadStatus(realId, loadStatus);
            break;

        case SAMPLE_TABLE:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(realId, loadStatus);
            break;

        default:
            break;
    }

    return ramAddr;
}

s32 AudioLoad_GetLoadTableIndex(s32 tableType, u32 entryId) {
    AudioTable* table = AudioLoad_GetLoadTable(tableType);

    if (table->entries[entryId].size == 0) {
        entryId = table->entries[entryId].romAddr;
    }
    return entryId;
}

void* AudioLoad_SearchCaches(s32 tableType, u32 id) {
    void* ramAddr;

    ramAddr = AudioHeap_SearchPermanentCache(tableType, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    ramAddr = AudioHeap_SearchCaches(tableType, CACHE_EITHER, id);
    if (ramAddr != NULL) {
        return ramAddr;
    }
    return NULL;
}

AudioTable* AudioLoad_GetLoadTable(s32 tableType) {
    AudioTable* table;

    switch (tableType) {
        case SEQUENCE_TABLE:
            table = gAudioCtx.sequenceTable;
            break;
        case FONT_TABLE:
            table = gAudioCtx.soundFontTable;
            break;
        case SAMPLE_TABLE:
            table = gAudioCtx.sampleBankTable;
            break;
        default:
            table = NULL;
            break;
    }
    return table;
}

void AudioLoad_RelocateFont(s32 fontId, uintptr_t fontBaseAddr, SampleBankRelocInfo* relocData) {
    uintptr_t* fontDataPtrs = fontBaseAddr;
    Drum*** drumDataPtrs = fontBaseAddr;
    Drum* drum;
    Instrument* instrument;
    SoundEffect* soundEffect;
    uintptr_t offset;
    s32 numDrums = gAudioCtx.soundFontList[fontId].numDrums;
    s32 numInstruments = gAudioCtx.soundFontList[fontId].numInstruments;
    s32 numSfx = gAudioCtx.soundFontList[fontId].numSfx;
    s32 i;

    if ((fontDataPtrs[0] != 0) && (numDrums != 0)) {
        fontDataPtrs[0] += fontBaseAddr;

        for (i = 0; i < numDrums; i++) {
            offset = (*drumDataPtrs)[i];
            if (offset == 0) {
                continue;
            }
            drum = offset += fontBaseAddr;
            (*drumDataPtrs)[i] = drum;
            if (drum->isRelocated) {
                continue;
            }
            AudioLoad_RelocateSample(&drum->tunedSample, fontBaseAddr, relocData);
            offset = (uintptr_t) drum->envelope;
            drum->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
            drum->isRelocated = true;
        }
    }

    if ((fontDataPtrs[1] != 0) && (numSfx != 0)) {

        fontDataPtrs[1] += fontBaseAddr;

        for (i = 0; i < numSfx; i++) {
            offset = (uintptr_t) (((SoundEffect*) fontDataPtrs[1]) + i);
            soundEffect = (SoundEffect*) offset;

            if ((soundEffect == NULL) || (soundEffect->tunedSample.sample == 0)) {
                continue;
            }

            AudioLoad_RelocateSample(&soundEffect->tunedSample, fontBaseAddr, relocData);
        }
    }

    if (numInstruments > 126) {
        numInstruments = 126;
    }

    for (i = 2; i <= numInstruments + 2 - 1; i++) {
        if (fontDataPtrs[i] != 0) {

            fontDataPtrs[i] += fontBaseAddr;

            instrument = fontDataPtrs[i];
            if (instrument->isRelocated == 0) {
                if (instrument->normalRangeLo != 0) {
                    AudioLoad_RelocateSample(&instrument->lowPitchTunedSample, fontBaseAddr, relocData);
                }
                AudioLoad_RelocateSample(&instrument->normalPitchTunedSample, fontBaseAddr, relocData);
                if (instrument->normalRangeHi != 0x7F) {
                    AudioLoad_RelocateSample(&instrument->highPitchTunedSample, fontBaseAddr, relocData);
                }
                offset = (uintptr_t) instrument->envelope;
                instrument->envelope = (EnvelopePoint*) (offset + fontBaseAddr);
                instrument->isRelocated = true;
            }
        }
    }
    gAudioCtx.soundFontList[fontId].drums = fontDataPtrs[0];
    gAudioCtx.soundFontList[fontId].soundEffects = (SoundEffect*) fontDataPtrs[1];
    gAudioCtx.soundFontList[fontId].instruments = (Instrument**) &fontDataPtrs[2];
}

void AudioLoad_SyncDma(uintptr_t devAddr, u8* ramAddr, size_t size, s32 medium) {

    size = ALIGN16(size);
    Audio_InvalDCache(ramAddr, size);
    while (true) {
        if (size < 0x400) {
            break;
        }
        AudioLoad_Dma(&gAudioCtx.syncDmaIoMesg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, 0x400,
                      &gAudioCtx.syncDmaQueue, medium, "FastCopy");
        osRecvMesg(&gAudioCtx.syncDmaQueue, NULL, OS_MESG_BLOCK);
        size -= 0x400;
        devAddr += 0x400;
        ramAddr += 0x400;
    }
    if (size != 0) {
        AudioLoad_Dma(&gAudioCtx.syncDmaIoMesg, OS_MESG_PRI_HIGH, OS_READ, devAddr, ramAddr, size,
                      &gAudioCtx.syncDmaQueue, medium, "FastCopy");
        osRecvMesg(&gAudioCtx.syncDmaQueue, NULL, OS_MESG_BLOCK);
    }
    PRINTF("Convert to %d %d\n");
}

void AudioLoad_SyncDmaUnkMedium(uintptr_t devAddr, u8* ramAddr, size_t size, s32 unkMediumParam) {
    uintptr_t adjustedDevAddr = devAddr;
    s32 pad;

    Audio_InvalDCache(ramAddr, size);
    func_807383B0(func_80735ECC(unkMediumParam, &adjustedDevAddr), adjustedDevAddr, ramAddr, size);
}

extern DmaHandler sDmaHandler;
extern s32 D_80771968;
extern s32 D_8077196C;
extern s32 D_80771970;
extern s32 D_80771974;

s32 AudioLoad_Dma(OSIoMesg* mesg, u32 priority, s32 direction, uintptr_t devAddr, void* ramAddr, size_t size,
                  OSMesgQueue* reqQueue, s32 medium, const char* dmaFuncType) {
    OSPiHandle* handle;

    if (gAudioCtx.resetTimer > 16) {
        return -1;
    }

    switch (medium) {
        case MEDIUM_CART:
            handle = gAudioCtx.cartHandle;
            break;

        case MEDIUM_DISK_DRIVE:
            handle = gAudioCtx.driveHandle;
            break;

        default:
            return 0;
    }

    if ((size % 0x10) != 0) {
        size = ALIGN16(size);
    }

    mesg->hdr.pri = priority;
    mesg->hdr.retQueue = reqQueue;
    mesg->dramAddr = ramAddr;
    mesg->devAddr = devAddr;
    mesg->size = size;
    handle->transferInfo.cmdType = 2;
    sDmaHandler(handle, mesg, direction);

    D_80771968++;
    D_8077196C = devAddr;
    D_80771970 = size;
    D_80771974 = medium;

    return 0;
}

extern s32 D_80771978[]; // LEOBYTE_TBL2
extern s32 D_807719A0[]; // LEOVZONE_TBL adjusted for system lbas
extern s32 D_807719E0[]; // LEOVZONE_PZONEHD_TBL adjusted to be in range 0 - 7

s32 func_80735DEC(s32 lba) {
    s32 i;
    s32 j = 0;

    for (i = 0; i < 15; i++, j++) {
        if (lba < D_807719A0[i]) {
            break;
        }
    }

    if (i == 15) {
        return 0;
    }

    j = D_807719E0[j];
    return D_80771978[j];
}

s32 func_80735E58(s32* lbaPtr, s32* devAddrPtr) {
    s32 blockSize;
    s32 lba;
    s32 devAddr;

    lba = *lbaPtr;
    devAddr = *devAddrPtr;

    while (true) {
        blockSize = func_80735DEC(lba);
        if (blockSize == 0) {
            return -1;
        }
        if (devAddr < blockSize) {
            break;
        }
        devAddr -= blockSize;
        lba++;
    }
    *lbaPtr = lba;
    *devAddrPtr = devAddr;
    return 0;
}

s32 func_80735ECC(s32 unkMediumParam, uintptr_t* devAddrPtr) {
    if (func_80735E58(&unkMediumParam, devAddrPtr) == -1) {
        rmonPrintf("LBA ERROR! \n");
        while (true) {}
    }
    return unkMediumParam;
}

void AudioLoad_SyncLoadSimple(u32 tableType, u32 fontId) {
    s32 didAllocate;

    AudioLoad_SyncLoad(tableType, fontId, &didAllocate);
}

void* AudioLoad_AsyncLoadInner(s32 tableType, s32 id, s32 nChunks, s32 retData, OSMesgQueue* retQueue) {
    size_t size;
    AudioTable* table;
    void* ramAddr;
    s32 medium;
    s8 cachePolicy;
    uintptr_t devAddr;
    s32 loadStatus;
    s32 pad;
    u32 realId = AudioLoad_GetLoadTableIndex(tableType, id);

    switch (tableType) {
        case SEQUENCE_TABLE:
            if (gAudioCtx.seqLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;

        case FONT_TABLE:
            if (gAudioCtx.fontLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;

        case SAMPLE_TABLE:
            if (gAudioCtx.sampleFontLoadStatus[realId] == LOAD_STATUS_IN_PROGRESS) {
                return NULL;
            }
            break;
    }

    ramAddr = AudioLoad_SearchCaches(tableType, realId);
    if (ramAddr != NULL) {
        loadStatus = LOAD_STATUS_COMPLETE;
        osSendMesg(retQueue, (OSMesg) (retData << 0x18), OS_MESG_NOBLOCK);
    } else {
        table = AudioLoad_GetLoadTable(tableType);
        size = table->entries[realId].size;
        size = ALIGN16(size);
        medium = table->entries[id].medium;
        cachePolicy = table->entries[id].cachePolicy;
        devAddr = table->entries[realId].romAddr;
        loadStatus = LOAD_STATUS_COMPLETE;

        switch (cachePolicy) {
            case 0:
                ramAddr = AudioHeap_AllocPermanent(tableType, realId, size);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                loadStatus = LOAD_STATUS_PERMANENTLY_LOADED;
                break;

            case 1:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_PERSISTENT, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 2:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_TEMPORARY, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;

            case 3:
            case 4:
                ramAddr = AudioHeap_AllocCached(tableType, size, CACHE_EITHER, realId);
                if (ramAddr == NULL) {
                    return ramAddr;
                }
                break;
        }

        if (medium == MEDIUM_UNK) {
            AudioLoad_StartAsyncLoadUnkMedium(table->header.unkMediumParam, devAddr, ramAddr, size, medium, nChunks,
                                              retQueue,
                                              (retData << 0x18) | (tableType << 0x10) | (id << 8) | loadStatus);
        } else {
            AudioLoad_StartAsyncLoad(devAddr, ramAddr, size, medium, nChunks, retQueue,
                                     (retData << 0x18) | (tableType << 0x10) | (realId << 8) | loadStatus);
        }
        loadStatus = LOAD_STATUS_IN_PROGRESS;
    }

    switch (tableType) {
        case SEQUENCE_TABLE:
            AudioLoad_SetSeqLoadStatus(realId, loadStatus);
            break;

        case FONT_TABLE:
            AudioLoad_SetFontLoadStatus(realId, loadStatus);
            break;

        case SAMPLE_TABLE:
            AudioLoad_SetSampleFontLoadStatusAndApplyCaches(realId, loadStatus);
            break;

        default:
            break;
    }

    return ramAddr;
}

void AudioLoad_ProcessLoads(s32 resetStatus) {
    AudioLoad_ProcessSlowLoads(resetStatus);
    AudioLoad_ProcessSamplePreloads(resetStatus);
    AudioLoad_ProcessAsyncLoads(resetStatus);
}

extern s32 (*sLeoHandler)(LEOCmd*, s32, u32, void*, u32, OSMesgQueue*);

s32 func_80736268(LEOCmd* cmdBlock, s32 direction, u32 lba, void* arg3, u32 nLbas, OSMesgQueue* mq, bool arg6) {
    void* vAddr;
    s32* sp20;

    if (arg6) {
        sp20 = arg3;
        vAddr = *((s32*) arg3 + 1);
        if ((lba == *sp20) && (nLbas == 1)) {
            osSendMesg(mq, NULL, 0);
            return 0;
        }
    } else {
        vAddr = arg3;
    }

    sLeoHandler(cmdBlock, direction, lba, vAddr, nLbas, mq);
    if ((nLbas == 1) && arg6) {
        *sp20 = lba;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_8073631C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736328.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736334.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_Init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736754.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736768.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736938.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807369D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_ProcessSlowLoads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736BCC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736C50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736CA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80736D8C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_StartAsyncLoadUnkMedium.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_StartAsyncLoad.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_ProcessAsyncLoads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807370D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807371B4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807372F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_8073744C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807374DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_RelocateSample.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_RelocateFontAndPreloadSamples.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_ProcessSamplePreloads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80737C20.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80737C68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80737D9C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80737DF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738270.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807383B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738558.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738580.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_8073860C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738850.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/AudioLoad_ProcessScriptLoads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738914.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738944.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_807389AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738A04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738AA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738B84.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738BC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738CA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/audio/load/func_80738E1C.s")
