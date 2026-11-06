/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_0019E3C8[];
extern u8 D_0019E3E0[];
extern s32 func_01EE3A84(s32);
extern void func_01F0C090(const u8 *, s32);
extern void *func_01EE3A98(s32);
extern s32 func_0011A8A0(void *, const u8 *);

s32 func_01F07798(s32 arg0, s32 arg1)
{
    if (func_01EE3A84(arg1) != 1) {
        func_01F0C090(D_0019E3C8, 0x2A);
    }
    return func_0011A8A0(func_01EE3A98(arg1), D_0019E3E0) == 0;
}
