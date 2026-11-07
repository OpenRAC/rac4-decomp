/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EF3690(s32);
extern s32 D_0016FF28[];

void func_001573C4(void **arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    *arg0 = D_0016FF28;
    if (temp_a1 != 0) {
        func_01EF3690(arg0);
    }
}
