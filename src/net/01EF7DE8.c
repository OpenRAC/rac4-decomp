#include "common.h"

// Returns word ARG0->fC8 of the array at ARG0->fD0.
s32 func_01EF7DE8(void *arg0) {
    s32 idx = *(s32 *)((u8 *)arg0 + 0xC8);
    s32 *base = *(s32 **)((u8 *)arg0 + 0xD0);
    s32 off = idx << 2;

    idx = off + (u32)base;
    return *(s32 *)idx;
}
