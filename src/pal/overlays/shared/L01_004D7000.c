#include "common.h"

extern f32 func_00454370(f32, f32);
extern void func_L01_0059F8F8(u8 *, u8 *, s32, f32, f32);

// Stores func_00454370 of the floats at arg1+0x300 and arg0+0xF8 in arg1+0x1D8, then runs
// func_L01_0059F8F8 on arg1+0x170 and +0x1F0 and, when arg1+0x348 is set, on +0x270 after
// storing 0.35 times arg1+0x304 at +0x2D0.
void func_L01_004D7000(u8 *arg0, u8 *arg1) {
    *(f32 *)(arg1 + 0x1D8) = func_00454370(*(f32 *)(arg1 + 0x300), *(f32 *)(arg0 + 0xF8));
    func_L01_0059F8F8(arg0, arg1 + 0x170, 0, 0.0432f, 0.43200004f);
    *(f32 *)(arg1 + 0x250) = *(f32 *)(arg1 + 0x304);
    func_L01_0059F8F8(arg0, arg1 + 0x1F0, 2, 0.014400001f, 0.28800002f);
    if (*(s32 *)(arg1 + 0x348) != 0) {
        *(f32 *)(arg1 + 0x2D0) = *(f32 *)(arg1 + 0x304) * 0.35f;
        func_L01_0059F8F8(arg0, arg1 + 0x270, 3, 0.014400001f, 0.28800002f);
    }
}
