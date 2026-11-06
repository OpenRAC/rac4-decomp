#include "common.h"

extern void func_L01_004AE578(void);
extern void func_L01_004AE5F8(void);
void *D_00221D90[2] = {(void *)func_L01_004AE578, (void *)func_L01_004AE5F8};

s32 func_L01_004AE4C0(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_00221D90;
    }
    return 0;
}
