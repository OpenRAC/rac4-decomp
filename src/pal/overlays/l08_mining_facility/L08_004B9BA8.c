/* cflags:  -Wuninitialized */
#include "common.h"

s32 func_00474368(s32, s32, s32);           /* extern */
extern s32 D_00222714;

s32 func_L08_004B9BA8(void *arg0) {
    s32 *var_16;
    s32 temp_2;
    s32 temp_4;
    s32 var_17;

    var_17 = 5;
    var_16 = (s32 *)((*(s32 *)((u8 *)(arg0) + (0xAC))) + 0x10);
    do {
        temp_4 = *var_16 << 8;
        var_16 = (s32 *)((unsigned char *)(var_16) + (4));
        var_17 = var_17 - 1;
        temp_2 = func_00474368(D_00222714 + temp_4, 1, -1);
    } while (var_17 >= 0);
    return temp_2;
}
