/* Not matching yet: PAL WIP; main net.text 0x01EAA7B8, 212B. Not part of the build. */
/*
 * Invalid actual GPREL16: physical0x168C10 - GP0x2259FF = -0xBCDEF, outside signed16. Extra
 * ordinary-delay row-cell read remains. No masked/truncated binding is accepted.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: da0cba4aab83c3289d6b762f956432a06867f2e8dd210501881ce335d2e7ee6b
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EAA7B8 nonmatching/pal/net/func_01EAA7B8.c --diff
 */
#include "common.h"

extern u8 D_00168B84;
extern s32 *D_00168B8C;
extern s32 D_00168B90;
extern u32 D_001B23BC;
extern u32 D_001B23C0;

s32 func_01EAA7B8(s32 key, s32 row, void *payload)
{
    s32 *table;
    u32 row_address;
    u32 offset;
    u32 capacity;
    u32 count;
    u32 *counter;
    u32 *slot;

    if (D_00168B84 != 1) {
        return 5;
    }
    table = D_00168B8C;
    if (table == 0) {
        return 5;
    }
    row_address = (u32)D_00168B90;
    if (row_address == 0) {
        return 5;
    }
    if ((u32)key >= 0x100U) {
        return 2;
    }
    if ((u32)row >= D_001B23C0) {
        return 2;
    }

    capacity = D_001B23BC;
    offset = (u32)row << 2;
    counter = (u32 *)((u8 *)row_address + offset);
    count = *counter;
    if (capacity < count) {
        return 0x3EB;
    }
    if ((u32)key >= count) {
        *counter = (u32)key;
        counter = (u32 *)((u8 *)(u32)D_00168B90 + offset);
        *counter += 1U;
        table = D_00168B8C;
        capacity = D_001B23BC;
    }

    slot = (u32 *)((u8 *)table + (((u32)row * capacity + (u32)key) << 2));
    if (*slot != 0) {
        return 0x3EA;
    }
    *slot = (u32)payload;
    return 0;
}
