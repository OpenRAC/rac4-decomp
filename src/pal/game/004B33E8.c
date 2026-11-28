#include "common.h"

#include "pal/menu_flow.h"

extern s32 D_00221848;
extern f32 func_004760C0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_004985F0(s32 sound);
extern s32 func_004A2798(s32 *group, s32 id);
extern s32 func_005052D0(s32 handle, f32 x, f32 y);
extern s32 func_005055E8(s32 handle, f32 *x, f32 *y);

/* Move item 7 to its target and start the 60-tick hold. */
void func_004B33E8(void)
{
    f32 x;
    f32 y;

    if (D_003097A8.started == 0) {
        D_003097A8.started = 1;
        func_004985F0(0x2A);
    }
    func_005055E8(func_004A2798(&D_00221848, 7), &x, &y);
    if (func_004760C0(&x, 0.5f, 0.3f, 0.01f) != 0.0f) {
        func_005052D0(func_004A2798(&D_00221848, 7), x, y);
        return;
    }
    func_004985F0(0x36);
    D_003097A8.timer = 0x3C;
    D_003097A8.started = 0;
    D_003097A8.state++;
}

/* Skip the hidden panel or move item 15 into position for the 20-tick hold. */
void func_004B39A0(void)
{
    f32 x;
    f32 y;

    if (D_003097A8.entryCount == 0) {
        D_003097A8.started = 0;
        D_003097A8.state++;
        return;
    }
    if (D_003097A8.started == 0) {
        D_003097A8.started = 1;
        func_004985F0(0x2E);
    }
    func_005055E8(func_004A2798(&D_00221848, 0xF), &x, &y);
    if (func_004760C0(&x, 0.5f, 0.3f, 0.01f) != 0.0f) {
        func_005052D0(func_004A2798(&D_00221848, 0xF), x, y);
        return;
    }
    D_003097A8.timer = 0x14;
    D_003097A8.started = 0;
    D_003097A8.state++;
}
