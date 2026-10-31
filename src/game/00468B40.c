#include "common.h"

// Process array with 16-byte stride, accumulating aligned size
s32 func_00468B40(s32 *arg0) {
    s32 var_a1 = 8;

    if (*arg0 != 0) {
        do {
            s32 temp_v0 = arg0[1];
            var_a1 += 8;
            arg0 += 4;
            var_a1 += temp_v0;
            var_a1 = (var_a1 + 3) & ~3;
        } while (*arg0 != 0);
    }

    return var_a1 + 8;
}
