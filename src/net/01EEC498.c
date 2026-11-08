/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x8AB8];
    s32 f8AB8;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019B870[];

s32 func_01EEC498(Type1 *arg0) {
    if (arg0->f8AB8 <= 0) {
        func_01F0C090(D_0019B870, 0x67A);
    }
    return arg0->f8AB8;
}
