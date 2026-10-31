#include "common.h"

extern s32 func_00549BB8();

/* Validates arg1 - 1 against 8, calls func_00549BB8, then decrements the byte at arg0 + 0x21 + index. */
s32 func_00549FD0(s32 arg0, s32 arg1) {
    u32 temp_s1;
    u8 *temp_a0;

    temp_s1 = arg1 - 1;
    if (temp_s1 >= 8U || func_00549BB8() == 0) {
        return 0;
    }
    temp_a0 = (u8 *)(arg0 + 0x21);
    temp_a0 += temp_s1;
    *temp_a0 -= 1;
    return 1;
}
