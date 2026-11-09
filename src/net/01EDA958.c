/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Turn a run of bit numbers into a mask. */
u32 func_01EDA958(s32 arg0, u16 *arg1, u16 arg2) {
    u32 mask = 0;
    u32 count = arg2;

    while (count != 0) {
        count--;
        mask |= 1 << *arg1++;
    }
    return mask;
}
