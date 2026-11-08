/* Not matching yet: BYTES 84/152 (tools/try_func.py func_01EB9880 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

// Find the last entry whose type is 0xD-0xF, or the first type 1 entry.
s32 func_01EB9880(u8 *p, s32 *outType, u16 *outIndex) {
    s32 i;
    s32 t;

    *outIndex = -2;
    *outType = 0;
    i = *(u16 *)(p + 0x19C) - 1;
    while (i >= 0) {
        t = *(s32 *)(*(u32 *)(p + 0x184) + i * 0x50);
        if ((u32)(t - 7) < 3) {
            break;
        }
        if (t == 1) {
            *outType = 7;
            return i;
        }
        i--;
    }
    if (i >= 0) {
        *outType = t;
        *outIndex = i;
    }
    return i;
}
