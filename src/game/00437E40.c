#include "common.h"

extern s32 D_0023AB20[];
s32 D_0021DC84 = 0;
s32 D_0021DC88 = 0;

/* On the first call, sets D_0021DC84 to D_0023AB20 + 0x900000; returns D_0021DC84. */
s32 func_00437E40(void) {
    if (D_0021DC88 == 0) {
        D_0021DC88 = 1;
        D_0021DC84 = D_0023AB20[0] + 0x900000;
    }
    return D_0021DC84;
}
