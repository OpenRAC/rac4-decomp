#include "common.h"

/* If the object supports D_00220B5C (checked with the method at +0x14 of its +8 table), call func_0050DC80 with the object and arg1, clear the halfword at +0x52, and return 1; otherwise return 0. */
extern void func_0050DC80(void *arg0, s32 arg1);
extern s32 D_00220B5C;

s32 func_0050A120(void *arg0, s32 arg1) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220B5C) != 0) {
        func_0050DC80(arg0, arg1);
        *(s16 *)(object + 0x52) = 0;
        return 1;
    }
    return 0;
}
