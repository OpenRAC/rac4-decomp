/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 w[0x1FC]; } Blk;
extern void *func_01EEFEB8(s32);
extern void func_01F0C090(char *arg0, s32 arg1);
extern u8 D_0019B870[];

// Copies a 0x7F0-byte block returned by func_01EEFEB8 into arg0 + 0x1388 and returns 1.
s32 func_01EEB804(u8 *arg0, u8 *arg1) {
    Blk *src;
    Blk *dst;

    dst = (Blk *)(arg1 + 0x1388);
    src = func_01EEFEB8(*(s32 *)(arg0 + 0x138));
    if (src == 0) {
        func_01F0C090((char *)D_0019B870, 0x454);
    }
    *dst = *src;
    return 1;
}
