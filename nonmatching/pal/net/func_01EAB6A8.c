/* Not matching yet on PAL: 88B/native88B; 35 full real-bound bytes
 * (12 words) differ. Not part of the build. */
/* Canonical G/D_001B23E8 binds owned PAL1B2468. Actual R26 to helper01EABAF8
 * and one HI with both LO uses are valid; no GP or allocated nontext data.
 * NULL/helper-failure paths have no state/output access. Success retains
 * LW state.f0 -> SW output0 -> fresh LW state.f8 -> SW output4.
 * Base/status/result and branch-return/NOP scheduling remain nonnative.
 * Inherited wrapper eight-slot nominal ABI/source-linkage, primary-only,
 * whole-link/all-carrier and retired/timeout UNKNOWN qualifications remain.
 * No wrapper/helper/header changes, nominal type/extent/nonalias promise,
 * historical -mno-split-addresses or ee296/G0 profile transfer is made.
 * Recheck: tools/check_func.py --version pal func_01EAB6A8
 * nonmatching/pal/net/func_01EAB6A8.c --diff
 * Relocation-masked comparisons do not certify actual binding or acceptance.
 */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC; } G;
extern G D_001B23E8;
extern s32 func_01EABAF8(void);

/* Read the canonical clock words after the update succeeds. */
s32 func_01EAB6A8(s32 *output)
{
    s32 status;

    status = 2;
    if (output != NULL) {
        status = func_01EABAF8();
        if (status != 0) {
            return 0x640;
        }
        output[0] = D_001B23E8.f0;
        output[1] = D_001B23E8.f8;
    }
    return status;
}
