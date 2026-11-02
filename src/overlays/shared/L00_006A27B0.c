#include "common.h"

extern s32 D_00220474;

// If the object supports D_00220474 (checked with the method at +0x14 of its +8
// table), store the 2-bit fields at bits 9-10 and 11-12 of its +0xC flags in
// the two out words and return 1; otherwise return 0.
s32 func_L00_006A27B0(void *handle, s32 *out_a, s32 *out_b) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220474) != 0) {
        *out_a = (*(u32 *)(object + 0xC) >> 9) & 3;
        *out_b = (*(u32 *)(object + 0xC) >> 11) & 3;
        return 1;
    }
    return 0;
}
