/* cflags: -fno-schedule-insns */
#include "common.h"

/* Report whether the word state satisfies the nonempty enabled condition. */
s32 func_01EA73A8(u32 *arg0, s32 *arg1) {
    s32 result = 2;
    s32 nonnull = (arg0 != 0);

    if (arg0 != 0 && arg1 != 0) {
        u32 value = arg0[0];
        if (value < arg0[1]) {
            *arg1 = 0;
        } else if (arg0[3] == 0) {
            *arg1 = 0;
        } else if (value == 0) {
            *arg1 = 0;
        } else {
            *arg1 = nonnull;
        }
        result = 0;
    }
    return result;
}
