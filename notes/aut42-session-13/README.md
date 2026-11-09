This checkpoint preserves **34 pending game-code candidates**, covering **3,420 compiled bytes** (3,504 bytes with catalogue padding). It recovers **18 candidates** from the usage-interrupted session 12 and closes **16 additional candidates**. **No functions are adopted into progress.** No push or PR.

## Verification

Every retained candidate passes a fresh scratch compile, the full-build official byte audit, and full-build relocation checking. Candidate build: **2,879 exact / zero byte failures**. Every one of the 34 retained candidates appears explicitly in the official exact set, with zero candidate relocation mismatches or unresolved references; scratch checking covers **146 relocations**. The full relocation failure list is byte-for-byte identical to the baseline: **27 mismatches / zero unresolved**. All 34 staged sources have recognized definitions and match their scratch source hashes. US map/report generation and checks and the legacy check pass. PAL generation cannot run without the missing program dumps; its checks flag the 34 temporary sources and three near files. No candidates are adopted through that failed gate. The restored-baseline verification is recorded below.

## What made the difference

- Explicit incoming argument forwarding in `func_004F3440` and `func_00488828`: independent source review caught that their first scratch-exact drafts depended on accidentally preserved incoming registers. Corrected sources pass fresh scratch compilation.
- Correct word-table stores in `func_L00_00717DF0`, a signed full-width return in `func_00488828`, and correct leading argument positions in `func_004A28F0`, `func_0053CA40`, `func_00547FF8` and `func_00497980`.
- Correct word-table and halfword accesses plus an unsized global table in `func_L00_00670708`.
- Narrow volatile access and independent store order in `func_0047B9B8`; ordinary source store order closes `func_00489478`.
- Correct ignored return declarations in `func_004B01C8`, `func_004B1238` and `func_004970A0`.
- Retail returns zero or a callback result from `func_00505238`; its non-void declaration closes the earlier BYTES 24/464 scheduling miss in `func_004D7998`.
- Initializing a temporary only after the context helper call avoids keeping an unnecessary callee-saved register live and closes the typed `func_00505B70`.
- A fresh context-aware draft closes `func_L00_00770CA8`; corrected raw typed accesses close `func_004F5428`.
- Recovered candidates include global-object field offsets, callback/argument declarations, context-derived prototypes and call-field widths. Their previous source-review corrections are preserved.

## Retained near misses

- `func_004D0038`: **BYTES 7/232**. Modulo numerator/divisor/result registers and the final address operand order differ.
- `func_0050CC98`: **BYTES 15/280**. Byte-address scaling is corrected. Independent reset stores remain scheduled differently. Structured and raw drafts, whole-file settings and volatile accesses did not close it.
- `func_005054F8`: **BYTES 6/228** (232 bytes including retail padding). A complete descriptor object removes an unnecessary saved register; initialization timing fixes another. Only descriptor address setup and callback-result argument moves remain in a different order. Explicit null/live paths, callback return types and whole-file register-move settings did not close it.

The near sources are compiled freshly in their proper `nonmatching/game/` paths with temporary README rows; they are never placed in `src/` or counted as exact. Their patches and hashes are preserved separately. Existing near files, including `func_004D7998`, and their README rows are preserved for coordinated landing.

## Review and provenance

Independent read-only review checked catalogue classification, metadata definition recognition, calls/globals, memory widths, offsets, pointer scaling, control flow, and opaque callees' incoming arguments. It found two important implicit-argument defects, both corrected and recompiled. Final helper and near-source review found no additional issue. Source equality and definition recognition are also checked automatically. The build pipeline is unchanged; flags apply to entire translation units. No retail data, assembly or toolchain material is included.

`functions.tsv` records candidate paths, extents, provenance and SHA-256; `matches/` contains individual pending patches. `attempts.tsv` records drafts and compile failures as attempts, never matches. The current pass attempts or recompiles 640 distinct game-code targets; including the recovered session, 1,496 distinct targets are recorded. The earlier run ended under a provider usage limit; no workaround or scheduler change was made.

## Older pending-patch review

`prior-argument-review.md` records 17 confirmed implicit-argument defects in older session-6/8/9 pending patches. No older patch or claim was changed. These need explicit forwarding, source review and fresh audits before adoption; one requires careful vector/floating-point ABI reconstruction. The current session's two similar defects were repaired before final verification.

## Landing prerequisites

PAL program dumps, including `baserom/pal/main.elf`, remain missing. The baseline has 27 relocation mismatches in 26 functions and zero unresolved references, as documented in earlier session notes: global-symbol problems and the separately claimed level-41 literal error. Existing owners' claims and source files are preserved. Both versions' map/report generation is exercised with the temporary candidates and near files, with no guessed PAL placements retained. Candidate-only audit success does not satisfy the zero-baseline-error gate for adoption.

Temporary candidate files were archived out of `src/` under the landing lock; temporary near sources and compiler artifacts were archived in scratch. Both maps, both reports and README files were restored byte for byte. A second full baseline build completed, and fresh audits reproduce **2,845 exact / zero byte failures**, the same **27 relocation mismatches / zero unresolved**. US/PAL map and progress checks and the legacy check all pass. The known relocation failure remains explicit; the full zero-relocation-error adoption gate is not met. The 705 pre-existing definitions outside the old US audit lists are unchanged; US map generation checked them at their catalogue locations.

All 37 delivered patches pass `git apply --check` against the restored tree, and every patch's source hash agrees with its TSV entry. No permanent source, near-miss file, map, progress report or README table was changed outside this notes checkpoint.

AUT-42 remains in progress and the hourly autopilot remains active. New unsuccessful claims are released; matched candidates and earlier owners retain theirs.

Verification completed after approximately **45.9 wall-clock minutes**, including three full builds. No usage-limit interruption occurred in this run.
