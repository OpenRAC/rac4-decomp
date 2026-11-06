/* cflags: -O2 -G8 */
#include "common.h"
extern int D_00221E20;
extern u64 D_003D76D0[];
extern u8 D_003D7730[];
void func_0044D1B8(unsigned int a1)
{
    if (!*(u8 *)a1 || *(u64 *)(a1 + 72) != D_003D76D0[0]) {
        *(u32 *)D_00221E20 = 0x30000002;
        *(u32 *)(D_00221E20 + 4) = (u32)D_003D7730;
        *(u32 *)(D_00221E20 + 8) = 0;
        *(u32 *)(D_00221E20 + 12) = 0x50000002;
        D_00221E20 += 16;
    }
}
