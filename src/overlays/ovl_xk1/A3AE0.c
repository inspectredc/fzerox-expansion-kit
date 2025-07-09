#include "global.h"
#include "fzx_segmentA.h"
#include "assets/segment_1FB850.h"
#include "assets/segment_21C170.h"
#include "assets/overlays/ovl_xk1/aA3AE0.h"
#include "assets/overlays/machine_create/machine_create_assets.h"

extern s32 D_80119890;

extern u16 D_4001B00[];
extern u16 D_4001D40[];
extern u16 D_4001F80[];
extern u16 D_40021C0[];
extern u16 D_4002400[];
extern u16 D_4002640[];
extern u16 D_4002880[];
extern u16 D_4002AC0[];
extern u16 D_4002D00[];
extern u16 D_4002F40[];
extern u16 D_4003180[];
extern u16 D_40033C0[];
extern u16 D_4003600[];
extern u16 D_4000D80[];
extern u16 D_4000F00[];
extern u16 D_4001080[];
extern u16 D_4001200[];
extern u16 D_4000A80[];
extern u16 D_4000C00[];
extern u16 D_4001500[];
extern u16 D_4001800[];
extern u16 D_4001980[];
extern u16 aCreateMachinePartsTex[];
extern u16 aCreateMachineDesignTex[];
extern u16 aCreateMachineSettingsTex[];

s32 D_xk1_8003A550;
s32 D_xk1_8003A554;

#include "src/assets/overlays/ovl_xk1/aA3AE0/aA3AE0.c"

s32 D_xk1_800305F0 = 1;
s32 D_xk1_800305F4 = -1;
s32 D_xk1_800305F8 = 0;
s32 D_xk1_800305FC = 0;
s32 D_xk1_80030600 = 0;
s32 D_xk1_80030604 = 8;
s32 D_xk1_80030608 = 500;
s32 D_xk1_8003060C = 0;
s32 D_xk1_80030610 = -1;
s32 D_xk1_80030614 = 0;
s32 D_xk1_80030618 = 0;
s32 D_xk1_8003061C = 0;
s32 D_xk1_80030620 = 0;
s32 D_xk1_80030624 = 0;
s32 D_xk1_80030628 = 0;
s32 D_xk1_8003062C = 0;
s32 D_xk1_80030630 = 0;
s32 D_xk1_80030634 = 0;
s32 D_xk1_80030638 = 0;
s32 D_xk1_8003063C = 0;
s32 D_xk1_80030640 = 0;
s32 D_xk1_80030644 = 0;
s32 D_xk1_80030648 = 0;
s32 D_xk1_8003064C = 0;
s32 D_xk1_80030650 = 0;
s32 D_xk1_80030654 = 0;
s32 D_xk1_80030658 = 0;
s32 D_xk1_8003065C = 0;
s32 D_xk1_80030660 = 0;
s32 D_xk1_80030664 = 0;
s32 D_xk1_80030668 = 0;
s32 D_xk1_8003066C = 0;
s32 D_xk1_80030670 = 0;
s32 D_xk1_80030674 = 0;
s32 D_xk1_80030678 = -1;
s32* D_xk1_8003067C[] = {
    &D_xk1_80030614, &D_xk1_8003061C, NULL, &D_xk1_80030610, &D_xk1_80030678,
};

MenuDropItem D_xk1_80030690[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900D408, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900D648, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900D888, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900DAC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030744 = { 5, -1, -1, 120, 36, 0, 16, D_xk1_80030690, 160, 48, 160, 112, &D_xk1_80030648 };

MenuDropItem D_xk1_80030778[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900DD08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900DF48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900E188, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030808 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_80030778, 160, 48, 160, 96, &D_xk1_8003064C };

MenuDropItem D_xk1_8003083C[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900E3C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900E608, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900E848, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900EA88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_800308F0 = { 5, -1, -1, 120, 36, 0, 16, D_xk1_8003083C, 160, 48, 160, 112, &D_xk1_80030650 };

MenuDropItem D_xk1_80030924[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900ECC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900EF08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900F148, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900F388, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_800309D8 = { 5, -1, -1, 120, 36, 0, 16, D_xk1_80030924, 160, 48, 160, 112, &D_xk1_80030654 };

MenuDropItem D_xk1_80030A0C[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900F5C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900F808, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900FA48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030A9C = { 4, -1, -1, 120, 36, 0, 16, D_xk1_80030A0C, 160, 48, 160, 96, &D_xk1_80030658 };

MenuDropItem D_xk1_80030AD0[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900FC88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900FEC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_9010108, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030B60 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_80030AD0, 160, 48, 160, 96, &D_xk1_8003065C };

MenuDropItem D_xk1_80030B94[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_9010348, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_9010588, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_90107C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030C24 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_80030B94, 160, 48, 160, 96, &D_xk1_80030660 };

MenuDropItem D_xk1_80030C58[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_9010A08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_9010C48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_9010E88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_90110C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_9011308, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu6Tex, D_9011548, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu7Tex, D_9011788, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu8Tex, D_90119C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu9Tex, D_9011C08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu10Tex, D_9011E48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu11Tex, D_9012088, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu12Tex, D_90122C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu13Tex, D_9012508, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu14Tex, D_9012748, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu15Tex, D_9012988, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030E98 = { 16, -1, -1, 120, 36, 0, 16, D_xk1_80030C58, 160, 48, 160, 288, &D_xk1_80030664 };

MenuDropItem D_xk1_80030ECC[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_9012BC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_9012E08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_9013048, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_9013288, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_90134C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80030FA4 = { 6, -1, -1, 120, 36, 0, 16, D_xk1_80030ECC, 160, 48, 160, 128, &D_xk1_80030668 };

MenuDropItem D_xk1_80030FD8[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_9009088, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_90092C8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_9009508, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_9009748, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_9009988, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu6Tex, D_9009BC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu7Tex, D_9009E08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu8Tex, D_900A048, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu9Tex, D_900A288, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu10Tex, D_900A4C8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031140 = { 10, -1, -1, 72, 36, 0, 16, D_xk1_80030FD8, 112, 48, 112, 192, &D_xk1_8003066C };

MenuDropItem D_xk1_80031174[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_9013708, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_9013948, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_9013B88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_9013DC8, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_9014008, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu6Tex, D_9014248, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu7Tex, D_9014488, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu8Tex, D_90146C8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031294 = { 8, -1, -1, 120, 36, 0, 16, D_xk1_80031174, 160, 48, 160, 160, &D_xk1_80030670 };

MenuDropItem D_xk1_800312C8[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu1Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu2Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu3Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu4Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu5Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu6Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu7Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu8Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu9Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu10Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu11Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu12Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu13Tex },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_80030470, NULL, NULL, NULL, 48, 16, NULL, aExpansionKitMenu14Tex },
};

MenuWidget D_xk1_800314C0 = { 14, -1, -1, 72, 36, 0, 16, D_xk1_800312C8, 112, 48, 112, 256, &D_xk1_80030674 };

MenuDropItem D_xk1_800314F4[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900B008, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900B248, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900B488, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900B6C8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031584 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_800314F4, 160, 48, 160, 96, &D_xk1_80030638 };

MenuDropItem D_xk1_800315B8[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900B908, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900BB48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900BD88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900BFC8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031648 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_800315B8, 160, 48, 160, 96, &D_xk1_8003063C };

MenuDropItem D_xk1_8003167C[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900C208, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900C448, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900C688, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900C8C8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_8003170C = { 4, -1, -1, 120, 36, 0, 16, D_xk1_8003167C, 160, 48, 160, 96, &D_xk1_80030640 };

MenuDropItem D_xk1_80031740[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_900CB08, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900CD48, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900CF88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_900D1C8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_800317D0 = { 4, -1, -1, 120, 36, 0, 16, D_xk1_80031740, 160, 48, 160, 96, &D_xk1_80030644 };

MenuDropItem D_xk1_80031804[] = {
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, D_701F2A0, NULL, NULL, func_xk1_80026870, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, D_701F420, NULL, NULL, func_xk1_800268A8, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, aExpansionKitMenuClearAllTex, NULL, NULL, func_xk1_800268E4, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031870 = { 3, -1, -1, 216, 36, 0, 16, D_xk1_80031804, 256, 48, 256, 80, &D_xk1_80030678 };

s32 D_xk1_800318A4 = -1;
s32 D_xk1_800318A8 = -1;
s32 D_xk1_800318AC = -1;
s32 D_xk1_800318B0 = -1;
s32 D_xk1_800318B4 = -1;
s32 D_xk1_800318B8 = -1;

MenuDropItem D_xk1_800318BC[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_4001B00, NULL, func_xk3_8013298C, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_4001D40, NULL, func_xk3_801329A4, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_4001F80, NULL, func_xk3_801329BC, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_40021C0, NULL, func_xk3_801329D4, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_4002400, NULL, func_xk3_801329EC, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031970 = { 5, -1, -1, 72, 52, 0, 16, D_xk1_800318BC, 104, 56, 104, 120, &D_xk1_800318A8 };

MenuDropItem D_xk1_800319A4[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_4002640, NULL, func_xk3_80132A80, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_4002880, NULL, func_xk3_80132A98, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_4002AC0, NULL, func_xk3_80132AB0, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_4002D00, NULL, func_xk3_80132AC8, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_4002F40, NULL, func_xk3_80132AE0, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu6Tex, D_4003180, NULL, func_xk3_80132AF8, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu7Tex, D_40033C0, NULL, func_xk3_80132B10, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu8Tex, D_4003600, NULL, func_xk3_80132B28, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031AC4 = { 8, -1, -1, 72, 52, 0, 16, D_xk1_800319A4, 104, 56, 104, 168, &D_xk1_800318AC };

MenuDropItem D_xk1_80031AF8[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4000D80, NULL, NULL, func_xk3_80132B40, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4000F00, NULL, NULL, func_xk3_80132BB0, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4001080, NULL, NULL, func_xk3_80132C20, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4001200, NULL, NULL, func_xk3_80132C90, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031B88 = { 4, -1, -1, 72, 52, 0, 16, D_xk1_80031AF8, 104, 56, 104, 104, &D_xk1_800318B0 };

MenuDropItem D_xk1_80031BBC[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4000F00, NULL, &D_xk1_80031970, func_xk3_80132910, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_4000A80, NULL, &D_xk1_80031AC4, func_xk3_80132A04, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, D_4000C00, NULL, &D_xk1_80031B88, func_xk3_801326F0, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031C28 = { 3, -1, -1, 72, 36, 0, 16, D_xk1_80031BBC, 104, 48, 104, 80, &D_xk1_800318A4 };

MenuDropItem D_xk1_80031C5C[] = {
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_4001500, NULL, NULL, func_xk3_80132828, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138B30, NULL, NULL, func_xk3_80132DDC, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_xk3_80138CB0, NULL, NULL, func_xk3_80132850, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031CC8 = { 3, -1, -1, 168, 36, 0, 16, D_xk1_80031C5C, 200, 48, 200, 80, &D_xk1_800318B4 };

MenuDropItem D_xk1_80031CFC[] = {
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, D_4001800, NULL, NULL, func_xk3_8013277C, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, D_4001980, NULL, NULL, func_xk3_801327A4, 48, 16, NULL, NULL },
    { aExpansionKitMenuPurpleBorderBackgroundTex, aExpansionKitMenuPurpleBorderHighlightBackgroundTex, aExpansionKitMenuClearAllTex, NULL, NULL, func_xk3_80132808, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031D68 = { 3, -1, -1, 216, 36, 0, 16, D_xk1_80031CFC, 248, 48, 248, 80, &D_xk1_800318B8 };

MenuDropItem D_xk1_80031D9C[] = {
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachinePartsTex, NULL, NULL, func_xk3_80132884, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachineDesignTex, NULL, &D_xk1_80031C28, func_xk3_801326D8, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, aCreateMachineSettingsTex, NULL, NULL, func_xk3_80132E84, 48, 16, NULL, NULL },
    { D_xk3_80138E30, D_xk3_80138E30, NULL, NULL, &D_xk1_80031CC8, func_xk3_801326C0, 48, 16, NULL, NULL },
    { aExpansionKitMenuEntryTex, aExpansionKitMenuEntryTex, NULL, NULL, &D_xk1_80031D68, func_xk3_80132764, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80031E50 = { 5, -1, -1, 24, 20, 48, 0, D_xk1_80031D9C, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL };

MenuDropItem D_xk1_80031E84[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_A00B000, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_A00B240, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_A00B480, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu4Tex, D_A00B6C0, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu5Tex, D_A00B900, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031F38 = { 5, -1, -1, 120, 36, 0, 16, D_xk1_80031E84, 160, 48, 160, 112, &D_xk1_8003062C };

MenuDropItem D_xk1_80031F6C[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_A00BB40, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900A708, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900A948, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80031FD8 = { 3, -1, -1, 120, 36, 0, 16, D_xk1_80031F6C, 160, 48, 160, 80, &D_xk1_80030630 };

MenuDropItem D_xk1_8003200C[] = {
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu1Tex, D_A00BD80, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu2Tex, D_900AB88, NULL, NULL, 16, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderSplitBackgroundTex, aExpansionKitMenuGoldBorderSplitHighlightBackgroundTex, aExpansionKitMenu3Tex, D_900ADC8, NULL, NULL, 16, 16, NULL, NULL },
};

MenuWidget D_xk1_80032078 = { 3, -1, -1, 120, 36, 0, 16, D_xk1_8003200C, 160, 48, 160, 80, &D_xk1_80030634 };

MenuDropItem D_xk1_800320AC[] = {
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_9003F88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_9004108, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_9004288, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, D_9004408, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuBlueBorderBackgroundTex, aExpansionKitMenuBlueBorderHighlightBackgroundTex, aExpansionKitMenuCopyTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80032160 = { 5, -1, -1, 168, 36, 0, 16, D_xk1_800320AC, 208, 48, 208, 112, &D_xk1_80030610 };

MenuDropItem D_xk1_80032194[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005188, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005308, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005488, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005608, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005788, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_xk1_800302F0, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_8003226C = { 6, -1, -1, 24, 36, 0, 16, D_xk1_80032194, 64, 48, 64, 128, &D_xk1_80030614 };

MenuDropItem D_xk1_800322A0[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005908, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005A88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005C08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_701F120, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aExpansionKitMenuClearAllTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80032354 = { 5, -1, -1, 72, 36, 0, 16, D_xk1_800322A0, 112, 48, 112, 112, &D_xk1_8003061C };

MenuDropItem D_xk1_80032388[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005D88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9005F08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006088, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006208, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006388, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, aCourseEditMenuClearTex, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006508, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80032484 = { 7, -1, -1, 72, 36, 0, 16, D_xk1_80032388, 112, 48, 112, 144, &D_xk1_80030620 };

MenuDropItem D_xk1_800324B8[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006688, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006808, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006988, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006B08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006C88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006E08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9006F88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007108, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007288, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_800325FC = { 9, -1, -1, 72, 36, 0, 16, D_xk1_800324B8, 112, 48, 112, 176, &D_xk1_80030624 };

MenuDropItem D_xk1_80032630[] = {
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007408, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007588, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007708, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007888, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007A08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007B88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007D08, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9007E88, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBorderBackgroundTex, aExpansionKitMenuGoldBorderHighlightBackgroundTex, D_9008008, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80032774 = { 9, -1, -1, 72, 36, 0, 16, D_xk1_80032630, 112, 48, 112, 176, &D_xk1_80030628 };

MenuDropItem D_xk1_800327A8[] = {
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, D_9004708, NULL, &D_xk1_8003226C, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, D_9004888, NULL, &D_xk1_80032354, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuGoldBackgroundTex, aExpansionKitMenuGoldBackgroundTex, NULL, NULL, NULL, NULL, 48, 16, NULL, NULL },
    { D_9003988, D_9003988, NULL, NULL, &D_xk1_80032160, NULL, 48, 16, NULL, NULL },
    { aExpansionKitMenuEntryTex, aExpansionKitMenuEntryTex, NULL, NULL, &D_xk1_80031870, NULL, 48, 16, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL, NULL, 48, 16, NULL, NULL },
};

MenuWidget D_xk1_80032880 = { 6, -1, -1, 24, 20, 48, 0, D_xk1_800327A8, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL };

s32 D_xk1_800328B4[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 11, 10, 13 };

void func_xk1_80026870(void) {

    // TODO: move to appropriate place
    PRINTF("DEBUG\n");
    PRINTF("EDIT_MODE_COURSE **\n");
    PRINTF("VIRTUAL SCROLL %d\n");
    PRINTF("x,y %d, %d\n");

    D_80119890 = 0;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

void func_xk1_800268A8(void) {
    D_80119890 = 1;
    func_xk2_800EB9E0();
    D_xk1_8003A550 = 0x110;
    D_xk1_8003A554 = 0x38;
}

extern unk_800D6CA0 D_800D6CA0;
extern s32 D_xk1_80032C20;

void func_xk1_800268E4(void) {
    D_80119890 = 2;
    D_xk1_80032C20 = 0;
    D_800D6CA0.unk_08 = 0x23;
}

void func_xk1_80026908(s32 arg0) {
    D_xk1_800305F0 = arg0;
}

MenuWidget* func_xk1_80026914(MenuWidget* arg0) {
    MenuWidget* temp_a0;
    MenuWidget* var_v1 = arg0;

    while (true) {
        if (var_v1->unk_04 == -1) {
            break;
        }
        temp_a0 = var_v1->dropItems[var_v1->unk_04].widget;
        if (temp_a0 == NULL) {
            break;
        }
        var_v1 = temp_a0;
    }

    return var_v1;
}

s32 func_xk1_80026958(MenuWidget* arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 var_v1;

    var_v1 = -1;
    for (i = 0; i < arg0->numItems; i++) {
        if ((arg1 >= (arg0->unk_0C + arg0->unk_14 * i)) && (arg1 < ((arg0->unk_0C + arg0->unk_14 * i) + 0x30))) {
            if (((arg2 + D_xk1_8003060C) >= (arg0->unk_10 + (arg0->unk_18 * i))) &&
                ((arg2 + D_xk1_8003060C) < ((arg0->unk_10 + (arg0->unk_18 * i)) + 0x10))) {
                var_v1 = i;
            }
        }
    }
    return var_v1;
}

void func_xk1_800269F4(MenuWidget* arg0, s32* arg1, s32* arg2) {
    s32 var_v0;
    s32 var_v1;
    MenuWidget* temp_v1;

    while (true) {
        if (arg0->unk_04 == -1) {
            break;
        }
        temp_v1 = arg0->dropItems[arg0->unk_04].widget;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    var_v0 = *arg1;
    var_v1 = *arg2;
    if (var_v0 < arg0->unk_20) {
        var_v0 = arg0->unk_20;
    }

    if (arg0->unk_28 < var_v0) {
        var_v0 = arg0->unk_28;
    }

    if (arg0->unk_2C < var_v1) {
        var_v1 = arg0->unk_2C;
    }

    if (arg0->numItems < 10) {
        if (var_v1 < arg0->unk_24) {
            var_v1 = arg0->unk_24;
        }
        *arg1 = var_v0;
        *arg2 = var_v1;
    } else {
        if ((arg0->unk_10 + 160) < var_v1) {
            D_xk1_8003060C = ((D_xk1_8003060C + 16) / 16) * 16;
            var_v1 = arg0->unk_10 + 156;
        }

        if (arg0->unk_2C < (var_v1 + D_xk1_8003060C)) {
            D_xk1_8003060C = arg0->unk_2C - var_v1;
        }

        if (var_v1 < arg0->unk_10) {
            D_xk1_8003060C -= 16;
            var_v1 = arg0->unk_24;
        }
        if (D_xk1_8003060C < 0) {
            D_xk1_8003060C = 0;
        }
        *arg1 = var_v0;
        *arg2 = var_v1;
    }
}

void func_xk1_80026B44(Gfx** gfxP, MenuWidget* arg1, s32 arg2, s32 arg3) {
    s32 temp_ra;
    s32 temp_s0;
    s32 temp_v0;
    MenuDropItem* var_t5;
    s32 width;
    s32 height;
    Gfx* gfx;
    s32 i;

    gfx = *gfxP;

    temp_v0 = func_xk1_80026958(arg1, arg2, arg3);

    for (i = 0; i < arg1->numItems; i++) {
        var_t5 = &arg1->dropItems[i];

        temp_ra = arg1->unk_0C + (i * arg1->unk_14);
        temp_s0 = (arg1->unk_10 + (i * arg1->unk_18)) - (D_xk1_8003060C * (arg1->unk_14 == 0));

        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (i == temp_v0) {
            if (var_t5->backgroundSelectedTex != NULL) {
                gDPLoadTextureBlock(gfx++, var_t5->backgroundSelectedTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        } else {
            if (((arg1 == &D_xk1_80032880) || (arg1 == &D_xk1_80031E50)) && (i != temp_v0)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                                  PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if ((arg1 == &D_xk1_80031C28) && (temp_v0 != 2) && (i == 2)) {
                gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                                  PRIMITIVE, 0, TEXEL0, 0);
                gDPSetPrimColor(gfx++, 0, 0, 128, 128, 128, 255);
            }
            if (var_t5->backgroundTex != NULL) {
                gDPLoadTextureBlock(gfx++, var_t5->backgroundTex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0,
                                    G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                    G_TX_NOLOD, G_TX_NOLOD);

                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);

        if (arg1->dropItems[i].subContentsRGBATex != NULL) {
            gDPLoadTextureBlock(gfx++, var_t5->subContentsRGBATex, G_IM_FMT_RGBA, G_IM_SIZ_16b, 24, 12, 0,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 19) << 2, (temp_s0 + 2) << 2, (temp_ra + 45) << 2,
                                (temp_s0 + 14) << 2, 0, 0, 0, 1 << 10, 1 << 10);
        }
        if (arg1->dropItems[i].contentsTex != NULL) {
            width = var_t5->contentsWidth;
            height = var_t5->contentsHeight;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, var_t5->contentsTex, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + width) << 2, (temp_s0 + height) << 2, 0,
                                0, 0, 1 << 10, 1 << 10);
        }
        if (arg1->dropItems[i].subContentsI4Tex != NULL) {
            width = 16;
            height = 16;
            gDPPipeSync(gfx++);
            gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
            gDPSetCombineMode(gfx++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);

            gDPLoadTextureBlock_4b(gfx++, var_t5->subContentsI4Tex, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                                   G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (temp_ra + 28) << 2, temp_s0 << 2, (temp_ra + 44) << 2, (temp_s0 + 16) << 2, 0,
                                0, 0, 1 << 10, 1 << 10);
        }
        if ((i == temp_v0) && (D_800D6CA0.unk_08 != 3) && ((arg1 != &D_xk1_80032880) || (temp_v0 != 5))) {
            gDPPipeSync(gfx++);
            gDPSetCombineLERP(gfx++, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0,
                              PRIMITIVE, 0, TEXEL0, 0);

            gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, D_xk1_80030600);

            gDPLoadTextureBlock(gfx++, D_70201A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 48, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            if (D_xk1_800305F0 != 0) {
                gSPTextureRectangle(gfx++, temp_ra << 2, temp_s0 << 2, (temp_ra + 48) << 2, (temp_s0 + 16) << 2, 0, 0,
                                    0, 1 << 10, 1 << 10);
            }
        }
    }
    *gfxP = gfx;
}

extern u32 gGameFrameCount;

void func_xk1_800276B0(Gfx** gfxP, MenuWidget* arg1, s32 arg2, s32 arg3) {
    Gfx* gfx;
    MenuWidget* temp_v1;

    gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(gfx++, 0, 0, 255, 255, 255, 255);

    D_xk1_80030600 += D_xk1_80030604 * func_xk1_80025C0C();

    if (D_xk1_80030600 > 255) {
        D_xk1_80030600 = 255;
        D_xk1_80030604 = -4;
    }
    if (D_xk1_80030600 < 100) {
        // clang-format off
        D_xk1_80030600 = 100; \
        D_xk1_80030604 = 4;
        // clang-format on
    }
    func_xk1_80026B44(&gfx, arg1, arg2, arg3);

    while (true) {
        if (arg1->unk_14 != 0) {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);
        } else {
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, arg1->unk_0C, arg1->unk_10, arg1->unk_0C + 48,
                          arg1->unk_10 + (arg1->unk_18 * 9) + 0x10);
        }

        if (arg1->unk_04 == -1) {
            break;
        }
        temp_v1 = arg1->dropItems[arg1->unk_04].widget;
        if (temp_v1 == NULL) {
            break;
        }
        arg1 = temp_v1;
    }

    func_xk1_80026B44(&gfx, arg1, arg2, arg3);

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 12, 8, 308, 232);

    if ((arg1->numItems > 10) && (D_xk1_8003060C < ((arg1->numItems - 10) * arg1->unk_18))) {
        if ((gGameFrameCount % 4) >= 2) {
            gDPPipeSync(gfx++);
            gDPSetCombineMode(gfx++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPLoadTextureBlock(gfx++, D_701F5A0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(gfx++, (arg1->unk_0C + 8) << 2, (arg1->unk_10 + (arg1->unk_18 * 0xA)) << 2,
                                (arg1->unk_0C + 40) << 2, ((arg1->unk_10 + (arg1->unk_18 * 0xA)) + 16) << 2, 0, 0, 0,
                                1 << 10, 1 << 10);
        }
    }
    *gfxP = gfx;
}

void func_xk1_80027B74(MenuWidget* arg0) {
    MenuWidget* temp_v1;
    s32 temp_v0;

    if (D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->dropItems[temp_v0].widget;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }
    if (arg0 != &D_xk1_800314C0) {
        func_8074122C(0x25);
    }
    D_xk1_80030610 = -1;
    D_xk1_80030678 = -1;
    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
}

void func_xk1_80027C1C(MenuWidget* arg0) {
    MenuWidget* temp_v1;
    s32 temp_v0;

    if (D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->dropItems[temp_v0].widget;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
}

void func_xk1_80027C80(MenuWidget* arg0) {
    MenuWidget* temp_v1;
    s32 temp_v0;

    if (D_800D6CA0.unk_08 != 1 || D_xk1_800305F8 == 0) {
        return;
    }
    while (true) {
        temp_v0 = arg0->unk_04;
        if (temp_v0 == -1) {
            break;
        }
        arg0->unk_04 = -1;
        temp_v1 = arg0->dropItems[temp_v0].widget;
        if (temp_v1 == NULL) {
            break;
        }
        arg0 = temp_v1;
    }

    arg0->unk_08 = -1;
    D_xk1_800305F8 = 0;
    D_xk1_8003060C = 0;
    D_800D6CA0.unk_08 = 0;
}

extern s32 D_xk2_800F7048;

void func_xk1_80027CFC(MenuWidget* arg0, s32* arg1, s32* arg2) {
    s32 pad;
    MenuWidget* var_a3 = arg0;
    MenuWidget* temp_v1;
    s32 var_a1;

    if (D_xk2_800F7048 == 1) {
        return;
    }

    while (true) {
        if (var_a3->unk_04 == -1) {
            break;
        }
        temp_v1 = var_a3->dropItems[var_a3->unk_04].widget;
        if (temp_v1 == NULL) {
            break;
        }
        var_a3 = temp_v1;
    }

    var_a1 = func_xk1_80026958(var_a3, *arg1, *arg2);

    if ((var_a1 != var_a3->unk_08) && (var_a3->unk_08 != -1) && (var_a3 != &D_xk1_800314C0)) {
        func_8074122C(0x23U);
    }
    var_a3->unk_08 = var_a1;
}

void func_xk1_80027DC8(MenuWidget* arg0, s32* arg1, s32* arg2) {
    MenuWidget* temp_v1;
    MenuWidget* var_a3;
    MenuWidget* sp24;
    s32 sp20;

    var_a3 = arg0;
    while (true) {
        if (var_a3->unk_04 == -1) {
            break;
        }
        temp_v1 = var_a3->dropItems[var_a3->unk_04].widget;
        if (temp_v1 == NULL) {
            break;
        }
        var_a3 = temp_v1;
    }

    sp20 = func_xk1_80026958(var_a3, *arg1, *arg2);
    if (sp20 != -1) {
        if (((var_a3 != &D_xk1_80032880) || (sp20 != 2) || (D_xk1_80032880.dropItems[2].widget != NULL)) &&
            ((var_a3 != &D_xk1_80032880) || (sp20 != 5)) && ((var_a3 != &D_xk1_80032880) || (sp20 != 5)) &&
            (var_a3 != &D_xk1_800314C0)) {
            func_8074122C(0x24);
        }
        if (var_a3 != &D_xk1_800314C0) {
            D_xk1_8003060C = 0;
        }

        var_a3->unk_04 = sp20;
        var_a3->unk_08 = -1;
        if (var_a3->unk_30 != NULL) {
            *var_a3->unk_30 = sp20;
        }

        sp24 = var_a3->dropItems[sp20].widget;
        if (sp24 != NULL) {
            D_xk1_800305F8 = 1;
        }
        if (sp24 != NULL) {
            if (var_a3->dropItems[sp20].action != NULL) {
                var_a3->dropItems[sp20].action();
            }

            if (sp24->unk_30 != NULL) {
                if (*sp24->unk_30 == -1) {
                    D_xk1_800305FC = 0;
                    *arg1 = sp24->unk_20;
                    *arg2 = sp24->unk_24;
                } else {
                    D_xk1_800305FC = *sp24->unk_30;
                    if ((*sp24->unk_30 + 1) > 10) {
                        D_xk1_8003060C = (*sp24->unk_30 - 9) * sp24->unk_18;
                    }
                    *arg1 = (*sp24->unk_30 * sp24->unk_14) + sp24->unk_20;
                    *arg2 = ((*sp24->unk_30 * sp24->unk_18) + sp24->unk_24) - D_xk1_8003060C;
                }
            } else {
                *arg1 = sp24->unk_20;
                *arg2 = sp24->unk_24;
            }
        } else {
            if (var_a3->dropItems[sp20].action != NULL) {
                func_xk1_80027C1C(arg0);
                var_a3->dropItems[sp20].action();
            }
        }
    }
}

extern s32 D_80119880;
extern u8 D_xk2_800F7400;
extern s32 D_xk2_80104378;
extern unk_807B3C20 D_807B3C20;
extern s32 D_xk1_80032BF8;

void func_xk1_80028064(void) {
    if (D_xk1_80032160.unk_04 == -1) {
        return;
    }

    func_xk1_80027C80(&D_xk1_80032880);
    D_xk2_800F7400 = 1;
    switch (D_xk1_80030610) {
        case 0:
            func_8076877C(1, "CRSD");
            PRINTF("LESS POINT\n");
            D_80119880 = 0;
            D_800D6CA0.unk_08 = 50;
            break;
        case 1:
            D_80119880 = 1;
            func_xk2_800F27DC(gCurrentCourseInfo);
            if (D_807B3C20.unk_2900 < 4) {
                D_xk1_80032C20 = 0;
                D_800D6CA0.unk_08 = 16;
                D_xk2_80104378 = 9;
                D_80119880 = -2;
            } else {
                D_xk1_80032BF8 = 0;
                func_8076877C(1, "CRSD");
                PRINTF("NAME\n");
                D_800D6CA0.unk_08 = 50;
            }
            break;
        case 2:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("DELETE\n");
            D_80119880 = 3;
            D_800D6CA0.unk_08 = 50;
            break;
        case 3:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            D_80119880 = 2;
            D_800D6CA0.unk_08 = 50;
            break;
        case 4:
            D_xk1_80032BF8 = 0;
            func_8076877C(0, "CRSD");
            PRINTF("BGM NO. SET %d\n");
            D_80119880 = 7;
            D_800D6CA0.unk_08 = 50;
            break;
    }
}

void func_xk1_8002820C(void) {
    D_xk1_80030614 = 0;
    D_xk1_800327A8[1].contentsTex = D_9004888;
    D_xk1_800327A8[1].widget = &D_xk1_80032354;
    D_xk1_8003067C[1] = &D_xk1_8003061C;
    D_xk1_800327A8[2].contentsTex = NULL;
    D_xk1_800327A8[2].widget = NULL;
}

void func_xk1_80028250(void) {
    MenuWidget* sp94[] = {
        &D_xk1_80031F38,
        &D_xk1_80031FD8,
        &D_xk1_80032078,
        &D_xk1_80031584,
        &D_xk1_80031648,
        &D_xk1_8003170C,
        &D_xk1_800317D0,
        NULL,
        NULL,
    };
    s32* sp70[9] = {
        &D_xk1_8003062C,
        &D_xk1_80030630,
        &D_xk1_80030634,
        &D_xk1_80030638,
        &D_xk1_8003063C,
        &D_xk1_80030640,
        &D_xk1_80030644,
        NULL,
        NULL,
    };
    MenuWidget* sp4C[9] = {
        &D_xk1_80030744, &D_xk1_80030808, &D_xk1_800308F0, &D_xk1_800309D8, &D_xk1_80030A9C,
        &D_xk1_80030B60, &D_xk1_80030C24, &D_xk1_80030E98, &D_xk1_80030FA4,
    };
    s32* sp28[9] = {
        &D_xk1_80030648, &D_xk1_8003064C, &D_xk1_80030650, &D_xk1_80030654, &D_xk1_80030658,
        &D_xk1_8003065C, &D_xk1_80030660, &D_xk1_80030664, &D_xk1_80030668,
    };

    if (D_xk1_8003226C.unk_04 == -1) {
        return;
    }

    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030614) {
        case 0:
            D_xk1_800327A8[1].contentsTex = D_9004888;
            D_xk1_800327A8[1].widget = &D_xk1_80032354;
            D_xk1_8003067C[1] = &D_xk1_8003061C;
            D_xk1_800327A8[2].contentsTex = NULL;
            D_xk1_800327A8[2].widget = NULL;
            D_xk1_8003061C = 0;
            break;
        case 1:
            D_xk1_800327A8[1].contentsTex = D_9004A08;
            D_xk1_800327A8[1].widget = &D_xk1_80032484;
            D_xk1_8003067C[1] = &D_xk1_80030620;
            D_xk1_800327A8[2].contentsTex = NULL;
            D_xk1_800327A8[2].widget = NULL;
            D_xk1_80030620 = 0;
            break;
        case 2:
            D_xk1_80030624 = 0;
            D_xk1_8003062C = 0;
            D_xk1_80030630 = 0;
            D_xk1_80030634 = 0;
            D_xk1_80030638 = 0;
            D_xk1_8003063C = 0;
            D_xk1_80030640 = 0;
            D_xk1_80030644 = 0;
            D_xk1_800327A8[1].contentsTex = D_9004B88;
            D_xk1_800327A8[1].widget = &D_xk1_800325FC;
            D_xk1_8003067C[1] = &D_xk1_80030624;

            switch (D_xk1_80030624) {
                case 7:
                case 8:
                    D_xk1_800327A8[2].contentsTex = NULL;
                    break;
                default:
                    D_xk1_800327A8[2].contentsTex = D_9004E88;
                    break;
            }

            D_xk1_800327A8[2].widget = sp94[D_xk1_80030624];
            D_xk1_8003067C[2] = sp70[D_xk1_80030624];
            break;
        case 3:
            D_xk1_80030628 = 0;
            D_xk1_80030648 = 0;
            D_xk1_8003064C = 0;
            D_xk1_80030650 = 0;
            D_xk1_80030654 = 0;
            D_xk1_80030658 = 0;
            D_xk1_8003065C = 0;
            D_xk1_80030660 = 0;
            D_xk1_80030664 = 0;
            D_xk1_80030668 = 0;

            D_xk1_800327A8[1].contentsTex = D_9004B88;
            D_xk1_800327A8[1].widget = &D_xk1_80032774;
            D_xk1_8003067C[1] = &D_xk1_80030628;
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = sp4C[D_xk1_80030628];
            D_xk1_8003067C[2] = sp28[D_xk1_80030628];
            break;
        case 4:
            D_xk1_800327A8[1].contentsTex = D_9004D08;
            D_xk1_800327A8[1].widget = &D_xk1_80031140;
            D_xk1_8003067C[1] = &D_xk1_8003066C;
            D_xk1_800327A8[2].contentsTex = D_9005008;
            D_xk1_800327A8[2].widget = &D_xk1_80031294;
            D_xk1_8003067C[2] = &D_xk1_80030670;
            break;
        case 5:
            D_xk1_800327A8[1].contentsTex = D_9004E88;
            D_xk1_800327A8[1].widget = &D_xk1_800314C0;
            D_xk1_8003067C[1] = &D_xk1_80030674;
            D_xk1_800327A8[2].contentsTex = NULL;
            D_xk1_800327A8[2].widget = NULL;
            break;
    }
}

extern u8 D_80030060[];
extern u8 D_xk2_80104CA0[];
extern s32 D_xk2_80104CB0;
extern s32 D_xk2_80104CB8;
extern s32 D_xk2_80104CC0;
extern s32 D_xk2_800F7044;
extern s32 D_xk2_800F7058;
extern f32 D_xk2_80119744;

extern unk_802D1B60 D_807BCB58;
extern s32 D_800D65C8;

void func_xk1_8002860C(void) {
    func_xk2_800EF78C();
    func_xk2_800F5C50();
    D_80030060[0] = '\0';
    D_xk2_80104CB8 = 0;
    D_xk2_80104CC0 = 0;
    D_xk2_80104CB0 = 90;
    D_800D6CA0.unk_14 = 0;
    D_xk2_800F7044 = 0;
    D_807B3C20.unk_2900 = 0;
    gCurrentCourseInfo->segmentCount = 0;
    COURSE_CONTEXT()->courseData.controlPointCount = 0;
    D_800D6CA0.unk_0C = -1;
    D_800D6CA0.unk_04 = 0;
    D_800D6CA0.unk_1C = -1;
    if (D_800D6CA0.unk_08 != 0x10) {
        func_xk2_800F12B0();
    }
    D_xk2_80104CA0[3] = 0;
    D_xk2_80104CA0[7] = 0;
    D_800D65C8 = 0;
    D_xk2_800F7058 = 0;
    D_xk2_80119744 = 0.0f;
    D_xk1_8003061C = 0;
    func_xk2_800DC3F8();
    func_8070299C();
    gCurrentCourseInfo->length = 0.0f;
    D_807BCB58.unk_0C = 0;
    D_807BCB58.unk_08 = 0;
}

extern s32 D_xk2_800F7040;

void func_xk1_80028708(void) {
    if (D_xk1_80032354.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_8003061C) {
        case 2:
            func_xk2_800EF78C();
            func_xk2_800E72BC();
            D_xk1_8003061C = 0;
            return;
        case 3:
            func_xk2_800EF78C();
            func_xk2_800F0FF4();
            D_xk2_800F7040 = 3;
            D_xk1_8003061C = 0;
            return;
        case 4:
            D_xk1_80032C20 = 0;
            D_800D6CA0.unk_08 = 0x11;
            break;
        case 0:
        case 1:
            break;
    }
}

void func_xk1_800287BC(void) {
    if (D_xk1_80032484.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030620) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            break;
    }
}

void func_xk1_80028818(void) {
    if (D_xk1_800325FC.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030624) {
        case 0:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_80031F38;
            D_xk1_8003067C[2] = &D_xk1_8003062C;
            break;
        case 1:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_80031FD8;
            D_xk1_8003067C[2] = &D_xk1_80030630;
            break;
        case 2:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_80032078;
            D_xk1_8003067C[2] = &D_xk1_80030634;
            break;
        case 4:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_80031648;
            D_xk1_8003067C[2] = &D_xk1_8003063C;
            break;
        case 3:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_80031584;
            D_xk1_8003067C[2] = &D_xk1_80030638;
            break;
        case 5:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_8003170C;
            D_xk1_8003067C[2] = &D_xk1_80030640;
            break;
        case 6:
            D_xk1_800327A8[2].contentsTex = D_9004E88;
            D_xk1_800327A8[2].widget = &D_xk1_800317D0;
            D_xk1_8003067C[2] = &D_xk1_80030644;
            break;
        case 7:
            D_xk1_800327A8[2].contentsTex = NULL;
            D_xk1_800327A8[2].widget = NULL;
            break;
        case 8:
            D_xk1_800327A8[2].contentsTex = NULL;
            D_xk1_800327A8[2].widget = NULL;
            break;
    }
}

void func_xk1_80028A04(void) {

    if (D_xk1_80032774.unk_04 == -1) {
        return;
    }
    func_xk1_80027C80(&D_xk1_80032880);
    switch (D_xk1_80030628) {
        case 0:
            D_xk1_800327A8[2].widget = &D_xk1_80030744;
            D_xk1_8003067C[2] = &D_xk1_80030648;
            break;
        case 1:
            D_xk1_800327A8[2].widget = &D_xk1_80030808;
            D_xk1_8003067C[2] = &D_xk1_8003064C;
            break;
        case 2:
            D_xk1_800327A8[2].widget = &D_xk1_800308F0;
            D_xk1_8003067C[2] = &D_xk1_80030650;
            break;
        case 3:
            D_xk1_800327A8[2].widget = &D_xk1_800309D8;
            D_xk1_8003067C[2] = &D_xk1_80030654;
            break;
        case 4:
            D_xk1_800327A8[2].widget = &D_xk1_80030A9C;
            D_xk1_8003067C[2] = &D_xk1_80030658;
            break;
        case 5:
            D_xk1_800327A8[2].widget = &D_xk1_80030B60;
            D_xk1_8003067C[2] = &D_xk1_8003065C;
            break;
        case 6:
            D_xk1_800327A8[2].widget = &D_xk1_80030C24;
            D_xk1_8003067C[2] = &D_xk1_80030660;
            break;
        case 7:
            D_xk1_800327A8[2].widget = &D_xk1_80030E98;
            D_xk1_8003067C[2] = &D_xk1_80030664;
            break;
        case 8:
            D_xk1_800327A8[2].widget = &D_xk1_80030FA4;
            D_xk1_8003067C[2] = &D_xk1_80030668;
            break;
    }
}

void func_xk1_80028BA0(void) {
    if (D_xk1_80031F38.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028BD4(void) {
    if (D_xk1_80031FD8.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C08(void) {
    if (D_xk1_80032078.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C3C(void) {
    if (D_xk1_80031584.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028C70(void) {
    if (D_xk1_80031648.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028CA4(void) {
    if (D_xk1_8003170C.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028CD8(void) {
    if (D_xk1_800317D0.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D0C(void) {
    if (D_xk1_80030744.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D40(void) {
    if (D_xk1_80030808.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028D74(void) {
    if (D_xk1_800308F0.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028DA8(void) {
    if (D_xk1_800309D8.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028DDC(void) {
    if (D_xk1_80030A9C.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028E10(void) {
    if (D_xk1_80030B60.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        switch (D_xk1_8003065C) {
            case 0:
            case 1:
            case 2:
                break;
        }
    }
}

void func_xk1_80028E54(void) {
    if (D_xk1_80030C24.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028E88(void) {
    if (D_xk1_80030E98.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028EBC(void) {
    if (D_xk1_80030FA4.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
    }
}

void func_xk1_80028EF0(void) {
    if (D_xk1_80031140.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        COURSE_CONTEXT()->courseData.venue = D_xk1_8003066C;
        func_80702FF4(D_xk1_8003066C);
        func_80709A38(D_xk1_8003066C);
        D_xk2_800F7040 = 3;
    }
}

void func_xk1_80028F50(void) {
    if (D_xk1_80031294.unk_04 != -1) {
        func_xk1_80027C80(&D_xk1_80032880);
        COURSE_CONTEXT()->courseData.skybox = D_xk1_80030670;
    }
}

extern s32 D_800D11D4;

void func_xk1_80028F94(void) {

    if ((D_xk1_800314C0.unk_04 != -1) && (func_807424CC() == 0)) {
        if (D_xk1_800305F4 != D_xk1_800328B4[D_xk1_80030674]) {
            if (D_800D11D4 != 0) {
                func_8074122C(0x24);
            }
            D_xk1_800305F4 = D_xk1_800328B4[D_xk1_80030674];
            func_80741AF4(D_xk1_800328B4[D_xk1_800314C0.unk_04]);
            D_xk1_800314C0.unk_04 = -1;
            COURSE_CONTEXT()->courseData.unk_1F = D_xk1_800328B4[D_xk1_80030674];
        }
    }
}

void func_xk1_80029070(void) {
    D_xk1_80030614 = 0;
    D_xk1_800327A8[1].contentsTex = D_9004888;
    D_xk1_800327A8[1].widget = &D_xk1_80032354;
    D_xk1_8003067C[1] = &D_xk1_8003061C;
    D_xk1_800327A8[2].contentsTex = NULL;
    D_xk1_800327A8[2].widget = NULL;
}

s32 func_xk1_800290B4(void) {
    return D_xk1_8003060C;
}

s32 func_xk1_800290C0(void) {
    return D_xk1_80030600;
}
