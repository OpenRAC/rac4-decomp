/* Not matching yet: SIZE ours 48 / retail 56 (tools/try_func.py func_01EA9888 --diff). Not part of the build. */
#include "common.h"

/* Store a 32-bit value into four bytes, least significant first, and report 0. */
s32 func_01EA9888(u8 *arg0, u32 arg1) {
    u32 byte1 = arg1 >> 8;
    u32 byte3 = arg1 >> 24;
    u32 byte2 = arg1 >> 16;
    s32 result;

    if (arg0 == 0) {
        result = 2;
    } else {
        u8 *p = arg0;

        *p++ = arg1;
        *p++ = byte1;
        p[1] = byte3;
        *p = byte2;
        result = 0;
    }
    return result;
}
