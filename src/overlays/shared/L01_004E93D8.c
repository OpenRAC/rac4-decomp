#include "common.h"

s32 func_L01_004E93D8(void *context, const u8 *object)
{
    const u8 *state;
    if (object[0x33C] == 0x40)
        return 0;
    state = *(const u8 *const *)(object + 0x2E0);
    return *(const u32 *)(state + 0x2BC) == 0;
}
