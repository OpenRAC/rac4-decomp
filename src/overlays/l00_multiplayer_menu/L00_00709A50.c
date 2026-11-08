#include "common.h"

extern s32 D_003E4F00[];

void *func_L00_00709A50(u32 arg0) {
    void *var_v1;

    var_v1 = NULL;
    if (arg0 < 0x39U) {
        var_v1 = (void *)((arg0 * 0x10) + (u8 *)D_003E4F00);
    }
    return var_v1;
}
