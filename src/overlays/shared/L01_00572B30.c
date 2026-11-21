#include "common.h"

extern s32 func_L01_00572BE8(void *a, s32 b, f32 x, f32 y, f32 z, f32 w);
extern s32 func_L01_00572EC8(void *a, s32 b, f32 x, f32 y, f32 z, f32 w, f32 v, f32 u);

/* Dispatches on the shape kind of arg0 to the matching test against arg1. */
s32 func_L01_00572B30(u8 *arg0, u8 *arg1, f32 arg3, s32 arg2) {
    if (arg0 == 0) {
        return 1;
    }
    if ((u8)(arg0[0x1C] - 1) >= 3) {
        return 1;
    }
    if (arg1 == 0) {
        return 1;
    }
    if (arg1[0x11] >= 7) {
        return 1;
    }
    switch (arg0[0x1C]) {
    case 1:
        return func_L01_00572BE8(arg1, arg2, *(f32 *)(arg0 + 0), *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8), arg3);
    case 3:
        return func_L01_00572EC8(arg1, arg2, *(f32 *)(arg0 + 0), *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), arg3);
    }
    return 0;
}
