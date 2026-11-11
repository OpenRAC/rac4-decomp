/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

s32 func_01EEDCD0(s32, s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019C400[];

void func_01EEED4C(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        func_01F0C090(D_0019C400, 0x250);
    }
    func_01EEDCD0(arg0 + 0x311C, arg1, 0x10);
}
