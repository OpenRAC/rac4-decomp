#include "common.h"
extern void func_00455288(f32, f32, f32, f32, u64, const char *, s32, s32, s32, u64, f32, f32);
extern s32 func_00454F98(const char *, s32, f32);
extern s32 D_0021DF4C;
extern void func_00454B68(s32);
s32 func_00457BA0(s32 x, s32 y, u64 a, const char *b, s32 c)
{
    s32 old = D_0021DF4C;
    s32 result;
    func_00454B68(0);
    func_00455288(x, y, 1.0f, 1.0f, a, b, c, 1, 0, 0x80000000UL, 0.0f, 0.0f);
    result = (s32)((u32)x - (u32)(func_00454F98(b, c, 1.0f) >> 1));
    func_00454B68(old);
    return result;
}
