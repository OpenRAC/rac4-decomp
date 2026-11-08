#include "common.h"

s32 func_003FE588(void *arg0, s32 arg1)
{
    u32 value;
    s32 result;

    value = *(u32 *)((u8 *)arg0 + 0x28);
    result = 0x203;
    if (value != 0) {
        value = *(u32 *)value;
        result = 0x205;
        value ^= (u32)arg1;
        result = (value == 0) ? 0 : 0x205;
    }
    return result;
}
