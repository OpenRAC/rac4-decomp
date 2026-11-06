#include "common.h"

s32 D_0021E050 = 0;
s32 D_0021E080 = 0;
s32 D_0021E07C = 0;

/* Returns 1 when D_0021E050 is at most 99999 and D_0021E080 differs from D_0021E07C, otherwise 0. */
s32 func_00161778(void) {
    s32 var_v0;

    var_v0 = 0;
    if (D_0021E050 <= 99999) {
        if (D_0021E080 != D_0021E07C) {
            return 1;
        }
    }
    return var_v0;
}
