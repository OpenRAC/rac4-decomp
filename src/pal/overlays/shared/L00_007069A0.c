#include "common.h"

s32 func_L00_007069A0(void) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = *(void **)0x21E070;
    var_a0 = 0;
    if (((temp_v0 != NULL) && ((*(u8 *)((s8 *)(temp_v0) + (0x1A9))) == 2)) || ((*(u32 *)0x21DE98 - 0x2EU) < 4U)) {
        var_a0 = 1;
    }
    return var_a0;
}
