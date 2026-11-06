#include "common.h"

extern void func_L01_004DE878(void);
extern void func_L01_004DE8B0(void);
void *D_002222F8[2] = {(void *)func_L01_004DE878, (void *)func_L01_004DE8B0};

s32 func_L01_004DDF08(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_002222F8;
    }
    return 0;
}
