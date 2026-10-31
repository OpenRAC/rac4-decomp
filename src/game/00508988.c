#include "common.h"

extern s32 D_00220B50;

/* If the object supports D_00220B50 (checked with the method at +0x14 of its +8 table), store arg1 at +0x2C and return 1; otherwise return 0. */
s32 func_00508988(void *arg0, f32 fparg0) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B50) != 0) {
        *(f32 *)(object + 0x2C) = fparg0;
        return 1;
    }
    return 0;
}
