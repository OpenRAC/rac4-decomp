#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004A20D8(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049CCF8(s32, s32, s32, f32, f32, f32, f32);
extern char D_0031B050[];
/* Refresh the current entry rectangle and clear its pending bit. */
void func_004D2C08(void)
{
    f32 a, b, c, d;
    s32 i = func_00506BB8();
    char *p = D_0031B050 + i * 0x15c;
    func_004A20D8(p + 0xf0, &a, &b, &c, &d);
    func_0049CCF8(i, 0, 0, a, b, c, d);
    *(s32 *)(p + 8) &= ~4;
}
