/* Not matching yet: PAL WIP; level_00 .text 0x0077FD30, 140B. Not part of the build. */
/*
 * Actual lower-bound LWC occurs before DIV and upper-bound LWC after DIV, differing from native.
 * Consumed FP return repaired but read/order remains nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a44ecbf5655070b80b95f1f244eb24dae69bfad42a43930c5e1d2b3de61f1a49
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_0077FD30 nonmatching/pal/l00_multiplayer_menu/func_L00_0077FD30.c --diff
 */
#include "common.h"

extern f32 func_L00_0077A8C0(f32 value, f32 lower, f32 upper);
extern f32 D_00173830[];

f32 func_L00_0077FD30(s32 first, s32 second, f32 firstValue, f32 secondValue)
{
    s32 difference = (s32)((u32)first - (u32)second);
    f32 ratio;
    f32 lower;
    f32 upper;

    if (difference != 0) {
        f32 delta = secondValue - firstValue;
        f32 sign = 1.0f;
        f32 adjusted;
        f32 baseline;

        if (difference < 0) {
            sign = -1.0f;
        }
        adjusted = delta * sign;
        baseline = D_00173830[0];
        upper = D_00173830[2];
        ratio = (adjusted + baseline) / baseline;
        lower = D_00173830[1];
    } else {
        f32 delta = secondValue - firstValue;
        f32 baseline = D_00173830[0];

        ratio = delta / baseline;
        lower = -1.0f;
        upper = 1.0f;
    }
    return func_L00_0077A8C0(ratio, lower, upper);
}
