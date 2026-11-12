/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

s32 func_01EA7DC8();
s32 func_01EC3460();
s32 func_01EC3498();

s32 func_01EC4250(void) {
    s32 temp_v0;
    s32 var_s0;

    temp_v0 = func_01EC3460();
    var_s0 = temp_v0;
    if (temp_v0 == 0) {
        var_s0 = func_01EA7DC8();
        func_01EC3498();
    }
    return var_s0;
}
