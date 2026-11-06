#include "common.h"

extern void func_L01_004BCD18(void);
extern void func_L01_004BCD20(void);
void *D_00221F20[2] = {(void *)func_L01_004BCD18, (void *)func_L01_004BCD20};

s32 func_L01_004BC198(s32 unused, s32 selector, u32 *out) {
    if (selector == 19) {
        *out = 12;
        return (u32)D_00221F20;
    }
    return 0;
}
