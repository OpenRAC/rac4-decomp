/* Not matching yet: BYTES 40/72 (tools/try_func.py func_01EC27F8 --diff). Not part of the build. */
#include "common.h"

// Read the 8-byte body and the 0x18 word of the record.
s32 func_01EC27F8(u8 *p, u64 *out, s32 *outValue) {
    s32 r = 0;

    if (p == 0) {
        r = 2;
    } else if (*(s32 *)(p + 0x3C) != 0) {
        r = 0xD6DA;
    } else if (out == 0) {
        r = 2;
    } else if (outValue == 0) {
        r = 2;
    } else {
        *out = *(u64 *)(p + 0xC);
        *outValue = *(s32 *)(p + 0x18);
    }
    return r;
}
