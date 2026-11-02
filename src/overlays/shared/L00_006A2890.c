#include "common.h"

extern s32 D_00220474;

// If the object's method at +0x14 of its +8 table accepts D_00220474, store arg1 at +0x34 and return 1; otherwise return 0.
s32 func_L00_006A2890(void *arg0, s32 arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220474) != 0) {
        *(s32 *)(object + 0x34) = arg1;
        return 1;
    }
    return 0;
}
