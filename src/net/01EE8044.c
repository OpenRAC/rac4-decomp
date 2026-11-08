/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x5B1C];
    s32 f5B1C;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019B460[];

void func_01EE8044(Type1 *arg0, s32 arg1) {
    if (arg0->f5B1C != 0) {
        func_01F0C090(D_0019B460, 0x731);
    }
    arg0->f5B1C = arg1;
}
