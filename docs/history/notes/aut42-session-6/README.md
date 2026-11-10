This checkpoint recovers unfinished AUT-42 scratch work and preserves independently rebuilt pending C patches. No new C is adopted into progress: PAL dumps and the previously documented source/audit repairs remain landing prerequisites.

The recovered candidates came from interrupted, unreported scratch sessions labelled aut42s3–aut42s5. This run recompiled their C, reviewed external references, and required a fresh full-build byte audit plus candidate relocation checks before preserving them. Scratch verdicts alone are not the verification claim.

Useful refinements include missing argument registers, byte-based pointer arithmetic, byte/halfword versus word field widths, unused callees declared void, and the retail translation unit's register-save convention. The eight core functions using -fno-opt-stack retain that setting as a file-wide cflags comment. The compiler and assembler pipeline are unchanged.

A broad overlay selector briefly included entries classified as libgcc/libm. Those entries were excluded from recovery and counting, their temporary claims released, and the corrected selector accepts only common/level overlay classes. No library draft is retained here.

The pre-existing d7 claim and source for func_L41_003BEE28 are unchanged. Prior pending patches and other owners' claims are preserved. Unsuccessful claims created by this run are released at the checkpoint; retained candidate claims remain.

## Verified pending candidates

The fresh full build verifies **153 candidates**, covering **10,648 compiled bytes** (10,836 including retail alignment). Of these, 117 recover previously unreported scratch work and 36 were closed in this run. Every candidate appears in the official byte audit's exact set and has zero relocation mismatches or unresolved references. `functions.tsv` records each source path, provenance, extent and SHA-256; `matches/` contains one pending patch per function. The normalized final scratch sources separately pass 359 relocation checks.

Seven retained network near misses each differ by one byte; `near.tsv` records BYTES and the remaining instruction difference. Their pending `nonmatching/net/` patches include reproduction commands. When adopting them, add corresponding rows to `nonmatching/README.md` and regenerate both versions of the maps and reports. Boolean inversion and likely-branch differences remain after several source forms and file-wide optimization experiments; no compiler-output changes were made.

## Baseline and reporting blockers

The unchanged baseline still has 27 real relocation mismatches in 26 functions, with zero unresolved references: the 26 global-reference errors covered by session 2’s pending repair and the claimed level-41 0.05f versus 20.0f literal error. None belongs to a new candidate. The byte audit reports zero not exact. The exact source and references required for adoption must pass both whole-tree audits after coordinating those repairs.

PAL program data remain unavailable, including `baserom/pal/main.elf`. US mapping/report regeneration was exercised with the candidate C present; the corresponding PAL map generation cannot run without those dumps. Metadata-only PAL report writing does not verify PAL placement. The original maps/reports and README tables are restored together with the original source set. Existing legacy near-miss map drift remains documented in session 2; no guessed PAL placement or drift is committed.

`verification.json` records this run’s build/audit/report outcomes, including the expected blocked checks. Source adoption remains **zero**. Apply desired patches under the landing lock only after resolving prerequisites, then run the Wine-prefixed full build, both audits, both versions’ map/report writes and checks, and the legacy check. Keep source commits per function or related group.

The restored baseline was fully rebuilt and audited again, and its current US/PAL metadata and legacy progress checks pass. Only notes, source patches and verification metadata are committed. No push or PR was made.

This run attempted 2,466 distinct game-code targets across automatic drafting, recovery and refinement; most larger drafts were not close enough to retain. The 117 recovered and 36 newly closed candidates are disjoint from sessions 1 and 2. The session used about 43 minutes through final verification, with no usage-limit interruption.

Two blank-line whitespace cleanups were recompiled and passed a further official byte/relocation audit before packaging; both remained EXACT. Their source hashes reflect the cleaned C.
