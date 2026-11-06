#include "common.h"

extern void func_L01_004CA158(void);
extern void func_L01_004CA240(void);
void *D_00221FE0[2] = {(void *)func_L01_004CA158, (void *)func_L01_004CA240};

s32 func_L01_004CA138(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00221FE0;
    }
    return 0;
}
