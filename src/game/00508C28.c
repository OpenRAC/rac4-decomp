#include "common.h"

extern s32 D_00220B60;

// If the object supports D_00220B60 (checked with the method at +0x14 of its +8
// table), store its two floats at +0x1C and +0x20 in the out words and return 1;
// otherwise return 0.
s32 func_00508C28(void *handle, f32 *out_a, f32 *out_b) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B60) != 0) {
        *out_a = *(f32 *)(object + 0x1C);
        *out_b = *(f32 *)(object + 0x20);
        return 1;
    }
    return 0;
}
