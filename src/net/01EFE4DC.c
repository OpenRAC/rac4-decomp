/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x18C];
    s32 f18C;
};

s32 func_01EFE388();
s32 func_01EFED44(s32, void *);
s32 func_01F0C090(void *, s32);
extern s32 D_0019D938[];

void func_01EFE4DC(Type1 *arg0) {
    arg0->f18C = func_01EFE388();
    if (arg0->f18C == 0) {
        func_01F0C090(D_0019D938, 0xDD);
    }
    func_01EFED44(arg0->f18C, arg0);
}
