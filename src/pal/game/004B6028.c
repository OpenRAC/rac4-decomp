/* cflags: -ffast-math */
#include "common.h"
#include "pal/menu_state_00309940.h"

/* PAL reconstruction adapted from the retained 004B5138 attempt. */
extern s32 D_00221858;
extern s32 func_00454480(s32 color, s32 target, f32 blend);
extern f32 func_00475FF0(f32 value, f32 lower, f32 upper);
extern void func_00498818(s32 first, s32 second, s32 third, f32 value, f32 bias);
extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_005063C0(s32 handle, u32 value);

void func_004B6028(void)
{
    s32 color;
    color = func_00454480(D_00309940[0].color, 0x80FFFFFF, func_00475FF0((f32)D_00309940[0].f28, 15.0f, 30.0f));
    func_005063C0(func_004A2798(&D_00221858, 4), color);
    func_00498818(func_004A2798(&D_00221858, 3), func_004A2798(&D_00221858, 5), D_00309940[0].f34,
                  D_00309940[0].target < D_00309940[0].current ? D_00309940[0].target : D_00309940[0].current, 0.0f);
    func_00498818(func_004A2798(&D_00221858, 3), func_004A2798(&D_00221858, 4), D_00309940[0].f34,
                  D_00309940[0].target > D_00309940[0].current ? D_00309940[0].target : D_00309940[0].current, 0.0f);
}
