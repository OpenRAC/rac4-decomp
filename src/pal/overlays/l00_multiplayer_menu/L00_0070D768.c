/* cflags: -Wuninitialized */
#include "common.h"

int D_00220ABC = 0;

s32 func_L00_0070D768(void) {
    s32 temp_3;

    temp_3 = D_00220ABC;
    if (temp_3 != 0) {
        D_00220ABC = *(s32 *)((u8 *)temp_3 + 0x19C);
        *(s32 *)((u8 *)temp_3 + 0x19C) = 0;
    }
    return temp_3;
}