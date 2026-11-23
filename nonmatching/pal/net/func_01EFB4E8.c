/* Not matching yet: PAL WIP; main net.text 0x01EFB4E8, 88B. Not part of the build. */
/*
 * Native saves original a2 in v0, forwards a1 directly into a2 and a3 into t0. Compiled first
 * saves a1 in t1 and a2 in v1 before forwarding, adding one move and rescheduling the setup.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 3c267a2566ec8e0c1f0bdae8e4af7f0f29fee755d5dcfc2b0678a482adf1e891
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EFB4E8 nonmatching/pal/net/func_01EFB4E8.c --diff
 */
#include "common.h"

extern f32 func_01EFB224(void *object, void *receiver, const void *bytes,
                        s32 start, s32 end);

/* Compare the supplied threshold with the callee's ordered float result. */
s32 func_01EFB4E8(void *object, const void *bytes, s32 start, s32 end,
                 f32 threshold)
{
    s32 result;

    result = 0;
    if (threshold < func_01EFB224(object,
                                 **(void ***)((u8 *)object + 0x80),
                                 bytes, start, end)) {
        result = 1;
    }
    return result;
}
