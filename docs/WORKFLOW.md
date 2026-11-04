# Workflow

From a fresh clone to a matched function. The short version is in
[`CONTRIBUTING.md`](../CONTRIBUTING.md); the compiler and the build are in
[`TOOLCHAIN.md`](TOOLCHAIN.md); what tends to make a function match is in
[`LEVERS.md`](LEVERS.md).

On Linux and macOS, run the build commands through the container:
`bash tools/docker/run.sh <command>`.

## Setup (once, and after changing config/splat.yaml)

**The executable.** Copy `SCUS_974.65` from your disc to `baserom/` (ignored by
git). Its SHA-1 must be `aa91b1c3b9b1a244320c47580b77342ef9856e95`.

**The disassembly.**

```
bash tools/setup_asm.sh
```

The retail executable is only a loader with a compressed game image
([`RESEARCH.md`](RESEARCH.md)). The script checks the hash, unpacks the image
(`tools/unpack_wad.py`), rebuilds an ELF from its 17 sections
(`tools/split_image.py`), and runs [splat](https://github.com/ethteck/splat)
with `config/splat.yaml` into `asm/` (not tracked). A `venv/` with the pinned
tool versions is created on first use. If the splat configuration changed,
regenerate `config/functions.tsv` (every function with address and size) with
`venv/bin/python tools/gen_function_list.py`.

**The toolchain** ([`TOOLCHAIN.md`](TOOLCHAIN.md)):

```
git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
```

**The level overlays** (needed to check overlay functions, and to regenerate
`config/overlays.tsv` and `config/overlay_functions.tsv`, which are committed).
Unpack your disc with the [wrench](https://github.com/chaoticgd/wrench) build
tool, link the result to `private/overlays` (or set `$OVERLAYS`) and split it:

```
wrenchbuild unpack GAME.iso -o DIR -g dl -r us
venv/bin/python tools/split_overlays.py DIR
```

See [`OVERLAYS.md`](OVERLAYS.md).

**Helper tools** (cloned locally, not vendored):

```
git clone https://github.com/matt-kempster/m2c tools/ext/m2c
git clone https://github.com/simonlindholm/asm-differ tools/ext/asm-differ
```

## 0. Before decompiling anything: is it even game code?

libgcc (`0x12EE30` to `0x131958`) and libm are not game code: they are rebuilt
from GCC's and newlib's own sources, never decompiled
([`TOOLCHAIN.md`](TOOLCHAIN.md), `config/libgcc.tsv`, `config/libm.tsv`). Check
those tables before starting on a function in that range.

## 1. Get a sketch

Pick a function from `asm/nonmatchings/<segment>/func_XXXXXXXX.s` (or
`asm/overlays/<level>/nonmatchings/` for a level overlay). Small functions
without data tables are a good start; `config/functions.tsv` and
`config/overlay_functions.tsv` list all of them with sizes.

```
venv/bin/python tools/ext/m2c/m2c.py -t mipsee-gcc-c asm/nonmatchings/.../func_XXXXXXXX.s
```

The output is a draft: it usually needs types, struct members and cleaner
control flow.

Put it in the file its address belongs to, defining `func_XXXXXXXX` (the name in
`asm/`), starting the file with `#include "common.h"`. A file may hold several
functions.

| Function | File |
|---|---|
| core text, below `0x163B80` | `src/core/<ADDR>.c` |
| network text, from `0x1E00000` | `src/net/<ADDR>.c` |
| resident level text | `src/game/<ADDR>.c` |
| overlay code in two or more levels (`func_L01_00631CB8`) | `src/overlays/shared/L01_00631CB8.c` |
| overlay code in one level only | `src/overlays/lNN_<level>/LNN_<ADDR>.c` (e.g. `l00_multiplayer_menu/`) |

`config/overlay_functions.tsv` says which overlay functions are shared (`common`)
and which belong to one level (`level`); the level directory names come from
`config/overlays.tsv`.

### Automatic drafts (`tools/auto_structs.py`)

For small functions, `venv/bin/python tools/auto_structs.py prepare overlay N`
runs m2c, builds structures from the `->unkXX` accesses (members named by
offset, types from how they are used) and writes four compile variants;
`bash tools/docker/run.sh bash build/auto3/compile.sh` compiles them, `check`
keeps the ones that equal retail and `adopt` copies them into `src/`, in the
layout above. The first run matched 71 of 1,800 functions tried.

## 2. Iterate with the differ

The quickest loop leaves `src/` alone: write candidates in
`build/try/func_XXXXXXXX/` and run

```
venv/bin/python tools/try_func.py func_XXXXXXXX build/try/func_XXXXXXXX/p1.c --diff
```

It compiles the candidate through the real pipeline (in the container) and
says `EXACT`, `BYTES n/size` with the instructions that differ, `SIZE` or
`COMPILE`, in seconds. Several candidates go in one run. To see a function
already in `src/` against retail:

```
bash tools/docker/run.sh bash tools/build.sh
venv/bin/python tools/diff_func.py func_XXXXXXXX
```

`tools/diff_func.py` shows your function next to retail, word by word (for an
overlay function, against that level's `overlay.elf`). `tools/try_variants.py`
compiles several source forms of one function in a single run (see its
docstring; `EXTRA="..."` passes flags). [`LEVERS.md`](LEVERS.md) lists what has
made functions match so far.

## 3. Verify

```
bash tools/docker/run.sh bash tools/build.sh
venv/bin/python tools/audit_matches.py
venv/bin/python tools/audit_relocs.py
```

`tools/audit_matches.py` compares each compiled function with the retail bytes
at its address, masking only the fields the compiled object has relocations on
(jump targets, and the immediates of `lui`/`%lo`/`$gp` accesses to symbols):
every constant and offset must equal retail. This is
**not** a link-time comparison yet: a function that calls or reads the wrong
symbol can still pass. `tools/audit_relocs.py` closes that gap for the exact
functions: it resolves each relocation (calls, `%hi`/`%lo` pairs, `$gp`
accesses with `$gp = 0x22597F`, jump tables) to the address a link would give
it and compares that with the address retail's instruction encodes. Fix every
mismatch it reports in the C (the right `D_XXXXXXXX`, callee or case label)
and build again. An overlay function counts in every level that contains it.

If it does not match yet, keep it out of `src/`: see
[`NONMATCHING.md`](NONMATCHING.md).

## 4. Publish

```
python3 tools/match_map.py --write                  # where src/ matches on the US disc
python3 tools/match_map.py --version pal --write    # and on PAL
python3 tools/progress.py --write                   # progress/report.json (SCUS_974.65)
python3 tools/progress.py --version pal --write     # progress/pal/report.json (SCES_532.85)
```

After compiling C named by the selected disc's catalogue, an existing map can
instead be updated for complete source files:

```
python3 tools/match_map.py --version pal --update-native src/pal/overlays/shared/L00_006A3AF0.c --check
python3 tools/match_map.py --version us --update-native src/pal/overlays/shared/L00_006A3AF0.c --check
```

This checks every native definition in the selected files and retains unrelated
map bytes. PAL sources on US are recorded as `other` without reading US binaries.
US sources on PAL and moved or removed definitions require the full `--write`
workflow. Resolve colliding names before either workflow. Regenerate both
progress reports after either map update.

Map searches and native code comparisons need the dumps (`tools/levels.py dump`,
`docs/levels.md`). Commit the regenerated
`config/us/map.tsv`, `config/pal/map.tsv`, both reports and the README tables together with your
source. CI (`.github/workflows/progress.yml`) runs `tools/progress.py --check` for both versions
and fails if a report disagrees with `src/`; it cannot build the game, so the report always comes from
your machine.

## Names

Name functions by address (`func_XXXXXXXX`, `func_LNN_XXXXXXXX` for overlay
functions), types `Type1`, `Type2` ... and members by offset (`f20` for the
member at `0x20`) until you understand what something does. Then give it a
descriptive name of your own. Do not copy identifiers, file names or directory
names from any other source ([`LEGAL.md`](../LEGAL.md)).

## Repository layout

| Path | Contents |
|---|---|
| `src/core/`, `src/net/`, `src/game/` | Resident code, one file per start address until the real source file is known |
| `src/overlays/shared/`, `src/overlays/lNN_<level>/` | Level overlay code in two or more levels, and in one ([`OVERLAYS.md`](OVERLAYS.md)) |
| `src/libgcc/`, `src/libm/` | GCC's runtime library and newlib's math library, sources that match retail |
| `nonmatching/` | Near misses, never built ([`NONMATCHING.md`](NONMATCHING.md)) |
| `include/` | Shared headers (`common.h`) and assembly macros |
| `config/` | splat configuration, section table, function lists, library tables, the level overlays |
| `tools/` | Unpacker, splitters, compile pipeline (`cc.sh`), audit, diff and report tools, the agent queue (`wave.py`, `try_func.py`, `claims.py`); `tools/docker/` the build container |
| `.claude/agents/` | The worker agent used by waves ([`AGENT_WORKFLOW.md`](AGENT_WORKFLOW.md)) |
| `docs/` | This guide, the toolchain, research notes, the overlays, levers, near misses, the agent workflow |
| `notes/` | Notes on single functions |
| `progress/report.json` | the US (`SCUS_974.65`) objdiff-format progress report CI publishes (`tools/progress.py`) |
| `progress/pal/report.json` | the PAL (`SCES_532.85`) report (`tools/progress.py --version pal`) |
| `baserom/`, `asm/`, `assets/`, `build/`, `toolchain/`, `venv/`, `private/` | Local only, never committed |
