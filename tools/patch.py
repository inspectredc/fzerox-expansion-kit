# Adapted from AngheloAlf/drmario64
# SPDX-FileCopyrightText: © 2022-2024 AngheloAlf
# SPDX-License-Identifier: MIT

import sys
import argparse
import struct
import pathlib
import spimdisasm

# todo: generate this list from splat yaml
patchedEntries = [
    "main",
    "ovl_xk1",
    "ovl_i3",
    "ovl_i4",
    "course_select",
    "ovl_i6",
    "ovl_i7",
    "ovl_i8",
    "ovl_i2",
    "ovl_i9",
    "ovl_i10",
    "course_edit",
    "machine_create",
    "ovl_xk4",
    "segment_1FB850",
    "segment_21C170",
    "silence_3",
    "sand_ocean_3",
    "devils_forest_4",
    "port_town_3",
    "devils_forest_5",
    "big_blue_3",
    "mute_city_4",
    "space_plant_2",
    "port_town_4",
    "fire_field_2",
    "white_land_3",
    "big_foot",
]

diskRomAddrs = {
    "main" : 0x60,
    "ovl_xk1" : 0xA2E70,
    "ovl_i3" : 0xB0AB0,
    "ovl_i4" : 0xDE7C0,
    "course_select" : 0xE6660,
    "ovl_i6" : 0xEB850,
    "ovl_i7" : 0xF5080,
    "ovl_i8" : 0xFCC60,
    "ovl_i2" : 0x1039E0,
    "ovl_i9" : 0x132B30,
    "ovl_i10" : 0x1872B0,
    "course_edit" : 0x188850,
    "machine_create" : 0x1CB1E0,
    "ovl_xk4" : 0x1E0B00,
    "segment_1FB850" : 0x1FB850,
    "segment_21C170" : 0x21C170,
    "silence_3" : 0x230FB0,
    "sand_ocean_3" : 0x231790,
    "devils_forest_4" : 0x231F70,
    "port_town_3" : 0x232750,
    "devils_forest_5" : 0x232F30,
    "big_blue_3" : 0x233710,
    "mute_city_4" : 0x233EF0,
    "space_plant_2" : 0x2346D0,
    "port_town_4" : 0x234EB0,
    "fire_field_2" : 0x235690,
    "white_land_3" : 0x235E70,
    "big_foot" : 0x236650,
}

diskSegments = {
    "main" : 560,
    "ovl_xk1" : 598,
    "ovl_i3" : 602,
    "ovl_i4" : 613,
    "course_select" : 615,
    "ovl_i6" : 617,
    "ovl_i7" : 620,
    "ovl_i8" : 622,
    "ovl_i2" : 624,
    "ovl_i9" : 635,
    "ovl_i10" : 655,
    "course_edit" : 656,
    "machine_create" : 672,
    "ovl_xk4" : 677,
    "segment_1FB850" : 684,
    "segment_21C170" : 692,
    "silence_3" : 800,
    "sand_ocean_3" : 801,
    "devils_forest_4" : 802,
    "port_town_3" : 803,
    "devils_forest_5" : 804,
    "big_blue_3" : 805,
    "mute_city_4" : 806,
    "space_plant_2" : 807,
    "port_town_4" : 808,
    "fire_field_2" : 809,
    "white_land_3" : 810,
    "big_foot" : 811,
}

VERBOSE = False

def addSymbolToRelocate(relsOffetsToApply: dict[int, tuple[str, spimdisasm.common.RelocType]], symName: str, rel: spimdisasm.elf32.Elf32RelEntry, segmentRomOffset: int, segmentVram: int):
    relVram = rel.offset

    rType = spimdisasm.common.Relocation.RelocType.fromValue(rel.rType)
    assert rType is not None, rel.rType

    relRomOffset = relVram - segmentVram + segmentRomOffset
    relsOffetsToApply[relRomOffset] = (symName, rType)

def align(value: int, n: int) -> int:
    return (((value) + ((n)-1)) & ~((n)-1))

def align8MB(value: int) -> int:
    return align(value, 0x100000)

def main(argv):
    parser = argparse.ArgumentParser()

    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('rom', help="unpatched rom name")
    parser.add_argument('romp', help="patched rom name")
    parser.add_argument('elf', help="elf file name")
    parser.add_argument('version', help="version")

    args = parser.parse_args()

    VERBOSE = args.verbose
    rom = pathlib.Path(args.rom)
    romp = pathlib.Path(args.romp)
    elf = pathlib.Path(args.elf)
    version = args.version

    segmentOffsets: dict[str, tuple[int, int]] = {}
    relsOffetsToApply: dict[int, tuple[str, spimdisasm.common.RelocType]] = {}
    romOffsetValues: dict[str, int] = {}

    # spimdisasm.common.GlobalConfig.VERBOSE = VERBOSE

    elfBytearray = spimdisasm.common.Utils.readFileAsBytearray(elf)
    assert len(elfBytearray) > 0, f"'{elf}' could not be opened"

    romBytearray = spimdisasm.common.Utils.readFileAsBytearray(rom)
    assert len(romBytearray) > 0, f"'{rom}' could not be opened"

    elfFile = spimdisasm.elf32.Elf32File(elfBytearray)

    for entry in elfFile.sectionHeaders.sections:
        sectionEntryName = elfFile.shstrtab[entry.name]

        if entry.type == spimdisasm.elf32.Elf32SectionHeaderType.REL.value:
            sectionRels = spimdisasm.elf32.Elf32Rels(sectionEntryName, elfBytearray, entry.offset, entry.size)
            referencedSegment = sectionEntryName.replace(".rel.", ".")
            for rel in sectionRels.relocations:
                sym = elfFile.symtab[rel.rSym]

                symName = elfFile.strtab[sym.name]

                if symName.endswith("_ROM_START"):
                    segmentData = segmentOffsets[referencedSegment]

                    addSymbolToRelocate(relsOffetsToApply, symName, rel, segmentData[0], segmentData[1])


        if entry.type != spimdisasm.elf32.Elf32SectionHeaderType.PROGBITS.value:
            if VERBOSE:
                print(f"Skiping segment '{sectionEntryName}' because it isn't PROGBITS")
            continue

        entryFlags, unknownFlags = spimdisasm.elf32.Elf32SectionHeaderFlag.parseFlags(entry.flags)
        if spimdisasm.elf32.Elf32SectionHeaderFlag.ALLOC not in entryFlags:
            if VERBOSE:
                print(f"Skiping segment '{sectionEntryName}' because it doesn't have the alloc flag")
            continue

        if sectionEntryName[1:] not in patchedEntries:
            continue

        segmentOffsets[sectionEntryName] = (diskRomAddrs[sectionEntryName[1:]], entry.addr)
        romStartSymbol = f"{sectionEntryName[1:]}_ROM_START"

        romOffsetValues[romStartSymbol] = diskSegments[sectionEntryName[1:]]

        if VERBOSE:
            print()

    for relRomOffset, (symName, rType) in relsOffetsToApply.items():
        value = romOffsetValues[symName]
        hiValue = value >> 16
        loValue = value & 0xFFFF
        if loValue >= 0x8000:
            hiValue += 1

        if rType == spimdisasm.common.Relocation.RelocType.MIPS_HI16:
            struct.pack_into(f">H", romBytearray, relRomOffset+2, hiValue)
        elif rType == spimdisasm.common.Relocation.RelocType.MIPS_LO16:
            struct.pack_into(f">H", romBytearray, relRomOffset+2, loValue)
        elif rType == spimdisasm.common.Relocation.RelocType.MIPS_32:
            struct.pack_into(f">I", romBytearray, relRomOffset, value)
        else:
            assert False, rType

    romp.write_bytes(romBytearray)

    sys.exit()


if __name__ == "__main__":
    main(sys.argv[1:])
