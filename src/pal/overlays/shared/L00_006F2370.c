/* C adapted from rac3-decomp func_L39_00665CC0 (commit cd0e7c20fd8a). */
#include "common.h"

/* Tests the two byte fields or the word against the supplied key. */
s32 func_L00_006F2370(u8 *a, s32 k) {
    if ((a[12079] != 255 && a[12077] == 57) || k == *(s32 *)(a + 14976)) {
        return 1;
    }
    return 0;
}
