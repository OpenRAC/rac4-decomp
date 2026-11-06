#include "common.h"

extern void func_L01_0048F9F8(void);
extern void func_L01_0048FAA8(void);
void *D_00221BB0[2] = {(void *)func_L01_0048F9F8, (void *)func_L01_0048FAA8};

s32 func_L01_0048F3C8(s32 unused, s32 selector, u32 *out) {
    if (selector == 11) {
        *out = 16;
        return (u32)D_00221BB0;
    }
    return 0;
}
