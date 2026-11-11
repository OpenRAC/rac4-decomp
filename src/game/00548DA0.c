#include "common.h"

/* Bit 7 of the byte 0xA30 of slot a1, clamped to 0..0x1F. */
u64 func_00548DA0(u8 *a0, s32 a1) {
    s32 *index;
    u64 value;

    if (a1 >= 0x20) {
        a1 = 0x1F;
    }
    if ((*(index = &a1)) < 0) {
        a1 = 0;
    }
    value = *(u8 *)(a0 + *index * 0x44 + 0xA30);
    return (value ^ 0x80) >> 7;
}
