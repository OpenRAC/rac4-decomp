/* cflags: -ffast-math */
#include "common.h"

f32 func_L01_004DB450(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    f32 value = *(const f32 *)(state + 0x3C);
    value = value > 1.0f ? 1.0f : value;
    value = value < 0.0f ? 0.0f : value;
    return value;
}
