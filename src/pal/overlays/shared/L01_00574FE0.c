/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
s32 func_L01_00574FE0(void *arg0, s32 arg1) {
    s32 var_3;
    s32 var_5;
    u16 *var_4;
    u16 var_2;
    s32 var_6;
    var_2 = *(u8 *)((u8 *)arg0 + 0x91);
    var_5 = arg1 & 0xFFFF;
    var_3 = 0;
    if (var_2 != 0) {
        var_6 = var_2;
        var_4 = (u16 *)((u8 *)arg0 + 0x80);
loop_2:
        var_2 = *var_4;
        var_3 += 1;
        if (var_2 == var_5) return 1;
        var_2 = var_3 < (s32) var_6;
        var_4 += 1;
        if (var_2 == 0) goto done;
        goto loop_2;
    }
done:
    return 0;
}
