/* Not matching yet: BYTES 21/56 (tools/try_func.py func_01EDAF98 --diff). Not part of the build. */
#include "common.h"

// 16-bit value of entry `index` in the table, or 0xFFFF.
u16 func_01EDAF98(u8 *p, u16 index) {
    u16 r = 0xFFFF;

    if (p != 0 && index < 0x20 && index < *(u16 *)(p + 0x8)) {
        r = *(u16 *)(p + index * 8 + 0xC);
    }
    return r;
}
