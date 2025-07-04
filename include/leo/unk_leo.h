#ifndef UNK_LEO_H
#define UNK_LEO_H

#include "libultra/ultra64.h"
#include "PR/leo.h"

typedef struct MfsTimeFormat {
    union {
        struct {
            u8 unkb0, unkb1, unkb2, unkb3;
        };
        struct {
            u16 unks0, unks2;
        };
        u32 unki1;
    };
} MfsTimeFormat;

typedef struct MfsRamId {
    /* 0x00 */ char diskId[10]; // "64dd-Multi"
    /* 0x0A */ s8 fsType[2];
    /* 0x0C */ s8 fsVersion[2];
    /* 0x0E */ u8 attr;
    /* 0x0F */ u8 diskType;
    /* 0x10 */ char volumeName[20];
    /* 0x24 */ MfsTimeFormat formatDate;
    /* 0x28 */ u16 renewalCounter;
    /* 0x2A */ u8 destinationCode;
    /* 0x2B */ s8 reserve1;
    /* 0x2C */ u32 checksum;
    /* 0x30 */ s8 reserve2[0xC];
} MfsRamId; // size = 0x3C

typedef struct MfsRamDirectoryEntry {
    /* 0x00 */ u16 attr;
    /* 0x02 */ u16 parentDirId;
    /* 0x04 */ s8 companyCode[2];
    /* 0x06 */ s8 gameCode[4];
    union {
        /* 0x0A */ u16 dirId; // directories only
        /* 0x0A */ u16 fileAllocationTableId; // files only
    };
    union {
        /* 0x0C */ s8 reserve1[0x4]; // directories only
        /* 0x0C */ s32 fileSize; // files only
    };
    /* 0x10 */ char name[20];
    union {
        /* 0x24 */ s8 reserve2[0x6]; // directories only
        struct {
            /* 0x24 */ char extension[5];
            /* 0x29 */ u8 copyCount;
        }; // files only
    };
    /* 0x2A */ u8 renewalCounter;
    /* 0x2B */ s8 reserve3;
    /* 0x2C */ MfsTimeFormat creationDate;
} MfsRamDirectoryEntry; // size = 0x30

typedef struct MfsRamArea {
    /* 0x0000 */ MfsRamId id;
    /* 0x003C */ u16 fileAllocationTable[0xB3A];
    /* 0x16B0 */ MfsRamDirectoryEntry directoryEntry[1112];
} MfsRamArea; // size = 0xE730

#define LEO_MANAGER_REGION_NONE 0
#define LEO_MANAGER_REGION_JP 0x101
#define LEO_MANAGER_REGION_US 0x102

#define MFS_VOLUME_ATTR_VPROTECT_WRITE (1 << 5) // Prohibits writes unless game and company code matches
#define MFS_VOLUME_ATTR_VPROTECT_READ (1 << 6) // Prohibits reads unless game and company code matches
#define MFS_VOLUME_ATTR_WPROTECT (1 << 7) // Prohibits all writes

#define MFS_FILE_ATTR_COPYLIMIT (1 << 9)
#define MFS_FILE_ATTR_ENCODE (1 << 10)
#define MFS_FILE_ATTR_HIDDEN (1 << 11)
#define MFS_FILE_ATTR_FORBID_R (1 << 12)
#define MFS_FILE_ATTR_FORBID_W (1 << 13)
#define MFS_FILE_ATTR_FILE (1 << 14)
#define MFS_FILE_ATTR_DIRECTORY (1 << 15)

#define MFS_VALIDATION_CHECK_SUB_ENTRY (1 << 1)
#define MFS_VALIDATION_CHECK_ENTRY_AS_DIRECTORY (1 << 2) // Effectively unused, unsure of purpose
#define MFS_VALIDATION_CHECK_DIRECTORY (1 << 3)
#define MFS_VALIDATION_CHECK_PARENT (1 << 4)
#define MFS_VALIDATION_CHECK_MAIN_ENTRY (1 << 5)
#define MFS_VALIDATION_CHECK_READ (1 << 6)
#define MFS_VALIDATION_CHECK_WRITE (1 << 7)

#define MFS_ENTRY_ROOT_DIR 0
#define MFS_ENTRY_WORKING_DIR 0xFFFB
#define MFS_ENTRY_WORKING_PARENT_DIR 0xFFFC
#define MFS_ENTRY_ROOT_PARENT_DIR 0xFFFE
#define MFS_ENTRY_DOES_NOT_EXIST 0xFFFF

#define MFS_FAT_UNUSED 0
#define MFS_FAT_OUT_OF_MANAGEMENT 0xFFFD
#define MFS_FAT_PROHIBITED 0xFFFE
#define MFS_FAT_LAST_BLOCK 0xFFFF

#endif // UNK_LEO_H
