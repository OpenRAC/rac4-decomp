#include "common.h"

// Stores arg1 at offset 0x408 of arg0 and returns 0; returns 0x17 when arg0 is NULL.
s32 func_01ECC958(void *arg0, s32 arg1) {
    s32 ret = 0x17;

    if (arg0 != NULL) {
        *(s32 *)((u32)arg0 + 0x408) = arg1;
        ret = 0;
    }
    return ret;
}
