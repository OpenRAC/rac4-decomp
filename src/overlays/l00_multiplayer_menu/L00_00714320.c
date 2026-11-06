#include "common.h"
void func_L00_00714320(u8 *owner, s32 value)
{
    u8 *state = (u8 *)((u32)owner + 0x10000);
    if (!state[0xE79])
        state[0xE78] = value;
}
