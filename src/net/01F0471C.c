/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EE3A18(s32, void *);
s32 func_01EEFA80(s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019E090[];
extern s32 D_0019E0A0[];
extern s32 D_0019E0A8[];

s32 func_01F0471C(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = func_01EE3A18(arg1, D_0019E0A0);
    temp_v0 = func_01EE3A18(arg1, D_0019E0A8);
    if ((temp_s1 != 0) && (temp_v0 != 0)) {
        func_01EEFA80(temp_s1, temp_v0);
    } else {
        func_01F0C090(D_0019E090, 0x4B);
    }
    return 1;
}
