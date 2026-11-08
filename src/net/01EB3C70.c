/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA90F0();
s32 func_01EB2F70(s32);
s32 func_01EB3028(s32, s32);
s32 func_01EB3060(s32, s32);

void func_01EB3C70(s32 arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_01EA90F0();
    temp_v0_2 = func_01EB3028(temp_v0, arg1);
    if (temp_v0_2 != 0) {
        func_01EB3060(temp_v0, temp_v0_2);
        func_01EB2F70(temp_v0_2);
    }
}
