/* Not matching yet: PAL WIP; main net.text 0x01EA8AC8, 172B. Not part of the build. */
/*
 * Same non-NOP words, register choices and normalized actual branch destinations. Differences are
 * NOP positions and consequent branch displacements/offsets only: four mtc1-to-CVT padding NOPs,
 * one mtc1-to-DIV NOP, one compare-gap NOP in emitted text; native has two unreachable
 * conversion-gap NOP words and four DIV spacing NOPs instead. No source graph forcing or padding
 * proposed.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 54af4f9bb4f20fdd8ff660db4f446eb00ca0700b8c3af9976c0b87c38f9d24cc
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EA8AC8 nonmatching/pal/net/func_01EA8AC8.c --diff
 */
#include "common.h"

void func_01EA8AC8(void *record, u32 duration)
{
    u8 *bytes = record;

    if (duration != 0) {
        f32 counter = (f32)*(u32 *)(bytes + 0);
        f32 elapsed = (f32)duration;
        *(f32 *)(bytes + 4) = counter / (elapsed / 1000.0f);
    } else {
        *(f32 *)(bytes + 4) = 0.0f;
    }

    {
        f32 rate = *(f32 *)(bytes + 4);
        f32 maximum = *(f32 *)(bytes + 8);
        if (maximum < rate) {
            *(f32 *)(bytes + 8) = rate;
        }
    }
    *(u32 *)(bytes + 0) = 0;
}
