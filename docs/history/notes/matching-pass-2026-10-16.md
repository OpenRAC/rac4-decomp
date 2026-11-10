## Matching pass checkpoint (AUT-39)

The pass added exact `func_L00_00529620` (104 bytes), committed with the generated progress report. The current audit is 1,078/15,056 exact functions (1.713% of code bytes).

Closest nonexact results and what remains:

- `func_L00_0051E250`: BYTES 7/104 after two variants. The four cleanup calls and conditional callback match; the remaining output difference is the retail 0x20-byte stack frame versus the candidate's 0x10-byte frame. Staged under `nonmatching/`.
- `func_L00_0051C7E0`: BYTES 20/104 after three variants. Using an unsized global array made the global accesses and calls close; the frame size and remaining load/store scheduling differ.
- `func_L00_004F72C0`: BYTES 39/104 after one candidate. The nested calls and return path are close; register allocation and frame size differ.
- `func_L00_004F7340`: BYTES 45/104 after one candidate. It follows the two conditional calls and clears the state fields; frame size and branch layout differ.
- `func_L00_005263A8`: BYTES 21/104 after three variants. Added the second output pointer to match the helper's `$t0` argument and initialized both stack outputs. The candidate still uses a smaller frame and different stack-save layout.
- `func_L00_00537BB0`: SIZE 300/312 after two variants. The state-selection and comparison sequence matches closely; the remaining difference is mainly frame/save layout and branch arrangement.
- `func_L00_0050F548`: SIZE 188/208 after three variants; the state dispatch, indirect lookup loop, and copy still differ in register allocation and instruction scheduling.
- `func_L00_0050BD98`: SIZE 228/240 after three variants; the status tests and update logic are represented, but register allocation, branch order, and frame layout remain different.
- `func_L01_0050BC88`: SIZE 264/272 after two variants; its update branches remain differently scheduled and the saved-register arrangement differs.
- `func_L01_00462DA8`: SIZE 128/152 after a compile correction and one codegen attempt. Buffer field writes and register lifetimes remain different.
- `func_L00_0051A800`: SIZE 112/104 after two variants; helper order is correct, but the long-lived input and first call result land in opposite saved registers.
- `func_L00_0051EB68`: SIZE 100/104 after two variants; the callback and cleanup sequence is represented, with a smaller frame and a different final branch.
- `func_L00_00520D28`: SIZE 108/104 after three variants. A packed copy record generated the required `ldl`/`ldr` and `sdl`/`sdr`; register choices, instruction order, and frame size remain different.
- `func_L00_00517208`: SIZE 88/104 after three variants; output values and return behavior are represented, but the retail frame and saved status register differ.
- `func_L00_00517358`: SIZE 92/104 after three variants; pointer copies and zero extension are represented, but the return/pointer register allocation and load ordering differ.
- `func_L00_00553DC8`: SIZE 92/100 after three variants. It stages three incoming words for its helper; the remaining call-argument and return layout differs.
- `func_L00_0052F6C0`: SIZE 92/104 after two variants; callback and cleanup calls are represented, with a frame-size and tail-return difference.

Walls skipped: `func_L00_00553D58` branches to an external function label, and `func_L00_005C0FEC` reads unset `$t0`, `$v1`, and `$t1` registers.

## Follow-up checkpoint

After this note was first written, `func_L00_00535830` also matched exactly (104 bytes); both new matches this pass (`00529620`, `00535830`) are committed with the latest audit and progress report.

Follow-up attempts:

- `func_L00_0051E250` improved from BYTES 7/104 to BYTES 5/104 after adding a volatile stack slot. The best candidate still places the saved registers at different stack offsets; the nonmatching source has been updated to the 5-byte result.
- `func_L00_005415E0`: SIZE 92/104 after three variants; the state-bit conditional and helper call are represented, but the frame/register layout remains different.
- `func_L00_00537BB0`: SIZE 300/312 after three variants; max-value selection and branches remain differently scheduled.
- `func_L00_0072EC88`: SIZE 344/312 after two variants; the indirect calls and branches are represented, but it uses a larger frame and extra saved registers.
- `func_L00_00739F70`: SIZE 352/312 after three variants; the selection filtering and copy loop are represented, but register and frame layout remain different.
- `func_L00_00541648`: a 296/316-byte-size candidate was logged; the final semantics correction was not run because the wave budget was exhausted, so it is not staged as a near miss.
- `func_L00_004F72C0` improved from BYTES 39/104 to BYTES 17/104 with an explicit nonzero branch and return. The helper-call order is correct; saved-register and frame layout remain different. Its best source is now staged in `nonmatching/`.
- `func_L00_00744A90`: SIZE 348/312 on the first candidate, using the nearby menu wrapper as a model; indirect-call scheduling and stack frame differ.
- `func_L00_00745360`: SIZE 312/320 after three candidates; the repeated helper checks and ranking comparisons are represented, but branch layout, globals, register allocation, and frame differ.
- `func_L00_0052D158`: SIZE 300/316 after three candidates; normalization, nanosecond carry, and overflow logic are represented, but helper-call timing and arithmetic/register scheduling differ.
- `func_L00_00744A90`: a second candidate using explicit menu structure fields was SIZE 344/312, still differing in indirect-call scheduling and frame layout.
- `func_L00_004F7340`: the saved-frame variant was BYTES 47/104, worse than the best 45/104 candidate; the frame and conditional branch arrangement remain the main differences.
- `func_L00_0070C8C0` matched exactly (104 bytes). Its 0x46-iteration loop calls `func_L00_0070C548` and forwards each result to `func_L00_0070C528`; the full build, audit, and progress check passed.
- `func_L00_005423D8`: SIZE 100/104 after two candidates. Allocation success and error paths are represented; the stack-frame layout still differs.
