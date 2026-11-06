#include "common.h"
extern void func_00454A70(f32, f32, f32, f32, u64, const char *, s32, s32, s32, u64, f32, f32);
extern s32 func_00454780(const char *, s32, f32);
extern s32 D_0021DEC4;
extern void func_00454350(s32);
s32 func_00457388(s32 x, s32 y, u64 a, const char *b, s32 c)
{
    s32 old = D_0021DEC4;
    s32 result;
    func_00454350(0);
    func_00454A70(x, y, 1.0f, 1.0f, a, b, c, 1, 0, 0x80000000UL, 0.0f, 0.0f);
    result = (s32)((u32)x - (u32)(func_00454780(b, c, 1.0f) >> 1));
    func_00454350(old);
    return result;
}
