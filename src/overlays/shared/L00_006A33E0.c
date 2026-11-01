#include "common.h"

extern s32 D_00220484;

// If the object supports D_00220484 (checked with the method at +0x14 of its +8
// table), set or clear the bits of mask in the +0xC flags according to enable
// and return 1; otherwise return 0.
s32 func_L00_006A33E0(void *handle, s32 mask, s32 enable) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220484) != 0) {
        if (enable != 0) {
            *(u32 *)(object + 0xC) |= mask;
        } else {
            *(u32 *)(object + 0xC) &= ~mask;
        }
        return 1;
    }
    return 0;
}
