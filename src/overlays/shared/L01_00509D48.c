#include "common.h"

extern s32 D_0021DDB8;

// Refresh the byte at +0x60E from the state at +0x20 when +0x79C is stale, then return it.
u8 func_L01_00509D48(u8 *object) {
    u8 *linked;
    u8 state;

    linked = *(u8 **)(object + 0xAC);
    if (*(s32 *)(linked + 0x79C) != D_0021DDB8) {
        linked[0x60E] = (u32)(object[0x69] - 1) < 4 &&
            (state = object[0x20]) != 1 && state != 0xF && state != 0x12 && state != 0x17 &&
            state != 0x19 && state != 0x1A && state != 0x1B && state != 0x1C && state != 0x13 &&
            state != 0x14 && state != 0x16 && state != 0x15;
        *(s32 *)(linked + 0x79C) = D_0021DDB8;
    }
    return linked[0x60E];
}
