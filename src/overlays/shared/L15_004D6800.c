/* cflags: -fno-opt-stack */
#include "common.h"

extern s32 func_L00_005E60D0(s32, s32);

/* Picks a random one of the variadic s32 values, retrying while it equals *arg0; stores and returns it. */
s32 func_L15_004D6800(s32 *arg0, s32 arg1, ...)
{
    s32 buf[32];
    char *ap;
    s32 i;
    s32 j;
    s32 r;

    ap = (char *)__builtin_next_arg(arg1)
       - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    i = 0;
    do {
        buf[i] = *(s32 *)((ap += 8) - 8);
        i++;
    } while (i < arg1);

    j = 15;
    do {
        r = buf[func_L00_005E60D0(0, arg1 - 1)];
        j--;
    } while (j != -1 && r == *arg0);
    *arg0 = r;
    return r;
}
