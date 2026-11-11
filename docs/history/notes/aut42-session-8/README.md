This checkpoint preserves 187 rebuilt pending game-code candidates: 64 recovered from the interrupted, unreported aut42s7 session and 123 closed in this run. Nothing is adopted into progress. Work stays local on `aut-42-continuous-decomp`; no push or PR was made.

## Verification

The fresh complete build and official byte audit verify every retained candidate. They cover **6,864 compiled bytes** (7,160 with alignment), with zero candidate relocation mismatches or unresolved references. The whole candidate tree has 3,032 functions in the official exact set and zero not exact. `functions.tsv` records each source path, extent, provenance and SHA-256; `matches/` has one source patch per function.

All candidates were drafted from retail assembly/m2c or reconstructed siblings and iterated through the existing compiler/differ pipeline with the persistent Wine-server prefix. The pipeline was not changed. Calls, global addresses, argument positions and store widths were reviewed against retail. Scratch final validation checks 203 relocations with zero mismatches/unresolved; the three formatting-only repairs separately pass nine relocation checks.

Three compact recovered function definitions contained semicolons on their signature lines and were therefore invisible to the existing source-definition scanner: `func_004CCE70`, `func_L01_005D4BF0`, and `func_L00_0058FCA8`. Inserting a line break after each opening brace preserves every C token and makes all definitions visible. The formatted functions were recompiled, and a further complete build was used for the official audits and packaging. No scanner or compiler changes were needed.

## What made the difference

Restoring unused leading argument positions, distinguishing integer and float fields, matching byte/halfword store widths, using the correct operand order and byte stride in address arithmetic, and declaring ignored callee returns void closed several earlier near misses. File-wide `-fno-schedule-insns2` closes a family of network wrappers; all retained flags remain per translation unit. The fresh pass over valid sub-24-byte functions closes 71 candidates before refinement. Handwritten routines, fragments, libgcc and libm are excluded from retained candidates. The known libc `_tolower` at `func_0011A180` was identified using `config/libc.tsv`, archived outside src, and excluded from the final candidate and attempt counts.

This run attempted 1,133 distinct game-code targets across drafting, refinements and validation, including the 64 recovered candidates. Most failed tiny drafts were fragments with unset input registers or branches outside their catalogue extent and were not retained.

## Retained near misses

- `func_01F03E40`: **BYTES 2/108** — branch and field store use a0 instead of v0 after the handle-returning call.
- `func_00498DB0`: **BYTES 1/24** — commutative address addition has reversed source-register order.
- `func_004F6498`: **BYTES 1/28** — commutative addition has reversed source-register order.

`near/` holds pending patches for their proper `nonmatching/` paths, including BYTES results and reproduction commands; `near.tsv` lists the remaining instruction differences. These patches are not adopted because both versions' metadata still need regeneration. Add rows to `nonmatching/README.md` when landing them.

## Landing prerequisites

The existing baseline still has **27 relocation mismatches in 26 functions, zero unresolved**, unchanged by this work: the previously documented global-reference problems and the claimed level-41 0.05f versus 20.0f literal error. The `d7` claim and source for `func_L41_003BEE28` remain untouched, as do all previous pending patches and other owners' claims.

PAL dumps, including `baserom/pal/main.elf`, are still absent. US map and report writes were exercised with the candidates present. The PAL map write fails for missing data; metadata-only PAL report writing cannot verify new placements. No PAL placement was guessed. The baseline's existing map drift remains documented in session 2.

After preserving the verified patches, all candidate C was moved to scratch archives under the landing lock, and the original maps, reports and README tables were restored from backups that match HEAD. The original interrupted source forms and report state are also retained in scratch. The restored baseline was fully rebuilt: its byte audit has zero not exact, its relocation audit has the same 27 mismatches, and its current US/PAL map, progress and legacy checks pass. `verification.json` records the outcomes and explicit blockers.

Only notes, verified source patches and attempt metadata are committed. Newly created unsuccessful claims are released; retained candidate claims and previous owners' claims are preserved. Source adoption requires coordinating the baseline repairs, obtaining legal PAL dumps, and passing the full build, both audits and both versions' map/report checks. Keep source commits per function or closely related group when landing.

AUT-42 remains in progress and its hourly autopilot remains active. There was no usage-limit interruption. The run took about 47.5 minutes through final verification, including the recovered-work build and the final candidate/baseline builds.
