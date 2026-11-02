/* cflags: -O2 -G8 */
#include "common.h"
extern int D_00222EE0;
extern u64 D_004C4BE0[];
extern u8 D_004C4C40[];
void func_L00_005B5040(unsigned int a1)
{
    if (!*(u8 *)a1 || *(u64 *)(a1 + 72) != D_004C4BE0[0]) {
        *(u32 *)D_00222EE0 = 0x30000002;
        *(u32 *)(D_00222EE0 + 4) = (u32)D_004C4C40;
        *(u32 *)(D_00222EE0 + 8) = 0;
        *(u32 *)(D_00222EE0 + 12) = 0x50000002;
        D_00222EE0 += 16;
    }
}
