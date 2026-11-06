#include "common.h"

void func_L01_00429818(u8 *object, s32 mode)
{
    if ((u32)mode < 7) {
        u8 *state = *(u8 **)(object + 0xAC);

        state[0x4B] = mode;
        if (mode == 2) {
            *(u32 *)(state + 0x28) |= 0x80000;
        }
    }
}
