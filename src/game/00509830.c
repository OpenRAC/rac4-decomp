#include "common.h"

extern s32 D_00220B68;

/* If the object supports D_00220B68, store whether its +0xC flags hold any bit of mask in the byte at out and return 1; otherwise return 0. */
s32 func_00509830(void *handle, s32 mask, u8 *out) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B68) != 0) {
        *out = (*(u32 *)(object + 0xC) & mask) != 0;
        return 1;
    }
    return 0;
}
