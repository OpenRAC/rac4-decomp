/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void *D_0021EC50;
s32 func_L01_003CC598(s32 arg0) {
    s32 temp_3 = *(s32 *)((u8 *)D_0021EC50 + 0xAC);
    s32 temp_4;
    if (arg0 < 0) goto block_6;
    if (arg0 < 8) goto block_3;
    temp_4 = arg0 - 8;
    goto block_5;
block_3:
    return temp_3 + (arg0 << 5);
block_5:
    if (temp_4 < 0x38) goto block_7;
block_6:
    return 0;
block_7:
    return temp_3 + 0x100 + (temp_4 << 5);
}
