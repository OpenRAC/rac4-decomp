#include "common.h"

extern u8 D_3070A8[];
extern u8 D_3072A8[];

/* Mark the +0x24 byte of one 0x30-byte entry: the D_3070A8 table when mode is
   4, otherwise the mode-strided (0x200) D_3072A8 table. */
void func_0049DFA8(s32 mode, s32 index)
{
    u8 *target;

    if (mode == 4) {
        target = D_3070A8 + index * 0x30;
    } else {
        s32 row = index * 0x30;
        u8 *base = D_3072A8 + (mode << 9);
        target = base + row;
    }
    target[0x24] = 1;
}
