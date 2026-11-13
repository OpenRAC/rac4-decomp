#include "common.h"

extern u8 D_00306FFC[];
extern u8 D_003071A8[];

/* Mark the +0x34 byte of one 0x3C-byte entry: the D_00306FFC table when mode is
   4, otherwise the mode-strided (0x200) D_003071A8 table. */
void func_0049D1E8(s32 mode, s32 index)
{
    u8 *target;

    if (mode == 4) {
        target = D_00306FFC + index * 0x3C;
    } else {
        s32 row = index * 0x3C;
        u8 *base = D_003071A8 + (mode << 9);
        target = base + row;
    }
    target[0x34] = 1;
}
