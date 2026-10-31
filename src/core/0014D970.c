/* cflags: -fno-opt-stack */
#include "common.h"

extern void (*D_0016F744_[])(s32);

/* Frees the pointer held in the record at *arg0 (its first word) and then the pointer in *arg0 itself, clearing each; returns 0 if *arg0 was set, else 1. */
s32 func_0014D970(s32 **arg0) {
    s32 *temp_s0;
    s32 var_v0;

    temp_s0 = *arg0;
    var_v0 = 1;
    if (temp_s0 != NULL) {
        if (temp_s0[0] != 0) {
            D_0016F744_[0](temp_s0[0]);
            temp_s0[0] = 0;
        }
        if (*arg0 != NULL) {
            D_0016F744_[0]((s32)*arg0);
            *arg0 = NULL;
        }
        var_v0 = 0;
    }
    return var_v0;
}
