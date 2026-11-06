/* cflags: -fno-opt-stack */
#include "common.h"
extern const f32 D_001A0218[];
extern f32 func_001484E8(const s32 *steps, s32 unused, const f32 *samples,
                         f32 frequency, s32 length, f32 gain);
f32 func_0014C168(s32 index, const s32 *steps, s32 unused, const f32 *samples, s32 length, f32 gain, f32 *score)
{
    f32 candidates[2];
    f32 best = *(const f32 *)((u32)D_001A0218 + ((u32)index << 2));
    s32 count = 0;
    s32 i;
    if (index > 0) {
        f32 previous = *(const f32 *)((u32)D_001A0218 + (((u32)index - 1u) << 2));
        candidates[count++] = (best + previous) * 0.5f;
    }
    index = (s32)((u32)index + 1u);
    if (index < 74) {
        f32 next = *(const f32 *)((u32)D_001A0218 + ((u32)index << 2));
        candidates[count++] = (best + next) * 0.5f;
    }
    for (i = 0; i < count; i++) {
        f32 frequency = candidates[i];
        f32 value = func_001484E8(steps, unused, samples, frequency, length, gain);
        if (*score < value) {
            *score = value;
            best = frequency;
        }
    }
    return best;
}
