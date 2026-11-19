/* cflags: @ee296 -O2 -G8 -mno-split-addresses */
#include "common.h"

extern char *func_00122160(char *searchee, char *lookfor);
extern char D_0019C8D0[];
extern char D_0019C8D8[];

s32 func_01EF57D4(char *arg0, char *arg1, s32 arg2) {
    s32 lim = 0x400;
    s32 off;
    char *p;

    off = (arg2 > lim) ? (arg2 - lim) : 0;
    p = arg1 + off;
    if (func_00122160(p, D_0019C8D0) != 0) {
        return 1;
    }
    return func_00122160(p, D_0019C8D8) != 0;
}
