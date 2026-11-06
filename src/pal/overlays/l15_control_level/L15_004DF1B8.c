#include "common.h"

void func_L15_004DF1B8(u8 *object, u16 value, f32 amount)
{
    u8 *state = *(u8 **)(object + 0xAC);
    *(u16 *)(state + 0x300) = value;
    *(f32 *)(state + 0x30C) = amount;
    *(f32 *)(state + 0x208) = -10.0f;
    *(s32 *)(state + 0x32C) = 0;
    *(u16 *)(state + 0x302) = 0;
}
