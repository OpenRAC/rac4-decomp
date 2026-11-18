/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern char D_0019D240[];
extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A518(void *, s32, s32);
extern s32 func_0011AB04(u8 *);
extern void func_01F0C090(char *arg0, s32 arg1);

/* Copies a chunk into a zeroed buffer and hands it to the output handler. */
f32 func_01EFB224(u8 *a0, s32 a1, u8 *a2, s32 a3, s32 a4)
{
    u8 buf[0x3000];
    void **h;
    s32 n;

    n = a4 - a3;
    if (n > 0) {
        if (n >= *(s32 *)(a0 + 0xB8)) func_01F0C090(D_0019D240, 0x65D);
        h = **(void ****)(a0 + 0x80);
        func_0011A518(buf, 0, 0x3000);
        func_0011A370(buf, a2 + a3, n);
        buf[n] = 0;
        *(s32 *)(a0 + 0x180) = *(s32 *)(a0 + 0x180) + 1;
        return (*(f32 (**)(void *, s32, u8 *, s32))((u8 *)*h + 0x14))(h, *(s32 *)(a0 + 0x144), buf, func_0011AB04(buf));
    }
    return 0.0f;
}
