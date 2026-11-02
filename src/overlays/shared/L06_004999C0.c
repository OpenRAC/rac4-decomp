/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
M2C_UNK func_0053C1C8(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_L06_00565118(s32);                         /* extern */
M2C_UNK func_L06_00565628(s32);                     /* extern */

void func_L06_004999C0(void *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, u8 *, 0x20) == 0) {
        temp_a0 = *M2C_FIELD(arg0, s32 **, 0xAC);
        if (temp_a0 != -1) {
            func_L06_00565628(func_L06_00565118(temp_a0));
        }
        func_0053C1C8(arg0, 1, -1);
    }
}
