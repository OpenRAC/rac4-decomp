#include "common.h"

s32 func_L01_004F31E0(const u8 *object)
{
    const u8 *parent = *(const u8 *const *)(object + 0xB8);
    const u8 *state;
    if (parent[0x67] != 0xB)
        return 0;
    state = *(const u8 *const *)(object + 0xAC);
    return state[0x40] != 0;
}
