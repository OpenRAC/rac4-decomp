#include "common.h"

extern void func_L01_004D91E0(void);
extern void func_L01_004D9280(void);
void *D_00222230[2] = {(void *)func_L01_004D91E0, (void *)func_L01_004D9280};

s32 func_L01_004D9090(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_00222230;
    }
    return 0;
}
