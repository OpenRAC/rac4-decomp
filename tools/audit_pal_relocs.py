#!/usr/bin/env python3
"""Audit relocation targets of exact C written for the PAL disc.

Run after compiling the selected src/pal/ files and updating config/pal/map.tsv:

    python3 tools/audit_pal_relocs.py func_L00_005422B8
    python3 tools/audit_pal_relocs.py                 # all exact native PAL C

Like audit_relocs.py, this checks the fields that a byte comparison masks:
calls, address halves, $gp accesses, literals and jump tables. A source's
retail place comes from the checked PAL map. Shared callees are resolved at
their address in the caller's level using config/pal/functions.tsv.

The full run needs tools/build.sh first. Missing objects, unknown requested
functions, mismatches and unresolved relocations make the command fail.
"""
import argparse
import json
import re
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile

import audit_relocs
import elf_layout
import level_catalogue
import levels
import match_map


ROOT = Path(__file__).resolve().parent.parent


def native_rows():
    levels.select("pal")
    return {row["name"]: row for row in match_map.read_map()
            if row["status"] == "match" and row["file"].startswith("src/pal/")}


def object_path(row):
    source = row["file"]
    return ROOT / "build" / "obj" / (source.removeprefix("src/").replace("/", "_")[:-2] + ".o")


class PalChecker(audit_relocs.Checker):
    """Use the existing relocation checker with PAL native placements."""

    def __init__(self, rows, catalogue=None, gp=None):
        levels.select("pal")
        if gp is None:
            with open(levels.main_elf(), "rb") as stream:
                reginfo = ELFFile(stream).get_section_by_name(".reginfo")
                if reginfo is None or len(reginfo.data()) < 24:
                    raise ValueError("PAL main ELF has no usable .reginfo")
                gp = struct.unpack_from("<I", reginfo.data(), 20)[0]
        self.gp = gp
        self.places = {}
        self.ovl = {}
        for row in rows:
            if len(row["places"]) != 1:
                raise ValueError("expected one PAL place for " + row["name"])
            program, _, address, size = row["places"][0]
            self.places[row["name"]] = (address, program)
            if program.startswith("level_"):
                self.ovl[row["name"]] = ("L" + program[-2:], address, size)
        if catalogue is None:
            catalogue = level_catalogue.read_catalogue()
        self.level_places = {
            (name, "L%02d" % level): address
            for name, _, _, _, _, places in catalogue
            for level, address in places
        }
        self.sections_cache = {}
        self.alias, self.lib_syms = {}, {}
        self.mismatches, self.unresolved, self.checked = [], [], 0
        self.by_code = {"unique": 0, "twin": 0, "catalogue": 0}

    def sections(self, program):
        if program not in self.sections_cache:
            with open(levels.program_path(program), "rb") as stream:
                self.sections_cache[program] = audit_relocs.mp.sections(ELFFile(stream))
        return self.sections_cache[program]

    def place(self, name):
        if name not in self.places:
            return None
        address, program = self.places[name]
        return address, self.sections(program)

    def same_code(self, name, level, target):
        # An overlay function keeps its first level's name in every other level.
        base = re.sub(r"(?:__gp|__lui|_)$", "", name)
        if self.level_places.get((base, level)) == target:
            return "catalogue"
        return None


def audit(rows, object_for=object_path):
    checker = PalChecker(rows)
    for row in rows:
        path = Path(object_for(row))
        if not path.is_file():
            raise FileNotFoundError("missing compiled object: %s (run tools/build.sh)" % path)
        with open(path, "rb") as stream:
            names = {function.name for function in elf_layout.functions(ELFFile(stream))}
        if row["name"] not in names:
            raise ValueError("compiled object %s does not define %s" % (path, row["name"]))
        checker.check_object(path, {row["name"]}, set())
    return checker


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("functions", nargs="*", help="PAL native function names; all if omitted")
    parser.add_argument("-v", "--verbose", action="store_true", help="show all unresolved references")
    args = parser.parse_args(argv)
    known = native_rows()
    missing = sorted(set(args.functions) - known.keys())
    if missing:
        parser.error("not exact native PAL functions: " + ", ".join(missing))
    rows = [known[name] for name in (args.functions or sorted(known))]
    try:
        checker = audit(rows)
    except (FileNotFoundError, ValueError) as error:
        parser.error(str(error))
    result = {"mismatches": checker.mismatches, "unresolved": checker.unresolved}
    report = ROOT / "build" / "pal_relocs.json"
    report.parent.mkdir(parents=True, exist_ok=True)
    report.write_text(json.dumps(result, indent=1) + "\n")
    print("%d relocations checked in %d exact PAL native functions: %d mismatches, %d unresolved"
          % (checker.checked, len(rows), len(checker.mismatches), len(checker.unresolved)))
    for row in checker.mismatches:
        offset = "" if row["offset"] is None else "+0x%X" % row["offset"]
        ours = "?" if row["ours"] is None else "0x%08X" % row["ours"]
        retail = "?" if row["retail"] is None else "0x%08X" % row["retail"]
        print("  %s%s %s %s: ours %s, retail %s%s"
              % (row["function"], offset, row["type"], row["symbol"], ours, retail,
                 " (" + row["note"] + ")" if "note" in row else ""))
    if args.verbose or len(checker.unresolved) <= 20:
        for row in checker.unresolved:
            print("  unresolved: %(function)s+0x%(offset)X %(type)s %(symbol)s" % row)
    return int(bool(checker.mismatches or checker.unresolved))


if __name__ == "__main__":
    raise SystemExit(main())
