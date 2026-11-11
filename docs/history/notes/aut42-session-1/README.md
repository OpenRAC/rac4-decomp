# AUT-42 session 1: verified C awaiting landing prerequisites

Historical checkpoint: see `../aut42-session-2/README.md` for subsequent audit repairs and a correction to the literal-pool finding below. Level 41 contains 20.0f at `0x00220CC4`; 0.05f is the main program's value at that address, so the source has a real literal error.


49 game-code candidates, covering 4,824 retail bytes (4,688 compiled bytes plus alignment), were reconstructed from retail/m2c and existing matched siblings on 2026-10-22. All pass `tools/try_func.py --diff`; their scratch objects pass 192 relocation checks with 0 mismatches and 0 unresolved references. No near misses are retained.

These are pending source patches, **not additions to the matching progress total**. They are kept outside `src/` because this host lacks the PAL data required by the current reporting workflow, and the baseline audit needs reconciliation. No compiler, flags, assembler transformations, audit logic, or reporting logic was changed to obtain the results.

## Patches

Each patch adds ordinary C under the repository's required `src/game/` layout. Apply and commit one related group at a time, under the landing lock, after resolving the blockers below.

| Patch | Functions | Retail bytes |
| --- | ---: | ---: |
| `initializers.patch` | 13 | 1,248 |
| `owner-values.patch` | 10 | 880 |
| `interfaces.patch` | 21 | 2,144 |
| `func_00499298.patch` | 1 | 136 |
| `func_004B6CA8.patch` | 1 | 88 |
| `func_004D2B40.patch` | 1 | 64 |
| `func_004D8AF0.patch` | 1 | 136 |
| `func_0054A608.patch` | 1 | 128 |

What made the difference: reuse of matched control-flow shapes, then correction of each function's registration ID, structure field offset, initialization-loop bound, and validation bound. The first initializer drafts inherited three callback addresses from the sibling: masked byte checks accepted them, but manual review and relocation checks rejected them. All 39 callback references were corrected to the retail callbacks before preservation here.

## Required data

The US ISO already on this host was linked as `baserom/SCUS_974.65.iso`, then `tools/levels.py dump` and `tools/levels.py check` produced/checked all 49 US programs with 0 differences. These files are ignored and are not in this checkpoint.

`tools/match_map.py --version pal --write` fails opening `baserom/pal/main.elf`. No PAL ISO or program dump was found in the workspace or home directory. Supply the legally obtained `SCES_532.85.iso` and run `tools/levels.py --version pal dump`, or provide the corresponding extracted programs. The missing data was requested during the session. Reports must not be fabricated or marked as verified using US data.

## Full-build verification

With all 49 candidate files temporarily in `src/`, the full build completed (3,578 files). The official audit reported 2,891 exact, the same 3 pre-existing extent failures, and 705 functions outside the old lists. All 49 candidates occur in its exact set. The official relocation audit reported 7,653 checks, the same 80 baseline mismatches, and the same 3 baseline unresolved entries; none belongs to a candidate. US `tools/match_map.py --write` also succeeded and marked all candidates as matches (3,599 total match rows). Its generated map is retained only in ignored scratch storage, pending the PAL map and adoption. After packaging, the candidate source files and their objects were moved out of the build inputs so the checkout retains its original source/report relationship.

## Baseline audit findings

The first fresh full build, including the 13 new initializers, completed successfully. Its official audits reported 2,855 exact, 3 not exact, 705 functions outside the old US lists; and 80 relocation mismatches in 43 functions, with 3 unresolved relocations. Every reported failure belongs to source present at starting commit `ec193d8`; the new initializers had no failures.

Investigation distinguishes catalogue/audit gaps from incorrect source symbols:

- The three byte failures use outdated extents in `config/functions.tsv` / `config/overlay_functions.tsv`: `func_00161890` is 32 bytes in the new inventory (the old 160-byte extent includes a second, handwritten function); `func_00547A98` is 44 bytes rather than 36; `func_L01_004F3100` is 36 bytes rather than 28. The new inventory/catalogue and existing match-map rows include their actual extents. Direct comparisons against those extents confirm all three compiled functions equal retail.
- All 54 call relocation mismatches agree with the main-function copies recorded for that level in `config/us/functions.tsv`. The old relocation checker only recognizes relocated shared-overlay callees, not these resident-function copies. These should be handled using the version's program placements, without relaxing unrelated call checks.
- The remaining 26 mismatches are global references: 24 getters use a data symbol named after the function address instead of the retail `$gp` target; `func_L00_006AA088` reverses `D_0022339C` and `D_002233A0`. The exact correction list is in `baseline-relocations.json`. They need source corrections, not masking.
- Two unresolved calls in `func_0015BEE8` are compiler-generated `__udivdi3` calls. Both retail targets are `0x0012FEB0`; `config/libgcc.tsv` only lists source-rebuilt exact library functions and omits this helper. `src/libgcc/README.md` documents the prebuilt archive's matching helper and the still-unmatched source rebuild. Identifying a callee must not falsely count its source rebuild as matched.
- The third unresolved relocation is `R_MIPS_LITERAL` (type 8) in `func_L41_003BEE28`, targeting its `.lit4` float 0.05. The retail `$gp` address is `0x00220CC4`; its four literal bytes equal the compiled literal. The checker does not implement that relocation type.

Reconcile these baseline checks and supply PAL data before adopting the pending patches. Then run the full build, both audits, both match-map writes, both progress writes/checks, and the legacy progress check. The restored tree passes both current `tools/progress.py --check` commands (US and PAL, 3,727 map rows each). Its fresh official audits return the baseline 2,842 exact / 3 extent failures and 80 relocation mismatches / 3 unresolved. The regenerated legacy report check fails on those same three outdated-extent functions. Keep commits local; Stephan handles pushes. This session leaves the continuous schedule unchanged and the issue in progress.

The pending candidates remain claimed by `aut42s1` to prevent duplicate work. Their scratch drafts, m2c output, comparisons, and logs remain in ignored `build/try/<function>/` (the comparisons use arm `aut42`).

## Functions

| Function | Retail bytes | Matched sibling |
| --- | ---: | --- |
| `func_00499298` | 136 | `func_004A2A48` |
| `func_0049B378` | 96 | `func_004B5478` |
| `func_004A1A78` | 96 | `func_004B5478` |
| `func_004A2358` | 96 | `func_004B5478` |
| `func_004A2E48` | 96 | `func_004B5478` |
| `func_004A9C30` | 96 | `func_004B5478` |
| `func_004AFE50` | 96 | `func_004B5478` |
| `func_004B0F08` | 96 | `func_004B5478` |
| `func_004B2160` | 96 | `func_004B5478` |
| `func_004B4C90` | 96 | `func_004B5478` |
| `func_004C82C8` | 96 | `func_004B5478` |
| `func_004D4710` | 96 | `func_004B5478` |
| `func_004D9DC0` | 96 | `func_004B5478` |
| `func_004DBA98` | 96 | `func_004B5478` |
| `func_004B6CA8` | 88 | `func_004B6C00` |
| `func_004B6FD0` | 88 | `func_004B7028` |
| `func_004B70D8` | 88 | `func_004B7028` |
| `func_004B7290` | 88 | `func_004B7028` |
| `func_004B72E8` | 88 | `func_004B7028` |
| `func_004B7340` | 88 | `func_004B7028` |
| `func_004B7398` | 88 | `func_004B7028` |
| `func_004B74A0` | 88 | `func_004B7028` |
| `func_004B75B8` | 88 | `func_004B7028` |
| `func_004B7610` | 88 | `func_004B7028` |
| `func_004B7668` | 88 | `func_004B7028` |
| `func_004D2B40` | 64 | `func_004D2AC0` |
| `func_004D8AF0` | 136 | `func_004D6178` |
| `func_00508328` | 104 | `func_00508578` |
| `func_00508BC0` | 104 | `func_00508578` |
| `func_00509088` | 104 | `func_00508578` |
| `func_00509410` | 104 | `func_00508578` |
| `func_00509688` | 104 | `func_00508578` |
| `func_00509978` | 104 | `func_00508578` |
| `func_00509F80` | 104 | `func_00508578` |
| `func_005085E0` | 104 | `func_00508450` |
| `func_00508A48` | 104 | `func_00508450` |
| `func_00508C28` | 104 | `func_00508450` |
| `func_00509478` | 104 | `func_00508450` |
| `func_005096F0` | 104 | `func_00508450` |
| `func_00508DC0` | 104 | `func_0050A1F0` |
| `func_00509830` | 104 | `func_0050A1F0` |
| `func_00508EE8` | 104 | `func_0050A258` |
| `func_00509758` | 104 | `func_0050A258` |
| `func_00509898` | 104 | `func_0050A258` |
| `func_00509EC0` | 104 | `func_0050A258` |
| `func_005094E0` | 88 | `func_00509E68` |
| `func_00509F28` | 88 | `func_00509E68` |
| `func_00509D98` | 96 | `func_00509C60` |
| `func_0054A608` | 128 | `func_0054A688` |
