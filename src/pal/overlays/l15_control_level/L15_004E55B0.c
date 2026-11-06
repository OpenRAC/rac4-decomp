#include "common.h"

extern f32 func_004756D0(f32 from, f32 to, f32 factor);

f32 func_L15_004E55B0(const u8 *object, f32 from, f32 to)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    return func_004756D0(from, to, *(const f32 *)(state + 0x1C0));
}
