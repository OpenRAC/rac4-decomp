/* Not matching yet: BYTES 9/52 (tools/try_func.py func_01EA9950 --diff). Not part of the build. */
#include "common.h"

/* Read two bytes as a big-endian halfword into the buffer, or report 2. */
s32 func_01EA9950(u8 *arg0, u16 *arg1) {
    s32 result = 2;

    if (arg0 != 0) {
        if (arg1 != 0) {
            u16 value = arg0[0] << 8;

            *arg1 = value;
            value |= arg0[1];
            *arg1 = value;
            result = 0;
        }
    }
    return result;
}
