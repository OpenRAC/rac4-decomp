#include "common.h"

s32 func_L01_004E9EF0(const u8 *object, const u8 *owner)
{
    const u8 *state;
    owner = *(const u8 *const *)(owner + 0x2F4);
    if (owner == NULL)
        return 0;
    if (object[0x67] != 0xB)
        return 0;
    state = *(const u8 *const *)(owner + 0xAC);
    return state[0x40] != 0;
}
