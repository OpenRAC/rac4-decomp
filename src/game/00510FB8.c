#include "common.h"

extern void *func_00510EE0();
extern s32 D_00220B90;
extern s32 D_00220B88;

/* Returns the object from func_00510EE0 if it is non-null and its masked word, shifted by D_00220B88, is zero; otherwise NULL. */
s32 *func_00510FB8(void) {
    s32 *var_v0;

    var_v0 = func_00510EE0();
    if (var_v0 != NULL) {
        if (((u32)(*var_v0 & D_00220B90) >> D_00220B88) == 0) {
            return var_v0;
        }
    }
    return NULL;
}
