/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011AB04(char *);
extern s32 func_01EFCDF0(char *, s32);
extern void func_0011A41C(char *, char *, s32);
s32 func_01EFCEE8(char *arg0, s32 arg1) {
    s32 len;
    s32 n;
    len = func_0011AB04(arg0) - arg1;
    n = func_01EFCDF0(arg0, arg1);
    if (len > 0) {
        func_0011A41C(arg0 + n, arg0 + arg1, len);
    }
    arg0[n + len] = 0;
    return n;
}
