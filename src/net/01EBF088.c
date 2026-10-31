#include "common.h"

/* Stores arg1 at offset 0x80 of arg0 and returns 0; returns 2 when arg0 is NULL. */
s32 func_01EBF088(void *arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *(s32 *)((u8 *)arg0 + 0x80) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
