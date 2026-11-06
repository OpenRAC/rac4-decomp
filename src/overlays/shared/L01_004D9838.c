#include "common.h"

extern void func_L01_004D94B0(void);
extern void func_L01_004D9AA8(void);
void *D_00222240[2] = {(void *)func_L01_004D94B0, (void *)func_L01_004D9AA8};

s32 func_L01_004D9838(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00222240;
    }
    return 0;
}
