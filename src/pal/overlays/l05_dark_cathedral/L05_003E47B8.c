/* cflags: -O2 -G0 -Wuninitialized */
#include "common.h"

extern void *D_00363038;

s32 func_L05_003E47B8(s32 arg0) {
    s32 var_5;
    void **var_6;
    void *var_3;

    var_5 = 0;
    var_3 = D_00363038;
    var_6 = &D_00363038;
loop_1:
    var_6 = (void **)((unsigned char *)(var_6) + (4));
    if (var_3 != NULL) {
        var_5 = var_5 + 1;
        if ((*(s32 *)((u8 *)(var_3) + (0x2EC))) == arg0) {
            return 1;
        }
        goto block_5;
    }
    var_5 = var_5 + 1;
block_5:
    var_3 = *var_6;
    if (var_5 >= 0xA) {
        return 0;
    }
    goto loop_1;
}