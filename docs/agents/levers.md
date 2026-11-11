# Levers

What tends to make a function match. These came out of the work so far; add
yours here. The compiler and its flags are in [`toolchain.md`](../build/toolchain.md).

- **Not allowed in matched C**: `volatile`, inline assembly (`__asm__`,
  `asm`, register pins, barriers), `#define` aliases that rename a global or
  an address, and hardcoded addresses (`*(u32 *)0x1000F520`,
  `((void (*)(void))0x00123450)()`). A function that only matches with one of
  them is not matched: it stays in `nonmatching/`
  ([`nonmatching.md`](../contributing/nonmatching.md)).
- **Globals read with `lui`/`lw`** (not through `$gp`): declare them without a
  size so the compiler keeps them out of small data, and index them where
  they are used:
  ```c
  extern s32 D_00221ED8[];
  ... D_00221ED8[0] ...
  ```
  (never a `#define D_00221ED8 (D_00221ED8_[0])` alias), and add `/* cflags: -mno-split-addresses */` if the destination register is the
  `lui` temporary in retail.
- **`-G8`**: variables of up to 8 bytes are plain `extern` declarations when
  retail reaches them with `lui` (the destination register as temporary)
  and through `$gp` only in delay slots; reached through `$gp` elsewhere,
  they are defined above the function in the same file (`s32 D_x = 0;`).
  Retail's assembler only took data it had already seen for small
  (`tools/ps2eeas_sdata.py`).
- **Hardware registers** (0x10000000 and up, the 0x70000000 scratchpad, the
  uncached 0xB0000000 range): retail builds their addresses as constants
  (`lui`/`ori`, then an access at offset 0), which only a cast of the number
  gives. A global named by its address (`extern u32 D_1000F520;`) compiles to
  `lui`/`%lo` instead and does not match (checked on 13 functions), so a
  function that touches registers that way stays in `nonmatching/`.
- **Array indexing**: `p = array + i` and `array[i].field` give different
  register orders; `*(T *)((u32)p + (i << 2))` differs again. Try them all.
- **Return values**: `return x == -1 ? 0 : x;` often matches where a temporary
  holding `~x` does not.
- **Parameter types**: an `s8` compared with `-1` adds sign extensions retail does
  not have; use `s32`.
- **Calls with unknown arguments**: a decompiler may pass a leftover register as
  an argument; if retail does not set it, declare the callee without parameters.
- **Not your fault**: a nop after `mtc1` or a loop padded to a minimum length
  is added by `tools/cc.sh`; if it is missing or extra for one function, the rule
  in `tools/ps2eeas_nops.py` needs refining, not the C.
- **Files built without `-fopt-stack`**: if a prologue saves a callee-saved
  register with `sq`/`lq` in a 16-byte slot (`sq $s0, 0x10($sp)`, `sd $ra, 0($sp)`,
  frame `0x20`) while the rest of the image uses compact 8-byte `sd` slots, the
  original file was compiled without the flag. Start the file with
  `/* cflags: -fno-opt-stack */`. 223 of the functions still in
  `asm/nonmatchings/` have those saves.
- **`div` with a zero check**: `beql $x, $zero, .+8` / `break 0, 7` after a
  `div` means the file kept the default `-mcheck-zero-division`; the build passes
  `-mno-check-zero-division`, so add `/* cflags: -mcheck-zero-division */`.
  59 of the functions still in `asm/nonmatchings/` have that pair.
- **Empty delay slots**: retail's `...; sw $x, 0x36($a0); jr $ra; nop` — the
  last instruction before the jump, with a `nop` in its slot — means the file was
  built with `-fno-delayed-branch`; add `/* cflags: -fno-delayed-branch */`.
  Only where retail fills **no** slot anywhere in the function: with a loop the
  flag nops every back edge and regresses.
- **Address materialisation**: `lui $s0,%hi` + `addiu $s0,$s0,%lo` (the
  destination as its own temporary) is the non-split form and needs
  `-mno-split-addresses`; the default splits it (`lui $v1,%hi` +
  `addiu $a2,$v1,%lo`). When both appear, go by the register **reused across a
  call**. Related: byte-offset stores into a global (`*(s32 *)(G + 0x8)`) make
  GCC split the base and re-add `%lo` at the tail — a local `s32 *` into an
  `s32[]` (`p[2] = 0;`) keeps it in one register.

