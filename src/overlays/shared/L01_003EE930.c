#include "common.h"

extern void func_L01_003EE950(void);
extern void func_L01_003EEA00(void);
void *D_00220E60[2] = {(void *)func_L01_003EE950, (void *)func_L01_003EEA00};

s32 func_L01_003EE930(s32 unused, s32 selector, u32 *out) {
    if (selector == 20) {
        *out = 8;
        return (u32)D_00220E60;
    }
    return 0;
}
