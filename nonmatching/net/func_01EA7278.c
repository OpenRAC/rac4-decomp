/* Not matching yet: BYTES 41/76 (tools/try_func.py func_01EA7278 --diff). Not part of the build. (tools/try_func.py func_01EA7278 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Report how far the 0x8 cursor is ahead of the 0x4 base.
s32 func_01EA7278(u8 *p, u32 *out) {
    u32 cursor;
    u32 start;
    u32 base;

    if (p == 0 || out == 0) {
        return 2;
    }
    cursor = *(u32 *)(p + 0x8);
    if (*(u32 *)(p + 0xC) != cursor) {
        start = *(u32 *)(p + 0x0);
        base = *(u32 *)(p + 0x4);
        if (base < start) {
            *out = start - base;
        } else {
            *out = cursor - base;
        }
    } else {
        *out = 0;
    }
    return 0;
}
