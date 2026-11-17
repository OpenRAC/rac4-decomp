#include "common.h"

extern s32 func_00497810(u32 index);
extern s32 func_00504740(s32 handle, float *a, float *b);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505238(s32 handle, u32 value);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern f32 D_003D19B8[];

/* Sets up handle 0x7000B with arg1 and passes the D_003D19B8 entry chosen by arg0 to func_005058E0. */
void func_004AAF40(s32 arg0, s32 arg1)
{
    f32 v[2];
    s32 saved;

    saved = func_00505B20();
    func_00505AD8(arg0);
    func_00504F68(0x7000B, 1);
    func_00505238(0x7000B, 0);
    func_00505238(0x7000B, arg1);
    func_00504740(0x7000B, &v[0], &v[1]);
    func_005058E0(0x7000B, D_003D19B8[func_00497810(arg0)], v[1]);
    func_00505AD8(saved);
}
