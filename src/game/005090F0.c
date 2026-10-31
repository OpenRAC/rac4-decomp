#include "common.h"

extern s32 D_00220B60;

// If the object's method at +0x14 of its +8 table accepts D_00220B60, store arg1 at +0x34 and return 1; otherwise return 0.
s32 func_005090F0(void *arg0, s32 arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B60) != 0) {
        *(s32 *)(object + 0x34) = arg1;
        return 1;
    }
    return 0;
}
