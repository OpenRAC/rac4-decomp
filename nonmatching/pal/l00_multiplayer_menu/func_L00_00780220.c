/* Not matching yet: PAL WIP; level_00 .text 0x00780220, 208B. Not part of the build. */
/*
 * Two-pass live-count/read/store traversal retained; chosen212B/native208B draft still differs in
 * retry, inner-search continuation and delay/result scheduling. Shorter strength-reduced
 * alternatives are preserved in history, not preferred by size.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: da255b84621e8de015f779058304096471a34be3f9f82c8b8ebb4b03517f115c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00780220 nonmatching/pal/l00_multiplayer_menu/func_L00_00780220.c --diff
 */
#include "common.h"
struct Roster;
extern struct Roster D_001E0DF8;

void func_L00_00780220(s32 *total, s32 *rows, s32 *selected, s32 *position)
{
    {
        u8 *base = (u8 *)&D_001E0DF8;
        s32 i;
        s32 count;
        for (i = 0; i < 10; i++) {
            if (*(s32 *)(base + 0x4B0 + i * 4) != 0 && *selected == -1)
                *selected = i;
            count = *(s32 *)(base + 0x78 + i * 100);
            if (count > 0) {
                *(u32 *)total = *(u32 *)total + (u32)count;
                *(u32 *)rows = *(u32 *)rows + 1U;
            }
        }
    }
    {
        u8 *counts = (u8 *)&D_001E0DF8 + 0x78;
        u8 *entries = counts - 0x50;
        s32 i;
        s32 j;
        s32 count;
        s32 next;
        s32 offset;
        s32 value;
        i = 0;
        j = 0;
        do {
            next = i + 1;
search_row:
            offset = i * 100;
            count = *(s32 *)(counts + offset);
            if (j >= count)
                goto next_row;
            value = *(s32 *)(entries + ((u32)offset + ((u32)j << 2)));
            if (value != *selected) {
                j++;
                goto search_row;
            }
            *position = j;
next_row:
            i = next;
            j = 0;
        } while (i < 10);
    }
}
