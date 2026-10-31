#include "common.h"

extern s32 D_00220B50;

/* If the object's method at +0x14 of its +8 table accepts D_00220B50, store fparg0 at +0x10 and return 1; otherwise return 0. */
s32 func_00508648(u8 *arg0, f32 fparg0) {
    u8 *table = *(u8 **)(arg0 + 8);
    s32 (*method)(void *, s32, f32) = *(s32 (**)(void *, s32, f32))(table + 0x14);

    if (method(arg0, D_00220B50, fparg0) != 0) {
        *(f32 *)(arg0 + 0x10) = fparg0;
        return 1;
    }
    return 0;
}
