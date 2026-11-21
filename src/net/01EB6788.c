/* cflags: @ee296 -O2 -G0 */
#include "common.h"

/* Finds a run of free blocks in the bitmap at +0x14, marks it with sequence numbers and returns the run's first block address, or 0 when no run fits. */
s32 func_01EB6788(void *arg0, u32 arg1) {
    s32 ret;
    s32 count;
    s32 last;
    s32 run;
    s32 idx;
    s32 rem;
    s32 val;
    u32 bs;
    u32 lo;
    u8 *map;

    ret = 0;
    if (arg0 == NULL) {
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    bs = *(u32 *)((u8 *)arg0 + 0x8);
    count = *(s32 *)((u8 *)arg0 + 0xC);
    if (bs * count < arg1) {
        return 0;
    }
    lo = (arg1 + bs - 1) / bs;
    idx = 0;
    last = count;
    rem = lo;
    run = 0;
    if (count > 0) {
        map = *(u8 **)((u8 *)arg0 + 0x14);
        while (idx < count) {
            if (map[idx] == 0) {
                run += 1;
                if (run == lo) {
                    last = idx;
                    break;
                }
            } else {
                run = 0;
            }
            idx += 1;
        }
    }
    if (last < count) {
        idx = 1;
        do {
            val = idx | 0x80;
            (*(u8 **)((u8 *)arg0 + 0x14))[last] = val;
            idx += 1;
            rem -= 1;
            ret = *(u32 *)((u8 *)arg0 + 0x10) + last * *(u32 *)((u8 *)arg0 + 0x8);
            last -= 1;
        } while (rem > 0);
    }
    return ret;
}
