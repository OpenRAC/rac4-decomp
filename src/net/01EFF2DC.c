/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern char D_0019D9E8[];
extern void func_01F0C090(const char *, s32);
/* Set the state and report the location. */
s32 func_01EFF2DC(char *p)
{
    *(s32 *)(p + 0x2d8) = 1;
    func_01F0C090(D_0019D9E8, 0x1bd);
    return 0;
}
