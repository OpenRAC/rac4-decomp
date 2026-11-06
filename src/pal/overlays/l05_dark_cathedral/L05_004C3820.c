/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_L05_004C3820(void *arg0) {
    s32 var_3;
    var_3 = 1;
    if (!(*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0xAC) + 0x10) >= 1.0f)) {
        var_3 = 0;
    }
    return var_3;
}
