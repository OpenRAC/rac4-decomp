#include "common.h"

extern s32 func_L00_0071EDF0(void *, s32);
extern void func_L00_00710200(void *, s32);
extern u8 D_004BC998[];

s32 func_L00_00738EE8(void *arg0, s32 arg1)
{
    *(void **)((u8 *)arg0 + 88) = D_004BC998;
    func_L00_00710200((u8 *)arg0 + 608, 2);
    return func_L00_0071EDF0(arg0, arg1);
}
