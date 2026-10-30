#include "common.h"

extern int D_3096A8[];

// Clear the bit at position arg0 from D_3096A8.
void func_004B2260(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_3096A8[0x1] & ~(1 << arg0);
    D_3096A8[0x1] = temp_v0;
    if (temp_v0 == 0) {
        D_3096A8[0x1F] = 0x14;
        D_3096A8[0x0] = 0xF;
    }
}
