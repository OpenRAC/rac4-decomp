#include "common.h"
typedef struct {
    char pad[0x14];
    f32 x, y, w, h;
    u8 active;
    char gap[7];
    s32 choice;
    char rest[0x1D0];
} State;
extern State D_00307354[];
extern void func_004A0928(s32), func_004A0490(s32, f32 *, f32 *, f32 *, f32 *), func_004A0560(s32, s32, f32 *, f32 *, f32 *, f32 *), func_0049DD20(s32, s32, f32, f32, f32, f32), func_0049CCF8(s32, s32, s32, f32, f32, f32, f32);
void func_004A0398(s32 index, f32 x, f32 y, f32 w, f32 h)
{
    f32 c, d;
    State *p = D_00307354 + index;
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    if (p->active) {
        func_004A0928(index);
        func_004A0490(index, &x, &y, &c, &d);
        func_0049DD20(index, 0, x, y, c, d);
        func_004A0560(index, p->choice, &x, &y, &c, &d);
        func_0049CCF8(index, 0, 0, x, y, c, d);
    }
}
