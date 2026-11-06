#include "common.h"

extern s32 D_0023F774[];
extern f32 D_0023FFF0[];
extern int D_00222B9C;

extern void func_00449A28(void *, void (*)(), s32);
extern f32 func_00454158(f32);
extern f32 func_00454140(f32);
extern void func_004481E8(void);
extern void func_L01_0052E0F0();

// Once the counter D_0023F774 reaches 0xA8D: registers func_L01_0052E0F0 with func_00449A28
// on D_00222B9C, stores func_00454158(0.225) / func_00454140(0.225) in D_0023FFF0 and calls
// func_004481E8.
void func_L01_005320C8(void) {
    f32 s;

    if (D_0023F774[0] >= 0xA8D) {
        func_00449A28(&D_00222B9C, func_L01_0052E0F0, 0);
        s = func_00454158(0.225f);
        D_0023FFF0[0] = s / func_00454140(0.225f);
        func_004481E8();
    }
}
