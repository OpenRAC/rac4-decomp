#include "common.h"

extern f32 func_00453928(f32 angle);

f32 func_00473C78(f32 value)
{
    return (1.0f - func_00453928(value * 3.1415927410125732421875f)) * 0.5f;
}
