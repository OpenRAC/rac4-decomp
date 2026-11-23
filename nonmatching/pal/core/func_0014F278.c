/* Not matching yet: PAL WIP; main core.text 0x0014F278, 252B. Not part of the build. */
/*
 * Initial pointer copies and sum MOV schedule differ: actual preguard t2/t0 captures versus native
 * postguard setup; actual BC1F+28 versus native+20 with relocated same operations. No memory
 * dereference added to earlyexit.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 3533b6f47bcb679b3bfccb353c79c1545b56ed91c60f0683b854b77040a02c9f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0014F278 nonmatching/pal/core/func_0014F278.c --diff
 */
#include "common.h"

void func_0014F278(f32 *input, s16 offset, s16 prefix, f32 *output, f32 scale)
{
    f32 inputSum = 0.0f;
    f32 outputSum = 0.0f;
    f32 *inputCursor = input;
    f32 *outputCursor = output;
    f32 correction;
    s32 i;

    if (scale == 1.0f && offset == 0 && prefix == 0) {
        return;
    }
    for (i = 0; i < 65; i++) {
        if (i < prefix) {
            *outputCursor = *inputCursor;
        } else {
            s32 mapped = (s32)((u32)(s32)((f32)i * scale) + (u32)(s32)offset);
            f32 *sampled = input + mapped;

            *outputCursor = *sampled;
            if (mapped < 65) {
                *outputCursor = *sampled;
            } else {
                *outputCursor = input[64];
            }
        }
        {
            f32 currentInput = *inputCursor;
            f32 currentOutput = *outputCursor;

            inputSum += currentInput;
            outputSum += currentOutput;
        }
        inputCursor++;
        outputCursor++;
    }
    correction = (inputSum - outputSum) / 65.0f;
    for (i = 64; i >= 0; i--) {
        f32 value = *output;

        output++;
        *input = value + correction;
        input++;
    }
}
