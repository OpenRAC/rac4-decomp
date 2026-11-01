#include "common.h"

extern s32 D_00220480;
s32 func_006A7320(void *, f32);

// If the object supports D_00220480 (checked with the method at +0x14 of its +8
// table), run func_006A7320 with the value and return 1; otherwise return 0.
s32 func_L00_006A2150(void *handle, f32 value) {
    u8 *object = handle;
    u8 *vtable = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(vtable + 0x14);
    if (method(handle, D_00220480) == 0) goto fail;
    func_006A7320(handle, value);
    return 1;
fail:
    return 0;
}
