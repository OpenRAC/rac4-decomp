#include "common.h"

extern s32 func_00500470(void *arg0, s32 arg1);
extern void *func_005010E0();
extern s32 D_222038_[];

/* Calls func_00500470 with the word at +0x14 of the object at +4 of D_222038 (or of a fallback object), returning -1 if that word is null. */
s32 func_00505C90(s32 arg0) {
    u8 *var_v0;
    u8 *temp_v1;
    s32 var_a0;
    s32 var_v0_2;

    var_v0_2 = -1;
    if (D_222038_[1] != 0) {
        var_v0 = (u8 *)D_222038_;
    } else {
        var_v0 = func_005010E0();
    }
    temp_v1 = *(u8 **)(var_v0 + 4);
    var_a0 = 0;
    if (temp_v1 != NULL) {
        var_a0 = *(s32 *)(temp_v1 + (*(s32 *)(temp_v1 + 0x14) << 2));
    }
    if (var_a0 != 0) {
        var_v0_2 = func_00500470((void *)var_a0, arg0);
    }
    return var_v0_2;
}
