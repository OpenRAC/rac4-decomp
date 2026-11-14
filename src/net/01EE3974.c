/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);

/* Returns the first node in arg0's list whose f24 pointer func_0011A8A0 accepts for arg1, or NULL. */
void *func_01EE3974(void **arg0, const u8 *arg1) {
    void **var_s0;
    void *temp_v0;

    if (arg0 == NULL) {
        return NULL;
    }
    var_s0 = arg0[2];
    while (var_s0 != NULL) {
        temp_v0 = var_s0[9];
        if (temp_v0 != NULL && func_0011A8A0(temp_v0, arg1) == 0) {
            return var_s0;
        }
        var_s0 = var_s0[0];
    }
    return NULL;
}
