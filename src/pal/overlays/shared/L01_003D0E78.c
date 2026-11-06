#include "common.h"

extern s32 func_L01_003D09C0(const u8 *object);

s32 func_L01_003D0E78(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    s32 result = 0;
    if (state[0x96] != 0) {
        if (state[0x95] == 0 || func_L01_003D09C0(object) == 0)
            result = 1;
    }
    return result;
}
