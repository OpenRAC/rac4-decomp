/* cflags: -fno-schedule-insns */
#include "common.h"
s32 func_L00_007647B0(s32);                 /* extern */

s32 func_L00_00711178(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (((u32) (arg1 - 3) < 2U) || (arg1 == 7)) {
        func_L00_007647B0(5);
        var_v1 = 1;
        (*(u8 *)((u8 *)(arg0) + 0x5C)) = (u8) ((*(u8 *)((u8 *)(arg0) + 0x5C)) ^ 1);
    }
    return var_v1;
}
