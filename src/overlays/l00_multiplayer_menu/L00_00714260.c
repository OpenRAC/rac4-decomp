/* cflags: -G0 */
#include "common.h"

// Index the 0x45C table by the difference of the two 0x10A60 counters.
s32 func_L00_00714260(u8 *p) {
    u8 *q;
    s32 diff;

    q = p;
    diff = *(s32 *)(q + 0x10A60) - *(s32 *)(q + 0x10E74);
    q += diff * 4;
    return *(s32 *)(q + 0x45C);
}
