#include "common.h"

extern f32 func_004760C0(f32 *value, f32 target, f32 fraction, f32 minimum);

void func_00498038(f32 *value, s32 target)
{
    func_004760C0(value, (f32)target, 0.2f, 0.01f);
}
