#include "common.h"

extern s32 D_00221868;
extern s32 func_004A2798(s32 *, s32), func_005053D0(s32, f32);
extern f32 func_00505540(s32);
void func_004B65E8(void)
{
    s32 handle = func_004A2798(&D_00221868, 1);
    if (func_00505540(handle) < 0.5f)
        func_005053D0(handle, func_00505540(handle) + 0.02f);
    handle = func_004A2798(&D_00221868, 11);
    if (func_00505540(handle) > 0.5f)
        func_005053D0(handle, func_00505540(handle) - 0.02f);
}
