/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

void func_01EAE578(s32, s32, s32, s32);

s32 func_01EAE710(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 n = 0;

    while (arg3 >= 0x40) {
        func_01EAE578(arg0, 0x11, arg1, arg2);
        arg1 += 0x40;
        arg2 += 0x40;
        arg3 -= 0x40;
        n += 0x40;
    }
    return n;
}
