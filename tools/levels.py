#!/usr/bin/env python3
"""levels.py: the discs' programs, from the ISO to the build's targets.

    python3 tools/levels.py [--version us|pal] dump     # baserom/<version>/ from baserom/<ID>.iso
    python3 tools/levels.py [--version us|pal] config   # config/<version>/levels.tsv, programs.tsv
    python3 tools/levels.py [--version us|pal] check    # the dumps agree with the committed tables

For dump and config, --iso PATH reads an existing disc image in place, instead of the default
baserom/<ID>.iso. It does not change the selected version or where the outputs are written.

Two versions, the same code and layout: `us` (the default, and the primary target), the NTSC-U
disc `baserom/SCUS_974.65.iso`; `pal`, the PAL disc `baserom/SCES_532.85.iso` ("Ratchet:
Gladiator", SCES-53285). `--version` (or the environment's RAC_VERSION) selects one for this
and every other tool that reads these tables. `baserom/SCUS_974.87.iso` is a beta: reference
only, never read here.

## The programs

  - `main`: the game image packed inside the loader (`SCUS_974.65` or `SCES_532.85`, an ISO9660
    file). The loader is copied to baserom/<version>/; its WAD blob is unpacked (tools/unpack_wad.py) into 17
    sections (tools/split_image.py's names: .vutext, core.*, the resident menu's .lit/.bss/
    .data/lvl.*/.text, patch.data, net.*).
  - `frontbin`: the front end, the same kind of program as a level (8 sections: .lit, .bss,
    .data, lvl.vtbl, lvl.camvtbl, lvl.sndvtbl, .text, net.text), loaded at 0x21E200 over the
    main image's resident menu.
  - 47 level programs, the same 8 sections each (levels 0, the multiplayer menu, store their
    second section as data, not as .bss zeros).

Every program on the disc is a list of sections, each a 16-byte record (destination, size,
ELF section type, entry point) followed by its bytes (a .bss's zeros too). Every record repeats
the entry point.

## Where they are on the disc (Wrench's src/iso/table_of_contents.cpp, docs/file_loading.md,
## src/wrenchbuild/level/level_wad.cpp, level_data_wad.cpp, globals/misc_wad.cpp)

All data is addressed by sector (0x800 bytes) through the table of contents at sector 1001:

  - the table opens with the global WAD headers, each starting (header size, sector), one
    after the other: 0x648 (the first words at sector 1001 are 0x648, 0x8FC, ...), 0x50 (the
    MISC wad), 0x2A8, 0x68, 0x228, 0xA870, 0xF88, 0x68. Deadlocked's level table follows at
    TOC offset 0xC430. (Wrench finds it by looking for six valid level-header pointers in a
    row, because the word after the last global header, 0x403, looks like one more header.)
  - the level table: one 24-byte entry per level number, three (header sector, size in
    sectors) pairs in the order AUDIO, LEVEL, SCENE (UYA's and Deadlocked's order). Empty
    numbers are zeros; the multiplayer levels have only a LEVEL file. The header sectors are
    inside the table of contents.
  - the LEVEL header (DlLevelWadHeader, 0xC68 bytes): +0x00 header size, +0x04 the file's
    sector, +0x08 the level number, +0x0C reverb, +0x10 max mission sizes, +0x18 `data`
    (sector offset in the file, sector count), +0x20 the sound bank, ...;
  - the level data (DlLevelDataHeader): +0x00 moby8355 pvars, +0x08 `overlay` (byte offset in
    the level data, byte size): the level program; then core index, GS RAM, HUD, core data...
  - the MISC wad (DlMiscWadHeader, the global header of size 0x50): +0x04 its sector, +0x20
    `frontbin` (sector offset, sector count): the front end's program, padded to whole
    sectors (the program ends where its last record ends).

## The dumps (baserom/, never committed)

Each program is written as an ELF (write_elf()): the ELF header, one PT_LOAD per section, the
sections' bytes back to back (16-aligned, a .bss of zeros has no file bytes), .shstrtab and the
section header table; sh_type is the disc's type word. `dump` checks that converting each ELF
back gives the disc's program byte for byte. config/<version>/levels.tsv and programs.tsv
keep the SHA-1 of the ELF and of the program as the disc stores it (the main image: as the
loader's WAD unpacks it), the entry point and the sections. The build (tools/build_levels.py)
compares what it builds with both.
"""
import argparse
import hashlib
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
TOC_LBA = 1001
SECTOR = 0x800
LEVEL_TABLE = 0xC430          # the TOC offset after the 8 global headers (the same on both discs)

# The two versions. `us` is the primary target (the repository was built on it); `pal` the second.
VERSIONS = {"us": "SCUS_974.65", "pal": "SCES_532.85"}
V = os.environ.get("RAC_VERSION", "us")


def select(version):
    """Make VERSION ('us' or 'pal') the one every path below refers to."""
    global V
    if version not in VERSIONS:
        sys.exit("unknown version %r (us or pal)" % version)
    V = version


def cli_version(argv=None):
    """Take `--version us|pal` (or `--version=...`) out of ARGV (sys.argv) and select it."""
    argv = sys.argv if argv is None else argv
    for i, x in enumerate(list(argv)):
        if x == "--version" and i + 1 < len(argv):
            select(argv[i + 1])
            del argv[i:i + 2]
            break
        if x.startswith("--version="):
            select(x.split("=", 1)[1])
            del argv[i]
            break
    return V


def version_id():
    return VERSIONS[V]


def cfg(name):
    """config/<version>/NAME: the version's committed tables."""
    return os.path.join(ROOT, "config", V, name)


def dump_dir():
    return os.path.join(ROOT, "baserom", V)


def iso_path():
    return os.path.join(ROOT, "baserom", version_id() + ".iso")


def loader_path():
    return os.path.join(dump_dir(), version_id())


def main_elf():
    return os.path.join(dump_dir(), "main.elf")

# level number -> (directory slug, title): the US decompilation's names (config/overlays.tsv)
NAMES = {
    0: ("multiplayer_menu", "Multiplayer Menu"),
    1: ("dreadzone_station", "Dreadzone Station"), 2: ("catacrom_graveyard", "Catacrom Graveyard"),
    4: ("sarathos_swamp", "Sarathos Swamp"), 5: ("dark_cathedral", "Dark Cathedral"),
    6: ("temple_of_shaar", "Temple Of Shaar"), 7: ("valix_lighthouse", "Valix Lighthouse"),
    8: ("mining_facility", "Mining Facility"), 10: ("torval_ruins", "Torval Ruins"),
    11: ("tempus_station", "Tempus Station"), 13: ("maraxus_prison", "Maraxus Prison"),
    14: ("ghost_station", "Ghost Station"), 15: ("control_level", "Control Level"),
    41: ("battledome_tower", "Battledome Tower"), 42: ("catacrom_graveyard_mp", "Catacrom Graveyard (multiplayer)"),
    44: ("sarathos_swamp_mp", "Sarathos Swamp (multiplayer)"), 45: ("dark_cathedral_mp", "Dark Cathedral (multiplayer)"),
    46: ("temple_of_shaar_mp", "Temple Of Shaar (multiplayer)"),
    47: ("valix_lighthouse_mp", "Valix Lighthouse (multiplayer)"),
    48: ("mining_facility_mp", "Mining Facility (multiplayer)"), 50: ("torval_ruins_mp", "Torval Ruins (multiplayer)"),
    51: ("tempus_station_mp", "Tempus Station (multiplayer)"), 53: ("maraxus_prison_mp", "Maraxus Prison (multiplayer)"),
    54: ("ghost_station_mp", "Ghost Station (multiplayer)"),
}
for _n in (1, 2, 4, 5, 6, 7, 8, 10, 11, 13, 14, 15):
    NAMES[_n + 20] = (NAMES[_n][0] + "_splitscreen", NAMES[_n][1] + " (split screen)")
for _n in (41, 42, 44, 45, 46, 47, 48, 50, 51, 53, 54):
    NAMES[_n + 20] = (NAMES[_n][0].replace("_mp", "") + "_mp_splitscreen",
                      NAMES[_n][1].replace(" (multiplayer)", "") + " (multiplayer, split screen)")
MULTIPLAYER = {0} | set(range(41, 75))

# the sections of a level program (and frontbin), in the program's order
LEVEL_SECTIONS = [".lit", ".bss", ".data", "lvl.vtbl", "lvl.camvtbl", "lvl.sndvtbl", ".text", "net.text"]
# the main image's (tools/split_image.py)
MAIN_SECTIONS = [".reginfo", ".vutext", "core.text", "core.data", "core.rdata", "core.bss",
                 "core.lit", ".lit", ".bss", ".data", "lvl.vtbl", "lvl.camvtbl",
                 "lvl.sndvtbl", ".text", "patch.data", "net.text", "net.nostomp"]
CODE_SECTIONS = {".vutext", "core.text", ".text", "net.text"}


def dirname(number):
    return "%02d_%s" % (number, NAMES[number][0])


def title(number):
    return "Level %02d: %s" % (number, NAMES[number][1])


def elf_path(number):
    return os.path.join(dump_dir(), "levels", dirname(number) + ".elf")


def program_path(name):
    """The dump of a program: 'main', 'frontbin', 'level_NN' or a level directory (NN_slug)."""
    if name == "main":
        return main_elf()
    if name == "frontbin":
        return os.path.join(dump_dir(), "frontbin.elf")
    if name.startswith("level_"):
        return elf_path(int(name[6:]))
    return os.path.join(dump_dir(), "levels", name + ".elf")


# --- the disc -----------------------------------------------------------------------

def iso_file(f, wanted):
    """(sector, size) of a file in the ISO9660 root directory."""
    f.seek(16 * SECTOR)
    pvd = f.read(SECTOR)
    if pvd[1:6] != b"CD001":
        sys.exit("not an ISO9660 image")
    lba, size = struct.unpack_from("<I", pvd, 158)[0], struct.unpack_from("<I", pvd, 166)[0]
    f.seek(lba * SECTOR)
    d = f.read(size)
    p = 0
    while p < len(d):
        n = d[p]
        if n == 0:
            p = (p // SECTOR + 1) * SECTOR
            continue
        name = d[p + 33:p + 33 + d[p + 32]].split(b";")[0].decode("ascii", "replace")
        if name == wanted:
            return struct.unpack_from("<I", d, p + 2)[0], struct.unpack_from("<I", d, p + 10)[0]
        p += n
    sys.exit("%s is not on the disc" % wanted)


def parse_records(raw, stop_at_padding=False):
    """(entry, [(address, size, type, bytes)], length used) of a program in the disc's format."""
    sections, p, ep = [], 0, None
    while p + 16 <= len(raw):
        dest, n, kind, e = struct.unpack_from("<4I", raw, p)
        if ep is None:
            ep = e
        if e != ep or (stop_at_padding and dest == 0 and n == 0):
            break
        sections.append((dest, n, kind, raw[p + 16:p + 16 + n]))
        p += 16 + n
    return ep, sections, p


def read_disc(iso=None):
    """{'main': (entry, sections, raw), 'frontbin': ..., level number: ...} and the loader."""
    import unpack_wad
    out = {}
    with open(iso or iso_path(), "rb") as f:
        lba, size = iso_file(f, version_id())
        f.seek(lba * SECTOR)
        loader = f.read(size)
        image = unpack_wad.decompress(loader, unpack_wad.find_wad(loader))
        ep, secs, used = parse_records(image)
        if used != len(image) or len(secs) != len(MAIN_SECTIONS):
            sys.exit("the main image has an unexpected layout")
        out["main"] = (ep, secs, image)
        f.seek(TOC_LBA * SECTOR)
        toc = f.read(0x100000)
        # the MISC wad: the global header of size 0x50
        ofs = 0
        misc = None
        for _ in range(8):
            hsize, sector = struct.unpack_from("<ii", toc, ofs)
            if hsize == 0x50:
                misc = (sector, struct.unpack_from("<ii", toc, ofs + 0x20))
            ofs += hsize
        if ofs != LEVEL_TABLE or misc is None:
            sys.exit("the table of contents has an unexpected layout")
        sector, (fofs, fsize) = misc
        f.seek((sector + fofs) * SECTOR)
        raw = f.read(fsize * SECTOR)
        ep, secs, used = parse_records(raw, stop_at_padding=True)
        if any(raw[used:]) or len(secs) != len(LEVEL_SECTIONS):
            sys.exit("frontbin has an unexpected layout")
        out["frontbin"] = (ep, secs, raw[:used])
        for i in range(100):
            audio, _, level, _, scene, _ = struct.unpack_from("<6i", toc, LEVEL_TABLE + 24 * i)
            if level <= TOC_LBA or (level - TOC_LBA) * SECTOR >= len(toc):
                continue          # no LEVEL file, or past the table (the entries end)
            at = (level - TOC_LBA) * SECTOR
            hsize, file_lba, number = struct.unpack_from("<3i", toc, at)
            if hsize != 0xC68:
                sys.exit("level table entry %d: not a LEVEL header" % i)
            if number not in NAMES:
                sys.exit("level table entry %d: unknown level number %d" % (i, number))
            data_ofs, _ = struct.unpack_from("<2i", toc, at + 0x18)
            base = (file_lba + data_ofs) * SECTOR
            f.seek(base + 8)
            prog_ofs, prog_size = struct.unpack("<ii", f.read(8))
            f.seek(base + prog_ofs)
            raw = f.read(prog_size)
            ep, secs, used = parse_records(raw)
            if used != len(raw) or len(secs) != len(LEVEL_SECTIONS):
                sys.exit("level %d: unexpected program layout" % number)
            out[number] = (ep, secs, raw)
    if sorted(k for k in out if isinstance(k, int)) != sorted(NAMES):
        sys.exit("levels on the disc: %s; expected %s" % (sorted(k for k in out if isinstance(k, int)), sorted(NAMES)))
    return out, loader


def records(entry, sections):
    """The disc's program format for (entry, [(address, size, type, bytes)])."""
    return b"".join(struct.pack("<4I", a, n, k, entry) + b for a, n, k, b in sections)


# --- the ELF dumps ------------------------------------------------------------------

def write_elf(entry, sections, names):
    """A program as an ELF (module docstring). sh_type is the disc's type word; a section of
    type 8 (NOBITS) must be zeros and has no file bytes."""
    off = 0x34 + 0x20 * len(sections)
    body = bytearray()
    lay = []
    for a, n, kind, b in sections:
        at = (off + len(body) + 15) & ~15
        body += bytes(at - off - len(body))
        if kind == 8:
            if any(b):
                sys.exit("section at 0x%X: type NOBITS but not zeros" % a)
        else:
            body += b
        lay.append(at)
    shstr = b"\0" + b"".join(s.encode() + b"\0" for s in names) + b".shstrtab\0"
    str_at = off + len(body)
    body += shstr
    shoff = (off + len(body) + 3) & ~3
    body += bytes(shoff - off - len(body))
    ehdr = b"\x7fELF\x01\x01\x01" + bytes(9) + struct.pack(
        "<HHIIIIIHHHHHH", 2, 8, 1, entry, 0x34, shoff, 0x20924001, 0x34, 0x20, len(sections), 40,
        len(sections) + 2, len(sections) + 1)
    phdrs = b""
    for (a, n, kind, _), at, name in zip(sections, lay, names):
        flags = 4 | (1 if name in CODE_SECTIONS else 0) | (2 if name not in CODE_SECTIONS else 0)
        phdrs += struct.pack("<8I", 1, at, a, a, 0 if kind == 8 else n, n, flags, 16)
    shdrs = bytes(40)
    k = 1
    for (a, n, kind, _), at, name in zip(sections, lay, names):
        flags = 2 | (4 if name in CODE_SECTIONS else 1)
        shdrs += struct.pack("<10I", k, kind, flags, a, at, n, 0, 0, 16, 0)
        k += len(name) + 1
    shdrs += struct.pack("<10I", k, 3, 0, 0, str_at, len(shstr), 0, 0, 1, 0)
    return ehdr + phdrs + bytes(body) + shdrs


def read_elf(data):
    """(entry, [(name, address, size, type, bytes)]) of an ELF (write_elf()'s, or any other with
    section headers: a built program)."""
    entry, shoff = struct.unpack_from("<I", data, 0x18)[0], struct.unpack_from("<I", data, 0x20)[0]
    shnum, shstrndx = struct.unpack_from("<HH", data, 0x30)
    sh = [struct.unpack_from("<10I", data, shoff + 40 * i) for i in range(shnum)]
    st = sh[shstrndx][4]
    out = []
    for s in sh[1:]:
        name = data[st + s[0]:data.index(b"\0", st + s[0])].decode()
        if s[1] == 3:
            continue
        b = bytes(s[5]) if s[1] == 8 else data[s[4]:s[4] + s[5]]
        out.append((name, s[3], s[5], s[1], b))
    return entry, out


def program_of_elf(data):
    """The disc's program bytes for a dumped ELF."""
    entry, secs = read_elf(data)
    return records(entry, [(a, n, k, b) for _, a, n, k, b in secs])


def sections_of(path):
    """{section name: (address, bytes)} of a dumped program."""
    _, secs = read_elf(open(path, "rb").read())
    return {name: (a, b) for name, a, n, k, b in secs}


# --- dump and tables ----------------------------------------------------------------

def all_programs(progs):
    """[(table key, dump path, names, (entry, sections, raw))] in table order."""
    out = [("main", main_elf(), MAIN_SECTIONS, progs["main"]),
           ("frontbin", program_path("frontbin"), LEVEL_SECTIONS, progs["frontbin"])]
    for n in sorted(k for k in progs if isinstance(k, int)):
        out.append((n, elf_path(n), LEVEL_SECTIONS, progs[n]))
    return out


def dump(write=True, iso=None):
    progs, loader = read_disc(iso)
    rows = []
    if write:
        os.makedirs(os.path.join(dump_dir(), "levels"), exist_ok=True)
        open(loader_path(), "wb").write(loader)
    for key, path, names, (entry, secs, raw) in all_programs(progs):
        elf = write_elf(entry, secs, names)
        if program_of_elf(elf) != raw:
            sys.exit("%s: the ELF does not convert back to the disc's program" % key)
        if write:
            open(path, "wb").write(elf)
        rows.append((key, entry, [(nm, a, n, k) for nm, (a, n, k, _) in zip(names, secs)],
                     hashlib.sha1(elf).hexdigest(), hashlib.sha1(raw).hexdigest()))
    if write:
        print("wrote %s, %s and %d level programs" % (os.path.relpath(loader_path(), ROOT), os.path.relpath(main_elf(), ROOT),
                                                      len(rows) - 2))
    return rows, hashlib.sha1(loader).hexdigest()


TABLE_HEAD = """# The %s level programs (tools/levels.py config): number, directory, title, SHA-1 of the ELF that
# tools/levels.py dump writes to baserom/%s/levels/<directory>.elf, SHA-1 of the program as the
# disc stores it, entry point, sections (name:address:size:type), and the lowest-numbered level
# whose program is byte-identical to this one (itself when none is).
"""
PROGRAMS_HEAD = """# The %s disc's other programs (tools/levels.py config): name, dump, SHA-1 of the dump, SHA-1 of the
# program as the disc stores it (main: as the loader's WAD unpacks it), entry, sections
# (name:address:size:type). The loader %s itself: see the `loader` row.
"""


def secs_text(secs):
    return ",".join("%s:%08X:%X:%X" % s for s in secs)


def write_config(iso=None):
    rows, loader_sha1 = dump(write=False, iso=iso)
    first = {}
    lines = [(TABLE_HEAD % (version_id(), V)).rstrip("\n")]
    plines = [(PROGRAMS_HEAD % (version_id(), version_id())).rstrip("\n")]
    plines.append("\t".join(["loader", os.path.relpath(loader_path(), ROOT), loader_sha1, loader_sha1, "-", "-"]))
    for key, entry, secs, elf_sha1, raw_sha1 in rows:
        if isinstance(key, int):
            same = first.setdefault(raw_sha1, key)
            lines.append("\t".join([str(key), dirname(key), NAMES[key][1], elf_sha1, raw_sha1, "%08X" % entry,
                                    secs_text(secs), str(same)]))
        else:
            plines.append("\t".join([key, os.path.relpath(program_path(key), ROOT), elf_sha1, raw_sha1,
                                     "%08X" % entry, secs_text(secs)]))
    os.makedirs(os.path.dirname(cfg("levels.tsv")), exist_ok=True)
    open(cfg("levels.tsv"), "w", newline="\n").write("\n".join(lines) + "\n")
    open(cfg("programs.tsv"), "w", newline="\n").write("\n".join(plines) + "\n")
    copies = sum(1 for l in lines[1:] if l.split("\t")[0] != l.split("\t")[-1])
    print("wrote %s (%d levels, %d byte-identical copies of another) and %s" % (
        os.path.relpath(cfg("levels.tsv"), ROOT), len(lines) - 1, copies, os.path.relpath(cfg("programs.tsv"), ROOT)))


def _secs(field):
    out = []
    for s in field.split(","):
        name, a, n, k = s.split(":")
        out.append((name, int(a, 16), int(n, 16), int(k, 16)))
    return out


def read_table(path=None):
    """[{number, dir, title, elf_sha1, program_sha1, entry, sections, copy_of}]"""
    out = []
    for line in open(path or cfg("levels.tsv"), encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.rstrip("\n").split("\t")
        out.append({"number": int(f[0]), "dir": f[1], "title": f[2], "elf_sha1": f[3], "program_sha1": f[4],
                    "entry": int(f[5], 16), "sections": _secs(f[6]), "copy_of": int(f[7])})
    return out


def read_programs(path=None):
    """{name: {dump, elf_sha1, program_sha1, entry, sections}} (main, frontbin, loader)"""
    out = {}
    for line in open(path or cfg("programs.tsv"), encoding="utf-8"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.rstrip("\n").split("\t")
        out[f[0]] = {"dump": f[1], "elf_sha1": f[2], "program_sha1": f[3],
                     "entry": None if f[4] == "-" else int(f[4], 16),
                     "sections": [] if f[5] == "-" else _secs(f[5])}
    return out


def targets():
    """[(target name, dump path, elf_sha1, program_sha1, sections)]: main, frontbin, level_NN."""
    p = read_programs()
    out = [(k, os.path.join(ROOT, p[k]["dump"]), p[k]["elf_sha1"], p[k]["program_sha1"], p[k]["sections"])
           for k in ("main", "frontbin")]
    for r in read_table():
        out.append(("level_%02d" % r["number"], elf_path(r["number"]), r["elf_sha1"], r["program_sha1"],
                    r["sections"]))
    return out


def check():
    bad = 0
    for name, path, elf_sha1, _, _ in targets():
        h = hashlib.sha1(open(path, "rb").read()).hexdigest() if os.path.exists(path) else "missing"
        if h != elf_sha1:
            print("%s: %s is %s, the table says %s" % (name, os.path.relpath(path, ROOT), h, elf_sha1))
            bad += 1
    print("%d dumps checked, %d differ" % (len(targets()), bad))
    return 1 if bad else 0


def main():
    parser = argparse.ArgumentParser(description="Dump a disc's programs and check their tables.")
    parser.add_argument("command", choices=("dump", "config", "check"))
    parser.add_argument("--version", choices=VERSIONS, default=V,
                        help="disc version (default: RAC_VERSION, or us)")
    parser.add_argument("--iso", metavar="PATH", help="input disc image for dump/config (default: baserom/<ID>.iso)")
    args = parser.parse_args()
    if args.iso is not None and args.command == "check":
        parser.error("--iso applies to dump and config; check reads the extracted dumps")
    select(args.version)
    if args.command == "dump":
        dump(iso=args.iso)
    elif args.command == "config":
        write_config(iso=args.iso)
    else:
        sys.exit(check())


if __name__ == "__main__":
    main()
