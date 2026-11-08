/* cflags: -Wuninitialized */
#include "common.h"

s64 func_L01_004AFA58(int arg0);

s32 func_L01_004AF6E0(void *arg0) {
    u8 var_3;
    u32 var_2;
    s32 var_5;

    var_2 = *(u32 *)((u8 *)arg0 + 0xAC);
    var_3 = *(u8 *)((u8 *)var_2 + 1032);
    var_5 = 0;
    if (var_3 == 0) {
        var_2 = (u32) (func_L01_004AFA58((s32) arg0) != 0);
        var_5 = (s32) var_2;
    }
    return var_5;
}