/* Not matching yet: BYTES 27/52 (tools/try_func.py func_0050E438 --diff). Not part of the build. */
#include "common.h"

// Store a float and, for two message types, the message's payload word.
s32 func_0050E438(u8 *p, u8 *msg, f32 value) {
    u16 type;
    s32 found = 0;

    *(f32 *)(p + 0x58) = value;
    type = *(u16 *)(msg + 0x4);
    if (type == 0x6E || type == 0x3E9) {
        found = 1;
        *(s32 *)(p + 0x30) = *(s32 *)(msg + 0x8);
    }
    return found;
}
