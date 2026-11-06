# Five more NTSC-U network helpers

This collection adds five verified functions, **172 retail bytes**, after
`d853ce16`. The previous twenty local matches remain unchanged. All five
claims are retained as `codex-20261101-five-06`.

| Function | Bytes | Behavior |
| --- | ---: | --- |
| `func_01EBDED0` | 32 | Always clear the required word output; null context returns positive 0xD2F2, otherwise copy word +0x70 and return 0 |
| `func_01EBDEF0` | 32 | Always clear the required halfword output; null context returns positive 0xD2F3, otherwise copy unsigned halfword +0x5C and return 0 |
| `func_01EB72B0` | 36 | Check output and context pointers; return 2 without writing on null, otherwise copy unsigned halfword +0x1A2 and return 0 |
| `func_01EB4E40` | 36 | Forward the buffer and first word of an eight-byte value to `func_01EA91C0`; return 0 |
| `func_01EB4FF0` | 36 | Pass fixed address 0x001B26C0 to `func_01E9D390`, ignore its result and return 0 |

Origin was freshly fetched without merging. All seventeen currently open
PR patches, local source/maps/near misses/claims/history and shared xmap
records were checked. Strict normalized fingerprints found no duplicates
among same-size US NET functions. Neither version's map had selected rows.
PAL inventories have corresponding addresses and extents, but PAL retail
inputs remain absent, so byte equivalence is unverified.

Two reused Terra Medium workers handled one function at a time in separate
scratch directories, with no nested workers or numerical attempt ceiling.
Every function matched its first candidate using the existing whole-file
profile `@ee296 -O2 -G0`. All five candidates and logged runs are preserved.
No compiler, toolchain or build-pipeline changes were needed.

Primary review checked actual assembly, ABI, widths, offsets, null behavior
and write ordering. The formatter wrapper's m2c draft omitted the unchanged
buffer argument in a0; the reconstructed C explicitly forwards it together
with the first aggregate word in a1. The callee consumes both registers to
format dotted-decimal bytes. The aggregate's original type identity is
unknown. The other wrapper passes an address, not the contents there; its
callee overwrites incoming a0 before use and returns a word that is ignored.

Integration took the landing lock. Each actual source was rebuilt through
the normal launcher and independently checked again before installing its
object. All 172 bytes match after standard relocation resolution in a proof
copy held only in memory, with no padding or object edits. The three getters
match without any masking. Independent target checks verify both calls and
the HI16/LO16 address pair, with zero new mismatches or unresolved targets.
All 136 recorded installed toolchain files retain their hashes.

Official US coverage/progress checks pass at **4,176 functions / 323,504
bytes**. Only the official generator's five new map rows were adopted;
all old rows and order were preserved. Its 59 unrelated regeneration
discrepancies and complete raw output remain recorded locally. The legacy
audit reaches 3,523 exact and retains the same three non-exact and 761
unlisted functions. Full relocation discrepancy records remain byte-identical:
80 existing mismatches and three unresolved entries.

PAL files are untouched. Its coverage guard lacks twenty-five local US rows;
no PAL rows or progress were fabricated. Proofs, snapshots, raw reports and
attempts remain ignored under `build/batches/codex-20261101-five-06/` and
`build/try/`. No push, PR, publication, game launch or desktop interaction.
