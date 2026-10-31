#include "common.h"

/* Stores arg1 at offset 0x44 of arg0 and returns 0; returns 2 when arg1 is zero. */
s32 func_01EC2280(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg0 + 0x44) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
