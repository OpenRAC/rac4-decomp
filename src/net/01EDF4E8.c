/* cflags: @ee296 -O2 -G0 -fno-gcse */
#include "common.h"

void func_0011EAA0(void *, s32, void *);
s32 func_01EE15D8(s32);
s32 func_01EE18D0(s32, s32, s32, s32);
void func_01EE1A10(s32);
s32 func_01EE1AE8(s32, s32, s32);
s32 func_01EE3070(s32);
extern s32 D_0016A934[];
extern s32 D_0016A938[];
extern s32 D_00199F28[];
extern s32 D_00199F70[];

s32 func_01EDF4E8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_v0;

    temp_v0 = func_01EE18D0(0x80, D_0016A934[0], D_0016A938[0], arg2);
    if (func_01EE1AE8(temp_v0, arg0, arg1) != arg1) {
        func_01EE1A10(temp_v0);
        return -7;
    }
    temp_s0 = func_01EE3070(temp_v0);
    if (func_01EE15D8(temp_v0) == 0) {
        func_01EE1A10(temp_v0);
        return -6;
    }
    if (temp_s0 != 0xD4) {
        func_0011EAA0(D_00199F28, 0xDF, D_00199F70);
    }
    return 0;
}
