/* Not matching yet: PAL WIP; level_00 .text 0x006CDCC0, 104B. Not part of the build. */
/*
 * Native preserves indexed costs from one hoisted costbase, IDcursor, capturedbound moved from
 * initial v0, indexzero before guard, and specific cost-address/index/load/IDadvance scheduling
 * with aligned loop. Tested ordinary graphs either strength-reduce costs to a second cursor or
 * retain indexed costs with different setup/lifetimes/order. No defensible untested source role
 * currently explains remaining native copy/align
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 1aa6b45748529755896cd590eca884b30b611f67c12b3d12f1e815adfb3397b7
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_006CDCC0 nonmatching/pal/shared/func_L00_006CDCC0.c --diff
 */
#include "common.h"

s32 func_L00_006CDCC0(void *record, s32 wantedID, s32 threshold)
{
    s32 count = *(s32 *)((u8 *)record + 0x264C);
    s32 index = 0;
    s32 running = *(s32 *)((u8 *)record + 0x370);
    if (count > 0) {
        s32 *ids = (s32 *)((u8 *)record + 0x260C);
        s32 *costs = (s32 *)((u8 *)record + 0x262C);
        s32 *cost;
scan:
        if (threshold < running)
            return 0;
        if (*ids == wantedID)
            return 1;
        cost = &costs[index];
        ++index;
        ++ids;
        running = (s32)((u32)running + (u32)*cost);
        if (index < count)
            goto scan;
    }
    return 0;
}
