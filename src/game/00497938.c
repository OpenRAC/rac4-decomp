#include "common.h"

extern u8 D_2F32B8[];

// Stores ARG1 into the second word of the 0x54-byte record ARG0.
void func_00497938(s32 arg0, s32 arg1) {
    s32 *p = (s32 *)(D_2F32B8 - (-(arg0 * 0x54)));

    p[1] = arg1;
}
