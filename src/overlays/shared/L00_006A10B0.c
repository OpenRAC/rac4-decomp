#include "common.h"

extern s32 D_00220478;

// If the object supports D_00220478 (checked with the method at +0x14 of its +8
// table), store the two floats at +0x1C and +0x20 and return 1; otherwise
// return 0.
s32 func_L00_006A10B0(void *arg0, f32 fparg0, f32 fparg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32, f32, f32) = *(s32 (**)(void *, s32, f32, f32))(table + 0x14);
    if (method(arg0, D_00220478, fparg0, fparg1) != 0) {
        *(f32 *)(object + 0x1C) = fparg0;
        *(f32 *)(object + 0x20) = fparg1;
        return 1;
    }
    return 0;
}
