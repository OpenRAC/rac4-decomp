This read-only review found 17 implicit-argument defects in older pending patches. These are source semantics problems even though the original objects passed byte/relocation checks: the compiler happened to leave incoming registers intact at an argument-free call. **They must be repaired and re-audited before adoption.** No earlier patch or claim was changed in this session; no corrected match is claimed for these 17 functions.

Paths are `notes/aut42-session-<session>/matches/<caller>.patch`; line numbers refer to those patches. Each finding was checked against retail register dataflow, rather than treating an m2c signature as proof.

| Session | Caller (patch line) | Callee | Required forwarding and evidence |
|---|---|---|---|
| 6 | `func_00498120` (23) | `func_00510BE8` | Add incoming `s32 arg0`; pass it. Callee multiplies a0 by 0x31F0 to select an object. |
| 6 | `func_01EA9718` (23) | `func_01EA95C0` | Pass arg0. Callee saves a0, dereferences it, and clears its first word. |
| 6 | `func_01EB32C8` (19) | `func_01EA90F0` | Pass arg0. Callee compares object +0x10 against a0. |
| 6 | `func_L00_00714A80` (31) | `func_L00_007107F0` | Pass arg0 and arg1; destination and source are both consumed. |
| 6 | `func_L01_0045C0C8` (12) | `func_L01_0045A690` | Pass arg0 as an object pointer; callee reads +0xAC. |
| 6 | `func_L01_004E4308` (29) | `func_L01_004E4358` | Pass arg0; callee reads +0xAC. |
| 6 | `func_L06_004C7320` (21) | `func_L06_004C7378` | Pass arg0; callee reads/writes object fields. |
| 8 | `func_01F035B0` (29) | `func_01EF382C` | Add incoming arg1/arg2 and pass arg0/arg1/arg2. Callee preserves all three, uses arg1 during initialization and later forwards arg2. |
| 8 | `func_L00_00709378` (13) | `func_L00_00709A50` | Pass arg0; callee bounds-checks it and indexes a table. |
| 8 | `func_L00_00763C00` (24) | `func_L00_0071B478` | Pass arg0; callee reads object +0x230. |
| 8 | `func_L00_007646A0` (13) | `func_0011AB04` | Pass arg0; callee tests alignment and reads bytes/quadwords from a0. Do not decompile the callee if library classification applies. |
| 8 | `func_L01_0064F680` (11) | `func_L01_0064F278` | Forward a0, a1, full vector a2, f12 and f13, retaining wrapper a3. ABI reconstruction required; see below. |
| 8 | `func_L04_004DD400` (10) | `func_L04_004DCF70` | Pass arg0; callee reads object +0x94. |
| 8 | `func_L41_003E2B98` (37) | `func_L41_003E2B38` | Add incoming s32 arg0 and pass it; callee compares a context byte against a0. |
| 9 | `func_0054A608` (14) | `func_0054A7E0` | Pass arg0/arg1; callee clamps a1 and reads arg0 + arg1 * 0x44 + 0xA3C. |
| 9 | `func_L00_0074A3C8` (14) | `func_L00_0071B478` | Pass arg0; same object-pointer consumption as above. |
| 9 | `func_L01_00468F58` (17) | `func_L01_004690D8` | Pass arg0; callee loads object position +0x10. |

For `func_L01_0064F680`, the callee transfers incoming a2 to vf1 at 0x0064F284 and adds its XYZ components to a position at 0x0064F2B0. A scalar s32 cannot express that vector. The callee also preserves f12/f13 at 0x0064F2A4/0x0064F2AC and uses both. The wrapper and callee need ABI-appropriate vector and floating-point parameter declarations; do not invent scalar stand-ins, pin registers or add assembly to force the result. Preserve incoming a3 for the wrapper's comparison. Record a wall if this cannot be expressed through the supported plain-C toolchain.

Every corresponding callee declaration needs explicit parameter types as part of the repair. Priority for the next session: repair these pending sources in scratch, then freshly compile, review and audit them before retaining replacement patches. Respect existing claims and the landing lock. Missing PAL dumps and baseline relocation repairs remain separate adoption prerequisites.
