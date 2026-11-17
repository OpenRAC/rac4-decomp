#include "common.h"

extern u8 D_306FFC[];
extern u8 D_3071A8[];

// Clears byte 0x34 of one 0x3C-byte entry: player 4 indexes D_306FFC, others index D_3071A8 by 512-byte blocks.
void func_0049D238(s32 player, s32 index)
{
    u8 *target;

    if (player == 4) {
        target = D_306FFC + index * 0x3C;
    } else {
        s32 row = index * 0x3C;
        u8 *base = D_3071A8 + (player << 9);
        target = base + row;
    }
    target[0x34] = 0;
}
