#include "common.h"

/* Shifts the bytes from arg2 + arg4 up to arg3 - 2 one place higher, then writes a space and a terminating zero */
void func_L00_00716710(s32 unused0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;

    (void)unused0;
    for (i = arg3 - 2; i >= arg2 + arg4; i--) {
        arg1[i + 1] = arg1[i];
    }
    arg1[arg2 + arg4] = 0x20;
    arg1[arg3 - 1] = 0;
}
