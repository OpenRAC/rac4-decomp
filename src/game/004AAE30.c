#include "common.h"

extern s32 func_00496B88(s32);
extern s32 func_00497810(s32);
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern s32 func_00504740(s32 handle, f32 *a, f32 *b);
extern s32 func_00504F68(s32, s32);
extern s32 func_00505238(s32, s32);
extern s32 func_005058E0(s32 id, f32 a, f32 b);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);

extern f32 D_003D19B8[];
typedef struct {
    f32 x, y;
} Type1;
extern Type1 D_003D9278[];

void func_004AAE30(s32 arg0, s32 arg1)
{
    f32 v[2];
    s32 saved;
    s32 idx;

    saved = func_00505B20();
    func_00505AD8(arg0);
    idx = func_00496B88(arg0);
    func_00504F68(0x7000C, 1);
    func_00505238(0x7000C, 0);
    func_00505238(0x7000C, arg1);
    func_00504740(0x7000C, &v[0], &v[1]);
    func_005058E0(0x7000C, D_003D19B8[func_00497810(arg0)], v[1]);
    func_00504238(0x7000C, D_003D9278[idx].x, D_003D9278[idx].y - v[1] * 0.5f);
    func_00505AD8(saved);
}
