/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0015DB88(s32);
extern s32 D_0016FE00[];

void func_01EED5B8(void **arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    *arg0 = D_0016FE00;
    if (temp_a1 != 0) {
        func_0015DB88(arg0);
    }
}
