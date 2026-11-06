#include "common.h"

extern s32 D_00221768;
extern s32 func_004A1A60(s32 *, s32), func_00504338(s32, f32);
extern f32 func_005044A8(s32);
void func_004B56F8(void)
{
    s32 handle = func_004A1A60(&D_00221768, 1);
    if (func_005044A8(handle) < 0.5f)
        func_00504338(handle, func_005044A8(handle) + 0.02f);
    handle = func_004A1A60(&D_00221768, 11);
    if (func_005044A8(handle) > 0.5f)
        func_00504338(handle, func_005044A8(handle) - 0.02f);
}
