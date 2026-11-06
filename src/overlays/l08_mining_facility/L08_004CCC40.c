#include "common.h"
s32 func_L08_004CCC40(void *arg0) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((u8 *)(arg0) + 0x20));
    var_a0 = 0;
    if ((temp_v1 == 2) || (temp_v1 == 4)) {
        var_a0 = 1;
    }
    return var_a0;
}
