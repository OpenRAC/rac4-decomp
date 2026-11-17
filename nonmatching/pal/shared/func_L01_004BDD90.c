/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 10/40 (4 words differ).
 * Function text: 40 B; native catalogue: 40 B; 6 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004BDD90 nonmatching/pal/shared/func_L01_004BDD90.c --diff
 */
#include "common.h"

/* Select zero when the linked byte disables the object predicate. */
s32 func_L01_004BDD90(void *object)
{
    u32 disabled = ((u8 *)*(void **)((u8 *)object + 0xAC))[0x258];
    return disabled ? 0 : ((u8 *)object)[0x20] == 9;
}
