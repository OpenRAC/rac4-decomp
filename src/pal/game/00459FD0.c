#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/3896E8.c func_0038DF10.
 * Independently reconstructed from RAC4 PAL retail. */

extern u32 *D_00221F20;
extern u8 D_003D9FF0[], D_003DA010[], D_0020BF90[], D_003D9F80[];
void func_00459FD0(s32 alternate)
{
    D_00221F20[0] = 0x30000002;
    if (alternate)
        D_00221F20[1] = (u32)D_003D9FF0;
    else
        D_00221F20[1] = (u32)D_003DA010;
    D_00221F20[2] = 0;
    D_00221F20[3] = 0x50000002;
    D_00221F20 += 4;
    D_00221F20[0] = 0x30000029;
    D_00221F20[1] = (u32)D_0020BF90;
    D_00221F20[2] = 0;
    D_00221F20[3] = 0x50000029;
    D_00221F20 += 4;
    D_00221F20[0] = 0x30000003;
    D_00221F20[1] = (u32)D_003D9F80;
    D_00221F20[2] = 0;
    D_00221F20[3] = 0x50000003;
    D_00221F20 += 4;
}
