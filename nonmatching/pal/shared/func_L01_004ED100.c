/* Not matched: PAL SCES_532.85.
 * BYTES 9/124 (5 tail words differ), raw and unmasked at all twelve placements.
 * The first 92 bytes match; this is not complete-function certification.
 * Consumed-parameter counter and typed element loop are reconstructed;
 * fallback pointer allocation and return/store scheduling still differ.
 * Initial child capture and all alias-sensitive reloads remain explicit.
 * Static descriptor entries do not prove runtime invocation or unique types.
 * Reproduce: python3 tools/check_func.py --version pal func_L01_004ED100 nonmatching/pal/shared/func_L01_004ED100.c --diff
 */
#include "common.h"

s32 func_L01_004ED100(void *arg0, s32 arg1)
{
    u8 **var_a0;
    void *temp_a0;
    void *temp_v1;
    u8 *temp_v1_2;
    u8 *temp_base;
    void *temp_v1_3;
    temp_v1 = *((void **)(((s8 *)arg0) + 0xAC));
    temp_a0 = *((void **)(((s8 *)temp_v1) + 0x2F4));
    *((s32 *)(((s8 *)temp_v1) + 0x320)) = arg1;
    if (temp_a0 != NULL) {
        arg1 = 3;
        *((u8 *)(((s8 *)temp_a0) + 0x30)) = *((u8 *)(((s8 *)arg0) + 0x30));
        *((u16 *)(((s8 *)(*((void **)(((s8 *)temp_v1) + 0x2F4)))) + 0x32)) = *((u16 *)(((s8 *)arg0) + 0x32));
        temp_base = *((u8 **)((s8 *)(*((void **)(((s8 *)temp_v1) + 0x2F4))) + 0xAC));
        var_a0 = (u8 **)(temp_base + 0xD0);
        do {
            temp_v1_2 = *var_a0;
            arg1 -= 1;
            if (temp_v1_2 != NULL) {
                *((u16 *)(temp_v1_2 + 0x32)) = *((u16 *)(((s8 *)arg0) + 0x32));
            }
            var_a0 += 1;
        } while (arg1 >= 0);
        return 1;
    }
    temp_v1_3 = *((void **)(((s8 *)temp_v1) + 0x358));
    if (temp_v1_3 == NULL) {
        return 1;
    }
    *((u16 *)(((s8 *)temp_v1_3) + 0x32)) = *((u16 *)(((s8 *)arg0) + 0x32));
    return 1;
}
