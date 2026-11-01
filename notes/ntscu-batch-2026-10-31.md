# Bounded NTSC-U matching batch, 2026-10-31

Target: Deadlocked SCUS_974.65 only. Starting revision:
`749612988ee65ce999b7c8959012b1fc2c5b6641`. Fetch confirmed clean main equal
to origin/main. Open PRs #50, #51, #52 and #53 were inspected, including
actual diffs; none was draft at inspection. Source, maps, near misses,
claims and prior logs were checked before claiming these four functions.
Each had zero prior attempts. Main-image US normalized-code comparisons
found no other equivalent for any of them. PAL's committed inventory has
the same four core addresses and sizes; its retail bytes are absent, so
PAL byte equivalence was not established.

## Completed result

| Function | Bytes | Counted runs / cap | Compiler / file options |
| --- | ---: | ---: | --- |
| `func_0014ADD8` | 56 | 3 / 6 | Existing default SN profile |
| `func_0014C368` | 68 | 3 / 6 | SN, `-Wa,-G0` |
| `func_0014D010` | 68 | 5 / 6 | Original EE-GCC 2.9-ee-991111-01, `-O2 -G0 -Wa,-G0` |
| `func_0014DE80` | 84 | 2 / 6 | SN, `-Wa,-G0` |

All four are integrated in their own `src/core/<address>.c` files: four
functions / 276 bytes added, with no other function attempted. Thirteen
launcher runs were counted, including two initial Git Bash sandbox startup
failures and the isolated profile's first filesystem failure. Four further
rebuilds verified unchanged accepted candidates from integrated source;
these were verification, not additional candidate searches. Logs and all
candidates remain in ignored `build/try/<function>/` directories.

Each source was reviewed independently, written under the landing lock,
then rebuilt through the existing local matching launcher. ADD8, D010 and
DE80 equal all their retail bytes without masking and have no relocation
fields, calls or globals. C368 equals retail with only its single call
relocation masked; its actual target resolves correctly to `func_00136378`.
Independent and targeted relocation checks have zero new mismatches and
zero unresolved targets. Matched claims remain held; no landing lock remains.

ADD8 uses an unsigned wrapping counter and a signed initial test, avoiding
signed-overflow tricks. DE80 preserves the signed byte and s16 checks and
ordered float comparison. D010 preserves the scaled reciprocal, conversion
and clamp. Its normal float-to-integer cast has a finite representable input
domain; the byte match is not a general abstract-C claim for NaN, infinity
or unrepresentable values. Its observed caller reads the float from a table;
no live input-domain validation was performed.

## Resolved build causes

The initial early-stop diagnoses for C368 and DE80 were incomplete. Their
`li.s` constants were becoming GNU assembler literal-pool loads. The SN
build driver now forwards explicit standard `-Wa,...` file options to both
assembler passes, unchanged and in order. The new files opt into `-Wa,-G0`.
No existing source used `-Wa` options; default and existing `@ee29` invocations
remain unchanged. The small-data/nop passes retain their fixed assumptions,
so this evidence does not qualify that option for arbitrary files with globals.

D010 still lacked two nops with the installed profiles, including a direct
probe of the installed SN assembler. The owner approved one isolated extra
compiler-profile investigation. A hash-pinned public original
`2.9-ee-991111-01` compiler emits the required padding itself. Its new
`@ee29-01` whole-file route performs no compiler-output rewriting or SN
fixups. It uses private Linux runtime libraries and headless WSL; both
installed toolchains and system libraries are unchanged. Old 32-bit stat()
cannot represent Windows-mount inode numbers, so byte-identical source and
project include files are staged on native WSL /tmp; emitted assembly is
copied back unchanged. This transport is qualified for this self-contained
unit, which uses no path-dependent macros or source-relative includes.
Archive provenance, hashes, runtime requirements and transport limits are
in `docs/TOOLCHAIN.md` and `tools/ee29_01.py`. No SDK headers, samples or source
were used or extracted. No compiler or runtime binaries are committed.

Ten compiler-route tests and four isolated-profile tests pass. A separate
Terra High review found no actionable issues in either the opt-in forwarding
change or the isolated route for this scope. No game was launched.

## Preserved baseline and report boundaries

The legacy byte audit went from 3,498 to 3,502 exact functions, adding only
these four. The same three pre-existing non-exact functions remain:
`func_00161890`, `func_00547A98` and `func_L01_004F3100`. The same 761 functions
remain outside that audit's old lists. The full relocation audit retains
identical records for 80 discrepancies and three unresolved targets; this
is not a clean whole-tree qualification.

Full US map regeneration on the unchanged baseline changed 59 unrelated
rows: 51 library rows and eight existing near-miss mappings. Raw before and
after maps are preserved. Only these four new rows from the official map
generator were adopted by the batch's deterministic selection script;
every pre-batch row and its order were retained. US progress and the README
table were regenerated: 4,155 / 18,085 functions, 322,540 / 5,782,424 bytes.
US map coverage and progress guards and diff whitespace checks pass.

PAL files remain unchanged in this NTSC-U-only batch. Its static coverage
check reports the four new US source rows missing; absent PAL retail inputs
prevent verifying their PAL mapping. No passing PAL guard or PAL match is
claimed. Detailed local receipts: `build/batches/codex-20261031-ntscu-01/`.

The first local commit remains intact. Completion work is a separate local
commit; no squash, push, PR, publication or game launch was performed.
