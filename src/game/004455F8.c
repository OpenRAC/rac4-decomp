#include "common.h"

/* Copies 10 s32 values from arguments to memory at $a0 */
void func_004455F8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    *(s32 *)(arg0 + 0x00) = arg1;
    *(s32 *)(arg0 + 0x04) = arg2;
    *(s32 *)(arg0 + 0x08) = arg3;
    *(s32 *)(arg0 + 0x0C) = arg4;
    *(s32 *)(arg0 + 0x10) = arg5;
    *(s32 *)(arg0 + 0x14) = arg6;
    *(s32 *)(arg0 + 0x18) = arg7;
    *(s32 *)(arg0 + 0x1C) = arg8;
    *(s32 *)(arg0 + 0x20) = arg9;
    *(s32 *)(arg0 + 0x24) = arg10;
}
