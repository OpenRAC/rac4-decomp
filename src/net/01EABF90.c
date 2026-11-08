/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA95C0(s32 *);
s32 func_01EACB10(s32);

void func_01EABF90(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_01EACB10(temp_v0);
        func_01EA95C0(arg0);
        *arg0 = 0;
    }
}
