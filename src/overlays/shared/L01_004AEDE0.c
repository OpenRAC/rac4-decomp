#include "common.h"

extern void func_L01_004AF060(void);
extern void func_L01_004AF080(void);
void *D_00221DB8[2] = {(void *)func_L01_004AF060, (void *)func_L01_004AF080};

s32 func_L01_004AEDE0(s32 unused, s32 selector, u32 *out) {
    if (selector == 19) {
        *out = 12;
        return (u32)D_00221DB8;
    }
    return 0;
}
