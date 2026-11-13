/* cflags: -ffast-math -fno-schedule-insns2 */
#include "common.h"

// Raises b+0x24 towards a+0x18 + x, capped at b+0x14 + 2.5, and adds the rise (at most 0.1) to b+0x18.
void func_L01_004F4050(u8 *a, u8 *b, f32 x) {
    f32 d;
    f32 c;
    f32 y;
    f32 lim;

    if (x <= 0.0f) {
        return;
    }
    *(f32 *)(b + 0x20) = 0.0f;
    y = *(f32 *)(a + 0x18) + x;
    lim = *(f32 *)(b + 0x14) + 2.5f;
    y = lim < y ? lim : y;
    c = *(f32 *)(b + 0x24);
    if (c < y) {
        d = y - c;
        *(f32 *)(b + 0x24) = y;
        *(f32 *)(b + 0x18) = *(f32 *)(b + 0x18) + (d < 0.10000001f ? d : 0.10000001f);
    }
}
