#include "global.h"
#include "ovl_i4.h"
#include "fzx_game.h"
#include "fzx_object.h"
#include "fzx_course.h"
#include "fzx_assets.h"
#include "assets/overlays/ovl_i4/title.h"

s32 D_i4_80077070;
s32 D_i4_80077074;

UNUSED s32 D_i4_80076690 = 0;
#include "src/assets/overlays/ovl_i4/title/title.c"

static unk_80077D50 sTitleBackgroundMainCompTexInfo[] = {
    { 17, aTitleBackgroundMainTex, TEX_WIDTH(aTitleBackgroundMainTex), TEX_HEIGHT(aTitleBackgroundMainTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundMainTex) }
};
static unk_80077D50 sTitleBackgroundComicCompTexInfo[] = {
    { 17, aTitleBackgroundComicTex, TEX_WIDTH(aTitleBackgroundComicTex), TEX_HEIGHT(aTitleBackgroundComicTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundComicTex) }
};
static unk_80077D50 sTitleBackgroundFalconCompTexInfo[] = {
    { 17, aTitleBackgroundFalconTex, TEX_WIDTH(aTitleBackgroundFalconTex), TEX_HEIGHT(aTitleBackgroundFalconTex),
      TEX_COMPRESSED_SIZE(aTitleBackgroundFalconTex) }
};

static unk_80077D50* sTitleBackgroundCompTexInfos[] = {
    sTitleBackgroundMainCompTexInfo,
    sTitleBackgroundComicCompTexInfo,
    sTitleBackgroundFalconCompTexInfo,
};

unk_80077D50 sTitleLogoCompTexInfo[] = { { 18, aTitleLogoTex, TEX_WIDTH(aTitleLogoTex), TEX_HEIGHT(aTitleLogoTex),
                                           TEX_COMPRESSED_SIZE(aTitleLogoTex) } };
unk_80077D50 sTitlePushStartCompTexInfo[] = { { 18, aTitlePushStartTex, TEX_WIDTH(aTitlePushStartTex),
                                                TEX_HEIGHT(aTitlePushStartTex),
                                                TEX_COMPRESSED_SIZE(aTitlePushStartTex) } };
unk_80077D50 sTitleNoControllerCompTexInfo[] = { { 20, aTitleNoControllerTex, TEX_WIDTH(aTitleNoControllerTex),
                                                   TEX_HEIGHT(aTitleNoControllerTex),
                                                   TEX_COMPRESSED_SIZE(aTitleNoControllerTex) } };
unk_80077D50 sTitleExpansionPakWarningCompTexInfo[] = {
    { 20, aTitleExpansionPakWarningTex, TEX_WIDTH(aTitleExpansionPakWarningTex),
      TEX_HEIGHT(aTitleExpansionPakWarningTex), TEX_COMPRESSED_SIZE(aTitleExpansionPakWarningTex) }
};
unk_80077D50 sTitleDiskWarningCompTexInfo[] = { { 20, aTitleDiskWarningTex, TEX_WIDTH(aTitleDiskWarningTex),
                                                  TEX_HEIGHT(aTitleDiskWarningTex),
                                                  TEX_COMPRESSED_SIZE(aTitleDiskWarningTex) } };

unk_80077D50* sTitleWarningCompTexInfos[] = {
    sTitleNoControllerCompTexInfo,
    sTitleExpansionPakWarningCompTexInfo,
    sTitleDiskWarningCompTexInfo,
};

unk_80077D50 sCopyrightCompTexInfo[] = { { 17, aCopyrightDDTex, TEX_WIDTH(aCopyrightDDTex), TEX_HEIGHT(aCopyrightDDTex),
                                           TEX_COMPRESSED_SIZE(aCopyrightDDTex) },
                                         { 0 } };

//! @bug Compressed size listed does not match the actual compressed texture size
unk_80077D50 sN64DDLogoCompTexInfo[] = {
    { 17, aN64DDLogoTex, TEX_WIDTH(aN64DDLogoTex), TEX_HEIGHT(aN64DDLogoTex), 0x2E7 }, { 0 }
};

UNUSED s32 D_i4_80076F08[] = { 85, 21, 120, 150 };

s32 D_i4_80076F18 = 0;

void func_i4_80073F50(u16* arg0) {
}

void func_i4_80073F58(u16* texture) {
    s32 column;
    s32 pixel;
    s32 pixelIndex;
    s32 nextPixelIndex;

    column = (Math_Rand1() >> 3) % 304;
    pixelIndex = (((Math_Rand1() >> 4) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 1) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;
    nextPixelIndex = (pixelIndex + 304) % (304 * 240);

    pixel = texture[pixelIndex];
    texture[pixelIndex] = texture[nextPixelIndex];
    texture[nextPixelIndex] = pixel;
}

void func_i4_8007407C(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 4) % 304;
    pixelIndex = (((Math_Rand1() >> 5) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 6) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    if (texture[pixelIndex] < *srcPixel) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_800741C8(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 fakeVar;
    u16* srcPixel;

    column = (Math_Rand1() >> 5) % 304;
    pixelIndex = (((Math_Rand1() >> 6) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 7) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    // FAKE
    fakeVar = texture[pixelIndex];

    if (*srcPixel - texture[pixelIndex] < 0) {
        texture[pixelIndex] = *srcPixel;
    }
}

void func_i4_80074314(u16* texture) {
    u32 column;
    s32 pad;
    u32 pixelIndex;
    s32 pad2;
    u16* srcPixel;

    column = (Math_Rand1() >> 6) % 304;
    pixelIndex = (((Math_Rand1() >> 7) % 240) * 304) + column;

    srcPixel = (u16*) texture + pixelIndex;

    switch ((Math_Rand1() >> 8) % 4) {
        case 0:
            pixelIndex = (pixelIndex + 1) % (304 * 240);
            break;
        case 1:
            pixelIndex = (pixelIndex - 1) % (304 * 240);
            break;
        case 2:
            pixelIndex = (pixelIndex + 304) % (304 * 240);
            break;
        case 3:
            pixelIndex = (pixelIndex - 304) % (304 * 240);
            break;
    }

    texture[pixelIndex] = *srcPixel;
}

extern s16 D_8076C7A8;
extern s32 D_8079A32C;
extern s32 gCourseIndex;

void Title_Init(void) {
    D_8076C7A8 = 3;
    D_i4_80076F18 = 1;
    gCourseIndex = COURSE_MUTE_CITY;
    D_i4_80077070 = 0;
    D_i4_80077074 = 0;
    Object_Init(OBJECT_FRAMEBUFFER, 0, 0, 1);
    Object_Init(OBJECT_TITLE_BACKGROUND, 0, 0, 8);
    Object_Init(OBJECT_TITLE_LOGO, 0, 0, 10);
    Object_Init(OBJECT_21, 130, 181, 12);
    Object_Init(OBJECT_TITLE_PUSH_START, 0, 0, 12);
    Object_Init(OBJECT_TITLE_COPYRIGHT, 78, 200, 12);
    if (D_8079A32C != 0) {
        Object_Init(OBJECT_TITLE_DISK_DRIVE, 0, 0, 12);
    }
}

extern s16 D_8076C810;
extern s32 gControllersConnected;
extern s32 gGameMode;
extern u16 gInputButtonPressed;

s32 Title_Update(void) {

    if (gControllersConnected == 0) {
        return gGameMode;
    }
    Controller_SetGlobalInputs(&gSharedController);
    Math_Rand1();
    if ((D_8079A32C != 0) && (OBJECT_COUNTER(Object_Get(OBJECT_TITLE_DISK_DRIVE)) != 0) &&
        (OBJECT_STATE(Object_Get(OBJECT_TITLE_DISK_DRIVE)) == 0)) {
        return gGameMode;
    }
    if (D_i4_80077074 != 0) {
        return gGameMode;
    }

    if (D_i4_80077070 < 0) {
        return gGameMode;
    }

    D_i4_80077070++;
    if (D_i4_80077070 < 80) {
        return gGameMode;
    }

    if ((D_8076C810 == 0) && (gInputButtonPressed & (BTN_A | BTN_START))) {
        func_8074122C(0x3E);
        func_8070DAFC();
        func_80741BD4(0xF);
        D_i4_80077070 = -1;
        if ((D_8079A32C != 0) && (OBJECT_STATE(Object_Get(OBJECT_TITLE_DISK_DRIVE)) == 1)) {
            func_807423C4();
        }
        return GAMEMODE_FLX_MAIN_MENU;
    } else {
        return GAMEMODE_FLX_TITLE;
    }
}

Gfx* Title_Draw(Gfx* gfx) {
    return Object_UpdateAndDrawAll(gfx);
}

extern s8 D_8076CC94;

void Title_BackgroundInit(Object* backgroundObj) {
    OBJECT_STATE(backgroundObj) = D_8076CC94;
    func_i2_800AE17C(sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)], 0, true);
    if (OBJECT_STATE(backgroundObj) == 0) {
        OBJECT_LEFT(backgroundObj) = 8;
    }
}

void func_i4_80074708(void) {
}

void Title_LogoInit(Object* logoObj) {
    OBJECT_STATE(logoObj) = D_8076CC94;
    OBJECT_LEFT(logoObj) = 0x55;

    switch (OBJECT_STATE(logoObj)) {
        case 0:
        case 2:
            OBJECT_TOP(logoObj) = 0x15;
            break;
        case 1:
            OBJECT_TOP(logoObj) = 0x30;
            break;
    }

    func_i2_800AE17C(sTitleLogoCompTexInfo, 0, true);
}

void func_i4_80074778(void) {
}

void Title_StartInit(Object* startObj) {

    OBJECT_STATE(startObj) = D_8076CC94;
    func_i2_800AE17C(sTitleNoControllerCompTexInfo, 0, true);
    if (gControllersConnected != 0) {
        func_i2_800AE17C(sTitlePushStartCompTexInfo, 0, true);
        OBJECT_LEFT(startObj) = 120;
        switch (OBJECT_STATE(startObj)) {
            case 0:
                OBJECT_TOP(startObj) = 150;
                return;
            case 1:
            case 2:
                OBJECT_LEFT(startObj) += 70;
                OBJECT_TOP(startObj) = 171;
                break;
        }
    }
}

void func_i4_8007483C(void) {
}

void Title_CopyrightInit(void) {
    func_i2_800AE578(sCopyrightCompTexInfo, false);
}

extern s32 gRamDDCompatible;

void Title_DiskDriveInit(Object* diskDriveObj) {
    s32 var_v0;

    OBJECT_LEFT(diskDriveObj) = 80;

    switch (D_8076CC94) {
        case 0:
        case 2:
            OBJECT_TOP(diskDriveObj) = 100;
            break;
        case 1:
            OBJECT_TOP(diskDriveObj) = 120;
            break;
    }

    if (!gRamDDCompatible) {
        var_v0 = 1;
    } else {
        var_v0 = 2;
    }

    func_i2_800AE17C(sTitleWarningCompTexInfos[var_v0], 0, true);
}

void func_i4_800748F4(void) {
    func_i2_800AE578(sN64DDLogoCompTexInfo, 0);
}

void (*sTitleBackgroundEffectFuncs[])(u16*) = {
    func_i4_80073F50, func_i4_80073F50, func_i4_80073F58, func_i4_8007407C, func_i4_800741C8, func_i4_80074314,
};

void Title_BackgroundUpdate(Object* backgroundObj) {
    void (*backgroundEffect)(u16*);
    s32 i;
    u16* backgroundTexture;

    if (D_i4_80076F18 == 0) {
        OBJECT_STATE(backgroundObj)++;
        if (OBJECT_STATE(backgroundObj) > 5) {
            OBJECT_STATE(backgroundObj) = 1;
        }
        backgroundEffect = sTitleBackgroundEffectFuncs[OBJECT_STATE(backgroundObj)];
    } else {
        backgroundEffect = sTitleBackgroundEffectFuncs[D_i4_80076F18];
    }

    backgroundTexture = func_i2_800AEA90(aTitleBackgroundMainTex);

    for (i = 1999; i > 0; i--) {
        backgroundEffect(backgroundTexture);
    }
}

Gfx* Title_BackgroundDraw(Gfx* gfx, Object* backgroundObj) {
    return func_i2_800AF584(gfx, sTitleBackgroundCompTexInfos[OBJECT_STATE(backgroundObj)], OBJECT_LEFT(backgroundObj),
                            OBJECT_TOP(backgroundObj), 0, 0, 0, 1.0f, 1.0f, true);
}

Gfx* func_i4_80074A20(Gfx* gfx, Object* arg1) {
    return gfx;
}

Gfx* Title_LogoDraw(Gfx* gfx, Object* logoObj) {
    return func_i2_800AF584(gfx, sTitleLogoCompTexInfo, OBJECT_LEFT(logoObj), OBJECT_TOP(logoObj), 0, 0, 0, 1.0f, 1.0f,
                            true);
}

Gfx* func_i4_80074A84(Gfx* gfx, Object* arg1) {
    return gfx;
}

extern u32 gGameFrameCount;

Gfx* Title_StartDraw(Gfx* gfx, Object* startObj) {
    s32 var_v1;

    if (gControllersConnected != 0) {
        if ((D_i4_80077070 < 95) && (D_i4_80077070 >= 0)) {
            return gfx;
        }
        gfx = func_8070D4A8(gfx, 0);
        gfx = func_i2_800AF584(gfx, sTitlePushStartCompTexInfo, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), 1, 0, 0,
                               1.0f, 1.0f, true);
    } else {
        OBJECT_LEFT(startObj) = 80;

        switch (OBJECT_STATE(startObj)) {
            case 0:
            case 2:
                OBJECT_TOP(startObj) = 150;
                break;
            case 1:
                OBJECT_TOP(startObj) = 162;
                break;
        }

        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_80709C90(gfx, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), OBJECT_LEFT(startObj) + 160,
                            OBJECT_TOP(startObj) + 32, (s32) (var_v1 * 40) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((40 - var_v1) * 255) / 40, 0, 0, 255);
        }

        gfx = func_i2_800AF584(gfx, sTitleNoControllerCompTexInfo, OBJECT_LEFT(startObj), OBJECT_TOP(startObj), 0, 0, 0,
                               1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* func_i4_80074CC4(Gfx* gfx, Object* arg1) {
    return gfx;
}

Gfx* Title_CopyrightDraw(Gfx* gfx, Object* copyrightObj) {
    return func_i2_800AF584(gfx, sCopyrightCompTexInfo, OBJECT_LEFT(copyrightObj), OBJECT_TOP(copyrightObj), 0, 0, 0,
                            1.0f, 1.0f, true);
}

Gfx* Title_DiskDriveDraw(Gfx* gfx, Object* diskDriveObj) {
    s32 var_t0;
    s32 var_v1;

    var_t0 = 0;
    if (!gRamDDCompatible) {
        var_t0 = 1;
    } else if (OBJECT_STATE(diskDriveObj) != 0) {
        var_t0 = 2;
    }

    if (var_t0 != 0) {
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            var_v1 = 90 - var_v1;
        } else {
            var_v1 = 30 - var_v1;
        }

        gfx = func_80709C90(gfx, OBJECT_LEFT(diskDriveObj), OBJECT_TOP(diskDriveObj), OBJECT_LEFT(diskDriveObj) + 160,
                            OBJECT_TOP(diskDriveObj) + 32, (s32) (var_v1 * 40) / 60, 0, 0, 0xF0);
        var_v1 = gGameFrameCount % 60;
        if (var_v1 > 30) {
            gDPSetPrimColor(gfx++, 0, 0, 255, 0, 0, 255);
        } else {
            gDPSetPrimColor(gfx++, 0, 0, ((40 - var_v1) * 255) / 40, 0, 0, 255);
        }
        gfx = func_i2_800AF584(gfx, sTitleWarningCompTexInfos[var_t0], OBJECT_LEFT(diskDriveObj),
                               OBJECT_TOP(diskDriveObj), 0, 0, 0, 1.0f, 1.0f, true);
    }
    return gfx;
}

Gfx* func_i4_80074EE0(Gfx* gfx, Object* arg1) {
    return func_i2_800AF584(gfx, sN64DDLogoCompTexInfo, OBJECT_LEFT(arg1), OBJECT_TOP(arg1), 0, 0, 0, 1.0f, 1.0f,
                            false);
}

extern s8 D_8076C7D8;

void Title_DiskDriveUpdate(Object* arg0) {
    if (gRamDDCompatible != 0 && (D_i4_80077070 != -1) && (D_8076C7D8 == 0)) {}
}
