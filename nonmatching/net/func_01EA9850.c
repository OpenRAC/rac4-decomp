/* Not matching yet: BYTES 35/56 (tools/try_func.py func_01EA9850 --diff). Not part of the build. */
#include "common.h"

// Read a little-endian 16-bit value out of two bytes.
s32 func_01EA9850(u8 *src, u16 *out) {
    u16 first;

    if (src == 0 || out == 0) {
        return 2;
    }
    first = src[0];
    *out = first;
    *out = first | (src[1] << 8);
    return 0;
}
