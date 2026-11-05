#include "common.h"
extern f32 func_00498580(f32, f32, f32, f32);
extern void func_00453C68(s32, s32, f32);
void func_00498670(f32 *value, s32 arg1, s32 arg2, f32 delta) {
    f32 x = *value + delta;
    *value = x;
    x = func_00498580(x, 0.5f, 0.2f, 0.3f);
    func_00453C68(arg1, arg2, x);
}
