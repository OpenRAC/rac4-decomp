#include "common.h"
extern s32 func_00505B20(void);
extern void func_004A13A0(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern char D_00316D00[];

/* Applies four values from the active record and clears flag four. */
void func_004CFA40(void)
{
    s32 i = func_00505B20();
    char *p = D_00316D00 + i * 2528;
    f32 x0, x1, x2, x3;
    func_004A13A0(p + 2420, &x0, &x1, &x2, &x3);
    func_0049BFC0(i, 0, 0, x0, x1, x2, x3);
    *(s32 *)(p + 8) &= ~4;
}
