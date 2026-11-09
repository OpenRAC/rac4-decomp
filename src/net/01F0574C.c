/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x250];
    s32 f250;
    s32 f254;
    s32 f258;
    s32 f25C;
    s32 f260;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E200[];

void func_01F0574C(Type1 *arg0) {
    if (arg0->f250 >= 0x65) {
        func_01F0C090(D_0019E200, 0x16D);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x16E);
    }
    if (arg0->f25C < arg0->f260) {
        func_01F0C090(D_0019E200, 0x16F);
    }
    if (arg0->f25C >= (arg0->f260 + arg0->f254)) {
        func_01F0C090(D_0019E200, 0x170);
    }
    arg0->f25C = -1;
}
