/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0011A8A0(s32, void *);
s32 func_01EE3A18(s32, void *);
s32 func_01EE3A84(s32);
s32 func_01EE3A98(s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0019D720[];
extern s32 D_0019D738[];
extern s32 D_0019D740[];
extern s32 D_0019D748[];

s32 func_01EFCBAC(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 var_s1;

    if (func_01EE3A84(arg1) != 1) {
        func_01F0C090(D_0019D720, 0x14);
    }
    temp_s0 = func_01EE3A18(arg1, D_0019D738);
    var_s1 = 0;
    if (func_0011A8A0(func_01EE3A98(arg1), D_0019D740) == 0) {
        var_s1 = func_0011A8A0(temp_s0, D_0019D748) == 0;
    }
    return var_s1;
}
