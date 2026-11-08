/* Not matching yet: BYTES 48/60 (tools/try_func.py func_01EA8F98 --diff). Not part of the build. */
#include "common.h"

// True when all 16 words of the block are zero.
s32 func_01EA8F98(u32 *p) {
    u32 i;

    if (p == NULL) {
        return 1;
    }
    for (i = 0; i < 0x10; i++) {
        if (p[i] != 0) {
            return 0;
        }
    }
    return 1;
}
