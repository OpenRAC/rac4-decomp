# Toolchain

What builds the code and why: the compiler and its flags, how `tools/cc.sh`
turns a C file into an object, and how the libraries are rebuilt. How the
retail executable itself is laid out is in [`RESEARCH.md`](RESEARCH.md).

## Where the binaries come from

The compilers are third-party mirrors of commercial software and are never
committed (`toolchain/` is ignored):

```
git clone https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01 toolchain/sn-prodg-3.01
git clone https://github.com/AngheloAlf/sce_ps2_sdk_24 toolchain/sn-prodg-24
```

They are 32-bit Windows programs. On Windows they run natively (Git Bash); on
Linux and macOS through Wine in a container (see the end of this file).

## Compiler and flags

**SN GCC 2.95.3 v1.36** (`ee-gcc2953.exe` from the ProDG 3.01 mirror), flags

```
-O2 -G8 -fopt-stack -mno-check-zero-division
```

plus `-mno-split-addresses` for some files (a source file says so with
`/* cflags: -mno-split-addresses */` on its first line; `tools/build.sh` reads it).

How it was found. Five small functions whose C is certain from the assembly
were compiled with every compiler in the mirrors and compared with retail
(exact matches out of 5 / same size out of 5):

| Compiler | `-O2` | Notes |
|---|---|---|
| **SN GCC 2.95.3 v1.36** (`sn-prodg-3.01` `ee-gcc2953.exe`) | **4 / 5**, 5 / 5 | the remaining function differed in one register |
| Sony 2.9-ee-991111 (`ee-gcc.exe`) | 3 / 5, 4 / 5 | wrong code for one function |
| SN 1.14 (`sn-prodg-24` `ee-gcc2953.exe`) | 1 / 5, 5 / 5 | |
| SN 2.74 (`ee-gcc295.exe`) | 1 / 5, 5 / 5 | |

The Up Your Arsenal decomp reports the same compiler (its
`compiler_matrix_findings.md`), and also supplied the flags below.

- **`-fopt-stack`** (SN only): retail saves callee-saved registers with `sd`/`ld`
  in compact 8-byte slots (`s0` at 0, `s1` at 8, `ra` at 0x10). Without the flag
  the compiler emits `sq`/`lq` pairs in 16-byte slots, and every function that
  saves two or more registers fails.
- **`-G8`**: of retail's `$gp`-relative accesses, 1,799 are `lw`, 917 `sw`, 330
  `lwc1` and 18 are 8-byte `ld`/`sd`, so the small-data threshold is 8. Globals
  that retail reads with `lui`/`lw` are declared without a size
  (`extern T x[];` plus `#define x (x[0])`) so the compiler does not put them in
  `.sdata`.
- **`-mno-split-addresses`**: makes the compiler emit a global access as one
  assembler macro, and the assembler then uses the destination register as the
  temporary (`lui $a0; lw $a0, lo($a0)`). Without it the compiler splits the
  access itself and picks another register. Which files need it differs (the Up
  Your Arsenal decomp reports the same, in runs of consecutive functions).
- **`-mno-check-zero-division`**: no `break 7` after `div` (not yet needed here).

Source-level findings: a counter that retail reloads from memory needs
`volatile`; `p = array + i` gives a different register order than
`array[i].field`; an `s8` parameter compared with -1 adds sign extensions that
retail does not have (use `s32`).

## What happens to each object (`tools/cc.sh`)

`tools/build.sh` compiles every `src/**/*.c` (except the libraries) into
`build/obj/` through `tools/cc.sh`, which reproduces what SN's assembler does
because that assembler is not usable here:

1. compile to assembly (`-S`);
2. `tools/ps2eeas_dli.py`: expand 64-bit constants the way SN's assembler does;
3. `tools/ps2eeas_lis.py`: expand float constants (`li.s`) the way SN's
   assembler does (below);
4. `tools/ps2eeas_sdata.py`: reach each small global through `$gp` or with
   `lui` where SN's assembler does (below);
5. assemble once with the compiler driver's GNU `as`;
6. `tools/ps2eeas_nops.py`: add the nops SN's assembler adds (it pads short
   loops, and puts a nop after an `mtc1` whose result is read next, and between
   a float compare and its `bc1`);
7. assemble again.

A source file can add compiler flags on its first line:

```c
/* cflags: -mno-split-addresses */
```

Options apply to the whole file, never to one function: GCC 2.95 takes them per
translation unit. If one function needs other flags, it goes in a file of its
own.

## The assembler

Retail's code was assembled by SN's own assembler (`ps2eeas`), not by the GNU
`as` the compiler driver calls. It differs in ways that show up as extra nops
and different constant sequences. `tools/cc.sh` reproduces them in two extra
steps around the normal compile (compile to assembly, expand 64-bit constants as
`ps2eeas` does, assemble once, add the nops `ps2eeas` adds, assemble again), with
`tools/ps2eeas_dli.py` and `tools/ps2eeas_nops.py` taken from rac1-decomp,
which measured the real assembler. The rules: loops shorter than a minimum are
padded with nops (here, 5 instructions target through branch, 6 with the
branch's delay slot: the retail histogram of backward branches in level code
starts at 5), a float compare followed directly by `bc1` gets a nop between them,
and an `mtc1` whose destination is read by the next instruction gets one too.
Retail's level code has 722 `mtc1; nop; cvt.s.w` sequences and 93 without; the
nop pass accounts for the first group.

Small data: GCC writes accesses to globals as macros (`lw $2,D_x`) and leaves
`$gp` or `lui` to the assembler. GNU `as` uses `$gp` for every object of 8
bytes or less. `ps2eeas` (1.9.6 in the SDK mirror, run on test files) reads the
file once and uses `$gp` only for a plain `D_x` whose definition in
`.sdata`/`.sbss` it has already seen, and inside `.set nomacro` (GCC's filled
delay slots), where one instruction is required; everything else becomes `lui`
plus the access. Retail agrees: in the resident and L00 code, when one function
reaches a global both ways, 1231 of 1252 `$gp` accesses sit in delay slots.
`tools/ps2eeas_sdata.py` reproduces that by renaming accesses (`D_x__gp`,
`D_x__lui`) so GNU `as` picks the same form; on all the matched sources,
`ps2eeas_dli` + `ps2eeas_sdata` + GNU `as` give the same text as `ps2eeas`
wherever the old pipeline did, and two files more (the rest differ only in
the nops step 5 adds).

Float constants: GCC writes them as `li.s $fN, value`. `ps2eeas` (1.9.25 in the
SN 3.01 mirror) always builds the value in `$at`: `lui`, `ori` when the low half
is not zero, then `mtc1`. GNU `as` does the same only for a zero low half; at -G8
it puts any other value in `.lit4` and loads it with one `lwc1 ...($gp)`.
`tools/ps2eeas_lis.py` writes the `ps2eeas` sequence out before the first
assembly. In the PAL text the `lui`/`ori`/`mtc1 $at` form appears 13,207 times.
A file whose matched code relies on the `.lit4` load can keep it with the token
`@lit4` in its cflags (`/* cflags: @lit4 */`); `tools/cc.sh` removes the token
and skips the step for that file.

Not explained yet: retail has two nops before most `div.s` (281 of 435 in level code,
including library code), while the compilers in the mirrors emit none and `ps2eeas` on
small test cases adds none either; in the library code the compiler puts the `div.s` in
a jump's delay slot and retail does not.

Other near misses are a delay slot that retail leaves empty, or a register move
that retail schedules before a save where the compiler puts it after.

## libgcc

The GCC runtime library is linked in at `0x12EE30` to `0x131958`. Those functions
were not written for the game: they are GCC's own sources built by Sony's
toolchain, so they are rebuilt from GCC's sources (`src/libgcc/README.md`),
the same way as in rac1-decomp: Sony's 2.9-ee driver, `-O2 -G2`, one object per
module, soft-float as two whole-file objects. `tools/build_libgcc.sh` builds,
`tools/map_libgcc.py` pairs each compiled function with its retail address
(`config/libgcc.tsv`). 24 of the 36 functions match. `__moddi3` and
`__umoddi3` come out at the right size with 7 and 2 words different (retail's
stack frame is larger), `__udivdi3` is 12 bytes short. Sony's prebuilt
`libgcc.a` matches retail for all three, so retail linked that archive;
the archive is a reference only and not a substitute.

## libm

The math library (`__ieee754_*`, `sqrtf`, `floorf` ...) is newlib's libm
(fdlibm), built by Sony's 2.9-ee driver with `-O2 -G2`, the same as libgcc.
`tools/map_archive.py` pairs the functions of the library archive in the
toolchain mirror with retail (`config/libm.tsv`: 40 functions, 20,220 bytes);
`tools/build_libm.sh` builds newlib's sources (snapshot 2000-02-17,
`tools/get_newlib.sh`). 27 of the 40 members match exactly (7,744 bytes);
`src/libm/README.md` lists the rest.

## Building the libraries

```
bash tools/docker/run.sh bash tools/build_libgcc.sh
bash tools/get_newlib.sh                           # once: the math library headers
bash tools/docker/run.sh bash tools/build_libm.sh
```

Each compiled function is paired with its retail address in `config/libgcc.tsv`
and `config/libm.tsv`. Only source files that match are kept in `src/libgcc/`
and `src/libm/` (their READMEs list what does not match yet).
`tools/map_archive.py ARCHIVE.a NAME` makes such a table from a library archive
in the toolchain mirror; the archive is a reference for names and addresses
only, never a substitute for source.

## Running it on macOS and Linux

`bash tools/docker/run.sh <command>` runs any command in a 32-bit Debian
container with Wine, the repository mounted at the same path as on the host.
It uses Podman if present, otherwise Docker. The image is the one rac1-decomp
publishes (`ghcr.io/lynder063/rac1-build`, override with `RAC_BUILD_IMAGE`);
if it cannot be pulled, it is built from `tools/docker/Dockerfile`.

## Sony EE GCC 2.9 route for whole-file builds

Most RAC4 code uses SN GCC 2.95.3 v1.36 and the SN-output fixups described
above. A source file may opt into Sony EE GCC 2.9-ee-991111 with a standalone
`@ee29` token in its first-line `cflags` (for example,
`/* cflags: @ee29 -O2 -G0 */`). The `tools/build.sh` flag reader passes these
flags to `tools/cc.sh` for the entire translation unit; do not treat this as a
per-function option.

For that route, `tools/cc.sh` invokes
`toolchain/sn-prodg-24/local/sce/ee/gcc/bin/ee-gcc.exe` with the explicitly
pinned backend at `lib/gcc-lib/ee/2.9-ee-991111`, emits assembly, and assembles
it with the SN GCC 2.95.3 driver. The `@ee29` marker is removed before compiler
invocation. If no other flags are supplied, the route uses `-O2 -G0`. It
intentionally skips the SN-specific `ps2eeas_dli.py`, `ps2eeas_sdata.py`, and
`ps2eeas_nops.py` passes; these reproduce transformations of SN's compiler
output and must not be applied to the Sony compiler's output.

Both toolchain mirrors are third-party distributions and remain uncommitted
under ignored `toolchain/`. This route uses their local compiler binaries; it
does not use Sony SDK source or sample code. A route-level shell test only
checks command selection, argument forwarding, output creation, and diagnostics.
It does not establish compiler byte parity. Exact matching still requires the
project's normal retail comparison and RAC4 verification pipeline, including
relocation review, before any match claim.
The command-route tests require Bash and Python but no retail files or proprietary tools:

```
python tools/test_cc_routes.py
```
