#include "common.h"

extern void func_L02_004CF710(void);
extern void func_L02_004CF700(void);
static void *D_00222240[2] = {(void *)func_L02_004CF710, (void *)func_L02_004CF700};

s32 func_L02_004CF5F8(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00222240;
    }
    return 0;
}
