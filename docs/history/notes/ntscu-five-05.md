# Five NTSC-U network helpers

This collection adds five independently verified functions, 180 retail bytes,
after the fifteen-function local commit `52169993`. The prior fifteen remain
unchanged. Claims are retained as `codex-20261101-five-05`.

| Function | Bytes | Candidate files / logged runs | Whole-file profile | Behavior |
| --- | ---: | ---: | --- | --- |
| `func_01EA9800` | 36 | 11 / 12 | `@ee296 -O2 -G0` | Copy one byte when both pointers are valid; return 2 on null, otherwise 0 |
| `func_01EB4DE8` | 36 | 2 / 3 | `@ee296 -O2 -G0` | Compare the first words of two eight-byte values passed by value |
| `func_01EB7288` | 36 | 2 / 2 | `@ee296 -O2 -G0` | Read unsigned halfword +0x1A4 into a halfword output; null pointers return 2 without writing |
| `func_01EB84B8` | 36 | 1 / 1 | `@ee296 -O2 -G0` | Clear a valid word output before checking context; read unsigned halfword +0x19C on success |
| `func_01EC52B8` | 36 | 1 / 1 | `@ee32-040921 -O2 -G0` | Return 0 for 0, -84 and -108, otherwise 1 |

Two Terra Medium workers handled one function at a time in separate scratch
directories. All 17 candidate files and 19 logged attempts are preserved;
the latter include two initial failed compiler launches. There was no
numerical attempt ceiling. The byte-copy register allocation matched after
using separate early returns and a byte temporary. Existing pinned compiler
profiles sufficed; no compiler or build-pipeline changes were made.

Primary review checked each function's actual assembly, argument registers,
return values, offsets, access widths and null-check/write ordering. The
comparison spills the two incoming 64-bit registers into separate 16-byte
stack slots and compares their low words. An ordinary two-word aggregate
reproduces that ABI. The function is registered at table +0x58 by
`func_01EB4B60`; its adjacent initializer clears eight bytes, and the adjacent
predicate spills one eight-byte value. Original type identity remains
unknown; no direct caller or conflicting source declaration was found.

Integration took the landing lock. Each actual source was rebuilt through
the normal launcher and independently verified again before installing its
object. All 180 bytes match retail without relocation masking or alignment
padding. All five functions have no calls, globals or relocations; targeted
relocation checks have no mismatches or unresolved targets. No object bytes
were patched. The 136 recorded installed toolchain files retain their hashes.

US coverage and progress checks pass at **4,171 functions / 323,332 bytes**.
The official US map generator's five new rows were adopted while preserving
all old rows and their order. Its 59 unrelated baseline row discrepancies
remain excluded, with the complete raw generated output retained locally.
The legacy audit is 3,518 exact, retaining the same three non-exact and 761
unlisted functions. The full relocation discrepancy record remains
byte-identical: 80 existing mismatches and three unresolved entries.

The recorded origin/main and PR #54/#55/#56 heads were unchanged. A current
GitHub search also surfaced PR #57 through #70; their actual patches add PAL
game functions with unrelated addresses and behavior, without selected NET
function overlap. PAL retail inputs remain absent, so PAL byte equivalence
is unverified. PAL source and metadata are untouched; its coverage guard
now lacks twenty local US rows, including these five. No PAL rows or progress
were fabricated.

Proofs, baseline snapshots, raw reports, overlap review, candidates and logs
remain ignored under `build/batches/codex-20261101-five-05/` and `build/try/`.
No push, PR, publication, game launch or desktop interaction was performed.
