#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "libultra/ultra64.h"
#include "fzx_math.h"
#include "gfx.h"
#include "PR/leo.h"
#include "libc/stdbool.h"
#include "other_types.h"
#include "unk_structs.h"
#include "controller.h"

void Game_ThreadEntry(void* arg0);
void Audio_ThreadEntry(void* arg0);

void Controller_SetGlobalInputs(Controller* controller);

void func_80703F90(void);
void func_80767958(void*);
s32 func_80768A5C(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq);
s32 func_80768AF0(LEOCmd* cmdBlock, s32 direction, u32 lba, void* vAddr, u32 nLbas, OSMesgQueue* mq);
s32 func_80768C08(OSPiHandle*, OSIoMesg*, s32);
s32 Segment_SetPhysicalAddress(s32 segment, s32 addr);
Gfx* Segment_SetTableAddresses(Gfx*);
s32 Segment_SetAddress(s32 segment, s32 addr);

void mio0Decode(u8*, void*);
void Audio_SetSoundMode(u8 soundMode);
void Game_Init(void);

void Controller_UpdateInputs(void);
void Controller_Init(void);

void Math_SinTableInit(void);
void Math_Rand1Init(s32 seed, s32 mask);
void Math_Rand2Init(s32 seed, s32 mask);
s32 Math_Round(f32 num);
void func_806F86C0(Mtx*, MtxF*, f32, s32, s32, s32, f32, f32, f32);
void func_806F7FCC(Mtx*, MtxF*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_806F8868(Mtx*, MtxF*, f32, s32, f32, f32, f32, f32, f32, f32);

void func_80701C04(void* romAddr, void* ramAddr, size_t size);
void func_80701D7C(u8* romAddr, u8* ramAddr, size_t size);


void func_80702A68(void);
void func_80702A94(void);

void func_80703320(f32*, f32*);
s32 func_80703444(Vec3f*, f32);

void func_807038B0(void);
void func_80703948(void);
s32 func_80703CA4(s32 startLba, void* vram, s32 diskSize, s32 bssSize);
s32 func_80703E08(s32 startLba, void* vram, s32 diskSize, s32 bssSize);

void SLForceWritebackDCacheAll(void);
s32 SLLeoReadWrite(LEOCmd* cmdBlock, s32 direction, s32 lba, u8* vAddr, u32 nLbas, OSMesgQueue* mq);
s32 SLLeoReadWrite_DATA(LEOCmd* cmdBlock, s32 direction, s32 lba, u8* vAddr, u32 nLbas, OSMesgQueue* mq);
void SLMFSRecoverManageArea(void);
void func_80706518(s32, s32, s32);
void SLMFSDeleteFile(u16, u8*, u8*, s32);
void SLMFSNewDisk(void);
void SLMFSNewDisk2(void);
s32 func_80707780(void);
s32 SLCheckDiskInsert(void);
void func_80707B08(void);
void func_8070818C(u8* romAddr, u8* ramAddr, size_t size);

void func_807083D8(void);
void func_80708430(void);

void func_80704870(void);
void func_8070D220(void);
void func_807082B0(void);
bool func_80708D88(void);
void func_8071E988(void);
void func_8071E9C4(void);
void func_80708F4C(void);
void func_8071EA88(void);
void func_807419F0(u8);
s32 func_80703228(void);
void func_806F4FC8(void);

void func_8070F8A4(s32, s32);
void func_8070F240(void);
void func_80704CE0(void);
void func_80704DB0(char*, char*);
void func_8070F0F0(void);
void func_80704F38(OSThread*);
void Fault_Init(void);
void Fault_SetFrameBuffer(FrameBuffer* buffer, u16 width, u16 height);
void Audio_Init(RomOffset, RomOffset, RomOffset);
void Audio_PreNMI(void);
void func_806F5A50(void);

void func_806F5310(void);
Gfx* func_806F59E0(Gfx*);
void func_80709C3C(void);
void func_80745CB8(void);

bool func_80704F44(LEODiskID, LEODiskID);
s32 SLLeoReadDiskID(LEODiskID*);
void SLLeo_mfs_newdisk(void);

void func_80708430(void);
void func_8070D358(void);
void func_8070DA84(void);
void func_8070DAD4(s32);
void func_8070DAFC(void);
void func_8070F0D0(void);
void func_80715F9C(void);
void func_8071ED34(void);

s32 func_807424CC(void);
s32 func_80742790(void);
void func_8074279C(void);

s32 func_80768B88(OSPiHandle*, OSIoMesg*, s32);
u16 func_80766788(void);
s32 func_80766660(u16);

Gfx* func_xk1_8002ED64(Gfx*);
Gfx* func_xk1_8002F9DC(Gfx*);
void func_xk1_8002FFA0(void);
void func_xk1_8002FFDC(void);

s32 Save_UpdateCourseCharacterSave(s32);
void func_i2_800A20A0(void);
Gfx* func_i2_800A2B0C(Gfx*);
void func_i2_800A2CCC(void);
void func_i2_800A20EC(void);
void func_i2_800A231C(void);
s32 func_i2_800A27C4(void);
void func_i2_800AA994(void);
void func_i2_800AABD0(void);
void func_i2_800B079C(void);
void func_i2_800B07F0(void);
void func_i2_800B0D10(s32);
f32 func_i2_800B20D0(CourseSegment*, f32, f32*);
f32 func_i2_800B2500(CourseSegment*, f32, Vec3f*);
void func_i2_800B26B8(CourseSegment*, f32, Vec3f*);
f32 func_i2_800B2824(CourseSegment*, f32, Mtx3F*, f32);
void func_i2_800B904C(void);

void func_i3_ResetLivesChangeCounter(void);
void func_i3_8005FDB0(void);
void func_i4_80073EA0(void);

void func_i10_8012B520(void);
void func_i10_8012B854(void);
void func_i10_8012B894(s32);
void func_i10_8012B904(void);

void Title_Init(void);
void Race_Init(void);
void Records_Init(void);
void MainMenu_Init(void);
void MachineSelect_Init(void);
void MachineSettings_Init(void);
void CourseSelect_Init(void);
void Credits_Init(void);
void CourseEdit_Init(void);
void NextCourseSelect_Init(void);
void MachineCreate_Init(void);
void EndingCutscene_Init(void);
void OptionsMenu_Init(void);
void func_xk4_800D8260(void);

s32 Title_Update(void);
s32 Race_Update(void);
s32 Records_Update(void);
s32 MainMenu_Update(void);
s32 MachineSelect_Update(void);
s32 MachineSettings_Update(void);
s32 CourseSelect_Update(void);
s32 Credits_Update(void);
s32 CourseEdit_Update(void);
s32 NextCourseSelect_Update(void);
s32 MachineCreate_Update(void);
s32 EndingCutscene_Update(void);
s32 OptionsMenu_Update(void);
s32 func_xk4_800D82A4(void);

Gfx* Title_Draw(Gfx* gfx);
Gfx* Race_Draw(Gfx* gfx);
Gfx* Records_Draw(Gfx* gfx);
Gfx* MainMenu_Draw(Gfx* gfx);
Gfx* MachineSelect_Draw(Gfx* gfx);
Gfx* MachineSettings_Draw(Gfx* gfx);
Gfx* CourseSelect_Draw(Gfx* gfx);
Gfx* Credits_Draw(Gfx* gfx);
Gfx* CourseEdit_Draw(Gfx* gfx);
Gfx* MachineCreate_Draw(Gfx* gfx);
Gfx* EndingCutscene_Draw(Gfx* gfx);
Gfx* OptionsMenu_Draw(Gfx* gfx);
Gfx* func_xk4_800D8348(Gfx* gfx);


#endif // FUNCTIONS_H
