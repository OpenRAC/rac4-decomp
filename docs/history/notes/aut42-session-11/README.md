This checkpoint preserves **46 audited pending game-code candidates**, covering **6,772 compiled bytes** (6,844 bytes with catalogue padding). It recovers **27 candidates** from the unreported interrupted session 10 and closes **19 additional candidates** in this run. **No functions are adopted into progress.** Nothing is pushed and no PR is opened.

## Verification

Every retained candidate passes a fresh scratch compile, the full-build official byte audit, and full-build relocation checks. Candidate build: 2,891 exact / zero byte failures. Candidate relocation mismatches and unresolved references: zero; the independent scratch check covers 216 relocations. All 46 source definitions are recognized by the metadata scanner. The compiler pipeline is unchanged, and flags apply only to entire translation units. None of the retained code is in the libgcc/libm/core-library areas.

`functions.tsv` records each candidate's source path, extent, provenance and SHA-256. `matches/` contains an individual source patch for each candidate. `attempts.tsv` includes 2,112 distinct targets across the recovered scratch session and current session; 1,482 distinct targets were attempted or recompiled in the current run. Draft and compile failures count as attempts, never matches. No retail assembly, binary data or toolchain files are included.

An independent read-only review checked classification, definition recognition, source equality, calls/globals against retail assembly, key widths/control flow and build fidelity. It found no critical or important issue. Its source review was completed before the official candidate audit; the audit results below were collected separately by the main agent.

## What made the difference

- Explicit null/live branches close related UI selection routines: `func_004D1C00`, `func_004CEDB0`, `func_004CF950`, `func_004CDF08` and, together with a typed global table, `func_004D9408`.
- Declaring ignored callee returns `void` fixes several register-allocation differences, including `func_0049E3E8`, `func_004D8AF0`, `func_004DBC90` and `func_L01_004CFCE0`.
- Ordered volatile field reads close `func_004F23B0`; a volatile halfword read closes the previous one-byte miss in `func_01EB1A80`.
- Correct leading argument position and callee return type close `func_0046EDD8`.
- Typed global objects preserve retail field offsets in `func_004AF168` and `func_004B0EC0`.
- Direct typed accesses through byte addresses close `func_L01_00406450`; reordered independent source stores close `func_L01_005E5AD8`.
- Reconstructing callback types and correcting the byte field at +0x264 closes the 432-byte `func_L00_007223F0`. Calls, callback loads and named globals agree with retail.
- A nested success path closes `func_00483398`.

## Retained near misses

- `func_L00_00766EB8`: **BYTES 12/380**. Independent word stores remain in a different order. Volatile accesses, whole-file scheduling settings, permutations and a structured draft did not close it.
- `func_L00_0072FE40`: **BYTES 24/820**. Reconstructed callbacks, the missing leading argument, the loop and ordered final stores improve the first compilable draft from BYTES 58/820. Remaining differences concern loop argument movement, initialization scheduling and the global-context load register/branch. The larger prototype/control-flow sweeps did not close it.

The near files were compiled freshly while temporarily in their proper `nonmatching/l00_multiplayer_menu/` paths, with temporary README rows. Their patches are in `near/`, and `near.tsv` records measured results and hashes. They were never placed in `src/` or counted as exact. Restore their README rows and regenerate both versions' metadata when applying these pending patches. After applying a near patch, reproduce it with `venv/bin/python tools/try_func.py FUNCTION nonmatching/l00_multiplayer_menu/FUNCTION.c --diff`, using the documented persistent Wine-server prefix for container compilation. Existing near misses, including the old `func_004F23B0` draft and its row, are preserved for coordinated landing.

Other documented boolean inversion and branch-likely walls were left pending after bounded attempts. Broader struct/raw, ignored-return, source-width, argument-position, prototype and twin passes are recorded in the attempt table. The larger scheduling walls yielded no additional exact result.

## Landing prerequisites and restored baseline

PAL program dumps, including `baserom/pal/main.elf`, remain missing. Both versions' map/report write commands were exercised against the temporary candidates and near misses. PAL placement generation cannot validate their locations without those dumps; no PAL addresses were guessed. Reports and maps from this temporary experiment are not retained.

The baseline retains **27 relocation mismatches in 26 functions, zero unresolved**: the previously documented global-reference problems and the separately claimed level-41 0.05f versus 20.0f literal problem. Earlier claims, source files and pending patches are preserved. The known repair patches remain in earlier session notes. Source adoption still requires repairing that baseline, legal PAL dumps, regenerated US/PAL metadata and the full verification gate.

After packaging, the temporary candidate sources were moved to scratch under the landing lock, and the temporary near files were archived. Both maps, both reports and both README files were restored byte for byte. A second complete build and fresh audits reproduce the original baseline: 2,845 exact / zero byte failures, the same 27 relocation errors / zero unresolved. US/PAL map and progress checks and the legacy progress check pass. The 705 pre-existing definitions outside the old US audit lists are unchanged; every new retained candidate appears explicitly in the official exact set.

New unsuccessful claims were released; candidate and earlier owners' claims remain. AUT-42 stays in progress and its hourly autopilot remains active. No usage-limit interruption occurred during this run. Verification finished after approximately 47.2 minutes.
