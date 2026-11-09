/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

s32 func_0011AB04(s32);
s32 func_01EFC598(s32, s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019D4A0[];

void func_01EFC4E8(s32 arg0, s32 arg1) {
    if (func_0011AB04(arg1) >= 0x200) {
        func_01F0C090(D_0019D4A0, 0x240);
    }
    func_01EFC598(arg0, arg1, func_0011AB04(arg1));
}
