/* Not matching yet: BYTES 13/56 (tools/try_func.py func_01EDAF98 --diff). Not part of the build. */
/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

// 16-bit value of entry `index` in the table, or 0xFFFF.
u16 func_01EDAF98(u8 *p, u16 index) {
    u16 r = 0xFFFF;

    if (p != 0 && index < 0x20 && index < *(u16 *)(p + 0x8)) {
        r = *(u16 *)(p + (index << 3) + 0xC);
    }
    return r;
}
