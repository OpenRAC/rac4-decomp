/* C adapted from rac3-decomp func_003A9748 (NTSC-U func_003A9600, commit 403f30a9) */
#include "common.h"
extern u32 *D_00221E20;
extern void func_004537D0(u32 *, s32, s32);
void func_004E78D0(u32 a0, s32 a1, u32 a2) {
    D_00221E20[0] = a2 | 0x10000000;
    D_00221E20[1] = 0;
    D_00221E20[2] = 0x1000404;
    D_00221E20[3] = a0 | (a2 << 16) | 0x6C000000;
    D_00221E20 += 4;
    func_004537D0(D_00221E20, a1, a2 << 4);
    D_00221E20 = (u32 *)((u8 *)D_00221E20 + (a2 << 4));
}

