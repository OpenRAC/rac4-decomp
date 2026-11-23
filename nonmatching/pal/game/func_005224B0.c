/* Not matching yet: PAL WIP; main .text 0x005224B0, 104B. Not part of the build. */
/*
 * Captured count/threshold and modular arithmetic retained, but 104B output differs in11 words/16
 * bytes from native. Control/result/pointer scheduling remains nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 24481596a1d0fa2fca2a299d587b92f9f1bf8ddbfbed9a13345d9ae024d4725b
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_005224B0 nonmatching/pal/game/func_005224B0.c --diff
 */
#include "common.h"

s32 func_005224B0(void *object, s32 wantedId, s32 position)
{
    s32 count = *(s32 *)((s8 *)object + 0x264C);
    s32 index = 0;
    s32 threshold = *(s32 *)((s8 *)object + 0x370);
    if (count > 0) {
        s32 *ids = (s32 *)((s8 *)object + 0x25EC);
        s32 *steps = (s32 *)((s8 *)object + 0x262C);
        for (; index < *(s32 *)((s8 *)object + 0x264C); index++) {
            if (position < threshold)
                return 0;
            if (ids[index] == wantedId)
                return 1;
            threshold = (s32)((u32)threshold + (u32)steps[index]);
        }
    }
    return 0;
}
