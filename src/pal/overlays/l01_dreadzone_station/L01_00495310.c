#include "common.h"

s32 func_L01_00495310(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    return 1.0f <= *(const f32 *)(state + 0x64);
}
