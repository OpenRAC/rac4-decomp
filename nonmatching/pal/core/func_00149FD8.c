/* Not matching yet: PAL WIP; main core.text 0x00149FD8, 116B. Not part of the build. */
/*
 * Stored as all 25 actual differing/positionally shifted words in trials.jsonl, including the
 * final absent JR/store positions.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 56d4cc5aeafaa9bef296160b5636c72fb23ca3dbb96778982cc71f2227000361
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00149FD8 nonmatching/pal/core/func_00149FD8.c --diff
 */
#include "common.h"

/* Applies the selected coefficient pair to an input float pair. */
void func_00149FD8(void *arg0, void *arg1, s32 arg2, void *arg3) {
    f32 *input = (f32 *)arg0;
    f32 *coefficient = (f32 *)arg1 + arg2 * 2;
    f32 *out = (f32 *)arg3;
    f32 coefficient0 = coefficient[0];
    f32 coefficient1 = coefficient[1];
    f32 square_sum = coefficient0 * coefficient0 + coefficient1 * coefficient1;
    f32 first = input[0] * coefficient0 - input[1] * coefficient1;
    f32 scale = 1.0f / square_sum;

    out[0] = scale * first;
    out[1] = scale * (input[1] * coefficient[0] + input[0] * coefficient[1]);
}
