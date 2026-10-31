# Ratchet: Deadlocked (PS2) Decompilation

[![Website](https://img.shields.io/badge/Website-openrac.dev-ff8a00?logo=googlechrome&logoColor=white)](https://openrac.dev)
[![Discord](https://img.shields.io/badge/Discord-Join%20Community-5865F2?logo=discord&logoColor=white)](https://discord.gg/Sfd2B54PDG)
[![Progress report](https://github.com/OpenRAC/rac-deadlocked-decomp/actions/workflows/progress.yml/badge.svg)](https://github.com/OpenRAC/rac-deadlocked-decomp/actions/workflows/progress.yml)
[![Code](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp)
[![Functions](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/OpenRAC/rac4-decomp)

A work-in-progress **matching decompilation** of *Ratchet: Deadlocked* (*Ratchet: Gladiator* in PAL regions; Insomniac Games, 2005) for the PlayStation 2, part of the **[OpenRAC](https://openrac.dev)** initiative.

The objective is to produce C/C++ source code that, when compiled with the original toolchain, generates a byte-identical copy of the retail programs: the main program, the front end and the 47 level programs, each read straight from the disc. The primary target is the NTSC-U disc (`SCUS_974.65`), which the existing C was matched against; the PAL disc, *Ratchet: Gladiator* (`SCES_532.85`), is the second version, built and counted the same way, and the same C counts there wherever it builds to the PAL bytes too. Matched code is then refactored toward readable, idiomatic C++ with accurate types and naming, using matching builds as continuous regression tests.

> [!NOTE]
> This repository contains **no game assets, retail executables, or disassembly**. To build, you must provide your own legally obtained copy of the game. Please review [`LEGAL.md`](LEGAL.md) before contributing.

---

## Progress

Progress is published on **[ByteMatch](https://bytematch.dev/OpenRAC/rac4-decomp)** for both versions (US by default) and on **[openrac.dev](https://openrac.dev)**.

| Version | Region | Target ID | Code Matched | Functions Matched |
|---|---|---|---|---|
| v1.00 (primary) | NTSC-U | `SCUS_974.65` | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&label=Functions&measure=matched_functions)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65) |
| PAL | Europe (*Ratchet: Gladiator*) | `SCES_532.85` | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&label=Functions&measure=matched_functions)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85) |

A function counts as matched on a version when its C, built with its file's own flags, gives that disc's bytes of the function with only the fields its object relocates masked (`tools/match_map.py`, `config/<version>/map.tsv`); the fuzzy figure adds what the near misses in `nonmatching/` get right. There is no C in the programs' build yet: every program builds byte-identical from its assembly ([`docs/levels.md`](docs/levels.md)), and `tools/audit_matches.py` checks every function of `src/` against the US bytes.

| Category | US | PAL | Contents |
|---|---|---|---|
| Main program | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=core&label=Main%20program&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=core) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=core&label=Main%20program&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=core) | The main image: engine core, network code, resident menus, and frontbin's own code |
| Engine core | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=core_text&label=Engine%20core&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=core_text) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=core_text&label=Engine%20core&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=core_text) | `core.text`, resident in every level (libgcc and libm apart) |
| libgcc | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=libgcc&label=libgcc&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=libgcc) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=libgcc&label=libgcc&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=libgcc) | GCC's runtime, rebuilt from GCC's source (`src/libgcc/`) |
| libm | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=libm&label=libm&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=libm) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=libm&label=libm&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=libm) | newlib's math library, rebuilt from its source (`src/libm/`) |
| Network | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=net_text&label=Network&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=net_text) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=net_text&label=Network&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=net_text) | `net.text`, the same in every program |
| Resident menus | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=menu_text&label=Resident%20menus&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=menu_text) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=menu_text&label=Resident%20menus&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=menu_text) | The main image's resident `.text` (the menus); frontbin links it a second time and is counted with it |
| frontbin | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=frontbin&label=frontbin&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=frontbin) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=frontbin&label=frontbin&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=frontbin) | The functions only frontbin has |
| Level code | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_code&label=Level%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_code) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_code&label=Level%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_code) | Every level program's code, each distinct function once |
| Shared level code | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=common&label=Shared%20level%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=common) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=common&label=Shared%20level%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=common) | In two or more distinct level programs |
| Level-specific code | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=levels&label=Level-specific%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=levels) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=levels&label=Level-specific%20code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=levels) | In one level program only |

<details>
<summary>The counts</summary>

**NTSC-U (`SCUS_974.65`)**

<!-- progress:begin SCUS_974.65 (tools/progress.py --write) -->
| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| **Main program** | 2,627 of 8,948 | 192,776 of 2,193,280 bytes (8.79%) | 9.30% |
| Engine core (core.text) | 753 of 1,695 | 72,008 of 298,900 bytes (24.09%) | 24.63% |
| libgcc | 2 of 2 | 16 of 16 bytes (100.00%) | 100.00% |
| Network (net.text) | 460 of 2,441 | 14,496 of 465,620 bytes (3.11%) | 4.13% |
| Resident menus (.text) | 1,409 of 4,785 | 105,452 of 1,416,576 bytes (7.44%) | 7.79% |
| frontbin's own code | 3 of 25 | 804 of 12,168 bytes (6.61%) | 6.61% |
| **Shared level code** | 1,082 of 5,076 | 83,504 of 1,980,204 bytes (4.22%) | 4.90% |
| **Level-specific code** | 609 of 4,061 | 63,396 of 1,608,940 bytes (3.94%) | 4.61% |
| Level 00: Multiplayer Menu | 447 of 2,798 | 45,056 of 943,140 bytes (4.78%) | 5.64% |
| Level 01: Dreadzone Station (and 21) | 35 of 356 | 3,444 of 188,848 bytes (1.82%) | 1.82% |
| Level 02: Catacrom Graveyard (and 22) | 2 of 35 | 124 of 26,596 bytes (0.47%) | 0.47% |
| Level 04: Sarathos Swamp (and 24) | 2 of 19 | 196 of 11,708 bytes (1.67%) | 1.67% |
| Level 05: Dark Cathedral (and 25) | 3 of 102 | 288 of 59,824 bytes (0.48%) | 0.64% |
| Level 06: Temple Of Shaar (and 26) | 3 of 31 | 168 of 9,360 bytes (1.79%) | 1.79% |
| Level 07: Valix Lighthouse (and 27) | 4 of 46 | 464 of 28,304 bytes (1.64%) | 1.64% |
| Level 08: Mining Facility (and 28) | 4 of 48 | 180 of 24,400 bytes (0.74%) | 0.74% |
| Level 10: Torval Ruins (and 30) | 3 of 37 | 256 of 20,140 bytes (1.27%) | 1.27% |
| Level 11: Tempus Station (and 31) | 2 of 17 | 104 of 8,804 bytes (1.18%) | 1.18% |
| Level 13: Maraxus Prison (and 33) | 4 of 34 | 444 of 16,916 bytes (2.62%) | 2.62% |
| Level 14: Ghost Station (and 34) | 6 of 29 | 444 of 14,548 bytes (3.05%) | 3.05% |
| Level 15: Control Level (and 35) | 13 of 135 | 932 of 116,368 bytes (0.80%) | 0.80% |
| Level 41: Battledome Tower (all 22 multiplayer maps) | 81 of 374 | 11,296 of 139,984 bytes (8.07%) | 9.93% |
| **Total** | 4,318 of 18,085 | 339,676 of 5,782,424 bytes (5.87%) | 6.49% |

Each distinct function counts once: frontbin's copy of the menus is the main image's, and a level function counts once however many of the 47 levels have it. 192,776 bytes (3.33%) are in units with nothing left to decompile.
<!-- progress:end -->

**PAL (`SCES_532.85`)**

<!-- progress:begin SCES_532.85 (tools/progress.py --write) -->
| | Functions (exact) | Code (exact) | Fuzzy |
| --- | ---: | ---: | ---: |
| **Main program** | 2,687 of 8,945 | 198,808 of 2,202,512 bytes (9.03%) | 9.52% |
| Engine core (core.text) | 754 of 1,699 | 72,192 of 299,052 bytes (24.14%) | 24.68% |
| libgcc | 2 of 2 | 16 of 16 bytes (100.00%) | 100.00% |
| Network (net.text) | 482 of 2,441 | 15,436 of 465,620 bytes (3.32%) | 4.33% |
| Resident menus (.text) | 1,448 of 4,786 | 111,144 of 1,422,048 bytes (7.82%) | 8.13% |
| frontbin's own code | 1 of 17 | 20 of 15,776 bytes (0.13%) | 0.13% |
| **Shared level code** | 1,261 of 5,088 | 92,516 of 2,008,520 bytes (4.61%) | 5.27% |
| **Level-specific code** | 763 of 4,080 | 71,124 of 1,601,892 bytes (4.44%) | 5.01% |
| Level 00: Multiplayer Menu | 582 of 2,826 | 51,620 of 943,820 bytes (5.47%) | 6.15% |
| Level 01: Dreadzone Station (and 21) | 52 of 357 | 4,404 of 189,772 bytes (2.32%) | 2.32% |
| Level 02: Catacrom Graveyard (and 22) | 2 of 29 | 124 of 21,232 bytes (0.58%) | 0.58% |
| Level 04: Sarathos Swamp (and 24) | 2 of 19 | 196 of 11,868 bytes (1.65%) | 1.65% |
| Level 05: Dark Cathedral (and 25) | 3 of 106 | 288 of 61,960 bytes (0.46%) | 0.62% |
| Level 06: Temple Of Shaar (and 26) | 3 of 31 | 168 of 9,440 bytes (1.78%) | 1.78% |
| Level 07: Valix Lighthouse (and 27) | 4 of 44 | 464 of 27,640 bytes (1.68%) | 1.68% |
| Level 08: Mining Facility (and 28) | 4 of 48 | 180 of 24,900 bytes (0.72%) | 0.72% |
| Level 10: Torval Ruins (and 30) | 4 of 38 | 396 of 20,392 bytes (1.94%) | 1.94% |
| Level 11: Tempus Station (and 31) | 2 of 17 | 104 of 9,024 bytes (1.15%) | 1.15% |
| Level 13: Maraxus Prison (and 33) | 5 of 34 | 508 of 15,996 bytes (3.18%) | 3.18% |
| Level 14: Ghost Station (and 34) | 6 of 23 | 444 of 8,884 bytes (5.00%) | 5.00% |
| Level 15: Control Level (and 35) | 13 of 134 | 932 of 116,624 bytes (0.80%) | 0.80% |
| Level 41: Battledome Tower (all 22 multiplayer maps) | 81 of 374 | 11,296 of 140,340 bytes (8.05%) | 9.91% |
| **Total** | 4,711 of 18,113 | 362,448 of 5,812,924 bytes (6.24%) | 6.80% |

Each distinct function counts once: frontbin's copy of the menus is the main image's, and a level function counts once however many of the 47 levels have it. 198,808 bytes (3.42%) are in units with nothing left to decompile.
<!-- progress:end -->

</details>

### Levels

Each level carries its own program: its code, data and dispatch tables, loaded over the main image's menus when the level starts. Each disc has 47 of them but only 14 distinct programs: the 12 split-screen campaign levels are byte-identical copies of their single-player levels, and all 22 multiplayer maps run one program (level 41's). Their functions are counted once each: under *Shared level code* when two or more distinct programs have them, else in their level's own row; a function the resident menus have too is counted there ([`docs/levels.md`](docs/levels.md)).

<details>
<summary>Per level</summary>

| Level | Name | Same program as | US | PAL |
|---|---|---|---|---|
| 00 | Multiplayer Menu | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_00&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_00) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_00&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_00) |
| 01 | Dreadzone Station | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_01&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_01) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_01&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_01) |
| 02 | Catacrom Graveyard | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_02&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_02) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_02&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_02) |
| 04 | Sarathos Swamp | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_04&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_04) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_04&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_04) |
| 05 | Dark Cathedral | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_05&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_05) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_05&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_05) |
| 06 | Temple Of Shaar | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_06&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_06) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_06&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_06) |
| 07 | Valix Lighthouse | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_07&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_07) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_07&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_07) |
| 08 | Mining Facility | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_08&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_08) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_08&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_08) |
| 10 | Torval Ruins | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_10&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_10) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_10&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_10) |
| 11 | Tempus Station | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_11&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_11) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_11&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_11) |
| 13 | Maraxus Prison | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_13&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_13) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_13&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_13) |
| 14 | Ghost Station | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_14&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_14) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_14&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_14) |
| 15 | Control Level | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_15&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_15) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_15&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_15) |
| 21 | Dreadzone Station (split screen) | 01 | (level 01's) | (level 01's) |
| 22 | Catacrom Graveyard (split screen) | 02 | (level 02's) | (level 02's) |
| 24 | Sarathos Swamp (split screen) | 04 | (level 04's) | (level 04's) |
| 25 | Dark Cathedral (split screen) | 05 | (level 05's) | (level 05's) |
| 26 | Temple Of Shaar (split screen) | 06 | (level 06's) | (level 06's) |
| 27 | Valix Lighthouse (split screen) | 07 | (level 07's) | (level 07's) |
| 28 | Mining Facility (split screen) | 08 | (level 08's) | (level 08's) |
| 30 | Torval Ruins (split screen) | 10 | (level 10's) | (level 10's) |
| 31 | Tempus Station (split screen) | 11 | (level 11's) | (level 11's) |
| 33 | Maraxus Prison (split screen) | 13 | (level 13's) | (level 13's) |
| 34 | Ghost Station (split screen) | 14 | (level 14's) | (level 14's) |
| 35 | Control Level (split screen) | 15 | (level 15's) | (level 15's) |
| 41 | Battledome Tower | | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCUS_974.65&category=level_41&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCUS_974.65?category=level_41) | [![](https://bytematch.dev/OpenRAC/rac4-decomp.svg?mode=shield&version=SCES_532.85&category=level_41&label=Code&measure=matched_code_percent)](https://bytematch.dev/OpenRAC/rac4-decomp/SCES_532.85?category=level_41) |
| 42 | Catacrom Graveyard (multiplayer) | 41 | (level 41's) | (level 41's) |
| 44 | Sarathos Swamp (multiplayer) | 41 | (level 41's) | (level 41's) |
| 45 | Dark Cathedral (multiplayer) | 41 | (level 41's) | (level 41's) |
| 46 | Temple Of Shaar (multiplayer) | 41 | (level 41's) | (level 41's) |
| 47 | Valix Lighthouse (multiplayer) | 41 | (level 41's) | (level 41's) |
| 48 | Mining Facility (multiplayer) | 41 | (level 41's) | (level 41's) |
| 50 | Torval Ruins (multiplayer) | 41 | (level 41's) | (level 41's) |
| 51 | Tempus Station (multiplayer) | 41 | (level 41's) | (level 41's) |
| 53 | Maraxus Prison (multiplayer) | 41 | (level 41's) | (level 41's) |
| 54 | Ghost Station (multiplayer) | 41 | (level 41's) | (level 41's) |
| 61 | Battledome Tower (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 62 | Catacrom Graveyard (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 64 | Sarathos Swamp (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 65 | Dark Cathedral (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 66 | Temple Of Shaar (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 67 | Valix Lighthouse (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 68 | Mining Facility (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 70 | Torval Ruins (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 71 | Tempus Station (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 73 | Maraxus Prison (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |
| 74 | Ghost Station (multiplayer, split screen) | 41 | (level 41's) | (level 41's) |

</details>

---

## Quick Start

### Prerequisites
- **Linux & macOS**: [Docker](https://www.docker.com/) or [Podman](https://podman.io/) (uses the prebuilt Wine container via GitHub Container Registry), and Python 3.10+.
- **Windows**: Git Bash, Python 3.10+, and community toolchain mirrors.
  The compilers run natively (no Wine or container needed). The venv's interpreter is
  `venv/Scripts/python.exe`: use it wherever these docs say `venv/bin/python`.

### Setup & Build

1. **Clone the repository:**
   ```bash
   git clone https://github.com/OpenRAC/rac-deadlocked-decomp.git
   cd rac-deadlocked-decomp
   ```

2. **Provide your original executable:**
   Copy `SCUS_974.65` from your disc image into `baserom/`:
   ```bash
   # Expected SHA-1: aa91b1c3b9b1a244320c47580b77342ef9856e95
   cp /path/to/SCUS_974.65 baserom/SCUS_974.65
   ```

3. **Generate the disassembly and fetch toolchains:**
   ```bash
   bash tools/setup_asm.sh                 # unpack, split, splat -> asm/
   git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
   git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
   ```

4. **Build and verify:**
   ```bash
   # Windows (native):
   bash tools/build.sh

   # Linux & macOS (via container):
   bash tools/docker/run.sh bash tools/build.sh

   # Then compare every function with retail:
   venv/bin/python tools/audit_matches.py
   # and write the progress reports (needs the dumps, see below):
   python3 tools/match_map.py --write && python3 tools/progress.py --write
   ```

### Both discs: the programs, their build and the count

Each disc's programs are read from your own `baserom/SCUS_974.65.iso` (or `baserom/SCES_532.85.iso`
with `--version pal`; the SHA-1s are in `config/<version>/programs.tsv` and `levels.tsv`), built
from their assembly, and counted ([`docs/levels.md`](docs/levels.md)):

```bash
python3 tools/levels.py dump                           # baserom/us/ (add --version pal for baserom/pal/)
python3 tools/build_levels.py --asm -P 16              # 49 targets, one MATCH each (ee-as/ee-ld; Linux, or the container)
JOBS=16 bash tools/docker/run.sh bash tools/build.sh   # then build_libgcc.sh, build_libm.sh
python3 tools/match_map.py --write                     # where src/ matches (and --version pal)
python3 tools/progress.py --write                      # progress/report.json and its table (and --version pal)
python3 tools/check_func.py func_L01_XXXXXXXX try.c    # one function against its US bytes (--version pal: PAL)
```

For detailed documentation:
- [`docs/WORKFLOW.md`](docs/WORKFLOW.md) – Setup in full, and the step-by-step function matching guide
- [`docs/TOOLCHAIN.md`](docs/TOOLCHAIN.md) – Compiler, flags, assembler passes, libraries and the container
- [`docs/RESEARCH.md`](docs/RESEARCH.md) – How the retail executable is packed and taken apart
- [`docs/levels.md`](docs/levels.md) – Both discs' programs, their build, how the functions are counted, and the old against the new totals
- [`docs/OVERLAYS.md`](docs/OVERLAYS.md) – The 47 US level overlays the existing C was matched against

---

## Contributing

Contributions are warmly welcome! Whether you are interested in decompiling functions, researching engine quirks, or improving documentation:

- See [`CONTRIBUTING.md`](CONTRIBUTING.md) for contribution guidelines and rules.
- See [`docs/WORKFLOW.md`](docs/WORKFLOW.md) for the step-by-step function matching guide.
- Join our **[Discord Community](https://discord.gg/Sfd2B54PDG)** to discuss progress, ask questions, and collaborate!

---

## Credits

This project builds upon years of dedicated reverse-engineering research and tooling by the community:

- **GFI (Game Fuckery Inc.)** – Special thanks to the GFI Discord community for years of reverse engineering, game research, and technical insights that made this decompilation possible.
- **[rac1-decomp](https://github.com/OpenRAC/rac1-decomp)** – Repository layout, README, progress workflow and report generator, toolchain notes, the libgcc build recipe, and `tools/ps2eeas_nops.py` / `tools/ps2eeas_dli.py` (the nops and constant sequences of SN's assembler).
- **[rac3-uya-decomp-pal](https://github.com/OpenRAC/rac3-uya-decomp-pal)** – The PAL treatment this repository follows: reading the levels from the disc, the function inventory (rac1-decomp's rules), the catalogue and the report (`tools/inventory.py`, `tools/level_catalogue.py`, `tools/progress.py` are adapted from it).
- **[rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp)** by vetusmagnus – *Up Your Arsenal*, the closest engine relative. Compiler research (SN ee-gcc 2.95.3 v1.36) and the `-fopt-stack`, `-G8` and global-declaration findings.
- **[OpenRAC](https://github.com/OpenRAC/OpenRAC)** – Status of Deadlocked, sourcing policy, and the sibling decompilations of the engine family.
- **[Lombyte](https://github.com/mateuszklysz/Lombyte)** by mateuszklysz – R&C1 NTSC decomp, checked for Deadlocked coverage (none).
- **[Wrench](https://github.com/chaoticgd/wrench)** by chaoticgd – PS2 Ratchet & Clank modding tools; its documentation of the packed image (`docs/file_loading.md`, "WAD Compression") and the executable's layout, and the level overlays it unpacks.
- **[GCC](https://gcc.gnu.org)** and **[newlib](https://sourceware.org/newlib/)** – The library sources in `src/libgcc/` and `src/libm/` (see [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md)).
- **Decompilation Tooling & Ecosystem**:
  - [splat](https://github.com/ethteck/splat) & [spimdisasm](https://github.com/Decompollaborate/spimdisasm) – Binary splitting and MIPS disassembly.
  - [m2c](https://github.com/matt-kempster/m2c) & [asm-differ](https://github.com/simonlindholm/asm-differ) – Assembly-to-C translation and diffing.
  - [objdiff](https://github.com/encounter/objdiff) – Object diffing tool.
  - [ByteMatch](https://bytematch.dev), [decomp.dev](https://decomp.dev) & [decomp.wiki](https://decomp.wiki) – Progress tracking and decompilation knowledge base.
  - [AngheloAlf](https://github.com/AngheloAlf) – PS2 toolchain mirrors.

---

## License

- Code written for this project is licensed under the [GNU General Public License v3.0](LICENSE).
- Reconstructed libraries and third-party components retain their original licenses (see [`THIRD_PARTY_NOTICES.md`](THIRD_PARTY_NOTICES.md) and [`LEGAL.md`](LEGAL.md)).
- *Ratchet: Deadlocked* is a registered trademark of Sony Interactive Entertainment. This project is not affiliated with or endorsed by Sony or Insomniac Games.
