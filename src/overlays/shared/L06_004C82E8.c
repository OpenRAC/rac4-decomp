#include "common.h"

extern s32 func_L06_004C8388(void *arg0);
extern s32 D_0021DF64;

// Return 1 when func_L06_004C8388 passes and the entry's +0x88 word is not below the table word at +0x74 of the indexed slot.
s32 func_L06_004C82E8(void *arg0) {
    u8 *temp_a2;

    if (func_L06_004C8388(arg0) != 0) {
        temp_a2 = *(u8 **)((u8 *)arg0 + 0xAC);
        if (!(*(s32 *)(temp_a2 + 0x88) < *(s32 *)(temp_a2 + (D_0021DF64 << 2) + 0x74))) {
            return 1;
        }
    }
    return 0;
}
