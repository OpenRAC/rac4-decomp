/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1B4];
    s32 f1B4;
};

s32 func_01EFEF40(s32, void *);
s32 func_01F039BC();
s32 func_01F0C090(void *, s32);
extern s32 D_0019DF78[];

void func_01F03B10(Type1 *arg0) {
    arg0->f1B4 = func_01F039BC();
    if (arg0->f1B4 == 0) {
        func_01F0C090(D_0019DF78, 0x8D);
    }
    func_01EFEF40(arg0->f1B4, arg0);
}
