/* cflags: -O2 -G8 */
#include "common.h"
extern int D_00221F20;
extern u64 D_003D7710[];
extern u8 D_003D7770[];
void func_0044D860(unsigned int a1)
{
    if (!*(u8 *)a1 || *(u64 *)(a1 + 72) != D_003D7710[0]) {
        *(u32 *)D_00221F20 = 0x30000002;
        *(u32 *)(D_00221F20 + 4) = (u32)D_003D7770;
        *(u32 *)(D_00221F20 + 8) = 0;
        *(u32 *)(D_00221F20 + 12) = 0x50000002;
        D_00221F20 += 16;
    }
}
