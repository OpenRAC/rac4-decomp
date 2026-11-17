/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

s32 func_L01_004FFD18(void *arg0) {
    void *temp_4;
    void *temp_5;

    temp_5 = M2C_FIELD(arg0, void **, 0xAC);
    temp_4 = M2C_FIELD(temp_5, void **, 0x254);
    if (temp_4 == NULL) {
        goto block_5;
    }
    if (M2C_FIELD(temp_4, s16 *, 0xBC) != 0x20EC) {
        goto block_5;
    }
    if (M2C_FIELD(M2C_FIELD(temp_4, void **, 0xAC), u8 *, 0x1F3) != 0) {
        goto block_4;
    }
    goto block_6;
block_4:
block_5:
    return 0;
block_6:
    if (M2C_FIELD(temp_5, s16 *, 0x76) != 0) {
        goto block_8;
    }
    return M2C_FIELD(temp_5, u8 *, 0x281) != 0;
block_8:
    return 0;
}
