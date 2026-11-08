/* Not matching yet: BYTES 33/60 (tools/try_func.py func_0015F3F0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_00172160[];

/* Fill sixteen words with -1 and clear the word after them. */
void func_0015F3F0(void) {
    s32 *p = (s32 *)((u8 *)D_00172160 + 0x15E8);
    s32 i;

    for (i = 0xF; i >= 0; i--) {
        *p = -1;
        p--;
    }
    (*(s32 *)((u8 *)D_00172160 + 0x15EC)) = 0;
}
