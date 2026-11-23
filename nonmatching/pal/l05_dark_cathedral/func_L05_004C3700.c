/* Not matching yet: PAL WIP; level_05 .text 0x004C3700, 68B. Not part of the build. */
/*
 * No useful remaining ordinary expression/control hypothesis currentlyidentified that yields
 * native finalSW28 afterthreebyteclears without blindly permuting samefoldedzero expressions,
 * changingdeclaredfieldtypes/flags, forcedregisters/volatile/dummywork or weakening
 * requiredmemoryorder. Native-clear grouping/originalsourceform remainsunreconstructed; not a
 * universal compilerimpossibilityproof. Rootcan reprioritize base
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 0a75dde7dd84eeb2c4189c26634d9781210c19d59b86b9737d2cebce61f8975e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L05_004C3700 nonmatching/pal/l05_dark_cathedral/func_L05_004C3700.c --diff
 */
#include "common.h"
s32 func_L05_004C3700(void *object, s32 word1, s32 word2)
{
    void *state = *(void **)((u8 *)object + 0xAC);
    if (*(s32 *)((u8 *)state + 0x20) == 0) {
        int value = 0xFF;
        *(s8 *)((u8 *)object + 0x30) = value;
        *(s32 *)((u8 *)state + 0x20) = word1;
        *(s32 *)((u8 *)state + 0x24) = word2;
        *(s8 *)((u8 *)state + 0x2C) = 1;
        *(s8 *)((u8 *)state + 0x2E) = 0;
        *(s8 *)((u8 *)state + 0x2D) = 0;
        *(s32 *)((u8 *)state + 0x28) = (*(s8 *)((u8 *)state + 0x18) = 0);
        return 1;
    } else {
        return 0;
    }
}
