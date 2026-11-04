#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A13A0(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern char D_0030B358[];

/* Applies four values from the active record and clears its flag. */
void func_004C1068(void)
{
    s32 i = func_00505B20();
    char *p = D_0030B358 + i * 600;
    f32 x0, x1, x2, x3;
    func_004A13A0(p + 492, &x0, &x1, &x2, &x3);
    func_0049BFC0(i, 0, 0, x0, x1, x2, x3);
    *(s32 *)(p + 4) &= ~1;
}
