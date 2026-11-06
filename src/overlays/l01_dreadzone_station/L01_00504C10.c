#include "common.h"
f32 func_L01_00504C10(const u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    f32 ratio = *(const f32 *)(state + 0x280) / (f32) * (const s32 *)(state + 0x284);
    if (ratio < 0.15f)
        return 0.75f;
    if (ratio < 0.45f)
        return 0.5f;
    if (ratio < 0.75f)
        return 0.25f;
    return 0.0f;
}
