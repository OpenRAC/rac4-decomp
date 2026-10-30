#include "common.h"

extern void *func_005010E0();
extern s32 D_00222038_[];

/* Returns the word at +0x14 of the object at +4 of D_00222038 (fetching a fallback object if that is empty), or -1 if it is null. */
s32 func_00505B20(void) {
    void *var_v0;
    void *temp_v0;
    s32 var_v1;

    var_v0 = D_00222038_;
    if (*(void **)((u8 *)D_00222038_ + 4) == NULL) {
        var_v0 = func_005010E0();
    }
    temp_v0 = *(void **)((u8 *)var_v0 + 4);
    var_v1 = -1;
    if (temp_v0 != NULL) {
        var_v1 = *(s32 *)((u8 *)temp_v0 + 0x14);
    }
    return var_v1;
}
