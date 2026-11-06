#include "common.h"

extern void func_L01_003D09C8(void);
extern void func_L01_003D0B20(void);
void *D_00220C30[2] = {(void *)func_L01_003D09C8, (void *)func_L01_003D0B20};

s32 func_L01_003D09A8(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00220C30;
    }
    return 0;
}
