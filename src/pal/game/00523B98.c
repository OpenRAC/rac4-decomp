#include "common.h"

extern s32 func_00549F80(void *, s32, s32, s32, s32, s32, void *);
/* Forward object fields and indexed data to the operation. */
s32 func_00523B98(char *p, u8 index, s32 arg, void *last)
{
    return func_00549F80(*(void **)(p + 0x26e4), index, arg, *(u8 *)(p + 0x266d) != 0, *(s32 *)(p + 0x2f28), *(s32 *)(p + index * 0x50 + 0x2318), last);
}
