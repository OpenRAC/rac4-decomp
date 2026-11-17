/* cflags: -ffast-math -Wuninitialized */
#include "common.h"

extern f32 func_00454170(f32);

static __inline__ f32 min_f32(f32 a, f32 b) { return a > b ? b : a; }
static __inline__ f32 max_f32(f32 a, f32 b) { return a < b ? b : a; }

f32 func_L00_00590698(f32 numerator, f32 denominator)
{
    f32 ratio = numerator / denominator;
    return func_00454170(max_f32(min_f32(ratio, 1.0f), -1.0f));
}
