#include "common.h"
s32 func_L01_00493B18(void *arg0) {
    s32 var_v1;

    var_v1 = 1;
    if (!((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xAC))) + 0x64)) >= 1.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}
