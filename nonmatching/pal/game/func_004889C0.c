/* Not matched: PAL SCES_532.85.
 * SIZE ours 144 / disc 152 at all fifteen actual placements; no relocations.
 * 115/152 bytes agree positionally, including an eight-byte size deficit;
 * this is a comparison heuristic, not semantic correctness or a match.
 * Native has two pre-divide NOPs absent from the default-profile output;
 * branch displacements and shifted tail instructions consequently differ.
 * Preserve ordered/unordered gates, operand order, and the shared return join.
 * No latency padding, profile change, or finite-input assumption is introduced.
 * Reproduce: python3 tools/check_func.py --version pal func_004889C0 nonmatching/pal/game/func_004889C0.c --diff
 */
#include "common.h"

s32 func_004889C0(f32 fparg0, f32 fparg1, f32 fparg2)
{
    s32 var_v0;

    if (fparg0 <= 0.0f) {
        var_v0 = 0;
        if (!((fparg2 <= 0.0f) && (fparg1 > 0.0f))) {
        } else {
            return 1;
        }
        return var_v0;
    }
    var_v0 = 0;
    if (fparg2 > 0.0f) {
        if (fparg1 <= 0.0f) {
            return 1;
        }
        var_v0 = 1;
        if (!(((fparg0 - fparg2) / (fparg1 - fparg2)) < 0.5f)) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
