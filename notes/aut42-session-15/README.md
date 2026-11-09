This session preserves 52 pending game-code candidates, covering 4,480 compiled bytes (4,560 including catalogue padding): 45 recovered from the interrupted session 14 and seven newly closed here. It also preserves 27 corrections to existing source interfaces and one near miss. No functions are adopted into progress. No push or PR.

## Recovered candidates and interface repairs

Forty-four recovered candidates repair earlier pending patches; the remaining recovered candidate, `func_004D0038`, closes the session-13 BYTES 7/232 near miss with compound byte remainder and a correctly sized object table. The replacement-patch provenance is recorded in `functions.tsv`. Original patches and claims remain intact; do not apply both versions of the same new-file patch.

The repairs explicitly forward inputs consumed by retail callees and preserve returned results consumed by retail callers. `func_L01_0064F680` now forwards its full 128-bit vector in a2, integer a3 and floats f12/f13, then preserves and returns the full 128-bit result while restoring the global. Independent review confirmed this against both caller and callee instructions.

The 27 existing-source correction patches include nine recovered from session 14 and 18 additional wrappers in the `00496B68`–`00496FE0` group. The new wrappers forward between one and six scalar arguments instead of relying on accidental register preservation. Review found two further return omissions in `func_00496D20` and `func_00496D40`; both now explicitly return their callees' Boolean results. `func_00547A40` forwards the former result unchanged, illustrating why merely scanning for consumers within one caller misses return propagation. These corrections do not add functions or bytes to progress.

## Seven new candidates

- `func_004B76C0` (140 bytes): corrected context and byte-based table addressing reconstruct the modulo-three menu update and subsequent calls.
- `func_00505B20` (68 bytes): a typed two-level context selection followed by the selector load reproduces retail's pointer and branch shape. Ordinary fields suffice; the tested volatile alternatives were rejected.
- `func_L01_00633070` (56 bytes): a correctly typed global byte store and explicit callee declaration reproduce the conditional flag update.
- `func_0054AA58` (72 bytes): preserve both calls to the record lookup and load the two fields in retail's order.
- `func_0048AF98` (96 bytes): correct packed-handle argument and pointer-return declarations; unsigned left shift followed by signed right shift expresses retail's sign extension without signed-left-shift overflow.
- `func_0048A430` (88 bytes): preserve the unused first integer argument and independent f12/f13 inputs. Reordering independent source stores gives retail's float-register allocation with no extra flags or volatile qualifiers.
- `func_L00_00707E30` (120 bytes): explicit procedure and setter prototypes, correct globals and menu branch conditions. The `005C4AC0` alias was checked directly in the overlay ELF and identified as the resident `func_004593D8` copy; it consumes exactly three scalar inputs and stores a packed word.

## Retained near miss

`func_L00_00518878`: **BYTES 4/52** (56 bytes with retail padding). The draft uses a 16-byte frame with ra at +0x08; retail reserves 32 bytes and places ra at +0x10. The body, call and store agree. Whole-file register-save settings did not reproduce both the slot placement and the scalar sd/ld operations. It is tested in its proper `nonmatching/l00_multiplayer_menu/` path and is never placed in `src/` or counted as exact.

## Attempts and review

Drafted 444 fresh targets and attempted compilation of 1,954 context variants. There are 518 distinct targets including recovered candidates and existing-source corrections; `attempts.tsv` includes draft failures, rejected SIZE results and unsuccessful variants as attempts, never matches. Callback declaration/syntax repairs yielded no additional matches. Assertion-wrapper scheduling, callback descriptor size, global byte-address forms and the older helper near miss were investigated without retaining an improvement; prior artifacts remain intact.

Independent read-only review covered all recovered candidates, the 27 existing corrections and all seven new candidates. The two Boolean return omissions were corrected and freshly compiled. Final review reports no remaining important findings. Calls/globals, parameter positions, float/vector ABI, pointer scaling, widths and returns were checked against retail. Automated scans and the byte audit are not exhaustive semantic proofs. No PAL runtime verification is claimed.

## Verification and landing prerequisites

Fresh full candidate build: **2,897 exact / zero byte failures**. All 52 pending candidates and all 27 existing corrections appear explicitly in the official exact set. Every selected function has zero candidate relocation mismatches and zero unresolved references. The full relocation failure list is identical to the original baseline: **27 mismatches in 26 functions / zero unresolved**. Source and object hashes for all 79 selected functions are recorded; the 27 corrections cover **784 already-matched bytes**, not new progress.

US map/report generation and checks pass with the temporary sources and near file. PAL map generation fails on missing `baserom/pal/main.elf`. PAL report writing itself exits zero using the old map; both PAL coverage checks fail for the 52 pending source files and one near file. Those generated reports are discarded rather than counted as PAL verification.

The restored baseline is fully rebuilt again: **2,845 exact / zero byte failures**, the same **27 relocation mismatches / zero unresolved**. US and PAL map/progress checks and the legacy check all pass on that restored baseline. Both maps, both reports and both README files are restored byte for byte. All **80 pending patches** pass `git apply --check`; the 52 new-file source hashes and near-source hash agree with their TSV records. The near patch includes its README row. No permanent source or progress files are changed by this notes checkpoint.

PAL program dumps, including `baserom/pal/main.elf`, remain missing. The baseline has the documented 27 relocation mismatches in 26 functions, including the separately claimed level-41 literal error. Neither baseline failures nor missing PAL verification are silently treated as candidate success. Sources, near files, maps, both reports and README tables are restored after temporary verification; source patches remain pending for coordinated landing.

`functions.tsv`, `corrections.tsv` and `near.tsv` record paths, extents, verdicts, hashes and supersession data. `matches/` contains new-file candidate patches; `corrections/` contains ordinary modification patches against the original baseline; `near/` contains the separate pending near file. Patches contain reconstructed C only. No retail assets, assembly, object files or toolchain material are committed. Existing owners' claims remain attached to their work; unsuccessful claims created in this session are released at hand-off.

AUT-42 remains in progress; the hourly autopilot remains active. No provider-limit bypass or scheduler changes were made.

Verification completed after approximately **42.4 wall-clock minutes**, including three full builds. No usage-limit interruption occurred in this run.
