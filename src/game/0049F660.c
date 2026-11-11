#include "common.h"
typedef struct {
    char pad[0x14];
    f32 x, y, w, h;
    u8 active;
    char gap[7];
    s32 choice;
    char rest[0x1D0];
} State;
extern State D_00307254[];
extern void func_0049FBF0(s32), func_0049F758(s32, f32 *, f32 *, f32 *, f32 *), func_0049F828(s32, s32, f32 *, f32 *, f32 *, f32 *), func_0049CFE8(s32, s32, f32, f32, f32, f32), func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
void func_0049F660(s32 index, f32 x, f32 y, f32 w, f32 h)
{
    f32 c, d;
    State *p = D_00307254 + index;
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    if (p->active) {
        func_0049FBF0(index);
        func_0049F758(index, &x, &y, &c, &d);
        func_0049CFE8(index, 0, x, y, c, d);
        func_0049F828(index, p->choice, &x, &y, &c, &d);
        func_0049BFC0(index, 0, 0, x, y, c, d);
    }
}
