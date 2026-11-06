#include "common.h"

extern void func_L01_00481780(void);
extern void func_L01_00481790(void);
void *D_00221A98[2] = {(void *)func_L01_00481780, (void *)func_L01_00481790};

s32 func_L01_0047FBD0(s32 unused, s32 selector, u32 *out) {
    if (selector == 5) {
        *out = 16;
        return (u32)D_00221A98;
    }
    return 0;
}
