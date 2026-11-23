/* Not matching yet: PAL WIP; main net.text 0x01F074CC, 48B. Not part of the build. */
/*
 * trials.jsonl residualNativeDiff contains every actual word at offsets0 through44
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a2cda0aa1c4c124c8a038a128a081bb22d9c308002c3f40ea44cefcf66dca19f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01F074CC nonmatching/pal/net/func_01F074CC.c --diff
 */
#include "common.h"

/* Clears the two words in each of eight indexed pairs. */
void func_01F074CC(void *arg0) {
    s32 *base = (s32 *)arg0;
    s32 i = 0;

    do {
        s32 *pair = base + i * 2;
        i++;
        pair[1] = 0;
        pair[0] = 0;
    } while (i < 8);
}
