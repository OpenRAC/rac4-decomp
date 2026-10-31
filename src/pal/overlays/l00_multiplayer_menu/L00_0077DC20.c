/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

#include "pal/global_002234A4.h"

/* Clear the byte at E4 and copy the input word at 18 to E8. */
void func_L00_0077DC20(void *arg0)
{
    void *target = *(void **)((u8 *)D_002234A4 + 0x60);

    *(s8 *)((u8 *)target + 0xE4) = 0;
    *(s32 *)((u8 *)target + 0xE8) = *(s32 *)((u8 *)arg0 + 0x18);
}
