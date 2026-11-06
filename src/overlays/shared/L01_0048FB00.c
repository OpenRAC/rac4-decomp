#include "common.h"

extern void func_L01_0048FEB8(void);
extern void func_L01_0048FF10(void);
void *D_00221BC0[2] = {(void *)func_L01_0048FEB8, (void *)func_L01_0048FF10};

s32 func_L01_0048FB00(s32 unused, s32 selector, u32 *out) {
    if (selector == 11) {
        *out = 16;
        return (u32)D_00221BC0;
    }
    return 0;
}
