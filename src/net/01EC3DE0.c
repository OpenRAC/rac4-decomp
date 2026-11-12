/* cflags: @ee32-040921 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"
s32 func_01EA7D98(s32, s32);
s32 func_01EC3460();
s32 func_01EC3498();

s32 func_01EC3DE0(s32 arg0, s32 arg1) {
    s32 r = func_01EC3460();
    s32 s;

    if (r == 0) {
        s = 2;
        if (arg0 != 0) {
            s = func_01EA7D98(arg0, arg1);
        }
        func_01EC3498();
        return s;
    }
    return r;
}
