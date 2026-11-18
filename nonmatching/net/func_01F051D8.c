/* Not matching yet: BYTES 14/132 (tools/try_func.py func_01F051D8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"
s32 func_01EF0550(s32, s32);
void func_01EF0B14(s32, s32);

void func_01F051D8(u8 *arg0)
{
    s32 i;
    s32 *p;
    s32 v;

    if (*(s32 *)(arg0 + 0x27C) != 0) {
        func_01EF0B14(*(s32 *)(arg0 + 0x27C), 3);
    }
    i = 0;
    if (*(s32 *)(arg0 + 0x250) > 0) {
        p = (s32 *)(arg0 + 0xC0);
        do {
            v = *p++;
            if (v != 0) {
                func_01EF0550(*(s32 *)(*(u8 **)(arg0 + 0x80) + 8), v);
            }
            i++;
        } while (i < *(s32 *)(arg0 + 0x250));
    }
}
