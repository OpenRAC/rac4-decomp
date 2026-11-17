#include "common.h"

typedef struct Detector Detector;

/* Evaluates the selected polynomial and records its ordered threshold test. */
s32 func_0014D9E0(Detector *state, f32 threshold)
{
    f32 input = *(f32 *)state;
    f32 value;
    s32 result;

    if (input > 160000.0f) {
        value = (((input * -9.043945e-8f) + 3.535748f) * input) + 62071.0f;
    } else {
        value = (((input * -0.000005544613f) + 4.047152f) * input) + 362.0f;
    }
    *(f32 *)((u8 *)state + 4) = value;
    result = value < threshold;
    *(s8 *)((u8 *)state + 0x13) = result;
    return result;
}
