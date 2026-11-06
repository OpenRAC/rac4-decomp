/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_00653498();
s32 func_006534A8();
s32 func_006534B8(void);
s32 func_L00_00696588(s32);
s32 func_L01_006538A8(s32, s32);


s32 func_L01_005840A8(s32 arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (func_00653498() != arg0) {
        if (func_006534A8() == arg0) {
            var_v0 = 0;
            if (func_006534B8() == 0) {
                if (func_L00_00696588(0) != 0) {
                    return 1;
                }
                goto block_6;
            }
            return var_v0;
        }
        func_L01_006538A8(arg0, 1);
block_6:
        var_v0 = 0;
        return var_v0;
    }
    return var_v0;
}
