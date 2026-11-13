/* Not matching yet: BYTES 10/132 (tools/try_func.py func_01EFEF40 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC4];
    s32 fC4;
    char _p68[0x66E8 - 0xC8];
    s32 f66E8[0x40];
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019D9E8[];

void func_01EFEF40(Type1 *arg0, s32 arg1) {
    s32 i;
    if (arg1 == 0) {
        func_01F0C090(D_0019D9E8, 0x137);
    }
    i = arg0->fC4;
    if (i >= 0x40) {
        func_01F0C090(D_0019D9E8, 0x13C);
        return;
    }
    arg0->f66E8[i] = arg1;
    arg0->fC4 = i + 1;
}
