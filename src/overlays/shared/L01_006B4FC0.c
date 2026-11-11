#include "common.h"

s32 func_00667008(s32);
s32 func_L00_006EBEA0(s32, s32, s32, s32);

s32 func_L01_006B4FC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 t = func_00667008(arg0);
    if (t != 0) return func_L00_006EBEA0(t, arg1, arg2, arg3);
    return 0;
}
