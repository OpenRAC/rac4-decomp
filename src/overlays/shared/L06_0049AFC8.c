#include "common.h"

extern void func_L06_0049B380(void);
void *D_00221AC8[2] = {(void *)func_L06_0049B380, NULL};

s32 func_L06_0049AFC8(s32 unused, s32 selector, u32 *out) {
    if (selector == 21) {
        *out = 4;
        return (u32)D_00221AC8;
    }
    return 0;
}
