/* cflags: -O2 -G0 */
#include "common.h"

extern void func_00457130(void *, u64, void *, s32, s32, u64, void *, void *, f32);
/* Forwards arguments with a sign-extended short selector. */
void func_00457F98(void *a, u64 b, void *c, s32 d, s32 e, s32 f, s32 g, u64 h, void *i, void *j, f32 scale)
{
    func_00457130(a, b, c, d, (s16)g, h, i, j, scale);
}
