/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Packs the dot-separated decimal groups of the string at arg0 into one 32-bit value; NULL gives 0. */
u32 func_01EA9140(s8 *arg0) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s8 *var_a0;
    s8 var_v0;
    u32 var_a2;

    var_a2 = 0;
    var_a1 = 0;
    if (arg0 != NULL) {
        var_v0 = *arg0;
        var_a0 = arg0 + 1;
        if (var_v0 != 0) {
            do {
                temp_v1 = var_v0 - 0x30;
                if (var_v0 == 0x2E) {
                    temp_v1_2 = var_a1 << 0x18;
                    var_a2 = (var_a2 >> 8) + temp_v1_2;
                    var_a1 = 0;
                } else if ((u32)(temp_v1 & 0xFF) < 0xA) {
                    var_a1 = var_a1 * 2;
                    var_a1 = var_a1 + (var_a1 << 2);
                    var_a1 = var_a1 + temp_v1;
                }
                var_v0 = *var_a0;
                var_a0 += 1;
            } while (var_v0 != 0);
        }
        var_a2 = (var_a2 >> 8) + (var_a1 << 0x18);
    }
    return var_a2;
}
