/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

#include "pal/global_002234A4.h"

/* Clear the byte and copy the input word into the referenced object. */
void func_L00_00781AE0(void *arg0)
{
    void *object = *(void **)((u8 *)D_002234A4 + 0x68);
    *(s8 *)((u8 *)object + 0x2F54) = 0;
    *(s32 *)((u8 *)object + 0x2F58) = *(s32 *)((u8 *)arg0 + 0x18);
}
