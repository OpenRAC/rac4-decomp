/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_00121FA0(s8 *arg0, s8 *arg1);
extern s32 func_01EE3A18(s32,void *);
extern s32 D_0016E670[];
extern s32 D_0019E7A0[];

// Looks up arg1 in the table at D_0016E670 (two entries), stores the index in *arg2.
s32 func_01F0BEE0(s32 arg0, s32 arg1, u32 *arg2) {
    s32 *var_s1;
    s32 temp_a1;
    s32 temp_v0;
    u32 var_s0;

    temp_v0 = func_01EE3A18(arg1, D_0019E7A0);
    if (temp_v0 != 0) {
        var_s0 = 0;
        var_s1 = D_0016E670;
loop_2:
        temp_a1 = *var_s1;
        var_s1 += 1;
        if (func_00121FA0(temp_v0, temp_a1) == 0) {
            *arg2 = var_s0;
            return 1;
        }
        var_s0 += 1;
        if (var_s0 >= 2U) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
