/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EF081C(s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019B460[];

s32 func_01EE6AF8(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        func_01F0C090(D_0019B460, 0x30D);
    }
    func_01EF081C(arg0 + 0x3AD8, arg1);
    return 1;
}
