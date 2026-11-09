/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8];
    void *f8;
    char _pC[0x8];
    s32 f14;
    char _p18[0x8];
    s32 f20;
};

void func_01F0C090(void *, s32);
extern s32 D_0019E918[];
s32 func_01F0C7D4(Type1 *arg0, void **arg1, u32 *arg2) {
    *arg1 = arg0->f8;
    if (arg0->f20 == 0) {
        func_01F0C090(D_0019E918, 0x148);
    }
    *arg2 = arg0->f14;
    return arg0->f8 != 0;
}
