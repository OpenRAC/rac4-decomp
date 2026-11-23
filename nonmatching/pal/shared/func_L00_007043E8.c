/* Not matching yet: PAL WIP; level_00 .text 0x007043E8, 60B. Not part of the build. */
/*
 * Default compiler uses context in a0 and captured next in v1, omitting native initial a0-to-a1
 * copy. It chooses BEQ-to-null instead of native BNE-to-nonnull, moves next into v0 before return,
 * and puts head SW in JR delay rather than native MOVE-next delay. Result56B versus native60B at
 * all14 placements.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6179e0d9cd34a69adff59f1fd29a05fdd21b1f9828ca00f9e686306caa1b9be9
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_007043E8 nonmatching/pal/shared/func_L00_007043E8.c --diff
 */
#include "common.h"

/* Remove the current node and return the captured new head. */
void *func_L00_007043E8(void *arg0)
{
    u8 *object = arg0;
    u8 *node;
    u8 count;
    u8 *next;

    node = *(u8 **)(object + 0x2C);
    if (node == NULL) {
        return NULL;
    }
    node[2] = 0xFF;
    node = *(u8 **)(object + 0x2C);
    count = object[0x20];
    next = *(u8 **)(node + 0x20);
    object[0x20] = (u8)(count - 1);
    *(u8 **)(object + 0x2C) = next;
    return next;
}
