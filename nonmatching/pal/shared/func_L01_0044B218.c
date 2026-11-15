/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: MATCH (relocation-masked text only).
 * Function text: 140 B; native catalogue: 140 B; 3 placement(s).
 * Masked text equality only; actual symbol bindings, ownership and semantics remain unresolved.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_0044B218 nonmatching/pal/shared/func_L01_0044B218.c --diff
 */
#include "common.h"
extern u8 *D_003660F8[];
extern void func_00474368(void *, s32, s32);

/* Find a linked player state that requires changing the object's state to five. */
s32 func_L01_0044B218(u8 *object)
{
    u8 *player;
    s32 i;

    if (object[0x20] != 1) {
        return 1;
    }
    for (i = 0, player = D_003660F8[0]; i < 10; player = D_003660F8[++i]) {
        if (player != 0 && *(u8 **)(player + 0x2EC) == object &&
            *(s32 *)(player + 0x2F0) >= 3) {
            func_00474368(object, 5, -1);
            return 1;
        }
    }
    return 0;
}
