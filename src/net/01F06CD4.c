/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EEE070(s8, s32);

s32 func_01F06CD4(s8 arg0) {
    s32 temp_a1;
    s32 var_v0;

    temp_a1 = arg0 < 0x41;
    if ((arg0 >= 0x47) || (var_v0 = 1, (temp_a1 != 0))) {
        var_v0 = func_01EEE070(arg0, temp_a1) != 0;
    }
    return var_v0;
}
