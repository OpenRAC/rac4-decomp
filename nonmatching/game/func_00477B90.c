/* Not matching yet: SIZE ours 144 / retail 136 (tools/try_func.py func_00477B90 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
} S4;

extern f32 func_004725D8(f32, f32);

S4 func_00477B90(f32 x)
{
    f32 nx = -x;
    S4 r;

    r.f0 = 0.0f;
    r.f1 = func_004725D8(nx, x);
    r.f2 = func_004725D8(nx, x);
    r.f3 = func_004725D8(nx, x);
    return r;
}
