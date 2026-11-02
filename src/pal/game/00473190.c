/* cflags: -mno-split-addresses */
#include "common.h"

extern s16 D_002215A8[];

/* Insert a new value into an empty slot unless it is already present. */
s32 func_00473190(s32 value)
{
    s32 index;
    for (index = 0; index < 8; index++) {
        if (!D_002215A8[index]) {
            D_002215A8[index] = value;
            return 1;
        }
        if (D_002215A8[index] == value)
            return 0;
    }
    return 0;
}
