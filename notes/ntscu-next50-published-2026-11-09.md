# NTSC-U continuation publication - 2026-11-09

Adds **42 newly matched functions (3,552 bytes, 93 actual relocation checks)** and corrects **20 existing function interfaces (1,948 bytes, 91 relocation checks)** on upstream `0bddadfd0832b633c69c2ee14e3c54ea41afa72d`.

The reserved batch reached 43 verified local matches. One, `func_0011D5D8`, was independently integrated upstream in PR131; this change retains its evidence-supported interface correction and does not count it again. Three newly integrated formatter/scanner callers receive compatibility corrections as well. PR121 remains separate; none of its 40 new matching sources or allocator header is copied. The optional native scratch-storage transport prerequisite is the same change proposed there, and leaves compiler inputs, flags and emitted instructions unchanged.

## Verification

- Built an isolated worktree from current upstream. Reused 7,510 objects only after complete source identity, 29 common-header identity checks, unchanged instruction-fixup checks and copied-object SHA256 verification; built the other 878 baseline units. The upstream host-runner change is retained, with the same native Windows runner selected per invocation. Runtime sources/headers are unchanged.
- Rebuilt all 62 complete changed translation units. Each matches the entire retail function after resolving every relocation; constants, calls, globals and relocation targets were reviewed. Existing function instructions remain byte-identical. The existing 004F0AB0 catalogue extent includes four zero alignment bytes under the normal audit/link-padding rule; all 42 new functions have exact compiled extents without padding. No generated assembly or output rewriting is used to force a match.
- Reviewed the reconstructed ABI contracts, variadic slot handling, pointer widths, record fields, call/global identities and target input domains. A separate bounded correctness review checked the three newly integrated callers against owned format metadata.
- 28 isolated-compiler and command-route tests pass.
- Fresh full-tree audit: 5,650 to 5,692 exact, exactly the 42 additions. The complete 164 pre-existing non-exact and 1,932 unlisted records are unchanged. Relocation audit retains the same 27 mismatches in 13 functions and zero unresolved; those legacy discrepancies are not new failures.
- US map/progress checks pass: 7,715 of 18,170 functions, 748,432 matched bytes. Every unrelated upstream map row is retained byte-for-byte. The near index is regenerated from current files, including previously unindexed upstream drafts; this gives no additional matching credit.
- PAL coverage remains blocked: 49 missing rows (42 new definitions plus seven retained drafts), with local RAC4 PAL retail inputs unavailable. PAL map/report are unchanged; earlier-game PAL inputs do not establish RAC4 PAL matches. This publication is a draft pending that regional coverage.

## Interfaces and input domains

- Formatter `0011D5D8` is reconstructed as `s32(const char *, ...)`, forwarding the actual formatter status. Scanner `0011D9A8` is `s32(void *, const char *, ...)` with its target-specific temporary-stream layout and compiler-provided variadic cursor. These are matching PS2 interfaces, not portable host implementations.
- Scanner consumers pass the output pointer types required by their formats. The new `L00_0076DED0` correction preserves its public scalar address-word interface and explicitly passes an input pointer plus two unsigned-32 output pointers. Its input string and aligned outputs must be valid. The two new print callers use formats consuming no additional arguments and discard the result.
- Pointer/address-word conversions assume the pinned 32-bit EABI and observed valid object domain. Record initializers require writable aligned records/tables of the documented offsets and extents. Unsigned sequence arithmetic preserves modulo-2^32 behavior.
- The clock converter retains both unsigned 64-bit products and divides through the actual unsigned-64 helper. All u32 inputs fit its result range; observed direct callers use the full result. Its compiler-revision research reference is credited in THIRD_PARTY_NOTICES.md; no donor C was imported.
- Existing timer forwarding helpers use unsigned-32 output pointers and signed status. EA0BD0 preserves the inherited failure path that can leave a local unwritten; its arithmetic payload domain requires a successful write. This change does not claim to repair that existing behavior.
- E9D378 has an inferred unused context-pointer parameter grounded in its observed direct caller. Its constant-zero body is unchanged. Original source arity and exhaustive indirect-call coverage are not claimed.

## New matches

| Function | Bytes | Relocation checks |
| --- | ---: | ---: |
| `func_0011D9A8` | 152 | 4 |
| `func_0012E848` | 112 | 1 |
| `func_0015B808` | 64 | 4 |
| `func_01E9B290` | 60 | 3 |
| `func_01E9BAE0` | 72 | 1 |
| `func_01E9BB28` | 72 | 1 |
| `func_01E9C130` | 64 | 1 |
| `func_01E9C170` | 64 | 1 |
| `func_01E9C620` | 88 | 2 |
| `func_01E9EB98` | 64 | 1 |
| `func_01EA37B0` | 64 | 1 |
| `func_01EA4520` | 76 | 2 |
| `func_01EABC80` | 80 | 6 |
| `func_01EACEA0` | 60 | 1 |
| `func_01EACFC0` | 84 | 3 |
| `func_01EB0D18` | 92 | 3 |
| `func_01EB1040` | 92 | 3 |
| `func_01EB1B30` | 92 | 3 |
| `func_01EB30C8` | 108 | 3 |
| `func_01EB4D28` | 88 | 1 |
| `func_01EB8EB0` | 72 | 1 |
| `func_01EC41E8` | 100 | 1 |
| `func_01ED4380` | 100 | 3 |
| `func_01ED43E8` | 72 | 2 |
| `func_01EF262C` | 108 | 3 |
| `func_01EF339C` | 56 | 1 |
| `func_01EF5FE8` | 96 | 2 |
| `func_01EF6A28` | 96 | 2 |
| `func_01EF83AC` | 136 | 4 |
| `func_01EF8CB4` | 116 | 5 |
| `func_01EFA92C` | 56 | 0 |
| `func_01EFBFB4` | 76 | 2 |
| `func_01EFCF64` | 120 | 3 |
| `func_01EFD334` | 116 | 3 |
| `func_01F0026C` | 56 | 2 |
| `func_01F035B0` | 88 | 6 |
| `func_01F044F4` | 68 | 1 |
| `func_01F05D34` | 56 | 1 |
| `func_01F05FEC` | 72 | 1 |
| `func_01F0A128` | 68 | 1 |
| `func_01F0B598` | 72 | 1 |
| `func_01F0BBF8` | 104 | 3 |

## Existing interface corrections

| Function | Bytes | Relocation checks |
| --- | ---: | ---: |
| `func_0011D5D8` | 100 | 3 |
| `func_001564C8` | 28 | 1 |
| `func_00158198` | 164 | 13 |
| `func_00162CA0` | 192 | 8 |
| `func_004F0AB0` | 240 | 12 |
| `func_004F2048` | 40 | 2 |
| `func_01E9D378` | 8 | 0 |
| `func_01E9DD18` | 40 | 1 |
| `func_01E9DD68` | 40 | 1 |
| `func_01EA0BD0` | 32 | 1 |
| `func_01EA9718` | 80 | 1 |
| `func_01EAB210` | 20 | 1 |
| `func_01EABC68` | 20 | 1 |
| `func_01ED68A0` | 104 | 6 |
| `func_01EF6594` | 168 | 13 |
| `func_01EF6CC0` | 152 | 13 |
| `func_L00_00767CE0` | 104 | 2 |
| `func_L00_0076DED0` | 40 | 2 |
| `func_L00_00775C40` | 176 | 2 |
| `func_L00_00778FF0` | 200 | 8 |

## Deferred and reserved

The seven below are retained as plain-C near misses, excluded from the build and matching count. They are deferred until a specific new source-family or compiler-phase witness appears; repeated tied source/flag trials are closed. A sibling compiler-rule audit found no justified shared compiler change to apply. This does not prove the functions impossible.

| Function | Retained gap |
| --- | --- |
| `func_001633D0` | 31/56 bytes differ |
| `func_01EABC10` | 13/88 bytes differ |
| `func_01EB5B88` | 13/60 bytes differ |
| `func_01EF4E64` | 8/76 bytes differ |
| `func_01EF5938` | 16/116 bytes differ |
| `func_01EF73F0` | 10/156 bytes differ |
| `func_01F04BF0` | 56-byte candidate versus 60-byte retail |

The four earlier compiler-layout cases remain reserved and untouched: `func_01EA7248`, `func_01EADF8C`, `func_01EC22E0`, `func_01F074CC`. All published functions and interface corrections stay reserved until integration or explicit release. Coordination remains in issue112; no retail data, generated assembly, build output or toolchain is committed. No game/runtime test is claimed.
