/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0011A8A0(s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019E5C0[];

s32 func_01F09CAC(s32 *arg0, s32 arg1) {
    if (arg1 == 0) {
        func_01F0C090(D_0019E5C0, 0x36);
    }
    return func_0011A8A0(arg1, *arg0) == 0;
}
