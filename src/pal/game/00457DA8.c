#include "common.h"
extern s32 D_0021DF4C;
extern void func_00454B68(s32);
extern void func_00455288(f32, f32, f32, f32, s32, void *, s32, s32, s32, u64, f32, f32);
void func_00457DA8(s32 x, s32 y, s32 a, void *b, s32 c)
{
    s32 old = D_0021DF4C;
    func_00454B68(0);
    func_00455288((f32)x, (f32)y, 1.0f, 1.0f, a, b, c, 0, 0, 0x80000000UL, 0.0f, 0.0f);
    func_00454B68(old);
}
