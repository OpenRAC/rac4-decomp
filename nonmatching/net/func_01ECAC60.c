/* Not matching yet: BYTES 7/116 (tools/try_func.py func_01ECAC60 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_00167F38;
extern s32 D_1B7390;
extern s32 func_01EC9A08();

/* Validate the index against the object's 0x10C limit, look the slot up and mark
   it; 0x17 and 9 are the refusal codes. */
s32 func_01ECAC60(u32 index)
{
    char *obj = (char *)D_00167F38;
    s32 *q;
    char *slot;

    if (index >= *(u32 *)(obj + 0x10C)) {
        return 0x17;
    }
    q = (s32 *)D_1B7390;
    if (q == 0) {
        return 9;
    }
    slot = (char *)func_01EC9A08();
    if (slot == 0) {
        return 9;
    }
    if (*(s32 *)(slot + 0xC) != q[0x404 / 4]) {
        return 9;
    }
    *(u8 *)(slot + 4) = 1;
    return 0;
}
