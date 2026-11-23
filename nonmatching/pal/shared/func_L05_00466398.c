/* Not matching yet: PAL WIP; level_05 .text 0x00466398, 60B. Not part of the build. */
/*
 * Conditional result uses zero initialization/MOVZ instead of native input copy/MOVN; final
 * zero-result and return scheduling differ. Actual effects remain subject to the retained source
 * contract.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 3fe8c2adafd6d8ab5c05283d6457dcc1cb91e18756da6a5fcca1d0252fc4fdd2
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L05_00466398 nonmatching/pal/shared/func_L05_00466398.c --diff
 */
#include "common.h"
extern s32 D_0021E714;

s32 func_L05_00466398(void *object)
{
    u8 *context;
    s32 result = 1;

    if (D_0021E714 == 1)
        return result;
    context = *(u8 **)((u8 *)object + 0xAC);
    if (context[0x1D7] != 0)
        return 0;
    if (context[0x1DD] != 0)
        result = 0;
    return result;
}
