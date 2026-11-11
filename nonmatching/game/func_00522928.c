/* Not matching yet: BYTES 71/120 (tools/try_func.py func_00522928 --diff). Not part of the build. */
/* cflags: -Os */
#include "common.h"

s32 func_00548620();

/* Forward the object's fields and the selected 0x50-stride entry to the operation. */
s32 func_00522928(char *p, u8 index, s32 arg2, s16 arg3, u8 slot, s32 last)
{
    s32 v = arg3;
    s32 fifth = arg2;

    if (v == -1) {
        v = *(s16 *)(p + slot * 0x50 + 0x2318);
    }
    return func_00548620(*(void **)(p + 0x26E4), index, *(s32 *)(p + 0x2F00),
                         *(u8 *)(p + 0x266D) != 0, fifth, *(u8 *)(p + 0x2F10),
                         v, slot, *(s32 *)(p + slot * 0x50 + 0x22F0), last);
}
