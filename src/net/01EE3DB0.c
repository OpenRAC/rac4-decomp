/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC; } Blk;
Blk *func_01EE3CEC(s32, u32);
void *func_01EE3DB0(s32 a0, u32 n) {
    Blk *b;
    s32 off;
    if (n < 8) {
        n = 8;
    }
    n = n - (n & 7) + 8;
    b = func_01EE3CEC(a0, n);
    if (b == 0) {
        return 0;
    }
    off = b->f4;
    b->fC = off;
    b->f4 = off + n;
    return (char *)b + off + 0x14;
}
