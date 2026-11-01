#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004A20D8(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049CCF8(s32, s32, s32, f32, f32, f32, f32);
extern char D_0031A960[];

/* Applies four values from the active record and clears its flag. */
void func_004D19E8(void)
{
    s32 i = func_00506BB8();
    char *p = D_0031A960 + i * 420;
    f32 x0, x1, x2, x3;
    func_004A20D8(p + 312, &x0, &x1, &x2, &x3);
    func_0049CCF8(i, 0, 0, x0, x1, x2, x3);
    *(s32 *)(p + 8) &= ~4;
}
