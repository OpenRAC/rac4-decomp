/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

s32 func_0011AB04(s32);
s32 func_01F09C2C(s32);

s32 func_01F0A2A0(s32 arg0) {
    s32 i = 0;
loop:
    if (func_0011AB04(func_01F09C2C(arg0))) {
        return 1;
    }
    arg0 += 8;
    i++;
    if (i < 5) goto loop;
    return 0;
}
