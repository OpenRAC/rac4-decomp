#include "common.h"

extern void func_L01_004466F0(void);
extern void func_L01_00446728(void);
static void *D_00221598[2] = {(void *)func_L01_004466F0, (void *)func_L01_00446728};

s32 func_L01_00445D08(s32 unused, s32 selector, u32 *out) {
    if (selector == 19) {
        *out = 12;
        return (u32)D_00221598;
    }
    return 0;
}
