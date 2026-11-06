#include "common.h"

extern u8 D_002F9208[];

/* If the flag byte D_002F9208 is set, clears it and returns 1; else 0. */
s32 func_L00_00620698(void) {
    if (D_002F9208[0] != 0) {
        D_002F9208[0] = 0;
        return 1;
    }
    return 0;
}
