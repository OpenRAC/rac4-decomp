# The discs: their programs, their build, and how the functions are counted

Two versions, built and counted the same way, with the same tools (`--version us|pal`, US by
default):

| Version | Disc | ISO (yours, never committed) | Role |
| --- | --- | --- | --- |
| `us` | NTSC-U v1.00 | `baserom/SCUS_974.65.iso` | the primary target: the C in `src/` was matched against it |
| `pal` | PAL, *Ratchet: Gladiator* (`SCES-53285`) | `baserom/SCES_532.85.iso` | the second version |

`baserom/SCUS_974.87.iso` is a beta: a reference only, never a target and never counted. The
per-function US build and audit (`tools/build.sh`, `tools/audit_matches.py` against
`baserom/SCUS_974.65.elf` and the US overlays, `docs/OVERLAYS.md`) are unchanged.

## The programs on each disc

| Program | What it is | Code sections counted |
| --- | --- | --- |
| `main` | the game image the loader (`SCUS_974.65` / `SCES_532.85`) unpacks: 17 sections, entry `0x1574E8` | `core.text`, `net.text`, the resident menu `.text` |
| `frontbin` | the front end, loaded over the main image's menus | its `.text` (the menu `.text` linked a second time) |
| `level_NN` | the 47 level programs: `.lit .bss .data lvl.vtbl lvl.camvtbl lvl.sndvtbl .text net.text` | `.text` |

`.vutext` is VU microcode (no EE code) and is not counted, as in rac3-uya-decomp-pal. `net.text`
is the same 0x97330 bytes in every program of a disc; it is counted once, in the main image.

    python3 tools/levels.py dump      # baserom/us/: SCUS_974.65 (the loader), main.elf, frontbin.elf, levels/NN_slug.elf
    python3 tools/levels.py config    # config/us/levels.tsv, config/us/programs.tsv
    python3 tools/levels.py check     # the dumps against the committed SHA-1s
    python3 tools/levels.py --version pal dump      # the same for PAL: baserom/pal/, config/pal/

To use an ISO where it already lives, pass `--iso` to `dump` or `config`. Quote paths with
spaces, for example:

    python3 tools/levels.py --version pal dump --iso "/path/to/Ratchet Gladiator.iso"
    python3 tools/levels.py --version pal check

The version still needs to match the disc (`--version pal` for `SCES_532.85`); `--iso` only
changes the input path. Dumps and tables stay under `baserom/<version>/` and `config/<version>/`.
`check` needs only the dumps, so it does not accept `--iso`.

`dump` reads the ISO directly (no Wrench unpack): the loader from the ISO9660 root, its WAD
unpacked by `tools/unpack_wad.py`; frontbin through the MISC wad; the levels through the table
of contents at sector 1001. Deadlocked's table is not laid out like UYA's: the docstring of
`tools/levels.py` has the format, from Wrench's `src/iso/table_of_contents.cpp`,
`src/wrenchbuild/level/level_wad.cpp`, `level_data_wad.cpp` and `globals/misc_wad.cpp`; both discs
put the level table at TOC offset 0xC430. Each program is written as an ELF and checked to
convert back to the disc's bytes; `config/<version>/levels.tsv` and `programs.tsv` keep the
SHA-1 of the ELF and of the program as the disc stores it, the entry point and the sections.

On the US disc the loader is byte for byte `baserom/SCUS_974.65` (SHA-1
`aa91b1c3b9b1a244320c47580b77342ef9856e95`), the main image's sections are those of
`baserom/SCUS_974.65.elf` (tools/split_image.py), and every level's `.text` is the `.text` of the
wrench-unpacked US overlay the existing C was matched against.

### The levels

Each disc has 47 level programs but only **14 distinct ones**: the 12 split-screen campaign
levels (21-35) are byte-identical copies of the single-player levels (1-15), and all 22
multiplayer maps (41-54, 61-74) carry one and the same program (level 41's). The last column of
`config/<version>/levels.tsv` says which; it is the same on both discs. (The copies differ only in
their other files: geometry, mobys, sound.)

| Level | Also (byte-identical copies) | US `.text` | US own functions | PAL `.text` | PAL own functions |
| --- | --- | --- | ---: | --- | ---: |
| 00 Multiplayer Menu |  | `0x4EEF00` +`0x28F220` | 2,798 (943,140 bytes) | `0x4EF400` +`0x294100` | 2,826 (943,820 bytes) |
| 01 Dreadzone Station | 21 | `0x3C7C80` +`0x2FEA50` | 356 (188,848 bytes) | `0x3C7E00` +`0x304040` | 357 (189,772 bytes) |
| 02 Catacrom Graveyard | 22 | `0x3BFF80` +`0x2B66D0` | 35 (26,596 bytes) | `0x3C0180` +`0x2BB600` | 29 (21,232 bytes) |
| 04 Sarathos Swamp | 24 | `0x3BF200` +`0x2B7498` | 19 (11,708 bytes) | `0x3BF400` +`0x2BC248` | 19 (11,868 bytes) |
| 05 Dark Cathedral | 25 | `0x3C1780` +`0x2DB6E8` | 102 (59,824 bytes) | `0x3C1980` +`0x2E0698` | 106 (61,960 bytes) |
| 06 Temple Of Shaar | 26 | `0x3BEF00` +`0x2AFDE0` | 31 (9,360 bytes) | `0x3BF000` +`0x2B4990` | 31 (9,440 bytes) |
| 07 Valix Lighthouse | 27 | `0x3BF300` +`0x2A29C8` | 46 (28,304 bytes) | `0x3BF400` +`0x2A72B8` | 44 (27,640 bytes) |
| 08 Mining Facility | 28 | `0x3BF200` +`0x2BA998` | 48 (24,400 bytes) | `0x3BF380` +`0x2BF908` | 48 (24,900 bytes) |
| 10 Torval Ruins | 30 | `0x3C0580` +`0x2C3970` | 37 (20,140 bytes) | `0x3C0700` +`0x2C88A0` | 38 (20,392 bytes) |
| 11 Tempus Station | 31 | `0x3BE500` +`0x2B2C50` | 17 (8,804 bytes) | `0x3BE680` +`0x2B7900` | 17 (9,024 bytes) |
| 13 Maraxus Prison | 33 | `0x3C0500` +`0x2CA518` | 34 (16,916 bytes) | `0x3C0600` +`0x2CF5C8` | 34 (15,996 bytes) |
| 14 Ghost Station | 34 | `0x3C0A00` +`0x2C3968` | 29 (14,548 bytes) | `0x3C0B80` +`0x2C8918` | 23 (8,884 bytes) |
| 15 Control Level | 35 | `0x3C4C00` +`0x2CFC40` | 135 (116,368 bytes) | `0x3C4D80` +`0x2D4D30` | 134 (116,624 bytes) |
| 41 Battledome Tower | the other 21 multiplayer maps (42-54, 61-74) | `0x3A1580` +`0x28DAA8` | 374 (139,984 bytes) | `0x3A1780` +`0x2921C8` | 374 (140,340 bytes) |

## Building them (`MATCH` for all 49 targets of each disc)

    python3 tools/build_levels.py --asm -P 16 --rounds 3                   # US: main, frontbin, level_00 ... level_74
    python3 tools/build_levels.py --version pal --asm -P 16 --rounds 3     # PAL

Every program is a target (`main`, `frontbin`, `level_NN`). `tools/asm_programs.py` writes its
assembly from the dump: one `.s` per function, named as the function tables name it
(`asm/<version>/<program>/<section>/<name>.s`; a level that is a copy of another is built from
that level's, `net.text` from the main image's), the data sections as `.word` lines, and the
linker script (`build/<version>/<target>/<target>.ld`) that puts every section at its address.
`tools/build_levels.py` assembles each section with the repository's toolchain
(`toolchain/sn-prodg-24`: binutils 2.10-ee `ee-as` and `ee-ld`, run natively on Linux; on a Mac
through `tools/docker/run.sh`), links, puts the sections back into the disc's program format and
prints `MATCH` when both SHA-1s are the disc's (the program as the disc stores it, and the dump's
ELF). The programs are built first, then the copies built from their assembly. All 49 targets
match on both discs:

    US:  main: MATCH: as the disc stores it sha1 518d45bdf27352fbf752252666a1b4bc5635102a
         frontbin ... 1755364d4decf4b6f1aa72720c33a603e086c646, level_00 ... 209b2ed1f0a4ae88a6a643f46e3642dde333fb5a,
         level_01 and 21 ... ede05221ddaf64abb39290c840e5167a085c39c5, level_41 and the other maps ... b507d4c6368abc07c7cd01ea1de02ffb7b794742
         49 of 49 targets match
    PAL: main ... dcfac0aab50b16d64f7c921888258a82afcab53a, frontbin ... da501734355880aa3c2b6f9afbac1630e24d3d0e,
         level_00 ... 9debe58ea65ba4b6a582814eb8ab19815b04fa7a, level_41 and the other maps ... dac41d0a93557917ee51b0e22c62426f50cf9596
         49 of 49 targets match

The instructions come from rabbitizer (R5900, no pseudo-instructions); branch targets are local
labels, calls and jumps to a function of the same program use its name. What binutils 2.10-ee
cannot assemble as it is becomes `.word` with the disassembly in a comment: VU0 macro-mode
instructions (`vmulq`, `vadday`, ... in rabbitizer's spelling), COP0 moves, `ldc1`/`sdc1`, short
loops it refuses in `noreorder` code, and words of data among code. The build finds them itself
(`asm/<version>/<program>/words.txt`, `--rounds`): about 3,800 in a main image and 11,000 to
12,600 per level program (of 750,000 or so words). Code sections are assembled in parts of about
8 KB that no branch crosses, because the old assembler takes time quadratic in a file's size (one
1.4 MB file took ten minutes; the parts take seconds).

This differs from rac3-uya-decomp-pal, which runs splat per level: here the per-function `.s`
and the linker scripts come straight from the committed function tables, so the build and the
count cut the code in the same places, and nothing needs the "halt function search" or fill
fixes splat needed there.

**C is not built into these programs yet** (rac3-uya-decomp-pal does the same): the targets prove
the tables, the dumps and the assembly; the next step is building `src/` C in place of a
function's `.s`, renaming what it refers to by the catalogue.

## Counting functions (`config/<version>/inventory.tsv`, `functions.tsv`)

The functions are found from the binaries with rac1-decomp's rules (`tools/overlays.py
split()`, `code_size()`, `tools/overlay_remnants.py` there), ported from rac3-uya-decomp-pal's
`tools/inventory.py` and applied the same way to every code section of each disc:

- **starts**: the section's start and the entry point; every `jal`, `bgezal` or `bltzal` target;
  the instruction after a `jr $ra` and its delay slot, past the zero words after it; after a `j`
  and its delay slot when a frame opener follows; a frame opener right after a zero word; a
  pointer in the program's data that points just after finished code; the `lvl.*` tables'
  pointers;
- **joined**: a conditional branch never leaves its function, so a start that one crosses is not
  a start, unless a call or a dispatch table reaches it;
- **proven**: where C in `src/` builds to the disc's bytes (`config/<version>/map.tsv`), the
  function starts and ends where the C does;
- **size**: without the zero words after it, but with its last jump's delay slot; an entry of
  only zero words or `0xCDCDCDCD` fill is padding, not a function;
- **linker remnants**: an 8-aligned entry of words that are not jumps or branches, after finished
  code, that nothing branches to or points at. They count as functions (finished original bytes).

Then each distinct function counts once (`tools/level_catalogue.py`, rac1-decomp's and
rac2-decomp's catalogue): two places are one function when their instructions are equal apart
from what linking changes (`inventory.identity()`: jump targets and address halves are masked,
except those into the resident core and `net.text`; constants, stack slots and field offsets are
compared) and their sizes are equal; the k-th copy of identical code in each level is one
function. The 33 copy levels are not cut again: they are their level.

- **frontbin** (`frontend_pairs.tsv`): frontbin's `.text` is the main image's resident menu
  `.text` linked a second time. Its functions with the identity and size of a menu function, in
  the same order (unique ones as anchors, repeated ones copy by copy between two anchors), count
  once, with the main image: 4,752 of 4,777 on the US disc, 4,768 of 4,785 on PAL.
- **levels**: on the US disc, 106,632 function places in the 14 distinct level programs are
  12,641 distinct functions: 3,499 are the menu `.text`'s (counted with the main image), 5 are
  frontbin's own, 5,076 are shared by two or more distinct programs and 4,061 are in one only (the
  multiplayer menu, level 00, has 2,798 of them). PAL: 107,276 places, 12,701 functions (3,530,
  3, 5,088, 4,080).

| Class | US functions | US bytes | PAL functions | PAL bytes |
| --- | ---: | ---: | ---: | ---: |
| Main image `core.text` (libgcc 31 and libm 27 included) | 1,697 | 298,916 | 1,701 | 299,068 |
| Main image `net.text` | 2,441 | 465,620 | 2,441 | 465,620 |
| Main image resident menu `.text` | 4,785 | 1,416,576 | 4,786 | 1,422,048 |
| frontbin's own | 25 | 12,168 | 17 | 15,776 |
| Shared level code | 5,076 | 1,980,204 | 5,088 | 2,008,520 |
| Level-specific code | 4,061 | 1,608,940 | 4,080 | 1,601,892 |
| **Total** | **18,085** | **5,782,424** | **18,113** | **5,812,924** |

Linker remnants (US): 91 of the `core.text` functions, 59 of `net.text`'s, 559 of the menu
`.text`'s and 735 of the level catalogue's.

### Old against new totals (US)

The earlier count (`tools/gen_progress_report.py`, now writing `build/legacy_report.json` only)
had **15,056 functions, 5,175,440 bytes**: `config/functions.tsv` (US `core.text` 1,710 /
299,180 bytes, `net.text` 2,434 / 465,672, resident `.text` 3,883 / 974,772) and
`config/overlay_functions.tsv` (the US overlays split by `tools/split_overlays.py`: 4,714 common
/ 2,603,676 and 2,315 level-specific / 832,140; 3,869 identical to the resident text left out).
Counted from the same US binaries with the rules above it is **18,085 functions, 5,782,424
bytes**:

| | Old | New | What changed |
| --- | ---: | ---: | --- |
| `core.text` | 1,710 / 299,180 | 1,697 / 298,916 | 1,668 starts are the same (1,626 with the same size); 42 old starts are gone (pieces joined to the function before: an early return or trap block after a `jr $ra`), 29 new ones; 3,868 bytes of padding after functions no longer counted (the old sizes ran to the next start); 91 linker remnants |
| `net.text` | 2,434 / 465,672 | 2,441 / 465,620 | 2,427 starts the same; 7 joined, 14 new; 2,972 bytes of padding; 59 remnants |
| resident `.text` | 3,883 / 974,772 | 4,785 / 1,416,576 | the old list had seven holes `tools/find_functions.py` could not cut (452,388 bytes; one of 392,472 at `0x40A3F8`, code with data in it), so it covered 974,772 of the section's 1,427,160 bytes; the inventory cuts all of it: 1,161 new starts (133 of them remnants), 259 old ones joined, 45,332 bytes of padding |
| frontbin | not counted | 25 / 12,168 | a second program the old count never had; its 4,752 copies of menu functions count once |
| level code | 7,029 / 3,435,816 | 9,137 / 3,589,144 | see below |
| **Total** | **15,056 / 5,175,440** | **18,085 / 5,782,424** | |

The level code changes for three reasons:

1. **Copies.** The old split counted all 47 overlays, so a function in level 01 and its
   split-screen copy 21 was "common": 1,086 of its 4,714 common functions (646,108 bytes) are in
   one distinct program only, and every function outside the multiplayer menu was common (the
   2,315 level-specific ones were all level 00's). Here the copies are their level: 4,061
   functions belong to one distinct program, 5,076 are shared.
2. **Identity.** The old split's `retail.normalise()` masks every immediate of a load, store or
   add and every `lui`, so routines that differ in a constant or a field offset were one
   function. `inventory.identity()` compares constants, stack slots and field offsets (only
   address fields are masked), so they are separate functions here: more distinct functions in
   fewer bytes each (the shared code is 5,076 functions in 1,980,204 bytes against the old
   3,628 truly shared ones in 1,957,568).
3. **Cutting rules.** Joined pieces, padding left out of the sizes, 735 linker remnants, starts
   from data pointers and dispatch tables. The menu `.text` functions found in the levels (3,499
   here, 3,869 in the old split) are counted with the main image in both.

### PAL against US

PAL has 18,113 functions in 5,812,924 bytes: 28 more functions and 30,500 more bytes than the US
disc. Its main image is the same size in `core.text` (+152 bytes) and `net.text` (equal), its menu
`.text` 5,472 bytes longer, and its level programs' `.text` 18 to 23 KB longer each (level 01:
`0x304040` bytes against `0x2FEA50`); the rules and the copies are the same.

## Carrying the matches (`config/<version>/map.tsv`)

`tools/match_map.py --write` (after `tools/build.sh`, `build_libgcc.sh`, `build_libm.sh`) looks up
every function of `src/` in the disc's programs: its compiled code, with the file's own flags,
is searched for in the section that holds its kind of code, comparing words with only the fields
its object relocates masked, exactly as `tools/audit_matches.py` compares (constants and offsets
must be equal; no per-function flags). On the US disc a find at the address the function's name
gives wins; on PAL a place where the inventory starts a function of that size, then the one
nearest the address the unique finds around it predict.

**US.** All **2,019** functions `tools/audit_matches.py` finds exact match at their own address,
and land in **2,017** distinct functions of the count:

| Category | Functions | Bytes |
| --- | ---: | ---: |
| Engine core (`core.text`) | 336 | 7,932 |
| libgcc | 24 | 6,132 |
| libm | 27 | 7,744 |
| Network (`net.text`) | 52 | 2,464 |
| Resident menus (`.text`) | 726 | 61,688 |
| frontbin's own | 2 | 796 |
| Shared level code | 478 | 68,860 |
| Level-specific code | 372 | 55,016 |
| **Total** | **2,017** (exact 3.64% of the code; fuzzy 4.09%) | **210,632** |

Two pairs of them are one function each, so they count once: `func_L01_00591BD8` is the menu
function `func_00473A88` (the level 01 copy of it), and `func_L41_003BFCB8` is the shared function
`func_L01_0043B938`. Both files keep building and passing the audit. Seven US names are counted
under another catalogue name because their code is a function counted elsewhere:
`func_L00_005E1870` (the menu's `func_0046FD10`), `func_L00_006FCB68` and `func_L00_006FFC68`
(frontbin's own `func_FB_00544408`, `func_FB_00547028`), `func_L01_00427C40` (`func_00430C10`),
`func_L01_00591BD8` (`func_00473A88`), `func_L01_005A8C48` (`func_0047EBC0`) and
`func_L41_003BFCB8` (`func_L01_0043B938`). None of the 2,019 is lost to a cut: where C starts or
ends a function the inventory did not, it takes the C's extent as proven.

The near misses in `nonmatching/` give the fuzzy figure: 137 are of a US function (their
closeness, the verdict on their first line, rac1-decomp's `closeness()`), 9 are not.

**PAL.** 1,987 of them match PAL too (1,985 distinct functions: 1,163 of the main image, 458
shared, 364 level-specific; exact 3.47%, fuzzy 3.88%). **32 match the US disc only** (`differs`
rows on PAL; their C stays in `src/`): most are the 60 Hz constants of NTSC against PAL's 50 Hz
(30 frames against 25, 60 against 50, 300 against 250, a float 60.0 against 50.0) or a count of
languages; nine have no PAL function with the same code at all. 135 near misses are of a PAL
function with the US function's code (closeness carried over), 11 are not.

| US function | Source | PAL function | What differs on PAL |
| --- | --- | --- | --- |
| `func_004A2698` | `src/game/004A2698.c` | - | no PAL function has the US code (changed for PAL) |
| `func_004AD3E0` | `src/game/004AD3E0.c` | - | no PAL function has the US code (changed for PAL) |
| `func_004F55E0` | `src/game/004F55E0.c` | `func_004F6660` | `addiu $a0, $zero, 0x6` → `addiu $a0, $zero, 0x5`; `addiu $v1, $zero, 0x12C` → `addiu $v1, $zero, 0xFA` (+1 more) |
| `func_00522C70` | `src/game/00522C70.c` | `func_00523E68` | `addiu $a2, $zero, 0x7` → `addiu $a2, $zero, 0x6`; `addiu $a2, $zero, 0x7` → `addiu $a2, $zero, 0x6` |
| `func_L00_00593FD0` | `src/overlays/shared/L00_00593FD0.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L00_00599350` | `src/overlays/shared/L00_00599350.c` | `func_L00_00599F58` | `addiu $a0, $a1, -0x3970` → `addiu $a0, $a1, -0x3870`; `addiu $v1, $v1, 0x2710` → `addiu $v1, $v1, 0x2850` (+23 more) |
| `func_L00_006091A8` | `src/overlays/shared/L00_006091A8.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L00_006ADAA0` | `src/overlays/shared/L00_006ADAA0.c` | `func_L00_006B12C0` | `slti $a0, $v0, 0x1E` → `slti $a0, $v0, 0x19` |
| `func_L00_006B7EB8` | `src/overlays/shared/L00_006B7EB8.c` | `func_L00_006BB798` | `lwc1 $f0, -0x541F($gp)` → `lwc1 $f0, -0x53EF($gp)`; `lbu $v0, -0x21C3($v0)` → `lbu $v0, -0x213B($v0)` (+2 more) |
| `func_L00_006EE7E8` | `src/overlays/shared/L00_006EE7E8.c` | `func_L00_006F23A8` | `slti $v0, $v0, 0x97` → `slti $v0, $v0, 0x7E` |
| `func_L00_00711A80` | `src/overlays/l00_multiplayer_menu/L00_00711A80.c` | `func_L00_007158A0` | `addiu $a2, $zero, 0x2D` → `addiu $a2, $zero, 0x25`; `addiu $a1, $a1, 0xC10` → `addiu $a1, $a1, 0xCD0` |
| `func_L00_00714610` | `src/overlays/l00_multiplayer_menu/L00_00714610.c` | `func_L00_00718458` | `addiu $a2, $zero, 0x2D` → `addiu $a2, $zero, 0x25`; `addiu $a1, $a1, 0xC68` → `addiu $a1, $a1, 0xD28` |
| `func_L00_00719430` | `src/overlays/l00_multiplayer_menu/L00_00719430.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L00_00743DA0` | `src/overlays/l00_multiplayer_menu/L00_00743DA0.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L01_003EE3D8` | `src/overlays/shared/L01_003EE3D8.c` | `func_L01_003EECB0` | `addiu $a2, $zero, 0xA` → `addiu $a2, $zero, 0x8` |
| `func_L01_0044AA78` | `src/overlays/shared/L01_0044AA78.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L01_0045FE18` | `src/overlays/shared/L01_0045FE18.c` | `func_L01_00461100` | `addiu $a2, $zero, 0x7` → `addiu $a2, $zero, 0x6`; `addiu $a2, $zero, 0x11` → `addiu $a2, $zero, 0xE` |
| `func_L01_00469AF8` | `src/overlays/shared/L01_00469AF8.c` | `func_L01_0046AEE0` | `addiu $v1, $zero, 0x6` → `addiu $v1, $zero, 0x5` |
| `func_L01_0047E238` | `src/overlays/shared/L01_0047E238.c` | `func_L01_0047F798` | `sltiu $v0, $v0, 0x5` → `sltiu $v0, $v0, 0x4` |
| `func_L01_004B6F50` | `src/overlays/shared/L01_004B6F50.c` | `func_L01_004B8A78` | `addiu $a1, $zero, 0x3C` → `addiu $a1, $zero, 0x32` |
| `func_L01_004C22F0` | `src/overlays/shared/L01_004C22F0.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L01_004CF6B0` | `src/overlays/shared/L01_004CF6B0.c` | `func_L01_004D15D8` | `addiu $a1, $zero, 0x78` → `addiu $a1, $zero, 0x64` |
| `func_L01_004DDFC8` | `src/overlays/shared/L01_004DDFC8.c` | `func_L01_004DFF68` | `lui $at, 0x4270` → `lui $at, 0x4248` |
| `func_L01_004EFD50` | `src/overlays/shared/L01_004EFD50.c` | `func_L01_004F1D18` | `sltiu $v0, $v0, 0x78` → `sltiu $v0, $v0, 0x64` |
| `func_L01_00558B10` | `src/overlays/shared/L01_00558B10.c` | `func_L01_0055B6A8` | `lw $v0, -0x2248($v0)` → `lw $v0, -0x21C0($v0)`; `lw $v0, -0x2248($v0)` → `lw $v0, -0x21C0($v0)` |
| `func_L01_0056C6C0` | `src/overlays/shared/L01_0056C6C0.c` | - | no PAL function has the US code (changed for PAL) |
| `func_L02_004C4F50` | `src/overlays/shared/L02_004C4F50.c` | `func_L02_004C6B18` | `addiu $v0, $zero, 0x1E` → `addiu $v0, $zero, 0x19` |
| `func_L04_0049A500` | `src/overlays/shared/L04_0049A500.c` | `func_L04_0049BDD0` | `addiu $v0, $zero, 0x17` → `addiu $v0, $zero, 0x13` |
| `func_L06_004C8430` | `src/overlays/shared/L06_004C8430.c` | `func_L06_004C9C68` | `addiu $v0, $v0, 0x258` → `addiu $v0, $v0, 0x1F4` |
| `func_L08_004CFFC0` | `src/overlays/shared/L08_004CFFC0.c` | `func_L08_004D1BD8` | `addiu $v0, $zero, 0x1E` → `addiu $v0, $zero, 0x19` |
| `func_L41_003BBFE8` | `src/overlays/shared/L41_003BBFE8.c` | `func_L41_003BC668` | `addiu $v1, $zero, 0x12C` → `addiu $v1, $zero, 0xFA` |
| `func_L41_003DF608` | `src/overlays/shared/L41_003DF608.c` | `func_L41_003DFDA0` | `lw $v0, 0x2794($v0)` → `lw $v0, 0x2894($v0)`; `addiu $a3, $zero, 0x3E` → `addiu $a3, $zero, 0x34` (+2 more) |

`config/<version>/map.tsv` holds the source names, files, catalogue names and places (program,
section, address, size) and the closeness; no bytes. CI counts from it without the disc, and
fails when a function of `src/` or `nonmatching/` has no row.

## Names, and new C

Catalogue names: `func_XXXXXXXX` for the main image (`core.text`, `net.text`, the menu `.text`),
`func_FB_XXXXXXXX` for frontbin's own functions, and `func_LNN_XXXXXXXX` for level code: its
address in the lowest-numbered level that has it (`NN` is a distinct program's number). On the US
disc these are the names `src/` already uses (US addresses), so new C goes in `src/` as before.
On PAL the addresses differ: PAL names read the same as US ones but are other functions, so C
written against PAL goes in **`src/pal/`** under its PAL name (`tools/match_map.py --version pal`
checks it there, the US audit and the US map leave it out).

New US C goes where its kind of code lives: `src/core/ADDR.c`, `src/net/ADDR.c`,
`src/game/ADDR.c` (the menu `.text`), `src/frontbin/FB_ADDR.c` (`func_FB_ADDR`),
`src/overlays/shared/LNN_ADDR.c` and `src/overlays/lNN_<slug>/LNN_ADDR.c`. A function that the
old lists (`config/functions.tsv`, `config/overlay_functions.tsv`) do not have is checked by
`tools/match_map.py` at its catalogue place on the US disc (`match` or `nomatch`) and found by its
code on PAL; `tools/audit_matches.py` lists such names and leaves them to it. The map is the
proof on each disc; the audit is the old per-function check of the listed names (it reads the
US overlays from `private/overlays` or, without a wrench unpack, from `baserom/us/levels/`).

Landing new C (after `tools/build.sh`, `build_libgcc.sh`, `build_libm.sh`):

    python3 tools/match_map.py --write && python3 tools/match_map.py --version pal --write
    python3 tools/inventory.py --write && python3 tools/level_catalogue.py && python3 tools/match_map.py --write
    python3 tools/inventory.py --version pal --write && python3 tools/level_catalogue.py --version pal && python3 tools/match_map.py --version pal --write
    python3 tools/progress.py --write && python3 tools/progress.py --version pal --write
    python3 tools/progress.py --check && python3 tools/progress.py --version pal --check

(The second and third lines matter only when a match moves a cut: run them until the tables stop
changing; then commit `config/us/`, `config/pal/`, both reports and the README with the C.)

For a worker (US by default; add `--version pal` for PAL):

    python3 tools/asm_programs.py main level_01 ...                    # asm/us/... once, from the dumps
    python3 tools/check_func.py --todo level_05 --max 200               # what is left, smallest first, with each .s
    python3 tools/check_func.py --where func_L05_004F0A10               # its place and its .s
    python3 tools/check_func.py func_L05_004F0A10 try.c [--diff]        # func_L05_004F0A10: MATCH, or BYTES n/size, SIZE ...

`check_func.py` compiles like `tools/try_func.py` (`tools/cc.sh`, the file's own
`/* cflags: ... */`, through the container unless wine is on `PATH`) and compares with the disc's
bytes at the function's place, with the same masking as the map. `--todo` takes `core.text`,
`net.text`, `.text` (the menus), `frontbin`, `shared` or `level_NN`.

## Reports

`tools/progress.py --version us|pal` writes objdiff's report v2 from the committed tables alone:
`progress/report.json` for `SCUS_974.65` and `progress/pal/report.json` for `SCES_532.85`, with
the same units and categories: one unit per source file of `src/` that matches main-image code,
the main-image functions with no matching C in units of 64 KB of their section
(`main/core.text/0011xxxx`), one "Shared level code" unit (category `common`) and one unit per
distinct level program with its own functions ("Level 01: Dreadzone Station (and 21)",
categories `levels` and `level_01`). Categories `core` (the whole main program), `core_text`,
`libgcc`, `libm`, `net_text`, `menu_text`, `frontbin`, `level_code`, `common`, `levels`,
`level_NN`. Exact and fuzzy are computed apart. `.github/workflows/progress.yml` checks both,
validates them with objdiff-cli and uploads them as `SCUS_974.65_report` and
`SCES_532.85_report`; ByteMatch shows both versions, `SCUS_974.65` by default (the project's
default-version setting).

After matching new functions:

    JOBS=16 bash tools/docker/run.sh bash tools/build.sh   # and build_libgcc.sh, build_libm.sh
    python3 tools/match_map.py --write && python3 tools/match_map.py --version pal --write   # needs the dumps
    python3 tools/inventory.py --write && python3 tools/level_catalogue.py && python3 tools/match_map.py --write   # when a match moved a cut (and --version pal)
    python3 tools/progress.py --write && python3 tools/progress.py --version pal --write
