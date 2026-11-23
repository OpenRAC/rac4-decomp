/* Not matching yet: PAL WIP; main .text 0x00454328, 72B. Not part of the build. */
/*
 * All useful explored ordinary source models remain20Bormore larger. h01 keeps sumf12 and boundf1,
 * branchesBC1FL with firstSUB in likelydelay, loads lowerbound only on lower-test arm and returns
 * through MOV.S. Native computes sumf0, loads both immediate bounds before firstbranch, uses
 * upperBC1T/lowerC.LT in its ordinarydelay, then shared sequentialcorrection/finalNOP. Capturing
 * predicateBoolean creates integer material
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 589cc5760d054e92049224d3b6ff3188e90a24b6e0b8780c6b78b5bff7e83166
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00454328 nonmatching/pal/game/func_00454328.c --diff
 */
#include "common.h"

/* Apply one ordered angular correction to the rounded sum. */
f32 func_00454328(f32 a, f32 b) {
    f32 sum = a + b;
    if (sum < 3.1415927f) {
        if (sum < -3.1415927f) {
            sum = sum + 3.1415927f;
            sum = sum + 3.1415927f;
        }
    } else {
        sum = sum - 3.1415927f;
        sum = sum - 3.1415927f;
    }
    return sum;
}
