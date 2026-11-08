/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x66E4];
    s32 f66E4;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019D9E8[];

void func_01EFEED0(Type1 *arg0, s32 arg1) {
    if (arg1 == 0) {
        func_01F0C090(D_0019D9E8, 0x125);
    }
    if (arg0->f66E4 != 0) {
        func_01F0C090(D_0019D9E8, 0x12C);
        return;
    }
    arg0->f66E4 = arg1;
}
