/* cflags: -mno-split-addresses */
#include "common.h"

extern s16 D_002215A8[];

s32 func_004731E0(s32 value)
{
    s32 i = 0;
    s16 *p;

    p = D_002215A8;
    for (; i < 8; i++, p++) {
        if (*p == value) {
            *p = 0;
            return 1;
        }
    }
    return 0;
}
