/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

#include "pal/global_002234A4.h"

/* Clear the byte at 0xEC and copy the input word into 0xF0. */
void func_L00_0077DDA8(void *arg0) {
    void *target = *(void **)((u8 *)D_002234A4 + 0x60);
    *(s8 *)((u8 *)target + 0xEC) = 0;
    *(s32 *)((u8 *)target + 0xF0) = *(s32 *)((u8 *)arg0 + 0x18);
}
