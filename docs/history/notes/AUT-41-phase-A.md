# AUT-41 Phase A

Timed phase: 2026-10-18 11:01:14 to 2026-10-18 12:52:14 UTC (111.0 minutes).
Agent: one Codex matching agent. No worker agents and no push.

## Results

- 23 new audited matches; 4,744 matched code bytes; 2,564 bytes/hour.
- 91 unique functions compile-tested through try_func; 25.3% became new matches.
- 104 additional draft-only rejections; 195 total attempted/drafted functions and 11.8% overall exact rate.
- The two inherited matches (L01_0045B3A0 and L01_00499070, 192 bytes) were verified and committed before the timer; they are excluded from these results.
- Two stale near-miss entries already had matched source (004A8B10 and L01_005AC6C8). Their unsuccessful candidate trials remain in the compile-tested denominator and add no matched bytes.
- Bytes are the progress report/catalogue size, including retail alignment padding, with each shared function counted once.
- Final code checkpoint: `82cdad7`. Full builds, audit_matches (0 not exact), audit_relocs (0 mismatches and 0 unresolved), and the progress report check passed for every source commit.

## What mattered

Explicit parameter lists restored arguments m2c omitted, including the fifth and sixth arguments of the UI constructor. Correct 64-bit parameter types kept literal expansion together. Unsized globals controlled split address loading. Local declaration/initialization order and separate load/counter variables reproduced register lifetimes. Correct byte stores and limited volatile accesses reproduced store order.

A non-void declaration for a discarded callee result fixed the v0/v1 load-register difference in 004C3A08. Returning a pointer from the copy helper did the same for L00_0077C4F8. Other earlier return-type near misses were not retried after their iteration cap. Promising follow-ups are func_L01_0044AA78 (BYTES 2/172) and func_L01_00468A38 (BYTES 2/292), whose preceding discarded callee results are currently declared void.

The automatic draft pass compile-tested 50 functions and found no exact match in that first pass. Many drafts failed type inference or compilation; selected ones were subsequently repaired manually. Draft-only failures are shown separately so the overall and compiler-tested exact rates are both available.

## Matched functions

| Function | Bytes |
|---|---:|
| `func_0046F738` | 112 |
| `func_00476320` | 304 |
| `func_0049E618` | 160 |
| `func_004C3A08` | 280 |
| `func_004D5E48` | 288 |
| `func_004D7488` | 288 |
| `func_004D7D40` | 416 |
| `func_004E1F90` | 168 |
| `func_0050DC80` | 152 |
| `func_L00_005D3228` | 240 |
| `func_L00_005D5B50` | 400 |
| `func_L00_00666EF8` | 136 |
| `func_L00_006703A0` | 216 |
| `func_L00_00676588` | 176 |
| `func_L00_0068C840` | 128 |
| `func_L00_0077C4F8` | 168 |
| `func_L01_0046E2C8` | 128 |
| `func_L01_004D0880` | 248 |
| `func_L01_004DA958` | 112 |
| `func_L01_00559D98` | 112 |
| `func_L41_003DF440` | 200 |
| `func_L41_0040E218` | 168 |
| `func_L41_00440D00` | 144 |

## Reviewed near misses

| Function | Best valid result | Remaining issue |
|---|---|---|
| `func_00163218` | BYTES 1/116 | Scalar alias for the first second-array load fixes the register; the remaining first-iteration increment is li rather than addiu. |
| `func_L00_006D2880` | BYTES 2/156 | Correct byte strides and local declaration order fix the body. Only the two independent lui instructions remain reversed. |
| `func_L01_004CFEC8` | BYTES 31/140 | Restored object argument to func_L00_0066CCE8. Remaining global load/store and argument scheduling differs. |
| `func_L00_006F5E28` | BYTES 56/472 | Tail branch ordering is exact after reversing the nested condition. Scan loops and end-pointer construction still differ. |
| `func_L01_00427C40` | BYTES 11/220 | Packed, 4-byte-aligned 12-byte copies reproduce the unaligned transfers. The result and fourth argument use swapped saved registers. |
| `func_L01_00443C98` | BYTES 61/152 | Callees overwrite a2/a3 before reading them; their prototypes take two arguments. Remaining store ordering and temporaries differ. |
| `func_004C57C0` | BYTES 25/332 | Restored six-argument widget constructor and five-argument setup call; corrected final field to a byte. Address-hoisting and stores still differ. |
| `func_004BB018` | BYTES 5/308 | Correct final byte store is mandatory. Original word-store draft at 4/308 is rejected. The three reset stores remain reordered; volatile stores move li as well. |
| `func_004D7998` | BYTES 37/464 | Explicit text temporaries and a format pointer improve the tail slightly. Four argument-move pairs and format address scheduling remain different. |

These candidates are stored in nonmatching, outside the build. Lower byte counts from incorrect-width or incomplete-prototype drafts were not adopted. SIZE mismatches were not retained as C.

## Other attempts and limits

`build/phaseA/attempts.csv` is attached to the issue comment with every attempted function, its verdicts, draft-only failures and stale entries. The CSV is an issue artifact; it is not committed under build/.

004C8428 reached a size-stable but substantially different 329/632-byte experiment after a scalar descriptor change; the valid array-based draft remained SIZE 616/632, so no C candidate was retained. L41_0040E010 remained SIZE 200/208 after bounding the final table read.

004EEC48 was rejected as a fragment (missing return/unset registers). 004EF430 requires fixed-gp startup/stack context and was skipped before compilation. Network code, VU operations, libgcc and libm were excluded.

No external blocker. The source checkpoint, near misses and this report are committed on speed-test-2026-10-18.
