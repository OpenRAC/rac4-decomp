#include "common.h"

extern s32 func_00453CE8(void *);
extern void func_L01_005B0178(u8 *, f32, f32, f32);

// By arg1: 0 resets the object (+0x98, the timer at +0x4AC of its block, the byte at +0x2B1,
// bit 0x80 of +0xF0); 1 counts the timer down and raises +0x70 by 0.006 up to the value at
// +0x24 of its +0x24 object, then calls func_L01_005B0178(0, 27, 31); 4 sets everything up.
// Returns 1.
s32 func_L01_00493700(u8 *arg0, s32 arg1) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);

    switch (arg1) {
    case 0:
        *(s32 *)(arg0 + 0x98) = 0;
        *(s32 *)(vars + 0x4AC) = 4;
        vars[0x2B1] = 0;
        *(s32 *)(vars + 0xF0) |= 0x80;
        break;
    case 1:
        if (func_00453CE8(vars + 0x4AC) != 0) {
            *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        }
        if (*(f32 *)(arg0 + 0x70) < *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24)) {
            *(f32 *)(arg0 + 0x70) += 0.006f;
        } else {
            *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24);
        }
        func_L01_005B0178(arg0, 0.0f, 27.0f, 31.0f);
        break;
    case 4:
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
        *(f32 *)(arg0 + 0x70) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24);
        vars[0x2B1] = 1;
        *(s32 *)(vars + 0x13C) = 0;
        *(s32 *)(vars + 0xF4) |= 0x800;
        *(s32 *)(vars + 0xF0) &= ~0x80;
        break;
    }
    return 1;
}
