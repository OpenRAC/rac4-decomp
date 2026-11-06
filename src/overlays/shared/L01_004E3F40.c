#include "common.h"

extern void func_L01_004E4500(void);
extern void func_L01_004E4548(void);
void *D_002223C8[2] = {(void *)func_L01_004E4500, (void *)func_L01_004E4548};

s32 func_L01_004E3F40(s32 unused, s32 selector, u32 *out) {
    if (selector == 17) {
        *out = 12;
        return (u32)D_002223C8;
    }
    return 0;
}
