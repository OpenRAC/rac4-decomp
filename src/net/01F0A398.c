/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_01EE3A84(void *arg0);
extern s32 func_01EE3A98(void *arg0);
extern void func_01F0C090(const char *, s32);
extern s32 D_0019E5D8[];
extern s32 D_0019E5F0[];
extern s32 D_0019E600[];

/* Return 1 unless both names compare unequal to the two strings. */
s32 func_01F0A398(s32 arg0, void *arg1)
{
    s32 r;

    if (func_01EE3A84(arg1) != 1) {
        func_01F0C090((char *)D_0019E5D8, 0x2F);
    }
    r = 0;
    if (func_0011A8A0((void *)func_01EE3A98(arg1), (u8 *)D_0019E5F0) == 0
        || func_0011A8A0((void *)func_01EE3A98(arg1), (u8 *)D_0019E600) == 0) {
        r = 1;
    }
    return r;
}
