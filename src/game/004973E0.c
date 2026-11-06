#include "common.h"

extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);

void func_004973E0(f32 *value, s32 target)
{
    func_004757E0(value, (f32)target, 0.2f, 0.01f);
}
