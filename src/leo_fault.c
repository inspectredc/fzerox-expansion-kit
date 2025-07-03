#include "global.h"
#include "leo/leo_internal.h"

extern s32 D_8079A32C;
extern OSPiHandle* gDriveRomHandle;

u16* sLeoPrintFrameBuffer;
u16* sLeoPrintCurPixel;
OSMesgQueue sLeoFontMsgQueue;
OSMesg sLeoFontMsgBuf[1];
OSIoMesg sLeoFontIoMsg;
s32 sLeoFontLoadedCharacters[110];

#define SHIFT_JIS(x) (((x) & (0xFF00)) >> 8), ((x) & (0xFF))

u8 D_8076D010[] = { SHIFT_JIS(0x824F), SHIFT_JIS(0) }; // ０

u8 D_8076D014[] = { SHIFT_JIS(0x8250), SHIFT_JIS(0) }; // １

u8 D_8076D018[] = { SHIFT_JIS(0x8251), SHIFT_JIS(0) }; // ２

u8 D_8076D01C[] = { SHIFT_JIS(0x8252), SHIFT_JIS(0) }; // ３

u8 D_8076D020[] = { SHIFT_JIS(0x8253), SHIFT_JIS(0) }; // ４

u8 D_8076D024[] = { SHIFT_JIS(0x8254), SHIFT_JIS(0) }; // ５

u8 D_8076D028[] = { SHIFT_JIS(0x8255), SHIFT_JIS(0) }; // ６

u8 D_8076D02C[] = { SHIFT_JIS(0x8256), SHIFT_JIS(0) }; // ７

u8 D_8076D030[] = { SHIFT_JIS(0x8257), SHIFT_JIS(0) }; // ８

u8 D_8076D034[] = { SHIFT_JIS(0x8258), SHIFT_JIS(0) }; // ９

u8 D_8076D038[] = {
    // エラー番号
    SHIFT_JIS(0x8347), SHIFT_JIS(0x8389), SHIFT_JIS(0x815B), SHIFT_JIS(0x94D4), SHIFT_JIS(0x8D86), SHIFT_JIS(0),
};

u8 D_8076D044[] = {
    // 取扱説明書をお読みください。
    SHIFT_JIS(0x8EE6), SHIFT_JIS(0x88B5), SHIFT_JIS(0x90E0), SHIFT_JIS(0x96BE), SHIFT_JIS(0x8F91),
    SHIFT_JIS(0x82F0), SHIFT_JIS(0x82A8), SHIFT_JIS(0x93C7), SHIFT_JIS(0x82DD), SHIFT_JIS(0x82AD),
    SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D064[] = {
    // 【注意】アクセスランプ点滅中に
    SHIFT_JIS(0x8179), SHIFT_JIS(0x928D), SHIFT_JIS(0x88D3), SHIFT_JIS(0x817A), SHIFT_JIS(0x8341), SHIFT_JIS(0x834E),
    SHIFT_JIS(0x835A), SHIFT_JIS(0x8358), SHIFT_JIS(0x8389), SHIFT_JIS(0x8393), SHIFT_JIS(0x8376), SHIFT_JIS(0x935F),
    SHIFT_JIS(0x96C5), SHIFT_JIS(0x9286), SHIFT_JIS(0x82C9), SHIFT_JIS(0),
};

u8 D_8076D084[] = {
    // ディスクを抜かないでください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x94B2),
    SHIFT_JIS(0x82A9), SHIFT_JIS(0x82C8), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D0A4[] = {
    // 詳しくは、取扱説明書を
    SHIFT_JIS(0x8FDA), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82CD), SHIFT_JIS(0x8141), SHIFT_JIS(0x8EE6),
    SHIFT_JIS(0x88B5), SHIFT_JIS(0x90E0), SHIFT_JIS(0x96BE), SHIFT_JIS(0x8F91), SHIFT_JIS(0x82F0), SHIFT_JIS(0),
};

u8 D_8076D0BC[] = {
    // お読みください。
    SHIFT_JIS(0x82A8), SHIFT_JIS(0x93C7), SHIFT_JIS(0x82DD), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D0D0[] = {
    // ディスクを差し込んでください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x8DB7),
    SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D0F0[] = {
    // ディスクを差し込みなおして
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0),
    SHIFT_JIS(0x8DB7), SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82DD), SHIFT_JIS(0x82C8),
    SHIFT_JIS(0x82A8), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0),
};

u8 D_8076D10C[] = {
    // 間違ったディスクが差し込まれている
    SHIFT_JIS(0x8AD4), SHIFT_JIS(0x88E1), SHIFT_JIS(0x82C1), SHIFT_JIS(0x82BD), SHIFT_JIS(0x8366), SHIFT_JIS(0x8342),
    SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82AA), SHIFT_JIS(0x8DB7), SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E),
    SHIFT_JIS(0x82DC), SHIFT_JIS(0x82EA), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82E9), SHIFT_JIS(0),
};

u8 D_8076D130[] = {
    // 可能性があります。
    SHIFT_JIS(0x89C2), SHIFT_JIS(0x945C), SHIFT_JIS(0x90AB), SHIFT_JIS(0x82AA), SHIFT_JIS(0x82A0),
    SHIFT_JIS(0x82E8), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B7), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D144[] = {
    // 正しいディスクに交換してください。
    SHIFT_JIS(0x90B3), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358),
    SHIFT_JIS(0x834E), SHIFT_JIS(0x82C9), SHIFT_JIS(0x8CF0), SHIFT_JIS(0x8AB7), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4),
    SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D168[] = {
    // ディスクが差し込まれていますか。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82AA), SHIFT_JIS(0x8DB7),
    SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82EA), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82A2),
    SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B7), SHIFT_JIS(0x82A9), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D18C[] = {
    // 起動時のディスクを差し込んで
    SHIFT_JIS(0x8B4E), SHIFT_JIS(0x93AE), SHIFT_JIS(0x8E9E), SHIFT_JIS(0x82CC), SHIFT_JIS(0x8366),
    SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x8DB7),
    SHIFT_JIS(0x82B5), SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C5), SHIFT_JIS(0),
};

u8 D_8076D1AC[] = {
    // ください。
    SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D1B8[] = {
    // ディスクを取り出してください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x8EE6),
    SHIFT_JIS(0x82E8), SHIFT_JIS(0x8F6F), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D1D8[] = {
    // 前回データが最後まできちんと
    SHIFT_JIS(0x914F), SHIFT_JIS(0x89F1), SHIFT_JIS(0x8366), SHIFT_JIS(0x815B), SHIFT_JIS(0x835E),
    SHIFT_JIS(0x82AA), SHIFT_JIS(0x8DC5), SHIFT_JIS(0x8CE3), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82C5),
    SHIFT_JIS(0x82AB), SHIFT_JIS(0x82BF), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C6), SHIFT_JIS(0),
};

u8 D_8076D1F8[] = {
    // セーブできませんでした。
    SHIFT_JIS(0x835A), SHIFT_JIS(0x815B), SHIFT_JIS(0x8375), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AB),
    SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B9), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82B5),
    SHIFT_JIS(0x82BD), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D214[] = {
    // 全てのデータを消します。
    SHIFT_JIS(0x9153), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82CC), SHIFT_JIS(0x8366), SHIFT_JIS(0x815B),
    SHIFT_JIS(0x835E), SHIFT_JIS(0x82F0), SHIFT_JIS(0x8FC1), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82DC),
    SHIFT_JIS(0x82B7), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D230[] = {
    // Ａボタンを押してください。
    SHIFT_JIS(0x8260), SHIFT_JIS(0x837B), SHIFT_JIS(0x835E), SHIFT_JIS(0x8393), SHIFT_JIS(0x82F0),
    SHIFT_JIS(0x899F), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D24C[] = {
    // ゲーム中のディスクの交換は
    SHIFT_JIS(0x8351), SHIFT_JIS(0x815B), SHIFT_JIS(0x8380), SHIFT_JIS(0x9286), SHIFT_JIS(0x82CC),
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82CC),
    SHIFT_JIS(0x8CF0), SHIFT_JIS(0x8AB7), SHIFT_JIS(0x82CD), SHIFT_JIS(0),
};

u8 D_8076D268[] = {
    // できません。
    SHIFT_JIS(0x82C5), SHIFT_JIS(0x82AB), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B9),
    SHIFT_JIS(0x82F1), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D278[] = {
    // コースのデータがきちんと
    SHIFT_JIS(0x8352), SHIFT_JIS(0x815B), SHIFT_JIS(0x8358), SHIFT_JIS(0x82CC), SHIFT_JIS(0x8366),
    SHIFT_JIS(0x815B), SHIFT_JIS(0x835E), SHIFT_JIS(0x82AA), SHIFT_JIS(0x82AB), SHIFT_JIS(0x82BF),
    SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C6), SHIFT_JIS(0),
};

u8 D_8076D294[] = {
    // 読めませんでした。
    SHIFT_JIS(0x93C7), SHIFT_JIS(0x82DF), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82B9), SHIFT_JIS(0x82F1),
    SHIFT_JIS(0x82C5), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82BD), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D2A8[] = {
    // リセットボタンを押してください。
    SHIFT_JIS(0x838A), SHIFT_JIS(0x835A), SHIFT_JIS(0x8362), SHIFT_JIS(0x8367), SHIFT_JIS(0x837B), SHIFT_JIS(0x835E),
    SHIFT_JIS(0x8393), SHIFT_JIS(0x82F0), SHIFT_JIS(0x899F), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82AD),
    SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D2CC[] = {
    // しばらくお待ちください。
    SHIFT_JIS(0x82B5), SHIFT_JIS(0x82CE), SHIFT_JIS(0x82E7), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82A8),
    SHIFT_JIS(0x91D2), SHIFT_JIS(0x82BF), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3),
    SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D2E8[] = {
    // モードセレクト画面で差し込んでいた
    SHIFT_JIS(0x8382), SHIFT_JIS(0x815B), SHIFT_JIS(0x8368), SHIFT_JIS(0x835A), SHIFT_JIS(0x838C), SHIFT_JIS(0x834E),
    SHIFT_JIS(0x8367), SHIFT_JIS(0x89E6), SHIFT_JIS(0x96CA), SHIFT_JIS(0x82C5), SHIFT_JIS(0x8DB7), SHIFT_JIS(0x82B5),
    SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C5), SHIFT_JIS(0x82A2), SHIFT_JIS(0x82BD), SHIFT_JIS(0),
};

u8 D_8076D30C[] = {
    // ディスクに戻してください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82C9),
    SHIFT_JIS(0x96DF), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8 D_8076D328[] = {
    // ディスクを戻してください。
    SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x8358), SHIFT_JIS(0x834E), SHIFT_JIS(0x82F0),
    SHIFT_JIS(0x96DF), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82C4), SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE),
    SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0),
};

u8* sLeoErrorMessages[] = {
    D_8076D010, D_8076D014, D_8076D018, D_8076D01C, D_8076D020, D_8076D024, D_8076D028, D_8076D02C,
    D_8076D030, D_8076D034, D_8076D038, D_8076D044, D_8076D064, D_8076D084, D_8076D0A4, D_8076D0BC,
    D_8076D0D0, D_8076D0F0, D_8076D10C, D_8076D130, D_8076D144, D_8076D168, D_8076D18C, D_8076D1AC,
    D_8076D1B8, D_8076D1D8, D_8076D1F8, D_8076D214, D_8076D230, D_8076D24C, D_8076D268, D_8076D278,
    D_8076D294, D_8076D2A8, D_8076D2CC, D_8076D2E8, D_8076D30C, D_8076D328,
};

u8 sLeoFontCharacters[] = {
    SHIFT_JIS(0x824F), SHIFT_JIS(0x8250), SHIFT_JIS(0x8251), SHIFT_JIS(0x8252), SHIFT_JIS(0x8253), SHIFT_JIS(0x8254),
    SHIFT_JIS(0x8255), SHIFT_JIS(0x8256), SHIFT_JIS(0x8257), SHIFT_JIS(0x8258), SHIFT_JIS(0x8347), SHIFT_JIS(0x8389),
    SHIFT_JIS(0x815B), SHIFT_JIS(0x94D4), SHIFT_JIS(0x8D86), SHIFT_JIS(0x8EE6), SHIFT_JIS(0x88B5), SHIFT_JIS(0x90E0),
    SHIFT_JIS(0x96BE), SHIFT_JIS(0x8F91), SHIFT_JIS(0x82F0), SHIFT_JIS(0x82A8), SHIFT_JIS(0x93C7), SHIFT_JIS(0x82DD),
    SHIFT_JIS(0x82AD), SHIFT_JIS(0x82BE), SHIFT_JIS(0x82B3), SHIFT_JIS(0x82A2), SHIFT_JIS(0x8142), SHIFT_JIS(0x8179),
    SHIFT_JIS(0x928D), SHIFT_JIS(0x88D3), SHIFT_JIS(0x817A), SHIFT_JIS(0x8341), SHIFT_JIS(0x834E), SHIFT_JIS(0x835A),
    SHIFT_JIS(0x8358), SHIFT_JIS(0x8393), SHIFT_JIS(0x8376), SHIFT_JIS(0x935F), SHIFT_JIS(0x96C5), SHIFT_JIS(0x9286),
    SHIFT_JIS(0x82C9), SHIFT_JIS(0x8366), SHIFT_JIS(0x8342), SHIFT_JIS(0x94B2), SHIFT_JIS(0x82A9), SHIFT_JIS(0x82C8),
    SHIFT_JIS(0x82C5), SHIFT_JIS(0x8FDA), SHIFT_JIS(0x82B5), SHIFT_JIS(0x82CD), SHIFT_JIS(0x8141), SHIFT_JIS(0x8DB7),
    SHIFT_JIS(0x8D9E), SHIFT_JIS(0x82F1), SHIFT_JIS(0x82C4), SHIFT_JIS(0x8AD4), SHIFT_JIS(0x88E1), SHIFT_JIS(0x82C1),
    SHIFT_JIS(0x82BD), SHIFT_JIS(0x82AA), SHIFT_JIS(0x82DC), SHIFT_JIS(0x82EA), SHIFT_JIS(0x82E9), SHIFT_JIS(0x89C2),
    SHIFT_JIS(0x945C), SHIFT_JIS(0x90AB), SHIFT_JIS(0x82A0), SHIFT_JIS(0x82E8), SHIFT_JIS(0x82B7), SHIFT_JIS(0x90B3),
    SHIFT_JIS(0x8CF0), SHIFT_JIS(0x8AB7), SHIFT_JIS(0x8B4E), SHIFT_JIS(0x93AE), SHIFT_JIS(0x8E9E), SHIFT_JIS(0x82CC),
    SHIFT_JIS(0x8F6F), SHIFT_JIS(0x914F), SHIFT_JIS(0x89F1), SHIFT_JIS(0x835E), SHIFT_JIS(0x8DC5), SHIFT_JIS(0x8CE3),
    SHIFT_JIS(0x82AB), SHIFT_JIS(0x82BF), SHIFT_JIS(0x82C6), SHIFT_JIS(0x8375), SHIFT_JIS(0x82B9), SHIFT_JIS(0x9153),
    SHIFT_JIS(0x8FC1), SHIFT_JIS(0x8260), SHIFT_JIS(0x837B), SHIFT_JIS(0x899F), SHIFT_JIS(0x8351), SHIFT_JIS(0x8380),
    SHIFT_JIS(0x8352), SHIFT_JIS(0x82DF), SHIFT_JIS(0x838A), SHIFT_JIS(0x8362), SHIFT_JIS(0x8367), SHIFT_JIS(0x82CE),
    SHIFT_JIS(0x82E7), SHIFT_JIS(0x91D2), SHIFT_JIS(0x8382), SHIFT_JIS(0x8368), SHIFT_JIS(0x838C), SHIFT_JIS(0x89E6),
    SHIFT_JIS(0x96CA), SHIFT_JIS(0x96DF), SHIFT_JIS(0),
};

u16 sLeoFontPallete[] = {
    GPACK_RGBA5551(0, 0, 0, 1),       GPACK_RGBA5551(16, 16, 16, 1),    GPACK_RGBA5551(32, 32, 32, 1),
    GPACK_RGBA5551(48, 48, 48, 1),    GPACK_RGBA5551(64, 64, 64, 1),    GPACK_RGBA5551(80, 80, 80, 1),
    GPACK_RGBA5551(96, 96, 96, 1),    GPACK_RGBA5551(112, 112, 112, 1), GPACK_RGBA5551(136, 136, 136, 1),
    GPACK_RGBA5551(152, 152, 152, 1), GPACK_RGBA5551(168, 168, 168, 1), GPACK_RGBA5551(184, 184, 184, 1),
    GPACK_RGBA5551(200, 200, 200, 1), GPACK_RGBA5551(216, 216, 216, 1), GPACK_RGBA5551(232, 232, 232, 1),
    GPACK_RGBA5551(255, 255, 255, 1),
};

void LeoFault_CopyFontToRam(s32* code, u8* ramAddr) {
    uintptr_t fontAddr = LeoGetKAdr(code) + DDROM_FONT_START;

    sLeoFontIoMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    sLeoFontIoMsg.hdr.retQueue = &sLeoFontMsgQueue;
    sLeoFontIoMsg.dramAddr = ramAddr;
    sLeoFontIoMsg.devAddr = fontAddr;
    sLeoFontIoMsg.size = 0x80; // leo font size
    gDriveRomHandle->transferInfo.cmdType = LEO_CMD_TYPE_2;
    if (D_8079A32C == 2) {
        func_80768B88(gDriveRomHandle, &sLeoFontIoMsg, OS_READ);
    } else {
        osInvalDCache(osPhysicalToVirtual((uintptr_t) ramAddr), 0x80);
        osEPiStartDma(gDriveRomHandle, &sLeoFontIoMsg, OS_READ);
    }
    osRecvMesg(&sLeoFontMsgQueue, NULL, OS_MESG_BLOCK);
}

extern u8 D_8003BBD8[];

void LeoFault_LoadFontSet(void) {
    u16 i;

    osCreateMesgQueue(&sLeoFontMsgQueue, sLeoFontMsgBuf, ARRAY_COUNT(sLeoFontMsgBuf));
    for (i = 0; i < 110; i++) {
        sLeoFontLoadedCharacters[i] = (sLeoFontCharacters[i * 2] << 8) + sLeoFontCharacters[i * 2 + 1];
        LeoFault_CopyFontToRam(sLeoFontLoadedCharacters[i], D_8003BBD8 + i * 0x80);
    }
}

void LeoFault_DrawErrorBox(u16 left, u16 top, u16 right, u16 bottom, u16 color) {
    u16 i;
    u16 j;

    sLeoPrintFrameBuffer = osViGetNextFramebuffer();

    for (i = top; i <= bottom; i++) {
        for (j = left; j <= right; j++) {
            sLeoPrintCurPixel = sLeoPrintFrameBuffer + (i * SCREEN_WIDTH) + j;
            *sLeoPrintCurPixel = color;
        }
    }
}

void func_8070F3B4(void) {
    func_80703FC8();
}

extern u16 sLeoFontPallete[];
extern FrameBuffer* gFrameBuffers[3];

void func_8070F3D4(Gfx** gfxP, s32 posX, s32 posY, u8* fontCharData) {
    u8 i;
    u16 j;
    u8 k;
    u8 color1index;
    u8 color2index;

    if (gfxP == NULL) {
        u8* fontPtr = fontCharData;

        for (i = posY; i < posY + 16; i++) {
            for (j = posX; j < posX + 16; j += 2, fontPtr++) {
                color1index = *fontPtr >> 4;
                color2index = *fontPtr & 0xF;
                for (k = 0; k < ARRAY_COUNT(gFrameBuffers); k++) {
                    sLeoPrintCurPixel = gFrameBuffers[k]->data + (i * SCREEN_WIDTH) + j;
                    if (color1index != 0) {
                        *sLeoPrintCurPixel = sLeoFontPallete[color1index];
                    }

                    sLeoPrintCurPixel++;
                    if (color2index != 0) {
                        *sLeoPrintCurPixel = sLeoFontPallete[color2index];
                    }
                }
            }
        }
    } else {
        Gfx* gfx = *gfxP;

        gDPLoadTextureBlock_4b(gfx++, fontCharData, G_IM_FMT_I, 16, 16, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                               G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gfx++, posX << 2, posY << 2, (posX + 16) << 2, (posY + 16) << 2, 0, 0, 0, 1 << 10, 1 << 10);

        *gfxP = gfx;
    }
}

extern s32* D_8003BBB0;
extern u8* D_8003BBC0;

u8* func_8070F634(s32 code) {
    u16 i;

    for (i = 0; i < 110; i++) {
        if (code == sLeoFontLoadedCharacters[i]) {
            return D_8003BBD8 + i * 0x80;
        }
    }
    for (i = 0; i < 20; i++) {
        if (code == D_8003BBB0[i]) {
            return D_8003BBC0 + i * 0x80;
        }
    }
    return NULL;
}

void LeoFault_DrawErrorMessage(Gfx** gfxP, s32 posX, s32 posY, u8* codes) {
    u8 i;
    u8* fontData;

    for (i = 0; codes[i] != 0; i += 2, posX += 16) {
        fontData = func_8070F634((codes[i] << 8) + codes[i + 1]);
        func_8070F3D4(gfxP, posX, posY, fontData);
    }
}

void LeoFault_DrawErrorMessageNumber(Gfx** gfxP, s32 posX, s32 posY, s8* str) {
    u8 i;

    if (*str == '1') {
        posX -= 6;
    } else {
        posX -= 4;
    }

    for (i = 0; str[i] != 0; i++) {
        func_8070F3D4(gfxP, posX, posY, &D_8003BBD8[(str[i] - '0') * 0x80]);
        if (str[i] == '1') {
            posX += 7;
        } else {
            posX += 9;
        }
    }
}

void LeoFault_DrawErrorNumber(s32 errNo) {
    char errNoStr[4];

    sprintf(errNoStr, "%02d", errNo);
    LeoFault_DrawErrorMessage(NULL, 108, 70, sLeoErrorMessages[10]);
    LeoFault_DrawErrorMessageNumber(NULL, 194, 70, errNoStr);
}

void func_8070F8A4(s32 arg0, s32 arg1) {
    FrameBuffer* temp_a0;
    u8 i;
    u64* temp_v1;
    u64* temp;
    u64* var_v0;

    func_80767940();
    if (arg0 == LEO_ERROR_WAITING_NMI) {
        return;
    }

    if (arg1 == 10) {
        for (i = 0; i < ARRAY_COUNT(gFrameBuffers); i++) {
            var_v0 = &gFrameBuffers[i]->buffer[0x3B60];
            temp_v1 = temp = &gFrameBuffers[i]->buffer[0x4060];
            while (var_v0 < temp_v1) {
                var_v0++;
                *(var_v0 - 1) = 0x1000100010001;
            }
        }
        LeoFault_DrawErrorMessage(NULL, 68, 190, sLeoErrorMessages[34]);
    } else if (arg1 == 11) {
        SLForceWritebackDCacheAll();
        Fault_SetFrameBuffer(osViGetNextFramebuffer(), SCREEN_WIDTH, 16);
        Fault_FillRectangle(62, 187, 196, 22);
        LeoFault_DrawErrorBox(60, 185, 259, 186, GPACK_RGBA5551(130, 130, 255, 1));
        LeoFault_DrawErrorBox(60, 209, 259, 210, GPACK_RGBA5551(130, 130, 255, 1));
        LeoFault_DrawErrorBox(60, 187, 0x3D, 208, GPACK_RGBA5551(130, 130, 255, 1));
        LeoFault_DrawErrorBox(258, 187, 259, 208, GPACK_RGBA5551(130, 130, 255, 1));
        LeoFault_DrawErrorMessage(NULL, 68, 190, sLeoErrorMessages[34]);
    } else {
        func_8070F3B4();
        switch (arg1) {
            case 0:
                LeoFault_DrawErrorMessage(NULL, 52, 110, sLeoErrorMessages[11]);
                LeoFault_DrawErrorNumber(arg0);
                break;
            case 1:
                LeoFault_DrawErrorMessage(NULL, 40, 101, sLeoErrorMessages[12]);
                LeoFault_DrawErrorMessage(NULL, 40, 121, sLeoErrorMessages[13]);
                LeoFault_DrawErrorMessage(NULL, 40, 141, sLeoErrorMessages[14]);
                LeoFault_DrawErrorMessage(NULL, 40, 161, sLeoErrorMessages[15]);
                LeoFault_DrawErrorMessage(NULL, 44, 190, sLeoErrorMessages[16]);
                LeoFault_DrawErrorNumber(arg0);
                break;
            case 2:
                LeoFault_DrawErrorMessage(NULL, 56, 107, sLeoErrorMessages[17]);
                LeoFault_DrawErrorMessage(NULL, 56, 127, sLeoErrorMessages[23]);
                LeoFault_DrawErrorNumber(arg0);
                break;
            case 3:
                LeoFault_DrawErrorMessage(NULL, 24, 90, sLeoErrorMessages[18]);
                LeoFault_DrawErrorMessage(NULL, 24, 110, sLeoErrorMessages[19]);
                LeoFault_DrawErrorMessage(NULL, 24, 130, sLeoErrorMessages[20]);
                break;
            case 4:
                LeoFault_DrawErrorMessage(NULL, 36, 110, sLeoErrorMessages[21]);
                break;
            case 5:
                LeoFault_DrawErrorMessage(NULL, 48, 100, sLeoErrorMessages[22]);
                LeoFault_DrawErrorMessage(NULL, 48, 120, sLeoErrorMessages[23]);
                break;
            case 6:
                LeoFault_DrawErrorMessage(NULL, 48, 90, sLeoErrorMessages[25]);
                LeoFault_DrawErrorMessage(NULL, 48, 110, sLeoErrorMessages[26]);
                LeoFault_DrawErrorMessage(NULL, 48, 130, sLeoErrorMessages[27]);
                LeoFault_DrawErrorMessage(NULL, 60, 190, sLeoErrorMessages[28]);
                break;
            case 7:
                LeoFault_DrawErrorMessage(NULL, 48, 100, sLeoErrorMessages[25]);
                LeoFault_DrawErrorMessage(NULL, 48, 120, sLeoErrorMessages[26]);
                LeoFault_DrawErrorMessage(NULL, 60, 190, sLeoErrorMessages[28]);
                break;
            case 8:
                LeoFault_DrawErrorMessage(NULL, 24, 80, sLeoErrorMessages[29]);
                LeoFault_DrawErrorMessage(NULL, 24, 100, sLeoErrorMessages[30]);
                LeoFault_DrawErrorMessage(NULL, 24, 130, sLeoErrorMessages[35]);
                LeoFault_DrawErrorMessage(NULL, 24, 150, sLeoErrorMessages[36]);
                break;
            case 9:
                LeoFault_DrawErrorMessage(NULL, 64, 100, sLeoErrorMessages[31]);
                LeoFault_DrawErrorMessage(NULL, 64, 120, sLeoErrorMessages[32]);
                LeoFault_DrawErrorMessage(NULL, 36, 190, sLeoErrorMessages[33]);
                break;
            case 12:
                LeoFault_DrawErrorMessage(NULL, 60, 110, sLeoErrorMessages[37]);
                break;
        }
    }
    SLForceWritebackDCacheAll();
}
