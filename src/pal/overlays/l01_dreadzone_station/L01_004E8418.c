/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern u8 D_003ABA40[];
extern u8 D_003AB970[];

u8 *func_L01_004E8418(s32 arg0, s32 arg1, s32 *arg2) {
    if (arg1 == 0) goto block_3;
    if (arg1 == 6) goto block_4;
    return NULL;
block_3:
    *arg2 = 0x48;
    return D_003ABA40;
block_4:
    *arg2 = 0xD0;
    return D_003AB970;
}
