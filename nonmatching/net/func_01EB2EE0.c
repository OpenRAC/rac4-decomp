/* Not matching yet: BYTES 51/64 (tools/try_func.py func_01EB2EE0 --diff). Not part of the build. */
#include "common.h"

// True when all 0x40 bytes of the block are zero.
s32 func_01EB2EE0(u8 *p) {
    u32 i;

    if (p == NULL) {
        return 1;
    }
    for (i = 0; i < 0x40; i++) {
        if (p[i] != 0) {
            return 0;
        }
    }
    return 1;
}
