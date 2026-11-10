/* cflags: @ee29 -O2 -G8 -malign-loops=2 -fno-gcse */
#include "common.h"

/* Release the first entry at or after START whose word matches KEY, clearing it. */
void func_L00_006A9778(s32 a0, s32 start, s32 key, char *base)
{
    s32 i;

    for (i = start + 1; i < 0x100; i++) {
        s32 *tab = (s32 *)(base + 0x48C0);
        char *idx = (char *)(i << 2);
        s32 *p = (s32 *)(idx + (s32)tab);
        if (*p == key) {
            *p = 0;
            break;
        }
    }
}
