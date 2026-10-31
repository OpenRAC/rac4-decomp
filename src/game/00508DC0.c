#include "common.h"

extern s32 D_00220B60;

// If the object supports D_00220B60 (checked with the method at +0x14 of its +8
// table), store whether mask is set in its +0xC flags as a byte in out and
// return 1; otherwise return 0.
s32 func_00508DC0(void *handle, s32 mask, s8 *out) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B60) != 0) {
        *out = (*(u32 *)(object + 0xC) & mask) != 0;
        return 1;
    }
    return 0;
}
