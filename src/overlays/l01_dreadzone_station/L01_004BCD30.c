#include "common.h"

extern void func_L01_004BDE30(void);
extern void func_L01_004BDE38(void);
void *D_00221F38[2] = {(void *)func_L01_004BDE30, (void *)func_L01_004BDE38};

s32 func_L01_004BCD30(s32 unused, s32 selector, u32 *out) {
    if (selector == 19) {
        *out = 12;
        return (u32)D_00221F38;
    }
    return 0;
}
