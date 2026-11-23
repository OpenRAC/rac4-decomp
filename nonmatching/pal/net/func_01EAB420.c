/* Not matching yet: PAL WIP; main net.text 0x01EAB420, 212B. Not part of the build. */
/*
 * h05/t05 and h06/t06 and h07/t07 emit identical208B text, native212B. Initial data/guard
 * instructions through native+0x68 agree apart from shifted final-return branch offsets.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: bedb5347f6a96cc6e498f36b26e1c0ace8b201400ba54a5625a9fa27c9e72436
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EAB420 nonmatching/pal/net/func_01EAB420.c --diff
 */
#include "common.h"

s32 func_01EAB420(void *arg0, void *arg1, void *arg2) {
    s32 status = 2;
    u32 first0;
    u32 first1;
    if (arg0 == NULL) goto out;
    if (arg1 == NULL) goto out;
    if (arg2 == NULL) goto out;
    first0 = *(u32 *)arg0;
    first1 = *(u32 *)arg1;
    if (first0 == first1) {
        if (*(u32 *)((u8 *)arg0 + 4) > *(u32 *)((u8 *)arg1 + 4)) {
            *(u32 *)((u8 *)arg2 + 4) = 0;
            goto zero_first;
        }
        *(u32 *)arg2 = 0;
        *(u32 *)((u8 *)arg2 + 4) = *(u32 *)((u8 *)arg1 + 4) - *(u32 *)((u8 *)arg0 + 4);
        goto valid;
    }
    if (first0 < first1) {
        if (*(u32 *)((u8 *)arg1 + 4) < *(u32 *)((u8 *)arg0 + 4)) {
            *(u32 *)arg2 = first1 - first0 - 1U;
            *(u32 *)((u8 *)arg2 + 4) = 1000000U - (*(u32 *)((u8 *)arg0 + 4) - *(u32 *)((u8 *)arg1 + 4));
        } else {
            *(u32 *)arg2 = first1 - first0;
            *(u32 *)((u8 *)arg2 + 4) = *(u32 *)((u8 *)arg1 + 4) - *(u32 *)((u8 *)arg0 + 4);
        }
        goto valid;
    }
    *(u32 *)((u8 *)arg2 + 4) = 0;
zero_first:
    *(u32 *)arg2 = 0;
    return 0;
valid:
    status = 0;
out:
    return status;
}
