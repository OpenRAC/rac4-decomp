/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_00535FB0(s32 arg0, s32 arg1, s32 arg2) {
    s32 a3;
    s32 t0;

    a3 = arg1 + 1;
    if (arg2 >= 0x1F) {
        while (arg2 > 0) {
            arg2 >>= 7;
            a3++;
        }
    }
    t0 = arg1 < 0x80;
    if (arg1 == 0) {
        a3 = ((arg0 ^ 2) == 0) ? (a3 + 2) : a3;
    }
    a3++;
    if (!t0 && arg1 > 0) {
        while (arg1 > 0) {
            arg1 >>= 8;
            a3++;
        }
    }
    return a3;
}
