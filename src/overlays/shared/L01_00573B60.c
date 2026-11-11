#include "common.h"

typedef int u128 __attribute__((mode(TI)));

/* Copy 16 bytes, then the two bytes and two floats around them. */
s32 func_L01_00573B60(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    *(u128 *)arg0 = *(u128 *)arg1;
    *(u8 *)((u8 *)arg0 + 0x10) = arg3;
    *(f32 *)((u8 *)arg0 + 0x18) = arg5;
    *(f32 *)((u8 *)arg0 + 0x14) = arg4;
    *(u8 *)((u8 *)arg0 + 0x11) = arg2;
    return 1;
}
