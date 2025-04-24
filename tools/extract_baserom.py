from leo64dd_python import leo64dd
from leo64dd_python import leo64ddfile

import argparse
import pathlib

RESERVED_BLOCK_COUNT = 24
MAIN_BLOCK_START = 560
MAIN_BLOCK_END = 598
OVERLAY_BLOCKS = { 655, 598, 602, 613, 615, 617, 620, 622, 624 }

def leo_decode(ba):
    out = bytearray()
    out.extend(ba)

    for i in range (0, 256):
        out[(i * 17) % 256] = ba[i]

    return out

def main(args):
    print()

    with open(args.file, "rb") as infile:
        disk_img = bytearray(infile.read())
    disk_obj = leo64ddfile.load_disk_file(disk_img)

    romBA = bytearray()
    rom = pathlib.Path("baserom." + args.version + ".z64dd")

    for i in range(MAIN_BLOCK_START, MAIN_BLOCK_END):
        romBA.extend(disk_obj.get_lba(RESERVED_BLOCK_COUNT + i))

    romDecodedBA = leo_decode(romBA)

    rom.write_bytes(romDecodedBA)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Extracts an fzerox-expansion disk file to z64dd")
    parser.add_argument("--file", help="Baserom file (.ndd/.mame/.d64)", required=True)
    parser.add_argument("--version", help="Version (e.g. jp)", required=True)
    args = parser.parse_args()
    main(args)

