/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/40 (4 words differ).
 * Function text: 40 B; native catalogue: 40 B; 7 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_003D7D00 nonmatching/pal/shared/func_L01_003D7D00.c --diff
 */
#include "common.h"

/* Reject the nested status before checking the object state. */
s32 func_L01_003D7D00(void *arg0)
{
    if (*(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0xAC) + 0x460) != 0)
        return 0;
    return *(u8 *)((s8 *)arg0 + 0x20) == 0xf;
}
