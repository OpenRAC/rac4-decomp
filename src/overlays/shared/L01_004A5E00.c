#include "common.h"

s32 func_L01_004A5E00(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    const u32 *entries = (const u32 *)(state + 0xA0);
    s32 index;

    for (index = 0; index < 8; index++) {
        if (entries[index] != 0) {
            return 1;
        }
    }
    return 0;
}
