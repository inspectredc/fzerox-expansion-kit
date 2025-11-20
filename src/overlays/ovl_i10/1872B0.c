#include "global.h"

extern s32 D_8079A32C;
extern OSPiHandle* gSramPiHandlePtr;

s32 func_i10_8012B520(void) {
    gSramPiHandlePtr = Sram_Init();
    func_i10_8012B5E8(Arena_Allocate(ALLOC_PEEK, sizeof(SaveContext)));
    if (D_8079A32C != 0) {
        func_xk1_8002FBC8();
    }
    func_i10_8012B580();
    return 0;
}

extern s32 sDDStaffGhostRecordTimes[];

void func_i10_8012B580(void) {
    s32 pad;
    s32 courseIndex;
    GhostInfo sp30;

    for (courseIndex = 0; courseIndex < 24; courseIndex++) {
        Save_LoadStaffGhostRecord(&sp30, courseIndex);
        sDDStaffGhostRecordTimes[courseIndex] = sp30.raceTime;
    }
}

void func_i10_8012B5E8(SaveContext* saveContext) {
    s32 i;
    s32 var_s2;
    s32 sp34;
    ProfileSave* var_s1;

    Sram_ReadWrite(OS_READ, 0, saveContext, sizeof(SaveContext));

    for (var_s2 = 0, i = 0, var_s1 = saveContext->profileSaves; i < 2; var_s2++, i++, var_s1++) {
        if (!func_i10_8012B6A0(var_s1->saveSettings.fileName)) {
            break;
        }
        sp34 = i;
    }

    if (var_s2 == 2) {
        Save_Init(saveContext, 0);
        return;
    }
    if (var_s2 == 1) {
        func_i10_8012B6E4(saveContext, sp34);
    }
    Save_Load(saveContext);
}

extern const char D_i2_800C1CC0[];

bool func_i10_8012B6A0(u8* arg0) {
    s32 ret = false;
    s32 i;

    for (i = 0; i != 8; i++) {
        if (arg0[i] != D_i2_800C1CC0[i]) {
            ret = true;
            break;
        }
    }

    return ret;
}

void func_i10_8012B6E4(SaveContext* arg0, s32 arg1) {
    s32 i;
    u8* temp_a2 = arg0->profileSaves[arg1].saveSettings.fileName;

    for (i = 0; i < 8; i++) {
        temp_a2[i] = D_i2_800C1CC0[i];
    }

    Sram_ReadWrite(OS_WRITE, temp_a2 - (u8*) arg0, temp_a2, 8);
}
