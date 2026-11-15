#include "common.h"

extern u8 D_21DC18[];
s32 D_0021E0D8 = 0;

// Check three entries: where the word is 1 the byte must be zero, otherwise the byte must be below 5; a failing check returns 1, and passing all three returns 0.
s32 func_00162D60(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if ((&D_0021E0D8)[i] == 1) {
            if (D_21DC18[i] != 0) {
                return 1;
            }
        } else if (D_21DC18[i] >= 5) {
            return 1;
        }
    }
    return 0;
}
