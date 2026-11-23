#include "common.h"

s32 func_00504EB0(void *object)
{
    s32 count;
    s32 index;
    s32 advanced;
    s32 remaining;

    count = *(s32 *)((u8 *)object + 8);
    if (count == 0)
        return 0;

    index = *(s32 *)((u8 *)object + 4);
    remaining = *(s32 *)((u8 *)object + 0xC);
    advanced = (s32)((u32)index + 1U);
    *(s32 *)((u8 *)object + 8) = (s32)((u32)count - 1U);
    remaining = (s32)((u32)remaining - 1U);
    *(s32 *)((u8 *)object + 0xC) = remaining < 0 ? 0 : remaining;
    *(s32 *)((u8 *)object + 4) = advanced % 64;
    return 1;
}
