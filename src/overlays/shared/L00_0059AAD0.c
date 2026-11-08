#include "common.h"

extern void func_0059B0F0(void *, s32, s32, f32, f32, f32, f32);

/* from rac3-decomp's func_L01_003F2AF8 */
void func_L00_0059AAD0(void *a0, u8 *a1) {
    a1[29] = 0;
    if (*(f32 *)(a1 + 16) >= 0.0f) {
        func_0059B0F0(a0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
    }
}
