/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA42D8(s32);
s32 func_01EA57B8(void);
s32 func_01EA57F8(void);
s32 func_01ECF6B8(s32, s32, s32, s32, s32, s32);

s32 func_01EC9340(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 r;
    s32 ret;

    r = func_01EA42D8(func_01EA57B8());
    if (r != 0) {
        return r;
    }
    ret = func_01ECF6B8(arg0, arg1, arg2, arg3, arg4, arg5);
    r = func_01EA42D8(func_01EA57F8());
    if (r != 0) {
        return r;
    }
    return ret;
}
