/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division */
#include "common.h"




s32 func_L00_00554510(u8 *arg0, u8 *arg1) {
    unsigned long w = *(unsigned long *)(arg0 + 0x10);
    unsigned long mask = 0x9000;
    mask <<= 22;
    if (w & mask) {
        *(u8 **)(arg1 + 0x18) = arg0;
        *(u32 *)(arg1 + 0x1C) = *(u32 *)(arg0 + 0x20);
        *(u8 **)(arg0 + 0x20) = arg1;
        arg0[0x16] |= 8;
        return 0;
    }
    return 4;
}

