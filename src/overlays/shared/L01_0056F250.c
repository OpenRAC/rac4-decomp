#include "common.h"
typedef long long s128;
extern s32 func_0056EE18(s128, void *, s128, s128 *, s128 *, void *);

s32 func_L01_0056F250(void *first, void *context, void *second, s128 *output, void *settings)
{
    s128 local;
    if (!first || !second)
        return 0;
    local = *(s128 *)((u8 *)second + 0xF0);
    return func_0056EE18(*(s128 *)((u8 *)first + 0x10), context,
                           *(s128 *)((u8 *)second + 0x10), &local,
                           output, settings);
}
