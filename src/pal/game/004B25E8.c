#include "common.h"

extern s32 D_00221828;
extern s32 D_00309754[];
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005056E0(s32, f32 *, f32 *);
extern s32 func_005055E8(s32, f32 *, f32 *);
extern s32 func_005052D0(s32, f32, f32);
extern s32 func_005061B0(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_005058D8(s32, f32, f32, f32, f32);

void func_004B25E8(void)
{
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 scale;

    func_005056E0(func_004A2798(&D_00221828, 3), &a, &b);
    scale = b * (f32)(D_00309754[0] - 1);
    func_005055E8(func_004A2798(&D_00221828, 0x1C), &c, &d);
    func_005052D0(func_004A2798(&D_00221828, 0x1C), c, d + scale);
    func_005061B0(func_004A2798(&D_00221828, 1), &x, &y, &z, &w);
    func_005058D8(func_004A2798(&D_00221828, 1), x, y, z, w + scale);
}
