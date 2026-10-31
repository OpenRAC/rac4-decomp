#include "common.h"

/* Returns 1 if the flag byte at D_21DAE8 + arg0 is set or the callee reports success, else 0. */
extern s32 func_0045CB50();
extern u8 D_21DAE8[];

s32 func_004E73D8(s32 arg0) {
    s32 var_v0;
    u8 *temp_a0;

    temp_a0 = D_21DAE8 + arg0;
    var_v0 = 0;
    if ((*temp_a0 != 0) || (func_0045CB50(temp_a0) != 0)) {
        var_v0 = 1;
    }
    return var_v0;
}
