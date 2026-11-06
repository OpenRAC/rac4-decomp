# Queue worker protocol

You match functions of Ratchet: Deadlocked (PS2, NTSC-U) byte for byte: C
that SN GCC 2.95.3 v1.36 (`-O2 -G8 -fopt-stack`, EABI, MIPS R5900) compiles
to retail's code. Your prompt gives WAVE, ID, N and COUNT. This file is your
whole instruction set: do not read WORKER.md or other docs, and do not
explore the tree beyond what a packet names.

## Loop: claim COUNT functions at a time until N are handled

Run everything from the repository root.

1. `venv/bin/python tools/wave.py claim <WAVE> <ID> --count <COUNT>` prints
   a packet per function: what it calls and uses, its assembly, an m2c
   draft and matched C nearby. `QUEUE EMPTY`: stop.
2. An attempt is ONE message with two tool calls, in this order:
   - Write `build/try/<func>/pK.c` (K from the number the packet header
     gives, then up by one: a new file each time, never one an earlier
     round wrote);
   - Bash `venv/bin/python tools/try_func.py <func> build/try/<func>/pK.c --diff`

   With several claimed functions, put their attempts in the same message.
3. Not `EXACT`: say in one line which instructions differ, then change one
   thing. `COMPILE`: read `build/try/<func>/log.txt`, fix it.
4. A function is handled when try_func says `EXACT`, or when you stop:
   - its budget is spent (try_func refuses further runs);
   - three different wordings compile to the same bytes (an allocator or
     scheduler tie that rewording will not move);
   - it hits a wall below.

   When you stop, append two or three lines to `build/try/<func>/NOTES.md`:
   what the function does, where the difference is, what would unblock it.
   Stopping is a normal outcome. Write no RESULT.md: the runs are logged.
5. Claim again until N functions are handled or the claim prints
   `QUEUE EMPTY`. Do not stop earlier: finishing one claim is not the end.
6. Your final message is one line and nothing else:
   `{"id": "<ID>", "exact": ["func_..."], "stopped": ["func_..."], "idiom": "<25 words at most, or empty>"}`

## Rules

- Write only in `build/try/<func>/`, only files you create. Never edit
  `src/`, `include/`, `config/`, `tools/`, `docs/` or `nonmatching/`; never
  delete anything; never commit, build the game, start sub-agents or use
  the web.
- Compile only through try_func. No compiler runs or harnesses of your own.
- Plain C: no register pins, no inline assembly, no barriers
  (`__asm__("" : ...)`, `do { } while (0)`), no `volatile` at all, no
  `#define` that renames a global or an address, no hardcoded address (a
  number cast to a pointer), no read of a local that was never assigned. A
  match that needs one is not a match: stop instead (the function stays in
  `nonmatching/`). A function that reads a register
  it never sets, or branches outside itself, is a fragment: stop at once.
- The build is fixed: no step may change what the compiler emitted, and
  flags apply only to whole files (GCC 2.95 has no per-function options).
  A function that only matches with a new post-processing step is not a
  match (CONTRIBUTING.md, "Build fidelity"). A `/* cflags: ... */` first
  line in your candidate is allowed: the function lands in a file of its
  own, and that line becomes the file's flags.
- try_func masks call targets and global addresses: a wrong callee or
  global still says `EXACT`. Call and use exactly the symbols the assembly
  names, by those names.
- Sources: work from the assembly and from what the packet gives you.
  Never use Sony SDK source, sample code or headers, or any leaked
  material, from memory either (CONTRIBUTING.md, "Sources"). If a function
  looks like SDK sample code, decode it from the assembly like any other.
- Names are by address only: `func_...`, `D_...`, types `Type1`, members
  by offset (`f20`). Never a name from another project or from memory.
- A hardware register (0x10000000 and up, 0x70000000 scratchpad, the
  uncached 0xB0000000 range) that retail reaches as a constant address
  (`lui`/`ori`, then an access at offset 0) needs
  `*(volatile int *)0x10000000`, which is not allowed: stop. A global
  named by its address gives `lui`/`%lo` and does not match.

## Candidate file

Extern declarations first, then the one function under its own name, with
one comment line above it saying what it does. Declare what the packet
lists as "not declared anywhere yet"; copy exactly the declarations it
gives for the rest. A declaration whose prototype uses a type you don't
have (`Type1 *`): declare it with `void *` instead. No string literals:
`extern char D_xxx[];`. `#include "common.h"` is added for you; its types
are `s8`..`s64`, `u8`..`u64`, `f32`, `f64`.

## Near misses

When the packet shows "Best earlier attempt", an earlier worker came close
and stopped. The packet gives that candidate (`best.c`) and every
instruction that still differs. Your first attempt is `best.c` with one
change aimed at the first difference; never start over.

- Same instructions, registers swapped: change the order locals are first
  assigned, or swap the operands of a `+`, `*`, `&`, `|` or `==`.
- Same instructions in another order: reorder the independent statements
  that produce them (see "Codegen": the source's last store tends to come
  out first).
- One extra or missing move: a local the compiler keeps or folds. Inline
  it, or give the value its own local.
- `lui` + `lw` against `$gp`, or the reverse: the global's declaration
  (see "Reading the assembly").
- A difference only in a branch-likely (`beql`/`bnel`) or a delay slot:
  try the other form of the condition (`if (!x) ... else ...`).

Three changes that leave the same differences mean the tie won't move:
stop and say in NOTES.md which instructions are left.

## Reading the assembly

- Arguments `$a0`-`$a3`, `$t0`-`$t3`; floats `$f12`, `$f13`, `$f14`...;
  results `$v0`, `$f0`. `$s0`-`$s7` are saved. Retail saves them with
  `sd`/`ld` in 8-byte slots (`-fopt-stack`).
- `func_XXXXXXXX` and `D_XXXXXXXX` are the resident executable;
  `func_LNN_XXXXXXXX` is level overlay code, named after the first level it
  occurs in: an L01 function may call `func_L00_...`, and that is right.
- Small globals (`-G8`, up to 8 bytes), as the build's assembler step
  (tools/ps2eeas_sdata.py) treats them, like retail's assembler:
  - reached with `lui` + `%lo` whose temporary is the destination
    register (`lui $v0` / `lw $v0`; `$at` for a store), and through `$gp`
    only in branch delay slots, if at all: a plain `extern s32 D_x;` (or
    `f32`, `s16`...);
  - reached through `$gp` outside a delay slot: the variable was defined
    above the function in its file. Define it there: `s32 D_x = 0;`.
  When the assembly gives only an offset (`lw $v0, -0x37F7($gp)`), the
  global's address is `0x22597F` plus that offset (`$gp` is `0x22597F`,
  from `.reginfo`): `-0x37F7($gp)` is `D_00222188`.
- A global retail reaches with `lui` + `%lo` where the `lui` is shared by
  several accesses or uses another temporary, and never through `$gp`:
  declare it without a size and index it where you use it,
  ```c
  extern s32 D_00221ED8[];
  ... D_00221ED8[0] ...
  ```
  or as an array or struct of unknown size (`extern Type1 D_x[];`). Never
  a `#define D_00221ED8 (D_00221ED8_[0])` alias.
- `lui $a0, %hi(D_x)` then `lw $a0, %lo(D_x)($a0)` (the destination register
  as the temporary): the file needs `-mno-split-addresses`; start the
  candidate with `/* cflags: -mno-split-addresses */`.

## Codegen

Verified on this repository's matches:

- A counter retail reloads from memory, or a store retail leaves a nop
  delay slot after: look for a call or a store through a pointer between
  the accesses (they force the reload). `volatile` is not allowed; if
  nothing else gives the reload, stop.
- `p = array + i` and `array[i].field` give different register orders;
  `*(T *)((u32)p + (i << 2))` differs again. Try them all.
- `return x == -1 ? 0 : x;` often matches where a temporary holding `~x`
  does not.
- An `s8` parameter compared with `-1` adds sign extensions retail does
  not have: use `s32`.
- A callee given a leftover register it does not use: declare it without
  parameters.
- A nop after `mtc1`, or a short loop padded with nops, is added by the
  build (tools/cc.sh): if it is missing or extra, say so in NOTES.md and
  stop; the C is not the problem.

From rac1-decomp (the same compiler family, verified there):

- The first temporary after a call is `$v0` when the callee returns a value
  and `$v1` when it does not: that decides a callee's return type.
  `sltiu` is an unsigned compare, `slti` a signed one; `lbu`/`lb`,
  `lhu`/`lh` give a field's signedness.
- Write stores in the target's order first. Where the compiler had a free
  choice, the source's last store tends to come out first: permute.
- A value loaded once and used twice is a local; a field loaded again at
  each use is re-read in the source.
- One shared `return` with the value set in each arm, or a `return` per
  arm: try the other when only the epilogue differs.
- Argument moves come out in the order the callee's parameters are
  declared: a float set up before or after an integer is the prototype,
  not a scheduler tie.
- `sltiu $2, $2, 3` after `addiu $2, $3, -5`: a range test,
  `v >= 5 && v <= 7`.
- `movn`/`movz`: a default then one conditional assignment,
  `r = 0x7E; if (arg == 0) r = 0x68;`. Swap which value is the default to
  get the other instruction.
- A jump table in retail: a `switch` with one `case` label per value, even
  when several cases do the same thing; merged labels give a compare tree.
- An `lq`/`sq` pair is a 128-bit copy:
  `typedef int u128 __attribute__((mode(TI)));` then
  `*(u128 *)(a + 0x30) = *(u128 *)(b + 0x10);`.
- A byte store of 0x80 and up through a `char *` comes out as a negative
  constant: write it through `unsigned char *`.
- When one function of a family has matched (the packet's "Matched C
  nearby"), write its siblings in exactly its form first.

## Walls: stop at once and name the wall in NOTES.md

- `cfc2`/`ctc2`, VU0 macro instructions, `$at` used as an ordinary
  register, trapping `add`/`addi`: the original was assembly or has no C
  form.
- Retail leaves a branch delay slot empty (a `nop`) where the compiler
  fills it, and no rewording moves it: note it, do not chase it.
- More saved registers or a bigger frame than retail with the instructions
  otherwise right, after `-mno-split-addresses` was tried: note it.
- The function ends in a tail call to another function — `ld $ra, 0($sp)`,
  `j func_XXXXXXXX`, `addiu $sp, ...` — rather than `jal` plus an epilogue:
  SN GCC 2.95.3 v1.36 emits no `j` for a C call and has no sibling-call
  option (it rejects `-foptimize-sibling-calls`), and no matched function
  here contains one. Over 200 functions in the US image end this way. Note
  it and stop; the C is not the problem.
