#include "common.h"
typedef struct Owner {
    u8 unused[0xAC];
    const u8 *state;
} Owner;
s32 func_L04_004A20B0(const Owner *owner)
{
    return owner->state[0x312] != 0;
}
