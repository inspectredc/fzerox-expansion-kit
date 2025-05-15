#include "global.h"
#include "audio.h"

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807343CC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734708.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_IsFontLoadComplete.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_IsSeqLoadComplete.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_IsSampleLoadComplete.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734B08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734B38.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734B68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734BC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734BF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734C58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_SyncLoadSeqParts.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734D40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_SyncLoadInstrument.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80734EFC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_AsyncLoadSeq.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_AsyncLoadSampleBank.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_AsyncLoadFont.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_GetFontsForSequence.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_DiscardSeqFonts.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807350F4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_SyncInitSeqPlayer.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_SyncInitSeqPlayerSkipTicks.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735244.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735374.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807353C8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807353E8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735504.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735608.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735818.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735854.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807358A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807358EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735B58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735C7C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735CD4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735DEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735E58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735ECC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735F0C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80735F2C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_ProcessLoads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736268.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_8073631C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736328.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736334.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_Init.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736754.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736768.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736938.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807369D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736A44.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736BCC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736C50.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736CA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736D8C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736E08.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736E8C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80736FB0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807370D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807371B4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807372F0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_8073744C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807374DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737534.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737674.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737A6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737C20.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737C68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737D9C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80737DF4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738270.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807383B0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738558.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738580.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_8073860C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738850.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/AudioLoad_ProcessScriptLoads.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738914.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738944.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_807389AC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738A04.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738AA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738B84.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738BC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738CA8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/41AE0/func_80738E1C.s")
