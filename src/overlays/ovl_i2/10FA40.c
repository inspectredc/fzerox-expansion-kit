#include "global.h"
#include "ovl_i2.h"
#include "fzx_game.h"
#include "fzx_object.h"

unk_800E33E0 D_i2_800D58B0[200];
s32 D_i2_800D5EF0;
Object gObjects[32];
unk_800E3F28 D_800D63F8[16];
unk_800E4068 D_i2_800D6538[16];

extern s32 D_807C70C0;

void func_i2_800AE100(s32 segAddr, size_t size, u8* startAddr) {
    CLEAR_DATA_CACHE(startAddr, size);
    func_8070818C(D_807C70C0 + SEGMENT_OFFSET(segAddr), startAddr, size);
}

void func_i2_800AE170(void) {
    D_i2_800D5EF0 = 0;
}

extern uintptr_t gArenaStartPtrs[];

u8* func_i2_800AE17C(unk_80077D50* arg0, s32 arg1, bool arg2) {
    bool var_a0;
    s32 var_s0;
    s32 alignedWidth;
    s32 var_s2;
    size_t textureSize;
    u8* header;
    u8* sp44;
    u8* var_s4;
    bool var_s7;
    unk_800E33E0* var_s8 = D_i2_800D58B0;

    sp44 = gArenaStartPtrs[0];
    var_s7 = false;

    while (arg0->unk_04 != 0) {
        var_a0 = false;
        if (arg1 == 0) {
            for (var_s0 = 0; var_s0 < D_i2_800D5EF0; var_s0++) {
                // FAKE
                if (D_i2_800D58B0[var_s0].unk_00 == (0, arg0->unk_04)) {
                    var_a0 = true;
                    break;
                }
            }
        }
        if (!var_a0) {
            switch (arg0->unk_00) {
                case 4:
                case 5:
                    if (arg0->width % 16) {
                        alignedWidth = ((arg0->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = arg0->width;
                    }
                    textureSize = arg0->height * alignedWidth;
                    var_s4 = Arena_Allocate(ALLOC_FRONT, textureSize);
                    func_i2_800AE100(arg0->unk_04, textureSize, var_s4);
                    break;
                case 20:
                case 21:

                    if (arg0->width % 16) {
                        alignedWidth = ((arg0->width + 16) / 16) * 16;
                    } else {
                        alignedWidth = arg0->width;
                    }
                    textureSize = arg0->height * alignedWidth;
                    if (arg0->compressedSize != 0) {
                        var_s2 = ALIGN_2(arg0->compressedSize) + 2;
                    } else {
                        var_s2 = 0x400;
                    }
                    var_s4 = Arena_Allocate(ALLOC_FRONT, textureSize);
                    header = Arena_Allocate(ALLOC_PEEK, var_s2);
                    CLEAR_DATA_CACHE(header, var_s2);
                    func_i2_800AE100(arg0->unk_04, var_s2, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s4);
                    } else {
                        bzero(var_s4, (arg0->height * alignedWidth) / 2);
                    }
                    break;
                case 17:
                case 18:
                    if (arg0->compressedSize != 0) {
                        var_s0 = ALIGN_2(arg0->compressedSize) + 2;
                    } else {
                        var_s0 = 0x400;
                    }

                    var_s4 = Arena_Allocate(ALLOC_FRONT, arg0->height * arg0->width * 2);
                    header = Arena_Allocate(ALLOC_PEEK, var_s0);
                    CLEAR_DATA_CACHE(header, var_s0);
                    func_i2_800AE100(arg0->unk_04, var_s0, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s4);
                    } else {
                        bzero(var_s4, arg0->height * arg0->width * 2);
                    }
                    break;
                default:
                    var_s0 = arg0->height * arg0->width * 2;
                    var_s4 = Arena_Allocate(ALLOC_FRONT, var_s0);
                    func_i2_800AE100(arg0->unk_04, var_s0, var_s4);
                    break;
            }
            if (!var_s7) {
                sp44 = var_s4;
                var_s7 = true;
            }
            var_s8[D_i2_800D5EF0].unk_00 = arg0->unk_04;
            var_s8[D_i2_800D5EF0].unk_04 = (s32) var_s4;
            D_i2_800D5EF0++;
        }

        if (arg2) {
            break;
        }

        arg0++;
    }

    return sp44;
}

u8* func_i2_800AE578(unk_80077D50* arg0, bool arg1) {
    s32 temp_s0;
    bool var_a0;
    s32 var_s0;
    bool var_s6;
    u8* header;
    u8* var_fp;
    u8* var_s3;
    unk_800E33E0* var_s7 = D_i2_800D58B0;

    var_s6 = false;
    var_fp = gArenaStartPtrs[0];

    while (arg0->unk_04 != NULL) {
        var_a0 = false;
        if (!arg1) {
            for (var_s0 = 0; var_s0 < D_i2_800D5EF0; var_s0++) {
                if (D_i2_800D58B0[var_s0].unk_00 == (0, arg0->unk_04)) {
                    var_a0 = true;
                    break;
                }
            }
        }
        if (!var_a0) {
            switch (arg0->unk_00) {
                case 17:
                case 18:
                    if (arg0->compressedSize != 0) {
                        var_s0 = ((arg0->compressedSize >> 1) * 2) + 2;
                    } else {
                        var_s0 = 0x400;
                    }
                    var_s3 = Arena_Allocate(ALLOC_FRONT, arg0->height * arg0->width * 2);
                    header = Arena_Allocate(ALLOC_PEEK, var_s0);
                    CLEAR_DATA_CACHE(header, var_s0);
                    bcopy(arg0->unk_04, header, var_s0);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s3);
                    } else {
                        bzero(var_s3, arg0->height * arg0->width * 2);
                    }
                    break;
                default:
                    var_s0 = arg0->height * arg0->width * 2;
                    var_s3 = Arena_Allocate(ALLOC_FRONT, var_s0);
                    func_i2_800AE100(arg0->unk_04, var_s0, var_s3);
                    break;
            }
            if (!var_s6) {
                var_fp = var_s3;
                var_s6 = true;
            }
            var_s7[D_i2_800D5EF0].unk_00 = arg0->unk_04;
            var_s7[D_i2_800D5EF0].unk_04 = var_s3;
            D_i2_800D5EF0++;
        }
        arg0++;
    }
    return var_fp;
}

void* func_i2_800AE7C4(void* arg0, s32 textureSize, s32 arg2, s32 arg3, bool arg4) {
    s32 var_a3;
    bool var_t0;
    u8* var_s0;
    u8* var_a2;
    s32 sp24;
    unk_800E33E0* var_v1 = D_i2_800D58B0;

    var_t0 = false;
    if ((arg2 == 0) && !arg4) {
        for (var_a3 = 0; var_a3 < D_i2_800D5EF0; var_a3++) {
            if (D_i2_800D58B0[var_a3].unk_00 == arg0) {
                var_t0 = true;
                break;
            }
        }
    }
    if (!var_t0 || arg4) {
        if (arg3 == 0) {
            if (!arg4) {
                var_s0 = Arena_Allocate(ALLOC_FRONT, textureSize);
            } else {
                var_s0 = Arena_Allocate(ALLOC_PEEK, textureSize);
            }
            func_i2_800AE100(arg0, textureSize, var_s0);
        } else {
            var_s0 = Arena_Allocate(ALLOC_PEEK, 8);
            func_i2_800AE100(arg0, 8, var_s0);
            var_a3 = func_8072E44C(var_s0);

            if (!arg4) {
                var_s0 = Arena_Allocate(ALLOC_FRONT, var_a3);
                var_a2 = Arena_Allocate(ALLOC_PEEK, textureSize);
            } else {
                if (var_a3 % 16) {
                    var_a3 = ((var_a3 / 16) * 16) + 16;
                }
                if (textureSize % 16) {
                    textureSize = ((textureSize / 16) * 16) + 16;
                }

                sp24 = textureSize + var_a3;
                var_s0 = Arena_Allocate(ALLOC_PEEK, sp24);
                CLEAR_DATA_CACHE(var_s0, sp24);
                var_a2 = var_s0 + var_a3;
            }

            CLEAR_DATA_CACHE(var_a2, textureSize);
            func_i2_800AE100(arg0, textureSize, var_a2);
            if (*(s32*) var_a2 == (s32) 'MIO0') {
                mio0Decode(var_a2, var_s0);
            } else {
                bzero(var_s0, var_a3);
            }
        }
        if (!arg4) {
            var_v1[D_i2_800D5EF0].unk_00 = arg0;
            var_v1[D_i2_800D5EF0].unk_04 = var_s0;
            D_i2_800D5EF0++;
        }
    } else {
        // FAKE
        return (var_v1 + var_a3)->unk_04;
    }
    return var_s0;
}

TexturePtr func_i2_800AEA90(void* arg0) {
    s32 i;

    for (i = 0; i < D_i2_800D5EF0; i++) {
        if (arg0 == D_i2_800D58B0[i].unk_00) {
            return D_i2_800D58B0[i].unk_04;
        }
    }
    return NULL;
}

Gfx* func_i2_800AEAD8(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                                 0, 0);
    }
}

Gfx* func_i2_800AEC60(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 1,
                                 0, 0);
        case 1:
        default:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0,
                                 0, 0);
    }
}

Gfx* func_i2_800AEDF0(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, s32 arg5, s32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 0, 0,
                                 0);
        case 5:
        case 21:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_I, G_IM_SIZ_4b, 3, 1, 0,
                                 0);
        case 2:
        case 18:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 arg5, arg6);
        case 1:
        default:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0,
                                 arg5, arg6);
    }
}

Gfx* func_i2_800AEF88(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 0, 0, 0);
    }
}

Gfx* func_i2_800AF130(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 1,
                                 0, 0);
        case 1:
        default:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 0, 0, 1);
    }
}

Gfx* func_i2_800AF2DC(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, f32 arg5, f32 arg6) {

    switch (arg1->unk_00) {
        case 3:
            return func_8070A99C(gfx, texture, left, top, arg1->width, arg1->height, G_IM_FMT_IA, G_IM_SIZ_8b, 2, 0, 0,
                                 0);
        case 4:
        case 20:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 5:
        case 21:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_I,
                                 G_IM_SIZ_4b, 3, 0, 0);
        case 2:
        case 18:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 1, 1, 0);
        case 1:
        default:
            return func_8070C600(gfx, texture, left, top, arg1->width, arg1->height, arg5, arg6, G_IM_FMT_RGBA,
                                 G_IM_SIZ_16b, 1, 0, 0);
    }
}

// BAD RETURN
Gfx* func_i2_800AF498(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, TexturePtr texture, u32 arg5, s32 arg6, s32 arg7,
                      f32 arg8, f32 arg9) {
    switch (arg5) {
        case 0:
            return func_i2_800AEAD8(gfx, arg1, left, top, texture);
        case 1:
            return func_i2_800AEC60(gfx, arg1, left, top, texture);
        case 2:
            return func_i2_800AEDF0(gfx, arg1, left, top, texture, arg6, arg7);
        case 3:
            return func_i2_800AEF88(gfx, arg1, left, top, texture, arg8, arg9);
        case 5:
            return func_i2_800AF130(gfx, arg1, left, top, texture, arg8, arg9);
        case 4:
            return func_i2_800AF2DC(gfx, arg1, left, top, texture, arg8, arg9);
    }
}

Gfx* func_i2_800AF584(Gfx* gfx, unk_80077D50* arg1, s32 left, s32 top, u32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8,
                      bool arg9) {
    TexturePtr texture;

    while (arg1->unk_04 != 0) {
        // FAKE
        if (gfx) {}

        texture = func_i2_800AEA90(arg1->unk_04);
        if (texture != NULL) {
            gfx = func_i2_800AF498(gfx, arg1, left, top, texture, arg4, arg5, arg6, arg7, arg8);
        }
        if (arg9) {
            break;
        }
        arg1++;
    }
    return gfx;
}

Gfx* func_i2_800AF678(Gfx* gfx, unk_800E3F28* arg1, s32 left, s32 top, u32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8,
                      bool arg9) {
    TexturePtr texture;
    unk_80077D50* var_s0;
    s32 var;

    var_s0 = arg1->unk_00[arg1->unk_04].unk_00;

    while (var_s0->unk_04 != 0) {
        if (gfx) {}
        var = arg1->unk_0A;
        switch (var) {
            case 0:
                texture = arg1->unk_0C;
                break;
            default:
                texture = arg1->unk_10;
                break;
        }

        if (texture != NULL) {
            gfx = func_i2_800AF498(gfx, var_s0, left, top, texture, arg4, arg5, arg6, arg7, arg8);
        }

        if (arg9) {
            break;
        }

        var_s0++;
    }
    return gfx;
}

void func_i2_800AF78C(void) {
    s32 i;

    D_i2_800D6538[0].unk_00 = NULL;

    for (i = 1; i < 17; i++) {}
}

void func_i2_800AF7B0(unk_80077D50* arg0, TexturePtr arg1) {
    unk_800E4068* var_v0;

    var_v0 = D_i2_800D6538;
    while (var_v0->unk_00 != NULL) {
        var_v0++;
    }
    var_v0->unk_00 = arg0;
    var_v0->unk_04 = arg1;
}

void func_i2_800AF7E0(void) {
    s32 var_v1;
    u8* header;
    size_t size;
    unk_80077D50* temp_s1;
    unk_800E4068* var_s3;

    var_s3 = D_i2_800D6538;

    while (true) {
        temp_s1 = var_s3->unk_00;
        if (temp_s1 != NULL) {
            switch (temp_s1->unk_00) {
                case 4:
                case 5:
                    if (temp_s1->width % 16) {
                        var_v1 = ((temp_s1->width + 16) / 16) * 16;
                    } else {
                        var_v1 = temp_s1->width;
                    }
                    func_i2_800AE100(temp_s1->unk_04, temp_s1->height * var_v1, var_s3->unk_04);
                    break;
                case 17:
                case 18:
                    if (temp_s1->compressedSize != 0) {
                        size = ALIGN_2(temp_s1->compressedSize) + 2;
                    } else {
                        size = 0x400;
                    }
                    header = Arena_Allocate(ALLOC_PEEK, size);
                    CLEAR_DATA_CACHE(header, size);
                    func_i2_800AE100(temp_s1->unk_04, size, header);
                    if (*(s32*) header == (s32) 'MIO0') {
                        mio0Decode(header, var_s3->unk_04);
                    } else {
                        bzero(var_s3->unk_04, temp_s1->height * temp_s1->width * 2);
                    }
                    break;
                default:
                    size = temp_s1->height * temp_s1->width;
                    func_i2_800AE100(temp_s1->unk_04, size * 2, var_s3->unk_04);
                    break;
            }
            var_s3->unk_00 = NULL;
            var_s3++;
        } else {
            break;
        }
    }
}

void func_i2_800AF9C8(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        D_800D63F8[i].unk_08 = 0;
    }
}

s32 func_i2_800AF9F8(unk_800792D8* arg0) {
    s32 i = 0;
    u8* var_v0;

    while (D_800D63F8[i].unk_08 != 0) {
        if (++i >= 16) {
            return -1;
        }
    }

    D_800D63F8[i].unk_00 = arg0;
    D_800D63F8[i].unk_04 = -1;
    D_800D63F8[i].unk_06 = 0;
    D_800D63F8[i].unk_08 = -0x8000;

    if (arg0[0].unk_00 != NULL) {
        D_800D63F8[i].unk_0C = func_i2_800AE17C(arg0[0].unk_00, 1, true);
    }

    D_800D63F8[i].unk_10 = (arg0[1].unk_00 != NULL) ? func_i2_800AE17C(arg0[1].unk_00, 1, true)
                                                    : func_i2_800AE17C(arg0[0].unk_00, 1, true);
    D_800D63F8[i].unk_0A = 0;
    return i;
}

void func_i2_800AFB1C(s32 arg0, s32 arg1, unk_800792D8* arg2) {
    unk_800E3F28* sp1C;
    s32 temp_a3;

    D_800D63F8[arg0].unk_04 = arg1;
    D_800D63F8[arg0].unk_00 = arg2;
    // FAKE
    D_800D63F8[arg0].unk_06 = (arg2 + arg1)->unk_04;
    temp_a3 = arg2[D_800D63F8[arg0].unk_04].unk_00;

    if (D_800D63F8[arg0].unk_0A != 0) {
        func_i2_800AF7B0(temp_a3, D_800D63F8[arg0].unk_0C);
        D_800D63F8[arg0].unk_0A = 0;
    } else {
        func_i2_800AF7B0(temp_a3, D_800D63F8[arg0].unk_10);
        D_800D63F8[arg0].unk_0A = 1;
    }
}

void Object_ClearAll(void) {
    s32 i;

    for (i = 0; i < 32; i++) {
        gObjects[i].cmdId = OBJECT_FREE;
    }
}

void Object_Init(s32 cmdId, s32 left, s32 top, s8 priority) {
    s32 i = 0;
    Object* object = gObjects;

    while (true) {
        if (object->cmdId == OBJECT_FREE) {
            break;
        }
        if (++i > ARRAY_COUNT(gObjects)) {
            return;
        }
        object++;
    }

    object->cmdId = cmdId;
    object->state = 0;
    object->state2 = 0;
    object->left = left;
    object->top = top;
    object->priority = priority;
    object->shouldDraw = true;
    object->counter = 0;
    object->counter2 = 0;

    switch (cmdId) {
        case OBJECT_TITLE_BACKGROUND:
            Title_BackgroundInit(object);
            break;
        case OBJECT_14:
            func_i4_80074708();
            break;
        case OBJECT_TITLE_LOGO:
            Title_LogoInit(object);
            break;
        case OBJECT_16:
            func_i4_80074778();
            break;
        case OBJECT_TITLE_PUSH_START:
            Title_StartInit(object);
            break;
        case OBJECT_18:
            func_i4_8007483C();
            break;
        case OBJECT_TITLE_COPYRIGHT:
            Title_CopyrightInit();
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            Title_DiskDriveInit(object);
            break;
        case OBJECT_21:
            func_i4_800748F4();
            break;
        case OBJECT_MACHINE_SELECT_HEADER:
            MachineSelect_HeaderInit();
            break;
        case OBJECT_32:
            func_i4_80070288(object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            MachineSettings_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            MachineSelect_PortraitInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            MachineSelect_CursorNumInit(object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            MachineSelect_CursorInit();
            break;
        case OBJECT_MACHINE_SELECT_MACHINE:
            MachineSelect_MachineInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_MACHINE:
            MachineSettings_MachineInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            MachineSettings_EngineWeightInit();
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            MachineSettings_StatsInit();
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            MachineSettings_NameCardInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            MachineSettings_SliderInit();
            break;
        case OBJECT_MACHINE_SELECT_OK:
            MachineSelect_OkInit(object);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            MachineSettings_OkInit(object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            MachineSelect_DifficultyCupsInit(object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            MachineSelect_StatsInit();
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            MainMenu_BackgroundInit(object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            MainMenu_SignInit(object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            MainMenu_HeaderInit(object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            MainMenu_NumPlayersInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            MainMenu_DifficultyInit();
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            MainMenu_TimeAttackModeInit();
            break;
        case OBJECT_MAIN_MENU_OK:
            MainMenu_OkInit(object);
            break;
        case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
            MainMenu_UnlockEverythingInit(object);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            CourseSelect_BackgroundInit(object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            CourseSelect_ModelInit();
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
        case OBJECT_COURSE_SELECT_CUP_6:
        case OBJECT_COURSE_SELECT_CUP_7:
            CourseSelect_CupInit(object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            CourseSelect_HeaderInit(object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            CourseSelect_OkInit(object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            CourseSelect_ArrowsInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            CourseSelect_GhostMarkerInit(object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            CourseSelect_GhostOptionInit(object);
            break;
        case OBJECT_170:
            func_xk3_80133B4C(object);
            break;
        case OBJECT_171:
            func_xk3_80133B84();
            break;
        case OBJECT_172:
            func_xk3_80133BD4(object);
            break;
        case OBJECT_173:
            func_xk3_80133F40();
            break;
        case OBJECT_174:
            func_xk3_8012F5F0(object);
            break;
        default:
            break;
    }
}

Gfx* Object_Draw(Gfx* gfx, Object* object) {

    if (!object->shouldDraw) {
        return gfx;
    }

    switch (object->cmdId) {
        case OBJECT_FREE:
            break;
        case OBJECT_FRAMEBUFFER:
            gfx = func_8070A3D8(gfx);
            gfx = func_8070A6C0(gfx);
            gfx = func_8070A3F4(gfx);
            break;
        case OBJECT_TITLE_BACKGROUND:
            gfx = Title_BackgroundDraw(gfx, object);
            break;
        case OBJECT_14:
            gfx = func_i4_80074A20(gfx, object);
            break;
        case OBJECT_12:
            gfx = func_8070A790(gfx, 118, 164, 203, 217, 255, 255, 255, 48);
            break;
        case OBJECT_13:
            gfx = func_8070A6DC(gfx, 12, 8, 307, 231, 0, 0, 0, 0);
            break;
        case OBJECT_TITLE_LOGO:
            gfx = Title_LogoDraw(gfx, object);
            break;
        case OBJECT_16:
            gfx = func_i4_80074A84(gfx, object);
            break;
        case OBJECT_TITLE_PUSH_START:
            gfx = Title_StartDraw(gfx, object);
            break;
        case OBJECT_18:
            gfx = func_i4_80074CC4(gfx, object);
            break;
        case OBJECT_TITLE_COPYRIGHT:
            gfx = Title_CopyrightDraw(gfx, object);
            break;
        case OBJECT_TITLE_DISK_DRIVE:
            gfx = Title_DiskDriveDraw(gfx, object);
            break;
        case OBJECT_21:
            gfx = func_i4_80074EE0(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_BACKGROUND:
            gfx = MachineSelect_BackgroundDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_BACKGROUND:
            gfx = func_8070A498(gfx, 24, 24, 24);
            break;
        case OBJECT_MACHINE_SELECT_HEADER:
            gfx = MachineSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_32:
            gfx = func_i4_80071054(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
        case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
            gfx = MachineSettings_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_PORTRAIT_0:
        case OBJECT_MACHINE_SELECT_PORTRAIT_1:
        case OBJECT_MACHINE_SELECT_PORTRAIT_2:
        case OBJECT_MACHINE_SELECT_PORTRAIT_3:
            gfx = MachineSelect_PortraitDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
        case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
            gfx = MachineSelect_CursorNumDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_CURSOR:
            gfx = MachineSelect_CursorDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_MACHINE:
            gfx = MachineSelect_MachineDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_OK:
            gfx = MachineSelect_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_STATS_0:
        case OBJECT_MACHINE_SELECT_STATS_1:
        case OBJECT_MACHINE_SELECT_STATS_2:
        case OBJECT_MACHINE_SELECT_STATS_3:
            gfx = MachineSelect_StatsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_MACHINE:
            gfx = MachineSettings_MachineDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME:
            gfx = MachineSettings_NameDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_ENGINE_WEIGHT:
            gfx = MachineSettings_EngineWeightDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_STATS:
            gfx = MachineSettings_StatsDraw(gfx, object);
            break;
        case OBJECT_58:
            gfx = func_i4_800729D8(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_NAME_CARD:
            gfx = MachineSettings_NameCardDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SLIDER:
            gfx = MachineSettings_SliderDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SETTINGS_SPLITSCREEN_BARS:
            gfx = MachineSettings_SplitscreenDraw(gfx);
            break;
        case OBJECT_MACHINE_SETTINGS_OK:
            gfx = MachineSettings_OkDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_DIFFICULTY_CUPS:
            gfx = MachineSelect_DifficultyCupsDraw(gfx, object);
            break;
        case OBJECT_MACHINE_SELECT_NAME:
            gfx = MachineSelect_NameDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_BACKGROUND:
            gfx = MainMenu_BackgroundDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_MODE_SIGN_0:
        case OBJECT_MAIN_MENU_MODE_SIGN_1:
        case OBJECT_MAIN_MENU_MODE_SIGN_2:
        case OBJECT_MAIN_MENU_MODE_SIGN_3:
        case OBJECT_MAIN_MENU_MODE_SIGN_4:
        case OBJECT_MAIN_MENU_MODE_SIGN_5:
        case OBJECT_MAIN_MENU_MODE_SIGN_6:
        case OBJECT_MAIN_MENU_MODE_SIGN_7:
            gfx = MainMenu_SignDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_HEADER:
            gfx = MainMenu_HeaderDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_NUM_PLAYERS:
            gfx = MainMenu_NumPlayersDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_DIFFICULTY:
            gfx = MainMenu_DifficultyDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_SELECT_TIME_ATTACK_MODE:
            gfx = MainMenu_TimeAttackModeDraw(gfx, object);
            break;
        case OBJECT_MAIN_MENU_OK:
            gfx = MainMenu_OkDraw(gfx, object);
            break;
        case OBJECT_100:
        case OBJECT_140:
            gfx = func_8070A498(gfx, 0, 0, 0);
            break;
        case OBJECT_COURSE_SELECT_BACKGROUND:
            gfx = CourseSelect_BackgroundDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_MODEL:
            gfx = CourseSelect_ModelDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_CUP_0:
        case OBJECT_COURSE_SELECT_CUP_1:
        case OBJECT_COURSE_SELECT_CUP_2:
        case OBJECT_COURSE_SELECT_CUP_3:
        case OBJECT_COURSE_SELECT_CUP_4:
        case OBJECT_COURSE_SELECT_CUP_5:
        case OBJECT_COURSE_SELECT_CUP_6:
        case OBJECT_COURSE_SELECT_CUP_7:
            gfx = CourseSelect_CupDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_HEADER:
            gfx = CourseSelect_HeaderDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_OK:
            gfx = CourseSelect_OkDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_ARROWS:
            gfx = CourseSelect_ArrowsDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_NAME:
            gfx = CourseSelect_NameDraw(gfx);
            break;
        case OBJECT_COURSE_SELECT_GHOST_MARKER:
            gfx = CourseSelect_GhostMarkerDraw(gfx, object);
            break;
        case OBJECT_COURSE_SELECT_GHOST_OPTION:
            gfx = CourseSelect_GhostOptionDraw(gfx, object);
            break;
        case OBJECT_170:
            gfx = func_xk3_80133F6C(gfx, object);
            break;
        case OBJECT_171:
            gfx = func_xk3_801340DC(gfx, object);
            break;
        case OBJECT_172:
            gfx = func_xk3_80134408(gfx, object);
            break;
        case OBJECT_173:
            gfx = func_xk3_80134854(gfx, object);
            break;
        case OBJECT_174:
            gfx = func_xk3_8012F628(gfx, object);
            break;
    }
    return gfx;
}

Gfx* Object_UpdateAndDrawAll(Gfx* gfx) {
    s32 i;
    s32 j;

    for (i = 0; i < 32; i++) {
        switch (gObjects[i].cmdId) {
            case OBJECT_FREE:
                break;
            case OBJECT_TITLE_BACKGROUND:
                Title_BackgroundUpdate(&gObjects[i]);
                break;
            case OBJECT_TITLE_DISK_DRIVE:
                Title_DiskDriveUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_OK:
                MainMenu_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MAIN_MENU_UNLOCK_EVERYTHING:
                MainMenu_UnlockEverythingUpdate(&gObjects[i]);
                break;
            case OBJECT_32:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                func_i4_800732A0(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_0:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_1:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_2:
            case OBJECT_MACHINE_SETTINGS_PORTRAIT_3:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSettings_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_PORTRAIT_0:
            case OBJECT_MACHINE_SELECT_PORTRAIT_1:
            case OBJECT_MACHINE_SELECT_PORTRAIT_2:
            case OBJECT_MACHINE_SELECT_PORTRAIT_3:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSelect_PortraitUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_0:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_1:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_2:
            case OBJECT_MACHINE_SELECT_CURSOR_NUM_3:
                MachineSelect_CursorNumUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_CURSOR:
                MachineSelect_CursorUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_MACHINE:
                MachineSelect_MachineUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_MACHINE:
                MachineSettings_MachineUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_NAME_CARD:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                MachineSettings_NameCardUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SELECT_OK:
                MachineSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_MACHINE_SETTINGS_OK:
                MachineSettings_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_MODEL:
                CourseSelect_ModelUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_CUP_0:
            case OBJECT_COURSE_SELECT_CUP_1:
            case OBJECT_COURSE_SELECT_CUP_2:
            case OBJECT_COURSE_SELECT_CUP_3:
            case OBJECT_COURSE_SELECT_CUP_4:
            case OBJECT_COURSE_SELECT_CUP_5:
            case OBJECT_COURSE_SELECT_CUP_6:
            case OBJECT_COURSE_SELECT_CUP_7:
                CourseSelect_CupUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_OK:
                CourseSelect_OkUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_ARROWS:
                CourseSelect_ArrowsUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_MARKER:
                CourseSelect_GhostMarkerUpdate(&gObjects[i]);
                break;
            case OBJECT_COURSE_SELECT_GHOST_OPTION:
                CourseSelect_GhostOptionUpdate(&gObjects[i]);
                break;
            case OBJECT_170:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                func_xk3_80134A48(&gObjects[i]);
                break;
            case OBJECT_172:
                func_xk3_80134B04(&gObjects[i]);
                break;
            case OBJECT_174:
                D_800D63F8[OBJECT_CACHE_INDEX(&gObjects[i])].unk_04 = 0;
                func_xk3_8012F6A8(&gObjects[i]);
                break;
        }
    }

    for (j = 0; j < 16; j++) {
        for (i = 0; i < 32; i++) {
            if (j == gObjects[i].priority) {
                gfx = Object_Draw(gfx, &gObjects[i]);
            }
        }
    }

    return gfx;
}

Object* Object_Get(s32 cmdId) {
    Object* object;

    object = gObjects;

    while (true) {
        if (cmdId == object->cmdId) {
            break;
        }
        object++;
        //! @bug this allows for an iteration out of the bounds of the array
        if (object > &gObjects[ARRAY_COUNT(gObjects)]) {
            return NULL;
        }
    }
    return object;
}

extern s32 gGameMode;

void func_i2_800B079C(void) {
    func_i2_800AE170();
    Object_ClearAll();
    func_i2_800AF9C8();
    func_i2_800AF78C();
    if (gGameMode != GAMEMODE_CREATE_MACHINE) {
        func_8070DD88();
    }
}

void func_i2_800B07F0(void) {
    Object_ClearAll();
    func_i2_800AF9C8();
    func_i2_800AF78C();
    func_8070DD88();
}

void Object_LerpPosXToTarget(Object* object, s32 target, s32 stepScale) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= stepScale;
            if (++step > 8) {
                step = 8;
            }
        } else {
            step /= stepScale;
            if (--step < -8) {
                step = -8;
            }
        }
    }
    OBJECT_LEFT(object) += step;
}

void Object_LerpPosYToTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpToPos(Object* object, s32 xTarget, s32 yTarget) {
    Object_LerpPosXToTarget(object, xTarget, 4);
    Object_LerpPosYToTarget(object, yTarget);
}

void Object_LerpPosXToClampedTargetMaxStep(Object* object, s32 target, s32 maxStep) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (maxStep < ++step) {
                step = maxStep;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -maxStep) {
                step = -maxStep;
            }
            if (step > -8) {
                step = -8;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpPosYToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 192) {
                step = 192;
            }
            if (step < 8) {
                step = 8;
            }
            OBJECT_TOP(object) += step;

            if (target < OBJECT_TOP(object)) {
                OBJECT_TOP(object) = target;
            }
        } else {
            step /= 4;
            if (--step < -192) {
                step = -192;
            }
            if (step >= -7) {
                step = -8;
            }
            OBJECT_TOP(object) += step;

            if (OBJECT_TOP(object) < target) {
                OBJECT_TOP(object) = target;
            }
        }
    }
}

// Duplicate function
void Object_LerpPosYToTarget2(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_TOP(object);
    if (step != 0) {
        if (step > 0) {
            step /= 4;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 4;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) += step;
}

void Object_LerpPosXToClampedTarget(Object* object, s32 target) {
    s32 step;

    step = target - OBJECT_LEFT(object);
    if (step != 0) {
        step = 200 / step;
        if (step > 0) {
            if (step > 24) {
                step = 24;
            }
            if (step < 16) {
                step = 16;
            }
            OBJECT_LEFT(object) += step;

            if (target < OBJECT_LEFT(object)) {
                OBJECT_LEFT(object) = target;
            }
        } else {
            if (step < -24) {
                step = -24;
            }
            if (step > -16) {
                step = -16;
            }
            OBJECT_LEFT(object) += step;

            if (OBJECT_LEFT(object) < target) {
                OBJECT_LEFT(object) = target;
            }
        }
    }
}

void Object_LerpAwayFromPosX(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_LEFT(object);
    s32 step;

    step = origin - OBJECT_LEFT(object);
    if (origin == OBJECT_LEFT(object)) {
        OBJECT_LEFT(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_LEFT(object) -= step;
}

void Object_LerpAwayFromPosY(Object* object, s32 origin, s32 initialStep) {
    UNUSED s32 temp = OBJECT_TOP(object);
    s32 step;

    step = origin - OBJECT_TOP(object);
    if (origin == OBJECT_TOP(object)) {
        OBJECT_TOP(object) += initialStep;
        return;
    }
    if (step != 0) {
        if (step > 0) {
            step /= 8;
            if (++step > 16) {
                step = 16;
            }
        } else {
            step /= 8;
            if (--step < -16) {
                step = -16;
            }
        }
    }
    OBJECT_TOP(object) -= step;
}
