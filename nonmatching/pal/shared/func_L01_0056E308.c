/* Not matching yet: PAL WIP; level_01 .text 0x0056E308, 84B. Not part of the build. */
/*
 * A legitimate ordinary source result/control graph producing native conditional ADDIU1 branch
 * rather than the observed SLTU result normalization. No useful additional supported graph
 * identified here, no global compiler impossibility claim or arbitrary cap.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: c8f7df4bf5dfcc5dfe5b8b697db2c5c1e1a5e094fcf32abd8de1bc73d69e5a3a
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_0056E308 nonmatching/pal/shared/func_L01_0056E308.c --diff
 */
#include "common.h"
s32 func_L01_0056E308(void *object)
{
    u8 *p = object;
    s32 active, required, intersection;
    s32 result;
    if (p == 0) return 0;
    result = 0;
    do {
        if (*(s32 *)(p + 0x19C) > 0) break;
        active = *(s32 *)(p + 0x178);
        required = *(s32 *)(p + 0x174);
        intersection = active & required;
        if (intersection != required) break;
        if (intersection == 0 && *(u8 *)(p + 0x1DB) == 0) break;
        if (*(u8 *)(p + 0x1DC) == 0) break;
        result = 1;
    } while (0);
    return result;
}
