/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00520DC8(void *, u8 *, s32);

/* Pad a message into a block: 0, 2, nonzero random bytes, 0, then the data. */
s32 func_L00_005200D8(void *arg0, u8 *arg1, s32 arg2, u8 *arg3, s32 arg4) {
    u8 *p;
    s32 i;
    s32 n;
    s32 k;

    if (arg0 == 0) {
        return 2;
    }
    if (arg2 < arg4 + 11) {
        return 1;
    }
    p = arg1 + arg2 - arg4;
    for (i = arg4 - 1; i >= 0; i--) {
        p[i] = arg3[i];
    }
    k = arg4 + 3;
    p = arg1;
    *p++ = 0;
    *p++ = 2;
    n = arg2 - k;
    func_00520DC8(arg0, p, n);
    for (i = 0; i < n; i++) {
        if (p[i] == 0) {
            func_00520DC8(arg0, p + i, 1);
            i--;
        }
    }
    p[n] = 0;
    return 0;
}
