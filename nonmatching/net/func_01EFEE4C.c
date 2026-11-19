/* Not matching yet: BYTES 10/132 (tools/try_func.py func_01EFEE4C --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xC0];
    s32 fC0;
    char _p1[0x6520];
    s32 f65E4[1];
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019D9E8[];

void func_01EFEE4C(Type1 *arg0, s32 arg1) {
    s32 t;

    if (arg1 == 0) {
        func_01F0C090(D_0019D9E8, 0x114);
    }
    t = arg0->fC0;
    if (t >= 0x40) {
        func_01F0C090(D_0019D9E8, 0x119);
        return;
    }
    arg0->f65E4[t] = arg1;
    arg0->fC0 = t + 1;
}
