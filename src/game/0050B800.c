#include "common.h"

extern s32 D_00220B70;

/* If the object's table method at +0x14 accepts D_00220B70, store the float at +0x10 and return 1; otherwise return 0. */
s32 func_0050B800(void *handle, f32 value) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B70) != 0) {
        *(f32 *)(object + 0x10) = value;
        return 1;
    }
    return 0;
}
