/* Not matching yet: PAL WIP; level_00 .text 0x005DCDC0, 188B. Not part of the build. */
/*
 * Actual compiler CSE omits two path-specific required fresh final status loads. Source spelling
 * of reloads is not emitted-effect proof.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b86c9d502836828dad31f4c059010e4b08b8236384735063e4ad5a70fb9121d5
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_005DCDC0 nonmatching/pal/l00_multiplayer_menu/func_L00_005DCDC0.c --diff
 */
#include "common.h"

extern u8 D_001719C8[];

/* Queue the word and minimum-sized request while the state is ready. */
s32 func_L00_005DCDC0(s32 word0, u32 request) {
    u8 *state = D_001719C8;
    s32 index = *(s32 *)(state + 0x1B0);

    if (index == -1 ||
        (((u32)*(s32 *)(state + 0x0C) << 10) + 0x10000U) < request) {
        return 0;
    }
    if (*(s32 *)(state + 0x1C4) < 3 && *(s32 *)(state + 0x1CC) < 0) {
        *(s32 *)(state + 0x1DC) = word0;
        if (request <= 0xFFFFU) {
            *(u32 *)(state + (u32)index * 0xD4U + 0x24) = 0x10000U;
        } else {
            *(u32 *)(state + (u32)index * 0xD4U + 0x24) = request;
        }
        if (*(s32 *)(state + 0x1CC) < 0) {
            s32 freshIndex = *(s32 *)(state + 0x1B0);
            *(s32 *)(state + 0x1CC) = 0x24;
            *(s32 *)(state + 0x1D0) = freshIndex;
        }
    }
    return *(s32 *)(state + 0x1CC) == 0x24;
}
