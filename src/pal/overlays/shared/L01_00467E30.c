#include "common.h"

s32 func_L01_00467E30(const u32 *values, s32 count, u32 target)
{
    s32 i;
    for (i = 0; i < count; ++i, ++values) {
        if (*values == target)
            return 1;
    }
    return 0;
}
