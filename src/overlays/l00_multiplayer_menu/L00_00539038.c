/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern u64 func_00130480(u64, u64);

/* remainder of a multi-word number by a divisor, 32 bits at a time */
u64 func_L00_00539038(s32 *arg0, u64 arg1) {
    u64 r;
    s32 i;
    u64 *words;
    u64 w;
    u64 m;

    r = 0;
    for (i = arg0[1] - 1; i >= 0;) {
        words = (u64 *)arg0[0];
loop:
        w = words[i];
        m = 0xFFFFFFFF;
        i--;
        r = func_00130480((r << 32) | (w >> 32), arg1);
        r = func_00130480((r << 32) | (w & m), arg1);
        if (i >= 0) {
            goto loop;
        }
        break;
    }
    return r;
}
