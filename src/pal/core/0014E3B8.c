#include "common.h"
/* cflags: -fno-opt-stack */
typedef struct Ring Ring;
extern s32 D_0016F7D0[];
extern f32 D_001A2188[];
extern void func_0014A5E8(const Ring *ring, s32 position, s32 length, void *destination);
extern void func_0014A150(const f32 *input, const f32 *window, f32 *output, s32 count);
extern f32 func_00148648(const f32 *left, const f32 *right, s32 count);
extern void func_001478E8(const f32 *values, s32 count, s32 order, f32 *real, f32 *imaginary);
extern void func_00146E68(const f32 *values, s32 count, s32 order, f32 *real, f32 *imaginary);
extern f32 func_00148F20(const f32 *real, const f32 *imaginary, void *state);
f32 func_0014E3B8(const Ring *ring, void *state, f32 *energy_out)
{
    f32 work[291];
    f32 real[257];
    f32 imaginary[257];
    func_0014A5E8(ring, 145, 291, work);
    func_0014A150(work, D_001A2188, work, 291);
    *energy_out = func_00148648(work, work, 291) * (1.0f / 291.0f);
    if (D_0016F7D0[0] > 0)
        func_001478E8(work, 291, 9, real, imaginary);
    else
        func_00146E68(work, 291, 9, real, imaginary);
    return func_00148F20(real, imaginary, state);
}
