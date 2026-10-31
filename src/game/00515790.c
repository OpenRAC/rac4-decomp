#include "common.h"

// Clamps the index to 0x1F and to the count at 0x2C74, then returns the float in the ring slot at 0x28F0.
f32 func_00515790(u8 *a0, s32 a1) {
    s32 a3;

    if (a1 >= 0x20) {
        a1 = 0x1F;
    }
    a3 = *(s32 *)(a0 + 0x2C74);
    if (a3 < a1) {
        a1 = a3;
    }
    return *(f32 *)(a0 + (((*(s32 *)(a0 + 0x2C70) - a1) + 0x1F) % 32 << 2) + 0x28F0);
}
