/* Not matching yet: PAL WIP; main .text 0x0046C940, 112B. Not part of the build. */
/*
 * 0x0004 lw v0,0x40(a0) | lw v1,0x40(a0)
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 466140abb2ce8a884aaf82ee5c4f2823ff892cf9a223b58897d586436547bc46
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0046C940 nonmatching/pal/game/func_0046C940.c --diff
 */
#include "common.h"

/* Interpolate two signed halfwords at the observed table offset. */
f32 func_0046C940(void *arg0)
{
    f32 time;
    s32 index;
    s8 *base;
    s16 *pair;

    time = *(f32 *)((s8 *)arg0 + 0x44);
    index = (s32)time;
    base = *(s8 **)((s8 *)arg0 + 0x40) + 0x20;
    pair = (s16 *)(base + index * 4);
    return (f32)pair[1] * 0.0625f
        + (time - (f32)index) * (f32)pair[0] * 0.5f;
}
