#include "common.h"

/* If the object supports D_00220480 (checked with the method at +0x14 of its +8 table), call func_006A4548 with the object and the two arguments and return 1; otherwise return 0. */
extern void func_006A4548(void *arg0, s32 arg1, s32 arg2);
extern s32 D_00220480;
s32 func_L00_006A1D88(void *arg0, s32 arg1, s32 arg2) {
    u8 *object = arg0;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(arg0, D_00220480) != 0) {
        func_006A4548(arg0, arg1, arg2);
        return 1;
    }
    return 0;
}
