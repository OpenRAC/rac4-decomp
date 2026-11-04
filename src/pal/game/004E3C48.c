#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/3C9888.c func_003C99D0.
 * Independently reconstructed from RAC4 PAL retail. */

extern u32 *D_00221F20, *D_00221E2C;
extern s32 D_0021DAB0, D_00221E34;
extern void func_004E4B68(void), func_004E8AB0(void);
extern s32 func_004E4CD0(s32);
void func_004E3C48(void)
{
    u32 *saved = D_00221F20;
    s32 size;
    D_00221F20 += 4;
    D_00221E2C[0] = 0x20000000;
    D_00221E2C[1] = (u32)D_00221F20;
    D_00221E2C[2] = 0;
    D_00221E2C[3] = 0;
    func_004E4B68();
    size = func_004E4CD0(D_0021DAB0);
    func_004E8AB0();
    if (D_00221E34 < size)
        D_00221E34 = size;
    D_00221F20[0] = 0x20000000;
    D_00221F20[1] = (u32)(D_00221E2C + 4);
    D_00221F20[2] = 0;
    D_00221F20[3] = 0;
    D_00221F20 += 4;
    saved[0] = 0x20000000;
    saved[1] = (u32)D_00221F20;
    saved[2] = 0;
    saved[3] = 0;
}
