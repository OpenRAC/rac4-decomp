#include "common.h"

extern void func_L08_004D1890(void);
extern void func_L08_004D18D8(void);
void *D_002220F0[2] = {(void *)func_L08_004D1890, (void *)func_L08_004D18D8};

s32 func_L08_004D12D0(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_002220F0;
    }
    return 0;
}
