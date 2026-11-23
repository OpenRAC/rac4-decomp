/* Not matching yet: PAL WIP; main net.text 0x01EF24D4, 180B. Not part of the build. */
/*
 * Native recalculates index*8, keeps separate p/q/offset/index/handle/object values and saves
 * s0..s5. Candidate strength-reduces addresses to a q cursor advanced by8, uses p=q-4 and saves
 * s0..s3. Prologue/branch-delay/restore scheduling differs. No further concrete ordinary graph
 * beyond tested count snapshot is proposed; no lifetime/register/copy/type/flags/padding search.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9286179c67f866bacc6fa8c0a88c163da96a87eb3b7ba41206407c132d91dfe0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EF24D4 nonmatching/pal/net/func_01EF24D4.c --diff
 */
#include "common.h"

s32 func_01EEE13C(void);
s32 func_01EF0550(s32 object, s32 pointer_word);

void func_01EF24D4(void *object, s32 handle)
{
    s32 index = 0;
    s32 count;
    s32 *p;
    s32 *q;
    u32 offset;

    if (handle == 0) {
        handle = func_01EEE13C();
    }
    if (*(s32 *)((u8 *)object + 0x400) > 0) {
        do {
            offset = (u32)index * 8U;
            index = (s32)((u32)index + 1U);
            p = (s32 *)((u8 *)object + offset);
            q = (s32 *)((u8 *)object + 4 + offset);
            func_01EF0550(handle, *p);
            *p = 0;
            func_01EF0550(handle, *q);
            *q = 0;
            count = *(s32 *)((u8 *)object + 0x400);
            *p = 0;
            *q = 0;
        } while (index < count);
    }
    *(s32 *)((u8 *)object + 0x400) = 0;
}
