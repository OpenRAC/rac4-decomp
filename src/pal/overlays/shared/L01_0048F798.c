/* cflags: -ffast-math -Wuninitialized */
#include "common.h"

static __inline__ float min_f32(float a, float b) { return a > b ? b : a; }
static __inline__ float max_f32(float a, float b) { return a < b ? b : a; }

/* Clear the first word and clamp the next two float components. */
void func_L01_0048F798(long a1, long a2, float *a3, unsigned int a4)
{
    float v4;

    *(u32 *)a4 = 0;
    v4 = *(float *)(a4 + 8);
    *(float *)(a4 + 4) = max_f32(min_f32(*(float *)(a4 + 4), a3[3]), a3[2]);
    *(float *)(a4 + 8) = max_f32(min_f32(v4, a3[5]), a3[4]);
}
