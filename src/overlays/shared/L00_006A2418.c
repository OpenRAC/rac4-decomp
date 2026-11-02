#include "common.h"

extern void func_006A7510(void *, s32);
extern s32 D_00220480;

// If the object supports D_00220480 (checked with the method at +0x14 of its +8 table), call func_006A7510 with the object and arg1 and return 1; otherwise return 0.
s32 func_L00_006A2418(void *arg0, s32 arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(object, D_00220480) != 0) {
        func_006A7510(object, arg1);
        return 1;
    }
    return 0;
}
