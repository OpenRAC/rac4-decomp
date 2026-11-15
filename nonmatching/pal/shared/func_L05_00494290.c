/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/40 (4 words differ).
 * Function text: 40 B; native catalogue: 40 B; 3 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L05_00494290 nonmatching/pal/shared/func_L05_00494290.c --diff
 */
#include "common.h"

s32 func_L05_00494290(void *arg0)
{
    s32 result;

    result = *(u8 *)(*(u8 **)((u8 *)arg0 + 0xAC) + 0x1A8) == 0
        ? *(u8 *)((u8 *)arg0 + 0x20) == 7
        : 0;
    return result;
}
