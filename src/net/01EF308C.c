/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_0011EB90(s8 *);
s8 *func_01EE3A18();
s32 func_01EEE070(s8);

s32 func_01EF308C(s32 arg0, s32 arg1, s32 *arg2) {
    s8 *temp_v0;

    temp_v0 = func_01EE3A18();
    if ((temp_v0 != NULL) && (func_01EEE070(*temp_v0) != 0)) {
        *arg2 = func_0011EB90(temp_v0);
        return 1;
    }
    return 0;
}
