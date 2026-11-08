/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0011AB04(s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019D4A0[];

s32 func_01EFC550(s32 arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0xB8;
    if (func_0011AB04(temp_s0) >= 0x200) {
        func_01F0C090(D_0019D4A0, 0x247);
    }
    return temp_s0;
}
