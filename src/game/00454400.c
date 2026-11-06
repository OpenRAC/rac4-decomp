#include "common.h"
s32 func_00454400(void) {
    s32 var_v0;
    void *temp_v1;

    temp_v1 = *(void **)0x21DE8C;
    var_v0 = -1;
    if (temp_v1 != NULL) {
        var_v0 = (*(s32 *)((u8 *)(temp_v1) + -4));
    }
    return var_v0;
}
