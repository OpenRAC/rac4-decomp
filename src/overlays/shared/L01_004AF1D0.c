#include "common.h"

void *D_00221DD0[2] = {NULL, NULL};

s32 func_L01_004AF1D0(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_00221DD0;
    }
    return 0;
}
