/* Not matching yet: PAL WIP; level_00 .text 0x00746030, 192B. Not part of the build. */
/*
 * +14/+18: default compiler loads capacity first, native loads count first; both snapshots occur
 * before any write/call.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 705e7a607d43287fcee3dca01c69e23e96369da2ed0810c5961c795fbe7a6afa
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00746030 nonmatching/pal/l00_multiplayer_menu/func_L00_00746030.c --diff
 */
#include "common.h"
extern void func_L00_00745F90(void *object, s32 param_a, s32 param_b);

s32 func_L00_00746030(void *arg0, s32 arg1) {
    u8 *owner = (u8 *)arg0;
    u8 *buffer = owner + 0x284;
    s32 count;
    s32 capacity;
    u64 previous_high = 0;
    arg1 &= 0xFF;
    count = *(s32 *)(owner + 0x34C);
    capacity = *(s32 *)(owner + 0x350);
    if (count >= capacity) goto rejected;
    if (count >= (s32)((u32)capacity - 1U)) {
        if (arg1 & 0x80) return 0;
    }
    count = *(s32 *)(owner + 0x34C);
    if (count > 0) previous_high = (u64)buffer[count - 1] >> 7;
    if (arg1 != 0x20) goto append;
    if (count != 0) {
        if (buffer[count - 1] != arg1) goto append;
    }
    if (previous_high != 0) goto append;
rejected:
    return 0;
append:
    buffer[count] = arg1;
    buffer[(s32)((u32)*(s32 *)(owner + 0x34C) + 1U)] = 0;
    *(s32 *)(owner + 0x34C) = (s32)((u32)*(s32 *)(owner + 0x34C) + 1U);
    func_L00_00745F90(arg0, 0, *(u8 *)(owner + 0x265));
    return 1;
}
