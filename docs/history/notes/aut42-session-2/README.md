# AUT-42 session 2

This checkpoint preserves pending C patches; **none of these new functions has been adopted into the progress totals**. The source tree is restored after full-build verification. No compiler, assembler transformation or per-function compiler option was added.

## New candidates

The tools-first passes attempted 562 new targets; 258 produced function objects. Manual refinement closed 51 candidates, covering 6,040 retail bytes (5,920 compiled bytes plus alignment). `functions.tsv` lists each function, its sizes and its individual patch in `matches/`. All final scratch comparisons report EXACT, and the candidates pass 225 relocation checks with zero mismatches and zero unresolved references. The full build compiled 3,580 files; the official byte audit reported 2,896 exact, zero not exact, and the same 705 newer names outside its old lists. Every new candidate is in the exact set. The full relocation audit checked 7,688 references, with zero candidate errors or unresolved references. With the 25 global corrections applied, its only mismatch is the unchanged, already-claimed literal error described below. `verification.json` records the results; `attempts.tsv` distinguishes discarded experiments from retained candidates.

The useful changes were byte-based indexing in m2c's initially untyped pointer expressions, correct byte/halfword/quadword fields, missing incoming arguments, the object argument of indirect calls, float parameter types, unused callees declared `void`, and sibling-specific object strides and embedded-object offsets. Referenced calls and global addresses were reviewed against each function's assembly. Integer colour constants and the inline -1.0f constant are values, not data symbols.

`near-miss.patch` preserves `func_004E6FA0` for `nonmatching/game/`: **BYTES 3/96**. The global comparison allocates v0/v1 in the opposite roles to retail. Array/plain declarations and split/no-split addressing did not close it; no output manipulation was attempted. When adopting this near miss, also add its row to `nonmatching/README.md` and regenerate both versions' maps and reports. It remains outside the build inputs here.

## Existing source corrections

`global-references.patch` corrects 24 getters whose data symbol was named after the function instead of its actual GP target, plus `func_L00_006AA088`, which reverses two globals. These are 25 existing functions and 26 erroneous references, not 25 new matches. All corrected scratch functions remain EXACT; their references pass relocation verification. The patch is kept pending rather than claiming that source has been adopted.

The pre-existing claim on `func_L41_003BEE28` (`d7:L41_003BEE28`) is preserved and its source is unchanged. The stricter audit discovered an additional real error there: the C passes **0.05f**, whereas its level 41 GP literal at `0x00220CC4` is **20.0f**. Both the wrench overlay ELF and the US disc dump agree. The main program happens to contain 0.05f at the same address; session 1's statement that the literal agreed was therefore wrong. Literal checking must use the caller's program. Coordinate this repair with the existing claim and verify its generated code before landing it.

## Audit repairs

The compatibility updates are independent of candidate adoption:

- Three stale extents in the old tables now agree with the current US inventory/catalogue and existing map: `func_00161890` is 32 bytes, `func_00547A98` is 44, and `func_L01_004F3100` is 36. The baseline byte audit consequently reports 2,845 exact and zero not exact; its 705 newer catalogue names remain the responsibility of `match_map.py`.
- Calls to resident functions linked into levels are accepted only at their explicitly named `(function, level, address)` entries in `config/us/functions.tsv`. This reconciles 54 baseline call checks without accepting a neighbouring target or a copy in an unlisted level.
- `config/library_callees.tsv` identifies the already documented `__udivdi3` helper at `0x0012FEB0`, without adding it to the source-match aliases or progress. The prebuilt EE archive object has 1,488 instruction bytes equal modulo relocation fields and three consistent relocation checks. `library-callee-evidence.json` contains metadata only; no library object or retail bytes are committed.
- R_MIPS_LITERAL now masks only the immediate, retaining the opcode and destination register in byte comparisons. Its literal value is checked against the caller's GP address, and all references must agree on pool placement. Unknown forms or missing data remain unresolved; unresolved entries make the audit fail.

The 11 synthetic ELF regression tests exercise named copies, rejected wrong targets, literal values, nonzero pool offsets, inconsistent placements, eight-byte loads, retained instruction fields, unsupported instructions, and library-callee separation. They require neither proprietary data nor the compiler. An independent read-only code review found no blocking issue.

With the unchanged baseline C, the revised relocation audit reports **27 mismatches in 26 functions, zero unresolved**: the 26 global references above and the newly exposed wrong literal. These are real source errors; they are not masked away. The previous 80 mismatches/3 unresolved are therefore reconciled into 27 actionable errors.

## Landing prerequisites

This host still lacks the legally obtained PAL `SCES_532.85` program dumps, including `baserom/pal/main.elf`. Do not invent PAL placements or report verification using US data. Supply the PAL disc/dumps, coordinate the claimed literal repair, then apply the desired pending patches under the landing lock. Apply one new function per commit, or a tightly related group. Run the Wine-prefixed full build, both audits, both versions' match-map and progress writes/checks, and the legacy progress check according to the current repository docs.

The successful candidates remain claimed under their existing `aut42s2*` owners. Unsuccessful targets are released at the session checkpoint. Session 1's 49 pending candidates and claims are preserved.

## Reporting and restored tree

The US match-map write succeeded and explicitly marks all 51 candidates as matches. US progress generation/checking succeeded. The PAL map write failed on missing `baserom/pal/main.elf`; the PAL source/map check correctly rejected the 51 missing candidate rows. Its metadata-only progress write is not a PAL data verification. Temporary source, maps, reports and README changes were then restored to the baseline, leaving only these pending patches and the audit-tool updates. The final restored build compiled 3,529 files. Its fresh byte audit reports 2,845 exact / zero not exact; the relocation audit reports the 27 documented errors / zero unresolved. Both versions' progress metadata checks, the legacy progress check, all 11 regression tests, and pending-patch apply checks pass.

A fresh US regeneration on the restored tree also changes eight pre-existing near-miss map rows. This is a separate legacy-extent problem in `match_map.py:near_places`, which prefers `layout.retail_bytes` from the old lists: for example `func_L00_005190D8` is read as 100 bytes there but is 104 bytes in the modern catalogue, so it incorrectly changes from `near` to `none`. That lookup uses `retail.normalise`, not relocation masks, so this drift is independent of the literal-mask correction. Exact totals stay unchanged. The generated drift was not committed: the original maps, reports and README tables are retained, pending a proper near-miss lookup reconciliation and PAL data. Current metadata checks pass with those originals.
