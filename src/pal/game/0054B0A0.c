#include "common.h"
extern s32 func_0054B140(void *, s32);
extern s32 func_0054BD48(void *, s32);
s32 func_0054B0A0(void *inventory, s32 upgrade)
{
    s32 item;
    if (((u32)upgrade - 1) >= 8)
        return 0;
    if (func_0054B140(inventory, upgrade))
        return 1;
    for (item = 1; item < 20; ++item) {
        if (func_0054BD48(inventory, item) == upgrade)
            return 1;
    }
    return 0;
}
