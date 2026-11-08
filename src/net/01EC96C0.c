/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA42D8(s32);
s32 func_01EA57B8();
s32 func_01EA57F8();
s32 func_01EC98E8(s32);
s32 func_01ECB548(s32, s32, s32);

s32 func_01EC96C0(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    var_v0 = func_01EA42D8(func_01EA57B8());
    if (var_v0 == 0) {
        temp_s0 = func_01ECB548(arg0, func_01EC98E8(arg1), 0);
        temp_v0 = func_01EA42D8(func_01EA57F8());
        var_v0 = (temp_v0 == 0) ? temp_s0 : temp_v0;
    }
    return var_v0;
}
