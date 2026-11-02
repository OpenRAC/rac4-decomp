#include "common.h"

/* Remove the next pair from the ring and clear the exhausted flag. */
s32 func_0045CFA8(char *p, s32 *a, s32 *b)
{
    s32 count = *(s32 *)(p + 0x60), index;
    s32 *x, *y;
    if (!count)
        return 0;
    count--;
    *(s32 *)(p + 0x60) = count;
    if (!count)
        p[0x6c] = 0;
    x = (s32 *)(p + 8);
    y = (s32 *)(p + 0xc);
    *a = *(s32 *)((u32)x + (*(s32 *)(p + 0x5c) << 3));
    *b = *(s32 *)((u32)y + (*(s32 *)(p + 0x5c) << 3));
    x += *(s32 *)(p + 0x5c) * 2;
    *x = -1;
    y += *(s32 *)(p + 0x5c) * 2;
    *y = -1;
    index = *(s32 *)(p + 0x5c) + 1;
    *(s32 *)(p + 0x5c) = index == 10 ? 0 : index;
    return 1;
}
