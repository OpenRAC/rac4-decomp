/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 func_00498100(s32 arg0);
extern s32 func_00498120();
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;

// Gate on D_0021EDD4 and D_0021EDD8, then compare func_00498120 with arg1; for arg1 2 also test func_00498100.
s32 func_00498158(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 result;

    if (D_0021EDD4 != 0) {
        return 1;
    }
    if (D_0021EDD8 != 1) {
        return 1;
    }
    if (arg1 == 0xE) {
        return 1;
    }
    temp_s1 = arg0 == 0;
    result = 0;
    if (func_00498120(temp_s1) != arg1 || (arg1 == 2 && func_00498100(temp_s1) != 0)) {
        result = 1;
    }
    return result;
}
