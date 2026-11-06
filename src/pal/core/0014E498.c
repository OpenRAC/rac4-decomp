#include "common.h"
/* cflags: -fno-opt-stack */
typedef struct Ring Ring;
extern s32 D_0016F7D0[];
extern s32 func_0014D0E0(f32 frequency);
extern s32 func_00148A78(void *state, const Ring *ring, s32 position, s32 length, f32 *work);
extern void func_0014A5E8(const Ring *ring, s32 position, s32 length, void *destination);
extern void func_00147D50(const f32 *input, s32 count, f32 *output, f32 scale);
extern void func_0014A1D8(f32 *values, s32 count);
extern void func_001478E8(const f32 *values, s32 count, s32 order, f32 *real, f32 *imaginary);
extern void func_00146E68(const f32 *values, s32 count, s32 order, f32 *real, f32 *imaginary);
void func_0014E498(void *state, const Ring *ring, f32 *real, f32 *imaginary, s32 *length_out, s32 *offset_out, f32 frequency)
{
    f32 work[261];
    s32 length = func_0014D0E0(frequency);
    s32 offset = func_00148A78(state, ring, 145, length, work);
    *offset_out = offset;
    func_0014A5E8(ring, offset + 145, length, work);
    func_00147D50(work, length, work, 2.0f);
    func_0014A1D8(work, length);
    if (D_0016F7D0[0] > 0)
        func_001478E8(work, length, 9, real, imaginary);
    else
        func_00146E68(work, length, 9, real, imaginary);
    *length_out = length;
}
