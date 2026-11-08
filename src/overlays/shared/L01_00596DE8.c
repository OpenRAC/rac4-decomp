#include "common.h"

extern s32 func_00596E48(u8 *a0);

/* from rac3-decomp's func_L01_0044AEB8, constants adapted */
s32 func_L01_00596DE8(u8 *a0) {
    if (a0 == 0) return 0;
    if (func_00596E48(a0) != 0) return *(s16 *)(a0 + 0xbc) == 0x1F6;
    return 1;
}
