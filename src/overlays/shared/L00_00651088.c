#include "common.h"

extern s32 D_00314294[];
// returns whether the word the selected table entry points to is nonzero
s32 func_L00_00651088(s32 arg0) {
    u8 *base;
    s32 var_a0;
    u8 *var_v0;

    base = (u8 *)D_00314294;
    var_a0 = arg0;
    if (var_a0 < 0) {
        var_a0 = *(s32 *)(base + 0x54);
        var_v0 = NULL;
        if (var_a0 < 0) {
            goto done;
        }
    }
    var_v0 = *(u8 **)(base + 0x34) + var_a0 * 0x18;
done:
    return **(s32 **)(var_v0 + 8) != 0;
}
