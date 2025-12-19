#include "leo/mfs.h"

u8 D_8077B4D0[0x4D10] = { 0 };
u8 D_807801E0[0x4D10] = { 0 };
MfsRamArea gMfsRamArea = { 0 };
MfsRamDirectoryEntry gCurrentDirectoryEntry = { 0 };
u16 gFileAllocationTable[0xB3A] = { 0 };
s32 D_80794CC4 = 0;
OSMesgQueue* D_80794CC8 = NULL;
OSMesg D_80794CCC = NULL;
s32 gDirectoryEntryCount = 0;
s32 gMfsError = LEO_ERROR_GOOD;
s32 D_80794CD8 = 0;
s32 D_80794CDC = 0;
u16 gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
LEODiskID D_80794CE8 = { 0 };
OSMesg D_80794D08[1] = { NULL };
OSMesgQueue D_80794D0C = { 0 };
LEOCapacity gRamAreaCapacity = { 0 };
s32 D_80794D30 = N64DD_MANAGER_NOT_CREATED;
char D_80794D34[] = "64dd-Multi";
char gCompanyCode[2] = { 0 };
char gGameCode[4] = { 0 };
u8 D_80794D48 = 0;
