/* Not matching yet: PAL WIP; level_00 .text 0x00532668, 76B. Not part of the build. */
/*
 * Postdecrement-operator yields allones sentinel88B. Explicit zero-test loops64B. Explicit
 * capturedold loop72B closest. Rotated do/while72B, nestedkey72B, commonresult60/72B,
 * searchpredicatewhile68B, hitbreak64B. Explicit whilecondition h11 duplicates h03; forupdate h04
 * duplicates h02. No arbitrary attempt cap used.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d69dab492b91f057432bab51e118a5e3dc959d2b57a2430628da30b2b8e95594
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00532668 nonmatching/pal/l00_multiplayer_menu/func_L00_00532668.c --diff
 */
#include "common.h"

/* Search captured records with a defined modular word countdown. */
s32 *func_L00_00532668(void *arg0, s32 arg1)
{
    u32 remaining;
    s32 *cursor;

    if (arg1 == 0)
        return NULL;
    remaining = *(u32 *)arg0;
    cursor = *(s32 **)((u8 *)arg0 + 8);
    for (;;) {
        u32 old = remaining;
        remaining -= 1U;
        if (old == 0)
            break;
        if (*cursor == arg1)
            return cursor;
        cursor += 3;
    }
    return NULL;
}
