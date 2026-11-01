# Five-function NTSC-U batch, 2026-10-31

Starting revision: `1d647ecb`, on `codex/deadlocked-ntscu-batch-20261031`.
A safe fetch found origin/main at `fe6ec0d2`; this branch was three commits
ahead and 69 behind. No merge or rebase was performed. The Luna Medium
scout checked source, claims, attempts, US/PAL inventories and maps, and
all open/draft PRs. The only open PR was #54, whose actual PAL source
changes were inspected. No overlapping work was found. Full US code
comparisons found no exact duplicate source places locally or upstream;
PAL retail bytes are unavailable, so no PAL byte-equivalence claim is made.

Five functions were claimed as `codex-20261031-five-03`. Two Terra Medium
workers used separate function scratch directories. A bounded Terra High
escalation investigated the getters' return allocation after Medium attempts
stalled; it matched the halfword getter using ordinary early returns and
whole-file `-Os`. No worker spawned children.

| Function | Behavior | Exact bytes | Candidate runs | Whole-file flags |
|---|---|---:|---:|---|
| `func_01EA88A0` | ASCII decimal-digit predicate | 36 | 3 | default |
| `func_01E9B268` | Unaligned sixteen-byte copy to destination +0x34 | 40 | 5 | `-fno-schedule-insns` |
| `func_01EB72D8` | Halfword output from object +0x1CC; clear output before null-object failure | 36 | 6 | `-Os` |

Primary review compared each complete function with retail without masking
or alignment padding, checked its memory/control-flow semantics, and audited
targets. None has calls, globals or relocations. Integration took the
landing lock. Every integrated source was then rebuilt through the existing
local matching launcher and verified again. The copy retains both loads
before its stores; the halfword getter retains the output-zeroing side effect
on its null-object failure path.

The other two functions remain outside `src/`:

| Function | Best preserved candidate | Difference | Used / approved runs |
|---|---|---|---:|
| `func_01EA71C8` | `build/try/func_01EA71C8/p0.c` | BYTES 7/36; status/load registers and return move | 17 / 18 |
| `func_01EA4EE8` | `build/try/func_01EA4EE8/p0.c` | BYTES 8/32; status/global-address registers and return move | 17 / 18 |

The user raised the original six-run ceiling to twelve for all five,
then eighteen for these two remaining functions. Their final runs are held
for a justified test. Rewording, size optimization, scheduler options and
the available EE 2.9 routes have not resolved the allocation. Function-free
diagnostics found the installed SN 1.14 backend incompatible with the
wrapper's default stack option and the alternate driver's preprocessing
invocation. No target run was hidden in those diagnostics. A public
EE-GCC 3.2-040921 bundle is an availability lead only: neither its exact
binary provenance nor a connection to Deadlocked's NET code was established.
An explicit exception to the original no-toolchain-changes constraint was
requested before evaluating it. No new profile has been downloaded or added.
No source wall or impossibility is claimed for either near miss.

The legacy audit adds exactly the three verified functions, from 3,503 to
3,506 exact. Its original three non-exact functions and 761 unlisted
functions remain. The like-for-like relocation audit retains byte-identical
records: 80 existing mismatches and three unresolved targets. An additional
audit including library objects retained those 80 mismatches and reported
55 extra unresolved library targets; it has a different scope from the
baseline. No clean whole-tree audit is claimed.

The official US map generator was run. Its 59 pre-existing unrelated row
differences reproduced the pre-batch regeneration baseline; only the three
new generated rows were adopted, preserving every old row and its order.
US progress and the README table were regenerated: 4,159 functions and
322,760 matched bytes. US map/progress and whitespace checks pass. PAL
files are unchanged; its coverage guard lacks the five prior local source
rows plus these three. PAL inputs are absent and outside this NTSC-U batch.

Candidates, attempt logs, ownership, baseline snapshots, PR exclusions,
independent proofs and diagnostics remain in ignored `build/try/` and
`build/batches/codex-20261031-five-03/`. All five claims are retained while
the two remaining functions are pending. No existing work, toolchain or
baseline discrepancy was changed. No squash, push, PR or game launch was
performed.

## Continued allocator investigation

The user then requested continued work and questioned the attempt caps.
The numerical ceilings were removed for the two remaining functions;
the old budget files and every logged attempt were retained. Work stayed
on these two functions. No additional source match has been claimed.

EE-GCC 3.2-ee-040921 was evaluated in a separate ignored profile. Its
original C compiler and driver run with copies of the existing private
32-bit Linux runtime through headless WSL. Inputs, include files and its
executable wrapper use native temporary storage for the old filesystem API.
Compiler output is transported unchanged to the existing SN assembler.
The helper validates the required binary/runtime hashes before execution.
Neither installed toolchain was changed: all 136 files still have their
recorded SHA-256 values. Whole-file markers also permit evaluations using
the already installed SN 1.14 and SN 2.74 drivers, omitting their unsupported
stack option and pinning the corresponding backend/preprocessor paths.
The default SN 1.36 and existing EE 2.9 routes retain their behavior.

The 040921 compiler fixes the status register and common return layout.
The best getter is now **BYTES 2/36**, and the best global helper is
**BYTES 4/32**: each uses `$t7` for the data/address temporary where retail
uses `$v1`. These figures count differing bytes, not matching bytes.
The primary independently checked the global helper's HI16/LO16 pair:
one target check, no mismatch or unresolved target, resolving the stored
address to `0x001AFD28` in `core.bss`. This does not make it a byte match.
The packet's claim that this global was undeclared was stale:
`src/net/01EA3778.c` already declares a signed-word array alias at that
address and passes its address to a 24-byte copy.

RTL diagnostics locate the temporary's selection in local allocation,
before global allocation coalesces the result into `$v0`. Verbose options,
disabling pre-allocation scheduling and disabling the live-range pass did
not resolve it. Typed/ordinary-register locals, structure assignment and
the older installed SN compilers also did not match. A standard `memmove`
expression retained a call and is unsuitable. A real inline store helper
was inlined but retained the older SN register mismatch. No artificial
operations, hard register bindings, assembly or volatile ordering were used.
Current logged totals are 29 getter attempts and 22 global-helper attempts.

The Luna scout inspected the unmodified 040921 compiler binary's symbol
data: its initialized allocation table starts `15,14,...,0`, consistent
with local selection of `$t7`. The closest earlier 030926 build has the
same allocation and fixed/call-used tables, so it was not executed or used
for target compiles. The older 030210-beta2 build instead has PE32/Cygwin
binaries and no visible allocation-order table. Public GCC 3.2.3 source
conditionally declares that table under `REG_ALLOC_ORDER`, whose undefined
case uses ascending order. This supports a beta experiment, but does not
prove the vendor binary's behavior or exact source/patch provenance.

Only compiler binaries, bundled runtime DLLs and the original compiler
control specs were extracted from the beta archive. Its non-system DLL
import dependencies are all present. No SDK headers, samples or source
were read or extracted. The attempted native version probe was rejected
by automatic approval review before the command ran: executing downloaded
PE32 binaries and DLLs on Windows was judged a risk not clearly authorized
by the general continuation. Specific permission was requested for the
version/ABI probes and two target functions. No indirect execution or
runtime workaround was attempted; native execution remains pending.

Fourteen fake-driver route tests and six isolated-helper tests pass. A
rebuild of the committed default-route digit predicate still matches, and
all three committed integrated objects retain their full unmasked proofs.
No additional source, map or progress rows changed in this continuation;
the recorded broad-audit discrepancies and PAL boundary remain as above.
All new artifacts and the exact rejected action are checkpointed under the
ignored batch directory. Claims remain held for the pending functions.

## Word getter verified; final address helper pending

The user authorized continuing the isolated beta checks, then explicitly
approved the separate 030926 profile when automatic review distinguished
the two executable profiles. Both passed version/scalar ABI checks using
their original pinned inputs. The beta reproduces the older shared-status
allocation; 030926 reproduces the newer address-renaming behavior. Neither
profile supplied a new match. Their opt-in routes, original specs and
private runtime handling are documented in `docs/TOOLCHAIN.md`.

`func_01EA71C8` **matches all 36 bytes** using its original shared-status C
and whole-file `@ee32-040921 -O2 -G0 -frename-registers`. It used 31 logged
attempts. Primary review found no calls, globals or relocations, compared
the complete code without masking or padding, integrated under the landing
lock, rebuilt the actual source, and verified the new integrated object.
The source correctly avoids all accesses on either null-pointer failure.

Only its official generated US map row was adopted, preserving every old
row and order and the previously recorded regeneration differences. US
progress now records 4,160 functions and 322,796 matched bytes. US coverage
passes. The legacy audit has 3,507 exact functions with the same three
non-exact and 761 unlisted functions. The like-for-like relocation records
remain identical to the baseline (80 mismatches, three unresolved). PAL
files remain untouched; its coverage guard now lacks nine local US rows.

The remaining `func_01EA4EE8` has 47 logged attempts and remains outside
`src/`. Its nearest valid candidate still differs in two bytes: address-high
register `a1` versus retail `v1`, with the completed address in `v1`.
The captured renamer dump processes the low-address chain first. The public
GPL GCC 3.2 reference then explains the observed high-chain exclusion: its
last instruction writes the newly assigned `v1`, and the conservative overlap
check excludes that register. Exact source identity for the vendor binary
is unproven, so this is a reference-supported explanation, not proof of
its implementation. No output or compiler binary was patched.

Both installed original SN assemblers were checked on a small non-game
address-macro probe, including ordinary optimization options. They keep the
two macro instructions adjacent; there is no evidence supporting an
invented scheduling fixup. An attempted full GCC-output assembly with the
older original assembler crashed and produced a zero-byte object; it is
not a usable match proof. The decoded compiler option table provides no
local-allocation disable switch. No speculative aggregate-return interface,
fixed-register flags, volatile ordering or artificial arithmetic was used.

Two interrupted beta launcher results were independently recovered and
recorded exactly once in `runs.log`; the artifacts and accounting notes
are retained. Later worker approval-context failures did not run candidates;
the primary supplied the already recorded authorization for the same checks
and used the normal launcher. No rejected action was run indirectly.

Sixteen route tests and eight profile tests pass. An initial rerun of the
profile tests failed because the sandbox denied its temporary directory;
the unchanged tests passed with the normal permitted execution context.
The newly integrated getter still rebuilds exact after shared transport
changes. The remaining investigation is original-compiler build metadata,
with no arbitrary numerical attempt ceiling. The user's subsequent sequence
is recorded: finish this final match, commit and squash the local matching
work, then refresh origin/PRs/claims with Luna and claim five more functions.
That squash and new selection have not happened while the last match is
still pending. No push, PR or game launch was performed.

## Five-function batch complete

`func_01EA4EE8` matched on logged attempt 51 with the actual original
EE-GCC `2.96-ee-001003-1`, `-O2 -G0`, and canonical scalar early-return C.
The installed directory bearing that version name had instead contained
SN v1.07: the scout established this by compiler/preprocessor banners and
hash comparison with the public v1.07 package. Testing that already
installed v1.07 did not match. The user then explicitly approved the
distinct Linux EE 2.96 compiler, whose pinned isolated profile passed the
scalar ABI probe. Its shared-status candidate did not match; its ordinary
early-return form did. No output fixup, register binding, artificial
operation, changed ABI or compiler-binary edit was needed.

Primary review verified all 32 bytes' opcode/register/constant fields,
the null-output return of `0x17`, the successful pointer store and zero
return, and the lack of calls or a stack frame. Its HI16/LO16 pair resolves
to the correct `D_1AFD28` address, `0x001AFD28` in `core.bss`. Applying only
standard relocation fields to an in-memory proof copy yields all retail
bytes exactly. The compiled object itself was never patched. Source was
integrated under the landing lock, rebuilt through the normal launcher,
and independently checked again. The new object replaced no existing one.

All five selected functions now match, totaling **180 retail bytes**.
Only the five new official generated US map rows were adopted over the
batch, retaining every earlier row and order and the 59 known unrelated
regeneration differences. US coverage/progress passes: **4,161 functions,
322,828 matched bytes**. The legacy audit adds exactly these five over
the fresh batch baseline, reaching 3,508 exact with the original three
non-exact functions and 761 unlisted functions. Relocation discrepancy
records remain identical: 80 mismatches and three unresolved targets.
PAL files remain unchanged; its coverage guard lacks ten local US rows.

The complete local matching work now contains ten independently verified
functions and **564 retail bytes** since `74961298`. A targeted pre-squash
review rechecked all ten current objects, their alignment boundaries and
their two relocated targets (one call and one global address). All 136
installed toolchain files still have their original recorded hashes.
Sixteen route tests and eight profile tests pass, including the real EE
2.96 and already installed SN v1.07 selection paths and profile guards.

The user authorized committing and squashing this local work, followed
by a fresh Luna origin/local/PR/claim probe and five new function claims.
The completed-function claims are retained. The batch's preserved
artifacts include every candidate and failed attempt, final proofs,
compiler-identity evidence and the audit snapshots. No push, PR or game
launch is authorized or performed.
