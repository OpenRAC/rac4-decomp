#include "common.h"

extern s32 func_00472590(s32, s32);
extern void func_004F2728(s32, s32);
extern s32 D_00355DA0[];

// Resets the record at D_00355DA0 for arg0 (90 at +0x4, func_00472590(26, 35) at +0x10, 1.0 at
// +0x14), runs func_004F2728(0, 0) and returns 1.
s32 func_0054B0E8(s32 arg0) {
    D_00355DA0[2] = arg0;
    D_00355DA0[0] = 0;
    D_00355DA0[1] = 0x5A;
    *(f32 *)&D_00355DA0[5] = 1.0f;
    D_00355DA0[3] = 0;
    D_00355DA0[4] = func_00472590(0x1A, 0x23);
    func_004F2728(0, 0);
    return 1;
}
