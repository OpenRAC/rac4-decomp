#include "common.h"
extern s32 D_0021DEC4;
extern void func_00454350(s32);
extern void func_00454A70(f32, f32, f32, f32, s32, void *, s32, s32, s32, u64, f32, f32);
void func_00457590(s32 x, s32 y, s32 a, void *b, s32 c)
{
    s32 old = D_0021DEC4;
    func_00454350(0);
    func_00454A70((f32)x, (f32)y, 1.0f, 1.0f, a, b, c, 0, 0, 0x80000000UL, 0.0f, 0.0f);
    func_00454350(old);
}
