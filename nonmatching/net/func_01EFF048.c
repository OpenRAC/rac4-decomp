/* Not matching yet: BYTES 10/132 (tools/try_func.py func_01EFF048 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xCC];
    s32 fCC;
    char _p1[0x68E8 - 0xCC - 4];
    s32 f68E8[0x40];
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019D9E8[];

void func_01EFF048(Type1 *arg0, s32 arg1) {
    s32 i;

    if (arg1 == 0) {
        func_01F0C090(D_0019D9E8, 0x159);
    }
    i = arg0->fCC;
    if (i >= 0x40) {
        func_01F0C090(D_0019D9E8, 0x15E);
        return;
    }
    arg0->f68E8[i] = arg1;
    arg0->fCC = i + 1;
}
