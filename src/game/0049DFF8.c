#include "common.h"

extern u8 D_3070A8[];
extern u8 D_3072A8[];

// Clears byte 0x24 of one 0x30-byte entry: player 4 indexes D_3070A8, others index D_3072A8 by 512-byte blocks.
void func_0049DFF8(s32 player, s32 index)
{
    u8 *target;

    if (player == 4) {
        target = D_3070A8 + index * 0x30;
    } else {
        s32 row = index * 0x30;
        u8 *base = D_3072A8 + (player << 9);
        target = base + row;
    }
    target[0x24] = 0;
}
