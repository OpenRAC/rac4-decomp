/* Not matched: PAL SCES_532.85.
 * BYTES 14/120 (6 words differ) with stock relocation masking; one actual placement.
 * Resolved raw comparison: 16/120 bytes differ after binding D_001EE680 plus addend 0x1A8.
 * Continuation timing and resident-field address folding still differ.
 * Resident symbol ownership is supported; index range, signed product domain,
 * complete data type and original return type remain unresolved. No data is defined.
 * Reproduce: python3 tools/check_func.py --version pal func_L00_0074C440 nonmatching/pal/l00_multiplayer_menu/func_L00_0074C440.c --diff
 */
#include "common.h"

extern u8 D_001EE680[];

/* Toggle four observed bytes according to their indexed resident mask state. */
void func_L00_0074C440(void *arg0) {
    s32 *var_a3;
    s32 temp_v1;
    u32 var_a5;
    u32 continuation;
    u8 *var_a2;

    var_a5 = 0;
    var_a2 = arg0 + 0x294;
    var_a3 = arg0 + 0x264;
    do {
        temp_v1 = *var_a3;
        var_a5 += 1;
        var_a3 += 1;
        continuation = var_a5 < 4U;
        if (((~temp_v1) != 0) &&
            (*(s32 *)((s8 *)(D_001EE680 + (temp_v1 * 0x5C0)) + 0x1A8) & 0x40) &&
            ((temp_v1 != 0) || (*(u8 *)((s8 *)arg0 + 0x298) != 0))) {
            *var_a2 ^= 1;
        }
        var_a2 += 1;
    } while (continuation);
}
