/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x18C];
    s32 f18C;
};

s32 func_01EFDB34();
s32 func_01EFEBA8(s32, void *);
s32 func_01F0C090(void *, s32);
extern s32 D_0019D858[];

void func_01EFDC88(Type1 *arg0) {
    s32 temp_v0;

    temp_v0 = func_01EFDB34();
    arg0->f18C = temp_v0;
    if (temp_v0 == 0) {
        func_01F0C090(D_0019D858, 0xDD);
    }
    func_01EFEBA8(arg0->f18C, arg0);
}
