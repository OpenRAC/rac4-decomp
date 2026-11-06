/* cflags: @ee29 -O2 -G0 -Wuninitialized -mno-split-addresses */
#include "common.h"

extern u8 D_00223C70[];

int func_L01_0047DDE0(int a1, int a2, u32 *a3) {
    if (a2 != 15)
        return 0;
    *a3 = 16;
    return (u32)D_00223C70;
}
