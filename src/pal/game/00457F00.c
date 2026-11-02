#include "common.h"

extern void func_00454B68(s32);
extern void func_00456690(f32, f32, void *, s32, void *, s32, u64);
extern s32 D_0021DF4C;
/* Draw using the temporary mode and restore the prior mode. */
void func_00457F00(void *a, s32 b, void *c, s32 d)
{
    s32 saved = D_0021DF4C;
    func_00454B68(0);
    func_00456690(1.0f, 1.0f, a, b, c, d, 0x80000000ULL);
    func_00454B68(saved);
}
