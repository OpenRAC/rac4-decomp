/* Not matching yet: PAL SCES_532.85, SIZE ours 148 / disc 168. Not part of the build.
 * Retained A61 structured-sign WIP; unchanged default PAL compiler, no extra flags.
 * Direct initial sign control and unconditional NEG were recovered. Actual output
 * still selects a +/-1 bound and shares one SUB instead of native branch-owned
 * numerators. Both native reachable pre-DIV NOPs remain absent; the zero-path
 * NOP skipped by the arithmetic branch is not a recovered latency instruction.
 * FP maximum/result copies, register choices, loop and quotient/zero continuation
 * differ. Two actual families (160 B and 148 B) are nonexact; size is not acceptance.
 * Existing f32(f32*) interface and three ordered reads/cursor+4 are retained.
 * No original array extent, finite/nonzero, nonalias or FCSR guarantee is inferred.
 * No helpers, globals, relocations or allocated nontext data in the actual object.
 * Input equals actual CompiledSource; the exact input bytes follow this header.
 * No semantic, whole-link or all-carrier certificate; no historical profile transfer.
 * Reproduce: python3 tools/check_func.py --version pal func_0048BAB0 nonmatching/pal/game/func_0048BAB0.c --diff
 */
#include "common.h"

f32 func_0048BAB0(f32 *values)
{
    f32 maximum = 0.0f;
    s32 remaining = 2;

    do {
        f32 input = *values;
        f32 negative;
        f32 numerator;
        f32 ratio;

        if (input < 0.0f) {
            negative = -input;
            if (input < -1.0f) {
                numerator = -1.0f - input;
                goto quotient;
            }
        } else {
            negative = -input;
            if (1.0f < input) {
                numerator = 1.0f - input;
                goto quotient;
            }
        }
        ratio = 0.0f;
        goto update_maximum;

quotient:
        ratio = numerator / negative;
update_maximum:
        if (maximum < ratio)
            maximum = ratio;
        remaining--;
        values++;
    } while (remaining >= 0);

    return maximum;
}
