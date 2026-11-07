/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_00121FA0(s32, void *);
s32 func_01EE3A18();
extern s32 D_0019C6C8[];
extern s32 D_0019C6D0[];

s32 func_01EF30EC(s32 arg0, s32 arg1, s32 *arg2) {
    s32 var_v0;

    var_v0 = func_01EE3A18();
    if (var_v0 != 0) {
        if (func_00121FA0(var_v0, D_0019C6C8) == 0) {
            *arg2 = 1;
            return 1;
        }
        if (func_00121FA0(var_v0, D_0019C6D0) == 0) {
            *arg2 = 0;
        }
        var_v0 = 1;
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
