#include "common.h"

extern void func_00454350(s32);
extern void func_00455E78(f32, f32, void *, s32, void *, s32, u64);
extern s32 D_0021DEC4;
/* Draw using the temporary mode and restore the prior mode. */
void func_004576E8(void *a, s32 b, void *c, s32 d)
{
    s32 saved = D_0021DEC4;
    func_00454350(0);
    func_00455E78(1.0f, 1.0f, a, b, c, d, 0x80000000ULL);
    func_00454350(saved);
}
