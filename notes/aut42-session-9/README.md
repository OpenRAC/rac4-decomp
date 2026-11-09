This checkpoint preserves **70 newly audited pending game-code candidates**, covering **3,548 compiled bytes** (3,668 bytes with catalogue padding). **No functions are adopted into progress.** Work stays local on `aut-42-continuous-decomp`; there is no push or PR.

## Verification

The complete candidate build and official byte audit place every retained candidate in the exact set: 2,915 exact functions overall, zero not exact. Candidate relocation checks and the full-build relocation audit find zero candidate mismatches or unresolved references. The selected scratch objects independently pass 101 relocation checks. `functions.tsv` records each source path, extent, provenance and SHA-256; `matches/` contains one source patch per function.

All candidates were reconstructed from retail assembly and m2c drafts, with typed memory accesses where automatic structure reconstruction failed. Compilation and iteration use the existing `try_func` compiler/comparison pipeline and persistent Wine-server prefix. Calls and named globals were reviewed against retail; stores and constants pass the official byte audit. The compiler pipeline is unchanged, and retained settings apply to entire translation units. No libgcc, libm or core-library code is retained.

## What made the difference

- Unsigned address and index arithmetic gives `func_004737F0` the retail register allocation.
- Nested typed memory accesses recover getters, setters, initializers and wrappers that the automatic struct builder could not draft.
- Restoring unused leading integer and float argument positions fixes wrappers, including the third float register in `func_L15_004E38D8`.
- Using a halfword read/store fixes `func_L13_004BE4B0`.
- Typed indexed fields keep offsets on the retail memory instructions instead of folding them into global relocations.
- Correct source-pointer arguments and store ordering close `func_L00_00716790`; an ignored callee return type and store ordering close `func_004AFC80`.

The run attempted 2,060 distinct game-code targets, recorded in `attempts.tsv`, including 1,800 raw-access reconstructions. Larger automatic drafts, file-wide option sweeps, prototype repairs and the final twin searches produced no further candidates beyond the retained set. Known branch-likely, boolean-inversion and commutative-register-order walls remain unresolved; their earlier pending patches and notes are preserved. Broad option sweeps and prototype loosening did not close them. Avoid repeating these raw batches without a new type or control-flow hypothesis; the attempt table records their best results.

## Retained near miss

`near/func_01EB4D80.patch` preserves `func_01EB4D80` for its proper `nonmatching/net/func_01EB4D80.c` path. A fresh compile while it temporarily occupied that path reports **BYTES 1/44**: the final byte combination uses `or` where retail uses `addu`. Its unsigned C reads the four bytes in order. It is never placed in `src/` or counted as exact. The near-miss file was archived and its temporary README row removed because PAL metadata generation must cover both `src/` and `nonmatching/`. Add the README row and regenerate both versions when landing the patch.

## Landing prerequisites and restored baseline

PAL dumps, including `baserom/pal/main.elf`, remain absent. Both versions' map/report write commands were exercised with the temporary candidates. PAL placement generation fails for the missing dump; metadata-only report writing cannot verify new PAL placements. No PAL mapping was guessed. The candidate PAL checks report 71 uncovered entries: 70 source candidates and the temporary near miss. Neither source nor near-miss adoption is retained while that gate is blocked.

The baseline still has **27 relocation mismatches in 26 functions, zero unresolved**, unchanged by this work: the previously documented global-reference problems and the claimed level-41 0.05f versus 20.0f literal error. The `d7` claim and source for `func_L41_003BEE28` remain untouched.

After packaging the audited candidates, their temporary source files were moved to scratch archives under the landing lock. The original maps, reports and README tables were restored byte for byte. The baseline was fully rebuilt and audited again: 2,845 exact / zero not exact; the same 27 relocation errors / zero unresolved. US/PAL map and progress checks and the legacy progress check pass. The 705 pre-existing compiled definitions outside the legacy US byte-audit lists are unchanged; every new retained candidate is explicitly present in that audit's exact set.

New unsuccessful claims were released; matched candidate claims and all earlier owners' claims were preserved. Source adoption still requires the baseline relocation repairs, legal PAL dumps, both versions' regenerated metadata and the full verification gate. Land source changes per function or tightly related group.

AUT-42 remains in progress and its hourly autopilot stays active. No usage-limit interruption occurred. Verification finished after approximately 46.0 minutes.
