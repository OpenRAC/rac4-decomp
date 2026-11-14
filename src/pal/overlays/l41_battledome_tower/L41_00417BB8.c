#include "common.h"

/* Tests the pointed-to state against the supplied float and mode values. */
s32 func_L41_00417BB8(void *arg0, f32 arg1)
{
    u8 *owner;
    u8 *state;

    owner = *(u8 **)((u8 *)arg0 + 0xAC);
    if (arg1 <= 0.0f ||
        (state = *(u8 **)(owner + 0x40), *(s32 *)(state + 0x25CC) == 0x31) ||
        *(s32 *)(state + 0x25D4) == 0x14 || *(f32 *)(state + 0x2E20) <= 0.0f) {
        return 0;
    }
    return 1;
}
