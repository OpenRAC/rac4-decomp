#include "common.h"

void func_L01_0046A280(u8 *object)
{
    const u8 *state = *(const u8 *const *)(object + 0xAC);
    *(u16 *)(object + 0x74) = 0;
    if (state[0x501] != 0)
        *(u16 *)(object + 0x74) = 42;
    else
        *(u16 *)(object + 0x74) = 21;
}
