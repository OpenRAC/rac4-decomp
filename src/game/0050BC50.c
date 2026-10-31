#include "common.h"

extern s32 D_00220B54;

// If the object supports D_00220B54 (checked with the method at +0x14 of its +8
// table), store bits 9-10 and 11-12 of the word at +0xC to *x and *y and return 1;
// otherwise return 0.
s32 func_0050BC50(void *handle, s32 *x, s32 *y) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B54) != 0) {
        *x = ((u32)*(u32 *)(object + 0xC) >> 9) & 3;
        *y = ((u32)*(u32 *)(object + 0xC) >> 11) & 3;
        return 1;
    }
    return 0;
}
