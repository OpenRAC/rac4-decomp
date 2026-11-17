#include "common.h"

/* Rounds arg0 + 0x10 up to a multiple of 4, adds arg1 records of 0xD8 bytes, rounds again and returns the distance from arg0 */
s32 func_L00_0076CB00(s32 arg0, s32 arg1) {
    u32 align;
    u32 temp_hi;
    u32 var_a1;
    u32 var_v1;

    align = 4;
    var_v1 = arg0 + 0x10;
    temp_hi = var_v1 % align;
    if (temp_hi != 0) {
        var_v1 += align - temp_hi;
    }
    var_a1 = (arg1 * 0xD8) + var_v1;
    temp_hi = var_a1 % align;
    if (temp_hi != 0) {
        var_a1 += align - temp_hi;
    }
    return var_a1 - arg0;
}
