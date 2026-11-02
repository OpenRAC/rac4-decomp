#include "common.h"

extern void func_006A73B0(void *, s32, f32, f32);
extern s32 D_00220480;

// If the object supports D_00220480 (checked with the method at +0x14 of its +8
// table), run func_006A73B0 with 1 and the two values and return 1; otherwise
// return 0.
s32 func_L00_006A22E8(void *handle, f32 value, f32 value2) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220480) != 0) {
        func_006A73B0(handle, 1, value, value2);
        return 1;
    }
    return 0;
}
