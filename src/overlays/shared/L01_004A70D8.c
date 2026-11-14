#include "common.h"

extern u8 func_L00_005E60D0(s32, s32);

/* Picks a random variadic argument different from the last pick. */
s32 func_L01_004A70D8(u8 *a0, s32 n, ...) {
    char *ap;
    s32 v;
    s32 r;

    v = func_L00_005E60D0(0, n - 1);
    if (v == *a0) {
        v = (v + 1) % n;
    }
    *a0 = v;
    ap = (char *)__builtin_next_arg(n) - (8 - __builtin_args_info(2)) * 8;
    do {
        ap += 8;
        r = *(s32 *)(ap - 8);
        v--;
    } while (v != -1);
    return r;
}
