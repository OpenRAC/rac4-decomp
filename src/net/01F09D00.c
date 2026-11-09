/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
};

u32 func_0011AB04(s32);
void func_01EED528(s32);
void func_01EEDCD0(s32, s32, s32);
void func_01F0C090(void *, s32);
extern s32 D_0019E5C0;

void func_01F09D00(Type1 *arg0, s32 arg1, s32 arg2) {
    if ((arg0->f0 == 0) || (arg0->f4 == 0)) {
        func_01F0C090(&D_0019E5C0, 0x3D);
    }
    if ((func_0011AB04(arg1) >= 0x20U) || (func_0011AB04(arg2) >= 0x101U)) {
        func_01EED528(0x1E);
        func_01F0C090(&D_0019E5C0, 0x44);
    }
    if ((arg1 == 0) || (arg2 == 0)) {
        func_01F0C090(&D_0019E5C0, 0x48);
    }
    func_01EEDCD0(arg0->f0, arg1, func_0011AB04(arg1) + 1);
    func_01EEDCD0(arg0->f4, arg2, func_0011AB04(arg2) + 1);
}
