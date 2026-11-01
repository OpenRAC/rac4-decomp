#include "common.h"

extern f32 func_00454140(f32 angle);

f32 func_00474558(f32 value)
{
    return (1.0f - func_00454140(value * 3.1415927410125732421875f)) * 0.5f;
}
