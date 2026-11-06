#include "common.h"

extern void func_L01_00453820(void);
extern void func_L01_00453930(void);
static void *D_00221688[2] = {(void *)func_L01_00453820, (void *)func_L01_00453930};

s32 func_L01_004536F8(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00221688;
    }
    return 0;
}
