#include "common.h"

extern s32 func_0050EE98(void *arg0, f32 *arg1, f32 *arg2);
extern s32 D_00220B68;

/* If the object supports D_00220B68 (checked with the method at +0x14 of its +8 table), call func_0050EE98 with the object and arg1 and arg2 and return 1; otherwise return 0. */
s32 func_00509EC0(void *arg0, s32 arg1, s32 arg2) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(object, D_00220B68) != 0) {
        func_0050EE98(object, (f32 *)arg1, (f32 *)arg2);
        return 1;
    }
    return 0;
}
