#include "common.h"

extern s32 func_0044B080(void *, f32);
extern s32 D_003096A8[];

void func_004B3DE0(void *object)
{
    if (func_0044B080(object, 0.05f)) {
        D_003096A8[0]++;
    }
}
