#include "common.h"

extern s32 func_L00_0071AF88(void *, s32);
extern void func_L00_0070C3E0(void *, s32);
extern u8 D_004BBD20[];

s32 func_L00_0072BD20(void *arg0, s32 arg1)
{
    *(void **)((u8 *)arg0 + 88) = D_004BBD20;
    func_L00_0070C3E0((u8 *)arg0 + 676, 2);
    return func_L00_0071AF88(arg0, arg1);
}
