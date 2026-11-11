# Twenty NTSC-U network helpers

This collection adds **twenty independently verified functions / 696 retail
bytes** after `617abef3`. The earlier twenty-five local matches remain closed.
The twenty matched claims are retained as `codex-20261101-twenty-07`.

| Function | Verified bytes | Behavior |
| --- | ---: | --- |
| `func_01EB0D78` | 28 | Clear 0x34 bytes and return the destination |
| `func_01EB4DB0` | 28 | Clear eight bytes and return the destination |
| `func_01EDA098` | 28 | Clear 0x30 bytes and return the destination |
| `func_01F07154` | 28 | Clear 0x40 bytes and return the destination |
| `func_01EC3498` | 32 | Call `func_01EA9ED8` with fixed context 0x001B69C0 and null optional output; preserve status |
| `func_01ED5570` | 32 | Copy 0x18 bytes from 0x001B7678 to the incoming destination |
| `func_01ED5638` | 32 | Copy 0x30 bytes from 0x001B7690 to the incoming destination |
| `func_01ED9BE8` | 32 | Forward two inputs and constants -0x3C6, 0x12C and zero; preserve callback result |
| `func_01EF21FC` | 32 | Clear word +0x400 before zeroing the first 0x400 bytes; return destination |
| `func_01ED5548` | 36 | Copy 0x18 bytes from the incoming source to fixed destination 0x001B7678 |
| `func_01EDB388` | 36 | Clear 0x114 bytes and return zero |
| `func_01EA0610` | 40 | Initialize valid output to 0x100, then read context word +0x404; null returns 0x17 |
| `func_01EA47E8` | 40 | Read a word from a nonnull table only for unsigned indices below 256 |
| `func_01EC2840` | 40 | Null returns 2; nonzero +0x3C returns 0xD6DA; otherwise set +0x38 to one and return zero |
| `func_01EC9B08` | 40 | Same guarded output contract, distinct context word +0x408 |
| `func_01ED8500` | 40 | Null returns -21; otherwise clear words +0/+4/+0xC, set halfword +0x10 to -1, preserve +8 |
| `func_01EEE000` | 40 | Test ASCII A-Z or a-z using defined unsigned range arithmetic |
| `func_01EDB030` | 36 | Forward a halfword-array pointer and shifted/masked word count; return the helper's mask |
| `func_01EFA2A4` | 36 | Forward the object, signed low byte and zero flag to `func_01EFA118` |
| `func_01EED4D8` | 40 | Call `func_01F0C090` with address 0x0019C2D8 and code 0xE7, then return zero |

Origin was freshly fetched without merging. All seventeen open PR patches,
local source/maps/near misses/claims/history, normalized same-size US NET
fingerprints and shared xmap records were checked. PR #54 had grown to
twenty-eight PAL functions, without selected-function overlap. PAL bytes are
absent, so equivalent inventory addresses do not prove regional byte identity.

Two reused Terra Medium workers matched one function at a time in disjoint
scratch folders. The twenty landed functions retain 36 candidates and logged
runs. They use existing pinned `@ee296 -O2 -G0`; the signed-byte wrapper adds
whole-file `-fno-optimize-sibling-calls`, and the final fixed-address wrapper
adds whole-file `-mno-split-addresses`. No toolchain or build-pipeline change
was made. Plain C only; no pins, inline assembly, barriers, volatile ordering,
invented dependencies, undefined-overflow tricks or object edits.

One originally selected function, `func_01EEEDA0`, remains a deferred near
miss. Its initial word load and output write ordering are understood, but an
independent address calculation and store remain swapped. Its 57 candidate
runs, seven diagnostic runs, RTL-comment evidence and notes remain local.
A bounded fresh Terra High diagnosis confirmed the scheduling tie after the
Medium reviews. No numerical attempt ceiling was imposed. Its claim was
released and the freshly checked `func_01EED4D8` substituted within this
twenty-match batch. The near miss is excluded from source and progress.

Primary review checked actual callees, incoming arguments, signedness,
memory widths, offsets and write ordering. The memset/memcpy-like helpers
return their destination pointers; tail wrappers preserve those results.
The signed-byte helper has arbitrary v0 on early paths, so its wrapper uses
a void interface. Other inferred source type identities remain provisional.
Integration took the landing lock. Every actual source was rebuilt through
the normal launcher and checked again before installing its object. All
696 bytes match after standard relocation resolution in an in-memory proof
copy only; six functions match without masking. All nineteen call/address
target groups pass independently, with no new mismatch or unresolved target.

Official US coverage/progress checks pass at **4,196 functions / 324,212
bytes**. This report credits **708 new bytes**, twelve more than the proven
696: `config/us/inventory.tsv` merges the 32-byte `func_01EC3498` with its
separate 12-byte neighbor `func_01EC34B8`, while the legacy function list and
new official map row correctly record the matched 32-byte extent. The extra
twelve bytes are neighboring code, not zero padding, and are **not proven
by this batch**. The existing catalogue and reporting tools were not changed;
the full discrepancy is recorded locally. Do not equate that report credit
with additional verified code.

Only the official generator's twenty new US map rows were adopted; all old
rows and order remain unchanged. Its 59 unrelated regeneration discrepancies
and raw output are retained. The legacy audit reaches 3,543 exact while
retaining the same three non-exact and 761 unlisted functions. Full relocation
discrepancy records remain byte-identical: 80 existing mismatches and three
unresolved targets. All 136 recorded installed toolchain hashes are unchanged.

PAL files are untouched; its coverage guard lacks forty-five local US rows.
No PAL results were fabricated. All scratch, proofs, snapshots, raw reports
and selection amendments remain ignored under `build/try/` and
`build/batches/codex-20261101-twenty-07/`. No push, PR, publication, further
squash, game launch or desktop interaction was performed.
