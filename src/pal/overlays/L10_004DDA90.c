#include "common.h"
extern s32 func_L01_004DFA38(void *object);

f32 func_L10_004DDA90(void *object)
{
    s32 active = func_L01_004DFA38(object);
    f32 result = 1.0f;
    if (active == 0)
        result = 0.0f;
    return result;
}
