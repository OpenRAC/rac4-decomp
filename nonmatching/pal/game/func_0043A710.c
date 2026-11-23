/* Not matching yet: PAL WIP; main .text 0x0043A710, 196B. Not part of the build. */
/*
 * Duration1/2 region: native BNEL nonzero with LWC438 delay then zero-duration stores/forward
 * branch; candidate BEQL zero with SWC434 delay, nonzero conversion region first and later
 * SB448=0. Native capture occurs before MTC/CVT; candidate after CVT/constants.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d26d317591a1da32153a4d34150a6ab88b9a2e5bf698d38332205af67c54a00b
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0043A710 nonmatching/pal/game/func_0043A710.c --diff
 */
#include "common.h"

typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x470 - 0x54]; } S_0043A9D0;
extern S_0043A9D0 D_00229D80[];

void func_0043A710(s32 recordIndex, s32 duration, s32 selector,
                   f32 x, f32 y, f32 z, f32 w)
{
    u8 *record = (u8 *)D_00229D80 + (u32)recordIndex * 0x470U;

    switch (selector) {
    case 0:
        *(f32 *)(record + 0x434) = x;
        record[0x449] = 1;
        record[0x448] = 0;
        return;
    case 1:
    case 2:
        if (duration != 0) {
            f32 previous = *(f32 *)(record + 0x438);
            f32 reciprocal;
            record[0x448] = (u8)selector;
            reciprocal = 1.0f / (f32)duration;
            *(f32 *)(record + 0x450) = previous;
            *(s16 *)(record + 0x44A) = (s16)duration;
            *(f32 *)(record + 0x44C) = reciprocal;
        } else {
            *(f32 *)(record + 0x434) = x;
            record[0x448] = 0;
        }
        record[0x449] = 1;
        return;
    case 3:
        *(f32 *)(record + 0x444) = w;
        record[0x448] = (u8)selector;
        *(f32 *)(record + 0x434) = x;
        record[0x449] = 1;
        *(f32 *)(record + 0x43C) = y;
        *(f32 *)(record + 0x440) = z;
        return;
    default:
        return;
    }
}
