/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Counts the nonzero bytes of the buffer at arg0 + 0x14 and stores that count times the field at 0x8 into *arg1; returns 0, or 2 on a null pointer.
s32 func_01EB6100(u8 *arg0, s32 *arg1) {
    u32 count;
    u32 i;
    u32 n;
    u32 next;

    count = 0;
    if (arg0 == 0) {
        return 2;
    }
    if (arg1 == 0) {
        return 2;
    }
    *arg1 = 0;
    n = *(u32 *)(arg0 + 0xC);
    for (i = 0; i < n; i++) {
        next = count + 1;
        if (*(u8 *)(*(u32 *)(arg0 + 0x14) + i) != 0) {
            count = next;
        }
    }
    *arg1 = count * *(s32 *)(arg0 + 8);
    return 0;
}
