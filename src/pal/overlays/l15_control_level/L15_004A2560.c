#include "common.h"

extern s32 D_0021DE98;

s32 func_L15_004A2560(void *arg0) {
    void *temp_a0;

    temp_a0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    if (((*(s32 *)((s8 *)(temp_a0) + (0x70))) == 0) && ((D_0021DE98 != 0xF) || ((*(s32 *)((s8 *)(temp_a0) + (0x78))) == 0))) {
        return 1;
    }
    return 0;
}
