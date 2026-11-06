#include "common.h"

extern void func_L06_004BF570(void);
void *D_00221E50[2] = {(void *)func_L06_004BF570, NULL};

s32 func_L06_004BF1E8(s32 unused, s32 selector, u32 *out) {
    if (selector == 21) {
        *out = 4;
        return (u32)D_00221E50;
    }
    return 0;
}
