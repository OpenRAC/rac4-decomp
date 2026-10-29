#include "common.h"

extern s32 func_00453D20(void *);
extern void func_L01_005B0178(u8 *, f32, f32, f32);

// As func_L01_00493700, with a 16-bit timer at +0x4A6, 0.85 times the value at +0x24 of the
// +0x24 object as the limit and func_L01_005B0178(0, 20, 32). Returns 1.
s32 func_L01_004C3A20(u8 *arg0, s32 arg1) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x98) = 0;
        *(s16 *)(vars + 0x4A6) = 4;
        vars[0x2B1] = 0;
        *(s32 *)(vars + 0xF0) |= 0x80;
        break;
    case 1:
        if (func_00453D20(vars + 0x4A6) != 0) {
            *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        }
        if (*(f32 *)(arg0 + 0x70) < *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24) * 0.85f) {
            *(f32 *)(arg0 + 0x70) += 0.006f;
        } else {
            *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24) * 0.85f;
        }
        func_L01_005B0178(arg0, 0.0f, 20.0f, 32.0f);
        break;
    case 4:
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24) * 0.85f;
        vars[0x2B1] = 1;
        *(s32 *)(vars + 0x13C) = 0;
        *(s32 *)(vars + 0xF4) |= 0x800;
        *(s32 *)(vars + 0xF0) &= ~0x80;
        break;
    }
    return 1;
}
