#include "common.h"
extern void func_00455288(f32, f32, f32, f32, s32, const void *, s32, s32, s32, u64, f32, f32);
extern s32 func_00454F98(const char *, s32, f32);
s32 func_00457AF8(s32 x, s32 y, s32 a, const char *b, s32 c)
{
    func_00455288(x, y, 1.0f, 1.0f, a, b, c, 1, 0, 0x80000000UL, 0.0f, 0.0f);
    return (s32)((u32)x - (u32)(func_00454F98(b, c, 1.0f) >> 1));
}
