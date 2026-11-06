#include "common.h"

extern s32 func_00505B20(void);
extern void func_004A13A0(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern char D_0031B050[];
/* Refresh the current entry rectangle and clear its pending bit. */
void func_004D1CF8(void)
{
    f32 a, b, c, d;
    s32 i = func_00505B20();
    char *p = D_0031B050 + i * 0x15c;
    func_004A13A0(p + 0xf0, &a, &b, &c, &d);
    func_0049BFC0(i, 0, 0, a, b, c, d);
    *(s32 *)(p + 8) &= ~4;
}
