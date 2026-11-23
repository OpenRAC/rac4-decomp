/* Not matching yet: PAL WIP; level_00 .text 0x004FC1C8, 152B. Not part of the build. */
/*
 * 140B newtext versus native152B; unlike old144B object and nooldfunctiontextduplicate.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 3cdbadb1e6f02ca0951e85c2fbd384472d67eda6033f62afc0557ae3a33a5d58
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_004FC1C8 nonmatching/pal/l00_multiplayer_menu/func_L00_004FC1C8.c --diff
 */
#include "common.h"

extern s64 func_L00_00516E90(void *context, u8 *buffer, u32 count);

/* Fill the cached byte buffer, preserving full-width read results. */
s64 func_L00_004FC1C8(void *object, u32 requested)
{
    u8 *buffer;
    s64 result;
    u32 value;
    u32 count;

    count = *(u32 *)((u8 *)object + 0x4C);
    value = requested;
    if (count < requested) {
        buffer = *(u8 **)((u8 *)object + 0x48);
loop_4:
        *(s32 *)((u8 *)object + 0x18) = 3;
        result = func_L00_00516E90(*(void **)((u8 *)object + 0xC),
                                 buffer + count, requested - count);
        if (result > 0) {
            count = *(u32 *)((u8 *)object + 0x4C);
            *(s32 *)((u8 *)object + 0x18) = 1;
            count += (u32)result;
            *(u32 *)((u8 *)object + 0x4C) = count;
            if (count >= requested) {
                value = count;
                return (s64)(s32)value;
            }
            goto loop_4;
        }
        return result;
    }
    return (s64)(s32)value;
}
