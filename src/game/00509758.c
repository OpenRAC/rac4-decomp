#include "common.h"

extern s32 D_00220B68;
extern void func_0050F030(void *, s32, s32);

// If the object supports D_00220B68 (checked with the method at +0x14 of its +8
// table), pass the object and the two arguments on to func_0050F030 and return 1;
// otherwise return 0.
s32 func_00509758(void *handle, s32 arg_a, s32 arg_b) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B68) != 0) {
        func_0050F030(handle, arg_a, arg_b);
        return 1;
    }
    return 0;
}
