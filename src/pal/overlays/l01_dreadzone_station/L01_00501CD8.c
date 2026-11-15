/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern u8 D_003ABFA0[];
extern u8 D_003ABFC0[];

u8 *func_L01_00501CD8(s32 arg0, s32 arg1, s32 *arg2) {
    if (arg1 == 8) goto block_3;
    if (arg1 != 14) goto block_4;
    *arg2 = 28;
    return D_003ABFA0;
block_3:
    *arg2 = 36;
    return D_003ABFC0;
block_4:
    return 0;
}
