#include "common.h"

/* Match the separate half-value lifetimes observed in the two retail arms. */
extern f32 func_001364F0(f32);
static inline f32 clamp_low(f32 x) { return x > 8.0f ? x : 8.0f; }
static inline f32 clamp_high(f32 x) { return x > 160.0f ? 160.0f : x; }
static inline f32 round_offset(f32 x) {
    f32 offset;
    if (x > 0.0f) {
        offset = 0.5f;
        offset = x + offset;
    } else {
        offset = 0.5f;
        offset = x - offset;
    }
    return offset;
}
s32 func_0014C2B8(f32 x) {
    x = clamp_low(x);
    x = clamp_high(x);
    return (s32)round_offset((5.075174f - func_001364F0(x)) * 85.12109f);
}
