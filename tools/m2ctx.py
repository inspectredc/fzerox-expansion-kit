#!/usr/bin/env python3

import argparse
import os
import sys
import subprocess
import tempfile
from pathlib import Path

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / ".."
src_dir = root_dir / "src"

# Project-specific
CPP_FLAGS = [
    "-Iinclude",
    "-Iinclude/libc",
    "-Isrc",
    "-Iassets",
    "-Ibuild",
    "-I.",

    "-D__sgi",
    "-D_LANGUAGE_C",
    "-DNON_MATCHING",
    "-D_MIPS_SZLONG=32",
    "-ffreestanding",
    "-DM2CTX",
    "-DF3DEX_GBI_2",

    "-std=gnu89",
]

def import_c_file(in_file) -> str:
    in_file = os.path.relpath(in_file, root_dir)

    cpp_command = ["gcc", "-E", "-P", "-undef", "-dM", *CPP_FLAGS, in_file]
    cpp_command2 = ["gcc", "-E", "-P", "-undef", *CPP_FLAGS, in_file]

    with tempfile.NamedTemporaryFile(suffix=".c") as tmp:
        stock_macros = subprocess.check_output(["gcc", "-E", "-P", "-undef", "-dM", tmp.name], cwd=root_dir, encoding="utf-8")

    out_text = ""
    try:
        out_text += subprocess.check_output(cpp_command, cwd=root_dir, encoding="utf-8")
        out_text += subprocess.check_output(cpp_command2, cwd=root_dir, encoding="utf-8")
    except subprocess.CalledProcessError:
        print(
            "Failed to preprocess input file, when running command:\n"
            + " ".join(cpp_command),
            file=sys.stderr,
            )
        sys.exit(1)

    if not out_text:
        print("Output is empty - aborting")
        sys.exit(1)

    for line in stock_macros.strip().splitlines():
        out_text = out_text.replace(line + "\n", "")
    return out_text


def main():
    parser = argparse.ArgumentParser(usage="./m2ctx.py path/to/file.c or ./m2ctx.py (from an actor or gamestate's asm dir)",
                                     description="Creates a ctx.c file for m2c or decomp.me. "
                                     "Output will be saved as ctx.c")
    parser.add_argument('filepath', help="path of c file to be processed")
    args = parser.parse_args()

    c_file_path = args.filepath
    print("Using file: {}".format(c_file_path))

    output = import_c_file(c_file_path)

    ctxPath = root_dir / "ctx.c"
    with ctxPath.open("w", encoding="UTF-8") as f:
        f.write(output)


if __name__ == "__main__":
    main()
