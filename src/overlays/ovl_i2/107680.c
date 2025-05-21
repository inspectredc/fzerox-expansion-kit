#include "global.h"
#include "fzx_game.h"
#include "fzx_save.h"
#include "fzx_course.h"
#include "fzx_machine.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5D40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5D7C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5DB8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5DFC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5E38.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5EB0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A5F58.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A634C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6578.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A66C0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A68A8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6988.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A69D4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6A30.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6B70.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6BF8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6C68.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6D18.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6D88.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6DD0.s")

void Save_WriteCharacterSave(CharacterSave* characterSave, s32 courseIndex) {
    characterSave->checksum = Save_CalculateCharacterSaveChecksum(characterSave);
    Sram_ReadWrite(OS_WRITE, (uintptr_t) &gSaveContext.characterSaves[courseIndex] - (uintptr_t) &gSaveContext,
                   characterSave, sizeof(CharacterSave));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6E6C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A6EB4.s")

s32 Save_UpdateCourseCharacterSave(s32 courseIndex) {
    s32 pad[2];
    CharacterSave* characterSave = &gSaveContext.characterSaves[courseIndex];

    Save_SaveCharacterSave(characterSave);
    Save_WriteCharacterSave(characterSave, courseIndex);
    return 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A706C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A72BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A737C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7438.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7538.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7584.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A762C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7660.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7750.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A77EC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7944.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A79BC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7A30.s")

void func_i2_800A7A8C(unk_80141C88_unk_1D* arg0) {

    arg0->unk_00.character = 0;
    arg0->unk_00.customType = 0;
    arg0->unk_00.frontType = 0;
    arg0->unk_00.rearType = 0;
    arg0->unk_00.wingType = 0;
    arg0->unk_00.logo = 0;
    arg0->unk_00.number = 0;
    arg0->unk_00.decal = 0;
    arg0->unk_00.bodyR = 0;
    arg0->unk_00.bodyG = 0;
    arg0->unk_00.bodyB = 0;
    arg0->unk_00.numberR = 0;
    arg0->unk_00.numberG = 0;
    arg0->unk_00.numberB = 0;
    arg0->unk_00.decalR = 0;
    arg0->unk_00.decalG = 0;
    arg0->unk_00.decalB = 0;
    arg0->unk_00.cockpitR = 0;
    arg0->unk_00.cockpitG = 0;
    arg0->unk_00.cockpitB = 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7AE0.s")

void Save_InitCourseRecord(SaveCourseRecords* courseRecords, bool shouldClear) {
    s32 i;
    s32 j;

    if (shouldClear) {
        Save_ClearData(courseRecords, sizeof(SaveCourseRecords));
    }

    for (i = 0; i < 5; i++) {
        courseRecords->timeRecord[i] = MAX_TIMER;
        courseRecords->engines[i] = 0.5f;
        func_i2_800A7A8C(&courseRecords->unk_50[i]);
        // clang-format off
        for (j = 0; j < 4; j++) { \
            courseRecords->name[i][j] = '\0';
        }
        // clang-format on
    }

    courseRecords->maxSpeed = 0.0f;
    courseRecords->bestTime = MAX_TIMER;

    func_i2_800A7A8C(&courseRecords->unk_F0);
}

void Save_InitGhostRecord(GhostRecord* ghostRecord, bool shouldClear) {
    s32 i;

    if (shouldClear) {
        Save_ClearData(ghostRecord, sizeof(GhostRecord));
    }

    ghostRecord->replayChecksum = 0;
    ghostRecord->ghostType = GHOST_NONE;
    ghostRecord->encodedCourseIndex = 0;
    ghostRecord->raceTime = MAX_TIMER;
    ghostRecord->unk_10 = 0;

    func_i2_800A7A8C(&ghostRecord->unk_20);

    for (i = 0; i < 9; i++) {
        ghostRecord->trackName[i] = 0;
    }
}

void func_i2_800A7C84(GhostRecord* ghostRecord) {
    Save_InitGhostRecord(ghostRecord, true);
    ghostRecord->checksum = Save_CalculateGhostRecordChecksum(ghostRecord);
}

void func_i2_800A7CB8(SaveCourseRecords* courseRecords) {
    Save_InitCourseRecord(courseRecords, true);
    courseRecords->checksum = Save_CalculateSaveCourseRecordChecksum(courseRecords);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7CEC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7D40.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7DA8.s")

void Save_ClearData(void* data, s32 size) {
    s32 i;
    u8* ptr;

    // clang-format off
    for (i = 0, ptr = data; i < size; i++, ptr++) { \
        *ptr = 0;
    }
    // clang-format on
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7E70.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A7F94.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8038.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8098.s")

void func_i2_800A81D4(void) {
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A81DC.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8320.s")

extern f32 gCharacterLastEngine[];

void Save_SaveCharacterSave(CharacterSave* characterSave) {
    s32 i;

    for (i = 0; i < 30; i++) {
        characterSave->characterEngine[i] = gCharacterLastEngine[i];
    }

    characterSave->unk_02 = 0;
    characterSave->unk_04 = 0;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8450.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A85E0.s")

void func_i2_800A88D8(unk_80141C88_unk_1D* arg0, MachineInfo* arg1) {

    arg1->character = arg0->unk_00.character;
    arg1->customType = arg0->unk_00.customType;
    arg1->frontType = arg0->unk_00.frontType;
    arg1->rearType = arg0->unk_00.rearType;
    arg1->wingType = arg0->unk_00.wingType;
    arg1->logo = arg0->unk_00.logo;
    arg1->number = arg0->unk_00.number;
    arg1->decal = arg0->unk_00.decal;
    arg1->bodyR = arg0->unk_00.bodyR;
    arg1->bodyG = arg0->unk_00.bodyG;
    arg1->bodyB = arg0->unk_00.bodyB;
    arg1->numberR = arg0->unk_00.numberR;
    arg1->numberG = arg0->unk_00.numberG;
    arg1->numberB = arg0->unk_00.numberB;
    arg1->decalR = arg0->unk_00.decalR;
    arg1->decalG = arg0->unk_00.decalG;
    arg1->decalB = arg0->unk_00.decalB;
    arg1->cockpitR = arg0->unk_00.cockpitR;
    arg1->cockpitG = arg0->unk_00.cockpitG;
    arg1->cockpitB = arg0->unk_00.cockpitB;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A897C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8B00.s")

void func_i2_800A8CE4(SaveCourseRecords* courseRecord, s32 courseIndex) {
    Save_LoadCourseRecord(courseRecord, courseIndex);
}

void Save_LoadCourseRecord(SaveCourseRecords* courseRecord, s32 courseIndex) {
    u16 checksum;
    s32 i;
    s32 j;
    CourseInfo* courseInfo;

    courseInfo = &gCourseInfos[courseIndex];

    for (i = 0; i < 5; i++) {
        courseInfo->timeRecord[i] = courseRecord->timeRecord[i];
        courseInfo->recordEngines[i] = courseRecord->engines[i];
        func_i2_800A88D8(&courseRecord->unk_50[i], &courseInfo->recordMachineInfos[i]);
        for (j = 0; j < 4; j++) {
            courseInfo->recordNames[i][j] = courseRecord->name[i][j];
        }
    }
    courseInfo->maxSpeed = courseRecord->maxSpeed;
    courseInfo->bestTime = courseRecord->bestTime;
    func_i2_800A88D8(&courseRecord->unk_F0, &courseInfo->maxSpeedMachine);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8E20.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8EBC.s")

void func_i2_800A8FBC(void) {
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A8FC4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A906C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A91AC.s")

u16 Save_CalculateChecksum(void* data, s32 size) {
    u8* dataPtr = data;
    u16 checksum = 0;
    s32 i;

    for (i = 0; i < size; i++) {
        checksum += *dataPtr++;
    }

    return checksum;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9480.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A94A0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A94C4.s")

s32 Save_CalculateSaveCourseRecordChecksum(SaveCourseRecords* courseRecords) {
    return Save_CalculateChecksum(&courseRecords->unk_02, sizeof(SaveCourseRecords) - sizeof(u16));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A951C.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9540.s")

s32 Save_CalculateGhostRecordChecksum(GhostRecord* ghostRecord) {
    return Save_CalculateChecksum(&ghostRecord->ghostType, sizeof(GhostRecord) - sizeof(u16));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9588.s")

s32 Save_CalculateCharacterSaveChecksum(CharacterSave* characterSave) {
    return Save_CalculateChecksum(&characterSave->unk_02, sizeof(CharacterSave) - sizeof(u16));
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A95D0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A95F4.s")

extern OSIoMesg sSramIoMesg;
extern OSPiHandle* gSramPiHandlePtr;
extern OSMesgQueue gDmaMesgQueue;

void Sram_ReadWrite(s32 direction, u32 offset, void* dramAddr, size_t size) {
    osWritebackDCache(dramAddr, size);
    osInvalDCache(osPhysicalToVirtual((uintptr_t) dramAddr), size);
    sSramIoMesg.hdr.pri = 0;
    sSramIoMesg.hdr.retQueue = &gDmaMesgQueue;
    sSramIoMesg.dramAddr = dramAddr;
    sSramIoMesg.devAddr = offset + OS_K1_TO_PHYSICAL(0xA8000000);
    sSramIoMesg.size = size;
    func_80768B88(gSramPiHandlePtr, &sSramIoMesg, direction);
    osRecvMesg(&gDmaMesgQueue, NULL, OS_MESG_BLOCK);
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9728.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9788.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A97B4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9820.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9894.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A98E4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9934.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9A54.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9AE0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9B88.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/func_i2_800A9BA4.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/D_i2_800C1CC0.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/D_i2_800C1CC8.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/ovl_i2/107680/jtbl_i2_800C1CD0.s")
