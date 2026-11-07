/* Not matching yet: BYTES 50/80 (tools/try_func.py func_01EACF60 --diff). Not part of the build. */
#include "common.h"

// Add `add` to the 0x80-word little-endian counter at `p`.
void func_01EACF60(u32 *p, u32 add) {
    u32 i;
    u32 value;

    for (i = 0; i < 0x80; i++) {
        if (i == 0) {
            value = p[i] + add;
            p[i] = value;
            if (value >= add) {
                return;
            }
        } else {
            value = p[i] + 1;
            p[i] = value;
            if (value != 0) {
                return;
            }
        }
    }
}
