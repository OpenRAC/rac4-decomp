#include "common.h"

/* Store a2 in the halfword of slot a1, clamped to 0..0x1F. */
void func_00547DC8(u8 *a0, s32 a1, s32 a2) {
    s32 *index = &a1;

    if (a1 >= 0x20) {
        a1 = 0x1F;
    }
    if (a1 < 0) {
        a1 = 0;
    }
    if (a2 < 0) {
        a2 = 0;
    }
    *(s16 *)(a0 + *index * 0x44 + 0xA32) = a2;
}
