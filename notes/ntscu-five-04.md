# Five-function NTSC-U follow-up

The previous ten verified functions (564 retail bytes) were squashed at
the user's request into `486e1069`, preserving the identical content tree.
Their seven unpublished commits remain on the local recovery branch
`codex/deadlocked-before-squash-20261031`. Nothing was pushed.

A fresh Luna Medium probe safely fetched origin/main at `fe6ec0d2` and
refreshed local source/maps, claims, near misses and all open/draft PRs.
The branch was one local commit ahead and 69 behind; no merge or rebase
was performed. The only open PR, #54, had expanded to seventeen PAL
functions at `a2469f02`. Its actual source patch was inspected. Five
unclaimed NTSC-U functions were selected with no local/upstream/PR/history
overlap or normalized duplicate among existing same-size US source places.
PAL bytes remain absent, so no PAL byte-equivalence claim is made.

The primary claimed exactly five as `codex-20261031-five-04`. Two Terra
Medium workers handled one function at a time in separate scratch
directories, with no nested agents and no numerical attempt ceiling.
Every candidate is logged and preserved. All five matched with the already
approved original EE-GCC 2.96 profile, whole-file `@ee296 -O2 -G0`:

| Function | Retail bytes | Candidate runs | Behavior |
|---|---:|---:|---|
| `func_01EAA020` | 52 | 9 | Null returns 2; call `func_00126BE0` with word +0xC; -1 maps to 900 (0x384), other results to 0 |
| `func_01EAA060` | 52 | 1 | Same contract with the distinct `func_00126BC0` target |
| `func_01EA9FE8` | 52 | 1 | Same contract with the distinct `func_00126BB0` target |
| `func_01EAA0D0` | 96 | 13 | Initialize five words; return 1 for nonzero unsigned ordered bounds, otherwise 0; invalid bounds store status 2 |
| `func_01EA9D98` | 72 | 14 | Clear byte 0 and words 4/8; call `func_01EA9F90(context)`; mark byte 0 on success and preserve helper status; null returns 2 |

The total is **324 bytes and 38 logged candidates**. No selected function
remains unmatched. Negative early-return C resolved the shared-result
allocation/layout differences; no new toolchain change was needed in this
batch. No register pins, artificial operations, volatile ordering, output
patches or altered calling conventions were used.

Primary review checked actual assembly rather than the scout's rough
semantic descriptions: 900 is decimal `0x384`, the wrappers test -1, the
initializer has unsigned ordered bounds, and the resetter returns the
helper status. These descriptions were corrected in the ignored report.
The syscall stubs' observed return use requires signed-word return
declarations in the new wrappers; unrelated existing void declarations
were left alone. The reset helper reads its incoming context pointer and
writes fields +0xC/+0x10, so the caller passes the pointer explicitly and
its private context type includes that minimum prefix.

All complete opcode/register/constant fields match. The initializer's
96 bytes match without masking; standard resolution of the four verified
JAL relocations makes each other complete function byte-identical, with no
alignment padding and no compiler object modified. Integration took the
landing lock. Every actual source was rebuilt through the normal launcher
and independently checked again before installing its new object. The four
actual call targets were audited separately, even for the similar wrappers.

Only the five new rows from the official US map generator were adopted;
all earlier rows and their order remain unchanged, including the recorded
unrelated regeneration discrepancies. US coverage/progress and whitespace
checks pass. US progress is **4,166 functions / 323,152 matched bytes**.
The legacy audit adds exactly five functions, reaching 3,513 exact while
retaining the same three non-exact and 761 unlisted functions. The full
like-for-like relocation discrepancy records remain byte-identical: 80
existing mismatches and three unresolved targets. No clean whole-tree
audit is claimed. All 136 installed compiler/tool files retain their
recorded hashes.

PAL source/metadata are untouched. Its coverage guard still fails because
PAL inputs are absent and now lacks fifteen local US rows across these
batches. No PAL progress was invented or regenerated. Proofs, candidates,
logs, PR exclusions and baseline snapshots remain under ignored
`build/try/` and `build/batches/codex-20261031-five-04/`. The matched claims
are retained. No push, PR, publication or game launch was performed.
