#include "common.h"

extern void *func_00476ED0(void *);

s32 func_L01_005B93B8(void *arg0, s32 arg1)
{
    u8 *state = func_00476ED0(arg0);
    if (!state)
        return 0;
    *(s32 *)(state + 0x58) = arg1;
    return 1;
}