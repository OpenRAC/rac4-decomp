#include "common.h"
/* Returns the element of the table at +0xD0 indexed by the value at +0xC8. */
s32 func_01EF7DE8(void *arg0) {
    s32 idx = *(s32 *)((u8 *)arg0 + 0xC8);
    s32 *base = *(s32 **)((u8 *)arg0 + 0xD0);
    idx = (idx << 2) + (u32)base;
    return *(s32 *)idx;
}
