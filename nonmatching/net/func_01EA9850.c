/* Not matching yet: BYTES 26/56 (tools/try_func.py func_01EA9850 --diff). Not part of the build. */
/* cflags: -G0 */
#include "common.h"

// Read a little-endian 16-bit value out of two bytes.
s32 func_01EA9850(u8 *src, u16 *out) {
    u16 value;

    if (src != NULL && out != NULL) {
        value = src[0];
        *out = value;
        value |= src[1] << 8;
        *out = value;
        return 0;
    }
    return 2;
}
