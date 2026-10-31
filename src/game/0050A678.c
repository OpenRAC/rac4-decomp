#include "common.h"

extern s32 D_00220B5C;

// If the object supports D_00220B5C (checked with the method at +0x14 of its +8
// table), copy the float at +0x10 to the out pointer and return 1; otherwise
// return 0.
s32 func_0050A678(void *arg0, f32 *arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B5C) != 0) {
        *arg1 = *(f32 *)(object + 0x10);
        return 1;
    }
    return 0;
}
