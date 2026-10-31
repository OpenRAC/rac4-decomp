#include "common.h"

extern s32 func_00453CE8(void *);
extern void func_L01_005B0178(u8 *, f32, f32, f32);

// As func_L01_00493700 with the timer at +0x4C4, two more fields, and func_L01_005B0178(0, 1, 2)
// when the byte at +0x123 of the block is 6, else (0, 13, 24). Returns 1.
s32 func_L01_003D7348(u8 *arg0, s32 arg1) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x98) = 0;
        *(s32 *)(vars + 0x4C4) = 4;
        *(s32 *)(vars + 0x1E4) = 1;
        vars[0x2B1] = 0;
        *(s32 *)(vars + 0xF0) |= 0x80;
        break;
    case 1:
        if (func_00453CE8(vars + 0x4C4) != 0) {
            *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        }
        if (*(f32 *)(arg0 + 0x70) < *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24)) {
            *(f32 *)(arg0 + 0x70) += 0.006f;
        } else {
            *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24);
        }
        if (vars[0x123] == 6) {
            func_L01_005B0178(arg0, 0.0f, 1.0f, 2.0f);
        } else {
            func_L01_005B0178(arg0, 0.0f, 13.0f, 24.0f);
        }
        break;
    case 4:
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24);
        vars[0x2B1] = 1;
        *(f32 *)(vars + 0x1F4) = 1.0f;
        *(s32 *)(vars + 0xF4) |= 0x800;
        *(s32 *)(vars + 0xF0) &= ~0x80;
        *(s32 *)(vars + 0x13C) = 0;
        break;
    }
    return 1;
}
