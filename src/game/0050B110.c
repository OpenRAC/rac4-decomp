#include "common.h"

extern s32 D_00220B6C;

// If the object's method at +0x14 of its +8 table accepts D_00220B6C, store the value at +0x34 and return 1; otherwise return 0.
s32 func_0050B110(void *handle, s32 value) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B6C) != 0) {
        *(s32 *)(object + 0x34) = value;
        return 1;
    }
    return 0;
}
