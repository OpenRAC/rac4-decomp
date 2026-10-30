#include "common.h"

/* Copies 8 s16 values and writes zeros to other fields */
void func_00455E40(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8) {
    *(s16 *)(arg0 + 0x00) = arg1;
    *(s16 *)(arg0 + 0x02) = arg2;
    *(s16 *)(arg0 + 0x04) = arg3;
    *(s16 *)(arg0 + 0x06) = arg4;
    *(s16 *)(arg0 + 0x08) = arg5;
    *(s16 *)(arg0 + 0x0A) = arg6;
    *(s16 *)(arg0 + 0x0C) = 0;
    *(s16 *)(arg0 + 0x0E) = 0;
    *(s16 *)(arg0 + 0x10) = arg7;
    *(s16 *)(arg0 + 0x12) = (s16) arg8;
    *(s16 *)(arg0 + 0x14) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
