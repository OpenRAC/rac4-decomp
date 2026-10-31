/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern void *D_0021E078;

/* Clear one byte and set the next when the flag is nonzero. */
void func_L41_0062A6B8(void)
{
    if (*(u8 *)((u8 *)D_0021E078 + 0x23) != 0) {
        *(s8 *)((u8 *)D_0021E078 + 0x1B) = 0;
        *(s8 *)((u8 *)D_0021E078 + 0x1C) = 1;
    }
}
