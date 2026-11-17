/* cflags: -O2 -G8 -fno-opt-stack -Wuninitialized -Wall */
#include "common.h"

s32 func_L00_00568330(s32, s32, s32, s32 *, s32);
s32 func_L00_00568010(s32, s32);

s32 func_L00_00566940(s32 arg0) {
    s32 value = 1;

    func_L00_00568330(arg0, 65535, 4105, &value, 4);
    return func_L00_00568010(arg0, 2);
}
