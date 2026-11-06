#include "common.h"
void func_L00_00714340(u8 *owner, s32 value)
{
    u8 *state = (u8 *)((u32)owner + 0x10000);
    state[0xE79] = value;
    if (value == 1)
        state[0xE78] = value;
}
