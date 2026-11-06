#include "common.h"
s32 func_L00_005F1778(s32, void *, s32);    /* extern */

void func_L01_0050F848(s32 arg0, void *arg1) {
    s32 temp_a0;

    temp_a0 = (*(s32 *)((u8 *)(arg1) + 0x10));
    if (temp_a0 != 0) {
        func_L00_005F1778(temp_a0, arg1 + 0x30, 0);
    }
}
