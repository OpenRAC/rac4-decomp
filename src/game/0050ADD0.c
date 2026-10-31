#include "common.h"

extern s32 D_00220B6C;

// If the object supports D_00220B6C (checked with the method at +0x14 of its +8
// table), store arg2 at +0x4C and arg1 at +0x50 and return 1; otherwise return 0.
s32 func_0050ADD0(void *handle, s32 arg1, s32 arg2) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B6C) != 0) {
        *(s32 *)(object + 0x50) = arg1;
        *(s32 *)(object + 0x4C) = arg2;
        return 1;
    }
    return 0;
}
