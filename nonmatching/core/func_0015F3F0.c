/* cflags: -fno-gcse */
/* Not matching yet: BYTES 4/60 (tools/try_func.py func_0015F3F0 --diff). Not part of the build. */
#include "common.h"

extern u32 D_00172160[];

/* Fill sixteen words with -1 and clear the word after them. */
void func_0015F3F0(void) {
    unsigned int off;
    u8 *base = (u8 *)D_00172160;
    s32 *p = (s32 *)(base + 0x15E8);
    s32 i;
    s32 value;

    value = -1;
    for (i = 0xF; i >= 0; i--) {
        *p = value;
        p--;
    }
    off = 0x15EC;
    D_00172160[off / 4] = 0;
}
