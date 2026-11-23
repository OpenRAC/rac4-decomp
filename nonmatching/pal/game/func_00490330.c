/* Not matching yet: PAL WIP; main .text 0x00490330, 144B. Not part of the build. */
/*
 * Captured signed minimum and live sample reloads retained, but bound/count/loop register roles,
 * likely-branch joins and scheduling differ. Optional output store still precedes the required
 * fresh sample read.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f72871ffb52b5fbc5c8811189e71568c0b9bb0762f7ae6f6c34c8ac0654941f7
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00490330 nonmatching/pal/game/func_00490330.c --diff
 */
#include "common.h"

typedef struct {
    u8 pad0[844];
    s32 idx;
    s32 pad350;
    s32 arr[7];
} T_5C0F08;
extern T_5C0F08 D_001EE680;

s32 func_00490330(s32 mask, s32 depth, s32 *ordinal, void *record)
{
    u8 *base;
    s32 count;
    s32 limit;
    s32 counter;
    s32 head;
    s32 index;
    s32 *sample;

    if (record != NULL) {
        base = (u8 *)record;
        count = *(s32 *)(base + 0x190);
    } else {
        base = (u8 *)&D_001EE680;
        count = *(s32 *)(base + 0x190);
    }
    if (count < depth) {
        depth = count;
    }
    limit = (s32)((u32)depth + 1U);
    for (counter = 1; counter < limit;
         counter = (s32)((u32)counter + 1U)) {
        head = *(s16 *)(base + 0x18E);
        index = (s32)((u32)head - (u32)counter + 30U) % 30;
        sample = (s32 *)(base + 0x1E0 + index * 4);
        if ((*sample & mask) != 0) {
            if (ordinal != NULL) {
                *ordinal = counter - 1;
            }
            return *sample & mask;
        }
    }
    return 0;
}
