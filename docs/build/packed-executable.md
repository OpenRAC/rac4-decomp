# The packed executable

How the retail executable is built, and how it is taken apart here (the
toolchain is in [`toolchain.md`](toolchain.md)). Everything below was derived
from the retail NTSC-U executable (`SCUS_974.65`, `VER = 1.00`, SHA-1
`aa91b1c3b9b1a244320c47580b77342ef9856e95`), the compilers and libraries that
ship with the toolchain mirrors, and public documentation (wrench, the Up Your
Arsenal and R&C1 decompilations, GCC and its libgcc sources).

## The retail executable

`SCUS_974.65` is 1,692,216 bytes: a small loader plus one compressed game image.

| | |
|---|---|
| ELF | 32-bit LE, `EXEC`, entry `0x800008`, one `LOAD` segment, no symbol table |
| Loader | `.text`, 20 KB at `0x800000`: kernel startup, TLB setup, and an LZO1X-style decompressor at `0x800160` |
| Payload | a `WAD` blob at file offset `0x7080`, 1,662,911 bytes, in `.rodata` |

The disc's ISO9660 filesystem holds only the loader, the IOP image and the DNAS
and network GUI files; the rest of the image is read by sector number, outside
the filesystem (see wrench's `docs/file_loading.md`).

### The packed image

The payload starts with `WAD`, a `u32` compressed size and 9 bytes of padding,
then packets in an LZO1X-style format. The compressor pads at every 0x2000-byte
boundary with a `12 00 00` packet followed by `0xEE` fill, because the game
streams the data through the scratchpad in 0x2000 blocks. Decoding state and
the match window continue across those boundaries. `tools/unpack_wad.py`
decodes it: **5,157,636 bytes**, ending exactly at the declared size.

The unpacked image is a stream of 16-byte headers (`dest`, `size`, ELF type,
entry) each followed by its data: **17 sections**, entry point `0x1574E8`.
`tools/split_image.py` splits them and builds `baserom/SCUS_974.65.elf` (one
segment per section) for splat. `config/sections.txt` lists them:

| Section | Address | Size |
|---|---|---|
| `.vutext` | `0x00100080` | `0x1A0E0` |
| `core.text` | `0x0011A180` | `0x49990` |
| `core.data` | `0x00163B80` | `0x2E350` |
| `core.rdata` | `0x00191F00` | `0x13248` |
| `core.bss` | `0x001A5180` | `0x78AB8` |
| `core.lit`, `.lit` | `0x0021DC80`, `0x0021E180` | `0x4B8`, `0x2EF0` |
| `.bss` | `0x00221080` | `0x1A4908` |
| `.data` | `0x003C5A00` | `0x2B404` |
| `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` | `0x003F0E80`, `0x003F0F00`, `0x003F0F80` | `0xC`, `0x14`, `0x8` |
| `.text` (level code) | `0x003F1000` | `0x15C6D8` |
| `patch.data` | `0x0054D700` | `0x18` |
| `net.text` | `0x01E9A000` | `0x97330` |
| `net.nostomp` | `0x01F31380` | `0x6C20` |

Level code lives in `.text` and `.data`; those sections are overwritten when a
level loads, and each of the 47 levels carries its own overlay on the disc
(table of contents at sector 1001). The resident `.text` is the menus' code: 97
percent of it is inside the multiplayer menu overlay. See `docs/build/overlays.md`.

## Disassembly

`config/splat.yaml` (one segment per section) and `bash tools/setup_asm.sh`
generate `asm/`: **8,027 functions** (`core_text` 1,710, `net_text` 2,434, level
`.text` 3,883).

Level `.text` embeds scrambled data inside functions (a `b` jumps over it). The
words include fake branches, and splat then treats the first function as
running to the end of the section. `tools/find_functions.py` finds function
boundaries itself (section start, `jal` targets, after `jr $ra` plus delay
slot) into `config/symbol_addrs.txt` and gives each function with invalid
instructions its own subsegment (22 of them). A few still come out very large
and need their boundaries fixed by hand. `core.bss` and `.bss` are not split yet.

## Compiler, assembler and libraries

Moved to [`toolchain.md`](toolchain.md).

## Checking matches

`tools/audit_matches.py` compares every compiled function with the retail bytes
at its address, masking only the fields the compiled object relocates
(`tools/retail.py`, `fields()`). This is not
a link-time comparison, so a function that calls or reads the wrong symbol can
still count; `tools/audit_relocs.py` checks the relocation targets of the
exact functions against retail. `tools/diff_func.py` shows a function next to retail word by word;
`tools/try_variants.py` tries several source forms of one function at once.
`tools/progress.py` writes the reports (`docs/build/levels.md`); `tools/gen_progress_report.py` the old count
from `config/functions.tsv` and the audit result.

## Open questions

1. A linked image and a link-time comparison (relocations included).
2. The level overlays on the disc and their load addresses.
3. The float `nop` pattern above, and the scheduling differences.
4. `__moddi3`, `__udivdi3` and `__umoddi3` from source.
5. Splitting `core.bss` and `.bss`.
