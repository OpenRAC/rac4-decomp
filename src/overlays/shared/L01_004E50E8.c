#include "common.h"

extern void func_L01_004E4EB8(void);
extern void func_L01_004E51F0(void);
void *D_002223F0[2] = {(void *)func_L01_004E4EB8, (void *)func_L01_004E51F0};

s32 func_L01_004E50E8(s32 unused, s32 selector, u32 *out) {
    if (selector == 11) {
        *out = 16;
        return (u32)D_002223F0;
    }
    return 0;
}
