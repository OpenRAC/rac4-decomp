/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* Initializes the linked request only when its request word is clear. */
s32 func_L01_0048F2D8(void *arg0, s32 arg1, s32 arg2)
{
    u8 *linked;

    linked = *(u8 **)((u8 *)arg0 + 0xAC);
    if (*(u32 *)(linked + 0x17C))
        return 0;
    *(u32 *)(linked + 0x17C) = arg1;
    *(u8 *)(linked + 0x1D5) = 1;
    *(u32 *)(linked + 0x1D0) = arg2;
    *(u8 *)(linked + 0x1D4) = 0;
    return 1;
}
