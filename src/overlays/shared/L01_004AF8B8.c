#include "common.h"

extern void func_L01_004B0180(void);
extern void func_L01_004B01C0(void);
void *D_00221DE0[2] = {(void *)func_L01_004B0180, (void *)func_L01_004B01C0};

s32 func_L01_004AF8B8(s32 unused, s32 selector, u32 *out) {
    if (selector == 19) {
        *out = 12;
        return (u32)D_00221DE0;
    }
    return 0;
}
