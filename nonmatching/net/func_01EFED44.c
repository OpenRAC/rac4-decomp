/* Not matching yet: BYTES 10/132 (tools/try_func.py func_01EFED44 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB8];
    s32 fB8;
    char _p1[0x63E4 - 0xBC];
    s32 f63E4[0x40];
};

void func_01F0C090(void *, s32);
extern s32 D_0019D9E8[];

void func_01EFED44(Type1 *arg0, s32 arg1) {
    s32 idx;

    if (arg1 == 0) {
        func_01F0C090(D_0019D9E8, 0xF4);
    }
    idx = arg0->fB8;
    if (idx >= 0x40) {
        func_01F0C090(D_0019D9E8, 0xF9);
        return;
    }
    arg0->f63E4[idx] = arg1;
    arg0->fB8 = idx + 1;
}
