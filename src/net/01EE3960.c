#include "common.h"

/* Returns the word at offset 0x8 of arg0, or 0 when arg0 is NULL. */
s32 func_01EE3960(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = *(s32 *)((u8 *)arg0 + 0x8);
    }
    return var_v0;
}
