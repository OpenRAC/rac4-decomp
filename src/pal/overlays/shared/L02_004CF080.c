/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s32 D_00222894;

s32 func_L02_004CF080(s32 arg0) {
    u8 temp_3;
    void *temp_2;

    if (arg0 != -1) {
        goto block_2;
    }
block_1:
    return 1;
block_2:
    temp_2 = D_00222894 + (arg0 << 8);
    if (temp_2 == NULL) {
        goto block_1;
    }
    temp_3 = (*(u8 *)((u8 *)(temp_2) + (0x20)));
    if (temp_3 == 0xFE) {
        goto block_1;
    }
    if (temp_3 == 0xFD) {
        goto block_1;
    }
    if (temp_3 == 5) {
        goto block_1;
    }
    if (temp_3 == 6) {
        goto block_1;
    }
    if (temp_3 == 7) {
        goto block_1;
    }
    if (temp_3 == 8) {
        goto block_1;
    }
    return 0;
}
