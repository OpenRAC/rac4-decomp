#include "common.h"

/* net: returns the word at offset 0x24 of arg0, or 0 when arg0 is NULL */
s32 func_01EE3A98(void *arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = *(s32 *)((u8 *)arg0 + 0x24);
    }
    return var_v0;
}
