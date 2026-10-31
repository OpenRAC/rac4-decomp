/* cflags:  -Wuninitialized */
#include "pal/decomp.h"
typedef long long s128; typedef unsigned long long u128;
M2C_UNK func_00474368(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_L06_00568C30(s32);                         /* extern */
M2C_UNK func_L06_00569140(s32);                     /* extern */

void func_L06_0049AE90(void *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, u8 *, 0x20) == 0) {
        temp_a0 = *M2C_FIELD(arg0, s32 **, 0xAC);
        if (temp_a0 != -1) {
            func_L06_00569140(func_L06_00568C30(temp_a0));
        }
        func_00474368(arg0, 1, -1);
    }
}
