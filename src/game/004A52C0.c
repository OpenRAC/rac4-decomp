#include "common.h"

extern u8 D_307B58[];

// Stores the float ARG1 at offset 0xD0 of the 0xEC-byte entry ARG0.
void func_004A52C0(s32 arg0, f32 arg1) {
    u8 *entry = D_307B58 - (-(arg0 * 0xEC));

    *(f32 *)(entry + 0xD0) = arg1;
}
