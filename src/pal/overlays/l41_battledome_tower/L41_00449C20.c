/* C adapted from rac3-decomp func_L01_00515DE0 (commit cd0e7c20fd8a). */
#include "common.h"

/* Read the nested word, or return the default when the pointer is null. */
s32 func_L41_00449C20(u8 *p) {
    u8 *q = *(u8 **)(p + 172);
    if (q != 0) {
        return *(s32 *)(q + 28);
    }
    return 10;
}
