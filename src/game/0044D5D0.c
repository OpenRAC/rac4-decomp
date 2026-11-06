#include "common.h"

typedef struct {
    u8 f0;
    u8 f1[0x0F];
    s32 f10;
    u8 f14[0x2C];
    s64 f40;
} Type1;

extern Type1 D_00239540;
extern s32 func_0045EB60(s32, s32);
extern s64 func_0045EC28(s32);
extern void func_004E7990(s32, s64, s32);

/* Refresh the cached value and report whether it changed. */
void func_0044D5D0(s32 arg0, s32 arg1, s32 arg2)
{
    s64 result;
    if (D_00239540.f0 == 0) {
        result = func_0045EC28(func_0045EB60(arg1, arg2));
        func_004E7990(6, result, 0);
        return;
    }
    result = func_0045EC28(func_0045EB60(arg1, arg2));
    if (D_00239540.f40 != result) {
        D_00239540.f40 = result;
        func_004E7990(6, result, 1);
        D_00239540.f10 = 0x7C;
    }
}
