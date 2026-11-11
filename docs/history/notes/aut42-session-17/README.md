This session preserves 26 pending game-code candidates, covering 2,536 compiled bytes (2,608 including catalogue padding), 25 corrections to existing wrapper interfaces, and two near misses. No functions are adopted into progress. No push or PR.

## Candidates and interface corrections

Twelve candidates were recovered from session 16's unreported scratch work; fourteen were closed this session. The full candidate list and source hashes are in `functions.tsv`. Earlier patches and claims remain intact; `supersedes` identifies replacement patches or a closed earlier near miss. Do not apply two new-file patches for the same function.

The recovered set includes the former `func_L00_00766EB8` BYTES 12/380 initializer: changing the order of independent source stores reproduces retail's scheduled stores. Byte/halfword field widths, nested lookup tables, explicit scalar and 128-bit argument declarations, and correct argument forwarding also matter in this set.

New candidates include:

- `func_004C3988`: use a word-valued selector table, an 8-byte record stride, and a typed object address. The earlier byte-valued dereference was incorrect; two global-address additions also needed the typed declaration to schedule in retail's order.
- `func_0046A320`: explicitly typed callback slot and correct globals.
- `func_00497908` and `func_0049F010`: typed tables reconstruct the 0x54-byte mask record and special 0x200-byte-stride selection.
- `func_004A1140`: explicitly retain all six incoming arguments, store the buffer callback pointer and forward the four inputs consumed by the initializer.
- `func_004A1D58` and `func_004CAF90`: preserve the common return/store block instead of splitting it into early returns.
- `func_00549CA0`: remove the redundant loop argument temporary so the compiler passes the loop counter in retail's register.
- `func_L01_00468D48`: reorder independent byte resets while preserving their addresses and widths.
- `func_L00_00779750`: forward the buffer pointer through `func_01ED5D30`, record its status and return the wrapper's Boolean result.
- `func_L00_005C0880`: save/restore the state global around text measurement, preserving the text pointer, integer bound, independent float input and returned result.

The 25 existing-source repair patches forward real input registers instead of relying on accidental register preservation. Seventeen network wrappers forward a0 into `func_01EF3CF0`; eight resident wrappers forward a0/a1 into `func_004D0038`. Their 700 compiled bytes already count as matched and add no progress.

## Review

Independent read-only review examined all 26 candidates and 25 repairs against retail bodies, callees and relevant callers. It found three important interface issues: the omitted input to `func_01ED5D30`, pointer arguments declared as integers in `func_004A1140`, and a text pointer declared as an integer in `func_L00_005C0880`. All three were corrected and recompiled before the full candidate build. A duplicate lookup declaration was also removed. No remaining critical or important finding was reported. `review.json` records the corrections and final source hashes.

Review covered incoming arguments, returns, float/vector ABI, field widths, pointer strides, globals and call targets. It does not constitute an exhaustive proof of indirect callback contracts or PAL behavior. In particular, a live v0 after a final call alone does not establish a return contract.

## Follow-up review

While the full build ran, a bounded read-only review checked 20 additional small baseline wrappers outside the 25 repairs. All 20 omit inputs consumed by their callees. Two also have independently confirmed missing return contracts: `func_01EC9A08` must return a pointer consumed by `func_01ECE588`, and `func_00484598` must return the float consumed by `func_004845B8`. The primary agent rechecked both caller/callee paths. `next-session-review.tsv` records the evidence and existing claim owners. No repair code, compilation, claim changes or extra matched bytes are claimed for this table. Complete payload/callback types in `func_004F1BF0` and the core target's library/game provenance require investigation before changes.

## Near misses and attempts

`func_004BEF80` and `func_004BEFD0` are **BYTES 1/76 each** (80 retail bytes including padding). A packed byte-sized bit field fixes the access offset; GCC still emits logical right shift where retail uses arithmetic right shift. Both expressions act on a nonnegative byte. Neither is placed in `src/` or counted as exact. Their patches and the corresponding README rows are separate from the exact candidates.

The session screened or recompiled 631 distinct targets. It drafted 580 targets, compiled 1,902 distinct source variants across 398 targets, and selected 26 pending candidates plus 25 existing-source repairs. Many rejected catalogue entries are fragments or unsupported drafts; screening them does not make them decompiled functions. `attempts.tsv` distinguishes failed drafts, compile failures, size differences, scratch byte verdicts and retained work. The packed unaligned-copy experiment `func_01EA0BA0` stayed at BYTES 7/48; no improvement worth retaining was found. Unsupported vector code, stale claims and other owners' work were left alone.

## Verification and landing prerequisites

Fresh full candidate build: **2,871 exact / zero byte failures**. All 26 pending candidates and all 25 existing-source repairs appear in the official exact set. A separate check of their 107 relocations reports **zero mismatches and zero unresolved references**. The full relocation failure list is identical to the original baseline: **27 mismatches in 26 functions / zero unresolved**. Actual source and full-build object hashes for all 51 selected functions are in `verification.json`.

US map/report generation and checks pass with the temporary sources and near files. PAL map generation fails on missing `baserom/pal/main.elf`; PAL report writing exits zero using the old map, while both PAL coverage checks fail for the new sources and near files. Those generated maps/reports/README tables are discarded rather than treated as PAL verification. The legacy check passes after regeneration.

After restoring the baseline and fully rebuilding it: **2,845 exact / zero byte failures**, the same **27 relocation mismatches / zero unresolved**. US/PAL map and progress checks and the legacy check all pass. Both maps, both reports and both README files are restored byte for byte. All **54 pending patches** pass combined reverse and forward application checks; archived source hashes agree with their manifests. The two near-file scratch comparisons are reconfirmed. No permanent source or progress files are changed by this notes checkpoint.

Verification completed after approximately **46.7 wall-clock minutes**, including three full builds. No usage-limit interruption occurred. 575 unsuccessful claims created this session were released; earlier claims and the retained candidates' claims are preserved.

PAL program dumps, including `baserom/pal/main.elf`, remain missing. The baseline relocation errors include the separately claimed level-41 literal discrepancy, which is untouched. The missing PAL evidence and baseline errors prevent adoption. Individual patches remain pending for coordinated landing; source, near files, maps, reports and README tables are restored after temporary verification.

Each source patch contains reconstructed C only; no retail bytes, assembly, object files, toolchain material or game assets are committed. Prior claims remain attached to their work; unsuccessful claims created during this session are released at hand-off. AUT-42 remains in progress and the hourly autopilot remains active.
