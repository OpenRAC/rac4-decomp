#include "common.h"

extern s32 D_3284A0[];

/* Search for the first zero slot in an array of 4 and store arg0 there. */
void func_00436970(s32 arg0, s32 arg1) {
    s32 *var_a1;
    s32 i;

    var_a1 = &D_3284A0[arg1 * 4];
    for (i = 0; i < 4; i++) {
        if (*var_a1 == 0) {
            *var_a1 = arg0;
            return;
        }
        var_a1 += 1;
    }
}
