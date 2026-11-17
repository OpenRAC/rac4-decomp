/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_0051B620(s32 *, u8 *);

/* Pad the 16-byte block at s+4, run the block step on it, copy it out and copy the second block to out. */
void func_L00_0051B848(u8 *out, s32 *s)
{
    u8 *buf = (u8 *)(s + 1);
    s32 *p2 = s + 21;
    s32 *p1 = s + 5;
    s32 n = s[0];
    s32 pad = 16 - n;
    s32 i;

    for (i = n; i < 16; i++)
        buf[i] = pad;
    func_L00_0051B620(s, buf);
    for (i = 0; i < 16; i++)
        buf[i] = (u8)p1[i];
    func_L00_0051B620(s, buf);
    for (i = 0; i < 16; i++)
        out[i] = (u8)p2[i];
}
