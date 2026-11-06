/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_0046F998(void);
extern s32 D_00221450;
extern s32 D_00221454;
extern s32 D_00221458;
extern s32 D_0022145C;
extern s32 D_00221464;

s32 func_0046F7A8(u8 *arg0)
{
    u8 size = (*(u8 **)(arg0 + 0x24))[8];

    if (D_0022145C < size) {
        func_0046F998();
    }
    *(s32 *)(arg0 + 0x58) = D_00221458;
    D_00221458 += size << 6;
    D_0022145C -= size;
    *(s32 *)(D_00221464 * 8 + D_00221450) = (s32)arg0;
    *(s16 *)(D_00221464 * 8 + D_00221450 + 4) = (*(s32 *)(arg0 + 0x58) - D_00221454) >> 6;
    *(u8 *)(D_00221464 * 8 + D_00221450 + 6) = size;
    *(u8 *)(D_00221464 * 8 + D_00221450 + 7) = 0;
    D_00221464++;
    return *(s32 *)(arg0 + 0x58);
}
