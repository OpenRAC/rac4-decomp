/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u8 D_0016FF60[];
extern u8 D_00170420[];
extern char D_0019D0F0[];
extern s32 func_01EF0550(s32 object, s32 pointer_word);
extern void func_01F0C090(char *arg0, s32 arg1);
extern void func_01EF3748(void *p);

void func_01EF8434(u8 *p, s32 arg1)
{
    u8 *s0;
    s32 t;

    *(void **)(p + 0xB0) = D_00170420;
    s0 = *(u8 **)(*(u8 **)(p + 0x80));
    if (s0 == 0) {
        func_01F0C090(D_0019D0F0, 0x33);
    }
    t = *(s32 *)s0;
    t = *(s32 *)(t + 0x94);
    ((void (*)(u8 *, s32))t)(s0, *(s32 *)(p + 0x140));
    t = *(s32 *)(p + 0x16C);
    if (t != 0) {
        func_01EF0550(*(s32 *)(*(u8 **)(p + 0x80) + 8), t);
        *(s32 *)(p + 0x16C) = 0;
    }
    *(void **)(p + 0xB0) = D_0016FF60;
    if (arg1 & 1) {
        func_01EF3748(p);
    }
}
