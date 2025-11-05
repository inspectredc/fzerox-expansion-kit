#ifndef SEGMENT_SYMBOLS_H
#define SEGMENT_SYMBOLS_H

#include <PR/ultratypes.h>

#define DECLARE_VRAM_SEGMENT(name) \
    extern u8 name ## _VRAM[]; \
    extern u8 name ## _VRAM_END[]

#define DECLARE_ROM_SEGMENT(name) \
    extern u8 name ## _ROM_START[]; \
    extern u8 name ## _ROM_END[]

#define DECLARE_DISK_SEGMENT(name) \
    extern u8 name ## _ROM_START[]

#define DECLARE_TEXT_SEGMENT(name)   \
    extern u8 name ## _TEXT_START[]; \
    extern u8 name ## _TEXT_END[]

#define DECLARE_DATA_SEGMENT(name)   \
    extern u8 name ## _DATA_START[]; \
    extern u8 name ## _DATA_END[]; \
    extern u8 name ## _DATA_SIZE[]; \
    extern u8 name ## _RODATA_END[]

#define DECLARE_BSS_SEGMENT(name)   \
    extern u8 name ## _BSS_START[]; \
    extern u8 name ## _BSS_END[]

#define DECLARE_SEGMENT(name)    \
    DECLARE_VRAM_SEGMENT(name);  \
    DECLARE_DISK_SEGMENT(name);  \
    DECLARE_TEXT_SEGMENT(name);  \
    DECLARE_DATA_SEGMENT(name);  \
    DECLARE_BSS_SEGMENT(name)

#define SEGMENT_VRAM_START(segment) (segment ## _VRAM)
#define SEGMENT_VRAM_END(segment)   (segment ## _VRAM_END)
#define SEGMENT_VRAM_SIZE(segment)  (SEGMENT_VRAM_END(segment) - SEGMENT_VRAM_START(segment))

#define SEGMENT_TEXT_START(segment) (segment ## _TEXT_START)
#define SEGMENT_TEXT_END(segment)   (segment ## _TEXT_END)
#define SEGMENT_TEXT_SIZE(segment)  (SEGMENT_TEXT_END(segment) - SEGMENT_TEXT_START(segment))

#define SEGMENT_DATA_START(segment) (segment ## _DATA_START)
#define SEGMENT_DATA_END(segment)   (segment ## _DATA_END)
#define SEGMENT_RODATA_END(segment)   (segment ## _RODATA_END)
#define SEGMENT_DATA_SIZE(segment)  (SEGMENT_RODATA_END(segment) - SEGMENT_DATA_START(segment))

#define SEGMENT_DATA_SIZE_CONST(segment) (segment ## _DATA_SIZE)

#define SEGMENT_BSS_START(segment) (segment ## _BSS_START)
#define SEGMENT_BSS_END(segment)   (segment ## _BSS_END)
#define SEGMENT_BSS_SIZE(segment)  (SEGMENT_BSS_END(segment) - SEGMENT_BSS_START(segment))

#define SEGMENT_DISK_START(segment) (segment ## _ROM_START)
#define SEGMENT_DISK_SIZE(segment)  (SEGMENT_BSS_START(segment) - SEGMENT_VRAM_START(segment))

DECLARE_SEGMENT(main);

DECLARE_SEGMENT(expansion_kit);
DECLARE_SEGMENT(ovl_i3);
DECLARE_SEGMENT(ovl_i4);
DECLARE_SEGMENT(course_select);
DECLARE_SEGMENT(ovl_i6);
DECLARE_SEGMENT(ending);
DECLARE_SEGMENT(records);
DECLARE_SEGMENT(ovl_i2);
DECLARE_SEGMENT(ovl_i9);
DECLARE_SEGMENT(ovl_i10);

DECLARE_SEGMENT(course_edit);
DECLARE_SEGMENT(machine_create);
DECLARE_SEGMENT(ead_demo);


// Todo: Create sections in splat for all of these

DECLARE_SEGMENT(framebuffer1);
DECLARE_SEGMENT(framebuffer2);
DECLARE_SEGMENT(unk_gfx_segment);
DECLARE_SEGMENT(unk_bss_segment);
DECLARE_SEGMENT(gfxpool);
DECLARE_SEGMENT(buffers);
DECLARE_SEGMENT(framebuffer3);
DECLARE_SEGMENT(framebuffer_unused);
DECLARE_SEGMENT(audio_context);
DECLARE_SEGMENT(unk_context);

DECLARE_SEGMENT(segment_21C170);
DECLARE_SEGMENT(create_machine_textures);
DECLARE_SEGMENT(segment_1FB850);
DECLARE_SEGMENT(segment_16C8A0);
DECLARE_SEGMENT(segment_17B1E0);
DECLARE_SEGMENT(segment_17B960);
DECLARE_SEGMENT(segment_1B8550);
DECLARE_SEGMENT(segment_1E23F0);
DECLARE_SEGMENT(segment_22B0A0);
DECLARE_SEGMENT(segment_235130);
DECLARE_SEGMENT(segment_2738A0);

DECLARE_SEGMENT(silence_3);
DECLARE_SEGMENT(sand_ocean_3);
DECLARE_SEGMENT(devils_forest_4);
DECLARE_SEGMENT(port_town_3);
DECLARE_SEGMENT(devils_forest_5);
DECLARE_SEGMENT(big_blue_3);
DECLARE_SEGMENT(mute_city_4);
DECLARE_SEGMENT(space_plant_2);
DECLARE_SEGMENT(port_town_4);
DECLARE_SEGMENT(fire_field_2);
DECLARE_SEGMENT(white_land_3);
DECLARE_SEGMENT(big_foot);

DECLARE_SEGMENT(silence_3_staff_ghost);
DECLARE_SEGMENT(sand_ocean_3_staff_ghost);
DECLARE_SEGMENT(devils_forest_4_staff_ghost);
DECLARE_SEGMENT(port_town_3_staff_ghost);
DECLARE_SEGMENT(devils_forest_5_staff_ghost);
DECLARE_SEGMENT(big_blue_3_staff_ghost);
DECLARE_SEGMENT(mute_city_4_staff_ghost);
DECLARE_SEGMENT(space_plant_2_staff_ghost);
DECLARE_SEGMENT(port_town_4_staff_ghost);
DECLARE_SEGMENT(fire_field_2_staff_ghost);
DECLARE_SEGMENT(white_land_3_staff_ghost);
DECLARE_SEGMENT(big_foot_staff_ghost);

#endif
