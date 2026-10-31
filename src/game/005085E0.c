#include "common.h"

/* If the object supports D_00220B50 (checked with the method at +0x14 of its +8 table), store the float at +0x1C into *arg1 and the float at +0x20 into *arg2 and return 1; otherwise return 0. */
extern s32 D_00220B50;
s32 func_005085E0(void *arg0, f32 *arg1, f32 *arg2) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B50) != 0) {
        *arg1 = *(f32 *)(object + 0x1C);
        *arg2 = *(f32 *)(object + 0x20);
        return 1;
    }
    return 0;
}
