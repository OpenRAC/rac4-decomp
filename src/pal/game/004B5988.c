#include "common.h"

extern s32 D_00221848;
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005052D0(s32, f32, f32);

/* Position the five resources used by this menu. */
void func_004B5988(void)
{
    func_005052D0(func_004A2798(&D_00221848, 1), 0.5f, 0.7f);
    func_005052D0(func_004A2798(&D_00221848, 7), -0.5f, 0.15f);
    func_005052D0(func_004A2798(&D_00221848, 15), 1.35f, 0.5f);
    func_005052D0(func_004A2798(&D_00221848, 46), -0.25f, 0.5f);
    func_005052D0(func_004A2798(&D_00221848, 54), 1.25f, 0.5f);
}
