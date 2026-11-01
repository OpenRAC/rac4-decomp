#include "common.h"

extern void func_00455288(f32, f32, f32, f32, s32, void *, s32, s32, s32, u64, f32, f32);
/* Forward integer coordinates as floats with default rendering fields. */
void func_00457C90(s32 x, s32 y, s32 a, void *b, s32 c, f32 scale)
{
    func_00455288((f32)x, (f32)y, scale, scale, a, b, c, 1, 0, 0x80000000ULL, 0.0f, 0.0f);
}
