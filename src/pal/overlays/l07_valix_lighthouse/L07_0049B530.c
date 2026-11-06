#include "common.h"

s32 func_L07_0049B530(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    return *(const f32 *)(state + 0x20) == 1.0f;
}
