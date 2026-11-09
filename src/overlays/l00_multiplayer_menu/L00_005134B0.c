/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_L00_004F09A0(s32);
s32 func_L00_004F0A88(s32, s32);

s32 func_L00_005134B0(s32 arg0, s32 arg1) {
    s32 p = arg0 + func_L00_004F09A0(arg0);

    return p + func_L00_004F0A88(p, arg1) - arg0;
}
