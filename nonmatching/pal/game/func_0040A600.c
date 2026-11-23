/* Not matching yet: PAL WIP; main .text 0x0040A600, 384B. Not part of the build. */
/*
 * Exact native returntail duplication/sharedvalue placement andbranch-delay scheduling still
 * absent despite recovered actualcase-node grouping. No defensible further sourcegraph identified;
 * do not runcasepartition/returnspelling/scope/type/cast/flags/padding/registerseries. This closes
 * these emittedfamilies, not all future reconstruction or a globalcompilerclaim.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 2bdbf2bcb2a0e1ca6230fdde2b3a947d3338947a412d95de023fce295e56ce46
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0040A600 nonmatching/pal/game/func_0040A600.c --diff
 */
#include "common.h"

s32 func_0040A600(s32 value)
{
    if (value != 0) {
        switch (value) {
        case 0x64:
        case 0x65:
            return 0x5;
        case 0x100:
            return 0x10;
        case 0x101:
        case 0x102:
        case 0x103:
        case 0x104:
        case 0x105:
            return 0x5;
        case 0x106:
            return 0x5;
        case 0x107:
            return 0x7;
        case 0x108:
            return 0x5;
        case 0x109:
            return 0x5;
        case 0x10A:
            return 0x5;
        case 0x10B:
            return 0x5;
        case 0x10C:
            return 0xA;
        case 0x1F4:
        case 0x1F5:
            return 0x5;
        case 0x1F7:
        case 0x1F8:
            return 0x5;
        case 0x1F9:
            return 0xA;
        case 0x1FB:
            return 0x5;
        case 0x3E9:
            return 0x10;
        case 0x3EA:
            return 0x5;
        case 0x3EF:
            return 0x5;
        case 0x3F0:
            return 0xA;
        case 0x3F1:
        case 0x3F2:
        case 0x3F3:
        case 0x3F4:
            return 0x5;
        case 0x4B1:
        case 0x4B2:
        case 0x4B3:
            return 0x5;
        default:
            return value;
        }
    }
    return 0;
}
