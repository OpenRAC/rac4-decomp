/* cflags: -Wa,-G0 */
#include "common.h"

// Returns whether both signed fields, the argument, and the threshold satisfy the checks.
s32 func_0014DE80(s8 *arg0, s16 arg1, f32 arg2) {
    s32 result = 0;
    s8 field = arg0[0x14];
    if (field == 1 && arg1 == field && arg0[0x15] == arg1 && arg2 >= 0.45f) {
        result = 1;
    }
    return result;
}
