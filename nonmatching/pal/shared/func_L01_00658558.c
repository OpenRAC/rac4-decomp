/* Not matching yet: PAL WIP; level_01 .text 0x00658558, 108B. Not part of the build. */
/*
 * Native108B versus actual92B: native table-base construction/entry copy, register roles, and
 * separate final zero return; actual compiler common-return merge remains after successful
 * table-join repair. No whole-body match or masked acceptance claimed.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 0b3f468f56aac24528b69ff407b69b072062d57c79c9977cb1e3329c6da2819f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_00658558 nonmatching/pal/shared/func_L01_00658558.c --diff
 */
#include "common.h"

extern u8 D_PAL_00171228[];
extern u8 D_PAL_001CA0C0[];

s32 func_L01_00658558(u32 request)
{
    u8 *entry;

    if (request < 0x80U) {
        goto validate;
    }
reject:
    return 0;

validate:
    entry = D_PAL_001CA0C0 + (request << 3);
    if (*(s32 *)(entry + 0x4C10) <= 0) {
        goto reject;
    }
    if (*(s32 *)(entry + 0x4C14) <= 0) {
        goto reject;
    }
    if (D_PAL_00171228[0x12] == 0) {
        *(u32 *)(D_PAL_00171228 + 0x0C) = request;
        D_PAL_00171228[0x16] = 1;
        return 1;
    }
    return 0;
}
