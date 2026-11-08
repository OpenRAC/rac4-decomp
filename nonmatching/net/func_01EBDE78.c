/* Not matching yet: BYTES 30/88 (tools/try_func.py func_01EBDE78 --diff). Not part of the build. */
#include "common.h"

// Read the 0x14 or 0x24 word of a type 0xD record.
s32 func_01EBDE78(u8 *a0, u8 *p, s32 which, s32 *out) {
    s32 value;
    s32 r;

    *out = 0;
    r = 0xD2F2;
    if (a0 != 0) {
        r = 0xD2F3;
        if (p != 0) {
            if (*(s32 *)p == 0xD) {
                if (which == 0) {
                    value = *(s32 *)(p + 0x14);
                } else if (which == 1) {
                    value = *(s32 *)(p + 0x24);
                } else {
                    return 2;
                }
                *out = value;
                return 0;
            }
        }
    }
    return r;
}
