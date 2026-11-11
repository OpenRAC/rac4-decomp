#include "common.h"

extern void *func_004765F0(void *);

s32 func_L01_005B4EB0(void *arg0, s32 arg1)
{
    u8 *state = func_004765F0(arg0);
    if (!state)
        return 0;
    *(s32 *)(state + 0x58) = arg1;
    return 1;
}
