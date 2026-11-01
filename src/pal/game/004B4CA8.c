#include "common.h"

extern s32 func_0044B728(void *, f32);
extern s32 D_003097A8[];

void func_004B4CA8(void *object)
{
    if (func_0044B728(object, 0.05f)) {
        D_003097A8[0]++;
    }
}
