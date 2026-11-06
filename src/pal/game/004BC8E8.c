#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004A20D8(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049CCF8(s32, s32, s32, f32, f32, f32, f32);
extern char D_0030A6F0[];

/* Refresh the current rectangle and clear its pending update bit. */
void func_004BC8E8(void)
{
    f32 a, b, c, d;
    s32 index = func_00506BB8();
    char *p = D_0030A6F0 + index * 0x534;
    func_004A20D8(p + 0x4C8, &a, &b, &c, &d);
    func_0049CCF8(index, 0, 0, a, b, c, d);
    *(s32 *)(p + 4) &= ~4;
}
