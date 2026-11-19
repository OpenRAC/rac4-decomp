/* Not matching yet: BYTES 41/168 (tools/try_func.py func_01F0B3D0 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(s32 *arg0, s32 arg1);
extern s32 D_0019E698[];

s32 func_01F0B3D0(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 n;

    if (*(s32 *)(arg0 + 0xCC) > *(s32 *)(arg0 + 0xC4))
        func_01F0C090(D_0019E698, 0x180);
    if (*(s32 *)(arg0 + 0xC8) > *(s32 *)(arg0 + 0xC4))
        func_01F0C090(D_0019E698, 0x181);
    n = *(s32 *)(arg0 + 0xC4);
    for (i = 0; i < n; i++)
        if (*(s32 *)(*(s32 *)(arg0 + 0xC0) + i * 4) == arg1)
            return i;
    return -1;
}
